#if ENABLE_PICO_INTERACTION_PACK
using System;
using UnityEngine;
using UnityEngine.Events;
using UnityEngine.EventSystems;
using UnityEngine.XR.Interaction.Toolkit.Inputs;
using UnityEngine.XR.Interaction.Toolkit.Inputs.Readers;
using UnityEngine.XR.Interaction.Toolkit.Interactors;
using ByteDance.PICO.XR;
using UnityEngine.XR.Interaction.Toolkit.UI;

namespace ByteDance.PICO.Interaction
{
    [RequireComponent(typeof(UnityEngine.UI.Selectable))]
    [AddComponentMenu("PICO/UI/PXR UI Enhanced Button")]
    public class PXR_EnhancedButton : MonoBehaviour, IPointerEnterHandler, IPointerExitHandler
    {
        private string Tag = "**EnhancedButton**";

        #region Custom Interaction Events

        [Header("Custom Interaction Events")] public UnityEvent onSingleClick; // Single-click event
        public UnityEvent onDoubleClick; // Double-click event
        public UnityEvent onLongPress; // Long-press start event

        #endregion

        [SerializeField] private Tap _tap;
        private XRInputModalityManager.InputMode currentInputMode = XRInputModalityManager.InputMode.None;
        private bool ishover = false;
        private XRInputButtonReader m_UIPressInput=null;
        private bool isPressing = false;
        private Handedness currentInteractorHandedness = Handedness.None;
        private void Awake()
        {
            _tap = new Tap();
        }

        private void OnEnable()
        {
            PXR_InteractorManager.PinchUpAction += OnPinchUp;
            PXR_InteractorManager.PinchDownAction += OnPinchDown;
            _tap.TapAction += OnTap;
        }

        private void OnPinchDown(InteractorHandedness obj)
        {
            if (PXR_InteractorManager.Instance.CurrentInputMode != XRInputModalityManager.InputMode.TrackedHand)
            {
                return;
            }
            PDebug.InteractionLog(Tag, $"OnPinchDown InteractorHandedness:{obj}");
            
            if (ishover)
            {
                currentInteractorHandedness = (Handedness)obj;
                PDebug.InteractionLog(Tag, $"OnPinchDown InteractorHandedness:{obj}");  
                var pinchInteractor = PXR_InteractorManager.Instance.GetPinchInteractor(obj);
                if (pinchInteractor != null)
                {
                    pinchInteractor.ProcessEvent(HandPinchEvent.PinchDownEvent);
                    _tap.SelectBegan(pinchInteractor.EventParas, currentInteractorHandedness);
                }
            }
        }

        private void OnPinchUp(InteractorHandedness obj)
        {
            PDebug.InteractionLog(Tag, $"OnPinchUp  InteractorHandedness:{obj}");
            if (PXR_InteractorManager.Instance.CurrentInputMode != XRInputModalityManager.InputMode.TrackedHand)
            {
                return;
            }
            if (currentInteractorHandedness == (Handedness)obj)
            {
                PDebug.InteractionLog(Tag, $"OnPinchUp --- InteractorHandedness:{obj}");
                var pinchInteractor = PXR_InteractorManager.Instance.GetPinchInteractor(obj);
                if (pinchInteractor != null)
                {
                    pinchInteractor.ProcessEvent(HandPinchEvent.PinchUpEvent);
                    _tap.SelectEnded(pinchInteractor.EventParas, currentInteractorHandedness);
                }

                currentInteractorHandedness = Handedness.None;
            }
        }


        private void Update()
        {
            if (PXR_InteractorManager.Instance.CurrentInputMode == XRInputModalityManager.InputMode.MotionController &&
                m_UIPressInput != null)
            {
                if (m_UIPressInput.ReadIsPerformed())
                {
                    if (!isPressing)
                    {
                        PDebug.InteractionLog(Tag, "ReadIsPerformed Pressing: true");
                        isPressing = true;
                        var pinchInteractor = PXR_InteractorManager.Instance.GetPinchInteractor((InteractorHandedness)currentInteractorHandedness);
                        if (pinchInteractor != null)
                        {
                            pinchInteractor.ProcessEvent(HandPinchEvent.PinchDownEvent);
                            _tap.SelectBegan(pinchInteractor.EventParas, currentInteractorHandedness);
                        }
                    }
                }
                else
                {
                    if (isPressing)
                    {
                        PDebug.InteractionLog(Tag, "ReadIsPerformed Pressing: false");
                        isPressing = false;
                        var pinchInteractor = PXR_InteractorManager.Instance.GetPinchInteractor((InteractorHandedness)currentInteractorHandedness);
                        if (pinchInteractor != null)
                        {
                            pinchInteractor.ProcessEvent(HandPinchEvent.PinchUpEvent);
                            _tap.SelectEnded(pinchInteractor.EventParas, currentInteractorHandedness);
                        }
                    }
                }
            }
            _tap.Update();
        }

        private void OnTap(EventParameters arg1, TapType arg2)
        {
            switch (arg2)
            {
                case TapType.Click:
                    onSingleClick.Invoke();
                    break;
                case TapType.DoubleClick:
                    onDoubleClick.Invoke();
                    break;
                case TapType.LongPress:
                    onLongPress.Invoke();
                    break;
            }

            switch (currentInteractorHandedness)
            {
                case Handedness.None:
                    PDebug.InteractionLog(Tag, "OnTap: handedness:Other");
                    break;
                case Handedness.Left:
                    PDebug.InteractionLog(Tag, "OnTap: handedness:(Left)");
                    break;
                case Handedness.Right:
                    PDebug.InteractionLog(Tag, "OnTap: handedness:(Right)");
                    break;
            }
        }

        private void OnDisable()
        {
            PXR_InteractorManager.PinchUpAction -= OnPinchUp;
            PXR_InteractorManager.PinchDownAction -= OnPinchDown;
            _tap.TapAction -= OnTap;
        }


        public void OnPointerExit(PointerEventData eventData)
        {
            ishover = false;
            currentInteractorHandedness = Handedness.None;
            m_UIPressInput=null;
        }

        public void OnPointerEnter(PointerEventData eventData)
        {
            ishover = true;
            if (PXR_InteractorManager.Instance.CurrentInputMode !=currentInputMode)
            {
                _tap.Reset();
                currentInputMode=PXR_InteractorManager.Instance.CurrentInputMode;
            }
            if (PXR_InteractorManager.Instance.CurrentInputMode == XRInputModalityManager.InputMode.TrackedHand)
            {
                return;
            }
            IXRSelectInteractor pointerTransform = GetXRPointerInteractor(eventData);
            if (pointerTransform != null)
            {
                if (pointerTransform is NearFarInteractor)
                {
                    NearFarInteractor nearFarInteractor = pointerTransform as NearFarInteractor;
                    m_UIPressInput = nearFarInteractor.uiPressInput;
                    if (m_UIPressInput!=null)
                    {
                        currentInteractorHandedness = (Handedness)(nearFarInteractor.handedness);
                        PDebug.InteractionLog(Tag, "OnPointerEnter m_UIPressInput:true");
                    }
                    return;
                }
            }
            else
            {
                PDebug.InteractionLog(Tag, "OnPointerEnter pointerTransform:NULL");
            }
            m_UIPressInput = null;
        }
        public  IXRSelectInteractor GetXRPointerInteractor(PointerEventData eventData)
        {
            if (EventSystem.current.currentInputModule is XRUIInputModule xrInputModule)
            {
                var interactor = xrInputModule.GetInteractor(eventData.pointerId);
                if (interactor is IXRSelectInteractor)
                {
                    return (IXRSelectInteractor)interactor;
                }
            }

            return null;
        }
    }
}
#endif
