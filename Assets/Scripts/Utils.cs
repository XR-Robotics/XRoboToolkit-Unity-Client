using System;
using System.Net;
using System.Net.Sockets;
using Unity.XR.PICO.TOBSupport;
using Unity.XR.PXR;

namespace Robot
{
    public class Utils
    {
        public static long GetCurrentTimestamp()
        {
            DateTime epoch = new DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind.Utc);
            long currentTimestamp = (long)((DateTime.UtcNow - epoch).TotalMilliseconds * 1000000);
            return currentTimestamp;
        }

        //Obtain the local IPv4 address
        public static string GetLocalIPv4()
        {
            string localIP = "Not found";
            foreach (IPAddress ip in Dns.GetHostAddresses(Dns.GetHostName()))
            {
                if (ip.AddressFamily == System.Net.Sockets.AddressFamily.InterNetwork)
                {
                    localIP = ip.ToString();
                    break;
                }
            }

            return localIP;
        }

        /// <summary>
        /// Check if the local port is occupied
        /// </summary>
        /// <param name="port"></param>
        /// <returns></returns>
        public static bool IsPortAvailable(int port)
        {
            try
            {
                TcpListener listener = new TcpListener(IPAddress.Any, port);

                listener.Start();

                listener.Stop();

                return true;
            }
            catch (SocketException e)
            {
                return false;
            }
        }

        public static int GetAvailablePort()
        {
            TcpListener listener = new TcpListener(IPAddress.Loopback, 0); // 传入 0 让系统自动分配可用端口
            listener.Start();
            int port = ((IPEndPoint)listener.LocalEndpoint).Port;
            listener.Stop();
            return port;
        }

        public static string GetCameraIntrinsicsStrE(int width, int height)
        {
            string cameraIntrinsics = "";
            double[] intrinsics = PXR_Enterprise.GetCameraIntrinsicsfor4U(width, height, 76.35f, 61.05f);
            for (int i = 0; i < intrinsics.Length; i++)
            {
                if (i > 0)
                {
                    cameraIntrinsics += ",";
                }

                cameraIntrinsics += intrinsics[i].ToString("E16");
            }

            return cameraIntrinsics;
        }

        public static string GetCameraExtrinsicsStrE()
        {
            PXR_EnterprisePlugin.GetCameraExtrinsics(out var leftExtrinsics, out var rightExtrinsics);
            string cameraExtrinsics = "";

            //left
            for (int i = 0; i < leftExtrinsics.Length; i++)
            {
                if (i > 0)
                {
                    cameraExtrinsics += ",";
                }

                cameraExtrinsics += leftExtrinsics[i].ToString("E16");
            }


            cameraExtrinsics += "|";
            //right
            for (int i = 0; i < rightExtrinsics.Length; i++)
            {
                if (i > 0)
                {
                    cameraExtrinsics += ",";
                }

                cameraExtrinsics += rightExtrinsics[i].ToString("E16");
            }

            return cameraExtrinsics;
        }

        public static bool IsPico4U()
        {
#if UNITY_EDITOR
            return true;
#endif
            return PXR_Input.GetControllerDeviceType() == PXR_Input.ControllerDevice.PICO_4U;
        }
    }
}