using System;
using Robot;
using Robot.Network;
using Robot.V2.Network;
using UnityEngine;
using XRoboToolkit.Network;

namespace Network
{
    public static class NetworkCommand
    {
        public const string OPEN_CAMERA = "OPEN_CAMERA";
        public const string CLOSE_CAMERA = "CLOSE_CAMERA";
    }

    public class NetworkCommander : MonoBehaviour
    {
        private NetworkDataProcessor processor;
        private TcpManager tcpManager;

        private string logTag = "NetworkCommander";

        public static NetworkCommander Instance { get; private set; }

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

        public NetworkDataProcessor Processor
        {
            get { return processor; }
        }

        private void Start()
        {
            InitializeNetworkProcessor();
        }

        private void InitializeNetworkProcessor()
        {
            processor = new NetworkDataProcessor();

            // Register example command handlers
            processor.RegisterCommandHandler(NetworkCommand.OPEN_CAMERA, new OpenCameraHandler());
            processor.RegisterCommandHandler(NetworkCommand.CLOSE_CAMERA, new CloseCameraHandler());

            Debug.Log("Network data processor initialized with " + processor.GetRegisteredCommands().Length +
                      " handlers");
        }

        void OnDestroy()
        {
            // Clean up
            processor?.ClearAllHandlers();
        }

        #region Send Data

        public void SendCommand(string command, byte[] data = null)
        {
            var protocol = new NetworkDataProtocol(command, data);
            var serializedData = NetworkDataProtocolSerializer.Serialize(protocol);
            // Send the packet using TcpManager
            TcpManager.Instance.ClientSend(serializedData);
        }

        public void OpenCamera(byte[] data)
        {
            LogWindow.Warn("Sending OPEN_CAMERA command.");
            SendCommand(NetworkCommand.OPEN_CAMERA, data);
        }

        public void CloseCamera()
        {
            LogWindow.Warn("Sending CLOSE_CAMERA command.");
            SendCommand(NetworkCommand.CLOSE_CAMERA, new byte[0]);
        }

        #endregion

        private class OpenCameraHandler : ICommandHandler
        {
            public void HandleCommand(byte[] data)
            {
                Debug.Log("Handling OPEN_CAMERA command with data: " + BitConverter.ToString(data));
                // Add logic to open camera

                var cameraConfig = CameraRequestSerializer.Deserialize(data);
                Utils.WriteLog("OpenCameraHandler", $"Received camera config: {cameraConfig}");
                LogWindow.Warn($"Handling OPEN_CAMERA: {cameraConfig.ToString()}");

                // The stream only works for the VR headset
                if (cameraConfig.camera.Equals("VR"))
                {
                    CameraHandle.StartCameraPreview(cameraConfig.width, cameraConfig.height, cameraConfig.fps,
                        cameraConfig.bitrate, cameraConfig.enableMvHevc,
                        cameraConfig.renderMode,
                        () => { CameraHandle.StartSendImage(cameraConfig.ip, cameraConfig.port); });
                    // CameraSendToBtn.SetOn(true);
                }
            }
        }

        private class CloseCameraHandler : ICommandHandler
        {
            public void HandleCommand(byte[] data)
            {
                Debug.Log("Handling CLOSE_CAMERA command with data: " + BitConverter.ToString(data));
                LogWindow.Warn("Handling CLOSE_CAMERA command");
                // Stop the camera preview
                CameraHandle.StopPreview();
            }
        }
    }
}