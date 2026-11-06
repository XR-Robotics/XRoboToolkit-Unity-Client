using UnityEditor;
using UnityEngine;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    public static class AiSplitEnvironmentMenu
    {
#if ICON_CONFIGURATOR_ENABLE_AI_SPLIT_DEBUG_MENU
        [MenuItem("PICO/Icon Configurator/AI Split/Use PPE Internal")]
#endif
        public static void UsePpeInternal()
        {
            ApplyRegionSelection(AiSplitRegionPreference.Internal, true, "AI Split environment set to PPE internal.");
        }

#if ICON_CONFIGURATOR_ENABLE_AI_SPLIT_DEBUG_MENU
        [MenuItem("PICO/Icon Configurator/AI Split/Use CN")]
#endif
        public static void UseCn()
        {
            ApplyRegionSelection(AiSplitRegionPreference.Cn, false, "AI Split environment set to CN.");
        }

#if ICON_CONFIGURATOR_ENABLE_AI_SPLIT_DEBUG_MENU
        [MenuItem("PICO/Icon Configurator/AI Split/Use Global")]
#endif
        public static void UseGlobal()
        {
            ApplyRegionSelection(AiSplitRegionPreference.Global, false, "AI Split environment set to global.");
        }

#if ICON_CONFIGURATOR_ENABLE_AI_SPLIT_DEBUG_MENU
        [MenuItem("PICO/Icon Configurator/AI Split/Show Current")]
#endif
        public static void ShowCurrent()
        {
            IconAiSplitServiceFactory factory = IconAiSplitServiceFactory.CreateDefault();
            AiSplitTccStatus status = factory.GetConfigurationStatus();
            Debug.Log(status.DisplayText);
            EditorUtility.DisplayDialog("AI Split Config", status.DisplayText, "OK");
        }

#if ICON_CONFIGURATOR_ENABLE_AI_SPLIT_DEBUG_MENU
        [MenuItem("PICO/Icon Configurator/AI Split/Refresh AI Split Config")]
#endif
        public static void RefreshAiSplitConfig()
        {
            IconAiSplitServiceFactory factory = IconAiSplitServiceFactory.CreateDefault();
            factory.ClearConfigurationCache();
            factory.RefreshConfiguration(true);
            IconAiSplitServiceFactory.RequestGlobalConfigurationRefresh();
            Debug.Log("AI Split config refresh requested.");
        }

        private static void ApplyRegionSelection(
            AiSplitRegionPreference preference,
            bool usePpeInternal,
            string logMessage)
        {
            EditorPrefs.SetBool(AiSplitEnvironmentService.PpeInternalEditorPrefsKey, usePpeInternal);
            EditorPrefs.SetString(
                AiSplitEnvironmentService.RegionOverrideEditorPrefsKey,
                preference.ToString());

            IconAiSplitServiceFactory factory = IconAiSplitServiceFactory.CreateDefault();
            factory.ClearConfigurationCache();
            factory.RefreshConfiguration(true);
            IconAiSplitServiceFactory.RequestGlobalConfigurationRefresh();
            Debug.Log(logMessage);
        }
    }
}
