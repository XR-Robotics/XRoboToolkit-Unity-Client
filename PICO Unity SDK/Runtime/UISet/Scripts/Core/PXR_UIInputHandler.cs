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
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;
#if UNITY_EDITOR || DEVELOPMENT_BUILD
namespace ByteDance.PICO.Debugger
{
[RequireComponent(typeof(RectTransform))]
public class PXR_UIInputHandler : MonoBehaviour, IPointerDownHandler, IPointerUpHandler, IPointerMoveHandler, IPointerEnterHandler, IPointerExitHandler, IBeginDragHandler, IDragHandler, IEndDragHandler
{
    // Cache Canvas and Camera to improve performance
    private Canvas _parentCanvas;
    private Camera _eventCamera;

    
    [HideInInspector]public RectTransform rect;

    private void Awake()
    {
        _parentCanvas = GetComponentInParent<Canvas>();
        if (_parentCanvas == null)
        {
            Debug.LogError("This UI element is not under Canvas!", this);
            enabled = false;
            return;
        }

        _eventCamera = _parentCanvas.worldCamera;
        if (_eventCamera == null && _parentCanvas.renderMode != RenderMode.ScreenSpaceOverlay)
        {
            Debug.LogError("The World Camera of Canvas is not set!", this);
            enabled = false;
        }
        rect = GetComponent<RectTransform>();
    }
    public virtual void OnPointerDown(PointerEventData eventData){
        // Debug.Log("OnPointerDown ...");
    }
    public virtual void OnPointerUp(PointerEventData eventData) {
        // Debug.Log("OnPointerUp ...");
    }
    public virtual void OnPointerMove(PointerEventData eventData) {
        // Debug.Log("OnPointerMove ...");
    }
    public virtual void OnPointerEnter(PointerEventData eventData) {
        // Debug.Log("OnPointerEnter ...");
    }
    public virtual void OnPointerExit(PointerEventData eventData) {
        // Debug.Log("OnPointerExit ...");
    }
    public virtual void OnBeginDrag(PointerEventData eventData)
    {
        // Debug.Log("OnBeginDrag ...");
    }
    public virtual void OnDrag(PointerEventData data)
    {
        // Debug.Log("OnDrag ...");
    }
    public virtual void OnEndDrag(PointerEventData data)
    {
        // Debug.Log("OnEndDrag ...");
    }
    // todo opt
    protected void NormalizedPositionFromRay(in PointerEventData eventData,out Vector2? position)
    {
        Ray ray = new(_eventCamera.transform.position, _eventCamera.transform.forward);
        if (eventData.pointerCurrentRaycast.isValid == false )
        {
            position = null;
        }else{
            Vector3 worldHitPoint = eventData.pointerCurrentRaycast.worldPosition;

            RectTransform rectTransform = GetComponent<RectTransform>();
            Matrix4x4 worldToLocalMatrix = rectTransform.worldToLocalMatrix;
            Vector2 localPoint = worldToLocalMatrix.MultiplyPoint3x4(worldHitPoint);

            position = NormalizePoint(localPoint, rectTransform.rect);
        }
    }
    private Vector2 NormalizePoint(Vector2 point, Rect rect)
    {
        Vector2 bottomLeftOriginPoint = point - rect.position;

        float normalizedX = bottomLeftOriginPoint.x / rect.width;
        float normalizedY = bottomLeftOriginPoint.y / rect.height;

        return new Vector2(normalizedX, normalizedY);
    }
}
}
#endif