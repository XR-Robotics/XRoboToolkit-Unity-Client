using System;
using System.Text;
using UnityEngine;
using System.Threading.Tasks;

namespace Robot.V2.Network
{
    public enum ServerStatus
    {
        None,
        Started,
        Stopped,
    }
    public class TcpServer : AndroidJavaProxy
    {

        private static TcpServer _callbackProxy = new TcpServer();

        public static TcpServer CallbackProxy => _callbackProxy;

        public event Action<int> OnServerStarted;
        public event Action OnClientDisconnected;
        public event Action<byte[], int> OnDataReceived;
        public event Action<string> OnError;
        public event Action OnServerStopped;

        private string logTag = "TcpServer(C#)";

        public static ServerStatus Status { get; private set; } = ServerStatus.None;

        public TcpServer() : base("com.picovr.robotassistantlib.TcpServer$ServerCallback")
        {

        }

        private static AndroidJavaObject _javaObj = null;

        private static AndroidJavaObject GetJavaObject()
        {
            if (_javaObj == null)
            {
                _javaObj = new AndroidJavaObject("com.picovr.robotassistantlib.TcpServer");
            }

            return _javaObj;
        }

        public static void StartTCPServer(int port, Action<int> onServerStarted)
        {
            LogWindow.Info($"Starting TCP server on port {port}");
            _callbackProxy.OnServerStarted = onServerStarted;

            GetJavaObject().Call("startTCPServer", port, _callbackProxy);
            Status = ServerStatus.Started;
        }

        public static void StopServer()
        {
            LogWindow.Info("Stopping TCP server");
            GetJavaObject().Call("stopServer");
            Status = ServerStatus.Stopped;
        }

        // JNI callback methods
        public void onServerStarted(int port)
        {
            Utils.WriteLog(logTag, $"Server started on port: {port}");
            LogWindow.Info($"TCP Server successfully started on port {port}");
            OnServerStarted?.Invoke(port);
        }

        public void onClientConnected(AndroidJavaObject socket)
        {
            Utils.WriteLog(logTag, "Client connected: " + socket);
            LogWindow.Info("Client connected to TCP server");
        }

        public void onClientDisconnected()
        {
            Utils.WriteLog(logTag, "Client disconnected");
            LogWindow.Warn("Client disconnected from TCP server");
            OnClientDisconnected?.Invoke();
        }

        public void onDataReceived(byte[] data, int length)
        {
            Utils.WriteLog(logTag, "Received data of length: " + length);
            // decode
            var s = Encoding.UTF8.GetString(data);
            Utils.WriteLog(logTag, "Received data: " + s);
            OnDataReceived?.Invoke(data, length);
            Utils.WriteLog(logTag, "onDataReceived invoked");
        }

        public void onError(string errorMessage, AndroidJavaObject exception)
        {
            Utils.WriteLog(logTag, "Server error: " + errorMessage);
            LogWindow.Error($"TCP Server error: {errorMessage}");
            OnError?.Invoke($"{errorMessage} - {exception}");
        }

        public void onServerStopped()
        {
            Utils.WriteLog(logTag, "Server stopped");
            LogWindow.Info("TCP Server stopped");
            OnServerStopped?.Invoke();
        }

    }
}