using System;
using NUnit.Framework;
using UnityEditor;

namespace ByteDance.PICO.IconConfigurator.Editor.Tests
{
    public class IconAiSplitServiceFactoryTests
    {
        private string m_originalPayloadEnvironment;

        [SetUp]
        public void SetUp()
        {
            m_originalPayloadEnvironment = Environment.GetEnvironmentVariable(
                IconAiSplitServiceFactory.TccPayloadEnvironmentVariable);
            EditorPrefs.DeleteKey(IconAiSplitServiceFactory.TccPayloadEditorPrefsKey);
            EditorPrefs.DeleteKey(AiSplitEnvironmentService.PpeInternalEditorPrefsKey);
            EditorPrefs.DeleteKey(AiSplitEnvironmentService.RegionOverrideEditorPrefsKey);
            Environment.SetEnvironmentVariable(IconAiSplitServiceFactory.TccPayloadEnvironmentVariable, null);
        }

        [TearDown]
        public void TearDown()
        {
            EditorPrefs.DeleteKey(IconAiSplitServiceFactory.TccPayloadEditorPrefsKey);
            EditorPrefs.DeleteKey(AiSplitEnvironmentService.PpeInternalEditorPrefsKey);
            EditorPrefs.DeleteKey(AiSplitEnvironmentService.RegionOverrideEditorPrefsKey);
            Environment.SetEnvironmentVariable(
                IconAiSplitServiceFactory.TccPayloadEnvironmentVariable,
                m_originalPayloadEnvironment);
        }

        [Test]
        public void CreateDefault_WhenNoExplicitOverrideExists_UsesAutomaticTccUrlSource()
        {
            IconAiSplitServiceFactory factory = IconAiSplitServiceFactory.CreateDefault();

            AiSplitTccLoadResult result = factory.LoadConfiguration(forceRefresh: true);

            Assert.That(result.ErrorType, Is.Not.EqualTo(AiSplitErrorType.TccNotConfigured));
            if (result.Success)
            {
                Assert.That(result.SelectedRegion.Region, Is.EqualTo("cn"));
            }
            else
            {
                Assert.That(
                    result.ErrorMessage,
                    Does.Contain("https://lf3-config.bytetcc.com/obj/tcc-config-web/tcc-v2-data-pico.spatial-plugin.emulator"));
            }
        }

        [Test]
        public void CreateDefault_WhenEnvironmentPayloadOverrideExists_UsesOverrideInsteadOfAutomaticTccUrlSource()
        {
            Environment.SetEnvironmentVariable(
                IconAiSplitServiceFactory.TccPayloadEnvironmentVariable,
                CreateOuterPayload(CreateConfigJson("https://env-cn.example.test")));
            IconAiSplitServiceFactory factory = IconAiSplitServiceFactory.CreateDefault();

            AiSplitTccLoadResult result = factory.LoadConfiguration(forceRefresh: true);

            Assert.That(result.Success, Is.True, result.ErrorMessage);
            Assert.That(result.SelectedRegion.Region, Is.EqualTo("cn"));
            Assert.That(result.SelectedRegion.ApiBaseUrl, Is.EqualTo("https://env-cn.example.test"));
        }

        [Test]
        public void CreateDefault_WhenEditorPrefsAndEnvironmentPayloadsExist_PrefersEditorPrefsOverride()
        {
            EditorPrefs.SetString(
                IconAiSplitServiceFactory.TccPayloadEditorPrefsKey,
                CreateOuterPayload(CreateConfigJson("https://prefs-cn.example.test")));
            Environment.SetEnvironmentVariable(
                IconAiSplitServiceFactory.TccPayloadEnvironmentVariable,
                CreateOuterPayload(CreateConfigJson("https://env-cn.example.test")));
            IconAiSplitServiceFactory factory = IconAiSplitServiceFactory.CreateDefault();

            AiSplitTccLoadResult result = factory.LoadConfiguration(forceRefresh: true);

            Assert.That(result.Success, Is.True, result.ErrorMessage);
            Assert.That(result.SelectedRegion.Region, Is.EqualTo("cn"));
            Assert.That(result.SelectedRegion.ApiBaseUrl, Is.EqualTo("https://prefs-cn.example.test"));
        }

        private static string CreateOuterPayload(string aiSplitConfig)
        {
            return "{\"data\":{\"ai_split_config\":\"" + EscapeJsonString(aiSplitConfig) + "\"}}";
        }

        private static string CreateConfigJson(string cnApiBaseUrl)
        {
            return "{"
                + "\"enable\":true,"
                + "\"regions\":["
                + CreateRegionJson("internal", "https://internal.example.test")
                + ","
                + CreateRegionJson("cn", cnApiBaseUrl)
                + ","
                + CreateRegionJson("global", "https://global.example.test")
                + "],"
                + "\"api\":{\"generate_path\":\"/sdf/gen\",\"info_path\":\"/sdf/info\"},"
                + "\"tos\":{\"bucket_name\":\"icon-bucket\",\"object_directory\":\"icons\","
                + "\"public_base_url\":\"https://cdn.example.test\"},"
                + "\"signing\":{\"app_id\":\"app-id\",\"salt\":\"salt\"}"
                + "}";
        }

        private static string CreateRegionJson(string region, string apiBaseUrl)
        {
            return "{\"region\":\"" + region + "\",\"api_base_url\":\"" + EscapeJsonString(apiBaseUrl) + "\"}";
        }

        private static string EscapeJsonString(string value)
        {
            return (value ?? string.Empty)
                .Replace("\\", "\\\\")
                .Replace("\"", "\\\"")
                .Replace("\r", "\\r")
                .Replace("\n", "\\n");
        }
    }
}
