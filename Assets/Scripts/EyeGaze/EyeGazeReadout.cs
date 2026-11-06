using System.Globalization;
using UnityEngine;
using UnityEngine.UI;

namespace Robot
{
    [DisallowMultipleComponent]
    [DefaultExecutionOrder(400)]
    public sealed class EyeGazeReadout : MonoBehaviour
    {
        [SerializeField] private PicoEyeGazeSource source;
        [SerializeField] private EyeGazeRaycaster raycaster;
        [SerializeField] private Text statusText;
        [SerializeField] private Text messageText;
        [SerializeField] private Text valuesText;
        [SerializeField, Min(0.05f)] private float refreshInterval = 0.1f;

        private float _nextRefresh;
        private bool _lastValid;
        private bool _lastHit;
        private bool _lastRequested;
        private EyeGazeStatus _lastStatus;

        public PicoEyeGazeSource Source => source;
        public EyeGazeRaycaster Raycaster => raycaster;

        private void OnEnable()
        {
            _nextRefresh = 0f;
            if (raycaster == null && source != null)
                raycaster = source.GetComponent<EyeGazeRaycaster>();
            RefreshNow();
        }

        private void LateUpdate()
        {
            bool requested = source != null && source.TrackingRequested;
            bool valid = requested && source.HasValidSample;
            bool hit = valid && raycaster != null && raycaster.HasHit;
            EyeGazeStatus status = source != null ? source.Status : EyeGazeStatus.UnsupportedPlatform;
            // Clear stale values immediately; normal numeric updates are limited to 10 Hz.
            if (requested != _lastRequested || valid != _lastValid || hit != _lastHit ||
                status != _lastStatus || Time.unscaledTime >= _nextRefresh)
                RefreshNow();
        }

        public void Bind(PicoEyeGazeSource gazeSource, EyeGazeRaycaster gazeRaycaster)
        {
            source = gazeSource;
            raycaster = gazeRaycaster;
            RefreshNow();
        }

        public void RefreshNow()
        {
            if (statusText == null || messageText == null || valuesText == null)
                return;
            bool requested = source != null && source.TrackingRequested;
            bool valid = requested && source.HasValidSample;
            bool hit = valid && raycaster != null && raycaster.HasHit;
            EyeGazeStatus status = source != null ? source.Status : EyeGazeStatus.UnsupportedPlatform;
            _lastRequested = requested;
            _lastValid = valid;
            _lastHit = hit;
            _lastStatus = status;
            _nextRefresh = Time.unscaledTime + Mathf.Max(0.05f, refreshInterval);

            statusText.text = source == null ? "UNAVAILABLE" : !requested ? "OFF" :
                valid ? source.IsSimulated ? "SIMULATED" : "VALID" :
                status == EyeGazeStatus.Suspended ? "PAUSED" : "NO DATA";
            statusText.color = valid ? new Color(0.412f, 0.867f, 0.776f) :
                !requested ? new Color(0.659f, 0.714f, 0.776f) : new Color(0.965f, 0.773f, 0.435f);
            messageText.text = GetMessage(requested, valid, status);
            string origin = valid ? FormatVector(source.WorldOrigin) : "--";
            string direction = valid ? FormatVector(source.WorldDirection) : "--";
            string point = hit ? FormatVector(raycaster.Hit.Point) : "--";
            string target = hit ? FormatTarget(raycaster.Hit.Target) : "--";
            string distance = hit ? raycaster.Hit.Distance.ToString("F3", CultureInfo.InvariantCulture) +
                " m (" + (raycaster.Hit.Kind == EyeGazeHitKind.WorldSpaceUI ? "UI" : "Scene") + ")" : "--";
            string serviceCode = requested && source != null && !Application.isEditor ?
                source.LastSdkResult.ToString(CultureInfo.InvariantCulture) : "--";
            bool hasDiagnostics = requested && source != null && source.HasEyeDataDiagnostics;
            string dataCode = hasDiagnostics ?
                source.LastEyeDataResult.ToString(CultureInfo.InvariantCulture) : "--";
            string poseValidity = hasDiagnostics ?
                FormatValidity(source.LastLeftPoseValidity) + " / " +
                FormatValidity(source.LastRightPoseValidity) + " / " +
                FormatValidity(source.LastCombinedPoseValidity) : "--";
            valuesText.text = "GAZE RAY\nOrigin (m): " + origin + "\nDirection: " + direction +
                "\n\nSURFACE HIT\nHit (m): " + point + "\nTarget: " + target +
                "\nDistance: " + distance + "\n\nService code: " + serviceCode +
                "\nLast eye data code: " + dataCode + "\nLast pose valid (L/R/C): " + poseValidity;
        }

        private string GetMessage(bool requested, bool valid, EyeGazeStatus status)
        {
            if (source == null) return "Eye tracking source is unavailable.";
            if (!requested) return "Turn on EyeTracking to view results.";
            if (valid) return source.IsSimulated ? "Editor simulation | World coordinates" :
                "Live eye tracking | World coordinates";
            switch (status)
            {
                case EyeGazeStatus.MissingCamera: return "The gaze camera is unavailable.";
                case EyeGazeStatus.Suspended: return "Tracking paused or application unfocused.";
                case EyeGazeStatus.EyeTrackingDisabled: return "Eye tracking is disabled in XR settings.";
                case EyeGazeStatus.UnsupportedDevice: return "Eye tracking is not supported by this device.";
                case EyeGazeStatus.ServiceUnavailable: return "Eye tracking service is unavailable.";
                case EyeGazeStatus.UnsupportedPlatform: return "Real tracking requires a PICO device.";
                case EyeGazeStatus.WaitingForValidPose: return GetSampleFailureMessage();
                default: return "Waiting for a valid eye pose.";
            }
        }

        private string GetSampleFailureMessage()
        {
            switch (source.SampleFailure)
            {
                case EyeGazeSampleFailure.StatusUnavailable:
                    return "Unity XR eye pose status is unavailable.";
                case EyeGazeSampleFailure.PoseInvalid:
                    return source.HasEyeDataDiagnostics && source.LastCombinedPoseValidity > 0 ?
                        "Unity XR pose is invalid; native SDK reports a valid pose." :
                        "Eye pose is invalid. Check device eye tracking and calibration.";
                case EyeGazeSampleFailure.OriginUnavailable:
                    return "Unity XR eye origin is unavailable.";
                case EyeGazeSampleFailure.DirectionUnavailable:
                    return "Unity XR gaze direction is unavailable.";
                case EyeGazeSampleFailure.InvalidValues:
                    return "Eye pose has invalid numbers or a zero direction.";
                default:
                    return "Waiting for a valid eye pose.";
            }
        }

        private static string FormatValidity(int value) => value < 0 ? "--" :
            value.ToString(CultureInfo.InvariantCulture);

        private static string FormatVector(Vector3 value) => string.Format(CultureInfo.InvariantCulture,
            "{0:F3}, {1:F3}, {2:F3}", value.x, value.y, value.z);

        private static string FormatTarget(GameObject target)
        {
            if (target == null) return "--";
            string name = target.name.Replace('\n', ' ').Replace('\r', ' ');
            return name.Length <= 36 ? name : name.Substring(0, 33) + "...";
        }
    }
}
