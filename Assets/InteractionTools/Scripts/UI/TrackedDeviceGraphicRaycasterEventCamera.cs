using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.XR.Interaction.Toolkit.UI;

namespace com.picoxr.tobframwork.UI
{
    public class TrackedDeviceGraphicRaycasterEventCamera : TrackedDeviceGraphicRaycaster
    {
        public override void Raycast(PointerEventData eventData, List<RaycastResult> resultAppendList)
        {
            XRUIInputModule inputModel = eventData.currentInputModule as XRUIInputModule;
            if (inputModel != null)
            {
                inputModel.uiCamera = eventCamera;
            }

            base.Raycast(eventData, resultAppendList);
        }
    }
}