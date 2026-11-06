/*******************************************************************************
Copyright © 2015-2022 PICO Technology Co., Ltd.All rights reserved.  

NOTICE：All information contained herein is, and remains the property of 
PICO Technology Co., Ltd. The intellectual and technical concepts 
contained herein are proprietary to PICO Technology Co., Ltd. and may be 
covered by patents, patents in process, and are protected by trade secret or 
copyright law. Dissemination of this information or reproduction of this 
material is strictly forbidden unless prior written permission is obtained from
PICO Technology Co., Ltd. 
*******************************************************************************/
using UnityEngine;
using UnityEngine.UI;
#if UNITY_EDITOR || DEVELOPMENT_BUILD
namespace ByteDance.PICO.Debugger
{
    public class PXR_SideItemToggleController : MonoBehaviour
    {
        public GameObject group;
        public Image icon;
        public Toggle toggle;
        public void Toggle()
        {
            PXR_InspectorController.Instance.gameObject.SetActive(true);
            PXR_InspectorItem item = null;
            if (TryGetComponent(out item))
            {
                PXR_InspectorController.Instance.SetGameObject(item.Target);
            }
            // Lazily realise direct child rows the first time this node opens
            // (Stage 1). Cheap no-op on subsequent expands.
            if (toggle.isOn && item != null)
            {
                item.EnsureChildren();
            }
            if (group.transform.childCount <= 0) return;
            group.SetActive(toggle.isOn);
            var current = group.transform;
            while (current != null && current.TryGetComponent(out RectTransform rect))
            {
                LayoutRebuilder.ForceRebuildLayoutImmediate(rect);
                current = current.parent;
            }
            if (icon == null) return;
            icon.transform.eulerAngles = toggle.isOn ? Vector3.back * 90f : Vector3.zero;
        }
    }
}
#endif