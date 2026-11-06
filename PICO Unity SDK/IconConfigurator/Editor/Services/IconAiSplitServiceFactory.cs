using System;
using UnityEditor;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    public sealed class IconAiSplitServiceFactory
    {
        public const string TccPayloadEditorPrefsKey = "IconConfigurator.AiSplit.TccPayload";
        public const string TccPayloadEnvironmentVariable = "ICON_CONFIGURATOR_AI_TCC_PAYLOAD";
        public const string DeviceIdEnvironmentVariable = "ICON_CONFIGURATOR_AI_DID";

        public static event Action GlobalConfigurationRefreshRequested;

        private readonly AiSplitTccManager m_tccManager;
        private readonly IAiSplitTosUploader m_tosUploader;
        private readonly IAiSplitHttpClient m_httpClient;
        private readonly AiSplitDeviceIdProvider m_deviceIdProvider;
        private readonly AiSplitGenerationRateLimiter m_rateLimiter;
        private readonly IAiSplitClock m_clock;
        private readonly IAiSplitDelay m_delay;
        private readonly IAiSplitAssetDownloader m_assetDownloader;

        public IconAiSplitServiceFactory(
            AiSplitTccManager tccManager,
            IAiSplitTosUploader tosUploader,
            IAiSplitHttpClient httpClient,
            AiSplitDeviceIdProvider deviceIdProvider,
            AiSplitGenerationRateLimiter rateLimiter,
            IAiSplitClock clock,
            IAiSplitDelay delay,
            IAiSplitAssetDownloader assetDownloader = null)
        {
            m_tccManager = tccManager ?? throw new ArgumentNullException(nameof(tccManager));
            m_tosUploader = tosUploader ?? throw new ArgumentNullException(nameof(tosUploader));
            m_httpClient = httpClient ?? throw new ArgumentNullException(nameof(httpClient));
            m_deviceIdProvider = deviceIdProvider ?? throw new ArgumentNullException(nameof(deviceIdProvider));
            m_rateLimiter = rateLimiter ?? throw new ArgumentNullException(nameof(rateLimiter));
            m_clock = clock ?? new SystemAiSplitClock();
            m_delay = delay ?? new ThreadAiSplitDelay();
            m_assetDownloader = assetDownloader ?? new AiSplitAssetDownloader();
        }

        public static IconAiSplitServiceFactory CreateDefault()
        {
            SystemAiSplitClock clock = new SystemAiSplitClock();
            AiSplitEnvironmentService environmentService = new AiSplitEnvironmentService();
            Func<string> tccUrlProvider = () => AiSplitTccUrlConstants.GetUrl(environmentService.ResolvePreference());
            IAiSplitTccSource tccSource = new OverrideThenFallbackAiSplitTccSource(
                new EditorPrefsAiSplitTccSource(),
                new DynamicHttpAiSplitTccSource(tccUrlProvider));
            AiSplitTccManager tccManager = new AiSplitTccManager(
                tccSource,
                environmentService.ResolvePreference,
                tccUrlProvider);

            return new IconAiSplitServiceFactory(
                tccManager,
                new AiSplitTosUploader(new UnconfiguredAiSplitTosClient(), () => clock.UnixMilliseconds),
                new AiSplitHttpClient(),
                new AiSplitDeviceIdProvider(() => Environment.GetEnvironmentVariable(DeviceIdEnvironmentVariable)),
                new AiSplitGenerationRateLimiter(() => DateTime.UtcNow),
                clock,
                new ThreadAiSplitDelay());
        }

        public AiSplitTccLoadResult LoadConfiguration(bool forceRefresh = false)
        {
            return m_tccManager.TryLoad(forceRefresh);
        }

        public AiSplitTccLoadResult RefreshConfiguration(bool forceRefresh = true)
        {
            if (forceRefresh)
            {
                m_tccManager.ClearCache();
            }

            return m_tccManager.TryLoad(forceRefresh);
        }

        public void ClearConfigurationCache()
        {
            m_tccManager.ClearCache();
        }

        public AiSplitTccStatus GetConfigurationStatus()
        {
            return m_tccManager.GetStatus();
        }

        public static void RequestGlobalConfigurationRefresh()
        {
            GlobalConfigurationRefreshRequested?.Invoke();
        }

        public IIconAiSplitService CreateService()
        {
            return new RealIconAiSplitService(
                () => LoadConfiguration(),
                m_tosUploader,
                m_httpClient,
                m_deviceIdProvider,
                m_rateLimiter,
                m_clock,
                m_delay,
                m_assetDownloader);
        }

        private sealed class EditorPrefsAiSplitTccSource : IAiSplitTccSource
        {
            public AiSplitTccFetchResult Fetch()
            {
                string payload = EditorPrefs.GetString(TccPayloadEditorPrefsKey, string.Empty);
                if (string.IsNullOrWhiteSpace(payload))
                {
                    payload = Environment.GetEnvironmentVariable(TccPayloadEnvironmentVariable);
                }

                return string.IsNullOrWhiteSpace(payload)
                    ? AiSplitTccFetchResult.Failure("AI Split TCC payload is not configured.")
                    : AiSplitTccFetchResult.Success(payload);
            }
        }

        private sealed class OverrideThenFallbackAiSplitTccSource : IAiSplitTccSource
        {
            private readonly IAiSplitTccSource m_overrideSource;
            private readonly IAiSplitTccSource m_fallbackSource;

            public OverrideThenFallbackAiSplitTccSource(
                IAiSplitTccSource overrideSource,
                IAiSplitTccSource fallbackSource)
            {
                m_overrideSource = overrideSource ?? throw new ArgumentNullException(nameof(overrideSource));
                m_fallbackSource = fallbackSource ?? throw new ArgumentNullException(nameof(fallbackSource));
            }

            public AiSplitTccFetchResult Fetch()
            {
                AiSplitTccFetchResult overrideResult = m_overrideSource.Fetch();
                return overrideResult.IsSuccess ? overrideResult : m_fallbackSource.Fetch();
            }
        }

        private sealed class DynamicHttpAiSplitTccSource : IAiSplitTccSource
        {
            private readonly Func<string> m_urlProvider;

            public DynamicHttpAiSplitTccSource(Func<string> urlProvider)
            {
                m_urlProvider = urlProvider ?? (() => string.Empty);
            }

            public AiSplitTccFetchResult Fetch()
            {
                return new HttpAiSplitTccSource(m_urlProvider()).Fetch();
            }
        }

        private sealed class UnconfiguredAiSplitTosClient : IAiSplitTosClient
        {
            public void PutObject(
                string bucketName,
                string objectKey,
                byte[] bytes,
                System.Collections.Generic.Dictionary<string, string> headers)
            {
                throw new InvalidOperationException("AI Split TOS uploader is not configured for this editor session.");
            }
        }
    }
}
