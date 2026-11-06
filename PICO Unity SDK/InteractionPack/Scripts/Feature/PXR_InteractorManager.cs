﻿﻿﻿﻿﻿#if ENABLE_PICO_INTERACTION_PACK
using System;
using System.Collections;
using System.Collections.Generic;
using ByteDance.PICO.XR;
using UnityEngine;
using UnityEngine.XR.Interaction.Toolkit;
using UnityEngine.XR.Interaction.Toolkit.Inputs;
using UnityEngine.XR.Interaction.Toolkit.Interactors;
using UnityEngine.XR.Interaction.Toolkit.UI;

namespace ByteDance.PICO.Interaction
{
    public class PXR_InteractorManager : MonoBehaviour
    {
        private const string TAG = "[PXR_InteractorManager]";

        #region Internal Types

        private class HandState
        {
            public float LastStateChangeTime;
            public Transform CurrentInteractable;
            public Coroutine AntiShakeCoroutine;
            public bool IsSelecting;
        }

        #endregion

        private XRInputModalityManager _xrInputModality;
        private PXR_AimInteractor _aimInteractor;
        private PXR_PinchInteractor _pinchInteractorLeft;
        private PXR_PinchInteractor _pinchInteractorRight;
        private List<NearFarInteractor> _nearFarInteractors = new List<NearFarInteractor>();

        #region Actions

        public static event Action<InteractorHandedness> PinchUpAction;
        public static event Action<InteractorHandedness> PinchDownAction;
        public static event Action<HandPinchEvent> LeftPinchAction;
        public static event Action<HandPinchEvent> RightPinchAction;

        public static event Action<XRInputModalityManager.InputMode> InputModeChangeAction;
        public static event Action<InteractorHandedness, Transform> SelectEnterAction;
        public static event Action<InteractorHandedness, Transform> SelectExitAction;

        #endregion
        private int antiShakeThreshold = 200; 
        private HandState _leftHandState = new HandState();
        private HandState _rightHandState = new HandState();
        private XRInputModalityManager.InputMode _currentInputMode = XRInputModalityManager.InputMode.None;
        private static PXR_InteractorManager instance = null;

        public static PXR_InteractorManager Instance
        {
            get
            {
                if (instance == null)
                {
#if UNITY_6000_0_OR_NEWER
                    instance = FindFirstObjectByType<PXR_InteractorManager>();
#else
                    instance = FindObjectOfType<PXR_InteractorManager>();
#endif
                    if (instance == null)
                    {
                        GameObject go = new GameObject("[PXR_InteractorManager]");
                        DontDestroyOnLoad(go);
                        instance = go.AddComponent<PXR_InteractorManager>();
                        Debug.LogError(TAG + "PXR_InteractorManager instance is not initialized!");
                    }
                }

                return instance;
            }
        }

        private AimUpdateType _currentAimUpdateType = AimUpdateType.EyeGaze;

        public AimUpdateType CurrentAimUpdateType
        {
            get => _currentAimUpdateType;
            set => _currentAimUpdateType = value;
        }

        private HandPinchEvent lastHandPinchEvent = HandPinchEvent.NoneEvent;
        private HandPinchEvent currentHandPinchEvent = HandPinchEvent.NoneEvent;


        private HandPinchEvent lastRightPinchEvent = HandPinchEvent.NoneEvent;
        private HandPinchEvent rightHandPinchEvent = HandPinchEvent.NoneEvent;

        private HandPinchEvent RightHandPinchEvent
        {
            get => rightHandPinchEvent;
            set
            {
                lastRightPinchEvent = rightHandPinchEvent;
                rightHandPinchEvent = value;

                if (rightHandPinchEvent == HandPinchEvent.PinchUpEvent &&
                    lastRightPinchEvent == HandPinchEvent.PinchEvent)
                {
                    PinchUpTriggerEvent(InteractorHandedness.Right);
                    var pinchInteractor = GetPinchInteractor(InteractorHandedness.Right);
                    if (pinchInteractor != null)
                    {
                        pinchInteractor.SetPinchEvent(HandPinchEvent.PinchUpEvent, Vector3.zero, Quaternion.identity);
                    }
                }
                else if (rightHandPinchEvent == HandPinchEvent.PinchEvent &&
                         lastRightPinchEvent == HandPinchEvent.PinchDownEvent)
                {
                    PinchDownTriggerEvent(InteractorHandedness.Right);

                    if (_aimInteractor == null)
                    {
                        EnsureReferences();
                    }

                    if (_aimInteractor != null)
                    {
                        _aimInteractor.GetEyeForward(out var eyeTrackingState, out var _eyeOrigin, out var _eyeRotation);
                        var pinchInteractor = GetPinchInteractor(InteractorHandedness.Right);
                        if (pinchInteractor != null)
                        {
                            pinchInteractor.SetPinchEvent(HandPinchEvent.PinchDownEvent, _eyeOrigin, _eyeRotation);
                        }
                    }
                }
            }
        }

        private HandPinchEvent lastLeftPinchEvent = HandPinchEvent.NoneEvent;
        private HandPinchEvent leftHandPinchEvent = HandPinchEvent.NoneEvent;

        private HandPinchEvent LeftHandPinchEvent
        {
            get => leftHandPinchEvent;
            set
            {
                lastLeftPinchEvent = leftHandPinchEvent;
                leftHandPinchEvent = value;

                if (leftHandPinchEvent == HandPinchEvent.PinchUpEvent &&
                    lastLeftPinchEvent == HandPinchEvent.PinchEvent)
                {
                    PinchUpTriggerEvent(InteractorHandedness.Left);
                    var pinchInteractor = GetPinchInteractor(InteractorHandedness.Left);
                    if (pinchInteractor != null)
                    {
                        pinchInteractor.SetPinchEvent(HandPinchEvent.PinchUpEvent, Vector3.zero, Quaternion.identity);
                    }
                }
                else if (leftHandPinchEvent == HandPinchEvent.PinchEvent &&
                         lastLeftPinchEvent == HandPinchEvent.PinchDownEvent)
                {
                    PinchDownTriggerEvent(InteractorHandedness.Left);
                    if (_aimInteractor == null)
                    {
                        EnsureReferences();
                    }

                    if (_aimInteractor != null)
                    {
                        _aimInteractor.GetEyeForward(out var eyeTrackingState, out var _eyeOrigin, out var _eyeRotation);
                        var pinchInteractor = GetPinchInteractor(InteractorHandedness.Left);
                        if (pinchInteractor != null)
                        {
                            pinchInteractor.SetPinchEvent(HandPinchEvent.PinchDownEvent, _eyeOrigin, _eyeRotation);
                        }
                    }
                }
            }
        }

        private static InteractionData _interactionData;

        public static InteractionData InteractionData
        {
            get => _interactionData;
            set => _interactionData = value;
        }


        private void Awake()
        {
            _interactionData = new InteractionData();
            EnsureReferences();
        }

        public void SetScrollObject(Transform scrollObject)
        {
            _interactionData._scrollObject = scrollObject;
        }

        public void SetHandPinchEvent(InteractorHandedness handedness, HandPinchEvent handPinchEvent)
        {
            if (handedness == InteractorHandedness.Left)
            {
                LeftHandPinchEvent = handPinchEvent;
            }

            if (handedness == InteractorHandedness.Right)
            {
                RightHandPinchEvent = handPinchEvent;
            }
        }

        public PXR_PinchInteractor GetPinchInteractor(InteractorHandedness handedness)
        {
            if (_pinchInteractorLeft == null || _pinchInteractorRight == null)
            {
                EnsureReferences();
            }

            switch (handedness)
            {
                case InteractorHandedness.Left:
                    return _pinchInteractorLeft;
                case InteractorHandedness.Right:
                    return _pinchInteractorRight;
            }

            return null;
        }


        private void PinchDownTriggerEvent(InteractorHandedness handedness)
        {
            switch (handedness)
            {
                case InteractorHandedness.Left:
                    PDebug.InteractionLog(TAG, $" PinchTriggerEvent Down LeftHandPinchEvent: {LeftHandPinchEvent}");
                    LeftPinchAction?.Invoke(HandPinchEvent.PinchDownEvent);
                    break;
                case InteractorHandedness.Right:
                    PDebug.InteractionLog(TAG, $" PinchTriggerEvent Down RightHandPinchEvent: {RightHandPinchEvent}");
                    RightPinchAction?.Invoke(HandPinchEvent.PinchDownEvent);
                    break;
            }

            PinchDownAction?.Invoke(handedness);
        }

        private void PinchUpTriggerEvent(InteractorHandedness handedness)
        {
            switch (handedness)
            {
                case InteractorHandedness.Left:
                    PDebug.InteractionLog(TAG, $" PinchTriggerEvent Up LeftHandPinchEvent: {LeftHandPinchEvent}");
                    LeftPinchAction?.Invoke(HandPinchEvent.PinchUpEvent);

                    break;
                case InteractorHandedness.Right:
                    PDebug.InteractionLog(TAG, $" PinchTriggerEvent Up RightHandPinchEvent: {RightHandPinchEvent}");
                    RightPinchAction?.Invoke(HandPinchEvent.PinchUpEvent);
                    break;
            }

            PinchUpAction?.Invoke(handedness);
        }


        public void motionControllerModeEnded()
        {
            PDebug.InteractionLog(TAG, $" InputModeChange motionControllerModeEnded");

            CurrentInputMode = XRInputModalityManager.InputMode.TrackedHand;
        }

        public void motionControllerModeStarted()
        {
            PDebug.InteractionLog(TAG, $" InputModeChange motionControllerModeStarted");
            CurrentInputMode = XRInputModalityManager.InputMode.MotionController;
        }

        public void trackedHandModeStarted()
        {
            PDebug.InteractionLog(TAG, $" InputModeChange trackedHandModeStarted");
            CurrentInputMode = XRInputModalityManager.InputMode.TrackedHand;
        }

        public void trackedHandModeEnded()
        {
            PDebug.InteractionLog(TAG, $" InputModeChange trackedHandModeEnded");
            CurrentInputMode = XRInputModalityManager.InputMode.MotionController;
        }

        public Vector3 PerFramePinchPositionChange()
        {
            if (_currentAimUpdateType == AimUpdateType.UIScrollbyLeft)
            {
                var _interactor = GetPinchInteractor(InteractorHandedness.Left);
                if (_interactor == null) return Vector3.zero;
                return _interactor.PerFramePositionChange;
            }
            else if (_currentAimUpdateType == AimUpdateType.UIScrollbyRight)
            {
                var _interactor = GetPinchInteractor(InteractorHandedness.Right);
                if (_interactor == null) return Vector3.zero;
                return _interactor.PerFramePositionChange;
            }

            return Vector3.zero;
        }

        public Vector3 PerFramehandPosition()
        {
            if (_currentAimUpdateType == AimUpdateType.UIScrollbyLeft)
            {
                var _interactor = GetPinchInteractor(InteractorHandedness.Left);
                if (_interactor == null) return Vector3.zero;
                return _interactor.PerFramehandPosition;
            }
            else if (_currentAimUpdateType == AimUpdateType.UIScrollbyRight)
            {
                var _interactor = GetPinchInteractor(InteractorHandedness.Right);
                if (_interactor == null) return Vector3.zero;
                return _interactor.PerFramehandPosition;
            }

            return Vector3.zero;
        }

        public Quaternion PerFramePinchRotationChange()
        {
            if (_currentAimUpdateType == AimUpdateType.UIScrollbyLeft)
            {
                var _interactor = GetPinchInteractor(InteractorHandedness.Left);
                if (_interactor == null) return Quaternion.identity;
                return _interactor.PerFrameRotationChange;
            }
            else if (_currentAimUpdateType == AimUpdateType.UIScrollbyRight)
            {
                var _interactor = GetPinchInteractor(InteractorHandedness.Right);
                if (_interactor == null) return Quaternion.identity;
                return _interactor.PerFrameRotationChange;
            }

            return Quaternion.identity;
        }

        private void EnsureReferences()
        {
            if (_xrInputModality == null)
            {
                _xrInputModality = GetComponentInChildren<XRInputModalityManager>(true);
                if (_xrInputModality == null)
                {
#if UNITY_6000_0_OR_NEWER
                    _xrInputModality = FindFirstObjectByType<XRInputModalityManager>();
#else
                    _xrInputModality = FindObjectOfType<XRInputModalityManager>();
#endif
                }
            }

            if (_aimInteractor == null)
            {
                _aimInteractor = GetComponentInChildren<PXR_AimInteractor>(true);
                if (_aimInteractor == null)
                {
#if UNITY_6000_0_OR_NEWER
                    _aimInteractor = FindFirstObjectByType<PXR_AimInteractor>();
#else
                    _aimInteractor = FindObjectOfType<PXR_AimInteractor>();
#endif
                }
            }

            if (_pinchInteractorLeft == null || _pinchInteractorRight == null)
            {
                var pinchInteractors = FindObjectsOfType<PXR_PinchInteractor>(true);
                for (int i = 0; i < pinchInteractors.Length; i++)
                {
                    var pinchInteractor = pinchInteractors[i];
                    if (pinchInteractor == null) continue;

                    switch (pinchInteractor.Handedness)
                    {
                        case InteractorHandedness.Left:
                            if (_pinchInteractorLeft == null) _pinchInteractorLeft = pinchInteractor;
                            break;
                        case InteractorHandedness.Right:
                            if (_pinchInteractorRight == null) _pinchInteractorRight = pinchInteractor;
                            break;
                    }
                }
            }

            if (_nearFarInteractors == null)
            {
                _nearFarInteractors = new List<NearFarInteractor>();
            }

            if (_nearFarInteractors.Count == 0)
            {
                _nearFarInteractors.AddRange(GetComponentsInChildren<NearFarInteractor>(true));
                if (_nearFarInteractors.Count == 0)
                {
                    _nearFarInteractors.AddRange(FindObjectsOfType<NearFarInteractor>(true));
                }
            }
        }

        private void SubscribeInteractorEvents(NearFarInteractor interactor)
        {
            if (interactor == null) return;
            UnsubscribeInteractorEvents(interactor);

            interactor.hoverEntered.AddListener(OnHoverEntered);
            interactor.hoverExited.AddListener(OnHoverExited);
            interactor.selectEntered.AddListener(OnSelectEntered);
            interactor.selectExited.AddListener(OnSelectExited);
            interactor.uiHoverEntered.AddListener(OnUIHoverEntered);
            interactor.uiHoverExited.AddListener(OnUIHoverExited);
        }

        private void UnsubscribeInteractorEvents(NearFarInteractor interactor)
        {
            if (interactor == null) return;
            interactor.hoverEntered.RemoveListener(OnHoverEntered);
            interactor.hoverExited.RemoveListener(OnHoverExited);
            interactor.selectEntered.RemoveListener(OnSelectEntered);
            interactor.selectExited.RemoveListener(OnSelectExited);
            interactor.uiHoverEntered.RemoveListener(OnUIHoverEntered);
            interactor.uiHoverExited.RemoveListener(OnUIHoverExited);
        }

        void OnEnable()
        {
            EnsureReferences();
            if (_xrInputModality != null)
            {
                _xrInputModality.trackedHandModeEnded.AddListener(trackedHandModeEnded);
                _xrInputModality.trackedHandModeStarted.AddListener(trackedHandModeStarted);
                _xrInputModality.motionControllerModeStarted.AddListener(motionControllerModeStarted);
                _xrInputModality.motionControllerModeEnded.AddListener(motionControllerModeEnded);
            }

            if (_nearFarInteractors != null)
            {
                for (int i = 0; i < _nearFarInteractors.Count; i++)
                {
                    SubscribeInteractorEvents(_nearFarInteractors[i]);
                }
            }
        }

        void OnDisable()
        {
            if (_xrInputModality != null)
            {
                _xrInputModality.trackedHandModeEnded.RemoveListener(trackedHandModeEnded);
                _xrInputModality.trackedHandModeStarted.RemoveListener(trackedHandModeStarted);
                _xrInputModality.motionControllerModeStarted.RemoveListener(motionControllerModeStarted);
                _xrInputModality.motionControllerModeEnded.RemoveListener(motionControllerModeEnded);
            }

            if (_nearFarInteractors != null)
            {
                for (int i = 0; i < _nearFarInteractors.Count; i++)
                {
                    UnsubscribeInteractorEvents(_nearFarInteractors[i]);
                }
            }

            if (_leftHandState.AntiShakeCoroutine != null) StopCoroutine(_leftHandState.AntiShakeCoroutine);
            if (_rightHandState.AntiShakeCoroutine != null) StopCoroutine(_rightHandState.AntiShakeCoroutine);
        }

        #region Event Callback Implementation

        private Transform _lastHoveredInteractable;

        private void HandleHoverEnter(Transform target, string typePrefix)
        {

            if (target == _lastHoveredInteractable)
                return;

            _lastHoveredInteractable = target;

            PDebug.InteractionLog(TAG, $"{typePrefix} Hover Enter: {target.name}");
        }

        private void HandleHoverExit(Transform target, string typePrefix)
        {
            if (target != _lastHoveredInteractable)
                return;

            _lastHoveredInteractable = null;

            PDebug.InteractionLog(TAG, $"{typePrefix} Hover Exit: {target.name}");

        }

        /// <summary>
        /// Triggered when the interactor starts hovering over an interactable object
        /// </summary>
        void OnHoverEntered(HoverEnterEventArgs args)
        {
            HandleHoverEnter(args.interactableObject.transform, "Interactable");
        }

        /// <summary>
        /// Triggered when the interactor stops hovering over an interactable object
        /// </summary>
        void OnHoverExited(HoverExitEventArgs args)
        {
            HandleHoverExit(args.interactableObject.transform, "Interactable");
        }

        private HandState GetHandState(InteractorHandedness handedness)
        {
            return handedness == InteractorHandedness.Left ? _leftHandState : _rightHandState;
        }

        /// <summary>
        /// Triggered when the interactor starts selecting an interactable object
        /// </summary>
        void OnSelectEntered(SelectEnterEventArgs args)
        {
            PDebug.InteractionLog(TAG,
                $"OnSelect Select Enter: {args.interactorObject.transform.parent} {args.interactableObject.transform.name}");

            float currentTime = Time.unscaledTime;
            InteractorHandedness handedness = args.interactorObject.handedness;
            HandState state = GetHandState(handedness);

            // 1. Filter repeated triggers within a short time window
            if (currentTime - state.LastStateChangeTime < antiShakeThreshold / 1000f)
            {
                PDebug.InteractionLog(TAG,
                    $"OnSelect [Debounce Filter] Rapid repeated select - Target:{args.interactableObject.transform.name} | Interval:{Math.Round((currentTime - state.LastStateChangeTime) * 1000)}ms < {antiShakeThreshold}ms");
                return;
            }

            // 2. Record state and start debounce confirmation
            state.LastStateChangeTime = currentTime;
            state.CurrentInteractable = args.interactableObject.transform;

            // Stop previous debounce coroutine
            if (state.AntiShakeCoroutine != null) StopCoroutine(state.AntiShakeCoroutine);

            // Start coroutine to confirm selection state after a delay
            state.AntiShakeCoroutine =
                StartCoroutine(ConfirmSelectState(true, handedness, args.interactableObject.transform));
        }

        /// <summary>
        /// Triggered when the interactor stops selecting an interactable object
        /// </summary>
        void OnSelectExited(SelectExitEventArgs args)
        {
            PDebug.InteractionLog(TAG,
                $"OnSelect Select Exit: {args.interactorObject.transform.parent} {args.interactableObject.transform.name}");

            float currentTime = Time.unscaledTime;
            InteractorHandedness handedness = args.interactorObject.handedness;
            HandState state = GetHandState(handedness);

            // 1. Filter repeated triggers within a short time window
            if (currentTime - state.LastStateChangeTime < antiShakeThreshold / 1000f)
            {
                PDebug.InteractionLog(TAG,
                    $"OnSelect [Debounce Filter] Rapid repeated deselect - Target:{args.interactableObject.transform.name} | Interval:{Math.Round((currentTime - state.LastStateChangeTime) * 1000)}ms < {antiShakeThreshold}ms");
                return;
            }

            // 2. Record state and start debounce confirmation
            state.LastStateChangeTime = currentTime;

            // Stop previous debounce coroutine
            if (state.AntiShakeCoroutine != null) StopCoroutine(state.AntiShakeCoroutine);

            // Start coroutine to confirm deselection state after a delay
            state.AntiShakeCoroutine =
                StartCoroutine(ConfirmSelectState(false, handedness, args.interactableObject.transform));
        }

        /// <summary>
        /// Triggered when the interactor starts hovering over a UI element
        /// </summary>
        void OnUIHoverEntered(UIHoverEventArgs args)
        {
            HandleHoverEnter(args.uiObject.transform, "🖱️ UI");
        }

        /// <summary>
        /// Triggered when the interactor stops hovering over a UI element
        /// </summary>
        void OnUIHoverExited(UIHoverEventArgs args)
        {
            HandleHoverExit(args.uiObject.transform, "🖱️ UI");
        }

        #endregion

        #region Debounce Confirmation Logic

        /// <summary>
        /// Confirm selection state with a delay (core debounce logic)
        /// </summary>
        /// <param name="isSelect">Whether it is selecting</param>
        /// <param name="target">Target transform</param>
        IEnumerator ConfirmSelectState(bool isSelect, InteractorHandedness handedness, Transform target)
        {
            // Wait for the threshold duration to ensure the state is stable
            yield return new WaitForSecondsRealtime(antiShakeThreshold / 1000f);

            // After the state is stable, execute the actual business logic
            HandState state = GetHandState(handedness);

            if (isSelect)
            {
                if (!state.IsSelecting)
                {
                    state.IsSelecting = true;
                    OnSelectConfirmed(handedness, target);
                }
            }
            else
            {
                if (state.IsSelecting && target == state.CurrentInteractable)
                {
                    state.IsSelecting = false;
                    OnDeselectConfirmed(handedness, target);
                }
            }

            state.AntiShakeCoroutine = null;
        }

        /// <summary>
        /// Confirmed selection logic (called by business layer)
        /// </summary>
        void OnSelectConfirmed(InteractorHandedness handedness, Transform target)
        {
            PDebug.InteractionLog(TAG,
                $"OnSelect [Debounce Confirm] Confirmed Select: {(handedness == InteractorHandedness.Left ? "Left" : "Right")}  {target.name}");

            // Fire selection event // gesture is currently not stable enough
            SelectEnterAction?.Invoke(handedness, target);

            // ========== Put your actual selection business logic here ==========
            // Examples: grab object, play selection SFX, trigger interaction, etc.
            // Example:
            // GameObject target = GameObject.Find(targetName);
            // target.GetComponent<InteractableObject>().OnSelected();
        }

        /// <summary>
        /// Confirmed deselection logic (called by business layer)
        /// </summary>
        void OnDeselectConfirmed(InteractorHandedness handedness, Transform target)
        {
            PDebug.InteractionLog(TAG,
                $"OnSelect [Debounce Confirm] Confirmed Deselect: {(handedness == InteractorHandedness.Left ? "Left" : "Right")}  {target.name}");

            // Fire deselection event
            SelectExitAction?.Invoke(handedness, target);

            // ========== Put your actual deselection business logic here ==========
            // Examples: release object, play cancel SFX, end interaction, etc.
            // Example:
            // GameObject target = GameObject.Find(targetName);
            // target.GetComponent<InteractableObject>().OnDeselected();
        }

        #endregion

        #region Extensions: Get Current Stable State (For External Use)

        public XRInputModalityManager.InputMode CurrentInputMode
        {
            get => _currentInputMode;
            set
            {
                if (_currentInputMode != value)
                {
                    InputModeChangeAction?.Invoke(value);
                }

                _currentInputMode = value;
            }
        }

        /// <summary>
        /// Get current stable selection state (callable from external scripts)
        /// </summary>
        public bool GetStableSelectState(InteractorHandedness handedness)
        {
            return GetHandState(handedness).IsSelecting;
        }

        /// <summary>
        /// Get the currently selected target transform
        /// </summary>
        public Transform GetCurrentTargetTransform(InteractorHandedness handedness)
        {
            return GetHandState(handedness).CurrentInteractable;
        }

        public Transform GetCurrentHoveredTransform()
        {
            return _lastHoveredInteractable;
        }

        #endregion
    }
}
#endif
