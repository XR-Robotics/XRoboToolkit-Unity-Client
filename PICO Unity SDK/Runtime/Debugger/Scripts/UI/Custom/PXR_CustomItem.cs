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
using UnityEngine.EventSystems;
using UnityEngine.UI;
using TMPro;
#if UNITY_EDITOR || DEVELOPMENT_BUILD
namespace ByteDance.PICO.Debugger
{
    public class PXR_CustomItem : MonoBehaviour
    {
        // Field names kept identical to PXR_InspectorItem so the cloned
        // serialized bindings resolve after only swapping m_Script guid.
        public TextMeshProUGUI text;
        public GameObject folderIcon;
        private string nodeName;
        private GameObject target;
        public GameObject Target => target;
        public Transform group;

        // Two-level model:
        //   L1 (GameObject node): clicking only expands/collapses `group`,
        //       which holds one L2 child per debuggable component. The right
        //       detail panel is NOT driven by an L1 node.
        //   L2 (Component node): a leaf with no expand arrow; clicking drives
        //       the right detail panel with exactly that component's
        //       [PICODebuggerItem] members.
        private MonoBehaviour targetComponent;
        public MonoBehaviour TargetComponent => targetComponent;
        public bool IsComponentNode => targetComponent != null;

        public void SetTitle()
        {
            if (text != null) text.text = nodeName;
        }

        // L1: a GameObject node. List every component on `item` that exposes
        // at least one [PICODebuggerItem] member as an L2 child under `group`.
        public void Init(Transform item)
        {
            target = item.gameObject;
            targetComponent = null;
            nodeName = item.name;

            int childCount = BuildComponentChildren(item.gameObject);
            // Only show the expand arrow when there is something to expand.
            if (folderIcon != null) folderIcon.SetActive(childCount > 0);
            SetTitle();
        }

        // L2: a component leaf node. Drives the right panel when clicked.
        public void InitComponent(MonoBehaviour component)
        {
            target = component != null ? component.gameObject : null;
            targetComponent = component;
            nodeName = component != null ? component.GetType().Name : "<null>";
            // Leaf: never an expand arrow.
            if (folderIcon != null) folderIcon.SetActive(false);
            SetTitle();
        }

        private int BuildComponentChildren(GameObject go)
        {
            if (go == null || group == null) return 0;
            int count = 0;
            var comps = go.GetComponents<MonoBehaviour>();
            foreach (var comp in comps)
            {
                if (comp == null) continue;
                if (!PXR_CustomItemFactory.HasDebuggerItems(comp.GetType())) continue;
                AddComponentItem(comp);
                count++;
            }
            return count;
        }

        private void AddComponentItem(MonoBehaviour component)
        {
            if (PXR_CustomManager.Instance == null) return;
            var go = Instantiate(PXR_CustomManager.Instance.inspectItem, group);
            if (go.TryGetComponent(out PXR_CustomItem childItem))
            {
                childItem.InitComponent(component);
            }
        }
    }
}
#endif
