using System;
using System.Collections;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using LitJson;
using Network;
using Unity.XR.PXR;
using UnityEngine;
using UnityEngine.XR;
using CommonUsages = UnityEngine.XR.CommonUsages;
using InputDevice = UnityEngine.XR.InputDevice;

namespace Robot
{
    public class TcpHandler : MonoBehaviour
    {
        public const string Tag = ">>Tcp ";
        public const int RECEIVE_TIME_OUT_DEFAULT = 25000;
        public const int BUFFER_LEN = 1024 * 63;
        public const int TCP_PORT = 63901;

        public delegate void ReceiveFunctionMsg(string functionName, string value);

        public delegate void ReceiveMassage(NetPacket packet);

        public static event ReceiveMassage ReceiveEvent;
        public static event ReceiveFunctionMsg ReceiveFunctionEvent;

        public static bool SendTrackingData = false;
        public static bool EnterpriseDirectTrackingEnabled = true;
        private static object _sendObject = new object();
        private Queue<NetPacket> _receivePackages = new Queue<NetPacket>();
        private static readonly ConcurrentQueue<SendData> _sendDatas = new ConcurrentQueue<SendData>();

        private Socket _socket;
        private SocketState _state = SocketState.NONE;

        private bool _connectInited = false;
        private static string _address = "127.0.0.1"; // PC IP Address
        private static string _localAddress = ""; // Optional source address for deterministic routing
        private int _port = 8888; //PC Port
        private int _sendTimeout = 15000; // timeout
        [SerializeField] private int trackingThreadIdleSleepMs = 5;
        [SerializeField] private int trackingThreadWaitForHeadSleepMs = 1;
        [SerializeField] private int trackingThreadQueueBackpressureSleepMs = 1;
        [SerializeField] private bool outputTrackingRateToLogWindow = false;
        [SerializeField] private float trackingRateLogIntervalSeconds = 1f;
        [SerializeField] private bool outputEnterpriseControllerPayloadToLog = false;
        [SerializeField] private float enterpriseControllerPayloadLogIntervalSeconds = 1f;
        private Thread _sendThread;
        private Thread _trackingThread;
        private ByteBuffer receiveBuffer;
        private string _appVersion = "";
        private string _deviceSN = "";
        private JsonData _trackingJsonData = new JsonData();
        private JsonData _sendJson = new JsonData();
        private TrackingData _trackingData = new TrackingData();
        private ConcurrentQueue<string> _sendTrackingMsg = new ConcurrentQueue<string>();
        private int _pendingDirectTrackingPackets = 0;
        private bool _cachedAppFocus = true;
        private int _cachedActiveInputDevice = (int)ActiveInputDevice.ControllerActive;
        private readonly object _controllerInputLock = new object();
        private ControllerInputState _cachedLeftControllerInput;
        private ControllerInputState _cachedRightControllerInput;
        private long _lastDirectTrackingHeadSampleSeq;
        private long _lastDirectTrackingControllerSampleSeq;
        private float _lastHeardSend = 0;
        private float _lastReconnectTime = 0;
        private bool _reconnectEnable = false;
        private readonly System.Diagnostics.Stopwatch _trackingRateStopwatch = new System.Diagnostics.Stopwatch();
        private int _trackingPacketsSentInWindow = 0;
        private string _lastTrackingSendMode = "idle";
        private string _lastDirectTrackingGateStatus;
        private long _lastEnterpriseControllerPayloadLogTicks;

        // Direct tracking instrumentation counters (reset each reporting window)
        private long _directLoopCount;
        private long _directStaleReadCount;
        private long _directNewSampleCount;
        private long _directEnqueueCount;
        private long _lastDirectStatsLogTicks;

        private void Awake()
        {
            _appVersion = Application.version;
            _sendThread = new Thread(OnSendThread);
            _trackingThread = new Thread(OnTrackingThread);
            _trackingRateStopwatch.Start();
        }

        public SocketState State
        {
            get { return _state; }
            set { _state = value; }
        }

        public string ConnectErrorInfo { get; private set; }

        public static string GetTargetIP
        {
            get { return _address; }
        }

        public static string GetSourceIP
        {
            get { return _localAddress; }
        }

        public void Connect(string address)
        {
            Connect(address, null);
        }

        public void Connect(string address, string localAddress)
        {
            LogWindow.Info(
                string.IsNullOrEmpty(localAddress)
                    ? $"Attempting to connect to {address}"
                    : $"Attempting to connect from {localAddress} to {address}");
            _address = address;
            _localAddress = localAddress ?? "";
            _reconnectEnable = false;
            Connect();
        }

        private void Connect()
        {
            _port = TCP_PORT;
            _state = SocketState.CREATE;
            ConnectErrorInfo = "";
            Debug.Log(
                $"{Tag}connect to server: source " +
                $"{(string.IsNullOrEmpty(_localAddress) ? "auto" : _localAddress)} " +
                $"target {_address} port {_port}");
            IPAddress ia = IPAddress.Parse(_address);
            try
            {
                if (_state != SocketState.CLOSE)
                {
                    Close();
                }

                lock (_sendObject)
                {
                    _socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                    _socket.Blocking = true;
                    _socket.SendTimeout = _sendTimeout;
                    _socket.NoDelay = true;
                    _socket.ReceiveTimeout = RECEIVE_TIME_OUT_DEFAULT;
                    if (!string.IsNullOrEmpty(_localAddress))
                    {
                        IPAddress localIp = IPAddress.Parse(_localAddress);
                        _socket.Bind(new IPEndPoint(localIp, 0));
                    }


                    _state = SocketState.CONNECTING;
                    _socket.BeginConnect(ia, _port, ConnectCallback, _socket);
                }
            }
            catch (SocketException e)
            {
                _state = SocketState.CONNECT_ERROR;
                ConnectErrorInfo = e.Message;
                LogWindow.Error($"TCP connection failed: {e.Message}");
                Debug.LogError(Tag + "Connection failed: " + e.Message);
            }
        }

        private void ConnectCallback(IAsyncResult async)
        {
            try
            {
                Socket socket = (Socket)async.AsyncState;
                if (socket.Connected)
                {
                    _reconnectEnable = true;
                    socket.EndConnect(async);
                    _state = SocketState.WORKING;
                    LogWindow.Info("TCP socket connection established successfully");

                    if (_sendThread.ThreadState == ThreadState.Unstarted)
                    {
                        _sendThread.Start();
                    }

                    if (_trackingThread.ThreadState == ThreadState.Unstarted)
                    {
                        _trackingThread.Start();
                    }

                    receiveBuffer = new ByteBuffer(BUFFER_LEN);
                    socket.BeginReceive(receiveBuffer.data, receiveBuffer.GetReadableCount(),
                        receiveBuffer.GetRemainCapacity(), SocketFlags.None, OnDataReceived,
                        socket);
                    _connectInited = false;
                    if (!string.IsNullOrEmpty(_deviceSN))
                    {
                        ConnectInit();
                    }

                    Debug.Log(Tag + "Socket Connected!  ");
                }
                else
                {
                    _state = SocketState.CONNECT_ERROR;
                    ConnectErrorInfo = "connect error";
                    LogWindow.Error("TCP connection failed - socket not connected");
                    Debug.LogError(Tag + "connect Error");
                }
            }
            catch (Exception e)
            {
                ConnectErrorInfo = e.ToString();
                LogWindow.Error($"TCP connection exception: {e.Message}");
                Debug.LogError(Tag + "Connect error,Exception " + e);
                _state = SocketState.CONNECT_ERROR;
            }
        }

        private void ConnectInit()
        {
            LogWindow.Info($"Initializing connection with device SN: {_deviceSN}");
            Debug.Log("ConnectInit deviceSN:" + _deviceSN);
            Send(NetCMD.PACKET_CCMD_CONNECT, _deviceSN + "|-1");
            Send(NetCMD.PACKET_CCMD_SEND_VERSION, _deviceSN + "|1.0|" + _appVersion);
        }

        public void SetDeviceSn(string sn)
        {
            _deviceSN = sn;
            if (_state == SocketState.WORKING)
            {
                ConnectInit();
            }
        }

        private void OnDataReceived(IAsyncResult ar)
        {
            if (_state != SocketState.WORKING)
            {
                return;
            }

            var socket = (Socket)ar.AsyncState;
            try
            {
                int bytesRead = socket.EndReceive(ar);
                if (bytesRead > 0)
                {
                    receiveBuffer.AddWriteIndex(bytesRead);
                    bool msgEnough;
                    do
                    {
                        msgEnough = PackageHandle.Unpack(receiveBuffer, out var package);
                        if (msgEnough)
                        {
                            if (package.Cmd == NetCMD.PACKET_CMD_FROM_CONTROLLER_COMMON_FUNCTION)
                            {
                                Debug.Log("receive function:" + package.ToString());
                                if (package.ToString().Contains("timeTest"))
                                {
                                    Send(NetCMD.PACKET_CCMD_TO_CONTROLLER_FUNCTION, "timeTest");
                                }
                            }

                            _receivePackages.Enqueue(package);
                        }
                    } while (msgEnough);

                    receiveBuffer.RemoveReadedBytes();

                    // Continue receiving data
                    socket.BeginReceive(receiveBuffer.data, receiveBuffer.GetReadableCount(),
                        receiveBuffer.GetRemainCapacity(), SocketFlags.None, OnDataReceived,
                        socket);
                }
                else
                {
                    LogWindow.Warn("TCP client disconnected - no data received");
                    Debug.Log("Client disconnected.");
                    Close();
                }
            }
            catch (Exception ex)
            {
                LogWindow.Error($"TCP data receive error: {ex.Message}");
                Debug.LogError($"Error: {ex.Message}");
                Close();
            }
        }

        private static JsonData _functionJson = new JsonData();

        public static void SendFunctionValue(string function, string value)
        {
            _functionJson["functionName"] = function;
            _functionJson["value"] = value;

            Send(NetCMD.PACKET_CCMD_TO_CONTROLLER_FUNCTION, _functionJson.ToJson());
        }


        public static void Send(byte cmd, string msg)
        {
            _sendDatas.Enqueue(new SendData(cmd, Encoding.UTF8.GetBytes(msg)));
        }

        public static void SendCustomData(byte[] msg)
        {
            _sendDatas.Enqueue(new SendData(NetCMD.PACKET_CMD_CUSTOM_TO_PC, msg));
        }


        private void Update()
        {
            _cachedAppFocus = Application.isFocused;
            _cachedActiveInputDevice = (int)PXR_HandTracking.GetActiveInputDevice();
            ControllerInputState leftInput = ReadControllerInput(XRNode.LeftHand);
            ControllerInputState rightInput = ReadControllerInput(XRNode.RightHand);
            lock (_controllerInputLock)
            {
                _cachedLeftControllerInput = leftInput;
                _cachedRightControllerInput = rightInput;
            }

            if (SendTrackingData && !ShouldSendEnterpriseTrackingDirectly())
            {
                if (_sendTrackingMsg.Count < 2)
                {
                    _trackingData.Get(ref _trackingJsonData);
                    _sendTrackingMsg.Enqueue(_trackingJsonData.ToJson());
                }
            }

            if (State == SocketState.WORKING)
            {
                //heartbeat
                if (_deviceSN != null)
                {
                    if (Time.time - _lastHeardSend > 10)
                    {
                        _lastHeardSend = Time.time;
                        Send(NetCMD.PACKET_CCMD_CLIENT_HEARTBEAT, _deviceSN);
                    }
                }
            }

            if (_reconnectEnable)
            {
                if (State == SocketState.CLOSE || State == SocketState.CONNECT_ERROR)
                {
                    if (!string.IsNullOrEmpty(_address))
                    {
                        if (Time.time - _lastReconnectTime > 2)
                        {
                            Reconnect();
                            _lastReconnectTime = Time.time;
                        }
                    }
                }
            }

            ReceivePacketHandle();
        }

        private void ReceivePacketHandle()
        {
            lock (_receivePackages)
            {
                while (_receivePackages.Count > 0)
                {
                    try
                    {
                        NetPacket packet = _receivePackages.Dequeue();

                        if (packet.Cmd == NetCMD.PACKET_CMD_FROM_CONTROLLER_COMMON_FUNCTION)
                        {
                            string content = packet.ToString();
                            if (string.IsNullOrEmpty(content))
                            {
                                continue;
                            }

                            JsonData json = JsonMapper.ToObject(content);
                            if (!json.ContainsKey("functionName") || !json.ContainsKey("value"))
                            {
                                continue;
                            }

                            string functionName = json["functionName"].ToString();
                            Debug.Log("Receive functionName:" + functionName);
                            if (ReceiveFunctionEvent != null)
                            {
                                ReceiveFunctionEvent.Invoke(functionName, json["value"].ToString());
                            }
                        }
                        else
                        {
                            if (ReceiveEvent != null)
                            {
                                ReceiveEvent.Invoke(packet);
                            }
                        }
                    }
                    catch (Exception e)
                    {
                        Debug.LogError("ReceivePacketHandle Exception:" + e.ToString());
                    }
                }
            }
        }


        public void Reconnect()
        {
            LogWindow.Info("Attempting to reconnect to TCP server");
            Connect(_address);
        }


        private void OnTrackingThread()
        {
            while (_state != SocketState.DESTROY)
            {
                if (!IsEnterpriseDirectTrackingReady())
                {
                    LogEnterpriseDirectTrackingGateIfChanged();
                    ResetDirectTrackingCache();
                    Thread.Sleep(GetClampedSleepMs(trackingThreadIdleSleepMs));
                    continue;
                }

                if (_pendingDirectTrackingPackets >= 2)
                {
                    Thread.Sleep(GetClampedSleepMs(trackingThreadQueueBackpressureSleepMs));
                    continue;
                }

                Interlocked.Increment(ref _directLoopCount);

                // Read the latest cache and its sequence numbers first. Do not build any
                // JsonData objects until we know that at least one source has advanced.
                string headPose = null;
                int headStatus = 0;
                EnterpriseCollectionRecorder.EnterpriseControllerTcpPose leftController =
                    default(EnterpriseCollectionRecorder.EnterpriseControllerTcpPose);
                EnterpriseCollectionRecorder.EnterpriseControllerTcpPose rightController =
                    default(EnterpriseCollectionRecorder.EnterpriseControllerTcpPose);
                long headSampleSeq = _lastDirectTrackingHeadSampleSeq;
                long controllerSampleSeq = _lastDirectTrackingControllerSampleSeq;
                bool hasNewTrackingSample = false;

                LogEnterpriseDirectTrackingGateIfChanged();
                if (TrackingData.HeadOn)
                {
                    if (!EnterpriseCollectionRecorder.TryGetLatestEnterpriseHeadForTcp(
                            out headPose,
                            out headStatus,
                            out headSampleSeq))
                    {
                        Thread.Sleep(GetClampedSleepMs(trackingThreadWaitForHeadSleepMs));
                        continue;
                    }

                    hasNewTrackingSample |= headSampleSeq != _lastDirectTrackingHeadSampleSeq;
                }

                if (TrackingData.ControllerOn)
                {
                    EnterpriseCollectionRecorder.TryGetLatestEnterpriseControllerForTcp(
                        out leftController,
                        out rightController,
                        out controllerSampleSeq);
                    if (!IsControllerActiveInput())
                    {
                        leftController = EnterpriseCollectionRecorder.CreateInvalidEnterpriseControllerTcpPose();
                        rightController = EnterpriseCollectionRecorder.CreateInvalidEnterpriseControllerTcpPose();
                    }

                    hasNewTrackingSample |= controllerSampleSeq != _lastDirectTrackingControllerSampleSeq;
                }

                if (!hasNewTrackingSample)
                {
                    Interlocked.Increment(ref _directStaleReadCount);
                    // Avoid a tight busy loop even though no managed payload is created.
                    Thread.Sleep(Mathf.Max(1, GetClampedSleepMs(trackingThreadQueueBackpressureSleepMs)));
                    continue;
                }

                Interlocked.Increment(ref _directNewSampleCount);

                JsonData trackingValue = new JsonData();
                if (TrackingData.HeadOn)
                {
                    JsonData head = new JsonData();
                    head["pose"] = headPose;
                    head["status"] = headStatus;
                    trackingValue["Head"] = head;
                }

                if (TrackingData.ControllerOn)
                {
                    GetControllerInputSnapshot(out ControllerInputState leftInput, out ControllerInputState rightInput);
                    if (!IsControllerActiveInput())
                    {
                        leftInput = default(ControllerInputState);
                        rightInput = default(ControllerInputState);
                    }
                    JsonData controller = BuildEnterpriseControllerJson(
                        leftController,
                        rightController,
                        leftInput,
                        rightInput);
                    trackingValue["Controller"] = controller;
                    LogEnterpriseControllerPayloadIfNeeded(controller, controllerSampleSeq);
                }

                JsonData appState = new JsonData();
                trackingValue["timeStampNs"] = Utils.GetCurrentTimestamp();
                appState["focus"] = _cachedAppFocus;
                trackingValue["appState"] = appState;
                trackingValue["Input"] = _cachedActiveInputDevice;

                JsonData sendJson = new JsonData();
                sendJson["functionName"] = "Tracking";
                sendJson["value"] = trackingValue.ToJson();

                _sendDatas.Enqueue(new SendData(
                    NetCMD.PACKET_CCMD_TO_CONTROLLER_FUNCTION,
                    Encoding.UTF8.GetBytes(sendJson.ToJson()),
                    true));
                Interlocked.Increment(ref _directEnqueueCount);
                Interlocked.Increment(ref _pendingDirectTrackingPackets);
                _lastDirectTrackingHeadSampleSeq = headSampleSeq;
                _lastDirectTrackingControllerSampleSeq = controllerSampleSeq;

                LogDirectTrackingStatsIfNeeded(headSampleSeq, controllerSampleSeq);
            }
        }

        private bool ShouldSendEnterpriseTrackingDirectly()
        {
            return SendTrackingData &&
                   EnterpriseDirectTrackingEnabled &&
                   TrackingDataSourceCtrl.UseEnterpriseSDK &&
                   (TrackingData.HeadOn || TrackingData.ControllerOn);
        }

        private static JsonData BuildEnterpriseControllerJson(
            EnterpriseCollectionRecorder.EnterpriseControllerTcpPose left,
            EnterpriseCollectionRecorder.EnterpriseControllerTcpPose right,
            ControllerInputState leftInput,
            ControllerInputState rightInput)
        {
            JsonData controller = new JsonData();
            controller["left"] = BuildEnterpriseControllerSideJson(left, leftInput);
            controller["right"] = BuildEnterpriseControllerSideJson(right, rightInput);
            return controller;
        }

        private static JsonData BuildEnterpriseControllerSideJson(
            EnterpriseCollectionRecorder.EnterpriseControllerTcpPose pose,
            ControllerInputState input)
        {
            JsonData json = new JsonData();
            json["axisX"] = input.AxisX;
            json["axisY"] = input.AxisY;
            json["axisClick"] = input.AxisClick;
            json["grip"] = input.Grip;
            json["trigger"] = input.Trigger;
            json["primaryButton"] = input.PrimaryButton;
            json["secondaryButton"] = input.SecondaryButton;
            json["menuButton"] = input.MenuButton;
            json["inputDeviceValid"] = input.DeviceValid;
            json["axisValid"] = input.AxisValid;
            json["axisClickValid"] = input.AxisClickValid;
            json["gripValid"] = input.GripValid;
            json["triggerValid"] = input.TriggerValid;
            json["primaryButtonValid"] = input.PrimaryButtonValid;
            json["secondaryButtonValid"] = input.SecondaryButtonValid;
            json["menuButtonValid"] = input.MenuButtonValid;
            json["hasPose"] = pose.HasPose;
            json["pose"] = string.IsNullOrEmpty(pose.Pose)
                ? EnterpriseCollectionRecorder.InvalidControllerPose
                : pose.Pose;
            json["status"] = (double)pose.Status;
            json["timeStampNs"] = (double)pose.TimeStampNs;
            json["type"] = (double)pose.Type;
            json["poseError"] = (double)pose.PoseError;

            return json;
        }

        private static ControllerInputState ReadControllerInput(XRNode node)
        {
            InputDevice device = InputDevices.GetDeviceAtXRNode(node);
            bool axisValid = device.TryGetFeatureValue(CommonUsages.primary2DAxis, out Vector2 axis);
            bool axisClickValid = device.TryGetFeatureValue(CommonUsages.primary2DAxisClick, out bool axisClick);
            bool gripValid = device.TryGetFeatureValue(CommonUsages.grip, out float grip);
            bool triggerValid = device.TryGetFeatureValue(CommonUsages.trigger, out float trigger);
            bool primaryButtonValid = device.TryGetFeatureValue(CommonUsages.primaryButton, out bool primaryButton);
            bool secondaryButtonValid = device.TryGetFeatureValue(CommonUsages.secondaryButton, out bool secondaryButton);
            bool menuButtonValid = device.TryGetFeatureValue(CommonUsages.menuButton, out bool menuButton);
            return new ControllerInputState
            {
                DeviceValid = device.isValid,
                AxisX = axis.x,
                AxisY = axis.y,
                AxisClick = axisClick,
                Grip = grip,
                Trigger = trigger,
                PrimaryButton = primaryButton,
                SecondaryButton = secondaryButton,
                MenuButton = menuButton,
                AxisValid = device.isValid && axisValid,
                AxisClickValid = device.isValid && axisClickValid,
                GripValid = device.isValid && gripValid,
                TriggerValid = device.isValid && triggerValid,
                PrimaryButtonValid = device.isValid && primaryButtonValid,
                SecondaryButtonValid = device.isValid && secondaryButtonValid,
                MenuButtonValid = device.isValid && menuButtonValid
            };
        }

        private void GetControllerInputSnapshot(
            out ControllerInputState left,
            out ControllerInputState right)
        {
            lock (_controllerInputLock)
            {
                left = _cachedLeftControllerInput;
                right = _cachedRightControllerInput;
            }
        }

        private bool IsControllerActiveInput()
        {
            return _cachedActiveInputDevice == (int)ActiveInputDevice.ControllerActive;
        }

        private struct ControllerInputState
        {
            public bool DeviceValid;
            public float AxisX;
            public float AxisY;
            public bool AxisClick;
            public float Grip;
            public float Trigger;
            public bool PrimaryButton;
            public bool SecondaryButton;
            public bool MenuButton;
            public bool AxisValid;
            public bool AxisClickValid;
            public bool GripValid;
            public bool TriggerValid;
            public bool PrimaryButtonValid;
            public bool SecondaryButtonValid;
            public bool MenuButtonValid;
        }

        private void LogEnterpriseControllerPayloadIfNeeded(JsonData controller, long sampleSeq)
        {
            if (!outputEnterpriseControllerPayloadToLog)
            {
                return;
            }

            long nowTicks = System.Diagnostics.Stopwatch.GetTimestamp();
            double elapsedSeconds = (nowTicks - _lastEnterpriseControllerPayloadLogTicks) /
                                    (double)System.Diagnostics.Stopwatch.Frequency;
            float intervalSeconds = Mathf.Max(0.1f, enterpriseControllerPayloadLogIntervalSeconds);
            if (_lastEnterpriseControllerPayloadLogTicks != 0 && elapsedSeconds < intervalSeconds)
            {
                return;
            }

            _lastEnterpriseControllerPayloadLogTicks = nowTicks;
            string schemaMessage =
                "TCP enterprise controller schema: " +
                "axisX=double axisY=double axisClick=bool grip=double trigger=double " +
                "primaryButton=bool secondaryButton=bool menuButton=bool hasPose=bool pose=string " +
                "inputDeviceValid=bool *Valid=bool status=double timeStampNs=double " +
                "type=double poseError=double";
            string payloadMessage =
                $"TCP enterprise controller payload: sampleSeq={sampleSeq} json={controller.ToJson()}";
            Debug.Log($"{Tag}{schemaMessage}");
            Debug.Log($"{Tag}{payloadMessage}");
        }

        private bool IsEnterpriseDirectTrackingReady()
        {
            return ShouldSendEnterpriseTrackingDirectly() && _state == SocketState.WORKING && _connectInited;
        }

        private void LogEnterpriseDirectTrackingGateIfChanged()
        {
            string status = $"ready={IsEnterpriseDirectTrackingReady()} send={SendTrackingData} " +
                            $"directEnabled={EnterpriseDirectTrackingEnabled} " +
                            $"source={TrackingDataSourceCtrl.CurrentSource} " +
                            $"head={TrackingData.HeadOn} controller={TrackingData.ControllerOn} " +
                            $"hand={TrackingData.HandTrackingOn} trackingType={TrackingData.TrackingTypeValue} " +
                            $"state={_state} connectInited={_connectInited}";
            if (status == _lastDirectTrackingGateStatus)
            {
                return;
            }

            _lastDirectTrackingGateStatus = status;
            string message = $"TCP enterprise direct gate changed: {status}";
            LogWindow.Info(message);
            Debug.Log($"{Tag}{message}");
        }

        private void ResetDirectTrackingCache()
        {
            _lastDirectTrackingHeadSampleSeq = 0;
            _lastDirectTrackingControllerSampleSeq = 0;
        }

        private static int GetClampedSleepMs(int sleepMs)
        {
            return Mathf.Max(0, sleepMs);
        }

        private void RecordTrackingPacketSent(string mode)
        {
            _trackingPacketsSentInWindow++;
            _lastTrackingSendMode = mode;
            LogTrackingRateIfNeeded();
        }

        private void LogTrackingRateIfNeeded()
        {
            float intervalSeconds = Mathf.Max(0.1f, trackingRateLogIntervalSeconds);
            double elapsedSeconds = _trackingRateStopwatch.Elapsed.TotalSeconds;
            if (elapsedSeconds < intervalSeconds)
            {
                return;
            }

            double sendHz = elapsedSeconds > 0 ? _trackingPacketsSentInWindow / elapsedSeconds : 0;
            string rateMessage =
                $"TCP tracking send rate: {sendHz:F1}Hz mode={_lastTrackingSendMode} pending={_pendingDirectTrackingPackets}";
            if (outputTrackingRateToLogWindow)
            {
                LogWindow.Info(rateMessage);
            }

            Debug.Log($"{Tag}{rateMessage}");
            _trackingPacketsSentInWindow = 0;
            _trackingRateStopwatch.Restart();
        }

        private void LogDirectTrackingStatsIfNeeded(long headSeq, long controllerSeq)
        {
            long nowTicks = System.Diagnostics.Stopwatch.GetTimestamp();
            if (_lastDirectStatsLogTicks == 0)
            {
                _lastDirectStatsLogTicks = nowTicks;
                return;
            }

            double elapsedSeconds = (nowTicks - _lastDirectStatsLogTicks) /
                                    (double)System.Diagnostics.Stopwatch.Frequency;
            if (elapsedSeconds < 1.0)
            {
                return;
            }

            long loops = Interlocked.Exchange(ref _directLoopCount, 0);
            long stale = Interlocked.Exchange(ref _directStaleReadCount, 0);
            long fresh = Interlocked.Exchange(ref _directNewSampleCount, 0);
            long enqueued = Interlocked.Exchange(ref _directEnqueueCount, 0);
            _lastDirectStatsLogTicks = nowTicks;

            double loopHz = loops / elapsedSeconds;
            double staleHz = stale / elapsedSeconds;
            double freshHz = fresh / elapsedSeconds;
            double enqueueHz = enqueued / elapsedSeconds;

            Debug.Log($"{Tag}direct stats: loopHz={loopHz:F0} staleReadHz={staleHz:F0} " +
                      $"newSampleHz={freshHz:F0} enqueueHz={enqueueHz:F0} " +
                      $"headSeq={headSeq} controllerSeq={controllerSeq} " +
                      $"seqDelta={headSeq - controllerSeq} pending={_pendingDirectTrackingPackets}");
        }

        private void OnSendThread()
        {
            while (_state != SocketState.DESTROY)
            {
                if (_state != SocketState.WORKING)
                {
                    Thread.Sleep(100);
                    continue;
                }

                try
                {
                    lock (_sendObject)
                    {
                        SocketError socketError = SocketError.Success;
                        if (_socket != null && _socket.Connected)
                        {
                            //Sending general messages
                            while (_sendDatas.TryDequeue(out SendData sendData))
                            {
                                if (sendData.IsDirectTracking)
                                {
                                    Interlocked.Decrement(ref _pendingDirectTrackingPackets);
                                }

                                byte[] data = PackageHandle.Pack(sendData.Cmd, sendData.Content);

                                int totalBytes = data.Length;
                                int bytesSent = 0;
                                while (bytesSent < totalBytes)
                                {
                                    int remainingBytes = totalBytes - bytesSent;
                                    bytesSent += _socket.Send(data, bytesSent, remainingBytes,
                                        SocketFlags.None,
                                        out socketError);
                                    if (socketError == SocketError.Success)
                                    {
                                        if (sendData.Cmd == NetCMD.PACKET_CCMD_SEND_VERSION)
                                        {
                                            //This message has been successfully sent, indicating the establishment of communication with the PC side
                                            LogWindow.Info("PC connection established - version packet sent successfully");
                                            Debug.Log("pc connected !");
                                            _connectInited = true;
                                        }
                                    }
                                    else
                                    {
                                        break;
                                    }
                                }

                                if (socketError != SocketError.Success)
                                {
                                    LogWindow.Error($"TCP send error: {socketError}");
                                    Debug.LogError(Tag + "send SocketError:" + socketError);
                                    Close();
                                    break;
                                }

                                if (sendData.IsDirectTracking)
                                {
                                    RecordTrackingPacketSent("enterprise_direct");
                                }
                            }

                            //Tracking data transmission
                            if (_connectInited && SendTrackingData && !ShouldSendEnterpriseTrackingDirectly())
                            {
                                if (_sendTrackingMsg.Count > 0)
                                {
                                    _sendTrackingMsg.TryDequeue(out var msg);
                                    //Display the frequency of tracking data occurrence
                                    FPSDisplay.UpdateTime();
                                    _sendJson["functionName"] = "Tracking";
                                    _sendJson["value"] = msg;

                                    byte[] data = PackageHandle.Pack(NetCMD.PACKET_CCMD_TO_CONTROLLER_FUNCTION,
                                        Encoding.UTF8.GetBytes(_sendJson.ToJson()));

                                    int res = _socket.Send(data, 0, data.Length, SocketFlags.None,
                                        out socketError);
                                    if (res < data.Length)
                                    {
                                        Debug.LogWarning(Tag + "Incomplete data occurrence!");
                                    }


                                    if (socketError != SocketError.Success)
                                    {
                                        LogWindow.Error($"TCP tracking data send error: {socketError}");
                                        Debug.LogError(Tag + "SocketError:" + socketError);
                                        Close();
                                        continue;
                                    }

                                    RecordTrackingPacketSent("legacy");
                                }
                            }
                            else
                            {
                                if (ShouldSendEnterpriseTrackingDirectly())
                                {
                                    Thread.Yield();
                                }
                                else
                                {
                                    Thread.Sleep(14);
                                }
                            }
                        }
                        else
                        {
                            Close();
                        }
                    }
                }
                catch (Exception e)
                {
                    LogWindow.Error($"TCP send thread error: {e.Message}");
                    Debug.LogError(Tag + "Error OnSendThread:" + e);
                    Close();
                }
            }
        }

        private void OnDestroy()
        {
            if (_state != SocketState.CLOSE)
            {
                Close();
            }

            _state = SocketState.DESTROY;
        }

        public void Close()
        {
            LogWindow.Info("Closing TCP connection");
            Debug.Log(Tag + "Close:");
            if (_receivePackages != null)
            {
                lock (_receivePackages)
                {
                    _receivePackages.Clear();
                }
            }

            _state = SocketState.CLOSE;
            ResetDirectTrackingCache();
            Interlocked.Exchange(ref _pendingDirectTrackingPackets, 0);
            lock (_sendObject)
            {
                if (_socket != null)
                {
                    try
                    {
                        if (_socket.Connected)
                        {
                            _socket.Shutdown(SocketShutdown.Both);
                            _socket.Close();
                        }
                    }
                    catch (Exception e)
                    {
                        LogWindow.Error($"TCP socket cleanup error: {e.Message}");
                        Debug.LogError(Tag + "Clear Error:" + e);
                    }
                }
            }
        }


        struct SendData
        {
            public byte Cmd;
            public byte[] Content;
            public bool IsDirectTracking;

            public SendData(byte cmd, byte[] content, bool isDirectTracking = false)
            {
                Cmd = cmd;
                Content = content;
                IsDirectTracking = isDirectTracking;
            }
        }
    }

    public enum SocketState : int
    {
        NONE,
        CREATE,
        CONNECTING,
        WORKING,
        CLOSE,
        CONNECT_ERROR,
        DESTROY,
    }
}
