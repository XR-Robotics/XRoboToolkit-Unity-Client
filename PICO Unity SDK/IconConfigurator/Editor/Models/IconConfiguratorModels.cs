using System;
using System.Collections.Generic;
using UnityEngine;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    public enum IconConfiguratorMode
    {
        Manual,
        AiSplit,
    }

    public enum IconLayerKind
    {
        Background,
        Foreground1,
        Foreground2,
        FlatSource,
    }

    public enum GenerateStatus
    {
        Idle,
        Ready,
        Running,
        Succeeded,
        Failed,
        Cancelled,
    }

    public enum AiSplitErrorType
    {
        None,
        Configuration,
        TccNotConfigured,
        TccFetchFailed,
        TccDisabled,
        TccRegionMissing,
        TccFieldMissing,
        Network,
        Timeout,
        Cancelled,
        RateLimited,
        Upload,
        Download,
        Service,
        InvalidResponse,
        Unknown,
    }

    [Serializable]
    public class AiSplitTccConfig
    {
        [SerializeField] private bool m_enable;
        [SerializeField] private List<AiSplitRegionConfig> m_regions = new List<AiSplitRegionConfig>();
        [SerializeField] private AiSplitTimeoutConfig m_timeouts = new AiSplitTimeoutConfig();
        [SerializeField] private AiSplitApiConfig m_api = new AiSplitApiConfig();
        [SerializeField] private AiSplitTosConfig m_tos = new AiSplitTosConfig();
        [SerializeField] private AiSplitSigningConfig m_signing = new AiSplitSigningConfig();

        public bool Enable
        {
            get => m_enable;
            set => m_enable = value;
        }

        public List<AiSplitRegionConfig> Regions
        {
            get => m_regions;
            set => m_regions = value ?? new List<AiSplitRegionConfig>();
        }

        public AiSplitTimeoutConfig Timeouts
        {
            get => m_timeouts;
            set => m_timeouts = value ?? new AiSplitTimeoutConfig();
        }

        public AiSplitApiConfig Api
        {
            get => m_api;
            set => m_api = value ?? new AiSplitApiConfig();
        }

        public AiSplitTosConfig Tos
        {
            get => m_tos;
            set => m_tos = value ?? new AiSplitTosConfig();
        }

        public AiSplitSigningConfig Signing
        {
            get => m_signing;
            set => m_signing = value ?? new AiSplitSigningConfig();
        }
    }

    [Serializable]
    public class AiSplitRegionConfig
    {
        [SerializeField] private string m_region = string.Empty;
        [SerializeField] private string m_apiBaseUrl = string.Empty;
        [SerializeField] private string m_tccKey = string.Empty;
        [SerializeField] private string m_ttEnv = string.Empty;
        [SerializeField] private bool m_usePpe;
        [SerializeField] private string m_generateUrl = string.Empty;
        [SerializeField] private string m_infoUrl = string.Empty;
        [SerializeField] private string m_appId = string.Empty;
        [SerializeField] private string m_salt = string.Empty;

        public string Region
        {
            get => m_region;
            set => m_region = value ?? string.Empty;
        }

        public string ApiBaseUrl
        {
            get => m_apiBaseUrl;
            set => m_apiBaseUrl = value ?? string.Empty;
        }

        public string TccKey
        {
            get => m_tccKey;
            set => m_tccKey = value ?? string.Empty;
        }

        public string TtEnv
        {
            get => m_ttEnv;
            set => m_ttEnv = value ?? string.Empty;
        }

        public bool UsePpe
        {
            get => m_usePpe;
            set => m_usePpe = value;
        }

        public string GenerateUrl
        {
            get => m_generateUrl;
            set => m_generateUrl = value ?? string.Empty;
        }

        public string InfoUrl
        {
            get => m_infoUrl;
            set => m_infoUrl = value ?? string.Empty;
        }

        public string AppId
        {
            get => m_appId;
            set => m_appId = value ?? string.Empty;
        }

        public string Salt
        {
            get => m_salt;
            set => m_salt = value ?? string.Empty;
        }
    }

    [Serializable]
    public class AiSplitTimeoutConfig
    {
        [SerializeField] private int m_connectTimeoutSeconds = 3;
        [SerializeField] private int m_readTimeoutSeconds = 30;
        [SerializeField] private int m_pollIntervalSeconds = 2;
        [SerializeField] private int m_totalTimeoutSeconds = 300;

        public int ConnectTimeoutSeconds
        {
            get => m_connectTimeoutSeconds;
            set => m_connectTimeoutSeconds = Mathf.Max(0, value);
        }

        public int ReadTimeoutSeconds
        {
            get => m_readTimeoutSeconds;
            set => m_readTimeoutSeconds = Mathf.Max(0, value);
        }

        public int PollIntervalSeconds
        {
            get => m_pollIntervalSeconds;
            set => m_pollIntervalSeconds = Mathf.Max(0, value);
        }

        public int TotalTimeoutSeconds
        {
            get => m_totalTimeoutSeconds;
            set => m_totalTimeoutSeconds = Mathf.Max(0, value);
        }
    }

    [Serializable]
    public class AiSplitApiConfig
    {
        [SerializeField] private string m_generatePath = "/sdf/gen";
        [SerializeField] private string m_infoPath = "/sdf/info";

        public string GeneratePath
        {
            get => m_generatePath;
            set => m_generatePath = value ?? string.Empty;
        }

        public string InfoPath
        {
            get => m_infoPath;
            set => m_infoPath = value ?? string.Empty;
        }
    }

    [Serializable]
    public class AiSplitTosConfig
    {
        [SerializeField] private string m_bucketName = string.Empty;
        [SerializeField] private string m_objectDirectory = string.Empty;
        [SerializeField] private string m_publicBaseUrl = string.Empty;

        public string BucketName
        {
            get => m_bucketName;
            set => m_bucketName = value ?? string.Empty;
        }

        public string ObjectDirectory
        {
            get => m_objectDirectory;
            set => m_objectDirectory = value ?? string.Empty;
        }

        public string PublicBaseUrl
        {
            get => m_publicBaseUrl;
            set => m_publicBaseUrl = value ?? string.Empty;
        }
    }

    [Serializable]
    public class AiSplitSigningConfig
    {
        [SerializeField] private string m_appId = string.Empty;
        [SerializeField] private string m_salt = string.Empty;

        public string AppId
        {
            get => m_appId;
            set => m_appId = value ?? string.Empty;
        }

        public string Salt
        {
            get => m_salt;
            set => m_salt = value ?? string.Empty;
        }
    }

    [Serializable]
    public class AiSplitGenerateResponse
    {
        [SerializeField] private int m_code;
        [SerializeField] private string m_message = string.Empty;
        [SerializeField] private string m_requestId = string.Empty;
        [SerializeField] private AiSplitGenerateData m_data = new AiSplitGenerateData();

        public int Code
        {
            get => m_code;
            set => m_code = value;
        }

        public string Message
        {
            get => m_message;
            set => m_message = value ?? string.Empty;
        }

        public string RequestId
        {
            get => m_requestId;
            set => m_requestId = value ?? string.Empty;
        }

        public AiSplitGenerateData Data
        {
            get => m_data;
            set => m_data = value ?? new AiSplitGenerateData();
        }
    }

    [Serializable]
    public class AiSplitGenerateData
    {
        [SerializeField] private string m_taskId = string.Empty;

        public string TaskId
        {
            get => m_taskId;
            set => m_taskId = value ?? string.Empty;
        }
    }

    [Serializable]
    public class AiSplitInfoResponse
    {
        [SerializeField] private int m_code;
        [SerializeField] private string m_message = string.Empty;
        [SerializeField] private string m_requestId = string.Empty;
        [SerializeField] private AiSplitInfoData m_data = new AiSplitInfoData();

        public int Code
        {
            get => m_code;
            set => m_code = value;
        }

        public string Message
        {
            get => m_message;
            set => m_message = value ?? string.Empty;
        }

        public string RequestId
        {
            get => m_requestId;
            set => m_requestId = value ?? string.Empty;
        }

        public AiSplitInfoData Data
        {
            get => m_data;
            set => m_data = value ?? new AiSplitInfoData();
        }
    }

    [Serializable]
    public class AiSplitInfoData
    {
        [SerializeField] private string m_taskId = string.Empty;
        [SerializeField] private int m_progress;
        [SerializeField] private string m_modelVersion = string.Empty;
        [SerializeField] private List<AiSplitRemoteAsset> m_layers = new List<AiSplitRemoteAsset>();
        [SerializeField] private List<AiSplitRemoteAsset> m_sdfs = new List<AiSplitRemoteAsset>();
        [SerializeField] private AiSplitErrorType m_errorType;
        [SerializeField] private string m_errorMessage = string.Empty;

        public string TaskId
        {
            get => m_taskId;
            set => m_taskId = value ?? string.Empty;
        }

        public int Progress
        {
            get => m_progress;
            set => m_progress = Mathf.Clamp(value, 0, 100);
        }

        public string ModelVersion
        {
            get => m_modelVersion;
            set => m_modelVersion = value ?? string.Empty;
        }

        public List<AiSplitRemoteAsset> Layers
        {
            get => m_layers;
            set => m_layers = value ?? new List<AiSplitRemoteAsset>();
        }

        public List<AiSplitRemoteAsset> Sdfs
        {
            get => m_sdfs;
            set => m_sdfs = value ?? new List<AiSplitRemoteAsset>();
        }

        public AiSplitErrorType ErrorType
        {
            get => m_errorType;
            set => m_errorType = value;
        }

        public string ErrorMessage
        {
            get => m_errorMessage;
            set => m_errorMessage = value ?? string.Empty;
        }
    }

    [Serializable]
    public class AiSplitRemoteAsset
    {
        [SerializeField] private string m_url = string.Empty;
        [SerializeField] private string m_md5 = string.Empty;

        public string Url
        {
            get => m_url;
            set => m_url = value ?? string.Empty;
        }

        public string Md5
        {
            get => m_md5;
            set => m_md5 = value ?? string.Empty;
        }
    }

    [Serializable]
    public class IconLayerConfig
    {
        [SerializeField] private IconLayerKind m_layerKind;
        [SerializeField] private string m_assetGuid = string.Empty;
        [SerializeField] private string m_assetPath = string.Empty;
        [SerializeField] private string m_originalFileName = string.Empty;
        [SerializeField] private string m_contentHash = string.Empty;
        [SerializeField] private string m_displayName = string.Empty;
        [SerializeField] private int m_sourceWidth;
        [SerializeField] private int m_sourceHeight;
        [NonSerialized] private Texture2D m_texture;

        public IconLayerKind LayerKind
        {
            get => m_layerKind;
            set => m_layerKind = value;
        }

        public string AssetGuid
        {
            get => m_assetGuid;
            set => m_assetGuid = value ?? string.Empty;
        }

        public string AssetPath
        {
            get => m_assetPath;
            set => m_assetPath = value ?? string.Empty;
        }

        public string OriginalFileName
        {
            get => m_originalFileName;
            set => m_originalFileName = value ?? string.Empty;
        }

        public string ContentHash
        {
            get => m_contentHash;
            set => m_contentHash = value ?? string.Empty;
        }

        public string DisplayName
        {
            get => m_displayName;
            set => m_displayName = value ?? string.Empty;
        }

        public int SourceWidth
        {
            get => m_sourceWidth;
            set => m_sourceWidth = Mathf.Max(0, value);
        }

        public int SourceHeight
        {
            get => m_sourceHeight;
            set => m_sourceHeight = Mathf.Max(0, value);
        }

        public Texture2D Texture
        {
            get => m_texture;
            set => m_texture = value;
        }

        public bool HasAssetReference => !string.IsNullOrWhiteSpace(m_assetGuid) && !string.IsNullOrWhiteSpace(m_assetPath);
    }

    [Serializable]
    public class ManualLayerState
    {
        public const int MinLayerCount = 2;
        public const int MaxLayerCount = 3;

        [SerializeField] private List<IconLayerConfig> m_layers = CreateDefaultLayers();

        public List<IconLayerConfig> Layers
        {
            get => EnsureLayerList();
            set => m_layers = NormalizeLayers(value, false);
        }

        public IconLayerConfig Background
        {
            get => GetLayerAt(0);
            set => SetLayerAt(0, value, IconLayerKind.Background);
        }

        public IconLayerConfig Foreground1
        {
            get => GetLayerAt(1);
            set => SetLayerAt(1, value, IconLayerKind.Foreground1);
        }

        public IconLayerConfig Foreground2
        {
            get => GetLayerAt(2);
            set => SetLayerAt(2, value, IconLayerKind.Foreground2);
        }

        public IconLayerConfig GetLayerAt(int index)
        {
            List<IconLayerConfig> layers = EnsureLayerList();
            return index >= 0 && index < layers.Count ? layers[index] : null;
        }

        public void SetLayerAt(int index, IconLayerConfig layer)
        {
            SetLayerAt(index, layer, GetDefaultLayerKind(index));
        }

        public void AddEmptyLayer()
        {
            List<IconLayerConfig> layers = EnsureLayerList();
            if (layers.Count >= MaxLayerCount)
            {
                return;
            }

            layers.Add(CreateEmptyLayerForIndex(layers.Count));
        }

        public bool RemoveLayerAt(int index)
        {
            List<IconLayerConfig> layers = EnsureLayerList();
            if (layers.Count <= MinLayerCount || index < 0 || index >= layers.Count)
            {
                return false;
            }

            layers.RemoveAt(index);
            NormalizeExistingLayers(layers);
            return true;
        }

        public bool MoveLayer(int fromIndex, int toIndex)
        {
            List<IconLayerConfig> layers = EnsureLayerList();
            if (fromIndex < 0 || fromIndex >= layers.Count || toIndex < 0 || toIndex >= layers.Count || fromIndex == toIndex)
            {
                return false;
            }

            IconLayerConfig layer = layers[fromIndex];
            layers.RemoveAt(fromIndex);
            layers.Insert(toIndex, layer);
            NormalizeExistingLayers(layers);
            return true;
        }

        public static string GetDisplayNameForIndex(int index)
        {
            return IconLayerNaming.GetDisplayName(index);
        }

        private static List<IconLayerConfig> CreateDefaultLayers()
        {
            return new List<IconLayerConfig>
            {
                CreateEmptyLayerForIndex(0),
                CreateEmptyLayerForIndex(1),
            };
        }

        private static IconLayerConfig CreateEmptyLayerForIndex(int index)
        {
            return new IconLayerConfig
            {
                LayerKind = GetDefaultLayerKind(index),
                DisplayName = GetDisplayNameForIndex(index),
            };
        }

        private List<IconLayerConfig> EnsureLayerList()
        {
            m_layers = NormalizeLayers(m_layers, true);
            return m_layers;
        }

        private static List<IconLayerConfig> NormalizeLayers(List<IconLayerConfig> layers, bool useDefaultWhenEmpty)
        {
            if (layers == null || layers.Count == 0)
            {
                return useDefaultWhenEmpty ? CreateDefaultLayers() : new List<IconLayerConfig>();
            }

            List<IconLayerConfig> normalized = new List<IconLayerConfig>(Mathf.Min(MaxLayerCount, layers.Count));
            for (int i = 0; i < layers.Count && normalized.Count < MaxLayerCount; i++)
            {
                IconLayerConfig layer = layers[i] ?? CreateEmptyLayerForIndex(i);
                layer.LayerKind = GetDefaultLayerKind(i);
                layer.DisplayName = string.IsNullOrWhiteSpace(layer.DisplayName)
                    ? GetDisplayNameForIndex(i)
                    : layer.DisplayName;
                normalized.Add(layer);
            }

            return normalized;
        }

        private static void NormalizeExistingLayers(List<IconLayerConfig> layers)
        {
            for (int i = 0; i < layers.Count; i++)
            {
                if (layers[i] == null)
                {
                    layers[i] = CreateEmptyLayerForIndex(i);
                    continue;
                }

                layers[i].LayerKind = GetDefaultLayerKind(i);
                if (string.IsNullOrWhiteSpace(layers[i].DisplayName))
                {
                    layers[i].DisplayName = GetDisplayNameForIndex(i);
                }
            }
        }

        private void SetLayerAt(int index, IconLayerConfig layer, IconLayerKind layerKind)
        {
            List<IconLayerConfig> layers = EnsureLayerList();
            while (layers.Count <= index && layers.Count < MaxLayerCount)
            {
                layers.Add(CreateEmptyLayerForIndex(layers.Count));
            }

            if (index < 0 || index >= layers.Count)
            {
                return;
            }

            IconLayerConfig normalized = layer ?? CreateEmptyLayerForIndex(index);
            normalized.LayerKind = layerKind;
            normalized.DisplayName = string.IsNullOrWhiteSpace(normalized.DisplayName)
                ? GetDisplayNameForIndex(index)
                : normalized.DisplayName;
            layers[index] = normalized;
        }

        private static IconLayerKind GetDefaultLayerKind(int index)
        {
            return IconLayerNaming.GetLayerKind(index);
        }
    }

    [Serializable]
    public class AiSplitState
    {
        [SerializeField] private IconLayerConfig m_flatSource = new IconLayerConfig
        {
            LayerKind = IconLayerKind.FlatSource,
        };

        [SerializeField] private IconLayerConfig m_background = new IconLayerConfig
        {
            LayerKind = IconLayerKind.Background,
        };

        [SerializeField] private IconLayerConfig m_foreground1 = new IconLayerConfig
        {
            LayerKind = IconLayerKind.Foreground1,
        };

        [SerializeField] private IconLayerConfig m_foreground2 = new IconLayerConfig
        {
            LayerKind = IconLayerKind.Foreground2,
        };

        [SerializeField] private bool m_hasAcceptedTerms;
        [SerializeField] private GenerateStatus m_status;
        [SerializeField] private string m_errorMessage = string.Empty;
        [SerializeField] private AiSplitErrorType m_errorType;
        [SerializeField] private string m_taskId = string.Empty;
        [SerializeField] private string m_requestId = string.Empty;
        [SerializeField] private string m_modelVersion = string.Empty;
        [SerializeField] private string m_generatedAt = string.Empty;
        [SerializeField] private List<IconLayerConfig> m_generatedLayers = new List<IconLayerConfig>();
        [SerializeField] private List<IconLayerConfig> m_generatedSdfs = new List<IconLayerConfig>();

        public IconLayerConfig FlatSource
        {
            get => m_flatSource;
            set => m_flatSource = value ?? new IconLayerConfig { LayerKind = IconLayerKind.FlatSource };
        }

        public IconLayerConfig Background
        {
            get => m_background;
            set => m_background = value ?? new IconLayerConfig { LayerKind = IconLayerKind.Background };
        }

        public IconLayerConfig Foreground1
        {
            get => m_foreground1;
            set => m_foreground1 = value ?? new IconLayerConfig { LayerKind = IconLayerKind.Foreground1 };
        }

        public IconLayerConfig Foreground2
        {
            get => m_foreground2;
            set => m_foreground2 = value ?? new IconLayerConfig { LayerKind = IconLayerKind.Foreground2 };
        }

        public bool HasAcceptedTerms
        {
            get => m_hasAcceptedTerms;
            set => m_hasAcceptedTerms = value;
        }

        public GenerateStatus Status
        {
            get => m_status;
            set => m_status = value;
        }

        public string ErrorMessage
        {
            get => m_errorMessage;
            set => m_errorMessage = value ?? string.Empty;
        }

        public AiSplitErrorType ErrorType
        {
            get => m_errorType;
            set => m_errorType = value;
        }

        public string TaskId
        {
            get => m_taskId;
            set => m_taskId = value ?? string.Empty;
        }

        public string RequestId
        {
            get => m_requestId;
            set => m_requestId = value ?? string.Empty;
        }

        public string ModelVersion
        {
            get => m_modelVersion;
            set => m_modelVersion = value ?? string.Empty;
        }

        public string GeneratedAt
        {
            get => m_generatedAt;
            set => m_generatedAt = value ?? string.Empty;
        }

        public List<IconLayerConfig> GeneratedLayers
        {
            get
            {
                EnsureDynamicResultLists();
                return m_generatedLayers;
            }
            set => m_generatedLayers = value ?? new List<IconLayerConfig>();
        }

        public List<IconLayerConfig> GeneratedSdfs
        {
            get
            {
                EnsureDynamicResultLists();
                return m_generatedSdfs;
            }
            set => m_generatedSdfs = value ?? new List<IconLayerConfig>();
        }

        public void EnsureDynamicResultLists()
        {
            m_generatedLayers ??= new List<IconLayerConfig>();
            m_generatedSdfs ??= new List<IconLayerConfig>();

            if (m_generatedLayers.Count == 0)
            {
                AddLegacyLayerIfValid(m_generatedLayers, m_background);
                AddLegacyLayerIfValid(m_generatedLayers, m_foreground1);
                AddLegacyLayerIfValid(m_generatedLayers, m_foreground2);
            }
        }

        private static void AddLegacyLayerIfValid(List<IconLayerConfig> layers, IconLayerConfig layer)
        {
            if (layer?.HasAssetReference == true)
            {
                layers.Add(layer);
            }
        }
    }

    [Serializable]
    public class LocalizationEntry
    {
        [SerializeField] private string m_localeCode = string.Empty;
        [SerializeField] private string m_appName = string.Empty;
        [SerializeField] private bool m_isDefault;
        [SerializeField] private bool m_canRemove = true;

        public string LocaleCode
        {
            get => m_localeCode;
            set => m_localeCode = value ?? string.Empty;
        }

        public string AppName
        {
            get => m_appName;
            set => m_appName = value ?? string.Empty;
        }

        public bool IsDefault
        {
            get => m_isDefault;
            set => m_isDefault = value;
        }

        public bool CanRemove
        {
            get => m_canRemove;
            set => m_canRemove = value;
        }
    }

    [Serializable]
    public class IconAiSplitResult
    {
        [SerializeField] private IconLayerConfig m_background;
        [SerializeField] private IconLayerConfig m_foreground1;
        [SerializeField] private IconLayerConfig m_foreground2;
        [SerializeField] private List<IconLayerConfig> m_layers = new List<IconLayerConfig>();
        [SerializeField] private List<IconLayerConfig> m_sdfs = new List<IconLayerConfig>();
        [SerializeField] private string m_taskId = string.Empty;
        [SerializeField] private string m_requestId = string.Empty;
        [SerializeField] private string m_modelVersion = string.Empty;
        [SerializeField] private string m_generatedAt = string.Empty;
        [SerializeField] private AiSplitErrorType m_errorType;

        public IconLayerConfig Background
        {
            get => m_background;
            set => m_background = value;
        }

        public IconLayerConfig Foreground1
        {
            get => m_foreground1;
            set => m_foreground1 = value;
        }

        public IconLayerConfig Foreground2
        {
            get => m_foreground2;
            set => m_foreground2 = value;
        }

        public List<IconLayerConfig> Layers
        {
            get
            {
                EnsureDynamicLists();
                return m_layers;
            }
            set => m_layers = value ?? new List<IconLayerConfig>();
        }

        public List<IconLayerConfig> Sdfs
        {
            get
            {
                EnsureDynamicLists();
                return m_sdfs;
            }
            set => m_sdfs = value ?? new List<IconLayerConfig>();
        }

        public string TaskId
        {
            get => m_taskId;
            set => m_taskId = value ?? string.Empty;
        }

        public string RequestId
        {
            get => m_requestId;
            set => m_requestId = value ?? string.Empty;
        }

        public string ModelVersion
        {
            get => m_modelVersion;
            set => m_modelVersion = value ?? string.Empty;
        }

        public string GeneratedAt
        {
            get => m_generatedAt;
            set => m_generatedAt = value ?? string.Empty;
        }

        public AiSplitErrorType ErrorType
        {
            get => m_errorType;
            set => m_errorType = value;
        }

        public void EnsureDynamicLists()
        {
            m_layers ??= new List<IconLayerConfig>();
            m_sdfs ??= new List<IconLayerConfig>();

            if (m_layers.Count == 0)
            {
                AddLegacyLayerIfValid(m_layers, m_background);
                AddLegacyLayerIfValid(m_layers, m_foreground1);
                AddLegacyLayerIfValid(m_layers, m_foreground2);
            }
        }

        private static void AddLegacyLayerIfValid(List<IconLayerConfig> layers, IconLayerConfig layer)
        {
            if (layer?.HasAssetReference == true)
            {
                layers.Add(layer);
            }
        }
    }

    [Serializable]
    public class IconApplyPayload
    {
        [SerializeField] private string m_configGuid = string.Empty;
        [SerializeField] private string m_outputRootPath = string.Empty;
        [SerializeField] private string m_layersOutputPath = string.Empty;
        [SerializeField] private string m_previewOutputPath = string.Empty;
        [SerializeField] private string m_metadataOutputPath = string.Empty;
        [SerializeField] private string m_androidResRootPath = string.Empty;
        [SerializeField] private List<LocalizationEntry> m_localizations = new List<LocalizationEntry>();
        [SerializeField] private List<IconLayerConfig> m_layers = new List<IconLayerConfig>();
        [SerializeField] private List<IconLayerConfig> m_sdfLayers = new List<IconLayerConfig>();
        [SerializeField] private bool m_useCloudSdfs;
        [SerializeField] private IconLayerConfig m_background;
        [SerializeField] private IconLayerConfig m_foreground1;
        [SerializeField] private IconLayerConfig m_foreground2;
        [NonSerialized] private Texture2D m_previewTexture;

        public string ConfigGuid
        {
            get => m_configGuid;
            set => m_configGuid = value ?? string.Empty;
        }

        public string OutputRootPath
        {
            get => m_outputRootPath;
            set => m_outputRootPath = value ?? string.Empty;
        }

        public string LayersOutputPath
        {
            get => m_layersOutputPath;
            set => m_layersOutputPath = value ?? string.Empty;
        }

        public string PreviewOutputPath
        {
            get => m_previewOutputPath;
            set => m_previewOutputPath = value ?? string.Empty;
        }

        public string MetadataOutputPath
        {
            get => m_metadataOutputPath;
            set => m_metadataOutputPath = value ?? string.Empty;
        }

        public string AndroidResRootPath
        {
            get => m_androidResRootPath;
            set => m_androidResRootPath = value ?? string.Empty;
        }

        public List<LocalizationEntry> Localizations
        {
            get => m_localizations;
            set => m_localizations = value ?? new List<LocalizationEntry>();
        }

        public List<IconLayerConfig> Layers
        {
            get => m_layers;
            set => m_layers = value ?? new List<IconLayerConfig>();
        }

        public List<IconLayerConfig> SdfLayers
        {
            get => m_sdfLayers;
            set => m_sdfLayers = value ?? new List<IconLayerConfig>();
        }

        public bool UseCloudSdfs
        {
            get => m_useCloudSdfs;
            set => m_useCloudSdfs = value;
        }

        public IconLayerConfig Background
        {
            get => m_background ?? GetLayerAt(0);
            set => m_background = value;
        }

        public IconLayerConfig Foreground1
        {
            get => m_foreground1 ?? GetLayerAt(1);
            set => m_foreground1 = value;
        }

        public IconLayerConfig Foreground2
        {
            get => m_foreground2 ?? GetLayerAt(2);
            set => m_foreground2 = value;
        }

        public Texture2D PreviewTexture
        {
            get => m_previewTexture;
            set => m_previewTexture = value;
        }

        private IconLayerConfig GetLayerAt(int index)
        {
            return m_layers != null && index >= 0 && index < m_layers.Count ? m_layers[index] : null;
        }
    }

    [Serializable]
    public class IconConfiguratorValidationResult
    {
        [SerializeField] private bool m_canGenerate;
        [SerializeField] private bool m_canApply;
        [NonSerialized] private readonly Dictionary<IconLayerKind, string> m_layerErrors = new Dictionary<IconLayerKind, string>();
        [NonSerialized] private readonly Dictionary<string, string> m_localizationErrors = new Dictionary<string, string>();
        [NonSerialized] private readonly List<string> m_generalErrors = new List<string>();

        public bool CanGenerate
        {
            get => m_canGenerate;
            set => m_canGenerate = value;
        }

        public bool CanApply
        {
            get => m_canApply;
            set => m_canApply = value;
        }

        public Dictionary<IconLayerKind, string> LayerErrors => m_layerErrors;

        public Dictionary<string, string> LocalizationErrors => m_localizationErrors;

        public List<string> GeneralErrors => m_generalErrors;
    }

    [Serializable]
    public class IconApplyPreflightResult
    {
        [SerializeField] private List<string> m_plannedWritePaths = new List<string>();
        [SerializeField] private List<string> m_overwritePaths = new List<string>();
        [SerializeField] private List<string> m_deletePaths = new List<string>();

        public List<string> PlannedWritePaths
        {
            get => m_plannedWritePaths;
            set => m_plannedWritePaths = value ?? new List<string>();
        }

        public List<string> OverwritePaths
        {
            get => m_overwritePaths;
            set => m_overwritePaths = value ?? new List<string>();
        }

        public List<string> DeletePaths
        {
            get => m_deletePaths;
            set => m_deletePaths = value ?? new List<string>();
        }

        public bool RequiresConfirmation => m_overwritePaths.Count > 0 || m_deletePaths.Count > 0;
    }

    [Serializable]
    public class IconApplyResult
    {
        [SerializeField] private List<string> m_writtenPaths = new List<string>();
        [SerializeField] private List<string> m_deletedPaths = new List<string>();
        [SerializeField] private List<string> m_overwrittenPaths = new List<string>();

        public List<string> WrittenPaths
        {
            get => m_writtenPaths;
            set => m_writtenPaths = value ?? new List<string>();
        }

        public List<string> DeletedPaths
        {
            get => m_deletedPaths;
            set => m_deletedPaths = value ?? new List<string>();
        }

        public List<string> OverwrittenPaths
        {
            get => m_overwrittenPaths;
            set => m_overwrittenPaths = value ?? new List<string>();
        }

        public int WrittenFileCount => m_writtenPaths.Count;

        public int DeletedFileCount => m_deletedPaths.Count;

        public int OverwrittenFileCount => m_overwrittenPaths.Count;
    }

}
