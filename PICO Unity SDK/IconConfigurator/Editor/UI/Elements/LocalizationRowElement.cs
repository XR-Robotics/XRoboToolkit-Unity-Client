using System;
using System.Collections.Generic;
using UnityEngine.UIElements;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    public class IconConfiguratorLocalizationRowElement : VisualElement
    {
        private readonly PopupField<string> m_localePopup;
        private readonly TextField m_appNameField;
        private readonly Button m_removeButton;
        private readonly Label m_errorLabel;

        public IconConfiguratorLocalizationRowElement(
            LocalizationEntry entry,
            List<string> localeOptions,
            string errorText)
        {
            style.flexDirection = FlexDirection.Row;
            style.alignItems = Align.Center;
            style.marginBottom = 6;

            m_localePopup = new PopupField<string>(localeOptions, entry.LocaleCode);
            m_localePopup.style.width = 120;
            m_localePopup.style.minWidth = 120;
            m_localePopup.style.maxWidth = 120;
            m_localePopup.style.flexGrow = 0;
            m_localePopup.style.flexShrink = 0;
            m_localePopup.style.marginRight = 8;
            Add(m_localePopup);

            m_appNameField = new TextField
            {
                value = entry.AppName,
            };
            m_appNameField.style.flexGrow = 1;
            m_appNameField.style.flexShrink = 1;
            m_appNameField.style.minWidth = 100;
            m_appNameField.style.marginRight = 8;
            Add(m_appNameField);

            m_removeButton = new Button(() => RemoveRequested?.Invoke())
            {
                text = "Remove",
            };
            m_removeButton.SetEnabled(entry.CanRemove);
            m_removeButton.style.flexShrink = 0;
            m_removeButton.style.marginRight = 8;
            Add(m_removeButton);

            m_errorLabel = new Label(errorText ?? string.Empty);
            m_errorLabel.style.color = new UnityEngine.Color(1f, 0.45f, 0.45f);
            m_errorLabel.style.minWidth = 200;
            m_errorLabel.style.flexShrink = 0;
            Add(m_errorLabel);

            m_localePopup.RegisterValueChangedCallback(changeEvent => LocaleChanged?.Invoke(changeEvent.newValue));
            m_appNameField.RegisterValueChangedCallback(changeEvent => AppNameChanged?.Invoke(changeEvent.newValue));
        }

        public event Action<string> LocaleChanged;

        public event Action<string> AppNameChanged;

        public event Action RemoveRequested;

        public void SetErrorText(string errorText)
        {
            m_errorLabel.text = errorText ?? string.Empty;
        }
    }
}
