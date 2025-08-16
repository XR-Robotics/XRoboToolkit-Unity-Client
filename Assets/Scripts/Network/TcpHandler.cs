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
using UnityEngine;

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
        private static object _sendObject = new object();
        private Queue<NetPacket> _receivePackages = new Queue<NetPacket>();
        private static Queue<SendData> _sendDatas = new Queue<SendData>();

        private Socket _socket;
        private SocketState _state = SocketState.NONE;

        private bool _connectInited = false;
        private static string _address = "127.0.0.1"; // PC IP Address
        private int _port = 8888; //PC Port
        private int _sendTimeout = 15000; // timeout
        private Thread _sendThread;
        private ByteBuffer receiveBuffer;
        private string _appVersion = "";
        private string _deviceSN = "";
        private JsonData _trackingJsonData = new JsonData();
        private JsonData _sendJson = new JsonData();
        private TrackingData _trackingData = new TrackingData();
        private ConcurrentQueue<string> _sendTrackingMsg = new ConcurrentQueue<string>();
        private float _lastHeardSend = 0;
        private float _lastReconnectTime = 0;
        private bool _reconnectEnable = false;

        private void Awake()
        {
            _appVersion = Application.version;
            _sendThread = new Thread(OnSendThread);
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

        public void Connect(string address)
        {
            LogWindow.Info($"Attempting to connect to {address}");
            _address = address;
            _reconnectEnable = false;
            Connect();
        }

        private void Connect()
        {
            _port = TCP_PORT;
            _state = SocketState.CREATE;
            ConnectErrorInfo = "";
            Debug.Log(string.Format(Tag + "connect to server: ip {0}port: {1}", _address, _port.ToString()));
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
            if (SendTrackingData)
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
                            while (_sendDatas.Count > 0)
                            {
                                SendData sendData = _sendDatas.Dequeue();

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
                            }

                            //Tracking data transmission
                            if (_connectInited && SendTrackingData)
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
                                }
                            }
                            else
                            {
                                Thread.Sleep(14);
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

            public SendData(byte cmd, byte[] content)
            {
                Cmd = cmd;
                Content = content;
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