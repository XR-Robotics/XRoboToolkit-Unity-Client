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
using UnityEngine.XR;
using System;
using Unity.XR.CoreUtils;
using UnityEngine.XR.Interaction.Toolkit;
using UnityEngine.InputSystem;
#if UNITY_EDITOR || DEVELOPMENT_BUILD
namespace ByteDance.PICO.Debugger
{
    public class PXR_DebuggerInputManager : MonoBehaviour
    {
        [HideInInspector]public InputAction debuggerStartButton;
        [HideInInspector]public InputAction timerControllerButton;
        [HideInInspector]public InputAction rulerControllerButton;
        [HideInInspector]public InputAction rulerReleaseButton;
        [Header("Left Controller")]
        private bool isTracingLeftController;
        [HideInInspector]public InputAction leftControllerPositionAction;
        [HideInInspector]public InputAction leftControllerRotationAction;
        
        [Header("Right Controller")]
        private bool isTracingRightController;
        [HideInInspector]public InputAction rightControllerPositionAction;
        [HideInInspector]public InputAction rightControllerRotationAction;
        
        public Transform leftController;
        public Transform rightController;
        private XROrigin cachedXROrigin;
        public static PXR_DebuggerInputManager Instance { get; private set; }
        private void Awake()
        {
            if (Instance != null)
            {
                Debug.LogError($"The singleton has multiple instances！");
            }
            else
            {
                Destroy(Instance);
            }
            Instance = this;
            Init();
            
        }
        private void SetActions()
        {
            InputActionAsset config = Resources.Load<PXR_PicoDebuggerSO>("PXR_PicoDebuggerSO").inputActionAsset;
            if(config != null){
                foreach (var actionMap in config.actionMaps)
                {
                    if(actionMap.name == PXR_DebuggerConst.actionName){
                        foreach (var action in actionMap.actions)
                        {
                            switch (action.name)
                            {
                                case PXR_DebuggerConst.debuggerStartButton:
                                    debuggerStartButton = action;
                                break;
                                case PXR_DebuggerConst.rulerReleaseButton:
                                    rulerReleaseButton = action;
                                break;
                                case PXR_DebuggerConst.rulerControllerButton:
                                    rulerControllerButton = action;
                                break;
                                case PXR_DebuggerConst.timerControllerButton:
                                    timerControllerButton = action;
                                break;
                                case PXR_DebuggerConst.leftControllerPosition:
                                    leftControllerPositionAction = action;
                                break;
                                case PXR_DebuggerConst.leftControllerRotation:
                                    leftControllerRotationAction = action;
                                break;
                                case PXR_DebuggerConst.rightControllerPosition:
                                    rightControllerPositionAction = action;
                                break;
                                case PXR_DebuggerConst.rightControllerRotation:
                                    rightControllerRotationAction = action;
                                break;
                                default:
                                    Debug.LogWarning($"Unknown action name: {action.name}");
                                break;
                            }
                        }
                    }
                }
            }
            
        }
        private void Init()
        {
            SetActions();
            // Enable actions
            leftControllerPositionAction.Enable();
            leftControllerRotationAction.Enable();
            rightControllerPositionAction.Enable();
            rightControllerRotationAction.Enable();

            debuggerStartButton.Enable();
            timerControllerButton.Enable();
            rulerControllerButton.Enable();
            rulerReleaseButton.Enable();
            
            // Subscribe to position changes
            leftControllerPositionAction.performed += OnLeftControllerPosition;
            rightControllerPositionAction.performed += OnRightControllerPosition;
        }
        public void ToggleTracingLeftController(bool state){
            isTracingLeftController = state;
        }
        public void ToggleTracingRightController(bool state){
            isTracingRightController = state;
        }
        private void OnLeftControllerPosition(InputAction.CallbackContext context)
        {
            Vector3 position = context.ReadValue<Vector3>();
            position.y += GetCameraYOffset();
            leftController.position = position;
        }

        private void OnRightControllerPosition(InputAction.CallbackContext context)
        {
            Vector3 position = context.ReadValue<Vector3>();
            position.y += GetCameraYOffset();
            rightController.position = position;
        }

        // The controller position actions report poses in tracking space. In Floor
        // tracking-origin mode the rig's floor offset already lifts those poses to
        // world height, so tools line up. In non-Floor (Device/Eye) mode the rig
        // applies a CameraYOffset to lift the camera instead, and that offset is NOT
        // baked into the action values, so the tools sit too low by exactly that
        // amount. Add it back here to keep tools aligned with the user's view.
        private float GetCameraYOffset()
        {
            var origin = GetActiveXROrigin();
            if (origin == null) return 0f;
            if ((origin.CurrentTrackingOriginMode & TrackingOriginModeFlags.Floor) != 0) return 0f;
            return origin.CameraYOffset;
        }

        // Cache the resolved XROrigin so the per-frame Update / position callbacks
        // do not run FindObjectsOfType every time; re-resolve only if it is lost.
        private XROrigin GetActiveXROrigin()
        {
            if (cachedXROrigin != null && cachedXROrigin.gameObject.activeInHierarchy)
            {
                return cachedXROrigin;
            }
            cachedXROrigin = FindActiveXROrigin();
            return cachedXROrigin;
        }

        private XROrigin FindActiveXROrigin()
        {
            foreach (var origin in FindObjectsOfType<XROrigin>())
            {
                if (origin.gameObject.activeInHierarchy)
                {
                    return origin;
                }
            }
            return null;
        }
        
        private void OnDisable()
        {
            leftControllerPositionAction.performed -= OnLeftControllerPosition;
            rightControllerPositionAction.performed -= OnRightControllerPosition;
            
            leftControllerPositionAction.Disable();
            leftControllerRotationAction.Disable();
            rightControllerPositionAction.Disable();
            rightControllerRotationAction.Disable();

            debuggerStartButton.Disable();
            timerControllerButton.Disable();
            rulerControllerButton.Disable();
            rulerReleaseButton.Disable();
        }
        void Update()
        {
            float yOffset = GetCameraYOffset();
            if (leftControllerPositionAction.enabled && isTracingLeftController)
            {
                Vector3 position = leftControllerPositionAction.ReadValue<Vector3>();
                position.y += yOffset;
                leftController.SetPositionAndRotation(position, leftControllerRotationAction.ReadValue<Quaternion>());
            }

            if (rightControllerPositionAction.enabled && isTracingRightController)
            {
                Vector3 position = rightControllerPositionAction.ReadValue<Vector3>();
                position.y += yOffset;
                rightController.SetPositionAndRotation(position, rightControllerRotationAction.ReadValue<Quaternion>());
            }
        }
    }
}
#endif