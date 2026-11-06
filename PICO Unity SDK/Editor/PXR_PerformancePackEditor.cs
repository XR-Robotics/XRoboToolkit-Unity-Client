#if UNITY_EDITOR
using System;
using System.Collections.Generic;
using System.IO;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEditor.UIElements;
using UnityEngine;
using UnityEngine.Rendering;
using UnityEngine.SceneManagement;
using UnityEngine.UIElements;
using UnityEngine.XR;
#if URP
using UnityEngine.Rendering.Universal;
#endif
using ByteDance.PICO.XR;
#if ENABLE_PICO_OPENXR_SDK
using ByteDance.PICO.OpenXR;
#endif

namespace ByteDance.PICO.XR.Editor
{
    static class PXR_PerformancePackSettingsProvider
    {
        private const string EditorPrefsKey = "ByteDance.PICO.PerformancePack.Config";
        private const string PerformancePackAssetPath = "Assets/Resources/PXR_PerformancePackRuntimeConfig.asset";
        private const string LegacyPerformancePackAssetPath = "Assets/Resources/PXR_PerformancePackConfig.asset";
        private const float NarrowWidthThreshold = 840f;

        private static readonly Color TokenPrimary = new Color(0.00f, 0.40f, 1.00f);
        private static readonly Color TokenSuccess = new Color(0.32f, 0.77f, 0.10f);
        private static readonly Color TokenWarning = new Color(0.98f, 0.68f, 0.08f);
        private static readonly Color TokenError = new Color(1.00f, 0.31f, 0.31f);
        private static readonly Color TokenInfo = new Color(0.09f, 0.59f, 1.00f);

        private enum Tab
        {
            Basic = 0,
            Advanced = 1,
            Device = 2,
            Preview = 3,
            Help = 4,
        }

        private enum DeviceProfile
        {
            ProjectSwan = 0,
            PICO4Series = 1,
            OtherDevice = 2,
        }

        private enum StatusLevel
        {
            Recommended = 0,
            PerformanceWarning = 1,
            Unsupported = 2,
            Custom = 3,
        }

        [Serializable]
        private class DeviceTemplate
        {
            public string displayName;
            public float recommendedRenderScale;

            public List<string> refreshRates;
            public string recommendedRefreshRate;

            public List<string> foveations;
            public string recommendedFoveation;

            public bool superResolutionSupported;
            public bool superResolutionRecommended;
            public bool hdrSupported;
            public bool hdrRecommended;
            public bool adaptiveResolutionSupported;
            public bool adaptiveResolutionRecommended;
        }

        private const string FoveationFixedPrefix = "FFR-";
        private const string FoveationEyePrefix = "ETFR-";
        private static readonly List<string> FixedFoveationOptions = BuildFixedFoveationOptions();
        private static readonly List<string> FoveationOptions = BuildFoveationOptions();

        private static readonly Dictionary<DeviceProfile, DeviceTemplate> Templates = new Dictionary<DeviceProfile, DeviceTemplate>
        {
            {
                DeviceProfile.ProjectSwan,
                new DeviceTemplate
                {
                    displayName = "PICO Space Pro",
                    recommendedRenderScale = 1.15f,
                    refreshRates = new List<string> { "Default", "72Hz", "90Hz" },
                    recommendedRefreshRate = "90Hz",
                    foveations = new List<string>(FoveationOptions),
                    recommendedFoveation = BuildFoveationOption(FoveatedRenderingMode.EyeTrackedFoveatedRendering, FoveationLevel.Med),
                    superResolutionSupported = true,
                    superResolutionRecommended = false,
                    hdrSupported = true,
                    hdrRecommended = false,
                    adaptiveResolutionSupported = true,
                    adaptiveResolutionRecommended = false,
                }
            },
            {
                DeviceProfile.PICO4Series,
                new DeviceTemplate
                {
                    displayName = "PICO 4 Ultra",
                    recommendedRenderScale = 1.0f,
                    refreshRates = new List<string> { "Default", "72Hz", "90Hz" },
                    recommendedRefreshRate = "72Hz",
                    foveations = new List<string>(FixedFoveationOptions),
                    recommendedFoveation = BuildFoveationOption(FoveatedRenderingMode.FixedFoveatedRendering, FoveationLevel.None),
                    superResolutionSupported = true,
                    superResolutionRecommended = false,
                    hdrSupported = true,
                    hdrRecommended = false,
                    adaptiveResolutionSupported = true,
                    adaptiveResolutionRecommended = false,
                }
            },
            {
                DeviceProfile.OtherDevice,
                new DeviceTemplate
                {
                    displayName = "Other Device",
                    recommendedRenderScale = 1.0f,
                    refreshRates = new List<string> { "Default", "72Hz", "90Hz" },
                    recommendedRefreshRate = "Default",
                    foveations = new List<string>(FixedFoveationOptions),
                    recommendedFoveation = BuildFoveationOption(FoveatedRenderingMode.FixedFoveatedRendering, FoveationLevel.None),
                    superResolutionSupported = true,
                    superResolutionRecommended = false,
                    hdrSupported = true,
                    hdrRecommended = false,
                    adaptiveResolutionSupported = true,
                    adaptiveResolutionRecommended = false,
                }
            },
        };

        private static Tab _activeTab = Tab.Basic;
        private static Vector2 _scrollPosBasic;
        private static Vector2 _scrollPosAdvanced;
        private static Vector2 _scrollPosDevice;
        private static Vector2 _scrollPosPreview;
        private static Vector2 _scrollPosHelp;

        private static PXR_PerformancePackConfig _config;
        private static bool _isDirty;
        private static bool _isNarrowLayout;
        private static Action _requestRebuild;
        private static Action _requestStatusRefresh;

        private static PXR_PerformancePackDeviceConfig ActiveDeviceConfig
        {
            get
            {
                return _config.GetDeviceConfig(_config.editingProfile);
            }
        }

        private static PXR_PerformancePackDeviceConfig GetDeviceConfig(DeviceProfile profile)
        {
            return _config.GetDeviceConfig(ToRuntimeProfile(profile));
        }

        [MenuItem("PICO/Performance Pack", false, 1)] // Temporarily hidden
        private static void OpenWindow()
        {
            var window = EditorWindow.GetWindow<PerformancePackWindow>();
            window.titleContent = new GUIContent("Performance Pack");
            window.minSize = new Vector2(920, 620);
            window.Show();
        }

        private sealed class PerformancePackWindow : EditorWindow
        {
            private void OnEnable()
            {
                EnsureLoaded();
                _requestRebuild = () =>
                {
                    EnsureLoaded();
                    rootVisualElement.Clear();
                    BuildUI(rootVisualElement);
                };
                _requestRebuild.Invoke();
            }

            private void OnDisable()
            {
                if (_isDirty)
                {
                    SaveToProjectAsset();
                }

                if (_requestRebuild != null)
                {
                    _requestRebuild = null;
                }

                if (_requestStatusRefresh != null)
                {
                    _requestStatusRefresh = null;
                }
            }
        }

        private static void RequestRebuild()
        {
            _requestRebuild?.Invoke();
        }

        private static void RequestStatusRefresh()
        {
            _requestStatusRefresh?.Invoke();
        }

        private static void EnsureLoaded()
        {
            if (_config != null) return;
            bool createdAsset = false;
            RemoveLegacyEditorOnlyConfigAsset();
            _config = LoadFromProjectAsset();
            if (_config == null)
            {
                _config = LoadFromEditorPrefs() ?? CreateDefaultConfig();
                createdAsset = true;
            }
            MigrateLegacyChineseValues(_config);
            if (createdAsset)
            {
                SaveToProjectAsset();
            }
            _isDirty = false;
            NormalizeConfigForSelection(autoConfigure: false);
        }

        private static void RemoveLegacyEditorOnlyConfigAsset()
        {
            if (AssetDatabase.LoadAssetAtPath<UnityEngine.Object>(LegacyPerformancePackAssetPath) == null) return;
            AssetDatabase.DeleteAsset(LegacyPerformancePackAssetPath);
        }

        private static void MigrateLegacyChineseValues(PXR_PerformancePackConfig config)
        {
            if (config == null) return;
            config.EnsureDeviceConfigs();

            MigrateLegacyFoveationValue(config.projectSwan);
            MigrateLegacyFoveationValue(config.pico4Series);
            MigrateLegacyFoveationValue(config.otherDevice);
        }

        private static void MigrateLegacyFoveationValue(PXR_PerformancePackDeviceConfig config)
        {
            if (config == null) return;

            if (string.Equals(config.foveation, "\u5173\u95ed", StringComparison.Ordinal))
            {
                config.foveation = BuildFoveationOption(FoveatedRenderingMode.FixedFoveatedRendering, FoveationLevel.None);
            }
            if (string.Equals(config.foveation, "Off", StringComparison.Ordinal))
            {
                config.foveation = BuildFoveationOption(FoveatedRenderingMode.FixedFoveatedRendering, FoveationLevel.None);
            }
            if (string.Equals(config.foveation, "ETFR+MID", StringComparison.Ordinal))
            {
                config.foveation = BuildFoveationOption(FoveatedRenderingMode.EyeTrackedFoveatedRendering, FoveationLevel.Med);
            }
            if (string.Equals(config.foveation, "FixedFR-Med", StringComparison.Ordinal))
            {
                config.foveation = BuildFoveationOption(FoveatedRenderingMode.FixedFoveatedRendering, FoveationLevel.Med);
            }
            if (string.Equals(config.foveation, "EyeFR-Med", StringComparison.Ordinal))
            {
                config.foveation = BuildFoveationOption(FoveatedRenderingMode.EyeTrackedFoveatedRendering, FoveationLevel.Med);
            }
        }

        private static List<string> BuildFoveationOptions()
        {
            var options = BuildFixedFoveationOptions();
            options.Add(BuildFoveationOption(FoveatedRenderingMode.EyeTrackedFoveatedRendering, FoveationLevel.None));
            options.Add(BuildFoveationOption(FoveatedRenderingMode.EyeTrackedFoveatedRendering, FoveationLevel.Low));
            options.Add(BuildFoveationOption(FoveatedRenderingMode.EyeTrackedFoveatedRendering, FoveationLevel.Med));
            options.Add(BuildFoveationOption(FoveatedRenderingMode.EyeTrackedFoveatedRendering, FoveationLevel.High));
            options.Add(BuildFoveationOption(FoveatedRenderingMode.EyeTrackedFoveatedRendering, FoveationLevel.TopHigh));
            return options;
        }

        private static List<string> BuildFixedFoveationOptions()
        {
            var options = new List<string>();
            options.Add(BuildFoveationOption(FoveatedRenderingMode.FixedFoveatedRendering, FoveationLevel.None));
            options.Add(BuildFoveationOption(FoveatedRenderingMode.FixedFoveatedRendering, FoveationLevel.Low));
            options.Add(BuildFoveationOption(FoveatedRenderingMode.FixedFoveatedRendering, FoveationLevel.Med));
            options.Add(BuildFoveationOption(FoveatedRenderingMode.FixedFoveatedRendering, FoveationLevel.High));
            options.Add(BuildFoveationOption(FoveatedRenderingMode.FixedFoveatedRendering, FoveationLevel.TopHigh));
            return options;
        }

        private static string BuildFoveationOption(FoveatedRenderingMode mode, FoveationLevel level)
        {
            return (mode == FoveatedRenderingMode.EyeTrackedFoveatedRendering ? FoveationEyePrefix : FoveationFixedPrefix) + GetFoveationLevelLabel(level);
        }

        private static string GetFoveationModeLabel(FoveatedRenderingMode mode)
        {
            return mode == FoveatedRenderingMode.EyeTrackedFoveatedRendering ? "ETFR" : "FFR";
        }

        private static string GetFoveationLevelLabel(FoveationLevel level)
        {
            switch (level)
            {
                case FoveationLevel.None:
                    return "None";
                case FoveationLevel.Low:
                    return "Low";
                case FoveationLevel.Med:
                    return "Med";
                case FoveationLevel.High:
                    return "High";
                case FoveationLevel.TopHigh:
                    return "TopHigh";
                default:
                    return "None";
            }
        }

        private static bool TryParseFoveationModeLabel(string value, out FoveatedRenderingMode mode)
        {
            mode = FoveatedRenderingMode.FixedFoveatedRendering;
            if (string.Equals(value, "FFR", StringComparison.Ordinal)) return true;
            if (string.Equals(value, "ETFR", StringComparison.Ordinal))
            {
                mode = FoveatedRenderingMode.EyeTrackedFoveatedRendering;
                return true;
            }
            return false;
        }

        private static bool TryParseFoveation(string value, out FoveatedRenderingMode mode, out FoveationLevel level)
        {
            mode = FoveatedRenderingMode.FixedFoveatedRendering;
            level = FoveationLevel.None;
            if (string.IsNullOrEmpty(value)) return false;
            if (string.Equals(value, "Off", StringComparison.Ordinal))
            {
                return true;
            }
            if (string.Equals(value, "ETFR+MID", StringComparison.Ordinal))
            {
                mode = FoveatedRenderingMode.EyeTrackedFoveatedRendering;
                level = FoveationLevel.Med;
                return true;
            }
            if (value.StartsWith(FoveationFixedPrefix, StringComparison.Ordinal))
            {
                mode = FoveatedRenderingMode.FixedFoveatedRendering;
                return TryParseFoveationLevel(value.Substring(FoveationFixedPrefix.Length), out level);
            }
            if (value.StartsWith(FoveationEyePrefix, StringComparison.Ordinal))
            {
                mode = FoveatedRenderingMode.EyeTrackedFoveatedRendering;
                return TryParseFoveationLevel(value.Substring(FoveationEyePrefix.Length), out level);
            }
            return false;
        }

        private static bool TryParseFoveationLevel(string value, out FoveationLevel level)
        {
            level = FoveationLevel.None;
            if (string.IsNullOrEmpty(value)) return false;
            if (string.Equals(value, "None", StringComparison.Ordinal)) { level = FoveationLevel.None; return true; }
            if (string.Equals(value, "Low", StringComparison.Ordinal)) { level = FoveationLevel.Low; return true; }
            if (string.Equals(value, "Med", StringComparison.Ordinal)) { level = FoveationLevel.Med; return true; }
            if (string.Equals(value, "High", StringComparison.Ordinal)) { level = FoveationLevel.High; return true; }
            if (string.Equals(value, "TopHigh", StringComparison.Ordinal)) { level = FoveationLevel.TopHigh; return true; }
            return false;
        }

        private static FoveatedRenderingMode GetFoveationModeFromOption(string value)
        {
            if (TryParseFoveation(value, out FoveatedRenderingMode mode, out FoveationLevel _)) return mode;
            return FoveatedRenderingMode.FixedFoveatedRendering;
        }

        private static FoveationLevel GetFoveationLevelFromOption(string value)
        {
            if (TryParseFoveation(value, out FoveatedRenderingMode _, out FoveationLevel level)) return level;
            return FoveationLevel.None;
        }

        private static List<string> GetFoveationModeOptions(DeviceTemplate template)
        {
            var set = new HashSet<string>(StringComparer.Ordinal);
            for (int i = 0; i < template.foveations.Count; i++)
            {
                string option = template.foveations[i];
                if (TryParseFoveation(option, out FoveatedRenderingMode mode, out FoveationLevel _))
                {
                    set.Add(GetFoveationModeLabel(mode));
                }
            }
            return new List<string>(set);
        }

        private static List<string> GetFoveationLevelOptions(DeviceTemplate template)
        {
            var set = new HashSet<string>(StringComparer.Ordinal);
            for (int i = 0; i < template.foveations.Count; i++)
            {
                string option = template.foveations[i];
                if (TryParseFoveation(option, out FoveatedRenderingMode _, out FoveationLevel level))
                {
                    set.Add(GetFoveationLevelLabel(level));
                }
            }
            return new List<string>(set);
        }

        private static PXR_PerformancePackConfig CreateDefaultConfig()
        {
            var cfg = ScriptableObject.CreateInstance<PXR_PerformancePackConfig>();
            cfg.updatedAtUnixMs = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds();
            return cfg;
        }

        private static PXR_PerformancePackConfig LoadFromProjectAsset()
        {
            var asset = AssetDatabase.LoadAssetAtPath<PXR_PerformancePackConfig>(PerformancePackAssetPath);
            if (asset != null)
            {
                asset.EnsureDeviceConfigs();
                asset = RepairRuntimeAssetScriptReferenceIfNeeded(asset);
                asset.EnsureDeviceConfigs();
            }
            return asset;
        }

        private static PXR_PerformancePackConfig RepairRuntimeAssetScriptReferenceIfNeeded(PXR_PerformancePackConfig asset)
        {
            if (asset == null) return null;
            if (HasRuntimeAssetScriptReference(asset)) return asset;

            var repaired = ScriptableObject.CreateInstance<PXR_PerformancePackConfig>();
            CopyConfig(asset, repaired);

            if (!AssetDatabase.DeleteAsset(PerformancePackAssetPath))
            {
                return asset;
            }

            AssetDatabase.CreateAsset(repaired, PerformancePackAssetPath);
            AssetDatabase.SaveAssets();
            return repaired;
        }

        private static bool HasRuntimeAssetScriptReference(PXR_PerformancePackConfig asset)
        {
            var serializedObject = new SerializedObject(asset);
            var scriptProperty = serializedObject.FindProperty("m_Script");
            return scriptProperty != null && scriptProperty.objectReferenceValue != null;
        }

        private static void CopyConfig(PXR_PerformancePackConfig source, PXR_PerformancePackConfig target)
        {
            if (source == null || target == null) return;

            source.EnsureDeviceConfigs();
            target.deviceProjectSwan = source.deviceProjectSwan;
            target.devicePico4Series = source.devicePico4Series;
            target.deviceOtherDevice = source.deviceOtherDevice;
            target.editingProfile = source.editingProfile;
            target.projectSwan = CopyDeviceConfig(source.projectSwan);
            target.pico4Series = CopyDeviceConfig(source.pico4Series);
            target.otherDevice = CopyDeviceConfig(source.otherDevice);
            target.presetName = source.presetName;
            target.updatedAtUnixMs = source.updatedAtUnixMs;
        }

        private static PXR_PerformancePackDeviceConfig CopyDeviceConfig(PXR_PerformancePackDeviceConfig source)
        {
            if (source == null) return new PXR_PerformancePackDeviceConfig();

            return new PXR_PerformancePackDeviceConfig
            {
                renderScale = source.renderScale,
                refreshRate = source.refreshRate,
                foveation = source.foveation,
                superResolution = source.superResolution,
                hdr = source.hdr,
                adaptiveResolution = source.adaptiveResolution,
                sharpeningMode = source.sharpeningMode,
                sharpeningEnhance = source.sharpeningEnhance,
            };
        }

        private static PXR_PerformancePackConfig LoadFromEditorPrefs()
        {
            return null;
        }

        private static void SaveToProjectAsset()
        {
            _config.updatedAtUnixMs = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds();
            var asset = AssetDatabase.LoadAssetAtPath<PXR_PerformancePackConfig>(PerformancePackAssetPath);
            if (asset == null)
            {
                string resourcesPath = Path.Combine(Application.dataPath, "Resources");
                if (!Directory.Exists(resourcesPath))
                {
                    AssetDatabase.CreateFolder("Assets", "Resources");
                }
                AssetDatabase.CreateAsset(_config, PerformancePackAssetPath);
            }
            else
            {
                EditorUtility.SetDirty(asset);
            }
            AssetDatabase.SaveAssets();
            _isDirty = false;
        }

        private static void MarkDirty()
        {
            _isDirty = true;
            RequestStatusRefresh();
        }

        private static IEnumerable<DeviceProfile> GetSelectedProfiles()
        {
            if (_config.deviceProjectSwan) yield return DeviceProfile.ProjectSwan;
            if (_config.devicePico4Series) yield return DeviceProfile.PICO4Series;
            if (_config.deviceOtherDevice) yield return DeviceProfile.OtherDevice;
        }

        private static DeviceProfile GetPrimaryProfile()
        {
            if (_config.deviceProjectSwan) return DeviceProfile.ProjectSwan;
            if (_config.devicePico4Series) return DeviceProfile.PICO4Series;
            if (_config.deviceOtherDevice) return DeviceProfile.OtherDevice;
            return DeviceProfile.ProjectSwan;
        }

        private static DeviceProfile GetEditingProfile()
        {
            return (DeviceProfile)(int)_config.editingProfile;
        }

        private static PXR_PerformancePackDeviceProfile ToRuntimeProfile(DeviceProfile profile)
        {
            return (PXR_PerformancePackDeviceProfile)(int)profile;
        }

        private static bool IsProfileSelected(DeviceProfile profile)
        {
            switch (profile)
            {
                case DeviceProfile.PICO4Series:
                    return _config.devicePico4Series;
                case DeviceProfile.OtherDevice:
                    return _config.deviceOtherDevice;
                case DeviceProfile.ProjectSwan:
                default:
                    return _config.deviceProjectSwan;
            }
        }

        private static void EnsureEditingProfileIsSelected()
        {
            DeviceProfile editing = GetEditingProfile();
            if (!IsProfileSelected(editing))
            {
                _config.editingProfile = ToRuntimeProfile(GetPrimaryProfile());
            }
        }

        private static void NormalizeConfigForSelection(bool autoConfigure)
        {
            bool anySelected = _config.deviceProjectSwan || _config.devicePico4Series || _config.deviceOtherDevice;
            if (!anySelected)
            {
                _config.deviceProjectSwan = true;
                _config.devicePico4Series = true;
                _config.deviceOtherDevice = true;
            }

            EnsureEditingProfileIsSelected();
            DeviceProfile editingProfile = GetEditingProfile();
            DeviceTemplate template = Templates[editingProfile];

            if (autoConfigure)
            {
                ActiveDeviceConfig.renderScale = template.recommendedRenderScale;
                ActiveDeviceConfig.refreshRate = template.recommendedRefreshRate;
                ActiveDeviceConfig.foveation = template.recommendedFoveation;
                ActiveDeviceConfig.superResolution = template.superResolutionRecommended;
                ActiveDeviceConfig.sharpeningMode = SharpeningMode.None;
                ActiveDeviceConfig.sharpeningEnhance = SharpeningEnhance.None;
                ActiveDeviceConfig.hdr = template.hdrRecommended;
                ActiveDeviceConfig.adaptiveResolution = template.adaptiveResolutionRecommended;
                MarkDirty();
            }

            float clampedScale = Mathf.Clamp(ActiveDeviceConfig.renderScale, 0f, 2f);
            if (Mathf.Abs(clampedScale - ActiveDeviceConfig.renderScale) > 0.0001f)
            {
                ActiveDeviceConfig.renderScale = clampedScale;
                MarkDirty();
            }
            if (!IsValueSupportedAcrossSelection(templateSelector: t => t.refreshRates, value: ActiveDeviceConfig.refreshRate))
            {
                ActiveDeviceConfig.refreshRate = template.recommendedRefreshRate;
                MarkDirty();
            }
            if (!IsValueSupportedAcrossSelection(templateSelector: t => t.foveations, value: ActiveDeviceConfig.foveation))
            {
                ActiveDeviceConfig.foveation = template.recommendedFoveation;
                MarkDirty();
            }

            if (!IsToggleSupportedAcrossSelection(t => t.superResolutionSupported) && ActiveDeviceConfig.superResolution)
            {
                ActiveDeviceConfig.superResolution = false;
                MarkDirty();
            }
            if (!IsToggleSupportedAcrossSelection(t => t.hdrSupported) && ActiveDeviceConfig.hdr)
            {
                ActiveDeviceConfig.hdr = false;
                MarkDirty();
            }
            if (!IsToggleSupportedAcrossSelection(t => t.adaptiveResolutionSupported) && ActiveDeviceConfig.adaptiveResolution)
            {
                ActiveDeviceConfig.adaptiveResolution = false;
                MarkDirty();
            }
            if (ActiveDeviceConfig.superResolution && ActiveDeviceConfig.sharpeningMode != SharpeningMode.None)
            {
                ActiveDeviceConfig.sharpeningMode = SharpeningMode.None;
                MarkDirty();
            }
            if (ActiveDeviceConfig.superResolution || ActiveDeviceConfig.sharpeningMode == SharpeningMode.None)
            {
                if (ActiveDeviceConfig.sharpeningEnhance != SharpeningEnhance.None)
                {
                    ActiveDeviceConfig.sharpeningEnhance = SharpeningEnhance.None;
                    MarkDirty();
                }
            }
        }

        private static bool IsToggleSupportedAcrossSelection(Func<DeviceTemplate, bool> selector)
        {
            return selector(Templates[GetEditingProfile()]);
        }

        private static bool IsValueSupportedAcrossSelection(Func<DeviceTemplate, List<string>> templateSelector, string value)
        {
            return templateSelector(Templates[GetEditingProfile()]).Contains(value);
        }

        private static string BuildRecommendedText(Func<DeviceTemplate, string> selector)
        {
            return selector(Templates[GetEditingProfile()]);
        }

        private static string BuildRecommendedText(Func<DeviceTemplate, float> selector)
        {
            return FormatRenderScale(selector(Templates[GetEditingProfile()]));
        }

        private static StatusLevel EvaluateDropdownStatus(Func<DeviceTemplate, List<string>> supportedList, Func<DeviceTemplate, string> recommended, string value)
        {
            DeviceTemplate t = Templates[GetEditingProfile()];
            bool supported = supportedList(t).Contains(value);
            bool matchesRecommended = value == recommended(t);

            if (!supported) return StatusLevel.Unsupported;
            if (matchesRecommended) return StatusLevel.Recommended;
            return StatusLevel.Custom;
        }

        private static StatusLevel EvaluateRenderScaleStatus(float value)
        {
            value = ClampRenderScale(value);
            float r = Templates[GetEditingProfile()].recommendedRenderScale;

            if (Mathf.Abs(value - r) <= 0.001f) return StatusLevel.Recommended;
            return StatusLevel.Custom;
        }

        private static StatusLevel EvaluateToggleStatus(Func<DeviceTemplate, bool> supported, Func<DeviceTemplate, bool> recommended, bool value)
        {
            DeviceTemplate t = Templates[GetEditingProfile()];
            bool supportedValue = supported(t) || !value;
            bool matchesRecommended = value == recommended(t);

            if (!supportedValue) return StatusLevel.Unsupported;
            if (matchesRecommended) return StatusLevel.Recommended;
            return StatusLevel.Custom;
        }

        private static Color StatusColor(StatusLevel status)
        {
            switch (status)
            {
                case StatusLevel.Recommended:
                    return TokenSuccess;
                case StatusLevel.PerformanceWarning:
                    return TokenWarning;
                case StatusLevel.Unsupported:
                    return TokenError;
                case StatusLevel.Custom:
                default:
                    return GetTextSecondaryColor();
            }
        }

        private static string StatusText(StatusLevel status)
        {
            switch (status)
            {
                case StatusLevel.Recommended:
                    return "Recommended";
                case StatusLevel.PerformanceWarning:
                    return "Perf warning";
                case StatusLevel.Unsupported:
                    return "Unsupported";
                case StatusLevel.Custom:
                default:
                    return "Custom";
            }
        }

        private static Color GetBackgroundColor()
        {
            return EditorGUIUtility.isProSkin ? new Color(0.12f, 0.12f, 0.12f) : Color.white;
        }

        private static Color GetSurfaceColor()
        {
            return EditorGUIUtility.isProSkin ? new Color(0.16f, 0.16f, 0.16f) : new Color(0.96f, 0.96f, 0.96f);
        }

        private static Color GetBorderColor()
        {
            return EditorGUIUtility.isProSkin ? new Color(0.23f, 0.23f, 0.23f) : new Color(0.84f, 0.84f, 0.84f);
        }

        private static Color GetSeparatorColor()
        {
            return EditorGUIUtility.isProSkin ? new Color(0.18f, 0.18f, 0.18f) : new Color(0.90f, 0.90f, 0.90f);
        }

        private static Color GetTextPrimaryColor()
        {
            return EditorGUIUtility.isProSkin ? new Color(0.90f, 0.90f, 0.90f) : new Color(0.15f, 0.15f, 0.15f);
        }

        private static Color GetTextSecondaryColor()
        {
            return EditorGUIUtility.isProSkin ? new Color(0.62f, 0.62f, 0.62f) : new Color(0.55f, 0.55f, 0.55f);
        }

        private static void ApplyCardStyle(VisualElement element, bool withPadding = true)
        {
            Color border = GetBorderColor();
            element.style.backgroundColor = new StyleColor(GetSurfaceColor());
            element.style.borderTopWidth = 1;
            element.style.borderBottomWidth = 1;
            element.style.borderLeftWidth = 1;
            element.style.borderRightWidth = 1;
            element.style.borderTopColor = new StyleColor(border);
            element.style.borderBottomColor = new StyleColor(border);
            element.style.borderLeftColor = new StyleColor(border);
            element.style.borderRightColor = new StyleColor(border);
            element.style.borderTopLeftRadius = 6;
            element.style.borderTopRightRadius = 6;
            element.style.borderBottomLeftRadius = 6;
            element.style.borderBottomRightRadius = 6;
            if (withPadding)
            {
                element.style.paddingLeft = 12;
                element.style.paddingRight = 12;
                element.style.paddingTop = 12;
                element.style.paddingBottom = 12;
            }
        }

        private static void BuildUI(VisualElement root)
        {
            root.Clear();

            var container = new VisualElement();
            container.style.flexDirection = FlexDirection.Column;
            container.style.paddingLeft = 16;
            container.style.paddingRight = 16;
            container.style.paddingTop = 12;
            container.style.paddingBottom = 12;
            container.style.backgroundColor = new StyleColor(GetBackgroundColor());
            root.Add(container);

            var titleRow = new VisualElement();
            titleRow.style.flexDirection = FlexDirection.Row;
            titleRow.style.alignItems = Align.Center;
            titleRow.style.justifyContent = Justify.SpaceBetween;
            container.Add(titleRow);

            var title = new Label("Performance Pack");
            title.style.unityFontStyleAndWeight = FontStyle.Bold;
            title.style.fontSize = 18;
            title.style.color = new StyleColor(GetTextPrimaryColor());
            titleRow.Add(title);

            var statusText = new Label();
            statusText.style.color = new StyleColor(GetTextSecondaryColor());
            statusText.style.unityTextAlign = TextAnchor.MiddleRight;
            statusText.style.whiteSpace = WhiteSpace.Normal;
            titleRow.Add(statusText);

            var toolbar = new VisualElement();
            toolbar.style.flexDirection = FlexDirection.Row;
            toolbar.style.alignItems = Align.Center;
            toolbar.style.marginTop = 8;
            toolbar.style.paddingLeft = 8;
            toolbar.style.paddingRight = 8;
            toolbar.style.paddingTop = 6;
            toolbar.style.paddingBottom = 6;
            toolbar.style.backgroundColor = new StyleColor(GetSurfaceColor());
            toolbar.style.borderTopWidth = 1;
            toolbar.style.borderBottomWidth = 1;
            toolbar.style.borderLeftWidth = 1;
            toolbar.style.borderRightWidth = 1;
            toolbar.style.borderTopColor = new StyleColor(GetBorderColor());
            toolbar.style.borderBottomColor = new StyleColor(GetBorderColor());
            toolbar.style.borderLeftColor = new StyleColor(GetBorderColor());
            toolbar.style.borderRightColor = new StyleColor(GetBorderColor());
            toolbar.style.borderTopLeftRadius = 6;
            toolbar.style.borderTopRightRadius = 6;
            toolbar.style.borderBottomLeftRadius = 6;
            toolbar.style.borderBottomRightRadius = 6;
            container.Add(toolbar);

            var content = new VisualElement();
            content.style.flexGrow = 1;
            content.style.marginTop = 8;
            container.Add(content);

            void RefreshStatusText()
            {
                int count = 0;
                foreach (var _ in GetSelectedProfiles()) count++;
                string deviceText = count == 0 ? "No device selected" : $"{count} device(s) selected";
                string presetText = string.IsNullOrEmpty(_config?.presetName) ? "Preset: Default" : $"Preset: {_config.presetName}";
                string dirtyText = _isDirty ? "Status: Pending apply" : "Status: Saved";
                statusText.text = deviceText + " · " + presetText + " · " + dirtyText;
            }

            _requestStatusRefresh = RefreshStatusText;

            void RenderActiveTab()
            {
                content.Clear();
                RefreshStatusText();
                switch (_activeTab)
                {
                    case Tab.Basic:
                        content.Add(BuildBasicTab());
                        break;
                    case Tab.Advanced:
                        content.Add(BuildAdvancedTab());
                        break;
                    case Tab.Device:
                        content.Add(BuildDeviceTab());
                        break;
                    case Tab.Preview:
                        content.Add(BuildPreviewTab());
                        break;
                    case Tab.Help:
                        content.Add(BuildHelpTab());
                        break;
                }
            }

            void SwitchTab(Tab tab)
            {
                _activeTab = tab;
                RenderActiveTab();
            }

            var tabButtons = new Dictionary<Tab, Button>();

            void ApplyTabButtonStyle(Button button, bool selected)
            {
                button.style.marginRight = 6;
                button.style.paddingLeft = 10;
                button.style.paddingRight = 10;
                button.style.paddingTop = 4;
                button.style.paddingBottom = 4;
                button.style.borderTopLeftRadius = 4;
                button.style.borderTopRightRadius = 4;
                button.style.borderBottomLeftRadius = 4;
                button.style.borderBottomRightRadius = 4;
                button.style.borderTopWidth = 1;
                button.style.borderBottomWidth = 1;
                button.style.borderLeftWidth = 1;
                button.style.borderRightWidth = 1;

                if (selected)
                {
                    button.style.backgroundColor = new StyleColor(new Color(TokenPrimary.r, TokenPrimary.g, TokenPrimary.b, EditorGUIUtility.isProSkin ? 0.25f : 0.12f));
                    button.style.borderTopColor = new StyleColor(TokenPrimary);
                    button.style.borderBottomColor = new StyleColor(TokenPrimary);
                    button.style.borderLeftColor = new StyleColor(TokenPrimary);
                    button.style.borderRightColor = new StyleColor(TokenPrimary);
                    button.style.color = new StyleColor(GetTextPrimaryColor());
                }
                else
                {
                    button.style.backgroundColor = new StyleColor(Color.clear);
                    button.style.borderTopColor = new StyleColor(GetBorderColor());
                    button.style.borderBottomColor = new StyleColor(GetBorderColor());
                    button.style.borderLeftColor = new StyleColor(GetBorderColor());
                    button.style.borderRightColor = new StyleColor(GetBorderColor());
                    button.style.color = new StyleColor(GetTextSecondaryColor());
                }
            }

            void ApplyActionButtonStyle(Button button, Color baseColor)
            {
                float alpha = EditorGUIUtility.isProSkin ? 0.9f : 0.85f;
                var background = new Color(baseColor.r, baseColor.g, baseColor.b, alpha);
                button.style.marginLeft = 6;
                button.style.paddingLeft = 12;
                button.style.paddingRight = 12;
                button.style.paddingTop = 6;
                button.style.paddingBottom = 6;
                button.style.borderTopLeftRadius = 4;
                button.style.borderTopRightRadius = 4;
                button.style.borderBottomLeftRadius = 4;
                button.style.borderBottomRightRadius = 4;
                button.style.borderTopWidth = 1;
                button.style.borderBottomWidth = 1;
                button.style.borderLeftWidth = 1;
                button.style.borderRightWidth = 1;
                button.style.minWidth = 90;
                button.style.backgroundColor = new StyleColor(background);
                button.style.borderTopColor = new StyleColor(baseColor);
                button.style.borderBottomColor = new StyleColor(baseColor);
                button.style.borderLeftColor = new StyleColor(baseColor);
                button.style.borderRightColor = new StyleColor(baseColor);
                button.style.color = new StyleColor(Color.white);
                button.style.unityFontStyleAndWeight = FontStyle.Bold;
            }

            void ApplyActionButtonInteractions(Button button, Color baseColor)
            {
                float alpha = EditorGUIUtility.isProSkin ? 0.9f : 0.85f;
                var normal = new Color(baseColor.r, baseColor.g, baseColor.b, alpha);
                var hover = Color.Lerp(normal, Color.white, EditorGUIUtility.isProSkin ? 0.1f : 0.15f);
                var pressed = Color.Lerp(normal, Color.black, 0.2f);
                bool isPressed = false;

                button.RegisterCallback<MouseEnterEvent>(_ =>
                {
                    if (isPressed) return;
                    button.style.backgroundColor = new StyleColor(hover);
                });
                button.RegisterCallback<MouseLeaveEvent>(_ =>
                {
                    if (isPressed) return;
                    button.style.backgroundColor = new StyleColor(normal);
                });
                button.RegisterCallback<MouseDownEvent>(_ =>
                {
                    isPressed = true;
                    button.style.backgroundColor = new StyleColor(pressed);
                });
                button.RegisterCallback<MouseUpEvent>(_ =>
                {
                    isPressed = false;
                    button.style.backgroundColor = new StyleColor(hover);
                });
            }

            void SelectTab(Tab tab)
            {
                SwitchTab(tab);
                foreach (var kv in tabButtons)
                {
                    ApplyTabButtonStyle(kv.Value, kv.Key == _activeTab);
                }
            }

            void AddTabButton(Tab tab)
            {
                var button = new Button(() => SelectTab(tab)) { text = tab.ToString() };
                ApplyTabButtonStyle(button, tab == _activeTab);
                tabButtons[tab] = button;
                toolbar.Add(button);
            }

            AddTabButton(Tab.Basic);
            AddTabButton(Tab.Advanced);
            AddTabButton(Tab.Device);
            AddTabButton(Tab.Preview);
            AddTabButton(Tab.Help);

            var spacer = new VisualElement();
            spacer.style.flexGrow = 1;
            toolbar.Add(spacer);

            var applyButton = new Button(() =>
            {
                NormalizeConfigForSelection(autoConfigure: false);
                string summary = ApplyToSdkAndGetSummary();
                SaveToProjectAsset();
                RefreshStatusText();
                EditorUtility.DisplayDialog("Performance Pack", summary, "OK");
            })
            { text = "Apply" };
            ApplyActionButtonStyle(applyButton, TokenPrimary);
            ApplyActionButtonInteractions(applyButton, TokenPrimary);
            toolbar.Add(applyButton);

            var resetButton = new Button(() =>
            {
                NormalizeConfigForSelection(autoConfigure: true);
                RenderActiveTab();
            })
            { text = "Reset" };
            ApplyActionButtonStyle(resetButton, TokenWarning);
            ApplyActionButtonInteractions(resetButton, TokenWarning);
            toolbar.Add(resetButton);

            var savePresetButton = new Button(() =>
            {
                string path = EditorUtility.SaveFilePanel("Save Preset", string.Empty, "PICO_PerformancePack_Preset", "json");
                if (string.IsNullOrEmpty(path)) return;
                _config.presetName = Path.GetFileNameWithoutExtension(path);
                _config.updatedAtUnixMs = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds();
                File.WriteAllText(path, JsonUtility.ToJson(_config, true));
                MarkDirty();
                RefreshStatusText();
            })
            { text = "Save preset" };
            ApplyActionButtonStyle(savePresetButton, TokenSuccess);
            ApplyActionButtonInteractions(savePresetButton, TokenSuccess);
            toolbar.Add(savePresetButton);

            var exportButton = new Button(() =>
            {
                string path = EditorUtility.SaveFilePanel("Export Config", string.Empty, "PICO_PerformancePack_Config", "json");
                if (string.IsNullOrEmpty(path)) return;
                _config.updatedAtUnixMs = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds();
                File.WriteAllText(path, JsonUtility.ToJson(_config, true));
            })
            { text = "Export" };
            ApplyActionButtonStyle(exportButton, TokenInfo);
            ApplyActionButtonInteractions(exportButton, TokenInfo);
            toolbar.Add(exportButton);

            root.RegisterCallback<GeometryChangedEvent>(evt =>
            {
                bool isNarrow = evt.newRect.width > 1 && evt.newRect.width < NarrowWidthThreshold;
                if (isNarrow != _isNarrowLayout)
                {
                    _isNarrowLayout = isNarrow;
                    RenderActiveTab();
                }
            });

            RenderActiveTab();
        }

        private static string ApplyToSdkAndGetSummary()
        {
            EnsureLoaded();

            var lines = new List<string>();
            lines.Add("Applied configuration:");
            lines.Add($"Editing Device: {Templates[GetEditingProfile()].displayName}");

            bool savedAssets = false;
            bool updatedScene = false;

            ApplyRenderScaleToAndroidRenderPipelineAsset(lines, ref savedAssets);
            ApplyHdrToAndroidRenderPipelineAsset(lines, ref savedAssets);
            ApplyToPXRSettings(lines, ref savedAssets);
            ApplyToProjectSettingAndManagers(lines, ref savedAssets, ref updatedScene);
#if ENABLE_PICO_OPENXR_SDK
            ApplyToOpenXRProjectSetting(lines, ref savedAssets);
#endif

            if (savedAssets)
            {
                AssetDatabase.SaveAssets();
            }

            if (updatedScene)
            {
                AssetDatabase.SaveAssets();
            }

            if (ActiveDeviceConfig.adaptiveResolution && TryParseFoveation(ActiveDeviceConfig.foveation, out FoveatedRenderingMode _, out FoveationLevel level) && level != FoveationLevel.None)
            {
                lines.Add("Note: Adaptive Resolution is enabled; foveation may be incompatible on some setups.");
            }

            return string.Join("\n", lines);
        }

        private static void ApplyToPXRSettings(List<string> lines, ref bool savedAssets)
        {
            var settings = PXR_Settings.GetSettings();
            if (settings == null)
            {
                settings = ScriptableObject.CreateInstance<PXR_Settings>();
                EditorBuildSettings.AddConfigObject("ByteDance.PICO.XR.Settings", settings, true);
                savedAssets = true;
            }

            PXR_Settings.SystemDisplayFrequency freq = PXR_Settings.SystemDisplayFrequency.Default;
            if (TryParseRefreshRateHz(ActiveDeviceConfig.refreshRate, out int hz))
            {
                if (hz == 72) freq = PXR_Settings.SystemDisplayFrequency.RefreshRate72;
                else if (hz == 90) freq = PXR_Settings.SystemDisplayFrequency.RefreshRate90;
                else if (hz == 120) freq = PXR_Settings.SystemDisplayFrequency.RefreshRate120;
            }
            settings.systemDisplayFrequency = freq;
            EditorUtility.SetDirty(settings);
            savedAssets = true;

            lines.Add($"Refresh Rate: {ActiveDeviceConfig.refreshRate} (PXR_Settings.systemDisplayFrequency = {settings.systemDisplayFrequency})");
        }

        private static void ApplyToProjectSettingAndManagers(List<string> lines, ref bool savedAssets, ref bool updatedScene)
        {
            var projectConfig = PXR_ProjectSetting.GetProjectConfig();

            ApplyFoveationToProjectSetting(projectConfig);
            ApplyAdaptiveResolutionToProjectSetting(projectConfig);
            ApplySuperResolutionToProjectSetting(projectConfig);
            ApplySharpeningToProjectSetting(projectConfig);

            EditorUtility.SetDirty(projectConfig);
            savedAssets = true;

            var managers = UnityEngine.Object.FindObjectsOfType<PXR_Manager>();
            for (int i = 0; i < managers.Length; i++)
            {
                var m = managers[i];
                Undo.RecordObject(m, "Apply Performance Pack");

                ApplyFoveationToManager(m);
                ApplyAdaptiveResolutionToManager(m);
                ApplySuperResolutionToManager(m);
                ApplySharpeningToManager(m);

                EditorUtility.SetDirty(m);
                if (!Application.isPlaying && m.gameObject.scene.IsValid())
                {
                    EditorSceneManager.MarkSceneDirty(m.gameObject.scene);
                    updatedScene = true;
                }
            }

            lines.Add($"Render Scale: {FormatRenderScale(ActiveDeviceConfig.renderScale)}");
            lines.Add($"Foveated Rendering: {ActiveDeviceConfig.foveation}");
            lines.Add($"Adaptive Resolution: {(ActiveDeviceConfig.adaptiveResolution ? "On" : "Off")}");
            lines.Add($"Super Resolution: {(ActiveDeviceConfig.superResolution ? "On" : "Off")}");
        }

#if URP
        private static void ApplyRenderScaleToAndroidRenderPipelineAsset(List<string> lines, ref bool savedAssets)
        {
            UniversalRenderPipelineAsset pipelineAsset = GetAndroidRenderPipelineAsset(out string error);
            if (pipelineAsset == null)
            {
                lines.Add($"Render Scale: {error}");
                return;
            }

            float scale = ClampRenderScale(ActiveDeviceConfig.renderScale);
            if (Mathf.Abs(pipelineAsset.renderScale - scale) > 0.0001f)
            {
                Undo.RecordObject(pipelineAsset, "Apply Performance Pack Render Scale");
                pipelineAsset.renderScale = scale;
                EditorUtility.SetDirty(pipelineAsset);
                savedAssets = true;
            }

            lines.Add($"Render Scale: {FormatRenderScale(pipelineAsset.renderScale)} ({AssetDatabase.GetAssetPath(pipelineAsset)})");
        }

        private static void ApplyHdrToAndroidRenderPipelineAsset(List<string> lines, ref bool savedAssets)
        {
            UniversalRenderPipelineAsset pipelineAsset = GetAndroidRenderPipelineAsset(out string error);
            if (pipelineAsset == null)
            {
                lines.Add($"HDR: {error}");
                return;
            }

            bool hdr = ActiveDeviceConfig.hdr;
            if (pipelineAsset.supportsHDR != hdr)
            {
                Undo.RecordObject(pipelineAsset, "Apply Performance Pack HDR");
                pipelineAsset.supportsHDR = hdr;
                EditorUtility.SetDirty(pipelineAsset);
                savedAssets = true;
            }

            lines.Add($"HDR: {(pipelineAsset.supportsHDR ? "On" : "Off")} ({AssetDatabase.GetAssetPath(pipelineAsset)})");
        }

        private static UniversalRenderPipelineAsset GetAndroidRenderPipelineAsset(out string error)
        {
            error = null;
            UnityEngine.Object qualitySettingsAsset = null;
            UnityEngine.Object[] qualitySettingsAssets = AssetDatabase.LoadAllAssetsAtPath("ProjectSettings/QualitySettings.asset");
            for (int i = 0; i < qualitySettingsAssets.Length; i++)
            {
                if (qualitySettingsAssets[i] != null)
                {
                    qualitySettingsAsset = qualitySettingsAssets[i];
                    break;
                }
            }

            if (qualitySettingsAsset == null)
            {
                error = "Android quality settings asset was not found.";
                return null;
            }

            var serializedQualitySettings = new SerializedObject(qualitySettingsAsset);
            SerializedProperty qualityLevels = serializedQualitySettings.FindProperty("m_QualitySettings");
            int androidQualityIndex = GetAndroidDefaultQualityIndex(serializedQualitySettings);
            if (qualityLevels == null || androidQualityIndex < 0 || androidQualityIndex >= qualityLevels.arraySize)
            {
                error = "Android default quality level was not found.";
                return null;
            }

            SerializedProperty qualityLevel = qualityLevels.GetArrayElementAtIndex(androidQualityIndex);
            UniversalRenderPipelineAsset pipelineAsset = qualityLevel
                .FindPropertyRelative("customRenderPipeline")
                ?.objectReferenceValue as UniversalRenderPipelineAsset;
            if (pipelineAsset == null)
            {
                pipelineAsset = GraphicsSettings.defaultRenderPipeline as UniversalRenderPipelineAsset;
            }

            if (pipelineAsset == null)
            {
                error = "Android quality level does not use a URP asset.";
            }

            return pipelineAsset;
        }

        private static int GetAndroidDefaultQualityIndex(SerializedObject serializedQualitySettings)
        {
            SerializedProperty platformDefaults = serializedQualitySettings.FindProperty("m_PerPlatformDefaultQuality");
            if (platformDefaults == null || !platformDefaults.isArray)
            {
                return -1;
            }

            for (int i = 0; i < platformDefaults.arraySize; i++)
            {
                SerializedProperty platformDefault = platformDefaults.GetArrayElementAtIndex(i);
                SerializedProperty platform = platformDefault.FindPropertyRelative("first");
                if (platform == null || !string.Equals(platform.stringValue, "Android", StringComparison.Ordinal))
                {
                    continue;
                }

                SerializedProperty qualityIndex = platformDefault.FindPropertyRelative("second");
                return qualityIndex != null ? qualityIndex.intValue : -1;
            }

            return -1;
        }
#else
        private static void ApplyRenderScaleToAndroidRenderPipelineAsset(List<string> lines, ref bool savedAssets)
        {
            lines.Add("Render Scale: Runtime-only because URP is not installed.");
        }

        private static void ApplyHdrToAndroidRenderPipelineAsset(List<string> lines, ref bool savedAssets)
        {
            lines.Add("HDR: Preset-only because URP is not installed.");
        }
#endif

        private static void ApplyFoveationToProjectSetting(PXR_ProjectSetting projectConfig)
        {
            if (!TryParseFoveation(ActiveDeviceConfig.foveation, out FoveatedRenderingMode mode, out FoveationLevel level))
            {
                mode = FoveatedRenderingMode.FixedFoveatedRendering;
                level = FoveationLevel.None;
            }

            bool enabled = level != FoveationLevel.None;
            projectConfig.enableETFR = enabled && mode == FoveatedRenderingMode.EyeTrackedFoveatedRendering;
            projectConfig.eyeTracking = projectConfig.enableETFR;
            projectConfig.foveationLevel = level;
            projectConfig.validationFFREnabled = enabled && mode == FoveatedRenderingMode.FixedFoveatedRendering;
            projectConfig.validationETFREnabled = enabled && mode == FoveatedRenderingMode.EyeTrackedFoveatedRendering;

            if (!enabled)
            {
                projectConfig.enableSubsampled = false;
                projectConfig.recommendSubsamping = false;
                return;
            }

            bool glesGamma = false;
            var apis = PlayerSettings.GetGraphicsAPIs(EditorUserBuildSettings.activeBuildTarget);
            if (apis != null && apis.Length > 0)
            {
                glesGamma = apis[0] == GraphicsDeviceType.OpenGLES3 && PlayerSettings.colorSpace == ColorSpace.Gamma;
            }

            if (glesGamma)
            {
                projectConfig.enableSubsampled = false;
                projectConfig.recommendSubsamping = false;
            }
            else
            {
                projectConfig.enableSubsampled = true;
                projectConfig.recommendSubsamping = true;
            }

        }

        private static void ApplyFoveationToManager(PXR_Manager manager)
        {
            if (!TryParseFoveation(ActiveDeviceConfig.foveation, out FoveatedRenderingMode mode, out FoveationLevel level))
            {
                mode = FoveatedRenderingMode.FixedFoveatedRendering;
                level = FoveationLevel.None;
            }

            manager.foveatedRenderingMode = mode;
            manager.eyeTracking = mode == FoveatedRenderingMode.EyeTrackedFoveatedRendering && level != FoveationLevel.None;
            if (mode == FoveatedRenderingMode.EyeTrackedFoveatedRendering)
            {
                manager.eyeFoveationLevel = level;
                manager.foveationLevel = FoveationLevel.None;
                if (level == FoveationLevel.None)
                {
                    manager.eyeFoveationLevel = FoveationLevel.None;
                }
            }
            else
            {
                manager.foveationLevel = level;
                manager.eyeFoveationLevel = FoveationLevel.None;
                if (level == FoveationLevel.None)
                {
                    manager.foveationLevel = FoveationLevel.None;
                }
            }
        }

        private static void ApplyAdaptiveResolutionToProjectSetting(PXR_ProjectSetting projectConfig)
        {
            projectConfig.adaptiveResolution = ActiveDeviceConfig.adaptiveResolution;
        }

        private static void ApplyAdaptiveResolutionToManager(PXR_Manager manager)
        {
            manager.adaptiveResolution = ActiveDeviceConfig.adaptiveResolution;

            float scale = ClampRenderScale(ActiveDeviceConfig.renderScale);
            float minScale = Mathf.Clamp(scale * 0.85f, 0f, scale);

            XRSettings.eyeTextureResolutionScale = scale;
            manager.maxEyeTextureScale = scale;
            manager.minEyeTextureScale = Mathf.Clamp(minScale, 0f, manager.maxEyeTextureScale);
        }

        private static void ApplySuperResolutionToProjectSetting(PXR_ProjectSetting projectConfig)
        {
            projectConfig.superResolution = ActiveDeviceConfig.superResolution;
        }

        private static void ApplySuperResolutionToManager(PXR_Manager manager)
        {
            manager.enableSuperResolution = ActiveDeviceConfig.superResolution;
        }

        private static void ApplySharpeningToProjectSetting(PXR_ProjectSetting projectConfig)
        {
            SharpeningMode mode = ActiveDeviceConfig.superResolution ? SharpeningMode.None : ActiveDeviceConfig.sharpeningMode;
            SharpeningEnhance enhance = mode == SharpeningMode.None
                ? SharpeningEnhance.None
                : ActiveDeviceConfig.sharpeningEnhance;

            projectConfig.normalSharpening = mode == SharpeningMode.Normal;
            projectConfig.qualitySharpening = mode == SharpeningMode.Quality;
            projectConfig.fixedFoveatedSharpening = enhance == SharpeningEnhance.FixedFoveated || enhance == SharpeningEnhance.Both;
            projectConfig.selfAdaptiveSharpening = enhance == SharpeningEnhance.SelfAdaptive || enhance == SharpeningEnhance.Both;
        }

        private static void ApplySharpeningToManager(PXR_Manager manager)
        {
            SharpeningMode mode = ActiveDeviceConfig.superResolution ? SharpeningMode.None : ActiveDeviceConfig.sharpeningMode;
            SharpeningEnhance enhance = mode == SharpeningMode.None
                ? SharpeningEnhance.None
                : ActiveDeviceConfig.sharpeningEnhance;

            manager.sharpeningMode = mode;
            manager.sharpeningEnhance = enhance;
        }

        private static bool TryParseRefreshRateHz(string text, out int hz)
        {
            hz = 0;
            if (string.IsNullOrEmpty(text)) return false;

            int i = 0;
            while (i < text.Length && (text[i] < '0' || text[i] > '9')) i++;
            if (i >= text.Length) return false;

            int value = 0;
            while (i < text.Length && text[i] >= '0' && text[i] <= '9')
            {
                value = value * 10 + (text[i] - '0');
                i++;
            }
            if (value <= 0) return false;
            hz = value;
            return true;
        }

        private static float ClampRenderScale(float value)
        {
            return Mathf.Clamp(value, 0f, 2f);
        }

        private static string FormatRenderScale(float value)
        {
            return ClampRenderScale(value).ToString("0.00");
        }

#if ENABLE_PICO_OPENXR_SDK
        private static FoveationFeature.FoveatedRenderingLevel MapOpenXRFoveationLevel(FoveationLevel level)
        {
            switch (level)
            {
                case FoveationLevel.Low:
                    return FoveationFeature.FoveatedRenderingLevel.Low;
                case FoveationLevel.Med:
                    return FoveationFeature.FoveatedRenderingLevel.Medium;
                case FoveationLevel.High:
                case FoveationLevel.TopHigh:
                    return FoveationFeature.FoveatedRenderingLevel.High;
                default:
                    return FoveationFeature.FoveatedRenderingLevel.Off;
            }
        }

        private static void ApplyToOpenXRProjectSetting(List<string> lines, ref bool savedAssets)
        {
            var config = PXR_OpenXRProjectSetting.GetProjectConfig();

            if (TryParseRefreshRateHz(ActiveDeviceConfig.refreshRate, out int hz))
            {
                if (hz == 72) config.displayFrequency = ByteDance.PICO.OpenXR.SystemDisplayFrequency.RefreshRate72;
                else if (hz == 90) config.displayFrequency = ByteDance.PICO.OpenXR.SystemDisplayFrequency.RefreshRate90;
                else if (hz == 120) config.displayFrequency = ByteDance.PICO.OpenXR.SystemDisplayFrequency.RefreshRate120;
                else config.displayFrequency = ByteDance.PICO.OpenXR.SystemDisplayFrequency.Default;
            }
            else
            {
                config.displayFrequency = ByteDance.PICO.OpenXR.SystemDisplayFrequency.Default;
            }

            if (!TryParseFoveation(ActiveDeviceConfig.foveation, out FoveatedRenderingMode mode, out FoveationLevel level))
            {
                mode = FoveatedRenderingMode.FixedFoveatedRendering;
                level = FoveationLevel.None;
            }

            bool enabled = level != FoveationLevel.None;
            config.foveationEnable = enabled;
            config.foveatedRenderingMode = mode == FoveatedRenderingMode.EyeTrackedFoveatedRendering
                ? FoveationFeature.FoveatedRenderingMode.EyeTrackedFoveatedRendering
                : FoveationFeature.FoveatedRenderingMode.FixedFoveatedRendering;
            config.foveatedRenderingLevel = MapOpenXRFoveationLevel(level);

            EditorUtility.SetDirty(config);
            savedAssets = true;

            PXR_Utils.EnableOpenXRFeature<DisplayRefreshRateFeature>();
            PXR_Utils.EnableOpenXRFeature<FoveationFeature>();

            lines.Add($"OpenXR: displayFrequency = {config.displayFrequency}");
            lines.Add($"OpenXR: foveationEnable = {config.foveationEnable}, mode = {config.foveatedRenderingMode}, level = {config.foveatedRenderingLevel}");
        }
#endif

        private static ScrollView CreateScrollView(Func<Vector2> getScrollOffset, Action<Vector2> setScrollOffset)
        {
            var scroll = new ScrollView(ScrollViewMode.Vertical);
            scroll.scrollOffset = getScrollOffset();

            if (scroll.verticalScroller != null)
            {
                scroll.verticalScroller.valueChanged += _ => setScrollOffset(scroll.scrollOffset);
            }
            if (scroll.horizontalScroller != null)
            {
                scroll.horizontalScroller.valueChanged += _ => setScrollOffset(scroll.scrollOffset);
            }
            scroll.RegisterCallback<WheelEvent>(_ => setScrollOffset(scroll.scrollOffset));
            scroll.RegisterCallback<GeometryChangedEvent>(_ => scroll.scrollOffset = getScrollOffset());

            return scroll;
        }

        private static VisualElement BuildBasicTab()
        {
            var root = new VisualElement();
            var scroll = CreateScrollView(() => _scrollPosBasic, v => _scrollPosBasic = v);
            root.Add(scroll);

            scroll.Add(BuildDeviceSelectionPanel(showTitle: true, autoConfigureOnChange: true));
            scroll.Add(BuildEditingProfilePanel());

            var header = new Label("Core Settings");
            header.style.unityFontStyleAndWeight = FontStyle.Bold;
            header.style.fontSize = 16;
            header.style.marginTop = 12;
            header.style.color = new StyleColor(GetTextPrimaryColor());
            scroll.Add(header);

            scroll.Add(BuildCoreSettingsGrid());
            return root;
        }

        private static VisualElement BuildAdvancedTab()
        {
            var root = new VisualElement();
            var scroll = CreateScrollView(() => _scrollPosAdvanced, v => _scrollPosAdvanced = v);
            root.Add(scroll);

            var header = new Label("Visual Enhancements");
            header.style.unityFontStyleAndWeight = FontStyle.Bold;
            header.style.fontSize = 16;
            header.style.color = new StyleColor(GetTextPrimaryColor());
            scroll.Add(header);

            scroll.Add(BuildToggleRow(
                label: "Super Resolution",
                getValue: () => ActiveDeviceConfig.superResolution,
                setValue: v =>
                {
                    ActiveDeviceConfig.superResolution = v;
                    if (v)
                    {
                        ActiveDeviceConfig.sharpeningMode = SharpeningMode.None;
                        ActiveDeviceConfig.sharpeningEnhance = SharpeningEnhance.None;
                    }
                    MarkDirty();
                },
                impact: "Medium",
                status: EvaluateToggleStatus(t => t.superResolutionSupported, t => t.superResolutionRecommended, ActiveDeviceConfig.superResolution)
            ));

            scroll.Add(BuildToggleRow(
                label: "HDR",
                getValue: () => ActiveDeviceConfig.hdr,
                setValue: v =>
                {
                    ActiveDeviceConfig.hdr = v;
                    MarkDirty();
                },
                impact: "Medium",
                status: EvaluateToggleStatus(t => t.hdrSupported, t => t.hdrRecommended, ActiveDeviceConfig.hdr)
            ));

            var sharpeningRow = BuildEnumRow(
                label: "Sharpening Mode",
                options: new List<string>(Enum.GetNames(typeof(SharpeningMode))),
                getValue: () => ActiveDeviceConfig.sharpeningMode.ToString(),
                setValue: v =>
                {
                    if (Enum.TryParse(v, out SharpeningMode mode))
                    {
                        ActiveDeviceConfig.sharpeningMode = mode;
                        if (mode == SharpeningMode.None)
                        {
                            ActiveDeviceConfig.sharpeningEnhance = SharpeningEnhance.None;
                        }
                        MarkDirty();
                    }
                }
            );
            sharpeningRow.SetEnabled(!ActiveDeviceConfig.superResolution);
            scroll.Add(sharpeningRow);

            if (!ActiveDeviceConfig.superResolution && ActiveDeviceConfig.sharpeningMode != SharpeningMode.None)
            {
                var sharpeningEnhanceRow = BuildEnumRow(
                    label: "Sharpening Enhance Mode",
                    options: new List<string>(Enum.GetNames(typeof(SharpeningEnhance))),
                    getValue: () => ActiveDeviceConfig.sharpeningEnhance.ToString(),
                    setValue: v =>
                    {
                        if (Enum.TryParse(v, out SharpeningEnhance enhance))
                        {
                            ActiveDeviceConfig.sharpeningEnhance = enhance;
                            MarkDirty();
                        }
                    }
                );
                sharpeningEnhanceRow.style.marginLeft = 16;
                sharpeningEnhanceRow.SetEnabled(!ActiveDeviceConfig.superResolution);
                scroll.Add(sharpeningEnhanceRow);
            }

            var header2 = new Label("Performance Optimizations");
            header2.style.unityFontStyleAndWeight = FontStyle.Bold;
            header2.style.fontSize = 16;
            header2.style.marginTop = 12;
            header2.style.color = new StyleColor(GetTextPrimaryColor());
            scroll.Add(header2);

            scroll.Add(BuildToggleRow(
                label: "Adaptive Resolution",
                getValue: () => ActiveDeviceConfig.adaptiveResolution,
                setValue: v =>
                {
                    ActiveDeviceConfig.adaptiveResolution = v;
                    MarkDirty();
                },
                impact: "Low",
                status: EvaluateToggleStatus(t => t.adaptiveResolutionSupported, t => t.adaptiveResolutionRecommended, ActiveDeviceConfig.adaptiveResolution)
            ));

            return root;
        }

        private static VisualElement BuildDeviceTab()
        {
            var root = new VisualElement();
            var scroll = CreateScrollView(() => _scrollPosDevice, v => _scrollPosDevice = v);
            root.Add(scroll);

            scroll.Add(BuildDeviceSelectionPanel(showTitle: false, autoConfigureOnChange: true));
            scroll.Add(BuildEditingProfilePanel());

            var hint = new Label("Select target devices to auto-apply recommended values. You can override them in Basic/Advanced tabs.");
            hint.style.marginTop = 8;
            hint.style.whiteSpace = WhiteSpace.Normal;
            hint.style.color = new StyleColor(GetTextSecondaryColor());
            scroll.Add(hint);
            return root;
        }

        private static VisualElement BuildPreviewTab()
        {
            var root = new VisualElement();
            var scroll = CreateScrollView(() => _scrollPosPreview, v => _scrollPosPreview = v);
            root.Add(scroll);

            var header = new Label("Preview");
            header.style.unityFontStyleAndWeight = FontStyle.Bold;
            header.style.fontSize = 16;
            header.style.color = new StyleColor(GetTextPrimaryColor());
            scroll.Add(header);

            scroll.Add(BuildSummaryCard());

            foreach (var profile in GetSelectedProfiles())
            {
                scroll.Add(BuildDevicePreviewCard(profile));
            }

            return root;
        }

        private static VisualElement BuildHelpTab()
        {
            var root = new VisualElement();
            var scroll = CreateScrollView(() => _scrollPosHelp, v => _scrollPosHelp = v);
            root.Add(scroll);

            var header = new Label("Help");
            header.style.unityFontStyleAndWeight = FontStyle.Bold;
            header.style.fontSize = 16;
            header.style.color = new StyleColor(GetTextPrimaryColor());
            scroll.Add(header);

            var content = new Label(
                "Performance Pack provides a centralized UI to select recommended settings per target device and override when needed.\n\n" +
                "Status:\n" +
                "Recommended: matches recommended values for all selected devices\n" +
                "Perf warning: recommended for some devices but not all\n" +
                "Unsupported: at least one selected device does not support the value\n" +
                "Custom: differs from all selected devices' recommendations\n\n" +
                "Flow: Select devices → Review recommendations → Customize → Preview → Save/Export"
            );
            content.style.whiteSpace = WhiteSpace.Normal;
            content.style.marginTop = 8;
            content.style.color = new StyleColor(GetTextPrimaryColor());
            scroll.Add(content);

            var legendCard = new VisualElement();
            legendCard.style.marginTop = 10;
            ApplyCardStyle(legendCard);
            scroll.Add(legendCard);

            var legendTitle = new Label("Status Legend");
            legendTitle.style.unityFontStyleAndWeight = FontStyle.Bold;
            legendTitle.style.color = new StyleColor(GetTextPrimaryColor());
            legendCard.Add(legendTitle);

            legendCard.Add(BuildLegendRow(StatusLevel.Recommended, "Matches recommended values for all selected devices."));
            legendCard.Add(BuildLegendRow(StatusLevel.PerformanceWarning, "Recommended for some devices, but not all."));
            legendCard.Add(BuildLegendRow(StatusLevel.Unsupported, "At least one selected device does not support the value."));
            legendCard.Add(BuildLegendRow(StatusLevel.Custom, "Differs from all selected devices' recommendations."));

            return root;
        }

        private static VisualElement BuildLegendRow(StatusLevel status, string description)
        {
            var row = new VisualElement();
            row.style.flexDirection = FlexDirection.Row;
            row.style.alignItems = Align.Center;
            row.style.marginTop = 8;

            var chip = BuildStatusChip(status);
            chip.style.marginRight = 10;
            row.Add(chip);

            var label = new Label(description);
            label.style.flexGrow = 1;
            label.style.whiteSpace = WhiteSpace.Normal;
            label.style.color = new StyleColor(GetTextSecondaryColor());
            row.Add(label);

            return row;
        }

        private static VisualElement BuildDeviceSelectionPanel(bool showTitle, bool autoConfigureOnChange)
        {
            var box = new VisualElement();
            ApplyCardStyle(box);

            if (showTitle)
            {
                var title = new Label("Device Selection");
                title.style.unityFontStyleAndWeight = FontStyle.Bold;
                title.style.fontSize = 16;
                title.style.color = new StyleColor(GetTextPrimaryColor());
                box.Add(title);
            }

            var row = new VisualElement();
            row.style.flexDirection = FlexDirection.Row;
            row.style.flexWrap = Wrap.Wrap;
            row.style.marginTop = 6;
            box.Add(row);

            var projectSwanToggle = new Toggle("PICO Space Pro") { value = _config.deviceProjectSwan };
            var pico4Toggle = new Toggle("PICO 4 Ultra") { value = _config.devicePico4Series };
            var otherToggle = new Toggle("Other Device") { value = _config.deviceOtherDevice };
            ApplyDeviceToggleStyle(projectSwanToggle);
            ApplyDeviceToggleStyle(pico4Toggle);
            ApplyDeviceToggleStyle(otherToggle);
            projectSwanToggle.style.marginRight = 12;
            pico4Toggle.style.marginRight = 12;

            void OnDeviceChanged()
            {
                MarkDirty();
                NormalizeConfigForSelection(autoConfigureOnChange);
                RequestRebuild();
            }

            projectSwanToggle.RegisterValueChangedCallback(evt =>
            {
                _config.deviceProjectSwan = evt.newValue;
                OnDeviceChanged();
            });
            pico4Toggle.RegisterValueChangedCallback(evt =>
            {
                _config.devicePico4Series = evt.newValue;
                OnDeviceChanged();
            });
            otherToggle.RegisterValueChangedCallback(evt =>
            {
                _config.deviceOtherDevice = evt.newValue;
                OnDeviceChanged();
            });

            row.Add(projectSwanToggle);
            row.Add(pico4Toggle);
            row.Add(otherToggle);

            var helper = new Label("Multi-select supported. Recommendations update based on selection; unsupported values are flagged.");
            helper.style.marginTop = 6;
            helper.style.whiteSpace = WhiteSpace.Normal;
            helper.style.color = new StyleColor(GetTextSecondaryColor());
            box.Add(helper);

            return box;
        }

        private static void ApplyDeviceToggleStyle(Toggle toggle)
        {
            toggle.style.color = new StyleColor(GetTextPrimaryColor());

            var input = toggle.Q<VisualElement>(className: Toggle.inputUssClassName);
            var checkmark = toggle.Q<VisualElement>(className: Toggle.checkmarkUssClassName);
            if (input == null || checkmark == null) return;

            void Refresh(bool selected)
            {
                Color border = selected
                    ? TokenPrimary
                    : EditorGUIUtility.isProSkin
                        ? new Color(0.62f, 0.62f, 0.62f)
                        : new Color(0.42f, 0.42f, 0.42f);
                Color background = selected
                    ? TokenPrimary
                    : EditorGUIUtility.isProSkin
                        ? new Color(0.08f, 0.08f, 0.08f)
                        : Color.white;

                input.style.backgroundColor = new StyleColor(background);
                input.style.borderTopWidth = 1;
                input.style.borderBottomWidth = 1;
                input.style.borderLeftWidth = 1;
                input.style.borderRightWidth = 1;
                input.style.borderTopColor = new StyleColor(border);
                input.style.borderBottomColor = new StyleColor(border);
                input.style.borderLeftColor = new StyleColor(border);
                input.style.borderRightColor = new StyleColor(border);
                checkmark.style.unityBackgroundImageTintColor = new StyleColor(Color.white);
            }

            Refresh(toggle.value);
            toggle.RegisterValueChangedCallback(evt => Refresh(evt.newValue));
        }

        private static VisualElement BuildEditingProfilePanel()
        {
            var box = new VisualElement();
            box.style.marginTop = 10;
            ApplyCardStyle(box);

            var title = new Label("Editing Device");
            title.style.unityFontStyleAndWeight = FontStyle.Bold;
            title.style.fontSize = 14;
            title.style.color = new StyleColor(GetTextPrimaryColor());
            box.Add(title);

            var selectedProfiles = new List<DeviceProfile>(GetSelectedProfiles());
            if (selectedProfiles.Count == 0)
            {
                selectedProfiles.Add(DeviceProfile.ProjectSwan);
            }

            var options = new List<string>();
            for (int i = 0; i < selectedProfiles.Count; i++)
            {
                options.Add(Templates[selectedProfiles[i]].displayName);
            }

            DeviceProfile editingProfile = GetEditingProfile();
            int currentIndex = selectedProfiles.IndexOf(editingProfile);
            if (currentIndex < 0) currentIndex = 0;

            var popup = new PopupField<string>(options, currentIndex);
            popup.style.marginTop = 8;
            popup.RegisterValueChangedCallback(evt =>
            {
                int index = options.IndexOf(evt.newValue);
                if (index < 0 || index >= selectedProfiles.Count) return;
                _config.editingProfile = ToRuntimeProfile(selectedProfiles[index]);
                NormalizeConfigForSelection(autoConfigure: false);
                MarkDirty();
                RequestRebuild();
            });
            box.Add(popup);

            var helper = new Label("Basic and Advanced settings edit this device only. Preview shows every selected device profile.");
            helper.style.marginTop = 6;
            helper.style.whiteSpace = WhiteSpace.Normal;
            helper.style.color = new StyleColor(GetTextSecondaryColor());
            box.Add(helper);

            return box;
        }

        private static VisualElement BuildCoreSettingsGrid()
        {
            var grid = new VisualElement();
            grid.style.marginTop = 8;

            if (!_isNarrowLayout)
            {
                grid.Add(BuildGridHeaderRow());
            }
            grid.Add(BuildRenderScaleRow(
                label: "Render Scale",
                getValue: () => ActiveDeviceConfig.renderScale,
                setValue: v =>
                {
                    ActiveDeviceConfig.renderScale = ClampRenderScale(v);
                    MarkDirty();
                    NormalizeConfigForSelection(autoConfigure: false);
                },
                recommended: BuildRecommendedText(t => t.recommendedRenderScale),
                status: EvaluateRenderScaleStatus(ActiveDeviceConfig.renderScale)
            ));
            grid.Add(BuildDropdownRow(
                label: "Refresh Rate",
                options: BuildUnionOptions(t => t.refreshRates),
                getValue: () => ActiveDeviceConfig.refreshRate,
                setValue: v =>
                {
                    ActiveDeviceConfig.refreshRate = v;
                    MarkDirty();
                    NormalizeConfigForSelection(autoConfigure: false);
                },
                recommended: BuildRecommendedText(t => t.recommendedRefreshRate),
                status: EvaluateDropdownStatus(t => t.refreshRates, t => t.recommendedRefreshRate, ActiveDeviceConfig.refreshRate)
            ));
            if (!TryParseFoveation(ActiveDeviceConfig.foveation, out FoveatedRenderingMode currentMode, out FoveationLevel currentLevel))
            {
                currentMode = FoveatedRenderingMode.FixedFoveatedRendering;
                currentLevel = FoveationLevel.None;
            }

            grid.Add(BuildDropdownRow(
                label: "Foveation Mode",
                options: BuildUnionOptions(GetFoveationModeOptions),
                getValue: () => GetFoveationModeLabel(currentMode),
                setValue: v =>
                {
                    if (TryParseFoveationModeLabel(v, out FoveatedRenderingMode mode))
                    {
                        ActiveDeviceConfig.foveation = BuildFoveationOption(mode, currentLevel);
                        MarkDirty();
                        NormalizeConfigForSelection(autoConfigure: false);
                    }
                },
                recommended: BuildRecommendedText(t => GetFoveationModeLabel(GetFoveationModeFromOption(t.recommendedFoveation))),
                status: EvaluateDropdownStatus(GetFoveationModeOptions, t => GetFoveationModeLabel(GetFoveationModeFromOption(t.recommendedFoveation)), GetFoveationModeLabel(currentMode))
            ));
            grid.Add(BuildDropdownRow(
                label: "Foveation Level",
                options: BuildUnionOptions(GetFoveationLevelOptions),
                getValue: () => GetFoveationLevelLabel(currentLevel),
                setValue: v =>
                {
                    if (TryParseFoveationLevel(v, out FoveationLevel level))
                    {
                        ActiveDeviceConfig.foveation = BuildFoveationOption(currentMode, level);
                        MarkDirty();
                        NormalizeConfigForSelection(autoConfigure: false);
                    }
                },
                recommended: BuildRecommendedText(t => GetFoveationLevelLabel(GetFoveationLevelFromOption(t.recommendedFoveation))),
                status: EvaluateDropdownStatus(GetFoveationLevelOptions, t => GetFoveationLevelLabel(GetFoveationLevelFromOption(t.recommendedFoveation)), GetFoveationLevelLabel(currentLevel))
            ));

            return grid;
        }

        private static List<string> BuildUnionOptions(Func<DeviceTemplate, List<string>> selector)
        {
            var set = new HashSet<string>(StringComparer.Ordinal);
            foreach (string opt in selector(Templates[GetEditingProfile()]))
            {
                set.Add(opt);
            }

            var list = new List<string>(set);
            list.Sort(StringComparer.Ordinal);
            return list;
        }

        private static VisualElement BuildGridHeaderRow()
        {
            var row = new VisualElement();
            row.style.flexDirection = FlexDirection.Row;
            row.style.alignItems = Align.Center;
            row.style.paddingBottom = 6;
            row.style.borderBottomWidth = 1;
            row.style.borderBottomColor = new StyleColor(GetBorderColor());

            row.Add(BuildHeaderCell("Setting", 180));
            row.Add(BuildHeaderCell("Current", 180));
            row.Add(BuildHeaderCell("Recommended", 220));
            row.Add(BuildHeaderCell("Status", 120));
            return row;
        }

        private static Label BuildHeaderCell(string text, float width)
        {
            var label = new Label(text);
            label.style.unityFontStyleAndWeight = FontStyle.Bold;
            label.style.width = width;
            label.style.color = new StyleColor(GetTextPrimaryColor());
            return label;
        }

        private static VisualElement BuildDropdownRow(string label, List<string> options, Func<string> getValue, Action<string> setValue, string recommended, StatusLevel status)
        {
            string current = getValue();
            if (!options.Contains(current) && options.Count > 0)
            {
                current = options[0];
                setValue(current);
            }

            if (_isNarrowLayout)
            {
                var card = new VisualElement();
                ApplyCardStyle(card);
                card.style.marginTop = 8;

                var title = new Label(label);
                title.style.unityFontStyleAndWeight = FontStyle.Bold;
                title.style.color = new StyleColor(GetTextPrimaryColor());
                card.Add(title);

                var rowTop = new VisualElement();
                rowTop.style.flexDirection = FlexDirection.Row;
                rowTop.style.alignItems = Align.Center;
                rowTop.style.marginTop = 8;
                card.Add(rowTop);

                var popup = new PopupField<string>(options, current);
                popup.style.flexGrow = 1;
                popup.style.marginRight = 8;
                popup.RegisterValueChangedCallback(evt =>
                {
                    setValue(evt.newValue);
                    RequestRebuild();
                });
                rowTop.Add(popup);
                rowTop.Add(BuildStatusChip(status));

                if (!string.IsNullOrEmpty(recommended))
                {
                    var helper = new Label("Recommended: " + recommended);
                    helper.style.marginTop = 6;
                    helper.style.whiteSpace = WhiteSpace.Normal;
                    helper.style.color = new StyleColor(GetTextSecondaryColor());
                    card.Add(helper);
                }

                return card;
            }
            else
            {
                var row = new VisualElement();
                row.style.flexDirection = FlexDirection.Row;
                row.style.alignItems = Align.Center;
                row.style.paddingTop = 8;
                row.style.paddingBottom = 8;
                row.style.borderBottomWidth = 1;
                row.style.borderBottomColor = new StyleColor(GetSeparatorColor());

                var labelCell = new Label(label);
                labelCell.style.width = 180;
                labelCell.style.color = new StyleColor(GetTextPrimaryColor());
                row.Add(labelCell);

                var popup = new PopupField<string>(options, current);
                popup.style.width = 180;
                popup.style.marginLeft = 0;
                popup.style.marginRight = 0;
                popup.RegisterValueChangedCallback(evt =>
                {
                    setValue(evt.newValue);
                    RequestRebuild();
                });
                row.Add(popup);

                var recommendedCell = new Label(recommended);
                recommendedCell.style.whiteSpace = WhiteSpace.Normal;
                recommendedCell.style.width = 220;
                recommendedCell.style.color = new StyleColor(GetTextSecondaryColor());
                row.Add(recommendedCell);

                row.Add(BuildStatusChip(status));
                return row;
            }
        }

        private static VisualElement BuildRenderScaleRow(string label, Func<float> getValue, Action<float> setValue, string recommended, StatusLevel status)
        {
            float current = ClampRenderScale(getValue());
            if (_isNarrowLayout)
            {
                var card = new VisualElement();
                ApplyCardStyle(card);
                card.style.marginTop = 8;

                var title = new Label(label);
                title.style.unityFontStyleAndWeight = FontStyle.Bold;
                title.style.color = new StyleColor(GetTextPrimaryColor());
                card.Add(title);

                var rowTop = new VisualElement();
                rowTop.style.flexDirection = FlexDirection.Row;
                rowTop.style.alignItems = Align.Center;
                rowTop.style.marginTop = 8;
                card.Add(rowTop);

                var slider = new Slider(0f, 2f) { value = current };
                slider.style.flexGrow = 1;
                slider.style.marginRight = 8;

                var field = new FloatField { value = current, formatString = "0.00", isDelayed = true };
                field.style.width = 70;

                var statusChip = BuildStatusChip(status);
                BindRenderScaleControls(slider, field, statusChip, setValue);

                rowTop.Add(slider);
                rowTop.Add(field);
                rowTop.Add(statusChip);

                if (!string.IsNullOrEmpty(recommended))
                {
                    var helper = new Label("Recommended: " + recommended);
                    helper.style.marginTop = 6;
                    helper.style.whiteSpace = WhiteSpace.Normal;
                    helper.style.color = new StyleColor(GetTextSecondaryColor());
                    card.Add(helper);
                }

                return card;
            }
            else
            {
                var row = new VisualElement();
                row.style.flexDirection = FlexDirection.Row;
                row.style.alignItems = Align.Center;
                row.style.paddingTop = 8;
                row.style.paddingBottom = 8;
                row.style.borderBottomWidth = 1;
                row.style.borderBottomColor = new StyleColor(GetSeparatorColor());

                var labelCell = new Label(label);
                labelCell.style.width = 180;
                labelCell.style.color = new StyleColor(GetTextPrimaryColor());
                row.Add(labelCell);

                var controlCell = new VisualElement();
                controlCell.style.flexDirection = FlexDirection.Row;
                controlCell.style.alignItems = Align.Center;
                controlCell.style.width = 180;
                controlCell.style.flexShrink = 0;
                row.Add(controlCell);

                var slider = new Slider(0f, 2f) { value = current };
                slider.style.flexGrow = 1;
                slider.style.flexBasis = 0;
                slider.style.minWidth = 0;
                slider.style.marginRight = 8;

                var field = new FloatField { value = current, formatString = "0.00", isDelayed = true };
                field.style.width = 60;
                field.style.flexShrink = 0;

                var statusChip = BuildStatusChip(status);
                BindRenderScaleControls(slider, field, statusChip, setValue);

                controlCell.Add(slider);
                controlCell.Add(field);

                var recommendedCell = new Label(recommended);
                recommendedCell.style.whiteSpace = WhiteSpace.Normal;
                recommendedCell.style.width = 220;
                recommendedCell.style.color = new StyleColor(GetTextSecondaryColor());
                row.Add(recommendedCell);

                row.Add(statusChip);
                return row;
            }
        }

        private static void BindRenderScaleControls(
            Slider slider,
            FloatField field,
            VisualElement statusChip,
            Action<float> setValue)
        {
            slider.RegisterValueChangedCallback(evt =>
            {
                UpdateRenderScaleControls(slider, field, statusChip, setValue, evt.newValue);
            });
            field.RegisterValueChangedCallback(evt =>
            {
                UpdateRenderScaleControls(slider, field, statusChip, setValue, evt.newValue);
            });
        }

        private static void UpdateRenderScaleControls(
            Slider slider,
            FloatField field,
            VisualElement statusChip,
            Action<float> setValue,
            float value)
        {
            float clampedValue = ClampRenderScale(value);
            slider.SetValueWithoutNotify(clampedValue);
            field.SetValueWithoutNotify(clampedValue);
            setValue(clampedValue);
            UpdateStatusChip(statusChip, EvaluateRenderScaleStatus(clampedValue));
        }

        private static VisualElement BuildToggleRow(string label, Func<bool> getValue, Action<bool> setValue, string impact, StatusLevel status)
        {
            var toggle = new Toggle { value = getValue() };
            toggle.RegisterValueChangedCallback(evt =>
            {
                setValue(evt.newValue);
                NormalizeConfigForSelection(autoConfigure: false);
                RequestRebuild();
            });

            if (_isNarrowLayout)
            {
                var card = new VisualElement();
                ApplyCardStyle(card);
                card.style.marginTop = 8;

                var title = new Label(label);
                title.style.unityFontStyleAndWeight = FontStyle.Bold;
                title.style.color = new StyleColor(GetTextPrimaryColor());
                card.Add(title);

                var rowTop = new VisualElement();
                rowTop.style.flexDirection = FlexDirection.Row;
                rowTop.style.alignItems = Align.Center;
                rowTop.style.marginTop = 8;
                card.Add(rowTop);

                toggle.style.flexGrow = 1;
                toggle.style.marginRight = 8;
                rowTop.Add(toggle);
                rowTop.Add(BuildStatusChip(status));

                var helper = new Label("Impact: " + impact);
                helper.style.marginTop = 6;
                helper.style.color = new StyleColor(GetTextSecondaryColor());
                card.Add(helper);

                return card;
            }
            else
            {
                var row = new VisualElement();
                row.style.flexDirection = FlexDirection.Row;
                row.style.alignItems = Align.Center;
                row.style.paddingTop = 8;
                row.style.paddingBottom = 8;
                row.style.borderBottomWidth = 1;
                row.style.borderBottomColor = new StyleColor(GetSeparatorColor());

                var labelCell = new Label(label);
                labelCell.style.width = 180;
                labelCell.style.color = new StyleColor(GetTextPrimaryColor());
                row.Add(labelCell);

                toggle.style.width = 180;
                row.Add(toggle);

                var impactCell = new Label("Impact: " + impact);
                impactCell.style.width = 220;
                impactCell.style.color = new StyleColor(GetTextSecondaryColor());
                row.Add(impactCell);

                row.Add(BuildStatusChip(status));
                return row;
            }
        }

        private static VisualElement BuildEnumRow(string label, List<string> options, Func<string> getValue, Action<string> setValue)
        {
            string current = getValue();
            if (!options.Contains(current) && options.Count > 0)
            {
                current = options[0];
                setValue(current);
            }

            var popup = new PopupField<string>(options, current);
            popup.RegisterValueChangedCallback(evt =>
            {
                setValue(evt.newValue);
                NormalizeConfigForSelection(autoConfigure: false);
                RequestRebuild();
            });

            if (_isNarrowLayout)
            {
                var card = new VisualElement();
                ApplyCardStyle(card);
                card.style.marginTop = 8;

                var title = new Label(label);
                title.style.unityFontStyleAndWeight = FontStyle.Bold;
                title.style.color = new StyleColor(GetTextPrimaryColor());
                card.Add(title);

                var rowTop = new VisualElement();
                rowTop.style.flexDirection = FlexDirection.Row;
                rowTop.style.alignItems = Align.Center;
                rowTop.style.marginTop = 8;
                card.Add(rowTop);

                popup.style.flexGrow = 1;
                rowTop.Add(popup);

                return card;
            }
            else
            {
                var row = new VisualElement();
                row.style.flexDirection = FlexDirection.Row;
                row.style.alignItems = Align.Center;
                row.style.paddingTop = 8;
                row.style.paddingBottom = 8;
                row.style.borderBottomWidth = 1;
                row.style.borderBottomColor = new StyleColor(GetSeparatorColor());

                var labelCell = new Label(label);
                labelCell.style.width = 180;
                labelCell.style.color = new StyleColor(GetTextPrimaryColor());
                row.Add(labelCell);

                popup.style.width = 180;
                row.Add(popup);

                return row;
            }
        }

        private static VisualElement BuildStatusChip(StatusLevel status)
        {
            var chip = new VisualElement();
            chip.style.flexDirection = FlexDirection.Row;
            chip.style.alignItems = Align.Center;
            chip.style.justifyContent = Justify.Center;
            chip.style.paddingLeft = 8;
            chip.style.paddingRight = 8;
            chip.style.paddingTop = 3;
            chip.style.paddingBottom = 3;
            chip.style.borderTopLeftRadius = 10;
            chip.style.borderTopRightRadius = 10;
            chip.style.borderBottomLeftRadius = 10;
            chip.style.borderBottomRightRadius = 10;
            chip.style.borderTopWidth = 1;
            chip.style.borderBottomWidth = 1;
            chip.style.borderLeftWidth = 1;
            chip.style.borderRightWidth = 1;

            var dot = new VisualElement { name = "status-dot" };
            dot.style.width = 6;
            dot.style.height = 6;
            dot.style.borderTopLeftRadius = 3;
            dot.style.borderTopRightRadius = 3;
            dot.style.borderBottomLeftRadius = 3;
            dot.style.borderBottomRightRadius = 3;
            dot.style.marginRight = 6;
            chip.Add(dot);

            var text = new Label { name = "status-text" };
            text.style.color = new StyleColor(GetTextPrimaryColor());
            chip.Add(text);

            chip.style.width = 120;
            UpdateStatusChip(chip, status);
            return chip;
        }

        private static void UpdateStatusChip(VisualElement chip, StatusLevel status)
        {
            Color color = StatusColor(status);
            chip.style.borderTopColor = new StyleColor(color);
            chip.style.borderBottomColor = new StyleColor(color);
            chip.style.borderLeftColor = new StyleColor(color);
            chip.style.borderRightColor = new StyleColor(color);
            chip.style.backgroundColor = new StyleColor(new Color(
                color.r,
                color.g,
                color.b,
                EditorGUIUtility.isProSkin ? 0.16f : 0.10f));

            VisualElement dot = chip.Q<VisualElement>("status-dot");
            if (dot != null)
            {
                dot.style.backgroundColor = new StyleColor(color);
            }

            Label text = chip.Q<Label>("status-text");
            if (text != null)
            {
                text.text = StatusText(status);
            }
        }

        private static VisualElement BuildSummaryCard()
        {
            var box = new VisualElement();
            box.style.marginTop = 10;
            ApplyCardStyle(box);

            var title = new Label("Current Configuration");
            title.style.unityFontStyleAndWeight = FontStyle.Bold;
            title.style.fontSize = 14;
            title.style.color = new StyleColor(GetTextPrimaryColor());
            box.Add(title);

            box.Add(new Label($"Render Scale: {FormatRenderScale(ActiveDeviceConfig.renderScale)}"));
            box.Add(new Label($"Refresh Rate: {ActiveDeviceConfig.refreshRate}"));
            box.Add(new Label($"Foveated Rendering: {ActiveDeviceConfig.foveation}"));
            box.Add(new Label($"Super Resolution: {(ActiveDeviceConfig.superResolution ? "On" : "Off")}"));
            box.Add(new Label($"Sharpening Mode: {ActiveDeviceConfig.sharpeningMode}"));
            box.Add(new Label($"Sharpening Enhance Mode: {ActiveDeviceConfig.sharpeningEnhance}"));
            box.Add(new Label($"HDR: {(ActiveDeviceConfig.hdr ? "On" : "Off")}"));
            box.Add(new Label($"Adaptive Resolution: {(ActiveDeviceConfig.adaptiveResolution ? "On" : "Off")}"));

            return box;
        }

        private static VisualElement BuildDevicePreviewCard(DeviceProfile profile)
        {
            DeviceTemplate t = Templates[profile];
            PXR_PerformancePackDeviceConfig config = GetDeviceConfig(profile);

            var box = new VisualElement();
            box.style.marginTop = 10;
            ApplyCardStyle(box);

            var title = new Label("Device: " + t.displayName);
            title.style.unityFontStyleAndWeight = FontStyle.Bold;
            title.style.fontSize = 14;
            title.style.color = new StyleColor(GetTextPrimaryColor());
            box.Add(title);

            box.Add(BuildDeviceLine("Render Scale", FormatRenderScale(config.renderScale), FormatRenderScale(t.recommendedRenderScale), true));
            box.Add(BuildDeviceLine("Refresh Rate", config.refreshRate, t.recommendedRefreshRate, t.refreshRates.Contains(config.refreshRate)));
            box.Add(BuildDeviceLine("Foveated Rendering", config.foveation, t.recommendedFoveation, t.foveations.Contains(config.foveation)));
            box.Add(BuildDeviceLine("Super Resolution", config.superResolution ? "On" : "Off", t.superResolutionRecommended ? "On" : "Off", t.superResolutionSupported || !config.superResolution));
            box.Add(BuildDeviceLine("Sharpening Mode", (config.superResolution ? SharpeningMode.None : config.sharpeningMode).ToString(), SharpeningMode.None.ToString(), true));
            box.Add(BuildDeviceLine("Sharpening Enhance Mode", (config.superResolution || config.sharpeningMode == SharpeningMode.None ? SharpeningEnhance.None : config.sharpeningEnhance).ToString(), SharpeningEnhance.None.ToString(), true));
            box.Add(BuildDeviceLine("HDR", config.hdr ? "On" : "Off", t.hdrRecommended ? "On" : "Off", t.hdrSupported || !config.hdr));
            box.Add(BuildDeviceLine("Adaptive Resolution", config.adaptiveResolution ? "On" : "Off", t.adaptiveResolutionRecommended ? "On" : "Off", t.adaptiveResolutionSupported || !config.adaptiveResolution));

            return box;
        }

        private static VisualElement BuildDeviceLine(string label, string current, string recommended, bool supported)
        {
            StatusLevel status;
            if (!supported)
            {
                status = StatusLevel.Unsupported;
            }
            else if (current == recommended)
            {
                status = StatusLevel.Recommended;
            }
            else
            {
                status = StatusLevel.Custom;
            }

            var row = new VisualElement();
            row.style.flexDirection = FlexDirection.Row;
            row.style.alignItems = Align.Center;
            row.style.marginTop = 4;

            var left = new Label($"{label}：{current}");
            left.style.width = _isNarrowLayout ? 220 : 320;
            left.style.color = new StyleColor(GetTextPrimaryColor());
            row.Add(left);

            var mid = new Label($"Recommended: {recommended}");
            mid.style.width = _isNarrowLayout ? 180 : 220;
            mid.style.color = new StyleColor(GetTextSecondaryColor());
            row.Add(mid);

            row.Add(BuildStatusChip(status));

            return row;
        }
    }
}
#endif
