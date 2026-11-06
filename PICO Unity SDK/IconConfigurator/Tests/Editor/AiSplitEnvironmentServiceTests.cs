using NUnit.Framework;
using UnityEditor;

namespace ByteDance.PICO.IconConfigurator.Editor.Tests
{
    public class AiSplitEnvironmentServiceTests
    {
        [SetUp]
        public void SetUp()
        {
            EditorPrefs.DeleteKey(AiSplitEnvironmentService.PpeInternalEditorPrefsKey);
            EditorPrefs.DeleteKey(AiSplitEnvironmentService.RegionOverrideEditorPrefsKey);
        }

        [TearDown]
        public void TearDown()
        {
            EditorPrefs.DeleteKey(AiSplitEnvironmentService.PpeInternalEditorPrefsKey);
            EditorPrefs.DeleteKey(AiSplitEnvironmentService.RegionOverrideEditorPrefsKey);
        }

        [Test]
        public void ResolvePreference_WhenRegionOverrideIsCn_ReturnsCn()
        {
            EditorPrefs.SetString(
                AiSplitEnvironmentService.RegionOverrideEditorPrefsKey,
                AiSplitRegionPreference.Cn.ToString());
            AiSplitEnvironmentService service = new AiSplitEnvironmentService(
                () => true,
                key => key == AiSplitEnvironmentService.SpatialGlobalEnvironmentVariable ? "true" : null);

            Assert.That(service.ResolvePreference(), Is.EqualTo(AiSplitRegionPreference.Cn));
            Assert.That(service.ResolveRegionKey(), Is.EqualTo("cn"));
        }

        [Test]
        public void ResolvePreference_WhenRegionOverrideIsGlobal_ReturnsGlobal()
        {
            EditorPrefs.SetString(
                AiSplitEnvironmentService.RegionOverrideEditorPrefsKey,
                AiSplitRegionPreference.Global.ToString());
            AiSplitEnvironmentService service = new AiSplitEnvironmentService(
                () => false,
                _ => null);

            Assert.That(service.ResolvePreference(), Is.EqualTo(AiSplitRegionPreference.Global));
            Assert.That(service.ResolveRegionKey(), Is.EqualTo("global"));
        }

        [Test]
        public void ResolvePreference_WhenSpatialPluginEnvInternalIsEnabled_ReturnsInternal()
        {
            AiSplitEnvironmentService service = new AiSplitEnvironmentService(
                () => true,
                _ => null);

            Assert.That(service.ResolvePreference(), Is.EqualTo(AiSplitRegionPreference.Internal));
            Assert.That(service.ResolveRegionKey(), Is.EqualTo("internal"));
        }

        [TestCase("1")]
        [TestCase("true")]
        [TestCase("TRUE")]
        public void ResolvePreference_WhenSpatialGlobalEnvironmentIsEnabled_ReturnsGlobal(string value)
        {
            AiSplitEnvironmentService service = new AiSplitEnvironmentService(
                () => false,
                key => key == AiSplitEnvironmentService.SpatialGlobalEnvironmentVariable ? value : null);

            Assert.That(service.ResolvePreference(), Is.EqualTo(AiSplitRegionPreference.Global));
            Assert.That(service.ResolveRegionKey(), Is.EqualTo("global"));
        }

        [Test]
        public void ResolvePreference_WhenNoOverridesAreSet_ReturnsCn()
        {
            AiSplitEnvironmentService service = new AiSplitEnvironmentService(
                () => false,
                _ => null);

            Assert.That(service.ResolvePreference(), Is.EqualTo(AiSplitRegionPreference.Cn));
            Assert.That(service.ResolveRegionKey(), Is.EqualTo("cn"));
        }
    }
}
