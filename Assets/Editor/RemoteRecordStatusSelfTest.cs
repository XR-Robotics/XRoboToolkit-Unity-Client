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
        GameObject leftCameraObject = new GameObject("record-status-test-left-camera");
        GameObject rightCameraObject = new GameObject("record-status-test-right-camera");
        GameObject leftCanvasObject = new GameObject("record-status-test-left-canvas");
        GameObject rightCanvasObject = new GameObject("record-status-test-right-canvas");
        try
        {
            Camera leftCamera = leftCameraObject.AddComponent<Camera>();
            Camera rightCamera = rightCameraObject.AddComponent<Camera>();
            Canvas leftCanvas = leftCanvasObject.AddComponent<Canvas>();
            Canvas rightCanvas = rightCanvasObject.AddComponent<Canvas>();
            leftCanvas.renderMode = RenderMode.ScreenSpaceCamera;
            leftCanvas.worldCamera = leftCamera;
            leftCanvas.planeDistance = 0.31f;
            rightCanvas.renderMode = RenderMode.ScreenSpaceCamera;
            rightCanvas.worldCamera = rightCamera;
            rightCanvas.planeDistance = 0.31f;

            RemoteRecordStatusOverlay overlay =
                host.AddComponent<RemoteRecordStatusOverlay>();
            overlay.Configure(leftCanvasObject, rightCanvasObject);
            Assert(overlay.IsConfigured, "per-eye HUD creation");
            overlay.Apply(status);
            overlay.Clear();
        }
        finally
        {
            UnityEngine.Object.DestroyImmediate(host);
            UnityEngine.Object.DestroyImmediate(leftCanvasObject);
            UnityEngine.Object.DestroyImmediate(rightCanvasObject);
            UnityEngine.Object.DestroyImmediate(leftCameraObject);
            UnityEngine.Object.DestroyImmediate(rightCameraObject);
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
