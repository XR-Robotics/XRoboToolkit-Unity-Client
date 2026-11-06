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
using System.Collections;
using UnityEditor;
using UnityEngine;
using UnityEngine.InputSystem;
#if UNITY_EDITOR || DEVELOPMENT_BUILD
namespace ByteDance.PICO.Debugger
{
    public class PXR_UIManager : MonoBehaviour
    {
        public PXR_PicoDebuggerSO config;
        public PXR_UIController uiController;
        private GameObject _controller = null;
        private void Start()
        {
            config = Resources.Load<PXR_PicoDebuggerSO>("PXR_PicoDebuggerSO");
            uiController = Resources.Load<GameObject>("PXR_DebuggerPanel").GetComponent<PXR_UIController>();
            if (config.isOpen)
            {
                PXR_DebuggerInputManager.Instance.debuggerStartButton.performed += OnStartButtonPress;
            }
        }
        void OnDestroy()
        {
            PXR_DebuggerInputManager.Instance.debuggerStartButton.performed -= OnStartButtonPress;
        }
        private void OnStartButtonPress(InputAction.CallbackContext context)
        {
            ToggleController();
        }
        private void ToggleController()
        {
            if (_controller == null)
            {
                _controller = Instantiate(uiController.gameObject);
            }
            else
            {
                _controller.SetActive(!_controller.gameObject.activeSelf);
            }
        }
    }
}
#endif
