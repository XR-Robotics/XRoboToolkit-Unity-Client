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
using System;
#if UNITY_EDITOR || DEVELOPMENT_BUILD
namespace ByteDance.PICO.Debugger
{
    public class PXR_InspectorController : MonoBehaviour
    {
        public static PXR_InspectorController Instance;
        private void Awake()
        {
            if (Instance == null)
            {
                Instance = this;
            }
        }
        private GameObject go;
        public GameObject panel;

        public TextMeshProUGUI targetName;
        public TextMeshProUGUI worldPositionX;
        public TextMeshProUGUI worldPositionY;
        public TextMeshProUGUI worldPositionZ;

        public TextMeshProUGUI localPositionX;
        public TextMeshProUGUI localPositionY;
        public TextMeshProUGUI localPositionZ;

        public TextMeshProUGUI worldEulerX;
        public TextMeshProUGUI worldEulerY;
        public TextMeshProUGUI worldEulerZ;

        public TextMeshProUGUI localEulerX;
        public TextMeshProUGUI localEulerY;
        public TextMeshProUGUI localEulerZ;

        public TextMeshProUGUI worldQuaternion;

        public TextMeshProUGUI localQuaternion;

        public TextMeshProUGUI scaleX;
        public TextMeshProUGUI scaleY;
        public TextMeshProUGUI scaleZ;

        public Toggle toggle;
        private bool isOnCameraChain = false;

        private PXR_PicoDebuggerSO config;
        private bool isShowPanel = false;

        void Start()
        {
            config = Resources.Load<PXR_PicoDebuggerSO>("PXR_PicoDebuggerSO");
            TogglePanel(false);
        }
        void Update()
        {
            if (isShowPanel && go == null)
            {
                TogglePanel(false);
                PXR_InspectorManager.Instance.Refresh();
            }
            if (go != null && go.transform.hasChanged)
            {
                UpdatePanel();
                go.transform.hasChanged = false;
            }
        }
        private void TogglePanel(bool state)
        {
            isShowPanel = state;
            panel.SetActive(state);
            if (state)
            {
                EnsureScrollLayout();
                if (panel.transform is RectTransform panelRT)
                {
                    LayoutRebuilder.ForceRebuildLayoutImmediate(panelRT);
                    // The ScrollRect Content has no ContentSizeFitter of its own;
                    // sync its height to the Panel so the ScrollRect knows the
                    // real scrollable area.
                    var contentRT = panel.transform.parent as RectTransform;
                    if (contentRT != null)
                    {
                        contentRT.sizeDelta = new Vector2(contentRT.sizeDelta.x, panelRT.rect.height);
                    }
                }
            }
        }

        // The prefab's Panel is missing ContentSizeFitter and has
        // childForceExpandHeight=true, which locks the panel to a fixed
        // 500px and squeezes all rows into that height. Fix it at runtime
        // so the Panel sizes to fit its children (bug 7342957103).
        private void EnsureScrollLayout()
        {
            var panelCSF = panel.GetComponent<ContentSizeFitter>();
            if (panelCSF == null)
                panelCSF = panel.AddComponent<ContentSizeFitter>();
            panelCSF.verticalFit = ContentSizeFitter.FitMode.PreferredSize;

            var panelVLG = panel.GetComponent<VerticalLayoutGroup>();
            if (panelVLG != null)
                panelVLG.childForceExpandHeight = false;
        }
        public void SetGameObject(GameObject obj)
        {
            go = obj;
            targetName.text = $"{go.name}";
            toggle.isOn = go.activeSelf;
            // Disable the PICOSwitch toggle when the target is the main camera
            // or one of its ancestors, preventing users from turning off nodes
            // the debugger camera depends on (bug 7342935089).
            isOnCameraChain = PXR_UIController.IsCameraAncestor(go);
            if(!isOnCameraChain){
                toggle.isOn = go.activeSelf;
            }else{
                toggle.isOn = false;
            }   
            toggle.enabled = !isOnCameraChain;
            toggle.interactable = !isOnCameraChain;
            TogglePanel(true);
            UpdatePanel();
        }
        public void RefreshTarget()
        {
            if (go == null)
            {
                TogglePanel(false);
                return;
            }
            targetName.text = $"{go.name}";
            isOnCameraChain = PXR_UIController.IsCameraAncestor(go);
            if(!isOnCameraChain){
                toggle.isOn = go.activeSelf;
            }else{
                toggle.isOn = false;
            }   
            toggle.enabled = !isOnCameraChain;
            toggle.interactable = !isOnCameraChain;
            TogglePanel(true);
            UpdatePanel();
        }
        public void ToggleGO(Toggle toggle)
        {
            if (go != null && !isOnCameraChain)
            {
                go.SetActive(toggle.isOn);
            }
        }
        public void ChangeWorldPositionX(float v)
        {
            go.transform.position += config.worldPositionStep * v * Vector3.right;
        }
        public void ChangeWorldPositionY(float v)
        {
            go.transform.position += config.worldPositionStep * v * Vector3.up;
        }
        public void ChangeWorldPositionZ(float v)
        {
            go.transform.position += config.worldPositionStep * v * Vector3.forward;
        }
        public void ChangeLocalPositionX(float v)
        {
            go.transform.localPosition += config.localPositionStep * v * Vector3.right;
        }
        public void ChangeLocalPositionY(float v)
        {
            go.transform.localPosition += config.localPositionStep * v * Vector3.up;
        }
        public void ChangeLocalPositionZ(float v)
        {
            go.transform.localPosition += config.localPositionStep * v * Vector3.forward;
        }
        public void ChangeWorldEulerAngleX(float v)
        {
            go.transform.eulerAngles += config.worldRotationStep * v * Vector3.right;
        }
        public void ChangeWorldEulerAngleY(float v)
        {
            go.transform.eulerAngles += config.worldRotationStep * v * Vector3.up;
        }
        public void ChangeWorldEulerAngleZ(float v)
        {
            go.transform.eulerAngles += config.worldRotationStep * v * Vector3.forward;
        }
        public void ChangeLocalEulerAngleX(float v)
        {
            go.transform.localEulerAngles += config.localRotationStep * v * Vector3.right;
        }
        public void ChangeLocalEulerAngleY(float v)
        {
            go.transform.localEulerAngles += config.localRotationStep * v * Vector3.up;
        }
        public void ChangeLocalEulerAngleZ(float v)
        {
            go.transform.localEulerAngles += config.localRotationStep * v * Vector3.forward;
        }
        // Scale: Unity's only writable scale is transform.localScale
        // (transform.lossyScale / world scale is read-only). The ScaleItem in
        // the Inspector panel drives these handlers so X/Y/Z step the object's
        // transform scale. Step size comes from worldScaleStep in settings.
        public void ChangeScaleX(float v)
        {
            go.transform.localScale += config.worldScaleStep * v * Vector3.right;
        }
        public void ChangeScaleY(float v)
        {
            go.transform.localScale += config.worldScaleStep * v * Vector3.up;
        }
        public void ChangeScaleZ(float v)
        {
            go.transform.localScale += config.worldScaleStep * v * Vector3.forward;
        }
        public void UpdatePanel()
        {
            worldPositionX.text = $"{go.transform.position.x}";
            worldPositionY.text = $"{go.transform.position.y}";
            worldPositionZ.text = $"{go.transform.position.z}";

            localPositionX.text = $"{go.transform.localPosition.x}";
            localPositionY.text = $"{go.transform.localPosition.y}";
            localPositionZ.text = $"{go.transform.localPosition.z}";

            worldEulerX.text = $"{go.transform.eulerAngles.x}";
            worldEulerY.text = $"{go.transform.eulerAngles.y}";
            worldEulerZ.text = $"{go.transform.eulerAngles.z}";

            localEulerX.text = $"{go.transform.localEulerAngles.x}";
            localEulerY.text = $"{go.transform.localEulerAngles.y}";
            localEulerZ.text = $"{go.transform.localEulerAngles.z}";

            worldQuaternion.text = $"{go.transform.rotation}";
            localQuaternion.text = $"{go.transform.localRotation}";

            scaleX.text = $"{go.transform.localScale.x}";
            scaleY.text = $"{go.transform.localScale.y}";
            scaleZ.text = $"{go.transform.localScale.z}";
        }

    }
}

#endif