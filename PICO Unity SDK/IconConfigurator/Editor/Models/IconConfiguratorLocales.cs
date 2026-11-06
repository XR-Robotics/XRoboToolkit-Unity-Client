using System;
using System.Collections.Generic;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    public static class IconConfiguratorLocales
    {
        public const string DefaultLocale = "en-US";

        private static readonly string[] s_supportedLocales =
        {
            "en-US",
            "zh-CN",
            "ja-JP",
            "ko-KR",
        };

        private static readonly string[] s_cleanupLocales =
        {
            "en-US",
            "zh-CN",
            "ja-JP",
            "ko-KR",
            "de-DE",
            "fr-FR",
        };

        private static readonly HashSet<string> s_supportedLocaleSet = new HashSet<string>(s_supportedLocales);

        public static IReadOnlyList<string> SupportedLocales => s_supportedLocales;

        public static IReadOnlyList<string> CleanupLocales => s_cleanupLocales;

        public static bool IsSupported(string localeCode)
        {
            return !string.IsNullOrWhiteSpace(localeCode) && s_supportedLocaleSet.Contains(localeCode);
        }

        public static string GetAndroidStringFilePath(string localeCode)
        {
            return localeCode switch
            {
                "en-US" => $"{IconConfiguratorPaths.AndroidOutputDirectory}/values/strings.xml",
                "zh-CN" => $"{IconConfiguratorPaths.AndroidOutputDirectory}/values-zh-rCN/strings.xml",
                "ja-JP" => $"{IconConfiguratorPaths.AndroidOutputDirectory}/values-ja/strings.xml",
                "ko-KR" => $"{IconConfiguratorPaths.AndroidOutputDirectory}/values-ko/strings.xml",
                "de-DE" => $"{IconConfiguratorPaths.AndroidOutputDirectory}/values-de/strings.xml",
                "fr-FR" => $"{IconConfiguratorPaths.AndroidOutputDirectory}/values-fr/strings.xml",
                _ => throw new ArgumentOutOfRangeException(nameof(localeCode), localeCode, "Unsupported locale."),
            };
        }
    }
}
