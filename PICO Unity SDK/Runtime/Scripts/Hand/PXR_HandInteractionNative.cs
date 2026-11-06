#if !ENABLE_PICO_OPENXR_SDK
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

using System;
using System.Runtime.InteropServices;

#if XR_HANDS
namespace ByteDance.PICO.XR
{
    [Flags]
    internal enum PxrHandInteractionLocationFlags : ulong
    {
        None = 0,
        OrientationValid = 0x00000001,
        PositionValid = 0x00000002,
        OrientationTracked = 0x00000004,
        PositionTracked = 0x00000008,
    }

    [StructLayout(LayoutKind.Sequential)]
    internal struct PxrHandInteractionPoseState
    {
        public Posef pose;
        public ulong locationFlags;
        [MarshalAs(UnmanagedType.I1)] public bool isActive;
        private byte reserved0;
        private byte reserved1;
        private byte reserved2;
    }

    [StructLayout(LayoutKind.Sequential)]
    internal struct PxrHandInteractionState
    {
        public PxrHandInteractionPoseState aimPose;
        public PxrHandInteractionPoseState gripPose;
        public PxrHandInteractionPoseState pinchPose;
        public PxrHandInteractionPoseState pokePose;

        public float pinchValue;
        public float aimActivateValue;
        public float graspValue;

        [MarshalAs(UnmanagedType.I1)] public bool pinchReady;
        [MarshalAs(UnmanagedType.I1)] public bool aimActivateReady;
        [MarshalAs(UnmanagedType.I1)] public bool graspReady;
        private byte reserved3;
    }

    internal static class PXR_HandInteractionNative
    {
#if ENABLE_PICO_XR_SDK
        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_GetHandInteractionSupported([MarshalAs(UnmanagedType.I1)] ref bool supported);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_GetHandInteractionState(int hand, ref PxrHandInteractionState state);
#endif

        internal static bool GetSupported()
        {
#if ENABLE_PICO_XR_SDK
#if UNITY_EDITOR || UNITY_STANDALONE
            if (!PXR_Plugin.Loadstate)
            {
                return false;
            }
#endif
            if (!PXR_ProjectSetting.GetProjectConfig().handTracking)
            {
                return false;
            }

            bool supported = false;
            return Pxr_GetHandInteractionSupported(ref supported) == 0 && supported;
#else
            return false;
#endif
        }

        internal static bool GetState(HandType hand, ref PxrHandInteractionState state)
        {
#if ENABLE_PICO_XR_SDK
#if UNITY_EDITOR || UNITY_STANDALONE
            if (!PXR_Plugin.Loadstate)
            {
                return false;
            }
#endif
            if (!PXR_ProjectSetting.GetProjectConfig().handTracking)
            {
                return false;
            }

            return Pxr_GetHandInteractionState((int)hand, ref state) == 0;
#else
            return false;
#endif
        }
    }
}
#endif
#endif
