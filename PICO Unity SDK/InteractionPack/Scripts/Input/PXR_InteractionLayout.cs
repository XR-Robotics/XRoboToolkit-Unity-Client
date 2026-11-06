#if ENABLE_PICO_INTERACTION_PACK
using System.Collections.Generic;
using ByteDance.PICO.XR;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.Controls;
using UnityEngine.InputSystem.Layouts;
using UnityEngine.InputSystem.XR;
using UnityEngine.Scripting;
using UnityEngine.XR;

namespace ByteDance.PICO.Interaction
{
#if UNITY_EDITOR
    [UnityEditor.InitializeOnLoad]
#endif
    [Preserve,
     InputControlLayout(displayName = "PICO Interaction Utilities", commonUsages = new[] { "LeftHand", "RightHand" })]
    public class PXR_InteractionLayout : TrackedDevice
    {
        const string k_PICOInteractionDeviceProductName = "PICO Interaction Utilities";
        public static PXR_InteractionLayout leftHand { get; set; }
        public static PXR_InteractionLayout rightHand { get; set; }

        [Preserve, InputControl] public Vector3Control aimPosePosition { get; private set; }
        [Preserve, InputControl] public QuaternionControl aimPoseRotation { get; private set; }

        bool m_WasTracked = false;

        protected override void FinishSetup()
        {
            base.FinishSetup();

            aimPosePosition = GetChildControl<Vector3Control>(nameof(aimPosePosition));
            aimPoseRotation = GetChildControl<QuaternionControl>(nameof(aimPoseRotation));


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
#if UNITY_EDITOR
        static PXR_InteractionLayout() => RegisterLayout();
#endif
        public static void RegisterLayout()
        {
            InputSystem.RegisterLayout<PXR_InteractionLayout>(
                matches: new InputDeviceMatcher()
                    .WithProduct(k_PICOInteractionDeviceProductName));
        }

        public static PXR_InteractionLayout CreatePICOInteraction(InputDeviceCharacteristics extraCharacteristics)
        {
            // Debug.Log($"PXR_InteractionLayout CreatePICOInteractionHand {extraCharacteristics}");
            var desc = new InputDeviceDescription
            {
                product = k_PICOInteractionDeviceProductName,
                capabilities = new XRDeviceDescriptor
                {
                    characteristics = InputDeviceCharacteristics.TrackedDevice | extraCharacteristics,
                    inputFeatures = new List<XRFeatureDescriptor>
                    {
                        new XRFeatureDescriptor
                        {
                            name = "aim_pose_position",
                            featureType = FeatureType.Axis3D
                        },
                        new XRFeatureDescriptor
                        {
                            name = "aim_pose_rotation",
                            featureType = FeatureType.Rotation
                        }
                    }
                }.ToJson()
            };
            return InputSystem.AddDevice(desc) as PXR_InteractionLayout;
        }

        public void UpdatePICOInteraction(bool _trackingState, Vector3 aimPosition,
            Quaternion aimRotation)
        {
            if (!_trackingState)
            {
                if (m_WasTracked)
                {
                    InputSystem.QueueDeltaStateEvent(isTracked, false);
                    InputSystem.QueueDeltaStateEvent(trackingState, InputTrackingState.None);
                    m_WasTracked = false;
                }

                return;
            }
            InputSystem.QueueDeltaStateEvent(aimPosePosition, aimPosition);
            InputSystem.QueueDeltaStateEvent(aimPoseRotation, aimRotation);

            if (!m_WasTracked)
            {
                InputSystem.QueueDeltaStateEvent(trackingState,
                    InputTrackingState.Position | InputTrackingState.Rotation);
                InputSystem.QueueDeltaStateEvent(isTracked, true);
            }

            m_WasTracked = true;
        }
    }
}
#endif