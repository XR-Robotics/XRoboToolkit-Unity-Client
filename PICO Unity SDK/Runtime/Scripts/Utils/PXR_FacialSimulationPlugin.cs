using System;
using System.Runtime.InteropServices;
using UnityEngine;

namespace ByteDance.PICO.XR
{
    public static class PXR_FacialSimulationPlugin
    {
        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static unsafe extern PxrResult Pxr_GetFacialSimulationSupported(ref bool supported, ref int supportedModesCount, XrFacialSimulationModeBD* supportedModes);
        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern PxrResult Pxr_StartFacialSimulation(XrFacialSimulationModeBD mode);
        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern PxrResult Pxr_StopFacialSimulation();
        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern PxrResult Pxr_GetFacialSimulationData(long timestamp, ref PxrFacialSimulationData data);
        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern PxrResult Pxr_GetFacialSimulationMode(ref XrFacialSimulationModeBD mode);
        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern PxrResult Pxr_SetFacialSimulationMode(XrFacialSimulationModeBD mode);
        public static unsafe PxrResult UPxr_GetFacialSimulationSupported(ref bool supported, ref int supportedModesCount, ref XrFacialSimulationModeBD[] supportedModes)
        {
#if UNITY_EDITOR || !UNITY_ANDROID
            supported = false;
            supportedModesCount = 0;
            supportedModes = null;
            return PxrResult.SUCCESS;
#else
            supported = false;
            supportedModesCount = 0;
            supportedModes = null;
            PxrResult val = Pxr_GetFacialSimulationSupported(ref supported, ref supportedModesCount, null);

            if (val != PxrResult.SUCCESS || supportedModesCount <= 0)
            {
                return val;
            }

            supportedModes = new XrFacialSimulationModeBD[supportedModesCount];
            int modeCapacity = supportedModes.Length;

            try
            {
                fixed (XrFacialSimulationModeBD* modesPtr = supportedModes)
                {
                    supportedModesCount = modeCapacity;
                    val = Pxr_GetFacialSimulationSupported(ref supported, ref supportedModesCount, modesPtr);
                }
            }
            catch (Exception ex)
            {
                Debug.LogError($"PXR_FacialSimulationPlugin: Failed to query supported modes - {ex.Message}");
                supportedModes = null;
                supportedModesCount = 0;
                return PxrResult.ERROR_VALIDATION_FAILURE;
            }

            if (val != PxrResult.SUCCESS)
            {
                supportedModes = null;
                supportedModesCount = 0;
                return val;
            }

            if (supportedModesCount != supportedModes.Length)
            {
                Array.Resize(ref supportedModes, supportedModesCount);
            }

            return val;
#endif
        }

        public static PxrResult UPxr_StartFacialSimulation(XrFacialSimulationModeBD mode)
        {
#if UNITY_EDITOR || !UNITY_ANDROID
            return PxrResult.SUCCESS;
#else
            return Pxr_StartFacialSimulation(mode);
#endif
        }

        public static PxrResult UPxr_StopFacialSimulation()
        {
#if UNITY_EDITOR || !UNITY_ANDROID
            return PxrResult.SUCCESS;
#else
            return Pxr_StopFacialSimulation();
#endif
        }

        public static PxrResult UPxr_GetFacialSimulationMode(ref XrFacialSimulationModeBD mode)
        {
#if UNITY_EDITOR || !UNITY_ANDROID
            mode = XrFacialSimulationModeBD.XR_FACIAL_SIMULATION_MODE_DEFAULT_BD;
            return PxrResult.SUCCESS;
#else
            return Pxr_GetFacialSimulationMode(ref mode);
#endif
        }

        public static PxrResult UPxr_SetFacialSimulationMode(XrFacialSimulationModeBD mode)
        {
#if UNITY_EDITOR || !UNITY_ANDROID
            return PxrResult.SUCCESS;
#else
            return Pxr_SetFacialSimulationMode(mode);
#endif
        }

        public static PxrResult UPxr_GetFacialSimulationData(long timestamp, ref PxrFacialSimulationData data)
        {
#if UNITY_EDITOR || !UNITY_ANDROID
            return PxrResult.ERROR_VALIDATION_FAILURE;
#else
            return Pxr_GetFacialSimulationData(timestamp, ref data);
#endif
        }
    }

    public enum XrFacialSimulationModeBD
    {
        [InspectorName("None")]
        NONE = -1,
        [InspectorName("Face Only")]
        XR_FACIAL_SIMULATION_MODE_DEFAULT_BD = 0,// Only fills the XrFacialSimulationDataBD struct, which includes the full 52 facial expression weights.
        [InspectorName("Hybrid Combined Audio")]
        XR_FACIAL_SIMULATION_MODE_COMBINED_AUDIO_BD = 1,// Same as the default mode, only fills XrFacialSimulationDataBD, but the results may be more accurate.
        [InspectorName("Hybrid With Lip")]
        XR_FACIAL_SIMULATION_MODE_COMBINED_AUDIO_WITH_LIP_BD = 2,// Fills both XrFacialSimulationDataBD (facial expressions) and XrLipExpressionDataBD (20 lip viseme weights).
        [InspectorName("Lipsync Only")]
        XR_FACIAL_SIMULATION_MODE_ONLY_AUDIO_WITH_LIP_BD = 3 // Primarily fills the chained XrLipExpressionDataBD struct; at runtime, some expression data in XrFacialSimulationDataBD may also be filled.
    }

    [StructLayout(LayoutKind.Sequential)]
    public unsafe struct PxrFacialSimulationData
    {
        public long timestamp;
        public fixed float faceExpressionWeights[52];
        public fixed float lipsyncExpressionWeights[20];

        [MarshalAs(UnmanagedType.I1)]
        public bool isUpperFaceDataValid;

        [MarshalAs(UnmanagedType.I1)]
        public bool isLowerFaceDataValid;
    }

    public enum XrFaceExpressionBD
    {
        XR_FACE_EXPRESSION_BROW_DROP_L_BD = 0,
        XR_FACE_EXPRESSION_BROW_DROP_R_BD = 1,
        XR_FACE_EXPRESSION_BROW_INNER_UPWARDS_BD = 2,
        XR_FACE_EXPRESSION_BROW_OUTER_UPWARDS_L_BD = 3,
        XR_FACE_EXPRESSION_BROW_OUTER_UPWARDS_R_BD = 4,
        XR_FACE_EXPRESSION_EYE_BLINK_L_BD = 5,
        XR_FACE_EXPRESSION_EYE_LOOK_DROP_L_BD = 6,
        XR_FACE_EXPRESSION_EYE_LOOK_IN_L_BD = 7,
        XR_FACE_EXPRESSION_EYE_LOOK_OUT_L_BD = 8,
        XR_FACE_EXPRESSION_EYE_LOOK_UPWARDS_L_BD = 9,
        XR_FACE_EXPRESSION_EYE_LOOK_SQUINT_L_BD = 10,
        XR_FACE_EXPRESSION_EYE_LOOK_WIDE_L_BD = 11,
        XR_FACE_EXPRESSION_EYE_BLINK_R_BD = 12,
        XR_FACE_EXPRESSION_EYE_LOOK_DROP_R_BD = 13,
        XR_FACE_EXPRESSION_EYE_LOOK_IN_R_BD = 14,
        XR_FACE_EXPRESSION_EYE_LOOK_OUT_R_BD = 15,
        XR_FACE_EXPRESSION_EYE_LOOK_UPWARDS_R_BD = 16,
        XR_FACE_EXPRESSION_EYE_LOOK_SQUINT_R_BD = 17,
        XR_FACE_EXPRESSION_EYE_LOOK_WIDE_R_BD = 18,
        XR_FACE_EXPRESSION_NOSE_SNEER_L_BD = 19,
        XR_FACE_EXPRESSION_NOSE_SNEER_R_BD = 20,
        XR_FACE_EXPRESSION_CHEEK_PUFF_BD = 21,
        XR_FACE_EXPRESSION_CHEEK_SQUINT_L_BD = 22,
        XR_FACE_EXPRESSION_CHEEK_SQUINT_R_BD = 23,
        XR_FACE_EXPRESSION_MOUTH_CLOSE_BD = 24,
        XR_FACE_EXPRESSION_MOUTH_FUNNEL_BD = 25,
        XR_FACE_EXPRESSION_MOUTH_PUCKER_BD = 26,
        XR_FACE_EXPRESSION_MOUTH_L_BD = 27,
        XR_FACE_EXPRESSION_MOUTH_R_BD = 28,
        XR_FACE_EXPRESSION_MOUTH_SMILE_L_BD = 29,
        XR_FACE_EXPRESSION_MOUTH_SMILE_R_BD = 30,
        XR_FACE_EXPRESSION_MOUTH_FROWN_L_BD = 31,
        XR_FACE_EXPRESSION_MOUTH_FROWN_R_BD = 32,
        XR_FACE_EXPRESSION_MOUTH_DIMPLE_L_BD = 33,
        XR_FACE_EXPRESSION_MOUTH_DIMPLE_R_BD = 34,
        XR_FACE_EXPRESSION_MOUTH_STRETCH_L_BD = 35,
        XR_FACE_EXPRESSION_MOUTH_STRETCH_R_BD = 36,
        XR_FACE_EXPRESSION_MOUTH_ROLL_LOWER_BD = 37,
        XR_FACE_EXPRESSION_MOUTH_ROLL_UPPER_BD = 38,
        XR_FACE_EXPRESSION_MOUTH_SHRUG_LOWER_BD = 39,
        XR_FACE_EXPRESSION_MOUTH_SHRUG_UPPER_BD = 40,
        XR_FACE_EXPRESSION_MOUTH_PRESS_L_BD = 41,
        XR_FACE_EXPRESSION_MOUTH_PRESS_R_BD = 42,
        XR_FACE_EXPRESSION_MOUTH_LOWER_DROP_L_BD = 43,
        XR_FACE_EXPRESSION_MOUTH_LOWER_DROP_R_BD = 44,
        XR_FACE_EXPRESSION_MOUTH_UPPER_UPWARDS_L_BD = 45,
        XR_FACE_EXPRESSION_MOUTH_UPPER_UPWARDS_R_BD = 46,
        XR_FACE_EXPRESSION_JAW_FORWARD_BD = 47,
        XR_FACE_EXPRESSION_JAW_L_BD = 48,
        XR_FACE_EXPRESSION_JAW_R_BD = 49,
        XR_FACE_EXPRESSION_JAW_OPEN_BD = 50,
        XR_FACE_EXPRESSION_TONGUE_OUT_BD = 51
    }

    public enum XrLipExpressionBD
    {
        XR_LIP_EXPRESSION_PP_BD = 0,
        XR_LIP_EXPRESSION_CH_BD = 1,
        XR_LIP_EXPRESSION_LO_BD = 2,
        XR_LIP_EXPRESSION_O_BD = 3,
        XR_LIP_EXPRESSION_I_BD = 4,
        XR_LIP_EXPRESSION_LU_BD = 5,
        XR_LIP_EXPRESSION_RR_BD = 6,
        XR_LIP_EXPRESSION_XX_BD = 7,
        XR_LIP_EXPRESSION_LAA_BD = 8,
        XR_LIP_EXPRESSION_LI_BD = 9,
        XR_LIP_EXPRESSION_FF_BD = 10,
        XR_LIP_EXPRESSION_U_BD = 11,
        XR_LIP_EXPRESSION_TH_BD = 12,
        XR_LIP_EXPRESSION_LKK_BD = 13,
        XR_LIP_EXPRESSION_SS_BD = 14,
        XR_LIP_EXPRESSION_LE_BD = 15,
        XR_LIP_EXPRESSION_DD_BD = 16,
        XR_LIP_EXPRESSION_E_BD = 17,
        XR_LIP_EXPRESSION_LNN_BD = 18,
        XR_LIP_EXPRESSION_SIL_BD = 19
    }
}
