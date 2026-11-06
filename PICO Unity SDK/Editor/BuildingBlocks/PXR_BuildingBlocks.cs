#if ENABLE_PICO_XR_SDK || ENABLE_PICO_OPENXR_SDK
using System.Collections.Generic;
using System.Linq;
using Unity.XR.CoreUtils;
using Unity.XR.CoreUtils.Editor.BuildingBlocks;
using UnityEditor;
using UnityEditor.PackageManager.UI;
using UnityEditor.Presets;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.InputSystem;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using UnityEngine.XR.Interaction.Toolkit;
using UnityEngine.XR.Interaction.Toolkit.Inputs;
using UnityEngine.XR.Interaction.Toolkit.UI;
using UnityEngine.Rendering;
using System.IO;

#if ENABLE_PICO_OPENXR_SDK
using UnityEngine.XR.OpenXR;
using UnityEngine.XR.OpenXR.Features;
using ByteDance.PICO.OpenXR;

#if XR_HAND
using UnityEngine.XR.Hands.OpenXR;
#endif
#endif

#if XR_HAND
using UnityEngine.XR.Hands;
#endif

namespace ByteDance.PICO.XR.Editor
{
    
#region PICO Controller
    [BuildingBlockItem(Priority = k_SectionPriority)]
    class PXR_ControllerSection : IBuildingBlockSection
    {
        public const string k_SectionId = "PICO Controller";
        public string SectionId => k_SectionId;

        const string k_SectionIconPath = "Building/Block/Section/Icon/Path";
        public string SectionIconPath => k_SectionIconPath;
        const int k_SectionPriority = 1;

        readonly IBuildingBlock[] m_BBlocksElementIds = new IBuildingBlock[]
        {
            new PXR_BuildingBlocksControllerTracking(),
            new PXR_BuildingBlocksControllerTrackingCanvas(),
        };

        public IEnumerable<IBuildingBlock> GetBuildingBlocks()
        {
            var elements = m_BBlocksElementIds.ToList();
            return elements;
        }
    }

    class PXR_BuildingBlocksControllerTracking : IBuildingBlock
    {
        const string k_Id = "PICO Controller Tracking";
        const string k_BuildingBlockPath = PXR_Utils.BuildingBlockPathO + PXR_ControllerSection.k_SectionId + "/" + k_Id;
        const string k_IconPath = "buildingblockIcon";
        const string k_Tooltip = k_Id + " : Configure the controller model provided by PICO SDK in the scene and configure the controller interaction events. ";
        const int k_SectionPriority = 1;

        public string Id => k_Id;
        public string IconPath => k_IconPath;
        public bool IsEnabled => true;
        public string Tooltip => k_Tooltip;

        static string controllerLeftPath = PXR_Utils.sdkPackageName + "Resources/Prefabs/LeftControllerModel.prefab";
        static string controllerRightPath = PXR_Utils.sdkPackageName + "Resources/Prefabs/RightControllerModel.prefab";
        static string xrOriginName = $"{PXR_Utils.BuildingBlock} {k_Id} XR Origin (XR Rig)";
        static string controllerLeftName = "Left Controller";
        static string controllerRightName = "Right Controller";
        static string controllerModelLeftName = $"{PXR_Utils.BuildingBlock} Left Controller";
        static string controllerModelRightName = $"{PXR_Utils.BuildingBlock} Right Controller";

        static void DoInterestingStuff()
        {
            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strBuildingBlocks, PXR_AppLog.strBuildingBlocks_PICOControllerTracking);
            // Get XRI Interaction
            var xriPackage = UnityEditor.PackageManager.PackageInfo.FindForAssembly(typeof(XRInteractionManager).Assembly);
            if (xriPackage == null)
            {
                Debug.LogError($"Failed, please install {PXR_Utils.xriPackageName} first!");
                return;
            }
            PXR_Utils.xriVersion = xriPackage.version;
            Debug.Log($"XRI Toolkit version = {xriPackage.version}");

            var inputActionAsset = AssetDatabase.LoadAssetAtPath<InputActionAsset>(PXR_Utils.XRIDefaultInputActions);
#if XRI_TOOLKIT_3
            if (inputActionAsset == null)
            {
                bool result = PXR_Utils.UpdateSamples(PXR_Utils.xriPackageName, PXR_Utils.xriStarterAssetsSampleName);
                if (result)
                {
                    DoInterestingStuff();
                }
            }
            else
            {
                // Get XROrigin
                GameObject cameraOrigin = PXR_Utils.CheckAndCreateXROriginXRI300();
                Transform cameraOffset = cameraOrigin.transform.Find("Camera Offset");
                if (cameraOffset != null)
                {
                    Transform leftController = cameraOffset.transform.Find("Left Controller");
                    Transform rightController = cameraOffset.transform.Find("Right Controller");

                    if (leftController != null)
                    {
                        GameObject oldLeftC = leftController.Find("Left Controller Visual")?.gameObject;
                        oldLeftC.SetActive(false);

                        GameObject ob = leftController.Find(controllerModelLeftName)?.gameObject;
                        if (!ob)
                        {
                            ob = PrefabUtility.LoadPrefabContents(controllerLeftPath);
                            Undo.RegisterCreatedObjectUndo(ob, "Create controllerLeftPath.");
                            Undo.SetTransformParent(ob.transform, leftController, true, "Parent to leftController.");
                            ob.transform.localPosition = Vector3.zero;
                            ob.transform.localRotation = Quaternion.identity;
                            ob.transform.localScale = Vector3.one;
                            ob.name = controllerModelLeftName;
                        }
                        ob.SetActive(true);
                    }

                    if (rightController != null)
                    {
                        GameObject oldRightC = rightController.Find("Right Controller Visual")?.gameObject;
                        oldRightC.SetActive(false);

                        GameObject ob = rightController.Find(controllerModelRightName)?.gameObject;
                        if (!ob)
                        {
                            ob = PrefabUtility.LoadPrefabContents(controllerRightPath);
                            Undo.RegisterCreatedObjectUndo(ob, "Create controllerRightPath.");
                            Undo.SetTransformParent(ob.transform, rightController, true, "Parent to rightController.");
                            ob.transform.localPosition = Vector3.zero;
                            ob.transform.localRotation = Quaternion.identity;
                            ob.transform.localScale = Vector3.one;
                            ob.name = controllerModelRightName;
                        }
                        ob.SetActive(true);
                    }
                }

                EditorSceneManager.SaveScene(cameraOrigin.gameObject.scene);
            }
#else
            var presetLC = AssetDatabase.LoadAssetAtPath<Preset>(PXR_Utils.XRIDefaultLeftControllerPreset);
            var presetRC = AssetDatabase.LoadAssetAtPath<Preset>(PXR_Utils.XRIDefaultRightControllerPreset);
            if (presetLC == null || presetRC == null || inputActionAsset == null)
            {
                bool result = PXR_Utils.UpdateSamples(PXR_Utils.xriPackageName, PXR_Utils.xriStarterAssetsSampleName);
                if (result)
                {
                    DoInterestingStuff();
                }
            }
            else
            {
                // Get XROrigin
                GameObject cameraOrigin = PXR_Utils.CheckAndCreateXROrigin();

                Transform leftControllerTransform = cameraOrigin.transform.Find("Camera Offset").Find("Left Controller");
                Transform rightControllerTransform = cameraOrigin.transform.Find("Camera Offset").Find("Right Controller");

                if (leftControllerTransform == null || rightControllerTransform == null)
                {
                    List<ActionBasedController> controllersComponents = PXR_Utils.FindComponentsInScene<ActionBasedController>().Where(component => component.isActiveAndEnabled).ToList();
                    if (controllersComponents.Count > 1)
                    {
                        leftControllerTransform = controllersComponents[0].transform;
                        rightControllerTransform = controllersComponents[1].transform;
                    }
                    else
                    {
                        cameraOrigin.SetActive(false);
                        if (!EditorApplication.ExecuteMenuItem("GameObject/XR/XR Origin (VR)"))
                        {
                            EditorApplication.ExecuteMenuItem("GameObject/XR/XR Origin (Action-based)");
                        }
                        cameraOrigin = PXR_Utils.FindComponentsInScene<XROrigin>().Where(component => component.isActiveAndEnabled).ToList()[0].gameObject;
                        leftControllerTransform = cameraOrigin.transform.Find("Camera Offset").Find(controllerLeftName);
                        rightControllerTransform = cameraOrigin.transform.Find("Camera Offset").Find(controllerRightName);
                    }
                }

                if (leftControllerTransform != null)
                {
                    ActionBasedController leftController = leftControllerTransform.GetComponent<ActionBasedController>();

                    if (presetLC != null)
                    {
                        presetLC.ApplyTo(leftController);
                        Debug.Log("XRI Default Left Controller preset applied successfully.");
                    }
                    else
                    {
                        Debug.LogError("Failed to load XRI Default Left Controller preset.");
                    }

                    leftController.enableInputActions = true;
                    leftController.modelPrefab = AssetDatabase.LoadAssetAtPath<Transform>(controllerLeftPath);
                }

                if (rightControllerTransform != null)
                {
                    ActionBasedController rightController = rightControllerTransform.GetComponent<ActionBasedController>();

                    if (presetRC != null)
                    {
                        presetRC.ApplyTo(rightController);
                        Debug.Log("XRI Default Right Controller preset applied successfully.");
                    }
                    else
                    {
                        Debug.LogError("Failed to load XRI Default Right Controller preset.");
                    }

                    rightController.enableInputActions = true;
                    rightController.modelPrefab = AssetDatabase.LoadAssetAtPath<Transform>(controllerRightPath);
                }

                List<InputActionAsset> inputActions = new List<InputActionAsset>();
                inputActions.Add(inputActionAsset);

                List<InputActionManager> iamComponents = PXR_Utils.FindComponentsInScene<InputActionManager>().Where(component => component.isActiveAndEnabled).ToList();
                if (iamComponents.Count == 0)
                {
                    InputActionManager inputActionManager = cameraOrigin.transform.GetComponent<InputActionManager>();
                    if (!inputActionManager)
                    {
                        inputActionManager = cameraOrigin.AddComponent<InputActionManager>();
                    }

                    inputActionManager.enabled = true;
                    iamComponents.Add(inputActionManager);
                }
                foreach (var component in iamComponents)
                {
                    component.actionAssets = inputActions;
                }

                cameraOrigin.name = xrOriginName;
                leftControllerTransform.name = controllerLeftName;
                rightControllerTransform.name = controllerRightName;

                EditorSceneManager.SaveScene(cameraOrigin.gameObject.scene);
            }
#endif
            AssetDatabase.SaveAssets();
        }

        public void ExecuteBuildingBlock() => DoInterestingStuff();

        // Each building block should have an accompanying MenuItem as a good practice, we add them here.
        [MenuItem(k_BuildingBlockPath, false, k_SectionPriority)]
        public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff();

        [MenuItem(PXR_Utils.BuildingBlockPathP + PXR_ControllerSection.k_SectionId + "/" + k_Id, false, k_SectionPriority)]
        public static void ExecuteMenuItemHierarchy(MenuCommand command) => DoInterestingStuff();
    }

    class PXR_BuildingBlocksControllerTrackingCanvas : IBuildingBlock
    {
        const string k_Id = "Controller Canvas Interaction";
        const string k_BuildingBlockPath = PXR_Utils.BuildingBlockPathO + PXR_ControllerSection.k_SectionId + "/" + k_Id;
        const string k_IconPath = "buildingblockIcon";
        const string k_Tooltip = k_Id + " : Add Controller Ray Interaction to Canvas.";
        const int k_SectionPriority = 2;

        public string Id => k_Id;
        public string IconPath => k_IconPath;
        public bool IsEnabled => true;
        public string Tooltip => k_Tooltip;

        static string xrOriginName = $"{PXR_Utils.BuildingBlock} {k_Id} XR Origin (XR Rig)";
        static string canvasName = $"{PXR_Utils.BuildingBlock} {k_Id} Canvas";


        static void DoInterestingStuff()
        {
            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strBuildingBlocks, PXR_AppLog.strBuildingBlocks_ControllerCanvasInteraction);
            // Get XROrigin
            PXR_BuildingBlocksControllerTracking.ExecuteMenuItem(new MenuCommand(null));
            GameObject cameraOrigin = PXR_Utils.CheckAndCreateXROrigin();
            Undo.RegisterCreatedObjectUndo(cameraOrigin, "Create XROrigin");
            PXR_Utils.SetTrackingOriginMode();
            
            Canvas canvas;
            List<Canvas> canvasComponents = PXR_Utils.FindComponentsInScene<Canvas>().ToList();
            if (canvasComponents.Count == 0)
            {
                #if UNITY_6000_3_OR_NEWER
                if (!EditorApplication.ExecuteMenuItem("GameObject/UI (Canvas)/Canvas"))
                {
                    EditorApplication.ExecuteMenuItem("GameObject/UI (Canvas)/Canvas");
                }
                #else
                 if (!EditorApplication.ExecuteMenuItem("GameObject/UI/Canvas"))
                {
                    EditorApplication.ExecuteMenuItem("GameObject/UI/Canvas");
                }
                #endif

                var canvases = PXR_Utils.FindComponentsInScene<Canvas>();
                if (canvases.Count == 0)
                {
                    Debug.LogError("Canvas was not created successfully.");
                    return;
                }

                canvas = canvases[0];
                Undo.RegisterCreatedObjectUndo(canvas.gameObject, "Create Canvas");
            }
            else
            {
                canvas = canvasComponents[0];
            }

           string planeName = $"{PXR_Utils.BuildingBlock} Plane";
            GameObject plane = PXR_Utils.FindComponentsInScene<Transform>()
                .FirstOrDefault(component => component.name == planeName)?.gameObject;

            if (plane == null)
            {
                plane = GameObject.CreatePrimitive(PrimitiveType.Plane);
                Undo.RegisterCreatedObjectUndo(plane, "Create Plane");
                plane.name = planeName;
                plane.transform.position = Vector3.zero;
                plane.transform.rotation = Quaternion.identity;
                plane.transform.localScale = Vector3.one;
            }

            if (canvas)
            {
                TrackedDeviceGraphicRaycaster trackedDeviceGraphicRaycaster = canvas.transform.GetComponent<TrackedDeviceGraphicRaycaster>();
                if (trackedDeviceGraphicRaycaster == null)
                {
                    trackedDeviceGraphicRaycaster = Undo.AddComponent<TrackedDeviceGraphicRaycaster>(canvas.gameObject);
                }
                else
                {
                    Undo.RecordObject(trackedDeviceGraphicRaycaster, "Enable TrackedDeviceGraphicRaycaster");
                    trackedDeviceGraphicRaycaster.enabled = true;
                }

                Camera mainCam = PXR_Utils.GetMainCameraForXROrigin();
                Undo.RecordObject(canvas, "Set Canvas World Camera");
                canvas.worldCamera = mainCam;

                if (canvas.renderMode != RenderMode.WorldSpace)
                {
                    Vector2 canvasDimensionsScaled;
                    Vector2 canvasDimensionsInMeters = new Vector2(1.0f, 1.0f);
                    const float canvasWorldSpaceScale = 0.001f;
                    canvasDimensionsScaled = canvasDimensionsInMeters / canvasWorldSpaceScale;

                    RectTransform rectTransform = canvas.GetComponent<RectTransform>();
                    Undo.RecordObject(rectTransform, "Change Canvas Size Delta");
                    rectTransform.sizeDelta = canvasDimensionsScaled;

                    canvas.renderMode = RenderMode.WorldSpace;
                    canvas.transform.localScale = Vector3.one * canvasWorldSpaceScale;
                    canvas.transform.position = mainCam.transform.position + new Vector3(0, 0, 1);
                    Undo.RecordObject(canvas.transform, "Change Canvas Rotation");
                    canvas.transform.rotation = mainCam.transform.rotation;
                }

                Undo.RecordObject(canvas, "Change Canvas Name");
                canvas.name = canvasName;
            }

            GameObject eventSystemGO;
            List<EventSystem> esComponents = PXR_Utils.FindComponentsInScene<EventSystem>().ToList();

            if (esComponents.Count > 0)
            {
                foreach (var es in esComponents)
                {
                    Undo.DestroyObjectImmediate(es.gameObject);
                }
            }

            eventSystemGO = new GameObject("EventSystem");
            Undo.RegisterCreatedObjectUndo(eventSystemGO, "Create EventSystem");
            eventSystemGO.AddComponent<EventSystem>();
            XRUIInputModule xRUIInputModule = eventSystemGO.AddComponent<XRUIInputModule>();
            xRUIInputModule.clickSpeed = 0.3f;
            xRUIInputModule.moveDeadzone = 0.6f;
            xRUIInputModule.repeatDelay = 0.5f;
            xRUIInputModule.repeatRate = 0.1f;
            xRUIInputModule.trackedDeviceDragThresholdMultiplier = 2.0f;
            xRUIInputModule.trackedScrollDeltaMultiplier = 5.0f;
            xRUIInputModule.activeInputMode = XRUIInputModule.ActiveInputMode.InputSystemActions;
            string[] guids = AssetDatabase.FindAssets("XRI Default Input Actions t:InputActionAsset");
            if (guids.Length > 0)
            {
                string path = AssetDatabase.GUIDToAssetPath(guids[0]);
                UnityEngine.Object[] assets = AssetDatabase.LoadAllAssetsAtPath(path);

                InputActionReference GetAction(string map, string action)
                {
                    foreach (var asset in assets)
                    {
                        if (asset is InputActionReference reference &&
                            reference.action != null &&
                            reference.action.name == action &&
                            reference.action.actionMap != null &&
                            reference.action.actionMap.name == map)
                            return reference;
                    }

                    return null;
                }

                xRUIInputModule.pointAction = GetAction("XRI UI", "Point");
                xRUIInputModule.leftClickAction = GetAction("XRI UI", "Click");
                xRUIInputModule.middleClickAction = GetAction("XRI UI", "MiddleClick");
                xRUIInputModule.rightClickAction = GetAction("XRI UI", "RightClick");
                xRUIInputModule.scrollWheelAction = GetAction("XRI UI", "ScrollWheel");
                xRUIInputModule.navigateAction = GetAction("XRI UI", "Navigate");
                xRUIInputModule.submitAction = GetAction("XRI UI", "Submit");
                xRUIInputModule.cancelAction = GetAction("XRI UI", "Cancel");
            }

            Undo.RecordObject(cameraOrigin, "Change XROrigin Name");
            cameraOrigin.name = xrOriginName;

            EditorSceneManager.MarkSceneDirty(cameraOrigin.scene);
            EditorSceneManager.SaveScene(cameraOrigin.scene);
        }
        public void ExecuteBuildingBlock() => DoInterestingStuff();

        public static void ExecuteBuildingBlockStatic()
        {
            DoInterestingStuff();
        }

        // Each building block should have an accompanying MenuItem as a good practice, we add them here.
        [MenuItem(k_BuildingBlockPath, false, k_SectionPriority)]
        public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff();

        [MenuItem(PXR_Utils.BuildingBlockPathP + PXR_ControllerSection.k_SectionId + "/" + k_Id, false, k_SectionPriority)]
        public static void ExecuteMenuItemHierarchy(MenuCommand command) => DoInterestingStuff();
    }

#endregion

#region PICO Hand
    [BuildingBlockItem(Priority = k_SectionPriority)]
    class PXR_HandSection : IBuildingBlockSection
    {
        public const string k_SectionId = "PICO Hand";
        public string SectionId => k_SectionId;

        const string k_SectionIconPath = "Building/Block/Section/Icon/Path";
        public string SectionIconPath => k_SectionIconPath;
        const int k_SectionPriority = 2;

        readonly IBuildingBlock[] m_BBlocksElementIds = new IBuildingBlock[]
        {
#if !ENABLE_PICO_OPENXR_SDK
            new PXR_BuildingBlocksPICOHandTracking(),
            new PXR_BuildingBlocksXRIHandInteraction(),
#else
            new PXR_BuildingBlocksOpenXRXRIHandInteraction(),
#endif
            new PXR_BuildingBlocksXRHandTracking(),
            new PXR_BuildingBlocksXRIGrabInteraction(),
            new PXR_BuildingBlocksXRIPokeInteraction(),
        };

        public IEnumerable<IBuildingBlock> GetBuildingBlocks()
        {
            var elements = m_BBlocksElementIds.ToList();
            return elements;
        }
    }
#if ENABLE_PICO_XR_SDK
    class PXR_BuildingBlocksPICOHandTracking : IBuildingBlock
    {
        const string k_Id = "PICO Hand Tracking";
        const string k_BuildingBlockPath = PXR_Utils.BuildingBlockPathO + PXR_HandSection.k_SectionId + "/" + k_Id;
        const string k_IconPath = "buildingblockIcon";
        const string k_Tooltip = k_Id + " : Add the gesture model from PICO to the scene.";
        const int k_SectionPriority = 3;

        public string Id => k_Id;
        public string IconPath => k_IconPath;
        public bool IsEnabled => true;
        public string Tooltip => k_Tooltip;
        static string handLeftPath = PXR_Utils.sdkPackageName + "Resources/Prefabs/HandLeft.prefab";
        static string handRightPath = PXR_Utils.sdkPackageName + "Resources/Prefabs/HandRight.prefab";
        static string xrOriginName = $"{PXR_Utils.BuildingBlock} {k_Id} XR Origin (XR Rig)";
        static string handLeftName = $"{PXR_Utils.BuildingBlock} {k_Id} Left";
        static string handRightName = $"{PXR_Utils.BuildingBlock} {k_Id} Right";

        static void DoInterestingStuff()
        {
            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strBuildingBlocks, PXR_AppLog.strBuildingBlocks_PICOHandTracking);
            // Get XROrigin
            GameObject cameraOrigin = PXR_Utils.CheckAndCreateXROrigin();
            PXR_ProjectSetting.GetProjectConfig().handTracking = true;
            PXR_ProjectSetting.SaveAssets();

            // Add Left Hand
            List<PXR_Hand> leftList = PXR_Utils.FindComponentsInScene<PXR_Hand>().Where(component => component.transform.name == handLeftName).ToList();
            if (leftList.Count == 0)
            {
                GameObject leftHand = PrefabUtility.LoadPrefabContents(handLeftPath);
                if (leftHand != null)
                {
                    if (cameraOrigin != null)
                    {
                        Undo.SetTransformParent(leftHand.transform, cameraOrigin.transform.Find("Camera Offset"), true, "Parent to camera rig.");
                        leftHand.transform.localPosition = Vector3.zero;
                        leftHand.transform.localRotation = Quaternion.identity;
                        leftHand.transform.localScale = Vector3.one;
                        leftHand.SetActive(true);
                        leftHand.name = handLeftName;
                    }
                }
            }

            // Add Right Hand
            List<PXR_Hand> rightList = PXR_Utils.FindComponentsInScene<PXR_Hand>().Where(component => component.transform.name == handRightName).ToList();
            if (rightList.Count == 0)
            {
                GameObject rightHand = PrefabUtility.LoadPrefabContents(handRightPath);
                if (rightHand != null)
                {
                    if (cameraOrigin != null)
                    {
                        Undo.SetTransformParent(rightHand.transform, cameraOrigin.transform.Find("Camera Offset"), true, "Parent to camera rig.");
                        rightHand.transform.localPosition = Vector3.zero;
                        rightHand.transform.localRotation = Quaternion.identity;
                        rightHand.transform.localScale = Vector3.one;
                        rightHand.SetActive(true);
                        rightHand.name = handRightName;
                    }
                }
            }

            cameraOrigin.name = xrOriginName;

            EditorSceneManager.MarkSceneDirty(cameraOrigin.scene);
            EditorSceneManager.SaveScene(cameraOrigin.scene);
        }

        public void ExecuteBuildingBlock() => DoInterestingStuff();

        // Each building block should have an accompanying MenuItem as a good practice, we add them here.
        [MenuItem(k_BuildingBlockPath, false, k_SectionPriority)]
        public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff();

        [MenuItem(PXR_Utils.BuildingBlockPathP + PXR_HandSection.k_SectionId + "/" + k_Id, false, k_SectionPriority)]
        public static void ExecuteMenuItemHierarchy(MenuCommand command) => DoInterestingStuff();
    }
#endif

    class PXR_BuildingBlocksXRHandTracking : IBuildingBlock
    {
        const string k_Id = "XR Hand Tracking";
        const string k_BuildingBlockPath = PXR_Utils.BuildingBlockPathO + PXR_HandSection.k_SectionId + "/" + k_Id;
        const string k_IconPath = "buildingblockIcon";
        const string k_Tooltip = k_Id + " : Add the gesture model from XRHands to the scene.";
        const int k_SectionPriority = 4;

        public string Id => k_Id;
        public string IconPath => k_IconPath;
        public bool IsEnabled => true;
        public string Tooltip => k_Tooltip;
        static string xrOriginName = $"{PXR_Utils.BuildingBlock} {k_Id} XR Origin (XR Rig)";
        static string handLeftName = $"{PXR_Utils.BuildingBlock} {k_Id} Left";
        static string handRightName = $"{PXR_Utils.BuildingBlock} {k_Id} Right";

        private static bool isExecuting = false;
        private static bool isImportSampleStart = false;
        private static string ImportPendingKey = PXR_Utils.ProjectName+PXR_Utils.SceneName+"PXR_BuildingBlocksXRHandTracking";

        static void DoInterestingStuff()
        {
            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strBuildingBlocks, PXR_AppLog.strBuildingBlocks_XRHandTracking);
#if !XR_HAND
            if (isExecuting)
            {
                Debug.Log("DoInterestingStuff is already executing. Skipping operation.");
                return;
            }
            Debug.LogError($"Need to install {PXR_Utils.xrHandPackageName} first!");
            bool result = EditorUtility.DisplayDialog($"{PXR_Utils.xrHandPackageName}", $"It's detected that xrhand isn't installed in the current project. You can choose OK to auto-install XRHand, or Cancel and install it manually. ", "OK", "Cancel");
            if (result)
            {
                isExecuting = true;
                PXR_Utils.InstallOrUpdateHands();
            }
#else
            var xrHandPackage = UnityEditor.PackageManager.PackageInfo.FindForAssembly(typeof(UnityEngine.XR.Hands.XRHand).Assembly);
            if (xrHandPackage != null)
            {
                PXR_Utils.xrHandVersion = xrHandPackage.version;
                Debug.Log($"XRHand version = {PXR_Utils.xrHandVersion}");
                // if no samples, add.
                if (PXR_Utils.TryFindSample(PXR_Utils.xrHandPackageName, PXR_Utils.xrHandVersion, PXR_Utils.xrHandVisualizerSampleName, out var visualizerSample))
                {
                    // visualizerSample.Import(Sample.ImportOptions.OverridePreviousImports);
                    if (!Directory.Exists(visualizerSample.importPath)){
                        EditorPrefs.SetBool(ImportPendingKey, true);
                        visualizerSample.Import(Sample.ImportOptions.OverridePreviousImports);
                    }else{
                        GenerateXRHands();
                    }
                }
            }
            
#endif
        }
#if XR_HAND
        [InitializeOnLoadMethod]
        private static void OnDomainReloadXRHandHandler()
        {
            if(EditorPrefs.GetBool(ImportPendingKey, false)){
                Debug.Log("Detected post-import reload, continuing logic..." + EditorPrefs.GetBool(ImportPendingKey, false));
                EditorApplication.delayCall += ()=>{
                    GenerateXRHands();
                };
            }
        }
        private static void GenerateXRHands(){
            // Get XROrigin
            bool isURP = GraphicsSettings.currentRenderPipeline != null && GraphicsSettings.currentRenderPipeline.GetType().Name.Contains("Universal");
            var xrHandPackage = UnityEditor.PackageManager.PackageInfo.FindForAssembly(typeof(UnityEngine.XR.Hands.XRHand).Assembly);
            if (xrHandPackage != null) PXR_Utils.xrHandVersion = xrHandPackage.version;
            GameObject cameraOrigin = PXR_Utils.CheckAndCreateXROrigin();
            PXR_ProjectSetting.GetProjectConfig().handTracking = true;
            PXR_ProjectSetting.SaveAssets();

            // Add Left Hand
            List<XRHandSkeletonDriver> leftList = PXR_Utils.FindComponentsInScene<XRHandSkeletonDriver>().Where(component => component.transform.name == handLeftName).ToList();
            if (leftList.Count == 0)
            {
                GameObject leftHand = PrefabUtility.LoadPrefabContents(PXR_Utils.XRHandLeftHandPrefabPath);
                if (leftHand != null)
                {
                    if (cameraOrigin != null)
                    {
                        Undo.RegisterCreatedObjectUndo(leftHand, "Create left hand.");
                        Undo.SetTransformParent(leftHand.transform, cameraOrigin.transform.Find("Camera Offset"), true, "Parent to camera rig.");
                        leftHand.transform.localPosition = Vector3.zero;
                        leftHand.transform.localRotation = Quaternion.identity;
                        leftHand.transform.localScale = Vector3.one;
                        var leftHandSkin = leftHand.transform.GetComponentInChildren<SkinnedMeshRenderer>(true);
                        if(leftHandSkin != null && leftHandSkin.sharedMaterial != null){
                            var material = new Material(leftHandSkin.sharedMaterial);
                            material.shader = isURP?Shader.Find("Universal Render Pipeline/Lit"):Shader.Find("Standard");
                            leftHandSkin.material = material;
                        }
                        leftHand.SetActive(true);
                        leftHand.name = handLeftName;
                    }
                }
            }

            // Add Right Hand
            List<XRHandSkeletonDriver> rightList = PXR_Utils.FindComponentsInScene<XRHandSkeletonDriver>().Where(component => component.transform.name == handRightName).ToList();
            if (rightList.Count == 0)
            {
                GameObject rightHand = PrefabUtility.LoadPrefabContents(PXR_Utils.XRHandRightHandPrefabPath);
                if (rightHand != null)
                {
                    if (cameraOrigin != null)
                    {
                        Undo.RegisterCreatedObjectUndo(rightHand, "Create right hand.");
                        Undo.SetTransformParent(rightHand.transform, cameraOrigin.transform.Find("Camera Offset"), true, "Parent to camera rig.");
                        rightHand.transform.localPosition = Vector3.zero;
                        rightHand.transform.localRotation = Quaternion.identity;
                        rightHand.transform.localScale = Vector3.one;
                         var rightHandSkin = rightHand.transform.GetComponentInChildren<SkinnedMeshRenderer>(true);
                        if(rightHandSkin != null && rightHandSkin.sharedMaterial != null){
                            var material = new Material(rightHandSkin.sharedMaterial);
                            material.shader = isURP?Shader.Find("Universal Render Pipeline/Lit"):Shader.Find("Standard");
                            rightHandSkin.material = material;
                        }
                        rightHand.SetActive(true);
                        rightHand.name = handRightName;
                    }
                }
            }

            cameraOrigin.name = xrOriginName;

            EditorSceneManager.MarkSceneDirty(cameraOrigin.scene);
            EditorSceneManager.SaveScene(cameraOrigin.scene);
            isExecuting = false;
        }
#endif
        public void ExecuteBuildingBlock() => DoInterestingStuff();

        // Each building block should have an accompanying MenuItem as a good practice, we add them here.
        [MenuItem(k_BuildingBlockPath, false, k_SectionPriority)]
        public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff();

        [MenuItem(PXR_Utils.BuildingBlockPathP + PXR_HandSection.k_SectionId + "/" + k_Id, false, k_SectionPriority)]
        public static void ExecuteMenuItemHierarchy(MenuCommand command) => DoInterestingStuff();
    }


#if PICO_MS_SDK || ENABLE_PICO_XR_SDK
    class PXR_BuildingBlocksXRIHandInteraction : IBuildingBlock
    {
        const string k_Id = "XRI Hand Interaction";
        const string k_BuildingBlockPath = PXR_Utils.BuildingBlockPathO + PXR_HandSection.k_SectionId + "/" + k_Id;
        const string k_IconPath = "buildingblockIcon";
        const string k_Tooltip = k_Id + " : This button allows one-click configuration of the gesture interaction method in XRInteraction Toolkit to enable interaction between the hand and 3D objects.";
        static string k_BuildingBlocksXROriginName = $"{PXR_Utils.BuildingBlock} XRI Hand Interaction";
        static string k_BuildingBlocksGrabName = $"{PXR_Utils.BuildingBlock} XRI Hand Grab Interactable";
        const int k_SectionPriority = 5;

        public string Id => k_Id;
        public string IconPath => k_IconPath;
        public bool IsEnabled => true;
        public string Tooltip => k_Tooltip;

        static string handLeftPath = PXR_Utils.sdkPackageName + "Resources/Hand/Models/Hand_L.fbx";
        static string handRightPath = PXR_Utils.sdkPackageName + "Resources/Hand/Models/Hand_R.fbx";

#if PICO_MS_SDK
        static string isTrackedLeftHandPath = "<PicoAimHand>{LeftHand}/isTracked";
        static string trackingStateLeftHandPath = "<PicoAimHand>{LeftHand}/trackingState";
        static string aimPositionLeftHandPath = "<PicoAimHand>{LeftHand}/devicePosition";
        static string aimRotationLeftHandPath = "<PicoAimHand>{LeftHand}/deviceRotation";
        static string aimFlagsLeftHandPath = "<PicoAimHand>{LeftHand}/aimFlags";
        static string indexPressedLeftHandPath = "<PicoAimHand>{LeftHand}/indexPressed";
        static string pinchStrengthIndexLeftHandPath = "<PicoAimHand>{LeftHand}/pinchStrengthIndex";

        static string isTrackedRightHandPath = "<PicoAimHand>{RightHand}/isTracked";
        static string trackingStateRightHandPath = "<PicoAimHand>{RightHand}/trackingState";
        static string aimPositionRightHandPath = "<PicoAimHand>{RightHand}/devicePosition";
        static string aimRotationRightHandPath = "<PicoAimHand>{RightHand}/deviceRotation";
        static string aimFlagsRightHandPath = "<PicoAimHand>{RightHand}/aimFlags";
        static string indexPressedRightHandPath = "<PicoAimHand>{RightHand}/indexPressed";
        static string pinchStrengthIndexRightHandPath = "<PicoAimHand>{RightHand}/pinchStrengthIndex";
#else
        static string isTrackedLeftHandPath = "<PicoHandInteraction>{LeftHand}/isTracked";
        static string trackingStateLeftHandPath = "<PicoHandInteraction>{LeftHand}/trackingState";
        static string positionLeftHandPath = "<PicoHandInteraction>{LeftHand}/devicePose/position";
        static string rotationLeftHandPath = "<PicoHandInteraction>{LeftHand}/devicePose/rotation";
        static string aimPositionLeftHandPath = "<PicoHandInteraction>{LeftHand}/pointer/position";
        static string aimRotationLeftHandPath = "<PicoHandInteraction>{LeftHand}/pointer/rotation";
        static string pinchPositionLeftHandPath = "<PicoHandInteraction>{LeftHand}/pinchPose/position";
        static string pokePositionLeftHandPath = "<PicoHandInteraction>{LeftHand}/pokePose/position";
        static string pokeRotationLeftHandPath = "<PicoHandInteraction>{LeftHand}/pokePose/rotation";
        static string selectGraspFirmLeftHandPath = "<PicoHandInteraction>{LeftHand}/graspFirm";
        static string selectPinchTouchedLeftHandPath = "<PicoHandInteraction>{LeftHand}/pinchTouched";
        static string selectValueGraspValueLeftHandPath = "<PicoHandInteraction>{LeftHand}/graspValue";
        static string selectValuePinchValueLeftHandPath = "<PicoHandInteraction>{LeftHand}/pinchValue";
        static string uiPressPointerActivatedLeftHandPath = "<PicoHandInteraction>{LeftHand}/pointerActivated";
        static string uiPressValuePointerActivateValueLeftHandPath = "<PicoHandInteraction>{LeftHand}/pointerActivateValue";

        static string isTrackedRightHandPath = "<PicoHandInteraction>{RightHand}/isTracked";
        static string trackingStateRightHandPath = "<PicoHandInteraction>{RightHand}/trackingState";
        static string positionRightHandPath = "<PicoHandInteraction>{RightHand}/devicePose/position";
        static string rotationRightHandPath = "<PicoHandInteraction>{RightHand}/devicePose/rotation";
        static string aimPositionRightHandPath = "<PicoHandInteraction>{RightHand}/pointer/position";
        static string aimRotationRightHandPath = "<PicoHandInteraction>{RightHand}/pointer/rotation";
        static string pinchPositionRightHandPath = "<PicoHandInteraction>{RightHand}/pinchPose/position";
        static string pokePositionRightHandPath = "<PicoHandInteraction>{RightHand}/pokePose/position";
        static string pokeRotationRightHandPath = "<PicoHandInteraction>{RightHand}/pokePose/rotation";
        static string selectGraspFirmRightHandPath = "<PicoHandInteraction>{RightHand}/graspFirm";
        static string selectPinchTouchedRightHandPath = "<PicoHandInteraction>{RightHand}/pinchTouched";
        static string selectValueGraspValueRightHandPath = "<PicoHandInteraction>{RightHand}/graspValue";
        static string selectValuePinchValueRightHandPath = "<PicoHandInteraction>{RightHand}/pinchValue";
        static string uiPressPointerActivatedRightHandPath = "<PicoHandInteraction>{RightHand}/pointerActivated";
        static string uiPressValuePointerActivateValueRightHandPath = "<PicoHandInteraction>{RightHand}/pointerActivateValue";
#endif

        private static bool isExecuting = false;

        // Writes the `path` into the `Third` slot of the specified Fallback composite (FallbackComposite only uses first/second/third slots for runtime fallback).
        // - If the composite already has a `Third` part: replace its path with the target path;
        // - If the composite does not have a `Third` part: append a `Third` part at the end;
        // - If the path previously existed as a sibling binding (legacy implementation), erase it first to avoid priority conflicts with the composite.
        static void InsertIntoFallbackComposite(InputAction action, string compositeName, string path)
        {
            if (action == null || string.IsNullOrEmpty(path))
            {
                return;
            }

            // Step 1: Remove any sibling binding with the same target path (legacy implementation), delete from tail to head to avoid index shift
            for (int i = action.bindings.Count - 1; i >= 0; i--)
            {
                var b = action.bindings[i];
                if (!b.isComposite && !b.isPartOfComposite && b.path == path)
                {
                    action.ChangeBinding(i).Erase();
                }
            }

            // Step 2: Locate the target composite and scan its parts
            var bindings = action.bindings;
            int compositeIndex = -1;
            int thirdPartIndex = -1;
            int lastPartIndex = -1;

            for (int i = 0; i < bindings.Count; i++)
            {
                var b = bindings[i];
                if (b.isComposite)
                {
                    var name = b.GetNameOfComposite();
                    if (string.Equals(name, compositeName, System.StringComparison.OrdinalIgnoreCase))
                    {
                        compositeIndex = i;
                        lastPartIndex = i;
                        for (int j = i + 1; j < bindings.Count && bindings[j].isPartOfComposite; j++)
                        {
                            if (string.Equals(bindings[j].name, "Third", System.StringComparison.OrdinalIgnoreCase))
                            {
                                thirdPartIndex = j;
                            }
                            lastPartIndex = j;
                        }
                        break;
                    }
                }
            }

            if (compositeIndex < 0)
            {
                Debug.LogWarning($"{k_Id} {action.actionMap?.name}/{action.name} could not find \"{compositeName}\" composite, falling back to adding sibling binding.");
                action.AddBinding(path);
                return;
            }

            if (thirdPartIndex >= 0)
            {
                // Third slot already exists: directly overwrite path
                if (bindings[thirdPartIndex].effectivePath != path)
                {
                    action.ChangeBinding(thirdPartIndex).WithPath(path);
                }
                return;
            }

            // No Third slot: append at the end
            action.ChangeBinding(lastPartIndex).InsertPartBinding("Third", path);
        }

        static void DoInterestingStuff()
        {
            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strBuildingBlocks, PXR_AppLog.strBuildingBlocks_XRIHandInteraction);
#if !XR_HAND
            if (isExecuting)
            {
                Debug.Log("DoInterestingStuff is already executing. Skipping operation.");
                return;
            }
            Debug.LogError($"Need to install {PXR_Utils.xrHandPackageName} first!");
            bool result = EditorUtility.DisplayDialog($"{PXR_Utils.xrHandPackageName}", $"It's detected that xrhand isn't installed in the current project. You can choose OK to auto-install XRHand, or Cancel and install it manually. ", "OK", "Cancel");
            if (result)
            {
                isExecuting = true;
                PXR_Utils.InstallOrUpdateHands();
            }
#else
            var xrHandPackage = UnityEditor.PackageManager.PackageInfo.FindForAssembly(typeof(UnityEngine.XR.Hands.XRHand).Assembly);
            if (xrHandPackage != null)
            {
                PXR_Utils.xrHandVersion = xrHandPackage.version;
                Debug.Log($"XRHand version = {PXR_Utils.xrHandVersion}");
                // if no samples, add.
                if (PXR_Utils.TryFindSample(PXR_Utils.xrHandPackageName, PXR_Utils.xrHandVersion, PXR_Utils.xrHandVisualizerSampleName, out var visualizerSample))
                {
                    if (!Directory.Exists(visualizerSample.importPath))
                    {
                        visualizerSample.Import(Sample.ImportOptions.OverridePreviousImports);
                    }
                }
            }

#if ENABLE_PICO_XR_SDK
            // Under the ENABLE_PICO_XR_SDK path, the creation/update of the PicoHandInteraction device depends on PXR_HandInteractionNative.GetSupported(),
            // which first checks PXR_ProjectSetting.GetProjectConfig().handTracking.
            // If the user only runs this building block without enabling hand tracking, no device will be created at runtime, and all bindings become useless.
            // Consistent with PICO Hand Tracking / XR Hand Tracking building blocks, automatically enable handTracking.
            PXR_ProjectSetting.GetProjectConfig().handTracking = true;
            PXR_ProjectSetting.SaveAssets();
#endif

            // Get left controller and right controller
            // Get XRI Interaction
            var xriPackage = UnityEditor.PackageManager.PackageInfo.FindForAssembly(typeof(XRInteractionManager).Assembly);
            if (xriPackage != null)
            {
                PXR_Utils.xriVersion = xriPackage.version;
                Debug.Log($"XRI Toolkit version = {PXR_Utils.xriVersion}");

                // if no samples, add.
                if (PXR_Utils.TryFindSample(PXR_Utils.xriPackageName, PXR_Utils.xriVersion, PXR_Utils.xriHandsInteractionDemoSampleName, out var sampleXRHand))
                {
                    if (!Directory.Exists(sampleXRHand.importPath))
                    {
                        sampleXRHand.Import(Sample.ImportOptions.OverridePreviousImports);
                    }
                }

                var inputActionAsset = AssetDatabase.LoadAssetAtPath<InputActionAsset>(PXR_Utils.XRIDefaultInputActions);
                if (inputActionAsset == null)
                {
                    // add Samples
                    Debug.LogError($"Failed to load XRI Default Left Controller preset. Now load the {PXR_Utils.xriStarterAssetsSampleName} sample.");
                    if (PXR_Utils.TryFindSample(PXR_Utils.xriPackageName, PXR_Utils.xriVersion, PXR_Utils.xriStarterAssetsSampleName, out var sampleXRI))
                    {
                        if (!Directory.Exists(sampleXRI.importPath))
                        {
                            sampleXRI.Import(Sample.ImportOptions.OverridePreviousImports);
                             inputActionAsset = AssetDatabase.LoadAssetAtPath<InputActionAsset>(PXR_Utils.XRIDefaultInputActions);
                        }
                    }
                }

                // XRI LeftHand
#if XRI_TOOLKIT_3
                InputActionMap actionMapLeftHand = inputActionAsset.FindActionMap("XRI Left");
#else
                InputActionMap actionMapLeftHand = inputActionAsset.FindActionMap("XRI LeftHand");
#endif
                if (actionMapLeftHand != null)
                {
                    InputAction aimPositionAction = actionMapLeftHand.FindAction("Aim Position");
                    if (aimPositionAction != null)
                    {
                        InputAction isTrackedAction = actionMapLeftHand.FindAction("Is Tracked");
                        if (isTrackedAction != null)
                        {
                            bool isTrackedAdded = false;
                            foreach (var b in isTrackedAction.bindings)
                            {
                                if (isTrackedLeftHandPath == b.path)
                                {
                                    isTrackedAdded = true;
                                }
                            }
                            if (!isTrackedAdded)
                            {
                                Debug.Log($"{k_Id} {actionMapLeftHand.name} {isTrackedAction.name} {isTrackedLeftHandPath}");
                                isTrackedAction.AddBinding(isTrackedLeftHandPath);
                            }
                        }

                        InputAction trackingStateAction = actionMapLeftHand.FindAction("Tracking State");
                        if (trackingStateAction != null)
                        {
                            bool trackingStatedAdded = false;
                            foreach (var b in trackingStateAction.bindings)
                            {
                                if (trackingStateLeftHandPath == b.path)
                                {
                                    trackingStatedAdded = true;
                                }
                            }
                            if (!trackingStatedAdded)
                            {
                                Debug.Log($"{k_Id} {actionMapLeftHand.name} {trackingStateAction.name} {trackingStateLeftHandPath}");
                                trackingStateAction.AddBinding(trackingStateLeftHandPath);
                            }
                        }

                        bool aimPositionAdded = false;
                        foreach (var b in aimPositionAction.bindings)
                        {
                            if (aimPositionLeftHandPath == b.path)
                            {
                                aimPositionAdded = true;
                            }
                        }
                        if (!aimPositionAdded)
                        {
                            Debug.Log($"{k_Id} {actionMapLeftHand.name} {aimPositionAction.name} {aimPositionLeftHandPath}");
                            aimPositionAction.AddBinding(aimPositionLeftHandPath);
                        }
                    }

                    InputAction aimRotationAction = actionMapLeftHand.FindAction("Aim Rotation");
                    if (aimRotationAction != null)
                    {
                        bool aimRotationAdded = false;
                        foreach (var b in aimRotationAction.bindings)
                        {
                            if (aimRotationLeftHandPath == b.path)
                            {
                                aimRotationAdded = true;
                            }
                        }
                        if (!aimRotationAdded)
                        {
                            aimRotationAction.AddBinding(aimRotationLeftHandPath);
                        }
                    }

#if PICO_MS_SDK
                    InputAction aimFlagsAction = actionMapLeftHand.FindAction("Aim Flags");
                    if (aimFlagsAction == null)
                    {
                        aimFlagsAction = actionMapLeftHand.FindAction("Meta Aim Flags");
                    }

                    if (aimFlagsAction != null)
                    {
                        bool aimFlagsAdded = false;
                        foreach (var b in aimFlagsAction.bindings)
                        {
                            if (aimFlagsLeftHandPath == b.path)
                            {
                                aimFlagsAdded = true;
                            }
                        }
                        if (!aimFlagsAdded)
                        {
                            aimFlagsAction.AddBinding(aimFlagsLeftHandPath);
                        }
                    }
#else
                    InputAction positionAction = actionMapLeftHand.FindAction("Position");
                    InsertIntoFallbackComposite(positionAction, "Vector3Fallback", positionLeftHandPath);

                    InputAction rotationAction = actionMapLeftHand.FindAction("Rotation");
                    InsertIntoFallbackComposite(rotationAction, "QuaternionFallback", rotationLeftHandPath);

                    InputAction pinchPositionAction = actionMapLeftHand.FindAction("Pinch Position");
                    if (pinchPositionAction != null)
                    {
                        bool pinchPositionAdded = false;
                        foreach (var b in pinchPositionAction.bindings)
                        {
                            if (pinchPositionLeftHandPath == b.path)
                            {
                                pinchPositionAdded = true;
                            }
                        }
                        if (!pinchPositionAdded)
                        {
                            pinchPositionAction.AddBinding(pinchPositionLeftHandPath);
                        }
                    }

                    InputAction pokePositionAction = actionMapLeftHand.FindAction("Poke Position");
                    if (pokePositionAction != null)
                    {
                        bool pokePositionAdded = false;
                        foreach (var b in pokePositionAction.bindings)
                        {
                            if (pokePositionLeftHandPath == b.path)
                            {
                                pokePositionAdded = true;
                            }
                        }
                        if (!pokePositionAdded)
                        {
                            pokePositionAction.AddBinding(pokePositionLeftHandPath);
                        }
                    }

                    InputAction pokeRotationAction = actionMapLeftHand.FindAction("Poke Rotation");
                    if (pokeRotationAction != null)
                    {
                        bool pokeRotationAdded = false;
                        foreach (var b in pokeRotationAction.bindings)
                        {
                            if (pokeRotationLeftHandPath == b.path)
                            {
                                pokeRotationAdded = true;
                            }
                        }
                        if (!pokeRotationAdded)
                        {
                            pokeRotationAction.AddBinding(pokeRotationLeftHandPath);
                        }
                    }
#endif
                }

                // XRI RightHand
#if XRI_TOOLKIT_3
                InputActionMap actionMapRightHand = inputActionAsset.FindActionMap("XRI Right");
#else
                InputActionMap actionMapRightHand = inputActionAsset.FindActionMap("XRI RightHand");
#endif
                if (actionMapRightHand != null)
                {
                    InputAction isTrackedAction = actionMapRightHand.FindAction("Is Tracked");
                    if (isTrackedAction != null)
                    {
                        bool isTrackedAdded = false;
                        foreach (var b in isTrackedAction.bindings)
                        {
                            if (isTrackedRightHandPath == b.path)
                            {
                                isTrackedAdded = true;
                            }
                        }
                        if (!isTrackedAdded)
                        {
                            Debug.Log($"{k_Id} {actionMapRightHand.name} {isTrackedAction.name} {isTrackedRightHandPath}");
                            isTrackedAction.AddBinding(isTrackedRightHandPath);
                        }
                    }

                    InputAction trackingStateAction = actionMapRightHand.FindAction("Tracking State");
                    if (trackingStateAction != null)
                    {
                        bool trackingStatedAdded = false;
                        foreach (var b in trackingStateAction.bindings)
                        {
                            if (trackingStateRightHandPath == b.path)
                            {
                                trackingStatedAdded = true;
                            }
                        }
                        if (!trackingStatedAdded)
                        {
                            Debug.Log($"{k_Id} {actionMapRightHand.name} {trackingStateAction.name} {trackingStateRightHandPath}");
                            trackingStateAction.AddBinding(trackingStateRightHandPath);
                        }
                    }

                    InputAction aimPositionAction = actionMapRightHand.FindAction("Aim Position");
                    if (aimPositionAction != null)
                    {
                        bool aimPositionAdded = false;
                        foreach (var b in aimPositionAction.bindings)
                        {
                            if (aimPositionRightHandPath == b.path)
                            {
                                aimPositionAdded = true;
                            }
                        }
                        if (!aimPositionAdded)
                        {
                            aimPositionAction.AddBinding(aimPositionRightHandPath);
                        }
                    }

                    InputAction aimRotationAction = actionMapRightHand.FindAction("Aim Rotation");
                    if (aimRotationAction != null)
                    {
                        bool aimRotationAdded = false;
                        foreach (var b in aimRotationAction.bindings)
                        {
                            if (aimRotationRightHandPath == b.path)
                            {
                                aimRotationAdded = true;
                            }
                        }
                        if (!aimRotationAdded)
                        {
                            aimRotationAction.AddBinding(aimRotationRightHandPath);
                        }
                    }

#if PICO_MS_SDK
                    InputAction aimFlagsAction = actionMapRightHand.FindAction("Aim Flags");
                    if (aimFlagsAction == null)
                    {
                        aimFlagsAction = actionMapRightHand.FindAction("Meta Aim Flags");
                    }

                    if (aimFlagsAction != null)
                    {
                        bool aimFlagsAdded = false;
                        foreach (var b in aimFlagsAction.bindings)
                        {
                            if (aimFlagsRightHandPath == b.path)
                            {
                                aimFlagsAdded = true;
                            }
                        }
                        if (!aimFlagsAdded)
                        {
                            aimFlagsAction.AddBinding(aimFlagsRightHandPath);
                        }
                    }
#else
                    InputAction positionAction = actionMapRightHand.FindAction("Position");
                    InsertIntoFallbackComposite(positionAction, "Vector3Fallback", positionRightHandPath);

                    InputAction rotationAction = actionMapRightHand.FindAction("Rotation");
                    InsertIntoFallbackComposite(rotationAction, "QuaternionFallback", rotationRightHandPath);

                    InputAction pinchPositionAction = actionMapRightHand.FindAction("Pinch Position");
                    if (pinchPositionAction != null)
                    {
                        bool pinchPositionAdded = false;
                        foreach (var b in pinchPositionAction.bindings)
                        {
                            if (pinchPositionRightHandPath == b.path)
                            {
                                pinchPositionAdded = true;
                            }
                        }
                        if (!pinchPositionAdded)
                        {
                            pinchPositionAction.AddBinding(pinchPositionRightHandPath);
                        }
                    }

                    InputAction pokePositionAction = actionMapRightHand.FindAction("Poke Position");
                    if (pokePositionAction != null)
                    {
                        bool pokePositionAdded = false;
                        foreach (var b in pokePositionAction.bindings)
                        {
                            if (pokePositionRightHandPath == b.path)
                            {
                                pokePositionAdded = true;
                            }
                        }
                        if (!pokePositionAdded)
                        {
                            pokePositionAction.AddBinding(pokePositionRightHandPath);
                        }
                    }

                    InputAction pokeRotationAction = actionMapRightHand.FindAction("Poke Rotation");
                    if (pokeRotationAction != null)
                    {
                        bool pokeRotationAdded = false;
                        foreach (var b in pokeRotationAction.bindings)
                        {
                            if (pokeRotationRightHandPath == b.path)
                            {
                                pokeRotationAdded = true;
                            }
                        }
                        if (!pokeRotationAdded)
                        {
                            pokeRotationAction.AddBinding(pokeRotationRightHandPath);
                        }
                    }
#endif
                }

                // XRI LeftHand Interaction
#if XRI_TOOLKIT_3
                InputActionMap actionMapLeftHandI = inputActionAsset.FindActionMap("XRI Left Interaction");
#else
                InputActionMap actionMapLeftHandI = inputActionAsset.FindActionMap("XRI LeftHand Interaction");
#endif
                if (actionMapLeftHandI != null)
                {
                    InputAction selectAction = actionMapLeftHandI.FindAction("Select");
                    if (selectAction != null)
                    {
#if PICO_MS_SDK
                        bool selectAdded = false;
                        foreach (var b in selectAction.bindings)
                        {
                            if (indexPressedLeftHandPath == b.path)
                            {
                                selectAdded = true;
                            }
                        }
                        if (!selectAdded)
                        {
                            selectAction.AddBinding(indexPressedLeftHandPath);
                        }
#else
                        bool selectGraspFirmAdded = false;
                        bool selectPinchTouchedAdded = false;
                        foreach (var b in selectAction.bindings)
                        {
                            if (selectGraspFirmLeftHandPath == b.path)
                            {
                                selectGraspFirmAdded = true;
                            }

                            if (selectPinchTouchedLeftHandPath == b.path)
                            {
                                selectPinchTouchedAdded = true;
                            }
                        }
                        if (!selectGraspFirmAdded)
                        {
                            selectAction.AddBinding(selectGraspFirmLeftHandPath);
                        }

                        if (!selectPinchTouchedAdded)
                        {
                            selectAction.AddBinding(selectPinchTouchedLeftHandPath);
                        }
#endif
                    }

                    InputAction selectValueAction = actionMapLeftHandI.FindAction("Select Value");
                    if (selectValueAction != null)
                    {
#if PICO_MS_SDK
                        bool selectValueAdded = false;
                        foreach (var b in selectValueAction.bindings)
                        {
                            if (pinchStrengthIndexLeftHandPath == b.path)
                            {
                                selectValueAdded = true;
                            }
                        }
                        if (!selectValueAdded)
                        {
                            selectValueAction.AddBinding(pinchStrengthIndexLeftHandPath);
                        }
#else
                        bool selectValueGraspValueAdded = false;
                        bool selectValuePinchValueAdded = false;
                        foreach (var b in selectValueAction.bindings)
                        {
                            if (selectValueGraspValueLeftHandPath == b.path)
                            {
                                selectValueGraspValueAdded = true;
                            }

                            if (selectValuePinchValueLeftHandPath == b.path)
                            {
                                selectValuePinchValueAdded = true;
                            }
                        }
                        if (!selectValueGraspValueAdded)
                        {
                            selectValueAction.AddBinding(selectValueGraspValueLeftHandPath);
                        }

                        if (!selectValuePinchValueAdded)
                        {
                            selectValueAction.AddBinding(selectValuePinchValueLeftHandPath);
                        }
#endif
                    }

                    InputAction uiPressAction = actionMapLeftHandI.FindAction("UI Press");
                    if (uiPressAction != null)
                    {
#if PICO_MS_SDK
                        bool uiPressAdded = false;
                        foreach (var b in uiPressAction.bindings)
                        {
                            if (indexPressedLeftHandPath == b.path)
                            {
                                uiPressAdded = true;
                            }
                        }
                        if (!uiPressAdded)
                        {
                            uiPressAction.AddBinding(indexPressedLeftHandPath);
                        }
#else
                        bool uiPressAdded = false;
                        foreach (var b in uiPressAction.bindings)
                        {
                            if (uiPressPointerActivatedLeftHandPath == b.path)
                            {
                                uiPressAdded = true;
                            }
                        }
                        if (!uiPressAdded)
                        {
                            uiPressAction.AddBinding(uiPressPointerActivatedLeftHandPath);
                        }
#endif
                    }

                    InputAction uiPressValueAction = actionMapLeftHandI.FindAction("UI Press Value");
                    if (uiPressValueAction != null)
                    {
#if PICO_MS_SDK
                        bool uiPressValueAdded = false;
                        foreach (var b in uiPressValueAction.bindings)
                        {
                            if (pinchStrengthIndexLeftHandPath == b.path)
                            {
                                uiPressValueAdded = true;
                            }
                        }
                        if (!uiPressValueAdded)
                        {
                            uiPressValueAction.AddBinding(pinchStrengthIndexLeftHandPath);
                        }
#else
                        bool uiPressValueAdded = false;
                        foreach (var b in uiPressValueAction.bindings)
                        {
                            if (uiPressValuePointerActivateValueLeftHandPath == b.path)
                            {
                                uiPressValueAdded = true;
                            }
                        }
                        if (!uiPressValueAdded)
                        {
                            uiPressValueAction.AddBinding(uiPressValuePointerActivateValueLeftHandPath);
                        }
#endif
                    }
                }

                // XRI RightHand Interaction
#if XRI_TOOLKIT_3
                InputActionMap actionMapRightHandI = inputActionAsset.FindActionMap("XRI Right Interaction");
#else
                InputActionMap actionMapRightHandI = inputActionAsset.FindActionMap("XRI RightHand Interaction");
#endif
                if (actionMapRightHandI != null)
                {
                    InputAction selectAction = actionMapRightHandI.FindAction("Select");
                    if (selectAction != null)
                    {
#if PICO_MS_SDK
                        bool selectAdded = false;
                        foreach (var b in selectAction.bindings)
                        {
                            if (indexPressedRightHandPath == b.path)
                            {
                                selectAdded = true;
                            }
                        }
                        if (!selectAdded)
                        {
                            selectAction.AddBinding(indexPressedRightHandPath);
                        }
#else
                        bool selectGraspFirmAdded = false;
                        bool selectPinchTouchedAdded = false;
                        foreach (var b in selectAction.bindings)
                        {
                            if (selectGraspFirmRightHandPath == b.path)
                            {
                                selectGraspFirmAdded = true;
                            }

                            if (selectPinchTouchedRightHandPath == b.path)
                            {
                                selectPinchTouchedAdded = true;
                            }
                        }
                        if (!selectGraspFirmAdded)
                        {
                            selectAction.AddBinding(selectGraspFirmRightHandPath);
                        }

                        if (!selectPinchTouchedAdded)
                        {
                            selectAction.AddBinding(selectPinchTouchedRightHandPath);
                        }
#endif
                    }

                    InputAction selectValueAction = actionMapRightHandI.FindAction("Select Value");
                    if (selectValueAction != null)
                    {
#if PICO_MS_SDK
                        bool selectValueAdded = false;
                        foreach (var b in selectValueAction.bindings)
                        {
                            if (pinchStrengthIndexRightHandPath == b.path)
                            {
                                selectValueAdded = true;
                            }
                        }
                        if (!selectValueAdded)
                        {
                            selectValueAction.AddBinding(pinchStrengthIndexRightHandPath);
                        }
#else
                        bool selectValueGraspValueAdded = false;
                        bool selectValuePinchValueAdded = false;
                        foreach (var b in selectValueAction.bindings)
                        {
                            if (selectValueGraspValueRightHandPath == b.path)
                            {
                                selectValueGraspValueAdded = true;
                            }

                            if (selectValuePinchValueRightHandPath == b.path)
                            {
                                selectValuePinchValueAdded = true;
                            }
                        }
                        if (!selectValueGraspValueAdded)
                        {
                            selectValueAction.AddBinding(selectValueGraspValueRightHandPath);
                        }

                        if (!selectValuePinchValueAdded)
                        {
                            selectValueAction.AddBinding(selectValuePinchValueRightHandPath);
                        }
#endif
                    }

                    InputAction uiPressAction = actionMapRightHandI.FindAction("UI Press");
                    if (uiPressAction != null)
                    {
#if PICO_MS_SDK
                        bool uiPressAdded = false;
                        foreach (var b in uiPressAction.bindings)
                        {
                            if (indexPressedRightHandPath == b.path)
                            {
                                uiPressAdded = true;
                            }
                        }
                        if (!uiPressAdded)
                        {
                            uiPressAction.AddBinding(indexPressedRightHandPath);
                        }
#else
                        bool uiPressAdded = false;
                        foreach (var b in uiPressAction.bindings)
                        {
                            if (uiPressPointerActivatedRightHandPath == b.path)
                            {
                                uiPressAdded = true;
                            }
                        }
                        if (!uiPressAdded)
                        {
                            uiPressAction.AddBinding(uiPressPointerActivatedRightHandPath);
                        }
#endif
                    }

                    InputAction uiPressValueAction = actionMapRightHandI.FindAction("UI Press Value");
                    if (uiPressValueAction != null)
                    {
#if PICO_MS_SDK
                        bool uiPressValueAdded = false;
                        foreach (var b in uiPressValueAction.bindings)
                        {
                            if (pinchStrengthIndexRightHandPath == b.path)
                            {
                                uiPressValueAdded = true;
                            }
                        }
                        if (!uiPressValueAdded)
                        {
                            uiPressValueAction.AddBinding(pinchStrengthIndexRightHandPath);
                        }
#else
                        bool uiPressValueAdded = false;
                        foreach (var b in uiPressValueAction.bindings)
                        {
                            if (uiPressValuePointerActivateValueRightHandPath == b.path)
                            {
                                uiPressValueAdded = true;
                            }
                        }
                        if (!uiPressValueAdded)
                        {
                            uiPressValueAction.AddBinding(uiPressValuePointerActivateValueRightHandPath);
                        }
#endif
                    }
                }

                EditorUtility.SetDirty(inputActionAsset);
                AssetDatabase.SaveAssets();
            }

            AssetDatabase.SaveAssets();
            isExecuting = false;
#endif
        }

        public void ExecuteBuildingBlock() => DoInterestingStuff();

        public static void ExecuteBuildingBlockStatic()
        {
            DoInterestingStuff();
        }

        // Each building block should have an accompanying MenuItem as a good practice, we add them here.
        [MenuItem(k_BuildingBlockPath, false, k_SectionPriority)]
        public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff();

        [MenuItem(PXR_Utils.BuildingBlockPathP + PXR_HandSection.k_SectionId + "/" + k_Id, false, k_SectionPriority)]
        public static void ExecuteMenuItemHierarchy(MenuCommand command) => DoInterestingStuff();
    }
#endif

#if ENABLE_PICO_OPENXR_SDK
    class PXR_BuildingBlocksOpenXRXRIHandInteraction : IBuildingBlock
    {
        const string k_Id = "XRI Hand Interaction";
        const string k_BuildingBlockPath = PXR_Utils.BuildingBlockPathO  + PXR_HandSection.k_SectionId + "/"+ k_Id;
        const string k_IconPath = "buildingblockIcon";
        const string k_Tooltip = k_Id + " : This button allows one-click configuration of the gesture interaction method in XRInteraction Toolkit to enable interaction between the hand and 3D objects.";
        static string k_BuildingBlocksXROriginName = $"{PXR_Utils.BuildingBlock} XRI Hand Interaction";
        static string k_BuildingBlocksGrabName = $"{PXR_Utils.BuildingBlock} XRI Hand Grab Interactable";
        const int k_SectionPriority = 5;

        public string Id => k_Id;
        public string IconPath => k_IconPath;
        public bool IsEnabled => true;
        public string Tooltip => k_Tooltip;

        static string handLeftPath = PXR_Utils.sdkPackageName + "Resources/Hand/Models/Hand_L.fbx";
        static string handRightPath = PXR_Utils.sdkPackageName + "Resources/Hand/Models/Hand_R.fbx";
        // XRI LeftHand
        static string positionLeftHandPath = "<HandInteraction>{LeftHand}/devicePose/position";
        static string rotationLeftHandPath = "<HandInteraction>{LeftHand}/devicePose/rotation";
        static string aimPositionLeftHandPath = "<HandInteraction>{LeftHand}/pointer/position";
        static string aimRotationLeftHandPath = "<HandInteraction>{LeftHand}/pointer/rotation";

        static string pinchPosePinchPositionLeftHandPath = "<HandInteraction>{LeftHand}/pinchPose/position";
        static string pointerPinchPositionLeftHandPath = "<HandInteractionPoses>{LeftHand}/pointer/position";

        static string pokePosePinchPositionLeftHandPath = "<HandInteraction>{LeftHand}/pokePose/position";
        static string pokePosePositionLeftHandPath = "<HandInteractionPoses>{LeftHand}/pokePose/position";

        static string pokePosePinchRotationLeftHandPath = "<HandInteraction>{LeftHand}/pokePose/rotation";
        static string pokePoseRotationLeftHandPath = "<HandInteractionPoses>{LeftHand}/pokePose/rotation";

        // XRI RightHand
        static string positionRightHandPath = "<HandInteraction>{RightHand}/devicePose/position";
        static string rotationRightHandPath = "<HandInteraction>{RightHand}/devicePose/rotation";
        static string aimPositionRightHandPath = "<HandInteraction>{RightHand}/pointer/position";
        static string aimRotationRightHandPath = "<HandInteraction>{RightHand}/pointer/rotation";

        static string pinchPosePinchPositionRightHandPath = "<HandInteraction>{RightHand}/pinchPose/position";
        static string pointerPinchPositionRightHandPath = "<HandInteractionPoses>{RightHand}/pointer/position";

        static string pokePosePinchPositionRightHandPath = "<HandInteraction>{RightHand}/pokePose/position";
        static string pokePosePositionRightHandPath = "<HandInteractionPoses>{RightHand}/pokePose/position";

        static string pokePosePinchRotationRightHandPath = "<HandInteraction>{RightHand}/pokePose/rotation";
        static string pokePoseRotationRightHandPath = "<HandInteractionPoses>{RightHand}/pokePose/rotation";

        // XRI LeftHand Interaction 
        static string selectPinchReadyLeftHandPath = "<HandInteraction>{LeftHand}/pinchReady";
        static string selectGraspFirmLeftHandPath = "<HandInteraction>{LeftHand}/graspFirm";
        static string selectPinchTouchedLeftHandPath = "<HandInteraction>{LeftHand}/pinchTouched";

        static string selectValuePinchReadyLeftHandPath = "<HandInteraction>{LeftHand}/pinchValue";
        static string selectValueGraspFirmLeftHandPath = "<HandInteraction>{LeftHand}/graspValue";

        static string uiPressPinchReadyLeftHandPath = "<HandInteraction>{LeftHand}/pinchReady";
        static string uiPressPointerActivatedLeftHandPath = "<HandInteraction>{LeftHand}/pointerActivated";

        static string uiPressValuePinchReadyLeftHandPath = "<HandInteraction>{LeftHand}/pinchValue";
        static string uiPressValuePointerActivateValueLeftHandPath = "<HandInteraction>{LeftHand}/pointerActivateValue";

        // XRI RightHand Interaction
        static string selectPinchReadyRightHandPath = "<HandInteraction>{RightHand}/pinchReady";
        static string selectGraspFirmRightHandPath = "<HandInteraction>{RightHand}/graspFirm";
        static string selectPinchTouchedRightHandPath = "<HandInteraction>{RightHand}/pinchTouched";

        static string selectValuePinchReadyRightHandPath = "<HandInteraction>{RightHand}/pinchValue";
        static string selectValueGraspFirmRightHandPath = "<HandInteraction>{RightHand}/graspValue";

        static string uiPressPinchReadyRightHandPath = "<HandInteraction>{RightHand}/pinchReady";
        static string uiPressPointerActivatedRightHandPath = "<HandInteraction>{RightHand}/pointerActivated";

        static string uiPressValuePinchReadyRightHandPath = "<HandInteraction>{RightHand}/pinchValue";
        static string uiPressValuePointerActivateValueRightHandPath = "<HandInteraction>{RightHand}/pointerActivateValue";

        private static bool isExecuting = false;
        static void DoInterestingStuff()
        {
            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strBuildingBlocks, PXR_AppLog.strBuildingBlocks_XRIHandInteraction);
#if !XR_HAND
            if (isExecuting)
            {
                Debug.Log("DoInterestingStuff is already executing. Skipping operation.");
                return;
            }
            Debug.LogError($"Need to install {PXR_Utils.xrHandPackageName} first!");
            bool result = EditorUtility.DisplayDialog($"{PXR_Utils.xrHandPackageName}", $"It's detected that xrhand isn't installed in the current project. You can choose OK to auto-install XRHand, or Cancel and install it manually. ", "OK", "Cancel");
            if (result)
            {
                isExecuting = true;
                PXR_Utils.InstallOrUpdateHands();
            }
#else

            PXR_Utils.EnableHandTrackingFeature();
            var xrHandPackage = UnityEditor.PackageManager.PackageInfo.FindForAssembly(typeof(UnityEngine.XR.Hands.XRHand).Assembly);
            if (xrHandPackage != null)
            {
                PXR_Utils.xrHandVersion = xrHandPackage.version;
                Debug.Log($"XRHand version = {PXR_Utils.xrHandVersion}");
                // if no samples, add.
                if (PXR_Utils.TryFindSample(PXR_Utils.xrHandPackageName, PXR_Utils.xrHandVersion, PXR_Utils.xrHandVisualizerSampleName, out var visualizerSample))
                {
                    if (!Directory.Exists(visualizerSample.importPath))
                    {
                        visualizerSample.Import(Sample.ImportOptions.OverridePreviousImports);
                    }
                }
            }

            // Get left controller and right controller
            // Get XRI Interaction
            var xriPackage = UnityEditor.PackageManager.PackageInfo.FindForAssembly(typeof(XRInteractionManager).Assembly);
            if (xriPackage != null)
            {
                PXR_Utils.xriVersion = xriPackage.version;
                Debug.Log($"XRI Toolkit version = {PXR_Utils.xriVersion}");

                // if no samples, add.
                if (PXR_Utils.TryFindSample(PXR_Utils.xriPackageName, PXR_Utils.xriVersion, PXR_Utils.xriHandsInteractionDemoSampleName, out var sampleXRHand))
                {
                    if (!Directory.Exists(sampleXRHand.importPath))
                    {
                        sampleXRHand.Import(Sample.ImportOptions.OverridePreviousImports);
                    }
                }

                var inputActionAsset = AssetDatabase.LoadAssetAtPath<InputActionAsset>(PXR_Utils.XRIDefaultInputActions);
                if (inputActionAsset == null)
                {
                    // add Samples
                    Debug.LogError($"Failed to load XRI Default Left Controller preset. Now load the {PXR_Utils.xriStarterAssetsSampleName} sample.");
                    if (PXR_Utils.TryFindSample(PXR_Utils.xriPackageName, PXR_Utils.xriVersion, PXR_Utils.xriStarterAssetsSampleName, out var sampleXRI))
                    {
                        if (!Directory.Exists(sampleXRI.importPath))
                        {
                            sampleXRI.Import(Sample.ImportOptions.OverridePreviousImports);
                        }
                        inputActionAsset = AssetDatabase.LoadAssetAtPath<InputActionAsset>(PXR_Utils.XRIDefaultInputActions);
                    }
                }

#if !XRI_TOOLKIT_3
                // XRI LeftHand
                InputActionMap actionMapLeftHand = inputActionAsset.FindActionMap("XRI LeftHand");
                if (actionMapLeftHand != null)
                {
                    InputAction positionAction = actionMapLeftHand.FindAction("Position");
                    if (positionAction != null)
                    {
                        bool aimPositionAdded = false;
                        foreach (var b in positionAction.bindings)
                        {
                            if (positionLeftHandPath == b.path)
                            {
                                aimPositionAdded = true;
                            }
                        }
                        if (!aimPositionAdded)
                        {
                            Debug.Log($"{k_Id} {actionMapLeftHand.name} {positionAction.name} {positionLeftHandPath}");
                            positionAction.AddBinding(positionLeftHandPath);
                        }
                    }

                    InputAction rotationAction = actionMapLeftHand.FindAction("Rotation");
                    if (rotationAction != null)
                    {
                        bool rotationAdded = false;
                        foreach (var b in rotationAction.bindings)
                        {
                            if (rotationLeftHandPath == b.path)
                            {
                                rotationAdded = true;
                            }
                        }
                        if (!rotationAdded)
                        {
                            Debug.Log($"{k_Id} {actionMapLeftHand.name} {rotationAction.name} {rotationLeftHandPath}");
                            rotationAction.AddBinding(rotationLeftHandPath);
                        }
                    }

                    InputAction aimPositionAction = actionMapLeftHand.FindAction("Aim Position");
                    if (aimPositionAction != null)
                    {
                        bool aimPositionAdded = false;
                        foreach (var b in aimPositionAction.bindings)
                        {
                            if (aimPositionLeftHandPath == b.path)
                            {
                                aimPositionAdded = true;
                            }
                        }
                        if (!aimPositionAdded)
                        {
                            Debug.Log($"{k_Id} {actionMapLeftHand.name} {aimPositionAction.name} {aimPositionLeftHandPath}");
                            aimPositionAction.AddBinding(aimPositionLeftHandPath);
                        }
                    }

                    InputAction aimRotationAction = actionMapLeftHand.FindAction("Aim Rotation");
                    if (aimRotationAction != null)
                    {
                        bool aimRotationAdded = false;
                        foreach (var b in aimRotationAction.bindings)
                        {
                            if (aimRotationLeftHandPath == b.path)
                            {
                                aimRotationAdded = true;
                            }
                        }
                        if (!aimRotationAdded)
                        {
                            aimRotationAction.AddBinding(aimRotationLeftHandPath);
                        }
                    }


                    InputAction pinchPositionAction = actionMapLeftHand.FindAction("Pinch Position");
                    if (pinchPositionAction != null)
                    {
                        bool pinchPosePinchPositionAdded = false;
                        bool pointerPinchPositionAdded = false;
                        foreach (var b in pinchPositionAction.bindings)
                        {
                            if (pinchPosePinchPositionLeftHandPath == b.path)
                            {
                                pinchPosePinchPositionAdded = true;
                            }

                            if (pointerPinchPositionLeftHandPath == b.path)
                            {
                                pointerPinchPositionAdded = true;
                            }
                        }
                        if (!pinchPosePinchPositionAdded)
                        {
                            pinchPositionAction.AddBinding(pinchPosePinchPositionLeftHandPath);
                        }

                        if (!pointerPinchPositionAdded)
                        {
                            pinchPositionAction.AddBinding(pointerPinchPositionLeftHandPath);
                        }
                    }

                    InputAction pokePositionAction = actionMapLeftHand.FindAction("Poke Position");
                    if (pokePositionAction != null)
                    {
                        bool pokePosePinchPositionAdded = false;
                        bool pokePosePositionAdded = false;
                        foreach (var b in pokePositionAction.bindings)
                        {
                            if (pokePosePinchPositionLeftHandPath == b.path)
                            {
                                pokePosePinchPositionAdded = true;
                            }

                            if (pokePosePositionLeftHandPath == b.path)
                            {
                                pokePosePositionAdded = true;
                            }
                        }
                        if (!pokePosePinchPositionAdded)
                        {
                            pokePositionAction.AddBinding(pokePosePinchPositionLeftHandPath);
                        }

                        if (!pokePosePositionAdded)
                        {
                            pokePositionAction.AddBinding(pokePosePositionLeftHandPath);
                        }
                    }

                    InputAction pokeRotationAction = actionMapLeftHand.FindAction("Poke Rotation");
                    if (pokeRotationAction != null)
                    {
                        bool pokePosePinchRotationAdded = false;
                        bool pokePoseRotationAdded = false;
                        foreach (var b in pokeRotationAction.bindings)
                        {
                            if (pokePosePinchRotationLeftHandPath == b.path)
                            {
                                pokePosePinchRotationAdded = true;
                            }

                            if (pokePoseRotationLeftHandPath == b.path)
                            {
                                pokePoseRotationAdded = true;
                            }
                        }
                        if (!pokePosePinchRotationAdded)
                        {
                            pokeRotationAction.AddBinding(pokePosePinchRotationLeftHandPath);
                        }

                        if (!pokePoseRotationAdded)
                        {
                            pokeRotationAction.AddBinding(pokePoseRotationLeftHandPath);
                        }
                    }

                }

                // XRI RightHand
                InputActionMap actionMapRightHand = inputActionAsset.FindActionMap("XRI RightHand");

                if (actionMapRightHand != null)
                {
                    InputAction positionAction = actionMapRightHand.FindAction("Position");
                    if (positionAction != null)
                    {
                        bool aimPositionAdded = false;
                        foreach (var b in positionAction.bindings)
                        {
                            if (positionRightHandPath == b.path)
                            {
                                aimPositionAdded = true;
                            }
                        }
                        if (!aimPositionAdded)
                        {
                            Debug.Log($"{k_Id} {actionMapRightHand.name} {positionAction.name} {positionRightHandPath}");
                            positionAction.AddBinding(positionRightHandPath);
                        }
                    }

                    InputAction rotationAction = actionMapRightHand.FindAction("Rotation");
                    if (rotationAction != null)
                    {
                        bool rotationAdded = false;
                        foreach (var b in rotationAction.bindings)
                        {
                            if (rotationRightHandPath == b.path)
                            {
                                rotationAdded = true;
                            }
                        }
                        if (!rotationAdded)
                        {
                            Debug.Log($"{k_Id} {actionMapRightHand.name} {rotationAction.name} {rotationRightHandPath}");
                            rotationAction.AddBinding(rotationRightHandPath);
                        }
                    }

                    InputAction aimPositionAction = actionMapRightHand.FindAction("Aim Position");
                    if (aimPositionAction != null)
                    {
                        bool aimPositionAdded = false;
                        foreach (var b in aimPositionAction.bindings)
                        {
                            if (aimPositionRightHandPath == b.path)
                            {
                                aimPositionAdded = true;
                            }
                        }
                        if (!aimPositionAdded)
                        {
                            Debug.Log($"{k_Id} {actionMapRightHand.name} {aimPositionAction.name} {aimPositionRightHandPath}");
                            aimPositionAction.AddBinding(aimPositionRightHandPath);
                        }
                    }

                    InputAction aimRotationAction = actionMapRightHand.FindAction("Aim Rotation");
                    if (aimRotationAction != null)
                    {
                        bool aimRotationAdded = false;
                        foreach (var b in aimRotationAction.bindings)
                        {
                            if (aimRotationRightHandPath == b.path)
                            {
                                aimRotationAdded = true;
                            }
                        }
                        if (!aimRotationAdded)
                        {
                            aimRotationAction.AddBinding(aimRotationRightHandPath);
                        }
                    }

                    InputAction pinchPositionAction = actionMapRightHand.FindAction("Pinch Position");
                    if (pinchPositionAction != null)
                    {
                        bool pinchPosePinchPositionAdded = false;
                        bool pointerPinchPositionAdded = false;
                        foreach (var b in pinchPositionAction.bindings)
                        {
                            if (pinchPosePinchPositionRightHandPath == b.path)
                            {
                                pinchPosePinchPositionAdded = true;
                            }

                            if (pointerPinchPositionRightHandPath == b.path)
                            {
                                pointerPinchPositionAdded = true;
                            }
                        }
                        if (!pinchPosePinchPositionAdded)
                        {
                            pinchPositionAction.AddBinding(pinchPosePinchPositionRightHandPath);
                        }

                        if (!pointerPinchPositionAdded)
                        {
                            pinchPositionAction.AddBinding(pointerPinchPositionRightHandPath);
                        }
                    }

                    InputAction pokePositionAction = actionMapRightHand.FindAction("Poke Position");
                    if (pokePositionAction != null)
                    {
                        bool pokePosePinchPositionAdded = false;
                        bool pokePosePositionAdded = false;
                        foreach (var b in pokePositionAction.bindings)
                        {
                            if (pokePosePinchPositionRightHandPath == b.path)
                            {
                                pokePosePinchPositionAdded = true;
                            }

                            if (pokePosePositionRightHandPath == b.path)
                            {
                                pokePosePositionAdded = true;
                            }
                        }
                        if (!pokePosePinchPositionAdded)
                        {
                            pokePositionAction.AddBinding(pokePosePinchPositionRightHandPath);
                        }

                        if (!pokePosePositionAdded)
                        {
                            pokePositionAction.AddBinding(pokePosePositionRightHandPath);
                        }
                    }

                    InputAction pokeRotationAction = actionMapRightHand.FindAction("Poke Rotation");
                    if (pokeRotationAction != null)
                    {
                        bool pokePosePinchRotationAdded = false;
                        bool pokePoseRotationAdded = false;
                        foreach (var b in pokeRotationAction.bindings)
                        {
                            if (pokePosePinchRotationRightHandPath == b.path)
                            {
                                pokePosePinchRotationAdded = true;
                            }

                            if (pokePoseRotationRightHandPath == b.path)
                            {
                                pokePoseRotationAdded = true;
                            }
                        }
                        if (!pokePosePinchRotationAdded)
                        {
                            pokeRotationAction.AddBinding(pokePosePinchRotationRightHandPath);
                        }

                        if (!pokePoseRotationAdded)
                        {
                            pokeRotationAction.AddBinding(pokePoseRotationRightHandPath);
                        }
                    }
                }

                // XRI LeftHand Interaction
                InputActionMap actionMapLeftHandI = inputActionAsset.FindActionMap("XRI LeftHand Interaction");
                if (actionMapLeftHandI != null)
                {
                    // Select
                    InputAction selectAction = actionMapLeftHandI.FindAction("Select");
                    if (selectAction != null)
                    {
                        bool selectPinchReadyAdded = false;
                        bool selectGraspFirmAdded = false;
                        bool selectPinchTouchedAdded = false;
                        foreach (var b in selectAction.bindings)
                        {
                            if (selectPinchReadyLeftHandPath == b.path)
                            {
                                selectPinchReadyAdded = true;
                            }

                            if (selectGraspFirmLeftHandPath == b.path)
                            {
                                selectGraspFirmAdded = true;
                            }

                            if (selectPinchTouchedLeftHandPath == b.path)
                            {
                                selectPinchTouchedAdded = true;
                            }
                        }
                        if (!selectPinchReadyAdded)
                        {
                            selectAction.AddBinding(selectPinchReadyLeftHandPath);
                        }

                        if (!selectGraspFirmAdded)
                        {
                            selectAction.AddBinding(selectGraspFirmLeftHandPath);
                        }

                        if (!selectPinchTouchedAdded)
                        {
                            selectAction.AddBinding(selectPinchTouchedLeftHandPath);
                        }
                    }

                    // Select Value
                    InputAction selectValueAction = actionMapLeftHandI.FindAction("Select Value");
                    if (selectValueAction != null)
                    {
                        bool selectPinchValueAdded = false;
                        bool selectGraspValueAdded = false;
                        foreach (var b in selectValueAction.bindings)
                        {
                            if (selectValuePinchReadyLeftHandPath == b.path)
                            {
                                selectPinchValueAdded = true;
                            }

                            if (selectValueGraspFirmLeftHandPath == b.path)
                            {
                                selectGraspValueAdded = true;
                            }
                        }
                        if (!selectPinchValueAdded)
                        {
                            selectValueAction.AddBinding(selectValuePinchReadyLeftHandPath);
                        }

                        if (!selectGraspValueAdded)
                        {
                            selectValueAction.AddBinding(selectValueGraspFirmLeftHandPath);
                        }
                    }

                    // UI Press
                    InputAction uiPressAction = actionMapLeftHandI.FindAction("UI Press");
                    if (uiPressAction != null)
                    {
                        bool uiPressPinchReadyAdded = false;
                        bool uiPressPointerActivatedAdded = false;
                        foreach (var b in uiPressAction.bindings)
                        {
                            if (uiPressPinchReadyLeftHandPath == b.path)
                            {
                                uiPressPinchReadyAdded = true;
                            }

                            if (uiPressPointerActivatedLeftHandPath == b.path)
                            {
                                uiPressPointerActivatedAdded = true;
                            }
                        }
                        if (!uiPressPinchReadyAdded)
                        {
                            uiPressAction.AddBinding(uiPressPinchReadyLeftHandPath);
                        }

                        if (!uiPressPointerActivatedAdded)
                        {
                            uiPressAction.AddBinding(uiPressPointerActivatedLeftHandPath);
                        }
                    }

                    // UI Press Value
                    InputAction uiPressValueAction = actionMapLeftHandI.FindAction("UI Press Value");
                    if (uiPressValueAction != null)
                    {
                        bool uiPressValuePinchValueAdded = false;
                        bool uiPressValuePointerActivateValueAdded = false;
                        foreach (var b in uiPressValueAction.bindings)
                        {
                            if (uiPressValuePinchReadyLeftHandPath == b.path)
                            {
                                uiPressValuePinchValueAdded = true;
                            }

                            if (uiPressValuePointerActivateValueLeftHandPath == b.path)
                            {
                                uiPressValuePointerActivateValueAdded = true;
                            }
                        }
                        if (!uiPressValuePinchValueAdded)
                        {
                            uiPressValueAction.AddBinding(uiPressValuePinchReadyLeftHandPath);
                        }

                        if (!uiPressValuePointerActivateValueAdded)
                        {
                            uiPressValueAction.AddBinding(uiPressValuePointerActivateValueLeftHandPath);
                        }
                    }
                }

                // XRI RightHand Interaction
                InputActionMap actionMapRightHandI = inputActionAsset.FindActionMap("XRI RightHand Interaction");
                if (actionMapRightHandI != null)
                {
                    // Select
                    InputAction selectAction = actionMapRightHandI.FindAction("Select");
                    if (selectAction != null)
                    {
                        bool selectPinchReadyAdded = false;
                        bool selectGraspFirmAdded = false;
                        bool selectPinchTouchedAdded = false;
                        foreach (var b in selectAction.bindings)
                        {
                            if (selectPinchReadyRightHandPath == b.path)
                            {
                                selectPinchReadyAdded = true;
                            }

                            if (selectGraspFirmRightHandPath == b.path)
                            {
                                selectGraspFirmAdded = true;
                            }

                            if (selectPinchTouchedRightHandPath == b.path)
                            {
                                selectPinchTouchedAdded = true;
                            }
                        }
                        if (!selectPinchReadyAdded)
                        {
                            selectAction.AddBinding(selectPinchReadyRightHandPath);
                        }

                        if (!selectGraspFirmAdded)
                        {
                            selectAction.AddBinding(selectGraspFirmRightHandPath);
                        }

                        if (!selectPinchTouchedAdded)
                        {
                            selectAction.AddBinding(selectPinchTouchedRightHandPath);
                        }
                    }

                    // Select Value
                    InputAction selectValueAction = actionMapRightHandI.FindAction("Select Value");
                    if (selectValueAction != null)
                    {
                        bool selectPinchValueAdded = false;
                        bool selectGraspValueAdded = false;
                        foreach (var b in selectValueAction.bindings)
                        {
                            if (selectValuePinchReadyRightHandPath == b.path)
                            {
                                selectPinchValueAdded = true;
                            }

                            if (selectValueGraspFirmRightHandPath == b.path)
                            {
                                selectGraspValueAdded = true;
                            }
                        }
                        if (!selectPinchValueAdded)
                        {
                            selectValueAction.AddBinding(selectValuePinchReadyRightHandPath);
                        }

                        if (!selectGraspValueAdded)
                        {
                            selectValueAction.AddBinding(selectValueGraspFirmRightHandPath);
                        }
                    }

                    // UI Press
                    InputAction uiPressAction = actionMapRightHandI.FindAction("UI Press");
                    if (uiPressAction != null)
                    {
                        bool uiPressPinchReadyAdded = false;
                        bool uiPressPointerActivatedAdded = false;
                        foreach (var b in uiPressAction.bindings)
                        {
                            if (uiPressPinchReadyRightHandPath == b.path)
                            {
                                uiPressPinchReadyAdded = true;
                            }

                            if (uiPressPointerActivatedRightHandPath == b.path)
                            {
                                uiPressPointerActivatedAdded = true;
                            }
                        }
                        if (!uiPressPinchReadyAdded)
                        {
                            uiPressAction.AddBinding(uiPressPinchReadyRightHandPath);
                        }

                        if (!uiPressPointerActivatedAdded)
                        {
                            uiPressAction.AddBinding(uiPressPointerActivatedRightHandPath);
                        }
                    }

                    // UI Press Value
                    InputAction uiPressValueAction = actionMapRightHandI.FindAction("UI Press Value");
                    if (uiPressValueAction != null)
                    {
                        bool uiPressValuePinchValueAdded = false;
                        bool uiPressValuePointerActivateValueAdded = false;
                        foreach (var b in uiPressValueAction.bindings)
                        {
                            if (uiPressValuePinchReadyRightHandPath == b.path)
                            {
                                uiPressValuePinchValueAdded = true;
                            }

                            if (uiPressValuePointerActivateValueRightHandPath == b.path)
                            {
                                uiPressValuePointerActivateValueAdded = true;
                            }
                        }
                        if (!uiPressValuePinchValueAdded)
                        {
                            uiPressValueAction.AddBinding(uiPressValuePinchReadyRightHandPath);
                        }

                        if (!uiPressValuePointerActivateValueAdded)
                        {
                            uiPressValueAction.AddBinding(uiPressValuePointerActivateValueRightHandPath);
                        }
                    }
                }

#endif
                EditorUtility.SetDirty(inputActionAsset);
                AssetDatabase.SaveAssets();
            }

            AssetDatabase.SaveAssets();
            isExecuting = false;
#endif
        }

        public void ExecuteBuildingBlock() => DoInterestingStuff();

        public static void ExecuteBuildingBlockStatic()
        {
            DoInterestingStuff();
        }

        // Each building block should have an accompanying MenuItem as a good practice, we add them here.
        [MenuItem(k_BuildingBlockPath, false, k_SectionPriority)]
        public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff();

        [MenuItem(PXR_Utils.BuildingBlockPathP  + PXR_HandSection.k_SectionId + "/"+ k_Id, false, k_SectionPriority)]
        public static void ExecuteMenuItemHierarchy(MenuCommand command) => DoInterestingStuff();
    }
#endif

    class PXR_BuildingBlocksXRIGrabInteraction : IBuildingBlock
    {
        const string k_Id = "XRI Grab Interaction";
        const string k_BuildingBlockPath = PXR_Utils.BuildingBlockPathO + PXR_HandSection.k_SectionId + "/" + k_Id;
        const string k_IconPath = "buildingblockIcon";
        const string k_Tooltip = k_Id + " : Grab objects with hands or controllers.";
        static string k_BuildingBlocksXROriginName = $"{PXR_Utils.BuildingBlock} XRI Hand Interaction";
        static string k_BuildingBlocksGrabName = $"{PXR_Utils.BuildingBlock} XRI Hand Grab Interactable";
        const int k_SectionPriority = 6;

        public string Id => k_Id;
        public string IconPath => k_IconPath;
        public bool IsEnabled => true;
        public string Tooltip => k_Tooltip;

        private static bool isExecuting = false;

        static void DoInterestingStuff()
        {
            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strBuildingBlocks, PXR_AppLog.strBuildingBlocks_XRIGrabInteraction);
#if !XR_HAND
            if (isExecuting)
            {
                Debug.Log("DoInterestingStuff is already executing. Skipping operation.");
                return;
            }
            Debug.LogError($"Need to install {PXR_Utils.xrHandPackageName} first!");
            bool result = EditorUtility.DisplayDialog($"{PXR_Utils.xrHandPackageName}", $"It's detected that xrhand isn't installed in the current project. You can choose OK to auto-install XRHand, or Cancel and install it manually. ", "OK", "Cancel");
            if (result)
            {
                isExecuting = true;
                PXR_Utils.InstallOrUpdateHands();
            }
#else

            PXR_Utils.EnableHandTrackingFeature();
            // Get XRI Interaction
            var xriPackage = UnityEditor.PackageManager.PackageInfo.FindForAssembly(typeof(XRInteractionManager).Assembly);
            if (xriPackage == null)
            {
                Debug.LogError($"Failed, please install {PXR_Utils.xriPackageName} first!");
                return;
            }
            PXR_Utils.xriVersion = xriPackage.version;

            // if no samples, add.
            if (PXR_Utils.TryFindSample(PXR_Utils.xriPackageName, PXR_Utils.xriVersion, PXR_Utils.xriStarterAssetsSampleName, out var sampleXRIStarter))
            {
                if (!Directory.Exists(sampleXRIStarter.importPath))
                {
                    sampleXRIStarter.Import(Sample.ImportOptions.OverridePreviousImports);
                }
            }
            if (PXR_Utils.TryFindSample(PXR_Utils.xriPackageName, PXR_Utils.xriVersion, PXR_Utils.xriHandsInteractionDemoSampleName, out var sampleXRHand))
            {
                if (!Directory.Exists(sampleXRHand.importPath))
                {
                    sampleXRHand.Import(Sample.ImportOptions.OverridePreviousImports);
                }
            }

            Debug.Log($"XRI Toolkit version = {xriPackage.version}");

            if (PXR_Utils.FindComponentsInScene<Transform>().Where(component => component.name == k_BuildingBlocksXROriginName).ToList().Count == 0)
            {
                GameObject buildingBlockGO = new GameObject();
                Selection.activeGameObject = buildingBlockGO;

                // Get XROrigin
                GameObject cameraOrigin;
                List<XROrigin> components = PXR_Utils.FindComponentsInScene<XROrigin>().Where(component => component.isActiveAndEnabled).ToList();
                if (components.Count == 0)
                {
                    GameObject ob = PrefabUtility.LoadPrefabContents(PXR_Utils.XRInteractionHandsSetupPath);
                    var activeScene = SceneManager.GetActiveScene();
                    var rootObjects = activeScene.GetRootGameObjects();
                    Undo.SetTransformParent(ob.transform, buildingBlockGO.transform, true, "Parent to camera rig.");
                    ob.transform.localPosition = Vector3.zero;
                    ob.transform.localRotation = Quaternion.identity;
                    ob.transform.localScale = Vector3.one;
                    ob.SetActive(true);
                    cameraOrigin = PXR_Utils.FindComponentsInScene<XROrigin>().Where(component => component.isActiveAndEnabled).ToList()[0].gameObject;
                }
                else
                {
                    cameraOrigin = components[0].gameObject;
                }

                if (cameraOrigin)
                {
                    Transform parentT = cameraOrigin.transform.parent;
#if XRI_TOOLKIT_3
                    if (parentT == null || cameraOrigin.name != PXR_Utils.xri3HandsSetupPefabName)
#else
                    if (parentT == null || parentT.name != PXR_Utils.xri2HandsSetupPefabName)
#endif
                    {
                        cameraOrigin.SetActive(false);
                        GameObject ob = PrefabUtility.LoadPrefabContents(PXR_Utils.XRInteractionHandsSetupPath);
                        var activeScene = SceneManager.GetActiveScene();
                        var rootObjects = activeScene.GetRootGameObjects();
                        Undo.SetTransformParent(ob.transform, buildingBlockGO.transform, true, "Parent to camera rig.");
                        ob.transform.localPosition = Vector3.zero;
                        ob.transform.localRotation = Quaternion.identity;
                        ob.transform.localScale = Vector3.one;
                        ob.SetActive(true);
#if XRI_TOOLKIT_3
                        cameraOrigin = ob;
#else
                        if (ob.transform.Find("XR Origin (XR Rig)"))
                        {
                            cameraOrigin = ob.transform.Find("XR Origin (XR Rig)").gameObject;
                        }
#endif

                    }

                    if (!cameraOrigin.GetComponent<PXR_Manager>())
                    {
                        cameraOrigin.gameObject.AddComponent<PXR_Manager>();
                    }

                    var characterController = cameraOrigin.GetComponent<CharacterController>();
                    if (characterController)
                    {
                        characterController.enabled = false;
                    }
                }

                PXR_ProjectSetting.GetProjectConfig().handTracking = true;

                buildingBlockGO.name = k_BuildingBlocksXROriginName;
                Undo.RegisterCreatedObjectUndo(buildingBlockGO, k_Id);

                EditorSceneManager.MarkSceneDirty(buildingBlockGO.scene);
                EditorSceneManager.SaveScene(buildingBlockGO.scene);

                PXR_Utils.SetTrackingOriginMode();
                PXR_ProjectSetting.SaveAssets();
            }

            if (PXR_Utils.FindComponentsInScene<Transform>().Where(component => component.name == k_BuildingBlocksGrabName).ToList().Count == 0)
            {
                GameObject buildingBlockGO = new GameObject();
                Selection.activeGameObject = buildingBlockGO;

                Camera mainCamera = PXR_Utils.GetMainCameraForXROrigin();
                buildingBlockGO.transform.position = mainCamera.transform.position + new Vector3(0, 0, 0.5f);
                buildingBlockGO.transform.rotation = mainCamera.transform.rotation;
                buildingBlockGO.transform.localScale = new Vector3(0.05f, 0.05f, 0.05f);

                if (!EditorApplication.ExecuteMenuItem("GameObject/XR/Grab Interactable"))
                {
                    EditorApplication.ExecuteMenuItem("GameObject/XR/Grab Interactable");
                }

                GameObject grabInteractableGO = GameObject.Find("Grab Interactable");

                if (grabInteractableGO != null)
                {
                    grabInteractableGO.transform.parent = buildingBlockGO.transform;
                    grabInteractableGO.transform.localPosition = new Vector3(0, 0, 0.5f);
                    grabInteractableGO.transform.localRotation = Quaternion.identity;
                    grabInteractableGO.transform.localScale = Vector3.one;
                    grabInteractableGO.SetActive(true);

                    Selection.activeGameObject = buildingBlockGO;

                    Rigidbody rigidbody = grabInteractableGO.GetComponent<Rigidbody>();
                    if (rigidbody)
                    {
                        grabInteractableGO.GetComponent<Rigidbody>().useGravity = false;
                        grabInteractableGO.GetComponent<Rigidbody>().mass = 0;
#if UNITY_6000_0_OR_NEWER
                        grabInteractableGO.GetComponent<Rigidbody>().linearDamping = 2f;
#else
                        grabInteractableGO.GetComponent<Rigidbody>().drag = 2f;
#endif
                    }
                }

                buildingBlockGO.name = k_BuildingBlocksGrabName;
                Undo.RegisterCreatedObjectUndo(buildingBlockGO, k_Id);

                EditorSceneManager.MarkSceneDirty(buildingBlockGO.scene);
                EditorSceneManager.SaveScene(buildingBlockGO.scene);
            }
            AssetDatabase.SaveAssets();
            isExecuting = false;
#endif
                    }

                    public void ExecuteBuildingBlock() => DoInterestingStuff();

        public static void ExecuteBuildingBlockStatic()
        {
            DoInterestingStuff();
        }

        // Each building block should have an accompanying MenuItem as a good practice, we add them here.
        [MenuItem(k_BuildingBlockPath, false, k_SectionPriority)]
        public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff();

        [MenuItem(PXR_Utils.BuildingBlockPathP + PXR_HandSection.k_SectionId + "/" + k_Id, false, k_SectionPriority)]
        public static void ExecuteMenuItemHierarchy(MenuCommand command) => DoInterestingStuff();
    }

    class PXR_BuildingBlocksXRIPokeInteraction : IBuildingBlock
    {
        const string k_Id = "XRI Poke Interaction";
        const string k_BuildingBlockPath = PXR_Utils.BuildingBlockPathO + PXR_HandSection.k_SectionId + "/" + k_Id;
        const string k_IconPath = "buildingblockIcon";
        const string k_Tooltip = k_Id + " : Poke objects with hands or controllers.";
        static string k_BuildingBlocksXROriginName = $"{PXR_Utils.BuildingBlock} XRI Hand Interaction";
        static string k_BuildingBlocksGrabName = $"{PXR_Utils.BuildingBlock} XRI Hand Poke Interactable";
        const int k_SectionPriority = 7;

        public string Id => k_Id;
        public string IconPath => k_IconPath;
        public bool IsEnabled => true;
        public string Tooltip => k_Tooltip;

        private static bool isExecuting = false;

        static void DoInterestingStuff()
        {
            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strBuildingBlocks, PXR_AppLog.strBuildingBlocks_XRIPokeInteraction);
#if !XR_HAND
            if (isExecuting)
            {
                Debug.Log("DoInterestingStuff is already executing. Skipping operation.");
                return;
            }
            Debug.LogError($"Need to install {PXR_Utils.xrHandPackageName} first!");
            bool result = EditorUtility.DisplayDialog($"{PXR_Utils.xrHandPackageName}", $"It's detected that xrhand isn't installed in the current project. You can choose OK to auto-install XRHand, or Cancel and install it manually. ", "OK", "Cancel");
            if (result)
            {
                isExecuting = true;
                PXR_Utils.InstallOrUpdateHands();
            }
#else

            PXR_Utils.EnableHandTrackingFeature();
            // Get XRI Interaction
            var xriPackage = UnityEditor.PackageManager.PackageInfo.FindForAssembly(typeof(XRInteractionManager).Assembly);
            if (xriPackage == null)
            {
                Debug.LogError($"Failed, please install {PXR_Utils.xriPackageName} first!");
                return;
            }
            PXR_Utils.xriVersion = xriPackage.version;

            // if no samples, add.
            if (PXR_Utils.TryFindSample(PXR_Utils.xriPackageName, PXR_Utils.xriVersion, PXR_Utils.xriStarterAssetsSampleName, out var sampleXRIStarter))
            {
                if (!Directory.Exists(sampleXRIStarter.importPath))
                {
                    sampleXRIStarter.Import(Sample.ImportOptions.OverridePreviousImports);
                }
            }
            if (PXR_Utils.TryFindSample(PXR_Utils.xriPackageName, PXR_Utils.xriVersion, PXR_Utils.xriHandsInteractionDemoSampleName, out var sampleXRHand))
            {
                if (!Directory.Exists(sampleXRHand.importPath))
                {
                    sampleXRHand.Import(Sample.ImportOptions.OverridePreviousImports);
                }
            }

            Debug.Log($"XRI Toolkit version = {xriPackage.version}");

            if (PXR_Utils.FindComponentsInScene<Transform>().Where(component => component.name == k_BuildingBlocksXROriginName).ToList().Count == 0)
            {
                GameObject buildingBlockGO = new GameObject();
                Selection.activeGameObject = buildingBlockGO;

                // Get XROrigin
                GameObject cameraOrigin;
                List<XROrigin> components = PXR_Utils.FindComponentsInScene<XROrigin>().Where(component => component.isActiveAndEnabled).ToList();
                if (components.Count == 0)
                {
                    GameObject ob = PrefabUtility.LoadPrefabContents(PXR_Utils.XRInteractionHandsSetupPath);
                    Undo.RegisterCreatedObjectUndo(ob, "Create XRInteractionHandsSetupPath.");
                    var activeScene = SceneManager.GetActiveScene();
                    var rootObjects = activeScene.GetRootGameObjects();
                    Undo.SetTransformParent(ob.transform, buildingBlockGO.transform, true, "Parent to camera rig.");
                    ob.transform.localPosition = Vector3.zero;
                    ob.transform.localRotation = Quaternion.identity;
                    ob.transform.localScale = Vector3.one;
                    ob.SetActive(true);
                    cameraOrigin = PXR_Utils.FindComponentsInScene<XROrigin>().Where(component => component.isActiveAndEnabled).ToList()[0].gameObject;
                }
                else
                {
                    cameraOrigin = components[0].gameObject;
                }

                if (cameraOrigin)
                {
                    Transform parentT = cameraOrigin.transform.parent;
#if XRI_TOOLKIT_3
                    if (parentT == null || cameraOrigin.name != PXR_Utils.xri3HandsSetupPefabName)
#else
                    if (parentT == null || parentT.name != PXR_Utils.xri2HandsSetupPefabName)
#endif
                    {
                        cameraOrigin.SetActive(false);

                        GameObject ob = PrefabUtility.LoadPrefabContents(PXR_Utils.XRInteractionHandsSetupPath);
                        Undo.RegisterCreatedObjectUndo(ob, "Create XRInteractionHandsSetupPath.");
                        var activeScene = SceneManager.GetActiveScene();
                        var rootObjects = activeScene.GetRootGameObjects();
                        Undo.SetTransformParent(ob.transform, buildingBlockGO.transform, true, "Parent to camera rig.");
                        ob.transform.localPosition = Vector3.zero;
                        ob.transform.localRotation = Quaternion.identity;
                        ob.transform.localScale = Vector3.one;
                        ob.SetActive(true);
#if XRI_TOOLKIT_3
                        cameraOrigin = ob;
#else
                        if (ob.transform.Find("XR Origin (XR Rig)"))
                        {
                            cameraOrigin = ob.transform.Find("XR Origin (XR Rig)").gameObject;
                        }
#endif

                    }

                    if (!cameraOrigin.GetComponent<PXR_Manager>())
                    {
                        cameraOrigin.gameObject.AddComponent<PXR_Manager>();
                    }

                    var characterController = cameraOrigin.GetComponent<CharacterController>();
                    if (characterController)
                    {
                        characterController.enabled = false;
                    }
                }

                PXR_ProjectSetting.GetProjectConfig().handTracking = true;

                buildingBlockGO.name = k_BuildingBlocksXROriginName;
                Undo.RegisterCreatedObjectUndo(buildingBlockGO, k_Id);

                EditorSceneManager.MarkSceneDirty(buildingBlockGO.scene);
                EditorSceneManager.SaveScene(buildingBlockGO.scene);

                PXR_Utils.SetTrackingOriginMode();
                PXR_ProjectSetting.SaveAssets();
            }

            if (PXR_Utils.FindComponentsInScene<Transform>().Where(component => component.name == k_BuildingBlocksGrabName).ToList().Count == 0)
            {
                GameObject buildingBlockGO = new GameObject();
                Selection.activeGameObject = buildingBlockGO;
                buildingBlockGO.transform.position = PXR_Utils.GetMainCameraGOForXROrigin().transform.position;
                buildingBlockGO.transform.rotation = Quaternion.identity;

                GameObject ob = PrefabUtility.LoadPrefabContents(PXR_Utils.XRInteractionPokeButtonPath);
                Undo.RegisterCreatedObjectUndo(ob, "Create XRInteractionPokeButtonPath.");
                var activeScene = SceneManager.GetActiveScene();
                var rootObjects = activeScene.GetRootGameObjects();
                Undo.SetTransformParent(ob.transform, buildingBlockGO.transform, true, "Parent to camera rig.");
                ob.transform.localPosition = new Vector3(0, 0, 0.5f);
                ob.transform.localRotation = Quaternion.identity;
                ob.transform.localScale = Vector3.one;
                ob.SetActive(true);

                buildingBlockGO.name = k_BuildingBlocksGrabName;
                Undo.RegisterCreatedObjectUndo(buildingBlockGO, k_Id);

                EditorSceneManager.MarkSceneDirty(buildingBlockGO.scene);
                EditorSceneManager.SaveScene(buildingBlockGO.scene);
            }
            AssetDatabase.SaveAssets();
            isExecuting = false;
#endif
        }

        public void ExecuteBuildingBlock() => DoInterestingStuff();

        public static void ExecuteBuildingBlockStatic()
        {
            DoInterestingStuff();
        }

        // Each building block should have an accompanying MenuItem as a good practice, we add them here.
        [MenuItem(k_BuildingBlockPath, false, k_SectionPriority)]
        public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff();

        [MenuItem(PXR_Utils.BuildingBlockPathP + PXR_HandSection.k_SectionId + "/" + k_Id, false, k_SectionPriority)]
        public static void ExecuteMenuItemHierarchy(MenuCommand command) => DoInterestingStuff();
    }

#endregion

#region PICO Video Seethrough (VST)
    [BuildingBlockItem(Priority = k_SectionPriority)]
    class PXR_VideoSeethroughSection : IBuildingBlockSection
    {
        public const string k_SectionId = "PICO Video Seethrough";
        public string SectionId => k_SectionId;

        const string k_SectionIconPath = "Building/Block/Section/Icon/Path";
        public string SectionIconPath => k_SectionIconPath;
        const int k_SectionPriority = 3;

        readonly IBuildingBlock[] m_BBlocksElementIds = new IBuildingBlock[]
        {
            new PXR_BuildingBlocksVideoSeethrough(),
            new PXR_BuildingBlocksVideoSeethroughEffect(),
        };

        public IEnumerable<IBuildingBlock> GetBuildingBlocks()
        {
            var elements = m_BBlocksElementIds.ToList();
            return elements;
        }
    }

    class PXR_BuildingBlocksVideoSeethrough : IBuildingBlock
    {
        const string k_Id = "PICO Video Seethrough";
        const string k_BuildingBlockPath = PXR_Utils.BuildingBlockPathO + PXR_VideoSeethroughSection.k_SectionId + "/" + k_Id;
        const string k_IconPath = "buildingblockIcon";
        const string k_Tooltip = k_Id + " : Video seethrought can be set up and enabled with one click.";
        const int k_SectionPriority = 8;
        static string xrOriginName = $"{PXR_Utils.BuildingBlock} {k_Id} XR Origin (XR Rig)";

        public string Id => k_Id;
        public string IconPath => k_IconPath;
        public bool IsEnabled => true;
        public string Tooltip => k_Tooltip;

        static void DoInterestingStuff()
        {
            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strBuildingBlocks, PXR_AppLog.strBuildingBlocks_PICOVideoSeethrough);

            // Get XROrigin
            GameObject cameraOrigin = PXR_Utils.CheckAndCreateXROrigin();
            if (!cameraOrigin.GetComponent<PXR_CameraEffectBlock>())
            {
                cameraOrigin.AddComponent<PXR_CameraEffectBlock>();
            }

            Camera mainCamera = PXR_Utils.GetMainCameraForXROrigin();
            mainCamera.clearFlags = CameraClearFlags.SolidColor;
            mainCamera.backgroundColor = new Color(0, 0, 0, 0);

            cameraOrigin.name = xrOriginName;
            PXR_ProjectSetting.GetProjectConfig().videoSeeThrough = true;
            PXR_ProjectSetting.SaveAssets();
            PXR_Utils.DisableHDR();
#if ENABLE_PICO_OPENXR_SDK
            PXR_Utils.EnableOpenXRFeature<PassthroughFeature>();
#if UNITY_OPENXR_1_16_0
            if (!PXR_Utils.HasCompositionLayerInScene())
            {
                EditorApplication.ExecuteMenuItem("GameObject/XR/Composition Layers/PICO Composition Layer");
            }
#endif
#endif
            EditorSceneManager.SaveScene(cameraOrigin.gameObject.scene);
        }

        public void ExecuteBuildingBlock() => DoInterestingStuff();

        // Each building block should have an accompanying MenuItem as a good practice, we add them here.
        [MenuItem(k_BuildingBlockPath, false, k_SectionPriority)]
        public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff();

        [MenuItem(PXR_Utils.BuildingBlockPathP + PXR_VideoSeethroughSection.k_SectionId + "/" + k_Id, false, k_SectionPriority)]
        public static void ExecuteMenuItemHierarchy(MenuCommand command) => DoInterestingStuff();
    }

    class PXR_BuildingBlocksVideoSeethroughEffect : IBuildingBlock
    {
        const string k_Id = "PICO Video Seethrough Effect";
        const string k_BuildingBlockPath = PXR_Utils.BuildingBlockPathO + PXR_VideoSeethroughSection.k_SectionId + "/" + k_Id;
        const string k_IconPath = "buildingblockIcon";
        const string k_Tooltip = k_Id + " : The parameters of Video Seethrough Effect can be set and debugged. After recording the values, they can be used. ";
        const int k_SectionPriority = 9;

#if ENABLE_PICO_OPENXR_SDK
        static string cameraEffectPath = PXR_Utils.sdkPackageName + "BuildingBlocks/Prefabs/CameraEffectOpenXR.prefab";
#else
        static string cameraEffectPath = PXR_Utils.sdkPackageName + "BuildingBlocks/Prefabs/CameraEffect.prefab";
#endif
        static string cameraEffectName = $"{PXR_Utils.BuildingBlock} {k_Id}";
        static string xrOriginName = $"{PXR_Utils.BuildingBlock} {k_Id} XR Origin (XR Rig)";

        public string Id => k_Id;
        public string IconPath => k_IconPath;
        public bool IsEnabled => true;
        public string Tooltip => k_Tooltip;

        static void DoInterestingStuff()
        {
            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strBuildingBlocks, PXR_AppLog.strBuildingBlocks_PICOVideoSeethroughEffect);
            PXR_BuildingBlocksControllerTracking pXR_BuildingBlocksControllerTracking = new PXR_BuildingBlocksControllerTracking();
            pXR_BuildingBlocksControllerTracking.ExecuteBuildingBlock();

            // Get XROrigin
            GameObject cameraOrigin = PXR_Utils.CheckAndCreateXROrigin();
            Camera mainCamera = PXR_Utils.GetMainCameraForXROrigin();
            mainCamera.clearFlags = CameraClearFlags.SolidColor;
            mainCamera.backgroundColor = new Color(0, 0, 0, 0);

            PXR_ProjectSetting.GetProjectConfig().videoSeeThrough = true;
            PXR_ProjectSetting.SaveAssets();

            Canvas canvas;
            List<Canvas> canvasComponents = PXR_Utils.FindComponentsInScene<Canvas>().ToList();
            if (canvasComponents.Count == 0)
            {
                #if UNITY_6000_3_OR_NEWER
                if (!EditorApplication.ExecuteMenuItem("GameObject/UI (Canvas)/Canvas"))
                {
                    EditorApplication.ExecuteMenuItem("GameObject/UI (Canvas)/Canvas");
                }
                #else
                 if (!EditorApplication.ExecuteMenuItem("GameObject/UI/Canvas"))
                {
                    EditorApplication.ExecuteMenuItem("GameObject/UI/Canvas");
                }
                #endif
               
                var canvases = PXR_Utils.FindComponentsInScene<Canvas>();
                if (canvases.Count == 0)
                {
                    Debug.LogError("Canvas was not created successfully.");
                    return;
                }

                canvas = canvases[0];
            }
            else
            {
                canvas = canvasComponents[0];
            }
            string planeName = $"{PXR_Utils.BuildingBlock} Plane";
            GameObject plane = PXR_Utils.FindComponentsInScene<Transform>()
                .FirstOrDefault(component => component.name == planeName)?.gameObject;

            if (plane == null)
            {
                plane = GameObject.CreatePrimitive(PrimitiveType.Plane);
                Undo.RegisterCreatedObjectUndo(plane, "Create Plane");
                plane.name = planeName;
                plane.transform.position = Vector3.zero;
                plane.transform.rotation = Quaternion.identity;
                plane.transform.localScale = Vector3.one;
            }
            if (canvas)
            {
                TrackedDeviceGraphicRaycaster trackedDeviceGraphicRaycaster = canvas.transform.GetComponent<TrackedDeviceGraphicRaycaster>();
                if (trackedDeviceGraphicRaycaster == null)
                {
                    canvas.gameObject.AddComponent<TrackedDeviceGraphicRaycaster>();
                }
                else
                {
                    trackedDeviceGraphicRaycaster.enabled = true;
                }
                Camera mainCam = PXR_Utils.GetMainCameraForXROrigin();
                canvas.worldCamera = mainCam;
                if (canvas.renderMode != RenderMode.WorldSpace)
                {
                    Vector2 canvasDimensionsScaled;
                    Vector2 canvasDimensionsInMeters = new Vector2(1.0f, 1.0f);
                    const float canvasWorldSpaceScale = 0.001f;
                    canvasDimensionsScaled = canvasDimensionsInMeters / canvasWorldSpaceScale;
                    canvas.GetComponent<RectTransform>().sizeDelta = canvasDimensionsScaled;
                    canvas.renderMode = RenderMode.WorldSpace;
                    canvas.transform.localScale = Vector3.one * canvasWorldSpaceScale;
                    canvas.transform.position = mainCam.transform.position + new Vector3(0, 0, 1);
                    canvas.transform.rotation = mainCam.transform.rotation;
                }

                if (!canvas.transform.Find(cameraEffectName))
                {
                    GameObject cameraEffectPrefabs = PrefabUtility.LoadPrefabContents(cameraEffectPath);
                    if (cameraEffectPrefabs != null)
                    {
                        if (cameraOrigin != null)
                        {
                            Undo.RegisterCreatedObjectUndo(cameraEffectPrefabs, "Create camera effect.");
                            Undo.SetTransformParent(cameraEffectPrefabs.transform, canvas.transform, true, "Parent to canvas.");
                            cameraEffectPrefabs.transform.localPosition = Vector3.zero;
                            cameraEffectPrefabs.transform.localRotation = Quaternion.identity;
                            cameraEffectPrefabs.transform.localScale = Vector3.one * 2;
                            cameraEffectPrefabs.SetActive(true);
                            cameraEffectPrefabs.name = cameraEffectName;
                        }
                    }
                }
            }

            GameObject eventSystemGO;
            List<EventSystem> esComponents = PXR_Utils.FindComponentsInScene<EventSystem>().ToList();

            if (esComponents.Count > 0)
            {
                foreach (var es in esComponents)
                {
                    Undo.DestroyObjectImmediate(es.gameObject);
                }
            }

            eventSystemGO = new GameObject("EventSystem");
            Undo.RegisterCreatedObjectUndo(eventSystemGO, "Create EventSystem");
            eventSystemGO.AddComponent<EventSystem>();
            XRUIInputModule xRUIInputModule = eventSystemGO.AddComponent<XRUIInputModule>();
            xRUIInputModule.clickSpeed = 0.3f;
            xRUIInputModule.moveDeadzone = 0.6f;
            xRUIInputModule.repeatDelay = 0.5f;
            xRUIInputModule.repeatRate = 0.1f;
            xRUIInputModule.trackedDeviceDragThresholdMultiplier = 2.0f;
            xRUIInputModule.trackedScrollDeltaMultiplier = 5.0f;
            xRUIInputModule.activeInputMode = XRUIInputModule.ActiveInputMode.InputSystemActions;
            string[] guids = AssetDatabase.FindAssets("XRI Default Input Actions t:InputActionAsset");
            if (guids.Length > 0)
            {
                string path = AssetDatabase.GUIDToAssetPath(guids[0]);
                UnityEngine.Object[] assets = AssetDatabase.LoadAllAssetsAtPath(path);

                InputActionReference GetAction(string map, string action)
                {
                    foreach (var asset in assets)
                    {
                        if (asset is InputActionReference reference &&
                            reference.action != null &&
                            reference.action.name == action &&
                            reference.action.actionMap != null &&
                            reference.action.actionMap.name == map)
                            return reference;
                    }

                    return null;
                }

                xRUIInputModule.pointAction = GetAction("XRI UI", "Point");
                xRUIInputModule.leftClickAction = GetAction("XRI UI", "Click");
                xRUIInputModule.middleClickAction = GetAction("XRI UI", "MiddleClick");
                xRUIInputModule.rightClickAction = GetAction("XRI UI", "RightClick");
                xRUIInputModule.scrollWheelAction = GetAction("XRI UI", "ScrollWheel");
                xRUIInputModule.navigateAction = GetAction("XRI UI", "Navigate");
                xRUIInputModule.submitAction = GetAction("XRI UI", "Submit");
                xRUIInputModule.cancelAction = GetAction("XRI UI", "Cancel");
            }

            PXR_Utils.SetTrackingOriginMode();
            cameraOrigin.name = xrOriginName;
#if ENABLE_PICO_OPENXR_SDK
            PXR_Utils.EnableOpenXRFeature<PassthroughFeature>();
#if UNITY_OPENXR_1_16_0
            if (!PXR_Utils.HasCompositionLayerInScene())
            {
                EditorApplication.ExecuteMenuItem("GameObject/XR/Composition Layers/PICO Composition Layer");
            }
#endif
#endif
            Undo.RegisterCreatedObjectUndo(canvas, k_Id);
            EditorSceneManager.MarkSceneDirty(cameraOrigin.scene);
            EditorSceneManager.SaveScene(cameraOrigin.scene);
            PXR_Utils.DisableHDR();
        }

        public void ExecuteBuildingBlock() => DoInterestingStuff();

        // Each building block should have an accompanying MenuItem as a good practice, we add them here.
        [MenuItem(k_BuildingBlockPath, false, k_SectionPriority)]
        public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff();

        [MenuItem(PXR_Utils.BuildingBlockPathP + PXR_VideoSeethroughSection.k_SectionId + "/" + k_Id, false, k_SectionPriority)]
        public static void ExecuteMenuItemHierarchy(MenuCommand command) => DoInterestingStuff();
    }

#endregion

#region PICO Motion Tracker
    [BuildingBlockItem(Priority = k_SectionPriority)]
    class PXR_MotionTrackingSection : IBuildingBlockSection
    {
        public const string k_SectionId = "PICO Motion Tracker";
        public string SectionId => k_SectionId;

        const string k_SectionIconPath = "Building/Block/Section/Icon/Path";
        public string SectionIconPath => k_SectionIconPath;
        const int k_SectionPriority = 4;

        readonly IBuildingBlock[] m_BBlocksElementIds = new IBuildingBlock[]
        {
            new PXR_BuildingBlocksBodyTracking(),
            new PXR_BuildingBlocksBodyTrackingDebug(),
#if !ENABLE_PICO_OPENXR_SDK
            new PXR_BuildingBlocksMotionTracking(),
#endif
        };

        public IEnumerable<IBuildingBlock> GetBuildingBlocks()
        {
            var elements = m_BBlocksElementIds.ToList();
            return elements;
        }
    }

    class PXR_BuildingBlocksBodyTracking : IBuildingBlock
    {
        const string k_Id = "PICO Body Tracking";
        const string k_BuildingBlockPath = PXR_Utils.BuildingBlockPathO + PXR_MotionTrackingSection.k_SectionId + "/" + k_Id;
        const string k_IconPath = "buildingblockIcon";
        const string k_Tooltip = k_Id + " : Body Tracking can be set with one click through this block, and 24 cubes will be used to display the tracking status of 24 human body joints in real time. ";
        const int k_SectionPriority = 10;
        static string bodyTrackingPath = PXR_Utils.sdkPackageName + "BuildingBlocks/Prefabs/BodyTracking.prefab";
        static string k_BuildingBlocksGOName = $"{PXR_Utils.BuildingBlock} {k_Id}";

        public string Id => k_Id;
        public string IconPath => k_IconPath;
        public bool IsEnabled => true;
        public string Tooltip => k_Tooltip;

        static void DoInterestingStuff()
        {
#if ENABLE_PICO_OPENXR_SDK
            PXR_Utils.EnableOpenXRFeature<BodyTrackingFeature>();
#endif
            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strBuildingBlocks, PXR_AppLog.strBuildingBlocks_PICOBodyTracking);
            // Get XROrigin
            GameObject cameraOrigin = PXR_Utils.CheckAndCreateXROrigin();

            PXR_ProjectSetting.GetProjectConfig().bodyTracking = true;
            PXR_ProjectSetting.SaveAssets();

            if (PXR_Utils.FindComponentsInScene<Transform>().Where(component => component.name == k_BuildingBlocksGOName).ToList().Count == 0)
            {
                GameObject buildingBlockGO = new GameObject();
                Selection.activeGameObject = buildingBlockGO;

                Camera mainCamera = PXR_Utils.GetMainCameraForXROrigin();
                buildingBlockGO.transform.position = mainCamera.transform.position;
                buildingBlockGO.transform.rotation = mainCamera.transform.rotation;

                GameObject ob = PrefabUtility.LoadPrefabContents(bodyTrackingPath);
                Undo.RegisterCreatedObjectUndo(ob, "Create bodyTrackingPath.");
                var activeScene = SceneManager.GetActiveScene();
                var rootObjects = activeScene.GetRootGameObjects();
                Undo.SetTransformParent(ob.transform, buildingBlockGO.transform, true, "Parent to ob.");
                ob.transform.localPosition = Vector3.zero;
                ob.transform.localRotation = Quaternion.identity;
                ob.transform.localScale = Vector3.one;
                ob.SetActive(true);

                buildingBlockGO.name = k_BuildingBlocksGOName;
                Undo.RegisterCreatedObjectUndo(buildingBlockGO, k_Id);

                PXR_Utils.SetTrackingOriginMode();
                EditorSceneManager.MarkSceneDirty(buildingBlockGO.scene);
                EditorSceneManager.SaveScene(buildingBlockGO.scene);
            }
            AssetDatabase.SaveAssets();
        }

        public void ExecuteBuildingBlock() => DoInterestingStuff();

        // Each building block should have an accompanying MenuItem as a good practice, we add them here.
        [MenuItem(k_BuildingBlockPath, false, k_SectionPriority)]
        public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff();

        [MenuItem(PXR_Utils.BuildingBlockPathP + PXR_MotionTrackingSection.k_SectionId + "/" + k_Id, false, k_SectionPriority)]
        public static void ExecuteMenuItemHierarchy(MenuCommand command) => DoInterestingStuff();
    }

    class PXR_BuildingBlocksBodyTrackingDebug : IBuildingBlock
    {
        const string k_Id = "PICO Body Tracking Debug";
        const string k_BuildingBlockPath = PXR_Utils.BuildingBlockPathO + PXR_MotionTrackingSection.k_SectionId + "/" + k_Id;
        const string k_IconPath = "buildingblockIcon";
        const string k_Tooltip = k_Id + " : If the Avatar model you are using does not match the 24-joint data direction of PICO, you can adapt it by rotating the X, Y, and Z axes of the specified joint data. ";
        const int k_SectionPriority = 11;
        static string bodyTrackingPath = PXR_Utils.sdkPackageName + "BuildingBlocks/Prefabs/BodyTrackingDebug.prefab";
        static string k_BuildingBlocksGOName = $"{PXR_Utils.BuildingBlock} {k_Id}";

        public string Id => k_Id;
        public string IconPath => k_IconPath;
        public bool IsEnabled => true;
        public string Tooltip => k_Tooltip;

        static void DoInterestingStuff()
        {
#if ENABLE_PICO_OPENXR_SDK
            PXR_Utils.EnableOpenXRFeature<BodyTrackingFeature>();
#endif
            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strBuildingBlocks, PXR_AppLog.strBuildingBlocks_PICOBodyTrackingDebug);
            PXR_BuildingBlocksControllerTracking pXR_BuildingBlocksControllerTracking = new PXR_BuildingBlocksControllerTracking();
            pXR_BuildingBlocksControllerTracking.ExecuteBuildingBlock();
            // Get XROrigin
            GameObject cameraOrigin = PXR_Utils.CheckAndCreateXROrigin();

            PXR_ProjectSetting.GetProjectConfig().bodyTracking = true;
            PXR_ProjectSetting.SaveAssets();

            if (PXR_Utils.FindComponentsInScene<Transform>().Where(component => component.name == k_BuildingBlocksGOName).ToList().Count == 0)
            {
                GameObject buildingBlockGO = new GameObject();
                Selection.activeGameObject = buildingBlockGO;

                Camera mainCamera = PXR_Utils.GetMainCameraForXROrigin();
                buildingBlockGO.transform.position = mainCamera.transform.position;
                buildingBlockGO.transform.rotation = mainCamera.transform.rotation;

                GameObject ob = PrefabUtility.LoadPrefabContents(bodyTrackingPath);
                Undo.RegisterCreatedObjectUndo(ob, "Create bodyTrackingPath.");
                var activeScene = SceneManager.GetActiveScene();
                var rootObjects = activeScene.GetRootGameObjects();
                Undo.SetTransformParent(ob.transform, buildingBlockGO.transform, true, "Parent to ob.");
                ob.transform.localPosition = Vector3.zero + new Vector3(0, 0, 1);
                ob.transform.localRotation = Quaternion.identity;
                ob.transform.localScale = Vector3.one;
                ob.SetActive(true);

                buildingBlockGO.name = k_BuildingBlocksGOName;
                Undo.RegisterCreatedObjectUndo(buildingBlockGO, k_Id);

                PXR_Utils.SetTrackingOriginMode();
                EditorSceneManager.MarkSceneDirty(buildingBlockGO.scene);
                EditorSceneManager.SaveScene(buildingBlockGO.scene);
            }
            AssetDatabase.SaveAssets();
        }

        public void ExecuteBuildingBlock() => DoInterestingStuff();

        // Each building block should have an accompanying MenuItem as a good practice, we add them here.
        [MenuItem(k_BuildingBlockPath, false, k_SectionPriority)]
        public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff();

        [MenuItem(PXR_Utils.BuildingBlockPathP + PXR_MotionTrackingSection.k_SectionId + "/" + k_Id, false, k_SectionPriority)]
        public static void ExecuteMenuItemHierarchy(MenuCommand command) => DoInterestingStuff();
    }

#if !ENABLE_PICO_OPENXR_SDK
    class PXR_BuildingBlocksMotionTracking : IBuildingBlock
    {
        const string k_Id = "PICO Motion Tracking";
        const string k_BuildingBlockPath = PXR_Utils.BuildingBlockPathO + PXR_MotionTrackingSection.k_SectionId + "/" + k_Id;
        const string k_IconPath = "buildingblockIcon";
        const string k_Tooltip = k_Id + " : Motion Tracking can be set with one click through this block. ";
        const int k_SectionPriority = 12;
        static string k_BuildingBlocksGOName = $"{PXR_Utils.BuildingBlock} {k_Id}";

        public string Id => k_Id;
        public string IconPath => k_IconPath;
        public bool IsEnabled => true;
        public string Tooltip => k_Tooltip;

        static void DoInterestingStuff()
        {
            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strBuildingBlocks, PXR_AppLog.strBuildingBlocks_PICOObjectTracking);
            // Get XROrigin
            GameObject cameraOrigin = PXR_Utils.CheckAndCreateXROrigin();

            PXR_ProjectSetting.GetProjectConfig().bodyTracking = true;
            PXR_ProjectSetting.SaveAssets();

            if (PXR_Utils.FindComponentsInScene<Transform>().Where(component => component.name == k_BuildingBlocksGOName).ToList().Count == 0)
            {
                GameObject buildingBlockGO = new GameObject();
                Selection.activeGameObject = buildingBlockGO;

                Camera mainCamera = PXR_Utils.GetMainCameraForXROrigin();

                if (!buildingBlockGO.GetComponent<PXR_MotionTrackingBlock>())
                {
                    buildingBlockGO.AddComponent<PXR_MotionTrackingBlock>();
                }

                buildingBlockGO.name = k_BuildingBlocksGOName;
                Undo.RegisterCreatedObjectUndo(buildingBlockGO, k_Id);
                Undo.SetTransformParent(buildingBlockGO.transform, mainCamera.transform.parent, true, "Parent to camera offset.");
                buildingBlockGO.transform.localPosition = Vector3.zero;
                buildingBlockGO.transform.localRotation = Quaternion.identity;
                buildingBlockGO.transform.localScale = Vector3.one;

                PXR_Utils.SetTrackingOriginMode();
                EditorSceneManager.MarkSceneDirty(buildingBlockGO.scene);
                EditorSceneManager.SaveScene(buildingBlockGO.scene);
            }
            AssetDatabase.SaveAssets();
        }

        public void ExecuteBuildingBlock() => DoInterestingStuff();

        // Each building block should have an accompanying MenuItem as a good practice, we add them here.
        [MenuItem(k_BuildingBlockPath, false, k_SectionPriority)]
        public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff();

        [MenuItem(PXR_Utils.BuildingBlockPathP + PXR_MotionTrackingSection.k_SectionId + "/" + k_Id, false, k_SectionPriority)]
        public static void ExecuteMenuItemHierarchy(MenuCommand command) => DoInterestingStuff();
    }
#endif

#endregion

#if PICO_SPATIALIZER
#region PICO Spatial Audio
    [BuildingBlockItem(Priority = k_SectionPriority)]
    class PXR_SpatialAudioSection : IBuildingBlockSection
    {
        public const string k_SectionId = "PICO Spatial Audio";
        public string SectionId => k_SectionId;

        const string k_SectionIconPath = "Building/Block/Section/Icon/Path";
        public string SectionIconPath => k_SectionIconPath;
        const int k_SectionPriority = 5;

        readonly IBuildingBlock[] m_BBlocksElementIds = new IBuildingBlock[]
        {
            new PXR_BuildingBlocksSpatialAudioFreeField(),
            new PXR_BuildingBlocksSpatialAudioAmbisonics(),
        };

        public IEnumerable<IBuildingBlock> GetBuildingBlocks()
        {
            var elements = m_BBlocksElementIds.ToList();
            return elements;
        }
    }

    class PXR_BuildingBlocksSpatialAudioFreeField : IBuildingBlock
    {
        const string k_Id = "PICO Spatial Audio Free Field";
        const string k_BuildingBlockPath = PXR_Utils.BuildingBlockPathO + PXR_SpatialAudioSection.k_SectionId + "/" + k_Id;
        const string k_IconPath = "buildingblockIcon";
        const string k_Tooltip = k_Id + " : A free field is a sound field that only simulates the location of the audio source while ignoring all environmental acoustic phenomena such as reflection sounds.";
        const int k_SectionPriority = 13;
        static string freeFieldPath = PXR_Utils.sdkPackageName + "BuildingBlocks/Prefabs/SpatialAudioFreeField.prefab";
        static string k_BuildingBlocksGOName = $"{PXR_Utils.BuildingBlock} {k_Id}";

        public string Id => k_Id;
        public string IconPath => k_IconPath;
        public bool IsEnabled => true;
        public string Tooltip => k_Tooltip;

        static void DoInterestingStuff()
        {
            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strBuildingBlocks, PXR_AppLog.strBuildingBlocks_PICOSpatialAudioFreeField);
            // Get XROrigin
            GameObject cameraOrigin = PXR_Utils.CheckAndCreateXROrigin();
            Camera mainCam = PXR_Utils.GetMainCameraForXROrigin();
            if (!mainCam.GetComponent<PXR_Audio_Spatializer_AudioListener>())
            {
                mainCam.gameObject.AddComponent<PXR_Audio_Spatializer_AudioListener>();
            }

            if (PXR_Utils.FindComponentsInScene<Transform>().Where(component => component.name == k_BuildingBlocksGOName).ToList().Count == 0)
            {
                GameObject buildingBlockGO = new GameObject();
                Selection.activeGameObject = buildingBlockGO;

                Camera mainCamera = PXR_Utils.GetMainCameraForXROrigin();
                buildingBlockGO.transform.position = mainCamera.transform.position;
                buildingBlockGO.transform.rotation = mainCamera.transform.rotation;

                GameObject ob = PrefabUtility.LoadPrefabContents(freeFieldPath);
                Undo.RegisterCreatedObjectUndo(ob, "Create freeFieldPath.");
                var activeScene = SceneManager.GetActiveScene();
                var rootObjects = activeScene.GetRootGameObjects();
                Undo.SetTransformParent(ob.transform, buildingBlockGO.transform, true, "Parent to ob.");
                ob.transform.localPosition = Vector3.forward;
                ob.transform.localRotation = Quaternion.identity;
                ob.transform.localScale = Vector3.one;
                ob.SetActive(true);

                buildingBlockGO.name = k_BuildingBlocksGOName;
                Undo.RegisterCreatedObjectUndo(buildingBlockGO, k_Id);

                PXR_Utils.SetTrackingOriginMode();
                EditorSceneManager.MarkSceneDirty(buildingBlockGO.scene);
                EditorSceneManager.SaveScene(buildingBlockGO.scene);
            }
            AssetDatabase.SaveAssets();
        }

        public void ExecuteBuildingBlock() => DoInterestingStuff();

        // Each building block should have an accompanying MenuItem as a good practice, we add them here.
        [MenuItem(k_BuildingBlockPath, false, k_SectionPriority)]
        public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff();

        [MenuItem(PXR_Utils.BuildingBlockPathP + PXR_SpatialAudioSection.k_SectionId + "/" + k_Id, false, k_SectionPriority)]
        public static void ExecuteMenuItemHierarchy(MenuCommand command) => DoInterestingStuff();
    }

    class PXR_BuildingBlocksSpatialAudioAmbisonics : IBuildingBlock
    {
        const string k_Id = "PICO Spatial Audio Ambisonics";
        const string k_BuildingBlockPath = PXR_Utils.BuildingBlockPathO + PXR_SpatialAudioSection.k_SectionId + "/" + k_Id;
        const string k_IconPath = "buildingblockIcon";
        const string k_Tooltip = k_Id + " : Ambisonics is a full-sphere surround sound effect that covers audio sources on the horizontal plane and below and above the listener, thereby giving the listener a highly immersive audio experience.";
        const int k_SectionPriority = 14;
        static string patialAudioAmbisonicsPath = PXR_Utils.sdkPackageName + "BuildingBlocks/Prefabs/SpatialAudioAmbisonics.prefab";
        static string k_BuildingBlocksGOName = $"{PXR_Utils.BuildingBlock} {k_Id}";

        public string Id => k_Id;
        public string IconPath => k_IconPath;
        public bool IsEnabled => true;
        public string Tooltip => k_Tooltip;

        static void DoInterestingStuff()
        {
            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strBuildingBlocks, PXR_AppLog.strBuildingBlocks_PICOSpatialAudioAmbisonics);
            // Get XROrigin
            GameObject cameraOrigin = PXR_Utils.CheckAndCreateXROrigin();
            Camera mainCam = PXR_Utils.GetMainCameraForXROrigin();
            if (!mainCam.GetComponent<PXR_Audio_Spatializer_AudioListener>())
            {
                mainCam.gameObject.AddComponent<PXR_Audio_Spatializer_AudioListener>();
            }

            if (PXR_Utils.FindComponentsInScene<Transform>().Where(component => component.name == k_BuildingBlocksGOName).ToList().Count == 0)
            {
                GameObject buildingBlockGO = new GameObject();
                Selection.activeGameObject = buildingBlockGO;

                Camera mainCamera = PXR_Utils.GetMainCameraForXROrigin();
                buildingBlockGO.transform.position = mainCamera.transform.position;
                buildingBlockGO.transform.rotation = mainCamera.transform.rotation;

                GameObject ob = PrefabUtility.LoadPrefabContents(patialAudioAmbisonicsPath);
                Undo.RegisterCreatedObjectUndo(ob, "Create patialAudioAmbisonicsPath.");
                var activeScene = SceneManager.GetActiveScene();
                var rootObjects = activeScene.GetRootGameObjects();
                Undo.SetTransformParent(ob.transform, buildingBlockGO.transform, true, "Parent to ob.");
                ob.transform.localPosition = Vector3.forward;
                ob.transform.localRotation = Quaternion.identity;
                ob.transform.localScale = Vector3.one;
                ob.SetActive(true);

                buildingBlockGO.name = k_BuildingBlocksGOName;
                Undo.RegisterCreatedObjectUndo(buildingBlockGO, k_Id);

                PXR_Utils.SetTrackingOriginMode();
                EditorSceneManager.MarkSceneDirty(buildingBlockGO.scene);
                EditorSceneManager.SaveScene(buildingBlockGO.scene);
            }

            const string audioSettingsPath = "ProjectSettings/AudioManager.asset";
            var audioSettingsAsset = AssetDatabase.LoadAssetAtPath<Object>(audioSettingsPath);

            if (audioSettingsAsset == null)
            {
                Debug.LogError("Could not load audio settings asset.");
                return;
            }

            var serializedObject = new SerializedObject(audioSettingsAsset);
            var decoderProperty = serializedObject.FindProperty("m_AmbisonicDecoderPlugin");

            if (decoderProperty == null)
            {
                Debug.LogError("Could not find the Ambisonic Decoder Plugin property. Please manually set Project Settings => Audio => Ambisonic Decoder Plugin => Pico Ambisonic Decoder");
                return;
            }

            decoderProperty.stringValue = "Pico Ambisonic Decoder";
            serializedObject.ApplyModifiedProperties();

            Debug.Log("Ambisonic Decoder Plugin has been set to Pico Ambisonic Decoder.");
            AssetDatabase.SaveAssets();
        }

        public void ExecuteBuildingBlock() => DoInterestingStuff();

        // Each building block should have an accompanying MenuItem as a good practice, we add them here.
        [MenuItem(k_BuildingBlockPath, false, k_SectionPriority)]
        public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff();

        [MenuItem(PXR_Utils.BuildingBlockPathP + PXR_SpatialAudioSection.k_SectionId + "/" + k_Id, false, k_SectionPriority)]
        public static void ExecuteMenuItemHierarchy(MenuCommand command) => DoInterestingStuff();
    }

#endregion
#endif

#region Sense Pack

    [BuildingBlockItem(Priority = k_SectionPriority)]
    class PXR_SensePackSection : IBuildingBlockSection
    {
        public const string k_SectionId = "PICO Sense Pack";
        public string SectionId => k_SectionId;

        const string k_SectionIconPath = "Building/Block/Section/Icon/Path";
        public string SectionIconPath => k_SectionIconPath;
        const int k_SectionPriority = 6;

        readonly IBuildingBlock[] m_BBlocksElementIds = new IBuildingBlock[]
        {
            new PXR_BuildingBlocksSpatialAnchor(),
            new PXR_BuildingBlocksSpatialMesh(),
            new PXR_BuildingBlocksSceneCapture(),
        };

        public IEnumerable<IBuildingBlock> GetBuildingBlocks()
        {
            var elements = m_BBlocksElementIds.ToList();
            return elements;
        }
    }

    class PXR_BuildingBlocksSpatialAnchor : IBuildingBlock
    {
        const string k_Id = "PICO Spatial Anchor Sample";
        const string k_BuildingBlockPath = PXR_Utils.BuildingBlockPathO + PXR_SensePackSection.k_SectionId + "/" + k_Id;
        const string k_IconPath = "buildingblockIcon";
        const string k_Tooltip = k_Id + " : Video seethrought can be set up and enabled with one click.";
        const int k_SectionPriority = 15;

        static string k_BuildingBlocksCanvasGOName = $"{PXR_Utils.BuildingBlock} {k_Id} Manager";
        static string k_BuildingBlocksPreviewGOName = $"{PXR_Utils.BuildingBlock} {k_Id} Preview";
        static string spatialAnchorManagerPath = PXR_Utils.sdkPackageName + "BuildingBlocks/Prefabs/SpatialAnchorManager.prefab";
        static string spatialAnchorPreviewPath = PXR_Utils.sdkPackageName + "BuildingBlocks/Prefabs/SpatialAnchorPreview.prefab";

        static GameObject spatialAnchorPreviewGO;

        public string Id => k_Id;
        public string IconPath => k_IconPath;
        public bool IsEnabled => true;
        public string Tooltip => k_Tooltip;

        static void DoInterestingStuff()
        {
            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strBuildingBlocks, PXR_AppLog.strBuildingBlocks_PICOSpatialAnchorSample);

#if ENABLE_PICO_OPENXR_SDK
            PXR_Utils.EnableOpenXRFeature<PassthroughFeature>();
            PXR_Utils.EnableOpenXRFeature<PICOSpatialAnchor>();
#endif
            PXR_BuildingBlocksControllerTracking pXR_BuildingBlocksControllerTracking = new PXR_BuildingBlocksControllerTracking();
            pXR_BuildingBlocksControllerTracking.ExecuteBuildingBlock();
            // Get XROrigin
            GameObject cameraOrigin = PXR_Utils.CheckAndCreateXROrigin();

            if (!cameraOrigin.GetComponent<PXR_CameraEffectBlock>())
            {
                cameraOrigin.AddComponent<PXR_CameraEffectBlock>();
            }
            Camera mainCamera = PXR_Utils.GetMainCameraForXROrigin();
            mainCamera.clearFlags = CameraClearFlags.SolidColor;
            mainCamera.backgroundColor = new Color(0, 0, 0, 0);

            PXR_ProjectSetting.GetProjectConfig().videoSeeThrough = true;
            PXR_ProjectSetting.GetProjectConfig().spatialAnchor = true;
            PXR_ProjectSetting.SaveAssets();
            if (PXR_Utils.FindComponentsInScene<Transform>().Where(component => component.name == k_BuildingBlocksPreviewGOName).ToList().Count == 0)
            {
                Transform rightControllerTransform = cameraOrigin.transform.Find("Camera Offset").Find("Right Controller");

                spatialAnchorPreviewGO = PrefabUtility.LoadPrefabContents(spatialAnchorPreviewPath);
                Undo.RegisterCreatedObjectUndo(spatialAnchorPreviewGO, "Create spatialAnchorPreviewPath.");
                if (rightControllerTransform != null)
                {
                    Undo.SetTransformParent(spatialAnchorPreviewGO.transform, rightControllerTransform, true, "Parent to rightControllerTransform.");
                }
                spatialAnchorPreviewGO.transform.localPosition = Vector3.zero;
                spatialAnchorPreviewGO.transform.localRotation = Quaternion.identity;
                spatialAnchorPreviewGO.transform.localScale = Vector3.one;
                spatialAnchorPreviewGO.SetActive(false);
                spatialAnchorPreviewGO.name = k_BuildingBlocksPreviewGOName;
                Undo.RegisterCreatedObjectUndo(spatialAnchorPreviewGO, k_Id);
            }

            if (PXR_Utils.FindComponentsInScene<Transform>().Where(component => component.name == k_BuildingBlocksCanvasGOName).ToList().Count == 0)
            {
                GameObject spatialAnchorManagerGO = PrefabUtility.LoadPrefabContents(spatialAnchorManagerPath);
                Undo.RegisterCreatedObjectUndo(spatialAnchorManagerGO, "Create spatialAnchorManagerPath.");
                var activeScene = SceneManager.GetActiveScene();
                var rootObjects = activeScene.GetRootGameObjects();
                Undo.SetTransformParent(spatialAnchorManagerGO.transform, mainCamera.transform, true, "Parent to mainCamera.");
                spatialAnchorManagerGO.transform.localPosition = Vector3.zero + new Vector3(0, 0, 1);
                spatialAnchorManagerGO.transform.localRotation = Quaternion.identity;
                spatialAnchorManagerGO.transform.localScale = new Vector3(0.001f, 0.001f, 0.001f);
                spatialAnchorManagerGO.SetActive(true);
                spatialAnchorManagerGO.name = k_BuildingBlocksCanvasGOName;
                EditorSceneManager.SaveScene(spatialAnchorManagerGO.scene);

                PXRSample_SpatialAnchorManager spatialAnchorManager = spatialAnchorManagerGO.GetComponent<PXRSample_SpatialAnchorManager>();
                if (spatialAnchorManager == null)
                {
                    spatialAnchorManagerGO.AddComponent<PXRSample_SpatialAnchorManager>();
                }
                List<Transform> previewGOTransforms = PXR_Utils.FindComponentsInScene<Transform>().Where(component => component.name == k_BuildingBlocksPreviewGOName).ToList();
                if (previewGOTransforms.Count > 0)
                {
                    spatialAnchorManager.anchorPreview = previewGOTransforms[0].gameObject;
                }
                Undo.RegisterCreatedObjectUndo(spatialAnchorManagerGO, k_Id);
            }

            PXR_Utils.SetTrackingOriginMode();
            EditorSceneManager.SaveScene(cameraOrigin.gameObject.scene);
            PXR_Utils.DisableHDR();
        }

        public void ExecuteBuildingBlock() => DoInterestingStuff();

        // Each building block should have an accompanying MenuItem as a good practice, we add them here.
        [MenuItem(k_BuildingBlockPath, false, k_SectionPriority)]
        public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff();

        [MenuItem(PXR_Utils.BuildingBlockPathP + PXR_SensePackSection.k_SectionId + "/" + k_Id, false, k_SectionPriority)]
        public static void ExecuteMenuItemHierarchy(MenuCommand command) => DoInterestingStuff();
    }

    class PXR_BuildingBlocksSpatialMesh : IBuildingBlock
    {
        const string k_Id = "PICO Spatial Mesh";
        const string k_BuildingBlockPath = PXR_Utils.BuildingBlockPathO + PXR_SensePackSection.k_SectionId + "/" + k_Id;
        const string k_IconPath = "buildingblockIcon";
        const string k_Tooltip = k_Id + " : Video seethrought can be set up and enabled with one click.";
        const int k_SectionPriority = 16;

        static string k_BuildingBlocksGOName = $"{PXR_Utils.BuildingBlock} {k_Id}";
        static string meshPrefabPath = PXR_Utils.sdkPackageName + "BuildingBlocks/Prefabs/MeshPrefab.prefab";

        public string Id => k_Id;
        public string IconPath => k_IconPath;
        public bool IsEnabled => true;
        public string Tooltip => k_Tooltip;

        static void DoInterestingStuff()
        {
            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strBuildingBlocks, PXR_AppLog.strBuildingBlocks_PICOSpatialMesh);

#if ENABLE_PICO_OPENXR_SDK
            PXR_Utils.EnableOpenXRFeature<PassthroughFeature>();
            PXR_Utils.EnableOpenXRFeature<PICOSpatialMesh>();
#endif
            // Get XROrigin
            GameObject cameraOrigin = PXR_Utils.CheckAndCreateXROrigin();

            if (!cameraOrigin.GetComponent<PXR_CameraEffectBlock>())
            {
                cameraOrigin.AddComponent<PXR_CameraEffectBlock>();
            }
            Camera mainCamera = PXR_Utils.GetMainCameraForXROrigin();
            mainCamera.clearFlags = CameraClearFlags.SolidColor;
            mainCamera.backgroundColor = new Color(0, 0, 0, 0);

            PXR_ProjectSetting.GetProjectConfig().videoSeeThrough = true;
            PXR_ProjectSetting.GetProjectConfig().spatialMesh = true;
            PXR_ProjectSetting.GetProjectConfig().meshLod = PxrMeshLod.Low;
            PXR_ProjectSetting.SaveAssets();


            if (PXR_Utils.FindComponentsInScene<Transform>().Where(component => component.name == k_BuildingBlocksGOName).ToList().Count == 0)
            {
                GameObject buildingBlockGO = new GameObject();
                Selection.activeGameObject = buildingBlockGO;

                GameObject ob = PrefabUtility.LoadPrefabContents(meshPrefabPath);
                Undo.RegisterCreatedObjectUndo(ob, "Create meshPrefabPath.");
                var activeScene = SceneManager.GetActiveScene();
                var rootObjects = activeScene.GetRootGameObjects();
                Undo.SetTransformParent(ob.transform, buildingBlockGO.transform, true, "Parent to ob.");
                ob.transform.localPosition = Vector3.zero;
                ob.transform.localRotation = Quaternion.identity;
                ob.transform.localScale = Vector3.one;
                ob.SetActive(true);
                if (!buildingBlockGO.GetComponent<PXR_SpatialMeshManager>())
                {
                    buildingBlockGO.AddComponent<PXR_SpatialMeshManager>();
                }
                PXR_SpatialMeshManager spatialMeshManager = buildingBlockGO.GetComponent<PXR_SpatialMeshManager>();

                if (PXR_Settings.GetSettings().stereoRenderingModeAndroid == PXR_Settings.StereoRenderingModeAndroid.Multiview)
                {
                    Material skyboxMaterial = AssetDatabase.GetBuiltinExtraResource<Material>("Default-Skybox.mat");

                    if (skyboxMaterial == null)
                    {
                        Debug.LogWarning("Failed to load default skybox material");
                    }
                    ob.GetComponent<MeshRenderer>().material = skyboxMaterial;
                }
                spatialMeshManager.meshPrefab = ob;
                buildingBlockGO.name = k_BuildingBlocksGOName;
                Undo.RegisterCreatedObjectUndo(buildingBlockGO, k_Id);

                PXR_Utils.SetTrackingOriginMode();
                EditorSceneManager.MarkSceneDirty(buildingBlockGO.scene);
                EditorSceneManager.SaveScene(buildingBlockGO.scene);
                PXR_Utils.DisableHDR();
            }

            EditorSceneManager.SaveScene(cameraOrigin.gameObject.scene);
        }

        public void ExecuteBuildingBlock() => DoInterestingStuff();

        // Each building block should have an accompanying MenuItem as a good practice, we add them here.
        [MenuItem(k_BuildingBlockPath, false, k_SectionPriority)]
        public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff();

        [MenuItem(PXR_Utils.BuildingBlockPathP + PXR_SensePackSection.k_SectionId + "/" + k_Id, false, k_SectionPriority)]
        public static void ExecuteMenuItemHierarchy(MenuCommand command) => DoInterestingStuff();
    }

    class PXR_BuildingBlocksSceneCapture : IBuildingBlock
    {
        const string k_Id = "PICO Scene Capture";
        const string k_BuildingBlockPath = PXR_Utils.BuildingBlockPathO + PXR_SensePackSection.k_SectionId + "/" + k_Id;
        const string k_IconPath = "buildingblockIcon";
        const string k_Tooltip = k_Id + " : Video seethrought can be set up and enabled with one click.";
        const int k_SectionPriority = 17;

        static string k_BuildingBlocksGOName = $"{PXR_Utils.BuildingBlock} {k_Id}";
        static string meshPrefabPath = PXR_Utils.sdkPackageName + "BuildingBlocks/Prefabs/MeshPrefab.prefab";
        static string box2DPrefabPath = PXR_Utils.sdkPackageName + "Resources/Prefabs/Box2D.prefab";
        static string box3DPrefabPath = PXR_Utils.sdkPackageName + "Resources/Prefabs/Box3D.prefab";

        public string Id => k_Id;
        public string IconPath => k_IconPath;
        public bool IsEnabled => true;
        public string Tooltip => k_Tooltip;

        static void DoInterestingStuff()
        {
            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strBuildingBlocks, PXR_AppLog.strBuildingBlocks_PICOSceneCapture);

#if ENABLE_PICO_OPENXR_SDK
            PXR_Utils.EnableOpenXRFeature<PassthroughFeature>();
            PXR_Utils.EnableOpenXRFeature<PICOSceneCapture>();
#endif
            // Get XROrigin
            GameObject cameraOrigin = PXR_Utils.CheckAndCreateXROrigin();
            cameraOrigin.transform.localPosition = Vector3.zero;
            cameraOrigin.transform.localRotation = Quaternion.identity;
            cameraOrigin.transform.localScale = Vector3.one;
            if (!cameraOrigin.GetComponent<PXR_CameraEffectBlock>())
            {
                cameraOrigin.AddComponent<PXR_CameraEffectBlock>();
            }
            if (!cameraOrigin.GetComponent<PXR_SceneCaptureManager>())
            {
                cameraOrigin.AddComponent<PXR_SceneCaptureManager>();
            }

            PXR_SceneCaptureManager sceneCaptureManager = cameraOrigin.GetComponent<PXR_SceneCaptureManager>();
            if (sceneCaptureManager)
            {
                GameObject box2DGO = AssetDatabase.LoadAssetAtPath<GameObject>(box2DPrefabPath);
                if (box2DGO != null)
                {
                    sceneCaptureManager.box2DPrefab = box2DGO;
                }

                GameObject box3DGO = AssetDatabase.LoadAssetAtPath<GameObject>(box3DPrefabPath);
                if (box3DGO != null)
                {
                    sceneCaptureManager.box3DPrefab = box3DGO;
                }
            }

            Transform cameraOffset = cameraOrigin.transform.Find("Camera Offset");
            if (cameraOffset)
            {
                cameraOffset.transform.localPosition = Vector3.zero;
                cameraOffset.transform.localRotation = Quaternion.identity;
            }

            Camera mainCamera = PXR_Utils.GetMainCameraForXROrigin();
            mainCamera.clearFlags = CameraClearFlags.SolidColor;
            mainCamera.backgroundColor = new Color(0, 0, 0, 0);

            PXR_Utils.SetOneMainCameraInScene();
            PXR_ProjectSetting.GetProjectConfig().videoSeeThrough = true;
            PXR_ProjectSetting.GetProjectConfig().sceneCapture = true;
            PXR_ProjectSetting.SaveAssets();
            PXR_Utils.DisableHDR();

            EditorSceneManager.SaveScene(cameraOrigin.gameObject.scene);
        }

        public void ExecuteBuildingBlock() => DoInterestingStuff();

        // Each building block should have an accompanying MenuItem as a good practice, we add them here.
        [MenuItem(k_BuildingBlockPath, false, k_SectionPriority)]
        public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff();

        [MenuItem(PXR_Utils.BuildingBlockPathP + PXR_SensePackSection.k_SectionId + "/" + k_Id, false, k_SectionPriority)]
        public static void ExecuteMenuItemHierarchy(MenuCommand command) => DoInterestingStuff();
    }

#endregion

#region Compositor Layer

    [BuildingBlockItem(Priority = k_SectionPriority)]
    class PXR_CompositionLayerSection : IBuildingBlockSection
    {
        public const string k_SectionId = "PICO Composition Layer";
        public string SectionId => k_SectionId;

        const string k_SectionIconPath = "Building/Block/Section/Icon/Path";
        public string SectionIconPath => k_SectionIconPath;
        const int k_SectionPriority = 7;

        readonly IBuildingBlock[] m_BBlocksElementIds = new IBuildingBlock[]
        {
            new PXR_BuildingBlocksCompositionLayerOverlay(),
            new PXR_BuildingBlocksCompositionLayerUnderlay(),
        };

        public IEnumerable<IBuildingBlock> GetBuildingBlocks()
        {
            var elements = m_BBlocksElementIds.ToList();
            return elements;
        }
    }

    class PXR_BuildingBlocksCompositionLayerOverlay : IBuildingBlock
    {
        const string k_Id = "PICO Composition Layer Overlay";
        const string k_BuildingBlockPath = PXR_Utils.BuildingBlockPathO + PXR_CompositionLayerSection.k_SectionId + "/" + k_Id;
        const string k_IconPath = "buildingblockIcon";
        const string k_Tooltip = k_Id + " : Video seethrought can be set up and enabled with one click.";
        const int k_SectionPriority = 18;
        //static string xrOriginName = $"{PXR_Utils.BuildingBlock} {k_Id} XR Origin (XR Rig)";
        static string texturePath = PXR_Utils.sdkPackageName + "Resources/grid.jpg";

        static string k_BuildingBlocksGOName = $"{PXR_Utils.BuildingBlock} {k_Id}";

        public string Id => k_Id;
        public string IconPath => k_IconPath;
        public bool IsEnabled => true;
        public string Tooltip => k_Tooltip;

        static void DoInterestingStuff()
        {
            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strBuildingBlocks, PXR_AppLog.strBuildingBlocks_PICOCompositionLayerOverlay);
            // Get XROrigin
            GameObject cameraOrigin = PXR_Utils.CheckAndCreateXROrigin();

            PXR_ProjectSetting.SaveAssets();

            if (PXR_Utils.FindComponentsInScene<Transform>().Where(component => component.name == k_BuildingBlocksGOName).ToList().Count == 0)
            {
                GameObject buildingBlockGO = new GameObject();
                Selection.activeGameObject = buildingBlockGO;
                Camera mainCamera = PXR_Utils.GetMainCameraForXROrigin();
                buildingBlockGO.transform.position = mainCamera.transform.position + new Vector3(0, 0, 1.5f);
                buildingBlockGO.transform.rotation = mainCamera.transform.rotation;
                buildingBlockGO.transform.localScale = Vector3.one;

                GameObject overlayGO = new GameObject();
                PXR_CompositionLayer overlay = overlayGO.AddComponent<PXR_CompositionLayer>();
                overlay.overlayType = PXR_CompositionLayer.OverlayType.Overlay;
                overlay.textureType = PXR_CompositionLayer.TextureType.StaticTexture;
                overlay.overlayShape = PXR_CompositionLayer.OverlayShape.Quad;
                Texture loadedTexture = AssetDatabase.LoadAssetAtPath<Texture>(texturePath);

                if (loadedTexture != null)
                {
                    overlay.layerTextures[0] = loadedTexture;
                    overlay.layerTextures[1] = loadedTexture;
                }
                else
                {
                    Debug.LogError($"Failed to load texture, please check path: {texturePath}");
                }

                Undo.RegisterCreatedObjectUndo(buildingBlockGO, "Create Underlay.");
                Undo.SetTransformParent(overlayGO.transform, buildingBlockGO.transform, true, "Parent to buildingBlockGO.");
                overlayGO.transform.localPosition = Vector3.zero;
                overlayGO.transform.localRotation = Quaternion.identity;
                overlayGO.transform.localScale = Vector3.one;
                overlayGO.SetActive(true);
                overlayGO.name = "Overlay";

                buildingBlockGO.name = k_BuildingBlocksGOName;
#if ENABLE_PICO_OPENXR_SDK&&UNITY_OPENXR_1_16_0
                if (!PXR_Utils.HasCompositionLayerInScene())
                {
                    EditorApplication.ExecuteMenuItem("GameObject/XR/Composition Layers/PICO Composition Layer");
                }
#endif
                Undo.RegisterCreatedObjectUndo(buildingBlockGO, k_Id);

                PXR_Utils.SetOneMainCameraInScene();
                PXR_Utils.SetTrackingOriginMode();
                EditorSceneManager.MarkSceneDirty(buildingBlockGO.scene);
                EditorSceneManager.SaveScene(buildingBlockGO.scene);
            }

            EditorSceneManager.SaveScene(cameraOrigin.gameObject.scene);
        }

        public void ExecuteBuildingBlock() => DoInterestingStuff();

        // Each building block should have an accompanying MenuItem as a good practice, we add them here.
        [MenuItem(k_BuildingBlockPath, false, k_SectionPriority)]
        public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff();

        [MenuItem(PXR_Utils.BuildingBlockPathP + PXR_CompositionLayerSection.k_SectionId + "/" + k_Id, false, k_SectionPriority)]
        public static void ExecuteMenuItemHierarchy(MenuCommand command) => DoInterestingStuff();
    }

    class PXR_BuildingBlocksCompositionLayerUnderlay : IBuildingBlock
    {
        const string k_Id = "PICO Composition Layer Underlay";
        const string k_BuildingBlockPath = PXR_Utils.BuildingBlockPathO + PXR_CompositionLayerSection.k_SectionId + "/" + k_Id;
        const string k_IconPath = "buildingblockIcon";
        const string k_Tooltip = k_Id + " : Video seethrought can be set up and enabled with one click.";
        const int k_SectionPriority = 19;
        static string texturePath = PXR_Utils.sdkPackageName + "Resources/grid.jpg";
        static string materialPath = PXR_Utils.sdkPackageName + "Resources/Materials/UnderlayHole.mat";

        static string k_BuildingBlocksGOName = $"{PXR_Utils.BuildingBlock} {k_Id}";

        public string Id => k_Id;
        public string IconPath => k_IconPath;
        public bool IsEnabled => true;
        public string Tooltip => k_Tooltip;

        static void DoInterestingStuff()
        {
            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strBuildingBlocks, PXR_AppLog.strBuildingBlocks_PICOCompositionLayerUnderlay);
            // Get XROrigin
            GameObject cameraOrigin = PXR_Utils.CheckAndCreateXROrigin();

            if (PXR_Utils.FindComponentsInScene<Transform>().Where(component => component.name == k_BuildingBlocksGOName).ToList().Count == 0)
            {
                GameObject buildingBlockGO = new GameObject();
                Selection.activeGameObject = buildingBlockGO;
                Camera mainCamera = PXR_Utils.GetMainCameraForXROrigin();
                buildingBlockGO.transform.position = mainCamera.transform.position + new Vector3(0, 0, 2f);
                buildingBlockGO.transform.rotation = mainCamera.transform.rotation;
                buildingBlockGO.transform.localScale = Vector3.one;

                GameObject underlayHoleGO = new GameObject();
                MeshFilter meshFilter = underlayHoleGO.AddComponent<MeshFilter>();
                meshFilter.mesh = Resources.GetBuiltinResource<Mesh>("Quad.fbx");
                MeshRenderer meshRenderer = underlayHoleGO.AddComponent<MeshRenderer>();
                meshRenderer.material = AssetDatabase.LoadAssetAtPath<Material>(materialPath);
                Undo.RegisterCreatedObjectUndo(underlayHoleGO, "Create UnderlayHole.");
                Undo.SetTransformParent(underlayHoleGO.transform, buildingBlockGO.transform, true, "Parent to buildingBlockGO.");
                underlayHoleGO.transform.localPosition = Vector3.zero;
                underlayHoleGO.transform.localRotation = Quaternion.identity;
                underlayHoleGO.transform.localScale = Vector3.one;
                underlayHoleGO.SetActive(true);
                underlayHoleGO.name = "UnderlayHole";


                GameObject underlayGO = new GameObject();
                PXR_CompositionLayer overlay = underlayGO.AddComponent<PXR_CompositionLayer>();
                overlay.overlayType = PXR_CompositionLayer.OverlayType.Underlay;
                overlay.textureType = PXR_CompositionLayer.TextureType.StaticTexture;
                overlay.overlayShape = PXR_CompositionLayer.OverlayShape.Cylinder;
                Texture loadedTexture = AssetDatabase.LoadAssetAtPath<Texture>(texturePath);

                if (loadedTexture != null)
                {
                    overlay.layerTextures[0] = loadedTexture;
                    overlay.layerTextures[1] = loadedTexture;
                }
                else
                {
                    Debug.LogError($"Failed to load texture, please check path: {texturePath}");
                }

                Undo.RegisterCreatedObjectUndo(underlayHoleGO, "Create Underlay.");
                Undo.SetTransformParent(underlayGO.transform, underlayHoleGO.transform, true, "Parent to underlayHoleGO.");
                underlayGO.transform.localPosition = Vector3.zero;
                underlayGO.transform.localRotation = Quaternion.identity;
                underlayGO.transform.localScale = Vector3.one;
                underlayGO.SetActive(true);
                underlayGO.name = "Underlay";

                buildingBlockGO.name = k_BuildingBlocksGOName;
#if ENABLE_PICO_OPENXR_SDK&&UNITY_OPENXR_1_16_0
                if (!PXR_Utils.HasCompositionLayerInScene())
                {
                    EditorApplication.ExecuteMenuItem("GameObject/XR/Composition Layers/PICO Composition Layer");
                }
#endif
                Undo.RegisterCreatedObjectUndo(buildingBlockGO, k_Id);

                PXR_Utils.SetOneMainCameraInScene();
                PXR_Utils.SetTrackingOriginMode();
                EditorSceneManager.MarkSceneDirty(buildingBlockGO.scene);
                EditorSceneManager.SaveScene(buildingBlockGO.scene);
                PXR_Utils.DisableHDR();
            }

            EditorSceneManager.SaveScene(cameraOrigin.gameObject.scene);
        }

        public void ExecuteBuildingBlock() => DoInterestingStuff();

        // Each building block should have an accompanying MenuItem as a good practice, we add them here.
        [MenuItem(k_BuildingBlockPath, false, k_SectionPriority)]
        public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff();

        [MenuItem(PXR_Utils.BuildingBlockPathP + PXR_CompositionLayerSection.k_SectionId + "/" + k_Id, false, k_SectionPriority)]
        public static void ExecuteMenuItemHierarchy(MenuCommand command) => DoInterestingStuff();
    }
#endregion

#region Eye Gaze

[BuildingBlockItem(Priority = k_SectionPriority)]
class PXR_EyeGazeSection : IBuildingBlockSection
{
    public const string k_SectionId = "PICO Eye Gaze Interaction";
    public string SectionId => k_SectionId;

    const string k_SectionIconPath = "Building/Block/Section/Icon/Path";
    public string SectionIconPath => k_SectionIconPath;
    const int k_SectionPriority = 8;

    readonly IBuildingBlock[] m_BBlocksElementIds = new IBuildingBlock[]
    {
        new PXR_BuildingBlocksGazeInteractor(),
    };

    public IEnumerable<IBuildingBlock> GetBuildingBlocks()
    {
        var elements = m_BBlocksElementIds.ToList();
        return elements;
    }
}

class PXR_BuildingBlocksGazeInteractor : IBuildingBlock
{
    const string k_Id = "PICO Eye Gaze Interactor";
    const string k_BuildingBlockPath = PXR_Utils.BuildingBlockPathO + PXR_EyeGazeSection.k_SectionId + "/" + k_Id;
    const string k_IconPath = "buildingblockIcon";
    const string k_Tooltip = k_Id + " : PICO Eye Gaze Interactor can be set up and enabled with one click.";
    const int k_SectionPriority = 20;
    const string eyegazePosition = "<PXR_HMD>/eyeGazePosition";
    const string eyegazeRotation = "<PXR_HMD>/eyeGazeRotation";
    const string eyegazeIsTracked = "<PXR_HMD>/eyeGazeIsTracked";
    const string eyegazeTrackingState = "<PXR_HMD>/eyeGazeTrackingState";

    public string Id => k_Id;
    public string IconPath => k_IconPath;
    public bool IsEnabled => true;
    public string Tooltip => k_Tooltip;

    static void DoInterestingStuff()
    {
        PXR_AppLog.PXR_OnEvent(PXR_AppLog.strBuildingBlocks, PXR_AppLog.strBuildingBlocks_PICOGazeInteractor);


        var xriPackage =
            UnityEditor.PackageManager.PackageInfo.FindForAssembly(typeof(XRInteractionManager).Assembly);
        if (xriPackage != null)
        {
            PXR_Utils.xriVersion = xriPackage.version;
            Debug.Log($"XRI Toolkit version = {PXR_Utils.xriVersion}");
            var inputActionAsset =
                AssetDatabase.LoadAssetAtPath<InputActionAsset>(PXR_Utils.XRIDefaultInputActions);
            if (inputActionAsset == null)
            {
                // add Samples
                Debug.LogError(
                    $"Failed to load XRI Default Left Controller preset. Now load the {PXR_Utils.xriStarterAssetsSampleName} sample.");
                if (PXR_Utils.TryFindSample(PXR_Utils.xriPackageName, PXR_Utils.xriVersion,
                        PXR_Utils.xriStarterAssetsSampleName, out var sampleXRI))
                {
                    if (!Directory.Exists(sampleXRI.importPath))
                    {
                        sampleXRI.Import(Sample.ImportOptions.OverridePreviousImports);
                    }
                    inputActionAsset =
                        AssetDatabase.LoadAssetAtPath<InputActionAsset>(PXR_Utils.XRIDefaultInputActions);
                }
            }
#if XRI_TOOLKIT_3
            InputActionMap actionMapHead = inputActionAsset.FindActionMap("XRI Head");
#else
                    InputActionMap actionMapHead = inputActionAsset.FindActionMap("XRI Head");
#endif
            if (actionMapHead != null)
            {
                Debug.Log($"Found XRI Head Action Map: {actionMapHead}");
                InputAction eyegazePositionAction = actionMapHead.FindAction("Eye Gaze Position");
                if (eyegazePositionAction != null)
                {
                    bool eyegazePositionAdded = false;
                    foreach (var b in eyegazePositionAction.bindings)
                    {
                        if (eyegazePosition == b.path)
                        {
                            eyegazePositionAdded = true;
                        }
                    }

                    if (!eyegazePositionAdded)
                    {
                        Debug.Log($"{k_Id} {actionMapHead.name} {eyegazePositionAction.name} {eyegazePosition}");
                        
                        var existingBindings = new List<InputBinding>(eyegazePositionAction.bindings);
                        
                        for (int i = existingBindings.Count-1; i >=0; i--)
                        {
                            if (existingBindings[i].path.Contains("XRHMD")||existingBindings[i].path.Contains("PXR_HMD"))
                            {
                                eyegazePositionAction.ChangeBinding(i).Erase();
                            }
                        }
                        eyegazePositionAction.AddBinding(eyegazePosition);
                        for (int i = 0; i <existingBindings.Count; i++)
                        {
                            if (existingBindings[i].path.Contains("XRHMD")||existingBindings[i].path.Contains("PXR_HMD"))
                            {
                                eyegazePositionAction.AddBinding(existingBindings[i].path);
                            }
                        }
                    }
                    else
                    {
                        Debug.Log(
                            $"{k_Id} {actionMapHead.name} {eyegazePositionAction.name} {eyegazePosition} already added.");
                    }
                }

                InputAction eyegazeRotationAction = actionMapHead.FindAction("Eye Gaze Rotation");
                if (eyegazeRotationAction != null)
                {
                    bool eyegazeRotationAdded = false;
                    foreach (var b in eyegazeRotationAction.bindings)
                    {
                        if (eyegazeRotation == b.path)
                        {
                            eyegazeRotationAdded = true;
                        }
                    }

                    if (!eyegazeRotationAdded)
                    {
                        Debug.Log($"{k_Id} {actionMapHead.name} {eyegazeRotationAction.name} {eyegazeRotation}");
                        
                        var existingBindings = new List<InputBinding>(eyegazeRotationAction.bindings);
                        
                        for (int i = existingBindings.Count-1; i >=0; i--)
                        {
                            if (existingBindings[i].path.Contains("XRHMD")||existingBindings[i].path.Contains("PXR_HMD"))
                            {
                                eyegazeRotationAction.ChangeBinding(i).Erase();
                            }
                        }
                        eyegazeRotationAction.AddBinding(eyegazeRotation);
                        for (int i = 0; i <existingBindings.Count; i++)
                        {
                            if (existingBindings[i].path.Contains("XRHMD")||existingBindings[i].path.Contains("PXR_HMD"))
                            {
                                eyegazeRotationAction.AddBinding(existingBindings[i].path);
                            }
                        }
                        
                    }
                    else
                    {
                        Debug.Log(
                            $"{k_Id} {actionMapHead.name} {eyegazeRotationAction.name} {eyegazePosition} already added.");
                    }
                }

                InputAction eyegazeIsTrackedAction = actionMapHead.FindAction("Eye Gaze Is Tracked");
                if (eyegazeIsTrackedAction != null)
                {
                    bool eyegazeIsTrackedAdded = false;
                    foreach (var b in eyegazeIsTrackedAction.bindings)
                    {
                        if (eyegazeIsTracked == b.path)
                        {
                            eyegazeIsTrackedAdded = true;
                        }
                    }

                    if (!eyegazeIsTrackedAdded)
                    {
                        Debug.Log($"{k_Id} {actionMapHead.name} {eyegazeIsTrackedAction.name} {eyegazeIsTracked}");
                        var existingBindings = new List<InputBinding>(eyegazeIsTrackedAction.bindings);
                        
                        for (int i = existingBindings.Count-1; i >=0; i--)
                        {
                            if (existingBindings[i].path.Contains("XRHMD")||existingBindings[i].path.Contains("PXR_HMD"))
                            {
                                eyegazeIsTrackedAction.ChangeBinding(i).Erase();
                            }
                        }
                        eyegazeIsTrackedAction.AddBinding(eyegazeIsTracked);
                        for (int i = 0; i <existingBindings.Count; i++)
                        {
                            if (existingBindings[i].path.Contains("XRHMD")||existingBindings[i].path.Contains("PXR_HMD"))
                            {
                                eyegazeIsTrackedAction.AddBinding(existingBindings[i].path);
                            }
                        }
                    }
                    else
                    {
                        Debug.Log(
                            $"{k_Id} {actionMapHead.name} {eyegazeIsTrackedAction.name} {eyegazeIsTracked} already added.");
                    }
                }

                InputAction eyegazeTrackingStateAction = actionMapHead.FindAction("Eye Gaze Tracking State");
                if (eyegazeTrackingStateAction != null)
                {
                    bool eyegazeTrackingStateAdded = false;
                    foreach (var b in eyegazeTrackingStateAction.bindings)
                    {
                        if (eyegazeTrackingState == b.path)
                        {
                            eyegazeTrackingStateAdded = true;
                        }
                    }

                    if (!eyegazeTrackingStateAdded)
                    {
                        Debug.Log(
                            $"{k_Id} {actionMapHead.name} {eyegazeTrackingStateAction.name} {eyegazeTrackingState}");
                        
                        var existingBindings = new List<InputBinding>(eyegazeTrackingStateAction.bindings);
                        
                        for (int i = existingBindings.Count-1; i >=0; i--)
                        {
                            if (existingBindings[i].path.Contains("XRHMD")||existingBindings[i].path.Contains("PXR_HMD"))
                            {
                                eyegazeTrackingStateAction.ChangeBinding(i).Erase();
                            }
                        }
                        eyegazeTrackingStateAction.AddBinding(eyegazeTrackingState);
                        for (int i = 0; i <existingBindings.Count; i++)
                        {
                            if (existingBindings[i].path.Contains("XRHMD")||existingBindings[i].path.Contains("PXR_HMD"))
                            {
                                eyegazeTrackingStateAction.AddBinding(existingBindings[i].path);
                            }
                        }
                    }
                    else
                    {
                        Debug.Log(
                            $"{k_Id} {actionMapHead.name} {eyegazeTrackingStateAction.name} {eyegazeTrackingState} already added.");
                    }
                }
            }
            EditorUtility.SetDirty(inputActionAsset);
            AssetDatabase.SaveAssets();
        }
    }

    public void ExecuteBuildingBlock() => DoInterestingStuff();

    // Each building block should have an accompanying MenuItem as a good practice, we add them here.
    [MenuItem(k_BuildingBlockPath, false, k_SectionPriority)]
    public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff();

    [MenuItem(PXR_Utils.BuildingBlockPathP + PXR_EyeGazeSection.k_SectionId + "/" + k_Id, false, k_SectionPriority)]
    public static void ExecuteMenuItemHierarchy(MenuCommand command) => DoInterestingStuff();
}

    #endregion


    #region Camera Pack

    [BuildingBlockItem(Priority = k_SectionPriority)]
class PXR_CameraPackSection : IBuildingBlockSection
{
    public const string k_SectionId = "PICO Camera Pack";
    public string SectionId => k_SectionId;

    const string k_SectionIconPath = "Building/Block/Section/Icon/Path";
    public string SectionIconPath => k_SectionIconPath;
    const int k_SectionPriority = 10;

    readonly IBuildingBlock[] m_BBlocksElementIds = new IBuildingBlock[]
    {
        new PXR_BuildingBlocksAddCameraPack(),
        new PXR_BuildingBlocksAddCameraPackVisualizer(),
        new PXR_BuildingBlocksAddStereoCameraPackVisualizer(),
        new PXR_BuildingBlocksAddStereoTimestampMatchedCameraPackVisualizer(),
    };

    public IEnumerable<IBuildingBlock> GetBuildingBlocks()
    {
        var elements = m_BBlocksElementIds.ToList();
        return elements;
    }
}

class PXR_BuildingBlocksAddCameraPack : IBuildingBlock
{
    const string k_Id = "Add PICO Camera Pack Prefab";
    const string k_BuildingBlockPath = PXR_Utils.BuildingBlockPathO + PXR_CameraPackSection.k_SectionId + "/" + k_Id;
    const string k_IconPath = "buildingblockIcon";
    const string k_Tooltip = k_Id + " :PICO Camera Pack Prefab can be set up and enabled with one click.";
    const int k_SectionPriority = 22;

    public string Id => k_Id;
    public string IconPath => k_IconPath;
    public bool IsEnabled => true;
    public string Tooltip => k_Tooltip;
    static string cameraPackPrefabPath = PXR_Utils.sdkPackageName + "CameraPack/Prefabs/PXRCamTextureManager.prefab";
    static string cameraPackName = $"{PXR_Utils.BuildingBlock} PICO Camera Pack PXRCamTextureManager";
    static string xrOriginName = $"{PXR_Utils.BuildingBlock} PICO Camera Pack XR Origin (XR Rig)";

    static void DoInterestingStuff()
    {
        PXR_AppLog.PXR_OnEvent(PXR_AppLog.strBuildingBlocks, PXR_AppLog.strBuildingBlocks_PICOCameraPack);
        
        // Get XROrigin
        GameObject cameraOrigin = PXR_Utils.CheckAndCreateXROrigin();
        if (cameraOrigin != null)
        {
            var origin = cameraOrigin.GetComponent<XROrigin>();
            if (origin != null)
            {
                origin.RequestedTrackingOriginMode = XROrigin.TrackingOriginMode.Floor;
                Undo.RecordObject(origin, "Set Tracking Origin Mode");
            }
        }
        List<Transform> cameraPackList = PXR_Utils.FindComponentsInScene<Transform>()
        .Where(component => component.transform.name == cameraPackName).ToList();
        if (cameraPackList.Count == 0)
        {
            GameObject cameraPack = PrefabUtility.LoadPrefabContents(cameraPackPrefabPath);
            if (cameraPack != null)
            {
                Undo.SetTransformParent(cameraPack.transform, cameraOrigin.transform, true, "Parent to scene.");
                cameraPack.transform.localPosition = Vector3.zero;
                cameraPack.transform.localRotation = Quaternion.identity;
                cameraPack.transform.localScale = Vector3.one;
                cameraPack.SetActive(true);
                cameraPack.name = cameraPackName;
                cameraPack.transform.SetParent(null);
            }
        }

        cameraOrigin.name = xrOriginName;
        
        EditorSceneManager.MarkSceneDirty(cameraOrigin.scene);
        EditorSceneManager.SaveScene(cameraOrigin.scene);
    }

    public void ExecuteBuildingBlock() => DoInterestingStuff();

    // Each building block should have an accompanying MenuItem as a good practice, we add them here.
    [MenuItem(k_BuildingBlockPath, false, k_SectionPriority)]
    public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff();

    [MenuItem(PXR_Utils.BuildingBlockPathP + PXR_CameraPackSection.k_SectionId + "/" + k_Id, false, k_SectionPriority)]
    public static void ExecuteMenuItemHierarchy(MenuCommand command) => DoInterestingStuff();
}

class PXR_BuildingBlocksAddCameraPackVisualizer : IBuildingBlock
{
    const string k_Id = "Camera Pack Visualizer";
    const string k_BuildingBlockPath = PXR_Utils.BuildingBlockPathO + PXR_CameraPackSection.k_SectionId + "/" + k_Id;
    const string k_IconPath = "buildingblockIcon";
    const string k_Tooltip = k_Id + " : Add Camera Pack Visualizer and link to Camera Pack.";
    const int k_SectionPriority = 23;

    public string Id => k_Id;
    public string IconPath => k_IconPath;
    public bool IsEnabled => true;
    public string Tooltip => k_Tooltip;

    // Use package-relative path.
    static string visualizerPrefabPath = PXR_Utils.sdkPackageName + "BuildingBlocks/Prefabs/CameraPackVisualizer.prefab";
    static string visualizerName = $"{PXR_Utils.BuildingBlock} PICO Camera Pack Visualizer";

    public void ExecuteBuildingBlock() => DoInterestingStuff();

    [MenuItem(k_BuildingBlockPath, false, k_SectionPriority)]
    public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff();
    
    [MenuItem(PXR_Utils.BuildingBlockPathP + PXR_CameraPackSection.k_SectionId + "/" + k_Id, false, k_SectionPriority)]
    public static void ExecuteMenuItemHierarchy(MenuCommand command) => DoInterestingStuff();

    static void DoInterestingStuff()
    {
        // 1. Execute PXR_BuildingBlocksAddCameraPack
        PXR_BuildingBlocksAddCameraPack.ExecuteMenuItem(null);

        // 2. Create Visualizer
        GameObject xrOrigin = PXR_Utils.CheckAndCreateXROrigin();
        if (xrOrigin != null)
        {
            var origin = xrOrigin.GetComponent<XROrigin>();
            if (origin != null)
            {
                origin.RequestedTrackingOriginMode = XROrigin.TrackingOriginMode.Floor;
                Undo.RecordObject(origin, "Set Tracking Origin Mode");
            }
        }
        
        GameObject visualizerInstance = PrefabUtility.LoadPrefabContents(visualizerPrefabPath);
        if (visualizerInstance != null)
        {
            visualizerInstance.name = visualizerName;
            Undo.RegisterCreatedObjectUndo(visualizerInstance, "Create Visualizer");
            
            // Move to scene by parenting to XROrigin
            if (xrOrigin != null)
            {
                Undo.SetTransformParent(visualizerInstance.transform, xrOrigin.transform, true, "Parent to scene");
                visualizerInstance.transform.position = xrOrigin.transform.position + xrOrigin.transform.forward * 1.5f + xrOrigin.transform.up;
                visualizerInstance.transform.rotation = xrOrigin.transform.rotation;
            }
            else
            {
                // Fallback if XROrigin is missing (though CheckAndCreateXROrigin should handle it)
                visualizerInstance.transform.position = Vector3.forward * 1.5f + Vector3.up;
                visualizerInstance.transform.rotation = Quaternion.identity;
            }
            
            
            visualizerInstance.SetActive(true);
            Selection.activeGameObject = visualizerInstance;
            
            // Unparent to make it a root object (or keep it under XROrigin if desired, but following CameraPack pattern we unparent)
            // visualizerInstance.transform.SetParent(null); // Optional, based on user preference or consistency.
            // Keeping it under XROrigin is safer for "rig" movement, but if we want "normal GameObject in scene" at root:
            visualizerInstance.transform.SetParent(null);
        }
        else
        {
            Debug.LogError("Could not load visualizer prefab at " + visualizerPrefabPath);
            return;
        }

        // 4. Create Unlit/Texture material
        Material newMat = new Material(Shader.Find("Unlit/Texture"));
        newMat.name = "CameraPackVisualizerMaterial";
        
        // 5. Assign to created prefab
        MeshRenderer renderer = visualizerInstance.GetComponent<MeshRenderer>();
        if (renderer != null)
        {
            Undo.RecordObject(renderer, "Assign Material");
            renderer.material = newMat;
        }

        // 6. Assign to PXR_CamTextureManager.TargetMaterial
        // Use reflection to avoid direct dependency and cyclic reference
        var camPackAssembly = System.AppDomain.CurrentDomain.GetAssemblies()
            .FirstOrDefault(assembly => assembly.GetName().Name == "ByteDance.PICO.CameraPack");

        if (camPackAssembly != null)
        {
            var managerType = camPackAssembly.GetType("ByteDance.PICO.CameraPack.PXR_CamTextureManager");
            if (managerType != null)
            {
                var camManager = Object.FindObjectOfType(managerType);
                if (camManager != null)
                {
                    Undo.RecordObject(camManager, "Assign Target Material");
                    var field = managerType.GetField("TargetMaterial");
                    if (field != null)
                    {
                        field.SetValue(camManager, newMat);
                    }
                    else
                    {
                        Debug.LogError("TargetMaterial field not found on PXR_CamTextureManager.");
                    }
                }
                else
                {
                    Debug.LogError("PXR_CamTextureManager not found in scene.");
                }
            }
        }
        
        if (xrOrigin != null)
        {
            EditorSceneManager.MarkSceneDirty(xrOrigin.scene);
        }
    }
}

class PXR_BuildingBlocksAddStereoCameraPackVisualizer : IBuildingBlock
{
    const string k_Id = "Stereo Camera Pack Visualizer";
    const string k_BuildingBlockPath = PXR_Utils.BuildingBlockPathO + PXR_CameraPackSection.k_SectionId + "/" + k_Id;
    const string k_IconPath = "buildingblockIcon";
    const string k_Tooltip = k_Id + " : Add left and right Camera Pack visualizers and link them to separate Camera Pack managers.";
    const int k_SectionPriority = 24;

    public string Id => k_Id;
    public string IconPath => k_IconPath;
    public bool IsEnabled => true;
    public string Tooltip => k_Tooltip;

    static string cameraPackPrefabPath = PXR_Utils.sdkPackageName + "CameraPack/Prefabs/PXRCamTextureManager.prefab";
    static string visualizerPrefabPath = PXR_Utils.sdkPackageName + "BuildingBlocks/Prefabs/CameraPackVisualizer.prefab";
    static string xrOriginName = $"{PXR_Utils.BuildingBlock} Stereo Camera Pack XR Origin (XR Rig)";
    static string leftCameraPackName = $"{PXR_Utils.BuildingBlock} PICO Camera Pack PXRCamTextureManager Left";
    static string rightCameraPackName = $"{PXR_Utils.BuildingBlock} PICO Camera Pack PXRCamTextureManager Right";
    static string leftVisualizerName = $"{PXR_Utils.BuildingBlock} PICO Camera Pack Visualizer Left";
    static string rightVisualizerName = $"{PXR_Utils.BuildingBlock} PICO Camera Pack Visualizer Right";

    public void ExecuteBuildingBlock() => DoInterestingStuff();

    [MenuItem(k_BuildingBlockPath, false, k_SectionPriority)]
    public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff();

    [MenuItem(PXR_Utils.BuildingBlockPathP + PXR_CameraPackSection.k_SectionId + "/" + k_Id, false, k_SectionPriority)]
    public static void ExecuteMenuItemHierarchy(MenuCommand command) => DoInterestingStuff();

    static void DoInterestingStuff()
    {
        PXR_AppLog.PXR_OnEvent(PXR_AppLog.strBuildingBlocks, PXR_AppLog.strBuildingBlocks_PICOCameraPack);

        GameObject xrOrigin = PXR_Utils.CheckAndCreateXROrigin();
        if (xrOrigin == null)
        {
            Debug.LogError("Could not create or find XR Origin for Stereo Camera Pack Visualizer.");
            return;
        }

        SetFloorTrackingOrigin(xrOrigin);

        Material leftMaterial = CreateVisualizerMaterial("CameraPackVisualizerMaterialLeft");
        Material rightMaterial = CreateVisualizerMaterial("CameraPackVisualizerMaterialRight");

        GameObject leftManager = FindOrCreateCameraPackManager(leftCameraPackName, xrOrigin);
        GameObject rightManager = FindOrCreateCameraPackManager(rightCameraPackName, xrOrigin);
        if (leftManager == null || rightManager == null)
        {
            return;
        }

        ConfigureCameraPackManager(leftManager, "Left", leftMaterial);
        ConfigureCameraPackManager(rightManager, "Right", rightMaterial);

        GameObject leftVisualizer = FindOrCreateVisualizer(leftVisualizerName, leftManager.transform, new Vector3(-0.75f, 1.0f, 1.5f), leftMaterial);
        GameObject rightVisualizer = FindOrCreateVisualizer(rightVisualizerName, rightManager.transform, new Vector3(0.75f, 1.0f, 1.5f), rightMaterial);

        if (rightVisualizer != null)
        {
            Selection.activeGameObject = rightVisualizer;
        }
        else if (leftVisualizer != null)
        {
            Selection.activeGameObject = leftVisualizer;
        }

        xrOrigin.name = xrOriginName;
        EditorSceneManager.MarkSceneDirty(xrOrigin.scene);
        EditorSceneManager.SaveScene(xrOrigin.scene);
    }

    static void SetFloorTrackingOrigin(GameObject xrOrigin)
    {
        var origin = xrOrigin.GetComponent<XROrigin>();
        if (origin == null)
        {
            return;
        }

        Undo.RecordObject(origin, "Set Tracking Origin Mode");
        origin.RequestedTrackingOriginMode = XROrigin.TrackingOriginMode.Floor;
    }

    static GameObject FindOrCreateCameraPackManager(string cameraPackName, GameObject xrOrigin)
    {
        Transform existingManager = PXR_Utils.FindComponentsInScene<Transform>()
            .FirstOrDefault(component => component.transform.name == cameraPackName);
        if (existingManager != null)
        {
            existingManager.gameObject.SetActive(true);
            return existingManager.gameObject;
        }

        GameObject cameraPack = PrefabUtility.LoadPrefabContents(cameraPackPrefabPath);
        if (cameraPack == null)
        {
            Debug.LogError("Could not load camera pack prefab at " + cameraPackPrefabPath);
            return null;
        }

        Undo.RegisterCreatedObjectUndo(cameraPack, "Create Camera Pack Manager");
        Undo.SetTransformParent(cameraPack.transform, xrOrigin.transform, true, "Parent to XR Origin");
        cameraPack.transform.localPosition = Vector3.zero;
        cameraPack.transform.localRotation = Quaternion.identity;
        cameraPack.transform.localScale = Vector3.one;
        cameraPack.SetActive(true);
        cameraPack.name = cameraPackName;
        cameraPack.transform.SetParent(null);
        return cameraPack;
    }

    static GameObject FindOrCreateVisualizer(string visualizerName, Transform parent, Vector3 localPosition, Material material)
    {
        Transform existingVisualizer = PXR_Utils.FindComponentsInScene<Transform>()
            .FirstOrDefault(component => component.transform.name == visualizerName);
        GameObject visualizer = existingVisualizer != null
            ? existingVisualizer.gameObject
            : PrefabUtility.LoadPrefabContents(visualizerPrefabPath);

        if (visualizer == null)
        {
            Debug.LogError("Could not load visualizer prefab at " + visualizerPrefabPath);
            return null;
        }

        if (existingVisualizer == null)
        {
            Undo.RegisterCreatedObjectUndo(visualizer, "Create Camera Pack Visualizer");
        }

        visualizer.name = visualizerName;
        Undo.SetTransformParent(visualizer.transform, parent, false, "Parent to Camera Pack Manager");
        visualizer.transform.localPosition = localPosition;
        visualizer.transform.localRotation = Quaternion.identity;
        visualizer.SetActive(true);

        MeshRenderer renderer = visualizer.GetComponent<MeshRenderer>();
        if (renderer != null)
        {
            Undo.RecordObject(renderer, "Assign Material");
            renderer.material = material;
        }

        return visualizer;
    }

    static Material CreateVisualizerMaterial(string materialName)
    {
        Material material = new Material(Shader.Find("Unlit/Texture"));
        material.name = materialName;
        return material;
    }

    static void ConfigureCameraPackManager(GameObject cameraPackManager, string eyeName, Material targetMaterial)
    {
        var camPackAssembly = System.AppDomain.CurrentDomain.GetAssemblies()
            .FirstOrDefault(assembly => assembly.GetName().Name == "ByteDance.PICO.CameraPack");

        if (camPackAssembly == null)
        {
            Debug.LogError("ByteDance.PICO.CameraPack assembly not found.");
            return;
        }

        var managerType = camPackAssembly.GetType("ByteDance.PICO.CameraPack.PXR_CamTextureManager");
        if (managerType == null)
        {
            Debug.LogError("PXR_CamTextureManager type not found.");
            return;
        }

        var camManager = cameraPackManager.GetComponent(managerType);
        if (camManager == null)
        {
            camManager = cameraPackManager.GetComponentInChildren(managerType, true);
        }

        if (camManager == null)
        {
            Debug.LogError("PXR_CamTextureManager not found on " + cameraPackManager.name + ".");
            return;
        }

        Undo.RecordObject(camManager, "Configure Camera Pack Manager");

        var eyeField = managerType.GetField("Eye");
        if (eyeField != null)
        {
            eyeField.SetValue(camManager, System.Enum.Parse(eyeField.FieldType, eyeName));
        }
        else
        {
            Debug.LogError("Eye field not found on PXR_CamTextureManager.");
        }

        var targetMaterialField = managerType.GetField("TargetMaterial");
        if (targetMaterialField != null)
        {
            targetMaterialField.SetValue(camManager, targetMaterial);
        }
        else
        {
            Debug.LogError("TargetMaterial field not found on PXR_CamTextureManager.");
        }
    }
}

class PXR_BuildingBlocksAddStereoTimestampMatchedCameraPackVisualizer : IBuildingBlock
{
    const string k_Id = "Stereo Timestamp Matched Camera Pack Visualizer";
    const string k_BuildingBlockPath = PXR_Utils.BuildingBlockPathO + PXR_CameraPackSection.k_SectionId + "/" + k_Id;
    const string k_IconPath = "buildingblockIcon";
    const string k_Tooltip = k_Id + " : Match left and right camera frames by timestamp, stitch matched frames, and display frame statistics.";
    const int k_SectionPriority = 25;

    public string Id => k_Id;
    public string IconPath => k_IconPath;
    public bool IsEnabled => true;
    public string Tooltip => k_Tooltip;

    static string cameraPackPrefabPath = PXR_Utils.sdkPackageName + "CameraPack/Prefabs/PXRCamTextureManager.prefab";
    static string visualizerPrefabPath = PXR_Utils.sdkPackageName + "BuildingBlocks/Prefabs/CameraPackVisualizer.prefab";
    static string xrOriginName = $"{PXR_Utils.BuildingBlock} Stereo Timestamp Matched Camera Pack XR Origin (XR Rig)";
    static string leftCameraPackName = $"{PXR_Utils.BuildingBlock} PICO Camera Pack Timestamp Matched PXRCamTextureManager Left";
    static string rightCameraPackName = $"{PXR_Utils.BuildingBlock} PICO Camera Pack Timestamp Matched PXRCamTextureManager Right";
    static string matcherName = $"{PXR_Utils.BuildingBlock} PICO Camera Pack Timestamp Matched Matcher";
    static string visualizerName = $"{PXR_Utils.BuildingBlock} PICO Camera Pack Timestamp Matched Visualizer";
    static string statsName = $"{PXR_Utils.BuildingBlock} PICO Camera Pack Timestamp Matched Stats";

    public void ExecuteBuildingBlock() => DoInterestingStuff();

    [MenuItem(k_BuildingBlockPath, false, k_SectionPriority)]
    public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff();

    [MenuItem(PXR_Utils.BuildingBlockPathP + PXR_CameraPackSection.k_SectionId + "/" + k_Id, false, k_SectionPriority)]
    public static void ExecuteMenuItemHierarchy(MenuCommand command) => DoInterestingStuff();

    static void DoInterestingStuff()
    {
        PXR_AppLog.PXR_OnEvent(PXR_AppLog.strBuildingBlocks, PXR_AppLog.strBuildingBlocks_PICOCameraPack);

        GameObject xrOrigin = PXR_Utils.CheckAndCreateXROrigin();
        if (xrOrigin == null)
        {
            Debug.LogError("Could not create or find XR Origin for Stereo Timestamp Matched Camera Pack Visualizer.");
            return;
        }

        SetFloorTrackingOrigin(xrOrigin);

        Material targetMaterial = CreateVisualizerMaterial("CameraPackTimestampMatchedVisualizerMaterial");
        GameObject leftManager = FindOrCreateCameraPackManager(leftCameraPackName, xrOrigin);
        GameObject rightManager = FindOrCreateCameraPackManager(rightCameraPackName, xrOrigin);
        if (leftManager == null || rightManager == null)
        {
            return;
        }

        ConfigureCameraPackManager(leftManager, "Left", null);
        ConfigureCameraPackManager(rightManager, "Right", null);

        GameObject matcherGO = FindOrCreateRootObject(matcherName, xrOrigin.transform.position + xrOrigin.transform.forward * 1.5f + xrOrigin.transform.up, xrOrigin.transform.rotation);
        GameObject visualizerGO = FindOrCreateVisualizer(visualizerName, matcherGO.transform, targetMaterial);
        Text statsText = FindOrCreateStatsText(statsName, matcherGO.transform);
        ConfigureMatcher(matcherGO, leftManager, rightManager, targetMaterial, statsText);

        if (visualizerGO != null)
        {
            Selection.activeGameObject = visualizerGO;
        }
        else
        {
            Selection.activeGameObject = matcherGO;
        }

        xrOrigin.name = xrOriginName;
        EditorSceneManager.MarkSceneDirty(xrOrigin.scene);
        EditorSceneManager.SaveScene(xrOrigin.scene);
    }

    static void SetFloorTrackingOrigin(GameObject xrOrigin)
    {
        var origin = xrOrigin.GetComponent<XROrigin>();
        if (origin == null)
        {
            return;
        }

        Undo.RecordObject(origin, "Set Tracking Origin Mode");
        origin.RequestedTrackingOriginMode = XROrigin.TrackingOriginMode.Floor;
    }

    static GameObject FindOrCreateRootObject(string objectName, Vector3 position, Quaternion rotation)
    {
        Transform existingRoot = PXR_Utils.FindComponentsInScene<Transform>()
            .FirstOrDefault(component => component.transform.name == objectName);
        if (existingRoot != null)
        {
            existingRoot.gameObject.SetActive(true);
            existingRoot.position = position;
            existingRoot.rotation = rotation;
            return existingRoot.gameObject;
        }

        GameObject root = new GameObject(objectName);
        Undo.RegisterCreatedObjectUndo(root, "Create Timestamp Matched Camera Pack Root");
        root.transform.position = position;
        root.transform.rotation = rotation;
        root.transform.localScale = Vector3.one;
        return root;
    }

    static GameObject FindOrCreateCameraPackManager(string cameraPackName, GameObject xrOrigin)
    {
        Transform existingManager = PXR_Utils.FindComponentsInScene<Transform>()
            .FirstOrDefault(component => component.transform.name == cameraPackName);
        if (existingManager != null)
        {
            existingManager.gameObject.SetActive(true);
            return existingManager.gameObject;
        }

        GameObject cameraPack = PrefabUtility.LoadPrefabContents(cameraPackPrefabPath);
        if (cameraPack == null)
        {
            Debug.LogError("Could not load camera pack prefab at " + cameraPackPrefabPath);
            return null;
        }

        Undo.RegisterCreatedObjectUndo(cameraPack, "Create Camera Pack Manager");
        Undo.SetTransformParent(cameraPack.transform, xrOrigin.transform, true, "Parent to XR Origin");
        cameraPack.transform.localPosition = Vector3.zero;
        cameraPack.transform.localRotation = Quaternion.identity;
        cameraPack.transform.localScale = Vector3.one;
        cameraPack.SetActive(true);
        cameraPack.name = cameraPackName;
        cameraPack.transform.SetParent(null);
        return cameraPack;
    }

    static GameObject FindOrCreateVisualizer(string objectName, Transform parent, Material material)
    {
        Transform existingVisualizer = PXR_Utils.FindComponentsInScene<Transform>()
            .FirstOrDefault(component => component.transform.name == objectName);
        GameObject visualizer = existingVisualizer != null
            ? existingVisualizer.gameObject
            : PrefabUtility.LoadPrefabContents(visualizerPrefabPath);

        if (visualizer == null)
        {
            Debug.LogError("Could not load visualizer prefab at " + visualizerPrefabPath);
            return null;
        }

        if (existingVisualizer == null)
        {
            Undo.RegisterCreatedObjectUndo(visualizer, "Create Timestamp Matched Camera Pack Visualizer");
        }

        visualizer.name = objectName;
        Undo.SetTransformParent(visualizer.transform, parent, false, "Parent to Timestamp Matched Camera Pack Root");
        visualizer.transform.localPosition = Vector3.zero;
        visualizer.transform.localRotation = Quaternion.identity;
        visualizer.transform.localScale = new Vector3(2.666f, 1f, 1f);
        visualizer.SetActive(true);

        MeshRenderer renderer = visualizer.GetComponent<MeshRenderer>();
        if (renderer != null)
        {
            Undo.RecordObject(renderer, "Assign Material");
            renderer.material = material;
        }

        return visualizer;
    }

    static Text FindOrCreateStatsText(string objectName, Transform parent)
    {
        Transform existingStats = PXR_Utils.FindComponentsInScene<Transform>()
            .FirstOrDefault(component => component.transform.name == objectName);
        if (existingStats != null)
        {
            existingStats.gameObject.SetActive(true);
            return EnsureStatsText(existingStats.gameObject);
        }

        GameObject canvasGO = new GameObject(objectName, typeof(RectTransform), typeof(Canvas), typeof(CanvasScaler), typeof(GraphicRaycaster));
        Undo.RegisterCreatedObjectUndo(canvasGO, "Create Camera Pack Stats Canvas");
        Undo.SetTransformParent(canvasGO.transform, parent, false, "Parent to Timestamp Matched Camera Pack Root");
        canvasGO.transform.localPosition = new Vector3(0f, -0.75f, 0f);
        canvasGO.transform.localRotation = Quaternion.identity;
        canvasGO.transform.localScale = Vector3.one * 0.002f;

        Canvas canvas = canvasGO.GetComponent<Canvas>();
        canvas.renderMode = RenderMode.WorldSpace;
        canvas.worldCamera = PXR_Utils.GetMainCameraForXROrigin();

        RectTransform canvasRect = canvasGO.GetComponent<RectTransform>();
        canvasRect.sizeDelta = new Vector2(1200f, 360f);

        GameObject textGO = new GameObject("Stats Text", typeof(RectTransform), typeof(CanvasRenderer), typeof(Text));
        Undo.RegisterCreatedObjectUndo(textGO, "Create Camera Pack Stats Text");
        Undo.SetTransformParent(textGO.transform, canvasGO.transform, false, "Parent to Stats Canvas");

        RectTransform textRect = textGO.GetComponent<RectTransform>();
        textRect.anchorMin = Vector2.zero;
        textRect.anchorMax = Vector2.one;
        textRect.offsetMin = Vector2.zero;
        textRect.offsetMax = Vector2.zero;

        Text text = textGO.GetComponent<Text>();
        text.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf") ?? Resources.GetBuiltinResource<Font>("Arial.ttf");
        text.fontSize = 64;
        text.alignment = TextAnchor.UpperLeft;
        text.color = Color.white;
        text.text = "Left Frames: 0\nRight Frames: 0\nMatched Frames: 0\nDropped Left: 0\nDropped Right: 0";
        return text;
    }

    static Text EnsureStatsText(GameObject statsRoot)
    {
        Text existingText = statsRoot.GetComponentInChildren<Text>(true);
        if (existingText != null)
        {
            existingText.gameObject.SetActive(true);
            return existingText;
        }

        Canvas canvas = statsRoot.GetComponent<Canvas>();
        if (canvas == null)
        {
            canvas = Undo.AddComponent<Canvas>(statsRoot);
        }
        canvas.renderMode = RenderMode.WorldSpace;
        canvas.worldCamera = PXR_Utils.GetMainCameraForXROrigin();

        if (statsRoot.GetComponent<CanvasScaler>() == null)
        {
            Undo.AddComponent<CanvasScaler>(statsRoot);
        }

        if (statsRoot.GetComponent<GraphicRaycaster>() == null)
        {
            Undo.AddComponent<GraphicRaycaster>(statsRoot);
        }

        RectTransform canvasRect = statsRoot.GetComponent<RectTransform>();
        if (canvasRect != null)
        {
            canvasRect.sizeDelta = new Vector2(1200f, 360f);
        }

        GameObject textGO = new GameObject("Stats Text", typeof(RectTransform), typeof(CanvasRenderer), typeof(Text));
        Undo.RegisterCreatedObjectUndo(textGO, "Create Camera Pack Stats Text");
        Undo.SetTransformParent(textGO.transform, statsRoot.transform, false, "Parent to Stats Canvas");

        RectTransform textRect = textGO.GetComponent<RectTransform>();
        textRect.anchorMin = Vector2.zero;
        textRect.anchorMax = Vector2.one;
        textRect.offsetMin = Vector2.zero;
        textRect.offsetMax = Vector2.zero;

        Text text = textGO.GetComponent<Text>();
        text.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf") ?? Resources.GetBuiltinResource<Font>("Arial.ttf");
        text.fontSize = 64;
        text.alignment = TextAnchor.UpperLeft;
        text.color = Color.white;
        text.text = "Left Frames: 0\nRight Frames: 0\nMatched Frames: 0\nDropped Left: 0\nDropped Right: 0";
        return text;
    }

    static Material CreateVisualizerMaterial(string materialName)
    {
        Material material = new Material(Shader.Find("Unlit/Texture"));
        material.name = materialName;
        return material;
    }

    static void ConfigureCameraPackManager(GameObject cameraPackManager, string eyeName, Material targetMaterial)
    {
        var camPackAssembly = System.AppDomain.CurrentDomain.GetAssemblies()
            .FirstOrDefault(assembly => assembly.GetName().Name == "ByteDance.PICO.CameraPack");

        if (camPackAssembly == null)
        {
            Debug.LogError("ByteDance.PICO.CameraPack assembly not found.");
            return;
        }

        var managerType = camPackAssembly.GetType("ByteDance.PICO.CameraPack.PXR_CamTextureManager");
        if (managerType == null)
        {
            Debug.LogError("PXR_CamTextureManager type not found.");
            return;
        }

        var camManager = FindCameraPackManagerComponent(cameraPackManager, managerType);
        if (camManager == null)
        {
            Debug.LogError("PXR_CamTextureManager not found on " + cameraPackManager.name + ".");
            return;
        }

        Undo.RecordObject(camManager, "Configure Camera Pack Manager");

        var eyeField = managerType.GetField("Eye");
        if (eyeField != null)
        {
            eyeField.SetValue(camManager, System.Enum.Parse(eyeField.FieldType, eyeName));
        }

        var targetMaterialField = managerType.GetField("TargetMaterial");
        if (targetMaterialField != null)
        {
            targetMaterialField.SetValue(camManager, targetMaterial);
        }
    }

    static Component FindCameraPackManagerComponent(GameObject cameraPackManager, System.Type managerType)
    {
        if (cameraPackManager == null || managerType == null)
        {
            return null;
        }

        Component managerComponent = cameraPackManager.GetComponent(managerType);
        if (managerComponent == null)
        {
            managerComponent = cameraPackManager.GetComponentInChildren(managerType, true);
        }

        return managerComponent;
    }

    static void ConfigureMatcher(GameObject matcherGO, GameObject leftManager, GameObject rightManager, Material targetMaterial, Text statsText)
    {
        var camPackAssembly = System.AppDomain.CurrentDomain.GetAssemblies()
            .FirstOrDefault(assembly => assembly.GetName().Name == "ByteDance.PICO.CameraPack");

        if (camPackAssembly == null)
        {
            Debug.LogError("ByteDance.PICO.CameraPack assembly not found.");
            return;
        }

        var managerType = camPackAssembly.GetType("ByteDance.PICO.CameraPack.PXR_CamTextureManager");
        var matcherType = camPackAssembly.GetType("ByteDance.PICO.CameraPack.PXR_StereoCameraImageMatcher");
        if (managerType == null || matcherType == null)
        {
            Debug.LogError("Camera Pack matcher types not found.");
            return;
        }

        Component leftManagerComponent = FindCameraPackManagerComponent(leftManager, managerType);
        Component rightManagerComponent = FindCameraPackManagerComponent(rightManager, managerType);
        if (leftManagerComponent == null || rightManagerComponent == null)
        {
            Debug.LogError("PXR_CamTextureManager component not found for timestamp matched matcher.");
            return;
        }

        var matcher = matcherGO.GetComponent(matcherType);
        if (matcher == null)
        {
            matcher = Undo.AddComponent(matcherGO, matcherType);
        }

        Undo.RecordObject(matcher, "Configure Timestamp Matched Camera Pack Matcher");

        var leftManagerField = matcherType.GetField("LeftManager");
        if (leftManagerField != null)
        {
            leftManagerField.SetValue(matcher, leftManagerComponent);
        }

        var rightManagerField = matcherType.GetField("RightManager");
        if (rightManagerField != null)
        {
            rightManagerField.SetValue(matcher, rightManagerComponent);
        }

        var targetMaterialField = matcherType.GetField("TargetMaterial");
        if (targetMaterialField != null)
        {
            targetMaterialField.SetValue(matcher, targetMaterial);
        }

        var statsTextField = matcherType.GetField("StatsText");
        if (statsTextField != null)
        {
            statsTextField.SetValue(matcher, statsText);
        }
    }
}

#endregion

}
#endif
