using System;
using System.Collections.Generic;
using System.Linq;
using Unity.XR.CoreUtils;
using Unity.XR.CoreUtils.Editor;
using UnityEditor;
using UnityEditor.Callbacks;
using UnityEditor.PackageManager;
using UnityEditor.PackageManager.Requests;
using UnityEditor.PackageManager.UI;
using UnityEditor.SceneManagement;
using UnityEditor.XR.Management;
using UnityEditorInternal;
using UnityEngine;
using UnityEngine.SceneManagement;
using static Unity.XR.CoreUtils.XROrigin;
using UnityEngine.Rendering;
using UnityEditor.Build;
using Unity.XR.CoreUtils.Capabilities.Editor;
using UnityEngine.XR.Management;
using Unity.XR.CoreUtils.Capabilities;

#if UNITY_OPENXR
using UnityEngine.XR.OpenXR;
using UnityEngine.XR.OpenXR.Features;

#if XR_HAND
using UnityEngine.XR.Hands.OpenXR;
#endif

#if ENABLE_PICO_OPENXR_SDK
using ByteDance.PICO.OpenXR;
#endif

#endif

using System.IO;
#if ENABLE_PICO_OPENXR_SDK
using ByteDance.PICO.OpenXR.Editor;
#endif
using Unity.XR.CoreUtils.Capabilities.Editor;
#if URP
using UnityEngine.Rendering.Universal;
#endif

namespace ByteDance.PICO.XR.Editor
{
    [InitializeOnLoad]
    public static class PXR_Utils
    {
        public static string BuildingBlock = "[Building Block]";
        public const string BuildingBlockPathO = "GameObject/PICO Building Blocks/";
        public const string BuildingBlockMSPath0 = "GameObject/PICO Spatial/";
        public const string BuildingBlockPathP = "PICO/PICO Building Blocks/";
        public const string BuildingBlockMSPathP = "PICO/PICO Spatial/";
        public static string sdkPackageName = "Packages/com.bytedance.pico.xr/";

        public static readonly string[] LegacyConfigFilesWhitelist = new string[] {  };

        public static string ProjectName{
            get
            {
                return Path.GetFileName(Path.GetDirectoryName(Application.dataPath));
            }
        }

        public static string SceneName{
            get
            {
                return SceneManager.GetActiveScene().name;
            }
        }

        public static AndroidSdkVersions minSdkVersionInEditor = AndroidSdkVersions.AndroidApiLevel29;
#if UNITY_2021_2_OR_NEWER
        public static NamedBuildTarget recommendedBuildTarget = NamedBuildTarget.Android;
#else
        public static BuildTargetGroup recommendedBuildTarget = BuildTargetGroup.Android;
#endif

        #region xr.interaction.toolkit
        public static string xriPackageName = "com.unity.xr.interaction.toolkit";
        public static string xriVersion = "2.5.4";
        public static PackageVersion xriPackageVersion250 = new PackageVersion("2.5.0");
        public static PackageVersion xriPackageVersion300 = new PackageVersion("3.0.0");
        public static string xriCategory = "XR Interaction Toolkit";
        public static string xriSamplesPath = "Assets/Samples/XR Interaction Toolkit";
        public static string xriStarterAssetsSampleName = "Starter Assets";
        public static string xriHandsInteractionDemoSampleName = "Hands Interaction Demo";
        public static string xri2HandsSetupPefabName = "XR Interaction Hands Setup";
        public static string xri3HandsSetupPefabName = "XR Origin Hands (XR Rig)";
        public const string openxr_plugin = "ENABLE_PICO_OPENXR_SDK";
        public const string spatialadapter_plugin = "PICO_MS_SDK";
        public const string picoxr_plugin = "ENABLE_PICO_XR_SDK";
        public const string PICO_Interaction = "ENABLE_PICO_INTERACTION_PACK";
        public const string pico_live_preview = "PICO_LIVE_PREVIEW";
        public static string assetPath = "Assets/Resources/";
        public const string PICO_ICON_BLACK_NAME = "PICO developer logo black.png";
        public const string PICO_ICON_WHITE_NAME = "PICO developer logo white.png";
        public const string PICO_Full_Spatial_NAME = "Full Space.png";
        public const string PICO_Share_Spatial_NAME = "Share Space.png";
        const string k_SampleDisplayName = "Hands Interaction Demo";
        const string k_StarterAssetsSampleName = "Starter Assets";
        const string k_HandVisualizerSampleName = "HandVisualizer";
        const string k_HandsPackageName = "com.unity.xr.hands";
        const string k_XRIPackageName = "com.unity.xr.interaction.toolkit";
        public static PackageVersion XRICurPackageVersion
        {
            get
            {
                return new PackageVersion(xriVersion);
            }
        }
        public static string XRIDefaultInputActions
        {
            get
            {
                return $"{xriSamplesPath}/{xriVersion}/Starter Assets/XRI Default Input Actions.inputactions";
            }
        }

        public static string XRIDefaultLeftControllerPreset
        {
            get
            {
                if (XRICurPackageVersion >= xriPackageVersion250)
                {
                    return $"{xriSamplesPath}/{xriVersion}/Starter Assets/Presets/XRI Default Left Controller.preset";
                }
                else
                {
                    return $"{xriSamplesPath}/{xriVersion}/Starter Assets/XRI Default Left Controller.preset";
                }
            }
        }

        public static string XRIDefaultRightControllerPreset
        {
            get
            {
                if (XRICurPackageVersion >= xriPackageVersion250)
                {
                    return $"{xriSamplesPath}/{xriVersion}/Starter Assets/Presets/XRI Default Right Controller.preset";
                }
                else
                {
                    return $"{xriSamplesPath}/{xriVersion}/Starter Assets/XRI Default Right Controller.preset";
                }
            }
        }

        public static string XRInteractionHandsSetupPath
        {
            get
            {
                if (XRICurPackageVersion >= xriPackageVersion300)
                {
                    return $"{xriSamplesPath}/{xriVersion}/{xriHandsInteractionDemoSampleName}/Prefabs/{xri3HandsSetupPefabName}.prefab";
                }
                else if (XRICurPackageVersion >= xriPackageVersion250 && XRICurPackageVersion < xriPackageVersion300)
                {
                    return $"{xriSamplesPath}/{xriVersion}/{xriHandsInteractionDemoSampleName}/Prefabs/{xri2HandsSetupPefabName}.prefab";
                }
                else
                {
                    return $"{xriSamplesPath}/{xriVersion}/{xriHandsInteractionDemoSampleName}/Runtime/Prefabs/{xri2HandsSetupPefabName}.prefab";
                }
            }
        }
        public static string XRInteractionPokeButtonPath
        {
            get
            {
                if (XRICurPackageVersion >= xriPackageVersion250)
                {
                    return $"{xriSamplesPath}/{xriVersion}/{xriHandsInteractionDemoSampleName}/HandsDemoSceneAssets/Prefabs/PokeButton.prefab";
                }
                else
                {
                    return $"{xriSamplesPath}/{xriVersion}/{xriHandsInteractionDemoSampleName}/Runtime/Prefabs/PokeButton.prefab";
                }
            }
        }

        public static string XRInteractionXRI300OriginPath
        {
            get
            {
                if (XRICurPackageVersion >= xriPackageVersion250)
                {
                    return $"{xriSamplesPath}/{xriVersion}/{xriStarterAssetsSampleName}/Prefabs/XR Origin (XR Rig).prefab";
                }
                else
                {
                    return $"{xriSamplesPath}/{xriVersion}/{xriStarterAssetsSampleName}/Runtime/Prefabs/XR Origin (XR Rig).prefab";
                }
            }
        }
        #endregion

        #region xr.hands
        public static string xrHandPackageName = "com.unity.xr.hands";
        public static string xrHandVersion = "1.4.1";
        public static PackageVersion xrHandRecommendedPackageVersion = new PackageVersion("1.3.0");
        public static string xrHandSamplesPath = "Assets/Samples/XR Hands";
        public static string xrHandGesturesSampleName = "Gestures";
        public static string xrHandVisualizerSampleName = "HandVisualizer";

        public static string XRHandLeftHandPrefabPath
        {
            get
            {
                return $"{xrHandSamplesPath}/{xrHandVersion}/HandVisualizer/Prefabs/Left Hand Tracking.prefab";
            }
        }
        public static string XRHandRightHandPrefabPath
        {
            get
            {
                return $"{xrHandSamplesPath}/{xrHandVersion}/HandVisualizer/Prefabs/Right Hand Tracking.prefab";
            }
        }

        static AddRequest xrHandsPackageAddRequest;
        public static void InstallOrUpdateHands()
        {
            var currentT = DateTime.Now;
            var endT = currentT + TimeSpan.FromSeconds(3);

            var request = Client.Search(xrHandPackageName);
            if (request.Status == StatusCode.InProgress)
            {
                Debug.Log($"Searching for ({xrHandPackageName}) in Unity Package Registry.");
                while (request.Status == StatusCode.InProgress && currentT < endT)
                {
                    currentT = DateTime.Now;
                }
            }

            var addRequest = xrHandPackageName;
            if (request.Status == StatusCode.Success && request.Result.Length > 0)
            {
                var versions = request.Result[0].versions;
#if UNITY_2022_2_OR_NEWER
                var recommendedVersion = new PackageVersion(versions.recommended);
#else
                var recommendedVersion = new PackageVersion(versions.verified);
#endif
                var latestCompatible = new PackageVersion(versions.latestCompatible);
                if (recommendedVersion < xrHandRecommendedPackageVersion && xrHandRecommendedPackageVersion <= latestCompatible)
                    addRequest = $"{xrHandPackageName}@{xrHandRecommendedPackageVersion}";
            }

            xrHandsPackageAddRequest = Client.Add(addRequest);
            if (xrHandsPackageAddRequest.Error != null)
            {
                Debug.LogError($"Package installation error: {xrHandsPackageAddRequest.Error}: {xrHandsPackageAddRequest.Error.message}");
            }
        }
        #endregion

        #region xr.openxr
        public static string openXRPackageName = "com.unity.xr.openxr";
        public static PackageVersion openXRPackageVersion182 = new PackageVersion("1.8.2");
        public static string openXRVersion = "1.7.1";

        public static PackageVersion openXRCurPackageVersion
        {
            get
            {
                return new PackageVersion(openXRVersion);
            }
        }
        public static string GetPackageVersionSync(string packageName)
        {
            var request = Client.List();
            while (!request.IsCompleted) { }
            return request.Result.FirstOrDefault(p => p.name == packageName)?.version;
        }

        public static void EnableHandTrackingFeature()
        {
#if XR_HAND && ENABLE_PICO_OPENXR_SDK
            EnableOpenXRFeature<HandTracking>();
            EnableOpenXRFeature<UnityEngine.XR.OpenXR.Features.Interactions.HandInteractionProfile>();
#endif
        }

#if ENABLE_PICO_OPENXR_SDK
        public static void EnableOpenXRFeature<T>() where T : OpenXRFeature
        {
            var settings = OpenXRSettings.GetSettingsForBuildTargetGroup(BuildTargetGroup.Android);
            foreach (var feature in settings.GetFeatures<OpenXRFeature>())
            {
                if (feature is T targetFeature && !targetFeature.enabled)
                {
                    targetFeature.enabled = true;
                    EditorUtility.SetDirty(settings);
                    AssetDatabase.SaveAssets();
                    SettingsService.NotifySettingsProviderChanged();
                }
            }
        }

        public static bool IsEnableOpenXRFeature<T>() where T : OpenXRFeature
        {
            var settings = OpenXRSettings.GetSettingsForBuildTargetGroup(BuildTargetGroup.Android);
            foreach (var feature in settings.GetFeatures<OpenXRFeature>())
            {
                if (feature is T targetFeature)
                {
                    return targetFeature.enabled;
                }
            }
            return false;
        }

#endif

        #endregion

        public static List<T> FindComponentsInScene<T>() where T : Component
        {
            var activeScene = SceneManager.GetActiveScene();
            var foundComponents = new List<T>();

            var rootObjects = activeScene.GetRootGameObjects();
            foreach (var rootObject in rootObjects)
            {
                var components = rootObject.GetComponentsInChildren<T>(true);
                foundComponents.AddRange(components);
            }

            return foundComponents;
        }
        public static List<T> FindGameObjectsInScene<T>() where T : Component
        {
            var activeScene = SceneManager.GetActiveScene();
            var foundComponents = new List<T>();

            var rootObjects = activeScene.GetRootGameObjects();
            foreach (var rootObject in rootObjects)
            {
                var components = rootObject.GetComponentsInChildren<T>(true);
                foundComponents.AddRange(components);
            }

            return foundComponents;
        }

        public static void AddNewTag(string newTag)
        {
            SerializedObject tagManager = new SerializedObject(AssetDatabase.LoadAllAssetsAtPath("ProjectSettings/TagManager.asset")[0]);
            SerializedProperty tags = tagManager.FindProperty("tags");

            bool tagExists = false;
            for (int i = 0; i < tags.arraySize; i++)
            {
                if (tags.GetArrayElementAtIndex(i).stringValue == newTag)
                {
                    tagExists = true;
                    break;
                }
            }

            if (!tagExists)
            {
                tags.InsertArrayElementAtIndex(tags.arraySize);
                tags.GetArrayElementAtIndex(tags.arraySize - 1).stringValue = newTag;
                tagManager.ApplyModifiedProperties();
                Debug.Log($"Tag '{newTag}' has been added.");
            }
            else
            {
                Debug.LogWarning($"Tag '{newTag}' already exists.");
            }
        }

        public static bool TryFindSample(string packageName, string packageVersion, string sampleDisplayName, out Sample sample)
        {
            sample = default;

            IEnumerable<Sample> packageSamples;
            try
            {
                packageSamples = Sample.FindByPackage(packageName, packageVersion);
            }
            catch (Exception e)
            {
                Debug.LogError($"Couldn't find samples of the {ToString(packageName, packageVersion)} package. Exception: {e}");
                return false;
            }
            if (packageSamples == null)
            {
                Debug.LogWarning($"Couldn't find samples of the {ToString(packageName, packageVersion)} package.");
                return false;
            }

            foreach (var packageSample in packageSamples)
            {
                if (packageSample.displayName == sampleDisplayName)
                {
                    Debug.Log($" TryFindSample   packageSample.displayName={packageSample.displayName}, sampleDisplayName={sampleDisplayName}");
                    sample = packageSample;
                    return true;
                }
            }

            Debug.LogWarning($"Couldn't find {sampleDisplayName} sample in the { packageName}:{ packageVersion}.");
            return false;
        }
        private static string ToString(string packageName, string packageVersion)
        {
            return string.IsNullOrEmpty(packageVersion) ? packageName : $"{packageName}@{packageVersion}";
        }

        public static void SetTrackingOriginMode(TrackingOriginMode trackingOriginMode = TrackingOriginMode.Device)
        {
            List<XROrigin> components = FindComponentsInScene<XROrigin>().Where(component => component.isActiveAndEnabled).ToList();

            foreach (XROrigin origin in components)
            {
                if (TrackingOriginMode.NotSpecified == origin.RequestedTrackingOriginMode)
                {
                    Debug.Log($"SetTrackingOriginMode {trackingOriginMode}");
                    origin.RequestedTrackingOriginMode = trackingOriginMode;
                    EditorUtility.SetDirty(origin);
                    AssetDatabase.SaveAssets();
                }
            }
        }
#if XRI_TOOLKIT_3
        public static GameObject CheckAndCreateXROriginXRI300()
        {
            GameObject cameraOrigin;
            string k_BuildingBlocksXRI300OriginName = BuildingBlock + " XR Origin (XR Rig) XRI300";

            List<Transform> transforms = FindComponentsInScene<Transform>().Where(component => component.name == k_BuildingBlocksXRI300OriginName).ToList();
            if (transforms.Count == 0)
            {
                GameObject buildingBlockGO = new GameObject();
                Selection.activeGameObject = buildingBlockGO;

                List<XROrigin> components = FindComponentsInScene<XROrigin>().Where(component => component.isActiveAndEnabled).ToList();
                if (components.Count != 0)
                {
                    foreach (var c in components)
                    {
                        c.gameObject.SetActive(false);
                    }
                }

                GameObject ob = PrefabUtility.LoadPrefabContents(XRInteractionXRI300OriginPath);
                Undo.RegisterCreatedObjectUndo(ob, "Create XRInteractionXRI300OriginPath.");
                var activeScene = SceneManager.GetActiveScene();
                var rootObjects = activeScene.GetRootGameObjects();
                Undo.SetTransformParent(ob.transform, buildingBlockGO.transform, true, "Parent to buildingBlockGO.");
                ob.transform.localPosition = Vector3.zero;
                ob.transform.localRotation = Quaternion.identity;
                ob.transform.localScale = Vector3.one;
                ob.SetActive(true);
                cameraOrigin = ob;

                if (!cameraOrigin.GetComponent<PXR_Manager>())
                {
                    cameraOrigin.AddComponent<PXR_Manager>();
                }

                var characterController = cameraOrigin.GetComponent<CharacterController>();
                if (characterController)
                {
                    characterController.enabled = false;
                }

                if (cameraOrigin.transform.Find("Locomotion/Move"))
                {
                    cameraOrigin.transform.Find("Locomotion/Move").gameObject.SetActive(false);
                }

                buildingBlockGO.name = k_BuildingBlocksXRI300OriginName;
                Undo.RegisterCreatedObjectUndo(buildingBlockGO, "Create buildingBlockGO.");

                EditorSceneManager.MarkSceneDirty(buildingBlockGO.scene);
                EditorSceneManager.SaveScene(buildingBlockGO.scene);

                SetTrackingOriginMode();
                PXR_ProjectSetting.SaveAssets();
            }
            else
            {
                cameraOrigin = transforms[0].GetChild(0).gameObject;
            }

            return cameraOrigin;
        }
#endif
        public static GameObject CheckAndCreateXROrigin()
        {
            GameObject cameraOrigin;
            List<XROrigin> components = FindComponentsInScene<XROrigin>().Where(component => component.isActiveAndEnabled).ToList();
            if (components.Count == 0)
            {
                if (!EditorApplication.ExecuteMenuItem("GameObject/XR/XR Origin (VR)"))
                {
                    EditorApplication.ExecuteMenuItem("GameObject/XR/XR Origin (Action-based)");
                }
                cameraOrigin = FindComponentsInScene<XROrigin>().Where(component => component.isActiveAndEnabled).ToList()[0].gameObject;
                cameraOrigin.name = PXR_Utils.BuildingBlock + " XR Origin (XR Rig)";
                Undo.RegisterCreatedObjectUndo(cameraOrigin, "Create XR Origin");
                cameraOrigin.transform.localPosition = Vector3.zero;
                cameraOrigin.transform.localRotation = Quaternion.identity;
                cameraOrigin.transform.localScale = Vector3.one;
                cameraOrigin.SetActive(true);
            }
            else
            {
                cameraOrigin = components[0].gameObject;
            }

            if (!cameraOrigin.GetComponent<PXR_Manager>())
            {
                cameraOrigin.AddComponent<PXR_Manager>();
            }

            return cameraOrigin;
        }

        public static GameObject GetMainCameraGOForXROrigin()
        {
            GameObject cameraGameObject = Camera.main.gameObject;
            List<Camera> components = FindComponentsInScene<Camera>().Where(component => (component.enabled && component.gameObject.CompareTag("MainCamera"))).ToList();
            for (int i = 0; i < components.Count; i++)
            {
                GameObject gameObject = components[i].transform.gameObject;
                if (gameObject.GetComponentsInParent<XROrigin>().Length == 1)
                {
                    gameObject.SetActive(true);
                    cameraGameObject = gameObject;
                }
            }

            return cameraGameObject;
        }

        public static Camera GetMainCameraForXROrigin()
        {
            Camera mainCamera = Camera.main;

            List<Camera> components = FindComponentsInScene<Camera>().Where(component => (component.enabled && component.gameObject.CompareTag("MainCamera"))).ToList();
            for (int i = 0; i < components.Count; i++)
            {
                Camera camera = components[i];
                if (camera.GetComponentsInParent<XROrigin>().Length == 1)
                {
                    camera.gameObject.SetActive(true);
                    mainCamera = camera;
                }
            }

            return mainCamera;
        }

        public static bool HasCompositionLayerInScene()
        {
            var type = Type.GetType("Unity.XR.CompositionLayers.CompositionLayer, Unity.XR.CompositionLayers");
            if (type != null)
            {
#if UNITY_2023_1_OR_NEWER
                return UnityEngine.Object.FindAnyObjectByType(type, FindObjectsInactive.Include) != null;
#else
                return UnityEngine.Object.FindObjectOfType(type, true) != null;
#endif
            }
            return false;
        }

        public static void SetOneMainCameraInScene()
        {
            bool hasOneMainCamera = false;
            List<Camera> components = FindComponentsInScene<Camera>().Where(component => (component.enabled && component.gameObject.activeSelf)).ToList();
            if (components.Count == 0)
            {
                if (!EditorApplication.ExecuteMenuItem("GameObject/XR/XR Origin (VR)"))
                {
                    EditorApplication.ExecuteMenuItem("GameObject/XR/XR Origin (Action-based)");
                }
                return;
            }
            for (int i = 0; i < components.Count; i++)
            {
                GameObject gameObject = components[i].transform.gameObject;
                if (gameObject.GetComponentsInParent<XROrigin>().Length >= 1 && !hasOneMainCamera)
                {
                    if (!gameObject.CompareTag("MainCamera"))
                    {
                        gameObject.tag = "MainCamera";
                    }
                    gameObject.SetActive(true);
                    hasOneMainCamera = true;
                }
                else
                {
                    string newTag = $"Camera{i}";
                    AddNewTag(newTag);
                    gameObject.tag = newTag;
                    gameObject.SetActive(false);
                    components[i].enabled = false;
                }
            }
        }

        public static bool UpdateSamples(string packageName, string sampleDisplayName)
        {
            Debug.LogError($"Need to import {sampleDisplayName} first! Once completed, click this Block again.");
            bool result = EditorUtility.DisplayDialog($"{sampleDisplayName}", $"It's detected that {sampleDisplayName} has not been imported in the current project. You can choose OK to auto-import it, or Cancel and install it manually. ", "OK", "Cancel");
            if (result)
            {
                if (TryFindSample(packageName, string.Empty, sampleDisplayName, out var sample))
                {
                    sample.Import(Sample.ImportOptions.OverridePreviousImports);
                    AssetDatabase.Refresh();
                    return true;
                }
            }
            return false;
        }


        public static string minUnityVersion = "2022.3.15f1";
        public static int CompareUnityVersions(string versionA, string versionB)
        {
            string[] partsA = versionA.Split(new char[] { '.', 'f' }, StringSplitOptions.RemoveEmptyEntries);
            string[] partsB = versionB.Split(new char[] { '.', 'f' }, StringSplitOptions.RemoveEmptyEntries);

            int maxLength = Math.Max(partsA.Length, partsB.Length);

            for (int i = 0; i < maxLength; i++)
            {
                int partA = i < partsA.Length ? int.Parse(partsA[i]) : 0;
                int partB = i < partsB.Length ? int.Parse(partsB[i]) : 0;

                if (partA > partB)
                    return 1;
                if (partA < partB)
                    return -1;
            }

            return 0;
        }

        #region Project
        public static bool updateBasedOnCapabilityProfileSelection = false;
        static PXR_Utils()
        {
            CapabilityProfileSelection.SelectionSaved += OnSelectionSaved;
        }

        private static void OnSelectionSaved()
        {
            updateBasedOnCapabilityProfileSelection = true;
        }

        public static bool IsPXRValidationEnabled()
        {
#if ENABLE_PICO_XR_SDK
            if (updateBasedOnCapabilityProfileSelection)
            {
                return CapabilityProfileSelection.Selected.Any(c => c is PXR_SDKCapability);
            }

            return IsPXRPluginEnabled() && !PXR_ProjectSetting.GetProjectConfig().isSpatialAdapter;
#else
            return false;
#endif
        }


        public static bool IsOpenXRValidationEnabled()
        {
#if ENABLE_PICO_OPENXR_SDK
            if (updateBasedOnCapabilityProfileSelection)
            {
                return CapabilityProfileSelection.Selected.Any(c => c is PXR_OpenXR_SDKCapability);
            }
            return IsOpenXRPluginEnabled();
#else
            return false;
#endif
        }


        public static void ReSetCapabilityProfileSelection()
        {
            CapabilityProfileSelection.Clear();
            CapabilityProfileSelection.Save();
            updateBasedOnCapabilityProfileSelection = false;
        }

        public static bool IsPXRPluginEnabled()
        {
            var generalSettings = XRGeneralSettingsPerBuildTarget.XRGeneralSettingsForBuildTarget(
                BuildTargetGroup.Android);
            if (generalSettings == null)
                return false;

            var managerSettings = generalSettings.AssignedSettings;

            return managerSettings != null && managerSettings.activeLoaders.Any(loader => loader is PXR_Loader);
        }


        public static bool IsOpenXRPluginEnabled()
        {
#if UNITY_OPENXR
            var generalSettings = XRGeneralSettingsPerBuildTarget.XRGeneralSettingsForBuildTarget(
                BuildTargetGroup.Android);
            if (generalSettings == null)
                return false;

            var managerSettings = generalSettings.AssignedSettings;

            return managerSettings != null && managerSettings.activeLoaders.Any(loader => loader is OpenXRLoader);
#else
            return false;
#endif
        }

        #endregion

        public static class ScriptableObjectUtility
        {
            public static void CreateAsset<T>(T classdata, string path) where T : ScriptableObject
            {
                if (!Directory.Exists(path))
                {
                    Directory.CreateDirectory(path);
                }
                string assetPathAndName = AssetDatabase.GenerateUniqueAssetPath(path + typeof(T).ToString() + ".asset");
                AssetDatabase.CreateAsset(classdata, assetPathAndName);
                AssetDatabase.SaveAssets();
                AssetDatabase.Refresh();
            }
        }

        [InitializeOnLoadMethod]
        public static void IsPicoSpatializerAvailable()
        {
            string name = "PICO_SPATIALIZER";
#if UNITY_EDITOR
            string spatializerPath = sdkPackageName + "SpatialAudio/ByteDance.PICO.XR.Spatializer.asmdef";
            var asmDef = AssetDatabase.LoadAssetAtPath<AssemblyDefinitionAsset>(spatializerPath);
            if (asmDef == null)
            {
                RemoveDefineSymbol(name);
            }
            else
            {
                SetDefineSymbols(name);
            }
#endif
        }

        [InitializeOnLoadMethod]
        public static void SetDefaultDefineSymbols()
        {
            var buildTarget = NamedBuildTarget.FromBuildTargetGroup(EditorUserBuildSettings.selectedBuildTargetGroup);
            string currentDefines = PlayerSettings.GetScriptingDefineSymbols(buildTarget);

            var defineSymbols = new HashSet<string>(currentDefines.Split(';', StringSplitOptions.RemoveEmptyEntries));

            if (!defineSymbols.Contains(openxr_plugin) && !defineSymbols.Contains(spatialadapter_plugin) &&
                !defineSymbols.Contains(picoxr_plugin)&&!PXR_ProjectSetting.GetProjectConfig().isSpatialAdapter)
            {
                defineSymbols.Add(picoxr_plugin);
                string newDefines = string.Join(";", defineSymbols);
                PlayerSettings.SetScriptingDefineSymbols(buildTarget, newDefines);
                Debug.Log($"SetDefineSymbols init define symbols: {newDefines}");
            }
            
            if (!defineSymbols.Contains(openxr_plugin) && PXR_ProjectSetting.GetProjectConfig().isSpatialAdapter &&
                IsMSPackageInstalled())
            {
                SetDefineSymbols(spatialadapter_plugin);
            }
        }

        [InitializeOnLoadMethod]
        public static void SyncLivePreviewSymbolOnLoad()
        {
            // Re-align PICO_LIVE_PREVIEW with the current Standalone PICO loader state after each domain reload
            // (e.g. project open, branch switch, manual XR settings change).
            UpdateLivePreviewSymbol();
        }
        public static bool IsMSPackageInstalled()
        {
            string packageId = "com.bytedance.pico.spatialadapter";
            if (!File.Exists("Packages/manifest.json"))
                return false;

            string jsonText = File.ReadAllText("Packages/manifest.json");
            return jsonText.Contains(packageId);
        }
        public static bool SetDefineSymbols(string name)
        {
            var buildTarget = NamedBuildTarget.FromBuildTargetGroup(EditorUserBuildSettings.selectedBuildTargetGroup);
            string currentDefines = PlayerSettings.GetScriptingDefineSymbols(buildTarget);

            var defineSymbols = new HashSet<string>(currentDefines.Split(';', StringSplitOptions.RemoveEmptyEntries));

            if (!defineSymbols.Contains(name))
            {
                defineSymbols.Add(name);
                string newDefines = string.Join(";", defineSymbols);
                PlayerSettings.SetScriptingDefineSymbols(buildTarget, newDefines);
                Debug.Log($"SetDefineSymbols Final define symbols: {newDefines}");
                return true;
            }
            return false;
        }

        public static void RemoveDefineSymbol(string name)
        {
            var buildTarget = NamedBuildTarget.FromBuildTargetGroup(EditorUserBuildSettings.selectedBuildTargetGroup);
            string currentDefines = PlayerSettings.GetScriptingDefineSymbols(buildTarget);

            var defineSymbols = new HashSet<string>(currentDefines.Split(';', StringSplitOptions.RemoveEmptyEntries));

            if (defineSymbols.Remove(name))
            {
                string newDefines = string.Join(";", defineSymbols);
                PlayerSettings.SetScriptingDefineSymbols(buildTarget, newDefines);
            }
        }

        public static bool UpdateSDKSymbols()
        {
            XRGeneralSettings generalSettings = XRGeneralSettingsPerBuildTarget.XRGeneralSettingsForBuildTarget(BuildTargetGroup.Android);
            if (generalSettings == null) return false;
            var assignedSettings = generalSettings.AssignedSettings;
            if (assignedSettings == null) return false;

            string[] defineSymbols = PlayerSettings.GetScriptingDefineSymbols(NamedBuildTarget.Android).Split(';');
            List<string> defineSymbolsList = new List<string>(defineSymbols);
            bool modified = false;
            foreach (XRLoader loader in assignedSettings.activeLoaders)
            {
#if UNITY_OPENXR
                if (loader is OpenXRLoader)
                {
                    modified |= defineSymbolsList.Remove(PXR_Utils.spatialadapter_plugin);
                    modified |= defineSymbolsList.Remove(PXR_Utils.picoxr_plugin);
                    if (!defineSymbolsList.Contains(PXR_Utils.openxr_plugin))
                    {
                        defineSymbolsList.Add(PXR_Utils.openxr_plugin);
                        modified = true;
                    }
                }
#endif
                if (loader is PXR_Loader)
                {
                    modified |= defineSymbolsList.Remove(PXR_Utils.openxr_plugin);
                    string targetSymbol = PXR_ProjectSetting.GetProjectConfig().isSpatialAdapter
                        ? spatialadapter_plugin
                        : picoxr_plugin;

                    string oldSymbol = PXR_ProjectSetting.GetProjectConfig().isSpatialAdapter
                        ? picoxr_plugin
                        : spatialadapter_plugin;
                    modified |= defineSymbolsList.Remove(oldSymbol);
                    if (!IsMSPackageInstalled())
                    {
                        targetSymbol = "";
                    }

                    if (!string.IsNullOrEmpty(targetSymbol) && !defineSymbolsList.Contains(targetSymbol))
                    {
                        defineSymbolsList.Add(targetSymbol);
                        modified = true;
                    }
                }
            }

            if (modified)
            {
                if (defineSymbolsList.Contains(openxr_plugin) || defineSymbolsList.Contains(picoxr_plugin))
                {
                    if (CheckPICOInteractionPackResPackage()&&!defineSymbolsList.Contains(PICO_Interaction))
                    {
                        defineSymbolsList.Add(PICO_Interaction);
                    }
                }
            }
            if (modified)
            {
                PXR_Utils.ReSetCapabilityProfileSelection();
                string finalSymbols = string.Join(";", defineSymbolsList);
                PlayerSettings.SetScriptingDefineSymbols(NamedBuildTarget.Android, finalSymbols);
                return true;
            }
            return false;
        }

        /// <summary>
        /// Keeps the PICO_LIVE_PREVIEW scripting define in sync with the Standalone (Desktop) XR settings.
        /// When the PICO loader is active for Standalone the symbol is added, otherwise it is removed.
        /// The symbol is written to BOTH Android and Standalone targets, because Editor Play mode compiles
        /// scripts with the ACTIVE build target's defines (often Android), while Live Preview itself runs on Desktop.
        /// This lets the native P/Invoke branches guarded by PICO_LIVE_PREVIEW run under Editor/Standalone Live Preview
        /// regardless of which build target is currently active.
        /// Returns true if any target's define symbols were modified.
        /// </summary>
        public static bool UpdateLivePreviewSymbol()
        {
            var generalSettings = XRGeneralSettingsPerBuildTarget.XRGeneralSettingsForBuildTarget(BuildTargetGroup.Standalone);
            bool picoActive = generalSettings != null
                && generalSettings.AssignedSettings != null
                && generalSettings.AssignedSettings.activeLoaders.Any(loader => loader is PXR_Loader);

            bool modified = false;
            modified |= ApplyLivePreviewSymbol(NamedBuildTarget.Standalone, picoActive);
            modified |= ApplyLivePreviewSymbol(NamedBuildTarget.Android, picoActive);
            return modified;
        }

        private static bool ApplyLivePreviewSymbol(NamedBuildTarget target, bool picoActive)
        {
            string currentDefines = PlayerSettings.GetScriptingDefineSymbols(target);
            var defineSymbols = new HashSet<string>(currentDefines.Split(';', StringSplitOptions.RemoveEmptyEntries));

            bool modified = picoActive ? defineSymbols.Add(pico_live_preview) : defineSymbols.Remove(pico_live_preview);

            if (modified)
            {
                string newDefines = string.Join(";", defineSymbols);
                PlayerSettings.SetScriptingDefineSymbols(target, newDefines);
                Debug.Log($"UpdateLivePreviewSymbol [{target}] define symbols: {newDefines}");
            }
            return modified;
        }

#if URP
        public static UniversalRenderPipelineAsset GetCurrentURPAsset()
        {
            UniversalRenderPipelineAsset universalRenderPipelineAsset = null;
            if (QualitySettings.renderPipeline != null)
            {
                universalRenderPipelineAsset = (UniversalRenderPipelineAsset)QualitySettings.renderPipeline;

            }
            else if (GraphicsSettings.currentRenderPipeline != null)
            {
                universalRenderPipelineAsset = (UniversalRenderPipelineAsset)GraphicsSettings.defaultRenderPipeline;
            }
            return universalRenderPipelineAsset;
        }
#endif

        public static readonly string[] spatialAdapterPackagesLocalPath = new[]
        {
            "https://github.com/Pico-Developer/gltf-exporter.git?path=package/com.plattar.unitygltf#master",
            "https://github.com/Pico-Developer/usd-unity-sdk.git?path=package/com.unity.formats.usd#dev",
            "SpatialAdapter"
        };


        public static int currentPackageIndex = 0;
        private static AddRequest currentRequest;
        private static string cachedParentDirectory = null;
        public static string appModelCheckInstallMSDialogTitle = "**SpatialAdapter Package Installation Required**";
        public static string appModelCheckInstallMSDialogMessage = @"To enable SpatialAdapter features, the following packages are required.
Click ""OK"" to install them automatically, or ""Cancel"" to add them manually.
If automatic installation fails, please add the packages manually in the following order:
 
1. Unity glTF Exporter
   https://github.com/Pico-Developer/gltf-exporter.git?path=package/com.plattar.unitygltf#master
2. USD Unity SDK
   https://github.com/Pico-Developer/usd-unity-sdk.git?path=package/com.unity.formats.usd#dev
3. PICO Spatial Adapter Runtime
   SpatialAdapter/package.json";


        public static bool IsLocalPackageInstalled(string packageName)
        {
            string packagePath = Path.Combine("Packages", packageName);
            bool installed = Directory.Exists(packagePath);
            return installed;
        }

        private static bool IsRemotePackageSource(string source)
        {
            if (string.IsNullOrEmpty(source))
                return false;
            return source.StartsWith("http://", StringComparison.OrdinalIgnoreCase)
                || source.StartsWith("https://", StringComparison.OrdinalIgnoreCase)
                || source.StartsWith("git@", StringComparison.OrdinalIgnoreCase)
                || source.StartsWith("ssh://", StringComparison.OrdinalIgnoreCase);
        }

        private static string ResolvePackageSource(string source)
        {
            if (IsRemotePackageSource(source))
                return source;
            return GetPackageUri(source);
        }

        private static string GetRootPackageDirectory()
        {
            if (!string.IsNullOrEmpty(cachedParentDirectory))
                return cachedParentDirectory;

            if (string.IsNullOrEmpty(sdkPackageName))
                return null;

            DirectoryInfo directory = new DirectoryInfo(sdkPackageName);
            for (int i = 0; i < 1 && directory != null; i++)
            {
                directory = directory.Parent;
            }

            cachedParentDirectory = directory?.FullName;
            return cachedParentDirectory;
        }

        private static string GetPackageUri(string relativePath)
        {
            string parentDirectory = GetRootPackageDirectory();
            if (string.IsNullOrEmpty(parentDirectory))
                return null;

            string packagePath = Path.Combine(parentDirectory, relativePath);
            return $"file:{Path.GetFullPath(packagePath)}";
        }

        public static void CheckAndLoadNextPackage()
        {
            if (currentRequest != null)
            {
                if (currentRequest.IsCompleted)
                {
                    if (currentRequest.Status == StatusCode.Success)
                    {
                        Debug.Log("Added package: " + currentRequest.Result.displayName);
                        currentRequest = null;
                        EditorApplication.delayCall += LoadNextPackageDelayed;
                        EditorApplication.update -= CheckAndLoadNextPackage;
                    }
                    else
                    {
                        Debug.LogError("Failed to add package: " + currentRequest.Error.message);
                        EditorApplication.update -= CheckAndLoadNextPackage;
                        currentRequest = null;
                    }
                }
            }
            else if (currentPackageIndex >= 0 && currentPackageIndex < 3)
            {
                EditorApplication.update += CheckAndLoadNextPackage;
                LoadNextPackageDelayed();
            }
        }

        public static void LoadNextPackageDelayed()
        {
            EditorApplication.delayCall -= LoadNextPackageDelayed;

            if (currentPackageIndex < spatialAdapterPackagesLocalPath.Length)
            {
                string packageName = spatialAdapterPackagesName[currentPackageIndex];

                if (!IsLocalPackageInstalled(packageName))
                {
                    string packageSource = spatialAdapterPackagesLocalPath[currentPackageIndex];
                    string packageUri = ResolvePackageSource(packageSource);

                    if (string.IsNullOrEmpty(packageUri))
                    {
                        Debug.LogError("Aborting package import due to unresolved package source: " + packageSource);
                        EditorApplication.update -= CheckAndLoadNextPackage;
                        return;
                    }

                    currentRequest = Client.Add(packageUri);
                    Debug.Log("Adding package: " + packageSource + ",\n from: " + packageUri + ", \n currentPackageIndex:" + currentPackageIndex + ", \n currentRequest:" + currentRequest + ", \n currentRequest.Status:" + currentRequest.Status);
                }
                currentPackageIndex++;
                EditorApplication.update += CheckAndLoadNextPackage;
            }
            else
            {
                Debug.Log("All local packages have been added");
                EditorApplication.update -= CheckAndLoadNextPackage;
            }
        }

        public static AddRequest LoadLocalPackage(string packageName, string packageSource)
        {
            AddRequest request = null;
            if (!IsLocalPackageInstalled(packageName))
            {
                string packageUri = ResolvePackageSource(packageSource);
                if (string.IsNullOrEmpty(packageUri))
                {
                    Debug.LogError("Aborting package import due to unresolved package source: " + packageSource);
                    return request;
                }

                request = Client.Add(packageUri);
                Debug.Log("LoadLocalPackage Adding package: " + packageSource + ",\n from: " + packageUri + ", \n request:" + request + ", \n request.Status:" + request.Status);
            }
            return request;
        }

        public static List<string> spatialAdapterPackagesName = new List<string>
        {
            "com.plattar.unitygltf",
            "com.unity.formats.usd",
            "com.bytedance.pico.spatialadapter",
        };

        public static readonly string[] spatialAdapterPackagesDisplayName = new[]
        {
            "Unity glTF Exporter (com.plattar.unitygltf)",
            "USD Unity SDK (com.unity.formats.usd)",
            "PICO Spatial Adapter Runtime",
        };
        
        static AddRequest currentPackageAddRequest;
        private static bool isInstallationInProgress = false;
        public static void InstallOrUpdatePackage(string packageName, PackageVersion recommendedVersion, Action<bool, string> callback = null)
        {
            if (isInstallationInProgress)
            {
                Debug.LogWarning($"Package installation for '{packageName}' is already in progress. Please wait.");
                callback?.Invoke(false, "Another installation is in progress. Please wait.");
                return;
            }

            Debug.Log($"InstallOrUpdatePackage packageName={packageName}");
            isInstallationInProgress = true;
            var currentT = DateTime.Now;
            var endT = currentT + TimeSpan.FromSeconds(3);

            var searchRequest = Client.Search(packageName);

            while (searchRequest.Status == StatusCode.InProgress && currentT < endT)
            {
                currentT = DateTime.Now;
            }

            string addRequest = packageName;
            if (searchRequest.Status == StatusCode.Success && searchRequest.Result.Length > 0)
            {
                var versions = searchRequest.Result[0].versions;
#if UNITY_2022_2_OR_NEWER
                var actualRecommended = new PackageVersion(versions.recommended);
#else
        var actualRecommended = new PackageVersion(versions.verified);
#endif
                var latestCompatible = new PackageVersion(versions.latestCompatible);
                if (actualRecommended < recommendedVersion && recommendedVersion <= latestCompatible)
                    addRequest = $"{packageName}@{recommendedVersion}";
            }

            currentPackageAddRequest = Client.Add(addRequest);

            EditorApplication.update += CheckInstallationStatus;

            void CheckInstallationStatus()
            {
                if (currentPackageAddRequest == null)
                {
                    EditorApplication.update -= CheckInstallationStatus;
                    callback?.Invoke(false, "Package add request is null");
                    return;
                }

                if (currentPackageAddRequest.Status == StatusCode.InProgress)
                    return;

                EditorApplication.update -= CheckInstallationStatus;

                bool success = currentPackageAddRequest.Status == StatusCode.Success;
                string errorMessage = success ? null :
                    $"[{packageName}] Package installation error: {currentPackageAddRequest.Error?.message}";

                callback?.Invoke(success, errorMessage);
            }
        }

        public static void DisableHDR()
        {
#if URP
            if (QualitySettings.renderPipeline != null)
            {
                UniversalRenderPipelineAsset universalRenderPipelineAsset = (UniversalRenderPipelineAsset)QualitySettings.renderPipeline;
                universalRenderPipelineAsset.supportsHDR = false;

            }
            else if (GraphicsSettings.currentRenderPipeline != null)
            {
                UniversalRenderPipelineAsset universalRenderPipelineAsset = (UniversalRenderPipelineAsset)GraphicsSettings.defaultRenderPipeline;
                universalRenderPipelineAsset.supportsHDR = false;
            }
#endif
        }

        static bool CheckPICOInteractionPackResPackage()
        {
            var bl = PackageVersionUtility.IsPackageInstalled(k_XRIPackageName) &&
                     PackageVersionUtility.IsPackageInstalled(k_HandsPackageName) &&
                     PackageVersionUtility.GetPackageVersion(k_XRIPackageName) >= "3.0.5";
            if (!bl)
            {
                Debug.LogError(
                    $"Package no installation or version is lower than 3.0.5: {k_XRIPackageName}-{k_HandsPackageName}");
            }

            bl = bl && TryFindSample(k_XRIPackageName, string.Empty, k_StarterAssetsSampleName, out var sample1);
            if (!bl)
            {
                Debug.LogError($"Sample no installation : {k_StarterAssetsSampleName}");
            }

            bl = bl && TryFindSample(k_XRIPackageName, string.Empty, k_SampleDisplayName, out var sample2);
            if (!bl)
            {
                Debug.LogError($"Sample no installation : {k_SampleDisplayName}");
            }

            bl = bl && TryFindSample(k_HandsPackageName, string.Empty, k_HandVisualizerSampleName, out var sample3);
            if (!bl)
            {
                Debug.LogError($"Sample no installation : {k_HandVisualizerSampleName}");
            }

            return bl;
        }
    }
}
