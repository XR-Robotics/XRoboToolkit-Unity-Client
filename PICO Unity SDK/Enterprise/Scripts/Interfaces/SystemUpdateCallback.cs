using System;
using UnityEngine;

namespace ByteDance.PICO.Enterprise
{
    public class SystemUpdateCallback: AndroidJavaProxy
    {
        public Action<int, float> OnUpdateStatusChanged;
        public Action<int, string> OnUpdateComplete;
  
        public SystemUpdateCallback(Action<int, float> onUpdateStatusChanged,Action<int, string> onUpdateComplete) : base("com.picoxr.tobservice.interfaces.SystemUpdateCallback")
        {
            OnUpdateStatusChanged = onUpdateStatusChanged;
            OnUpdateComplete = onUpdateComplete;
        }

        public void onUpdateStatusChanged(int statusCode, float percent)
        {
            PXR_EnterpriseTools.QueueOnMainThread(() =>
            {
                if (OnUpdateStatusChanged != null)
                {
                    OnUpdateStatusChanged(statusCode, percent);
                }
            });
        }

        public void onUpdateComplete(int errorCode, String errorMsg)
        {
            PXR_EnterpriseTools.QueueOnMainThread(() =>
            {
                if (OnUpdateComplete != null)
                {
                    OnUpdateComplete(errorCode, errorMsg);
                }
            });
        }
    }
}