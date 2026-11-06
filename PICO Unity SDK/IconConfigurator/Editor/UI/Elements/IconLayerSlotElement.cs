using System;
using UnityEngine;
using UnityEngine.UIElements;
using UnityEditor;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    public class IconConfiguratorLayerSlotElement : VisualElement
    {
        private readonly Image m_previewImage;
        private readonly Label m_fileNameLabel;
        private readonly Label m_errorLabel;
        private readonly Button m_uploadButton;

        public IconConfiguratorLayerSlotElement(
            string title,
            bool required,
            bool canDelete,
            bool canMoveUp,
            bool canMoveDown,
            bool enableDragDrop)
        {
            Required = required;
            EnableDragDrop = enableDragDrop;

            style.flexDirection = FlexDirection.Row;
            style.alignItems = Align.Center;
            style.marginBottom = 6;
            AddToClassList("icon-configurator__layer-slot");

            VisualElement previewFrame = new VisualElement();
            previewFrame.style.width = 64;
            previewFrame.style.height = 64;
            previewFrame.style.backgroundColor = new UnityEngine.Color(0.2f, 0.2f, 0.2f);
            previewFrame.style.marginRight = 8;

            m_previewImage = new Image();
            m_previewImage.scaleMode = UnityEngine.ScaleMode.ScaleToFit;
            m_previewImage.style.width = 64;
            m_previewImage.style.height = 64;
            previewFrame.Add(m_previewImage);

            Add(previewFrame);

            VisualElement content = new VisualElement();
            content.style.flexGrow = 1;
            Add(content);

            Label titleLabel = new Label(required ? $"{title} *" : title);
            content.Add(titleLabel);

            m_fileNameLabel = new Label("No file selected");
            m_fileNameLabel.AddToClassList("icon-configurator__placeholder");
            m_fileNameLabel.style.marginTop = 2;
            content.Add(m_fileNameLabel);

            m_errorLabel = new Label();
            m_errorLabel.style.color = new UnityEngine.Color(1f, 0.45f, 0.45f);
            m_errorLabel.style.marginTop = 2;
            content.Add(m_errorLabel);

            VisualElement buttonRow = new VisualElement();
            buttonRow.style.flexDirection = FlexDirection.Row;
            buttonRow.style.marginTop = 4;
            content.Add(buttonRow);

            m_uploadButton = new Button(() => UploadRequested?.Invoke())
            {
                text = "Upload",
            };
            m_uploadButton.style.marginRight = 6;
            buttonRow.Add(m_uploadButton);

            Button clearButton = new Button(() => ClearRequested?.Invoke())
            {
                text = "Clear",
            };
            clearButton.style.marginRight = 6;
            buttonRow.Add(clearButton);

            Button deleteButton = new Button(() => DeleteRequested?.Invoke())
            {
                text = "Delete",
            };
            deleteButton.SetEnabled(canDelete);
            deleteButton.style.display = canDelete ? DisplayStyle.Flex : DisplayStyle.None;
            deleteButton.style.marginRight = 6;
            buttonRow.Add(deleteButton);

            Button moveUpButton = new Button(() => MoveUpRequested?.Invoke())
            {
                text = "Up",
            };
            moveUpButton.SetEnabled(canMoveUp);
            moveUpButton.style.display = enableDragDrop ? DisplayStyle.Flex : DisplayStyle.None;
            moveUpButton.style.marginRight = 6;
            buttonRow.Add(moveUpButton);

            Button moveDownButton = new Button(() => MoveDownRequested?.Invoke())
            {
                text = "Down",
            };
            moveDownButton.SetEnabled(canMoveDown);
            moveDownButton.style.display = enableDragDrop ? DisplayStyle.Flex : DisplayStyle.None;
            buttonRow.Add(moveDownButton);

            if (EnableDragDrop)
            {
                RegisterCallback<DragUpdatedEvent>(HandleDragUpdated);
                RegisterCallback<DragLeaveEvent>(_ => RemoveFromClassList("icon-configurator__layer-slot--drag-over"));
                RegisterCallback<DragPerformEvent>(HandleDragPerform);
            }
        }

        public event Action UploadRequested;

        public event Action ClearRequested;

        public event Action DeleteRequested;

        public event Action MoveUpRequested;

        public event Action MoveDownRequested;

        public event Action<string[]> FilesDropped;

        public bool Required { get; }

        public bool EnableDragDrop { get; }

        public void SetLayer(IconLayerConfig layer, string errorText)
        {
            m_previewImage.image = layer?.Texture;
            m_fileNameLabel.text = string.IsNullOrWhiteSpace(layer?.OriginalFileName)
                ? "No file selected"
                : layer.OriginalFileName;
            m_errorLabel.text = errorText ?? string.Empty;
            m_uploadButton.text = string.IsNullOrWhiteSpace(layer?.OriginalFileName) ? "Upload" : "Replace";
        }

        private void HandleDragUpdated(DragUpdatedEvent evt)
        {
            if (!HasFilePathPayload())
            {
                DragAndDrop.visualMode = DragAndDropVisualMode.Rejected;
                return;
            }

            DragAndDrop.visualMode = DragAndDropVisualMode.Copy;
            AddToClassList("icon-configurator__layer-slot--drag-over");
            evt.StopPropagation();
        }

        private void HandleDragPerform(DragPerformEvent evt)
        {
            RemoveFromClassList("icon-configurator__layer-slot--drag-over");
            if (!HasFilePathPayload())
            {
                DragAndDrop.visualMode = DragAndDropVisualMode.Rejected;
                return;
            }

            DragAndDrop.AcceptDrag();
            FilesDropped?.Invoke(DragAndDrop.paths);
            evt.StopPropagation();
        }

        private static bool HasFilePathPayload()
        {
            return DragAndDrop.paths != null && DragAndDrop.paths.Length > 0;
        }
    }
}
