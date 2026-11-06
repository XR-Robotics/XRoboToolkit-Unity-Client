using System;
using UnityEngine.UIElements;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    public class IconConfiguratorModeSegmentControl : VisualElement
    {
        private readonly Button m_manualButton;
        private readonly Button m_aiSplitButton;
        private IconConfiguratorMode m_value;

        public IconConfiguratorModeSegmentControl()
        {
            AddToClassList("icon-configurator__mode-segment");
            style.flexDirection = FlexDirection.Row;
            style.alignItems = Align.Center;
            style.minHeight = 28;

            m_manualButton = CreateButton("Manual", IconConfiguratorMode.Manual);
            m_aiSplitButton = CreateButton("AI Split", IconConfiguratorMode.AiSplit);

            Add(m_manualButton);
            Add(m_aiSplitButton);

            SetValueWithoutNotify(IconConfiguratorMode.Manual);
        }

        public event Action<IconConfiguratorMode> ValueChanged;

        public IconConfiguratorMode Value
        {
            get => m_value;
            set => SetValue(value, true);
        }

        public void SetValueWithoutNotify(IconConfiguratorMode value)
        {
            SetValue(value, false);
        }

        private Button CreateButton(string label, IconConfiguratorMode value)
        {
            Button button = new Button(() => SetValue(value, true))
            {
                text = label,
            };
            button.AddToClassList("icon-configurator__mode-button");
            button.style.minHeight = 24;
            button.style.marginRight = 8;
            return button;
        }

        private void SetValue(IconConfiguratorMode value, bool notify)
        {
            m_value = value;
            UpdateVisualState();

            if (notify)
            {
                ValueChanged?.Invoke(value);
            }
        }

        private void UpdateVisualState()
        {
            m_manualButton.EnableInClassList(
                "icon-configurator__mode-button--selected",
                m_value == IconConfiguratorMode.Manual);
            m_aiSplitButton.EnableInClassList(
                "icon-configurator__mode-button--selected",
                m_value == IconConfiguratorMode.AiSplit);
        }
    }
}
