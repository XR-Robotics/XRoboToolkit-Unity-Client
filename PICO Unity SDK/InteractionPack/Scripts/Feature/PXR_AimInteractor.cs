#if ENABLE_PICO_INTERACTION_PACK
using ByteDance.PICO.XR;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.XR;
using UnityEngine.XR;
using UnityEngine.XR.Interaction.Toolkit.Inputs;
using UnityEngine.XR.Interaction.Toolkit.Interactors;

namespace ByteDance.PICO.Interaction
{
    public class PXR_AimInteractor : MonoBehaviour
    {
        private string Tag = "**AimInteractor**";
        private float _updateInputActionLastLogTime = -999f;
        
        private PXR_EyeGazeCursorDriver _eyeGazeCursorDriver;
      
        private AimUpdateType _currentAimUpdateType = AimUpdateType.EyeGaze;
        public HandParameters left;
        public HandParameters right;
        private void Awake()
        {
            PXR_InteractionLayout.RegisterLayout();
            left = new HandParameters();
            right = new HandParameters();

            _eyeGazeCursorDriver = GetComponent<PXR_EyeGazeCursorDriver>();
            if (_eyeGazeCursorDriver == null)
                _eyeGazeCursorDriver = gameObject.AddComponent<PXR_EyeGazeCursorDriver>();
        }

        private void OnEnable()
        {
            PXR_InteractorManager.LeftPinchAction += onLeftPinchEvent;
            PXR_InteractorManager.RightPinchAction += onRightPinchEvent;
            EnablePicoInteractionUtilitiesActionMaps();
        }

        private void OnDisable()
        {
            PXR_InteractorManager.LeftPinchAction -= onLeftPinchEvent;
            PXR_InteractorManager.RightPinchAction -= onRightPinchEvent;
        }

        void Start()
        {
            Reset();
            CreateInteractionLayouts();
            EnablePicoInteractionUtilitiesActionMaps();
        }

        private static void EnablePicoInteractionUtilitiesActionMaps()
        {
            var asset = FindPicoInteractionUtilitiesAsset();
            if (asset != null)
            {
                var map = asset.FindActionMap("PICO Interaction Utilities", false);
                if (map != null && !map.enabled)
                    map.Enable();
                return;
            }

            var drivers = Object.FindObjectsOfType<TrackedPoseDriver>(true);
            foreach (var driver in drivers)
            {
                if (driver == null)
                    continue;

                EnablePicoInteractionUtilitiesActionMap(driver.positionInput.action);
                EnablePicoInteractionUtilitiesActionMap(driver.rotationInput.action);
                EnablePicoInteractionUtilitiesActionMap(driver.trackingStateInput.action);
            }
        }

        private static InputActionAsset FindPicoInteractionUtilitiesAsset()
        {
#if UNITY_EDITOR
            var guids = UnityEditor.AssetDatabase.FindAssets("PICOInteractionUtilities t:InputActionAsset");
            foreach (var guid in guids)
            {
                var path = UnityEditor.AssetDatabase.GUIDToAssetPath(guid);
                if (!path.EndsWith("PICOInteractionUtilities.inputactions"))
                    continue;
                var asset = UnityEditor.AssetDatabase.LoadAssetAtPath<InputActionAsset>(path);
                if (asset != null)
                    return asset;
            }
#endif

            var assets = Resources.FindObjectsOfTypeAll<InputActionAsset>();
            foreach (var a in assets)
            {
                if (a == null)
                    continue;
                if (a.name == "PICOInteractionUtilities")
                    return a;
            }

            return null;
        }

        private static void EnablePicoInteractionUtilitiesActionMap(InputAction action)
        {
            if (action == null)
                return;

            var map = action.actionMap;
            if (map == null)
                return;

            if (map.name != "PICO Interaction Utilities")
                return;

            if (!map.enabled)
                map.Enable();
        }

        private void onLeftPinchEvent(HandPinchEvent _event)
        {
           left._handPinchEvent = _event;
            if (_event==HandPinchEvent.PinchDownEvent)
            {
                GetEyeForward(out var eyeTrackingState, out Vector3 origin, out var rotation) ;
                left._aimPosition = origin;
               left._aimRotation = rotation;
            }
        }

        private void onRightPinchEvent(HandPinchEvent _event)
        {
           right._handPinchEvent = _event;
            if (_event==HandPinchEvent.PinchDownEvent)
            {
                GetEyeForward(out var eyeTrackingState, out Vector3 origin, out var rotation) ;
                right._aimPosition = origin;
                right._aimRotation = rotation;
            }
        }
        void CreateInteractionLayouts()
        {
            if (PXR_InteractionLayout.leftHand == null)
                PXR_InteractionLayout.leftHand =
                    PXR_InteractionLayout.CreatePICOInteraction(InputDeviceCharacteristics.Left);

            if (PXR_InteractionLayout.rightHand == null)
                PXR_InteractionLayout.rightHand =
                    PXR_InteractionLayout.CreatePICOInteraction(InputDeviceCharacteristics.Right);
        }

        void DestroyInteractionLayouts()
        {
            if (PXR_InteractionLayout.leftHand != null)
            {
                InputSystem.RemoveDevice(PXR_InteractionLayout.leftHand);
                PXR_InteractionLayout.leftHand = null;
            }

            if (PXR_InteractionLayout.rightHand != null)
            {
                InputSystem.RemoveDevice(PXR_InteractionLayout.rightHand);
                PXR_InteractionLayout.rightHand = null;
            }
        }
        
        private HandParameters getHandParameters()
        {
            return _currentAimUpdateType == AimUpdateType.UIScrollbyLeft?left:right;
        }

        private void setHandParameters(Vector3 aimPosition, Quaternion aimRotation)
        {
            if (_currentAimUpdateType == AimUpdateType.UIScrollbyLeft)
            {
                left._aimRotation = aimRotation;
                left._aimPosition = aimPosition;
            }
            else if (_currentAimUpdateType == AimUpdateType.UIScrollbyRight)
            {
                right._aimRotation = aimRotation;
                right._aimPosition = aimPosition;
            }
        }
        private void ChangeAimUpdateType(AimUpdateType _type)
        {
            _currentAimUpdateType = _type;
        }
        public static Vector3 WorldPointToPoseLocal( Vector3 worldPoint, in Pose targetPose)
        {
            Vector3 worldOffset = worldPoint - targetPose.position;
            Quaternion normalRot = targetPose.rotation.normalized;
            Vector3 localPoint = Quaternion.Inverse(normalRot) * worldOffset;
            return localPoint;
        }
        private void UpdateAimPose(ref Vector3 aimPosition,ref Quaternion aimRotation)
        {
            if (_currentAimUpdateType == AimUpdateType.UIScrollbyLeft||_currentAimUpdateType == AimUpdateType.UIScrollbyRight)
            {
                var _HandParameters = getHandParameters();
             
                aimPosition = _HandParameters._aimPosition;
                aimRotation=_HandParameters._aimRotation;

                var lasthandPosition = PXR_InteractorManager.Instance.PerFramePinchPositionChange();
                var framehandPosition = PXR_InteractorManager.Instance.PerFramehandPosition();


                var lastLocalPoint = WorldPointToPoseLocal(lasthandPosition,
                    new Pose(CameraUtility.MainCameraTransform.position, CameraUtility.MainCameraTransform.rotation));
                var frameLocalPoint = WorldPointToPoseLocal(framehandPosition,
                    new Pose(CameraUtility.MainCameraTransform.position, CameraUtility.MainCameraTransform.rotation));
                
                var vec = frameLocalPoint - lastLocalPoint;
                
                float absDeltaX = Mathf.Abs(vec.x);
                float absDeltaY = Mathf.Abs(vec.y);
               
                if (absDeltaY > absDeltaX)
                {
                    aimRotation = QuaternionLocalRotationTool.RotateLocalX(aimRotation,  -vec.y*PXR_Constant.ScrollMultiple);
                }
                else if (absDeltaY < absDeltaX)
                {
                    aimRotation = QuaternionLocalRotationTool.RotateLocalY(aimRotation,  vec.x*PXR_Constant.ScrollMultiple);
                }
                setHandParameters(aimPosition,aimRotation);
            }

        }

        private void UpdateInputAction(int trackingState, Vector3 aimPosition, Quaternion aimRotation)
        {
#if DEBUG_Interaction_PACK
            float now = Time.unscaledTime;
            if (now - _updateInputActionLastLogTime > 1f)
            {
                _updateInputActionLastLogTime = now;
                PLog.InteractionLog(Tag , " UpdateInputAction inputMode:" + PXR_InteractorManager.Instance.CurrentInputMode +
                          " aimType:" + _currentAimUpdateType +
                          " trackingState:" + trackingState +
                          " aimPos:" + aimPosition.ToString("F3") +
                          " aimEuler:" + aimRotation.eulerAngles.ToString("F1"));
            }
#endif

            if (PXR_InteractorManager.Instance.CurrentInputMode!=XRInputModalityManager.InputMode.TrackedHand)
            {
                if (PXR_InteractionLayout.leftHand != null)
                    PXR_InteractionLayout.leftHand.UpdatePICOInteraction(false, aimPosition, aimRotation);
                if (PXR_InteractionLayout.rightHand != null)
                    PXR_InteractionLayout.rightHand.UpdatePICOInteraction(false, aimPosition, aimRotation);
                return;
            }

            if (_currentAimUpdateType!=PXR_InteractorManager.Instance.CurrentAimUpdateType)
            {
                ChangeAimUpdateType(PXR_InteractorManager.Instance.CurrentAimUpdateType);
            }
     
            if ( _currentAimUpdateType== AimUpdateType.EyeGaze)
            {
                if (PXR_InteractionLayout.leftHand != null)
                {
                    PXR_InteractorManager.Instance.GetPinchInteractor(InteractorHandedness.Left).GetPinchDown(ref aimPosition, ref aimRotation);
                    PXR_InteractionLayout.leftHand.UpdatePICOInteraction(trackingState > 0, aimPosition, aimRotation);
                }

                if (PXR_InteractionLayout.rightHand != null)
                {
                    PXR_InteractionLayout.rightHand.UpdatePICOInteraction(trackingState > 0, aimPosition, aimRotation);
                }
            }
            else if (_currentAimUpdateType == AimUpdateType.UIScrollbyLeft)
            {
                UpdateAimPose(ref aimPosition,ref aimRotation);
                if (PXR_InteractionLayout.leftHand != null)
                    PXR_InteractionLayout.leftHand.UpdatePICOInteraction(true, aimPosition, aimRotation);
                if (PXR_InteractionLayout.rightHand != null)
                    PXR_InteractionLayout.rightHand.UpdatePICOInteraction(false, aimPosition, aimRotation);
            }
            else if (_currentAimUpdateType == AimUpdateType.UIScrollbyRight)
            {
                UpdateAimPose(ref aimPosition,ref aimRotation);
                if (PXR_InteractionLayout.leftHand != null)
                    PXR_InteractionLayout.leftHand.UpdatePICOInteraction(false, aimPosition, aimRotation);
                if (PXR_InteractionLayout.rightHand != null)
                    PXR_InteractionLayout.rightHand.UpdatePICOInteraction(true, aimPosition, aimRotation);
            }
        }

        public Vector3 GetEyeForward(out int trackingState, out Vector3 origin, out Quaternion rotation)
        {
            if (_eyeGazeCursorDriver != null)
                return _eyeGazeCursorDriver.GetEyeForward(out trackingState, out origin, out rotation);

            origin = Vector3.zero;
            rotation = Quaternion.identity;
            trackingState=0;

            return rotation * Vector3.forward;
        }

        private void Update()
        {
            if (_eyeGazeCursorDriver != null)
            {
                _eyeGazeCursorDriver.DriveCursorAndUpdateInteractionData();
                _eyeGazeCursorDriver.GetEyeForward(out var eyeTrackingState, out var eyeOrigin, out var eyeRotation);
                UpdateInputAction(eyeTrackingState, eyeOrigin, eyeRotation);
                return;
            }

            GetEyeForward(out var fallbackTrackingState, out var fallbackOrigin, out var fallbackRotation);
            UpdateInputAction(fallbackTrackingState, fallbackOrigin, fallbackRotation);
        }
        public void Reset()
        {
            gameObject.SetActive(true);
        }
        private void OnDestroy()
        {
            DestroyInteractionLayouts();
        }
    }
    public enum AimUpdateType
    {
        EyeGaze,
        UIScrollbyLeft,
        UIScrollbyRight,
    }
}
#endif
