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

using System.Linq;
using UnityEditor;
using UnityEngine;

namespace ByteDance.PICO.XR.Editor
{
    /// <summary>
    /// Ensures the Windows native plugins used by PICO Live Preview are imported with the
    /// exact platform configuration required for Standalone/Editor play mode.
    /// This is invoked once, only when the PICO loader transitions from unchecked to checked
    /// on the Standalone (Desktop) XR Plug-in Management page. It never polls per frame.
    /// </summary>
    public static class PXR_LivePreviewDllConfigurator
    {
        // Target native plugins (relative path fragments under the package's windows/x64 folder).
        private static readonly string[] k_targetDllFragments =
        {
            "windows/x64/PxrPlatform.dll",
            "windows/x64/openxr_loader.dll"
        };

        private const string k_windowsCpu = "x86_64";
        private const string k_windowsOs = "Windows";

        /// <summary>
        /// Forces the target Windows DLLs into the required import configuration:
        /// Any Platform off, Editor on (Windows/x86_64), Standalone Win + Win64 on (x86_64), Android off.
        /// Idempotent: only reimports a plugin whose configuration actually differs from the target.
        /// </summary>
        public static void EnsureWindowsPluginConfig()
        {
            PluginImporter[] plugins = PluginImporter.GetAllImporters();
            foreach (PluginImporter plugin in plugins)
            {
                if (plugin == null || string.IsNullOrEmpty(plugin.assetPath))
                {
                    continue;
                }

                // Normalize separators so the fragment match works regardless of OS path style.
                string normalizedPath = plugin.assetPath.Replace('\\', '/');
                bool isTarget = k_targetDllFragments.Any(fragment => normalizedPath.EndsWith(fragment));
                if (!isTarget)
                {
                    continue;
                }

                if (ApplyRequiredConfig(plugin))
                {
                    plugin.SaveAndReimport();
                    Debug.Log($"[PICO LivePreview] Corrected native plugin import config: {plugin.assetPath}");
                }
            }
        }

        /// <summary>
        /// Applies the required configuration to a single importer.
        /// Returns true if any setting was changed (i.e. a reimport is needed).
        /// </summary>
        private static bool ApplyRequiredConfig(PluginImporter plugin)
        {
            bool changed = false;

            // Any Platform: off.
            if (plugin.GetCompatibleWithAnyPlatform())
            {
                plugin.SetCompatibleWithAnyPlatform(false);
                changed = true;
            }

            // Editor: on, Windows/x86_64.
            if (!plugin.GetCompatibleWithEditor())
            {
                plugin.SetCompatibleWithEditor(true);
                changed = true;
            }
            if (plugin.GetEditorData("CPU") != k_windowsCpu)
            {
                plugin.SetEditorData("CPU", k_windowsCpu);
                changed = true;
            }
            if (plugin.GetEditorData("OS") != k_windowsOs)
            {
                plugin.SetEditorData("OS", k_windowsOs);
                changed = true;
            }

            // Standalone Win64: on, x86_64.
            if (!plugin.GetCompatibleWithPlatform(BuildTarget.StandaloneWindows64))
            {
                plugin.SetCompatibleWithPlatform(BuildTarget.StandaloneWindows64, true);
                changed = true;
            }
            if (plugin.GetPlatformData(BuildTarget.StandaloneWindows64, "CPU") != k_windowsCpu)
            {
                plugin.SetPlatformData(BuildTarget.StandaloneWindows64, "CPU", k_windowsCpu);
                changed = true;
            }

            // Standalone Win (32-bit slot is part of the "Standalone" include in the Inspector).
            if (!plugin.GetCompatibleWithPlatform(BuildTarget.StandaloneWindows))
            {
                plugin.SetCompatibleWithPlatform(BuildTarget.StandaloneWindows, true);
                changed = true;
            }

            // Android: off.
            if (plugin.GetCompatibleWithPlatform(BuildTarget.Android))
            {
                plugin.SetCompatibleWithPlatform(BuildTarget.Android, false);
                changed = true;
            }

            return changed;
        }
    }
}
