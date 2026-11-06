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
#if !ENABLE_PICO_OPENXR_SDK
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;
using System.Linq;
using UnityEngine.SceneManagement;
using UnityEngine.Rendering;
#if AR_FOUNDATION_5 || AR_FOUNDATION_6
using UnityEngine.XR.ARFoundation;
#endif

namespace ByteDance.PICO.XR.Editor
{
    [CustomEditor(typeof(PXR_Settings))]
    public class PXR_SettingsEditor : UnityEditor.Editor
    {
        private const string StereoRenderingModeAndroid = "stereoRenderingModeAndroid";
        private const string AppMode = "appMode";
        private const string SystemDisplayFrequency = "systemDisplayFrequency";
        private const string OptimizeBufferDiscards = "optimizeBufferDiscards";
        private const string SystemSplashScreen = "systemSplashScreen";

        static GUIContent guiStereoRenderingMode = EditorGUIUtility.TrTextContent("Stereo Rendering Mode");
        static GUIContent guiDisplayFrequency = EditorGUIUtility.TrTextContent("Display Refresh Rates");
        private static GUIContent guiOptimizeBuffer = EditorGUIUtility.TrTextContent("Optimize Buffer Discards(Vulkan)");
        static GUIContent guiSystemSplashScreen = EditorGUIUtility.TrTextContent("System Splash Screen");
        static GUIContent guiAppMode = EditorGUIUtility.TrTextContent("App Mode");

        private SerializedProperty appMode;
        private SerializedProperty stereoRenderingModeAndroid;
        private SerializedProperty systemDisplayFrequency;
        private SerializedProperty optimizeBufferDiscards;
        private SerializedProperty appLog;
        private SerializedProperty systemSplashScreen;
        
        
        private static PXR_EditorStyles _styles;
        private static bool hasSpatialAdapterAllInstalled = true;
        private static bool hasSpatialAdapterAllUninstalled = true;

        void OnEnable()
        {
            if (appMode == null)
                appMode = serializedObject.FindProperty(AppMode);
            if (stereoRenderingModeAndroid == null)
                stereoRenderingModeAndroid = serializedObject.FindProperty(StereoRenderingModeAndroid);
            if (systemDisplayFrequency == null)
                systemDisplayFrequency = serializedObject.FindProperty(SystemDisplayFrequency);
            if (optimizeBufferDiscards == null)
                optimizeBufferDiscards = serializedObject.FindProperty(OptimizeBufferDiscards);
            if (systemSplashScreen == null)
                systemSplashScreen = serializedObject.FindProperty(SystemSplashScreen);
            
            
            _styles ??= new PXR_EditorStyles();
        }

        public override void OnInspectorGUI()
        {
            if (serializedObject == null || serializedObject.targetObject == null)
                return;

            serializedObject.Update();
            EditorGUIUtility.labelWidth = 200.0f;
            BuildTargetGroup selectedBuildTargetGroup = EditorGUILayout.BeginBuildTargetSelectionGrouping();
            EditorGUILayout.Space();

            EditorGUILayout.BeginVertical(GUILayout.ExpandWidth(true));
            if (EditorApplication.isPlayingOrWillChangePlaymode)
            {
                EditorGUILayout.HelpBox("PICO settings cannot be changed when the editor is in play mode.", MessageType.Info);
                EditorGUILayout.Space();
            }
            EditorGUI.BeginDisabledGroup(EditorApplication.isPlayingOrWillChangePlaymode);
            if (selectedBuildTargetGroup == BuildTargetGroup.Android)
            {
                PXR_ProjectSetting projectConfig = PXR_ProjectSetting.GetProjectConfig();

                EditorGUILayout.PropertyField(appMode, guiAppMode);
                PXR_Settings.AppMode currentMode = (PXR_Settings.AppMode)appMode.enumValueIndex;
                EditorGUILayout.Space(10);

                if (PXR_Settings.AppMode.XR == currentMode)
                {
                    projectConfig.isSpatialAdapter = false;
                    EditorGUILayout.PropertyField(stereoRenderingModeAndroid, guiStereoRenderingMode);
                    EditorGUILayout.PropertyField(systemDisplayFrequency, guiDisplayFrequency);
                    EditorGUILayout.PropertyField(optimizeBufferDiscards, guiOptimizeBuffer);

                    bool aswDisabled = false;
#if !UNITY_2021_1_OR_NEWER
                    aswDisabled = true;
#endif
                    if (GraphicsDeviceType.OpenGLES3 == PlayerSettings.GetGraphicsAPIs(EditorUserBuildSettings.activeBuildTarget)[0])
                    {
                        GUI.enabled = false;
                        serializedObject.FindProperty("enableAppSpaceWarp").boolValue = false;
                        EditorGUILayout.PropertyField(serializedObject.FindProperty("enableAppSpaceWarp"), new GUIContent("Application SpaceWarp", "Set Graphics API to Vulkan."));
                    }
                    else if (aswDisabled)
                    {
                        GUI.enabled = false;
                        serializedObject.FindProperty("enableAppSpaceWarp").boolValue = false;
                        EditorGUILayout.PropertyField(serializedObject.FindProperty("enableAppSpaceWarp"), new GUIContent("Application SpaceWarp", "Unity Editor: 2021 LTS or later."));
                    }
                    else if (serializedObject.FindProperty("stereoRenderingModeAndroid").intValue == 0)
                    {
                        GUI.enabled = false;
                        serializedObject.FindProperty("enableAppSpaceWarp").boolValue = false;
                        EditorGUILayout.PropertyField(serializedObject.FindProperty("enableAppSpaceWarp"), new GUIContent("Application SpaceWarp", "Set Stereo Rendering Mode to Multiview."));
                    }
                    else
                    {
                        EditorGUILayout.PropertyField(serializedObject.FindProperty("enableAppSpaceWarp"), new GUIContent("Application SpaceWarp"));
                    }
                    GUI.enabled = true;

                    EditorGUILayout.PropertyField(systemSplashScreen, guiSystemSplashScreen);
                }
                else
                {
                    projectConfig.isSpatialAdapter = true;
                    string note = "Note: If the packages don't install correctly, you'll need to manually add the 3 packages in this order:";
                    EditorGUILayout.LabelField(note);
                    GUILayout.Space(2);

                    for (int i = 0; i < PXR_Utils.spatialAdapterPackagesLocalPath.Length; i++)
                    {
                        EditorConfigurations(i);
                    }
                }


#if AR_FOUNDATION_5 || AR_FOUNDATION_6
                GUILayout.Space(2);

                var guiContent = new GUIContent();
                guiContent.text = "AR Foundation";
                projectConfig.arFoundation = EditorGUILayout.Toggle(guiContent, projectConfig.arFoundation);
                if (projectConfig.arFoundation)
                {
                    EditorGUI.indentLevel++;
                    // body tracking
                    guiContent.text = "Body Tracking";
                    projectConfig.bodyTracking = EditorGUILayout.Toggle(guiContent, projectConfig.bodyTracking);

                    // face tracking
                    guiContent.text = "Face Tracking";
                    projectConfig.faceTracking = EditorGUILayout.Toggle(guiContent, projectConfig.faceTracking);

                    // anchor
                    guiContent.text = "Anchor";
                    projectConfig.spatialAnchor = EditorGUILayout.Toggle(guiContent, projectConfig.spatialAnchor);

                    // mesh
                    guiContent.text = "Meshing";
                    projectConfig.spatialMesh = EditorGUILayout.Toggle(guiContent, projectConfig.spatialMesh);
                    
                    guiContent.text = "Plane Detection";
                    projectConfig.planeDetection = EditorGUILayout.Toggle(guiContent, projectConfig.planeDetection);

#if ENABLE_PICO_XR_SDK || ENABLE_PICO_OPENXR_SDK
                    List<ARCameraManager> components = FindComponentsInScene<ARCameraManager>().Where(component => (component.enabled && component.gameObject.CompareTag("MainCamera"))).ToList();
                    bool cameraEffect = false;
                    for (int i = 0; i < components.Count; i++)
                    {
                        ARCameraManager aRCamera = components[i];
                        if (aRCamera.gameObject.GetComponent<PXR_ARCameraEffectManager>())
                        {
                            cameraEffect = true;
                        }
                        Camera camera = aRCamera.gameObject.GetComponent<Camera>();
                        if (camera)
                        {
                            camera.clearFlags = CameraClearFlags.SolidColor;
                            camera.backgroundColor = new Color(0, 0, 0, 0);
                        }
                    }

                    if (!cameraEffect && components.Count > 0)
                    {
                        ARCameraManager aRCamera = components[0];
                        if (!aRCamera.gameObject.GetComponent<PXR_ARCameraEffectManager>())
                        {
                            aRCamera.gameObject.AddComponent<PXR_ARCameraEffectManager>();
                        }
                        cameraEffect = true;
                    }
#endif
                    EditorGUI.indentLevel--;
                }
#endif
                if (GUI.changed)
                {
                    EditorUtility.SetDirty(projectConfig);
                    PXR_ProjectSetting.SaveAssets();
                }
                if (PXR_Utils.UpdateSDKSymbols())
                {
                    if (projectConfig.isSpatialAdapter)
                    {
                        if (!hasSpatialAdapterAllInstalled)
                        {
                            int result = EditorUtility.DisplayDialogComplex(PXR_Utils.appModelCheckInstallMSDialogTitle, PXR_Utils.appModelCheckInstallMSDialogMessage, "OK", "Cancel", "");
                            if (result == 0)
                            {
                                EditorApplication.update += PXR_Utils.CheckAndLoadNextPackage;
                            }
                        }
                    }
                }
            }
            EditorGUI.EndDisabledGroup();
            EditorGUILayout.EndVertical();
            EditorGUILayout.EndBuildTargetSelectionGrouping();

            serializedObject.ApplyModifiedProperties();
            EditorGUIUtility.labelWidth = 0f;
        }

        void EditorConfigurations(int i)
        {
            string packageSource = PXR_Utils.spatialAdapterPackagesLocalPath[i];
            string packageName = PXR_Utils.spatialAdapterPackagesName[i];
            string packageDisplayName = i < PXR_Utils.spatialAdapterPackagesDisplayName.Length
                ? PXR_Utils.spatialAdapterPackagesDisplayName[i]
                : packageName;
            bool enable = PXR_Utils.IsLocalPackageInstalled(packageName);
            string strinfo = enable ?
                $"{i + 1}. Installed: {packageDisplayName}" :
                $"{i + 1}. Required: Please install {packageDisplayName}";
            string tooltip = $"Source: {packageSource}";

            EditorGUILayout.BeginHorizontal();

            var iconStyle = new GUIStyle
            {
                fixedWidth = 20,
                fixedHeight = 20,
                alignment = TextAnchor.MiddleCenter,
            };
            if (enable)
            {
                GUI.color = Color.green;
                GUILayout.Label(EditorGUIUtility.IconContent("FilterSelectedOnly"), iconStyle);
                hasSpatialAdapterAllUninstalled = false;
            }
            else
            {
                GUI.color = Color.yellow;
                GUILayout.Label(EditorGUIUtility.IconContent("console.warnicon"), iconStyle);
                hasSpatialAdapterAllInstalled = false;
            }
            GUI.color = Color.white;
            GUIStyle titleStyle = new GUIStyle()
            {
                fontStyle = FontStyle.Normal,
                fontSize = 12,
                alignment = TextAnchor.MiddleLeft,
                normal = new GUIStyleState() { textColor = Color.white },
                wordWrap = true,
                stretchWidth = true
            };

            GUILayout.Label(new GUIContent(strinfo, tooltip), titleStyle, GUILayout.ExpandWidth(true));

            titleStyle.alignment = TextAnchor.MiddleCenter;
            if (enable)
            {
                titleStyle.normal.textColor = Color.green;
                GUILayout.Label("Installed", titleStyle,
                    GUILayout.Width(70),
                    GUILayout.ExpandWidth(false));
            }
            else
            {
                if (GUILayout.Button(new GUIContent("Install", tooltip),
                    GUILayout.Width(60),
                    GUILayout.Height(20),
                    GUILayout.ExpandWidth(false)))
                {
                    PXR_Utils.LoadLocalPackage(packageName, packageSource);
                }

                var buttonRectToApply = GUILayoutUtility.GetLastRect();
                if (Event.current.type == EventType.Repaint)
                {
                    EditorGUIUtility.AddCursorRect(buttonRectToApply, MouseCursor.Link);
                }
            }

            EditorGUILayout.EndHorizontal();
            GUILayout.Space(2);
        }

        public static List<T> FindComponentsInScene<T>() where T : Component
        {
            var activeScene = SceneManager.GetActiveScene();
            var foundComponents = new List<T>();

            var rootObjects = activeScene.GetRootGameObjects();
            foreach (var rootObject in rootObjects)
            {
                var components = rootObject.GetComponentsInChildren<T>(true);
                foundComponents.AddRange(components);
            }

            return foundComponents;
        }
        
    }
}
#endif