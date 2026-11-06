using System;
using System.Collections.Generic;
using System.IO;
using System.Net;
using System.Text;
using System.Text.RegularExpressions;
using UnityEngine;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    public enum AiSplitRegionPreference
    {
        Internal,
        Cn,
        Global,
    }

    public interface IAiSplitTccSource
    {
        AiSplitTccFetchResult Fetch();
    }

    public static class AiSplitTccUrlConstants
    {
        public const string InternalTccUrl =
            "https://lf3-config.bytetcc.com/obj/tcc-config-web/tcc-v2-data-pico.spatial-plugin.emulator-debug-test";
        public const string CnTccUrl =
            "https://lf3-config.bytetcc.com/obj/tcc-config-web/tcc-v2-data-pico.spatial-plugin.emulator";
        public const string GlobalTccUrl =
            "https://lf3-config.bytetcc.com/obj/tcc-config-web/tcc-v2-data-pico.spatial-plugin.emulator";

        public static string GetUrl(AiSplitRegionPreference preference)
        {
            return preference switch
            {
                AiSplitRegionPreference.Internal => InternalTccUrl,
                AiSplitRegionPreference.Global => GlobalTccUrl,
                _ => CnTccUrl,
            };
        }
    }

    public sealed class HttpAiSplitTccSource : IAiSplitTccSource
    {
        private const int FetchTimeoutSeconds = 5;

        private readonly string m_url;
        private readonly Func<string, int, AiSplitTccFetchResult> m_fetch;

        public HttpAiSplitTccSource(string url)
            : this(url, FetchUrl)
        {
        }

        public HttpAiSplitTccSource(string url, Func<string, int, AiSplitTccFetchResult> fetch)
        {
            m_url = url ?? string.Empty;
            m_fetch = fetch ?? throw new ArgumentNullException(nameof(fetch));
        }

        public AiSplitTccFetchResult Fetch()
        {
            if (string.IsNullOrWhiteSpace(m_url))
            {
                return AiSplitTccFetchResult.Failure("AI Split TCC URL is empty.");
            }

            AiSplitTccFetchResult primaryResult = m_fetch(m_url, FetchTimeoutSeconds);
            if (!ShouldRetryWithInternalUrl(m_url, primaryResult))
            {
                return primaryResult;
            }

            return m_fetch(AiSplitTccUrlConstants.InternalTccUrl, FetchTimeoutSeconds);
        }

        private static bool ShouldRetryWithInternalUrl(string url, AiSplitTccFetchResult result)
        {
            if (result.IsSuccess)
            {
                return false;
            }

            bool isCnOrGlobalUrl =
                string.Equals(url, AiSplitTccUrlConstants.CnTccUrl, StringComparison.Ordinal)
                || string.Equals(url, AiSplitTccUrlConstants.GlobalTccUrl, StringComparison.Ordinal);
            return isCnOrGlobalUrl
                && result.ErrorMessage.IndexOf("HTTP 404", StringComparison.OrdinalIgnoreCase) >= 0;
        }

        private static AiSplitTccFetchResult FetchUrl(string url, int timeoutSeconds)
        {
            try
            {
                HttpWebRequest webRequest = (HttpWebRequest)WebRequest.Create(url);
                webRequest.Method = "GET";
                webRequest.Accept = "application/json,*/*";
                webRequest.AutomaticDecompression = DecompressionMethods.GZip | DecompressionMethods.Deflate;
                webRequest.Timeout = Math.Max(1, timeoutSeconds) * 1000;
                webRequest.ReadWriteTimeout = Math.Max(1, timeoutSeconds) * 1000;

                using HttpWebResponse response = (HttpWebResponse)webRequest.GetResponse();
                string body = ReadResponseBody(response);
                return IsSuccessStatusCode(response)
                    ? AiSplitTccFetchResult.Success(body)
                    : AiSplitTccFetchResult.Failure(BuildHttpFailure(url, (int)response.StatusCode));
            }
            catch (WebException exception) when (exception.Response is HttpWebResponse errorResponse)
            {
                using (errorResponse)
                {
                    return AiSplitTccFetchResult.Failure(BuildHttpFailure(url, (int)errorResponse.StatusCode));
                }
            }
            catch (Exception exception) when (
                exception is WebException
                || exception is IOException
                || exception is InvalidOperationException
                || exception is NotSupportedException
                || exception is UriFormatException)
            {
                return AiSplitTccFetchResult.Failure(
                    "AI Split TCC GET " + url + " failed: " + exception.Message);
            }
        }

        private static bool IsSuccessStatusCode(HttpWebResponse response)
        {
            int statusCode = (int)response.StatusCode;
            return statusCode >= 200 && statusCode < 300;
        }

        private static string ReadResponseBody(HttpWebResponse response)
        {
            using Stream responseStream = response.GetResponseStream();
            if (responseStream == null)
            {
                return string.Empty;
            }

            using StreamReader reader = new StreamReader(responseStream, Encoding.UTF8);
            return reader.ReadToEnd();
        }

        private static string BuildHttpFailure(string url, int statusCode)
        {
            return "AI Split TCC GET " + url + " failed: HTTP " + statusCode + ".";
        }
    }

    public readonly struct AiSplitTccFetchResult
    {
        private AiSplitTccFetchResult(bool isSuccess, string payload, string errorMessage)
        {
            IsSuccess = isSuccess;
            Payload = payload ?? string.Empty;
            ErrorMessage = errorMessage ?? string.Empty;
        }

        public bool IsSuccess { get; }

        public string Payload { get; }

        public string ErrorMessage { get; }

        public static AiSplitTccFetchResult Success(string payload)
        {
            return new AiSplitTccFetchResult(true, payload, string.Empty);
        }

        public static AiSplitTccFetchResult Failure(string errorMessage)
        {
            return new AiSplitTccFetchResult(false, string.Empty, errorMessage);
        }
    }

    public sealed class AiSplitTccLoadResult
    {
        private AiSplitTccLoadResult(
            bool success,
            AiSplitTccConfig config,
            AiSplitRegionConfig selectedRegion,
            AiSplitErrorType errorType,
            string errorMessage,
            IReadOnlyList<string> missingFields)
        {
            Success = success;
            Config = config;
            SelectedRegion = selectedRegion;
            ErrorType = errorType;
            ErrorMessage = errorMessage ?? string.Empty;
            MissingFields = missingFields ?? Array.Empty<string>();
        }

        public bool Success { get; }

        public AiSplitTccConfig Config { get; }

        public AiSplitRegionConfig SelectedRegion { get; }

        public AiSplitErrorType ErrorType { get; }

        public string ErrorMessage { get; }

        public IReadOnlyList<string> MissingFields { get; }

        public static AiSplitTccLoadResult Loaded(AiSplitTccConfig config, AiSplitRegionConfig selectedRegion)
        {
            return new AiSplitTccLoadResult(
                true,
                config,
                selectedRegion,
                AiSplitErrorType.None,
                string.Empty,
                Array.Empty<string>());
        }

        public static AiSplitTccLoadResult ConfigurationError(string errorMessage, params string[] missingFields)
        {
            return ConfigurationError(AiSplitErrorType.Configuration, errorMessage, missingFields);
        }

        public static AiSplitTccLoadResult ConfigurationError(
            AiSplitErrorType errorType,
            string errorMessage,
            params string[] missingFields)
        {
            return new AiSplitTccLoadResult(
                false,
                null,
                null,
                errorType,
                errorMessage,
                missingFields ?? Array.Empty<string>());
        }
    }

    public sealed class AiSplitTccStatus
    {
        public string RegionKey { get; set; } = string.Empty;

        public string TccUrl { get; set; } = string.Empty;

        public bool Enabled { get; set; }

        public IReadOnlyList<string> MissingFields { get; set; } = Array.Empty<string>();

        public string DisplayText { get; set; } = string.Empty;
    }

    public sealed class AiSplitTccManager
    {
        private readonly IAiSplitTccSource m_source;
        private readonly Func<AiSplitRegionPreference> m_regionPreferenceProvider;
        private readonly Func<string> m_tccUrlProvider;
        private AiSplitTccLoadResult m_cachedResult;

        public AiSplitTccManager(
            IAiSplitTccSource source,
            Func<AiSplitRegionPreference> regionPreferenceProvider)
            : this(source, regionPreferenceProvider, null)
        {
        }

        public AiSplitTccManager(
            IAiSplitTccSource source,
            Func<AiSplitRegionPreference> regionPreferenceProvider,
            Func<string> tccUrlProvider)
        {
            m_source = source ?? throw new ArgumentNullException(nameof(source));
            m_regionPreferenceProvider = regionPreferenceProvider ?? (() => AiSplitRegionPreference.Global);
            m_tccUrlProvider = tccUrlProvider ?? (() => AiSplitTccUrlConstants.GetUrl(m_regionPreferenceProvider()));
        }

        public AiSplitTccLoadResult TryLoad(bool forceRefresh = false)
        {
            if (!forceRefresh && m_cachedResult != null)
            {
                return m_cachedResult;
            }

            AiSplitTccFetchResult fetchResult = m_source.Fetch();
            if (!fetchResult.IsSuccess)
            {
                m_cachedResult = AiSplitTccLoadResult.ConfigurationError(
                    ClassifyFetchError(fetchResult.ErrorMessage),
                    "AI Split TCC configuration unavailable: " + fetchResult.ErrorMessage);
                return m_cachedResult;
            }

            if (!TryExtractAiSplitConfig(fetchResult.Payload, out string rawConfig, out string extractError))
            {
                m_cachedResult = AiSplitTccLoadResult.ConfigurationError(extractError);
                return m_cachedResult;
            }

            AiSplitTccConfig config = ParseConfig(rawConfig);
            ApplyRawSchemaOverrides(config, rawConfig, m_regionPreferenceProvider());
            AiSplitTccLoadResult validationResult = Validate(config, m_regionPreferenceProvider());
            m_cachedResult = validationResult;
            return m_cachedResult;
        }

        public void ClearCache()
        {
            m_cachedResult = null;
        }

        public AiSplitTccStatus GetStatus()
        {
            AiSplitRegionPreference preference = m_regionPreferenceProvider();
            AiSplitTccLoadResult result = m_cachedResult ?? TryLoad();
            string regionKey = GetRegionName(preference);
            IReadOnlyList<string> missingFields = result?.MissingFields ?? Array.Empty<string>();
            bool enabled = result?.Success == true;
            string displayText = "AI Split Config: region=" + regionKey
                + ", tcc_url=" + RedactUrl(m_tccUrlProvider())
                + ", enabled=" + enabled.ToString().ToLowerInvariant();

            if (missingFields.Count > 0)
            {
                displayText += ", missing=" + string.Join(", ", missingFields);
            }

            return new AiSplitTccStatus
            {
                RegionKey = regionKey,
                TccUrl = m_tccUrlProvider(),
                Enabled = enabled,
                MissingFields = missingFields,
                DisplayText = displayText,
            };
        }

        private static AiSplitTccLoadResult Validate(AiSplitTccConfig config, AiSplitRegionPreference preference)
        {
            if (config == null)
            {
                return AiSplitTccLoadResult.ConfigurationError("AI Split TCC configuration is invalid.");
            }

            AiSplitRegionConfig selectedRegion = SelectRegion(config.Regions, preference);
            if (selectedRegion == null)
            {
                return MissingRegionError(preference);
            }

            ApplyRegionOverrides(config, selectedRegion);

            if (string.IsNullOrWhiteSpace(config.Signing.AppId))
            {
                return MissingFieldError(preference, "app_id (auth.app_id)");
            }

            if (string.IsNullOrWhiteSpace(config.Signing.Salt))
            {
                return MissingFieldError(preference, "salt (auth.salt)");
            }

            if (string.IsNullOrWhiteSpace(selectedRegion.ApiBaseUrl) && !HasCompleteApiUrls(config.Api))
            {
                return MissingFieldError(preference, "api_base_url");
            }

            return AiSplitTccLoadResult.Loaded(config, selectedRegion);
        }

        private static void ApplyRegionOverrides(AiSplitTccConfig config, AiSplitRegionConfig selectedRegion)
        {
            if (config == null || selectedRegion == null)
            {
                return;
            }

            config.Signing ??= new AiSplitSigningConfig();
            config.Api ??= new AiSplitApiConfig();

            config.Signing.AppId = FirstNonEmpty(selectedRegion.AppId, config.Signing.AppId);
            config.Signing.Salt = FirstNonEmpty(selectedRegion.Salt, config.Signing.Salt);
            config.Api.GeneratePath = FirstNonEmpty(selectedRegion.GenerateUrl, config.Api.GeneratePath);
            config.Api.InfoPath = FirstNonEmpty(selectedRegion.InfoUrl, config.Api.InfoPath);
        }

        private static AiSplitTccLoadResult MissingFieldError(AiSplitRegionPreference preference, string fieldName)
        {
            return AiSplitTccLoadResult.ConfigurationError(
                AiSplitErrorType.TccFieldMissing,
                "AI Split TCC configuration for " + GetRegionName(preference) + " missing " + fieldName + ".",
                fieldName);
        }

        private static AiSplitTccLoadResult MissingRegionError(AiSplitRegionPreference preference)
        {
            string regionName = GetRegionName(preference);
            return AiSplitTccLoadResult.ConfigurationError(
                AiSplitErrorType.TccRegionMissing,
                "AI Split TCC configuration missing region " + regionName + ".",
                "region " + regionName);
        }

        private static AiSplitErrorType ClassifyFetchError(string errorMessage)
        {
            bool isNotConfigured = !string.IsNullOrWhiteSpace(errorMessage)
                && errorMessage.IndexOf("not configured", StringComparison.OrdinalIgnoreCase) >= 0;
            return isNotConfigured ? AiSplitErrorType.TccNotConfigured : AiSplitErrorType.TccFetchFailed;
        }

        private static bool HasCompleteApiUrls(AiSplitApiConfig api)
        {
            return IsAbsoluteHttpUrl(api?.GeneratePath) && IsAbsoluteHttpUrl(api?.InfoPath);
        }

        private static bool IsAbsoluteHttpUrl(string value)
        {
            return Uri.TryCreate(value, UriKind.Absolute, out Uri uri)
                && (uri.Scheme == Uri.UriSchemeHttp || uri.Scheme == Uri.UriSchemeHttps);
        }

        private static AiSplitRegionConfig SelectRegion(
            IReadOnlyList<AiSplitRegionConfig> regions,
            AiSplitRegionPreference preference)
        {
            string expectedRegion = GetRegionName(preference);
            if (regions == null)
            {
                return null;
            }

            for (int i = 0; i < regions.Count; i++)
            {
                AiSplitRegionConfig region = regions[i];
                if (string.Equals(region?.Region, expectedRegion, StringComparison.OrdinalIgnoreCase))
                {
                    return region;
                }
            }

            return null;
        }

        public static string GetRegionName(AiSplitRegionPreference preference)
        {
            return preference switch
            {
                AiSplitRegionPreference.Internal => "internal",
                AiSplitRegionPreference.Cn => "cn",
                _ => "global",
            };
        }

        private static string RedactUrl(string value)
        {
            if (string.IsNullOrWhiteSpace(value))
            {
                return string.Empty;
            }

            return Regex.Replace(value, @"(?i)(token|secret|app_id|salt|key)=([^&\s]+)", "$1=<redacted>");
        }

        private static bool TryExtractAiSplitConfig(string payload, out string rawConfig, out string errorMessage)
        {
            rawConfig = string.Empty;
            errorMessage = string.Empty;

            string cleanedPayload = CleanJsonText(payload);
            if (string.IsNullOrWhiteSpace(cleanedPayload))
            {
                errorMessage = "AI Split TCC payload is empty.";
                return false;
            }

            if (TryReadJsonPropertyValue(cleanedPayload, "ai_split_config", out rawConfig))
            {
                rawConfig = CleanJsonText(rawConfig);
                if (string.IsNullOrWhiteSpace(rawConfig))
                {
                    errorMessage = "AI Split TCC data.ai_split_config is empty.";
                    return false;
                }

                rawConfig = NormalizeAiSplitConfigJson(rawConfig);
                return true;
            }

            if (cleanedPayload.Contains("\"enable\"", StringComparison.Ordinal))
            {
                rawConfig = NormalizeAiSplitConfigJson(cleanedPayload);
                return true;
            }

            errorMessage = "AI Split TCC payload missing data.ai_split_config.";
            return false;
        }

        private static string CleanJsonText(string value)
        {
            string cleaned = (value ?? string.Empty).Trim();
            cleaned = StripCodeFence(cleaned);

            if (cleaned.Length >= 2 && cleaned[0] == '`' && cleaned[^1] == '`')
            {
                cleaned = cleaned.Substring(1, cleaned.Length - 2).Trim();
            }

            if (cleaned.Length >= 2 && cleaned[0] == '"' && cleaned[^1] == '"')
            {
                cleaned = UnescapeJsonString(cleaned.Substring(1, cleaned.Length - 2)).Trim();
                cleaned = StripCodeFence(cleaned);
            }

            if (cleaned.Length >= 2 && cleaned[0] == '`' && cleaned[^1] == '`')
            {
                cleaned = cleaned.Substring(1, cleaned.Length - 2).Trim();
            }

            return cleaned;
        }

        private static string NormalizeAiSplitConfigJson(string rawConfig)
        {
            string cleanedConfig = CleanJsonText(rawConfig);
            string normalized = TryReadJsonPropertyValue(cleanedConfig, "ai_split", out string aiSplitConfig)
                ? CleanJsonText(aiSplitConfig)
                : cleanedConfig;

            normalized = NormalizeNumericAppIds(normalized);
            normalized = NormalizeTimeoutMsObject(normalized);
            return normalized;
        }

        private static string NormalizeNumericAppIds(string json)
        {
            return Regex.Replace(
                json ?? string.Empty,
                "(\"app_id\"\\s*:\\s*)(\\d+)",
                "$1\"$2\"");
        }

        private static string NormalizeTimeoutMsObject(string json)
        {
            if (string.IsNullOrWhiteSpace(json)
                || TryReadJsonPropertyValue(json, "timeouts", out _)
                || !TryReadJsonPropertyValue(json, "timeout_ms", out string timeoutValue)
                || string.IsNullOrWhiteSpace(timeoutValue)
                || timeoutValue[0] != '{')
            {
                return json;
            }

            bool hasConnect = TryReadIntJsonProperty(timeoutValue, "connect", out int connectMs);
            bool hasRead = TryReadIntJsonProperty(timeoutValue, "read", out int readMs);
            bool hasPoll = TryReadIntJsonProperty(timeoutValue, "poll_interval", out int pollMs);
            if (!hasConnect && !hasRead && !hasPoll)
            {
                return json;
            }

            StringBuilder builder = new StringBuilder();
            builder.Append("\"timeouts\":{");
            bool hasPrevious = false;
            AppendTimeoutField(builder, ref hasPrevious, "connect_timeout_seconds", hasConnect, connectMs);
            AppendTimeoutField(builder, ref hasPrevious, "read_timeout_seconds", hasRead, readMs);
            AppendTimeoutField(builder, ref hasPrevious, "poll_interval_seconds", hasPoll, pollMs);
            builder.Append('}');
            return InsertTopLevelProperty(json, builder.ToString());
        }

        private static void AppendTimeoutField(
            StringBuilder builder,
            ref bool hasPrevious,
            string propertyName,
            bool hasValue,
            int milliseconds)
        {
            if (!hasValue)
            {
                return;
            }

            if (hasPrevious)
            {
                builder.Append(',');
            }

            builder.Append('"').Append(propertyName).Append("\":");
            builder.Append(MillisecondsToSeconds(milliseconds));
            hasPrevious = true;
        }

        private static string InsertTopLevelProperty(string json, string propertyJson)
        {
            if (string.IsNullOrWhiteSpace(json) || string.IsNullOrWhiteSpace(propertyJson))
            {
                return json;
            }

            int insertIndex = json.LastIndexOf('}');
            if (insertIndex < 0)
            {
                return json;
            }

            string prefix = json.Substring(0, insertIndex).TrimEnd();
            string separator = prefix.EndsWith("{", StringComparison.Ordinal) ? string.Empty : ",";
            return prefix + separator + propertyJson + json.Substring(insertIndex);
        }

        private static bool TryReadIntJsonProperty(string json, string propertyName, out int value)
        {
            value = 0;
            return TryReadJsonPropertyValue(json, propertyName, out string rawValue)
                && int.TryParse(rawValue, out value);
        }

        private static void ApplyRawSchemaOverrides(
            AiSplitTccConfig config,
            string rawConfig,
            AiSplitRegionPreference preference)
        {
            if (config == null || string.IsNullOrWhiteSpace(rawConfig))
            {
                return;
            }

            ApplyRawTimeoutOverrides(config, rawConfig);
            ApplyRawRegionOverrides(config, rawConfig, preference);
        }

        private static void ApplyRawTimeoutOverrides(AiSplitTccConfig config, string rawConfig)
        {
            if (config?.Timeouts == null
                || !TryReadJsonPropertyValue(rawConfig, "timeout_ms", out string timeoutJson)
                || string.IsNullOrWhiteSpace(timeoutJson)
                || timeoutJson[0] != '{')
            {
                return;
            }

            if (TryReadIntJsonProperty(timeoutJson, "connect", out int connectMs))
            {
                config.Timeouts.ConnectTimeoutSeconds = MillisecondsToSeconds(connectMs);
            }

            if (TryReadIntJsonProperty(timeoutJson, "read", out int readMs))
            {
                config.Timeouts.ReadTimeoutSeconds = MillisecondsToSeconds(readMs);
            }

            if (TryReadIntJsonProperty(timeoutJson, "poll_interval", out int pollMs))
            {
                config.Timeouts.PollIntervalSeconds = MillisecondsToSeconds(pollMs);
            }
        }

        private static void ApplyRawRegionOverrides(
            AiSplitTccConfig config,
            string rawConfig,
            AiSplitRegionPreference preference)
        {
            if (config == null
                || !TryReadSelectedRegionJson(rawConfig, preference, out string regionJson))
            {
                return;
            }

            AiSplitRegionConfig selectedRegion = SelectRegion(config.Regions, preference);
            config.Signing ??= new AiSplitSigningConfig();
            config.Api ??= new AiSplitApiConfig();

            if (TryReadJsonPropertyValue(regionJson, "auth", out string authJson))
            {
                if (TryReadJsonPropertyValue(authJson, "app_id", out string appId))
                {
                    string cleanedAppId = CleanJsonText(appId);
                    if (!string.IsNullOrWhiteSpace(cleanedAppId))
                    {
                        config.Signing.AppId = cleanedAppId;
                        if (selectedRegion != null)
                        {
                            selectedRegion.AppId = cleanedAppId;
                        }
                    }
                }

                if (TryReadJsonPropertyValue(authJson, "salt", out string salt))
                {
                    string cleanedSalt = CleanJsonText(salt);
                    if (!string.IsNullOrWhiteSpace(cleanedSalt))
                    {
                        config.Signing.Salt = cleanedSalt;
                        if (selectedRegion != null)
                        {
                            selectedRegion.Salt = cleanedSalt;
                        }
                    }
                }
            }

            if (!TryReadJsonPropertyValue(regionJson, "api", out string apiJson))
            {
                return;
            }

            if (TryReadJsonPropertyValue(apiJson, "gen_url", out string genUrl))
            {
                string cleanedGenUrl = CleanJsonText(genUrl);
                if (!string.IsNullOrWhiteSpace(cleanedGenUrl))
                {
                    config.Api.GeneratePath = cleanedGenUrl;
                    if (selectedRegion != null)
                    {
                        selectedRegion.GenerateUrl = cleanedGenUrl;
                    }
                }
            }

            if (TryReadJsonPropertyValue(apiJson, "info_url", out string infoUrl))
            {
                string cleanedInfoUrl = CleanJsonText(infoUrl);
                if (!string.IsNullOrWhiteSpace(cleanedInfoUrl))
                {
                    config.Api.InfoPath = cleanedInfoUrl;
                    if (selectedRegion != null)
                    {
                        selectedRegion.InfoUrl = cleanedInfoUrl;
                    }
                }
            }

            if (TryReadJsonPropertyValue(apiJson, "tt_env", out string ttEnv))
            {
                string cleanedTtEnv = CleanJsonText(ttEnv);
                if (!string.IsNullOrWhiteSpace(cleanedTtEnv) && selectedRegion != null)
                {
                    selectedRegion.TtEnv = cleanedTtEnv;
                    selectedRegion.UsePpe = true;
                }
            }
        }

        private static bool TryReadSelectedRegionJson(
            string rawConfig,
            AiSplitRegionPreference preference,
            out string regionJson)
        {
            regionJson = string.Empty;
            return TryReadJsonPropertyValue(rawConfig, "region_config", out string regionConfigJson)
                && TryReadJsonPropertyValue(regionConfigJson, GetRegionName(preference), out regionJson);
        }

        private static int MillisecondsToSeconds(int milliseconds)
        {
            return Math.Max(1, (int)Math.Ceiling(milliseconds / 1000d));
        }

        private static string StripCodeFence(string value)
        {
            if (!value.StartsWith("```", StringComparison.Ordinal))
            {
                return value;
            }

            int firstLineEnd = value.IndexOf('\n');
            if (firstLineEnd < 0 || !value.EndsWith("```", StringComparison.Ordinal))
            {
                return value;
            }

            return value.Substring(firstLineEnd + 1, value.Length - firstLineEnd - 4).Trim();
        }

        private static bool TryReadJsonPropertyValue(string json, string propertyName, out string value)
        {
            value = string.Empty;
            if (string.IsNullOrEmpty(json))
            {
                return false;
            }

            string quotedProperty = "\"" + propertyName + "\"";
            int searchIndex = 0;
            while (true)
            {
                int propertyIndex = json.IndexOf(quotedProperty, searchIndex, StringComparison.Ordinal);
                if (propertyIndex < 0)
                {
                    return false;
                }

                searchIndex = propertyIndex + quotedProperty.Length;

                // Only treat this match as a key when it is not the tail of a longer token
                // (e.g. "x_app_id" should not match "app_id") and it is immediately followed
                // by a ':' separator. This keeps the lenient outer-wrapper traversal while
                // ignoring identical substrings that appear inside string values.
                if (!IsKeyBoundary(json, propertyIndex))
                {
                    continue;
                }

                int colonIndex = SkipWhitespace(json, searchIndex);
                if (colonIndex >= json.Length || json[colonIndex] != ':')
                {
                    continue;
                }

                int valueStart = SkipWhitespace(json, colonIndex + 1);
                if (valueStart >= json.Length)
                {
                    return false;
                }

                char first = json[valueStart];
                if (first == '"')
                {
                    return TryReadJsonString(json, valueStart, out value);
                }

                if (first == '{' || first == '[')
                {
                    return TryReadBalancedJson(json, valueStart, out value);
                }

                int valueEnd = valueStart;
                while (valueEnd < json.Length && json[valueEnd] != ',' && json[valueEnd] != '}')
                {
                    valueEnd++;
                }

                value = json.Substring(valueStart, valueEnd - valueStart).Trim();
                return true;
            }
        }

        private static bool IsKeyBoundary(string json, int quoteIndex)
        {
            int previous = quoteIndex - 1;
            while (previous >= 0 && char.IsWhiteSpace(json[previous]))
            {
                previous--;
            }

            // A genuine key follows the start of the object or a member separator.
            return previous < 0 || json[previous] == '{' || json[previous] == ',';
        }

        private static int SkipWhitespace(string value, int startIndex)
        {
            int index = startIndex;
            while (index < value.Length && char.IsWhiteSpace(value[index]))
            {
                index++;
            }

            return index;
        }

        private static bool TryReadJsonString(string json, int quoteStart, out string value)
        {
            value = string.Empty;
            bool escaped = false;
            for (int i = quoteStart + 1; i < json.Length; i++)
            {
                char current = json[i];
                if (escaped)
                {
                    escaped = false;
                    continue;
                }

                if (current == '\\')
                {
                    escaped = true;
                    continue;
                }

                if (current == '"')
                {
                    value = UnescapeJsonString(json.Substring(quoteStart + 1, i - quoteStart - 1));
                    return true;
                }
            }

            return false;
        }

        private static bool TryReadBalancedJson(string json, int startIndex, out string value)
        {
            value = string.Empty;
            char open = json[startIndex];
            char close = open == '{' ? '}' : ']';
            int depth = 0;
            bool inString = false;
            bool escaped = false;

            for (int i = startIndex; i < json.Length; i++)
            {
                char current = json[i];
                if (inString)
                {
                    if (escaped)
                    {
                        escaped = false;
                    }
                    else if (current == '\\')
                    {
                        escaped = true;
                    }
                    else if (current == '"')
                    {
                        inString = false;
                    }

                    continue;
                }

                if (current == '"')
                {
                    inString = true;
                    continue;
                }

                if (current == open)
                {
                    depth++;
                }
                else if (current == close)
                {
                    depth--;
                    if (depth == 0)
                    {
                        value = json.Substring(startIndex, i - startIndex + 1);
                        return true;
                    }
                }
            }

            return false;
        }

        private static string UnescapeJsonString(string value)
        {
            if (string.IsNullOrEmpty(value))
            {
                return string.Empty;
            }

            return value
                .Replace("\\\"", "\"")
                .Replace("\\\\", "\\")
                .Replace("\\/", "/")
                .Replace("\\n", "\n")
                .Replace("\\r", "\r")
                .Replace("\\t", "\t")
                .Replace("\\b", "\b")
                .Replace("\\f", "\f");
        }

        private static AiSplitTccConfig ParseConfig(string rawConfig)
        {
            try
            {
                AiSplitTccConfigDto dto = JsonUtility.FromJson<AiSplitTccConfigDto>(rawConfig);
                return dto == null ? null : dto.ToConfig();
            }
            catch (ArgumentException)
            {
                return null;
            }
        }

        [Serializable]
        private sealed class AiSplitTccConfigDto
        {
            public bool enable;
            public List<AiSplitRegionConfigDto> regions = new List<AiSplitRegionConfigDto>();
            public AiSplitRegionConfigMapDto region_config = new AiSplitRegionConfigMapDto();
            public int timeout_ms;
            public AiSplitTimeoutConfigDto timeouts = new AiSplitTimeoutConfigDto();
            public AiSplitApiConfigDto api = new AiSplitApiConfigDto();
            public AiSplitTosConfigDto tos = new AiSplitTosConfigDto();
            public AiSplitSigningConfigDto signing = new AiSplitSigningConfigDto();
            public AiSplitSigningConfigDto auth = new AiSplitSigningConfigDto();

            public AiSplitTccConfig ToConfig()
            {
                AiSplitApiConfigDto apiDto = api ?? new AiSplitApiConfigDto();
                AiSplitTccConfig config = new AiSplitTccConfig
                {
                    Enable = enable,
                    Regions = new List<AiSplitRegionConfig>(),
                    Timeouts = timeouts?.ToConfig() ?? new AiSplitTimeoutConfig(),
                    Api = apiDto.ToConfig(),
                    Tos = tos?.ToConfig() ?? new AiSplitTosConfig(),
                    Signing = MergeSigning(signing?.ToConfig(), auth?.ToConfig()),
                };

                if (timeout_ms > 0)
                {
                    config.Timeouts.TotalTimeoutSeconds = MillisecondsToSeconds(timeout_ms);
                }

                if (regions != null)
                {
                    for (int i = 0; i < regions.Count; i++)
                    {
                        config.Regions.Add(regions[i]?.ToConfig(apiDto.TtEnv) ?? new AiSplitRegionConfig());
                    }
                }

                region_config?.AddTo(config.Regions, apiDto.TtEnv);

                return config;
            }

            private static AiSplitSigningConfig MergeSigning(
                AiSplitSigningConfig currentSchema,
                AiSplitSigningConfig androidSchema)
            {
                return new AiSplitSigningConfig
                {
                    AppId = FirstNonEmpty(currentSchema?.AppId, androidSchema?.AppId),
                    Salt = FirstNonEmpty(currentSchema?.Salt, androidSchema?.Salt),
                };
            }

        }

        [Serializable]
        private sealed class AiSplitRegionConfigMapDto
        {
            public AiSplitRegionConfigDto @internal;
            public AiSplitRegionConfigDto cn;
            public AiSplitRegionConfigDto global;

            public void AddTo(List<AiSplitRegionConfig> regions, string fallbackTtEnv)
            {
                AddRegion(regions, "internal", @internal, fallbackTtEnv);
                AddRegion(regions, "cn", cn, fallbackTtEnv);
                AddRegion(regions, "global", global, fallbackTtEnv);
            }

            private static void AddRegion(
                List<AiSplitRegionConfig> regions,
                string regionName,
                AiSplitRegionConfigDto dto,
                string fallbackTtEnv)
            {
                if (regions == null || dto == null)
                {
                    return;
                }

                AiSplitRegionConfig region = dto.ToConfig(fallbackTtEnv);
                region.Region = regionName;
                regions.Add(region);
            }
        }

        [Serializable]
        private sealed class AiSplitRegionConfigDto
        {
            public string region;
            public string api_base_url;
            public string apiBaseUrl;
            public string tcc_key;
            public string tccKey;
            public string tt_env;
            public string ttEnv;
            public bool use_ppe;
            public bool usePpe;
            public AiSplitApiConfigDto api = new AiSplitApiConfigDto();
            public AiSplitSigningConfigDto auth = new AiSplitSigningConfigDto();

            public AiSplitRegionConfig ToConfig(string fallbackTtEnv)
            {
                AiSplitApiConfig apiConfig = api?.ToConfig() ?? new AiSplitApiConfig();
                AiSplitSigningConfig authConfig = auth?.ToConfig() ?? new AiSplitSigningConfig();
                string ttEnvValue = FirstNonEmpty(tt_env, ttEnv, api?.TtEnv, fallbackTtEnv);
                return new AiSplitRegionConfig
                {
                    Region = region,
                    ApiBaseUrl = CleanJsonText(FirstNonEmpty(api_base_url, apiBaseUrl)),
                    TccKey = FirstNonEmpty(tcc_key, tccKey),
                    TtEnv = ttEnvValue,
                    UsePpe = use_ppe || usePpe || !string.IsNullOrWhiteSpace(ttEnvValue),
                    GenerateUrl = apiConfig.GeneratePath,
                    InfoUrl = apiConfig.InfoPath,
                    AppId = authConfig.AppId,
                    Salt = authConfig.Salt,
                };
            }
        }

        [Serializable]
        private sealed class AiSplitTimeoutConfigDto
        {
            public int connect_timeout_seconds;
            public int connectTimeoutSeconds;
            public int read_timeout_seconds;
            public int readTimeoutSeconds;
            public int poll_interval_seconds;
            public int pollIntervalSeconds;
            public int total_timeout_seconds;
            public int totalTimeoutSeconds;

            public AiSplitTimeoutConfig ToConfig()
            {
                AiSplitTimeoutConfig config = new AiSplitTimeoutConfig();
                if (connect_timeout_seconds > 0 || connectTimeoutSeconds > 0)
                {
                    config.ConnectTimeoutSeconds = FirstPositive(connect_timeout_seconds, connectTimeoutSeconds);
                }

                if (read_timeout_seconds > 0 || readTimeoutSeconds > 0)
                {
                    config.ReadTimeoutSeconds = FirstPositive(read_timeout_seconds, readTimeoutSeconds);
                }

                if (poll_interval_seconds > 0 || pollIntervalSeconds > 0)
                {
                    config.PollIntervalSeconds = FirstPositive(poll_interval_seconds, pollIntervalSeconds);
                }

                if (total_timeout_seconds > 0 || totalTimeoutSeconds > 0)
                {
                    config.TotalTimeoutSeconds = FirstPositive(total_timeout_seconds, totalTimeoutSeconds);
                }

                return config;
            }
        }

        [Serializable]
        private sealed class AiSplitApiConfigDto
        {
            public string generate_path;
            public string generatePath;
            public string gen_url;
            public string genUrl;
            public string info_path;
            public string infoPath;
            public string info_url;
            public string infoUrl;
            public string tt_env;
            public string ttEnv;

            public string TtEnv => FirstNonEmpty(tt_env, ttEnv);

            public AiSplitApiConfig ToConfig()
            {
                AiSplitApiConfig config = new AiSplitApiConfig();
                string generate = CleanJsonText(FirstNonEmpty(gen_url, genUrl, generate_path, generatePath));
                string info = CleanJsonText(FirstNonEmpty(info_url, infoUrl, info_path, infoPath));

                if (!string.IsNullOrWhiteSpace(generate))
                {
                    config.GeneratePath = generate;
                }

                if (!string.IsNullOrWhiteSpace(info))
                {
                    config.InfoPath = info;
                }

                return config;
            }
        }

        [Serializable]
        private sealed class AiSplitTosConfigDto
        {
            public string bucket_name;
            public string bucketName;
            public string object_directory;
            public string objectDirectory;
            public string public_base_url;
            public string publicBaseUrl;
            public string public_url_prefix;
            public string publicUrlPrefix;

            public AiSplitTosConfig ToConfig()
            {
                return new AiSplitTosConfig
                {
                    BucketName = FirstNonEmpty(bucket_name, bucketName),
                    ObjectDirectory = FirstNonEmpty(object_directory, objectDirectory),
                    PublicBaseUrl = FirstNonEmpty(public_url_prefix, publicUrlPrefix, public_base_url, publicBaseUrl),
                };
            }
        }

        [Serializable]
        private sealed class AiSplitSigningConfigDto
        {
            public string app_id;
            public string appId;
            public string salt;

            public AiSplitSigningConfig ToConfig()
            {
                return new AiSplitSigningConfig
                {
                    AppId = CleanJsonText(FirstNonEmpty(app_id, appId)),
                    Salt = CleanJsonText(salt),
                };
            }
        }

        private static string FirstNonEmpty(params string[] values)
        {
            if (values == null)
            {
                return string.Empty;
            }

            for (int i = 0; i < values.Length; i++)
            {
                if (!string.IsNullOrWhiteSpace(values[i]))
                {
                    return values[i];
                }
            }

            return string.Empty;
        }

        private static int FirstPositive(int first, int second)
        {
            return first > 0 ? first : second;
        }
    }
}
