#if PICO_MS_SDK
using System.Collections.Generic;
using System.Linq;
using ByteDance.PICO.SpatialAdapter;
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
using UnityEngine.XR.Interaction.Toolkit;
using UnityEngine.XR.Interaction.Toolkit.Inputs;
using UnityEngine.XR.Interaction.Toolkit.UI;
using ByteDance.PICO.SpatialAdapter.Component;
#if XR_HAND
using UnityEngine.XR.Hands;
#endif

namespace ByteDance.PICO.XR.Editor
{
    #region PICO Multi Spatial
    [BuildingBlockItem(Priority = k_SectionPriority)]
    class PXR_SpatialAdapterSection : IBuildingBlockSection
    {
        const string k_SectionId = "PICO Spatial";
        public string SectionId => k_SectionId;

        const string k_SectionIconPath = "Building/Block/Section/Icon/Path";
        public string SectionIconPath => k_SectionIconPath;
        const int k_SectionPriority = 1;

        readonly IBuildingBlock[] m_BBlocksElementIds = new IBuildingBlock[]
        {
            new PXR_BuildingBlocksSpatialCameraForVolumeSpace(),
            new PXR_BuildingBlocksSpatialCameraForStageSpace(),
            new PXR_BuildingBlocksPieceSelection(),
        };

        public IEnumerable<IBuildingBlock> GetBuildingBlocks()
        {
            var elements = m_BBlocksElementIds.ToList();
            return elements;
        }
    }

    class PXR_BuildingBlocksSpatialCameraForVolumeSpace : IBuildingBlock
    {
        const string k_Id = "Add Spatial Camera For Volume Space";
        const string k_BuildingBlockMSPath = PXR_Utils.BuildingBlockMSPath0 + k_Id;
        const string k_IconPath = "buildingblockIcon";
        const string k_Tooltip = k_Id + " : Spatial camera defines the size of your world in shared space. ";
        const int k_SectionPriority = 1;
        static string spatialCameraPath = PXR_Utils.sdkPackageName + "BuildingBlocks/Prefabs/Spatial Camera For Volume Space.prefab";
        static string spatialCameraName = $"{PXR_Utils.BuildingBlock} {k_Id}";
        public static string k_BuildingBlocksGOName = $"{PXR_Utils.BuildingBlock} {k_Id}";

        public string Id => k_Id;
        public string IconPath => k_IconPath;
        public bool IsEnabled => true;
        public string Tooltip => k_Tooltip;

        static void DoInterestingStuff()
        {
            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strBuildingBlocks, PXR_AppLog.strBuildingBlocks_PICOVideoSeethroughEffect);

            var existingVolumeSpace = PXR_Utils.FindComponentsInScene<Transform>()
                .Where(t => t.name == PXR_BuildingBlocksSpatialCameraForStageSpace.k_BuildingBlocksGOName && t.gameObject.activeSelf).ToList();
            if (existingVolumeSpace != null && existingVolumeSpace.Count > 0)
            {
                int dialogResult = EditorUtility.DisplayDialogComplex(
                    "Conflict Detected", 
                    "Scene already contains an active Spatial Camera For Volume Space. Replace it with Stage Space version?", 
                    "OK", 
                    "Cancel", 
                    null
                );
                
                if (dialogResult == 1) 
                    return;
                
                if (dialogResult == 0) {
                    foreach (var item in existingVolumeSpace){
                        item.gameObject.SetActive(false);
                    }
                }
            }
        
            if (PXR_Utils.FindComponentsInScene<Transform>().Where(component => component.name == k_BuildingBlocksGOName && component.gameObject.activeSelf).ToList().Count == 0)
            {
                GameObject buildingBlockGO = new GameObject();
                Selection.activeGameObject = buildingBlockGO;
                buildingBlockGO.name = k_BuildingBlocksGOName;

                GameObject ob = PrefabUtility.LoadPrefabContents(spatialCameraPath);
                Undo.RegisterCreatedObjectUndo(ob, "Create spatialCameraPath.");
                var activeScene = SceneManager.GetActiveScene();
                var rootObjects = activeScene.GetRootGameObjects();
                Undo.SetTransformParent(ob.transform, buildingBlockGO.transform, true, "Parent to ob.");
                ob.transform.localPosition = Vector3.zero;
                ob.transform.localRotation = Quaternion.identity;
                ob.transform.localScale = Vector3.one;
                ob.SetActive(true);

                buildingBlockGO.name = k_BuildingBlocksGOName;
                Undo.RegisterCreatedObjectUndo(buildingBlockGO, k_Id);

                EditorSceneManager.MarkSceneDirty(buildingBlockGO.scene);
                EditorSceneManager.SaveScene(buildingBlockGO.scene);
            }
        }

        public void ExecuteBuildingBlock() => DoInterestingStuff();

        // Each building block should have an accompanying MenuItem as a good practice, we add them here.
        [MenuItem(k_BuildingBlockMSPath, false, k_SectionPriority)]
        public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff();

    }

    class PXR_BuildingBlocksSpatialCameraForStageSpace : IBuildingBlock
    {
        const string k_Id = "Add Spatial Camera For Stage Space";
        const string k_BuildingBlockMSPath = PXR_Utils.BuildingBlockMSPath0 + k_Id;
        const string k_IconPath = "buildingblockIcon";
        const string k_Tooltip = k_Id + " : Spatial camera defines the size of your world in full stage mode. ";
        const int k_SectionPriority = 2;
        static string spatialCameraPath = PXR_Utils.sdkPackageName + "BuildingBlocks/Prefabs/Spatial Camera For Stage Space.prefab";
        static string spatialCameraName = $"{PXR_Utils.BuildingBlock} {k_Id}";
        public static string k_BuildingBlocksGOName = $"{PXR_Utils.BuildingBlock} {k_Id}";

        public string Id => k_Id;
        public string IconPath => k_IconPath;
        public bool IsEnabled => true;
        public string Tooltip => k_Tooltip;

        static void DoInterestingStuff()
        {
            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strBuildingBlocks, PXR_AppLog.strBuildingBlocks_PICOVideoSeethroughEffect);

            var existingStageSpace = PXR_Utils.FindComponentsInScene<Transform>()
                .Where(t => t.name == PXR_BuildingBlocksSpatialCameraForVolumeSpace.k_BuildingBlocksGOName && t.gameObject.activeSelf).ToList();
            if (existingStageSpace != null && existingStageSpace.Count > 0)
            {
                int dialogResult = EditorUtility.DisplayDialogComplex(
                    "Conflict Detected", 
                    "Scene already contains an active Spatial Camera For Stage Space. Replace it with Volume Space version?", 
                    "OK", 
                    "Cancel", 
                    null
                );
                
                if (dialogResult == 1) 
                    return;
                
                if (dialogResult == 0) {
                    foreach (var item in existingStageSpace){
                        item.gameObject.SetActive(false);
                    }
                }
            }
        
            if (PXR_Utils.FindComponentsInScene<Transform>().Where(component => component.name == k_BuildingBlocksGOName && component.gameObject.activeSelf).ToList().Count == 0)
            {
                GameObject buildingBlockGO = new GameObject();
                Selection.activeGameObject = buildingBlockGO;
                buildingBlockGO.name = k_BuildingBlocksGOName;

                GameObject ob = PrefabUtility.LoadPrefabContents(spatialCameraPath);
                Undo.RegisterCreatedObjectUndo(ob, "Create spatialCameraPath.");
                var activeScene = SceneManager.GetActiveScene();
                var rootObjects = activeScene.GetRootGameObjects();
                Undo.SetTransformParent(ob.transform, buildingBlockGO.transform, true, "Parent to ob.");
                ob.transform.localPosition = Vector3.zero;
                ob.transform.localRotation = Quaternion.identity;
                ob.transform.localScale = Vector3.one;
                ob.SetActive(true);

                buildingBlockGO.name = k_BuildingBlocksGOName;
                Undo.RegisterCreatedObjectUndo(buildingBlockGO, k_Id);

                EditorSceneManager.MarkSceneDirty(buildingBlockGO.scene);
                EditorSceneManager.SaveScene(buildingBlockGO.scene);
            }
        }

        public void ExecuteBuildingBlock() => DoInterestingStuff();

        // Each building block should have an accompanying MenuItem as a good practice, we add them here.
        [MenuItem(k_BuildingBlockMSPath, false, k_SectionPriority)]
        public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff();

    }

    class PXR_BuildingBlocksPieceSelection : IBuildingBlock
    {
        const string k_Id = "Add Piece Selection";
        const string k_BuildingBlockMSPath = PXR_Utils.BuildingBlockMSPath0 + k_Id;
        const string k_IconPath = "buildingblockIcon";
        const string k_Tooltip = k_Id + " :  ";
        const int k_SectionPriority = 3;
        static string cameraEffectPath = PXR_Utils.sdkPackageName + "BuildingBlocks/Prefabs/CameraEffect.prefab";
        static string cameraEffectName = $"{PXR_Utils.BuildingBlock} {k_Id}";
        static string k_BuildingBlocksGOName = $"{PXR_Utils.BuildingBlock} {k_Id}";

        public string Id => k_Id;
        public string IconPath => k_IconPath;
        public bool IsEnabled => true;
        public string Tooltip => k_Tooltip;

        static void DoInterestingStuff(MenuCommand command = null)
        {
            GameObject selectedObject = command?.context as GameObject ?? Selection.activeGameObject;
            if (selectedObject == null)
            {
                Debug.LogWarning($"[{k_Id}] Please select a GameObject in the Hierarchy first.");
                return;
            }

            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strBuildingBlocks, PXR_AppLog.strBuildingBlocks_PICOVideoSeethroughEffect);

            if (selectedObject.GetComponent<PieceSelectionBehavior>() == null)
            {
                Undo.AddComponent<PieceSelectionBehavior>(selectedObject);
            }

            if (PXR_Utils.FindComponentsInScene<Transform>().Where(component => component.name == k_BuildingBlocksGOName).ToList().Count == 0)
            {
                GameObject buildingBlockGO = new GameObject();
                Selection.activeGameObject = buildingBlockGO;
                buildingBlockGO.name = k_BuildingBlocksGOName;
                if (buildingBlockGO.GetComponent<ManipulationInputManager>() == null)
                {
                    buildingBlockGO.AddComponent<ManipulationInputManager>();
                }
                Undo.RegisterCreatedObjectUndo(buildingBlockGO, k_Id);
            }

            EditorSceneManager.MarkSceneDirty(selectedObject.scene);
            EditorSceneManager.SaveScene(selectedObject.scene);
        }

        public void ExecuteBuildingBlock() => DoInterestingStuff();

        // Each building block should have an accompanying MenuItem as a good practice, we add them here.
        [MenuItem(k_BuildingBlockMSPath, false, k_SectionPriority)]
        public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff(command);

    }

    class PXR_BuildingBlocksSpatialAdapterVideoComponent : IBuildingBlock
    {
        const string k_Id = "Add PICO SpatialAdapter Video Component";
        const string k_BuildingBlockMSPath = PXR_Utils.BuildingBlockMSPath0 + k_Id;
        const string k_IconPath = "buildingblockIcon";
        const string k_Tooltip = k_Id + " : SpatialAdapter supports native Pico video player via SpatialAdapterVideoComponent. Add it to a gameobject or mesh object for video display. Assign video clips as with Unity Video player. Note: Manually copy video clips to Assets/StreamingAssets/Video folder for this component. ";
        const int k_SectionPriority = 3;
        static string videoPath = PXR_Utils.sdkPackageName + "Assets/StreamingAssets/Video/MSVideo3.mp4";
        static string cameraEffectName = $"{PXR_Utils.BuildingBlock} {k_Id}";
        static string k_BuildingBlocksGOName = $"{PXR_Utils.BuildingBlock} {k_Id}";

        public string Id => k_Id;
        public string IconPath => k_IconPath;
        public bool IsEnabled => true;
        public string Tooltip => k_Tooltip;

        static void DoInterestingStuff(MenuCommand command = null)
        {
            GameObject gameObject = command?.context as GameObject ?? Selection.activeGameObject;
            if (gameObject == null)
            {
                Debug.LogWarning($"[{k_Id}] Please select a GameObject in the Hierarchy first.");
                return;
            }

            if (gameObject.GetComponent<SpatialAdapterVideoComponent>() == null)
            {
                var videoC = Undo.AddComponent<SpatialAdapterVideoComponent>(gameObject);
                videoC.Path = videoPath;
            }

            EditorSceneManager.MarkSceneDirty(gameObject.scene);
            EditorSceneManager.SaveScene(gameObject.scene);
        }

        public void ExecuteBuildingBlock() => DoInterestingStuff();

        // Each building block should have an accompanying MenuItem as a good practice, we add them here.
        [MenuItem(k_BuildingBlockMSPath, false, k_SectionPriority)]
        public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff(command);

    }

    class PXR_BuildingBlocksSpatialAdapterNativeText : IBuildingBlock
    {
        const string k_Id = "Add PICO SpatialAdapter Native Text";
        const string k_BuildingBlockMSPath = PXR_Utils.BuildingBlockMSPath0 + k_Id;
        const string k_IconPath = "buildingblockIcon";
        const string k_Tooltip = k_Id + " : SpatialAdapter Native Text, a Unity component, directly renders text via the Spatial Engine. It prevents clarity loss in traditional conversion and offers a stable, efficient solution for developers in complex UI or dynamic content scenarios. ";
        const int k_SectionPriority = 3;
        static string cameraEffectName = $"{PXR_Utils.BuildingBlock} {k_Id}";
        static string k_BuildingBlocksGOName = $"{PXR_Utils.BuildingBlock} {k_Id}";

        public string Id => k_Id;
        public string IconPath => k_IconPath;
        public bool IsEnabled => true;
        public string Tooltip => k_Tooltip;

        static void DoInterestingStuff(MenuCommand command = null)
        {
            GameObject gameObject = command?.context as GameObject ?? Selection.activeGameObject;
            if (gameObject == null)
            {
                Debug.LogWarning($"[{k_Id}] Please select a GameObject in the Hierarchy first.");
                return;
            }

            if (gameObject.GetComponent<SpatialAdapterNativeText>() == null)
            {
                Undo.AddComponent<SpatialAdapterNativeText>(gameObject);
            }

            EditorSceneManager.MarkSceneDirty(gameObject.scene);
            EditorSceneManager.SaveScene(gameObject.scene);
        }

        public void ExecuteBuildingBlock() => DoInterestingStuff();

        // Each building block should have an accompanying MenuItem as a good practice, we add them here.
        [MenuItem(k_BuildingBlockMSPath, false, k_SectionPriority)]
        public static void ExecuteMenuItem(MenuCommand command) => DoInterestingStuff(command);

    }

    #endregion

}
#endif
