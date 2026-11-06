using System.Text;
using Network;
using ByteDance.PICO.XR;
using UnityEngine;

namespace Robot
{
    public class ExtDevTracking : MonoBehaviour
    {
        private void OnEnable()
        {
            // 启动独立外设透传数据接口的控制接口
            PXR_MotionTracking.SetExtDevTrackerPassDataState(true);
        }

        private void OnDisable()
        {
            PXR_MotionTracking.SetExtDevTrackerPassDataState(false);
        }

        public void Update()
        {
#if PICO_XR && UNITY_ANDROID && !UNITY_EDITOR
            if (PXR_MotionTracking.GetExpandDeviceCustomData(out var data) == 0 && data != null)
            {
                foreach (ExpandDevicesCustomData passData in data)
                {
                    if (passData.data != null)
                        PackageSend(passData);
                }
            }
#endif
        }

        [ContextMenu("Test")]
        public void Test()
        {
            byte[] snBytes = Encoding.ASCII.GetBytes("PA8E10MGH3229396D");
            string sn = "";
            for (var i = 0; i < snBytes.Length; i++)
            {
                sn += snBytes[i].ToString() + " ";
            }

            Debug.Log("sn:" + sn);
            byte[] data = { 0xA1, 0xB2, 0xC3, 0xD4 };

            byte[] package = PackageHandle.CustomPacket(CustomDataType.TRACKER_EXTRA_DEVICE, "PA8E10MGH3229396D",
                data);

            string msg = "";
            for (var i = 0; i < package.Length; i++)
            {
                msg += package[i].ToString() + " ";
            }

            Debug.Log("msg:" + msg);
            TcpHandler.SendCustomData(package);
        }

        private void PackageSend(ExpandDevicesCustomData passData)
        {
            byte[] package = PackageHandle.CustomPacket(CustomDataType.TRACKER_EXTRA_DEVICE,
                PicoMotionTrackerDevices.GetIdentifier(passData.deviceId), passData.data);
            TcpHandler.SendCustomData(package);
        }

        public void OnDestroy()
        {
            // 关闭独立外设透传数据接口的控制接口
            PXR_MotionTracking.SetExtDevTrackerPassDataState(false);
        }

    }
}
