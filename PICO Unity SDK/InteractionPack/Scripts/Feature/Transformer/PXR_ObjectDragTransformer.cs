#if ENABLE_PICO_INTERACTION_PACK
using System;
using System.Collections.Generic;
using ByteDance.PICO.XR;
using UnityEngine;
using UnityEngine.XR.Interaction.Toolkit;
using UnityEngine.XR.Interaction.Toolkit.Attachment;
using UnityEngine.XR.Interaction.Toolkit.Inputs;
using UnityEngine.XR.Interaction.Toolkit.Interactables;
using UnityEngine.XR.Interaction.Toolkit.Interactors;
using UnityEngine.XR.Interaction.Toolkit.Transformers;

namespace ByteDance.PICO.Interaction
{
    public class PXR_ObjectDragTransformer : XRBaseGrabTransformer
    {
        private const string TAG = "[PXR_ObjectDragTransformer]";
        private TransformSolver _transformSolver= new TransformSolver();
        private Dictionary<IXRSelectInteractor, PXR_PinchInteractor> devices =
            new Dictionary<IXRSelectInteractor, PXR_PinchInteractor>(2);

        EventPhase _eventPhase = EventPhase.Ended;
        private XRGrabInteractable _grabInteractable;


        private void Awake()
        {
            _transformSolver.InitShadowObject(transform);
        }


        private void OnPinchDown(InteractorHandedness hand, Transform target)
        {
            PDebug.InteractionLog(TAG, $"OnPinchDown handedness:{hand}");
            if (target != transform)
            {
                return;
            }
            PDebug.InteractionLog(TAG, $"OnPinchDown continue handedness:{hand}");
          
            foreach (KeyValuePair<IXRSelectInteractor, PXR_PinchInteractor> interactor in devices)
            {
                if (interactor.Key.handedness == hand)
                {
                    _eventPhase = EventPhase.Began;


                    var attachController = interactor.Key.transform.GetComponent<InteractionAttachController>();
                    devices[interactor.Key].setHandTransform(attachController.transformToFollow);
                    if (PXR_InteractorManager.Instance.CurrentInputMode ==
                        XRInputModalityManager.InputMode.MotionController)
                    {
                        interactor.Key.GetAttachTransform(_grabInteractable)
                            .GetPositionAndRotation(out var _position, out var _rotation);
                        devices[interactor.Key].setEventParas(this.gameObject);
                        devices[interactor.Key].SetCursorPos(_position);
                    }
                    else
                    {
                        devices[interactor.Key].SetCursorPos(PXR_InteractorManager.InteractionData._cursorPos);
                    }

                    devices[interactor.Key].ProcessEvent(HandPinchEvent.PinchDownEvent);
                    _transformSolver.Select(devices[interactor.Key].EventParas);
                    return;
                }
            }
            
            PDebug.InteractionLog(TAG, $"OnPinchDown handedness:{hand} not found");
        }

        private void OnPinchUp(InteractorHandedness hand, Transform target)
        {
            PDebug.InteractionLog(TAG, $"OnPinchUp handedness:{hand}");
            if (target != transform) return;
            PDebug.InteractionLog(TAG, $"OnPinchUp continue handedness:{hand}");
            
            IXRSelectInteractor interactorToRemove = null;
            foreach (KeyValuePair<IXRSelectInteractor, PXR_PinchInteractor> interactor in devices)
            {
                if (interactor.Key.handedness == hand)
                {
                    if (devices.ContainsKey(interactor.Key))
                    {
                        devices[interactor.Key].ProcessEvent(HandPinchEvent.PinchUpEvent);
                        _transformSolver.Select(devices[interactor.Key].EventParas);
                        interactorToRemove = interactor.Key;
                        break;
                    }
                }
            }

            if (interactorToRemove != null) devices.Remove(interactorToRemove);

            bool isContinue = false;
            foreach (KeyValuePair<IXRSelectInteractor, PXR_PinchInteractor> interactor in devices)
            {
                if (devices[interactor.Key].EventParas._eventPhase == EventPhase.Began ||
                    devices[interactor.Key].EventParas._eventPhase == EventPhase.Moved)
                {
                    isContinue = true;
                    break;
                }
            }
            
            PDebug.InteractionLog(TAG, $"OnPinchUp continue handedness:{hand} isContinue:{isContinue}");
          
            if (!isContinue)
            {
                _eventPhase = EventPhase.Ended;
            }
        }

        private void OnEnable()
        {
            PXR_InteractorManager.SelectEnterAction += OnPinchDown;
            PXR_InteractorManager.SelectExitAction += OnPinchUp;
            PXR_InteractorManager.InputModeChangeAction += OnInputModeChange;
        }


        private void OnDisable()
        {
            PXR_InteractorManager.SelectEnterAction -= OnPinchDown;
            PXR_InteractorManager.SelectExitAction -= OnPinchUp;
            PXR_InteractorManager.InputModeChangeAction -= OnInputModeChange;
        }

        private void OnInputModeChange(XRInputModalityManager.InputMode obj)
        {
            devices.Clear();
        }


        public override void OnGrab(XRGrabInteractable grabInteractable)
        {
            base.OnGrab(grabInteractable);
            _grabInteractable = grabInteractable;
            PDebug.InteractionLog(TAG, $"OnGrab grabInteractable:{_grabInteractable.gameObject.name}");
        }

        void CreateDevice(IXRSelectInteractor interactor)
        {
            PDebug.InteractionLog(TAG, $"CreateDevice handedness:{interactor.handedness}");
            var attachController = interactor.transform.GetComponent<InteractionAttachController>();
            if (attachController == null)
            {
                return;
            }

            if (!(interactor is NearFarInteractor))
            {
                return;
            }

            devices[interactor] =
                PXR_InteractorManager.Instance.GetPinchInteractor(interactor.handedness);
        }

        public override void OnGrabCountChanged(XRGrabInteractable grabInteractable, Pose targetPose,
            Vector3 localScale)
        {
            base.OnGrabCountChanged(grabInteractable, targetPose, localScale);
            var newGrabCount = grabInteractable.interactorsSelecting.Count;

            PDebug.InteractionLog(TAG, $"OnGrabCountChanged newGrabCount:{newGrabCount}");
            for (int i = 0; i < newGrabCount; i++)
            {
                var interactor0 = grabInteractable.interactorsSelecting[i];

                if (!devices.ContainsKey(interactor0))
                {
                    CreateDevice(interactor0);
                }
            }
        }

        public override void OnLink(XRGrabInteractable grabInteractable)
        {
            base.OnLink(grabInteractable);
            PDebug.InteractionLog(TAG, "OnLink");
        }

        public override void Process(XRGrabInteractable grabInteractable,
            XRInteractionUpdateOrder.UpdatePhase updatePhase, ref Pose targetPose, ref Vector3 localScale)
        {
        }

        private void Update()
        {
            if (_eventPhase == EventPhase.Ended || _eventPhase == EventPhase.Cancel)
            {
                return;
            }

            if (_eventPhase == EventPhase.Began)
            {
                _eventPhase = EventPhase.Moved;
            }

            if (_eventPhase == EventPhase.Moved)
            {
                var newPos = Vector3.zero;
                var newScale = Vector3.zero;
                var newRot = Quaternion.identity;
                bool isUpdate = false;
                foreach (KeyValuePair<IXRSelectInteractor, PXR_PinchInteractor> interactor in devices)
                {
                    if (devices[interactor.Key].EventParas._eventPhase == EventPhase.Moved ||
                        devices[interactor.Key].EventParas._eventPhase == EventPhase.Began)
                    {
                        devices[interactor.Key].ProcessEvent(HandPinchEvent.PinchEvent);
                        var ret = _transformSolver.Select(devices[interactor.Key].EventParas);
                        if (ret.isSuccess)
                        {
                            newPos = ret._position;
                            newScale = ret._scale;
                            newRot = ret._rotation;
                            isUpdate = true;
                        }
                    }
                }

                if (isUpdate)
                {
                    transform.SetPositionAndRotation(newPos, newRot);
                    transform.localScale = newScale;
                }
            }
        }
    }
}
#endif
