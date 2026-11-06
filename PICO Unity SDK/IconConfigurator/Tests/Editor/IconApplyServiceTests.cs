using System.Collections.Generic;
using NUnit.Framework;
using UnityEngine;

namespace ByteDance.PICO.IconConfigurator.Editor.Tests
{
    public class IconApplyServiceTests
    {
        [Test]
        public void CreatePayload_WhenManualConfigProvided_UsesStableOutputDirectories()
        {
            IconConfiguratorConfigAsset config = ScriptableObject.CreateInstance<IconConfiguratorConfigAsset>();
            config.LastMode = IconConfiguratorMode.Manual;
            config.Manual.Layers = new List<IconLayerConfig>
            {
                CreateLayer(IconLayerKind.Background, "Assets/IconConfigurator/Imported/background.png"),
                CreateLayer(IconLayerKind.Foreground1, "Assets/IconConfigurator/Imported/foreground1.png"),
                CreateLayer(IconLayerKind.Foreground2, "Assets/IconConfigurator/Imported/foreground2.png"),
                CreateLayer(IconLayerKind.Foreground2, "Assets/IconConfigurator/Imported/foreground3.png"),
            };
            config.Localizations = new List<LocalizationEntry>
            {
                new LocalizationEntry
                {
                    LocaleCode = "en-US",
                    AppName = "Icon Feature",
                    IsDefault = true,
                    CanRemove = false,
                },
            };
            IconApplyService service = new IconApplyService(
                new IconConfiguratorValidator(),
                new IconCompositePreviewService(),
                new List<IIconExportAdapter>());

            IconApplyPayload payload = service.CreatePayload(config, "cfg123");

            Assert.That(payload.ConfigGuid, Is.EqualTo("cfg123"));
            Assert.That(payload.OutputRootPath, Is.EqualTo("Assets/IconConfigurator/Generated/cfg123"));
            Assert.That(payload.LayersOutputPath, Is.EqualTo("Assets/IconConfigurator/Generated/cfg123/layers"));
            Assert.That(payload.PreviewOutputPath, Is.EqualTo("Assets/IconConfigurator/Generated/cfg123/preview"));
            Assert.That(payload.MetadataOutputPath, Is.EqualTo("Assets/IconConfigurator/Generated/cfg123/metadata"));
            Assert.That(payload.Layers.Count, Is.EqualTo(4));
            Assert.That(payload.Layers[0].AssetPath, Is.EqualTo("Assets/IconConfigurator/Imported/background.png"));
            Assert.That(payload.Layers[3].AssetPath, Is.EqualTo("Assets/IconConfigurator/Imported/foreground3.png"));
        }

        [TestCase("en-US", "Assets/IconConfigurator/Output/Android/res/values/strings.xml")]
        [TestCase("zh-CN", "Assets/IconConfigurator/Output/Android/res/values-zh-rCN/strings.xml")]
        [TestCase("ja-JP", "Assets/IconConfigurator/Output/Android/res/values-ja/strings.xml")]
        [TestCase("ko-KR", "Assets/IconConfigurator/Output/Android/res/values-ko/strings.xml")]
        [TestCase("de-DE", "Assets/IconConfigurator/Output/Android/res/values-de/strings.xml")]
        [TestCase("fr-FR", "Assets/IconConfigurator/Output/Android/res/values-fr/strings.xml")]
        public void GetAndroidStringFilePath_WhenLocaleProvided_ReturnsMappedPath(
            string localeCode,
            string expectedPath)
        {
            string actualPath = IconApplyService.GetAndroidStringFilePath(localeCode);

            Assert.That(actualPath, Is.EqualTo(expectedPath));
        }

        [Test]
        public void CreatePayload_WhenCalledTwiceWithSameGuid_IsIdempotent()
        {
            IconConfiguratorConfigAsset config = ScriptableObject.CreateInstance<IconConfiguratorConfigAsset>();
            config.LastMode = IconConfiguratorMode.Manual;
            config.Manual.Layers = new List<IconLayerConfig>
            {
                CreateLayer(IconLayerKind.Background, "Assets/IconConfigurator/Imported/background.png"),
                CreateLayer(IconLayerKind.Foreground1, "Assets/IconConfigurator/Imported/foreground1.png"),
            };
            config.Localizations = new List<LocalizationEntry>
            {
                new LocalizationEntry
                {
                    LocaleCode = "en-US",
                    AppName = "Icon Feature",
                    IsDefault = true,
                    CanRemove = false,
                },
            };
            IconApplyService service = new IconApplyService(
                new IconConfiguratorValidator(),
                new IconCompositePreviewService(),
                new List<IIconExportAdapter>());

            IconApplyPayload first = service.CreatePayload(config, "same-guid");
            IconApplyPayload second = service.CreatePayload(config, "same-guid");

            Assert.That(second.OutputRootPath, Is.EqualTo(first.OutputRootPath));
            Assert.That(second.LayersOutputPath, Is.EqualTo(first.LayersOutputPath));
        }

        [Test]
        public void CreatePayload_WhenAiSucceeded_UsesDynamicGeneratedLayersAndCloudSdfs()
        {
            IconConfiguratorConfigAsset config = ScriptableObject.CreateInstance<IconConfiguratorConfigAsset>();
            config.LastMode = IconConfiguratorMode.AiSplit;
            config.AiSplit.Status = GenerateStatus.Succeeded;
            config.AiSplit.GeneratedLayers = new List<IconLayerConfig>
            {
                CreateLayer(IconLayerKind.Background, "Assets/IconConfigurator/Generated/cfg/ai-split/task/layers/background.png"),
                CreateLayer(IconLayerKind.Foreground1, "Assets/IconConfigurator/Generated/cfg/ai-split/task/layers/foreground1.png"),
                CreateLayer(IconLayerKind.Foreground2, "Assets/IconConfigurator/Generated/cfg/ai-split/task/layers/foreground2.png"),
                CreateLayer(IconLayerKind.Foreground2, "Assets/IconConfigurator/Generated/cfg/ai-split/task/layers/foreground3.png"),
            };
            config.AiSplit.GeneratedSdfs = new List<IconLayerConfig>
            {
                CreateLayer(IconLayerKind.Background, "Assets/IconConfigurator/Generated/cfg/ai-split/task/sdf/background.png"),
                CreateLayer(IconLayerKind.Foreground1, "Assets/IconConfigurator/Generated/cfg/ai-split/task/sdf/foreground1.png"),
                CreateLayer(IconLayerKind.Foreground2, "Assets/IconConfigurator/Generated/cfg/ai-split/task/sdf/foreground2.png"),
                CreateLayer(IconLayerKind.Foreground2, "Assets/IconConfigurator/Generated/cfg/ai-split/task/sdf/foreground3.png"),
            };
            config.Localizations = new List<LocalizationEntry>
            {
                new LocalizationEntry
                {
                    LocaleCode = "en-US",
                    AppName = "Icon Feature",
                    IsDefault = true,
                    CanRemove = false,
                },
            };
            IconApplyService service = new IconApplyService(
                new IconConfiguratorValidator(),
                new IconCompositePreviewService(),
                new List<IIconExportAdapter>());

            IconApplyPayload payload = service.CreatePayload(config, "cfg");

            Assert.That(payload.Layers, Has.Count.EqualTo(4));
            Assert.That(payload.Layers[3].AssetPath, Does.EndWith("layers/foreground3.png"));
            Assert.That(payload.SdfLayers, Has.Count.EqualTo(4));
            Assert.That(payload.SdfLayers[3].AssetPath, Does.EndWith("sdf/foreground3.png"));
            Assert.That(payload.UseCloudSdfs, Is.True);
        }

        [Test]
        public void CreatePreflight_WhenSomeOutputsExist_ReportsOverwriteTargets()
        {
            IconConfiguratorConfigAsset config = ScriptableObject.CreateInstance<IconConfiguratorConfigAsset>();
            config.LastMode = IconConfiguratorMode.Manual;
            config.Manual.Layers = new List<IconLayerConfig>
            {
                CreateLayer(IconLayerKind.Background, "Assets/IconConfigurator/Imported/background.png"),
                CreateLayer(IconLayerKind.Foreground1, "Assets/IconConfigurator/Imported/foreground1.png"),
            };
            config.Localizations = new List<LocalizationEntry>
            {
                new LocalizationEntry
                {
                    LocaleCode = "en-US",
                    AppName = "Icon Feature",
                    IsDefault = true,
                    CanRemove = false,
                },
            };
            IconApplyService service = new IconApplyService(
                new IconConfiguratorValidator(),
                new IconCompositePreviewService(),
                new List<IIconExportAdapter>());

            IconApplyPreflightResult preflight = service.CreatePreflight(
                config,
                "cfg123",
                new[]
                {
                    "Assets/IconConfigurator/Generated/cfg123/layers/background.png",
                    "Assets/IconConfigurator/Output/Android/res/values/strings.xml",
                });

            Assert.That(preflight.PlannedWritePaths, Has.Count.GreaterThan(0));
            Assert.That(preflight.OverwritePaths, Has.Count.EqualTo(2));
        }

        [Test]
        public void CreatePreflight_WhenPreviewServiceMissing_DoesNotRequirePreviewTexture()
        {
            IconConfiguratorConfigAsset config = ScriptableObject.CreateInstance<IconConfiguratorConfigAsset>();
            config.LastMode = IconConfiguratorMode.Manual;
            config.Manual.Layers = new List<IconLayerConfig>
            {
                CreateLayer(IconLayerKind.Background, "Assets/IconConfigurator/Imported/background.png"),
                CreateLayer(IconLayerKind.Foreground1, "Assets/IconConfigurator/Imported/foreground1.png"),
            };
            config.Localizations = new List<LocalizationEntry>
            {
                new LocalizationEntry
                {
                    LocaleCode = "en-US",
                    AppName = "Icon Feature",
                    IsDefault = true,
                    CanRemove = false,
                },
            };
            IconApplyService service = new IconApplyService(
                new IconConfiguratorValidator(),
                null,
                new List<IIconExportAdapter>());

            IconApplyPreflightResult preflight = service.CreatePreflight(config, "cfg123");

            Assert.That(preflight.PlannedWritePaths, Has.Count.GreaterThan(0));
        }

        [Test]
        public void CreatePreflight_WhenLocaleRemoved_ReportsStaleLocaleFileForDeletion()
        {
            IconConfiguratorConfigAsset config = ScriptableObject.CreateInstance<IconConfiguratorConfigAsset>();
            config.LastMode = IconConfiguratorMode.Manual;
            config.Manual.Layers = new List<IconLayerConfig>
            {
                CreateLayer(IconLayerKind.Background, "Assets/IconConfigurator/Imported/background.png"),
                CreateLayer(IconLayerKind.Foreground1, "Assets/IconConfigurator/Imported/foreground1.png"),
            };
            config.Localizations = new List<LocalizationEntry>
            {
                new LocalizationEntry
                {
                    LocaleCode = "en-US",
                    AppName = "Icon Feature",
                    IsDefault = true,
                    CanRemove = false,
                },
            };
            IconApplyService service = new IconApplyService(
                new IconConfiguratorValidator(),
                new IconCompositePreviewService(),
                new List<IIconExportAdapter>());

            IconApplyPreflightResult preflight = service.CreatePreflight(
                config,
                "cfg123",
                new[]
                {
                    "Assets/IconConfigurator/Output/Android/res/values-ja/strings.xml",
                    "Assets/IconConfigurator/Output/Android/res/values-ja/strings.xml.meta",
                    "Assets/Plugins/Android/IconConfigurator.androidlib/res/values-ja/strings.xml",
                    "Assets/Plugins/Android/IconConfigurator.androidlib/res/values-ja/strings.xml.meta",
                });

            Assert.That(
                preflight.DeletePaths,
                Does.Contain("Assets/IconConfigurator/Output/Android/res/values-ja/strings.xml"));
            Assert.That(
                preflight.DeletePaths,
                Does.Contain("Assets/IconConfigurator/Output/Android/res/values-ja/strings.xml.meta"));
            Assert.That(
                preflight.DeletePaths,
                Does.Contain("Assets/Plugins/Android/IconConfigurator.androidlib/res/values-ja/strings.xml"));
            Assert.That(
                preflight.DeletePaths,
                Does.Contain("Assets/Plugins/Android/IconConfigurator.androidlib/res/values-ja/strings.xml.meta"));
        }

        [Test]
        public void CreatePreflight_WhenLegacyUnsupportedLocaleFilesExist_ReportsThemForDeletion()
        {
            IconConfiguratorConfigAsset config = ScriptableObject.CreateInstance<IconConfiguratorConfigAsset>();
            config.LastMode = IconConfiguratorMode.Manual;
            config.Manual.Layers = new List<IconLayerConfig>
            {
                CreateLayer(IconLayerKind.Background, "Assets/IconConfigurator/Imported/background.png"),
                CreateLayer(IconLayerKind.Foreground1, "Assets/IconConfigurator/Imported/foreground1.png"),
            };
            config.Localizations = new List<LocalizationEntry>
            {
                new LocalizationEntry
                {
                    LocaleCode = "en-US",
                    AppName = "Icon Feature",
                    IsDefault = true,
                    CanRemove = false,
                },
            };
            IconApplyService service = new IconApplyService(
                new IconConfiguratorValidator(),
                new IconCompositePreviewService(),
                new List<IIconExportAdapter>());

            IconApplyPreflightResult preflight = service.CreatePreflight(
                config,
                "cfg123",
                new[]
                {
                    "Assets/IconConfigurator/Output/Android/res/values-de/strings.xml",
                    "Assets/IconConfigurator/Output/Android/res/values-fr/strings.xml",
                    "Assets/Plugins/Android/IconConfigurator.androidlib/res/values-de/strings.xml",
                    "Assets/Plugins/Android/IconConfigurator.androidlib/res/values-fr/strings.xml",
                });

            Assert.That(
                preflight.DeletePaths,
                Does.Contain("Assets/IconConfigurator/Output/Android/res/values-de/strings.xml"));
            Assert.That(
                preflight.DeletePaths,
                Does.Contain("Assets/IconConfigurator/Output/Android/res/values-fr/strings.xml"));
            Assert.That(
                preflight.DeletePaths,
                Does.Contain("Assets/Plugins/Android/IconConfigurator.androidlib/res/values-de/strings.xml"));
            Assert.That(
                preflight.DeletePaths,
                Does.Contain("Assets/Plugins/Android/IconConfigurator.androidlib/res/values-fr/strings.xml"));
        }

        [Test]
        public void CreatePreflight_WhenAndroidPluginCleanupTargetsExist_ReportsDirectoryDeletes()
        {
            IconConfiguratorConfigAsset config = ScriptableObject.CreateInstance<IconConfiguratorConfigAsset>();
            config.LastMode = IconConfiguratorMode.Manual;
            config.Manual.Layers = new List<IconLayerConfig>
            {
                CreateLayer(IconLayerKind.Background, "Assets/IconConfigurator/Imported/background.png"),
                CreateLayer(IconLayerKind.Foreground1, "Assets/IconConfigurator/Imported/foreground1.png"),
            };
            config.Localizations = new List<LocalizationEntry>
            {
                new LocalizationEntry
                {
                    LocaleCode = "en-US",
                    AppName = "Icon Feature",
                    IsDefault = true,
                    CanRemove = false,
                },
            };
            IconApplyService service = new IconApplyService(
                new IconConfiguratorValidator(),
                new IconCompositePreviewService(),
                new List<IIconExportAdapter>());

            IconApplyPreflightResult preflight = service.CreatePreflight(
                config,
                "cfg123",
                new[]
                {
                    "Assets/Plugins/Android/res/drawable/legacy.png",
                    "Assets/Plugins/Android/res.meta",
                    "Assets/Plugins/Android/IconConfigurator 1.androidlib/res/values/strings.xml",
                    "Assets/Plugins/Android/IconConfigurator 1.androidlib.meta",
                });

            Assert.That(
                preflight.DeletePaths,
                Does.Contain("Assets/Plugins/Android/res"));
            Assert.That(
                preflight.DeletePaths,
                Does.Contain("Assets/Plugins/Android/res.meta"));
            Assert.That(
                preflight.DeletePaths,
                Does.Contain("Assets/Plugins/Android/IconConfigurator 1.androidlib"));
            Assert.That(
                preflight.DeletePaths,
                Does.Contain("Assets/Plugins/Android/IconConfigurator 1.androidlib.meta"));
        }

        [Test]
        public void ExportAdapters_WhenCloudSdfsAreProvided_ReadSdfLayersInsteadOfRegeneratingFromAiLayers()
        {
            string layeredSource = System.IO.File.ReadAllText(
                "Packages/sdk/IconConfigurator/Editor/Export/LayeredIconExportAdapter.cs");
            string androidSource = System.IO.File.ReadAllText(
                "Packages/sdk/IconConfigurator/Editor/Export/AndroidAppNameExportAdapter.cs");

            Assert.That(layeredSource.Contains("payload.SdfLayers"), Is.True);
            Assert.That(androidSource.Contains("payload.SdfLayers"), Is.True);
            Assert.That(layeredSource.Contains("WriteSdfTexture(payload.Layers[i]"), Is.False);
            Assert.That(androidSource.Contains("WriteSdfTexture(payload.Layers[i]"), Is.False);
        }

        private static IconLayerConfig CreateLayer(IconLayerKind layerKind, string assetPath)
        {
            return new IconLayerConfig
            {
                LayerKind = layerKind,
                AssetGuid = "guid",
                AssetPath = assetPath,
                OriginalFileName = System.IO.Path.GetFileName(assetPath),
            };
        }
    }
}
