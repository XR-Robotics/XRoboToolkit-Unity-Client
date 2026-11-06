using System.Collections.Generic;
using System.IO;
using NUnit.Framework;
using UnityEditor;
using UnityEngine;

namespace ByteDance.PICO.IconConfigurator.Editor.Tests
{
    public class IconApplyExportIntegrationTests
    {
        private const string k_ConfigGuid = "export-test-guid";
        private const string k_OutputRoot = "Assets/IconConfigurator/Generated/export-test-guid";
        private const string k_AndroidOutputRoot = "Assets/IconConfigurator/Output";
        private const string k_AndroidPluginResRoot = "Assets/Plugins/Android/IconConfigurator.androidlib/res";
        private const string k_ObsoleteAndroidPluginResRoot = "Assets/Plugins/Android/res";
        private const string k_DuplicateAndroidLibraryRoot = "Assets/Plugins/Android/IconConfigurator 1.androidlib";
        private const string k_DuplicateAndroidLibraryMetaPath = "Assets/Plugins/Android/IconConfigurator 1.androidlib.meta";

        [SetUp]
        public void SetUp()
        {
            DeleteAssetIfExists(k_OutputRoot);
            DeleteAssetIfExists(k_AndroidOutputRoot);
            DeleteAssetIfExists(k_AndroidPluginResRoot);
            DeleteAssetIfExists(k_ObsoleteAndroidPluginResRoot);
            DeleteAssetIfExists(k_DuplicateAndroidLibraryRoot);
            DeleteFileIfExists(k_DuplicateAndroidLibraryMetaPath);
            AssetDatabase.Refresh();
        }

        [TearDown]
        public void TearDown()
        {
            DeleteAssetIfExists(k_OutputRoot);
            DeleteAssetIfExists(k_AndroidOutputRoot);
            DeleteAssetIfExists(k_AndroidPluginResRoot);
            DeleteAssetIfExists(k_ObsoleteAndroidPluginResRoot);
            DeleteAssetIfExists(k_DuplicateAndroidLibraryRoot);
            DeleteFileIfExists(k_DuplicateAndroidLibraryMetaPath);
            AssetDatabase.Refresh();
        }

        [Test]
        public void Apply_WhenManualConfigProvided_ExportsSdfLauncherAndAndroidResourceFiles()
        {
            IconConfiguratorConfigAsset config = ScriptableObject.CreateInstance<IconConfiguratorConfigAsset>();
            try
            {
                config.LastMode = IconConfiguratorMode.Manual;
                config.Manual.Layers = new List<IconLayerConfig>
                {
                    CreateLayer(IconLayerKind.Background, "Assets/IconConfigurator/Imported/background.png", CreateMaskTexture(Color.red)),
                    CreateLayer(IconLayerKind.Foreground1, "Assets/IconConfigurator/Imported/foreground1.png", CreateMaskTexture(Color.green)),
                    CreateLayer(IconLayerKind.Foreground2, "Assets/IconConfigurator/Imported/foreground2.png", CreateMaskTexture(Color.blue)),
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
                    new LocalizationEntry
                    {
                        LocaleCode = "zh-CN",
                        AppName = "图标功能",
                        CanRemove = true,
                    },
                    new LocalizationEntry
                    {
                        LocaleCode = "ja-JP",
                        AppName = "アイコン機能",
                        CanRemove = true,
                    },
                    new LocalizationEntry
                    {
                        LocaleCode = "ko-KR",
                        AppName = "아이콘 기능",
                        CanRemove = true,
                    },
                };

                Directory.CreateDirectory(k_DuplicateAndroidLibraryRoot);
                File.WriteAllText(k_DuplicateAndroidLibraryMetaPath, "fileFormatVersion: 2\n");

                IconApplyService service = new IconApplyService(
                    new IconConfiguratorValidator(),
                    new IconCompositePreviewService(),
                    new List<IIconExportAdapter>
                    {
                        new LayeredIconExportAdapter(),
                        new AndroidAppNameExportAdapter(),
                    });

                service.Apply(config, k_ConfigGuid);

                Assert.That(File.Exists($"{k_OutputRoot}/layers/background.png"), Is.True);
                Assert.That(File.Exists($"{k_OutputRoot}/layers/foreground1.png"), Is.True);
                Assert.That(File.Exists($"{k_OutputRoot}/layers/foreground2.png"), Is.True);
                Assert.That(File.Exists($"{k_OutputRoot}/sdf/background.png"), Is.True);
                Assert.That(File.Exists($"{k_OutputRoot}/sdf/foreground1.png"), Is.True);
                Assert.That(File.Exists($"{k_OutputRoot}/sdf/foreground2.png"), Is.True);
                Assert.That(File.Exists($"{k_OutputRoot}/launcher/launcher.png"), Is.True);

                Assert.That(File.Exists("Assets/IconConfigurator/Output/Android/res/drawable/icon_3d_layer_0.png"), Is.True);
                Assert.That(File.Exists("Assets/IconConfigurator/Output/Android/res/drawable/icon_3d_layer_1.png"), Is.True);
                Assert.That(File.Exists("Assets/IconConfigurator/Output/Android/res/drawable/icon_3d_layer_2.png"), Is.True);
                Assert.That(File.Exists("Assets/IconConfigurator/Output/Android/res/drawable/icon_3d_sdf_0.png"), Is.True);
                Assert.That(File.Exists("Assets/IconConfigurator/Output/Android/res/drawable/icon_3d_sdf_1.png"), Is.True);
                Assert.That(File.Exists("Assets/IconConfigurator/Output/Android/res/drawable/icon_3d_sdf_2.png"), Is.True);
                Assert.That(File.Exists("Assets/IconConfigurator/Output/Android/res/mipmap-mdpi/ic_spatial_launcher.png"), Is.True);
                Assert.That(File.Exists("Assets/IconConfigurator/Output/Android/res/values/drawables_3d.xml"), Is.True);
                Assert.That(File.Exists("Assets/IconConfigurator/Output/Android/res/xml/locales_config.xml"), Is.True);
                Assert.That(File.Exists("Assets/IconConfigurator/Output/Android/res/values/strings.xml"), Is.True);
                Assert.That(File.Exists("Assets/IconConfigurator/Output/Android/res/values-zh-rCN/strings.xml"), Is.True);
                Assert.That(File.Exists("Assets/IconConfigurator/Output/Android/res/values-ja/strings.xml"), Is.True);
                Assert.That(File.Exists("Assets/IconConfigurator/Output/Android/res/values-ko/strings.xml"), Is.True);
                Assert.That(Directory.Exists("Assets/Plugins/Android/res"), Is.False);
                Assert.That(Directory.Exists(k_DuplicateAndroidLibraryRoot), Is.False);
                Assert.That(File.Exists(k_DuplicateAndroidLibraryMetaPath), Is.False);
                Assert.That(File.Exists("Assets/Plugins/Android/IconConfigurator.androidlib/project.properties"), Is.True);
                Assert.That(File.Exists("Assets/Plugins/Android/IconConfigurator.androidlib/AndroidManifest.xml"), Is.True);
                Assert.That(File.Exists("Assets/Plugins/Android/IconConfigurator.androidlib/res/drawable/icon_3d_layer_0.png"), Is.True);
                Assert.That(File.Exists("Assets/Plugins/Android/IconConfigurator.androidlib/res/drawable/icon_3d_sdf_0.png"), Is.True);
                Assert.That(File.Exists("Assets/Plugins/Android/IconConfigurator.androidlib/res/mipmap-mdpi/ic_spatial_launcher.png"), Is.True);
                Assert.That(File.Exists("Assets/Plugins/Android/IconConfigurator.androidlib/res/values/drawables_3d.xml"), Is.True);
                Assert.That(File.Exists("Assets/Plugins/Android/IconConfigurator.androidlib/res/values-ja/strings.xml"), Is.True);
                Assert.That(File.Exists("Assets/Plugins/Android/IconConfigurator.androidlib/res/values-ko/strings.xml"), Is.True);
                Assert.That(File.Exists("Assets/Plugins/Android/IconConfigurator.androidlib/res/xml/locales_config.xml"), Is.True);

                byte[] layerBytes = File.ReadAllBytes($"{k_OutputRoot}/layers/background.png");
                byte[] sdfBytes = File.ReadAllBytes($"{k_OutputRoot}/sdf/background.png");
                Assert.That(sdfBytes, Is.Not.EqualTo(layerBytes));

                string drawablesXml = File.ReadAllText("Assets/IconConfigurator/Output/Android/res/values/drawables_3d.xml");
                Assert.That(drawablesXml, Does.Contain("icon_3d_list"));
                Assert.That(drawablesXml, Does.Contain("icon_sdf_list"));
                Assert.That(drawablesXml, Does.Contain("@drawable/icon_3d_layer_0"));
                Assert.That(drawablesXml, Does.Contain("@drawable/icon_3d_sdf_2"));
                Assert.That(
                    drawablesXml.IndexOf("@drawable/icon_3d_layer_2", System.StringComparison.Ordinal),
                    Is.LessThan(drawablesXml.IndexOf("@drawable/icon_3d_layer_1", System.StringComparison.Ordinal)));
                Assert.That(
                    drawablesXml.IndexOf("@drawable/icon_3d_layer_1", System.StringComparison.Ordinal),
                    Is.LessThan(drawablesXml.IndexOf("@drawable/icon_3d_layer_0", System.StringComparison.Ordinal)));
                Assert.That(
                    drawablesXml.IndexOf("@drawable/icon_3d_sdf_2", System.StringComparison.Ordinal),
                    Is.LessThan(drawablesXml.IndexOf("@drawable/icon_3d_sdf_1", System.StringComparison.Ordinal)));
                Assert.That(
                    drawablesXml.IndexOf("@drawable/icon_3d_sdf_1", System.StringComparison.Ordinal),
                    Is.LessThan(drawablesXml.IndexOf("@drawable/icon_3d_sdf_0", System.StringComparison.Ordinal)));

                string localesXml = File.ReadAllText("Assets/IconConfigurator/Output/Android/res/xml/locales_config.xml");
                Assert.That(localesXml, Does.Contain("locale-config"));
                Assert.That(localesXml, Does.Contain("android:name=\"en-US\""));
                Assert.That(localesXml, Does.Contain("android:name=\"zh-CN\""));

                string defaultStringsXml = File.ReadAllText("Assets/IconConfigurator/Output/Android/res/values/strings.xml");
                string zhCnStringsXml = File.ReadAllText("Assets/IconConfigurator/Output/Android/res/values-zh-rCN/strings.xml");
                Assert.That(defaultStringsXml, Does.Contain("name=\"icon_configurator_app_name\""));
                Assert.That(defaultStringsXml, Does.Not.Contain("name=\"app_name\""));
                Assert.That(zhCnStringsXml, Does.Contain("name=\"icon_configurator_app_name\""));
                Assert.That(defaultStringsXml, Does.Contain("Icon Feature"));
                Assert.That(zhCnStringsXml, Does.Contain("图标功能"));
            }
            finally
            {
                DestroyLayerTextures(config);
                Object.DestroyImmediate(config);
            }
        }

        [Test]
        public void AndroidAppNameExportAdapter_WhenCloudSdfLayerIsMissing_DoesNotReferenceMissingSdfDrawable()
        {
            Texture2D background = CreateMaskTexture(Color.red);
            Texture2D foreground = CreateMaskTexture(Color.green);
            Texture2D backgroundSdf = CreateMaskTexture(Color.white);
            IconApplyPayload payload = new IconApplyPayload
            {
                Layers = new List<IconLayerConfig>
                {
                    CreateLayer(IconLayerKind.Background, "Assets/IconConfigurator/Generated/background.png", background),
                    CreateLayer(IconLayerKind.Foreground1, "Assets/IconConfigurator/Generated/foreground.png", foreground),
                },
                SdfLayers = new List<IconLayerConfig>
                {
                    CreateLayer(IconLayerKind.Background, "Assets/IconConfigurator/Generated/background-sdf.png", backgroundSdf),
                    new IconLayerConfig(),
                },
                UseCloudSdfs = true,
                Localizations = new List<LocalizationEntry>(),
            };

            try
            {
                AndroidAppNameExportAdapter adapter = new AndroidAppNameExportAdapter();

                adapter.Apply(payload);

                string drawablesXml = File.ReadAllText("Assets/IconConfigurator/Output/Android/res/values/drawables_3d.xml");
                Assert.That(drawablesXml, Does.Contain("@drawable/icon_3d_layer_1"));
                Assert.That(drawablesXml, Does.Contain("@drawable/icon_3d_layer_0"));
                Assert.That(drawablesXml, Does.Contain("@drawable/icon_3d_sdf_0"));
                Assert.That(drawablesXml, Does.Not.Contain("@drawable/icon_3d_sdf_1"));
                Assert.That(File.Exists("Assets/IconConfigurator/Output/Android/res/drawable/icon_3d_sdf_0.png"), Is.True);
                Assert.That(File.Exists("Assets/IconConfigurator/Output/Android/res/drawable/icon_3d_sdf_1.png"), Is.False);
            }
            finally
            {
                DestroyTexture(background);
                DestroyTexture(foreground);
                DestroyTexture(backgroundSdf);
            }
        }

        private static IconLayerConfig CreateLayer(IconLayerKind layerKind, string assetPath, Texture2D texture)
        {
            return new IconLayerConfig
            {
                LayerKind = layerKind,
                AssetGuid = $"guid-{layerKind}",
                AssetPath = assetPath,
                OriginalFileName = Path.GetFileName(assetPath),
                Texture = texture,
            };
        }

        private static Texture2D CreateMaskTexture(Color color)
        {
            Texture2D texture = new Texture2D(8, 8, TextureFormat.RGBA32, false);
            Color transparent = new Color(0f, 0f, 0f, 0f);

            for (int y = 0; y < texture.height; y++)
            {
                for (int x = 0; x < texture.width; x++)
                {
                    bool isFilled = x >= 2 && x <= 5 && y >= 2 && y <= 5;
                    texture.SetPixel(x, y, isFilled ? new Color(color.r, color.g, color.b, 1f) : transparent);
                }
            }

            texture.Apply();
            return texture;
        }

        private static void DeleteAssetIfExists(string path)
        {
            if (AssetDatabase.LoadAssetAtPath<Object>(path) != null || AssetDatabase.IsValidFolder(path))
            {
                AssetDatabase.DeleteAsset(path);
            }
        }

        private static void DeleteFileIfExists(string path)
        {
            if (File.Exists(path))
            {
                File.Delete(path);
            }
        }

        private static void DestroyLayerTextures(IconConfiguratorConfigAsset config)
        {
            if (config?.Manual?.Layers == null)
            {
                return;
            }

            for (int i = 0; i < config.Manual.Layers.Count; i++)
            {
                DestroyTexture(config.Manual.Layers[i]?.Texture);
            }
        }

        private static void DestroyTexture(Texture2D texture)
        {
            if (texture != null)
            {
                Object.DestroyImmediate(texture);
            }
        }
    }
}
