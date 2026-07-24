using System;
using System.Collections.Generic;
using System.IO;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using UnityEngine;
#if UNITY_ANDROID
using UnityEngine.Android;
#endif

using NetTcpClient = System.Net.Sockets.TcpClient;

public sealed class PicoMicrophoneStreamer : MonoBehaviour
{
    public const int DefaultPort = 13581;
    public const int OutputSampleRate = 16000;
    public const int OutputChannels = 1;
    public const int FrameDurationMs = 20;

    private const int CaptureLoopSeconds = 2;
    private const int SamplesPerFrame = OutputSampleRate * FrameDurationMs / 1000;
    private const int BytesPerFrame = SamplesPerFrame * sizeof(short);
    private const int MaxQueuedFrames = 5;
    private const int ConnectTimeoutMs = 2000;
    private const int SendTimeoutMs = 1000;
    private const int ReconnectDelayMs = 1000;
    private const int SendBufferBytes = 64 * 1024;
    private const int HeartbeatIntervalMs = 1000;
    private const int MaxCaptureBacklogMs = 100;
    private const float CaptureHealthIntervalSeconds = 5f;
    private const byte ProtocolVersion = 1;
    private const long UnixEpochTicks = 621355968000000000L;
    private static readonly byte[] AuthMagic = Encoding.ASCII.GetBytes("G1AT");
    private static readonly byte[] FrameMagic = Encoding.ASCII.GetBytes("G1AF");
    private static readonly byte[] HeartbeatMagic = Encoding.ASCII.GetBytes("G1AH");

    private readonly object _queueLock = new object();
    private readonly object _clientLock = new object();
    private readonly object _statusLock = new object();
    private readonly Queue<byte[]> _sendQueue = new Queue<byte[]>();
    private readonly AutoResetEvent _queueSignal = new AutoResetEvent(false);
    private readonly AutoResetEvent _stopSignal = new AutoResetEvent(false);
    private readonly float[] _outputFrame = new float[SamplesPerFrame];

    private AudioClip _microphoneClip;
    private string _microphoneDevice;
    private int _capturePosition;
    private int _sourceChannels = 1;
    private int _sourceSampleRate = OutputSampleRate;
    private int _outputFrameCount;

    private bool _hasPreviousSourceSample;
    private float _previousSourceSample;
    private long _previousSourceCaptureUnixNs;
    private long _sourceSampleIndex;
    private double _nextOutputSourcePosition;
    private long _outputFrameCaptureUnixNs;

    private Thread _sendThread;
    private NetTcpClient _client;
    private volatile bool _stopRequested = true;
    private volatile bool _connected;
    private volatile bool _muted;
    private string _host;
    private string _sessionToken;
    private int _port = DefaultPort;
    private int _runId;

    private long _capturedFrames;
    private long _sentFrames;
    private long _droppedFrames;
    private long _sendFailures;
    private long _lastWriteMs;
    private long _maxWriteMs;
    private float _nextCaptureHealthRealtime;

    private string _pendingStatusMessage;
    private bool _pendingStatusWarning;

    public bool IsConnected => _connected;
    public bool IsStreaming => !_stopRequested;
    public bool IsMuted => _muted;
    public long CapturedFrames => Interlocked.Read(ref _capturedFrames);
    public long SentFrames => Interlocked.Read(ref _sentFrames);
    public long DroppedFrames => Interlocked.Read(ref _droppedFrames);

    public static bool HasRecordPermission()
    {
#if UNITY_ANDROID && !UNITY_EDITOR
        return Permission.HasUserAuthorizedPermission(Permission.Microphone);
#else
        return true;
#endif
    }

    public static void RequestRecordPermission()
    {
#if UNITY_ANDROID && !UNITY_EDITOR
        if (!HasRecordPermission())
        {
            Permission.RequestUserPermission(Permission.Microphone);
        }
#endif
    }

    public bool StartStreaming(string host, int port, string sessionToken)
    {
        if (string.IsNullOrWhiteSpace(host))
        {
            CrashProbe.Breadcrumb("pico_microphone.start_skipped", "empty host", LogType.Warning);
            LogWindow.Warn("Pico microphone upload skipped: empty host.");
            return false;
        }

        if (string.IsNullOrWhiteSpace(sessionToken) ||
            Encoding.ASCII.GetByteCount(sessionToken) < 16 ||
            Encoding.ASCII.GetByteCount(sessionToken) > 256)
        {
            CrashProbe.Breadcrumb("pico_microphone.start_skipped", "invalid token", LogType.Warning);
            LogWindow.Warn("Pico microphone upload skipped: secure session token is missing or invalid.");
            return false;
        }

        if (!HasRecordPermission())
        {
            CrashProbe.Breadcrumb("pico_microphone.start_skipped", "record permission missing", LogType.Warning);
            LogWindow.Warn("Pico microphone upload skipped: RECORD_AUDIO permission is not granted.");
            return false;
        }

        StopStreaming(false);
        ResetCaptureState();
        _queueSignal.Reset();
        _stopSignal.Reset();

        _host = host.Trim();
        _port = port > 0 && port <= 65535 ? port : DefaultPort;
        _sessionToken = sessionToken;
        _microphoneDevice = GetPreferredMicrophoneDevice();

        try
        {
            _microphoneClip = Microphone.Start(
                _microphoneDevice,
                true,
                CaptureLoopSeconds,
                OutputSampleRate);
        }
        catch (Exception e)
        {
            CrashProbe.Exception("pico_microphone.microphone_start_exception", e);
            LogWindow.Warn($"Pico microphone could not start: {e.Message}");
            _microphoneClip = null;
        }

        if (_microphoneClip == null)
        {
            CrashProbe.Breadcrumb("pico_microphone.no_capture_device", "", LogType.Warning);
            LogWindow.Warn("Pico microphone upload skipped: no microphone capture device is available.");
            return false;
        }

        _sourceChannels = Math.Max(1, _microphoneClip.channels);
        _sourceSampleRate = _microphoneClip.frequency > 0
            ? _microphoneClip.frequency
            : OutputSampleRate;
        try
        {
            int initialPosition = Microphone.GetPosition(_microphoneDevice);
            _capturePosition = initialPosition >= 0 ? initialPosition : 0;
        }
        catch (Exception e)
        {
            CrashProbe.Exception("pico_microphone.position_query_exception", e);
            LogWindow.Warn($"Pico microphone position query failed: {e.Message}");
            StopMicrophoneCapture();
            return false;
        }

        _nextCaptureHealthRealtime = Time.realtimeSinceStartup + CaptureHealthIntervalSeconds;

        int runId = Interlocked.Increment(ref _runId);
        _stopRequested = false;
        _connected = false;

        _sendThread = new Thread(() => SendLoop(runId));
        _sendThread.IsBackground = true;
        _sendThread.Name = "PicoMicrophoneStreamer";
        _sendThread.Start();

        LogWindow.Info(
            $"Pico microphone streaming to {_host}:{_port} " +
            $"(source {_sourceSampleRate}Hz/{_sourceChannels}ch -> s16le {OutputSampleRate}Hz mono, " +
            $"{FrameDurationMs}ms frames).");
        CrashProbe.Breadcrumb(
            "pico_microphone.streaming",
            $"{_host}:{_port} source={_sourceSampleRate}Hz/{_sourceChannels}ch");
        return true;
    }

    public void StopStreaming()
    {
        StopStreaming(true);
    }

    public void SetMuted(bool muted)
    {
        if (_muted == muted)
        {
            return;
        }

        _muted = muted;
        if (muted)
        {
            _outputFrameCount = 0;
            ClearSendQueue(true);
        }

        LogWindow.Info(muted ? "Pico microphone muted." : "Pico microphone unmuted.");
    }

    private void StopStreaming(bool log)
    {
        bool wasRunning = !_stopRequested || _microphoneClip != null || _sendThread != null;
        _stopRequested = true;
        Interlocked.Increment(ref _runId);
        CloseClient();
        _queueSignal.Set();
        _stopSignal.Set();

        if (_sendThread != null && _sendThread.IsAlive && Thread.CurrentThread != _sendThread)
        {
            _sendThread.Join(500);
        }

        _sendThread = null;
        _connected = false;
        _sessionToken = null;
        StopMicrophoneCapture();
        ClearSendQueue(false);
        ResetResampler();

        if (log && wasRunning)
        {
            LogWindow.Info("Pico microphone upload stopped.");
            CrashProbe.Breadcrumb("pico_microphone.stopped");
        }
    }

    private static string GetPreferredMicrophoneDevice()
    {
        string[] devices = Microphone.devices;
        if (devices == null || devices.Length == 0)
        {
            return null;
        }

        return devices[0];
    }

    private void Update()
    {
        CaptureAvailableSamples();
        FlushPendingStatus();
    }

    private void CaptureAvailableSamples()
    {
        if (_stopRequested || _microphoneClip == null)
        {
            return;
        }

        int currentPosition;
        try
        {
            currentPosition = Microphone.GetPosition(_microphoneDevice);
        }
        catch (Exception e)
        {
            CrashProbe.Exception("pico_microphone.read_position_exception", e);
            SetPendingStatus($"Pico microphone read error: {e.Message}", true);
            return;
        }

        if (currentPosition < 0 || currentPosition == _capturePosition)
        {
            EmitCaptureHealthIfDue(currentPosition);
            return;
        }

        EmitCaptureHealthIfDue(currentPosition);

        int clipFrames = _microphoneClip.samples;
        if (clipFrames <= 0 || currentPosition >= clipFrames)
        {
            return;
        }

        int availableFrames = currentPosition >= _capturePosition
            ? currentPosition - _capturePosition
            : clipFrames - _capturePosition + currentPosition;

        int maxBacklogFrames = Math.Max(1, _sourceSampleRate * MaxCaptureBacklogMs / 1000);
        if (availableFrames > maxBacklogFrames)
        {
            int skippedFrames = availableFrames - maxBacklogFrames;
            _capturePosition = (_capturePosition + skippedFrames) % clipFrames;
            availableFrames = maxBacklogFrames;
            ResetResampler();
            long droppedOutputFrames = Math.Max(
                1L,
                (long)Math.Ceiling(
                    skippedFrames * OutputSampleRate /
                    (double)_sourceSampleRate /
                    SamplesPerFrame));
            Interlocked.Add(ref _droppedFrames, droppedOutputFrames);
            SetPendingStatus(
                $"Pico microphone capture backlog dropped: {skippedFrames} source frames.",
                true);
            CrashProbe.Breadcrumb(
                "pico_microphone.capture_backlog_dropped",
                $"source_frames={skippedFrames}",
                LogType.Warning);
        }

        long readUnixNs = GetUnixTimeNs();

        while (availableFrames > 0 && !_stopRequested)
        {
            int contiguousFrames = Math.Min(availableFrames, clipFrames - _capturePosition);
            if (!ReadCaptureSegment(
                    _capturePosition,
                    contiguousFrames,
                    availableFrames,
                    readUnixNs))
            {
                _capturePosition = currentPosition;
                return;
            }

            _capturePosition = (_capturePosition + contiguousFrames) % clipFrames;
            availableFrames -= contiguousFrames;
        }
    }

    private bool ReadCaptureSegment(
        int offsetFrames,
        int frameCount,
        int framesBehindCurrentAtStart,
        long readUnixNs)
    {
        if (frameCount <= 0)
        {
            return true;
        }

        float[] interleaved = new float[frameCount * _sourceChannels];
        if (!_microphoneClip.GetData(interleaved, offsetFrames))
        {
            CrashProbe.Breadcrumb("pico_microphone.get_data_failed", "", LogType.Warning);
            SetPendingStatus("Pico microphone AudioClip.GetData failed; dropping the unread capture segment.", true);
            return false;
        }

        for (int frame = 0; frame < frameCount; frame++)
        {
            int baseIndex = frame * _sourceChannels;
            float sum = 0f;
            for (int channel = 0; channel < _sourceChannels; channel++)
            {
                sum += interleaved[baseIndex + channel];
            }

            int framesBehindCurrent = Math.Max(0, framesBehindCurrentAtStart - frame);
            long captureUnixNs = readUnixNs -
                                 (long)(framesBehindCurrent * 1000000000.0 / _sourceSampleRate);
            AppendSourceSample(sum / _sourceChannels, captureUnixNs);
        }

        return true;
    }

    private void AppendSourceSample(float sample, long captureUnixNs)
    {
        if (!_hasPreviousSourceSample)
        {
            _hasPreviousSourceSample = true;
            _previousSourceSample = sample;
            _previousSourceCaptureUnixNs = captureUnixNs;
            _sourceSampleIndex = 0;
            _nextOutputSourcePosition = 0d;
            return;
        }

        _sourceSampleIndex++;
        double intervalStart = _sourceSampleIndex - 1d;
        while (_nextOutputSourcePosition <= _sourceSampleIndex)
        {
            double interpolation = _nextOutputSourcePosition - intervalStart;
            interpolation = Math.Max(0d, Math.Min(1d, interpolation));
            float output = _previousSourceSample +
                           (sample - _previousSourceSample) * (float)interpolation;
            long outputCaptureUnixNs = _previousSourceCaptureUnixNs +
                                       (long)((captureUnixNs - _previousSourceCaptureUnixNs) *
                                              interpolation);
            AppendOutputSample(output, outputCaptureUnixNs);
            _nextOutputSourcePosition += _sourceSampleRate / (double)OutputSampleRate;
        }

        _previousSourceSample = sample;
        _previousSourceCaptureUnixNs = captureUnixNs;
    }

    private void AppendOutputSample(float sample, long captureUnixNs)
    {
        if (_outputFrameCount == 0)
        {
            _outputFrameCaptureUnixNs = captureUnixNs;
        }
        _outputFrame[_outputFrameCount++] = sample;
        if (_outputFrameCount < SamplesPerFrame)
        {
            return;
        }

        _outputFrameCount = 0;
        if (_muted)
        {
            // Keep the capture ring drained, but send no frames while muted. Sending
            // zero PCM would keep the robot playback/ducking path falsely active.
            return;
        }

        byte[] pcmFrame = new byte[BytesPerFrame];
        for (int i = 0; i < SamplesPerFrame; i++)
        {
            float clamped = Mathf.Clamp(_outputFrame[i], -1f, 1f);
            int scaled = clamped <= -1f
                ? short.MinValue
                : clamped >= 1f
                    ? short.MaxValue
                    : Mathf.RoundToInt(clamped * short.MaxValue);
            short value = (short)scaled;
            pcmFrame[i * 2] = (byte)(value & 0xff);
            pcmFrame[i * 2 + 1] = (byte)((value >> 8) & 0xff);
        }

        long sequence = Interlocked.Increment(ref _capturedFrames);
        EnqueueFrame(BuildAudioFrameRecord(pcmFrame, sequence, _outputFrameCaptureUnixNs));
        if (sequence == 1)
        {
            CrashProbe.Breadcrumb(
                "pico_microphone.first_frame",
                $"capture_unix_ns={_outputFrameCaptureUnixNs}");
        }
    }

    private void EmitCaptureHealthIfDue(int currentPosition)
    {
        float now = Time.realtimeSinceStartup;
        if (now < _nextCaptureHealthRealtime)
        {
            return;
        }

        _nextCaptureHealthRealtime = now + CaptureHealthIntervalSeconds;
        bool recording = false;
        try
        {
            recording = Microphone.IsRecording(_microphoneDevice);
        }
        catch (Exception)
        {
            // The counters and position still provide useful diagnostics.
        }

        CrashProbe.Breadcrumb(
            "pico_microphone.health",
            $"recording={recording} position={currentPosition} " +
            $"captured={CapturedFrames} sent={SentFrames} dropped={DroppedFrames} " +
            $"connected={IsConnected} queued={QueuedFrames()} " +
            $"send_failures={Interlocked.Read(ref _sendFailures)} " +
            $"write_ms={Interlocked.Read(ref _lastWriteMs)} " +
            $"max_write_ms={Interlocked.Read(ref _maxWriteMs)}");
    }

    private void EnqueueFrame(byte[] frame)
    {
        lock (_queueLock)
        {
            while (_sendQueue.Count >= MaxQueuedFrames)
            {
                _sendQueue.Dequeue();
                Interlocked.Increment(ref _droppedFrames);
            }

            _sendQueue.Enqueue(frame);
        }

        _queueSignal.Set();
    }

    private bool TryDequeueFrame(out byte[] frame)
    {
        lock (_queueLock)
        {
            if (_sendQueue.Count == 0)
            {
                frame = null;
                return false;
            }

            // Preserve normal Unity capture bursts.  CaptureAvailableSamples can
            // legitimately enqueue two adjacent 20 ms frames in one Update;
            // dropping all but the newest frame here turned that batching into a
            // deterministic 20 ms hole.  EnqueueFrame already bounds the queue to
            // MaxQueuedFrames and drops only when TCP is genuinely backlogged.
            frame = _sendQueue.Dequeue();
            return true;
        }
    }

    private int QueuedFrames()
    {
        lock (_queueLock)
        {
            return _sendQueue.Count;
        }
    }

    private void ClearSendQueue(bool countAsDropped)
    {
        lock (_queueLock)
        {
            if (countAsDropped && _sendQueue.Count > 0)
            {
                Interlocked.Add(ref _droppedFrames, _sendQueue.Count);
            }

            _sendQueue.Clear();
        }
    }

    private void SendLoop(int runId)
    {
        while (IsRunActive(runId))
        {
            NetTcpClient tcp = null;
            try
            {
                tcp = ConnectWithTimeout(_host, _port, ConnectTimeoutMs);
                tcp.NoDelay = true;
                tcp.SendTimeout = SendTimeoutMs;
                tcp.SendBufferSize = SendBufferBytes;

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

                NetworkStream stream = tcp.GetStream();
                stream.WriteTimeout = SendTimeoutMs;
                byte[] authRecord = BuildAuthRecord(_sessionToken);
                stream.Write(authRecord, 0, authRecord.Length);

                if (IsRunActive(runId))
                {
                    ClearSendQueue(true);
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
                        SetPendingStatus($"Pico microphone connected: {_host}:{_port}", false);
                    }
                }

                long lastWriteTicks = DateTime.UtcNow.Ticks;
                while (IsRunActive(runId))
                {
                    if (!TryDequeueFrame(out byte[] frame))
                    {
                        if ((DateTime.UtcNow.Ticks - lastWriteTicks) / TimeSpan.TicksPerMillisecond >=
                            HeartbeatIntervalMs)
                        {
                            byte[] heartbeat = BuildHeartbeatRecord(GetUnixTimeNs());
                            stream.Write(heartbeat, 0, heartbeat.Length);
                            lastWriteTicks = DateTime.UtcNow.Ticks;
                        }
                        _queueSignal.WaitOne(100);
                        continue;
                    }

                    long writeStartedTicks = DateTime.UtcNow.Ticks;
                    stream.Write(frame, 0, frame.Length);
                    long writeMs = Math.Max(
                        0L,
                        (DateTime.UtcNow.Ticks - writeStartedTicks) /
                        TimeSpan.TicksPerMillisecond);
                    Interlocked.Exchange(ref _lastWriteMs, writeMs);
                    UpdateMaximum(ref _maxWriteMs, writeMs);
                    if (writeMs >= 100)
                    {
                        CrashProbe.Breadcrumb(
                            "pico_microphone.slow_write",
                            $"write_ms={writeMs} queued={QueuedFrames()}",
                            LogType.Warning);
                    }
                    lastWriteTicks = DateTime.UtcNow.Ticks;
                    Interlocked.Increment(ref _sentFrames);
                }
            }
            catch (SocketException e)
            {
                RecordSendFailure("socket", e.Message);
                SetPendingStatusForRun(runId, $"Pico microphone reconnecting: {e.Message}", true);
            }
            catch (IOException e)
            {
                RecordSendFailure("io", e.Message);
                SetPendingStatusForRun(runId, $"Pico microphone reconnecting: {e.Message}", true);
            }
            catch (TimeoutException e)
            {
                RecordSendFailure("timeout", e.Message);
                SetPendingStatusForRun(runId, $"Pico microphone reconnecting: {e.Message}", true);
            }
            catch (ObjectDisposedException)
            {
                if (IsRunActive(runId))
                {
                    SetPendingStatus("Pico microphone reconnecting: socket closed.", true);
                }
            }
            catch (Exception e)
            {
                RecordSendFailure("unexpected", e.Message);
                SetPendingStatusForRun(runId, $"Pico microphone error: {e.Message}", true);
            }
            finally
            {
                if (IsRunActive(runId))
                {
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
                _stopSignal.WaitOne(ReconnectDelayMs);
            }
        }
    }

    private bool IsRunActive(int runId)
    {
        return !_stopRequested && runId == Interlocked.CompareExchange(ref _runId, 0, 0);
    }

    private static NetTcpClient ConnectWithTimeout(string host, int port, int timeoutMs)
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

    private void RecordSendFailure(string kind, string message)
    {
        long failures = Interlocked.Increment(ref _sendFailures);
        CrashProbe.Breadcrumb(
            "pico_microphone.send_failure",
            $"kind={kind} count={failures} message={message}",
            LogType.Warning);
    }

    private static void UpdateMaximum(ref long target, long value)
    {
        long current = Interlocked.Read(ref target);
        while (value > current)
        {
            long observed = Interlocked.CompareExchange(ref target, value, current);
            if (observed == current)
            {
                return;
            }
            current = observed;
        }
    }

    private static byte[] BuildAuthRecord(string sessionToken)
    {
        byte[] token = Encoding.ASCII.GetBytes(sessionToken);
        byte[] body = new byte[AuthMagic.Length + 1 + token.Length];
        Buffer.BlockCopy(AuthMagic, 0, body, 0, AuthMagic.Length);
        body[AuthMagic.Length] = ProtocolVersion;
        Buffer.BlockCopy(token, 0, body, AuthMagic.Length + 1, token.Length);
        return AddRecordLength(body);
    }

    private static byte[] BuildAudioFrameRecord(byte[] pcm, long sequence, long captureUnixNs)
    {
        byte[] body = new byte[FrameMagic.Length + 1 + sizeof(long) + sizeof(long) + pcm.Length];
        int offset = 0;
        Buffer.BlockCopy(FrameMagic, 0, body, offset, FrameMagic.Length);
        offset += FrameMagic.Length;
        body[offset++] = ProtocolVersion;
        WriteUInt64BigEndian(body, offset, unchecked((ulong)sequence));
        offset += sizeof(long);
        WriteUInt64BigEndian(body, offset, unchecked((ulong)captureUnixNs));
        offset += sizeof(long);
        Buffer.BlockCopy(pcm, 0, body, offset, pcm.Length);
        return AddRecordLength(body);
    }

    private static byte[] BuildHeartbeatRecord(long captureUnixNs)
    {
        byte[] body = new byte[HeartbeatMagic.Length + 1 + sizeof(long)];
        Buffer.BlockCopy(HeartbeatMagic, 0, body, 0, HeartbeatMagic.Length);
        body[HeartbeatMagic.Length] = ProtocolVersion;
        WriteUInt64BigEndian(
            body,
            HeartbeatMagic.Length + 1,
            unchecked((ulong)captureUnixNs));
        return AddRecordLength(body);
    }

    private static byte[] AddRecordLength(byte[] body)
    {
        byte[] record = new byte[sizeof(int) + body.Length];
        WriteUInt32BigEndian(record, 0, unchecked((uint)body.Length));
        Buffer.BlockCopy(body, 0, record, sizeof(int), body.Length);
        return record;
    }

    private static void WriteUInt32BigEndian(byte[] buffer, int offset, uint value)
    {
        buffer[offset] = (byte)(value >> 24);
        buffer[offset + 1] = (byte)(value >> 16);
        buffer[offset + 2] = (byte)(value >> 8);
        buffer[offset + 3] = (byte)value;
    }

    private static void WriteUInt64BigEndian(byte[] buffer, int offset, ulong value)
    {
        for (int index = 7; index >= 0; index--)
        {
            buffer[offset + index] = (byte)value;
            value >>= 8;
        }
    }

    private static long GetUnixTimeNs()
    {
        return checked((DateTime.UtcNow.Ticks - UnixEpochTicks) * 100L);
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

    private void StopMicrophoneCapture()
    {
        if (_microphoneClip == null)
        {
            return;
        }

        try
        {
            Microphone.End(_microphoneDevice);
        }
        catch (Exception e)
        {
            LogWindow.Warn($"Pico microphone stop warning: {e.Message}");
        }

        _microphoneClip = null;
        _microphoneDevice = null;
        _capturePosition = 0;
    }

    private void ResetCaptureState()
    {
        ClearSendQueue(false);
        ResetResampler();
        lock (_statusLock)
        {
            _pendingStatusMessage = null;
            _pendingStatusWarning = false;
        }
        Interlocked.Exchange(ref _capturedFrames, 0);
        Interlocked.Exchange(ref _sentFrames, 0);
        Interlocked.Exchange(ref _droppedFrames, 0);
        Interlocked.Exchange(ref _sendFailures, 0);
        Interlocked.Exchange(ref _lastWriteMs, 0);
        Interlocked.Exchange(ref _maxWriteMs, 0);
    }

    private void ResetResampler()
    {
        _outputFrameCount = 0;
        _hasPreviousSourceSample = false;
        _previousSourceSample = 0f;
        _previousSourceCaptureUnixNs = 0L;
        _sourceSampleIndex = 0;
        _nextOutputSourcePosition = 0d;
        _outputFrameCaptureUnixNs = 0L;
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

    private void FlushPendingStatus()
    {
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

    private void OnApplicationPause(bool pauseStatus)
    {
        if (pauseStatus)
        {
            StopStreaming(false);
        }
    }

    private void OnDisable()
    {
        StopStreaming(false);
    }

    private void OnDestroy()
    {
        StopStreaming(false);
    }

    private void OnApplicationQuit()
    {
        StopStreaming(false);
    }
}
