using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.XR.Management;
using UnityEngine;
using UnityEngine.XR.Management;
#if UNITY_OPENXR
using UnityEngine.XR.OpenXR;
#endif

namespace ByteDance.PICO.XR.Editor
{

    [XRCustomLoaderUI("ByteDance.PICO.XR.PXR_Loader", BuildTargetGroup.Standalone)]
    [XRCustomLoaderUI("ByteDance.PICO.XR.PXR_Loader", BuildTargetGroup.Android)]
    internal class PXR_XRLoaderUI : IXRCustomLoaderUI
    {
        public static readonly GUIContent k_LoaderName = new GUIContent("PICO");
        protected float renderLineHeight = 0;

        /// <inheritdoc/>
        public float RequiredRenderHeight { get; protected set; }

        public virtual void SetRenderedLineHeight(float height)
        {
            renderLineHeight = height;
            RequiredRenderHeight = height;
        }

        protected Rect CalculateRectForContent(float xMin, float yMin, GUIStyle style, GUIContent content)
        {
            var size = style.CalcSize(content);
            var rect = new Rect();
            rect.xMin = xMin;
            rect.yMin = yMin;
            rect.width = size.x;
            rect.height = renderLineHeight;
            return rect;
        }
        

        public void OnGUI(Rect rect)
        {

            float xMin = rect.xMin;
            float yMin = rect.yMin;

            var labelRect = CalculateRectForContent(xMin, yMin, EditorStyles.toggle, k_LoaderName);
            var newToggled = EditorGUI.ToggleLeft(labelRect, k_LoaderName, IsLoaderEnabled);
            if (newToggled != IsLoaderEnabled)
            {
                // Detect the unchecked -> checked transition on the Standalone (Desktop) page.
                // Only then verify the Windows Live Preview DLL import config, once per transition.
                bool checkedOnStandalone = newToggled && !IsLoaderEnabled
                    && ActiveBuildTargetGroup == BuildTargetGroup.Standalone;

                IsLoaderEnabled = newToggled;

                if (checkedOnStandalone)
                {
                    PXR_LivePreviewDllConfigurator.EnsureWindowsPluginConfig();
                }
            }


            string currentDefines = PlayerSettings.GetScriptingDefineSymbolsForGroup(EditorUserBuildSettings.selectedBuildTargetGroup);
            PXR_Utils.UpdateSDKSymbols();
            // Keep the Standalone PICO_LIVE_PREVIEW define in sync with the PICO loader checkbox.
            PXR_Utils.UpdateLivePreviewSymbol();
        }


        public bool IsLoaderEnabled { get; set; }

        public string[] IncompatibleLoaders => new string[]
        {
            "UnityEngine.XR.OpenXR.OpenXRLoader",
            "UnityEngine.XR.WindowsMR.WindowsMRLoader",
            "Unity.XR.Oculus.OculusLoader",
        };

        public BuildTargetGroup ActiveBuildTargetGroup { get; set; }
    }
}