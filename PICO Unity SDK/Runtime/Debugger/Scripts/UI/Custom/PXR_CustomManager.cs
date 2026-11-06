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
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
#if UNITY_EDITOR || DEVELOPMENT_BUILD
namespace ByteDance.PICO.Debugger
{
    public class PXR_CustomManager : MonoBehaviour
    {
        public static PXR_CustomManager Instance;
        private void Awake(){
            if(Instance == null){
                Instance = this;
            }
        }
        // Field names kept identical to PXR_InspectorManager so the cloned
        // serialized bindings resolve after only swapping m_Script guid.
        public GameObject inspectItem;
        public Transform content;
        public GameObject transformInfoNode;
        private void ClearAllChildren(){
            int childCount = content.childCount;
            for (int i = childCount - 1; i >= 0; i--)
            {
                DestroyImmediate(content.GetChild(i).gameObject);
            }
        }
        public void CreateCustomList()
        {
            GenerateCustomList();
        }
        private void Start() {
            CreateCustomList();
        }
        public void Reset(){
            for (int i = 0; i < content.childCount; i++)
            {
                LayoutRebuilder.ForceRebuildLayoutImmediate(content.GetChild(i).GetComponent<RectTransform>());
            }
        }
        public void Refresh(){
            ClearAllChildren();
            GenerateCustomList();
            if (PXR_CustomController.Instance != null)
            {
                PXR_CustomController.Instance.RefreshTarget();
            }
        }
        // Goal B: scan for GameObjects whose components expose at least one
        // [PICODebuggerItem] member and list them flat (one level, parents and
        // children all peers, no tree). Detection is by item presence only —
        // there is no separate class-level marker, so a script can never be
        // silently dropped for forgetting one. Includes DontDestroyOnLoad
        // objects (which are NOT reachable through GetActiveScene().
        // GetRootGameObjects()), so we enumerate all loaded MonoBehaviours and
        // filter out prefab assets and the debugger's own UI.
        private void GenerateCustomList(){
            var seen = new HashSet<GameObject>();
            var behaviours = Resources.FindObjectsOfTypeAll<MonoBehaviour>();
            foreach (var mb in behaviours)
            {
                if (mb == null) continue;
                if (!PXR_CustomItemFactory.HasDebuggerItems(mb.GetType())) continue;

                GameObject obj = mb.gameObject;
                if (obj == null) continue;
                // Skip prefab assets / non-scene objects (assets have no valid scene).
                if (!obj.scene.IsValid()) continue;
                // Skip hidden / editor-only objects.
                if ((obj.hideFlags & (HideFlags.HideAndDontSave | HideFlags.DontSave)) != 0) continue;
                // Skip the debugger's own UI objects (same rule as Inspector).
                if (obj.GetComponent<PXR_UIController>() != null) continue;
                if (obj.GetComponent<PXR_UIManager>() != null) continue;
                if (!seen.Add(obj)) continue;

                var item = Instantiate(inspectItem, content);
                if (item.TryGetComponent(out PXR_CustomItem customItem))
                {
                    customItem.Init(obj.transform);
                }
            }
            Reset();
        }
    }
}
#endif
