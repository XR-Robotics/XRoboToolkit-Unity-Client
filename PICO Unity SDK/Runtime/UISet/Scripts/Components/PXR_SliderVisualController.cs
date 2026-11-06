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
using UnityEngine.EventSystems;
using System;
#if UNITY_EDITOR || DEVELOPMENT_BUILD
namespace ByteDance.PICO.Debugger
{
    [RequireComponent(typeof(Slider))]
    public class PXR_SliderVisualController : PXR_UIInputHandler
    {
        [Serializable]
        public struct IconInfo
        {
            public Sprite icon;
            [Range(0, 1)] public float scope;
        }
        public Slider slider;
        [Range(0, 1)] public float scope;
        public Image fillImage;
        public IconInfo[] iconInfoList;
        public GameObject handle;
        private bool isMultiIcon = false;
        private bool isHover = false;
        public bool canHideHandle;
        private bool IsShowHandle => !canHideHandle || isHover;

        void Awake()
        {
            if (slider == null) slider = GetComponent<Slider>();
            if (iconInfoList != null)
            {
                isMultiIcon = iconInfoList.Length > 1;
            }
            VisuallyHander();
        }
        void Update()
        {
            VisuallyHander();
        }
        private void OnValidate()
        {
            if (iconInfoList != null)
            {
                isMultiIcon = iconInfoList.Length > 1;
            }
            VisuallyHander();
        }
        private void VisuallyHander()
        {
            HandleHandler();
            IconHandler();
        }
        private void HandleHandler()
        {
            if (handle == null) return;
            handle.SetActive(slider.value > scope && IsShowHandle);
        }
        public override void OnPointerExit(PointerEventData eventData)
        {
            isHover = false;
        }
        public override void OnPointerEnter(PointerEventData eventData)
        {
            isHover = true;
        }
        private void IconHandler()
        {
            if (!isMultiIcon) return;
            for (var i = 0; i < iconInfoList.Length; i++)
            {
                if (iconInfoList[i].icon == null)
                {
                    Debug.Log("There is no configuration icon");
                    return;
                }
                if (slider.value <= iconInfoList[i].scope)
                {
                    if (fillImage != null) fillImage.sprite = iconInfoList[i].icon;
                    return;
                }
            }
        }
    }
}
#endif