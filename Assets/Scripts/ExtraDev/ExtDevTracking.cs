using System.Text;
using Network;
using Unity.XR.PXR;
using UnityEngine;

namespace Robot
{
    public class ExtDevTracking : MonoBehaviour
    {
        private bool _enable = false;
        private int _realLength = 0;
        private ExtDevTrackerPassDataArray _passDataArray = new ExtDevTrackerPassDataArray();

        public void Start()
        {
            PXR_MotionTracking.ExtDevPassDataAction += ExtDevPassDataAction;
        }

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
            if (_enable)
            {
                int result = PXR_MotionTracking.GetExtDevTrackerByPassData(ref _passDataArray, ref _realLength);
                for (int i = 0; i < _realLength; i++)
                {
                    ExtDevTrackerPassData passData = _passDataArray.passDatas[i];
                    PackageSend(passData);
                }
            }
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

        private void PackageSend(ExtDevTrackerPassData passData)
        {
            byte[] package = PackageHandle.CustomPacket(CustomDataType.TRACKER_EXTRA_DEVICE, passData.trackerSN.value,
                passData.passData);
            TcpHandler.SendCustomData(package);
        }

        public void OnDestroy()
        {
            PXR_MotionTracking.ExtDevPassDataAction -= ExtDevPassDataAction;
            // 关闭独立外设透传数据接口的控制接口
            PXR_MotionTracking.SetExtDevTrackerPassDataState(false);
        }

        private void ExtDevPassDataAction(int value)
        {
            if (value == 1) // 监听此事件，为 1 时，开始调用 GetExtDevTrackerByPassData
            {
                _enable = true;
            }
            else if (value == 0) // 监听此事件，为 0 时，停止调用 GetExtDevTrackerByPassData
            {
                _enable = false;
            }
        }
    }
}