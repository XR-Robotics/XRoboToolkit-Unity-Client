using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using ByteDance.PICO.XR;
using LitJson;
using Robot;
using UnityEditor;
using UnityEditor.Build.Player;
using PackageInfo = UnityEditor.PackageManager.PackageInfo;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using Pose = ByteDance.PICO.Enterprise.Pose;
using Unity.XR.CoreUtils.Editor;

public static class PicoSdkMigrationValidation
{
    private static int checks;
    private static readonly string Output = Path.GetFullPath("Logs/pico-sdk-6.1.1-validation");

    [MenuItem("Tools/XRoboToolkit/Validate PICO SDK Migration")]
    public static void Run()
    {
        checks = 0;
        Directory.CreateDirectory(Output);
        Check(Application.unityVersion == "2022.3.16f1", "Unity baseline");
        var package = PackageInfo.FindForAssembly(typeof(PXR_Manager).Assembly);
        Check(package != null && package.name == "com.bytedance.pico.xr" && package.version == "6.1.1",
            "loaded Runtime belongs to SDK 6.1.1");
        Check(!AppDomain.CurrentDomain.GetAssemblies().Any(assembly =>
            assembly.GetName().Name == "Unity.XR.PICO" || assembly.GetName().Name == "PICO.TobSupport"),
            "old PICO assemblies are not loaded");

        if (Application.isBatchMode && string.IsNullOrEmpty(SceneManager.GetActiveScene().path))
            EditorSceneManager.OpenScene("Assets/Main.unity", OpenSceneMode.Single);
        EyeGazeValidation.Run();
        ValidateScene();
        ValidateGazeSimulationAndProtocol();
        InspectProjectValidation();
        CompileAndroidScripts();
        File.WriteAllText(Path.Combine(Output, "result.json"),
            $"{{\"unity\":\"{Application.unityVersion}\",\"sdk\":\"6.1.1\",\"checks\":{checks}," +
            "\"eye_gaze_entry\":\"passed\",\"android_csharp\":\"passed\",\"device_verified\":false}");
        Debug.Log($"[PicoSdkMigrationValidation] PASS: {checks} migration checks, Android C# compiled. No APK built.");
    }

    private static void ValidateScene()
    {
        Scene original = SceneManager.GetActiveScene();
        Scene scene = original.path == "Assets/Main.unity" ? original :
            EditorSceneManager.OpenScene("Assets/Main.unity", OpenSceneMode.Additive);
        try
        {
            foreach (GameObject root in scene.GetRootGameObjects())
                CheckNoMissingScripts(root);
            var ui = scene.GetRootGameObjects().SelectMany(root => root.GetComponentsInChildren<UIOperate>(true)).Single();
            var preview = scene.GetRootGameObjects().SelectMany(root =>
                root.GetComponentsInChildren<EnterpriseEyeFramePreview>(true)).Single();
            var source = scene.GetRootGameObjects().SelectMany(root =>
                root.GetComponentsInChildren<EnterpriseEyeFrameSource>(true)).Single();
            GameObject panel = Field<GameObject>(preview, "_panel");
            Toggle toggle = Field<Toggle>(preview, "_syncToggle");
            int stops = 0;
            source.CaptureStopped += reason => { if (reason == "preview closed") stops++; };
            preview.Initialize();
            Check(Field<bool>(preview, "_initialized"), "EyeFrame preview scene bindings initialize");
            toggle.isOn = true;
            Check(panel.activeInHierarchy && ui.HeadTog.gameObject.activeInHierarchy && ui.HeadTog.IsInteractable(),
                "EyeFrame opens while main controls remain available");
            Canvas.ForceUpdateCanvases();
            RenderUI(toggle.GetComponentInParent<Canvas>(), panel.GetComponent<RectTransform>());
            toggle.isOn = false;
            Check(!panel.activeSelf && stops == 1, "unchecking EyeFrame stops capture and closes panel");
            toggle.isOn = true;
            Field<Button>(preview, "_backButton").onClick.Invoke();
            Check(!panel.activeSelf && !toggle.isOn && stops == 2 &&
                ui.HeadTog.gameObject.activeInHierarchy, "Close button stops capture and preserves main UI");
            source.NotifyServiceBound(false);
            Check(!source.CanStart, "editor does not claim a hardware EyeFrame backend");
            Material material = Field<Material>(preview, "_material");
            if (material != null)
                UnityEngine.Object.DestroyImmediate(material);
            preview.GetType().GetField("_material", BindingFlags.NonPublic | BindingFlags.Instance)
                .SetValue(preview, null);
            Invoke(preview, "OnDestroy");

            const string simulatorPath = "Assets/XRI/Simulation/Editor XR Device Simulator.prefab";
            var simulator = AssetDatabase.LoadAssetAtPath<GameObject>(simulatorPath);
            Check(simulator != null, "controller simulator prefab imports");
            CheckNoMissingScripts(simulator);
            var serialized = new SerializedObject(simulator.GetComponents<MonoBehaviour>().First());
            Check(serialized.FindProperty("m_DeviceSimulatorActionAsset").objectReferenceValue != null &&
                serialized.FindProperty("m_ControllerActionAsset").objectReferenceValue != null,
                "controller simulator action assets resolve");
            foreach (string path in new[] {
                "Assets/InteractionTools/PICO Input Actions.inputactions",
                "Assets/XRI/Simulation/XR Device Simulator Controls.inputactions",
                "Assets/XRI/Simulation/XR Device Controller Controls.inputactions" })
            {
                var actions = AssetDatabase.LoadAssetAtPath<InputActionAsset>(path);
                Check(actions != null && actions.actionMaps.Count > 0, "input actions import: " + path);
            }
            var loaderSettings = XRGeneralSettingsForAndroid();
            Check(loaderSettings == "ByteDance.PICO.XR.PXR_Loader", "Android uses the new PICO XR loader");
        }
        finally
        {
            if (scene != original)
                EditorSceneManager.CloseScene(scene, true);
        }
    }

    private static string XRGeneralSettingsForAndroid()
    {
        var general = UnityEditor.XR.Management.XRGeneralSettingsPerBuildTarget
            .XRGeneralSettingsForBuildTarget(BuildTargetGroup.Android);
        var loaders = general?.Manager?.activeLoaders;
        Check(loaders != null && loaders.Count == 1, "exactly one Android XR provider");
        return loaders[0].GetType().FullName;
    }

    private static void ValidateGazeSimulationAndProtocol()
    {
        Scene original = SceneManager.GetActiveScene();
        Scene scene = EditorSceneManager.NewScene(NewSceneSetup.EmptyScene, NewSceneMode.Additive);
        SceneManager.SetActiveScene(scene);
        try
        {
            var camera = new GameObject("Simulation Camera").AddComponent<Camera>();
            var rig = new GameObject("Simulation Rig");
            var gaze = rig.AddComponent<PicoEyeGazeSource>();
            var serialized = new SerializedObject(gaze);
            serialized.FindProperty("gazeCamera").objectReferenceValue = camera;
            serialized.ApplyModifiedPropertiesWithoutUndo();
            gaze.SetTrackingRequested(true);
            Check(gaze.TrackingRequested, "F8/UI activation path selects mouse simulation");
            serialized.Update();
            serialized.FindProperty("editorGazeMode").enumValueIndex = (int)EditorGazeMode.CameraLocalDirection;
            serialized.ApplyModifiedPropertiesWithoutUndo();
            Invoke(gaze, "LateUpdate");
            Check(gaze.HasValidSample && gaze.IsSimulated, "editor publishes a simulated gaze");
            serialized.Update();
            serialized.FindProperty("simulatedPoseValid").boolValue = false;
            serialized.ApplyModifiedPropertiesWithoutUndo();
            Invoke(gaze, "LateUpdate");
            Check(!gaze.HasValidSample && gaze.WorldDirection == Vector3.zero,
                "F9 validity path clears previous gaze sample");
            gaze.SetTrackingRequested(false);
            Check(!gaze.TrackingRequested && !gaze.HasValidSample, "disabling gaze clears simulation");

            var recorder = new GameObject("Protocol Validation").AddComponent<EnterpriseCollectionRecorder>();
            var pose = new Pose { timestamp = 1234567890123456789L, x = 1, rw = 1,
                type = 1, confidence = 3, poseError = -2 };
            var json = (JsonData)Invoke(recorder, "BuildPoseJson", pose);
            Check(((IDictionary)json).Count == 5 && json["pose"].IsString &&
                json["status"].IsInt && json["timeStampNs"].IsLong &&
                json["type"].IsInt && json["poseError"].IsInt &&
                (long)json["timeStampNs"] == pose.timestamp, "controller protocol field names and numeric types");
            Check((bool)InvokeStatic(typeof(EnterpriseCollectionRecorder), "IsValidEnterpriseControllerPose", pose),
                "valid controller pose survives migration");
            pose.x = double.NaN;
            Check(!(bool)InvokeStatic(typeof(EnterpriseCollectionRecorder), "IsValidEnterpriseControllerPose", pose),
                "controller NaN filter");
            pose.x = 11;
            Check(!(bool)InvokeStatic(typeof(EnterpriseCollectionRecorder), "IsValidEnterpriseControllerPose", pose),
                "controller position range filter");
            pose.x = 0;
            pose.timestamp = 0;
            Check(!(bool)InvokeStatic(typeof(EnterpriseCollectionRecorder), "IsValidEnterpriseControllerPose", pose),
                "default zero-timestamp controller filter");
        }
        finally
        {
            SceneManager.SetActiveScene(original);
            EditorSceneManager.CloseScene(scene, true);
        }
    }

    private static void CompileAndroidScripts()
    {
        var settings = new ScriptCompilationSettings
        {
            target = BuildTarget.Android,
            group = BuildTargetGroup.Android,
            options = ScriptCompilationOptions.DevelopmentBuild
        };
        var result = PlayerBuildInterface.CompilePlayerScripts(settings, Path.Combine(Output, "AndroidScripts"));
        Check(result.assemblies != null && result.assemblies.Count > 0, "Android C# compilation");
        foreach (string name in new[] { "Assembly-CSharp.dll", "ByteDance.PICO.XR.dll",
            "ByteDance.PICO.Enterprise.dll", "XRoboToolkit.EyeGaze.dll", "XRoboToolkit.EnterpriseEyeFrames.dll" })
            Check(File.Exists(Path.Combine(Output, "AndroidScripts", name)), "Android assembly: " + name);
    }

    private static void InspectProjectValidation()
    {
        var failures = new HashSet<BuildValidationRule>();
        typeof(BuildValidator).GetMethod("GetCurrentValidationIssues", BindingFlags.NonPublic | BindingFlags.Static)
            .Invoke(null, new object[] { failures, BuildTargetGroup.Android });
        var text = new StringBuilder("Read-only inspection. No FixIt callbacks were executed.\n");
        foreach (BuildValidationRule failure in failures.OrderBy(rule => rule.Category).ThenBy(rule => rule.Message))
            text.AppendLine($"{(failure.Error ? "ERROR" : "WARNING")} [{failure.Category}] {failure.Message}");
        File.WriteAllText(Path.Combine(Output, "project-validation.txt"), text.ToString());
        Debug.Log($"[PicoSdkMigrationValidation] Inspected {failures.Count} outstanding project validation rules.");
    }

    private static void RenderUI(Canvas canvas, RectTransform panel)
    {
        if (canvas == null || canvas.renderMode != RenderMode.WorldSpace)
            return;
        var corners = new Vector3[4];
        var basis = canvas.transform;
        Vector3 min = new Vector3(float.MaxValue, float.MaxValue, float.MaxValue);
        Vector3 max = new Vector3(float.MinValue, float.MinValue, float.MinValue);
        foreach (var rect in new[] { (RectTransform)canvas.transform, panel })
        {
            rect.GetWorldCorners(corners);
            foreach (Vector3 corner in corners)
            {
                Vector3 local = basis.InverseTransformPoint(corner);
                min = Vector3.Min(min, local);
                max = Vector3.Max(max, local);
            }
        }
        var cameraObject = new GameObject("UI Validation Camera");
        var camera = cameraObject.AddComponent<Camera>();
        camera.transform.SetPositionAndRotation(basis.TransformPoint((min + max) * 0.5f) -
            basis.forward * 10f, basis.rotation);
        camera.orthographic = true;
        camera.aspect = 1.6f;
        camera.orthographicSize = Mathf.Max((max.y - min.y) * basis.lossyScale.y,
            (max.x - min.x) * basis.lossyScale.x / camera.aspect) * 0.55f;
        camera.clearFlags = CameraClearFlags.SolidColor;
        camera.backgroundColor = new Color(0.04f, 0.05f, 0.07f);
        camera.cullingMask = 1 << canvas.gameObject.layer;
        var render = RenderTexture.GetTemporary(1600, 1000, 24);
        var texture = new Texture2D(1600, 1000, TextureFormat.RGB24, false);
        RenderTexture previous = RenderTexture.active;
        try
        {
            camera.targetTexture = render;
            camera.Render();
            RenderTexture.active = render;
            texture.ReadPixels(new Rect(0, 0, 1600, 1000), 0, 0);
            texture.Apply();
            File.WriteAllBytes(Path.Combine(Output, "main-eyeframe.png"), texture.EncodeToPNG());
        }
        finally
        {
            RenderTexture.active = previous;
            camera.targetTexture = null;
            RenderTexture.ReleaseTemporary(render);
            UnityEngine.Object.DestroyImmediate(texture);
            UnityEngine.Object.DestroyImmediate(cameraObject);
        }
    }

    private static void CheckNoMissingScripts(GameObject root)
    {
        foreach (Transform transform in root.GetComponentsInChildren<Transform>(true))
            if (GameObjectUtility.GetMonoBehavioursWithMissingScriptCount(transform.gameObject) != 0)
                throw new InvalidOperationException("Missing script on " + transform.name);
    }

    private static T Field<T>(object target, string name) =>
        (T)target.GetType().GetField(name, BindingFlags.NonPublic | BindingFlags.Instance).GetValue(target);

    private static object Invoke(object target, string name, params object[] arguments) =>
        target.GetType().GetMethod(name, BindingFlags.NonPublic | BindingFlags.Instance).Invoke(target, arguments);

    private static object InvokeStatic(Type type, string name, params object[] arguments) =>
        type.GetMethod(name, BindingFlags.NonPublic | BindingFlags.Static).Invoke(null, arguments);

    private static void Check(bool condition, string message)
    {
        if (!condition)
            throw new InvalidOperationException("[PicoSdkMigrationValidation] FAIL: " + message);
        checks++;
        Debug.Log("[PicoSdkMigrationValidation] PASS: " + message);
    }
}
