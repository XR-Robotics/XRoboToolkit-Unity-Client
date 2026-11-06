#if ENABLE_PICO_INTERACTION_PACK
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.XR;

using ByteDance.PICO.XR;

namespace ByteDance.PICO.Interaction
{
    public class PXR_EyeGazeCursorDriver : MonoBehaviour
    {
        [SerializeField] private Transform _cursor;
#if ENABLE_PICO_OPENXR_SDK
        [SerializeField] private InputActionReference _positionAction;
        [SerializeField] private InputActionReference _rotationAction;
        [SerializeField] private InputActionReference _trackingStateAction;
#endif
        private float _headBackOffset = 0f;
        private float _headDownOffset = 0f;
        private float _defaultDistance = 10f;

        private readonly UIScale _uiScale = new UIScale();
        private CollisionObject _collisionObject;

        private Transform _attackObject;
        private PXR_Constant.ScaleParam _scaleParam = new PXR_Constant.ScaleParam();
#if ENABLE_PICO_XR_SDK
        private static bool s_EyeTrackingStartAttempted;
        private static bool s_EyeTrackingStarted;
        private static float s_EyeTrackingLastLogTime;
        private static bool s_EyeTrackingLoggedAtLeastOnce;

        private static bool TryGetEyePoseFromPicoSdk(out Vector3 origin, out Quaternion rotation)
        {
            origin = Vector3.zero;
            rotation = Quaternion.identity;

            bool isTracking = false;
            if (!s_EyeTrackingStartAttempted)
            {
                s_EyeTrackingStartAttempted = true;
                var startInfo = new EyeTrackingStartInfo
                {
                    needCalibration = 1,
                    mode = EyeTrackingMode.PXR_ETM_BOTH
                };
                int startResult = PXR_MotionTracking.StartEyeTracking(ref startInfo);
                s_EyeTrackingStarted = startResult == 0;
                PDebug.InteractionLog("PXR_EyeGazeCursorDriver",
                    $"StartEyeTracking result={startResult}, started={s_EyeTrackingStarted}, mode={startInfo.mode}, needCalibration={startInfo.needCalibration}");
            }

            bool shouldLogThisFrame = false;
#if DEBUG_INTERACTION_PACK
            float now = Time.unscaledTime;
            if (!s_EyeTrackingLoggedAtLeastOnce || now - s_EyeTrackingLastLogTime > 1f)
            {
                shouldLogThisFrame = true;
                s_EyeTrackingLoggedAtLeastOnce = true;
                s_EyeTrackingLastLogTime = now;
            }
#endif

            var state = new EyeTrackingState();
            int stateResult = PXR_MotionTracking.GetEyeTrackingState(ref isTracking, ref state);
            if (stateResult != 0 || !isTracking)
            {
                if (shouldLogThisFrame)
                    PDebug.InteractionLog("PXR_EyeGazeCursorDriver",
                        $"GetEyeTrackingState result={stateResult}, isTracking={isTracking}, mode={state.currentTrackingMode}, code={state.code}");
                return false;
            }

            var getInfo = new EyeTrackingDataGetInfo
            {
                displayTime = 0,
                flags = EyeTrackingDataGetFlags.PXR_EYE_POSITION | EyeTrackingDataGetFlags.PXR_EYE_ORIENTATION
            };

            var data = new EyeTrackingData
            {
                eyeDatas = new PerEyeData[(int)PerEyeUsage.EyeCount]
            };
            for (int i = 0; i < data.eyeDatas.Length; i++)
            {
                data.eyeDatas[i].SetVersion(PXR_MotionTracking.PXR_EYE_TRACKING_API_VERSION);
            }

            int dataResult = PXR_MotionTracking.GetEyeTrackingData(ref getInfo, ref data);
            if (dataResult != 0 || data.eyeDatas == null || data.eyeDatas.Length <= (int)PerEyeUsage.Combined)
            {
                if (shouldLogThisFrame)
                    PDebug.InteractionLog("PXR_EyeGazeCursorDriver",
                        $"GetEyeTrackingData result={dataResult}, eyeDatasNull={(data.eyeDatas == null)}, eyeDatasLen={(data.eyeDatas != null ? data.eyeDatas.Length : -1)}");
                return false;
            }

            var combined = data.eyeDatas[(int)PerEyeUsage.Combined];
            if (combined.isPoseValid == 0)
            {
                if (shouldLogThisFrame)
                    PDebug.InteractionLog("PXR_EyeGazeCursorDriver",
                        $"EyeTrackingData combined pose invalid. isPoseValid={combined.isPoseValid}");
                return false;
            }

            origin = new Vector3(combined.pose.position.x, combined.pose.position.y, -combined.pose.position.z);
            rotation = new Quaternion(
                combined.pose.orientation.x,
                combined.pose.orientation.y,
                -combined.pose.orientation.z,
                -combined.pose.orientation.w
            );
            if (shouldLogThisFrame)
                PDebug.InteractionLog("PXR_EyeGazeCursorDriver",
                    $"EyePose ok. origin={origin:F4}, rotation={rotation.eulerAngles:F2}, forward={(rotation * Vector3.forward):F4}");
            return true;
        }
#endif

        public Vector3 GetEyeForward(out int trackingState, out Vector3 origin, out Quaternion rotation)
        {
            origin = Vector3.zero;
            rotation = Quaternion.identity;
            trackingState = 0;
#if ENABLE_PICO_XR_SDK
            if (TryGetEyePoseFromPicoSdk(out origin, out rotation))
            {
                trackingState = (int)(InputTrackingState.Position | InputTrackingState.Rotation);
               
            }
            return rotation * Vector3.forward;
#elif ENABLE_PICO_OPENXR_SDK
            var action = _trackingStateAction != null ? _trackingStateAction.action : null;
            trackingState = action != null ? action.ReadValue<int>() : 0;
            if (trackingState > 0 && _positionAction != null && _rotationAction != null)
            {
                var positionAction = _positionAction.action;
                var rotationAction = _rotationAction.action;
                if (positionAction != null && rotationAction != null)
                {
                    origin = positionAction.ReadValue<Vector3>();
                    rotation = rotationAction.ReadValue<Quaternion>();
                    return rotation * Vector3.forward;
                }
            }

            trackingState = (int)(InputTrackingState.Position | InputTrackingState.Rotation);
            origin = CameraUtility.MainCameraTransform.position;
            rotation = CameraUtility.MainCameraTransform.rotation;
            return rotation * Vector3.forward;
#else
            trackingState = (int)(InputTrackingState.Position | InputTrackingState.Rotation);
            origin = CameraUtility.MainCameraTransform.position;
            rotation = CameraUtility.MainCameraTransform.rotation;
            return rotation * Vector3.forward;
#endif
        }

        public Vector3 GetHeadOffsetPos()
        {
            Transform cam = CameraUtility.MainCameraTransform;
            if (cam == null) return Vector3.zero;
            return cam.position - (cam.forward * _headBackOffset) - (cam.up * _headDownOffset);
        }

        public void DriveCursorAndUpdateInteractionData()
        {
            Vector3 headOffsetPos = GetHeadOffsetPos();
            var data = PXR_InteractorManager.InteractionData;
            data._headOffsetPos = headOffsetPos;

            data._headForward = GetEyeForward(out _, out _, out _);

            if (_cursor == null)
            {
                PXR_InteractorManager.InteractionData = data;
                return;
            }

            if (InteractionUtil.CollisionTool.isRay(headOffsetPos, data._headForward, out _collisionObject))
            {
                _cursor.position = _collisionObject.Pos;
                 _cursor.forward = _collisionObject.Normal;

                data._cursorPos = _cursor.position;
                data._cursorRotation = _cursor.rotation;
                data._interactionObject = _collisionObject.CollisionTran;
                if (data._interactionObject != _attackObject)
                {
                    data.isSwitchObject = true;
                    _attackObject = data._interactionObject;
                }
            }
            else
            {
                Transform head = CameraUtility.MainCameraTransform;
                _cursor.position = data._headOffsetPos + data._headForward * _defaultDistance;
                if (_cursor.childCount > 0)
                    _cursor.GetChild(0).localRotation = Quaternion.identity;
                _cursor.LookAt(head.position, head.up);

                data._cursorPos = _cursor.position;
                data._cursorRotation = _cursor.rotation;
                data.isSwitchObject = false;
                data._interactionObject = null;
                _attackObject = null;
            }

            PXR_InteractorManager.InteractionData = data;

            if (_scaleParam != null)
            {
                float scale = _uiScale.ScaleGrap(Vector3.Distance(_cursor.position, headOffsetPos), _scaleParam);
                _cursor.localScale = Vector3.one * scale;
            }
        }
        public bool changeWindow(Transform mouseCollisionObject) 
        {
             var data = PXR_InteractorManager.InteractionData;
            if(mouseCollisionObject != _attackObject && data.isSwitchObject)
            {
                return true;
            }
            return false;
        }
#if ENABLE_PICO_XR_SDK
        private void OnDestroy()
        {
            if (!s_EyeTrackingStarted)
                return;

            var stopInfo = new EyeTrackingStopInfo();
            PXR_MotionTracking.StopEyeTracking(ref stopInfo);
            s_EyeTrackingStarted = false;
            s_EyeTrackingStartAttempted = false;
        }
#endif
    }
}
#endif
