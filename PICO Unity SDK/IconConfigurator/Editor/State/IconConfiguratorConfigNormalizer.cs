using System.Collections.Generic;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    public static class IconConfiguratorConfigNormalizer
    {
        public static void Normalize(IconConfiguratorConfigAsset config)
        {
            if (config == null)
            {
                return;
            }

            config.Manual ??= new ManualLayerState();
            config.AiSplit ??= new AiSplitState();
            config.Localizations ??= new List<LocalizationEntry>();

            NormalizeManualLayers(config.Manual);
            EnsureDefaultLocalization(config.Localizations);
            config.AiSplit.EnsureDynamicResultLists();
        }

        public static void NormalizeLocalizations(IList<LocalizationEntry> localizations)
        {
            RemoveUnsupportedLocalizations(localizations);
            EnsureDefaultLocalization(localizations);
        }

        private static void RemoveUnsupportedLocalizations(IList<LocalizationEntry> localizations)
        {
            if (localizations == null)
            {
                return;
            }

            for (int i = localizations.Count - 1; i >= 0; i--)
            {
                LocalizationEntry entry = localizations[i];
                if (entry == null)
                {
                    continue;
                }

                if (!IconConfiguratorLocales.IsSupported(entry.LocaleCode))
                {
                    localizations.RemoveAt(i);
                }
            }
        }

        private static void EnsureDefaultLocalization(IList<LocalizationEntry> localizations)
        {
            if (localizations == null)
            {
                return;
            }

            bool hasDefaultLocale = false;
            for (int i = 0; i < localizations.Count; i++)
            {
                LocalizationEntry entry = localizations[i];
                if (entry == null)
                {
                    continue;
                }

                bool isDefaultLocale = entry.LocaleCode == IconConfiguratorLocales.DefaultLocale;
                entry.IsDefault = isDefaultLocale;
                entry.CanRemove = !isDefaultLocale;

                if (isDefaultLocale)
                {
                    hasDefaultLocale = true;
                }
            }

            if (hasDefaultLocale)
            {
                return;
            }

            localizations.Insert(0, new LocalizationEntry
            {
                LocaleCode = IconConfiguratorLocales.DefaultLocale,
                AppName = string.Empty,
                IsDefault = true,
                CanRemove = false,
            });
        }

        private static void NormalizeManualLayers(ManualLayerState manual)
        {
            if (manual == null)
            {
                return;
            }

            IList<IconLayerConfig> layers = manual.Layers;
            while (layers.Count > ManualLayerState.MinLayerCount && IsTrailingEmptyLayer(layers[layers.Count - 1]))
            {
                layers.RemoveAt(layers.Count - 1);
            }
        }

        private static bool IsTrailingEmptyLayer(IconLayerConfig layer)
        {
            if (layer == null)
            {
                return true;
            }

            return !layer.HasAssetReference
                && string.IsNullOrWhiteSpace(layer.OriginalFileName)
                && string.IsNullOrWhiteSpace(layer.ContentHash)
                && layer.SourceWidth <= 0
                && layer.SourceHeight <= 0;
        }
    }
}
