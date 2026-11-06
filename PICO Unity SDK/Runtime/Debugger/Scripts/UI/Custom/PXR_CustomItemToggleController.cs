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
    public class PXR_CustomItemToggleController : MonoBehaviour
    {
        // Field names kept identical to PXR_SideItemToggleController so the
        // cloned serialized bindings resolve after only swapping m_Script guid.
        public GameObject group;
        public Image icon;
        public Toggle toggle;
        public void Toggle()
        {
            if (PXR_CustomController.Instance == null) return;
            if (!TryGetComponent(out PXR_CustomItem item)) return;

            // L2 component node: drive the right detail panel; never expands.
            if (item.IsComponentNode)
            {
                PXR_CustomController.Instance.gameObject.SetActive(true);
                PXR_CustomController.Instance.SetComponent(item.TargetComponent);
                return;
            }

            // L1 GameObject node: only expand/collapse the child component list;
            // does NOT drive the right detail panel.
            if (group == null || group.transform.childCount <= 0) return;
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
