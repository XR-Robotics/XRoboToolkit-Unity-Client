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
using UnityEngine.XR;

namespace ByteDance.PICO.XR
{
    internal static class PXR_SrpFoveationRendering
    {
#if UNITY_6000_0_OR_NEWER
        private static readonly List<XRDisplaySubsystem> DisplaySubsystems = new List<XRDisplaySubsystem>();
#endif

        internal static bool TryApplyProjectSettings()
        {
#if UNITY_6000_0_OR_NEWER
            PXR_ProjectSetting projectConfig = PXR_ProjectSetting.GetProjectConfig();
            if (projectConfig == null)
            {
                return false;
            }

            return TrySetFoveationLevel(projectConfig.foveationLevel, projectConfig.enableETFR);
#else
            return false;
#endif
        }

        internal static bool TrySetFoveationLevel(FoveationLevel level, bool isETFR)
        {
#if UNITY_6000_0_OR_NEWER
            XRDisplaySubsystem displaySubsystem;
            if (!TryGetRunningDisplaySubsystem(out displaySubsystem))
            {
                return false;
            }

            displaySubsystem.foveatedRenderingFlags = isETFR && level != FoveationLevel.None
                ? XRDisplaySubsystem.FoveatedRenderingFlags.GazeAllowed
                : XRDisplaySubsystem.FoveatedRenderingFlags.None;
            displaySubsystem.foveatedRenderingLevel = ToSrpFoveationLevel(level);
            return true;
#else
            return false;
#endif
        }

        internal static bool TryGetFoveationLevel(out FoveationLevel level)
        {
#if UNITY_6000_0_OR_NEWER
            XRDisplaySubsystem displaySubsystem;
            if (TryGetRunningDisplaySubsystem(out displaySubsystem))
            {
                level = FromSrpFoveationLevel(displaySubsystem.foveatedRenderingLevel);
                return true;
            }
#endif
            level = FoveationLevel.None;
            return false;
        }

#if UNITY_6000_0_OR_NEWER
        private static bool TryGetRunningDisplaySubsystem(out XRDisplaySubsystem displaySubsystem)
        {
            DisplaySubsystems.Clear();
            SubsystemManager.GetSubsystems(DisplaySubsystems);
            for (int i = 0; i < DisplaySubsystems.Count; i++)
            {
                XRDisplaySubsystem candidate = DisplaySubsystems[i];
                if (candidate != null && candidate.running)
                {
                    displaySubsystem = candidate;
                    return true;
                }
            }

            displaySubsystem = null;
            return false;
        }

        private static float ToSrpFoveationLevel(FoveationLevel level)
        {
            switch (level)
            {
                case FoveationLevel.Low:
                    return 0.25f;
                case FoveationLevel.Med:
                    return 0.5f;
                case FoveationLevel.High:
                    return 0.75f;
                case FoveationLevel.TopHigh:
                    return 1.0f;
                case FoveationLevel.None:
                default:
                    return 0.0f;
            }
        }

        private static FoveationLevel FromSrpFoveationLevel(float level)
        {
            if (level <= 0.0f)
            {
                return FoveationLevel.None;
            }

            if (level <= 0.25f)
            {
                return FoveationLevel.Low;
            }

            if (level <= 0.5f)
            {
                return FoveationLevel.Med;
            }

            if (level <= 0.75f)
            {
                return FoveationLevel.High;
            }

            return FoveationLevel.TopHigh;
        }
#endif
    }
}
#endif
