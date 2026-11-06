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
using UnityEditor;
#if UNITY_EDITOR || DEVELOPMENT_BUILD
namespace ByteDance.PICO.Debugger
{
    public class PXR_PicoDebuggerManager : MonoBehaviour
    {
        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
        private static void OnBeforeSceneLoadRuntimeMethod()
        {
            var config = Resources.Load<PXR_PicoDebuggerSO>("PXR_PicoDebuggerSO");
            if(config != null && config.isOpen){
                AddPrefab();
            }
        }

        private static void AddPrefab()
        {
            GameObject prefab = Resources.Load<GameObject>("PXR_PICODebugger");
            if (prefab != null)
            {
                Instantiate(prefab, Vector3.zero, Quaternion.identity);
                EnsureEventSystem();
            }
            else
            {
                Debug.LogError("Prefab not found in Resources folder.");
            }
        }

        // The debugger UI relies on an EventSystem (with a working input module)
        // for XR UI input. If the host scene has none -- or has a bare EventSystem
        // without an input module -- the panels render but cannot be interacted
        // with, so create / repair a minimal one here.
        private static void EnsureEventSystem()
        {
            var eventSystem = EventSystem.current;
            if (eventSystem == null) eventSystem = FindObjectOfType<EventSystem>();

            // Reuse an existing EventSystem only if it can actually dispatch input;
            // a bare EventSystem (no BaseInputModule) silently swallows UI events.
            if (eventSystem != null)
            {
                if (eventSystem.GetComponent<BaseInputModule>() == null)
                {
                    AddInputModule(eventSystem.gameObject);
                }
                return;
            }

            var go = new GameObject("PXR_DebuggerEventSystem");
            go.AddComponent<EventSystem>();
            AddInputModule(go);
            DontDestroyOnLoad(go);
        }

        private static void AddInputModule(GameObject go)
        {
#if ENABLE_INPUT_SYSTEM && UNITY_INPUT_SYSTEM
            // PICO HMD UI is driven by XR ray interactors, not mouse / touch. A raw
            // InputSystemUIInputModule with no actionsAsset does not respond to UI
            // input; XRUIInputModule ships with sensible defaults and needs no asset
            // wiring, matching the repo's XR input convention.
            go.AddComponent<UnityEngine.XR.Interaction.Toolkit.UI.XRUIInputModule>();
#else
            go.AddComponent<StandaloneInputModule>();
#endif
        }
    }
}
#endif