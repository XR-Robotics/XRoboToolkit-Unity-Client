using System;
using UnityEngine;

namespace Unity.XR.PICO.TOBSupport
{
    public class BindCallback : AndroidJavaProxy
    {
        public Action<bool> mCallback;

        public BindCallback(Action<bool> callback) : base("com.pvr.tobservice.ToBServiceHelper$BindCallBack")
        {
            mCallback = callback;
        }

        public void bindCallBack(bool var1)
        {
            HandleCallback(var1);
        }

        public void CallBack(bool var1)
        {
            HandleCallback(var1);
        }

        private void HandleCallback(bool bind)
        {
            Debug.Log("ToBService bindCallBack 回调:" + bind);
            PXR_EnterprisePlugin.GetServiceBinder();
            PXR_EnterpriseTools.QueueOnMainThread(() =>
            {
                if (mCallback != null)
                {
                    mCallback(bind);
                }
            });
        }
    }
}
