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
#if UNITY_EDITOR || DEVELOPMENT_BUILD
namespace ByteDance.PICO.Debugger
{
    public class PXR_DragButton : MonoBehaviour, IBeginDragHandler, IDragHandler, IEndDragHandler
    {
        public Image image;
        private Camera _camera;
        public PXR_UIController uiController;
        private float radius = 5f; // Radius of a sphere
        public Transform container;
        [SerializeField] private Color defaultColor;
        [SerializeField] private Color hoverColor;
        private bool isDragging = false;
        private const float minAngel = 65f;
        private Vector3 origin;
        private void Start()
        {
            _camera = Camera.main;
        }
        public void OnDrag(PointerEventData eventData)
        {
            if (!isDragging) return;
            image.color = Color.Lerp(image.color, hoverColor, Time.deltaTime);

            Ray ray = _camera.ScreenPointToRay(eventData.position);
            Vector3 targetPosition = ray.origin + ray.direction * radius;
            Vector3 forward = targetPosition - origin;
            float angle = Vector3.Angle(Vector3.up, forward);
            if (angle < 90f || angle > 180f - minAngel) return;
            container.position = targetPosition;
            container.forward = forward;
            container.eulerAngles = new Vector3(0, container.eulerAngles.y, container.eulerAngles.z);
        }

        public void OnBeginDrag(PointerEventData eventData)
        {
            isDragging = true;
            radius = uiController.GetDistance();
            origin = _camera.transform.position;
        }

        public void OnEndDrag(PointerEventData eventData)
        {
            isDragging = false;
            image.color = defaultColor;
        }
    }
}
#endif