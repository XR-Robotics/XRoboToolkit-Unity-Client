using System.Collections.Generic;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    public class IconConfiguratorValidator
    {
        public const int MaxAppNameLength = 50;

        public IconConfiguratorValidationResult Validate(IconConfiguratorConfigAsset config)
        {
            IconConfiguratorValidationResult result = new IconConfiguratorValidationResult();

            if (config == null)
            {
                result.CanGenerate = false;
                result.CanApply = false;
                return result;
            }

            ValidateLocalizations(config, result);

            if (config.LastMode == IconConfiguratorMode.Manual)
            {
                ValidateManual(config, result);
                result.CanGenerate = false;
                result.CanApply = result.LayerErrors.Count == 0
                    && result.LocalizationErrors.Count == 0
                    && result.GeneralErrors.Count == 0;
                return result;
            }

            ValidateAi(config, result);
            return result;
        }

        private static void ValidateManual(
            IconConfiguratorConfigAsset config,
            IconConfiguratorValidationResult result)
        {
            int layerCount = config.Manual?.Layers?.Count ?? 0;
            if (layerCount < ManualLayerState.MinLayerCount || layerCount > ManualLayerState.MaxLayerCount)
            {
                result.GeneralErrors.Add(
                    $"Manual mode requires between {ManualLayerState.MinLayerCount} and {ManualLayerState.MaxLayerCount} layers.");
            }

            if (config.Manual?.Background == null || !config.Manual.Background.HasAssetReference)
            {
                result.LayerErrors[IconLayerKind.Background] = "Background is required.";
            }

            if (config.Manual?.Foreground1 == null || !config.Manual.Foreground1.HasAssetReference)
            {
                result.LayerErrors[IconLayerKind.Foreground1] = "Foreground1 is required.";
            }
        }

        private static void ValidateAi(
            IconConfiguratorConfigAsset config,
            IconConfiguratorValidationResult result)
        {
            bool hasFlatSource = config.AiSplit?.FlatSource != null && config.AiSplit.FlatSource.HasAssetReference;
            bool hasLocalizationErrors = result.LocalizationErrors.Count > 0;
            bool hasValidResult = HasValidAiResult(config.AiSplit, result);

            result.CanGenerate = hasFlatSource && config.AiSplit.HasAcceptedTerms;
            result.CanApply = config.AiSplit.Status == GenerateStatus.Succeeded
                && !hasLocalizationErrors
                && hasValidResult
                && result.GeneralErrors.Count == 0;
        }

        private static bool HasValidAiResult(AiSplitState state, IconConfiguratorValidationResult result)
        {
            if (state == null || state.Status != GenerateStatus.Succeeded)
            {
                return false;
            }

            state.EnsureDynamicResultLists();
            int layerCount = state.GeneratedLayers.Count;
            int sdfCount = state.GeneratedSdfs.Count;
            if (layerCount != sdfCount)
            {
                result.GeneralErrors.Add("AI generated layer/sdf counts must match.");
                return false;
            }

            if (layerCount < ManualLayerState.MinLayerCount || layerCount > ManualLayerState.MaxLayerCount)
            {
                result.GeneralErrors.Add(
                    $"AI generated result requires between {ManualLayerState.MinLayerCount} and {ManualLayerState.MaxLayerCount} layer/sdf pairs.");
                return false;
            }

            for (int i = 0; i < layerCount; i++)
            {
                if (state.GeneratedLayers[i]?.HasAssetReference != true || state.GeneratedSdfs[i]?.HasAssetReference != true)
                {
                    result.GeneralErrors.Add("AI generated layer/sdf assets are required.");
                    return false;
                }
            }

            return true;
        }

        private static void ValidateLocalizations(
            IconConfiguratorConfigAsset config,
            IconConfiguratorValidationResult result)
        {
            HashSet<string> locales = new HashSet<string>();
            bool hasDefaultLocale = false;

            foreach (LocalizationEntry entry in config.Localizations)
            {
                string locale = entry.LocaleCode ?? string.Empty;
                string appName = entry.AppName?.Trim() ?? string.Empty;

                if (string.IsNullOrWhiteSpace(locale))
                {
                    continue;
                }

                if (!IconConfiguratorLocales.IsSupported(locale))
                {
                    result.LocalizationErrors[locale] = "Locale is not supported.";
                }

                if (!locales.Add(locale))
                {
                    result.LocalizationErrors[locale] = "Locale must be unique.";
                }

                if (locale == IconConfiguratorLocales.DefaultLocale)
                {
                    hasDefaultLocale = true;
                }

                if (string.IsNullOrWhiteSpace(appName))
                {
                    result.LocalizationErrors[locale] = locale == IconConfiguratorLocales.DefaultLocale
                        ? "Default app name is required."
                        : "App name is required.";
                    continue;
                }

                if (appName.Length > MaxAppNameLength)
                {
                    result.LocalizationErrors[locale] = $"App name is too long. Max length is {MaxAppNameLength}.";
                }
            }

            if (!hasDefaultLocale)
            {
                result.LocalizationErrors[IconConfiguratorLocales.DefaultLocale] = "Default locale is required.";
            }
        }
    }
}
