#if ENABLE_PICO_INTERACTION_PACK
using System;
using UnityEngine;
using UnityEngine.XR.Interaction.Toolkit;
using UnityEngine.XR.Interaction.Toolkit.Inputs.Readers;
using UnityEngine.XR.Interaction.Toolkit.Interactors;

namespace ByteDance.PICO.Interaction
{

    [DefaultExecutionOrder(XRInteractionUpdateOrder.k_XRInputDeviceButtonReader)]
    public class PXR_ReleaseThresholdButtonReader : MonoBehaviour, IXRInputButtonReader
    { 
        [SerializeField]
        private InteractorHandedness currentHandedness=InteractorHandedness.None;
        [SerializeField]
        [Tooltip("The source input that this component reads to create a processed button value.")]
        XRInputButtonReader m_ValueInput = new XRInputButtonReader("Value");
        
        public XRInputButtonReader valueInput
        {
            get => m_ValueInput;
            set => XRInputReaderUtility.SetInputProperty(ref m_ValueInput, value, this);
        }

        [SerializeField]
        [Tooltip("The threshold value to use to determine when the button is pressed. Considered pressed equal to or greater than this value.")]
        [Range(0f, 1f)]
        float m_PressThreshold = 0.8f;
        
        public float pressThreshold
        {
            get => m_PressThreshold;
            set => m_PressThreshold = value;
        }

        [SerializeField]
        [Tooltip("The threshold value to use to determine when the button is released when it was previously pressed. Keeps being pressed until falls back to a value of or below this value.")]
        [Range(0f, 1f)]
        float m_ReleaseThreshold = 0.25f;

    
        public float releaseThreshold
        {
            get => m_ReleaseThreshold;
            set => m_ReleaseThreshold = value;
        }

        bool m_IsPerformed;
        bool m_WasPerformedThisFrame;
        bool m_WasCompletedThisFrame;

        private HandPinchEvent _PinchEvent;
       
        void OnEnable()
        {
            m_ValueInput?.EnableDirectActionIfModeUsed();
        }

       
        void OnDisable()
        {
            m_ValueInput?.DisableDirectActionIfModeUsed();
        }

        private void Start()
        {
            _PinchEvent= HandPinchEvent.NoneEvent;
        }

        void Update()
        {
           
            // var prevPerformed = m_IsPerformed;
            var lastPinchSelect = m_IsPerformed;
            var pressAmount = m_ValueInput.ReadValue();
            bool newValue=m_IsPerformed;
        
          
            if (!lastPinchSelect && (pressAmount > m_PressThreshold)) newValue = true;
            else if (lastPinchSelect && (pressAmount <= m_ReleaseThreshold)) newValue = false;
       
            if (!lastPinchSelect && newValue) 
            {
                m_IsPerformed = true;
                _PinchEvent= HandPinchEvent.PinchDownEvent;
                PXR_InteractorManager.Instance.SetHandPinchEvent(currentHandedness,	HandPinchEvent.PinchDownEvent);
                // Debug.LogError($"PXR_ReleaseThresholdButtonReader {currentHandedness} PinchDownEvent：{m_ReleaseThreshold}");
            }
            else if (lastPinchSelect && newValue) 
            {
                m_IsPerformed = true;
                _PinchEvent= HandPinchEvent.PinchEvent;
                PXR_InteractorManager.Instance.SetHandPinchEvent(currentHandedness,	HandPinchEvent.PinchEvent);
                // Debug.LogWarning($"PXR_ReleaseThresholdButtonReader PinchEvent");
            }else if (lastPinchSelect && !newValue) 
            {
                m_IsPerformed = false;
                _PinchEvent= HandPinchEvent.PinchUpEvent;
                PXR_InteractorManager.Instance.SetHandPinchEvent(currentHandedness,	HandPinchEvent.PinchUpEvent);
                // Debug.Log($"PXR_ReleaseThresholdButtonReader {currentHandedness} PinchUpEvent：{m_ReleaseThreshold}");
            }
            else
            {
                m_IsPerformed = false;
            }
            m_WasPerformedThisFrame = !lastPinchSelect && m_IsPerformed;
            m_WasCompletedThisFrame = lastPinchSelect && !m_IsPerformed;

            // Debug.Log($"bbbb 2 m_IsPerformed: {m_IsPerformed}, m_WasPerformedThisFrame: {m_WasPerformedThisFrame}, m_WasCompletedThisFrame: {m_WasCompletedThisFrame}");
            
        }

        /// <inheritdoc />
        public bool ReadIsPerformed()
        {
            return m_IsPerformed;
        }

        /// <inheritdoc />
        public bool ReadWasPerformedThisFrame()
        {
            return m_WasPerformedThisFrame;
        }

        /// <inheritdoc />
        public bool ReadWasCompletedThisFrame()
        {
            return m_WasCompletedThisFrame;
        }

        /// <inheritdoc />
        public float ReadValue()
        {
            return m_ValueInput.ReadValue();
        }

        /// <inheritdoc />
        public bool TryReadValue(out float value)
        {
            return m_ValueInput.TryReadValue(out value);
        }
    }
}
#endif
