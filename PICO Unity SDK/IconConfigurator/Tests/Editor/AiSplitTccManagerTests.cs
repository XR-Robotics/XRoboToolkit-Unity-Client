using System;
using NUnit.Framework;

namespace ByteDance.PICO.IconConfigurator.Editor.Tests
{
    public class AiSplitTccManagerTests
    {
        [Test]
        public void TryLoad_WhenPayloadContainsStringifiedJson_CleansAndParsesDataAiSplitConfig()
        {
            FakeAiSplitTccSource source = new FakeAiSplitTccSource(CreateOuterPayload(
                "  `\n" + CreateConfigJson(enable: true) + "\n`  "));
            AiSplitTccManager manager = new AiSplitTccManager(source, () => AiSplitRegionPreference.Cn);

            AiSplitTccLoadResult result = manager.TryLoad();

            Assert.That(result.Success, Is.True, result.ErrorMessage);
            Assert.That(result.Config.Enable, Is.True);
            Assert.That(result.Config.Api.GeneratePath, Is.EqualTo("/sdf/gen"));
            Assert.That(result.Config.Api.InfoPath, Is.EqualTo("/sdf/info"));
            Assert.That(result.Config.Tos.BucketName, Is.EqualTo("icon-bucket"));
            Assert.That(result.Config.Signing.AppId, Is.EqualTo("app-id"));
            Assert.That(result.SelectedRegion.Region, Is.EqualTo("cn"));
            Assert.That(result.SelectedRegion.ApiBaseUrl, Is.EqualTo("https://cn.example.test"));
        }

        [Test]
        public void TryLoad_WhenPayloadContainsAndroidAiSplitSchema_NormalizesSnakeCaseFields()
        {
            FakeAiSplitTccSource source = new FakeAiSplitTccSource(CreateOuterPayload(CreateAndroidConfigJson()));
            AiSplitTccManager manager = new AiSplitTccManager(source, () => AiSplitRegionPreference.Cn);

            AiSplitTccLoadResult result = manager.TryLoad();

            Assert.That(result.Success, Is.True, result.ErrorMessage);
            Assert.That(result.Config.Enable, Is.True);
            Assert.That(result.Config.Regions, Has.Count.EqualTo(3));
            Assert.That(result.SelectedRegion.Region, Is.EqualTo("cn"));
            Assert.That(result.SelectedRegion.TtEnv, Is.EqualTo("ppe_android"));
            Assert.That(result.SelectedRegion.UsePpe, Is.True);
            Assert.That(result.Config.Timeouts.TotalTimeoutSeconds, Is.EqualTo(120));
            Assert.That(result.Config.Api.GeneratePath, Is.EqualTo("https://android.example.test/sdf/gen"));
            Assert.That(result.Config.Api.InfoPath, Is.EqualTo("https://android.example.test/sdf/info"));
            Assert.That(result.Config.Tos.BucketName, Is.EqualTo("android-bucket"));
            Assert.That(result.Config.Tos.ObjectDirectory, Is.EqualTo("android/icons"));
            Assert.That(result.Config.Tos.PublicBaseUrl, Is.EqualTo("https://cdn.android.example.test/public"));
            Assert.That(result.Config.Signing.AppId, Is.EqualTo("android-app-id"));
        }

        [Test]
        public void TryLoad_WhenAndroidAiSplitConfigHasMarkdownFence_CleansAndExtractsNestedAiSplit()
        {
            FakeAiSplitTccSource source = new FakeAiSplitTccSource(CreateOuterPayload(
                "```json\n" + CreateAndroidConfigJson() + "\n```"));
            AiSplitTccManager manager = new AiSplitTccManager(source, () => AiSplitRegionPreference.Cn);

            AiSplitTccLoadResult result = manager.TryLoad();

            Assert.That(result.Success, Is.True, result.ErrorMessage);
            Assert.That(result.SelectedRegion.Region, Is.EqualTo("cn"));
            Assert.That(result.Config.Api.GeneratePath, Is.EqualTo("https://android.example.test/sdf/gen"));
            Assert.That(result.Config.Tos.PublicBaseUrl, Is.EqualTo("https://cdn.android.example.test/public"));
        }

        [TestCase(
            AiSplitRegionPreference.Internal,
            "internal",
            "556443",
            "https://appstore-cn.picovr.com/api/app/v3/sdf/gen",
            "https://appstore-cn.picovr.com/api/app/v3/sdf/info")]
        [TestCase(
            AiSplitRegionPreference.Cn,
            "cn",
            "556443",
            "https://appstore-cn.picovr.com/api/app/v3/sdf/gen",
            "https://appstore-cn.picovr.com/api/app/v3/sdf/info")]
        [TestCase(
            AiSplitRegionPreference.Global,
            "global",
            "930645",
            "https://appstore-us.picovr.com/api/app/v3/sdf/gen",
            "https://appstore-us.picovr.com/api/app/v3/sdf/info")]
        public void TryLoad_WhenPayloadUsesRegionScopedAuthAndDirectApiUrls_UsesSelectedRegionValues(
            AiSplitRegionPreference preference,
            string expectedRegion,
            string expectedAppId,
            string expectedGenerateUrl,
            string expectedInfoUrl)
        {
            FakeAiSplitTccSource source = new FakeAiSplitTccSource(
                CreateOuterPayload(CreateRealRegionScopedConfigJson(includeTos: true)));
            AiSplitTccManager manager = new AiSplitTccManager(source, () => preference);

            AiSplitTccLoadResult result = manager.TryLoad();

            Assert.That(result.Success, Is.True, result.ErrorMessage);
            Assert.That(result.SelectedRegion.Region, Is.EqualTo(expectedRegion));
            Assert.That(result.SelectedRegion.TtEnv, Is.EqualTo("prod"));
            Assert.That(result.SelectedRegion.UsePpe, Is.True);
            Assert.That(result.Config.Signing.AppId, Is.EqualTo(expectedAppId));
            Assert.That(result.Config.Signing.Salt, Is.EqualTo("3f8a7b2c9d4e6a1f0c3d5b7a9e8f2d4c"));
            Assert.That(result.Config.Api.GeneratePath, Is.EqualTo(expectedGenerateUrl));
            Assert.That(result.Config.Api.InfoPath, Is.EqualTo(expectedInfoUrl));
            Assert.That(result.Config.Timeouts.ConnectTimeoutSeconds, Is.EqualTo(15));
            Assert.That(result.Config.Timeouts.ReadTimeoutSeconds, Is.EqualTo(60));
            Assert.That(result.Config.Timeouts.PollIntervalSeconds, Is.EqualTo(3));
        }

        [Test]
        public void TryLoad_WhenRealPayloadOmitsTos_DoesNotRequireTosToLoadConfiguration()
        {
            FakeAiSplitTccSource source = new FakeAiSplitTccSource(
                CreateOuterPayload(CreateRealRegionScopedConfigJson(includeTos: false)));
            AiSplitTccManager manager = new AiSplitTccManager(source, () => AiSplitRegionPreference.Internal);

            AiSplitTccLoadResult result = manager.TryLoad();

            Assert.That(result.Success, Is.True, result.ErrorMessage);
            Assert.That(result.SelectedRegion.Region, Is.EqualTo("internal"));
            Assert.That(result.Config.Signing.AppId, Is.EqualTo("556443"));
            Assert.That(result.Config.Api.GeneratePath, Is.EqualTo("https://appstore-cn.picovr.com/api/app/v3/sdf/gen"));
            Assert.That(result.Config.Tos.BucketName, Is.Empty);
            Assert.That(result.Config.Tos.ObjectDirectory, Is.Empty);
            Assert.That(result.Config.Tos.PublicBaseUrl, Is.Empty);
        }

        [TestCase(
            AiSplitRegionPreference.Internal,
            "https://lf3-config.bytetcc.com/obj/tcc-config-web/tcc-v2-data-pico.spatial-plugin.emulator-debug-test")]
        [TestCase(
            AiSplitRegionPreference.Cn,
            "https://lf3-config.bytetcc.com/obj/tcc-config-web/tcc-v2-data-pico.spatial-plugin.emulator")]
        [TestCase(
            AiSplitRegionPreference.Global,
            "https://lf3-config.bytetcc.com/obj/tcc-config-web/tcc-v2-data-pico.spatial-plugin.emulator")]
        public void GetUrl_WhenRegionPreferenceProvided_SelectsAndroidCompatibleTccUrl(
            AiSplitRegionPreference preference,
            string expectedUrl)
        {
            string url = AiSplitTccUrlConstants.GetUrl(preference);

            Assert.That(url, Is.EqualTo(expectedUrl));
        }

        [Test]
        public void Fetch_WhenHttpSourceIsUsed_PerformsGetWithFiveSecondTimeout()
        {
            string requestedUrl = string.Empty;
            int requestedTimeoutSeconds = 0;
            HttpAiSplitTccSource source = new HttpAiSplitTccSource(
                "https://tcc.example.test/config",
                (url, timeoutSeconds) =>
                {
                    requestedUrl = url;
                    requestedTimeoutSeconds = timeoutSeconds;
                    return AiSplitTccFetchResult.Success("{\"data\":{\"ai_split_config\":\"{}\"}}");
                });

            AiSplitTccFetchResult result = source.Fetch();

            Assert.That(result.IsSuccess, Is.True, result.ErrorMessage);
            Assert.That(result.Payload, Does.Contain("ai_split_config"));
            Assert.That(requestedUrl, Is.EqualTo("https://tcc.example.test/config"));
            Assert.That(requestedTimeoutSeconds, Is.EqualTo(5));
        }

        [Test]
        public void Fetch_WhenCnUrlReturns404_RetriesInternalUrl()
        {
            string[] requestedUrls = new string[2];
            int requestCount = 0;
            HttpAiSplitTccSource source = new HttpAiSplitTccSource(
                AiSplitTccUrlConstants.CnTccUrl,
                (url, timeoutSeconds) =>
                {
                    requestedUrls[requestCount++] = url;
                    return requestCount == 1
                        ? AiSplitTccFetchResult.Failure("AI Split TCC GET " + url + " failed: HTTP 404.")
                        : AiSplitTccFetchResult.Success("{\"data\":{\"ai_split_config\":\"{}\"}}");
                });

            AiSplitTccFetchResult result = source.Fetch();

            Assert.That(result.IsSuccess, Is.True, result.ErrorMessage);
            Assert.That(requestCount, Is.EqualTo(2));
            Assert.That(requestedUrls[0], Is.EqualTo(AiSplitTccUrlConstants.CnTccUrl));
            Assert.That(requestedUrls[1], Is.EqualTo(AiSplitTccUrlConstants.InternalTccUrl));
        }

        [Test]
        public void TryLoad_WhenTccFetchFails_ReturnsClearUnavailableConfigurationError()
        {
            FakeAiSplitTccSource source = FakeAiSplitTccSource.Failure(
                "GET https://tcc.example.test/config failed: HTTP 500.");
            AiSplitTccManager manager = new AiSplitTccManager(source, () => AiSplitRegionPreference.Cn);

            AiSplitTccLoadResult result = manager.TryLoad();

            Assert.That(result.Success, Is.False);
            Assert.That(result.ErrorType, Is.EqualTo(AiSplitErrorType.TccFetchFailed));
            Assert.That(result.ErrorMessage, Does.Contain("unavailable"));
            Assert.That(result.ErrorMessage, Does.Contain("https://tcc.example.test/config"));
            Assert.That(result.Config, Is.Null);
        }

        [Test]
        public void TryLoad_WhenTccPayloadIsNotConfigured_ReturnsSpecificNotConfiguredError()
        {
            FakeAiSplitTccSource source = FakeAiSplitTccSource.Failure(
                "AI Split TCC payload is not configured.");
            AiSplitTccManager manager = new AiSplitTccManager(source, () => AiSplitRegionPreference.Cn);

            AiSplitTccLoadResult result = manager.TryLoad();

            Assert.That(result.Success, Is.False);
            Assert.That(result.ErrorType, Is.EqualTo(AiSplitErrorType.TccNotConfigured));
            Assert.That(result.ErrorMessage, Does.Contain("not configured"));
        }

        [Test]
        public void TryLoad_WhenCalledTwice_UsesCachedParsedConfig()
        {
            FakeAiSplitTccSource source = new FakeAiSplitTccSource(CreateOuterPayload(CreateConfigJson(enable: true)));
            AiSplitTccManager manager = new AiSplitTccManager(source, () => AiSplitRegionPreference.Global);

            AiSplitTccLoadResult first = manager.TryLoad();
            AiSplitTccLoadResult second = manager.TryLoad();

            Assert.That(first.Success, Is.True, first.ErrorMessage);
            Assert.That(second.Success, Is.True, second.ErrorMessage);
            Assert.That(source.FetchCount, Is.EqualTo(1));
            Assert.That(second.SelectedRegion.Region, Is.EqualTo("global"));
        }

        [Test]
        public void RefreshConfiguration_WhenForceRefreshRequested_ClearsCachedTccPayload()
        {
            FakeAiSplitTccSource source = new FakeAiSplitTccSource(
                CreateOuterPayload(CreateConfigJson(enable: true)),
                CreateOuterPayload(CreateConfigJson(enable: true, cnApiBaseUrl: "https://cn-refreshed.example.test")));
            AiSplitTccManager manager = new AiSplitTccManager(
                source,
                () => AiSplitRegionPreference.Cn,
                () => AiSplitTccUrlConstants.CnTccUrl);

            AiSplitTccLoadResult first = manager.TryLoad();
            manager.ClearCache();
            AiSplitTccLoadResult refreshed = manager.TryLoad();

            Assert.That(first.Success, Is.True, first.ErrorMessage);
            Assert.That(refreshed.Success, Is.True, refreshed.ErrorMessage);
            Assert.That(source.FetchCount, Is.EqualTo(2));
            Assert.That(refreshed.SelectedRegion.ApiBaseUrl, Is.EqualTo("https://cn-refreshed.example.test"));
        }

        [Test]
        public void GetStatus_WhenConfigurationLoads_ReturnsRedactedRegionUrlAndEnableState()
        {
            FakeAiSplitTccSource source = new FakeAiSplitTccSource(
                CreateOuterPayload(CreateConfigJson(enable: true, appId: "secret-app", salt: "secret-salt")));
            AiSplitTccManager manager = new AiSplitTccManager(
                source,
                () => AiSplitRegionPreference.Cn,
                () => AiSplitTccUrlConstants.CnTccUrl);

            manager.TryLoad();
            AiSplitTccStatus status = manager.GetStatus();

            Assert.That(status.RegionKey, Is.EqualTo("cn"));
            Assert.That(status.TccUrl, Is.EqualTo(AiSplitTccUrlConstants.CnTccUrl));
            Assert.That(status.Enabled, Is.True);
            Assert.That(status.MissingFields, Is.Empty);
            Assert.That(status.DisplayText, Does.Contain("region=cn"));
            Assert.That(status.DisplayText, Does.Contain("enabled=true"));
            Assert.That(status.DisplayText, Does.Not.Contain("secret-app"));
            Assert.That(status.DisplayText, Does.Not.Contain("secret-salt"));
        }

        [Test]
        public void GetStatus_WhenConfigurationMissingField_ReturnsMissingFieldsWithoutSensitiveValues()
        {
            FakeAiSplitTccSource source = new FakeAiSplitTccSource(
                CreateOuterPayload(CreateConfigJson(enable: true, appId: "visible-secret-app", salt: string.Empty)));
            AiSplitTccManager manager = new AiSplitTccManager(
                source,
                () => AiSplitRegionPreference.Cn,
                () => AiSplitTccUrlConstants.CnTccUrl);

            manager.TryLoad();
            AiSplitTccStatus status = manager.GetStatus();

            Assert.That(status.RegionKey, Is.EqualTo("cn"));
            Assert.That(status.TccUrl, Is.EqualTo(AiSplitTccUrlConstants.CnTccUrl));
            Assert.That(status.Enabled, Is.False);
            Assert.That(status.MissingFields, Does.Contain("salt (auth.salt)"));
            Assert.That(status.DisplayText, Does.Contain("missing=salt (auth.salt)"));
            Assert.That(status.DisplayText, Does.Not.Contain("visible-secret-app"));
        }

        [TestCase(AiSplitRegionPreference.Internal, "internal")]
        [TestCase(AiSplitRegionPreference.Cn, "cn")]
        [TestCase(AiSplitRegionPreference.Global, "global")]
        public void TryLoad_WhenRegionPreferenceProvided_SelectsRequestedRegion(
            AiSplitRegionPreference preference,
            string expectedRegion)
        {
            FakeAiSplitTccSource source = new FakeAiSplitTccSource(CreateOuterPayload(CreateConfigJson(enable: true)));
            AiSplitTccManager manager = new AiSplitTccManager(source, () => preference);

            AiSplitTccLoadResult result = manager.TryLoad();

            Assert.That(result.Success, Is.True, result.ErrorMessage);
            Assert.That(result.SelectedRegion.Region, Is.EqualTo(expectedRegion));
        }

        [Test]
        public void TryLoad_WhenConfigDisableFlagIsFalse_DoesNotBlockConfiguration()
        {
            FakeAiSplitTccSource source = new FakeAiSplitTccSource(CreateOuterPayload(CreateConfigJson(enable: false)));
            AiSplitTccManager manager = new AiSplitTccManager(source, () => AiSplitRegionPreference.Cn);

            AiSplitTccLoadResult result = manager.TryLoad();

            Assert.That(result.Success, Is.True, result.ErrorMessage);
            Assert.That(result.ErrorType, Is.EqualTo(AiSplitErrorType.None));
            Assert.That(result.Config, Is.Not.Null);
            Assert.That(result.SelectedRegion.Region, Is.EqualTo("cn"));
        }

        [Test]
        public void TryLoad_WhenRequestedRegionMissing_ReturnsSpecificRegionMissingError()
        {
            string configJson = "{"
                + "\"enable\":true,"
                + "\"regions\":[" + CreateRegionJson("global", "https://global.example.test") + "],"
                + "\"api\":{\"generate_path\":\"/sdf/gen\",\"info_path\":\"/sdf/info\"},"
                + "\"tos\":{\"bucket_name\":\"icon-bucket\",\"object_directory\":\"icons/\","
                + "\"public_base_url\":\"https://cdn.example.test\"},"
                + "\"signing\":{\"app_id\":\"app-id\",\"salt\":\"salt\"}"
                + "}";
            FakeAiSplitTccSource source = new FakeAiSplitTccSource(CreateOuterPayload(configJson));
            AiSplitTccManager manager = new AiSplitTccManager(source, () => AiSplitRegionPreference.Cn);

            AiSplitTccLoadResult result = manager.TryLoad();

            Assert.That(result.Success, Is.False);
            Assert.That(result.ErrorType, Is.EqualTo(AiSplitErrorType.TccRegionMissing));
            Assert.That(result.ErrorMessage, Does.Contain("cn"));
            Assert.That(result.ErrorMessage, Does.Contain("region"));
            Assert.That(result.MissingFields, Does.Contain("region cn"));
        }

        [Test]
        public void TryLoad_WhenConfigMissing_ReturnsConfigurationError()
        {
            FakeAiSplitTccSource source = new FakeAiSplitTccSource("{\"data\":{}}");
            AiSplitTccManager manager = new AiSplitTccManager(source, () => AiSplitRegionPreference.Cn);

            AiSplitTccLoadResult result = manager.TryLoad();

            Assert.That(result.Success, Is.False);
            Assert.That(result.ErrorType, Is.EqualTo(AiSplitErrorType.Configuration));
            Assert.That(result.ErrorMessage, Does.Contain("data.ai_split_config"));
            Assert.That(result.Config, Is.Null);
        }

        [TestCase("", "salt", "https://cn.example.test", "cn", "missing app_id")]
        [TestCase("app-id", "", "https://cn.example.test", "cn", "missing salt")]
        [TestCase("app-id", "salt", "", "cn", "missing api_base_url")]
        public void TryLoad_WhenRequiredSensitiveFieldMissing_ReturnsConfigurationError(
            string appId,
            string salt,
            string cnApiBaseUrl,
            string expectedEnvironment,
            string expectedError)
        {
            string configJson = CreateConfigJson(enable: true, appId: appId, salt: salt, cnApiBaseUrl: cnApiBaseUrl);
            FakeAiSplitTccSource source = new FakeAiSplitTccSource(CreateOuterPayload(configJson));
            AiSplitTccManager manager = new AiSplitTccManager(source, () => AiSplitRegionPreference.Cn);

            AiSplitTccLoadResult result = manager.TryLoad();

            Assert.That(result.Success, Is.False);
            Assert.That(result.ErrorType, Is.EqualTo(AiSplitErrorType.TccFieldMissing));
            Assert.That(result.ErrorMessage, Does.Contain(expectedEnvironment));
            Assert.That(result.ErrorMessage, Does.Contain(expectedError));
            if (!string.IsNullOrEmpty(appId))
            {
                Assert.That(result.ErrorMessage, Does.Not.Contain(appId));
            }

            if (!string.IsNullOrEmpty(salt))
            {
                Assert.That(result.ErrorMessage, Does.Not.Contain(salt));
            }

            Assert.That(result.Config, Is.Null);
        }

        [Test]
        public void TryLoad_WhenAndroidSchemaMissingPublicUrlPrefix_ReturnsEnvironmentScopedFieldError()
        {
            string configJson = CreateAndroidConfigJson(publicUrlPrefix: string.Empty, salt: "super-secret-salt");
            FakeAiSplitTccSource source = new FakeAiSplitTccSource(CreateOuterPayload(configJson));
            AiSplitTccManager manager = new AiSplitTccManager(source, () => AiSplitRegionPreference.Cn);

            AiSplitTccLoadResult result = manager.TryLoad();

            Assert.That(result.Success, Is.False);
            Assert.That(result.ErrorType, Is.EqualTo(AiSplitErrorType.TccFieldMissing));
            Assert.That(result.ErrorMessage, Does.Contain("cn"));
            Assert.That(result.ErrorMessage, Does.Contain("tos.public_url_prefix"));
            Assert.That(result.ErrorMessage, Does.Not.Contain("super-secret-salt"));
            Assert.That(result.Config, Is.Null);
        }

        private static string CreateOuterPayload(string aiSplitConfig)
        {
            return "{\"data\":{\"ai_split_config\":\"" + EscapeJsonString(aiSplitConfig) + "\"}}";
        }

        private static string CreateConfigJson(
            bool enable,
            string appId = "app-id",
            string salt = "salt",
            string cnApiBaseUrl = "https://cn.example.test")
        {
            return "{"
                + "\"enable\":" + enable.ToString().ToLowerInvariant() + ","
                + "\"regions\":["
                + CreateRegionJson("internal", "https://internal.example.test")
                + ","
                + CreateRegionJson("cn", cnApiBaseUrl)
                + ","
                + CreateRegionJson("global", "https://global.example.test")
                + "],"
                + "\"timeouts\":{\"connect_timeout_seconds\":3,\"read_timeout_seconds\":30,"
                + "\"poll_interval_seconds\":2,\"total_timeout_seconds\":300},"
                + "\"api\":{\"generate_path\":\"/sdf/gen\",\"info_path\":\"/sdf/info\"},"
                + "\"tos\":{\"bucket_name\":\"icon-bucket\",\"object_directory\":\"icons/\","
                + "\"public_base_url\":\"https://cdn.example.test\"},"
                + "\"signing\":{\"app_id\":\"" + EscapeJsonString(appId) + "\",\"salt\":\""
                + EscapeJsonString(salt) + "\"}"
                + "}";
        }

        private static string CreateAndroidConfigJson(
            string publicUrlPrefix = "https://cdn.android.example.test/public",
            string salt = "android-salt")
        {
            return "{"
                + "\"ai_split\":{"
                + "\"enable\":true,"
                + "\"timeout_ms\":120000,"
                + "\"region_config\":{"
                + "\"internal\":{\"api_base_url\":\"https://internal.android.example.test\"},"
                + "\"cn\":{\"api_base_url\":\"https://cn.android.example.test\"},"
                + "\"global\":{\"api_base_url\":\"https://global.android.example.test\"}"
                + "},"
                + "\"auth\":{\"app_id\":\"android-app-id\",\"salt\":\"" + EscapeJsonString(salt) + "\"},"
                + "\"tos\":{\"bucket_name\":\"android-bucket\",\"object_directory\":\"android/icons\","
                + "\"public_url_prefix\":\"" + EscapeJsonString(publicUrlPrefix) + "\"},"
                + "\"api\":{\"gen_url\":\"https://android.example.test/sdf/gen\","
                + "\"info_url\":\"https://android.example.test/sdf/info\",\"tt_env\":\"ppe_android\"}"
                + "}"
                + "}";
        }

        private static string CreateRealRegionScopedConfigJson(bool includeTos)
        {
            return "{"
                + "\"ai_split\":{"
                + "\"region_config\":{"
                + "\"internal\":{"
                + "\"auth\":{\"app_id\":556443,\"salt\":\"3f8a7b2c9d4e6a1f0c3d5b7a9e8f2d4c\"},"
                + "\"api\":{\"gen_url\":\" `https://appstore-cn.picovr.com/api/app/v3/sdf/gen` \","
                + "\"info_url\":\" `https://appstore-cn.picovr.com/api/app/v3/sdf/info` \",\"tt_env\":\"prod\"}"
                + "},"
                + "\"cn\":{"
                + "\"auth\":{\"app_id\":556443,\"salt\":\"3f8a7b2c9d4e6a1f0c3d5b7a9e8f2d4c\"},"
                + "\"api\":{\"gen_url\":\" `https://appstore-cn.picovr.com/api/app/v3/sdf/gen` \","
                + "\"info_url\":\" `https://appstore-cn.picovr.com/api/app/v3/sdf/info` \",\"tt_env\":\"prod\"}"
                + "},"
                + "\"global\":{"
                + "\"auth\":{\"app_id\":930645,\"salt\":\"3f8a7b2c9d4e6a1f0c3d5b7a9e8f2d4c\"},"
                + "\"api\":{\"gen_url\":\" `https://appstore-us.picovr.com/api/app/v3/sdf/gen` \","
                + "\"info_url\":\" `https://appstore-us.picovr.com/api/app/v3/sdf/info` \",\"tt_env\":\"prod\"}"
                + "}"
                + "},"
                + "\"timeout_ms\":{\"connect\":15000,\"read\":60000,\"poll_interval\":3000}"
                + (includeTos
                    ? ",\"tos\":{\"bucket_name\":\"icon-bucket\",\"object_directory\":\"icons/\",\"public_base_url\":\"https://cdn.example.test\"}"
                    : string.Empty)
                + "}"
                + "}";
        }

        private static string CreateRegionJson(string region, string apiBaseUrl)
        {
            return "{\"region\":\"" + region + "\",\"api_base_url\":\"" + EscapeJsonString(apiBaseUrl)
                + "\",\"tcc_key\":\"data.ai_split_config\",\"tt_env\":\"ppe\",\"use_ppe\":true}";
        }

        private static string EscapeJsonString(string value)
        {
            return (value ?? string.Empty)
                .Replace("\\", "\\\\")
                .Replace("\"", "\\\"")
                .Replace("\r", "\\r")
                .Replace("\n", "\\n");
        }

        private sealed class FakeAiSplitTccSource : IAiSplitTccSource
        {
            private readonly string[] m_payloads;
            private readonly string m_errorMessage;

            public FakeAiSplitTccSource(string payload)
            {
                m_payloads = new[] { payload };
            }

            public FakeAiSplitTccSource(params string[] payloads)
            {
                m_payloads = payloads;
            }

            private FakeAiSplitTccSource(string payload, string errorMessage)
            {
                m_payloads = new[] { payload };
                m_errorMessage = errorMessage;
            }

            public static FakeAiSplitTccSource Failure(string errorMessage)
            {
                return new FakeAiSplitTccSource(string.Empty, errorMessage);
            }

            public int FetchCount { get; private set; }

            public AiSplitTccFetchResult Fetch()
            {
                FetchCount++;
                if (!string.IsNullOrWhiteSpace(m_errorMessage))
                {
                    return AiSplitTccFetchResult.Failure(m_errorMessage);
                }

                int payloadIndex = System.Math.Min(FetchCount - 1, m_payloads.Length - 1);
                return AiSplitTccFetchResult.Success(m_payloads[payloadIndex]);
            }
        }
    }
}
