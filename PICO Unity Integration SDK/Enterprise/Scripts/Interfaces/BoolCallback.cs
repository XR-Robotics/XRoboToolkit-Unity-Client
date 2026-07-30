using System;
using UnityEngine;

namespace Unity.XR.PICO.TOBSupport
{
    public class BoolCallback : AndroidJavaProxy
    {
        public Action<bool> mCallback;
  
        public BoolCallback(Action<bool> callback) : base("com.pvr.tobservice.interfaces.IBoolCallback")
        {
            mCallback = callback;
        }

        public void callBack(bool var1)
        {
            HandleCallback(var1);
        }

        public void CallBack(bool var1)
        {
            HandleCallback(var1);
        }

        private void HandleCallback(bool value)
        {
            PXR_EnterpriseTools.QueueOnMainThread(() =>
            {
                if (mCallback != null)
                {
                    mCallback(value);
                }
            });
        }
    }
}
