using System;
using System.IO;
using System.Net.Sockets;
using System.Threading;
using UnityEngine;

using NetTcpClient = System.Net.Sockets.TcpClient;

public class RemotePcmAudioPlayer : MonoBehaviour
{
    public const int DefaultPort = 13580;
    private const int SampleRate = 16000;
    private const int Channels = 1;
    private const int PrebufferMs = 160;
    private const int TargetBufferMs = 300;
    private const int HardBufferMs = 1000;
    private const int PrebufferSamples = SampleRate * PrebufferMs / 1000;
    private const int TargetBufferSamples = SampleRate * TargetBufferMs / 1000;
    private const int HardBufferSamples = SampleRate * HardBufferMs / 1000;
    private const int ConnectTimeoutMs = 2000;
    private const int ReadTimeoutMs = 5000;
    private const int ReconnectDelayMs = 1000;
    private const int ReceiveBufferBytes = 64 * 1024;
    private const float DefaultDigitalGain = 6f;
    private const float PlaybackHealthIntervalSeconds = 5f;
    private const float NonZeroThreshold = 1f / 32768f;

    private readonly object _ringLock = new object();
    private readonly object _clientLock = new object();
    private readonly object _statusLock = new object();
    private readonly object _healthLock = new object();

    private float[] _ringBuffer = new float[HardBufferSamples];
    private int _readIndex;
    private int _writeIndex;
    private int _bufferedSamples;
    private bool _playbackPrimed;

    private AudioSource _audioSource;
    private AudioClip _audioClip;
    private Thread _receiveThread;
    private NetTcpClient _client;
    private volatile bool _stopRequested = true;
    private volatile bool _connected;
    private string _host;
    private int _port = DefaultPort;
    private int _runId;
    private byte _pendingByte;
    private bool _hasPendingByte;
    private long _receivedSamples;
    private long _droppedSamples;
    private long _underrunSamples;
    private long _playedSamples;
    private long _nonZeroPlayedSamples;
    private long _stretchedSamples;
    private long _audioReadCallbacks;
    private double _lastOutputRms;
    private float _lastOutputPeak;
    private float _nextPlaybackHealthRealtime;

    [SerializeField] [Range(1f, 12f)] private float digitalGain = DefaultDigitalGain;

    private string _pendingStatusMessage;
    private bool _pendingStatusWarning;

    public bool IsConnected => _connected;
    public long ReceivedSamples => Interlocked.Read(ref _receivedSamples);
    public long DroppedSamples => Interlocked.Read(ref _droppedSamples);
    public long UnderrunSamples => Interlocked.Read(ref _underrunSamples);
    public long PlayedSamples => Interlocked.Read(ref _playedSamples);

    public void StartAudio(string host, int port = DefaultPort)
    {
        if (string.IsNullOrWhiteSpace(host))
        {
            CrashProbe.Breadcrumb("remote_audio.start_skipped", "empty host", LogType.Warning);
            LogWindow.Warn("Remote audio skipped: empty host.");
            return;
        }

        StopAudio(false);
        ResetRingBuffer();

        _host = host.Trim();
        _port = port > 0 && port <= 65535 ? port : DefaultPort;
        int runId = Interlocked.Increment(ref _runId);
        _stopRequested = false;
        _connected = false;

        EnsureAudioSource();
        _nextPlaybackHealthRealtime = Time.realtimeSinceStartup + PlaybackHealthIntervalSeconds;
        if (!_audioSource.isPlaying)
        {
            _audioSource.Play();
        }

        _receiveThread = new Thread(() => ReceiveLoop(runId));
        _receiveThread.IsBackground = true;
        _receiveThread.Name = "RemotePcmAudioPlayer";
        _receiveThread.Start();

        LogWindow.Info($"Remote audio connecting to {_host}:{_port} (s16le {SampleRate}Hz mono).");
        CrashProbe.Breadcrumb("remote_audio.connecting", $"{_host}:{_port}");
    }

    public void StopAudio()
    {
        StopAudio(true);
    }

    private void StopAudio(bool log)
    {
        bool wasRunning = !_stopRequested || _connected || _receiveThread != null;
        _stopRequested = true;
        Interlocked.Increment(ref _runId);
        CloseClient();

        if (_receiveThread != null && _receiveThread.IsAlive && Thread.CurrentThread != _receiveThread)
        {
            _receiveThread.Join(500);
        }

        _receiveThread = null;
        _connected = false;
        _hasPendingByte = false;
        ResetRingBuffer(false);

        if (_audioSource != null && _audioSource.isPlaying)
        {
            _audioSource.Stop();
        }

        if (log && wasRunning)
        {
            LogWindow.Info("Remote audio stopped.");
            CrashProbe.Breadcrumb("remote_audio.stopped");
        }
    }

    private void EnsureAudioSource()
    {
        if (_audioSource == null)
        {
            _audioSource = GetComponent<AudioSource>();
            if (_audioSource == null)
            {
                _audioSource = gameObject.AddComponent<AudioSource>();
            }

            _audioSource.playOnAwake = false;
            _audioSource.loop = true;
            _audioSource.spatialBlend = 0f;
            _audioSource.volume = 1f;
            _audioSource.mute = false;
            _audioSource.ignoreListenerPause = true;
            _audioSource.ignoreListenerVolume = true;
        }

        if (_audioClip == null)
        {
            _audioClip = AudioClip.Create(
                "G1RemoteMicPcm",
                SampleRate,
                Channels,
                SampleRate,
                true,
                OnAudioRead);
        }

        _audioSource.clip = _audioClip;
    }

    private void ReceiveLoop(int runId)
    {
        byte[] readBuffer = new byte[1280];

        while (IsRunActive(runId))
        {
            NetTcpClient tcp = null;
            try
            {
                tcp = ConnectWithTimeout(_host, _port, ConnectTimeoutMs);
                tcp.NoDelay = true;
                tcp.ReceiveTimeout = ReadTimeoutMs;
                tcp.ReceiveBufferSize = ReceiveBufferBytes;

                bool acceptedClient;
                lock (_clientLock)
                {
                    acceptedClient = IsRunActive(runId);
                    if (acceptedClient)
                    {
                        _client = tcp;
                    }
                }

                if (!acceptedClient)
                {
                    tcp.Close();
                    tcp = null;
                    break;
                }

                if (IsRunActive(runId))
                {
                    ResetRingBuffer(false);
                    bool markedConnected = false;
                    lock (_clientLock)
                    {
                        if (IsRunActive(runId) && _client == tcp)
                        {
                            _connected = true;
                            markedConnected = true;
                        }
                    }
                    if (markedConnected)
                    {
                        CrashProbe.Breadcrumb("remote_audio.connected", $"{_host}:{_port}");
                        SetPendingStatus($"Remote audio connected: {_host}:{_port}", false);
                    }
                }

                NetworkStream stream = tcp.GetStream();
                while (IsRunActive(runId))
                {
                    int bytesRead = stream.Read(readBuffer, 0, readBuffer.Length);
                    if (bytesRead <= 0)
                    {
                        break;
                    }
                    if (!IsRunActive(runId))
                    {
                        break;
                    }

                    bool firstPayload = Interlocked.Read(ref _receivedSamples) == 0;
                    QueuePcmBytes(readBuffer, bytesRead);
                    if (firstPayload)
                    {
                        CrashProbe.Breadcrumb(
                            "remote_audio.first_payload",
                            $"bytes={bytesRead} buffered_samples={ReceivedSamples}");
                    }
                }
            }
            catch (SocketException e)
            {
                CrashProbe.Breadcrumb(
                    "remote_audio.reconnecting",
                    $"socket={e.SocketErrorCode} received_samples={ReceivedSamples}",
                    LogType.Warning);
                SetPendingStatusForRun(runId, $"Remote audio reconnecting: {e.Message}", true);
            }
            catch (IOException e)
            {
                CrashProbe.Breadcrumb(
                    "remote_audio.reconnecting",
                    $"io={e.Message} received_samples={ReceivedSamples}",
                    LogType.Warning);
                SetPendingStatusForRun(runId, $"Remote audio reconnecting: {e.Message}", true);
            }
            catch (TimeoutException e)
            {
                CrashProbe.Breadcrumb(
                    "remote_audio.reconnecting",
                    $"timeout={e.Message} received_samples={ReceivedSamples}",
                    LogType.Warning);
                SetPendingStatusForRun(runId, $"Remote audio reconnecting: {e.Message}", true);
            }
            catch (ObjectDisposedException)
            {
                if (IsRunActive(runId))
                {
                    SetPendingStatus("Remote audio reconnecting: socket closed.", true);
                }
            }
            catch (Exception e)
            {
                CrashProbe.Exception("remote_audio.receive_loop_exception", e);
                SetPendingStatusForRun(runId, $"Remote audio error: {e.Message}", true);
            }
            finally
            {
                if (IsRunActive(runId))
                {
                    // An older connect attempt may outlive StopAudio's short join.
                    // Never let that stale run clear a newer session's jitter buffer.
                    ResetRingBuffer(false);
                    _connected = false;
                }

                lock (_clientLock)
                {
                    if (_client == tcp)
                    {
                        _client = null;
                    }
                }

                if (tcp != null)
                {
                    tcp.Close();
                }
            }

            if (IsRunActive(runId))
            {
                Thread.Sleep(ReconnectDelayMs);
            }
        }
    }

    private bool IsRunActive(int runId)
    {
        return !_stopRequested && runId == Interlocked.CompareExchange(ref _runId, 0, 0);
    }

    private NetTcpClient ConnectWithTimeout(string host, int port, int timeoutMs)
    {
        NetTcpClient tcp = new NetTcpClient();
        IAsyncResult result = tcp.BeginConnect(host, port, null, null);
        try
        {
            bool connected = result.AsyncWaitHandle.WaitOne(timeoutMs);
            if (!connected)
            {
                throw new TimeoutException($"connect timeout to {host}:{port}");
            }
            tcp.EndConnect(result);
            return tcp;
        }
        catch
        {
            tcp.Close();
            throw;
        }
        finally
        {
            result.AsyncWaitHandle.Close();
        }
    }

    private void QueuePcmBytes(byte[] bytes, int count)
    {
        int offset = 0;

        if (_hasPendingByte && count > 0)
        {
            EnqueueSample(ToFloatSample(_pendingByte, bytes[0]));
            _hasPendingByte = false;
            offset = 1;
        }

        int evenEnd = offset + ((count - offset) / 2) * 2;
        int sampleCount = (evenEnd - offset) / 2;
        if (sampleCount > 0)
        {
            float[] samples = new float[sampleCount];
            int sampleIndex = 0;
            for (int i = offset; i < evenEnd; i += 2)
            {
                samples[sampleIndex++] = ToFloatSample(bytes[i], bytes[i + 1]);
            }

            EnqueueSamples(samples, sampleCount);
        }

        if (evenEnd < count)
        {
            _pendingByte = bytes[count - 1];
            _hasPendingByte = true;
        }
    }

    private static float ToFloatSample(byte low, byte high)
    {
        short sample = (short)(low | (high << 8));
        return sample / 32768f;
    }

    private void EnqueueSample(float sample)
    {
        lock (_ringLock)
        {
            WriteSampleLocked(sample);
        }

        Interlocked.Increment(ref _receivedSamples);
    }

    private void EnqueueSamples(float[] samples, int count)
    {
        lock (_ringLock)
        {
            for (int i = 0; i < count; i++)
            {
                WriteSampleLocked(samples[i]);
            }
        }

        Interlocked.Add(ref _receivedSamples, count);
    }

    private void WriteSampleLocked(float sample)
    {
        if (_bufferedSamples == _ringBuffer.Length)
        {
            int dropCount = Math.Max(1, _bufferedSamples - TargetBufferSamples + 1);
            _readIndex = (_readIndex + dropCount) % _ringBuffer.Length;
            _bufferedSamples -= dropCount;
            Interlocked.Add(ref _droppedSamples, dropCount);
        }

        _ringBuffer[_writeIndex] = sample;
        _writeIndex = (_writeIndex + 1) % _ringBuffer.Length;
        _bufferedSamples++;
    }

    private void OnAudioRead(float[] data)
    {
        int outputCount = 0;
        int sourceCount = 0;

        lock (_ringLock)
        {
            if (!_playbackPrimed)
            {
                int required = Math.Min(data.Length, PrebufferSamples);
                if (_bufferedSamples < required)
                {
                    outputCount = 0;
                }
                else
                {
                    _playbackPrimed = true;
                }
            }

            sourceCount = _playbackPrimed ? Math.Min(data.Length, _bufferedSamples) : 0;
            int minimumStretchSource = Math.Max(1, data.Length * 2 / 3);
            if (sourceCount > 0 && sourceCount < minimumStretchSource)
            {
                sourceCount = 0;
                _playbackPrimed = false;
            }

            if (sourceCount == data.Length)
            {
                for (int i = 0; i < sourceCount; i++)
                {
                    data[i] = _ringBuffer[(_readIndex + i) % _ringBuffer.Length];
                }
                outputCount = data.Length;
            }
            else if (sourceCount > 1 && data.Length > 1)
            {
                // The Unitree multicast microphone can arrive below its declared
                // 16 kHz cadence.  Stretch a bounded near-full callback instead
                // of appending a periodic block of zeros, which is perceived as
                // missing syllables.  Severe gaps still fall back to rebuffering.
                float scale = (sourceCount - 1f) / (data.Length - 1f);
                for (int i = 0; i < data.Length; i++)
                {
                    float sourcePosition = i * scale;
                    int lower = Mathf.FloorToInt(sourcePosition);
                    int upper = Math.Min(sourceCount - 1, lower + 1);
                    float fraction = sourcePosition - lower;
                    float a = _ringBuffer[(_readIndex + lower) % _ringBuffer.Length];
                    float b = _ringBuffer[(_readIndex + upper) % _ringBuffer.Length];
                    data[i] = Mathf.Lerp(a, b, fraction);
                }
                outputCount = data.Length;
                Interlocked.Add(ref _stretchedSamples, data.Length - sourceCount);
            }

            _readIndex = (_readIndex + sourceCount) % _ringBuffer.Length;
            _bufferedSamples -= sourceCount;
        }

        for (int i = outputCount; i < data.Length; i++)
        {
            data[i] = 0f;
        }

        float gain = Mathf.Clamp(digitalGain, 1f, 12f);
        double sumSquares = 0d;
        float peak = 0f;
        long nonZero = 0;
        for (int i = 0; i < outputCount; i++)
        {
            float output = Mathf.Clamp(data[i] * gain, -1f, 1f);
            data[i] = output;
            float magnitude = Mathf.Abs(output);
            if (magnitude > NonZeroThreshold)
            {
                nonZero++;
            }
            if (magnitude > peak)
            {
                peak = magnitude;
            }
            sumSquares += output * output;
        }

        Interlocked.Increment(ref _audioReadCallbacks);
        Interlocked.Add(ref _playedSamples, outputCount);
        Interlocked.Add(ref _nonZeroPlayedSamples, nonZero);
        lock (_healthLock)
        {
            _lastOutputRms = outputCount > 0 ? Math.Sqrt(sumSquares / outputCount) : 0d;
            _lastOutputPeak = peak;
        }

        if (outputCount < data.Length)
        {
            Interlocked.Add(ref _underrunSamples, data.Length - outputCount);
        }
    }

    private void ResetRingBuffer(bool resetCounters = true)
    {
        lock (_ringLock)
        {
            Array.Clear(_ringBuffer, 0, _ringBuffer.Length);
            _readIndex = 0;
            _writeIndex = 0;
            _bufferedSamples = 0;
            _playbackPrimed = false;
        }

        if (resetCounters)
        {
            Interlocked.Exchange(ref _receivedSamples, 0);
            Interlocked.Exchange(ref _droppedSamples, 0);
            Interlocked.Exchange(ref _underrunSamples, 0);
            Interlocked.Exchange(ref _playedSamples, 0);
            Interlocked.Exchange(ref _nonZeroPlayedSamples, 0);
            Interlocked.Exchange(ref _stretchedSamples, 0);
            Interlocked.Exchange(ref _audioReadCallbacks, 0);
            lock (_healthLock)
            {
                _lastOutputRms = 0d;
                _lastOutputPeak = 0f;
            }
        }
        _hasPendingByte = false;
    }

    private void CloseClient()
    {
        lock (_clientLock)
        {
            if (_client != null)
            {
                _client.Close();
                _client = null;
            }
        }
    }

    private void SetPendingStatus(string message, bool warning)
    {
        lock (_statusLock)
        {
            _pendingStatusMessage = message;
            _pendingStatusWarning = warning;
        }
    }

    private void SetPendingStatusForRun(int runId, string message, bool warning)
    {
        if (IsRunActive(runId))
        {
            SetPendingStatus(message, warning);
        }
    }

    private void Update()
    {
        EmitPlaybackHealthIfDue();
        string message = null;
        bool warning = false;

        lock (_statusLock)
        {
            if (!string.IsNullOrEmpty(_pendingStatusMessage))
            {
                message = _pendingStatusMessage;
                warning = _pendingStatusWarning;
                _pendingStatusMessage = null;
            }
        }

        if (message == null)
        {
            return;
        }

        if (warning)
        {
            LogWindow.Warn(message);
        }
        else
        {
            LogWindow.Info(message);
        }
    }

    private void EmitPlaybackHealthIfDue()
    {
        float now = Time.realtimeSinceStartup;
        if (now < _nextPlaybackHealthRealtime)
        {
            return;
        }
        _nextPlaybackHealthRealtime = now + PlaybackHealthIntervalSeconds;

        int buffered;
        lock (_ringLock)
        {
            buffered = _bufferedSamples;
        }
        double rms;
        float peak;
        lock (_healthLock)
        {
            rms = _lastOutputRms;
            peak = _lastOutputPeak;
        }
        bool sourcePlaying = _audioSource != null && _audioSource.isPlaying;
        CrashProbe.Breadcrumb(
            "remote_audio.health",
            $"connected={IsConnected} source_playing={sourcePlaying} " +
            $"received={ReceivedSamples} played={PlayedSamples} " +
            $"nonzero={Interlocked.Read(ref _nonZeroPlayedSamples)} " +
            $"stretched={Interlocked.Read(ref _stretchedSamples)} " +
            $"underrun={UnderrunSamples} dropped={DroppedSamples} " +
            $"callbacks={Interlocked.Read(ref _audioReadCallbacks)} buffered={buffered} " +
            $"rms={rms:F6} peak={peak:F6} gain={Mathf.Clamp(digitalGain, 1f, 12f):F2}");
    }

    private void OnDestroy()
    {
        StopAudio(false);
    }

    private void OnDisable()
    {
        StopAudio(false);
    }

    private void OnApplicationQuit()
    {
        StopAudio(false);
    }

    private void OnApplicationPause(bool pauseStatus)
    {
        if (pauseStatus)
        {
            StopAudio(false);
        }
    }
}
