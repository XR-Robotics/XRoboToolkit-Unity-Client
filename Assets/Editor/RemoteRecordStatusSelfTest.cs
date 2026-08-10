using System;
using System.Text;
using UnityEditor;
using UnityEngine;

public static class RemoteRecordStatusSelfTest
{
    [MenuItem("Tools/Validation/Remote Record Status Self-Test")]
    public static void Run()
    {
        byte[] valid = Encoding.UTF8.GetBytes(
            "{\"schema\":\"g1_wuji_record_status_v1\"," +
            "\"operator_time\":\"2026-07-26 15:04:05\"," +
            "\"state\":\"RECORDING\",\"episode\":7,\"frame_count\":42}");
        Assert(
            RemoteRecordStatusSnapshot.TryParse(valid, out RemoteRecordStatusSnapshot status),
            "valid payload");
        Assert(status.State == "RECORDING", "state");
        Assert(status.OperatorTime == "2026-07-26 15:04:05", "operator time");
        Assert(status.Episode == 7, "episode");
        Assert(status.FrameCount == 42, "frame count");

        byte[] unknownState = Encoding.UTF8.GetBytes(
            "{\"schema\":\"g1_wuji_record_status_v1\"," +
            "\"operator_time\":\"2026-07-26 15:04:05\"," +
            "\"state\":\"UNTRUSTED\",\"episode\":-1,\"frame_count\":-2}");
        Assert(
            RemoteRecordStatusSnapshot.TryParse(
                unknownState,
                out RemoteRecordStatusSnapshot normalized),
            "unknown-state payload");
        Assert(normalized.State == "UNKNOWN", "unknown state is allowlisted");
        Assert(normalized.Episode == 0 && normalized.FrameCount == 0, "negative counters");

        byte[] wrongSchema = Encoding.UTF8.GetBytes(
            "{\"schema\":\"wrong\",\"operator_time\":\"2026-07-26 15:04:05\"}");
        Assert(
            !RemoteRecordStatusSnapshot.TryParse(wrongSchema, out _),
            "wrong schema rejected");

        GameObject host = new GameObject("record-status-test-host");
        GameObject cameraObject = new GameObject("record-status-test-camera");
        try
        {
            Camera camera = cameraObject.AddComponent<Camera>();

            RemoteRecordStatusOverlay overlay =
                host.AddComponent<RemoteRecordStatusOverlay>();
            Assert(overlay.Configure(camera), "head-locked HUD creation");
            Assert(overlay.IsConfigured, "head-locked HUD configured");
            Assert(overlay.Apply(status), "record status rendered");
            overlay.Clear();
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(host);
            UnityEngine.Object.DestroyImmediate(cameraObject);
        }

        Debug.Log("REMOTE_RECORD_STATUS_SELF_TEST_OK");
    }

    private static void Assert(bool condition, string label)
    {
        if (!condition)
        {
            throw new InvalidOperationException(
                $"Remote record status self-test failed: {label}");
        }
    }
}
