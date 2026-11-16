using System;
using System.Diagnostics;
using LitJson;
using UnityEngine;

namespace Robot
{
    /// <summary>A value-only gaze sample that can be serialized on a network thread.</summary>
    public readonly struct EyeTrackingSnapshot
    {
        public readonly bool Enabled;
        public readonly long SampleSeq;
        public readonly long TimeStampNs;
        public readonly bool HasPose;
        public readonly Vector3 Origin;
        public readonly Vector3 Direction;
        public readonly string TrackingState;
        public readonly uint Status;
        public readonly int SdkResult;
        public readonly string SampleFailure;
        public readonly bool IsSimulated;
        public readonly bool HasHit;
        public readonly string HitKind;
        public readonly Vector3 HitPoint;
        public readonly Vector3 HitNormal;
        public readonly float HitDistance;
        public readonly string HitTarget;

        internal EyeTrackingSnapshot(bool enabled, long sampleSeq, long timeStampNs,
            bool hasPose, Vector3 origin, Vector3 direction, string trackingState, uint status,
            int sdkResult, string sampleFailure, bool isSimulated, bool hasHit,
            string hitKind, Vector3 hitPoint, Vector3 hitNormal, float hitDistance, string hitTarget)
        {
            Enabled = enabled;
            SampleSeq = sampleSeq;
            TimeStampNs = timeStampNs;
            HasPose = hasPose;
            Origin = origin;
            Direction = direction;
            TrackingState = trackingState;
            Status = status;
            SdkResult = sdkResult;
            SampleFailure = sampleFailure;
            IsSimulated = isSimulated;
            HasHit = hasHit;
            HitKind = hitKind;
            HitPoint = hitPoint;
            HitNormal = hitNormal;
            HitDistance = hitDistance;
            HitTarget = hitTarget;
        }
    }

    /// <summary>Capture Unity state on the main thread and publish an immutable TCP snapshot.</summary>
    public sealed class EyeTrackingData
    {
        public const int SchemaVersion = 1;
        public const double MaxSampleAgeSeconds = 0.25;
        private const long UnixEpochTicks = 621355968000000000L;
        private readonly object _snapshotLock = new object();
        private readonly Func<double> _monotonicSeconds;
        private EyeTrackingSnapshot _snapshot;
        private long _sampleSeq;
        private double _lastCaptureSeconds;

        public EyeTrackingData(Func<double> monotonicSeconds = null)
        {
            _monotonicSeconds = monotonicSeconds ??
                (() => Stopwatch.GetTimestamp() / (double)Stopwatch.Frequency);
        }

        public bool IsEnabled
        {
            get
            {
                lock (_snapshotLock)
                    return _snapshot.Enabled;
            }
        }

        /// <summary>Call after the source and raycaster LateUpdate, only on Unity's main thread.</summary>
        public void Capture(PicoEyeGazeSource source, EyeGazeRaycaster raycaster)
        {
            bool enabled = source != null && source.TrackingRequested;
            bool hasPose = enabled && source.HasValidSample;
            EyeGazeHit hit = hasPose && raycaster != null && raycaster.Source == source
                ? raycaster.Hit : default;
            bool hasHit = hasPose && hit.HasHit;
            string state = source == null ? "Disabled" :
                !source.isActiveAndEnabled && enabled ? "Suspended" : source.Status.ToString();
            bool isSimulated = source != null && source.IsSimulated;
#if UNITY_EDITOR
            // Invalid editor samples must still be distinguishable from device samples.
            isSimulated = enabled;
#endif
            lock (_snapshotLock)
            {
                _snapshot = new EyeTrackingSnapshot(enabled, ++_sampleSeq,
                    (DateTime.UtcNow.Ticks - UnixEpochTicks) * 100L,
                    hasPose, hasPose ? source.WorldOrigin : Vector3.zero,
                    hasPose ? source.WorldDirection : Vector3.zero, state,
                    source != null ? source.CombinedPoseStatus : 0u,
                    source != null ? source.LastSdkResult : 0,
                    source != null ? source.SampleFailure.ToString() : "None",
                    isSimulated, hasHit, hasHit ? hit.Kind.ToString() : null,
                    hasHit ? hit.Point : Vector3.zero, hasHit ? hit.Normal : Vector3.zero,
                    hasHit ? hit.Distance : 0f,
                    hasHit && hit.Target != null ? hit.Target.name : null);
                _lastCaptureSeconds = _monotonicSeconds();
            }
        }

        /// <summary>Read or expire a snapshot without accessing Unity objects or the SDK.</summary>
        public EyeTrackingSnapshot GetSnapshot()
        {
            lock (_snapshotLock)
            {
                if (_snapshot.Enabled && _snapshot.HasPose &&
                    _monotonicSeconds() - _lastCaptureSeconds >= MaxSampleAgeSeconds)
                {
                    // Advance once on expiry so direct TCP sends the invalid transition.
                    _snapshot = new EyeTrackingSnapshot(true, ++_sampleSeq, _snapshot.TimeStampNs,
                        false, Vector3.zero, Vector3.zero, "Stale", _snapshot.Status,
                        _snapshot.SdkResult, "SampleExpired", _snapshot.IsSimulated, false,
                        null, Vector3.zero, Vector3.zero, 0f, null);
                }
                return _snapshot;
            }
        }

        public static void AppendTo(JsonData tracking, EyeTrackingSnapshot sample)
        {
            if (sample.Enabled)
                tracking["EyeTracking"] = ToJson(sample);
            else if (tracking.ContainsKey("EyeTracking"))
                tracking.Remove("EyeTracking");
        }

        public static JsonData ToJson(EyeTrackingSnapshot sample)
        {
            var json = new JsonData();
            json["schemaVersion"] = SchemaVersion;
            json["sampleSeq"] = sample.SampleSeq;
            json["timeStampNs"] = sample.TimeStampNs;
            json["hasPose"] = sample.HasPose;
            json["origin"] = VectorJson(sample.Origin);
            json["direction"] = VectorJson(sample.Direction);
            json["trackingState"] = sample.TrackingState;
            json["status"] = (long)sample.Status;
            json["sdkResult"] = sample.SdkResult;
            json["sampleFailure"] = sample.SampleFailure;
            json["isSimulated"] = sample.IsSimulated;
            json["coordinateSpace"] = "unity_world";
            json["positionUnit"] = "m";
            json["hasHit"] = sample.HasHit;
            if (sample.HasHit)
            {
                var hit = new JsonData();
                hit["kind"] = sample.HitKind;
                hit["point"] = VectorJson(sample.HitPoint);
                hit["normal"] = VectorJson(sample.HitNormal);
                hit["distance"] = (double)sample.HitDistance;
                hit["target"] = sample.HitTarget;
                json["hit"] = hit;
            }
            return json;
        }

        private static JsonData VectorJson(Vector3 value)
        {
            var json = new JsonData();
            json.SetJsonType(JsonType.Array);
            json.Add((double)value.x);
            json.Add((double)value.y);
            json.Add((double)value.z);
            return json;
        }
    }
}
