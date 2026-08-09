using System;
using UnityEngine;

namespace Unity.XR.PICO.TOBSupport
{
    public class IntCallback : AndroidJavaProxy
    {
        public Action<int> mCallback;

        public IntCallback(Action<int> callback) : base("com.pvr.tobservice.interfaces.IIntCallback")
        {
            mCallback = callback;
        }

        // Current tobservicelib-release.aar exposes IIntCallback.callback(int).
        // Keep CallBack for legacy callers, but implement the current binder ABI.
        public void callback(int var1)
        {
            HandleCallback(var1);
        }

        public void CallBack(int var1)
        {
            HandleCallback(var1);
        }

        private void HandleCallback(int value)
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