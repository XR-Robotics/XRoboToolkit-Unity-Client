#if ENABLE_PICO_INTERACTION_PACK
using System;
using ByteDance.PICO.XR;
using UnityEngine;
using UnityEngine.XR.Interaction.Toolkit.Interactors;

namespace ByteDance.PICO.Interaction
{
    public class PXR_PinchInteractor : MonoBehaviour
    {
        public InteractorHandedness Handedness;
        public NearFarInteractor _nearFarInteractor;
        [SerializeField] private HandDragFrame _handDragFrame= new HandDragFrame();
        private Vector3 _initialDevicePosition;
        private Quaternion _initialDeviceRotation;
        private bool _hasInitialPose = false;
        HandPinchEvent _handPinchEvent = HandPinchEvent.NoneEvent;
        private Vector3 _aimPosition;
        private Quaternion _aimRotation;
        public EventParameters EventParas;
      
        public Vector3 PositionChange
        {
            get
            {
                if (!_hasInitialPose || EventParas._handTransform == null)
                    return Vector3.zero;
                return EventParas._handTransform.position - _initialDevicePosition;
            }
        }

        public Quaternion RotationChange
        {
            get
            {
                if (!_hasInitialPose || EventParas._handTransform == null)
                    return Quaternion.identity;
                return EventParas._handTransform.rotation * Quaternion.Inverse(_initialDeviceRotation);
            }
        }

        private Vector3 _perFramePositionChange;
        public Vector3 PerFramePositionChange
        {
            get
            {
              
                if (EventParas._handTransform == null)
                    return Vector3.zero;
                return _perFramePositionChange;
            }
        }
        private Vector3 _perFramehandPosition;
        public Vector3 PerFramehandPosition
        {
            get
            {
              
                if (EventParas._handTransform == null)
                    return Vector3.zero;
                return _perFramehandPosition;
            }
        }
        private Quaternion _perFrameRotationChange;
        public Quaternion PerFrameRotationChange
        {
            get
            {
                
                if (EventParas._handTransform == null)
                    return Quaternion.identity;
                return _perFrameRotationChange;
            }
        }

        private void Awake()
        {
            EventParas = new EventParameters();
            EventParas.reset();
        }

        public void SetPinchEvent(HandPinchEvent pinchEvent,Vector3 aimPosition,Quaternion aimRotation)
        {
            PDebug.InteractionLog("PXR_PinchInteractor", $"Handedness: {Handedness}, HandPinchEvent: {pinchEvent}");

            _handPinchEvent = pinchEvent;
            _aimPosition = aimPosition;
            _aimRotation = aimRotation;
        }
        public bool GetPinchDown(ref Vector3 aimPosition,ref Quaternion aimRotation)
        {
            if (_handPinchEvent == HandPinchEvent.PinchDownEvent)
            {
                aimPosition = _aimPosition;
                aimRotation = _aimRotation;
                return true;
            }
            return false;
        }

        private Vector3 cursorPos;
        public void SetCursorPos(Vector3 _cursorPos)
        {
            cursorPos = _cursorPos;
        }
        public Vector3 GetCursorPos()
        {
            return cursorPos;
        }

        public Quaternion GetCursorRotation()
        {
            return PXR_InteractorManager.InteractionData._cursorRotation;
        }
        
        public Vector3 DragFrame(Vector3 targetPos)
        {
            EventParas._location3D = _handDragFrame.drag(EventParas._handTransform.position, targetPos,
                PXR_InteractorManager.InteractionData._headOffsetPos,
                PXR_InteractorManager.InteractionData._headForward);
     
            EventParas._timestamp = Time.realtimeSinceStartup;
            EventParas._rayOrigin = PXR_InteractorManager.InteractionData._headOffsetPos;
            EventParas._rayDirection =
                (EventParas._location3D - PXR_InteractorManager.InteractionData._headOffsetPos).normalized;
    
            EventParas._devicePosition = EventParas._handTransform.position;
            EventParas._deviceRotation = EventParas._handTransform.rotation;
            EventParas._eventPhase = EventPhase.Moved;

            EventParas._headPos = PXR_InteractorManager.InteractionData._headOffsetPos;
            EventParas._headForward = PXR_InteractorManager.InteractionData._headForward;
    
            return EventParas._location3D;
        }
        public void setHandTransform(Transform handTransform)
        {
            EventParas._handTransform = handTransform;
            EventParas._devicePosition = handTransform.position;
            EventParas._deviceRotation = handTransform.rotation;
            if (!_hasInitialPose)
            {
                _initialDevicePosition = EventParas._devicePosition;
                _initialDeviceRotation = EventParas._deviceRotation;
                _hasInitialPose = true;
            }
        }
        public void setEventParas(Vector3 location3D)
        {
            EventParas._location3D = location3D;
        }
        public void setEventParas(GameObject go)
        {
            EventParas._entity = go;
        }

        public void ProcessEvent(HandPinchEvent pinchEvent)
        {
            PDebug.InteractionLog("PXR_PinchInteractor", $"ProcessEvent: {pinchEvent} {Handedness}");
            switch (pinchEvent)
            {
                case HandPinchEvent.PinchDownEvent:
                    EventParas._timestamp = Time.realtimeSinceStartup;
                    PDebug.InteractionLog("PXR_PinchInteractor", $"ProcessEvent PinchDownEvent: {EventParas._timestamp}");
                    EventParas._rayOrigin = PXR_InteractorManager.InteractionData._headOffsetPos;
                    EventParas._rayDirection =
                        (GetCursorPos() -
                         PXR_InteractorManager.InteractionData._headOffsetPos).normalized;
                    if (PXR_InteractorManager.InteractionData._interactionObject != null)
                    {
                        EventParas._entity = PXR_InteractorManager.InteractionData._interactionObject.gameObject;
                    }

                    EventParas._eventPhase = EventPhase.Began;
                    EventParas._location3D = GetCursorPos();
                    EventParas._handedness = (Handedness)Handedness;
                    EventParas._headPos = PXR_InteractorManager.InteractionData._headOffsetPos;
                    EventParas._headForward = PXR_InteractorManager.InteractionData._headForward;
                    if (_nearFarInteractor != null && !_hasInitialPose)
                    {
                        setHandTransform(_nearFarInteractor.attachTransform);
                    }

                    break;
                case HandPinchEvent.PinchUpEvent:
                    PDebug.InteractionLog("PXR_PinchInteractor", $"ProcessEvent PinchUpEvent: {EventParas._timestamp}");
                    EventParas._eventPhase = EventPhase.Ended;
                    EventParas._entity = null;
                    _handDragFrame.releaseFrame();
                    _hasInitialPose = false;
                    EventParas.reset();
                    EventParas._timestamp = Time.realtimeSinceStartup;
                    break;
                case HandPinchEvent.NoneEvent:
                    EventParas.reset();
                    _hasInitialPose = false;
                    break;
                case HandPinchEvent.PinchEvent:
                    EventParas._location3D = _handDragFrame.drag(EventParas._handTransform.position,
                        EventParas._location3D,
                        PXR_InteractorManager.InteractionData._headOffsetPos,
                        PXR_InteractorManager.InteractionData._headForward);
                    EventParas._timestamp = Time.realtimeSinceStartup;
                    PDebug.InteractionLog("PXR_PinchInteractor", $"ProcessEvent PinchEvent: {EventParas._timestamp}");
                    EventParas._rayOrigin = PXR_InteractorManager.InteractionData._headOffsetPos;
                    EventParas._rayDirection =
                        (EventParas._location3D - PXR_InteractorManager.InteractionData._headOffsetPos).normalized;

                    // _perFramePositionChange = EventParas._handTransform.position - EventParas._devicePosition;
                    _perFramePositionChange =  EventParas._devicePosition;
                    _perFrameRotationChange = EventParas._handTransform.rotation *
                                              Quaternion.Inverse(EventParas._deviceRotation);
                    _perFramehandPosition= EventParas._handTransform.position;
                    PDebug.InteractionLog(
                        "PXR_PinchInteractor",
                        $"AimInteractor Device PerFrame Change {_perFramePositionChange.ToFormattedString(4)} {_perFrameRotationChange.ToFormattedString(4)} {_perFramehandPosition.ToString("F4")}");
                    EventParas._devicePosition = EventParas._handTransform.position;
                    EventParas._deviceRotation = EventParas._handTransform.rotation;
                    EventParas._eventPhase = EventPhase.Moved;

                    EventParas._headPos = PXR_InteractorManager.InteractionData._headOffsetPos;
                    EventParas._headForward = PXR_InteractorManager.InteractionData._headForward;
                    PDebug.InteractionLog("PXR_PinchInteractor", $"ScrollFrame DeviceChange {PositionChange} {RotationChange}");
                    break;
            }
        }
        public void ResetInitialPose()
        {
            _hasInitialPose = false;
        }
        
        public void SetInitialPose(Vector3 position, Quaternion rotation)
        {
            _initialDevicePosition = position;
            _initialDeviceRotation = rotation;
            _hasInitialPose = true;
        }
    }
}
#endif
