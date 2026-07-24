using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Threading;
using LitJson;
using Network;
using Robot;
using Robot.Conf;
using Robot.Network;
using Robot.V2.Network;
using Unity.XR.PICO.TOBSupport;
using UnityEngine;
using UnityEngine.UI;
using XRoboToolkit.Network;

public partial class UICameraCtrl : MonoBehaviour
{
    public GameObject RemoteCameraWindowObj;

    public CameraRequestDialog CameraRequestDialog;
    public ResolutionDialog ResolutionDialog;
    public CameraSendInputDialog CameraSendInputDialog;
    public CustomButton ListenCameraBtn;
    public CustomButton CameraSendToBtn;

    public CustomButton ListenPCCameraBtn;
    public Dropdown cameraDropdown;

    public SetLERE setLere;

    private JsonData _recordJson;
    public Text CameraStatusText;

    public CustomButton listenBtn;
    public VideoSourceManager videoSourceManager;

    public TcpManager tcpManager;
    private string logTag => "UICameraCtrl";

    private int streamingPort = 12345;
    private RemotePcmAudioPlayer remoteAudioPlayer;
    private PicoMicrophoneStreamer microphoneStreamer;
    private RemoteVideoProjectionRenderer videoProjectionRenderer;
    private OperatorControlClient operatorControlClient;
    private Coroutine cameraRequestCoroutine;
    private Coroutine microphoneStartCoroutine;
    private string activeAudioHost;
    private int audioSessionId;
    private int negotiatedAudioStreamPort;
    private bool audioDownlinkExplicitlyDisabled;
    private int negotiatedMicrophoneUploadPort;
    private string negotiatedMicrophoneUploadToken;
    private string currentAudioRequestId;
    private bool audioPortAckReceived;
    private bool acceptAudioPortConfig;
    private bool duplexAudioStarted;
    private bool microphoneMuted;
    private bool microphonePermissionRequested;
    private bool resumeDuplexAudioAfterPause;
    private bool controlClientConnected;
    private bool controlReconnectSuppressed;
    private float nextControlWatchdogRealtime;
    private long controlPingCount;
    private readonly List<byte> clientProtocolBuffer = new List<byte>();

    private const float AudioPortAckTimeoutSeconds = 1.5f;
    private const float MicrophonePermissionTimeoutSeconds = 10f;
    private const float ControlConnectTimeoutSeconds = 3f;
    private const float ControlReconnectDelaySeconds = 1f;
    private const float ControlWatchdogIntervalSeconds = 1f;
    private const string AudioPortConfigSchema = "g1_wuji_audio_ports_v2";
    private const string MicrophoneUploadProtocol = "g1_wuji_audio_uplink_v1";
    private const int MaxControlCommandBytes = 1024;
    private const int MaxControlPayloadBytes = 1024 * 1024;

    [Space(30)] [Header("Record")] public RecordDialog RecordDialog;
    public CustomButton RecordBtn;

    public Toggle trackingToggle;
    public Toggle visionToggle;

    private void Awake()
    {
        CrashProbe.Breadcrumb("camera_ctrl.awake");
        RecordBtn.OnChange += OnRecordBtn;
        TcpHandler.ReceiveFunctionEvent += OnNetReceive;
        CameraHandle.AddStateListener(OnCameraStateChanged);

        // Refactoring
        listenBtn.OnChange += OnListenCameraBtn;

        // Bind event
        tcpManager.OnServerReceived += OnServerReceived;
        operatorControlClient = new OperatorControlClient();
        operatorControlClient.Connected += OnControlClientConnected;
        operatorControlClient.Disconnected += OnControlClientDisconnected;
        operatorControlClient.DataReceived += OnClientDataReceived;
        operatorControlClient.Error += OnControlClientError;
        EnsureVideoProjectionRenderer();
    }

    private void OnServerReceived(byte[] data)
    {
        // apply protocol
        Utils.WriteLog(logTag, $"OnServerReceived: {data.Length} bytes");

        // Log first few bytes for debugging
        if (data.Length > 0)
        {
            string hexDump = BitConverter.ToString(data, 0, Math.Min(data.Length, 32));
            Utils.WriteLog(logTag, $"First bytes (hex): {hexDump}");
        }

        EventExecutor.ExecuteInUpdate(() =>
        {
            try
            {
                Utils.WriteLog(logTag, $"Processing data...");

                // Check if it's a complete message first
                if (!NetworkDataProtocolSerializer.IsCompleteMessage(data))
                {
                    Utils.WriteLog(logTag, $"Incomplete message received");
                    return;
                }

                var protocol = NetworkDataProtocolSerializer.Deserialize(data);
                Utils.WriteLog(logTag,
                    $"Successfully deserialized: command='{protocol.command}', data length={protocol.data.Length}");

                // Process the command
                if (NetworkCommander.Instance == null)
                {
                    Utils.WriteLog(logTag, $"NetworkCommander.Instance is null");
                    return;
                }

                if (NetworkCommander.Instance.Processor == null)
                {
                    Utils.WriteLog(logTag, $"NetworkCommander.Instance.Processor is null");
                    return;
                }

                bool handled = NetworkCommander.Instance.Processor.ProcessCommand(protocol);
                Utils.WriteLog(logTag, $"Command processed: {handled}");
            }
            catch (Exception e)
            {
                Utils.WriteLog(logTag, $"Error processing command: {e.Message}");
                Utils.WriteLog(logTag, $"Stack trace: {e.StackTrace}");

                // Log detailed buffer analysis
                string bufferDebug = NetworkDataProtocolSerializer.DebugBufferContents(data);
                Utils.WriteLog(logTag, $"Buffer analysis:\n{bufferDebug}");
            }
        });
    }

    private void OnClientReceived(string msg)
    {
        Utils.WriteLog(logTag, $"OnClientReceived: {msg}");
    }

    private void OnControlClientConnected()
    {
        EventExecutor.ExecuteInUpdate(() =>
        {
            if (operatorControlClient == null || !operatorControlClient.IsConnected)
            {
                return;
            }
            controlClientConnected = true;
            controlReconnectSuppressed = false;
            CrashProbe.Breadcrumb("operator_control.connected");
        });
    }

    private void OnControlClientDisconnected()
    {
        EventExecutor.ExecuteInUpdate(() =>
        {
            // Events cross from a worker thread to Unity's update queue. Ignore a
            // delayed disconnect from an older run after a newer run connected.
            if (operatorControlClient != null && operatorControlClient.IsConnected)
            {
                return;
            }
            HandleControlConnectionLost("disconnected");
        });
    }

    private void OnControlClientError(string message)
    {
        EventExecutor.ExecuteInUpdate(() =>
        {
            CrashProbe.Breadcrumb("operator_control.error", message, LogType.Warning);
            LogWindow.Warn($"Operator control client error: {message}");
        });
    }

    private void HandleControlConnectionLost(string reason)
    {
        controlClientConnected = false;
        if (controlReconnectSuppressed ||
            !isActiveAndEnabled ||
            listenBtn == null ||
            !listenBtn.On ||
            string.IsNullOrEmpty(activeAudioHost))
        {
            return;
        }

        LogWindow.Warn($"Operator control connection lost ({reason}); renegotiating session.");
        CrashProbe.Breadcrumb("operator_control.lost", reason, LogType.Warning);
        StopCameraRequestCoroutine();
        StopDuplexAudio(false);
        cameraRequestCoroutine = StartCoroutine(
            ReconnectCameraSessionAfterDelay(activeAudioHost));
    }

    private IEnumerator ReconnectCameraSessionAfterDelay(string host)
    {
        yield return new WaitForSecondsRealtime(ControlReconnectDelaySeconds);
        cameraRequestCoroutine = null;
        if (listenBtn != null && listenBtn.On && !string.IsNullOrEmpty(host))
        {
            RequestCameraStream(host);
        }
    }

    private void OnClientDataReceived(byte[] data)
    {
        if (data == null || data.Length == 0)
        {
            return;
        }

        // PING is a transport heartbeat, not a UI event.  Reply on the receive
        // thread so a busy Unity frame cannot revoke video and both audio
        // directions merely because the main-thread event queue was delayed.
        if (NetworkDataProtocolSerializer.TryDeserialize(
                data,
                out NetworkDataProtocol protocol) &&
            string.Equals(protocol.command, NetworkCommand.PING, StringComparison.Ordinal))
        {
            bool sent = operatorControlClient != null &&
                        operatorControlClient.SendCommand(NetworkCommand.PONG, protocol.data);
            long count = Interlocked.Increment(ref controlPingCount);
            if (count == 1 || count % 10 == 0 || !sent)
            {
                CrashProbe.Breadcrumb(
                    sent ? "operator_control.pong" : "operator_control.pong_failed",
                    $"count={count}",
                    sent ? LogType.Log : LogType.Warning);
            }
            return;
        }

        EventExecutor.ExecuteInUpdate(() => HandleClientDataChunk(data));
    }

    private void HandleClientDataChunk(byte[] data)
    {
        if (clientProtocolBuffer.Count == 0 && LooksLikeJson(data))
        {
            ApplyAudioPortConfig(data);
            return;
        }

        clientProtocolBuffer.AddRange(data);
        while (TryTakeClientProtocolFrame(out byte[] frame))
        {
            HandleClientProtocolFrame(frame);
        }
    }

    private void HandleClientProtocolFrame(byte[] frame)
    {
        if (NetworkDataProtocolSerializer.TryDeserialize(
                frame,
                out NetworkDataProtocol protocol) &&
            string.Equals(protocol.command, NetworkCommand.PING, StringComparison.Ordinal))
        {
            operatorControlClient?.SendCommand(NetworkCommand.PONG, protocol.data);
            return;
        }

        ApplyAudioPortConfig(frame);
    }

    private bool TryTakeClientProtocolFrame(out byte[] frame)
    {
        frame = null;
        if (clientProtocolBuffer.Count < sizeof(int))
        {
            return false;
        }

        int commandLength = ReadLittleEndianInt32(clientProtocolBuffer, 0);
        if (commandLength < 0 || commandLength > MaxControlCommandBytes)
        {
            LogWindow.Warn("Discarding malformed control response: invalid command length.");
            clientProtocolBuffer.Clear();
            return false;
        }

        int dataLengthOffset = sizeof(int) + commandLength;
        if (clientProtocolBuffer.Count < dataLengthOffset + sizeof(int))
        {
            return false;
        }

        int dataLength = ReadLittleEndianInt32(clientProtocolBuffer, dataLengthOffset);
        if (dataLength < 0 || dataLength > MaxControlPayloadBytes)
        {
            LogWindow.Warn("Discarding malformed control response: invalid payload length.");
            clientProtocolBuffer.Clear();
            return false;
        }

        int totalLength = dataLengthOffset + sizeof(int) + dataLength;
        if (clientProtocolBuffer.Count < totalLength)
        {
            return false;
        }

        frame = clientProtocolBuffer.GetRange(0, totalLength).ToArray();
        clientProtocolBuffer.RemoveRange(0, totalLength);
        return true;
    }

    private static int ReadLittleEndianInt32(List<byte> buffer, int offset)
    {
        return buffer[offset] |
               (buffer[offset + 1] << 8) |
               (buffer[offset + 2] << 16) |
               (buffer[offset + 3] << 24);
    }

    private static bool LooksLikeJson(byte[] data)
    {
        for (int i = 0; i < data.Length; i++)
        {
            byte value = data[i];
            if (value == (byte)' ' || value == (byte)'\t' || value == (byte)'\r' || value == (byte)'\n')
            {
                continue;
            }

            return value == (byte)'{';
        }

        return false;
    }

    private void ApplyAudioPortConfig(byte[] data)
    {
        if (!TryReadAudioPortAck(
                data,
                out int audioStreamPort,
                out int microphoneUploadPort,
                out string microphoneUploadToken,
                out string audioRequestId,
                out string videoProjection,
                out string videoStereoLayout))
        {
            CrashProbe.Breadcrumb("audio_config.invalid", $"bytes={data?.Length ?? 0}", LogType.Warning);
            return;
        }

        if (!string.Equals(audioRequestId, currentAudioRequestId, StringComparison.Ordinal))
        {
            CrashProbe.Breadcrumb("audio_config.stale", audioRequestId, LogType.Warning);
            LogWindow.Warn("Ignoring stale AUDIO_CONFIG from an older control request.");
            return;
        }

        if (!acceptAudioPortConfig ||
            string.IsNullOrEmpty(activeAudioHost) ||
            listenBtn == null ||
            !listenBtn.On)
        {
            return;
        }

        bool portsChanged = audioStreamPort != GetRemoteAudioPort() ||
                            (microphoneUploadPort > 0 &&
                             microphoneUploadPort != GetMicrophoneUploadPort()) ||
                            !string.Equals(
                                microphoneUploadToken,
                                negotiatedMicrophoneUploadToken,
                                StringComparison.Ordinal);
        if (audioStreamPort > 0)
        {
            negotiatedAudioStreamPort = audioStreamPort;
            audioDownlinkExplicitlyDisabled = false;
        }
        else
        {
            negotiatedAudioStreamPort = 0;
            audioDownlinkExplicitlyDisabled = true;
        }

        if (microphoneUploadPort > 0)
        {
            negotiatedMicrophoneUploadPort = microphoneUploadPort;
            negotiatedMicrophoneUploadToken = microphoneUploadToken;
        }
        else
        {
            negotiatedMicrophoneUploadPort = 0;
            negotiatedMicrophoneUploadToken = null;
        }

        audioPortAckReceived = true;
        acceptAudioPortConfig = false;
        ApplyVideoProjection(videoProjection, videoStereoLayout);
        CrashProbe.Breadcrumb(
            "audio_config.applied",
            $"downlink={GetRemoteAudioPort()} mic={GetMicrophoneUploadPort()} projection={videoProjection} layout={videoStereoLayout}");
        LogWindow.Info(
            $"Audio ports negotiated: downlink={GetRemoteAudioPort()}, " +
            $"microphone_upload={GetMicrophoneUploadPort()}.");

        if (duplexAudioStarted && portsChanged)
        {
            StartDuplexAudioForSession(activeAudioHost, audioSessionId);
        }
    }

    private static bool TryReadAudioPortAck(
        byte[] data,
        out int audioStreamPort,
        out int microphoneUploadPort,
        out string microphoneUploadToken,
        out string audioRequestId,
        out string videoProjection,
        out string videoStereoLayout)
    {
        audioStreamPort = 0;
        microphoneUploadPort = 0;
        microphoneUploadToken = null;
        audioRequestId = null;
        videoProjection = RemoteVideoProjectionRenderer.FlatProjection;
        videoStereoLayout = RemoteVideoProjectionRenderer.MonoLayout;
        byte[] jsonPayload = null;

        if (NetworkDataProtocolSerializer.TryDeserialize(data, out NetworkDataProtocol protocol))
        {
            bool isAudioConfig = string.Equals(
                protocol.command,
                NetworkCommand.AUDIO_CONFIG,
                StringComparison.Ordinal);
            bool isLegacyAck = string.Equals(
                protocol.command,
                NetworkCommand.OPEN_CAMERA_ACK,
                StringComparison.Ordinal);
            if (!isAudioConfig && !isLegacyAck)
            {
                return false;
            }

            jsonPayload = protocol.data;
        }
        else
        {
            // Compatibility fallback for an operator bridge that sends the ACK JSON directly.
            jsonPayload = data;
        }

        if (jsonPayload == null || jsonPayload.Length == 0)
        {
            return false;
        }

        try
        {
            JsonData json = JsonMapper.ToObject(Encoding.UTF8.GetString(jsonPayload));
            if (json == null || !json.IsObject)
            {
                return false;
            }

            if (!json.ContainsKey("schema") ||
                !string.Equals(
                    json["schema"].ToString(),
                    AudioPortConfigSchema,
                    StringComparison.Ordinal))
            {
                return false;
            }

            if (!MatchesOptionalInt(json, "sample_rate", PicoMicrophoneStreamer.OutputSampleRate) ||
                !MatchesOptionalInt(json, "channels", PicoMicrophoneStreamer.OutputChannels) ||
                !MatchesOptionalString(json, "sample_format", "s16le"))
            {
                return false;
            }

            if (json.ContainsKey("video_projection"))
            {
                videoProjection = RemoteVideoProjectionRenderer.NormalizeProjection(
                    json["video_projection"].ToString());
            }
            if (json.ContainsKey("video_stereo_layout"))
            {
                videoStereoLayout = RemoteVideoProjectionRenderer.NormalizeStereoLayout(
                    json["video_stereo_layout"].ToString());
            }

            if (!json.ContainsKey("audio_request_id"))
            {
                return false;
            }
            audioRequestId = json["audio_request_id"].ToString();
            if (string.IsNullOrWhiteSpace(audioRequestId) ||
                audioRequestId.Length < 16 ||
                audioRequestId.Length > 128)
            {
                return false;
            }

            if (!json.ContainsKey("audio_stream_port") ||
                !TryParsePortAllowDisabled(json["audio_stream_port"], out audioStreamPort))
            {
                return false;
            }

            if (!json.ContainsKey("microphone_upload_port") ||
                !TryParsePortAllowDisabled(
                    json["microphone_upload_port"],
                    out microphoneUploadPort))
            {
                return false;
            }

            if (microphoneUploadPort > 0)
            {
                bool protocolMatches = json.ContainsKey("microphone_upload_protocol") &&
                                       string.Equals(
                                           json["microphone_upload_protocol"].ToString(),
                                           MicrophoneUploadProtocol,
                                           StringComparison.Ordinal);
                string token = json.ContainsKey("microphone_upload_token")
                    ? json["microphone_upload_token"].ToString()
                    : null;
                bool tokenValid = !string.IsNullOrWhiteSpace(token) &&
                                  Encoding.ASCII.GetByteCount(token) >= 16 &&
                                  Encoding.ASCII.GetByteCount(token) <= 256;
                if (!protocolMatches || !tokenValid)
                {
                    microphoneUploadPort = 0;
                }
                else
                {
                    microphoneUploadToken = token;
                }
            }

            return true;
        }
        catch (Exception)
        {
            return false;
        }
    }

    private static bool TryParsePortAllowDisabled(JsonData value, out int port)
    {
        port = 0;
        return value != null &&
               int.TryParse(value.ToString(), out port) &&
               port >= 0 &&
               port <= 65535;
    }

    private static bool MatchesOptionalInt(JsonData json, string key, int expected)
    {
        if (!json.ContainsKey(key))
        {
            return true;
        }

        return int.TryParse(json[key].ToString(), out int value) && value == expected;
    }

    private static bool MatchesOptionalString(JsonData json, string key, string expected)
    {
        return !json.ContainsKey(key) ||
               string.Equals(json[key].ToString(), expected, StringComparison.Ordinal);
    }

    private void EnsureVideoProjectionRenderer()
    {
        if (RemoteCameraWindowObj == null)
        {
            return;
        }
        if (videoProjectionRenderer == null)
        {
            videoProjectionRenderer =
                RemoteCameraWindowObj.GetComponent<RemoteVideoProjectionRenderer>();
            if (videoProjectionRenderer == null)
            {
                videoProjectionRenderer =
                    RemoteCameraWindowObj.AddComponent<RemoteVideoProjectionRenderer>();
            }
        }
        videoProjectionRenderer.SetLegacyStereoRenderer(setLere);
    }

    private void ApplyVideoProjection(string projection, string stereoLayout)
    {
        EnsureVideoProjectionRenderer();
        if (videoProjectionRenderer == null)
        {
            return;
        }
        videoProjectionRenderer.Configure(projection, stereoLayout);
        CrashProbe.Breadcrumb(
            "video_projection.apply",
            $"projection={projection} layout={stereoLayout}");
        LogWindow.Info(
            $"Remote video projection={projection}, stereo_layout={stereoLayout}.");
    }

    public void OnListenCameraBtn(bool on)
    {
        if (on)
        {
            // check if the dropdown is updated
            if (cameraDropdown.options == null || cameraDropdown.options.Count == 0) return;

            // get the camera source from the dropdown
            var cameraSource = cameraDropdown.options[cameraDropdown.value].text;
            CrashProbe.Breadcrumb("listen.on", cameraSource);

            // Update camera source, including shaders, etc.
            videoSourceManager.UpdateVideoSource(cameraSource);

            // send video stream request to the server
            CameraSendInputDialog.Show(
                RequestCameraStream,
                cameraSource,
                () => listenBtn.SetOn(false)
            );
        }
        else
        {
            CrashProbe.Breadcrumb("listen.off");
            controlReconnectSuppressed = true;
            if (controlClientConnected && operatorControlClient != null)
            {
                operatorControlClient.SendCommand(NetworkCommand.CLOSE_CAMERA, new byte[0]);
            }
            if (operatorControlClient != null && operatorControlClient.IsRunning)
            {
                operatorControlClient.DisconnectSilently();
            }
            controlClientConnected = false;
            StopCameraRequestCoroutine();
            StopDuplexAudio();
            RemoteCameraWindowObj.SetActive(false);
        }

        // Update button
        listenBtn.SetOn(on);
    }

    public void RequestCameraStream(string ip)
    {
        if (listenBtn == null || !listenBtn.On || string.IsNullOrWhiteSpace(ip))
        {
            CrashProbe.Breadcrumb("camera_request.ignored", ip, LogType.Warning);
            LogWindow.Warn("Camera/audio request ignored because Listen is off or the operator IP is empty.");
            return;
        }

        CrashProbe.Breadcrumb("camera_request.start", ip);
        StopCameraRequestCoroutine();
        cameraRequestCoroutine = StartCoroutine(RequestCameraStreamCoroutine(ip));
    }

    IEnumerator RequestCameraStreamCoroutine(string ip)
    {
        int sessionId = BeginAudioSession(ip);

        if (TcpServer.Status == ServerStatus.Started)
        {
            // Close TcpServer first
            TcpManager.Instance.StopServer();
        }

        yield return new WaitForSeconds(0.1f);

        // Get camera parameters
        var camPara = VideoSourceConfigManager.Instance.CameraParameters;

        // Start listening to the camera
        RemoteCameraWindowObj.SetActive(true);
        RemoteCameraWindowObj.GetComponent<RemoteCameraWindow>().StartListen(camPara.width, camPara.height, camPara.fps,
            camPara.bitrate, streamingPort);

        yield return new WaitForSeconds(0.2f);

        // Reset LERE
        setLere.ResetCanvases();

        yield return new WaitForSeconds(0.1f);

        // Reconnect for every Listen request so an existing client from another
        // operator/profile cannot leak a stale AUDIO_CONFIG into this session.
        if (operatorControlClient != null && operatorControlClient.IsRunning)
        {
            controlReconnectSuppressed = true;
            operatorControlClient.DisconnectSilently();
            controlClientConnected = false;
            yield return new WaitForSeconds(0.1f);
        }

        // Initialize TcpClient; server IP is the video source/operator IP.
        controlClientConnected = false;
        controlReconnectSuppressed = false;
        operatorControlClient.Connect(ip, tcpManager != null ? tcpManager.port : 13579);
        float connectDeadline = Time.realtimeSinceStartup + ControlConnectTimeoutSeconds;
        while (sessionId == audioSessionId &&
               listenBtn != null &&
               listenBtn.On &&
               !controlClientConnected &&
               Time.realtimeSinceStartup < connectDeadline)
        {
            yield return null;
        }

        if (sessionId != audioSessionId ||
            listenBtn == null ||
            !listenBtn.On)
        {
            cameraRequestCoroutine = null;
            yield break;
        }

        if (!controlClientConnected)
        {
            LogWindow.Warn("Operator control connection timed out; retrying.");
            controlReconnectSuppressed = true;
            operatorControlClient.DisconnectSilently();
            controlReconnectSuppressed = false;
            yield return new WaitForSecondsRealtime(ControlReconnectDelaySeconds);
            cameraRequestCoroutine = null;
            if (sessionId == audioSessionId && listenBtn.On)
            {
                RequestCameraStream(ip);
            }
            yield break;
        }

        var localIP = Utils.GetLocalIPv4();

        // Send request to the server
        var customConfig = CameraRequestSerializer.FromCameraParameters(
            camPara,
            0,
            2, // (int)PXRCaptureRenderMode.PXRCapture_RenderMode_3D
            VideoSourceConfigManager.Instance.CurrentVideoSource.camera,
            localIP, // local ip
            streamingPort);
        
        LogWindow.Info("Requesting camera stream with config: " + customConfig.ToString());

        // Utils.WriteLog(logTag, $"send camera config: {customConfig}");
        var data = CameraRequestSerializer.Serialize(customConfig);

        // Use network commander
        clientProtocolBuffer.Clear();
        acceptAudioPortConfig = true;
        operatorControlClient.SendCommand(
            NetworkCommand.AUDIO_SESSION,
            Encoding.ASCII.GetBytes(currentAudioRequestId));
        operatorControlClient.SendCommand(NetworkCommand.OPEN_CAMERA, data);

        float ackDeadline = Time.realtimeSinceStartup + AudioPortAckTimeoutSeconds;
        while (sessionId == audioSessionId &&
               !audioPortAckReceived &&
               Time.realtimeSinceStartup < ackDeadline)
        {
            yield return null;
        }

        if (sessionId == audioSessionId)
        {
            if (!audioPortAckReceived)
            {
                acceptAudioPortConfig = false;
                LogWindow.Warn(
                    $"AUDIO_CONFIG timed out; using configured ports " +
                    $"{GetRemoteAudioPort()}/{GetMicrophoneUploadPort()}.");
            }

            StartDuplexAudioForSession(ip, sessionId);
        }

        cameraRequestCoroutine = null;
    }

    private void OnCameraStateChanged(int state)
    {
        CameraStatusText.text = state.ToString();
    }


    private void OnDestroy()
    {
        StopCameraRequestCoroutine();
        StopDuplexAudio();
        TcpHandler.ReceiveFunctionEvent -= OnNetReceive;
        CameraHandle.RemoveStateListener(OnCameraStateChanged);
        if (tcpManager != null)
        {
            tcpManager.OnServerReceived -= OnServerReceived;
        }
        if (operatorControlClient != null)
        {
            operatorControlClient.Connected -= OnControlClientConnected;
            operatorControlClient.Disconnected -= OnControlClientDisconnected;
            operatorControlClient.DataReceived -= OnClientDataReceived;
            operatorControlClient.Error -= OnControlClientError;
            operatorControlClient.Dispose();
            operatorControlClient = null;
        }
    }

    private int BeginAudioSession(string ip)
    {
        if (string.IsNullOrWhiteSpace(ip))
        {
            return -1;
        }

        StopDuplexAudio(false);
        activeAudioHost = ip.Trim();
        negotiatedAudioStreamPort = 0;
        audioDownlinkExplicitlyDisabled = false;
        negotiatedMicrophoneUploadPort = 0;
        negotiatedMicrophoneUploadToken = null;
        audioPortAckReceived = false;
        acceptAudioPortConfig = false;
        duplexAudioStarted = false;
        microphonePermissionRequested = false;
        clientProtocolBuffer.Clear();
        currentAudioRequestId = Guid.NewGuid().ToString("N");
        CrashProbe.Breadcrumb(
            "audio_session.begin",
            $"host={activeAudioHost} request_id={currentAudioRequestId}");
        ApplyVideoProjection(
            RemoteVideoProjectionRenderer.FlatProjection,
            RemoteVideoProjectionRenderer.MonoLayout);
        return ++audioSessionId;
    }

    private void StartDuplexAudioForSession(string ip, int sessionId)
    {
        if (sessionId != audioSessionId ||
            string.IsNullOrWhiteSpace(ip) ||
            listenBtn == null ||
            !listenBtn.On)
        {
            return;
        }

        activeAudioHost = ip.Trim();
        EnsureAudioComponents();
        int remoteAudioPort = GetRemoteAudioPort();
        if (remoteAudioPort > 0)
        {
            CrashProbe.Breadcrumb("audio_downlink.start", $"{activeAudioHost}:{remoteAudioPort}");
            remoteAudioPlayer.StartAudio(activeAudioHost, remoteAudioPort);
        }
        else
        {
            CrashProbe.Breadcrumb("audio_downlink.disabled");
            remoteAudioPlayer.StopAudio();
        }

        if (GetMicrophoneUploadPort() <= 0 ||
            string.IsNullOrEmpty(negotiatedMicrophoneUploadToken))
        {
            if (microphoneStartCoroutine != null)
            {
                StopCoroutine(microphoneStartCoroutine);
                microphoneStartCoroutine = null;
            }
            if (microphoneStreamer != null)
            {
                microphoneStreamer.StopStreaming();
            }
            LogWindow.Warn(
                "Secure Pico microphone session was not negotiated; uplink remains disabled.");
            CrashProbe.Breadcrumb("microphone_uplink.not_negotiated", "", LogType.Warning);
            duplexAudioStarted = true;
            return;
        }

        if (microphoneStartCoroutine != null)
        {
            StopCoroutine(microphoneStartCoroutine);
        }

        microphoneStartCoroutine = StartCoroutine(
            StartMicrophoneWhenAuthorized(
                activeAudioHost,
                GetMicrophoneUploadPort(),
                negotiatedMicrophoneUploadToken,
                sessionId));
        CrashProbe.Breadcrumb("microphone_uplink.authorizing", $"{activeAudioHost}:{GetMicrophoneUploadPort()}");
        duplexAudioStarted = true;
    }

    private IEnumerator StartMicrophoneWhenAuthorized(
        string host,
        int port,
        string sessionToken,
        int sessionId)
    {
#if UNITY_ANDROID && !UNITY_EDITOR
        if (!PicoMicrophoneStreamer.HasRecordPermission() && !microphonePermissionRequested)
        {
            microphonePermissionRequested = true;
            PicoMicrophoneStreamer.RequestRecordPermission();
            float permissionDeadline = Time.realtimeSinceStartup + MicrophonePermissionTimeoutSeconds;
            while (sessionId == audioSessionId &&
                   listenBtn != null &&
                   listenBtn.On &&
                   RemoteCameraWindowObj != null &&
                   RemoteCameraWindowObj.activeInHierarchy &&
                   !PicoMicrophoneStreamer.HasRecordPermission() &&
                   Time.realtimeSinceStartup < permissionDeadline)
            {
                yield return null;
            }
        }
#endif

        if (sessionId != audioSessionId ||
            listenBtn == null ||
            !listenBtn.On ||
            RemoteCameraWindowObj == null ||
            !RemoteCameraWindowObj.activeInHierarchy)
        {
            microphoneStartCoroutine = null;
            yield break;
        }

        if (!PicoMicrophoneStreamer.HasRecordPermission())
        {
            LogWindow.Warn("Pico microphone upload not started: RECORD_AUDIO permission was denied or timed out.");
            CrashProbe.Breadcrumb("microphone_uplink.permission_denied", "", LogType.Warning);
            Toast.Show("Microphone permission denied; voice upload is disabled.");
            microphoneStartCoroutine = null;
            yield break;
        }

        microphoneStreamer.SetMuted(microphoneMuted);
        microphoneStreamer.StartStreaming(host, port, sessionToken);
        CrashProbe.Breadcrumb("microphone_uplink.start", $"{host}:{port}");
        microphoneStartCoroutine = null;
    }

    private void StopDuplexAudio(bool clearHost = true)
    {
        CrashProbe.Breadcrumb(
            "duplex_audio.stop",
            $"clear_host={clearHost} had_host={!string.IsNullOrEmpty(activeAudioHost)}");
        audioSessionId++;
        duplexAudioStarted = false;

        if (microphoneStartCoroutine != null)
        {
            StopCoroutine(microphoneStartCoroutine);
            microphoneStartCoroutine = null;
        }

        if (remoteAudioPlayer != null)
        {
            remoteAudioPlayer.StopAudio();
        }

        if (microphoneStreamer != null)
        {
            microphoneStreamer.StopStreaming();
        }

        negotiatedAudioStreamPort = 0;
        audioDownlinkExplicitlyDisabled = false;
        negotiatedMicrophoneUploadPort = 0;
        negotiatedMicrophoneUploadToken = null;
        audioPortAckReceived = false;
        acceptAudioPortConfig = false;
        microphonePermissionRequested = false;
        currentAudioRequestId = null;
        clientProtocolBuffer.Clear();

        if (clearHost)
        {
            activeAudioHost = null;
        }
    }

    private void EnsureAudioComponents()
    {
        if (remoteAudioPlayer == null)
        {
            remoteAudioPlayer = RemoteCameraWindowObj.GetComponent<RemotePcmAudioPlayer>();
            if (remoteAudioPlayer == null)
            {
                remoteAudioPlayer = RemoteCameraWindowObj.AddComponent<RemotePcmAudioPlayer>();
            }
        }

        if (microphoneStreamer == null)
        {
            microphoneStreamer = RemoteCameraWindowObj.GetComponent<PicoMicrophoneStreamer>();
            if (microphoneStreamer == null)
            {
                microphoneStreamer = RemoteCameraWindowObj.AddComponent<PicoMicrophoneStreamer>();
            }
        }
    }

    private int GetRemoteAudioPort()
    {
        if (audioDownlinkExplicitlyDisabled)
        {
            return 0;
        }

        if (negotiatedAudioStreamPort > 0)
        {
            return negotiatedAudioStreamPort;
        }

        if (VideoSourceConfigManager.Instance == null)
        {
            return RemotePcmAudioPlayer.DefaultPort;
        }

        int configuredPort = VideoSourceConfigManager.Instance.AudioStreamPort;
        return configuredPort > 0 ? configuredPort : RemotePcmAudioPlayer.DefaultPort;
    }

    private int GetMicrophoneUploadPort()
    {
        return negotiatedMicrophoneUploadPort;
    }

    public void SetMicrophoneMuted(bool muted)
    {
        microphoneMuted = muted;
        if (microphoneStreamer != null)
        {
            microphoneStreamer.SetMuted(muted);
        }
    }

    private void StopCameraRequestCoroutine()
    {
        if (cameraRequestCoroutine == null)
        {
            return;
        }

        StopCoroutine(cameraRequestCoroutine);
        cameraRequestCoroutine = null;
    }

    private void OnRecordBtn(bool on)
    {
        if (on)
        {
            OpenRecord();
        }
        else
        {
            StopRecord();
        }
    }

    private void OpenRecord()
    {
        if (!visionToggle.isOn && !trackingToggle.isOn)
        {
            LogWindow.Error("Please select at least one option: Tracking or Vision.");
            return;
        }

        // Vision data
        if (visionToggle.isOn)
        {
            if (trackingToggle.isOn)
            {
                // Start together
                RecordDialog.Show(() =>
                {
                    StartRecord(RecordDialog.ResolutionWidth, RecordDialog.ResolutionHeight,
                        RecordDialog.Fps, RecordDialog.Bitrate, true);
                }, null);
            }
            else
            {
                // Vision data only
                RecordDialog.Show(() =>
                {
                    StartRecord(RecordDialog.ResolutionWidth, RecordDialog.ResolutionHeight,
                        RecordDialog.Fps, RecordDialog.Bitrate, false);
                }, null);
            }
        }
        else
        {
            if (trackingToggle.isOn)
            {
                // Only tracking data, use fixed resolution
                _recordTrackingData = true;
                OnStartRecordTracking(2160, 810);
                RecordBtn.SetOn(true);
            }
        }
    }

    private void StartRecord(int width, int height, int fps, int bitrate,
        bool onTrackingData)
    {
        LogWindow.Info($"Start record {width}x{height}@{fps} fps {bitrate} bps Tracking: {onTrackingData}");
        //The VR camera image acquisition is only effective on the B-end device of Pico4U.
        if (!Utils.IsPico4U())
        {
            Toast.Show("Please use B-end pico4U devices and apply for camera permissions.");
            return;
        }

        Toast.Show("Start Record");
        Debug.Log("StartRecord:" + width + "," + height + "," + fps + "," + bitrate + "," + onTrackingData);
        CameraHandle.StartCameraPreview(width, height, fps, bitrate, 0,
            (int)PXRCaptureRenderMode.PXRCapture_RenderMode_3D,
            () =>
            {
                string timeStamp = DateTime.Now.ToString("yyyyMMdd_HHmmss");
                string trackingFileName = $"CameraRecord_{timeStamp}.mp4";
                string filePath = Path.Combine("/sdcard/Download/", trackingFileName);
                LogWindow.Warn("Vision file path: " + filePath);
                CameraHandle.StartRecord(filePath);
                _recordTrackingData = onTrackingData;
                if (_recordTrackingData)
                    OnStartRecordTracking(width, height);
            });

        RecordBtn.SetOn(true);
        // PreviewCameraTog.gameObject.SetActive(true);
    }

    public void UpdateCameraParamsNew()
    {
        ResolutionDialog.Show("Setting the resolution", (width, height) =>
        {
            string cameraIntrinsics = CameraHandle.GetCameraIntrinsics(width, height);
            string cameraExtrinsics = CameraHandle.GetCameraExtrinsics();

            string saveStr = "CameraExtrinsics:" + cameraExtrinsics + "\n";
            saveStr += "cameraIntrinsics:" + cameraIntrinsics;
            WriteLocalText(string.Format("cameraParams_{0}x{1}", width, height), saveStr);
            Toast.Show("Parameter saved successfully!");
        }, null);
    }

    private void WriteLocalText(string fileName, string content)
    {
        string parentPath = Application.persistentDataPath;
        string filePath = Path.Combine(parentPath, fileName + ".txt");
        using (StreamWriter writer = new StreamWriter(filePath, false))
        {
            writer.Write(content + "\n");
        }

        Debug.Log("The file has been successfully written: " + filePath);
    }

    private void StopRecord()
    {
        Debug.Log(this + "StopRecord");
        LogWindow.Info("Stop record");
        if (_writer != null)
        {
            _writer.Close();
            _writer = null;
        }

        CameraHandle.StopPreview();
        CameraHandle.CloseCamera();
        RecordBtn.SetOn(false);
    }

    private void StopSendImage()
    {
        CameraHandle.StopPreview();
        CameraHandle.CloseCamera();
        CameraSendToBtn.SetOn(false);
    }

    public void OnRemoteCameraBtn()
    {
        Toast.Show("Request  camera screen on PC!");
        //Request camera screen on PC
        TcpHandler.SendFunctionValue("requestCameraList", "");
    }

    private StreamWriter _writer;
    private bool _recordTrackingData = false;
    private JsonData _trackingJsonData = new JsonData();
    private TrackingData _trackingData = new TrackingData();

    private void OnStartRecordTracking(int width, int height)
    {
        LogWindow.Info($"Start record tracking data: {width}x{height}");
        Debug.Log("OnStartRecordTracking");
        string timeStamp = DateTime.Now.ToString("yyyyMMdd_HHmmss");
        string trackingFileName = $"trackingData_{timeStamp}.txt";
        string filePath = Path.Combine("/sdcard/Download/", trackingFileName);
        Debug.Log("trackingFilePath:" + filePath);
        LogWindow.Warn("Tracking file path:" + filePath);
        _writer = new StreamWriter(filePath, true);
        _writer.AutoFlush = true; // Enable automatic refresh to prevent data loss

        JsonData cameraParam = new JsonData();
        long nsTime = Utils.GetCurrentTimestamp();
        cameraParam["notice"] =
            "This is the timestamp and head pose information when obtaining the image for the first frame.";
        cameraParam["timeStampNs"] = nsTime;
        //Convert coordinate system to right-handed system (X right, Y up, Z in)

        string cameraExtrinsics = CameraHandle.GetCameraExtrinsics();
        string cameraIntrinsics = CameraHandle.GetCameraIntrinsics(width, height);
        cameraParam["cameraExtrinsics"] = cameraExtrinsics;
        cameraParam["cameraIntrinsics"] = cameraIntrinsics;
        _writer.WriteLine(cameraParam.ToJson());
    }

    private void Update()
    {
        RunControlConnectionWatchdog();
        if (_recordTrackingData)
        {
            if (_writer != null)
            {
                _trackingData.Get(ref _trackingJsonData);
                _writer.WriteLine(_trackingJsonData.ToJson());
            }
        }
    }

    private void RunControlConnectionWatchdog()
    {
        float now = Time.realtimeSinceStartup;
        if (now < nextControlWatchdogRealtime)
        {
            return;
        }
        nextControlWatchdogRealtime = now + ControlWatchdogIntervalSeconds;

        if (controlReconnectSuppressed ||
            cameraRequestCoroutine != null ||
            listenBtn == null ||
            !listenBtn.On ||
            string.IsNullOrEmpty(activeAudioHost) ||
            operatorControlClient == null ||
            operatorControlClient.IsConnected)
        {
            return;
        }

        CrashProbe.Breadcrumb(
            "operator_control.watchdog_reconnect",
            activeAudioHost,
            LogType.Warning);
        LogWindow.Warn("Operator control watchdog detected a lost session; renegotiating.");
        RequestCameraStream(activeAudioHost);
    }

    private void OnApplicationPause(bool pauseStatus)
    {
        CrashProbe.Breadcrumb("camera_ctrl.pause", pauseStatus.ToString());
        if (pauseStatus)
        {
            resumeDuplexAudioAfterPause = listenBtn != null &&
                                          listenBtn.On &&
                                          !string.IsNullOrEmpty(activeAudioHost);
            StopDuplexAudio(false);
            controlReconnectSuppressed = true;
            if (operatorControlClient != null && operatorControlClient.IsRunning)
            {
                operatorControlClient.DisconnectSilently();
            }
            controlClientConnected = false;
        }

        if (CameraHandle.GetCaptureState() == (int)PXRCaptureState.CAPTURE_STATE_CAMERA_OPENING)
        {
            if (pauseStatus)
            {
                //release camera
                CameraHandle.CloseCamera();
            }
            else
            {
                //reopen camera
                CameraHandle.OpenCamera();
            }
        }

        if (!pauseStatus &&
            resumeDuplexAudioAfterPause &&
            listenBtn != null &&
            listenBtn.On &&
            !string.IsNullOrEmpty(activeAudioHost))
        {
            // The operator revokes the microphone token when the control socket
            // goes idle. Reconnect and issue OPEN_CAMERA instead of reusing it.
            RequestCameraStream(activeAudioHost);
        }

        if (!pauseStatus)
        {
            resumeDuplexAudioAfterPause = false;
        }
    }

    private void OnDisable()
    {
        CrashProbe.Breadcrumb("camera_ctrl.disable");
        resumeDuplexAudioAfterPause = resumeDuplexAudioAfterPause ||
                                      (listenBtn != null &&
                                       listenBtn.On &&
                                       !string.IsNullOrEmpty(activeAudioHost));
        StopCameraRequestCoroutine();
        StopDuplexAudio(false);
        controlReconnectSuppressed = true;
        if (operatorControlClient != null && operatorControlClient.IsRunning)
        {
            operatorControlClient.DisconnectSilently();
        }
        controlClientConnected = false;
    }

    private void OnEnable()
    {
        CrashProbe.Breadcrumb("camera_ctrl.enable");
        if (resumeDuplexAudioAfterPause &&
            listenBtn != null &&
            listenBtn.On &&
            !string.IsNullOrEmpty(activeAudioHost))
        {
            controlReconnectSuppressed = false;
            RequestCameraStream(activeAudioHost);
            resumeDuplexAudioAfterPause = false;
        }
    }
}
