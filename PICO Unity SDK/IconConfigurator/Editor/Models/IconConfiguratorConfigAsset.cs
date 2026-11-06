using System.Collections.Generic;
using UnityEngine;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    [CreateAssetMenu(
        fileName = "IconConfiguratorConfig",
        menuName = "PICO/Icon Configurator Config",
        order = 1000)]
    public class IconConfiguratorConfigAsset : ScriptableObject
    {
        [SerializeField] private IconConfiguratorMode m_lastMode = IconConfiguratorMode.Manual;
        [SerializeField] private int m_previewYaw = 37;
        [SerializeField] private ManualLayerState m_manual = new ManualLayerState();
        [SerializeField] private AiSplitState m_aiSplit = new AiSplitState();
        [SerializeField] private List<LocalizationEntry> m_localizations = new List<LocalizationEntry>();

        public IconConfiguratorMode LastMode
        {
            get => m_lastMode;
            set => m_lastMode = value;
        }

        public int PreviewYaw
        {
            get => m_previewYaw;
            set => m_previewYaw = value;
        }

        public ManualLayerState Manual
        {
            get => m_manual;
            set => m_manual = value ?? new ManualLayerState();
        }

        public AiSplitState AiSplit
        {
            get => m_aiSplit;
            set => m_aiSplit = value ?? new AiSplitState();
        }

        public List<LocalizationEntry> Localizations
        {
            get => m_localizations;
            set => m_localizations = value ?? new List<LocalizationEntry>();
        }
    }
}
