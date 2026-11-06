#if ENABLE_PICO_XR_SDK
using System;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Rendering;

namespace ByteDance.PICO.XR
{
    public class PXR_ObjectTrackingManager : MonoBehaviour
    {
        private const float FallbackMarkerSize = 0.1f;
        private readonly Dictionary<Guid, GameObject> objectMarkers = new Dictionary<Guid, GameObject>();
        private Material markerMaterial;

        private void Awake()
        {
            markerMaterial = CreateMarkerMaterial();
        }

        private async void Start()
        {
            var result = await PXR_MixedReality.StartSenseDataProvider(
                PxrSenseDataProviderType.DynamicObjectTracking);
            if (result != PxrResult.SUCCESS)
            {
                Debug.LogError($"[PXR_ObjectTrackingManager] StartSenseDataProvider failed: {result}");
            }
        }

        private void OnEnable()
        {
            PXR_Manager.DynamicObjectTrackingDataUpdated += DynamicObjectTrackingDataUpdated;
        }

        private void OnDisable()
        {
            PXR_Manager.DynamicObjectTrackingDataUpdated -= DynamicObjectTrackingDataUpdated;
        }

        private void OnDestroy()
        {
            foreach (var marker in objectMarkers.Values)
            {
                if (marker != null)
                {
                    Destroy(marker);
                }
            }
            objectMarkers.Clear();

            if (markerMaterial != null)
            {
                Destroy(markerMaterial);
                markerMaterial = null;
            }
        }

        private void DynamicObjectTrackingDataUpdated(List<PxrDynamicObjectData> objects)
        {
            var activeObjects = new HashSet<Guid>();
            foreach (var objectData in objects)
            {
                activeObjects.Add(objectData.uuid);
                var marker = GetOrCreateMarker(objectData);
                marker.transform.SetPositionAndRotation(objectData.position, objectData.rotation);
                marker.transform.localScale = GetObjectScale(objectData);
                marker.SetActive(true);
            }

            foreach (var marker in objectMarkers)
            {
                if (!activeObjects.Contains(marker.Key))
                {
                    marker.Value.SetActive(false);
                }
            }
        }

        private GameObject GetOrCreateMarker(PxrDynamicObjectData objectData)
        {
            if (objectMarkers.TryGetValue(objectData.uuid, out var marker))
            {
                return marker;
            }

            marker = GameObject.CreatePrimitive(IsFlatObject(objectData) ? PrimitiveType.Quad : PrimitiveType.Cube);
            marker.name = $"Dynamic Object {objectData.objectType} {objectData.uuid:N}";
            marker.transform.SetParent(transform, false);
            var renderer = marker.GetComponent<Renderer>();
            if (renderer != null && markerMaterial != null)
            {
                renderer.sharedMaterial = markerMaterial;
            }
            objectMarkers.Add(objectData.uuid, marker);
            return marker;
        }

        private static Vector3 GetObjectScale(PxrDynamicObjectData objectData)
        {
            if (objectData.objectType == PxrDynamicObjectType.Mouse &&
                objectData.sphereRadius > 0.0f)
            {
                var diameter = objectData.sphereRadius * 2.0f;
                return Vector3.one * diameter;
            }

            if (objectData.box3D.extent != Vector3.zero)
            {
                return objectData.box3D.extent;
            }

            return Vector3.one * FallbackMarkerSize;
        }

        private static bool IsFlatObject(PxrDynamicObjectData objectData)
        {
            return objectData.objectType == PxrDynamicObjectType.Keyboard ||
                   objectData.objectType == PxrDynamicObjectType.PicoKeyboard ||
                   objectData.objectType == PxrDynamicObjectType.PicoTouchpad ||
                   objectData.peripheralData.category == PxrPeripheralCategory.LaptopKeyboard ||
                   objectData.peripheralData.category == PxrPeripheralCategory.UncategorizedTouchpad;
        }

        private static Material CreateMarkerMaterial()
        {
#if UNITY_6000_0_OR_NEWER
            string shaderName = GraphicsSettings.defaultRenderPipeline != null
                ? "Universal Render Pipeline/Lit"
                : "Standard";
#else
            string shaderName = GraphicsSettings.renderPipelineAsset != null
                ? "Universal Render Pipeline/Lit"
                : "Standard";
#endif
            var shader = Shader.Find(shaderName);
            return shader != null ? new Material(shader) : null;
        }
    }
}
#endif
