#if ENABLE_PICO_XR_SDK
/*******************************************************************************
Copyright © 2015-2022 PICO Technology Co., Ltd.All rights reserved.

NOTICE：All information contained herein is, and remains the property of
PICO Technology Co., Ltd. The intellectual and technical concepts
contained herein are proprietary to PICO Technology Co., Ltd. and may be
covered by patents, patents in process, and are protected by trade secret or
copyright law. Dissemination of this information or reproduction of this
material is strictly forbidden unless prior written permission is obtained from
PICO Technology Co., Ltd.
*******************************************************************************/

using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.Controls;
using UnityEngine.InputSystem.Layouts;
using UnityEngine.InputSystem.XR;
using UnityEngine.Scripting;
using UnityEngine.XR;
#if XR_HANDS
namespace ByteDance.PICO.XR
{
    /// <remarks>
    /// The <see cref="TrackedDevice.devicePosition"/> and
    /// <see cref="TrackedDevice.deviceRotation"/> inherited from <see cref="TrackedDevice"/>
    /// represent the aim pose. You can use these values to discover the target for pinch gestures,
    /// when appropriate.
    ///
    /// Use the [XROrigin](xref:Unity.XR.CoreUtils.XROrigin) in the scene to position and orient
    /// the device properly. If you are using this data to set the Transform of a GameObject in
    /// the scene hierarchy, you can set the local position and rotation of the Transform and make
    /// it a child of the <c>CameraOffset</c> object below the <c>XROrigin</c>. Otherwise, you can use the
    /// Transform of the <c>CameraOffset</c> to transform the data into world space.
    /// </remarks>
#if UNITY_EDITOR
    [UnityEditor.InitializeOnLoad]
#endif
    [Preserve, InputControlLayout(displayName = "Pico Hand Interaction", commonUsages = new[] { "LeftHand", "RightHand" })]
    public partial class PicoHandInteraction : TrackedDevice
    {
        /// <summary>
        /// The left-hand <see cref="InputDevice"/> that contains
        /// <see cref="InputControl"/>s that surface data in the Pico Hand
        /// Tracking Aim extension.
        /// </summary>
        /// <remarks>
        /// It is recommended that you treat this as read-only, and do not set
        /// it yourself. It will be set for you if hand-tracking has been
        /// enabled and if you are running with either the OpenXR or Oculus
        /// plug-in.
        /// </remarks>
        public static PicoHandInteraction left { get; set; }

        /// <summary>
        /// The right-hand <see cref="InputDevice"/> that contains
        /// <see cref="InputControl"/>s that surface data in the Pico Hand
        /// Tracking Aim extension.
        /// </summary>
        /// <remarks>
        /// It is recommended that you treat this as read-only, and do not set
        /// it yourself. It will be set for you if hand-tracking has been
        /// enabled and if you are running with either the OpenXR or Oculus
        /// plug-in.
        /// </remarks>
        public static PicoHandInteraction right { get; set; }

        /// <summary>
        /// Threshold used when converting analog interaction values to button states.
        /// </summary>
        public const float pressThreshold = 0.8f;

        [Preserve, InputControl(alias = "gripPose", usage = "Device")]
        public PoseControl devicePose { get; private set; }
        [Preserve, InputControl(alias = "aimPose", usage = "Pointer")]
        public PoseControl pointer { get; private set; }
        [Preserve, InputControl(usage = "Poke")]
        public PoseControl pokePose { get; private set; }
        [Preserve, InputControl(usage = "Pinch")]
        public PoseControl pinchPose { get; private set; }

        [Preserve, InputControl(offset = 216, usage = "PinchValue")]
        public AxisControl pinchValue { get; private set; }
        [Preserve, InputControl(offset = 220, format = "BYTE", usage = "PinchTouched")]
        public ButtonControl pinchTouched { get; private set; }
        [Preserve, InputControl(offset = 221, format = "BYTE", usage = "PinchReady")]
        public ButtonControl pinchReady { get; private set; }

        [Preserve, InputControl(offset = 224, usage = "PointerActivateValue")]
        public AxisControl pointerActivateValue { get; private set; }
        [Preserve, InputControl(offset = 228, format = "BYTE", usage = "PointerActivated")]
        public ButtonControl pointerActivated { get; private set; }
        [Preserve, InputControl(offset = 229, format = "BYTE", usage = "PointerActivateReady")]
        public ButtonControl pointerActivateReady { get; private set; }

        [Preserve, InputControl(offset = 232, usage = "GraspValue")]
        public AxisControl graspValue { get; private set; }
        [Preserve, InputControl(offset = 236, format = "BYTE", usage = "GraspFirm")]
        public ButtonControl graspFirm { get; private set; }
        [Preserve, InputControl(offset = 237, format = "BYTE", usage = "GraspReady")]
        public ButtonControl graspReady { get; private set; }

        [Preserve, InputControl(offset = 2, format = "BYTE")]
        new public ButtonControl isTracked { get; private set; }
        /// <summary>
        /// A [IntegerControl](xref:UnityEngine.InputSystem.Controls.IntegerControl) required for backwards compatibility with the XRSDK layouts. This represents the bit flag set to indicate what data is valid. This value is equivalent to mapping gripPose/trackingState.
        /// </summary>
        [Preserve, InputControl(offset = 4)]
        new public IntegerControl trackingState { get; private set; }
        /// <summary>
        /// A [Vector3Control](xref:UnityEngine.InputSystem.Controls.Vector3Control) required for backwards compatibility with the XRSDK layouts. This is the device position. This value is equivalent to mapping gripPose/position.
        /// </summary>
        [Preserve, InputControl(offset = 8, noisy = true, alias = "gripPosition")]
        new public Vector3Control devicePosition { get; private set; }
        /// <summary>
        /// A [QuaternionControl](xref:UnityEngine.InputSystem.Controls.QuaternionControl) required for backwards compatibility with the XRSDK layouts. This is the device orientation. This value is equivalent to mapping gripPose/rotation.
        /// </summary>
        [Preserve, InputControl(offset = 20, noisy = true, alias = "gripRotation")]
        new public QuaternionControl deviceRotation { get; private set; }
        /// <summary>
        /// A [Vector3Control](xref:UnityEngine.InputSystem.Controls.Vector3Control) required for backwards compatibility with the XRSDK layouts. This is the aim position. This value is equivalent to mapping aimPose/position.
        /// </summary>
        [Preserve, InputControl(offset = 68, noisy = true)]
        public Vector3Control pointerPosition { get; private set; }
        /// <summary>
        /// A [QuaternionControl](xref:UnityEngine.InputSystem.Controls.QuaternionControl) required for backwards compatibility with the XRSDK layouts. This is the aim orientation. This value is equivalent to mapping aimPose/rotation.
        /// </summary>
        [Preserve, InputControl(offset = 80, noisy = true)]
        public QuaternionControl pointerRotation { get; private set; }
        /// <summary>
        /// A [Vector3Control](xref:UnityEngine.InputSystem.Controls.Vector3Control) required for backwards compatibility with the XRSDK layouts. This is the poke position. This value is equivalent to mapping pokePose/position.
        /// </summary>
        [Preserve, InputControl(offset = 128, noisy = true)]
        public Vector3Control pokePosition { get; private set; }
        /// <summary>
        /// A [QuaternionControl](xref:UnityEngine.InputSystem.Controls.QuaternionControl) required for backwards compatibility with the XRSDK layouts. This is the poke orientation. This value is equivalent to mapping pokePose/rotation.
        /// </summary>
        [Preserve, InputControl(offset = 140, noisy = true)]
        public QuaternionControl pokeRotation { get; private set; }
        /// <summary>
        /// A [Vector3Control](xref:UnityEngine.InputSystem.Controls.Vector3Control) required for backwards compatibility with the XRSDK layouts. This is the pinch position. This value is equivalent to mapping pinchPose/position.
        /// </summary>
        [Preserve, InputControl(offset = 188, noisy = true)]
        public Vector3Control pinchPosition { get; private set; }
        /// <summary>
        /// A [QuaternionControl](xref:UnityEngine.InputSystem.Controls.QuaternionControl) required for backwards compatibility with the XRSDK layouts. This is the pinch orientation. This value is equivalent to mapping pinchPose/rotation.
        /// </summary>
        [Preserve, InputControl(offset = 200, noisy = true)]
        public QuaternionControl pinchRotation { get; private set; }

        // Compatibility state for existing consumers. These are no longer primary InputControls.
        public HandAimStatus compatAimFlags { get; private set; }


        /// <summary>
        /// Perform final initialization tasks after the control hierarchy has been put into place.
        /// </summary>
        protected override void FinishSetup()
        {
            base.FinishSetup();

            devicePose = GetChildControl<PoseControl>(nameof(devicePose));
            pointer = GetChildControl<PoseControl>(nameof(pointer));
            pokePose = GetChildControl<PoseControl>(nameof(pokePose));
            pinchPose = GetChildControl<PoseControl>(nameof(pinchPose));

            pinchValue = GetChildControl<AxisControl>(nameof(pinchValue));
            pinchTouched = GetChildControl<ButtonControl>(nameof(pinchTouched));
            pinchReady = GetChildControl<ButtonControl>(nameof(pinchReady));

            pointerActivateValue = GetChildControl<AxisControl>(nameof(pointerActivateValue));
            pointerActivated = GetChildControl<ButtonControl>(nameof(pointerActivated));
            pointerActivateReady = GetChildControl<ButtonControl>(nameof(pointerActivateReady));

            graspValue = GetChildControl<AxisControl>(nameof(graspValue));
            graspFirm = GetChildControl<ButtonControl>(nameof(graspFirm));
            graspReady = GetChildControl<ButtonControl>(nameof(graspReady));

            isTracked = GetChildControl<ButtonControl>(nameof(isTracked));
            trackingState = GetChildControl<IntegerControl>(nameof(trackingState));
            devicePosition = GetChildControl<Vector3Control>(nameof(devicePosition));
            deviceRotation = GetChildControl<QuaternionControl>(nameof(deviceRotation));
            pointerPosition = GetChildControl<Vector3Control>(nameof(pointerPosition));
            pointerRotation = GetChildControl<QuaternionControl>(nameof(pointerRotation));
            pokePosition = GetChildControl<Vector3Control>(nameof(pokePosition));
            pokeRotation = GetChildControl<QuaternionControl>(nameof(pokeRotation));
            pinchPosition = GetChildControl<Vector3Control>(nameof(pinchPosition));
            pinchRotation = GetChildControl<QuaternionControl>(nameof(pinchRotation));

            var deviceDescriptor = XRDeviceDescriptor.FromJson(description.capabilities);
            if (deviceDescriptor != null)
            {
                if ((deviceDescriptor.characteristics & InputDeviceCharacteristics.Left) != 0)
                    InputSystem.SetDeviceUsage(this, UnityEngine.InputSystem.CommonUsages.LeftHand);
                else if ((deviceDescriptor.characteristics & InputDeviceCharacteristics.Right) != 0)
                    InputSystem.SetDeviceUsage(this, UnityEngine.InputSystem.CommonUsages.RightHand);
            }

            PXR_Plugin.System.FocusStateAcquired += OnFocusStateAcquired;
        }

        private void OnFocusStateAcquired()
        {
            m_WasTracked = false;
        }

        protected override void OnRemoved()
        {
            PXR_Plugin.System.FocusStateAcquired -= OnFocusStateAcquired;
            base.OnRemoved();
        }

        /// <summary>
        /// Creates a <see cref="PicoHandInteraction"/> and adds it to the Input System.
        /// </summary>
        /// <param name="extraCharacteristics">
        /// Additional characteristics to build the hand device with besides
        /// <see cref="InputDeviceCharacteristics.HandTracking"/> and <see cref="InputDeviceCharacteristics.TrackedDevice"/>.
        /// </param>
        /// <returns>
        /// A <see cref="PicoHandInteraction"/> retrieved from
        /// <see cref="InputSystem.AddDevice(InputDeviceDescription)"/>.
        /// </returns>
        /// <remarks>
        /// It is recommended that you do not call this yourself. It will be
        /// called for you at the appropriate time if hand-tracking has been
        /// enabled and if you are running with either the OpenXR or Oculus
        /// plug-in.
        /// </remarks>
        public static PicoHandInteraction CreateHand(InputDeviceCharacteristics extraCharacteristics)
        {
            var desc = new InputDeviceDescription
            {
                product = k_PicoHandInteractionDeviceProductName,
                capabilities = new XRDeviceDescriptor
                {
                    characteristics = InputDeviceCharacteristics.HandTracking | InputDeviceCharacteristics.TrackedDevice | extraCharacteristics,
                    inputFeatures = new List<XRFeatureDescriptor>
                    {
                        new XRFeatureDescriptor { name = "pinchValue", featureType = FeatureType.Axis1D },
                        new XRFeatureDescriptor { name = "pinchTouched", featureType = FeatureType.Binary },
                        new XRFeatureDescriptor { name = "pinchReady", featureType = FeatureType.Binary },
                        new XRFeatureDescriptor { name = "pointerActivateValue", featureType = FeatureType.Axis1D },
                        new XRFeatureDescriptor { name = "pointerActivated", featureType = FeatureType.Binary },
                        new XRFeatureDescriptor { name = "pointerActivateReady", featureType = FeatureType.Binary },
                        new XRFeatureDescriptor { name = "graspValue", featureType = FeatureType.Axis1D },
                        new XRFeatureDescriptor { name = "graspFirm", featureType = FeatureType.Binary },
                        new XRFeatureDescriptor { name = "graspReady", featureType = FeatureType.Binary },
                        new XRFeatureDescriptor { name = "pointerPosition", featureType = FeatureType.Axis3D },
                        new XRFeatureDescriptor { name = "pointerRotation", featureType = FeatureType.Rotation },
                        new XRFeatureDescriptor { name = "pokePosition", featureType = FeatureType.Axis3D },
                        new XRFeatureDescriptor { name = "pokeRotation", featureType = FeatureType.Rotation },
                        new XRFeatureDescriptor { name = "pinchPosition", featureType = FeatureType.Axis3D },
                        new XRFeatureDescriptor { name = "pinchRotation", featureType = FeatureType.Rotation },
                    }
                }.ToJson()
            };
            return InputSystem.AddDevice(desc) as PicoHandInteraction;
        }

        /// <summary>
        /// Queues update events in the Input System based on the supplied hand.
        /// It is not recommended that you call this directly. This will be called
        /// for you when appropriate.
        /// </summary>
        /// <param name="isHandRootTracked">
        /// Whether the hand root pose is valid.
        /// </param>
        /// <param name="aimFlags">
        /// The aim flags to update in the Input System.
        /// </param>
        /// <param name="aimPose">
        /// The aim pose to update in the Input System. Used if the hand root is tracked.
        /// </param>
        /// <param name="pinchIndex">
        /// The pinch strength for the index finger to update in the Input System.
        /// </param>
        private void UpdateHand(bool isHandRootTracked, ref PxrHandInteractionState state)
        {
            bool pinchTouchedNow = state.pinchValue > pressThreshold;
            bool pointerActivatedNow = state.aimActivateValue > pressThreshold;
            bool graspFirmNow = state.graspValue > pressThreshold;

            compatAimFlags = BuildCompatAimFlags(ref state);

            InputSystem.QueueDeltaStateEvent(pinchValue, state.pinchValue);
            QueueButtonState(pinchReady, state.pinchReady);
            InputSystem.QueueDeltaStateEvent(pointerActivateValue, state.aimActivateValue);
            QueueButtonState(pointerActivateReady, state.aimActivateReady);
            InputSystem.QueueDeltaStateEvent(graspValue, state.graspValue);
            QueueButtonState(graspReady, state.graspReady);

            if (pinchTouchedNow != m_WasPinchTouched)
            {
                QueueButtonState(pinchTouched, pinchTouchedNow);
                m_WasPinchTouched = pinchTouchedNow;
            }

            if (pointerActivatedNow != m_WasPointerActivated)
            {
                QueueButtonState(pointerActivated, pointerActivatedNow);
                m_WasPointerActivated = pointerActivatedNow;
            }

            if (graspFirmNow != m_WasGraspFirm)
            {
                QueueButtonState(graspFirm, graspFirmNow);
                m_WasGraspFirm = graspFirmNow;
            }


            bool gripTracked = IsPoseTracked(state.gripPose);
            if (!gripTracked || !isHandRootTracked)
            {
                if (m_WasTracked)
                {
                    QueueButtonState(isTracked, false);
                    InputSystem.QueueDeltaStateEvent(trackingState, InputTrackingState.None);
                    m_WasTracked = false;
                }

                return;
            }

            WriteOptionalPose(devicePose, devicePosition, deviceRotation, state.gripPose);
            WriteOptionalPose(pointer, null, null, state.aimPose);
            WriteOptionalPose(pokePose, null, null, state.pokePose);
            WriteOptionalPose(pinchPose, null, null, state.pinchPose);
        

            if (!m_WasTracked)
            {
                QueueButtonState(isTracked, true);
            }

            InputSystem.QueueDeltaStateEvent(trackingState, InputTrackingState.Position | InputTrackingState.Rotation);
            m_WasTracked = true;
        }

        internal bool UpdateHand(HandType handType, bool isHandRootTracked)
        {
            PxrHandInteractionState state = default;

            if (!PXR_HandInteractionNative.GetState(handType, ref state))
            {
                Debug.LogWarning($"[PXR_HandSubSystem] {handType} hand interaction state not available.");
                if (m_WasTracked)
                {
                    InputSystem.QueueDeltaStateEvent(trackingState, InputTrackingState.None);
                    QueueButtonState(isTracked, false);
                    m_WasTracked = false;
                }
                return false;
            }
            UpdateHand(isHandRootTracked, ref state);

            // Debug.Log($"GetReady success pinchReady= {state.pinchReady} pointerActivateReady= {state.aimActivateReady} graspReady= {state.graspReady}");
            // Debug.Log($"GetValue success pinchValue= {state.pinchValue} pointerActivateValue= {state.aimActivateValue} graspValue= {state.graspValue}");
            // Debug.Log($"GetPose success gripPose= {state.gripPose.pose}");
            // Debug.Log($"GetPose success aimPose= {state.aimPose.pose}");
            // Debug.Log($"GetPose success pokePose= {state.pokePose.pose}");
            // Debug.Log($"GetPose success pinchPose= {state.pinchPose.pose}");

            return IsPoseTracked(state.aimPose);
        }

#if UNITY_EDITOR
        static PicoHandInteraction() => RegisterLayout();
#endif
        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void RegisterLayout()
        {
            InputSystem.RegisterLayout<PicoHandInteraction>(
                matches: new InputDeviceMatcher()
                    .WithProduct(k_PicoHandInteractionDeviceProductName));
        }

        static void QueueButtonState(ButtonControl control, bool pressed)
        {
            // BYTE buttons normalize 0..255; raw bool true would read as 1/255.
            InputSystem.QueueDeltaStateEvent(control, pressed ? byte.MaxValue : byte.MinValue);
        }

        static bool IsPoseTracked(PxrHandInteractionPoseState poseState)
        {
            const PxrHandInteractionLocationFlags validMask =
                PxrHandInteractionLocationFlags.PositionValid |
                PxrHandInteractionLocationFlags.OrientationValid;
            return poseState.isActive &&
                   (((PxrHandInteractionLocationFlags)poseState.locationFlags & validMask) != 0);
        }

        static void WriteOptionalPose(PoseControl poseControl, Vector3Control positionControl, QuaternionControl rotationControl, PxrHandInteractionPoseState poseState)
        {
            if (!IsPoseTracked(poseState))
            {
                return;
            }

            var position = poseState.pose.Position.ToVector3();
            var rotation = poseState.pose.Orientation.ToQuat();

            if (poseControl != null)
            {
                InputSystem.QueueDeltaStateEvent(poseControl.position, position);
                InputSystem.QueueDeltaStateEvent(poseControl.rotation, rotation);
            }

            if (positionControl != null)
            {
                InputSystem.QueueDeltaStateEvent(positionControl, position);
            }

            if (rotationControl != null)
            {
                InputSystem.QueueDeltaStateEvent(rotationControl, rotation);
            }
        }

        static HandAimStatus BuildCompatAimFlags(ref PxrHandInteractionState state)
        {
            HandAimStatus flags = 0;
            if (IsPoseTracked(state.aimPose))
            {
                flags |= HandAimStatus.AimComputed;
                flags |= HandAimStatus.AimRayValid;
            }

            if (state.pinchValue > pressThreshold)
            {
                flags |= HandAimStatus.AimIndexPinching;
            }

            if (state.aimActivateValue > 0.5f)
            {
                flags |= HandAimStatus.AimRayTouched;
            }

            return flags;
        }

        const string k_PicoHandInteractionDeviceProductName = "Pico Hand Interaction";

        bool m_WasTracked;
        bool m_WasPinchTouched;
        bool m_WasPointerActivated;
        bool m_WasGraspFirm;
    }
}
#endif
#endif //XR_HANDS
