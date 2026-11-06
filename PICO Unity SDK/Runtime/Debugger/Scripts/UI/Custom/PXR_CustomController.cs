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
using System;
using System.Reflection;
using UnityEngine;
using UnityEngine.UI;
#if UNITY_EDITOR || DEVELOPMENT_BUILD
namespace ByteDance.PICO.Debugger
{
    public class PXR_CustomController : MonoBehaviour
    {
        public static PXR_CustomController Instance;
        private void Awake()
        {
            if (Instance == null)
            {
                Instance = this;
            }
        }
        private GameObject go;
        // The single component currently shown on the right detail panel. The
        // left list is two-level: L1 GameObject nodes only expand/collapse,
        // L2 component nodes select the component to render here.
        private MonoBehaviour selectedComponent;

        // The right Custom panel container. Its children are built entirely by
        // reflection over the selected component's [PICODebuggerItem] members;
        // there are no fixed transform rows anymore.
        public GameObject panel;

        // Item prefabs for each DebuggerType, wired in the Inspector. Kept out of
        // any Resources/ folder so they are not exposed for runtime loading; the
        // factory instantiates whichever one matches the member's type.
        [SerializeField] private GameObject defaultItemPrefab;
        [SerializeField] private GameObject toggleItemPrefab;
        [SerializeField] private GameObject rangeItemPrefab;
        [SerializeField] private GameObject actionItemPrefab;

        // Right-detail container for the reflection-built [PICODebuggerItem] rows.
        // Optional: if left unwired in the prefab it is created at runtime under
        // `panel`, so Goal B works without any additional prefab wiring.
        public Transform itemRoot;

        private bool isShowPanel = false;

        void Start()
        {
            TogglePanel(false);
        }
        void Update()
        {
            if (isShowPanel && selectedComponent == null)
            {
                TogglePanel(false);
                if (PXR_CustomManager.Instance != null)
                {
                    PXR_CustomManager.Instance.Refresh();
                }
            }
        }
        private void TogglePanel(bool state)
        {
            isShowPanel = state;
            if (panel != null)
            {
                panel.SetActive(state);
            }
        }
        // L2 selection entry point: render exactly one component's items.
        public void SetComponent(MonoBehaviour component)
        {
            selectedComponent = component;
            if (selectedComponent == null) return;
            go = selectedComponent.gameObject;
            TogglePanel(true);
            BuildItems();
        }

        // Retained for prefab-binding safety / older call sites. Selecting a
        // whole GameObject is no longer used by the two-level left list; it
        // falls back to the GameObject's first debuggable component (if any).
        public void SetGameObject(GameObject obj)
        {
            go = obj;
            if (go == null) return;
            selectedComponent = FindFirstDebuggable(go);
            TogglePanel(true);
            BuildItems();
        }
        public void RefreshTarget()
        {
            if (selectedComponent == null) return;
            go = selectedComponent.gameObject;
            TogglePanel(true);
            BuildItems();
        }
        private static MonoBehaviour FindFirstDebuggable(GameObject obj)
        {
            var comps = obj.GetComponents<MonoBehaviour>();
            foreach (var comp in comps)
            {
                if (comp == null) continue;
                if (PXR_CustomItemFactory.HasDebuggerItems(comp.GetType())) return comp;
            }
            return null;
        }
        public void ToggleGO(Toggle toggle)
        {
            if (go != null)
            {
                go.SetActive(toggle.isOn);
            }
        }

        // --- Goal B: reflection rendering of one component's [PICODebuggerItem]
        // members. The two-level left list selects a single component, so the
        // right panel lists exactly that script's fields / properties / methods.
        private void BuildItems()
        {
            EnsureItemRoot();
            ClearItems();
            if (selectedComponent == null) return;

            Type type = selectedComponent.GetType();
            if (!PXR_CustomItemFactory.HasDebuggerItems(type)) return;

            const BindingFlags flags = PXR_CustomItemFactory.MemberFlags;
            bool wroteHeader = false;

            foreach (var field in type.GetFields(flags))
            {
                var attr = field.GetCustomAttribute<PICODebuggerItemAttribute>(true);
                if (attr == null) continue;
                EnsureHeader(type, ref wroteHeader);
                PXR_CustomItemFactory.BuildItem(itemRoot, selectedComponent, field, attr, PrefabFor(attr.type));
            }
            foreach (var prop in type.GetProperties(flags))
            {
                var attr = prop.GetCustomAttribute<PICODebuggerItemAttribute>(true);
                if (attr == null) continue;
                EnsureHeader(type, ref wroteHeader);
                PXR_CustomItemFactory.BuildItem(itemRoot, selectedComponent, prop, attr, PrefabFor(attr.type));
            }
            foreach (var method in type.GetMethods(flags))
            {
                // Action: only no-arg void methods are supported.
                if (!PXR_CustomItemFactory.IsRenderableActionMethod(method)) continue;
                var attr = method.GetCustomAttribute<PICODebuggerItemAttribute>(true);
                EnsureHeader(type, ref wroteHeader);
                PXR_CustomItemFactory.BuildItem(itemRoot, selectedComponent, method, attr, PrefabFor(attr.type));
            }

            if (itemRoot is RectTransform rrt)
            {
                LayoutRebuilder.ForceRebuildLayoutImmediate(rrt);
            }
            // The ScrollRect Content has no ContentSizeFitter; sync its
            // height to the Panel so the ScrollRect can scroll to bottom
            // rows (bug 7345626621).
            var contentRT = itemRoot.parent as RectTransform;
            var panelRT = itemRoot as RectTransform;
            if (contentRT != null && panelRT != null)
            {
                contentRT.sizeDelta = new Vector2(contentRT.sizeDelta.x, panelRT.rect.height);
            }
        }

        // Maps a DebuggerType to the Inspector-wired prefab the factory will
        // instantiate for that row.
        private GameObject PrefabFor(DebuggerType type)
        {
            switch (type)
            {
                case DebuggerType.Toggle: return toggleItemPrefab;
                case DebuggerType.Range: return rangeItemPrefab;
                case DebuggerType.Action: return actionItemPrefab;
                default: return defaultItemPrefab;
            }
        }

        private void EnsureHeader(Type type, ref bool wroteHeader)
        {
            if (wroteHeader) return;
            PXR_CustomItemFactory.BuildGroupHeader(itemRoot, type.Name);
            wroteHeader = true;
        }

        private void EnsureItemRoot()
        {
            if (itemRoot != null) return;
            itemRoot = panel != null ? panel.transform : transform;
        }

        private void ClearItems()
        {
            if (itemRoot == null) return;
            for (int i = itemRoot.childCount - 1; i >= 0; i--)
            {
                var childGo = itemRoot.GetChild(i).gameObject;
#if UNITY_EDITOR
                if (!Application.isPlaying)
                    DestroyImmediate(childGo);
                else
                    Destroy(childGo);
#else
                Destroy(childGo);
#endif
            }
        }
    }
}
#endif
