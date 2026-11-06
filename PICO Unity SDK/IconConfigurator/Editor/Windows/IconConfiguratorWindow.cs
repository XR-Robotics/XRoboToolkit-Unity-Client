using UnityEditor;
using UnityEngine;
using UnityEngine.UIElements;
using System.Collections.Generic;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    public class IconConfiguratorWindow : EditorWindow
    {
        private const string k_UxmlPath =
            "Packages/com.bytedance.pico.xr/IconConfigurator/Editor/UI/UXML/IconConfiguratorWindow.uxml";
        private const string k_UssPath =
            "Packages/com.bytedance.pico.xr/IconConfigurator/Editor/UI/USS/IconConfiguratorWindow.uss";

        private const string k_AiAgreementToggleText = "I agree";
        private const string k_AiAgreementDisclaimer =
            "The AI auto-layering function is driven by algorithms, and the generated results may have deviations. "
            + "You can use manual layering at any time to ensure the desired effect.";

        private IconConfiguratorStateStore m_stateStore;
        private IconConfiguratorValidator m_validator;
        private IconConfiguratorImportService m_importService;
        private IconCompositePreviewService m_compositePreviewService;
        private IconSpatialPreviewService m_spatialPreviewService;
        private IconAiSplitServiceFactory m_aiSplitServiceFactory;
        private IIconAiSplitService m_aiSplitService;
        private AiSplitTccLoadResult m_aiConfiguration;
        private IconApplyService m_applyService;
        private IconConfiguratorConfigAsset m_config;
        private IconConfiguratorModeSegmentControl m_modeSegmentControl;
        private VisualElement m_layerContent;
        private VisualElement m_previewContent;
        private VisualElement m_localizationContent;
        private readonly List<IconConfiguratorLocalizationRowElement> m_localizationRows =
            new List<IconConfiguratorLocalizationRowElement>();
        private Label m_bottomStatusLabel;
        private Button m_applyButton;
        private Texture2D m_preview2DTexture;
        private float m_aiProgress;
        private bool m_yawDirty;
        private bool m_applyInProgress;
        private Image m_spatialPreviewImage;
        private Label m_spatialAngleLabel;
        private ProgressBar m_aiProgressBar;
        private string m_statusMessage = string.Empty;
        private bool m_isWindowActive;

        [MenuItem("PICO/Icon Configurator")]
        public static void OpenWindow()
        {
            IconConfiguratorWindow window = GetWindow<IconConfiguratorWindow>(true, "Icon Configurator", true);
            window.titleContent = new GUIContent("Icon Configurator");
            window.minSize = new Vector2(560f, 640f);
            window.Show();
        }

#if ICON_CONFIGURATOR_ENABLE_AI_SPLIT_DEBUG_MENU
        [MenuItem("PICO/Icon Configurator/Open Window")]
        public static void OpenWindowFromSubmenu()
        {
            OpenWindow();
        }
#endif

        private void OnEnable()
        {
            m_isWindowActive = true;
            m_stateStore = new IconConfiguratorStateStore();
            m_validator = new IconConfiguratorValidator();
            m_importService = new IconConfiguratorImportService();
            m_compositePreviewService = new IconCompositePreviewService();
            m_spatialPreviewService = new IconSpatialPreviewService();
            m_aiSplitServiceFactory = IconAiSplitServiceFactory.CreateDefault();
            m_aiConfiguration = m_aiSplitServiceFactory.LoadConfiguration();
            m_aiSplitService = m_aiSplitServiceFactory.CreateService();
            m_applyService = new IconApplyService(
                m_validator,
                m_compositePreviewService,
                new System.Collections.Generic.List<IIconExportAdapter>
                {
                    new LayeredIconExportAdapter(),
                    new AndroidAppNameExportAdapter(),
                    new AndroidManifestExportAdapter(),
                });
            m_config = m_stateStore.LoadOrCreateConfigAsset();
            AssemblyReloadEvents.beforeAssemblyReload += HandleBeforeAssemblyReload;
            IconAiSplitServiceFactory.GlobalConfigurationRefreshRequested += HandleGlobalAiSplitConfigurationRefreshRequested;

            BuildUi();
        }

        private void OnDisable()
        {
            m_isWindowActive = false;
            CancelRunningAiSplitForShutdown();

            if (m_yawDirty)
            {
                m_yawDirty = false;
                EditorApplication.update -= HandleYawUpdate;
            }

            m_stateStore?.Save();
            m_spatialPreviewService?.Cleanup();
            AssemblyReloadEvents.beforeAssemblyReload -= HandleBeforeAssemblyReload;
            IconAiSplitServiceFactory.GlobalConfigurationRefreshRequested -= HandleGlobalAiSplitConfigurationRefreshRequested;
            EditorApplication.delayCall -= ExecuteDeferredApply;
            rootVisualElement.UnregisterCallback<GeometryChangedEvent>(HandleRootGeometryChanged);

            if (m_preview2DTexture != null)
            {
                DestroyImmediate(m_preview2DTexture);
                m_preview2DTexture = null;
            }
        }

        private void BuildUi()
        {
            rootVisualElement.Clear();

            VisualTreeAsset visualTreeAsset = AssetDatabase.LoadAssetAtPath<VisualTreeAsset>(k_UxmlPath);
            StyleSheet styleSheet = AssetDatabase.LoadAssetAtPath<StyleSheet>(k_UssPath);

            if (visualTreeAsset == null || styleSheet == null)
            {
                rootVisualElement.Add(new Label("Failed to load Icon Configurator UI assets."));
                return;
            }

            visualTreeAsset.CloneTree(rootVisualElement);
            rootVisualElement.styleSheets.Add(styleSheet);

            ScrollView bodyScrollView = rootVisualElement.Q<ScrollView>("icon-configurator__body");
            bodyScrollView?.contentContainer.AddToClassList("icon-configurator__body-content");
            rootVisualElement.RegisterCallback<GeometryChangedEvent>(HandleRootGeometryChanged);

            VisualElement modeHost = rootVisualElement.Q<VisualElement>("icon-configurator__mode-host");
            m_layerContent = rootVisualElement.Q<VisualElement>("layer-content");
            m_previewContent = rootVisualElement.Q<VisualElement>("preview-content");
            m_localizationContent = rootVisualElement.Q<VisualElement>("localization-content");
            m_bottomStatusLabel = rootVisualElement.Q<Label>("bottom-status-label");
            m_applyButton = rootVisualElement.Q<Button>("apply-button");

            m_modeSegmentControl = new IconConfiguratorModeSegmentControl();
            m_modeSegmentControl.SetValueWithoutNotify(m_config.LastMode);
            m_modeSegmentControl.ValueChanged += HandleModeChanged;
            modeHost.Add(m_modeSegmentControl);

            RebuildDynamicSections();

            if (m_applyButton != null)
            {
                m_applyButton.clicked += HandleApplyClicked;
            }

            UpdateBottomBarState();
        }

        private void BuildLayerSection(VisualElement layerContent)
        {
            layerContent.Clear();
            m_aiProgressBar = null;

            IconConfiguratorValidationResult validationResult = m_validator.Validate(m_config);

            if (m_config.LastMode == IconConfiguratorMode.Manual)
            {
                BuildManualLayerSection(layerContent, validationResult);
                return;
            }

            AddAiLayerSection(layerContent, validationResult);
        }

        private void BuildManualLayerSection(VisualElement layerContent, IconConfiguratorValidationResult validationResult)
        {
            Label hintLabel = CreatePlaceholderLabel(
                $"Manual mode supports {ManualLayerState.MinLayerCount}-{ManualLayerState.MaxLayerCount} transparent PNG layers. Drag a file onto a slot to replace it.");
            layerContent.Add(hintLabel);

            List<IconLayerConfig> manualLayers = m_config.Manual.Layers;
            for (int i = 0; i < manualLayers.Count; i++)
            {
                int layerIndex = i;
                IconLayerConfig layer = manualLayers[i];
                string title = $"{layerIndex + 1}. {IconLayerNaming.GetDisplayName(layerIndex)}";
                IconLayerKind errorKey = GetManualLayerKind(layerIndex);
                string errorText = validationResult.LayerErrors.TryGetValue(errorKey, out string error) ? error : string.Empty;
                IconConfiguratorLayerSlotElement slot = new IconConfiguratorLayerSlotElement(
                    title,
                    layerIndex < ManualLayerState.MinLayerCount,
                    manualLayers.Count > ManualLayerState.MinLayerCount,
                    layerIndex > 0,
                    layerIndex < manualLayers.Count - 1,
                    true);
                slot.UploadRequested += () => HandleManualLayerUploadRequested(layerIndex);
                slot.ClearRequested += () => HandleManualLayerClearRequested(layerIndex);
                slot.DeleteRequested += () => HandleDeleteManualLayerRequested(layerIndex);
                slot.MoveUpRequested += () => HandleMoveManualLayerUp(layerIndex);
                slot.MoveDownRequested += () => HandleMoveManualLayerDown(layerIndex);
                slot.FilesDropped += files => HandleManualLayerFilesDropped(layerIndex, files);
                slot.SetLayer(layer, errorText);
                layerContent.Add(slot);
            }

            Button addLayerButton = new Button(HandleAddManualLayerClicked)
            {
                text = "Add Layer",
            };
            addLayerButton.SetEnabled(manualLayers.Count < ManualLayerState.MaxLayerCount);
            layerContent.Add(addLayerButton);

            if (validationResult.GeneralErrors.Count > 0)
            {
                for (int i = 0; i < validationResult.GeneralErrors.Count; i++)
                {
                    layerContent.Add(CreateErrorLabel(validationResult.GeneralErrors[i]));
                }
            }
        }

        private void AddAiLayerSection(VisualElement layerContent, IconConfiguratorValidationResult validationResult)
        {
            IconConfiguratorLayerSlotElement slot = new IconConfiguratorLayerSlotElement(
                "Flat Source",
                true,
                false,
                false,
                false,
                true);
            slot.UploadRequested += HandleAiFlatSourceUploadRequested;
            slot.ClearRequested += HandleAiFlatSourceClearRequested;
            slot.FilesDropped += HandleAiFlatSourceFilesDropped;
            string errorText = validationResult.LayerErrors.TryGetValue(IconLayerKind.FlatSource, out string error) ? error : string.Empty;
            slot.SetLayer(m_config.AiSplit.FlatSource, errorText);
            layerContent.Add(slot);

            if (m_aiConfiguration?.Success != true)
            {
                Label configurationLabel = CreateErrorLabel(BuildAiSplitConfigurationErrorMessage());
                layerContent.Add(configurationLabel);
                layerContent.Add(CreatePlaceholderLabel("Configuration issue does not remove the imported flat source."));
                layerContent.Add(CreatePlaceholderLabel("Switch to Manual mode to continue while AI Split is unavailable."));
            }

            ProgressBar progressBar = new ProgressBar
            {
                title = $"Progress {(int)(m_aiProgress * 100f)}%",
                value = m_aiProgress * 100f,
            };
            progressBar.SetEnabled(m_config.AiSplit.Status == GenerateStatus.Running);
            m_aiProgressBar = progressBar;
            layerContent.Add(progressBar);

            layerContent.Add(CreateAiAgreementSection());

            VisualElement actionRow = new VisualElement();
            actionRow.style.flexDirection = FlexDirection.Row;
            layerContent.Add(actionRow);

            Button generateButton = new Button(HandleGenerateClicked)
            {
                text = m_config.AiSplit.Status == GenerateStatus.Succeeded ? "Regenerate" : "Generate",
            };
            generateButton.SetEnabled(CanGenerateAi());
            generateButton.style.marginRight = 8;
            actionRow.Add(generateButton);

            Button cancelButton = new Button(HandleCancelGenerateClicked)
            {
                text = "Cancel",
            };
            cancelButton.SetEnabled(m_config.AiSplit.Status == GenerateStatus.Running);
            actionRow.Add(cancelButton);

            if (!string.IsNullOrWhiteSpace(m_config.AiSplit.ErrorMessage))
            {
                layerContent.Add(CreateErrorLabel(m_config.AiSplit.ErrorMessage));
                layerContent.Add(CreatePlaceholderLabel("You can retry generation or switch to Manual mode as a fallback."));
            }
        }

        private void BuildPreviewSection(VisualElement previewContent)
        {
            previewContent.Clear();

            VisualElement previewGrid = new VisualElement();
            previewGrid.AddToClassList("icon-configurator__preview-grid");
            previewGrid.Add(CreatePreviewCard("2D Feedback", GetCompositePreviewTexture(), false));
            previewGrid.Add(CreatePreviewCard("3D Spatial", GetSpatialPreviewTexture(), true));

            previewContent.Add(previewGrid);
        }

        private void BuildLocalizationSection(VisualElement localizationContent)
        {
            localizationContent.Clear();
            m_localizationRows.Clear();

            ScrollView scrollView = new ScrollView(ScrollViewMode.Vertical);
            scrollView.horizontalScrollerVisibility = ScrollerVisibility.Hidden;
            scrollView.style.maxHeight = 220;
            localizationContent.Add(scrollView);

            IconConfiguratorValidationResult validationResult = m_validator.Validate(m_config);

            for (int i = 0; i < m_config.Localizations.Count; i++)
            {
                int index = i;
                LocalizationEntry entry = m_config.Localizations[i];
                string errorText = validationResult.LocalizationErrors.TryGetValue(entry.LocaleCode, out string value)
                    ? value
                    : string.Empty;
                IconConfiguratorLocalizationRowElement row = new IconConfiguratorLocalizationRowElement(
                    entry,
                    new System.Collections.Generic.List<string>(IconConfiguratorLocales.SupportedLocales),
                    errorText);

                row.LocaleChanged += localeCode => HandleLocaleChanged(index, localeCode);
                row.AppNameChanged += appName => HandleAppNameChanged(index, appName);
                row.RemoveRequested += () => HandleRemoveLocalization(index);
                m_localizationRows.Add(row);
                scrollView.Add(row);
            }

            Button addButton = new Button(HandleAddLocalizationClicked)
            {
                text = "Add Locale",
            };
            addButton.SetEnabled(CanAddMoreLocales());
            localizationContent.Add(addButton);
        }

        private void HandleModeChanged(IconConfiguratorMode mode)
        {
            m_config.LastMode = mode;
            m_stateStore.Save();
            RebuildDynamicSections();
            UpdateBottomBarState();
        }

        private void HandlePreviewYawChanged(ChangeEvent<float> changeEvent)
        {
            m_config.PreviewYaw = Mathf.RoundToInt(changeEvent.newValue);

            if (m_spatialAngleLabel != null)
            {
                m_spatialAngleLabel.text = $"{m_config.PreviewYaw}\u00b0";
            }

            if (!m_yawDirty)
            {
                m_yawDirty = true;
                EditorApplication.update += HandleYawUpdate;
            }
        }

        private void HandleYawUpdate()
        {
            if (m_spatialPreviewImage != null)
            {
                ApplyPreviewTexture(m_spatialPreviewImage, GetSpatialPreviewTexture());
            }

            if (m_yawDirty)
            {
                m_yawDirty = false;
                EditorApplication.update -= HandleYawUpdate;
            }
        }

        private void HandleApplyClicked()
        {
            if (m_applyInProgress)
            {
                return;
            }

            m_statusMessage = string.Empty;
            m_applyInProgress = true;
            UpdateBottomBarState();
            Repaint();
            EditorApplication.delayCall -= ExecuteDeferredApply;
            EditorApplication.delayCall += ExecuteDeferredApply;
        }

        private void ExecuteDeferredApply()
        {
            try
            {
                IconApplyPreflightResult preflight = m_applyService.CreatePreflight(m_config, m_stateStore.GetConfigGuid());
                if (preflight.RequiresConfirmation)
                {
                    bool confirmed = EditorUtility.DisplayDialog(
                        "Confirm Apply",
                        BuildPreflightMessage(preflight),
                        "Apply",
                        "Cancel");

                    if (!confirmed)
                    {
                        m_statusMessage = "Apply cancelled.";
                        return;
                    }
                }

                IconApplyResult result = m_applyService.Apply(m_config, m_stateStore.GetConfigGuid());
                m_statusMessage = $"Apply completed. Wrote {result.WrittenFileCount} files, deleted {result.DeletedFileCount}, overwrote {result.OverwrittenFileCount}.";
            }
            catch (System.Exception exception)
            {
                m_statusMessage = exception.Message;
            }
            finally
            {
                m_applyInProgress = false;
                UpdateBottomBarState();
            }
        }

        private void HandleManualLayerUploadRequested(int layerIndex)
        {
            string sourcePath = EditorUtility.OpenFilePanelWithFilters(
                $"Select {IconLayerNaming.GetDisplayName(layerIndex)} image",
                string.Empty,
                IconConfiguratorImportService.GetSupportedImageFileFilters());

            if (string.IsNullOrWhiteSpace(sourcePath))
            {
                return;
            }

            TryImportManualLayer(layerIndex, sourcePath);
        }

        private void HandleManualLayerClearRequested(int layerIndex)
        {
            if (layerIndex < 0 || layerIndex >= m_config.Manual.Layers.Count)
            {
                return;
            }

            m_config.Manual.SetLayerAt(layerIndex, new IconLayerConfig
            {
                LayerKind = GetManualLayerKind(layerIndex),
                DisplayName = IconLayerNaming.GetDisplayName(layerIndex),
            });
            PersistAndRefresh(string.Empty);
        }

        private void HandleDeleteManualLayerRequested(int layerIndex)
        {
            if (!m_config.Manual.RemoveLayerAt(layerIndex))
            {
                m_statusMessage = "Manual mode must keep at least two layers.";
                UpdateBottomBarState();
                return;
            }

            PersistAndRefresh("Layer deleted.");
        }

        private void HandleMoveManualLayerUp(int layerIndex)
        {
            if (m_config.Manual.MoveLayer(layerIndex, layerIndex - 1))
            {
                PersistAndRefresh("Layer moved up.");
            }
        }

        private void HandleMoveManualLayerDown(int layerIndex)
        {
            if (m_config.Manual.MoveLayer(layerIndex, layerIndex + 1))
            {
                PersistAndRefresh("Layer moved down.");
            }
        }

        private void HandleAddManualLayerClicked()
        {
            if (m_config.Manual.Layers.Count >= ManualLayerState.MaxLayerCount)
            {
                m_statusMessage = $"Manual mode supports up to {ManualLayerState.MaxLayerCount} layers.";
                UpdateBottomBarState();
                return;
            }

            m_config.Manual.AddEmptyLayer();
            PersistAndRefresh("Layer slot added.");
        }

        private void HandleManualLayerFilesDropped(int layerIndex, string[] files)
        {
            if (files == null || files.Length == 0)
            {
                return;
            }

            TryImportManualLayer(layerIndex, files[0]);
        }

        private void HandleAiFlatSourceUploadRequested()
        {
            IconLayerConfig importedLayer = m_importService.ImportLayerFromDialog(IconLayerKind.FlatSource);
            if (importedLayer == null)
            {
                return;
            }

            m_config.AiSplit.FlatSource = importedLayer;
            RefreshAiStateFromInputs();
            PersistAndRefresh(string.Empty);
        }

        private void HandleAiFlatSourceClearRequested()
        {
            ResetAiSplitResults(clearFlatSource: true);
            RefreshAiStateFromInputs();
            PersistAndRefresh(string.Empty);
        }

        private void HandleAiFlatSourceFilesDropped(string[] files)
        {
            if (files == null || files.Length == 0)
            {
                return;
            }

            string sourcePath = files[0];
            if (!m_importService.TryImportLayer(sourcePath, IconLayerKind.FlatSource, out IconLayerConfig importedLayer, out string errorMessage))
            {
                m_statusMessage = errorMessage;
                UpdateBottomBarState();
                return;
            }

            m_config.AiSplit.FlatSource = importedLayer;
            ResetAiSplitResults(clearFlatSource: false);
            RefreshAiStateFromInputs();
            PersistAndRefresh($"Imported {importedLayer.OriginalFileName} as flat source.");
        }

        private void TryImportManualLayer(int layerIndex, string sourcePath)
        {
            if (!m_importService.TryImportLayer(sourcePath, GetManualLayerKind(layerIndex), out IconLayerConfig importedLayer, out string errorMessage))
            {
                m_statusMessage = errorMessage;
                UpdateBottomBarState();
                return;
            }

            importedLayer.DisplayName = IconLayerNaming.GetDisplayName(layerIndex);
            m_config.Manual.SetLayerAt(layerIndex, importedLayer);
            PersistAndRefresh($"Imported {importedLayer.OriginalFileName}.");
        }

        private void HandleAiAgreementChanged(ChangeEvent<bool> changeEvent)
        {
            m_config.AiSplit.HasAcceptedTerms = changeEvent.newValue;
            RefreshAiStateFromInputs();
            m_stateStore.Save();
            RebuildDynamicSections();
            UpdateBottomBarState();
        }

        private void HandleGlobalAiSplitConfigurationRefreshRequested()
        {
            RefreshAiSplitConfiguration(true);
        }

        private void RefreshAiSplitConfiguration(bool forceRefresh)
        {
            _ = forceRefresh;
            m_aiConfiguration = m_aiSplitServiceFactory.RefreshConfiguration(forceRefresh);
            m_aiSplitService = m_aiSplitServiceFactory.CreateService();
            m_statusMessage = BuildAiSplitConfigurationStatus();

            if (m_layerContent != null && m_previewContent != null && m_localizationContent != null)
            {
                RebuildDynamicSections();
                UpdateBottomBarState();
            }
        }

        private void HandleGenerateClicked()
        {
            if (!CanGenerateAi())
            {
                return;
            }

            m_aiProgress = 0f;
            m_config.AiSplit.Status = GenerateStatus.Running;
            m_config.AiSplit.ErrorMessage = string.Empty;
            m_config.AiSplit.ErrorType = AiSplitErrorType.None;
            m_stateStore.Save();
            RebuildDynamicSections();
            UpdateBottomBarState();

            m_aiSplitService.StartGenerate(
                m_config.AiSplit.FlatSource,
                m_stateStore.GetConfigGuid(),
                progress =>
                {
                    if (!m_isWindowActive)
                    {
                        return;
                    }

                    m_aiProgress = progress;
                    UpdateAiProgressBar();
                    Repaint();
                },
                (result, requestId, generatedAt) =>
                {
                    if (!m_isWindowActive)
                    {
                        return;
                    }

                    if (m_config.AiSplit.Status != GenerateStatus.Running)
                    {
                        return;
                    }

                    m_aiProgress = 1f;
                    m_config.AiSplit.Background = result.Background;
                    m_config.AiSplit.Foreground1 = result.Foreground1;
                    m_config.AiSplit.Foreground2 = result.Foreground2;
                    m_config.AiSplit.GeneratedLayers = new List<IconLayerConfig>(result.Layers);
                    m_config.AiSplit.GeneratedSdfs = new List<IconLayerConfig>(result.Sdfs);
                    m_config.AiSplit.TaskId = result.TaskId;
                    m_config.AiSplit.RequestId = requestId;
                    m_config.AiSplit.GeneratedAt = generatedAt;
                    m_config.AiSplit.ModelVersion = result.ModelVersion;
                    m_config.AiSplit.Status = GenerateStatus.Succeeded;
                    m_config.AiSplit.ErrorMessage = string.Empty;
                    m_config.AiSplit.ErrorType = result.ErrorType;
                    m_stateStore.Save();
                    RebuildDynamicSections();
                    UpdateBottomBarState();
                },
                error =>
                {
                    if (!m_isWindowActive)
                    {
                        return;
                    }

                    if (m_config.AiSplit.Status != GenerateStatus.Running)
                    {
                        return;
                    }

                    m_aiProgress = 0f;
                    m_config.AiSplit.Status = GenerateStatus.Failed;
                    m_config.AiSplit.ErrorMessage = error;
                    m_config.AiSplit.ErrorType = ClassifyAiError(error);
                    m_stateStore.Save();
                    RebuildDynamicSections();
                    UpdateBottomBarState();
                });
        }

        private void HandleCancelGenerateClicked()
        {
            if (m_config.AiSplit.Status != GenerateStatus.Running)
            {
                return;
            }

            m_aiSplitService.Cancel();
            m_aiProgress = 0f;

            m_config.AiSplit.EnsureDynamicResultLists();
            bool hasExistingResult = m_config.AiSplit.GeneratedLayers.Count >= ManualLayerState.MinLayerCount
                && m_config.AiSplit.GeneratedSdfs.Count == m_config.AiSplit.GeneratedLayers.Count;

            m_config.AiSplit.Status = hasExistingResult ? GenerateStatus.Cancelled : GenerateStatus.Ready;
            m_config.AiSplit.ErrorMessage = string.Empty;
            m_stateStore.Save();
            RebuildDynamicSections();
            UpdateBottomBarState();
        }

        private void CancelRunningAiSplitForShutdown()
        {
            if (m_config == null || m_config.AiSplit.Status != GenerateStatus.Running)
            {
                return;
            }

            m_aiSplitService?.Cancel();
            m_aiProgress = 0f;
            m_config.AiSplit.Status = GenerateStatus.Cancelled;
            m_config.AiSplit.ErrorMessage = string.Empty;
            m_stateStore?.Save();
        }

        private void HandleAddLocalizationClicked()
        {
            foreach (string locale in IconConfiguratorLocales.SupportedLocales)
            {
                if (HasLocale(locale))
                {
                    continue;
                }

                m_config.Localizations.Add(new LocalizationEntry
                {
                    LocaleCode = locale,
                    AppName = string.Empty,
                    IsDefault = locale == IconConfiguratorLocales.DefaultLocale,
                    CanRemove = locale != IconConfiguratorLocales.DefaultLocale,
                });
                IconConfiguratorConfigNormalizer.NormalizeLocalizations(m_config.Localizations);
                m_stateStore.Save();
                RebuildDynamicSections();
                UpdateBottomBarState();
                return;
            }
        }

        private void HandleLocaleChanged(int index, string localeCode)
        {
            if (index < 0 || index >= m_config.Localizations.Count)
            {
                return;
            }

            m_config.Localizations[index].LocaleCode = localeCode;
            IconConfiguratorConfigNormalizer.NormalizeLocalizations(m_config.Localizations);
            m_stateStore.Save();
            RebuildDynamicSections();
            UpdateBottomBarState();
        }

        private void HandleAppNameChanged(int index, string appName)
        {
            if (index < 0 || index >= m_config.Localizations.Count)
            {
                return;
            }

            m_config.Localizations[index].AppName = appName;
            m_stateStore.Save();
            RefreshLocalizationErrors();
            UpdateBottomBarState();
        }

        private void HandleRemoveLocalization(int index)
        {
            if (index < 0 || index >= m_config.Localizations.Count)
            {
                return;
            }

            if (!m_config.Localizations[index].CanRemove)
            {
                return;
            }

            m_config.Localizations.RemoveAt(index);
            m_stateStore.Save();
            RebuildDynamicSections();
            UpdateBottomBarState();
        }

        private void UpdateBottomBarState()
        {
            IconConfiguratorValidationResult result = m_validator.Validate(m_config);

            if (m_applyButton != null)
            {
                m_applyButton.SetEnabled(!m_applyInProgress && result.CanApply);
            }

            if (m_bottomStatusLabel == null)
            {
                return;
            }

            if (m_applyInProgress)
            {
                m_bottomStatusLabel.text = string.Empty;
                return;
            }

            if (!string.IsNullOrWhiteSpace(m_statusMessage))
            {
                m_bottomStatusLabel.text = m_statusMessage;
                return;
            }

            if (result.CanApply)
            {
                m_bottomStatusLabel.text = "Ready to apply";
                return;
            }

            if (result.GeneralErrors.Count > 0)
            {
                m_bottomStatusLabel.text = result.GeneralErrors[0];
                return;
            }

            m_bottomStatusLabel.text = m_config.LastMode == IconConfiguratorMode.Manual
                ? "Manual mode is incomplete"
                : "AI mode is incomplete";
        }

        private static Label CreatePlaceholderLabel(string text)
        {
            Label label = new Label(text);
            label.AddToClassList("icon-configurator__placeholder");
            return label;
        }

        private VisualElement CreateAiAgreementSection()
        {
            bool enabled = m_aiConfiguration?.Success == true;

            VisualElement agreement = new VisualElement();
            agreement.AddToClassList("icon-configurator__agreement");

            Toggle agreementToggle = new Toggle(k_AiAgreementToggleText)
            {
                value = m_config.AiSplit.HasAcceptedTerms,
            };
            agreementToggle.AddToClassList("icon-configurator__agreement-toggle");
            agreementToggle.SetEnabled(enabled);
            agreementToggle.RegisterValueChangedCallback(HandleAiAgreementChanged);
            agreement.Add(agreementToggle);

            Label disclaimer = new Label(k_AiAgreementDisclaimer);
            disclaimer.AddToClassList("icon-configurator__agreement-disclaimer");
            agreement.Add(disclaimer);

            return agreement;
        }

        private void RebuildDynamicSections()
        {
            BuildLayerSection(m_layerContent);
            RefreshPreviewSection();
            BuildLocalizationSection(m_localizationContent);
        }

        private void HandleRootGeometryChanged(GeometryChangedEvent changeEvent)
        {
            bool widthChanged = !Mathf.Approximately(changeEvent.oldRect.width, changeEvent.newRect.width);
            bool heightChanged = !Mathf.Approximately(changeEvent.oldRect.height, changeEvent.newRect.height);
            if (!widthChanged && !heightChanged)
            {
                return;
            }

            RefreshPreviewSection();
            Repaint();
        }

        private void RefreshPreviewSection()
        {
            if (m_previewContent == null)
            {
                return;
            }

            BuildPreviewSection(m_previewContent);
        }

        private Texture GetCompositePreviewTexture()
        {
            List<Texture2D> layers = GetActiveLayerTextures();

            if (m_preview2DTexture != null)
            {
                DestroyImmediate(m_preview2DTexture);
                m_preview2DTexture = null;
            }

            m_preview2DTexture = m_compositePreviewService.ComposePreview(layers, 300);
            return m_preview2DTexture;
        }

        private Texture GetSpatialPreviewTexture()
        {
            return m_spatialPreviewService.Render(GetActiveLayerTextures(), m_config.PreviewYaw);
        }

        private VisualElement CreatePreviewCard(string title, Texture texture, bool showSlider)
        {
            VisualElement container = new VisualElement();
            container.AddToClassList("icon-configurator__preview-card");

            if (showSlider)
            {
                container.AddToClassList("icon-configurator__preview-card--spatial");
            }

            VisualElement canvas = new VisualElement();
            canvas.AddToClassList("icon-configurator__preview-canvas");

            VisualElement shell = new VisualElement();
            shell.AddToClassList("icon-configurator__preview-shell");

            if (showSlider)
            {
                shell.AddToClassList("icon-configurator__preview-shell--spatial");
            }

            VisualElement viewport = new VisualElement();
            viewport.AddToClassList("icon-configurator__preview-viewport");
            viewport.AddToClassList("icon-configurator__preview-surface");

            if (!showSlider && texture != null)
            {
                viewport.AddToClassList("icon-configurator__preview-surface--checkerboard");
            }

            Image image = new Image
            {
                scaleMode = ScaleMode.ScaleToFit,
            };
            image.AddToClassList("icon-configurator__preview-image");
            ApplyPreviewTexture(image, texture);
            viewport.Add(image);
            
            if (showSlider)
            {
                m_spatialPreviewImage = image;
            }

            shell.Add(viewport);

            Label titleLabel = new Label(title);
            titleLabel.AddToClassList("icon-configurator__preview-card-title");
            titleLabel.AddToClassList("icon-configurator__preview-card-title--overlay");
            shell.Add(titleLabel);

            if (!showSlider)
            {
                canvas.Add(shell);
                container.Add(canvas);
                return container;
            }

            VisualElement sliderRow = new VisualElement();
            sliderRow.AddToClassList("icon-configurator__preview-slider-row");

            Label axisLabel = new Label("Y");
            axisLabel.AddToClassList("icon-configurator__preview-slider-axis");
            sliderRow.Add(axisLabel);

            Slider yawSlider = new Slider(-80f, 80f)
            {
                value = m_config.PreviewYaw,
            };
            yawSlider.AddToClassList("icon-configurator__preview-slider");
            yawSlider.RegisterValueChangedCallback(HandlePreviewYawChanged);
            // Slider dragging relies on the pointer manipulator and does not need keyboard focus.
            // Disable focus for the slider and its inner dragger to eliminate the lingering blue focus ring after dragging.
            yawSlider.focusable = false;
            yawSlider.RegisterCallback<AttachToPanelEvent>(_ =>
            {
                VisualElement dragger = yawSlider.Q("unity-dragger");
                if (dragger != null)
                {
                    dragger.focusable = false;
                }
            });
            sliderRow.Add(yawSlider);

            Label angleLabel = new Label($"{m_config.PreviewYaw}\u00b0");
            angleLabel.AddToClassList("icon-configurator__preview-slider-value");
            sliderRow.Add(angleLabel);
            
            m_spatialAngleLabel = angleLabel;

            VisualElement controls = new VisualElement();
            controls.AddToClassList("icon-configurator__preview-controls");
            controls.AddToClassList("icon-configurator__preview-controls--overlay");
            controls.Add(sliderRow);

            VisualElement overlay = new VisualElement();
            overlay.AddToClassList("icon-configurator__preview-overlay");
            overlay.Add(controls);
            shell.Add(overlay);

            canvas.Add(shell);
            container.Add(canvas);

            return container;
        }

        private static void ApplyPreviewTexture(Image image, Texture texture)
        {
            image.image = texture;
            image.style.display = texture == null ? DisplayStyle.None : DisplayStyle.Flex;
        }

        private void UpdateAiProgressBar()
        {
            if (m_aiProgressBar == null)
            {
                return;
            }

            int percent = (int)(m_aiProgress * 100f);
            m_aiProgressBar.value = m_aiProgress * 100f;
            m_aiProgressBar.title = $"Progress {percent}%";
        }

        private void RefreshAiStateFromInputs()
        {
            if (m_config.AiSplit.Status == GenerateStatus.Running)
            {
                return;
            }

            bool hasFlatSource = m_config.AiSplit.FlatSource != null && m_config.AiSplit.FlatSource.HasAssetReference;

            if (!hasFlatSource)
            {
                m_config.AiSplit.Status = GenerateStatus.Idle;
                m_config.AiSplit.ErrorMessage = string.Empty;
                return;
            }

            if (m_config.AiSplit.Status == GenerateStatus.Succeeded)
            {
                return;
            }

            m_config.AiSplit.Status = m_config.AiSplit.HasAcceptedTerms
                ? GenerateStatus.Ready
                : GenerateStatus.Idle;
        }

        private bool CanGenerateAi()
        {
            IconConfiguratorValidationResult result = m_validator.Validate(m_config);

            return m_config.AiSplit.Status != GenerateStatus.Running
                && HasAiFlatSource()
                && m_config.AiSplit.HasAcceptedTerms
                && HasValidAiConfiguration()
                && (m_config.AiSplit.Status == GenerateStatus.Ready
                    || m_config.AiSplit.Status == GenerateStatus.Succeeded
                    || m_config.AiSplit.Status == GenerateStatus.Failed
                    || m_config.AiSplit.Status == GenerateStatus.Cancelled)
                && result.CanGenerate;
        }

        private bool HasAiFlatSource()
        {
            return m_config?.AiSplit?.FlatSource != null && m_config.AiSplit.FlatSource.HasAssetReference;
        }

        private bool HasValidAiConfiguration()
        {
            return m_aiConfiguration?.Success == true
                && m_aiConfiguration.SelectedRegion != null;
        }

        private bool CanAddMoreLocales()
        {
            foreach (string locale in IconConfiguratorLocales.SupportedLocales)
            {
                if (!HasLocale(locale))
                {
                    return true;
                }
            }

            return false;
        }

        private bool HasLocale(string locale)
        {
            foreach (LocalizationEntry entry in m_config.Localizations)
            {
                if (entry.LocaleCode == locale)
                {
                    return true;
                }
            }

            return false;
        }

        private void HandleBeforeAssemblyReload()
        {
            CancelRunningAiSplitForShutdown();
        }

        private static Label CreateErrorLabel(string text)
        {
            Label label = new Label(text);
            label.style.color = new Color(1f, 0.45f, 0.45f);
            return label;
        }

        private string BuildAiSplitConfigurationStatus()
        {
            AiSplitTccStatus status = m_aiSplitServiceFactory.GetConfigurationStatus();
            return status.DisplayText;
        }

        private string BuildAiSplitConfigurationErrorMessage()
        {
            if (m_aiConfiguration == null)
            {
                return "AI Split configuration is unavailable.";
            }

            string prefix = m_aiConfiguration.ErrorType switch
            {
                AiSplitErrorType.TccNotConfigured => "AI Split TCC is not configured.",
                AiSplitErrorType.TccFetchFailed => "AI Split TCC fetch failed.",
                AiSplitErrorType.TccDisabled => "AI Split is disabled by TCC.",
                AiSplitErrorType.TccRegionMissing => "AI Split region configuration is missing.",
                AiSplitErrorType.TccFieldMissing => "AI Split TCC required field is missing.",
                _ => "AI Split configuration is unavailable.",
            };

            string message = string.IsNullOrWhiteSpace(m_aiConfiguration.ErrorMessage)
                ? prefix
                : prefix + " " + m_aiConfiguration.ErrorMessage;
            if (m_aiConfiguration.MissingFields.Count > 0)
            {
                message += " Missing: " + string.Join(", ", m_aiConfiguration.MissingFields) + ".";
            }

            return message;
        }

        private void RefreshLocalizationErrors()
        {
            IconConfiguratorValidationResult validationResult = m_validator.Validate(m_config);
            int count = Mathf.Min(m_localizationRows.Count, m_config.Localizations.Count);

            for (int i = 0; i < count; i++)
            {
                LocalizationEntry entry = m_config.Localizations[i];
                string errorText = validationResult.LocalizationErrors.TryGetValue(entry.LocaleCode, out string value)
                    ? value
                    : string.Empty;
                m_localizationRows[i].SetErrorText(errorText);
            }
        }

        private List<Texture2D> GetActiveLayerTextures()
        {
            List<Texture2D> textures = new List<Texture2D>();
            List<IconLayerConfig> activeLayers = GetActiveLayers();
            for (int i = 0; i < activeLayers.Count; i++)
            {
                if (activeLayers[i]?.Texture != null)
                {
                    textures.Add(activeLayers[i].Texture);
                }
            }

            return textures;
        }

        private List<IconLayerConfig> GetActiveLayers()
        {
            if (m_config.LastMode == IconConfiguratorMode.AiSplit)
            {
                m_config.AiSplit.EnsureDynamicResultLists();
                return new List<IconLayerConfig>(m_config.AiSplit.GeneratedLayers);
            }

            return new List<IconLayerConfig>(m_config.Manual.Layers);
        }

        private static IconLayerKind GetManualLayerKind(int layerIndex)
        {
            return IconLayerNaming.GetLayerKind(layerIndex);
        }

        private void PersistAndRefresh(string statusMessage)
        {
            m_statusMessage = statusMessage ?? string.Empty;
            m_stateStore.Save();
            RebuildDynamicSections();
            UpdateBottomBarState();
        }

        private void ResetAiSplitResults(bool clearFlatSource)
        {
            if (m_config.AiSplit.Status == GenerateStatus.Running)
            {
                m_aiSplitService?.Cancel();
            }

            m_aiProgress = 0f;

            if (clearFlatSource)
            {
                m_config.AiSplit.FlatSource = new IconLayerConfig
                {
                    LayerKind = IconLayerKind.FlatSource,
                };
            }

            m_config.AiSplit.Background = new IconLayerConfig
            {
                LayerKind = IconLayerKind.Background,
            };
            m_config.AiSplit.Foreground1 = new IconLayerConfig
            {
                LayerKind = IconLayerKind.Foreground1,
            };
            m_config.AiSplit.Foreground2 = new IconLayerConfig
            {
                LayerKind = IconLayerKind.Foreground2,
            };
            m_config.AiSplit.GeneratedLayers = new List<IconLayerConfig>();
            m_config.AiSplit.GeneratedSdfs = new List<IconLayerConfig>();
            m_config.AiSplit.TaskId = string.Empty;
            m_config.AiSplit.RequestId = string.Empty;
            m_config.AiSplit.ModelVersion = string.Empty;
            m_config.AiSplit.GeneratedAt = string.Empty;
            m_config.AiSplit.Status = clearFlatSource
                ? GenerateStatus.Idle
                : (m_config.AiSplit.HasAcceptedTerms ? GenerateStatus.Ready : GenerateStatus.Idle);
            m_config.AiSplit.ErrorMessage = string.Empty;
            m_config.AiSplit.ErrorType = AiSplitErrorType.None;
        }

        private static string BuildPreflightMessage(IconApplyPreflightResult preflight)
        {
            List<string> lines = new List<string>();
            if (preflight.OverwritePaths.Count > 0)
            {
                lines.Add($"Overwrite {preflight.OverwritePaths.Count} existing files?");
            }

            if (preflight.DeletePaths.Count > 0)
            {
                lines.Add($"Delete {preflight.DeletePaths.Count} stale locale files?");
            }

            lines.Add($"Write {preflight.PlannedWritePaths.Count} output files.");
            return string.Join("\n", lines);
        }

        private static AiSplitErrorType ClassifyAiError(string error)
        {
            if (string.Equals(error, AiSplitGenerationRateLimiter.RateLimitedMessage, System.StringComparison.Ordinal))
            {
                return AiSplitErrorType.RateLimited;
            }

            if (!string.IsNullOrWhiteSpace(error)
                && error.IndexOf("configuration", System.StringComparison.OrdinalIgnoreCase) >= 0)
            {
                return AiSplitErrorType.Configuration;
            }

            if (!string.IsNullOrWhiteSpace(error)
                && error.IndexOf("timed out", System.StringComparison.OrdinalIgnoreCase) >= 0)
            {
                return AiSplitErrorType.Timeout;
            }

            if (!string.IsNullOrWhiteSpace(error)
                && error.IndexOf("cancel", System.StringComparison.OrdinalIgnoreCase) >= 0)
            {
                return AiSplitErrorType.Cancelled;
            }

            return AiSplitErrorType.Unknown;
        }
    }
}
