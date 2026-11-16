// Managed protocol checks use the actual Unity Vector3, cache and LitJson implementations.
// Main-thread scene capture is covered separately by EyeTrackingTcpValidation in Unity.
using System;
using System.IO;
using System.Reflection;
using System.Text;
using System.Threading;
using LitJson;
using Network;
using Robot;
using UnityEngine;

internal static class EyeTrackingTcpChecks
{
    private static int _checks;

    private static void Main(string[] args)
    {
        AppDomain.CurrentDomain.AssemblyResolve += (sender, eventArgs) =>
        {
            string filename = new AssemblyName(eventArgs.Name).Name + ".dll";
            foreach (string directory in args)
            {
                string path = Path.Combine(directory, filename);
                if (File.Exists(path))
                    return Assembly.LoadFrom(path);
            }
            return null;
        };
        Run();
    }

    private static void Run()
    {
        double clock = 5.0;
        var data = new EyeTrackingData(() => clock);
        const long timestamp = 1793952000123456789L;
        EyeTrackingSnapshot valid = Fixture(true, 42L, timestamp, true, true);
        PublishFixture(data, valid, clock);
        JsonData json = EyeTrackingData.ToJson(data.GetSnapshot());
        Check(json["timeStampNs"].IsLong && (long)json["timeStampNs"] == timestamp &&
              json["sampleSeq"].IsLong && json["status"].IsLong,
            "Int64 timestamp, sample sequence and unsigned status serialization");
        Check(json["origin"].IsArray && json["origin"].Count == 3 &&
              json["origin"][0].IsDouble && json["hasPose"].IsBoolean &&
              json["hit"]["distance"].IsDouble,
            "explicit numeric vectors, Boolean validity and numeric hit distance");
        Check((long)JsonMapper.ToObject(json.ToJson())["timeStampNs"] == timestamp,
            "nanosecond timestamp survives JSON round trip");

        Exception threadError = null;
        var readers = new Thread[4];
        for (int index = 0; index < readers.Length; index++)
        {
            readers[index] = new Thread(() =>
            {
                try
                {
                    for (int sample = 0; sample < 1000; sample++)
                    {
                        string encoded = EyeTrackingData.ToJson(data.GetSnapshot()).ToJson();
                        if ((long)JsonMapper.ToObject(encoded)["timeStampNs"] != timestamp)
                            throw new InvalidOperationException("Snapshot changed while reading.");
                    }
                }
                catch (Exception exception) { Interlocked.CompareExchange(ref threadError, exception, null); }
            });
            readers[index].Start();
        }
        foreach (Thread reader in readers)
            Check(reader.Join(10000), "background reader completes");
        Check(threadError == null, "concurrent cache reads and JSON serialization");
        clock += EyeTrackingData.MaxSampleAgeSeconds;
        EyeTrackingSnapshot stale = data.GetSnapshot();
        Check(!stale.HasPose && !stale.HasHit && stale.Origin == Vector3.zero &&
              stale.Direction == Vector3.zero && stale.TrackingState == "Stale" &&
              stale.SampleFailure == "SampleExpired" && stale.TimeStampNs == timestamp &&
              stale.SampleSeq == 43L, "expired gaze clears pose and hit without changing acquisition time");
        Check(data.GetSnapshot().SampleSeq == stale.SampleSeq && valid.HasPose && valid.HasHit,
            "expiry advances once and copied snapshots stay immutable");

        var tracking = new JsonData();
        tracking["Head"] = "existing";
        EyeTrackingData.AppendTo(tracking, valid);
        EyeTrackingData.AppendTo(tracking, stale);
        Check(!(bool)tracking["EyeTracking"]["hasPose"] &&
              !tracking["EyeTracking"].ContainsKey("hit"), "invalid update removes the previous hit");
        EyeTrackingData.AppendTo(tracking, Fixture(true, 44L, timestamp + 100L, true, false));
        Check((bool)tracking["EyeTracking"]["hasPose"] &&
              !(bool)tracking["EyeTracking"]["hasHit"] &&
              !tracking["EyeTracking"].ContainsKey("hit"), "valid ray without a surface has no hit object");
        EyeTrackingData.AppendTo(tracking, Fixture(false, 45L, timestamp + 200L, false, false));
        Check(!tracking.ContainsKey("EyeTracking") && (string)tracking["Head"] == "existing",
            "disabled stream removes only EyeTracking from a reused payload");

        EyeTrackingData.AppendTo(tracking, valid);
        var envelope = new JsonData();
        envelope["functionName"] = "Tracking";
        envelope["value"] = tracking.ToJson();
        byte[] body = Encoding.UTF8.GetBytes(envelope.ToJson());
        byte[] packet = PackageHandle.Pack(NetCMD.PACKET_CCMD_TO_CONTROLLER_FUNCTION, body);
        Check(packet[0] == 0x3F && packet[1] == 0x6D &&
              BitConverter.ToInt32(packet, 2) == body.Length &&
              packet.Length == body.Length + 15 && packet[packet.Length - 1] == 0xA5,
            "existing TCP command, length, header and trailer");
        JsonData received = JsonMapper.ToObject(Encoding.UTF8.GetString(packet, 6, body.Length));
        JsonData decoded = JsonMapper.ToObject((string)received["value"]);
        Check((string)received["functionName"] == "Tracking" &&
              (long)decoded["EyeTracking"]["timeStampNs"] == timestamp &&
              (string)decoded["EyeTracking"]["hit"]["target"] == "测试 Panel",
            "UTF-8 envelope and nested Tracking value decode correctly");
        CheckRoutes(valid, clock);
        Console.WriteLine($"PASS: {_checks} managed EyeTracking TCP checks.");
    }

    private static void CheckRoutes(EyeTrackingSnapshot sample, double clock)
    {
        const BindingFlags flags = BindingFlags.Static | BindingFlags.NonPublic;
        var shared = (EyeTrackingData)typeof(TrackingData).GetField("_eyeTrackingData", flags).GetValue(null);
        PublishFixture(shared, sample, clock);
        var route = typeof(TcpHandler).GetMethod("ShouldSendEnterpriseTrackingDirectly", flags);
        Func<bool> usesDirect = () => (bool)route.Invoke(null, null);
        TrackingData.SetHeadOn(false);
        TrackingData.SetControllerOn(false);
        TrackingData.SetHandTrackingOn(false);
        TrackingData.SetTrackingType(TrackingData.TrackingType.None);
        TcpHandler.SendTrackingData = true;
        TcpHandler.EnterpriseDirectTrackingEnabled = true;
        Check(TrackingData.HasTracking && usesDirect(), "eye-only Enterprise stream uses direct tracking");
        TrackingData.SetHandTrackingOn(true);
        Check(!usesDirect(), "eye plus hand preserves the legacy hand route");
        TrackingData.SetHandTrackingOn(false);
        TrackingData.SetTrackingType(TrackingData.TrackingType.Body);
        Check(!usesDirect(), "eye plus body preserves the legacy body route");
        TrackingData.SetTrackingType(TrackingData.TrackingType.Motion);
        Check(!usesDirect(), "eye plus motion preserves the legacy tracker route");
        TrackingData.SetHeadOn(true);
        Check(usesDirect(), "existing head-enabled direct route is preserved");
        TcpHandler.EnterpriseDirectTrackingEnabled = false;
        Check(!usesDirect(), "direct tracking respects the existing direct toggle");
        TcpHandler.EnterpriseDirectTrackingEnabled = true;
        TcpHandler.SendTrackingData = false;
        Check(!usesDirect(), "tracking transmission respects the existing send toggle");
    }

    private static EyeTrackingSnapshot Fixture(bool enabled, long sequence, long timestamp,
        bool hasPose, bool hasHit)
    {
        // Inject value fixtures without calling Unity native APIs outside the editor.
        return (EyeTrackingSnapshot)Activator.CreateInstance(typeof(EyeTrackingSnapshot),
            BindingFlags.Instance | BindingFlags.NonPublic, null, new object[]
            {
                enabled, sequence, timestamp, hasPose, hasPose ? new Vector3(1f, 2f, 3f) : Vector3.zero,
                hasPose ? Vector3.forward : Vector3.zero, hasPose ? "Valid" : "Disabled",
                uint.MaxValue, 0, "None", false, hasHit, hasHit ? "Collider" : null,
                hasHit ? new Vector3(1f, 2f, 5f) : Vector3.zero,
                hasHit ? Vector3.back : Vector3.zero, hasHit ? 2f : 0f,
                hasHit ? "测试 Panel" : null
            }, null);
    }

    private static void PublishFixture(EyeTrackingData data, EyeTrackingSnapshot snapshot, double clock)
    {
        const BindingFlags flags = BindingFlags.Instance | BindingFlags.NonPublic;
        typeof(EyeTrackingData).GetField("_snapshot", flags).SetValue(data, snapshot);
        typeof(EyeTrackingData).GetField("_sampleSeq", flags).SetValue(data, snapshot.SampleSeq);
        typeof(EyeTrackingData).GetField("_lastCaptureSeconds", flags).SetValue(data, clock);
    }

    private static void Check(bool condition, string name)
    {
        if (!condition)
            throw new InvalidOperationException("FAIL: " + name);
        _checks++;
        Console.WriteLine("PASS: " + name);
    }
}
