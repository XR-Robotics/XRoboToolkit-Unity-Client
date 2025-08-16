using System;
using System.Text;
using UnityEngine;

namespace Robot.V2.Network
{
    public class TcpManager : MonoBehaviour
    {
        private TcpServer tcpServer;
        private TcpClient tcpClient;

        public int port = 13579;

        private string serverTag = "TcpManager - TcpServer(C#)";
        private string clientTag = "TcpManager - TcpClient(C#)";

        // public System.Action<string> OnServerReceived;
        public System.Action<byte[]> OnServerReceived;
        public System.Action<string> OnClientReceived;

        public static TcpManager Instance { get; private set; }

        public TcpServer TCPServer => tcpServer;
        public TcpClient TCPClient => tcpClient;

        private void Awake()
        {
            if (Instance == null)
            {
                Instance = this;
                DontDestroyOnLoad(gameObject);
            }
            else
            {
                Destroy(gameObject);
            }
        }

        void Start()
        {
            tcpServer = TcpServer.CallbackProxy;

            // bind event
            tcpServer.OnServerStarted += OnServerStarted;
            tcpServer.OnClientDisconnected += OnClientDisconnected;
            tcpServer.OnDataReceived += OnDataReceived;
            tcpServer.OnError += OnError;
            tcpServer.OnServerStopped += OnServerStopped;

            tcpClient = TcpClient.CallbackProxy;
            tcpClient.OnConnected += TcpClientOnOnConnected;
            tcpClient.OnDisconnected += TcpClientOnOnDisconnected;
            tcpClient.OnDataReceived += TcpClientOnOnDataReceived;
            tcpClient.OnError += TcpClientOnOnError;

#if !UNITY_EDITOR
            // Start server by default
            StartServer();
#endif
        }

        private void OnDestroy()
        {
            tcpServer.OnServerStarted -= OnServerStarted;
            tcpServer.OnClientDisconnected -= OnClientDisconnected;
            tcpServer.OnDataReceived -= OnDataReceived;
            tcpServer.OnError -= OnError;
            tcpServer.OnServerStopped -= OnServerStopped;

            tcpClient.OnConnected -= TcpClientOnOnConnected;
            tcpClient.OnDisconnected -= TcpClientOnOnDisconnected;
            tcpClient.OnDataReceived -= TcpClientOnOnDataReceived;
            tcpClient.OnError -= TcpClientOnOnError;
        }

        #region Server

        private void OnError(string msg)
        {
            Utils.WriteLog(serverTag, msg);
        }

        // private void OnDataReceived(byte[] data, int length)
        // {
        //     var s = Encoding.UTF8.GetString(data);
        //
        //     // Refer: https://github.com/googleads/googleads-mobile-unity/blob/master/samples/HelloWorld/Assets/Scripts/GoogleAdMobController.cs#L63
        //     // Use EventExecutor to schedule these calls on the next Update() loop.
        //     EventExecutor.ExecuteInUpdate(() => { OnServerReceived.Invoke(s); });
        //
        //     Utils.WriteLog(serverTag, $"data: {s} length: {length}");
        // }

        private void OnDataReceived(byte[] data, int length)
        {
            // Refer: https://github.com/googleads/googleads-mobile-unity/blob/master/samples/HelloWorld/Assets/Scripts/GoogleAdMobController.cs#L63
            // Use EventExecutor to schedule these calls on the next Update() loop.

            try
            {
                EventExecutor.ExecuteInUpdate(() => { OnServerReceived.Invoke(data); });

                Utils.WriteLog(serverTag, $"data: {data.Length} length: {length}");
            }
            catch (Exception e)
            {
                Utils.WriteLog(serverTag, $"exception: {e.Message} {e.StackTrace}");
            }
        }

        private void OnClientDisconnected()
        {
            Utils.WriteLog(serverTag, "Disconnected");
        }

        private void OnServerStopped()
        {
            Utils.WriteLog(serverTag, "Stopped");
        }

        private void OnServerStarted(int port)
        {
            Utils.WriteLog(serverTag, $"Started: {port}");
        }

        public void StartServer()
        {
            TcpServer.StartTCPServer(port, OnServerStarted);
        }

        public void StopServer()
        {
            Utils.WriteLog(serverTag, $"Stopping Server");
            TcpServer.StopServer();
            Utils.WriteLog(serverTag, $"Stopped Server");
        }

        #endregion

        #region Client

        private void TcpClientOnOnError(string arg1, Exception arg2)
        {
            Utils.WriteLog(clientTag, $"{arg1}\t{arg2}");
        }

        private void TcpClientOnOnDataReceived(byte[] data, int length)
        {
            // var s = Encoding.UTF8.GetString(data);
            OnClientReceived?.Invoke("");

            Utils.WriteLog(clientTag, $"data: {data} length: {length}");
        }

        private void TcpClientOnOnDisconnected()
        {
            Utils.WriteLog(clientTag, "Disconnected");
        }

        private void TcpClientOnOnConnected()
        {
            Utils.WriteLog(clientTag, "Connected");
        }

        public void StartClient(string host)
        {
            TcpClient.ConnectToServer(host, port, TcpClientOnOnConnected);
        }

        public void StopClient()
        {
            Utils.WriteLog(serverTag, $"Disconnecting Client");
            TcpClient.Disconnect();
            Utils.WriteLog(serverTag, $"Disconnected Client");
        }

        public void ClientSend(string s)
        {
            if (TcpClient.Status == ClientStatus.Connected)
            {
                Utils.WriteLog(clientTag, $"Send: {s}");
                TcpClient.Send(Encoding.UTF8.GetBytes(s));
            }
            else
            {
                LogWindow.Error("Client is not connected. Cannot send data.");
            }
        }

        public void ClientSend(byte[] data)
        {
            if (TcpClient.Status == ClientStatus.Connected)
            {
                Utils.WriteLog(clientTag, $"Send: {data.Length} bytes");
                TcpClient.Send(data);
            }
            else
            {
                LogWindow.Error("Client is not connected. Cannot send data.");
            }
        }

        #endregion
    }
}