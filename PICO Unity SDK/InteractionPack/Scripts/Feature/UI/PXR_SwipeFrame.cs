#if ENABLE_PICO_INTERACTION_PACK
using System.Collections;
using System.Collections.Generic;
using ByteDance.PICO.XR;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.XR.Interaction.Toolkit.Inputs;
using UnityEngine.XR.Interaction.Toolkit.Inputs.Readers;
using UnityEngine.XR.Interaction.Toolkit.Interactors;

namespace ByteDance.PICO.Interaction
{
    public class PXR_SwipeFrame : MonoBehaviour, IPointerEnterHandler, IPointerExitHandler
    {
        private string Tag = "**SwipeFrame**";
        private XRInputModalityManager.InputMode currentInputMode = XRInputModalityManager.InputMode.None;
        private InteractorHandedness currentInteractorHandedness = InteractorHandedness.None;
        private bool isHover = false;
        private bool isPressing = false;

        void Update()
        {
            if (isPressing)
            {
                var pinchInteractor = PXR_InteractorManager.Instance.GetPinchInteractor(currentInteractorHandedness);
                if (pinchInteractor != null)
                {
                    pinchInteractor.ProcessEvent(HandPinchEvent.PinchEvent);
                }
            }
        }

        private void OnPinchDown(InteractorHandedness obj)
        {
            if (PXR_InteractorManager.Instance.CurrentInputMode != XRInputModalityManager.InputMode.TrackedHand)
            {
                return;
            }

            PDebug.InteractionLog(Tag, $"OnPinchDown InteractorHandedness:{obj}");
            if (isHover)
            {
                currentInteractorHandedness = obj;
                PDebug.InteractionLog(Tag, $"OnPinchDown InteractorHandedness:{obj}");
                PXR_InteractorManager.Instance.CurrentAimUpdateType = currentInteractorHandedness == InteractorHandedness.Left
                    ? AimUpdateType.UIScrollbyLeft
                    : AimUpdateType.UIScrollbyRight;
                isPressing = true;
                PXR_InteractorManager.Instance.SetScrollObject(gameObject.transform);
                var pinchInteractor = PXR_InteractorManager.Instance.GetPinchInteractor(currentInteractorHandedness);
                if (pinchInteractor != null)
                {
                    pinchInteractor.ProcessEvent(HandPinchEvent.PinchDownEvent);
                }
            }
        }

        private void OnPinchUp(InteractorHandedness obj)
        {
            if (PXR_InteractorManager.Instance.CurrentInputMode != XRInputModalityManager.InputMode.TrackedHand)
            {
                return;
            }

            PDebug.InteractionLog(Tag, $"OnPinchUp InteractorHandedness:{obj}");
            if (currentInteractorHandedness == obj)
            {
                PDebug.InteractionLog(Tag, $"OnPinchUp InteractorHandedness:{obj}");
                PXR_InteractorManager.Instance.CurrentAimUpdateType = AimUpdateType.EyeGaze;
                PXR_InteractorManager.Instance.SetScrollObject(null);
                isPressing = false;
                var pinchInteractor = PXR_InteractorManager.Instance.GetPinchInteractor(currentInteractorHandedness);
                if (pinchInteractor != null)
                {
                    pinchInteractor.ProcessEvent(HandPinchEvent.PinchUpEvent);
                }

                currentInteractorHandedness = InteractorHandedness.None;
            }
        }

        private void OnEnable()
        {
            PXR_InteractorManager.PinchUpAction += OnPinchUp;
            PXR_InteractorManager.PinchDownAction += OnPinchDown;
        }

        private void OnDisable()
        {
            PXR_InteractorManager.PinchUpAction -= OnPinchUp;
            PXR_InteractorManager.PinchDownAction -= OnPinchDown;
        }

        public void OnPointerEnter(PointerEventData eventData)
        {
            isHover = true;
            if (PXR_InteractorManager.Instance.CurrentInputMode != currentInputMode)
            {
                currentInputMode = PXR_InteractorManager.Instance.CurrentInputMode;
            }
        }

        public void OnPointerExit(PointerEventData eventData)
        {
            isHover = false;
        }
    }
}
#endif
