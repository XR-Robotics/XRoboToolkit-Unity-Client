#if PICO_MS_SDK
using ByteDance.PICO.SpatialAdapter;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.SceneManagement;

namespace ByteDance.PICO.XR.Editor
{
    [InitializeOnLoad]
    internal static class PXR_SpatialCameraSpatialModeSynchronizerInstaller
    {
        private static bool scanQueued;

        static PXR_SpatialCameraSpatialModeSynchronizerInstaller()
        {
            ObjectFactory.componentWasAdded += OnComponentWasAdded;
            ObjectChangeEvents.changesPublished += OnObjectChangesPublished;
            EditorSceneManager.sceneOpened += OnSceneOpened;
            QueueLoadedSceneScan();
        }

        private static void OnComponentWasAdded(Component component)
        {
            if (component is SpatialCamera spatialCamera)
            {
                EnsureSynchronizer(spatialCamera);
            }
        }

        private static void OnObjectChangesPublished(ref ObjectChangeEventStream stream)
        {
            for (int eventIndex = 0; eventIndex < stream.length; eventIndex++)
            {
                ObjectChangeKind eventKind = stream.GetEventType(eventIndex);
                if (eventKind == ObjectChangeKind.ChangeGameObjectStructure ||
                    eventKind == ObjectChangeKind.CreateGameObjectHierarchy ||
                    eventKind == ObjectChangeKind.ChangeGameObjectParent)
                {
                    ScanLoadedScenes();
                    return;
                }
            }
        }

        private static void OnSceneOpened(Scene scene, OpenSceneMode mode)
        {
            QueueLoadedSceneScan();
        }

        private static void QueueLoadedSceneScan()
        {
            if (scanQueued || EditorApplication.isPlayingOrWillChangePlaymode)
            {
                return;
            }

            scanQueued = true;
            EditorApplication.delayCall += ScanLoadedScenes;
        }

        private static void ScanLoadedScenes()
        {
            scanQueued = false;
            if (EditorApplication.isPlayingOrWillChangePlaymode)
            {
                return;
            }

            for (int sceneIndex = 0; sceneIndex < SceneManager.sceneCount; sceneIndex++)
            {
                Scene scene = SceneManager.GetSceneAt(sceneIndex);
                if (!scene.isLoaded)
                {
                    continue;
                }

                foreach (GameObject root in scene.GetRootGameObjects())
                {
                    foreach (SpatialCamera spatialCamera in root.GetComponentsInChildren<SpatialCamera>(true))
                    {
                        EnsureSynchronizer(spatialCamera);
                    }
                }
            }
        }

        private static void EnsureSynchronizer(SpatialCamera spatialCamera)
        {
            if (spatialCamera == null ||
                EditorUtility.IsPersistent(spatialCamera) ||
                spatialCamera.TryGetComponent<PXR_SpatialCameraSpatialModeSynchronizer>(out _))
            {
                return;
            }

            Undo.AddComponent<PXR_SpatialCameraSpatialModeSynchronizer>(spatialCamera.gameObject);
        }
    }
}
#endif
