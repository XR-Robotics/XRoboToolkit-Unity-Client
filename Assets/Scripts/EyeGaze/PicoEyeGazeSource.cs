using UnityEngine;
#if PICO_XR && UNITY_ANDROID && !UNITY_EDITOR
using ByteDance.PICO.XR;
#endif

namespace Robot
{
    public enum EyeGazeStatus
    {
        Disabled,
        EditorSimulationOff,
        UnsupportedPlatform,
        MissingCamera,
        Suspended,
        EyeTrackingDisabled,
        UnsupportedDevice,
        ServiceUnavailable,
        WaitingForValidPose,
        Valid,
        Simulated
    }

    public enum EditorGazeMode
    {
        Off,
        CameraLocalDirection,
        Mouse
    }

    public enum EyeGazeSampleFailure
    {
        None,
        StatusUnavailable,
        PoseInvalid,
        OriginUnavailable,
        DirectionUnavailable,
        InvalidValues
    }

    [DisallowMultipleComponent]
    [DefaultExecutionOrder(100)]
    public sealed class PicoEyeGazeSource : MonoBehaviour
    {
        [SerializeField] private Camera gazeCamera;
        [SerializeField] private bool trackingRequested;
        [Tooltip("Request calibration once when this component starts its first eye tracking session.")]
        [SerializeField] private bool requestCalibrationOnFirstStart;
        [SerializeField, Min(0.5f)] private float serviceRetrySeconds = 2f;
        [SerializeField] private bool logStatusChanges = true;
#if UNITY_EDITOR
        [Header("Editor simulation (F8 switches mouse simulation, F9 switches validity)")]
        [SerializeField] private EditorGazeMode editorGazeMode;
        [SerializeField] private bool simulatedPoseValid = true;
        [SerializeField] private Vector3 simulatedLocalOrigin;
        [SerializeField] private Vector3 simulatedLocalDirection = Vector3.forward;
#endif
        [Header("Runtime state")]
        [SerializeField] private EyeGazeStatus status = EyeGazeStatus.Disabled;
        [SerializeField] private Vector3 worldOrigin;
        [SerializeField] private Vector3 worldDirection;
        [SerializeField] private int lastSdkResult;
        [SerializeField] private EyeGazeSampleFailure sampleFailure;
        [SerializeField] private uint combinedPoseStatus;
        [SerializeField] private int lastEyeDataResult;
        [SerializeField] private int lastLeftPoseValidity = -1;
        [SerializeField] private int lastRightPoseValidity = -1;
        [SerializeField] private int lastCombinedPoseValidity = -1;

        private Ray _worldRay;
        private int _sampleFrame = -1;
        private bool _paused;
        private bool _hasEyeDataDiagnostics;
#if PICO_XR && UNITY_ANDROID && !UNITY_EDITOR
        private bool _applicationFocused = true;
        private volatile bool _xrFocused = true;
        private bool _ownsSession;
        private bool _serviceReady;
        private bool _calibrationRequested;
        private float _nextServiceCheck;
        private float _nextPoseDiagnostics;
        private int _validPoseSamples;
        private int _invalidPoseSamples;
#endif

        public Camera GazeCamera => gazeCamera;
        public EyeGazeStatus Status => status;
        public int LastSdkResult => lastSdkResult;
        public EyeGazeSampleFailure SampleFailure => sampleFailure;
        public uint CombinedPoseStatus => combinedPoseStatus;
        public bool HasEyeDataDiagnostics => TrackingRequested && _hasEyeDataDiagnostics;
        public int LastEyeDataResult => lastEyeDataResult;
        public int LastLeftPoseValidity => lastLeftPoseValidity;
        public int LastRightPoseValidity => lastRightPoseValidity;
        public int LastCombinedPoseValidity => lastCombinedPoseValidity;
        public bool IsSimulated => status == EyeGazeStatus.Simulated;
        public bool HasValidSample => isActiveAndEnabled && _sampleFrame == Time.frameCount;
        public Vector3 WorldOrigin => HasValidSample ? worldOrigin : Vector3.zero;
        public Vector3 WorldDirection => HasValidSample ? worldDirection : Vector3.zero;
        public Ray WorldRay => HasValidSample ? _worldRay : default;
        public event System.Action<bool> TrackingRequestedChanged;
        public bool TrackingRequested
        {
            get
            {
#if UNITY_EDITOR
                return editorGazeMode != EditorGazeMode.Off;
#else
                return trackingRequested;
#endif
            }
        }

        /// <summary>Use the same activation path for the UI toggle and the editor shortcut.</summary>
        public void SetTrackingRequested(bool requested)
        {
            bool previous = TrackingRequested;
            trackingRequested = requested;
            ClearEyeDataDiagnostics();
#if UNITY_EDITOR
            editorGazeMode = requested ? EditorGazeMode.Mouse : EditorGazeMode.Off;
#elif PICO_XR && UNITY_ANDROID
            _nextServiceCheck = 0f;
            if (!requested)
                StopOwnedSession();
#endif
            ClearSample();
            if (previous != TrackingRequested)
                TrackingRequestedChanged?.Invoke(TrackingRequested);
        }

        private void OnValidate()
        {
            serviceRetrySeconds = Mathf.Max(0.5f, serviceRetrySeconds);
        }

        private void OnEnable()
        {
            ClearEyeDataDiagnostics();
            if (gazeCamera == null)
                gazeCamera = GetComponentInChildren<Camera>() ?? Camera.main;
#if PICO_XR && UNITY_ANDROID && !UNITY_EDITOR
            _applicationFocused = Application.isFocused;
            _xrFocused = true;
            _nextServiceCheck = 0f;
            PXR_Plugin.System.FocusStateAcquired += OnXrFocusAcquired;
            PXR_Plugin.System.FocusStateLost += OnXrFocusLost;
#endif
        }

        private void LateUpdate()
        {
            ClearSample();
#if UNITY_EDITOR
            if (Input.GetKeyDown(KeyCode.F8))
                SetTrackingRequested(!TrackingRequested);
            if (Input.GetKeyDown(KeyCode.F9))
                simulatedPoseValid = !simulatedPoseValid;
#endif
            if (!TrackingRequested)
            {
                SetStatus(Application.isEditor ? EyeGazeStatus.EditorSimulationOff : EyeGazeStatus.Disabled);
                return;
            }
            if (_paused)
            {
                ClearEyeDataDiagnostics();
                SetStatus(EyeGazeStatus.Suspended);
                return;
            }
            if (gazeCamera == null || !gazeCamera.isActiveAndEnabled)
            {
                ClearEyeDataDiagnostics();
                SetStatus(EyeGazeStatus.MissingCamera);
                return;
            }
#if UNITY_EDITOR
            ReadSimulatedPose();
#elif PICO_XR && UNITY_ANDROID
            if (!_applicationFocused || !_xrFocused)
            {
                ClearEyeDataDiagnostics();
                SetStatus(EyeGazeStatus.Suspended);
                return;
            }
            if (!EnsureService())
            {
                ClearEyeDataDiagnostics();
                return;
            }
            bool valid = ReadDevicePose();
            SetStatus(valid ? EyeGazeStatus.Valid : EyeGazeStatus.WaitingForValidPose);
            if (valid)
                _validPoseSamples++;
            else
                _invalidPoseSamples++;
            UpdateEyeDataDiagnostics();
#else
            SetStatus(EyeGazeStatus.UnsupportedPlatform);
#endif
        }

        private bool PublishPose(Vector3 localOrigin, Vector3 localDirection)
        {
            if (!EyeGazeMath.TryCreateWorldRay(gazeCamera.transform, localOrigin, localDirection,
                    out _worldRay))
                return false;
            worldOrigin = _worldRay.origin;
            worldDirection = _worldRay.direction;
            _sampleFrame = Time.frameCount;
            return true;
        }

        private void ClearSample()
        {
            _sampleFrame = -1;
            _worldRay = default;
            worldOrigin = Vector3.zero;
            worldDirection = Vector3.zero;
            sampleFailure = EyeGazeSampleFailure.None;
            combinedPoseStatus = 0;
        }

        private void ClearEyeDataDiagnostics()
        {
            _hasEyeDataDiagnostics = false;
            lastEyeDataResult = 0;
            lastLeftPoseValidity = -1;
            lastRightPoseValidity = -1;
            lastCombinedPoseValidity = -1;
#if PICO_XR && UNITY_ANDROID && !UNITY_EDITOR
            _nextPoseDiagnostics = 0f;
            _validPoseSamples = 0;
            _invalidPoseSamples = 0;
#endif
        }

#if UNITY_EDITOR
        private void ReadSimulatedPose()
        {
            if (editorGazeMode == EditorGazeMode.Off)
            {
                SetStatus(EyeGazeStatus.EditorSimulationOff);
                return;
            }
            Vector3 direction = simulatedLocalDirection;
            if (editorGazeMode == EditorGazeMode.Mouse)
            {
                Vector3 mousePosition = Input.mousePosition;
                if (!gazeCamera.pixelRect.Contains(mousePosition))
                {
                    SetStatus(EyeGazeStatus.WaitingForValidPose);
                    return;
                }
                direction = gazeCamera.transform.InverseTransformDirection(
                    gazeCamera.ScreenPointToRay(mousePosition).direction);
            }
            if (!simulatedPoseValid || !PublishPose(simulatedLocalOrigin, direction))
            {
                SetStatus(EyeGazeStatus.WaitingForValidPose);
                return;
            }
            SetStatus(EyeGazeStatus.Simulated);
        }
#endif

#if PICO_XR && UNITY_ANDROID && !UNITY_EDITOR
        private bool ReadDevicePose()
        {
            // Swan can return gaze validity flags despite the SDK's documented 0/1 status.
            if (!PXR_EyeTracking.GetCombinedEyePoseStatus(out combinedPoseStatus))
                sampleFailure = EyeGazeSampleFailure.StatusUnavailable;
            else if (!EyeGazeMath.IsCombinedEyePoseValid(combinedPoseStatus))
                sampleFailure = EyeGazeSampleFailure.PoseInvalid;
            else if (!PXR_EyeTracking.GetCombineEyeGazePoint(out Vector3 origin))
                sampleFailure = EyeGazeSampleFailure.OriginUnavailable;
            else if (!PXR_EyeTracking.GetCombineEyeGazeVector(out Vector3 direction))
                sampleFailure = EyeGazeSampleFailure.DirectionUnavailable;
            else if (!PublishPose(origin, direction))
                sampleFailure = EyeGazeSampleFailure.InvalidValues;
            return sampleFailure == EyeGazeSampleFailure.None;
        }

        private void UpdateEyeDataDiagnostics()
        {
            if (Time.unscaledTime < _nextPoseDiagnostics)
                return;
            _nextPoseDiagnostics = Time.unscaledTime + Mathf.Max(2f, serviceRetrySeconds);
            var getInfo = new EyeTrackingDataGetInfo
            {
                displayTime = 0,
                flags = EyeTrackingDataGetFlags.PXR_EYE_POSITION |
                        EyeTrackingDataGetFlags.PXR_EYE_ORIENTATION
            };
            // A fresh buffer prevents a failed/partial query from retaining a previous valid pose.
            var data = new EyeTrackingData
            {
                eyeDatas = new PerEyeData[(int)PerEyeUsage.EyeCount]
            };
            for (int i = 0; i < data.eyeDatas.Length; i++)
                data.eyeDatas[i].SetVersion(PXR_MotionTracking.PXR_EYE_TRACKING_API_VERSION);
            lastEyeDataResult = PXR_MotionTracking.GetEyeTrackingData(ref getInfo, ref data);
            _hasEyeDataDiagnostics = true;
            lastLeftPoseValidity = -1;
            lastRightPoseValidity = -1;
            lastCombinedPoseValidity = -1;
            bool hasData = lastEyeDataResult == (int)TrackingStateCode.PXR_MT_SUCCESS &&
                           data.eyeDatas != null &&
                           data.eyeDatas.Length >= (int)PerEyeUsage.EyeCount;
            if (hasData)
            {
                lastLeftPoseValidity = data.eyeDatas[(int)PerEyeUsage.LeftEye].isPoseValid;
                lastRightPoseValidity = data.eyeDatas[(int)PerEyeUsage.RightEye].isPoseValid;
                lastCombinedPoseValidity = data.eyeDatas[(int)PerEyeUsage.Combined].isPoseValid;
            }
            if (!logStatusChanges)
                return;
            string nativePose = hasData
                ? data.eyeDatas[(int)PerEyeUsage.Combined].pose.ToString()
                : "unavailable";
            Debug.Log($"[EyeGaze] Pose diagnostics: status={status}, failure={sampleFailure}, " +
                      $"xrCombinedStatus={combinedPoseStatus}, serviceResult={lastSdkResult}, " +
                      $"eyeDataResult={lastEyeDataResult}, nativeValid(L/R/C)=" +
                      $"{lastLeftPoseValidity}/{lastRightPoseValidity}/{lastCombinedPoseValidity}, " +
                      $"samples(valid/invalid)={_validPoseSamples}/{_invalidPoseSamples}, " +
                      $"nativeCombined={nativePose}.", this);
        }

        private bool EnsureService()
        {
            var manager = PXR_Manager.Instance;
            if (manager == null || !manager.eyeTracking)
            {
                _serviceReady = false;
                StopOwnedSession();
                SetStatus(EyeGazeStatus.EyeTrackingDisabled);
                return false;
            }
            if (Time.unscaledTime < _nextServiceCheck)
                return _serviceReady;
            _nextServiceCheck = Time.unscaledTime + Mathf.Max(0.5f, serviceRetrySeconds);
            bool supported = false;
            int modeCount = 0;
            var modes = new EyeTrackingMode[(int)EyeTrackingMode.PXR_ETM_COUNT];
            lastSdkResult = PXR_MotionTracking.GetEyeTrackingSupported(ref supported, ref modeCount,
                ref modes);
            if (lastSdkResult != (int)TrackingStateCode.PXR_MT_SUCCESS || !supported)
            {
                _serviceReady = false;
                SetStatus(lastSdkResult == (int)TrackingStateCode.PXR_MT_SUCCESS ||
                          lastSdkResult == (int)TrackingStateCode.PXR_MT_DEVICE_NOT_SUPPORT
                    ? EyeGazeStatus.UnsupportedDevice : EyeGazeStatus.ServiceUnavailable);
                return false;
            }

            bool running = false;
            var state = new EyeTrackingState();
            lastSdkResult = PXR_MotionTracking.GetEyeTrackingState(ref running, ref state);
            if (lastSdkResult != (int)TrackingStateCode.PXR_MT_SUCCESS &&
                lastSdkResult != (int)TrackingStateCode.PXR_MT_SERVICE_NEED_START)
            {
                _serviceReady = false;
                SetStatus(EyeGazeStatus.ServiceUnavailable);
                return false;
            }
            if (running && state.code == TrackingStateCode.PXR_MT_SUCCESS)
            {
                // Reuse a session owned by another component without stopping it later.
                _serviceReady = true;
                return true;
            }
            if (running)
            {
                _serviceReady = false;
                lastSdkResult = (int)state.code;
                SetStatus(EyeGazeStatus.ServiceUnavailable);
                return false;
            }
            _ownsSession = false;
            var startInfo = new EyeTrackingStartInfo
            {
                mode = EyeTrackingMode.PXR_ETM_BOTH,
                // The SDK uses 0 for "needs calibration" and 1 for "does not need".
                needCalibration = (byte)(requestCalibrationOnFirstStart && !_calibrationRequested ? 0 : 1)
            };
            lastSdkResult = PXR_MotionTracking.StartEyeTracking(ref startInfo);
            _serviceReady = lastSdkResult == (int)TrackingStateCode.PXR_MT_SUCCESS;
            _ownsSession = _serviceReady;
            if (_serviceReady)
            {
                _calibrationRequested = true;
                Debug.Log("[EyeGaze] Started binocular eye tracking.", this);
            }
            else
                SetStatus(EyeGazeStatus.ServiceUnavailable);
            return _serviceReady;
        }

        private void StopOwnedSession()
        {
            _serviceReady = false;
            if (!_ownsSession)
                return;
            var stopInfo = new EyeTrackingStopInfo();
            int result = PXR_MotionTracking.StopEyeTracking(ref stopInfo);
            if (result == (int)TrackingStateCode.PXR_MT_SUCCESS ||
                result == (int)TrackingStateCode.PXR_MT_SERVICE_NEED_START)
                _ownsSession = false;
            else
                Debug.LogWarning($"[EyeGaze] StopEyeTracking failed: {result}.", this);
        }

        // SDK callbacks only update flags; all Unity and SDK work stays on the main thread.
        private void OnXrFocusAcquired() => _xrFocused = true;
        private void OnXrFocusLost() => _xrFocused = false;
#endif

        private void OnApplicationPause(bool paused)
        {
            _paused = paused;
            ClearSample();
            ClearEyeDataDiagnostics();
#if PICO_XR && UNITY_ANDROID && !UNITY_EDITOR
            if (paused)
                StopOwnedSession();
            else
                _nextServiceCheck = 0f;
#endif
        }

        private void OnApplicationFocus(bool focused)
        {
#if PICO_XR && UNITY_ANDROID && !UNITY_EDITOR
            _applicationFocused = focused;
            if (!focused)
            {
                ClearSample();
                ClearEyeDataDiagnostics();
            }
            else
                _nextServiceCheck = 0f;
#endif
        }

        private void OnDisable()
        {
#if PICO_XR && UNITY_ANDROID && !UNITY_EDITOR
            PXR_Plugin.System.FocusStateAcquired -= OnXrFocusAcquired;
            PXR_Plugin.System.FocusStateLost -= OnXrFocusLost;
            StopOwnedSession();
#endif
            ClearSample();
            ClearEyeDataDiagnostics();
            SetStatus(EyeGazeStatus.Disabled);
        }

        private void SetStatus(EyeGazeStatus next)
        {
            if (status == next)
                return;
            status = next;
            if (logStatusChanges && next != EyeGazeStatus.WaitingForValidPose &&
                next != EyeGazeStatus.Valid && next != EyeGazeStatus.Simulated)
                Debug.Log($"[EyeGaze] Status={next}, sdkResult={lastSdkResult}.", this);
        }
    }
}
