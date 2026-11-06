using System.IO;
using NUnit.Framework;
using UnityEditor;
using UnityEngine;

namespace ByteDance.PICO.IconConfigurator.Editor.Tests
{
    public class IconConfiguratorStateStoreTests
    {
        private const string k_SettingsDirectory = "Assets/IconConfigurator/Settings";
        private const string k_ImportedDirectory = "Assets/IconConfigurator/Imported";
        private const string k_ConfigAssetPath = "Assets/IconConfigurator/Settings/IconConfiguratorConfig.asset";

        [SetUp]
        public void SetUp()
        {
            DeleteAssetIfExists(k_ConfigAssetPath);
            DeleteAssetIfExists(k_SettingsDirectory);
            DeleteAssetIfExists(k_ImportedDirectory);
            AssetDatabase.Refresh();
        }

        [TearDown]
        public void TearDown()
        {
            DeleteAssetIfExists(k_ConfigAssetPath);
            DeleteAssetIfExists(k_SettingsDirectory);
            DeleteAssetIfExists(k_ImportedDirectory);
            AssetDatabase.Refresh();
        }

        [Test]
        public void LoadOrCreateConfigAsset_WhenMissing_CreatesAssetAtFixedPath()
        {
            IconConfiguratorStateStore stateStore = new IconConfiguratorStateStore();

            IconConfiguratorConfigAsset config = stateStore.LoadOrCreateConfigAsset();

            Assert.That(config, Is.Not.Null);
            Assert.That(AssetDatabase.LoadAssetAtPath<IconConfiguratorConfigAsset>(k_ConfigAssetPath), Is.Not.Null);
        }

        [Test]
        public void LoadOrCreateConfigAsset_WhenCreated_AddsDefaultEnUsLocalization()
        {
            IconConfiguratorStateStore stateStore = new IconConfiguratorStateStore();

            IconConfiguratorConfigAsset config = stateStore.LoadOrCreateConfigAsset();

            Assert.That(config.Localizations.Count, Is.EqualTo(1));
            Assert.That(config.Localizations[0].LocaleCode, Is.EqualTo("en-US"));
            Assert.That(config.Localizations[0].CanRemove, Is.False);
        }

        [Test]
        public void ConfigNormalizer_WhenDefaultLocaleHasWrongFlags_FixesLocalizationFlags()
        {
            IconConfiguratorConfigAsset config = ScriptableObject.CreateInstance<IconConfiguratorConfigAsset>();
            config.Localizations.Add(new LocalizationEntry
            {
                LocaleCode = "en-US",
                AppName = "Icon Feature",
                IsDefault = false,
                CanRemove = true,
            });

            IconConfiguratorConfigNormalizer.Normalize(config);

            Assert.That(config.Localizations[0].IsDefault, Is.True);
            Assert.That(config.Localizations[0].CanRemove, Is.False);
        }

        [Test]
        public void ConfigNormalizer_WhenUnsupportedLocalesExist_RemovesThemAndKeepsSupportedLocales()
        {
            IconConfiguratorConfigAsset config = ScriptableObject.CreateInstance<IconConfiguratorConfigAsset>();
            config.Localizations.Add(new LocalizationEntry
            {
                LocaleCode = "en-US",
                AppName = "Demo",
            });
            config.Localizations.Add(new LocalizationEntry
            {
                LocaleCode = "de-DE",
                AppName = "Deutsch",
            });
            config.Localizations.Add(new LocalizationEntry
            {
                LocaleCode = "fr-FR",
                AppName = "Francais",
            });
            config.Localizations.Add(new LocalizationEntry
            {
                LocaleCode = "ja-JP",
                AppName = "Japanese",
            });

            IconConfiguratorConfigNormalizer.Normalize(config);

            Assert.That(config.Localizations, Has.Count.EqualTo(2));
            Assert.That(config.Localizations[0].LocaleCode, Is.EqualTo("en-US"));
            Assert.That(config.Localizations[1].LocaleCode, Is.EqualTo("ja-JP"));
        }

        [Test]
        public void ConfigNormalizer_WhenManualHasTrailingEmptyThirdLayer_TrimsBackToTwoLayers()
        {
            IconConfiguratorConfigAsset config = ScriptableObject.CreateInstance<IconConfiguratorConfigAsset>();
            config.Manual = new ManualLayerState
            {
                Layers = new System.Collections.Generic.List<IconLayerConfig>
                {
                    new IconLayerConfig { LayerKind = IconLayerKind.Background, DisplayName = "Background" },
                    new IconLayerConfig { LayerKind = IconLayerKind.Foreground1, DisplayName = "Foreground1" },
                    new IconLayerConfig { LayerKind = IconLayerKind.Foreground2, DisplayName = "Foreground2" },
                },
            };

            IconConfiguratorConfigNormalizer.Normalize(config);

            Assert.That(config.Manual.Layers, Has.Count.EqualTo(2));
        }

        [Test]
        public void ConfigNormalizer_WhenThirdLayerHasImportedAsset_KeepsThreeLayers()
        {
            IconConfiguratorConfigAsset config = ScriptableObject.CreateInstance<IconConfiguratorConfigAsset>();
            config.Manual = new ManualLayerState
            {
                Layers = new System.Collections.Generic.List<IconLayerConfig>
                {
                    new IconLayerConfig { LayerKind = IconLayerKind.Background, DisplayName = "Background" },
                    new IconLayerConfig { LayerKind = IconLayerKind.Foreground1, DisplayName = "Foreground1" },
                    new IconLayerConfig
                    {
                        LayerKind = IconLayerKind.Foreground2,
                        DisplayName = "Foreground2",
                        AssetGuid = "guid",
                        AssetPath = "Assets/IconConfigurator/Imported/foreground2.png",
                    },
                },
            };

            IconConfiguratorConfigNormalizer.Normalize(config);

            Assert.That(config.Manual.Layers, Has.Count.EqualTo(3));
            Assert.That(config.Manual.Layers[2].LayerKind, Is.EqualTo(IconLayerKind.Foreground2));
        }

        [Test]
        public void LoadOrCreateConfigAsset_WhenCreated_HasValidMonoScript()
        {
            IconConfiguratorStateStore stateStore = new IconConfiguratorStateStore();

            IconConfiguratorConfigAsset config = stateStore.LoadOrCreateConfigAsset();

            Assert.That(MonoScript.FromScriptableObject(config), Is.Not.Null);
        }

        [Test]
        public void LoadOrCreateConfigAsset_WhenBrokenAssetExists_RecreatesTypedAsset()
        {
            EnsureFolder("Assets/IconConfigurator");
            EnsureFolder(k_SettingsDirectory);
            File.WriteAllText(
                k_ConfigAssetPath,
@"%YAML 1.1
%TAG !u! tag:unity3d.com,2011:
--- !u!114 &11400000
MonoBehaviour:
  m_ObjectHideFlags: 0
  m_Script: {fileID: 0}
  m_Name: IconConfiguratorConfig
  m_EditorClassIdentifier: ByteDance.PICO.IconConfigurator.Editor:ByteDance.PICO.IconConfigurator.Editor:IconConfiguratorConfigAsset
");
            AssetDatabase.ImportAsset(k_ConfigAssetPath, ImportAssetOptions.ForceSynchronousImport);
            IconConfiguratorStateStore stateStore = new IconConfiguratorStateStore();

            IconConfiguratorConfigAsset config = stateStore.LoadOrCreateConfigAsset();

            Assert.That(config, Is.Not.Null);
            Assert.That(AssetDatabase.LoadAssetAtPath<IconConfiguratorConfigAsset>(k_ConfigAssetPath), Is.Not.Null);
            Assert.That(MonoScript.FromScriptableObject(config), Is.Not.Null);
        }

        [Test]
        public void GetConfigGuid_WhenAssetExists_ReturnsAssetGuid()
        {
            IconConfiguratorStateStore stateStore = new IconConfiguratorStateStore();
            stateStore.LoadOrCreateConfigAsset();

            string guid = stateStore.GetConfigGuid();

            Assert.That(guid, Is.EqualTo(AssetDatabase.AssetPathToGUID(k_ConfigAssetPath)));
        }

        [Test]
        public void RestoreTextureCache_WhenAssetGuidAndPathExist_LoadsTexture()
        {
            IconConfiguratorStateStore stateStore = new IconConfiguratorStateStore();
            IconConfiguratorConfigAsset config = stateStore.LoadOrCreateConfigAsset();
            Texture2D texture = CreateTextureAsset("background_test.png");
            string assetPath = AssetDatabase.GetAssetPath(texture);
            string assetGuid = AssetDatabase.AssetPathToGUID(assetPath);

            config.Manual.Layers[0] = new IconLayerConfig
            {
                LayerKind = IconLayerKind.Background,
                AssetGuid = assetGuid,
                AssetPath = assetPath,
            };

            stateStore.RestoreTextureCache(config);

            Assert.That(config.Manual.Layers[0].Texture, Is.Not.Null);
            Assert.That(config.Manual.Layers[0].Texture, Is.EqualTo(texture));
        }

        [Test]
        public void RestoreTextureCache_WhenAiDynamicLayerAndSdfListsExist_LoadsTextures()
        {
            IconConfiguratorStateStore stateStore = new IconConfiguratorStateStore();
            IconConfiguratorConfigAsset config = stateStore.LoadOrCreateConfigAsset();
            Texture2D layerTexture = CreateTextureAsset("ai_layer_test.png");
            Texture2D sdfTexture = CreateTextureAsset("ai_sdf_test.png");

            config.AiSplit.GeneratedLayers = new System.Collections.Generic.List<IconLayerConfig>
            {
                CreateLayerFromTexture(IconLayerKind.Background, layerTexture),
            };
            config.AiSplit.GeneratedSdfs = new System.Collections.Generic.List<IconLayerConfig>
            {
                CreateLayerFromTexture(IconLayerKind.Background, sdfTexture),
            };

            stateStore.RestoreTextureCache(config);

            Assert.That(config.AiSplit.GeneratedLayers[0].Texture, Is.EqualTo(layerTexture));
            Assert.That(config.AiSplit.GeneratedSdfs[0].Texture, Is.EqualTo(sdfTexture));
        }

        private static Texture2D CreateTextureAsset(string fileName)
        {
            if (!AssetDatabase.IsValidFolder("Assets/IconConfigurator"))
            {
                AssetDatabase.CreateFolder("Assets", "IconConfigurator");
            }

            if (!AssetDatabase.IsValidFolder(k_ImportedDirectory))
            {
                AssetDatabase.CreateFolder("Assets/IconConfigurator", "Imported");
            }

            Texture2D texture = new Texture2D(2, 2, TextureFormat.RGBA32, false);
            texture.SetPixels(new[]
            {
                Color.red,
                Color.red,
                Color.red,
                Color.red,
            });
            texture.Apply();

            string filePath = Path.Combine(k_ImportedDirectory, fileName).Replace("\\", "/");
            File.WriteAllBytes(filePath, texture.EncodeToPNG());
            AssetDatabase.ImportAsset(filePath);

            Object.DestroyImmediate(texture);

            return AssetDatabase.LoadAssetAtPath<Texture2D>(filePath);
        }

        private static IconLayerConfig CreateLayerFromTexture(IconLayerKind layerKind, Texture2D texture)
        {
            string assetPath = AssetDatabase.GetAssetPath(texture);
            return new IconLayerConfig
            {
                LayerKind = layerKind,
                AssetGuid = AssetDatabase.AssetPathToGUID(assetPath),
                AssetPath = assetPath,
            };
        }

        private static void DeleteAssetIfExists(string path)
        {
            if (AssetDatabase.LoadAssetAtPath<Object>(path) != null || AssetDatabase.IsValidFolder(path))
            {
                AssetDatabase.DeleteAsset(path);
            }
        }

        private static void EnsureFolder(string path)
        {
            if (AssetDatabase.IsValidFolder(path))
            {
                return;
            }

            string parent = path.Substring(0, path.LastIndexOf('/'));
            string folderName = path.Substring(path.LastIndexOf('/') + 1);

            if (!AssetDatabase.IsValidFolder(parent))
            {
                EnsureFolder(parent);
            }

            AssetDatabase.CreateFolder(parent, folderName);
        }
    }
}
