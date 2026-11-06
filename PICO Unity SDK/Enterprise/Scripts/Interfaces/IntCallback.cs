using System;
using UnityEngine;

namespace ByteDance.PICO.Enterprise
{
    public class IntCallback : AndroidJavaProxy
    {
        public Action<int> mCallback;

        public IntCallback(Action<int> callback) : base("com.picoxr.tobservice.interfaces.IntCallback")
        {
            mCallback = callback;
        }

        public void CallBack(int var1)
        {
            PXR_EnterpriseTools.QueueOnMainThread(() =>
            {
                if (mCallback != null)
                {
                    mCallback(var1);
                }
            });
        }
    }
}