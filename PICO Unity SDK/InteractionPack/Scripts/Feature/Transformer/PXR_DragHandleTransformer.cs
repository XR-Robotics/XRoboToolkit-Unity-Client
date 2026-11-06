#if ENABLE_PICO_INTERACTION_PACK
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
    public class PXR_DragHandleTransformer : XRBaseGrabTransformer
    {
        private const string TAG = "[PXR_DragHandleTransformer]";
        private DragHandle _dragHandle=new DragHandle();

        private Vector3 startScale;
        private IXRSelectInteractor m_OriginalInteractor;
        private InteractorHandedness m_OriginalHandedness = InteractorHandedness.None;
        private PXR_PinchInteractor m_OriginalPinchInteractor;

        EventPhase _eventPhase = EventPhase.Ended;
        private XRGrabInteractable _grabInteractable;

        private void Awake()
        {
            startScale = transform.parent.localScale;
            _dragHandle.InitShadowObject(transform, transform.parent);
        }


        private void OnPinchDown(InteractorHandedness hand, Transform target)
        {
            PDebug.InteractionLog(TAG, $"OnPinchDown handedness:{hand}");
            if (target != transform)
            {
                return;
            }

            PDebug.InteractionLog(TAG, $"OnPinchDown continue handedness:{hand}");
            if (m_OriginalHandedness == hand && m_OriginalInteractor != null && m_OriginalPinchInteractor != null)
            {
                _eventPhase = EventPhase.Began;

                var attachController = m_OriginalInteractor.transform.GetComponent<InteractionAttachController>();
                m_OriginalPinchInteractor.setHandTransform(attachController.transformToFollow);
                if (PXR_InteractorManager.Instance.CurrentInputMode ==
                    XRInputModalityManager.InputMode.MotionController)
                {
                    m_OriginalInteractor.GetAttachTransform(_grabInteractable)
                        .GetPositionAndRotation(out var _position, out var _rotation);
                    m_OriginalPinchInteractor.setEventParas(this.gameObject);
                    m_OriginalPinchInteractor.SetCursorPos(_position);
                }
                else
                {
                    m_OriginalPinchInteractor.SetCursorPos(this.transform.position);
                }

                m_OriginalPinchInteractor.ProcessEvent(HandPinchEvent.PinchDownEvent);
                return;
            }

            PDebug.InteractionLog(TAG, $"OnPinchDown handedness:{hand} not found");
        }

        private void OnPinchUp(InteractorHandedness hand, Transform target)
        {
            PDebug.InteractionLog(TAG, $"OnPinchUp handedness:{hand}");
            if (target != transform) return;
            PDebug.InteractionLog(TAG, $"OnPinchUp continue handedness:{hand}");

            if (m_OriginalHandedness == hand && m_OriginalInteractor != null && m_OriginalPinchInteractor != null)
            {
                m_OriginalPinchInteractor.ProcessEvent(HandPinchEvent.PinchUpEvent);
                _dragHandle.Select(m_OriginalPinchInteractor.EventParas);
                _eventPhase = EventPhase.Ended;
                m_OriginalHandedness = InteractorHandedness.None;
                m_OriginalInteractor = null;
                m_OriginalPinchInteractor = null;
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
        }

        public override void OnGrab(XRGrabInteractable grabInteractable)
        {
            base.OnGrab(grabInteractable);
            _grabInteractable = grabInteractable;
            PDebug.InteractionLog(TAG, $"OnGrab grabInteractable:{_grabInteractable.gameObject.name}");
        }

        public override void OnGrabCountChanged(XRGrabInteractable grabInteractable, Pose targetPose,
            Vector3 localScale)
        {
            base.OnGrabCountChanged(grabInteractable, targetPose, localScale);
            var newGrabCount = grabInteractable.interactorsSelecting.Count;
            PDebug.InteractionLog(TAG, $"OnGrabCountChanged newGrabCount:{newGrabCount}");
            if (newGrabCount > 0)
            {
                var interactor0 = grabInteractable.interactorsSelecting[0];
                if (m_OriginalInteractor != interactor0)
                {
                    m_OriginalInteractor = interactor0;
                    m_OriginalHandedness = interactor0.handedness;
                    m_OriginalPinchInteractor =
                        PXR_InteractorManager.Instance.GetPinchInteractor(m_OriginalHandedness);
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
                
                var ret=_dragHandle.Select(m_OriginalPinchInteractor.EventParas);
                if (ret.isSuccess)
                {
                   transform.SetPositionAndRotation(ret._position, ret._rotation);
                   transform.localScale = ret._scale;
                }
                _eventPhase = EventPhase.Moved;
            }

            if (_eventPhase == EventPhase.Moved)
            {
                if (m_OriginalPinchInteractor != null)
                {
                    m_OriginalPinchInteractor
                        .DragFrame(m_OriginalPinchInteractor.EventParas._location3D);
                    var ret =_dragHandle.Select(m_OriginalPinchInteractor.EventParas);
                    if (ret.isSuccess)
                    {
                        transform.SetPositionAndRotation(ret._position, ret._rotation);
                        transform.localScale = ret._scale;
                    }
                    PDebug.InteractionLog(TAG, $"OnPinchMoved continue handedness:{m_OriginalHandedness}");
                }
            }
        }
    }
}
#endif
