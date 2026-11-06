using NUnit.Framework;
using UnityEngine;

namespace ByteDance.PICO.IconConfigurator.Editor.Tests
{
    public class IconConfiguratorValidatorTests
    {
        [Test]
        public void Validate_WhenManualLayerCountBelowMinimum_ReturnsGeneralError()
        {
            IconConfiguratorConfigAsset config = CreateManualConfig();
            config.Manual.Layers = new System.Collections.Generic.List<IconLayerConfig>
            {
                CreateLayer(IconLayerKind.Background),
            };
            IconConfiguratorValidator validator = new IconConfiguratorValidator();

            IconConfiguratorValidationResult result = validator.Validate(config);

            Assert.That(result.CanApply, Is.False);
            Assert.That(result.GeneralErrors, Has.Some.Contains("2 and 3"));
        }

        [Test]
        public void Validate_WhenManualBackgroundMissing_ReturnsBackgroundError()
        {
            IconConfiguratorConfigAsset config = CreateManualConfig();
            config.Manual.Layers[0] = new IconLayerConfig();
            IconConfiguratorValidator validator = new IconConfiguratorValidator();

            IconConfiguratorValidationResult result = validator.Validate(config);

            Assert.That(result.CanApply, Is.False);
            Assert.That(result.LayerErrors.ContainsKey(IconLayerKind.Background), Is.True);
        }

        [Test]
        public void Validate_WhenManualSecondLayerMissing_ReturnsForeground1Error()
        {
            IconConfiguratorConfigAsset config = CreateManualConfig();
            config.Manual.Layers[1] = new IconLayerConfig();
            IconConfiguratorValidator validator = new IconConfiguratorValidator();

            IconConfiguratorValidationResult result = validator.Validate(config);

            Assert.That(result.CanApply, Is.False);
            Assert.That(result.LayerErrors.ContainsKey(IconLayerKind.Foreground1), Is.True);
        }

        [Test]
        public void Validate_WhenDefaultLocalizationEmpty_ReturnsLocalizationError()
        {
            IconConfiguratorConfigAsset config = CreateManualConfig();
            config.Localizations[0].AppName = string.Empty;
            IconConfiguratorValidator validator = new IconConfiguratorValidator();

            IconConfiguratorValidationResult result = validator.Validate(config);

            Assert.That(result.CanApply, Is.False);
            Assert.That(result.LocalizationErrors.ContainsKey("en-US"), Is.True);
        }

        [Test]
        public void Validate_WhenNonDefaultLocalizationEmpty_ReturnsLocalizationError()
        {
            IconConfiguratorConfigAsset config = CreateManualConfig();
            config.Localizations.Add(new LocalizationEntry
            {
                LocaleCode = "zh-CN",
                AppName = string.Empty,
                CanRemove = true,
            });
            IconConfiguratorValidator validator = new IconConfiguratorValidator();

            IconConfiguratorValidationResult result = validator.Validate(config);

            Assert.That(result.CanApply, Is.False);
            Assert.That(result.LocalizationErrors.ContainsKey("zh-CN"), Is.True);
        }

        [Test]
        public void Validate_WhenDefaultLocaleMissing_ReturnsLocalizationError()
        {
            IconConfiguratorConfigAsset config = CreateManualConfig();
            config.Localizations.Clear();
            config.Localizations.Add(new LocalizationEntry
            {
                LocaleCode = "zh-CN",
                AppName = "Icon Feature CN",
                CanRemove = true,
            });
            IconConfiguratorValidator validator = new IconConfiguratorValidator();

            IconConfiguratorValidationResult result = validator.Validate(config);

            Assert.That(result.CanApply, Is.False);
            Assert.That(result.LocalizationErrors.ContainsKey("en-US"), Is.True);
        }

        [Test]
        public void Validate_WhenDefaultLocalePresent_DoesNotNormalizeLocalizationFlags()
        {
            IconConfiguratorConfigAsset config = CreateManualConfig();
            config.Localizations[0].IsDefault = false;
            config.Localizations[0].CanRemove = true;
            IconConfiguratorValidator validator = new IconConfiguratorValidator();

            validator.Validate(config);

            Assert.That(config.Localizations[0].IsDefault, Is.False);
            Assert.That(config.Localizations[0].CanRemove, Is.True);
        }

        [Test]
        public void Validate_WhenLocalesDuplicate_ReturnsDuplicateLocaleError()
        {
            IconConfiguratorConfigAsset config = CreateManualConfig();
            config.Localizations.Add(new LocalizationEntry
            {
                LocaleCode = "zh-CN",
                AppName = "One",
                CanRemove = true,
            });
            config.Localizations.Add(new LocalizationEntry
            {
                LocaleCode = "zh-CN",
                AppName = "Two",
                CanRemove = true,
            });
            IconConfiguratorValidator validator = new IconConfiguratorValidator();

            IconConfiguratorValidationResult result = validator.Validate(config);

            Assert.That(result.CanApply, Is.False);
            Assert.That(result.LocalizationErrors.ContainsKey("zh-CN"), Is.True);
        }

        [Test]
        public void Validate_WhenAppNameTooLong_ReturnsLengthError()
        {
            IconConfiguratorConfigAsset config = CreateManualConfig();
            config.Localizations[0].AppName = new string('A', IconConfiguratorValidator.MaxAppNameLength + 1);
            IconConfiguratorValidator validator = new IconConfiguratorValidator();

            IconConfiguratorValidationResult result = validator.Validate(config);

            Assert.That(result.CanApply, Is.False);
            Assert.That(result.LocalizationErrors["en-US"], Does.Contain("too long"));
        }

        [Test]
        public void Validate_WhenAiAgreementNotAccepted_CannotGenerate()
        {
            IconConfiguratorConfigAsset config = CreateAiConfig();
            config.AiSplit.HasAcceptedTerms = false;
            IconConfiguratorValidator validator = new IconConfiguratorValidator();

            IconConfiguratorValidationResult result = validator.Validate(config);

            Assert.That(result.CanGenerate, Is.False);
        }

        [Test]
        public void Validate_WhenAiDefaultAppNameIsEmpty_StillAllowsGenerate()
        {
            IconConfiguratorConfigAsset config = CreateAiConfig();
            config.AiSplit.HasAcceptedTerms = true;
            config.Localizations[0].AppName = string.Empty;
            IconConfiguratorValidator validator = new IconConfiguratorValidator();

            IconConfiguratorValidationResult result = validator.Validate(config);

            Assert.That(result.LocalizationErrors.ContainsKey("en-US"), Is.True);
            Assert.That(result.CanGenerate, Is.True);
        }

        [Test]
        public void Validate_WhenAiGenerationNotSucceeded_CannotApply()
        {
            IconConfiguratorConfigAsset config = CreateAiConfig();
            config.AiSplit.HasAcceptedTerms = true;
            config.AiSplit.Status = GenerateStatus.Ready;
            IconConfiguratorValidator validator = new IconConfiguratorValidator();

            IconConfiguratorValidationResult result = validator.Validate(config);

            Assert.That(result.CanApply, Is.False);
        }

        [Test]
        public void Validate_WhenAiSucceededWithoutMatchingCloudSdfs_CannotApply()
        {
            IconConfiguratorConfigAsset config = CreateAiConfig();
            config.AiSplit.HasAcceptedTerms = true;
            config.AiSplit.Status = GenerateStatus.Succeeded;
            config.AiSplit.GeneratedLayers = new System.Collections.Generic.List<IconLayerConfig>
            {
                CreateLayer(IconLayerKind.Background),
                CreateLayer(IconLayerKind.Foreground1),
                CreateLayer(IconLayerKind.Foreground2),
            };
            config.AiSplit.GeneratedSdfs = new System.Collections.Generic.List<IconLayerConfig>
            {
                CreateLayer(IconLayerKind.Background),
            };
            IconConfiguratorValidator validator = new IconConfiguratorValidator();

            IconConfiguratorValidationResult result = validator.Validate(config);

            Assert.That(result.CanApply, Is.False);
            Assert.That(result.GeneralErrors, Has.Some.Contains("layer/sdf"));
        }

        private static IconConfiguratorConfigAsset CreateManualConfig()
        {
            IconConfiguratorConfigAsset config = ScriptableObject.CreateInstance<IconConfiguratorConfigAsset>();
            config.LastMode = IconConfiguratorMode.Manual;
            config.Manual = new ManualLayerState
            {
                Layers = new System.Collections.Generic.List<IconLayerConfig>
                {
                    CreateLayer(IconLayerKind.Background),
                    CreateLayer(IconLayerKind.Foreground1),
                },
            };
            config.Localizations.Add(new LocalizationEntry
            {
                LocaleCode = "en-US",
                AppName = "Icon Feature",
                IsDefault = true,
                CanRemove = false,
            });

            return config;
        }

        private static IconConfiguratorConfigAsset CreateAiConfig()
        {
            IconConfiguratorConfigAsset config = ScriptableObject.CreateInstance<IconConfiguratorConfigAsset>();
            config.LastMode = IconConfiguratorMode.AiSplit;
            config.AiSplit = new AiSplitState
            {
                FlatSource = CreateLayer(IconLayerKind.FlatSource),
                Status = GenerateStatus.Ready,
            };
            config.Localizations.Add(new LocalizationEntry
            {
                LocaleCode = "en-US",
                AppName = "Icon Feature",
                IsDefault = true,
                CanRemove = false,
            });

            return config;
        }

        private static IconLayerConfig CreateLayer(IconLayerKind kind)
        {
            return new IconLayerConfig
            {
                LayerKind = kind,
                AssetGuid = "guid",
                AssetPath = $"Assets/{kind}.png",
                OriginalFileName = $"{kind}.png",
            };
        }
    }
}
