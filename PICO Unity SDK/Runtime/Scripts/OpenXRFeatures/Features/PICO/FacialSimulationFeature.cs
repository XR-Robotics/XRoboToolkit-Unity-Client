#if ENABLE_PICO_OPENXR_SDK
using ByteDance.PICO.XR;
using UnityEngine;
using UnityEngine.XR.OpenXR;
#if UNITY_EDITOR
using UnityEditor.XR.OpenXR.Features;
#endif

namespace ByteDance.PICO.OpenXR
{
#if UNITY_EDITOR
    [OpenXRFeature(UiName = "PICO Facial Simulation",
        Hidden = false,
        BuildTargetGroups = new[] { UnityEditor.BuildTargetGroup.Android },
        Company = "PICO",
        OpenxrExtensionStrings = extensionString,
        Version = PXR_Plugin.PXR_SDK_Version,
        FeatureId = featureId)]
#endif
    public class FacialSimulationFeature : OpenXRFeatureBase
    {
        public const string featureId = "com.pico.openxr.feature.PICO_FacialSimulation";
        public const string extensionString = "XR_BD_facial_simulation";

        [Tooltip("When enabled, facial simulation requests the FACE_TRACKING permission during Android manifest setup.")]
        public bool enableFaceTrackingPermission = true;

        [Tooltip("When enabled, facial simulation requests the RECORD_AUDIO permission for audio-assisted modes.")]
        public bool enableRecordAudioPermission = false;

        public static bool isEnable => OpenXRRuntime.IsExtensionEnabled(extensionString);

        public override string GetExtensionString()
        {
            return extensionString;
        }

        public static PxrResult GetFacialSimulationSupported(ref bool supported, ref int supportedModesCount,
            ref XrFacialSimulationModeBD[] supportedModes)
        {
            if (!isEnable)
            {
                supported = false;
                supportedModesCount = 0;
                supportedModes = null;
                return PxrResult.ERROR_EXTENSION_NOT_PRESENT;
            }

            return PXR_FacialSimulation.GetFacialSimulationSupported(ref supported, ref supportedModesCount, ref supportedModes);
        }

        public static PxrResult StartFacialSimulation(XrFacialSimulationModeBD mode)
        {
            if (!isEnable)
            {
                return PxrResult.ERROR_EXTENSION_NOT_PRESENT;
            }

            return PXR_FacialSimulation.StartFacialSimulation(mode);
        }

        public static PxrResult StopFacialSimulation()
        {
            if (!isEnable)
            {
                return PxrResult.ERROR_EXTENSION_NOT_PRESENT;
            }

            return PXR_FacialSimulation.StopFacialSimulation();
        }

        public static PxrResult GetFacialSimulationMode(ref XrFacialSimulationModeBD mode)
        {
            if (!isEnable)
            {
                return PxrResult.ERROR_EXTENSION_NOT_PRESENT;
            }

            return PXR_FacialSimulation.GetFacialSimulationMode(ref mode);
        }

        public static PxrResult SetFacialSimulationMode(XrFacialSimulationModeBD mode)
        {
            if (!isEnable)
            {
                return PxrResult.ERROR_EXTENSION_NOT_PRESENT;
            }

            return PXR_FacialSimulation.SetFacialSimulationMode(mode);
        }

        public static PxrResult GetFacialSimulationData(long timestamp, ref PxrFacialSimulationData data)
        {
            if (!isEnable)
            {
                return PxrResult.ERROR_EXTENSION_NOT_PRESENT;
            }

            return PXR_FacialSimulation.GetFacialSimulationData(timestamp, ref data);
        }
    }
}
#endif
