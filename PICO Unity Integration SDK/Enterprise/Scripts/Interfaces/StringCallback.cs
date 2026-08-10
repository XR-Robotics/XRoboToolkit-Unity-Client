using System;
using UnityEngine;

namespace Unity.XR.PICO.TOBSupport
{
    public class StringCallback : AndroidJavaProxy
    {
        public Action<string> mCallback;

        public StringCallback(Action<string> callback) : base("com.pvr.tobservice.interfaces.IStringCallback")
        {
            mCallback = callback;
        }

        // Current tobservicelib-release.aar exposes IStringCallback.callback(String).
        // Keep CallBack for legacy callers, but implement the current binder ABI.
        public void callback(string var1)
        {
            HandleCallback(var1);
        }

        public void CallBack(string var1)
        {
            HandleCallback(var1);
        }

        private void HandleCallback(string value)
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