using System;
using UnityEngine;

namespace ByteDance.PICO.Enterprise
{
    public class BoolCallback : AndroidJavaProxy
    {
        public Action<bool> mCallback;
  
        public BoolCallback(Action<bool> callback) : base("com.picoxr.tobservice.interfaces.BoolCallback")
        {
            mCallback = callback;
        }

        public void CallBack(bool var1)
        {
            PXR_EnterpriseTools.QueueOnMainThread(() =>
            {
                if (mCallback!=null)
                {
                    mCallback(var1);
                }
            });
        }
    }
}