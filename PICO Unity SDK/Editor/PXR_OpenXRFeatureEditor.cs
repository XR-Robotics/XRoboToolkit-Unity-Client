#if ENABLE_PICO_OPENXR_SDK
using ByteDance.PICO.XR;
using UnityEditor;
using UnityEngine;

namespace ByteDance.PICO.OpenXR.Editor
{
    [CustomEditor(typeof(PICOFeature))]
    internal class PXR_OpenXRFeatureEditor : UnityEditor.Editor
    {
        private PXR_OpenXRProjectSetting projectConfig;
        void OnEnable()
        {
             projectConfig = PXR_OpenXRProjectSetting.GetProjectConfig();
        }

        public override void OnInspectorGUI()
        {
          
            // Update anything from the serializable object
            EditorGUIUtility.labelWidth = 215.0f;
            
            //eye tracking
            GUIStyle firstLevelStyle = new GUIStyle(GUI.skin.label);
            firstLevelStyle.alignment = TextAnchor.UpperLeft;
            firstLevelStyle.fontStyle = FontStyle.Bold;
            firstLevelStyle.fontSize = 12;
            firstLevelStyle.wordWrap = true;
            var guiContent = new GUIContent();
            guiContent.text = "Eye Tracking";
            guiContent.tooltip = "Before calling EyeTracking API, enable this option first, only for Neo3 Pro Eye , PICO 4 Pro device.";
            projectConfig.isEyeTracking = EditorGUILayout.Toggle(guiContent, projectConfig.isEyeTracking);
            if (projectConfig.isEyeTracking)
            {
                projectConfig.isEyeTrackingCalibration = EditorGUILayout.Toggle(new GUIContent("Eye Tracking Calibration"), projectConfig.isEyeTrackingCalibration);
                EditorGUILayout.BeginVertical("box");
                EditorGUILayout.LabelField("Note:  Eye Tracking is supported only on Neo 3 Pro Eye , PICO 4 Pro", firstLevelStyle);
                EditorGUILayout.EndVertical();
            }
            projectConfig.isHandTracking = EditorGUILayout.Toggle("Hand Tracking", projectConfig.isHandTracking);
            if (projectConfig.isHandTracking)
            {
                //hand tracking Support
                var handSupport = new GUIContent();
                handSupport.text = "Hand Tracking Support";
                projectConfig.handTrackingSupportType =(HandTrackingSupport)EditorGUILayout.EnumPopup(handSupport, projectConfig.handTrackingSupportType); 
            }
            
            var displayFrequencyContent = new GUIContent();
            displayFrequencyContent.text = "Display Refresh Rates";
            projectConfig.displayFrequency = (SystemDisplayFrequency)EditorGUILayout.EnumPopup(displayFrequencyContent, projectConfig.displayFrequency);
            
            // content protect
            projectConfig.useContentProtect = EditorGUILayout.Toggle("Use Content Protect", projectConfig.useContentProtect);
            if (projectConfig.useContentProtect)
            {
                projectConfig.contentProtectFlags = (SecureContentFlag)EditorGUILayout.EnumPopup("Content Protect", projectConfig.contentProtectFlags);
            }
            
            //FFR
            var foveationEnableContent = new GUIContent();
            foveationEnableContent.text = "Foveated Rendering";
            projectConfig.foveationEnable = EditorGUILayout.Toggle(foveationEnableContent, projectConfig.foveationEnable);
            if (projectConfig.foveationEnable)
            {
                var foveationContent = new GUIContent();
                foveationContent.text = "Foveated Rendering Mode";
                projectConfig.foveatedRenderingMode = (FoveationFeature.FoveatedRenderingMode)EditorGUILayout.EnumPopup(foveationContent, projectConfig.foveatedRenderingMode);
                
                var foveationLevel = new GUIContent();
                foveationLevel.text = "Foveated Rendering Level";
                projectConfig.foveatedRenderingLevel = (FoveationFeature.FoveatedRenderingLevel)EditorGUILayout.EnumPopup(foveationLevel, projectConfig.foveatedRenderingLevel);
                
#if UNITY_OPENXR_1_11_0
                if (projectConfig.foveatedRenderingLevel !=FoveationFeature.FoveatedRenderingLevel.Off)
                {
                    GUILayout.BeginHorizontal();
                    var subsampledEnabledContent = new GUIContent();
                    subsampledEnabledContent.text = "Subsampling";
                    projectConfig.isSubsampledEnabled = EditorGUILayout.Toggle(subsampledEnabledContent, projectConfig.isSubsampledEnabled);
                    GUILayout.EndHorizontal();
                    EditorGUILayout.BeginVertical("box");
                    EditorGUILayout.LabelField("This function has been replaced by the official interface in versions above 1.9.1.", firstLevelStyle);
                    EditorGUILayout.EndVertical();
                }
#else
                projectConfig.isSubsampledEnabled = false;
#endif
            }
            GUILayout.BeginHorizontal();
            guiContent.text = "System Splash Screen";
            EditorGUILayout.LabelField(guiContent, GUILayout.Width(185));
            projectConfig.systemSplashScreen = (Texture2D)EditorGUILayout.ObjectField(projectConfig.systemSplashScreen, typeof(Texture2D), true);
            GUILayout.EndHorizontal();
            
            EditorGUILayout.BeginVertical("box");
            EditorGUILayout.LabelField("Note:  Set the system splash screen picture in PNG format.", firstLevelStyle);
            EditorGUILayout.EndVertical();
            
            var MRSafeguard = new GUIContent();
            MRSafeguard.text = "MR Safeguard";
            MRSafeguard.tooltip = "MR safety, if you choose this option, your application will adopt MR safety policies during runtime. If not selected, it will continue to use VR safety policies by default.";
            projectConfig.MRSafeguard = EditorGUILayout.Toggle(MRSafeguard, projectConfig.MRSafeguard);
            
            serializedObject.Update();
            if (GUI.changed)
            {
                EditorUtility.SetDirty(projectConfig);
            }
            serializedObject.ApplyModifiedProperties();
        }
    }
}
#endif
