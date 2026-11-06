#if PICO_MS_SDK
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.Controls;
using UnityEngine.InputSystem.Layouts;
using UnityEngine.InputSystem.XR;
using UnityEngine.Scripting;
using UnityEngine.XR;
using ByteDance.PICO.Spatial.Stage;
using ByteDance.PICO.Spatial;
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
    [Preserve, InputControlLayout(displayName = "Pico Aim Hand", commonUsages = new[] { "LeftHand", "RightHand" })]
    public partial class PicoAimHand : TrackedDevice
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
        public static PicoAimHand left { get; set; }

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
        public static PicoAimHand right { get; set; }

        /// <summary>
        /// The pinch amount required to register as being pressed for the
        /// purposes of <see cref="indexPressed"/>, <see cref="middlePressed"/>,
        /// <see cref="ringPressed"/>, and <see cref="littlePressed"/>.
        /// </summary>
        public const float pressThreshold = 0.8f;

        /// <summary>
        /// A [ButtonControl](xref:UnityEngine.InputSystem.Controls.ButtonControl)
        /// that represents whether the pinch between the index finger and
        /// the thumb is mostly pressed (greater than a threshold of <c>0.8</c>
        /// contained in <see cref="pressThreshold"/>).
        /// </summary>
        [Preserve, InputControl(offset = 0)]
        public ButtonControl indexPressed { get; private set; }

        /// <summary>
        /// Cast the result of reading this to <see cref="PicoAimFlags"/> to examine the value.
        /// </summary>
        [Preserve, InputControl]
        public IntegerControl aimFlags { get; private set; }

        /// <summary>
        /// An [AxisControl](xref:UnityEngine.InputSystem.Controls.AxisControl)
        /// that represents the pinch strength between the index finger and
        /// the thumb.
        /// </summary>
        /// <remarks>
        /// A value of <c>0</c> denotes no pinch at all, while a value of
        /// <c>1</c> denotes a full pinch.
        /// </remarks>
        [Preserve, InputControl]
        public AxisControl pinchStrengthIndex { get; private set; }

        [Preserve, InputControl]
        public Vector3Control pinchPosePosition { get; private set; }

        [Preserve, InputControl]
        public QuaternionControl pinchPoseRotation { get; private set; }

        /// <summary>
        /// Perform final initialization tasks after the control hierarchy has been put into place.
        /// </summary>
        protected override void FinishSetup()
        {
            base.FinishSetup();

            indexPressed = GetChildControl<ButtonControl>(nameof(indexPressed));
            aimFlags = GetChildControl<IntegerControl>(nameof(aimFlags));
            pinchStrengthIndex = GetChildControl<AxisControl>(nameof(pinchStrengthIndex));
            pinchPosePosition = GetChildControl<Vector3Control>(nameof(pinchPosePosition));
            pinchPoseRotation = GetChildControl<QuaternionControl>(nameof(pinchPoseRotation));

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
        /// Creates a <see cref="PicoAimHand"/> and adds it to the Input System.
        /// </summary>
        /// <param name="extraCharacteristics">
        /// Additional characteristics to build the hand device with besides
        /// <see cref="InputDeviceCharacteristics.HandTracking"/> and <see cref="InputDeviceCharacteristics.TrackedDevice"/>.
        /// </param>
        /// <returns>
        /// A <see cref="PicoAimHand"/> retrieved from
        /// <see cref="InputSystem.AddDevice(InputDeviceDescription)"/>.
        /// </returns>
        /// <remarks>
        /// It is recommended that you do not call this yourself. It will be
        /// called for you at the appropriate time if hand-tracking has been
        /// enabled and if you are running with either the OpenXR or Oculus
        /// plug-in.
        /// </remarks>
        public static PicoAimHand CreateHand(InputDeviceCharacteristics extraCharacteristics)
        {
            var desc = new InputDeviceDescription
            {
                product = k_PicoAimHandDeviceProductName,
                capabilities = new XRDeviceDescriptor
                {
                    characteristics = InputDeviceCharacteristics.HandTracking | InputDeviceCharacteristics.TrackedDevice | extraCharacteristics,
                    inputFeatures = new List<XRFeatureDescriptor>
                    {
                        new XRFeatureDescriptor
                        {
                            name = "index_pressed",
                            featureType = FeatureType.Binary
                        },
                        new XRFeatureDescriptor
                        {
                            name = "aim_flags",
                            featureType = FeatureType.DiscreteStates
                        },
                        new XRFeatureDescriptor
                        {
                            name = "aim_pose_position",
                            featureType = FeatureType.Axis3D
                        },
                        new XRFeatureDescriptor
                        {
                            name = "aim_pose_rotation",
                            featureType = FeatureType.Rotation
                        },
                        new XRFeatureDescriptor
                        {
                            name = "pinch_strength_index",
                            featureType = FeatureType.Axis1D
                        },
                        new XRFeatureDescriptor
                        {
                            name = "pinch_Pose_Position",
                            featureType = FeatureType.Axis3D
                        },
                        new XRFeatureDescriptor
                        {
                            name = "pinch_Pose_Rotation",
                            featureType = FeatureType.Rotation
                        },
                    }
                }.ToJson()
            };
            return InputSystem.AddDevice(desc) as PicoAimHand;
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
        public void UpdateHand(bool isHandRootTracked, HandAimStatus aimFlags, Posef aimPose, Posef pinchPose, float pinchIndex)
        {
            if (aimFlags != m_PreviousFlags)
            {
                InputSystem.QueueDeltaStateEvent(this.aimFlags, (int)aimFlags);
                m_PreviousFlags = aimFlags;
            }

            bool isIndexPressed = pinchIndex > pressThreshold;

            if (isIndexPressed != m_WasIndexPressed)
            {
                InputSystem.QueueDeltaStateEvent(indexPressed, isIndexPressed);
                m_WasIndexPressed = isIndexPressed;
            }

            InputSystem.QueueDeltaStateEvent(pinchStrengthIndex, pinchIndex);

            if ((aimFlags & HandAimStatus.AimComputed) == 0)
            {
                if (m_WasTracked)
                {
                    InputSystem.QueueDeltaStateEvent(isTracked, false);
                    InputSystem.QueueDeltaStateEvent(trackingState, InputTrackingState.None);
                    m_WasTracked = false;
                }

                return;
            }

            if (isHandRootTracked)
            {
                InputSystem.QueueDeltaStateEvent(devicePosition, aimPose.Position.ToVector3());
                InputSystem.QueueDeltaStateEvent(deviceRotation, aimPose.Orientation.ToQuat());

                InputSystem.QueueDeltaStateEvent(pinchPosePosition, pinchPose.Position.ToVector3());
                InputSystem.QueueDeltaStateEvent(pinchPoseRotation, pinchPose.Orientation.ToQuat());
                if (!m_WasTracked)
                {
                    InputSystem.QueueDeltaStateEvent(trackingState, InputTrackingState.Position | InputTrackingState.Rotation);
                    InputSystem.QueueDeltaStateEvent(isTracked, true);
                }

                m_WasTracked = true;
            }
            else if (m_WasTracked)
            {
                InputSystem.QueueDeltaStateEvent(trackingState, InputTrackingState.None);
                InputSystem.QueueDeltaStateEvent(isTracked, false);
                m_WasTracked = false;
            }
        }

        internal bool UpdateHand(HandType handType, bool isHandRootTracked)
        {
            HandPinchState handState = new HandPinchState();
            SpatialNativeApi.Pmp_GetHandTrackerPinchState((int)handType, ref handState);
            Posef handPose = new Posef();
            handPose.Position.x = handState.PinchPose.position.x;
            handPose.Position.y = handState.PinchPose.position.y;
            handPose.Position.z = handState.PinchPose.position.z;
            handPose.Orientation.x = handState.PinchPose.rotation.x;
            handPose.Orientation.y = handState.PinchPose.rotation.y;
            handPose.Orientation.z = handState.PinchPose.rotation.z;
            handPose.Orientation.w = handState.PinchPose.rotation.w;

            UpdateHand(
                isHandRootTracked,
                handState.isActive == 1 ? HandAimStatus.AimComputed : 0, Posef.Identity,
                handPose,
                handState.pinchStrengthIndex);
            m_WasTracked = handState.isActive == 1;
            return handState.isActive == 1;

        }

#if UNITY_EDITOR
        static PicoAimHand() => RegisterLayout();
#endif
        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void RegisterLayout()
        {
            InputSystem.RegisterLayout<PicoAimHand>(
                matches: new InputDeviceMatcher()
                    .WithProduct(k_PicoAimHandDeviceProductName));
        }

        const string k_PicoAimHandDeviceProductName = "Pico Aim Hand Tracking";

        HandAimStatus m_PreviousFlags;
        bool m_WasTracked;
        bool m_WasIndexPressed;
    }
}
#endif //XR_HANDS
#endif
