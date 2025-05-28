using System;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;

using UnityEngine.XR.Interaction.Toolkit.UI;

/// -------------------------------
/// Des: UI interaction for Rendertarget rendering，For example, for the time processing of curved screen UI.
/// Author：wangchuang.1113@bytedance.com
/// Date：2024-1-23
/// -------------------------------
public class RenderTargetGraphicRaycaster : GraphicRaycaster
{
    protected Canvas currentCanvas;
    protected Vector2 lastKnownPosition;
    protected const float UI_CONTROL_OFFSET = 0.00001f;

    public GameObject TargetScreen;
    public LayerMask OverlayLayerMask;

    [NonSerialized]
    // Use a static to prevent list reallocation. We only need one of these globally (single main thread), and only to hold temporary data
    private static List<RaycastResult> _raycastResults = new List<RaycastResult>();


    public override void Raycast(PointerEventData eventData, List<RaycastResult> resultAppendList)
    {
        if (canvas == null)
        {
            return;
        }

        TrackedDeviceEventData deviceEventData = eventData as TrackedDeviceEventData;
        if (deviceEventData == null || deviceEventData.interactor == null)
        {
            base.Raycast(eventData, resultAppendList);
            return;
        }

        XRUIInputModule inputModel = eventData.currentInputModule as XRUIInputModule;
        if (inputModel == null)
        {
            return;
        }

        if (eventData.pointerDrag != null)
        {
            inputModel.uiCamera = eventData.pressEventCamera;
        }
        else
        {
            inputModel.uiCamera = eventCamera;
        }

        Camera currentCamera = inputModel.uiCamera;
        UnityEngine.XR.Interaction.Toolkit.Interactors.XRRayInteractor interactor = deviceEventData.interactor as UnityEngine.XR.Interaction.Toolkit.Interactors.XRRayInteractor;

        if (inputModel != null && interactor != null)
        {
            //   inputModel.uiCamera = Camera.main;
            TrackedDeviceModel deviceModel;
            inputModel.GetTrackedDeviceModel(deviceEventData.interactor, out deviceModel);
            Vector3 forword = deviceModel.orientation * Vector3.forward;
            var ray = new Ray(deviceModel.position, forword);

            RaycastHit hit;
            if (Physics.Raycast(ray, out hit, interactor.maxRaycastDistance, OverlayLayerMask) &&
                hit.transform != null && hit.transform.gameObject == TargetScreen)
            {
                Renderer render = hit.transform.GetComponent<Renderer>();
                Texture texture = render.material.mainTexture;
                Vector2 controllerPosition =
                    new Vector2(hit.textureCoord.x * texture.width, hit.textureCoord.y * texture.height);
                deviceEventData.rayHitIndex = 1;
                RaycastOverLay(canvas, currentCamera, Vector3.Distance(ray.origin, hit.point), hit.point,
                    controllerPosition, ref _raycastResults);
            }
            else
            {
                Raycast(canvas, currentCamera, ray, ref _raycastResults);
            }

            SetNearestRaycast(ref eventData, ref resultAppendList, ref _raycastResults);
            Debug.DrawRay(deviceModel.position, forword, Color.cyan);
            _raycastResults.Clear();
        }
    }

    protected virtual void SetNearestRaycast(ref PointerEventData eventData, ref List<RaycastResult> resultAppendList,
        ref List<RaycastResult> raycastResults)
    {
        if (raycastResults != null && raycastResults.Count > 0)
        {
            eventData.position = raycastResults[0].screenPosition;
            eventData.delta = eventData.position - lastKnownPosition;
            eventData.pointerCurrentRaycast = raycastResults[0];
            resultAppendList.AddRange(raycastResults);
        }
    }

    protected virtual float GetHitDistance(Ray ray)
    {
        var hitDistance = float.MaxValue;

        if (canvas.renderMode != RenderMode.ScreenSpaceOverlay && blockingObjects != BlockingObjects.None)
        {
            var maxDistance = Vector3.Distance(ray.origin, canvas.transform.position);

            if (blockingObjects == BlockingObjects.ThreeD || blockingObjects == BlockingObjects.All)
            {
                RaycastHit hit;
                Physics.Raycast(ray, out hit, maxDistance);
                if (hit.collider)
                {
                    hitDistance = hit.distance;
                }
            }

            if (blockingObjects == BlockingObjects.TwoD || blockingObjects == BlockingObjects.All)
            {
                RaycastHit2D hit = Physics2D.Raycast(ray.origin, ray.direction, maxDistance);

                if (hit.collider != null)
                {
                    hitDistance = hit.fraction * maxDistance;
                }
            }
        }

        return hitDistance;
    }

    protected virtual void RaycastOverLay(Canvas canvas, Camera eventCamera, float distance, Vector3 worldPosition,
        Vector2 screenPosition, ref List<RaycastResult> results)
    {
        // var hitDistance = GetHitDistance(ray);
        var canvasGraphics = GraphicRegistry.GetGraphicsForCanvas(canvas);
        for (int i = 0; i < canvasGraphics.Count; ++i)
        {
            var graphic = canvasGraphics[i];

            if (graphic.depth == -1 || !graphic.raycastTarget)
            {
                continue;
            }

            if (!RectTransformUtility.RectangleContainsScreenPoint(graphic.rectTransform, screenPosition, eventCamera))
            {
                continue;
            }

            if (graphic.Raycast(screenPosition, eventCamera))
            {
                Vector3 world = worldPosition;
                RectTransformUtility.ScreenPointToWorldPointInRectangle(graphic.rectTransform, screenPosition,
                    eventCamera, out world);

                var result = new RaycastResult()
                {
                    gameObject = graphic.gameObject,
                    module = this,
                    distance = distance,
                    screenPosition = screenPosition,
                    worldPosition = world,
                    depth = graphic.depth,
                    sortingLayer = canvas.sortingLayerID,
                    sortingOrder = canvas.sortingOrder,
                };
                results.Add(result);
            }
        }

        results.Sort((g1, g2) => g2.depth.CompareTo(g1.depth));
    }

    protected virtual void Raycast(Canvas canvas, Camera eventCamera, Ray ray, ref List<RaycastResult> results)
    {
        var hitDistance = GetHitDistance(ray);
        var canvasGraphics = GraphicRegistry.GetGraphicsForCanvas(canvas);
        for (int i = 0; i < canvasGraphics.Count; ++i)
        {
            var graphic = canvasGraphics[i];

            if (graphic.depth == -1 || !graphic.raycastTarget)
            {
                continue;
            }

            var graphicTransform = graphic.transform;
            Vector3 graphicForward = graphicTransform.forward;
            float distance = Vector3.Dot(graphicForward, graphicTransform.position - ray.origin) /
                             Vector3.Dot(graphicForward, ray.direction);

            if (distance < 0)
            {
                continue;
            }

            //Prevents "flickering hover" on items near canvas center.
            if ((distance - UI_CONTROL_OFFSET) > hitDistance)
            {
                continue;
            }

            Vector3 position = ray.GetPoint(distance);
            Vector2 pointerPosition = eventCamera.WorldToScreenPoint(position);

            if (!RectTransformUtility.RectangleContainsScreenPoint(graphic.rectTransform, pointerPosition, eventCamera))
            {
                continue;
            }

            if (graphic.Raycast(pointerPosition, eventCamera))
            {
                var result = new RaycastResult()
                {
                    gameObject = graphic.gameObject,
                    module = this,
                    distance = distance,
                    screenPosition = pointerPosition,
                    worldPosition = position,
                    depth = graphic.depth,
                    sortingLayer = canvas.sortingLayerID,
                    sortingOrder = canvas.sortingOrder,
                };
                results.Add(result);
            }
        }

        results.Sort((g1, g2) => g2.depth.CompareTo(g1.depth));
    }

    protected virtual Canvas canvas
    {
        get
        {
            if (currentCanvas != null)
            {
                return currentCanvas;
            }

            currentCanvas = gameObject.GetComponent<Canvas>();
            return currentCanvas;
        }
    }
}