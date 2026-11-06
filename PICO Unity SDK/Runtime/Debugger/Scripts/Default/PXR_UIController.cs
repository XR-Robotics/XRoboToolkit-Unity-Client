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
    public class PXR_UIController : MonoBehaviour
    {
        public static PXR_UIController Instance { get; private set; }
        public PXR_PicoDebuggerSO config;
        [HideInInspector] public Vector3 origin;
        private Transform _camera;
        private float distance;
        private StartPosiion state;

        public void Awake()
        {
            if (config == null)
            {
                config = Resources.Load<PXR_PicoDebuggerSO>("PXR_PicoDebuggerSO");
            }

            if (Instance == null)
            {
                Instance = this;
            }
            Init();
        }
        private void Init()
        {
            _camera = Camera.main != null ? Camera.main.transform : null;
            state = config.startPosition;
            distance = GetDistance();
            if (_camera != null)
            {
                ResetTransform();
            }
        }

        public float GetDistance()
        {
            return state switch
            {
                StartPosiion.Far => 3f,
                StartPosiion.Medium => 2f,
                StartPosiion.Near => 1f,
                _ => 2f,
            };
        }
        private void OnEnable()
        {
            if (_camera == null) return;
            ResetTransform();
        }
        // Update is called once per frame
        private void ResetTransform()
        {
            if (_camera == null) return;
            origin = _camera.position;
            Vector3 forward = _camera.transform.forward;
            forward.y = 0;
            forward = forward.normalized;
            transform.position = origin + distance * forward;
            transform.forward = transform.position - origin;
        }

        /// <summary>
        /// Returns true if the given GameObject is the debugger's camera itself
        /// or one of its ancestors in the scene hierarchy. Prevents users from
        /// disabling nodes the debugger camera depends on (bug 7342935089).
        ///
        /// Walks up from the camera Transform to root on every call, so it
        /// always reflects the current hierarchy — no stale cache.
        /// </summary>
        public static bool IsCameraAncestor(GameObject go)
        {
            if (go == null) return false;

            // Use the instance-level _camera captured in Init(); fall back to
            // Camera.main if the instance hasn't been created yet or the
            // captured reference was destroyed.
            Transform cam = null;
            if (Instance != null)
            {
                cam = Instance._camera;
            }
            if (cam == null)
            {
                Camera mainCam = Camera.main;
                cam = mainCam != null ? mainCam.transform : null;
            }
            if (cam == null) return false;

#if UNITY_6000_4_OR_NEWER
            EntityId targetId = go.GetEntityId();
            var node = cam;
            while (node != null)
            {
                if (node.gameObject.GetEntityId() == targetId)
                    return true;
                node = node.parent;
            }
#else
            int targetId = go.GetInstanceID();
            var node = cam;
            while (node != null)
            {
                if (node.gameObject.GetInstanceID() == targetId)
                    return true;
                node = node.parent;
            }
#endif
            return false;
        }
    }
}
#endif