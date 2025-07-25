using UnityEngine;
using System;

namespace Robot.V2.Network
{
    public enum ClientStatus
    {
        None,
        Connected,
        Disconnected,
    }
    public class TcpClient : AndroidJavaProxy
    {
        private static TcpClient _callbackProxy = new TcpClient();

        public static TcpClient CallbackProxy => _callbackProxy;

        public event Action OnConnected;
        public event Action OnDisconnected;
        public event Action<byte[], int> OnDataReceived;
        public event Action<string, Exception> OnError;

        private string logTag = "TcpClient(C#)";

        public static ClientStatus Status { get; private set; } = ClientStatus.None;

        public TcpClient() : base("com.picovr.robotassistantlib.TcpClient$ClientCallback")
        {

        }

        private static AndroidJavaObject _javaObj = null;

        private static AndroidJavaObject GetJavaObject()
        {
            if (_javaObj == null)
            {
                _javaObj = new AndroidJavaObject("com.picovr.robotassistantlib.TcpClient");
            }

            return _javaObj;
        }

        public static void ConnectToServer(string ip, int port, Action onConnected)
        {
            LogWindow.Info($"Attempting to connect to server at {ip}:{port}");
            _callbackProxy.OnConnected = onConnected;
            GetJavaObject().Call("connectToServer", ip, port, _callbackProxy);
            Status = ClientStatus.Connected;
        }

        public static void Send(byte[] data)
        {
            GetJavaObject().Call("send", data);
        }

        public static void Disconnect()
        {
            LogWindow.Info("Disconnecting from TCP server");
            GetJavaObject().Call("disconnect");
            Status = ClientStatus.Disconnected;
        }

        public void onConnected()
        {
            Utils.WriteLog(logTag, "Java TcpClient: Connected");
            LogWindow.Info("TCP Client successfully connected to server");
            Status = ClientStatus.Connected;
            OnConnected?.Invoke();
        }

        public void onDisconnected()
        {
            Utils.WriteLog(logTag, "Java TcpClient: Disconnected");
            LogWindow.Warn("TCP Client disconnected from server");
            Status = ClientStatus.Disconnected;
            OnDisconnected?.Invoke();
        }

        public void onDataReceived(byte[] data, int length)
        {
            Utils.WriteLog(logTag, $"Java TcpClient: Received data of length {length}");
            OnDataReceived?.Invoke(data, length);
        }

        public void onError(string errorMessage, AndroidJavaObject exception)
        {
            Utils.WriteLog(logTag, $"Java TcpClient: Error - {errorMessage} - {exception}");
            LogWindow.Error($"TCP Client error: {errorMessage}");
            OnError?.Invoke(errorMessage, new Exception($"{errorMessage} - {exception}"));
        }
    }
}