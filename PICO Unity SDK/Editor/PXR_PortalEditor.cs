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

using System.IO;
using UnityEditor;
using UnityEngine;
using System.Collections.Generic;
using System.Linq;
using System;
using UnityEditor.XR.Management;
using UnityEngine.XR.Management;
using UnityEditor.XR.Management.Metadata;
using UnityEditor.Build;
using System.Collections;
using System.Collections.Generic;
using UnityEditor.PackageManager;
using UnityEditor.PackageManager.Requests;
#if ENABLE_PICO_OPENXR_SDK
using ByteDance.PICO.OpenXR;
#endif

namespace ByteDance.PICO.XR.Editor
{
    [InitializeOnLoad]
    public class PXR_PortalEditor : EditorWindow
    {
        private const string titleName = "PICO Unity SDK";
        private const string windowName = titleName + " Portal";
        private static PXR_PortalEditor instance;
        private static PXR_EditorStyles _styles;
        public event Action<ResponseFirst> WhenRespondedFirst = delegate { };
        public event Action<ResponseSecond> WhenRespondedSecond = delegate { };
        private Vector2 scrollPosition = Vector2.zero;
        private const BuildTarget recommendedBuildTarget = BuildTarget.Android;

        public enum ResponseFirst
        {
            About,
            XR,
            SpatialAdapter,
            OpenXR,
        }

        private Dictionary<ResponseFirst, bool> buttonFirstClickedStates = new Dictionary<ResponseFirst, bool>()
        {
            { ResponseFirst.About, false },
            { ResponseFirst.XR, false },
            { ResponseFirst.SpatialAdapter, false },
            { ResponseFirst.OpenXR, false },
        };


        public enum ResponseSecond
        {
            Configs,
            Tools,
            Samples,
        }

        private Dictionary<ResponseSecond, bool> buttonSecondClickedStates = new Dictionary<ResponseSecond, bool>()
        {
            { ResponseSecond.Configs, false },
            { ResponseSecond.Tools, false },
            { ResponseSecond.Samples, false },
        };
        Action openProjectValidationAction = () =>
        {
            SettingsService.OpenProjectSettings("Project/XR Plug-in Management/Project Validation");

            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Tools_ProjectValidation_Open);
        };

        Action applyBuildTargetAction = () =>
        {
            EditorUserBuildSettings.SwitchActiveBuildTarget(BuildTargetGroup.Android, recommendedBuildTarget);
            EditorUserBuildSettings.selectedBuildTargetGroup = BuildTargetGroup.Android;

            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Configs_RequiredBuildTargetAndroidApplied);
        };

        Action applyMinAndroidAPIAction = () =>
        {
            PlayerSettings.Android.minSdkVersion = PXR_Utils.minSdkVersionInEditor;

            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Configs_RequiredAndroidSdkVersionsApplied);
        };

        Action applyARM64Action = () =>
        {
            PlayerSettings.SetScriptingBackend(NamedBuildTarget.Android, ScriptingImplementation.IL2CPP);
            PlayerSettings.Android.targetArchitectures = AndroidArchitecture.ARM64;
        };

        Action applyPICOXRPluginAction = () =>
        {
            SettingsService.OpenProjectSettings("Project/XR Plug-in Management");
            const string picoLoaderType = "ByteDance.PICO.XR.PXR_Loader";

            var buildTargetSettings = AssetDatabase.FindAssets("t:XRGeneralSettingsPerBuildTarget")
                .Select(guid => AssetDatabase.LoadAssetAtPath<XRGeneralSettingsPerBuildTarget>(AssetDatabase.GUIDToAssetPath(guid)))
                .FirstOrDefault();

            if (buildTargetSettings == null)
            {
                buildTargetSettings = ScriptableObject.CreateInstance<XRGeneralSettingsPerBuildTarget>();
                AssetDatabase.CreateAsset(buildTargetSettings, "Assets/XRGeneralSettingsPerBuildTarget.asset");
                Debug.Log($"PXR_Loader XRGeneralSettingsPerBuildTarget");
                AssetDatabase.SaveAssets();
            }

            var generalSettings = buildTargetSettings.SettingsForBuildTarget(BuildTargetGroup.Android);
            if (generalSettings == null)
            {
                generalSettings = ScriptableObject.CreateInstance<XRGeneralSettings>();
                AssetDatabase.AddObjectToAsset(generalSettings, buildTargetSettings);
                buildTargetSettings.SetSettingsForBuildTarget(BuildTargetGroup.Android, generalSettings);

                var managerSettings = ScriptableObject.CreateInstance<XRManagerSettings>();
                AssetDatabase.AddObjectToAsset(managerSettings, buildTargetSettings);
                generalSettings.Manager = managerSettings;

                EditorUtility.SetDirty(buildTargetSettings);
                AssetDatabase.SaveAssets();
            }

            if (generalSettings.Manager)
            {
                while (generalSettings.Manager.activeLoaders.Count > 0)
                {
                    var loaderName = generalSettings.Manager.activeLoaders[0].GetType().FullName;
                    XRPackageMetadataStore.RemoveLoader(generalSettings.Manager, loaderName, BuildTargetGroup.Android);
                }

                bool success = XRPackageMetadataStore.AssignLoader(generalSettings.Manager, picoLoaderType, BuildTargetGroup.Android);
                if (!success)
                {
                    success = XRPackageMetadataStore.AssignLoader(generalSettings.Manager, nameof(PXR_Loader), BuildTargetGroup.Android);
                }

                EditorUtility.SetDirty(generalSettings.Manager);
                EditorUtility.SetDirty(generalSettings);
                EditorUtility.SetDirty(buildTargetSettings);
                AssetDatabase.SaveAssets();
                AssetDatabase.Refresh();
                SettingsService.NotifySettingsProviderChanged();

                EditorApplication.delayCall += () =>
                {
                    if (!success || !PXR_Utils.IsPXRPluginEnabled())
                    {
                        Debug.LogError("Failed to enable PICO XR loader. Please check Project Settings > XR Plug-in Management (Android).");
                    }
                };
            }

            PXR_Utils.UpdateSDKSymbols();
            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Configs_RequiredPICOXRPluginApplied);
            instance?.Repaint();
        };

        Action applyOpenXRInstallAction = () =>
        {
            if (!PXR_Utils.IsLocalPackageInstalled(PXR_Utils.openXRPackageName))
            {
                PXR_Utils.InstallOrUpdatePackage(PXR_Utils.openXRPackageName, PXR_Utils.openXRPackageVersion182);
            }
        };

        Action applyOpenXRPluginAction = () =>
        {
            SettingsService.OpenProjectSettings("Project/XR Plug-in Management");
            const string openXRLoaderType = "UnityEngine.XR.OpenXR.OpenXRLoader";
            var generalSettings = XRGeneralSettingsPerBuildTarget.XRGeneralSettingsForBuildTarget(BuildTargetGroup.Android);
            if (generalSettings && generalSettings.Manager)
            {
                IReadOnlyList<XRLoader> list = generalSettings.Manager.activeLoaders;
                while (list.Count > 0)
                {
                    string nameTemp = list[0].GetType().FullName;
                    XRPackageMetadataStore.RemoveLoader(generalSettings.Manager, nameTemp, BuildTargetGroup.Android);
                }

                bool success = XRPackageMetadataStore.AssignLoader(
                    generalSettings.Manager, openXRLoaderType, BuildTargetGroup.Android);
                EditorUtility.SetDirty(generalSettings.Manager);
                EditorUtility.SetDirty(generalSettings);
                AssetDatabase.SaveAssets();
                SettingsService.NotifySettingsProviderChanged();

                if (!success)
                {
                    Debug.LogError("Failed to enable OpenXR loader. Please check Project Settings > XR Plug-in Management (Android).");
                }
            }
            PXR_Utils.UpdateSDKSymbols();
            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Configs_RequiredPICOXRPluginApplied);
            instance?.Repaint();
        };

        Action applyOpenXRPICOGroupRequiredAction = () =>
        {
            SettingsService.OpenProjectSettings("Project/XR Plug-in Management");
#if ENABLE_PICO_OPENXR_SDK
            PXR_Utils.EnableOpenXRFeature<PICOFeature>();
            PXR_Utils.EnableOpenXRFeature<OpenXRExtensions>();
            PXR_Utils.EnableOpenXRFeature<ByteDance.PICO.OpenXR.Interactions.PICO4ControllerProfile>();
            PXR_Utils.EnableOpenXRFeature<ByteDance.PICO.OpenXR.Interactions.PICO4UltraControllerProfile>();
            PXR_Utils.EnableOpenXRFeature<ByteDance.PICO.OpenXR.Interactions.PICONeo3ControllerProfile>();
            PXR_Utils.EnableOpenXRFeature<ByteDance.PICO.OpenXR.Interactions.PICOG3ControllerProfile>();
#endif
        };

        Action applyPICOAppModeSpatialAdapterAction = () =>
        {
            var settings = PXR_Settings.GetSettings();
            if (settings == null)
            {
                settings = ScriptableObject.CreateInstance<PXR_Settings>();
                EditorBuildSettings.AddConfigObject("ByteDance.PICO.XR.Settings", settings, true);
            }

            settings.appMode = PXR_Settings.AppMode.Spatial;
            EditorUtility.SetDirty(settings);

            PXR_ProjectSetting.GetProjectConfig().isSpatialAdapter = true;
            PXR_ProjectSetting.SaveAssets();
            AssetDatabase.SaveAssets();
            SettingsService.NotifySettingsProviderChanged();
            PXR_Utils.UpdateSDKSymbols();
            instance?.Repaint();

            EditorApplication.delayCall += () =>
            {
                var finalSettings = PXR_Settings.GetSettings();
                var finalConfig = PXR_ProjectSetting.GetProjectConfig();
                if (finalSettings == null || finalSettings.appMode != PXR_Settings.AppMode.Spatial || !finalConfig.isSpatialAdapter)
                {
                    Debug.LogError("Failed to apply AppMode=Spatial. Please check PICO settings and PXR_ProjectSetting asset.");
                }
            };
        };


        Action applyPICOAppModeXRAction = () =>
        {
            var settings = PXR_Settings.GetSettings();
            if (settings == null)
            {
                settings = ScriptableObject.CreateInstance<PXR_Settings>();
                EditorBuildSettings.AddConfigObject("ByteDance.PICO.XR.Settings", settings, true);
            }

            settings.appMode = PXR_Settings.AppMode.XR;
            EditorUtility.SetDirty(settings);

            PXR_ProjectSetting.GetProjectConfig().isSpatialAdapter = false;
            AssetDatabase.DeleteAsset("Assets/Plugins/Android/AndroidManifest.xml");
            AssetDatabase.DeleteAsset("Assets/Plugins/Android/LauncherManifest.xml");
            PlayerSettings.SplashScreen.show = true;
            PXR_ProjectSetting.SaveAssets();
            AssetDatabase.SaveAssets();
            SettingsService.NotifySettingsProviderChanged();
            PXR_Utils.UpdateSDKSymbols();
            instance?.Repaint();

            EditorApplication.delayCall += () =>
            {
                var finalSettings = PXR_Settings.GetSettings();
                var finalConfig = PXR_ProjectSetting.GetProjectConfig();
                if (finalSettings == null || finalSettings.appMode != PXR_Settings.AppMode.XR || finalConfig.isSpatialAdapter)
                {
                    Debug.LogError("Failed to apply AppMode=XR. Please check PICO settings and PXR_ProjectSetting asset.");
                }
            };
        };


        [MenuItem("PICO/Portal", false, 0)]
        public static void ShowWindow()
        {
            if (instance == null)
            {
                instance = GetWindow<PXR_PortalEditor>();
                instance.Show();
            }
            else
            {
                instance.Focus();
            }
            string version = "_UnityXR_" + PXR_Plugin.System.UPxr_GetSDKVersion() + "_" + Application.unityVersion;
            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Enter + version);
        }

        [InitializeOnLoadMethod]
        private static void InitializeOnLoad()
        {
            if (!PXR_ProjectSetting.GetProjectConfig().portalInited)
            {
                EditorApplication.delayCall += () =>
                {
                    EditorApplication.update += UpdateOnce;
                };

            }
        }

        static void UpdateOnce()
        {
            EditorApplication.update -= UpdateOnce;
            ShowWindow();
            PXR_ProjectSetting.GetProjectConfig().portalInited = true;
            PXR_ProjectSetting.SaveAssets();
            SettingsService.OpenProjectSettings("Project/XR Plug-in Management");
        }

        private void Awake()
        {
            titleContent = new GUIContent(windowName);
            minSize = new Vector2(1080, 840);
            maxSize = minSize + new Vector2(2, 2);
            EditorApplication.delayCall += () => maxSize = new Vector2(4000, 4000);
        }

        private void OnEnable()
        {
            _styles ??= new PXR_EditorStyles();
            _styles.RefreshTheme();
            buttonFirstClickedStates[(ResponseFirst)PXR_ProjectSetting.GetProjectConfig().portalFirstSelected] = true;
            buttonSecondClickedStates[ResponseSecond.Configs] = true;

        }

        private void OnDestroy()
        {
            instance = null;
        }

        private void OnGUI()
        {
            _styles.RefreshTheme();
            if (EditorApplication.isPlayingOrWillChangePlaymode)
            {
                CloseWindow();
            }

            using (new EditorGUILayout.VerticalScope())
            {
                EditorGUILayout.Space(20);
                DrawTitle(titleName);
                EditorGUILayout.Space(10);

                EditorGUILayout.Separator();

                DrawHorizontalLine(_styles.colorLine, 2);
                using (new EditorGUILayout.HorizontalScope())
                {
                    GUILayout.Space(30);
                    DrawLeftButton();
                    DrawVerticalLine(_styles.colorLine, 2);
                    GUILayout.Space(30);

                    Rect windowRect = position;
                    float xOffset = 30 + 200 + 30;
                    float width = windowRect.width - xOffset;
                    float topSpaceUsed = 30 + _styles.HeaderText.fixedHeight + 30;
                    float height = windowRect.height - topSpaceUsed - 30 - 2;

                    _styles.BackgroundColor.fixedWidth = width;
                    _styles.BackgroundColor.fixedHeight = height;
                    using (new GUILayout.VerticalScope(_styles.BackgroundColor))
                    {
                        if (buttonFirstClickedStates[ResponseFirst.About])
                        {
                            scrollPosition = GUILayout.BeginScrollView(scrollPosition, false, true);
                            using (new EditorGUILayout.VerticalScope())
                            {
                                string title = "About the SDK";
                                GUIContent bodyContent = new GUIContent("PICO's official Unity package for developing applications for PICO XR devices.");
                                DrawTwoRowLayout(title, bodyContent);

                                var contentFullSpatial = LoadPortalIconContent(PXR_Utils.PICO_Full_Spatial_NAME, "Full Space");
                                GUIContent textContentFullSpatial = new GUIContent("Full Space");


                                var contentShareSpatial = LoadPortalIconContent(PXR_Utils.PICO_Share_Spatial_NAME, "Shared Space");
                                GUIContent textContentShareSpatial = new GUIContent("Shared Space");

                                GUIStyle centeredStyle = new GUIStyle(EditorStyles.label);
                                centeredStyle.alignment = TextAnchor.UpperCenter;

                                EditorGUILayout.BeginHorizontal(GUILayout.ExpandWidth(false), GUILayout.ExpandHeight(true));
                                {
                                    EditorGUILayout.BeginVertical(GUILayout.ExpandWidth(false), GUILayout.ExpandHeight(false));
                                    {
                                        EditorGUILayout.LabelField(contentShareSpatial, _styles.IconBigStyle,
                                            GUILayout.Width(_styles.IconBigStyle.fixedWidth),
                                            GUILayout.Height(_styles.IconBigStyle.fixedHeight),
                                            GUILayout.ExpandWidth(false), GUILayout.ExpandHeight(false));
                                        GUILayout.Space(5);
                                        EditorGUILayout.LabelField(textContentShareSpatial, centeredStyle, GUILayout.Width(_styles.IconBigStyle.fixedWidth), GUILayout.ExpandHeight(false));

                                        bodyContent = new GUIContent($"<b>Key Features:</b>\n"
+ "<b>·</b> Run multiple applications simultaneously (desktop-like)\n"
+ "<b>·</b> System-managed rendering and interaction events via PICO Spatial Engine\n"
+ "<b>·</b> Supports PICO plugin provider only\n");
                                        GUILayout.Space(5);
                                        EditorGUILayout.LabelField(bodyContent, _styles.ContentText);
                                    }
                                    EditorGUILayout.EndVertical();

                                    GUILayout.Space(20);
                                    EditorGUILayout.BeginVertical(GUILayout.ExpandWidth(false), GUILayout.ExpandHeight(false));
                                    {
                                        EditorGUILayout.LabelField(contentFullSpatial, _styles.IconBigStyle,
                                            GUILayout.Width(_styles.IconBigStyle.fixedWidth),
                                            GUILayout.Height(_styles.IconBigStyle.fixedHeight),
                                            GUILayout.ExpandWidth(false), GUILayout.ExpandHeight(false));
                                        GUILayout.Space(5);
                                        EditorGUILayout.LabelField(textContentFullSpatial, centeredStyle, GUILayout.Width(_styles.IconBigStyle.fixedWidth), GUILayout.ExpandHeight(false));

                                        bodyContent = new GUIContent($"<b>Key Features:</b>\n"
+ "<b>·</b> Exclusive fullscreen environment for immersive experiences\n"
+ "<b>·</b> Rendering via Unity Engine\n"
+ "<b>·</b> Allows permitted direct access to raw input data(e.g.eye tracking, controllers, hand gestures) to enable customized interactions\n"
+ "<b>·</b> Supports PICO or OpenXR plugin provider.");
                                        GUILayout.Space(5);
                                        EditorGUILayout.LabelField(bodyContent, _styles.ContentText);
                                    }
                                    EditorGUILayout.EndVertical();
                                }
                                EditorGUILayout.EndHorizontal();
                                {
                                    GUILayout.FlexibleSpace();
                                }
                                title = "SDK Feature Packs and Highlights";
                                bodyContent = new GUIContent($"<b>PICO Spatial (SpatialAdapter)</b>: for developing applications that run in the Share Space mode, where multiple applications can run simultaneously in mixed reality space. Each app will rely on the PICO Spatial system to render and receive input and interaction events.");

                                DrawTwoRowLayout(title, bodyContent);
                                bodyContent = new GUIContent($"<b>Input and Interaction(Interaction Pack):</b> provides input and interactions for the headset, controllers, hand gestures, motion trackers, eye tracking.");
                                GUILayout.Space(5);
                                EditorGUILayout.LabelField(bodyContent, _styles.ContentText);
                                bodyContent = new GUIContent($"<b>Mixed Reality(Sense Pack):</b> environmental sensing and spatial capabilities, including video see - through, spatial anchor, shared spatial anchor, spatial mesh, scene capture, and more.");
                                GUILayout.Space(5);
                                EditorGUILayout.LabelField(bodyContent, _styles.ContentText);
                                bodyContent = new GUIContent($"<b>SecureMR:</b> our privacy - preserved AI mixed reality scene understanding inference solution based on camera video data.");
                                GUILayout.Space(5);
                                EditorGUILayout.LabelField(bodyContent, _styles.ContentText);
                                bodyContent = new GUIContent($"<b>Spatial Audio:</b> beyond stereo audio, our spatial audio engine renders sound spatially to a greater extent.");
                                GUILayout.Space(5);
                                EditorGUILayout.LabelField(bodyContent, _styles.ContentText);
                                bodyContent = new GUIContent($"<b>Platform Services:</b> in-app purchases, DLC, accounts and friends, ranking, room and match - making etc.");
                                GUILayout.Space(5);
                                EditorGUILayout.LabelField(bodyContent, _styles.ContentText);
                                bodyContent = new GUIContent($"<b>Enterprise Services:</b> features that run on PICO enterprise devices, including devices and system management, screencast, large space use cases.");
                                GUILayout.Space(5);
                                EditorGUILayout.LabelField(bodyContent, _styles.ContentText);
                                bodyContent = new GUIContent($"<b>PICO Building Blocks:</b> utility tool for quickly setting up features and projects with a single click.");
                                GUILayout.Space(5);
                                EditorGUILayout.LabelField(bodyContent, _styles.ContentText);
                                GUILayout.Space(5);

                                title = "Documentation";
                                bodyContent = new GUIContent("Check the documentation on the PICO developer website for the latest features, API references, samples, tools, and release notes. You can also ask the AI bot on the website for development questions.");
                                DrawTwoRowLayout(title, bodyContent);
                                string link = "https://developer.picoxr.com/document/unity";
                                if (GUILayout.Button(link, _styles.SmallBlueLinkStyle, GUILayout.ExpandWidth(false)))
                                {
                                    Application.OpenURL(link);
                                    PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_About_Documentation);
                                }
                                var buttonRectDocumentation = GUILayoutUtility.GetLastRect();
                                if (Event.current.type == EventType.Repaint)
                                {
                                    EditorGUIUtility.AddCursorRect(buttonRectDocumentation, MouseCursor.Link);
                                }

                                title = "Installation";
                                bodyContent = new GUIContent("The SDK can be installed from the Unity Package Manager. Open the Package Manager and click the ' + ' button. We recommend using <b>Add package from git URL...</b> to add the SDK from the <b>PICO Developer GitHub</b>  or get it from Unity Asset Store [link TBD].");
                                DrawTwoRowLayout(title, bodyContent);

                                link = "https://github.com/Pico-Developer/PICO-Unity-Integration-SDK";
                                if (GUILayout.Button(link, _styles.SmallBlueLinkStyle, GUILayout.ExpandWidth(false)))
                                {
                                    Application.OpenURL(link);
                                    PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_About_Installation);
                                }

                                var buttonRectInstallation = GUILayoutUtility.GetLastRect();
                                if (Event.current.type == EventType.Repaint)
                                {
                                    EditorGUIUtility.AddCursorRect(buttonRectInstallation, MouseCursor.Link);
                                }

                                bodyContent = new GUIContent("You can also download the SDK from the PICO developer official website and install it by clicking <b>Add package from disk...</b> and selecting the <b>.package file</b> in the downloaded files.");
                                EditorGUILayout.LabelField(bodyContent, _styles.ContentText);
                            }
                            GUILayout.EndScrollView();
                        }
                        else if (buttonFirstClickedStates[ResponseFirst.XR])
                        {
                            GUILayout.Space(30);
                            DrawTopButton();
                            if (buttonSecondClickedStates[ResponseSecond.Configs])
                            {
                                scrollPosition = GUILayout.BeginScrollView(scrollPosition, false, true);
                                GUILayout.Space(30);
                                using (new EditorGUILayout.VerticalScope())
                                {
                                    string title = "Information";
                                    GUILayout.Label(title, _styles.BigWhiteTitleStyle, GUILayout.ExpandWidth(true));
                                    string bodyContent = $"Supported Unity Version: Unity {PXR_Utils.minUnityVersion} and above.";
                                    EditorGUILayout.LabelField(bodyContent, _styles.ContentText);

                                    GUILayout.Space(30);
                                    title = "Configuration";
                                    GUILayout.Label(title, _styles.BigWhiteTitleStyle, GUILayout.ExpandWidth(true));

                                    string strinfo = $"Required: Build Target = {recommendedBuildTarget}";
                                    bool appliedBuildTarget = EditorUserBuildSettings.activeBuildTarget == recommendedBuildTarget;
                                    EditorConfigurations(strinfo, appliedBuildTarget, applyBuildTargetAction);

                                    strinfo = $"Required: AndroidSdkVersions = {PXR_Utils.minSdkVersionInEditor}";
                                    bool appliedAdroidSdkVersions = PlayerSettings.Android.minSdkVersion == PXR_Utils.minSdkVersionInEditor;
                                    EditorConfigurations(strinfo, appliedAdroidSdkVersions, applyMinAndroidAPIAction);

                                    strinfo = $"Required: ARM64 and IL2CPP scripting must be enabled";
                                    bool appliedARM64 = PlayerSettings.Android.targetArchitectures == AndroidArchitecture.ARM64 &&
                                        PlayerSettings.GetScriptingBackend(BuildTargetGroup.Android) == ScriptingImplementation.IL2CPP;
                                    EditorConfigurations(strinfo, appliedARM64, applyARM64Action);

                                    strinfo = "Required: PICO XR plugin must be enabled";
                                    EditorConfigurations(strinfo, PXR_Utils.IsPXRPluginEnabled(), applyPICOXRPluginAction);

                                    strinfo = "Required: AppMode must be set to XR";
                                    EditorConfigurations(strinfo, PXR_Utils.IsPXRPluginEnabled() && !PXR_ProjectSetting.GetProjectConfig().isSpatialAdapter, applyPICOAppModeXRAction);

                                    bool applied = appliedBuildTarget && appliedAdroidSdkVersions && appliedARM64 && PXR_Utils.IsPXRPluginEnabled() && !PXR_ProjectSetting.GetProjectConfig().isSpatialAdapter;
                                    if (!applied)
                                    {
                                        EditorGUILayout.BeginHorizontal();
                                        {
                                            bodyContent = "For one-click configuration, you can click 'Apply' one by one or use 'Apply All'.";
                                            EditorGUILayout.LabelField(bodyContent, _styles.ContentText, GUILayout.Width(673), GUILayout.ExpandHeight(true));

                                            if (GUILayout.Button("Apply All", GUILayout.ExpandWidth(false), GUILayout.Width(80), GUILayout.Height(30)))
                                            {
                                                applyBuildTargetAction.Invoke();
                                                applyMinAndroidAPIAction.Invoke();
                                                applyARM64Action.Invoke();
                                                applyPICOXRPluginAction.Invoke();
                                                applyPICOAppModeXRAction.Invoke();
                                                PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Configs_ToApplyAllApplied);
                                            }

                                            var buttonRectToApplyAll = GUILayoutUtility.GetLastRect();
                                            if (Event.current.type == EventType.Repaint)
                                            {
                                                EditorGUIUtility.AddCursorRect(buttonRectToApplyAll, MouseCursor.Link);
                                            }
                                            GUILayout.FlexibleSpace();
                                        }
                                        EditorGUILayout.EndHorizontal();
                                    }

                                    GUILayout.Space(20);

                                    using (new EditorGUILayout.HorizontalScope())
                                    {
                                        bodyContent = "For more configuration items, open Project Validation.";
                                        EditorGUILayout.LabelField(bodyContent, _styles.ContentText, GUILayout.Width(673), GUILayout.ExpandHeight(true));
                                        if (GUILayout.Button("Open", GUILayout.Width(80), GUILayout.Height(30)))
                                        {
                                            SettingsService.OpenProjectSettings("Project/XR Plug-in Management/Project Validation");
                                            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Configs_ProjectValidation);
                                        }
                                        var buttonRectProjectValidation = GUILayoutUtility.GetLastRect();
                                        if (Event.current.type == EventType.Repaint)
                                        {
                                            EditorGUIUtility.AddCursorRect(buttonRectProjectValidation, MouseCursor.Link);
                                        }
                                        GUILayout.FlexibleSpace();
                                    }

                                    GUILayout.Space(30);
                                    title = "PICO XR Project Setting";
                                    GUILayout.Label(title, _styles.BigWhiteTitleStyle, GUILayout.ExpandWidth(true));

                                    using (new EditorGUILayout.HorizontalScope())
                                    {
                                        bodyContent = $"SDK Settings for turning on and off features. You can locate it at this filepath: {PXR_Utils.assetPath}PXR_ProjectSetting.asset.";
                                        EditorGUILayout.LabelField(bodyContent, _styles.ContentText, GUILayout.Width(673), GUILayout.ExpandHeight(true));

                                        if (GUILayout.Button("Open", GUILayout.ExpandWidth(false), GUILayout.Width(80), GUILayout.Height(30)))
                                        {
                                            PXR_ProjectSetting asset;
                                            string path = PXR_Utils.assetPath + "PXR_ProjectSetting.asset";
                                            if (!File.Exists(path))
                                            {
                                                asset = new PXR_ProjectSetting();
                                                PXR_Utils.ScriptableObjectUtility.CreateAsset<PXR_ProjectSetting>(asset, PXR_Utils.assetPath);
                                            }

                                            asset = AssetDatabase.LoadAssetAtPath<PXR_ProjectSetting>(path);
                                            if (asset != null)
                                            {
                                                AssetDatabase.OpenAsset(asset);
                                            }
                                            else
                                            {
                                                Debug.LogError("Asset not found at path: " + PXR_Utils.assetPath);
                                            }

                                            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Configs_OpenPICOXRProjectSetting);
                                        }
                                        var buttonRectProjectSetting = GUILayoutUtility.GetLastRect();
                                        if (Event.current.type == EventType.Repaint)
                                        {
                                            EditorGUIUtility.AddCursorRect(buttonRectProjectSetting, MouseCursor.Link);
                                        }
                                        GUILayout.FlexibleSpace();
                                    }
                                }
                                GUILayout.EndScrollView();
                            }
                            else if (buttonSecondClickedStates[ResponseSecond.Tools])
                            {
                                DrawPICOToolsList();
                            }
                            else if (buttonSecondClickedStates[ResponseSecond.Samples])
                            {
                                scrollPosition = GUILayout.BeginScrollView(scrollPosition, false, true);
                                GUILayout.Space(30);
                                using (new EditorGUILayout.VerticalScope())
                                {
                                    string title = "PICO Unity Integration SDK Samples";
                                    GUILayout.Label(title, _styles.BigWhiteTitleStyle, GUILayout.ExpandWidth(true));

                                    GUILayout.Space(30);
                                    string bodyContent = "Besides the Samples you can import through the Unity Package Manager interface, PICO provides comprehensive sample projects that coverthe core features of the Unity Integration SDK on GitHub.";
                                    EditorGUILayout.LabelField(bodyContent, _styles.ContentText);

                                    title = "Mixed Reality Sample";
                                    string gitHubLink = "https://github.com/Pico-Developer/MRSample-Unity";
                                    string documentationLink = "https://developer.picoxr.com/document/unity/mixed-reality-sample/";
                                    DrawSDKSampleLayout(title, documentationLink, gitHubLink);

                                    title = "Interaction Sample";
                                    gitHubLink = "https://github.com/Pico-Developer/InteractionSample-Unity";
                                    documentationLink = "https://developer.picoxr.com/document/unity/y3lpmdhw/";
                                    DrawSDKSampleLayout(title, documentationLink, gitHubLink);

                                    title = "Platform Services Sample";
                                    gitHubLink = "https://github.com/Pico-Developer/PlatformSample-Unity";
                                    documentationLink = "https://developer.picoxr.com/document/unity/simple-demo/";
                                    DrawSDKSampleLayout(title, documentationLink, gitHubLink);

                                    title = "Spatial Audio Sample";
                                    gitHubLink = "https://github.com/Pico-Developer/SpatialAudioSample-Unity";
                                    documentationLink = "https://developer.picoxr.com/document/unity/spatial-audio-sample/";
                                    DrawSDKSampleLayout(title, documentationLink, gitHubLink);

                                    title = "AR Foundation Sample";
                                    gitHubLink = "https://github.com/Pico-Developer/PICOARFoundationSamples-Unity";
                                    documentationLink = "https://developer.picoxr.com/document/unity/ar-foundation-for-pico-unity-integration-sdk/";
                                    DrawSDKSampleLayout(title, documentationLink, gitHubLink);

                                    title = "PICO Avatar Sample";
                                    gitHubLink = "https://github.com/Pico-Developer/PICO-Avatar-SDK-Unity";
                                    DrawSDKSampleLayout(title, null, gitHubLink);

                                    title = "URP Fork";
                                    gitHubLink = "https://github.com/Pico-Developer/PICO-URP-Fork";
                                    DrawSDKSampleLayout(title, null, gitHubLink);
                                }
                                GUILayout.EndScrollView();
                            }

                        }
                        else if (buttonFirstClickedStates[ResponseFirst.SpatialAdapter])
                        {
                            GUILayout.Space(30);
                            DrawTopButton();
                            if (buttonSecondClickedStates[ResponseSecond.Configs])
                            {
                                scrollPosition = GUILayout.BeginScrollView(scrollPosition, false, true);
                                GUILayout.Space(30);
                                using (new EditorGUILayout.VerticalScope())
                                {
                                    string title = "Information";
                                    GUILayout.Label(title, _styles.BigWhiteTitleStyle, GUILayout.ExpandWidth(true));
                                    string bodyContent = $"Supported Unity Version: 2022.3.23f, version above this aren't supported.";
                                    EditorGUILayout.LabelField(bodyContent, _styles.ContentText);

                                    GUILayout.Space(30);
                                    title = "Configuration";
                                    GUILayout.Label(title, _styles.BigWhiteTitleStyle, GUILayout.ExpandWidth(true));

                                    string strinfo = $"Required: Build Target = {recommendedBuildTarget}";
                                    bool appliedBuildTarget = EditorUserBuildSettings.activeBuildTarget == recommendedBuildTarget;
                                    EditorConfigurations(strinfo, appliedBuildTarget, applyBuildTargetAction);

                                    strinfo = $"Required: AndroidSdkVersions = {PXR_Utils.minSdkVersionInEditor}";
                                    bool appliedAdroidSdkVersions = PlayerSettings.Android.minSdkVersion == PXR_Utils.minSdkVersionInEditor;
                                    EditorConfigurations(strinfo, appliedAdroidSdkVersions, applyMinAndroidAPIAction);

                                    strinfo = $"Required: ARM64 and IL2CPP scripting must be enabled";
                                    bool appliedARM64 = PlayerSettings.Android.targetArchitectures == AndroidArchitecture.ARM64 &&
                                        PlayerSettings.GetScriptingBackend(BuildTargetGroup.Android) == ScriptingImplementation.IL2CPP;
                                    EditorConfigurations(strinfo, appliedARM64, applyARM64Action);

                                    strinfo = "Required: PICO XR plugin must be enabled";
                                    EditorConfigurations(strinfo, PXR_Utils.IsPXRPluginEnabled(), applyPICOXRPluginAction);

                                    strinfo = "Required: AppMode must be set to Spatial";
                                    EditorConfigurations(strinfo, PXR_Utils.IsPXRPluginEnabled() && PXR_ProjectSetting.GetProjectConfig().isSpatialAdapter, applyPICOAppModeSpatialAdapterAction);

                                    if (PXR_ProjectSetting.GetProjectConfig().isSpatialAdapter)
                                    {
                                        for (int i = 0; i < PXR_Utils.spatialAdapterPackagesLocalPath.Length; i++)
                                        {
                                            string packageSource = PXR_Utils.spatialAdapterPackagesLocalPath[i];
                                            string packageName = PXR_Utils.spatialAdapterPackagesName[i];
                                            string packageDisplayName = i < PXR_Utils.spatialAdapterPackagesDisplayName.Length
                                                ? PXR_Utils.spatialAdapterPackagesDisplayName[i]
                                                : packageName;
                                            bool enable = PXR_Utils.IsLocalPackageInstalled(packageName);

                                            strinfo = enable ? $"Installed: {packageDisplayName}" : $"Required: install {packageDisplayName}";
                                            string tooltip = $"Source: {packageSource}";
                                            Action loadPackageAction = () =>
                                            {
                                                PXR_Utils.LoadLocalPackage(packageName, packageSource);
                                            };
                                            EditorConfigurations(strinfo, tooltip, enable, loadPackageAction);
                                        }
                                    }

                                    GUILayout.Space(20);

                                    using (new EditorGUILayout.HorizontalScope())
                                    {
                                        bodyContent = "For more configuration items, open Project Validation.";
                                        EditorGUILayout.LabelField(bodyContent, _styles.ContentText, GUILayout.Width(673), GUILayout.ExpandHeight(true));
                                        if (GUILayout.Button("Open", GUILayout.Width(80), GUILayout.Height(30)))
                                        {
                                            SettingsService.OpenProjectSettings("Project/XR Plug-in Management/Project Validation");
                                            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Configs_ProjectValidation);
                                        }
                                        var buttonRectProjectValidation = GUILayoutUtility.GetLastRect();
                                        if (Event.current.type == EventType.Repaint)
                                        {
                                            EditorGUIUtility.AddCursorRect(buttonRectProjectValidation, MouseCursor.Link);
                                        }
                                        GUILayout.FlexibleSpace();
                                    }
                                }
                                GUILayout.EndScrollView();
                            }
                            else if (buttonSecondClickedStates[ResponseSecond.Tools])
                            {
                                DrawPICOToolsList();
                            }
                            else if (buttonSecondClickedStates[ResponseSecond.Samples])
                            {
                            }
                        }
                        else if (buttonFirstClickedStates[ResponseFirst.OpenXR])
                        {
                            GUILayout.Space(30);
                            DrawTopButton();
                            if (buttonSecondClickedStates[ResponseSecond.Configs])
                            {
                                scrollPosition = GUILayout.BeginScrollView(scrollPosition, false, true);
                                GUILayout.Space(30);
                                using (new EditorGUILayout.VerticalScope())
                                {
                                    string title = "Information";
                                    GUILayout.Label(title, _styles.BigWhiteTitleStyle, GUILayout.ExpandWidth(true));
                                    string bodyContent = $"Supported Unity Version: Unity {PXR_Utils.minUnityVersion} and above.";
                                    EditorGUILayout.LabelField(bodyContent, _styles.ContentText);

                                    GUILayout.Space(30);
                                    title = "Configuration";
                                    GUILayout.Label(title, _styles.BigWhiteTitleStyle, GUILayout.ExpandWidth(true));

                                    string strinfo = $"Required: Build Target = {recommendedBuildTarget}";
                                    bool appliedBuildTarget = EditorUserBuildSettings.activeBuildTarget == recommendedBuildTarget;
                                    EditorConfigurations(strinfo, appliedBuildTarget, applyBuildTargetAction);

                                    strinfo = $"Required: AndroidSdkVersions = {PXR_Utils.minSdkVersionInEditor}";
                                    bool appliedAdroidSdkVersions = PlayerSettings.Android.minSdkVersion == PXR_Utils.minSdkVersionInEditor;
                                    EditorConfigurations(strinfo, appliedAdroidSdkVersions, applyMinAndroidAPIAction);

                                    strinfo = $"Required: ARM64 and IL2CPP scripting must be enabled";
                                    bool appliedARM64 = PlayerSettings.Android.targetArchitectures == AndroidArchitecture.ARM64 &&
                                        PlayerSettings.GetScriptingBackend(BuildTargetGroup.Android) == ScriptingImplementation.IL2CPP;
                                    EditorConfigurations(strinfo, appliedARM64, applyARM64Action);

                                    bool enable = PXR_Utils.IsLocalPackageInstalled(PXR_Utils.openXRPackageName);
                                    strinfo = enable ? $"Installed: {PXR_Utils.openXRPackageName}" : $"Required: install {PXR_Utils.openXRPackageName}";
                                    EditorConfigurations(strinfo, PXR_Utils.IsLocalPackageInstalled(PXR_Utils.openXRPackageName), applyOpenXRInstallAction);

#if UNITY_OPENXR
                                    strinfo = "Required: OpenXR plugin must be enabled";
                                    EditorConfigurations(strinfo, PXR_Utils.IsOpenXRPluginEnabled(), applyOpenXRPluginAction);
#endif
                                    if (PXR_Utils.IsOpenXRPluginEnabled())
                                    {
                                        strinfo = "Required: PICO XR feature group must be enabled";
#if ENABLE_PICO_OPENXR_SDK
                                        EditorConfigurations(strinfo, PXR_Utils.IsEnableOpenXRFeature<PICOFeature>(), applyOpenXRPICOGroupRequiredAction);
#endif
                                    }

                                    bool applied = appliedBuildTarget && appliedAdroidSdkVersions && appliedARM64 && PXR_Utils.IsLocalPackageInstalled(PXR_Utils.openXRPackageName)
#if UNITY_OPENXR
                                        && PXR_Utils.IsOpenXRPluginEnabled()
#endif
#if ENABLE_PICO_OPENXR_SDK
                                        && PXR_Utils.IsEnableOpenXRFeature<PICOFeature>()
#endif
                                        ;
                                    if (!applied)
                                    {
                                        EditorGUILayout.BeginHorizontal();
                                        {
                                            bodyContent = "For one-click configuration, you can click 'Apply' one by one or use 'Apply All'.";
                                            EditorGUILayout.LabelField(bodyContent, _styles.ContentText, GUILayout.Width(673), GUILayout.ExpandHeight(true));

                                            if (GUILayout.Button("Apply All", GUILayout.ExpandWidth(false), GUILayout.Width(80), GUILayout.Height(30)))
                                            {
                                                applyBuildTargetAction.Invoke();
                                                applyMinAndroidAPIAction.Invoke();
                                                applyARM64Action.Invoke();
                                                applyOpenXRInstallAction.Invoke();
                                                applyOpenXRPluginAction.Invoke();
                                                applyOpenXRPICOGroupRequiredAction.Invoke();
                                                PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Configs_ToApplyAllApplied);
                                            }

                                            var buttonRectToApplyAll = GUILayoutUtility.GetLastRect();
                                            if (Event.current.type == EventType.Repaint)
                                            {
                                                EditorGUIUtility.AddCursorRect(buttonRectToApplyAll, MouseCursor.Link);
                                            }
                                            GUILayout.FlexibleSpace();
                                        }
                                        EditorGUILayout.EndHorizontal();
                                    }

                                    GUILayout.Space(20);

                                    using (new EditorGUILayout.HorizontalScope())
                                    {
                                        bodyContent = "For more configuration items, open Project Validation.";
                                        EditorGUILayout.LabelField(bodyContent, _styles.ContentText, GUILayout.Width(673), GUILayout.ExpandHeight(true));
                                        if (GUILayout.Button("Open", GUILayout.Width(80), GUILayout.Height(30)))
                                        {
                                            SettingsService.OpenProjectSettings("Project/XR Plug-in Management/Project Validation");
                                            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Configs_ProjectValidation);
                                        }
                                        var buttonRectProjectValidation = GUILayoutUtility.GetLastRect();
                                        if (Event.current.type == EventType.Repaint)
                                        {
                                            EditorGUIUtility.AddCursorRect(buttonRectProjectValidation, MouseCursor.Link);
                                        }
                                        GUILayout.FlexibleSpace();
                                    }

                                    GUILayout.Space(30);
                                    title = "PICO XR Project Setting";
                                    GUILayout.Label(title, _styles.BigWhiteTitleStyle, GUILayout.ExpandWidth(true));

                                    using (new EditorGUILayout.HorizontalScope())
                                    {
                                        bodyContent = $"SDK Settings for turning on and off features. You can locate it at this filepath: {PXR_Utils.assetPath}PXR_ProjectSetting.asset.";
                                        EditorGUILayout.LabelField(bodyContent, _styles.ContentText, GUILayout.Width(673), GUILayout.ExpandHeight(true));

                                        if (GUILayout.Button("Open", GUILayout.ExpandWidth(false), GUILayout.Width(80), GUILayout.Height(30)))
                                        {
                                            PXR_ProjectSetting asset;
                                            string path = PXR_Utils.assetPath + "PXR_ProjectSetting.asset";
                                            if (!File.Exists(path))
                                            {
                                                asset = new PXR_ProjectSetting();
                                                PXR_Utils.ScriptableObjectUtility.CreateAsset<PXR_ProjectSetting>(asset, PXR_Utils.assetPath);
                                            }

                                            asset = AssetDatabase.LoadAssetAtPath<PXR_ProjectSetting>(path);
                                            if (asset != null)
                                            {
                                                AssetDatabase.OpenAsset(asset);
                                            }
                                            else
                                            {
                                                Debug.LogError("Asset not found at path: " + PXR_Utils.assetPath);
                                            }

                                            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Configs_OpenPICOXRProjectSetting);
                                        }
                                        var buttonRectProjectSetting = GUILayoutUtility.GetLastRect();
                                        if (Event.current.type == EventType.Repaint)
                                        {
                                            EditorGUIUtility.AddCursorRect(buttonRectProjectSetting, MouseCursor.Link);
                                        }
                                        GUILayout.FlexibleSpace();
                                    }
                                }
                                GUILayout.EndScrollView();
                            }
                            else if (buttonSecondClickedStates[ResponseSecond.Tools])
                            {
                                DrawPICOToolsList();
                            }
                            else if (buttonSecondClickedStates[ResponseSecond.Samples])
                            { }
                        }
                        GUILayout.FlexibleSpace();
                    }
                }
            }
        }


        private void DrawTitle(string title)
        {
            using (new GUILayout.HorizontalScope())
            {
                EditorGUILayout.LabelField(title, _styles.HeaderText, GUILayout.ExpandWidth(true));

                GUILayout.FlexibleSpace();
                EditorGUILayout.LabelField("Version " + PXR_Plugin.System.UPxr_GetSDKVersion(), _styles.VersionText);

                string iconName = EditorGUIUtility.isProSkin ? PXR_Utils.PICO_ICON_WHITE_NAME : PXR_Utils.PICO_ICON_BLACK_NAME;
                var content = LoadPortalIconContent(iconName, "PICO Logo");
                EditorGUILayout.LabelField(content, _styles.IconStyle,
                    GUILayout.Width(_styles.IconStyle.fixedWidth),
                    GUILayout.Height(_styles.IconStyle.fixedHeight), GUILayout.ExpandWidth(true));
            }
        }

        private static string GetPortalResourcePath(string assetName)
        {
            return PXR_Utils.sdkPackageName + "Resources/" + assetName;
        }

        private static GUIContent LoadPortalIconContent(string assetName, string tooltip)
        {
            Texture2D icon = AssetDatabase.LoadAssetAtPath<Texture2D>(GetPortalResourcePath(assetName));
            return new GUIContent(icon, tooltip);
        }

        public void DrawTwoRowLayout(string title, GUIContent bodyContent, string link = null, System.Action buttonAction = null, string button = null)
        {
            GUILayout.Space(20);
            using (new EditorGUILayout.VerticalScope())
            {
                using (new EditorGUILayout.HorizontalScope())
                {
                    GUILayout.Label(title, _styles.BigWhiteTitleStyle, GUILayout.ExpandWidth(true));
                    if (link != null)
                    {
                        if (GUILayout.Button("Documentation", _styles.SmallBlueLinkStyle, GUILayout.Width(200)))
                        {
                            Application.OpenURL(link);

                            if (title == "Project Validation")
                            {
                                PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Tools_ProjectValidation_Documentation);
                            }
                            else if (title == "PICO Building Blocks")
                            {
                                PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Tools_BuildingBlocks);
                            }
                            else if (title == "PICO XR Toolkit-MR")
                            {
                                PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Tools_PICOXRToolkitMR);
                            }
                            else if (title == "XR Profiling Toolkit")
                            {
                                PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Tools_XRProfilingToolkit);
                            }
                            else if (title == "PICO Developer Center")
                            {
                                PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Tools_PICODeveloperCenter);
                            }
                            else if (title == "Emulator")
                            {
                                PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Tools_Emulator);
                            }
                            else if (title == "More Developer Tools")
                            {
                                PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Tools_MoreDeveloperTools);
                            }
                        }

                        var buttonRect = GUILayoutUtility.GetLastRect();
                        if (Event.current.type == EventType.Repaint)
                        {
                            EditorGUIUtility.AddCursorRect(buttonRect, MouseCursor.Link);
                        }
                    }
                    if (buttonAction != null)
                    {
                        GUILayout.Space(170);
                        string buttonText = button != null ? button : "Open " + title;
                        if (GUILayout.Button("Open", GUILayout.ExpandWidth(false), GUILayout.Width(80), GUILayout.Height(30)))
                        {
                            buttonAction?.Invoke();
                        }

                        var buttonRect = GUILayoutUtility.GetLastRect();
                        if (Event.current.type == EventType.Repaint)
                        {
                            EditorGUIUtility.AddCursorRect(buttonRect, MouseCursor.Link);
                        }
                    }
                    else
                    {
                        GUIStyle Box = new GUIStyle()
                        {
                            fixedWidth = 250,
                        };
                        GUILayout.Box("", Box, GUILayout.ExpandWidth(false));
                    }

                    GUILayout.Space(30);
                }
                EditorGUILayout.Space(10);
                if (bodyContent != null)
                {
                    EditorGUILayout.LabelField(bodyContent, _styles.ContentText);
                }
            }
        }

        private void DrawHorizontalLine(Color color, int thickness)
        {
            Rect rect = EditorGUILayout.GetControlRect(false, thickness);
            EditorGUI.DrawRect(rect, color);
        }

        private void DrawVerticalLine(Color color, int thickness)
        {
            Rect rect = new Rect(240, 122, thickness, Screen.height);
            EditorGUI.DrawRect(rect, color);
        }

        private void DrawLeftButton()
        {
            using (new EditorGUILayout.VerticalScope())
            {
                EditorGUILayout.Space(30);

                var buttons = new[] {
                    ("<size=18>About</size>", ResponseFirst.About),
                    ("<size=18>PICO XR</size>", ResponseFirst.XR),
                    ("<size=18>PICO Spatial</size>", ResponseFirst.SpatialAdapter),
                    ("<size=18>Unity OpenXR</size>", ResponseFirst.OpenXR),
                 };

                foreach (var (btnText, response) in buttons)
                {
                    bool isClicked = GUILayout.Button(btnText, buttonFirstClickedStates[response] ? _styles.ButtonSelected : _styles.Button, GUILayout.ExpandHeight(false));

                    var rect = GUILayoutUtility.GetLastRect();
                    if (Event.current.type == EventType.Repaint)
                    {
                        EditorGUIUtility.AddCursorRect(rect, MouseCursor.Link);
                    }

                    if (isClicked)
                    {
                        ClickedFirstButton(response);
                        buttonSecondClickedStates[ResponseSecond.Configs] = true;
                        buttonSecondClickedStates[ResponseSecond.Tools] = false;
                        buttonSecondClickedStates[ResponseSecond.Samples] = false;
                    }
                    EditorGUILayout.Space(30);
                }
            }

            float windowHeight = position.height;
            float toggleY = windowHeight - EditorGUIUtility.singleLineHeight - 20;
            float toggleX = 20;
            float toggleWidth = position.width - 30;

            float buttonHeight = 30;
            float buttonY = toggleY - buttonHeight - 15;
            Rect buttonRect = new Rect(toggleX, buttonY, 150, buttonHeight);

            if (GUI.Button(buttonRect, "Submit Question"))
            {
                Application.OpenURL("https://picodevsupport.freshdesk.com/");
            }

            if (buttonRect.Contains(Event.current.mousePosition))
            {
                EditorGUIUtility.AddCursorRect(buttonRect, MouseCursor.Link);
            }

            Rect toggleRect = new Rect(toggleX, toggleY, toggleWidth, EditorGUIUtility.singleLineHeight);

            var guiContent = new GUIContent();
            guiContent.text = "Allow usage data collection";
            guiContent.tooltip = "To improve service quality, we will collect non-identifiable behavioral data (such as engine or sdk version, the status of sdk and engine capabilities being enabled, etc.). You can disable this at any time.";
            PXR_ProjectSetting.GetProjectConfig().isDataCollectionDisabled = !EditorGUI.ToggleLeft(toggleRect, guiContent, !PXR_ProjectSetting.GetProjectConfig().isDataCollectionDisabled);

            if (toggleRect.Contains(Event.current.mousePosition))
            {
                EditorGUIUtility.AddCursorRect(toggleRect, MouseCursor.Link);
            }
        }

        private void DrawTopButton()
        {
            using (new EditorGUILayout.HorizontalScope())
            {
                var buttons = new[] {
                    ("<size=18>Configs</size>", ResponseSecond.Configs),
                    ("<size=18>Tools</size>", ResponseSecond.Tools),
                    ("<size=18>Samples</size>", ResponseSecond.Samples),
                 };

                foreach (var (btnText, response) in buttons)
                {
                    bool isClicked = GUILayout.Button(btnText, buttonSecondClickedStates[response] ? _styles.ButtonSelected : _styles.Button, GUILayout.ExpandHeight(false));

                    var rect = GUILayoutUtility.GetLastRect();
                    if (Event.current.type == EventType.Repaint)
                    {
                        EditorGUIUtility.AddCursorRect(rect, MouseCursor.Link);
                    }

                    if (isClicked)
                    {
                        ClickedSecondButton(response);
                    }
                }
            }
        }

        private void ClickedFirstButton(ResponseFirst responseT)
        {
            var keys = buttonFirstClickedStates.Keys.ToArray();
            for (int i = 0; i < keys.Length; i++)
            {
                var response = keys[i];
                buttonFirstClickedStates[response] = responseT == response;
                if(responseT == response)
                {
                    PXR_ProjectSetting.GetProjectConfig().portalFirstSelected = (int)responseT;
                }
            }
            WhenRespondedFirst.Invoke(responseT);
            switch (responseT)
            {
                case ResponseFirst.About:
                    PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_About_Open);
                    break;
                case ResponseFirst.XR:
                    PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Configs_Open);
                    break;
                case ResponseFirst.SpatialAdapter:
                    PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Tools_Open);
                    break;
                case ResponseFirst.OpenXR:
                    PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Sample_Open);
                    break;
                default:
                    break;
            }
        }

        private void ClickedSecondButton(ResponseSecond responseT)
        {
            var keys = buttonSecondClickedStates.Keys.ToArray();
            for (int i = 0; i < keys.Length; i++)
            {
                var response = keys[i];
                buttonSecondClickedStates[response] = responseT == response;
            }
            WhenRespondedSecond.Invoke(responseT);
            switch (responseT)
            {
                case ResponseSecond.Configs:
                    PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Configs_Open);
                    break;
                case ResponseSecond.Tools:
                    PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Tools_Open);
                    break;
                case ResponseSecond.Samples:
                    PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Sample_Open);
                    break;
                default:
                    break;
            }
        }


        private void DrawPICOToolsList()
        {
            GUILayout.Space(20);
            string title = "Unity Editor Tools and Developer Tools";
            EditorGUILayout.LabelField(title, _styles.BigWhiteTitleStyle, GUILayout.ExpandHeight(true));
            EditorGUILayout.LabelField("", GUI.skin.horizontalSlider);

            scrollPosition = GUILayout.BeginScrollView(scrollPosition, false, true);
            using (new EditorGUILayout.VerticalScope())
            {
                title = "Project Validation";
                string links = "https://developer.picoxr.com/document/unity/project-validation/";
                GUIContent bodyContent = new GUIContent("Project Validation can display the validation rules required by the installed XR package. For any validation rules that are not properly set up, you can use this feature to automatically fix them with a single click.");
                DrawTwoRowLayout(title, bodyContent, links, openProjectValidationAction);

                title = "PICO Building Blocks";
                links = "https://developer.picoxr.com/document/unity/pico-building-blocks/";
                bodyContent = new GUIContent("The PICO Building Block system allows you to set up features, including those in the SDK and Unity Engine, with a single click.");
                DrawTwoRowLayout(title, bodyContent, links);

                title = "PICO Developer Center";
                links = "https://developer.picoxr.com/resources/#pdc";
                bodyContent = new GUIContent("PICO Developer Center (referred to as PDC tools below) is a developer service platform that integrates essential tools like the ADB command debugging tool and real-time preview tool. You can efficiently manage, develop, and debug your apps using the PDC tool.");
                DrawTwoRowLayout(title, bodyContent, links);

                title = "RenderDoc for PICO";
                links = "https://developer.picoxr.com/document/unity/renderdoc-for-pico/";
                bodyContent = new GUIContent("For graphic analysis and debugging. See Document for details.");
                DrawTwoRowLayout(title, bodyContent, links);

                title = "PICO Command Line Utility";
                links = "https://developer.picoxr.com/document/unity/command-line-utility/";
                bodyContent = new GUIContent("For managing the files on the PICO Developer Platform more easily. See Document for details.");
                DrawTwoRowLayout(title, bodyContent, links);

                title = "Metrics HUD";
                links = "https://developer.picoxr.com/document/unity/metrics-hud/";
                bodyContent = new GUIContent("Used to monitor the performance metrics of a running app in real time. See Document for details.");
                DrawTwoRowLayout(title, bodyContent, links);

                title = "PICO Haptic Editor";
                links = "https://developer.picoxr.com/document/unity/pico-haptic-editor/";
                bodyContent = new GUIContent("Used to edit broadband and multi-channel haptic feedback. See Document for details.");
                DrawTwoRowLayout(title, bodyContent, links);

                title = "PICO Graphics Probe Tool";
                links = "https://developer.picoxr.com/document/unity/pico-graphics-probe-tool/";
                bodyContent = new GUIContent("Used to analyze and debug your app's performance. See Document for details.");
                DrawTwoRowLayout(title, bodyContent, links);

                title = "Snapdragon Profiler";
                links = "https://developer.picoxr.com/document/unity/242767/";
                bodyContent = new GUIContent("Used to analyze CPU, GPU, DSP, memory usage, power consumption, heat dissipation, and network data, which are useful references for finding and fixing performance bottlenecks. See Document for details.");
                DrawTwoRowLayout(title, bodyContent, links);

                title = "PICO XR Toolkit-MR";
                links = "https://developer.picoxr.com/document/unity/sense-pack-overview/";
                bodyContent = new GUIContent("The PICO XR Toolkit-MR part is a set of tools included in the SensePack on top of the Mixed Reality API. It is used to perform common operations when building spatial perception applications.");
                DrawTwoRowLayout(title, bodyContent, links);

                title = "XR Profiling Toolkit";
                links = "https://github.com/Pico-Developer/XR-Profiling-Toolkit";
                bodyContent = new GUIContent("An automated and customizable graphics profiling tool for evaluating the performance of XR applications on cross-vendor headsets.");
                DrawTwoRowLayout(title, bodyContent, links);


                title = "Emulator";
                links = "https://developer.picoxr.com/resources/#emulator";
                bodyContent = new GUIContent("You can install your app on PICO Emulator and run it, so as to preview how your app performs.");
                DrawTwoRowLayout(title, bodyContent, links);

                title = "More Developer Tools";
                links = "https://developer.picoxr.com/document/unity/developer-tools-overview/";
                bodyContent = new GUIContent("PICO provides a range of developer tools covering app debugging, performance monitoring, haptic editing, and more.See the Developer Tools Documentationpage to learn more details.");
                DrawTwoRowLayout(title, bodyContent, links);
            }
            GUILayout.EndScrollView();
        }

        private void DrawSDKSampleLayout(string title, string documentationLink, string gitHubLink)
        {
            GUILayout.Space(20);
            using (new EditorGUILayout.HorizontalScope())
            {
                _styles.BigWhiteTitleStyle.fontStyle = FontStyle.Bold;
                GUILayout.Label(title, _styles.BigWhiteTitleStyle, GUILayout.ExpandWidth(false));

                if (documentationLink != null)
                {
                    GUILayout.Label(" | ", _styles.BigWhiteTitleStyle, GUILayout.Width(20));
                    if (GUILayout.Button("Documentation", _styles.SmallBlueLinkStyle, GUILayout.ExpandWidth(false)))
                    {
                        Application.OpenURL(documentationLink);

                        if (title == "Mixed Reality Sample")
                        {
                            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Samples_MixedRealitySample_Documentation);
                        }
                        else if (title == "Interaction Sample")
                        {
                            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Samples_InteractionSample_Documentation);
                        }
                        else if (title == "Motion Tracker Sample")
                        {
                            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Samples_MotionTrackerSample_Documentation);
                        }
                        else if (title == "Platform Services Sample")
                        {
                            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Samples_PlatformServicesSample_Documentation);
                        }
                        else if (title == "Spatial Audio Sample")
                        {
                            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Samples_SpatialAudioSample_Documentation);
                        }
                        else if (title == "AR Foundation Sample")
                        {
                            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Samples_ARFoundationSample_Documentation);
                        }
                        else if (title == "Adaptive Resolution Sample")
                        {
                            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Samples_AdaptiveResolutionSample_Documentation);
                        }
                        else if (title == "Toon World")
                        {
                            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Samples_ToonWorldSample_Documentation);
                        }
                        else if (title == "MicroWar")
                        {
                            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Samples_MicroWarSample_Documentation);
                        }
                        else if (title == "PICO Avatar Sample")
                        {
                            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Samples_PICOAvatarSample_Documentation);
                        }
                        else if (title == "URP Fork")
                        {
                            PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Samples_URPFork_Documentation);
                        }
                    }

                    var buttonRectDoc = GUILayoutUtility.GetLastRect();
                    if (Event.current.type == EventType.Repaint)
                    {
                        EditorGUIUtility.AddCursorRect(buttonRectDoc, MouseCursor.Link);
                    }
                }

                GUILayout.Label(" | ", _styles.BigWhiteTitleStyle, GUILayout.Width(20));
                if (GUILayout.Button("GitHub", _styles.SmallBlueLinkStyle, GUILayout.ExpandWidth(false)))
                {
                    Application.OpenURL(gitHubLink);

                    if (title == "Mixed Reality Sample")
                    {
                        PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Samples_MixedRealitySample_GitHub);
                    }
                    else if (title == "Interaction Sample")
                    {
                        PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Samples_InteractionSample_GitHub);
                    }
                    else if (title == "Motion Tracker Sample")
                    {
                        PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Samples_MotionTrackerSample_GitHub);
                    }
                    else if (title == "Platform Services Sample")
                    {
                        PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Samples_PlatformServicesSample_GitHub);
                    }
                    else if (title == "Spatial Audio Sample")
                    {
                        PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Samples_SpatialAudioSample_GitHub);
                    }
                    else if (title == "AR Foundation Sample")
                    {
                        PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Samples_ARFoundationSample_GitHub);
                    }
                    else if (title == "Adaptive Resolution Sample")
                    {
                        PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Samples_AdaptiveResolutionSample_GitHub);
                    }
                    else if (title == "Toon World")
                    {
                        PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Samples_ToonWorldSample_GitHub);
                    }
                    else if (title == "MicroWar")
                    {
                        PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Samples_MicroWarSample_GitHub);
                    }
                    else if (title == "PICO Avatar Sample")
                    {
                        PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Samples_PICOAvatarSample_GitHub);
                    }
                    else if (title == "URP Fork")
                    {
                        PXR_AppLog.PXR_OnEvent(PXR_AppLog.strPortal, PXR_AppLog.strPortal_Samples_URPFork_GitHub);
                    }
                }

                var buttonRectGitHub = GUILayoutUtility.GetLastRect();
                if (Event.current.type == EventType.Repaint)
                {
                    EditorGUIUtility.AddCursorRect(buttonRectGitHub, MouseCursor.Link);
                }
            }
        }

        void EditorConfigurations(string strConfiguration, bool enable, Action buttonAction)
        {
            EditorConfigurations(strConfiguration, null, enable, buttonAction);
        }

        void EditorConfigurations(string strConfiguration, string tooltip, bool enable, Action buttonAction)
        {
            EditorGUILayout.BeginHorizontal();
            var iconStyle = new GUIStyle
            {
                fixedWidth = 30,
                stretchHeight = true,
                alignment = TextAnchor.MiddleCenter,
            };
            if (enable)
            {
                GUI.color = Color.green;
                EditorGUILayout.LabelField(EditorGUIUtility.IconContent("FilterSelectedOnly"), iconStyle, GUILayout.Width(30), GUILayout.ExpandHeight(true));
            }
            else
            {
                GUI.color = Color.yellow;
                EditorGUILayout.LabelField(EditorGUIUtility.IconContent("console.warnicon"), iconStyle, GUILayout.Width(30), GUILayout.ExpandHeight(true));
            }
            GUI.color = Color.white;
            var labelContent = new GUIContent(strConfiguration, string.IsNullOrEmpty(tooltip) ? null : tooltip);
            EditorGUILayout.LabelField(labelContent, _styles.ContentText, GUILayout.Width(640), GUILayout.ExpandHeight(true));

            GUIStyle styleApplied = new GUIStyle();
            styleApplied.fontSize = 14;
            styleApplied.fixedWidth = 80;
            styleApplied.fixedHeight = 30;
            styleApplied.padding = new RectOffset(4, 4, 4, 4);
            styleApplied.alignment = TextAnchor.MiddleCenter;
            if (enable)
            {
                styleApplied.normal.textColor = Color.green;
                GUILayout.Label("Applied", styleApplied);
            }
            else
            {
                if (GUILayout.Button("Apply", GUILayout.ExpandWidth(false), GUILayout.Width(80), GUILayout.Height(30)))
                {
                    buttonAction?.Invoke();
                }

                var buttonRectToApply = GUILayoutUtility.GetLastRect();
                if (Event.current.type == EventType.Repaint)
                {
                    EditorGUIUtility.AddCursorRect(buttonRectToApply, MouseCursor.Link);
                }
            }

            GUILayout.FlexibleSpace();
            EditorGUILayout.EndHorizontal();
        }

        private void CloseWindow()
        {
            Close();
        }
        
        
        
    }
}
