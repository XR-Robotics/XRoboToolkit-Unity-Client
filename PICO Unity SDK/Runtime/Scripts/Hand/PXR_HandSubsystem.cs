#if PICO_MS_SDK||ENABLE_PICO_XR_SDK
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

using Unity.Collections;
using UnityEngine;
using UnityEngine.Scripting;
using System.Runtime.CompilerServices;
using UnityEngine.XR.Management;
using UnityEngine.InputSystem;
using UnityEngine.XR;
using System.Collections.Generic;

using UnityEngine.InputSystem.Controls;
using UnityEngine.InputSystem.Layouts;
using UnityEngine.InputSystem.XR;
#if PICO_MS_SDK     
using ByteDance.PICO.Spatial.Stage;
using ByteDance.PICO.Spatial;
#endif
#if XR_HANDS
using UnityEngine.XR.Hands;
using UnityEngine.XR.Hands.ProviderImplementation;
using Handedness = UnityEngine.XR.Hands.Handedness;

namespace ByteDance.PICO.XR
{
    [Preserve]
    /// <summary>
    /// Implement Unity XRHandSubSystem 
    /// Reference: https://docs.unity3d.com/Packages/com.unity.xr.hands@1.1/manual/implement-a-provider.html
    /// </summary>
    public class PXR_HandSubSystem : XRHandSubsystem
    {
        const string LogTag = "[PXR_HandSubSystem]";
        XRHandProviderUtility.SubsystemUpdater m_Updater;

        // This method registers the subsystem descriptor with the SubsystemManager
        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void RegisterDescriptor()
        {
            var handsSubsystemCinfo = new XRHandSubsystemDescriptor.Cinfo
            {
                id = "PICO Hands",
                providerType = typeof(PXRHandSubsystemProvider),
                subsystemTypeOverride = typeof(PXR_HandSubSystem)
            };
            XRHandSubsystemDescriptor.Register(handsSubsystemCinfo);
        }

        protected override void OnCreate()
        {
            base.OnCreate();
            m_Updater = new XRHandProviderUtility.SubsystemUpdater(this);
            Debug.Log($"{LogTag} OnCreate");
        }

        protected override void OnStart()
        {
            Debug.Log($"{LogTag} OnStart");
            m_Updater.Start();
            base.OnStart();
        }

        protected override void OnStop()
        {
            Debug.Log($"{LogTag} OnStop");
            m_Updater.Stop();
            base.OnStop();
        }

        protected override void OnDestroy()
        {
            Debug.Log($"{LogTag} OnDestroy");
            m_Updater.Destroy();
            m_Updater = null;
            base.OnDestroy();
        }

#if PICO_MS_SDK
        public static PICOTrackingState GetHandTrackingState()
        {
            return (PICOTrackingState)SpatialNativeApi.Pmp_GetHandTrackingState();
        }

        public static PICOTrackingSupportState GetHandTrackingSupported()
        {
            return (PICOTrackingSupportState)SpatialNativeApi.Pmp_GetHandTrackingSupported();
        }
#endif

        class PXRHandSubsystemProvider : XRHandSubsystemProvider
        {
            HandJointLocations jointLocations = new HandJointLocations();

            readonly HandLocationStatus AllStatus = HandLocationStatus.PositionTracked | HandLocationStatus.PositionValid |
                                                    HandLocationStatus.OrientationTracked | HandLocationStatus.OrientationValid;

            bool isValid = false;
            bool m_HasLoggedInvalidLayout;
            bool m_LeftUpdateFailedLogged;
            bool m_RightUpdateFailedLogged;
            bool m_LeftInactiveLogged;
            bool m_RightInactiveLogged;
            bool m_LeftTrackingActiveLogged;
            bool m_RightTrackingActiveLogged;
            bool? m_LastHandInteractionSupported;
#if PICO_MS_SDK
            bool isHandTrackingActive = false;

            public bool SetAutomaticUpdatingEnabled(bool isEnabled)
            {
                if (isEnabled != isHandTrackingActive)
                {
                    if (isEnabled)
                    {
                        isHandTrackingActive = SpatialNativeApi.Pmp_StartHandTracking();
                        Debug.Log($"{LogTag} SetAutomaticUpdatingEnabled(true) -> {isHandTrackingActive}");
                    }
                    else
                    {
                        isHandTrackingActive = !SpatialNativeApi.Pmp_StopHandTracking();
                        Debug.Log($"{LogTag} SetAutomaticUpdatingEnabled(false) -> {!isHandTrackingActive}");
                    }
                    return true;
                }
                
                return false;
            }
#endif

            public override void Start()
            {
                Debug.Log($"{LogTag} Provider.Start");
#if ENABLE_PICO_XR_SDK||PICO_MS_SDK
                CreateHands();
#endif
            }

            public override void Stop()
            {
                Debug.Log($"{LogTag} Provider.Stop");
#if ENABLE_PICO_XR_SDK||PICO_MS_SDK
                DestroyHands();
#endif
                
#if PICO_MS_SDK
                // Disable automatic updating
                SetAutomaticUpdatingEnabled(false);
#endif
            }

            public override void Destroy()
            {
            }

            /// <summary>
            /// Mapping the PICO Joint Index To Unity Joint Index
            /// </summary>
            static int[] pxrJointIndexToUnityJointIndexMapping;

            static void Initialize()
            {
                if (pxrJointIndexToUnityJointIndexMapping == null)
                {
                    pxrJointIndexToUnityJointIndexMapping = new int[(int)HandJoint.JointMax];
                    pxrJointIndexToUnityJointIndexMapping[(int)HandJoint.JointPalm] = XRHandJointID.Palm.ToIndex();
                    pxrJointIndexToUnityJointIndexMapping[(int)HandJoint.JointWrist] = XRHandJointID.Wrist.ToIndex();
                    pxrJointIndexToUnityJointIndexMapping[(int)HandJoint.JointThumbMetacarpal] = XRHandJointID.ThumbMetacarpal.ToIndex();
                    pxrJointIndexToUnityJointIndexMapping[(int)HandJoint.JointThumbProximal] = XRHandJointID.ThumbProximal.ToIndex();
                    pxrJointIndexToUnityJointIndexMapping[(int)HandJoint.JointThumbDistal] = XRHandJointID.ThumbDistal.ToIndex();
                    pxrJointIndexToUnityJointIndexMapping[(int)HandJoint.JointThumbTip] = XRHandJointID.ThumbTip.ToIndex();

                    pxrJointIndexToUnityJointIndexMapping[(int)HandJoint.JointIndexMetacarpal] = XRHandJointID.IndexMetacarpal.ToIndex();
                    pxrJointIndexToUnityJointIndexMapping[(int)HandJoint.JointIndexProximal] = XRHandJointID.IndexProximal.ToIndex();
                    pxrJointIndexToUnityJointIndexMapping[(int)HandJoint.JointIndexIntermediate] = XRHandJointID.IndexIntermediate.ToIndex();
                    pxrJointIndexToUnityJointIndexMapping[(int)HandJoint.JointIndexDistal] = XRHandJointID.IndexDistal.ToIndex();
                    pxrJointIndexToUnityJointIndexMapping[(int)HandJoint.JointIndexTip] = XRHandJointID.IndexTip.ToIndex();


                    pxrJointIndexToUnityJointIndexMapping[(int)HandJoint.JointMiddleMetacarpal] = XRHandJointID.MiddleMetacarpal.ToIndex();
                    pxrJointIndexToUnityJointIndexMapping[(int)HandJoint.JointMiddleProximal] = XRHandJointID.MiddleProximal.ToIndex();
                    pxrJointIndexToUnityJointIndexMapping[(int)HandJoint.JointMiddleIntermediate] = XRHandJointID.MiddleIntermediate.ToIndex();
                    pxrJointIndexToUnityJointIndexMapping[(int)HandJoint.JointMiddleDistal] = XRHandJointID.MiddleDistal.ToIndex();
                    pxrJointIndexToUnityJointIndexMapping[(int)HandJoint.JointMiddleTip] = XRHandJointID.MiddleTip.ToIndex();

                    pxrJointIndexToUnityJointIndexMapping[(int)HandJoint.JointRingMetacarpal] = XRHandJointID.RingMetacarpal.ToIndex();
                    pxrJointIndexToUnityJointIndexMapping[(int)HandJoint.JointRingProximal] = XRHandJointID.RingProximal.ToIndex();
                    pxrJointIndexToUnityJointIndexMapping[(int)HandJoint.JointRingIntermediate] = XRHandJointID.RingIntermediate.ToIndex();
                    pxrJointIndexToUnityJointIndexMapping[(int)HandJoint.JointRingDistal] = XRHandJointID.RingDistal.ToIndex();
                    pxrJointIndexToUnityJointIndexMapping[(int)HandJoint.JointRingTip] = XRHandJointID.RingTip.ToIndex();

                    pxrJointIndexToUnityJointIndexMapping[(int)HandJoint.JointLittleMetacarpal] = XRHandJointID.LittleMetacarpal.ToIndex();
                    pxrJointIndexToUnityJointIndexMapping[(int)HandJoint.JointLittleProximal] = XRHandJointID.LittleProximal.ToIndex();
                    pxrJointIndexToUnityJointIndexMapping[(int)HandJoint.JointLittleIntermediate] = XRHandJointID.LittleIntermediate.ToIndex();
                    pxrJointIndexToUnityJointIndexMapping[(int)HandJoint.JointLittleDistal] = XRHandJointID.LittleDistal.ToIndex();
                    pxrJointIndexToUnityJointIndexMapping[(int)HandJoint.JointLittleTip] = XRHandJointID.LittleTip.ToIndex();
                }
            }

            /// <summary>
            /// Gets the layout of hand joints for this provider, by having the
            /// provider mark each index corresponding to a <see cref="XRHandJointID"/>
            /// get marked as <see langword="true"/> if the provider attempts to track
            /// that joint.
            /// </summary>
            /// <remarks>
            /// Called once on creation so that before the subsystem is even started,
            /// so the user can immediately create a valid hierarchical structure as
            /// soon as they get a reference to the subsystem without even needing to
            /// start it.
            /// </remarks>
            /// <param name="handJointsInLayout">
            /// Each index corresponds to a <see cref="XRHandJointID"/>. For each
            /// joint that the provider will attempt to track, mark that spot as
            /// <see langword="true"/> by calling <c>.ToIndex()</c> on that ID.
            /// </param>
            public override void GetHandLayout(NativeArray<bool> handJointsInLayout)
            {
                Initialize();
                handJointsInLayout[XRHandJointID.Palm.ToIndex()] = true;
                handJointsInLayout[XRHandJointID.Wrist.ToIndex()] = true;

                handJointsInLayout[XRHandJointID.ThumbMetacarpal.ToIndex()] = true;
                handJointsInLayout[XRHandJointID.ThumbProximal.ToIndex()] = true;
                handJointsInLayout[XRHandJointID.ThumbDistal.ToIndex()] = true;
                handJointsInLayout[XRHandJointID.ThumbTip.ToIndex()] = true;

                handJointsInLayout[XRHandJointID.IndexMetacarpal.ToIndex()] = true;
                handJointsInLayout[XRHandJointID.IndexProximal.ToIndex()] = true;
                handJointsInLayout[XRHandJointID.IndexIntermediate.ToIndex()] = true;
                handJointsInLayout[XRHandJointID.IndexDistal.ToIndex()] = true;
                handJointsInLayout[XRHandJointID.IndexTip.ToIndex()] = true;

                handJointsInLayout[XRHandJointID.MiddleMetacarpal.ToIndex()] = true;
                handJointsInLayout[XRHandJointID.MiddleProximal.ToIndex()] = true;
                handJointsInLayout[XRHandJointID.MiddleIntermediate.ToIndex()] = true;
                handJointsInLayout[XRHandJointID.MiddleDistal.ToIndex()] = true;
                handJointsInLayout[XRHandJointID.MiddleTip.ToIndex()] = true;

                handJointsInLayout[XRHandJointID.RingMetacarpal.ToIndex()] = true;
                handJointsInLayout[XRHandJointID.RingProximal.ToIndex()] = true;
                handJointsInLayout[XRHandJointID.RingIntermediate.ToIndex()] = true;
                handJointsInLayout[XRHandJointID.RingDistal.ToIndex()] = true;
                handJointsInLayout[XRHandJointID.RingTip.ToIndex()] = true;

                handJointsInLayout[XRHandJointID.LittleMetacarpal.ToIndex()] = true;
                handJointsInLayout[XRHandJointID.LittleProximal.ToIndex()] = true;
                handJointsInLayout[XRHandJointID.LittleIntermediate.ToIndex()] = true;
                handJointsInLayout[XRHandJointID.LittleDistal.ToIndex()] = true;
                handJointsInLayout[XRHandJointID.LittleTip.ToIndex()] = true;

                isValid = true;
            }


            /// <summary>
            /// Attempts to retrieve current hand-tracking data from the provider.
            /// </summary>
            public override UpdateSuccessFlags TryUpdateHands(
                UpdateType updateType,
                ref Pose leftHandRootPose,
                NativeArray<XRHandJoint> leftHandJoints,
                ref Pose rightHandRootPose,
                NativeArray<XRHandJoint> rightHandJoints)
            {
                if (!isValid)
                {
                    if (!m_HasLoggedInvalidLayout)
                    {
                        Debug.LogWarning($"{LogTag} TryUpdateHands skipped because hand layout is not initialized yet.");
                        m_HasLoggedInvalidLayout = true;
                    }
                    return UpdateSuccessFlags.None;
                }
#if PICO_MS_SDK
                // Enable automatic updating
                if (!isHandTrackingActive)
                {
                    SetAutomaticUpdatingEnabled(true);
                }
#endif

                UpdateSuccessFlags ret = UpdateSuccessFlags.None;

                const int handRootIndex = (int)HandJoint.JointWrist;
                


#if ENABLE_PICO_XR_SDK
                if (PXR_HandTracking.GetJointLocations(HandType.HandLeft, ref jointLocations))
#elif PICO_MS_SDK
                if (GetJointLocations(HandType.HandLeft, ref jointLocations))
#endif
                {
                    if (jointLocations.isActive != 0U)
                    {
                        if (!m_LeftTrackingActiveLogged || m_LeftUpdateFailedLogged || m_LeftInactiveLogged)
                        {
                            Debug.Log($"{LogTag} Left hand tracking active. jointCount={jointLocations.jointCount}, updateType={updateType}");
                            m_LeftTrackingActiveLogged = true;
                        }
                        m_LeftUpdateFailedLogged = false;
                        m_LeftInactiveLogged = false;

                        for (int index = 0, jointCount = (int)jointLocations.jointCount; index < jointCount; ++index)
                        {
                            ref HandJointLocation joint = ref jointLocations.jointLocations[index];
                            int unityHandJointIndex = pxrJointIndexToUnityJointIndexMapping[index];

                            leftHandJoints[unityHandJointIndex] = CreateXRHandJoint(Handedness.Left, unityHandJointIndex, joint);

                            if (index == handRootIndex)
                            {
                                leftHandRootPose = PXRPosefToUnityPose(joint.pose);
                                ret |= UpdateSuccessFlags.LeftHandRootPose;
                            }
                        }
#if UNITY_EDITOR
                        ret |= UpdateSuccessFlags.LeftHandJoints;
#else

#if ENABLE_PICO_XR_SDK
                        // When hand interaction is not supported, PicoHandInteraction.left may be null (CreateHands has already called DestroyHands).
                        // Here we only skip the device update, which does not affect the success path where XRHand joints have already been populated.
                        if (PicoHandInteraction.left != null
                            && PicoHandInteraction.left.UpdateHand(HandType.HandLeft, (ret & UpdateSuccessFlags.LeftHandRootPose) != 0))
                        {
                            ret |= UpdateSuccessFlags.LeftHandJoints;
                        }
                        else
                        {
                            // Even if the hand interaction device is unavailable, joints have already been written, so the LeftHandJoints success flag must be preserved.
                            ret |= UpdateSuccessFlags.LeftHandJoints;
                        }
#elif PICO_MS_SDK
                        if (PicoAimHand.left != null
                            && PicoAimHand.left.UpdateHand(HandType.HandLeft, (ret & UpdateSuccessFlags.LeftHandRootPose) != 0))
                        {
                            ret |= UpdateSuccessFlags.LeftHandJoints;
                        }
                        else
                        {
                            ret |= UpdateSuccessFlags.LeftHandJoints;
                        }
#endif
#endif
                    }
                    else if (!m_LeftInactiveLogged)
                    {
                        Debug.LogWarning($"{LogTag} Left hand joint data received but hand is inactive. updateType={updateType}");
                        m_LeftInactiveLogged = true;
                        m_LeftTrackingActiveLogged = false;
                    }
                }
                else if (!m_LeftUpdateFailedLogged)
                {
                    Debug.LogWarning($"{LogTag} Failed to get left hand joint locations. updateType={updateType}");
                    m_LeftUpdateFailedLogged = true;
                    m_LeftTrackingActiveLogged = false;
                }

#if ENABLE_PICO_XR_SDK
                if (PXR_HandTracking.GetJointLocations(HandType.HandRight, ref jointLocations))
#elif PICO_MS_SDK
                if (GetJointLocations(HandType.HandRight, ref jointLocations))
#endif
                
                {
                    if (jointLocations.isActive != 0U)
                    {
                        if (!m_RightTrackingActiveLogged || m_RightUpdateFailedLogged || m_RightInactiveLogged)
                        {
                            Debug.Log($"{LogTag} Right hand tracking active. jointCount={jointLocations.jointCount}, updateType={updateType}");
                            m_RightTrackingActiveLogged = true;
                        }
                        m_RightUpdateFailedLogged = false;
                        m_RightInactiveLogged = false;

                        for (int index = 0, jointCount = (int)jointLocations.jointCount; index < jointCount; ++index)
                        {
                            ref HandJointLocation joint = ref jointLocations.jointLocations[index];
                            int unityHandJointIndex = pxrJointIndexToUnityJointIndexMapping[index];
                            rightHandJoints[unityHandJointIndex] = CreateXRHandJoint(Handedness.Right, unityHandJointIndex, joint);

                            if (index == handRootIndex)
                            {
                                rightHandRootPose = PXRPosefToUnityPose(joint.pose);
                                ret |= UpdateSuccessFlags.RightHandRootPose;
                            }
                        }

#if UNITY_EDITOR
                        ret |= UpdateSuccessFlags.RightHandJoints;
#else

#if ENABLE_PICO_XR_SDK
                        if (PicoHandInteraction.right != null
                            && PicoHandInteraction.right.UpdateHand(HandType.HandRight, (ret & UpdateSuccessFlags.RightHandRootPose) != 0))
                        {
                            ret |= UpdateSuccessFlags.RightHandJoints;
                        }
                        else
                        {
                            ret |= UpdateSuccessFlags.RightHandJoints;
                        }
#elif PICO_MS_SDK
                        if (PicoAimHand.right != null
                            && PicoAimHand.right.UpdateHand(HandType.HandRight, (ret & UpdateSuccessFlags.RightHandRootPose) != 0))
                        {
                            ret |= UpdateSuccessFlags.RightHandJoints;
                        }
                        else
                        {
                            ret |= UpdateSuccessFlags.RightHandJoints;
                        }
#endif
#endif
                    }
                    else if (!m_RightInactiveLogged)
                    {
                        Debug.LogWarning($"{LogTag} Right hand joint data received but hand is inactive. updateType={updateType}");
                        m_RightInactiveLogged = true;
                        m_RightTrackingActiveLogged = false;
                    }
                }
                else if (!m_RightUpdateFailedLogged)
                {
                    Debug.LogWarning($"{LogTag} Failed to get right hand joint locations. updateType={updateType}");
                    m_RightUpdateFailedLogged = true;
                    m_RightTrackingActiveLogged = false;
                }

                return ret;
            }
            
#if PICO_MS_SDK
            bool GetJointLocations(HandType hand, ref HandJointLocations jointLocations)
            {
                HandJointResult handJointResult = new HandJointResult();
                SpatialNativeApi.Pmp_GetHandHandJointResult((int)hand, ref handJointResult);
                HandLocationStatus status = handJointResult.isActive == 1 ? AllStatus : HandLocationStatus.None;

                jointLocations.isActive = handJointResult.isActive;
                jointLocations.jointCount = 26;
                jointLocations.jointLocations = new HandJointLocation[26];
                for (int i = 0; i < 26; i++)
                {
                    jointLocations.jointLocations[i].locationStatus = status;
                    jointLocations.jointLocations[i].pose = UnityPosefToPXRPose(handJointResult.jointLocations[i]);
                }

                return handJointResult.isActive == 1;
            }   
#endif

#if ENABLE_PICO_XR_SDK||PICO_MS_SDK
            void CreateHands()
            {
#if ENABLE_PICO_XR_SDK
                bool isSupported = PXR_HandInteractionNative.GetSupported();
                if (m_LastHandInteractionSupported != isSupported)
                {
                    if (isSupported)
                        Debug.Log($"{LogTag} Hand interaction is supported.");
                    else
                        Debug.LogWarning($"{LogTag} Hand interaction is not supported. Existing hand devices will be removed.");

                    m_LastHandInteractionSupported = isSupported;
                }

                if (!isSupported)
                {
                    DestroyHands();
                    return;
                }
#endif
                Debug.Log($"{LogTag} Created hands.");
#if ENABLE_PICO_XR_SDK
                if (PicoHandInteraction.left == null)
                {
                    PicoHandInteraction.left = PicoHandInteraction.CreateHand(InputDeviceCharacteristics.Left);
                    Debug.Log($"{LogTag} Created left PicoHandInteraction device.");
                }

                if (PicoHandInteraction.right == null)
                {
                    PicoHandInteraction.right = PicoHandInteraction.CreateHand(InputDeviceCharacteristics.Right);
                    Debug.Log($"{LogTag} Created right PicoHandInteraction device.");
                }
#elif PICO_MS_SDK
                if (PicoAimHand.left == null)
                {
                    PicoAimHand.left = PicoAimHand.CreateHand(InputDeviceCharacteristics.Left);
                    Debug.Log($"{LogTag} Created left PicoAimHand device.");
                }

                if (PicoAimHand.right == null)
                {
                    PicoAimHand.right = PicoAimHand.CreateHand(InputDeviceCharacteristics.Right);
                    Debug.Log($"{LogTag} Created right PicoAimHand device.");
                }
#endif
            }

            void DestroyHands()
            {
#if ENABLE_PICO_XR_SDK
                if (PicoHandInteraction.left != null)
                {
                    Debug.Log($"{LogTag} Removing left PicoHandInteraction device.");
                    InputSystem.RemoveDevice(PicoHandInteraction.left);
                    PicoHandInteraction.left = null;
                }

                if (PicoHandInteraction.right != null)
                {
                    Debug.Log($"{LogTag} Removing right PicoHandInteraction device.");
                    InputSystem.RemoveDevice(PicoHandInteraction.right);
                    PicoHandInteraction.right = null;
                }
#elif PICO_MS_SDK
                if (PicoAimHand.left != null)
                {
                    Debug.Log($"{LogTag} Removing left PicoAimHand device.");
                    InputSystem.RemoveDevice(PicoAimHand.left);
                    PicoAimHand.left = null;
                }

                if (PicoAimHand.right != null)
                {
                    Debug.Log($"{LogTag} Removing right PicoAimHand device.");
                    InputSystem.RemoveDevice(PicoAimHand.right);
                    PicoAimHand.right = null;
                }
#endif
            }
#endif
            
            /// <summary>
            /// Create Unity XRHandJoint From PXR HandJointLocation
            /// </summary>
            /// <param name="handedness"></param>
            /// <param name="unityHandJointIndex"></param>
            /// <param name="joint"></param>
            /// <returns></returns>
            [MethodImpl(MethodImplOptions.AggressiveInlining)]
            XRHandJoint CreateXRHandJoint(Handedness handedness, int unityHandJointIndex, in HandJointLocation joint)
            {
                Pose pose = Pose.identity;
                XRHandJointTrackingState state = XRHandJointTrackingState.None;
                if ((joint.locationStatus & AllStatus) == AllStatus)
                {
                    state = (XRHandJointTrackingState.Pose | XRHandJointTrackingState.Radius);
                    pose = PXRPosefToUnityPose(joint.pose);
                }

                return XRHandProviderUtility.CreateJoint(handedness,
                    state,
                    XRHandJointIDUtility.FromIndex(unityHandJointIndex),
                    pose,joint.radius
                );

            }


            /// <summary>
            /// PXR's Posef to Unity'Pose
            /// </summary>
            /// <param name="pxrPose"></param>
            /// <returns></returns>
            [MethodImpl(MethodImplOptions.AggressiveInlining)]
            Pose PXRPosefToUnityPose(in Posef pxrPose)
            {
                Vector3 position = pxrPose.Position.ToVector3();
                Quaternion orientation = pxrPose.Orientation.ToQuat();
                return new Pose(position, orientation);
            }
            
            Posef UnityPosefToPXRPose(in Pose unityPose)
            {
                Vector3f position = new Vector3f
                {
                    x = unityPose.position.x,
                    y = unityPose.position.y,
                    z = - unityPose.position.z
                };
                Quatf orientation  = new Quatf
                {
                    x = unityPose.rotation.x,
                    y = unityPose.rotation.y,
                    z = - unityPose.rotation.z,
                    w = - unityPose.rotation.w
                };
                return new Posef
                {
                    Position = position,
                    Orientation = orientation
                };
            }
        }
    }
}
#endif //XR_HANDS
#endif
