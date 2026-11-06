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
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.Management;
using UnityEngine.XR;
using UnityEngine.Scripting;
using AOT;
#if PICO_MS_SDK
using ByteDance.PICO.Spatial.Stage;
#endif
#if UNITY_INPUT_SYSTEM
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.Layouts;
using UnityEngine.InputSystem.XR;
using ByteDance.PICO.XR.Input;
using System.Linq;

#if XR_COMPOSITION_LAYERS
using Unity.XR.CompositionLayers.Services;
#endif

#endif

#if UNITY_EDITOR
using UnityEditor;
#endif

#if AR_FOUNDATION_5 || AR_FOUNDATION_6
using UnityEngine.XR.ARSubsystems;
#endif

#if XR_HANDS
using UnityEngine.XR.Hands;
#endif


namespace ByteDance.PICO.XR
{
#if UNITY_INPUT_SYSTEM
#if UNITY_EDITOR
    [InitializeOnLoad]
#endif
    static class InputLayoutLoader
    {
        static InputLayoutLoader()
        {
            RegisterInputLayouts();
        }

        public static void RegisterInputLayouts()
        {
#if ENABLE_PICO_XR_SDK||PICO_MS_SDK
            InputSystem.RegisterLayout<PXR_HMD>(matches: new InputDeviceMatcher().WithInterface(XRUtilities.InterfaceMatchAnyVersion)
                .WithProduct(@"^(PICO HMD)|^(PICO Neo)|^(PICO G)"));
            InputSystem.RegisterLayout<PXR_Controller>(matches: new InputDeviceMatcher().WithInterface(XRUtilities.InterfaceMatchAnyVersion)
                .WithProduct(@"^(PICO Controller)"));
#endif
        }
    }
#endif

    public class PXR_Loader : XRLoaderHelper
#if UNITY_EDITOR
    , IXRLoaderPreInit
#endif
    {
        private const string TAG = "PXR_Loader";
        private static List<XRDisplaySubsystemDescriptor> displaySubsystemDescriptors = new List<XRDisplaySubsystemDescriptor>();
        private static List<XRInputSubsystemDescriptor> inputSubsystemDescriptors = new List<XRInputSubsystemDescriptor>();
        private static List<XRMeshSubsystemDescriptor> meshSubsystemDescriptors = new List<XRMeshSubsystemDescriptor>();
#if XR_HANDS
        private static List<XRHandSubsystemDescriptor> handSubsystemDescriptors = new List<XRHandSubsystemDescriptor>();
#endif
#if AR_FOUNDATION_5 || AR_FOUNDATION_6
        private static List<XRSessionSubsystemDescriptor> sessionSubsystemDescriptors = new List<XRSessionSubsystemDescriptor>();
        private static List<XRCameraSubsystemDescriptor> cameraSubsystemDescriptors = new List<XRCameraSubsystemDescriptor>();
        private static List<XRFaceSubsystemDescriptor> faceSubsystemDescriptors = new List<XRFaceSubsystemDescriptor>();
        private static List<XRHumanBodySubsystemDescriptor> humanBodySubsystemDescriptors = new List<XRHumanBodySubsystemDescriptor>();
        private static List<XRAnchorSubsystemDescriptor> anchorSubsystemDescriptors = new List<XRAnchorSubsystemDescriptor>();
        private static List<XRPlaneSubsystemDescriptor> planeSubsystemDescriptors = new List<XRPlaneSubsystemDescriptor>();
#endif

        public delegate Quaternion ConvertRotationWith2VectorDelegate(Vector3 from, Vector3 to);

        public XRDisplaySubsystem displaySubsystem
        {
            get
            {
                return GetLoadedSubsystem<XRDisplaySubsystem>();
            }
        }

        public XRInputSubsystem inputSubsystem
        {
            get
            {
                return GetLoadedSubsystem<XRInputSubsystem>();
            }
        }

        public XRMeshSubsystem meshSubsystem
        {
            get
            {
                return GetLoadedSubsystem<XRMeshSubsystem>();
            }
        }
        internal enum LoaderState
        {
            Uninitialized,
            InitializeAttempted,
            Initialized,
            StartAttempted,
            Started,
            StopAttempted,
            Stopped,
            DeinitializeAttempted
        }

        internal LoaderState currentLoaderState { get; private set; } = LoaderState.Uninitialized;

        List<LoaderState> validLoaderInitStates = new List<LoaderState> { LoaderState.Uninitialized, LoaderState.InitializeAttempted };
        List<LoaderState> validLoaderStartStates = new List<LoaderState> { LoaderState.Initialized, LoaderState.StartAttempted, LoaderState.Stopped };
        List<LoaderState> validLoaderStopStates = new List<LoaderState> { LoaderState.StartAttempted, LoaderState.Started, LoaderState.StopAttempted };
        List<LoaderState> validLoaderDeinitStates = new List<LoaderState> { LoaderState.InitializeAttempted, LoaderState.Initialized, LoaderState.Stopped, LoaderState.DeinitializeAttempted };

        List<LoaderState> runningStates = new List<LoaderState>()
        {
            LoaderState.Initialized,
            LoaderState.StartAttempted,
            LoaderState.Started
        };
        public override bool Initialize()
        {
            Debug.Log($"{TAG} Initialize() currentLoaderState={currentLoaderState}");
#if UNITY_INPUT_SYSTEM
            InputLayoutLoader.RegisterInputLayouts();
#endif
#if PICO_MS_SDK
            SpatialNativeApi.UPxr_Init();
            if (inputSubsystem == null)
            {
                CreateSubsystem<XRInputSubsystemDescriptor, XRInputSubsystem>(inputSubsystemDescriptors, "PICO Input");
                if (inputSubsystem == null)
                    return false;
            }
#if XR_HANDS
            CreateSubsystem<XRHandSubsystemDescriptor, XRHandSubsystem>(handSubsystemDescriptors, "PICO Hands");
#endif
#if AR_FOUNDATION_6
            if (PXR_ProjectSetting.GetProjectConfig().arFoundation)
            {
                Debug.Log($"{TAG} [SpatialAdapterPlatform]  CreateSubsystem ");
                CreateSubsystem<XRSessionSubsystemDescriptor, XRSessionSubsystem>(sessionSubsystemDescriptors, PXR_SessionSubsystem.k_SubsystemId);
                if (PXR_ProjectSetting.GetProjectConfig().spatialAnchor)
                {
                    CreateSubsystem<XRAnchorSubsystemDescriptor, XRAnchorSubsystem>(anchorSubsystemDescriptors, PXR_AnchorSubsystem.k_SubsystemId);
                }
                if (PXR_ProjectSetting.GetProjectConfig().spatialMesh)
                {
                    Debug.Log($"{TAG} [SpatialAdapterPlatform]  CreateSubsystem XRMeshSubsystemDescriptor");
                    CreateSubsystem<XRMeshSubsystemDescriptor, XRMeshSubsystem>(meshSubsystemDescriptors, "PICO Mesh");
                }
            }
#endif
            SpatialNativeApi.Pmp_SetEventDataBufferCallBack(XrEventDataBufferFunction);
            currentLoaderState = LoaderState.Initialized;
            return true;
#else

// #if UNITY_ANDROID 
       
            PXR_Settings settings = GetSettings();
            if (settings != null)
            {
                UserDefinedSettings userDefinedSettings = new UserDefinedSettings
                {
                    stereoRenderingMode = settings.GetStereoRenderingMode(),
                    colorSpace = (ushort)((QualitySettings.activeColorSpace == ColorSpace.Linear) ? 1 : 0),
                    useContentProtect = Convert.ToUInt16(PXR_ProjectSetting.GetProjectConfig().useContentProtect),
                    systemDisplayFrequency = settings.GetSystemDisplayFrequency(),
                    optimizeBufferDiscards = settings.GetOptimizeBufferDiscards(),
                    enableAppSpaceWarp = Convert.ToUInt16(settings.enableAppSpaceWarp),
                    enableSubsampled = Convert.ToUInt16(PXR_ProjectSetting.GetProjectConfig().enableSubsampled),
                    lateLatchingDebug = Convert.ToUInt16(PXR_ProjectSetting.GetProjectConfig().latelatchingDebug),
                    enableStageMode = Convert.ToUInt16(PXR_ProjectSetting.GetProjectConfig().stageMode),
                    enableSuperResolution = Convert.ToUInt16(PXR_ProjectSetting.GetProjectConfig().superResolution),
                    normalSharpening = Convert.ToUInt16(PXR_ProjectSetting.GetProjectConfig().normalSharpening),
                    qualitySharpening = Convert.ToUInt16(PXR_ProjectSetting.GetProjectConfig().qualitySharpening),
                    fixedFoveatedSharpening = Convert.ToUInt16(PXR_ProjectSetting.GetProjectConfig().fixedFoveatedSharpening),
                    selfAdaptiveSharpening = Convert.ToUInt16(PXR_ProjectSetting.GetProjectConfig().selfAdaptiveSharpening),
#if UNITY_6000_0_OR_NEWER && ENABLE_PICO_XR_SDK
                    enableETFR = 0,
                    foveationLevel = 0,
#else
                    enableETFR = Convert.ToUInt16(PXR_ProjectSetting.GetProjectConfig().enableETFR),
                    foveationLevel = Convert.ToUInt16((int)PXR_ProjectSetting.GetProjectConfig().foveationLevel + 1),
#endif
                    spatialMeshLod = Convert.ToUInt16(PXR_ProjectSetting.GetProjectConfig().meshLod),
                    enableEyeTracking = Convert.ToUInt16(PXR_ProjectSetting.GetProjectConfig().eyeTracking),
                    dynamicFoveation =1,
                };
                
                PXR_Plugin.System.UPxr_SetUserDefinedSettings(userDefinedSettings);
            }
#if ENABLE_PICO_XR_SDK || ENABLE_PICO_OPENXR_SDK
            PXR_Plugin.System.UPxr_SetXrEventDataBufferCallBack(XrEventDataBufferFunction);
#endif
// #endif

            PXR_Plugin.System.ProductName = PXR_Plugin.System.UPxr_GetProductName();
            PXR_Plugin.System.UPxr_GetSDKLogLevel();
            if (currentLoaderState == LoaderState.Initialized)
                return true;

            if (!validLoaderInitStates.Contains(currentLoaderState))
                return false;

            if (displaySubsystem == null)
            {
                CreateSubsystem<XRDisplaySubsystemDescriptor, XRDisplaySubsystem>(displaySubsystemDescriptors, "PICO Display");
                if (displaySubsystem == null)
                    return false;
            }

            if (inputSubsystem == null)
            {
                CreateSubsystem<XRInputSubsystemDescriptor, XRInputSubsystem>(inputSubsystemDescriptors, "PICO Input");
                if (inputSubsystem == null)
                    return false;
            }
            if (PXR_ProjectSetting.GetProjectConfig().spatialMesh)
            {
                CreateSubsystem<XRMeshSubsystemDescriptor, XRMeshSubsystem>(meshSubsystemDescriptors, "PICO Mesh");
            }
#if XR_HANDS
            CreateSubsystem<XRHandSubsystemDescriptor, XRHandSubsystem>(handSubsystemDescriptors, "PICO Hands");
#endif
#if ENABLE_PICO_XR_SDK || ENABLE_PICO_OPENXR_SDK
#if AR_FOUNDATION_5 || AR_FOUNDATION_6
            if (PXR_ProjectSetting.GetProjectConfig().arFoundation)
            {
                CreateSubsystem<XRSessionSubsystemDescriptor, XRSessionSubsystem>(sessionSubsystemDescriptors, PXR_SessionSubsystem.k_SubsystemId);
                CreateSubsystem<XRCameraSubsystemDescriptor, XRCameraSubsystem>(cameraSubsystemDescriptors, PXR_CameraSubsystem.k_SubsystemId);
                if (PXR_ProjectSetting.GetProjectConfig().faceTracking)
                {
                    CreateSubsystem<XRFaceSubsystemDescriptor, XRFaceSubsystem>(faceSubsystemDescriptors, PXR_FaceSubsystem.k_SubsystemId);
                }
                if (PXR_ProjectSetting.GetProjectConfig().bodyTracking)
                {
                    CreateSubsystem<XRHumanBodySubsystemDescriptor, XRHumanBodySubsystem>(humanBodySubsystemDescriptors, PXR_HumanBodySubsystem.k_SubsystemId);
                }
                if (PXR_ProjectSetting.GetProjectConfig().spatialAnchor)
                {
                    CreateSubsystem<XRAnchorSubsystemDescriptor, XRAnchorSubsystem>(anchorSubsystemDescriptors, PXR_AnchorSubsystem.k_SubsystemId);
                }
                if (PXR_ProjectSetting.GetProjectConfig().planeDetection)
                {
                    CreateSubsystem<XRPlaneSubsystemDescriptor, XRPlaneSubsystem>(planeSubsystemDescriptors, PXR_PlaneSubsystem.k_SubsystemId);
                }
            }
#endif
#endif

            if (displaySubsystem == null && inputSubsystem == null)
            {
                Debug.LogError("PXRLog Unable to start PICO Plugin.");
            }
            else if (displaySubsystem == null)
            {
                Debug.LogError("PXRLog Failed to load display subsystem.");
            }
            else if (inputSubsystem == null)
            {
                Debug.LogError("PXRLog Failed to load input subsystem.");
            }
            else
            {
                PXR_Plugin.System.UPxr_InitializeFocusCallback();
            }
            PXR_Plugin.Loadstate=true;
#if XR_HANDS
            var handSubSystem = GetLoadedSubsystem<XRHandSubsystem>();
            if (handSubSystem == null)
            {
                Debug.LogError("PXRLog Failed to load XRHandSubsystem.");
            }
#endif

            if (PXR_ProjectSetting.GetProjectConfig().spatialAnchor)
            {
                PXR_Plugin.MixedReality.UPxr_CreateSpatialAnchorSenseDataProvider();
            }
            if (PXR_ProjectSetting.GetProjectConfig().sceneCapture)
            {
                PXR_Plugin.MixedReality.UPxr_CreateSceneCaptureSenseDataProvider();
            }
            if (PXR_ProjectSetting.GetProjectConfig().planeDetection)
            {
                PXR_Plugin.MixedReality.UPxr_CreatePlaneDetectionSenseDataProvider();
            }
            if (PXR_ProjectSetting.GetProjectConfig().environmentDepth)
            {
                PXR_Plugin.MixedReality.UPxr_CreateEnvironmentDepthSenseDataProvider();
            }
            if (PXR_ProjectSetting.GetProjectConfig().lightEstimation)
            {
                PXR_Plugin.MixedReality.UPxr_CreateLightEstimationProvider(PXR_ProjectSetting.GetProjectConfig().lightEstimationTextureResolution);
            }
            if (PXR_ProjectSetting.GetProjectConfig().objectTracking)
            {
                PXR_Plugin.MixedReality.UPxr_CreateDynamicObjectTrackingSenseDataProvider(
                    new[]
                    {
                        PxrDynamicObjectType.Keyboard,
                        PxrDynamicObjectType.PicoKeyboard,
                        PxrDynamicObjectType.Mouse,
                        PxrDynamicObjectType.PicoTouchpad
                    });
            }


            currentLoaderState = LoaderState.Initialized;
            return displaySubsystem != null;
#endif
        }
        
#if PICO_MS_SDK
        [MonoPInvokeCallback(typeof(SpatialNativeApi.XrEventDataCallBack))]
        static void XrEventDataBufferFunction(ref int data, ref int action)
        {
            Debug.Log($"PICO_MS_SDK XrEventDataBufferFunction eventType={action}");
            switch (action)
            {
                case (int)EventAction.MESH_UPDATE:
                    Debug.Log($"GetSpatialMeshDataInfo count={data} eventType={action}");
                    List<PxrSpatialMeshInfo> meshInfos = new List<PxrSpatialMeshInfo>();
                    for (int i = 0; i < data; i++)
                    {
                        SpatialNativeApi.GetSpatialMeshDataInfo(out Guid uuid, out int state, out Vector3 position,
                            out Quaternion rotation, out ushort[] indices, out Vector3[] vertices,
                            out SemanticLabel[] labels);
                        PxrSpatialMeshInfo meshInfo = new PxrSpatialMeshInfo();
                        meshInfo.uuid = uuid;
                        meshInfo.state = (MeshChangeState)state;
                        meshInfo.position = position;
                        meshInfo.rotation = rotation;
                        meshInfo.indices = indices;
                        meshInfo.vertices = vertices;
                        meshInfo.labels = Array.ConvertAll(labels, b => (PxrSemanticLabel)b);
                        meshInfos.Add(meshInfo);
                    }

                    // for (int i = 0; i < meshInfos.Count; i++)
                    // {
                    //     Debug.Log("GetSpatialMeshDataInfo uuid: " + meshInfos[i].uuid + " state: " + meshInfos[i].state +
                    //               " position: " + meshInfos[i].position + " rotation: " + meshInfos[i].rotation);
                    //     for (int ii = 0; ii < meshInfos[i].indices.Length; ii++)
                    //     {
                    //         Debug.Log($"GetSpatialMeshDataInfo indices[{ii}]: {meshInfos[i].indices[ii]}");
                    //     }
                    //     
                    //     for (int ii = 0; ii < meshInfos[i].vertices.Length; ii++)
                    //     {
                    //         Debug.Log($"GetSpatialMeshDataInfo vertices[{ii}]: {meshInfos[i].vertices[ii]}");
                    //     }
                    //     
                    //     for (int ii = 0; ii < meshInfos[i].labels.Length; ii++)
                    //     {
                    //         Debug.Log($"GetSpatialMeshDataInfo semanticLabels[{ii}]: {meshInfos[i].labels[ii]}");
                    //     }
                    // }
                    PXR_Manager.QuerySpatialMeshAnchor(meshInfos);
                    break;
            }
        }
#endif
        public override bool Start()
        {
            Debug.Log($"{TAG} Start() currentLoaderState={currentLoaderState}");
            
            
            if (currentLoaderState == LoaderState.Started)
                return true;

            if (!validLoaderStartStates.Contains(currentLoaderState))
                return false;

            currentLoaderState = LoaderState.StartAttempted;
            
            StartSubsystem<XRInputSubsystem>();
#if PICO_MS_SDK
#if XR_HANDS
            StartSubsystem<XRHandSubsystem>();
#endif
#if AR_FOUNDATION_6

            if (PXR_ProjectSetting.GetProjectConfig().spatialAnchor)
            {
                StartSubsystem<XRAnchorSubsystem>();
            }
#endif
            return true;
#else
            StartSubsystem<XRDisplaySubsystem>();
#if XR_HANDS
            StartSubsystem<XRHandSubsystem>();
#endif
#if AR_FOUNDATION_5 || AR_FOUNDATION_6
            if (PXR_ProjectSetting.GetProjectConfig().arFoundation)
            {
                StartSubsystem<XRCameraSubsystem>();
                if (PXR_ProjectSetting.GetProjectConfig().bodyTracking)
                {
                    StartSubsystem<XRHumanBodySubsystem>();
                }

                if (PXR_ProjectSetting.GetProjectConfig().faceTracking)
                {
                    StartSubsystem<XRFaceSubsystem>();
                }
            }

            if (PXR_ProjectSetting.GetProjectConfig().spatialAnchor)
            {
                StartSubsystem<XRAnchorSubsystem>();
            }
            
            if (PXR_ProjectSetting.GetProjectConfig().planeDetection)
            {
                StartSubsystem<XRPlaneSubsystem>();
            }
            
#endif

            if (!displaySubsystem?.running ?? false)
            {
                StartSubsystem<XRDisplaySubsystem>();
            }

            if (!inputSubsystem?.running ?? false)
            {
                StartSubsystem<XRInputSubsystem>();
            }
            currentLoaderState = LoaderState.Started;
#if ENABLE_PICO_XR_SDK
            ApplyKeyboardPassthroughPreferenceIfNeeded(true);
#endif

            return true;
#endif
        }

#if ENABLE_PICO_XR_SDK
        private PxrResult ApplyKeyboardPassthroughPreferenceIfNeeded(bool enabled)
        {
            if (enabled && !PXR_ProjectSetting.GetProjectConfig().keyboardPassthrough)
            {
                return PxrResult.SUCCESS;
            }

            var result = PXR_MixedReality.SetEnvironmentPassthroughPreference(
                PxrEnvironmentPassthroughType.Keyboard,
                enabled);
            if (result != PxrResult.SUCCESS)
            {
                Debug.LogWarning(
                    $"{TAG} SetEnvironmentPassthroughPreference Keyboard={enabled} Failed:{result}");
            }

            return result;
        }
#endif

        public override bool Stop()
        {
            Debug.Log($"{TAG} Stop() currentLoaderState={currentLoaderState}");
            if (currentLoaderState == LoaderState.Stopped)
                return true;

            if (!validLoaderStopStates.Contains(currentLoaderState))
                return false;

            currentLoaderState = LoaderState.StopAttempted;
            var inputRunning = inputSubsystem?.running ?? false;
            if (inputRunning)
            {
                StopSubsystem<XRInputSubsystem>();
            }
#if PICO_MS_SDK
#if XR_HANDS
            StopSubsystem<XRHandSubsystem>();
#endif
#if AR_FOUNDATION_6

            if (PXR_ProjectSetting.GetProjectConfig().spatialAnchor)
            {
                StopSubsystem<XRAnchorSubsystem>();
            }
#endif
            return true;
#else

            var displayRunning = displaySubsystem?.running ?? false;
            if (displayRunning)
            {
                StopSubsystem<XRDisplaySubsystem>();
            }
            if ((meshSubsystem != null && PXR_ProjectSetting.GetProjectConfig().spatialMesh))
            {
                if (meshSubsystem.running)
                {
                    StopSubsystem<XRMeshSubsystem>();
                }
                PXR_Plugin.MixedReality.UPxr_DisposeMesh();
                DestroySubsystem<XRMeshSubsystem>();
            }
            
            PXR_Plugin.Loadstate=false;
#if XR_HANDS
            StopSubsystem<XRHandSubsystem>();
#endif
#if AR_FOUNDATION_5 || AR_FOUNDATION_6
            if (PXR_ProjectSetting.GetProjectConfig().arFoundation)
            {
                StopSubsystem<XRCameraSubsystem>();
                if (PXR_ProjectSetting.GetProjectConfig().bodyTracking)
                {
                    StopSubsystem<XRHumanBodySubsystem>();
                }

                if (PXR_ProjectSetting.GetProjectConfig().faceTracking)
                {
                    StopSubsystem<XRFaceSubsystem>();
                }
            }

            if (PXR_ProjectSetting.GetProjectConfig().spatialAnchor)
            {
                StopSubsystem<XRAnchorSubsystem>();
            }
            if (PXR_ProjectSetting.GetProjectConfig().planeDetection)
            {
                StopSubsystem<XRPlaneSubsystem>();
            }
#endif
            PXR_Plugin.System.UPxr_DeinitializeFocusCallback();
#if ENABLE_PICO_XR_SDK || ENABLE_PICO_OPENXR_SDK
            if (PXR_ProjectSetting.GetProjectConfig().spatialAnchor)
            {
                PXR_MixedReality.GetSenseDataProviderState(PxrSenseDataProviderType.SpatialAnchor, out var providerState);
                if (providerState == PxrSenseDataProviderState.Running)
                {
                    PXR_MixedReality.StopSenseDataProvider(PxrSenseDataProviderType.SpatialAnchor);
                }
                PXR_Plugin.MixedReality.UPxr_DestroySenseDataProvider(PXR_Plugin.MixedReality.UPxr_GetSenseDataProviderHandle(PxrSenseDataProviderType.SpatialAnchor));
            }
            if (PXR_ProjectSetting.GetProjectConfig().sceneCapture)
            {
                PXR_MixedReality.GetSenseDataProviderState(PxrSenseDataProviderType.SceneCapture, out var providerState);
                if (providerState == PxrSenseDataProviderState.Running)
                {
                    PXR_MixedReality.StopSenseDataProvider(PxrSenseDataProviderType.SceneCapture);
                }
                PXR_Plugin.MixedReality.UPxr_DestroySenseDataProvider(PXR_Plugin.MixedReality.UPxr_GetSenseDataProviderHandle(PxrSenseDataProviderType.SceneCapture));
            }
            if (PXR_ProjectSetting.GetProjectConfig().planeDetection)
            {
                PXR_MixedReality.GetSenseDataProviderState(PxrSenseDataProviderType.PlaneDetection, out var providerState);
                if (providerState == PxrSenseDataProviderState.Running)
                {
                    PXR_MixedReality.StopSenseDataProvider(PxrSenseDataProviderType.PlaneDetection);
                }
                PXR_Plugin.MixedReality.UPxr_DestroySenseDataProvider(PXR_Plugin.MixedReality.UPxr_GetSenseDataProviderHandle(PxrSenseDataProviderType.PlaneDetection));
            }
            
            if (PXR_ProjectSetting.GetProjectConfig().environmentDepth)
            {
                PXR_Plugin.MixedReality.UPxr_DestroyEnvironmentDepthSenseDataProvider();
            }
            
            if (PXR_ProjectSetting.GetProjectConfig().lightEstimation)
            {
                PXR_MixedReality.GetSenseDataProviderState(PxrSenseDataProviderType.LightEstimation, out var providerState);
                if (providerState == PxrSenseDataProviderState.Running)
                {
                    PXR_MixedReality.StopSenseDataProvider(PxrSenseDataProviderType.LightEstimation);
                }
                PXR_Plugin.MixedReality.UPxr_DestroySenseDataProvider(PXR_Plugin.MixedReality.UPxr_GetSenseDataProviderHandle(PxrSenseDataProviderType.LightEstimation));
            }
            if (PXR_ProjectSetting.GetProjectConfig().objectTracking &&
                PXR_Plugin.MixedReality.DynamicObjectTrackingProviderHandle != 0)
            {
                PXR_Plugin.MixedReality.UPxr_DestroyDynamicObjectTrackingSenseDataProvider();
            }
            
#endif
            currentLoaderState = LoaderState.Stopped;
            return true;
#endif
        }

        public override bool Deinitialize()
        {
            Debug.Log($"{TAG} Deinitialize() currentLoaderState={currentLoaderState}");
            if (PXR_Plugin.System.IsOpenXRLoaderActive())
            {
                return false;
            }
            if (currentLoaderState == LoaderState.Uninitialized)
                return true;

            if (!validLoaderDeinitStates.Contains(currentLoaderState))
            {
                return false;
            }

            currentLoaderState = LoaderState.DeinitializeAttempted;
            
            DestroySubsystem<XRInputSubsystem>();
            
#if PICO_MS_SDK
           
#if XR_HANDS
            DestroySubsystem<XRHandSubsystem>();
#endif
#if AR_FOUNDATION_6

            if (PXR_ProjectSetting.GetProjectConfig().spatialAnchor)
            {
                DestroySubsystem<XRAnchorSubsystem>();
            }
            if (PXR_ProjectSetting.GetProjectConfig().spatialMesh)
            {
                if (meshSubsystem.running)
                {
                    StopSubsystem<XRMeshSubsystem>();
                }
                PXR_Plugin.MixedReality.UPxr_DisposeMesh();
                DestroySubsystem<XRMeshSubsystem>();
            }
#endif
            SpatialNativeApi.Pmp_Deinitialize();
            return true;
#else

            DestroySubsystem<XRDisplaySubsystem>();
           
#if XR_HANDS
            DestroySubsystem<XRHandSubsystem>();
#endif
#if AR_FOUNDATION_5 || AR_FOUNDATION_6
            if (PXR_ProjectSetting.GetProjectConfig().arFoundation)
            {
                DestroySubsystem<XRCameraSubsystem>();
                if (PXR_ProjectSetting.GetProjectConfig().bodyTracking)
                {
                    DestroySubsystem<XRHumanBodySubsystem>();
                }

                if (PXR_ProjectSetting.GetProjectConfig().faceTracking)
                {
                    DestroySubsystem<XRFaceSubsystem>();
                }
            }
#endif


            currentLoaderState = LoaderState.Uninitialized;
            Debug.Log($"{TAG} Deinitialize() end currentLoaderState={currentLoaderState}");
            return true;
#endif
        }
#if ENABLE_PICO_XR_SDK || ENABLE_PICO_OPENXR_SDK
        [MonoPInvokeCallback(typeof(ConvertRotationWith2VectorDelegate))]
        static Quaternion ConvertRotationWith2Vector(Vector3 from, Vector3 to)
        {
            return Quaternion.FromToRotation(from, to);
        }

        [MonoPInvokeCallback(typeof(XrEventDataBufferCallBack))]
        static void XrEventDataBufferFunction(ref XrEventDataBuffer eventDB)
        {
            int status, action;
            PLog.d("XrEventFunction",$"XrEventDataBufferFunction eventType={eventDB.type}",false);
            switch (eventDB.type)
            {
                case XrStructureType.XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED:
                    
                    int sessionstate = BitConverter.ToInt32(eventDB.data, 8);
                    Debug.Log($"XrEventDataBufferFunction sessionstate={sessionstate}");
                    if (PXR_Plugin.System.SessionStateChanged != null)
                    {                        
                        PXR_Plugin.System.SessionStateChanged((XrSessionState)sessionstate);
                    }
#if AR_FOUNDATION_5 || AR_FOUNDATION_6
                    PXR_SessionSubsystem.instance?.OnSessionStateChange((XrSessionState)sessionstate);
#endif
#if XR_COMPOSITION_LAYERS
                    OnSessionStateChanged((XrSessionState)sessionstate);
#endif
                    break;
                case XrStructureType.XR_TYPE_EVENT_CONTROLLER_STATE_CHANGED_PICO:

                    XrDeviceEventType eventType = (XrDeviceEventType)eventDB.data[0];
                    status = eventDB.data[5];
                    action = eventDB.data[6];
                    PLog.i(TAG, $"Controller eventType={eventType}, status={status}, action={action}", false);
                    switch (eventType)
                    {
                        case XrDeviceEventType.XR_DEVICE_INPUTDEVICE_CHANGED:
                            if (PXR_Plugin.System.InputDeviceChanged != null)
                            {
                                PXR_Plugin.System.InputDeviceChanged(status);
                            }
                            break;
                    }

                    break;
                case XrStructureType.XR_TYPE_EVENT_DATA_DISPLAY_REFRESH_RATE_CHANGED_FB:
                    float drRate = BitConverter.ToSingle(eventDB.data, 4);
                    if (PXR_Plugin.System.DisplayRefreshRateChangedAction != null)
                    {
                        PXR_Plugin.System.DisplayRefreshRateChangedAction(drRate);
                    }

                    PLog.i(TAG, $"RefreshRateChanged value ={drRate}", false);
                    break;
                case XrStructureType.XR_TYPE_EVENT_SEETHROUGH_STATE_CHANGED:
                    status = BitConverter.ToInt32(eventDB.data, 0);
                    PXR_Plugin.Boundary.seeThroughState = status;
                    if (PXR_Plugin.Boundary.SeethroughStateChangedAction != null)
                    {
                        PXR_Plugin.Boundary.SeethroughStateChangedAction(status);
                    }

                    PLog.i(TAG, $"SeethroughStateChanged status ={status}", false);
                    break;
                case XrStructureType.XR_TYPE_EVENT_DATA_MRC_STATUS_CHANGED_PICO:
                    status = BitConverter.ToInt32(eventDB.data, 0);
                    PLog.i(TAG, $"XR_TYPE_EVENT_DATA_MRC_STATUS_CHANGED_PICO status ={status}", false);
                    PXR_Plugin.System.enableMRC = status == 1;
                    if (PXR_Plugin.System.MRCStateChangedAction != null)
                    {
                        PXR_Plugin.System.MRCStateChangedAction(status == 1);
                    }

                    break;
                case XrStructureType.XR_TYPE_EVENT_LOG_LEVEL_CHANGE:
                    status = BitConverter.ToInt32(eventDB.data, 4);
                    PLog.logLevel = (PLog.LogLevel)status;
                    PLog.d(TAG, $"SDKLoglevelChanged logLevel ={status}");
                    break;
                case XrStructureType.XR_TYPE_EVENT_DATA_USER_PRESENCE_CHANGED_EXT:
                    bool isUserPresent = BitConverter.ToBoolean(eventDB.data, 8);
                    if (PXR_Plugin.System.UserPresenceChangedAction != null)
                    {
                        PXR_Plugin.System.UserPresenceChangedAction(isUserPresent);
                    }

                    break;
                case XrStructureType.XR_TYPE_EVENT_KEY_EVENT:
                    if (PXR_Plugin.System.RecenterSuccess != null)
                    {
                        PXR_Plugin.System.RecenterSuccess();
                    }

                    break;
                
                case XrStructureType.XR_TYPE_EVENT_DATA_ENVIRONMENT_BLEND_MODE_CHANGED_EXT:
                    if (PXR_Manager.VstDisplayStatusChanged != null)
                    {
                        int status_ = BitConverter.ToInt32(eventDB.data, 8);
                        PXR_Manager.VstDisplayStatusChanged(status_==1?PxrVstStatus.Disabled:PxrVstStatus.Enabled);
                    }
                    break;
                case XrStructureType.XR_TYPE_EVENT_DATA_SENSE_DATA_PROVIDER_STATE_CHANGED:
                case XrStructureType.XR_TYPE_EVENT_DATA_SENSE_DATA_UPDATED:
                case XrStructureType.XR_TYPE_EVENT_DATA_AUTO_SCENE_CAPTURE_UPDATE_PICO:
                case XrStructureType.XR_TYPE_EVENT_DATA_KEYBOARD_PASSTHROUGH_STATE_CHANGED_PICO:
                case XrStructureType.XR_TYPE_EVENT_DATA_PICO_KEYBOARD_PASSTHROUGH_STATE_CHANGED_PICO:
                {
                    PXR_Manager.Instance.PollEvent(eventDB);
                    break;
                }
                case XrStructureType.XR_TYPE_EVENT_DATA_REQUEST_MOTION_TRACKER_COMPLETE:
#if ENABLE_PICO_OPENXR_SDK
#else
                    if (PXR_MotionTracking.RequestMotionTrackerCompleteAction != null)
                    {
                        RequestMotionTrackerCompleteEventData requestMotionTrackerCompleteEventData = new RequestMotionTrackerCompleteEventData();
                        requestMotionTrackerCompleteEventData.trackerCount = BitConverter.ToUInt32(eventDB.data, 0);
                        requestMotionTrackerCompleteEventData.trackerIds = new long[requestMotionTrackerCompleteEventData.trackerCount];
                        for (int i = 0; i < requestMotionTrackerCompleteEventData.trackerCount; i++)
                        {
                            requestMotionTrackerCompleteEventData.trackerIds[i] = BitConverter.ToInt64(eventDB.data, 8+ 8 * i);
                        }

                        requestMotionTrackerCompleteEventData.result =
                            (PxrResult)BitConverter.ToInt32(eventDB.data, 4 + 8 * (int)requestMotionTrackerCompleteEventData.trackerCount);
                        PXR_MotionTracking.RequestMotionTrackerCompleteAction(requestMotionTrackerCompleteEventData);
                    }
#endif
                    break;
                case XrStructureType.XR_TYPE_EVENT_DATA_MOTION_TRACKER_CONNECTION_STATE_CHANGED:
#if ENABLE_PICO_OPENXR_SDK
#else
                    if (PXR_MotionTracking.MotionTrackerConnectionAction != null)
                    {
                        Int64 trackerId = BitConverter.ToInt64(eventDB.data, 0);
                        int state =  BitConverter.ToInt32(eventDB.data, 8);
                        PXR_MotionTracking.MotionTrackerConnectionAction(trackerId, state);
                    }
#endif
                    break;
                case XrStructureType.XR_TYPE_EVENT_DATA_MOTION_TRACKER_POWER_KEY_EVENT:
#if ENABLE_PICO_OPENXR_SDK
#else
                    if (PXR_MotionTracking.MotionTrackerPowerKeyAction != null)
                    {
                        Int64 trackerId = BitConverter.ToInt64(eventDB.data, 0);
                        bool state =  BitConverter.ToBoolean(eventDB.data, 8);
                        PXR_MotionTracking.MotionTrackerPowerKeyAction(trackerId, state);
                    }
#endif
                    break;
                case XrStructureType.XR_TYPE_EVENT_DATA_EXPAND_DEVICE_CONNECTION_STATE_CHANGED:
#if ENABLE_PICO_OPENXR_SDK
#else
                    if (PXR_MotionTracking.ExpandDeviceConnectionAction != null)
                    {
                        UInt64 trackerId = BitConverter.ToUInt64(eventDB.data, 0);
                        int state =  BitConverter.ToInt32(eventDB.data, 8);
                        PXR_MotionTracking.ExpandDeviceConnectionAction((long)trackerId, state);
                    }
#endif
                    break;
                case XrStructureType.XR_TYPE_EVENT_DATA_EXPAND_DEVICE_BATTERY_STATE_CHANGED:
#if ENABLE_PICO_OPENXR_SDK
#else
                    if (PXR_MotionTracking.ExpandDeviceBatteryAction != null)
                    {
                        
                        ExpandDeviceBatteryEventData expandDevice = new ExpandDeviceBatteryEventData();
                        expandDevice.deviceId = BitConverter.ToUInt64(eventDB.data, 0);
                        expandDevice.batteryLevel = BitConverter.ToSingle(eventDB.data, 8);
                        expandDevice.chargingState = (XrBatteryChargingState)BitConverter.ToInt32(eventDB.data, 12);
                      
                        PXR_MotionTracking.ExpandDeviceBatteryAction(expandDevice);
                    }
#endif
                    break;
                case XrStructureType.XR_TYPE_EVENT_DATA_EXPAND_DEVICE_CUSTOM_DATA_STATE_CHANGED:
#if ENABLE_PICO_OPENXR_SDK
#else
                    if (PXR_MotionTracking.ExtDevPassDataAction != null)
                    {
                        status = BitConverter.ToInt32(eventDB.data, 0);
                        PXR_MotionTracking.ExtDevPassDataAction(status);
                    }
#endif
                    break;
            }
        }
#endif
        public PXR_Settings GetSettings()
        {
            PXR_Settings settings = null;
#if UNITY_EDITOR
            UnityEditor.EditorBuildSettings.TryGetConfigObject<PXR_Settings>("ByteDance.PICO.XR.Settings", out settings);
#endif
#if UNITY_ANDROID && !UNITY_EDITOR
            settings = PXR_Settings.settings;
#endif
            return settings;
        }

#if UNITY_EDITOR
        public string GetPreInitLibraryName(BuildTarget buildTarget, BuildTargetGroup buildTargetGroup)
        {
            return "PxrPlatform";
        }
#endif

#if UNITY_ANDROID && !UNITY_EDITOR
        [Preserve]
        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSplashScreen)]
        static void RuntimeLoadPicoPlugin()
        {
            PLog.i(TAG, "RuntimeLoadPicoPlugin");
            string version = "UnityXR_" + PXR_Plugin.System.UPxr_GetSDKVersion() + "_" + Application.unityVersion;
            PXR_Plugin.System.UPxr_SetConfigString( ConfigType.EngineVersion, version );
        }
#endif

        private static bool _isSessionActive = false;
        public static void OnSessionStateChanged(XrSessionState state)
        {
            PLog.i(TAG, $"OnSessionStateChanged Session state changed to: {state}");
#if XR_COMPOSITION_LAYERS
            if (state == XrSessionState.Focused && !_isSessionActive)
            {
                if (CompositionLayerManager.Instance != null)
                {
                    PLog.i(TAG, $"OnSessionBegin OpenXRLayerProvider");
                    CompositionLayerManager.Instance.LayerProvider ??= new PXR_LayerProvider();
                    _isSessionActive = true;
                }
            }
            else if (state == XrSessionState.Stopping && _isSessionActive)
            {
                if (CompositionLayerManager.Instance?.LayerProvider is PXR_LayerProvider)
                {
                    PLog.i(TAG, $"OnSessionEnd OpenXRLayerProvider");
                    ((PXR_LayerProvider)CompositionLayerManager.Instance.LayerProvider).Dispose();
                    CompositionLayerManager.Instance.LayerProvider = null;
                    _isSessionActive = false;
                }
            }
#endif
        }        
    }
}
