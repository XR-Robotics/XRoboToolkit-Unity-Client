using System;
using System.Reflection;
using System.Text;
using System.Threading;
using LitJson;
using Network;
using Robot;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.SceneManagement;

public static class EyeTrackingTcpValidation
{
    [MenuItem("Tools/XRoboToolkit/Validate Eye Tracking TCP")]
    public static void Run()
    {
        if (EditorApplication.isPlayingOrWillChangePlaymode)
            throw new InvalidOperationException("Run eye tracking TCP validation outside Play mode.");
        Scene originalScene = SceneManager.GetActiveScene();
        Scene testScene = EditorSceneManager.NewScene(NewSceneSetup.EmptyScene, NewSceneMode.Additive);
        SceneManager.SetActiveScene(testScene);
        int checks = 0;
        try
        {
            var camera = new GameObject("TCP Validation Camera").AddComponent<Camera>();
            camera.transform.SetPositionAndRotation(new Vector3(2f, 3f, 4f),
                Quaternion.Euler(0f, 90f, 0f));
            var rig = new GameObject("TCP Validation Rig");
            var source = rig.AddComponent<PicoEyeGazeSource>();
            var caster = rig.AddComponent<EyeGazeRaycaster>();
            ConfigureSource(source, camera);
            var casterSettings = new SerializedObject(caster);
            casterSettings.FindProperty("source").objectReferenceValue = source;
            casterSettings.FindProperty("ignoredRoot").objectReferenceValue = rig.transform;
            casterSettings.FindProperty("hitWorldSpaceUI").boolValue = false;
            casterSettings.FindProperty("hitLayers").intValue = 1 << 31;
            casterSettings.ApplyModifiedPropertiesWithoutUndo();
            var blocker = GameObject.CreatePrimitive(PrimitiveType.Cube);
            blocker.name = "TCP Validation Blocker";
            blocker.layer = 31;
            blocker.transform.position = camera.transform.position + camera.transform.forward * 2f;
            blocker.transform.localScale = Vector3.one * 0.5f;
            Physics.SyncTransforms();

            double nowSeconds = 10.0;
            var data = new EyeTrackingData(() => nowSeconds);
            Sample(source, caster);
            data.Capture(source, caster);
            EyeTrackingSnapshot valid = data.GetSnapshot();
            Check(valid.Enabled && valid.HasPose && valid.IsSimulated &&
                  Vector3.Distance(valid.Origin, camera.transform.position) < 0.0001f &&
                  Vector3.Distance(valid.Direction, Vector3.right) < 0.0001f,
                "current simulated gaze is captured in Unity world meters", ref checks);
            Check(valid.HasHit && valid.HitTarget == blocker.name &&
                  Mathf.Abs(valid.HitDistance - 1.75f) < 0.001f,
                "hit belongs to the same gaze source and frame", ref checks);

            JsonData json = EyeTrackingData.ToJson(valid);
            Check(json["sampleSeq"].IsLong && json["timeStampNs"].IsLong &&
                  json["status"].IsLong && json["sdkResult"].IsInt &&
                  json["hasPose"].IsBoolean && json["origin"].IsArray &&
                  json["origin"][0].IsDouble && json["direction"][0].IsDouble &&
                  json["hit"]["distance"].IsDouble,
                "integers, booleans and vector numbers use explicit JSON types", ref checks);
            JsonData decoded = JsonMapper.ToObject(json.ToJson());
            Check((long)decoded["timeStampNs"] == valid.TimeStampNs &&
                  (long)decoded["timeStampNs"] > 9007199254740991L,
                "nanosecond timestamp round trips without double precision loss", ref checks);

            Exception threadError = null;
            string backgroundJson = null;
            var thread = new Thread(() =>
            {
                try { backgroundJson = EyeTrackingData.ToJson(data.GetSnapshot()).ToJson(); }
                catch (Exception exception) { threadError = exception; }
            });
            thread.Start();
            Check(thread.Join(2000) && threadError == null && backgroundJson == json.ToJson(),
                "background read and serialization use the published values", ref checks);

            nowSeconds += EyeTrackingData.MaxSampleAgeSeconds;
            EyeTrackingSnapshot stale = data.GetSnapshot();
            Check(!stale.HasPose && !stale.HasHit && stale.Origin == Vector3.zero &&
                  stale.Direction == Vector3.zero && stale.TrackingState == "Stale" &&
                  stale.SampleFailure == "SampleExpired" && stale.TimeStampNs == valid.TimeStampNs &&
                  stale.SampleSeq == valid.SampleSeq + 1 &&
                  data.GetSnapshot().SampleSeq == stale.SampleSeq,
                "expiry clears pose and hit and advances the sequence only once", ref checks);
            Check(valid.HasPose && valid.HasHit,
                "previously copied snapshots remain immutable after expiry", ref checks);

            Sample(source, caster);
            data.Capture(source, caster);
            EyeTrackingSnapshot recovered = data.GetSnapshot();
            Check(recovered.HasPose && recovered.SampleSeq > stale.SampleSeq,
                "fresh sampling recovers after expiry", ref checks);

            blocker.SetActive(false);
            Physics.SyncTransforms();
            Sample(source, caster);
            data.Capture(source, caster);
            json = EyeTrackingData.ToJson(data.GetSnapshot());
            Check((bool)json["hasPose"] && !(bool)json["hasHit"] && !json.ContainsKey("hit"),
                "a valid ray without a surface does not carry the previous hit", ref checks);

            var settings = new SerializedObject(source);
            settings.FindProperty("simulatedPoseValid").boolValue = false;
            settings.ApplyModifiedPropertiesWithoutUndo();
            Sample(source, caster);
            data.Capture(source, caster);
            EyeTrackingSnapshot invalid = data.GetSnapshot();
            Check(invalid.Enabled && !invalid.HasPose && !invalid.HasHit &&
                  invalid.IsSimulated && invalid.Origin == Vector3.zero &&
                  invalid.Direction == Vector3.zero &&
                  invalid.TrackingState == "WaitingForValidPose",
                "invalid samples publish explicit invalidity and clear old values", ref checks);

            var tracking = new JsonData();
            tracking["Head"] = "preserved";
            EyeTrackingData.AppendTo(tracking, invalid);
            Check(tracking.ContainsKey("EyeTracking") &&
                  tracking["Head"].ToString() == "preserved",
                "eye data is additive to the existing Tracking payload", ref checks);
            source.SetTrackingRequested(false);
            Sample(source, caster);
            data.Capture(source, caster);
            EyeTrackingData.AppendTo(tracking, data.GetSnapshot());
            Check(!data.IsEnabled && !tracking.ContainsKey("EyeTracking") &&
                  tracking["Head"].ToString() == "preserved",
                "switching off removes the field from a reused payload", ref checks);

            EyeTrackingData.AppendTo(tracking, valid);
            var envelope = new JsonData();
            envelope["functionName"] = "Tracking";
            envelope["value"] = tracking.ToJson();
            byte[] body = Encoding.UTF8.GetBytes(envelope.ToJson());
            byte[] packet = PackageHandle.Pack(NetCMD.PACKET_CCMD_TO_CONTROLLER_FUNCTION, body);
            Check(packet[0] == NetCMD.SEND_PACKET_HEAD &&
                  packet[1] == NetCMD.PACKET_CCMD_TO_CONTROLLER_FUNCTION &&
                  BitConverter.ToInt32(packet, 2) == body.Length &&
                  packet.Length == body.Length + 15 &&
                  packet[packet.Length - 1] == NetCMD.SEND_PACKET_EDN,
                "eye data uses the existing command and TCP frame", ref checks);
            JsonData receivedEnvelope = JsonMapper.ToObject(Encoding.UTF8.GetString(packet, 6, body.Length));
            JsonData receivedTracking = JsonMapper.ToObject((string)receivedEnvelope["value"]);
            Check((string)receivedEnvelope["functionName"] == "Tracking" &&
                  (long)receivedTracking["EyeTracking"]["timeStampNs"] == valid.TimeStampNs,
                "receiver parses the outer envelope and nested value string", ref checks);

            Debug.Log($"[EyeTrackingTcpValidation] PASS: {checks} checks. Unity {Application.unityVersion}.");
        }
        finally
        {
            SceneManager.SetActiveScene(originalScene);
            EditorSceneManager.CloseScene(testScene, true);
        }
    }

    private static void ConfigureSource(PicoEyeGazeSource source, Camera camera)
    {
        var settings = new SerializedObject(source);
        settings.FindProperty("gazeCamera").objectReferenceValue = camera;
        settings.FindProperty("editorGazeMode").enumValueIndex = (int)EditorGazeMode.CameraLocalDirection;
        settings.FindProperty("simulatedPoseValid").boolValue = true;
        settings.FindProperty("simulatedLocalOrigin").vector3Value = Vector3.zero;
        settings.FindProperty("simulatedLocalDirection").vector3Value = Vector3.forward;
        settings.FindProperty("logStatusChanges").boolValue = false;
        settings.ApplyModifiedPropertiesWithoutUndo();
    }

    private static void Sample(PicoEyeGazeSource source, EyeGazeRaycaster caster)
    {
        const BindingFlags flags = BindingFlags.Instance | BindingFlags.NonPublic;
        typeof(PicoEyeGazeSource).GetMethod("LateUpdate", flags).Invoke(source, null);
        typeof(EyeGazeRaycaster).GetMethod("LateUpdate", flags).Invoke(caster, null);
    }

    private static void Check(bool condition, string name, ref int checks)
    {
        if (!condition)
            throw new InvalidOperationException($"[EyeTrackingTcpValidation] FAIL: {name}.");
        checks++;
        Debug.Log($"[EyeTrackingTcpValidation] PASS: {name}.");
    }
}
