
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
using System.Collections;
using UnityEngine;
using UnityEngine.InputSystem;
#if UNITY_EDITOR || DEVELOPMENT_BUILD
namespace ByteDance.PICO.Debugger
{
    public class PXR_Tool_TimerController : MonoBehaviour
    {
        private readonly float delayTime = 0.5f;
        [SerializeField] private Animator anim;
        private bool isTurnOn = false;
        private bool isLock = true;

        void Start()
        {
            PXR_DebuggerInputManager.Instance.timerControllerButton.performed += CutDown;
            StartCoroutine(Delay(Open));
        }
        void OnDestroy()
        {
            Time.timeScale = 1f;
            PXR_DebuggerInputManager.Instance.timerControllerButton.performed -= CutDown;
        }
        private void CutDown(InputAction.CallbackContext context)
        {
            Debug.Log("time");
            if (isLock) return;
            isTurnOn = !isTurnOn;
            anim.SetBool("TurnOn", isTurnOn);
            StartCoroutine(Delay(Open));
            if (isTurnOn)
            {
                StartCoroutine(Delay(TimePause));
            }
            else
            {
                Time.timeScale = 1f;
            }
            isLock = true;
        }
        private IEnumerator Delay(Action action)
        {
            yield return new WaitForSeconds(delayTime);
            action();
        }
        private void Open()
        {
            isLock = false;
        }
        private void TimePause()
        {
            Time.timeScale = 0f;
        }
    }
}
#endif