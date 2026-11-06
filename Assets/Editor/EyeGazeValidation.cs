using System;
using System.Reflection;
using Robot;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public static class EyeGazeValidation
{
    [MenuItem("Tools/XRoboToolkit/Validate Eye Gaze")]
    public static void Run()
    {
        if (EditorApplication.isPlayingOrWillChangePlaymode)
            throw new InvalidOperationException("Run eye gaze validation outside Play mode.");
        Scene originalScene = SceneManager.GetActiveScene();
        Scene testScene = EditorSceneManager.NewScene(NewSceneSetup.EmptyScene, NewSceneMode.Additive);
        SceneManager.SetActiveScene(testScene);
        int checks = 0;
        GraphicRaycaster validationRaycaster = null;
        try
        {
            Check(EyeGazeMath.IsCombinedEyePoseValid(1u),
                "documented Boolean combined eye status accepted", ref checks);
            Check(EyeGazeMath.IsCombinedEyePoseValid(1539u),
                "Swan combined eye status 0x603 accepted", ref checks);
            Check(EyeGazeMath.IsCombinedEyePoseValid(515u),
                "Swan combined eye status 0x203 accepted", ref checks);
            Check(!EyeGazeMath.IsCombinedEyePoseValid(0u),
                "unavailable combined eye status rejected", ref checks);
            Check(!EyeGazeMath.IsCombinedEyePoseValid(2u),
                "gaze direction without valid origin rejected", ref checks);
            Check(!EyeGazeMath.IsCombinedEyePoseValid(513u),
                "extra metadata flags do not replace a valid gaze direction", ref checks);

            var cameraObject = new GameObject("Validation Camera");
            var camera = cameraObject.AddComponent<Camera>();
            camera.transform.SetPositionAndRotation(new Vector3(12345f, 23456f, 34567f),
                Quaternion.Euler(0f, 90f, 0f));
            Vector3 localOrigin = new Vector3(0.02f, 0.01f, 0.03f);
            Check(EyeGazeMath.TryCreateWorldRay(camera.transform, localOrigin, Vector3.forward * 1000f,
                      out Ray ray) && Vector3.Distance(ray.origin,
                      camera.transform.position + camera.transform.rotation * localOrigin) < 0.005f &&
                  Vector3.Distance(ray.direction, Vector3.right) < 0.0001f,
                "camera-to-world conversion and direction normalization", ref checks);
            Check(!EyeGazeMath.TryCreateWorldRay(camera.transform, Vector3.zero, Vector3.zero, out _),
                "zero direction rejected", ref checks);
            Check(!EyeGazeMath.TryCreateWorldRay(camera.transform, new Vector3(float.NaN, 0f, 0f),
                    Vector3.forward, out _), "NaN origin rejected", ref checks);
            Check(!EyeGazeMath.TryCreateWorldRay(camera.transform, Vector3.zero,
                    new Vector3(0f, 0f, float.PositiveInfinity), out _), "infinite direction rejected", ref checks);
            Check(!EyeGazeMath.TryCreateWorldRay(null, Vector3.zero, Vector3.forward, out _),
                "missing camera rejected", ref checks);

            var rig = new GameObject("Validation Rig");
            var caster = rig.AddComponent<EyeGazeRaycaster>();
            var settings = new SerializedObject(caster);
            settings.FindProperty("ignoredRoot").objectReferenceValue = rig.transform;
            settings.ApplyModifiedPropertiesWithoutUndo();
            ray = new Ray(camera.transform.position, camera.transform.forward);
            var blocker = GameObject.CreatePrimitive(PrimitiveType.Cube);
            blocker.name = "Validation Blocker";
            blocker.transform.position = ray.GetPoint(2f);
            blocker.transform.localScale = Vector3.one * 0.5f;
            Physics.SyncTransforms();
            Check(caster.Cast(ray, camera).Target == blocker, "collider hit", ref checks);

            var canvasObject = new GameObject("Validation Canvas", typeof(RectTransform),
                typeof(Canvas), typeof(GraphicRaycaster));
            var canvas = canvasObject.GetComponent<Canvas>();
            // BaseRaycaster does not run OnEnable outside Play mode.
            validationRaycaster = canvasObject.GetComponent<GraphicRaycaster>();
            typeof(BaseRaycaster).GetMethod("OnEnable", BindingFlags.Instance | BindingFlags.NonPublic)
                .Invoke(validationRaycaster, null);
            canvas.renderMode = RenderMode.WorldSpace;
            canvas.worldCamera = camera;
            canvas.transform.SetPositionAndRotation(ray.GetPoint(1f), camera.transform.rotation);
            ((RectTransform)canvas.transform).sizeDelta = Vector2.one;
            var imageObject = new GameObject("Validation Surface", typeof(RectTransform), typeof(Image));
            imageObject.transform.SetParent(canvas.transform, false);
            ((RectTransform)imageObject.transform).sizeDelta = Vector2.one;
            Canvas.ForceUpdateCanvases();
            // Batch mode has no Game view frame to assign the uGUI render depth.
            camera.Render();
            EyeGazeHit uiHit = caster.Cast(ray, camera);
            Check(uiHit.Kind == EyeGazeHitKind.WorldSpaceUI && uiHit.Target == imageObject &&
                  Mathf.Abs(uiHit.Distance - 1f) < 0.005f &&
                  Vector3.Dot(uiHit.Normal, ray.direction) < -0.99f,
                "world UI in front of collider", ref checks);

            blocker.transform.position = ray.GetPoint(0.5f);
            Physics.SyncTransforms();
            Check(caster.Cast(ray, camera).Target == blocker, "nearer collider occludes UI", ref checks);
            blocker.SetActive(false);
            imageObject.GetComponent<Image>().raycastTarget = false;
            Canvas.ForceUpdateCanvases();
            Check(!caster.Cast(ray, camera).HasHit, "no hit when UI raycast target is disabled", ref checks);
            imageObject.GetComponent<Image>().raycastTarget = true;
            var canvasGroup = canvasObject.AddComponent<CanvasGroup>();
            canvasGroup.blocksRaycasts = false;
            Canvas.ForceUpdateCanvases();
            Check(!caster.Cast(ray, camera).HasHit, "CanvasGroup raycast filter respected", ref checks);
            canvasObject.SetActive(false);
            blocker.SetActive(true);
            blocker.transform.SetParent(rig.transform, true);
            Physics.SyncTransforms();
            Check(!caster.Cast(ray, camera).HasHit, "rig geometry excluded", ref checks);
            blocker.transform.SetParent(null, true);
            blocker.GetComponent<Collider>().isTrigger = true;
            Physics.SyncTransforms();
            Check(!caster.Cast(ray, camera).HasHit, "trigger volumes excluded", ref checks);
            Check(!caster.Cast(new Ray(ray.origin, Vector3.zero), camera).HasHit,
                "invalid ray cannot report a hit", ref checks);

            Shader shader = Resources.Load<Shader>("EyeGazeUnlit");
            Check(shader != null && shader.isSupported && !ShaderUtil.ShaderHasError(shader),
                "visualization shader imported without errors", ref checks);
            const string prefabPath = "Assets/InteractionTools/Prefabs/XR Origin (XR Rig).prefab";
            GameObject prefab = AssetDatabase.LoadAssetAtPath<GameObject>(prefabPath);
            var prefabSource = prefab.GetComponent<PicoEyeGazeSource>();
            var prefabCaster = prefab.GetComponent<EyeGazeRaycaster>();
            Check(prefabSource != null && prefabSource.GazeCamera != null &&
                  prefabCaster != null && prefabCaster.Source == prefabSource &&
                  prefab.GetComponent<EyeGazeVisualizer>() != null,
                "imported XR Rig has the gaze components and camera references", ref checks);
            Debug.Log($"[EyeGazeValidation] PASS: {checks} checks. Unity {Application.unityVersion}.");
        }
        finally
        {
            if (validationRaycaster != null)
                typeof(BaseRaycaster).GetMethod("OnDisable", BindingFlags.Instance | BindingFlags.NonPublic)
                    .Invoke(validationRaycaster, null);
            SceneManager.SetActiveScene(originalScene);
            EditorSceneManager.CloseScene(testScene, true);
        }
    }

    private static void Check(bool condition, string name, ref int checks)
    {
        if (!condition)
            throw new InvalidOperationException($"[EyeGazeValidation] FAIL: {name}.");
        checks++;
        Debug.Log($"[EyeGazeValidation] PASS: {name}.");
    }
}
