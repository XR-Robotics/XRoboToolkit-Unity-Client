using System.IO;
using System.Text.RegularExpressions;
using NUnit.Framework;
using UnityEngine.UIElements;

namespace ByteDance.PICO.IconConfigurator.Editor.Tests
{
    public class IconConfiguratorWindowLayoutTests
    {
        private const string k_UssPath =
            "Packages/sdk/IconConfigurator/Editor/UI/USS/IconConfiguratorWindow.uss";

        [Test]
        public void ModeSegmentControl_WhenCreated_ReservesVisibleButtonHeight()
        {
            IconConfiguratorModeSegmentControl control = new IconConfiguratorModeSegmentControl();
            Button manualButton = control.Q<Button>(className: "icon-configurator__mode-button");

            Assert.That(control.ClassListContains("icon-configurator__mode-segment"), Is.True);
            Assert.That(control.resolvedStyle.minHeight.value, Is.GreaterThanOrEqualTo(28f));
            Assert.That(manualButton, Is.Not.Null);
            Assert.That(manualButton.resolvedStyle.minHeight.value, Is.GreaterThanOrEqualTo(24f));
        }

        [Test]
        public void WindowStyles_WhenHeightShrinks_KeepHeaderAndBottomBarVisible()
        {
            string ussContent = File.ReadAllText(k_UssPath);

            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__header\s*\{[^}]*flex-shrink:\s*0;",
                    RegexOptions.Singleline),
                Is.True);
            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__body\s*\{[^}]*min-height:\s*0;",
                    RegexOptions.Singleline),
                Is.True);
            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__bottom-bar\s*\{[^}]*flex-shrink:\s*0;",
                    RegexOptions.Singleline),
                Is.True);
        }

        [Test]
        public void OpenWindow_WhenInvoked_UsesUtilityWindowMode()
        {
            const string windowFilePath =
                "Packages/sdk/IconConfigurator/Editor/Windows/IconConfiguratorWindow.cs";

            string source = File.ReadAllText(windowFilePath);

            Assert.That(
                source.Contains("GetWindow<IconConfiguratorWindow>(true"),
                Is.True);
        }

        [Test]
        public void WindowStyles_WhenPreviewUsesTargetLayout_DefinesTwoColumnPreviewCards()
        {
            string ussContent = File.ReadAllText(k_UssPath);

            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__body-content\s*\{[^}]*flex-grow:\s*1;",
                    RegexOptions.Singleline),
                Is.True);
            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__section--preview\s*\{[^}]*flex-grow:\s*1;",
                    RegexOptions.Singleline),
                Is.True);
            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__preview-grid\s*\{[^}]*flex-direction:\s*row;",
                    RegexOptions.Singleline),
                Is.True);
            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__preview-card\s*\{[^}]*flex-grow:\s*1;",
                    RegexOptions.Singleline),
                Is.True);
            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__preview-slider-row\s*\{[^}]*justify-content:\s*space-between;",
                    RegexOptions.Singleline),
                Is.True);
        }

        [Test]
        public void WindowSource_WhenPreviewMatchesDesign_UsesPreviewGridAndInlineSlider()
        {
            const string windowPath =
                "Packages/sdk/IconConfigurator/Editor/Windows/IconConfiguratorWindow.cs";

            string source = File.ReadAllText(windowPath);

            Assert.That(source.Contains("icon-configurator__preview-grid"), Is.True);
            Assert.That(source.Contains("CreatePreviewCard("), Is.True);
            Assert.That(source.Contains("showSlider"), Is.True);
        }

        [Test]
        public void WindowSource_WhenWindowGeometryChanges_RefreshesPreviewGlobally()
        {
            const string windowPath =
                "Packages/sdk/IconConfigurator/Editor/Windows/IconConfiguratorWindow.cs";

            string source = File.ReadAllText(windowPath);

            Assert.That(source.Contains("contentContainer.AddToClassList(\"icon-configurator__body-content\")"), Is.True);
            Assert.That(source.Contains("RegisterCallback<GeometryChangedEvent>"), Is.True);
            Assert.That(source.Contains("HandleRootGeometryChanged"), Is.True);
            Assert.That(source.Contains("RefreshPreviewSection()"), Is.True);
        }

        [Test]
        public void WindowSource_WhenManualLayeringIsDynamic_UsesManualLayersCollectionAndReorderActions()
        {
            const string windowPath =
                "Packages/sdk/IconConfigurator/Editor/Windows/IconConfiguratorWindow.cs";

            string source = File.ReadAllText(windowPath);

            Assert.That(source.Contains("m_config.Manual.Layers"), Is.True);
            Assert.That(source.Contains("HandleMoveManualLayerUp"), Is.True);
            Assert.That(source.Contains("HandleMoveManualLayerDown"), Is.True);
            Assert.That(source.Contains("HandleAddManualLayerClicked"), Is.True);
        }

        [Test]
        public void WindowSource_WhenManualLayerLimitIsThree_UsesUpdatedHintTextAndSharedMaxCount()
        {
            const string windowPath =
                "Packages/sdk/IconConfigurator/Editor/Windows/IconConfiguratorWindow.cs";

            string source = File.ReadAllText(windowPath);

            Assert.That(source.Contains("Manual mode supports {ManualLayerState.MinLayerCount}-{ManualLayerState.MaxLayerCount} transparent PNG layers."), Is.True);
            Assert.That(source.Contains("supports up to {ManualLayerState.MaxLayerCount} layers"), Is.True);
        }

        [Test]
        public void WindowSource_WhenAiSplitServiceCreated_UsesFactoryInsteadOfDirectMock()
        {
            const string windowPath =
                "Packages/sdk/IconConfigurator/Editor/Windows/IconConfiguratorWindow.cs";

            string source = File.ReadAllText(windowPath);

            Assert.That(source.Contains("IconAiSplitServiceFactory"), Is.True);
            Assert.That(source.Contains("new MockIconAiSplitService()"), Is.False);
        }

        [Test]
        public void WindowSource_WhenAiSplitConfigRefreshes_ClearsCacheAndReloadsPanelState()
        {
            const string windowPath =
                "Packages/sdk/IconConfigurator/Editor/Windows/IconConfiguratorWindow.cs";

            string source = File.ReadAllText(windowPath);

            Assert.That(source.Contains("RefreshAiSplitConfiguration("), Is.True);
            Assert.That(source.Contains("m_aiSplitServiceFactory.RefreshConfiguration(forceRefresh)"), Is.True);
            Assert.That(source.Contains("BuildAiSplitConfigurationStatus("), Is.True);
        }

        [Test]
        public void WindowSource_WhenAiSplitConfigInvalid_KeepsFlatSourceAndShowsConfigurationReason()
        {
            const string windowPath =
                "Packages/sdk/IconConfigurator/Editor/Windows/IconConfiguratorWindow.cs";

            string source = File.ReadAllText(windowPath);

            Assert.That(source.Contains("BuildAiSplitConfigurationErrorMessage("), Is.True);
            Assert.That(source.Contains("Configuration issue does not remove the imported flat source."), Is.True);
        }

        [Test]
        public void WindowSource_WhenWindowDisables_CancelsAiSplitAndIgnoresLateCallbacks()
        {
            const string windowPath =
                "Packages/sdk/IconConfigurator/Editor/Windows/IconConfiguratorWindow.cs";

            string source = File.ReadAllText(windowPath);

            Assert.That(source.Contains("m_isWindowActive = true;"), Is.True);
            Assert.That(source.Contains("m_isWindowActive = false;"), Is.True);
            Assert.That(source.Contains("CancelRunningAiSplitForShutdown();"), Is.True);
            Assert.That(source.Contains("if (!m_isWindowActive)"), Is.True);
        }

        [Test]
        public void WindowSource_WhenGenerateIsEnabled_RequiresFlatSourceTermsAndValidConfiguration()
        {
            const string windowPath =
                "Packages/sdk/IconConfigurator/Editor/Windows/IconConfiguratorWindow.cs";

            string source = File.ReadAllText(windowPath);

            Assert.That(source.Contains("HasAiFlatSource()"), Is.True);
            Assert.That(source.Contains("HasValidAiConfiguration()"), Is.True);
            Assert.That(source.Contains("m_config.AiSplit.HasAcceptedTerms"), Is.True);
            Assert.That(source.Contains("result.CanGenerate"), Is.True);
        }

        [Test]
        public void WindowSource_WhenAiConfigurationIsValid_DoesNotRequireEnableFlag()
        {
            const string windowPath =
                "Packages/sdk/IconConfigurator/Editor/Windows/IconConfiguratorWindow.cs";

            string source = File.ReadAllText(windowPath);

            Assert.That(source.Contains("m_aiConfiguration?.Success == true"), Is.True);
            Assert.That(source.Contains("m_aiConfiguration.SelectedRegion != null"), Is.True);
            Assert.That(source.Contains("m_aiConfiguration.Config?.Enable == true"), Is.False);
        }

        [Test]
        public void EditorMenuSource_WhenTask3ControlsExist_HidesAiSplitEnvironmentCommandsByDefault()
        {
            const string menuPath =
                "Packages/sdk/IconConfigurator/Editor/Services/AiSplitEnvironmentMenu.cs";

            string source = File.ReadAllText(menuPath);

            Assert.That(source.Contains("#if ICON_CONFIGURATOR_ENABLE_AI_SPLIT_DEBUG_MENU"), Is.True);
            Assert.That(source.Contains("PICO/Icon Configurator/AI Split/Use PPE Internal"), Is.True);
            Assert.That(source.Contains("PICO/Icon Configurator/AI Split/Use CN"), Is.True);
            Assert.That(source.Contains("PICO/Icon Configurator/AI Split/Use Global"), Is.True);
            Assert.That(source.Contains("PICO/Icon Configurator/AI Split/Show Current"), Is.True);
            Assert.That(source.Contains("PICO/Icon Configurator/AI Split/Refresh AI Split Config"), Is.True);
            Assert.That(source.Contains("IconAiSplitServiceFactory.CreateDefault()"), Is.True);
            Assert.That(source.Contains("factory.ClearConfigurationCache()"), Is.True);
        }

        [Test]
        public void WindowSource_WhenAiSplitSubmenuExists_HidesExplicitOpenWindowMenuItemByDefault()
        {
            const string windowPath =
                "Packages/sdk/IconConfigurator/Editor/Windows/IconConfiguratorWindow.cs";

            string source = File.ReadAllText(windowPath);

            Assert.That(source.Contains("#if ICON_CONFIGURATOR_ENABLE_AI_SPLIT_DEBUG_MENU"), Is.True);
            Assert.That(source.Contains("PICO/Icon Configurator/Open Window"), Is.True);
        }

        [Test]
        public void WindowSource_WhenAiPreviewUsesGeneratedResult_ReadsDynamicLayerList()
        {
            const string windowPath =
                "Packages/sdk/IconConfigurator/Editor/Windows/IconConfiguratorWindow.cs";

            string source = File.ReadAllText(windowPath);

            Assert.That(source.Contains("GeneratedLayers"), Is.True);
            Assert.That(source.Contains("return new List<IconLayerConfig>\n                {\n                    m_config.AiSplit.Background"), Is.False);
        }

        [Test]
        public void LocalizationRow_WhenAppNameChanges_CanRefreshInlineError()
        {
            const string rowPath =
                "Packages/sdk/IconConfigurator/Editor/UI/Elements/LocalizationRowElement.cs";
            const string windowPath =
                "Packages/sdk/IconConfigurator/Editor/Windows/IconConfiguratorWindow.cs";

            string rowSource = File.ReadAllText(rowPath);
            string windowSource = File.ReadAllText(windowPath);

            Assert.That(rowSource.Contains("SetErrorText("), Is.True);
            Assert.That(windowSource.Contains("RefreshLocalizationErrors()"), Is.True);
            Assert.That(windowSource.Contains("m_localizationRows"), Is.True);
        }

        public void LocalizationRow_WhenLocaleOptionsBuilt_ExcludesLocalesUsedByOtherRows()
        {
            const string windowPath =
                "Packages/sdk/IconConfigurator/Editor/Windows/IconConfiguratorWindow.cs";

            string source = File.ReadAllText(windowPath);

            Assert.That(source.Contains("BuildLocaleOptionsForRow(index)"), Is.True);
            Assert.That(source.Contains("HasLocale(locale, index)"), Is.True);
            Assert.That(source.Contains("new System.Collections.Generic.List<string>(IconConfiguratorLocales.SupportedLocales)"), Is.False);
        }

        [Test]
        public void LocaleDefinitions_WhenSupportedLocalesDeclared_OnlyContainZhEnJaKo()
        {
            const string localesPath =
                "Packages/sdk/IconConfigurator/Editor/Models/IconConfiguratorLocales.cs";

            string source = File.ReadAllText(localesPath);
            Match supportedMatch = Regex.Match(
                source,
                @"s_supportedLocales\s*=\s*\{(?<body>.*?)\};",
                RegexOptions.Singleline);

            Assert.That(supportedMatch.Success, Is.True);
            string supportedBody = supportedMatch.Groups["body"].Value;
            Assert.That(supportedBody.Contains("\"en-US\""), Is.True);
            Assert.That(supportedBody.Contains("\"zh-CN\""), Is.True);
            Assert.That(supportedBody.Contains("\"ja-JP\""), Is.True);
            Assert.That(supportedBody.Contains("\"ko-KR\""), Is.True);
            Assert.That(supportedBody.Contains("\"de-DE\""), Is.False);
            Assert.That(supportedBody.Contains("\"fr-FR\""), Is.False);
        }

        [Test]
        public void WindowSource_WhenApplyStarts_ClearsStatusBeforeDeferredApply()
        {
            const string windowPath =
                "Packages/sdk/IconConfigurator/Editor/Windows/IconConfiguratorWindow.cs";

            string source = File.ReadAllText(windowPath);

            Assert.That(source.Contains("m_applyInProgress"), Is.True);
            Assert.That(source.Contains("EditorApplication.delayCall += ExecuteDeferredApply"), Is.True);
            Assert.That(source.Contains("m_bottomStatusLabel.text = string.Empty;"), Is.True);
        }

        [Test]
        public void WindowSource_WhenManualLayerSlotsSupportDragUpload_RegistersDragCallbacks()
        {
            const string slotPath =
                "Packages/sdk/IconConfigurator/Editor/UI/Elements/IconLayerSlotElement.cs";

            string source = File.ReadAllText(slotPath);

            Assert.That(source.Contains("RegisterCallback<DragUpdatedEvent>"), Is.True);
            Assert.That(source.Contains("RegisterCallback<DragPerformEvent>"), Is.True);
            Assert.That(source.Contains("FilesDropped"), Is.True);
        }

        [Test]
        public void WindowSource_WhenAiFlatSourceDropped_ClearsPreviousGeneratedResult()
        {
            const string windowPath =
                "Packages/sdk/IconConfigurator/Editor/Windows/IconConfiguratorWindow.cs";

            string source = File.ReadAllText(windowPath);
            Match handlerMatch = Regex.Match(
                source,
                @"private void HandleAiFlatSourceFilesDropped\(string\[\] files\)(?<body>.*?)\r?\n        private void TryImportManualLayer",
                RegexOptions.Singleline);

            Assert.That(handlerMatch.Success, Is.True);
            string handlerBody = handlerMatch.Groups["body"].Value;
            Assert.That(handlerBody.Contains("m_config.AiSplit.FlatSource = importedLayer;"), Is.True);
            Assert.That(handlerBody.Contains("ResetAiSplitResults(clearFlatSource: false);"), Is.True);
            Assert.That(
                handlerBody.IndexOf("ResetAiSplitResults(clearFlatSource: false);", System.StringComparison.Ordinal),
                Is.LessThan(handlerBody.IndexOf("RefreshAiStateFromInputs();", System.StringComparison.Ordinal)));
        }

        [Test]
        public void WindowStyles_WhenPreviewMatchesDesign_UsesCompactTwoCardSpacing()
        {
            string ussContent = File.ReadAllText(k_UssPath);

            Assert.That(ussContent.Contains(".icon-configurator__preview-grid"), Is.True);
            Assert.That(ussContent.Contains(".icon-configurator__preview-card"), Is.True);
            Assert.That(ussContent.Contains(".icon-configurator__preview-surface"), Is.True);
            Assert.That(ussContent.Contains(".icon-configurator__preview-slider-row"), Is.True);
        }

        [Test]
        public void WindowSource_WhenPreviewLayoutChanges_DoesNotRenameLayerOrLocalizationSections()
        {
            const string uxmlPath =
                "Packages/sdk/IconConfigurator/Editor/UI/UXML/IconConfiguratorWindow.uxml";

            string source = File.ReadAllText(uxmlPath);

            Assert.That(source.Contains("icon-configurator__layers"), Is.True);
            Assert.That(source.Contains("icon-configurator__localization"), Is.True);
        }

        [Test]
        public void WindowStyles_When2DPreviewUsesDesignLikeViewport_DefinesCheckerboardAndCenteredViewport()
        {
            string ussContent = File.ReadAllText(k_UssPath);

            Assert.That(ussContent.Contains(".icon-configurator__preview-viewport"), Is.True);
            Assert.That(ussContent.Contains(".icon-configurator__preview-surface--checkerboard"), Is.True);
            Assert.That(ussContent.Contains(".icon-configurator__preview-image"), Is.True);
        }

        [Test]
        public void WindowSource_When2DPreviewUsesCenteredViewport_AddsCheckerboardViewportClasses()
        {
            const string windowPath =
                "Packages/sdk/IconConfigurator/Editor/Windows/IconConfiguratorWindow.cs";

            string source = File.ReadAllText(windowPath);

            Assert.That(source.Contains("icon-configurator__preview-viewport"), Is.True);
            Assert.That(source.Contains("icon-configurator__preview-surface--checkerboard"), Is.True);
            Assert.That(source.Contains("icon-configurator__preview-image"), Is.True);
        }

        [Test]
        public void WindowStyles_When2DPreviewUsesCheckerboard_UsesCenteredContentAlignment()
        {
            string ussContent = File.ReadAllText(k_UssPath);

            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__preview-viewport\s*\{[^}]*justify-content:\s*center;[^}]*align-items:\s*center;",
                    RegexOptions.Singleline),
                Is.True);
        }

        [Test]
        public void WindowStyles_WhenPreviewCardsMatchDesign_DefinesCanvasAndControlStripClasses()
        {
            string ussContent = File.ReadAllText(k_UssPath);

            Assert.That(ussContent.Contains(".icon-configurator__preview-canvas"), Is.True);
            Assert.That(ussContent.Contains(".icon-configurator__preview-controls"), Is.True);
            Assert.That(ussContent.Contains(".icon-configurator__preview-card--spatial"), Is.True);
        }

        [Test]
        public void WindowSource_WhenPreviewCardsMatchDesign_UsesCanvasAndSpatialControlContainers()
        {
            const string windowPath =
                "Packages/sdk/IconConfigurator/Editor/Windows/IconConfiguratorWindow.cs";

            string source = File.ReadAllText(windowPath);

            Assert.That(source.Contains("icon-configurator__preview-canvas"), Is.True);
            Assert.That(source.Contains("icon-configurator__preview-controls"), Is.True);
            Assert.That(source.Contains("icon-configurator__preview-card--spatial"), Is.True);
        }

        [Test]
        public void WindowStyles_WhenPreviewCardsMatchDesign_GivesCanvasSharedHeightAndFooterStrip()
        {
            string ussContent = File.ReadAllText(k_UssPath);

            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__preview-canvas\s*\{[^}]*min-height:\s*160px;",
                    RegexOptions.Singleline),
                Is.True);
            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__preview-controls\s*\{[^}]*min-height:\s*32px;",
                    RegexOptions.Singleline),
                Is.True);
        }

        [Test]
        public void WindowStyles_WhenPreviewCardsNeedEqualWidth_DefinesGapAndZeroBasis()
        {
            string ussContent = File.ReadAllText(k_UssPath);

            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__preview-grid\s*\{[^}]*column-gap:\s*12px;",
                    RegexOptions.Singleline),
                Is.True);
            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__preview-card\s*\{[^}]*flex-basis:\s*0;",
                    RegexOptions.Singleline),
                Is.True);
        }

        [Test]
        public void WindowStyles_WhenPreviewCardsNeedEqualWidth_UsesStretchAndSpacing()
        {
            string ussContent = File.ReadAllText(k_UssPath);

            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__preview-grid\s*\{[^}]*align-items:\s*stretch;",
                    RegexOptions.Singleline),
                Is.True);
        }

        [Test]
        public void WindowStyles_WhenPreviewGapMustBeVisible_DefinesCardShellBackgroundAndPadding()
        {
            string ussContent = File.ReadAllText(k_UssPath);

            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__preview-card\s*\{[^}]*padding:\s*6px;",
                    RegexOptions.Singleline),
                Is.True);
            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__preview-card\s*\{[^}]*background-color:\s*rgb\(52,\s*52,\s*56\);",
                    RegexOptions.Singleline),
                Is.True);
        }

        [Test]
        public void WindowStyles_WhenPreviewGapMustBeVisible_KeepsSurfaceFlushInsideShell()
        {
            string ussContent = File.ReadAllText(k_UssPath);

            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__preview-card-title\s*\{[^}]*margin-bottom:\s*8px;",
                    RegexOptions.Singleline),
                Is.True);
        }

        [Test]
        public void WindowStyles_WhenPreviewNeedsSoftCorners_DefinesSubtleCardAndSurfaceRadius()
        {
            string ussContent = File.ReadAllText(k_UssPath);

            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__preview-card\s*\{[^}]*border-radius:\s*6px;",
                    RegexOptions.Singleline),
                Is.True);
            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__preview-surface\s*\{[^}]*border-radius:\s*4px;",
                    RegexOptions.Singleline),
                Is.True);
        }

        [Test]
        public void WindowSource_WhenSpatialPreviewUsesOverlayControls_CreatesOverlayContainers()
        {
            const string windowPath =
                "Packages/sdk/IconConfigurator/Editor/Windows/IconConfiguratorWindow.cs";

            string source = File.ReadAllText(windowPath);

            Assert.That(
                source.Contains("icon-configurator__preview-shell"),
                Is.True);
            Assert.That(
                source.Contains("icon-configurator__preview-shell--spatial"),
                Is.True);
            Assert.That(
                source.Contains("icon-configurator__preview-overlay"),
                Is.True);
        }

        [Test]
        public void WindowStyles_WhenSpatialOverlayMatchesDesign_AttachesBarToCanvasEdges()
        {
            string ussContent = File.ReadAllText(k_UssPath);

            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__preview-shell\s*\{[^}]*position:\s*relative;",
                    RegexOptions.Singleline),
                Is.True);
            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__preview-overlay\s*\{[^}]*left:\s*0;[^}]*right:\s*0;[^}]*bottom:\s*0;",
                    RegexOptions.Singleline),
                Is.True);
            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__preview-controls--overlay\s*\{[^}]*min-height:\s*24px;[^}]*border-top-left-radius:\s*4px;[^}]*border-top-right-radius:\s*4px;",
                    RegexOptions.Singleline),
                Is.True);
        }

        [Test]
        public void WindowStyles_WhenSpatialOverlayMatchesDesign_UsesLightTextAndSliderColors()
        {
            string ussContent = File.ReadAllText(k_UssPath);

            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__preview-slider-axis\s*\{[^}]*color:\s*rgb\(236,\s*236,\s*236\);",
                    RegexOptions.Singleline),
                Is.True);
            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__preview-slider-value\s*\{[^}]*color:\s*rgb\(236,\s*236,\s*236\);",
                    RegexOptions.Singleline),
                Is.True);
            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__preview-controls--overlay\s+\.unity-base-slider__tracker\s*\{[^}]*background-color:\s*rgba\(255,\s*255,\s*255,\s*0\.35\);",
                    RegexOptions.Singleline),
                Is.True);
        }

        [Test]
        public void WindowStyles_WhenSpatialOverlayMatchesDesign_UsesLightOverlayBackground()
        {
            string ussContent = File.ReadAllText(k_UssPath);

            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__preview-controls--overlay\s*\{[^}]*background-color:\s*rgba\(178,\s*178,\s*184,\s*0\.98\);",
                    RegexOptions.Singleline),
                Is.True);
        }

        [Test]
        public void WindowSource_WhenPreviewTitlesFloatInsideCanvas_AddsOverlayTitleClassToBothCards()
        {
            const string windowPath =
                "Packages/sdk/IconConfigurator/Editor/Windows/IconConfiguratorWindow.cs";

            string source = File.ReadAllText(windowPath);

            Assert.That(
                source.Contains("icon-configurator__preview-card-title--overlay"),
                Is.True);
            Assert.That(
                Regex.Matches(source, "shell.Add\\(titleLabel\\);").Count,
                Is.GreaterThan(0));
        }

        [Test]
        public void WindowStyles_WhenPreviewTitlesFloatInsideCanvas_UsesAbsoluteTopLeftBadge()
        {
            string ussContent = File.ReadAllText(k_UssPath);

            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__preview-card-title--overlay\s*\{[^}]*position:\s*absolute;[^}]*top:\s*8px;[^}]*left:\s*8px;[^}]*margin-bottom:\s*0;",
                    RegexOptions.Singleline),
                Is.True);
        }

        [Test]
        public void WindowStyles_WhenPreviewResizes_KeepsCardsShrinkableAtEqualWidth()
        {
            string ussContent = File.ReadAllText(k_UssPath);

            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__preview-grid\s*\{[^}]*flex-grow:\s*1;",
                    RegexOptions.Singleline),
                Is.True);
            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__preview-card\s*\{[^}]*min-width:\s*0;",
                    RegexOptions.Singleline),
                Is.True);
        }

        [Test]
        public void WindowStyles_WhenPreviewMatchesLighterDesign_UsesBrighterCanvasAndBadgeTones()
        {
            string ussContent = File.ReadAllText(k_UssPath);

            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__preview-card-title\s*\{[^}]*background-color:\s*rgb\(132,\s*132,\s*140\);",
                    RegexOptions.Singleline),
                Is.True);
            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__preview-surface\s*\{[^}]*background-color:\s*rgb\(150,\s*150,\s*156\);",
                    RegexOptions.Singleline),
                Is.True);
        }

        [Test]
        public void WindowStyles_WhenPreviewMatchesLighterDesign_UsesBrighterSpatialFooterTone()
        {
            string ussContent = File.ReadAllText(k_UssPath);

            Assert.That(
                Regex.IsMatch(
                    ussContent,
                    @"\.icon-configurator__preview-controls--overlay\s*\{[^}]*background-color:\s*rgba\(178,\s*178,\s*184,\s*0\.98\);",
                    RegexOptions.Singleline),
                Is.True);
        }
    }
}
