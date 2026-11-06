using System;
using UnityEngine;
using UnityEngine.Rendering;

namespace ByteDance.PICO.XR
{
    public enum PXR_PerformancePackDeviceProfile
    {
        ProjectSwan = 0,
        PICO4Series = 1,
        OtherDevice = 2,
    }

    [Serializable]
    public sealed class PXR_PerformancePackDeviceConfig
    {
        public float renderScale = 1.0f;
        public string refreshRate = "90Hz";
        public string foveation = "FFR-None";
        public bool superResolution;
        public bool hdr;
        public bool adaptiveResolution;
        public SharpeningMode sharpeningMode = SharpeningMode.None;
        public SharpeningEnhance sharpeningEnhance = SharpeningEnhance.None;
    }

    public sealed class PXR_PerformancePackConfig : ScriptableObject
    {
        public const string ResourceName = "PXR_PerformancePackRuntimeConfig";

        public bool deviceProjectSwan = true;
        public bool devicePico4Series = true;
        public bool deviceOtherDevice;
        public PXR_PerformancePackDeviceProfile editingProfile = PXR_PerformancePackDeviceProfile.ProjectSwan;

        public PXR_PerformancePackDeviceConfig projectSwan = new PXR_PerformancePackDeviceConfig
        {
            renderScale = 1.15f,
            refreshRate = "90Hz",
            foveation = "ETFR-Med",
            superResolution = false,
            hdr = false,
            adaptiveResolution = false,
            sharpeningMode = SharpeningMode.None,
            sharpeningEnhance = SharpeningEnhance.None,
        };

        public PXR_PerformancePackDeviceConfig pico4Series = new PXR_PerformancePackDeviceConfig
        {
            renderScale = 1.0f,
            refreshRate = "72Hz",
            foveation = "FFR-None",
            superResolution = false,
            hdr = false,
            adaptiveResolution = false,
            sharpeningMode = SharpeningMode.None,
            sharpeningEnhance = SharpeningEnhance.None,
        };

        public PXR_PerformancePackDeviceConfig otherDevice = new PXR_PerformancePackDeviceConfig
        {
            renderScale = 1.0f,
            refreshRate = "Default",
            foveation = "FFR-None",
            superResolution = false,
            hdr = false,
            adaptiveResolution = false,
            sharpeningMode = SharpeningMode.None,
            sharpeningEnhance = SharpeningEnhance.None,
        };

        public string presetName = "Default";
        public long updatedAtUnixMs;

        public PXR_PerformancePackDeviceConfig GetDeviceConfig(PXR_PerformancePackDeviceProfile profile)
        {
            EnsureDeviceConfigs();
            switch (profile)
            {
                case PXR_PerformancePackDeviceProfile.PICO4Series:
                    return pico4Series;
                case PXR_PerformancePackDeviceProfile.OtherDevice:
                    return otherDevice;
                case PXR_PerformancePackDeviceProfile.ProjectSwan:
                default:
                    return projectSwan;
            }
        }

        public void EnsureDeviceConfigs()
        {
            if (projectSwan == null) projectSwan = new PXR_PerformancePackDeviceConfig();
            if (pico4Series == null) pico4Series = new PXR_PerformancePackDeviceConfig();
            if (otherDevice == null) otherDevice = new PXR_PerformancePackDeviceConfig();
        }
    }
}
