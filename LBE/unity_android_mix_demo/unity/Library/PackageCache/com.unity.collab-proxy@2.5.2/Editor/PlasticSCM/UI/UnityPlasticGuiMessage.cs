using UnityEditor;

using Codice.Client.Common;
using PlasticGui;

namespace Unity.PlasticSCM.Editor.UI
{
    internal class UnityPlasticGuiMessage : GuiMessage.IGuiMessage
    {
        void GuiMessage.IGuiMessage.ShowMessage(
            string title,
            string message,
            GuiMessage.GuiMessageType messageType)
        {
            if (!PlasticPlugin.ConnectionMonitor.IsConnected)
                return;

            EditorUtility.DisplayDialog(
                GetDialogTitleForMessageType(title, messageType),
                message,
                PlasticLocalization.GetString(PlasticLocalization.Name.CloseButton));
        }

        void GuiMessage.IGuiMessage.ShowError(string message)
        {
            if (!PlasticPlugin.ConnectionMonitor.IsConnected)
                return;

            EditorUtility.DisplayDialog(
                GetDialogTitleForMessageType(null, GuiMessage.GuiMessageType.Critical),
                message,
                PlasticLocalization.GetString(PlasticLocalization.Name.CloseButton));
        }

        GuiMessage.GuiMessageResponseButton GuiMessage.IGuiMessage.ShowQuestion(
            string title,
            string message,
            string positiveActionButton,
            string neutralActionButton,
            string negativeActionButton)
        {
            if (string.IsNullOrEmpty(negativeActionButton))
            {
                bool result = EditorUtility.DisplayDialog(
                    GetDialogTitle(title),
                    message,
                    positiveActionButton,
                    neutralActionButton);

                return (result) ?
                    GuiMessage.GuiMessageResponseButton.Positive :
                    GuiMessage.GuiMessageResponseButton.Neutral;
            }

            int intResult = EditorUtility.DisplayDialogComplex(
                GetDialogTitle(title),
                message,
                positiveActionButton,
                neutralActionButton,
                negativeActionButton);

            return GetResponse(intResult);
        }

        bool GuiMessage.IGuiMessage.ShowQuestion(
            string title,
            string message,
            string yesButton)
        {
            return EditorUtility.DisplayDialog(
                GetDialogTitle(title),
                message,
                yesButton,
                PlasticLocalization.GetString(PlasticLocalization.Name.NoButton));
        }

        bool GuiMessage.IGuiMessage.ShowQuestionWithLearnMore(
            string title,
            string message,
            string yesButton,
            string noButton,
            MultiLinkLabelData learnMoreContent)
        {
            return EditorUtility.DisplayDialog(
                GetDialogTitle(title),
                message,
                yesButton,
                noButton);
        }

        bool GuiMessage.IGuiMessage.ShowYesNoQuestion(string title, string message)
        {
            return EditorUtility.DisplayDialog(
                GetDialogTitle(title),
                message,
                PlasticLocalization.GetString(PlasticLocalization.Name.YesButton),
                PlasticLocalization.GetString(PlasticLocalization.Name.NoButton));
        }

        GuiMessage.GuiMessageResponseButton GuiMessage.IGuiMessage.ShowYesNoCancelQuestion(
            string title, string message)
        {
            int intResult = EditorUtility.DisplayDialogComplex(
                GetDialogTitle(title),
                message,
                PlasticLocalization.GetString(PlasticLocalization.Name.YesButton),
                PlasticLocalization.GetString(PlasticLocalization.Name.CancelButton),
                PlasticLocalization.GetString(PlasticLocalization.Name.NoButton));

            return GetResponse(intResult);
        }

        bool GuiMessage.IGuiMessage.ShowYesNoQuestionWithType(
            string title, string message, GuiMessage.GuiMessageType messageType)
        {
            return EditorUtility.DisplayDialog(
                GetDialogTitleForMessageType(title, messageType),
                message,
                PlasticLocalization.GetString(PlasticLocalization.Name.YesButton),
                PlasticLocalization.GetString(PlasticLocalization.Name.NoButton));
        }

        GuiMessage.GuiMessageResponseButton GuiMessage.IGuiMessage.ShowQuestionWithCheckBox(
            string title,
            string message,
            string positiveButtonText,
            string neutralButtonText,
            string negativeButtonText,
            MultiLinkLabelData dontShowAgainContent,
            out bool checkBoxValue)
        {
            checkBoxValue = false;
            return ((GuiMessage.IGuiMessage)this).ShowQuestion(
                title, message, positiveButtonText, neutralButtonText, negativeButtonText);
        }

        static string GetDialogTitle(string title)
        {
            if (string.IsNullOrEmpty(title))
                return UnityConstants.PLASTIC_WINDOW_TITLE;

            if (title.Contains(UnityConstants.PLASTIC_WINDOW_TITLE))
                return title;

            return string.Format("{0} - {1}",
                UnityConstants.PLASTIC_WINDOW_TITLE, title);
        }

        static string GetDialogTitleForMessageType(
            string title,
            GuiMessage.GuiMessageType messageType)
        {
            string alertTypeText = GetMessageTypeText(messageType);
            return string.Format("{0} - {1}", alertTypeText, GetDialogTitle(title));
        }

        static string GetMessageTypeText(GuiMessage.GuiMessageType messageType)
        {
            string alertTypeText = string.Empty;

            switch (messageType)
            {
                case GuiMessage.GuiMessageType.Informational:
                    alertTypeText = "Information";
                    break;
                case GuiMessage.GuiMessageType.Warning:
                    alertTypeText = "Warning";
                    break;
                case GuiMessage.GuiMessageType.Critical:
                    alertTypeText = "Error";
                    break;
                case GuiMessage.GuiMessageType.Question:
                    alertTypeText = "Question";
                    break;
            }

            return alertTypeText;
        }

        static GuiMessage.GuiMessageResponseButton GetResponse(int dialogResult)
        {
            switch (dialogResult)
            {
                case 0:
                    return GuiMessage.GuiMessageResponseButton.Positive;
                case 1:
                    return GuiMessage.GuiMessageResponseButton.Neutral;
                case 2:
                    return GuiMessage.GuiMessageResponseButton.Negative;
                default:
                    return GuiMessage.GuiMessageResponseButton.Neutral;
            }
        }
    }
}
