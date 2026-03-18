using System;
using System.Threading.Tasks;

using UnityEditor;
using UnityEngine;

using Codice.Client.Common;
using Codice.Client.Common.EventTracking;
using Codice.Client.Common.Threading;
using Codice.CM.Common;
using Codice.LogWrapper;
using GluonGui;
using PlasticGui;
using PlasticGui.WorkspaceWindow;
using PlasticGui.WorkspaceWindow.NotificationBar;
using Unity.PlasticSCM.Editor.AssetMenu;
using Unity.PlasticSCM.Editor.AssetUtils;
using Unity.PlasticSCM.Editor.Configuration;
using Unity.PlasticSCM.Editor.Configuration.CloudEdition.Welcome;
using Unity.PlasticSCM.Editor.Inspector;
using Unity.PlasticSCM.Editor.Tool;
using Unity.PlasticSCM.Editor.UI;
using Unity.PlasticSCM.Editor.UI.Avatar;
using Unity.PlasticSCM.Editor.UI.Progress;
using Unity.PlasticSCM.Editor.UI.StatusBar;
using Unity.PlasticSCM.Editor.Views.CreateWorkspace;
using Unity.PlasticSCM.Editor.Views.Welcome;
using Unity.PlasticSCM.Editor.WebApi;

using GluonCheckIncomingChanges = PlasticGui.Gluon.WorkspaceWindow.CheckIncomingChanges;
using GluonNewIncomingChangesUpdater = PlasticGui.Gluon.WorkspaceWindow.NewIncomingChangesUpdater;
using PlasticAssetModificationProcessor = Unity.PlasticSCM.Editor.AssetUtils.Processor.AssetModificationProcessor;

namespace Unity.PlasticSCM.Editor
{
    internal class PlasticWindow : EditorWindow,
        CheckIncomingChanges.IAutoRefreshIncomingChangesView,
        GluonCheckIncomingChanges.IAutoRefreshIncomingChangesView,
        CreateWorkspaceView.ICreateWorkspaceListener
    {
        internal bool ShowWelcomeViewForTesting { get; set; }

        internal WorkspaceWindow WorkspaceWindowForTesting { get { return mWorkspaceWindow; } }
        
        internal ViewSwitcher ViewSwitcherForTesting { get { return mViewSwitcher; } }

        internal CmConnection CmConnectionForTesting { get { return CmConnection.Get(); } }
        
        internal WelcomeView GetWelcomeView()
        {
            if (mWelcomeView != null)
                return mWelcomeView;

            mWelcomeView = new WelcomeView(
                this,
                this,
                PlasticGui.Plastic.API,
                PlasticGui.Plastic.WebRestAPI,
                CmConnection.Get());

            return mWelcomeView;
        }

        internal void DisableCollabIfEnabledWhenLoaded()
        {
            mDisableCollabIfEnabledWhenLoaded = true;
        }

        internal PlasticProjectSettingsProvider.IAutoRefreshView GetPendingChangesView()
        {
            return mViewSwitcher != null ? mViewSwitcher.PendingChangesTab : null;
        }

        internal void UpdateWindowIcon(PlasticNotification.Status status)
        {
            Texture windowIcon = PlasticNotification.GetIcon(status);

            if (titleContent.image != windowIcon)
                titleContent.image = windowIcon;
        }

        internal void RefreshWorkspaceUI()
        {
            InitializePlastic();
            Repaint();

            OnFocus();
        }

        internal void InitializePlastic()
        {
            if (mForceToReOpen)
            {
                mForceToReOpen = false;
                return;
            }

            try
            {
                if (UnityConfigurationChecker.NeedsConfiguration())
                    return;

                mWkInfo = FindWorkspace.InfoForApplicationPath(
                    ApplicationDataPath.Get(), PlasticGui.Plastic.API);

                if (mWkInfo == null)
                    return;

                PlasticPlugin.EnableForWorkspace();

                DisableVCSIfEnabled(mWkInfo.ClientPath);

                mIsGluonMode = PlasticGui.Plastic.API.IsGluonWorkspace(mWkInfo);

                mViewHost = new ViewHost();

                mStatusBar = new StatusBar();

                mViewSwitcher = new ViewSwitcher(
                    PlasticGui.Plastic.API.GetRepositorySpec(mWkInfo),
                    mWkInfo,
                    mViewHost,
                    mIsGluonMode,
                    PlasticPlugin.AssetStatusCache,
                    mShowDownloadPlasticExeWindow,
                    mProcessExecutor,
                    PlasticPlugin.WorkspaceOperationsMonitor,
                    mStatusBar,
                    this);

                InitializeNewIncomingChanges(mWkInfo, mIsGluonMode, mViewSwitcher);

                // Create a CooldownWindowDelayer to make the auto-refresh changes delayed.
                // In this way, we cover the following scenario:
                // * When Unity Editor window is activated it writes some files to its Temp
                //   folder. This causes the fswatcher to process those events.
                // * We need to wait until the fswatcher finishes processing the events,
                //   otherwise the NewChangesInWk method will return TRUE because there
                //   are pending events to process, which causes an unwanted 'get pending
                //   changes' operation when there are no new changes.
                // * So, we need to delay the auto-refresh call in order
                //   to give the fswatcher enough time to process the events.
                mCooldownAutoRefreshChangesAction = new CooldownWindowDelayer(
                    () =>
                    {
                        mViewSwitcher.AutoRefreshPendingChangesView();
                        mViewSwitcher.AutoRefreshIncomingChangesView();
                    },
                    UnityConstants.AUTO_REFRESH_CHANGES_DELAYED_INTERVAL);

                mWorkspaceWindow = new WorkspaceWindow(
                    mWkInfo,
                    mViewHost,
                    mViewSwitcher,
                    mViewSwitcher,
                    mDeveloperNewIncomingChangesUpdater,
                    this);

                mViewSwitcher.SetWorkspaceWindow(mWorkspaceWindow);
                mViewSwitcher.ShowInitialView();

                PlasticApp.RegisterWorkspaceWindow(mWorkspaceWindow);
                PlasticPlugin.WorkspaceOperationsMonitor.RegisterWindow(
                    mWorkspaceWindow,
                    mViewHost,
                    mDeveloperNewIncomingChangesUpdater);

                UnityStyles.Initialize(Repaint);

                AssetMenuItems.BuildOperations(
                    mWkInfo,
                    mWorkspaceWindow,
                    mViewSwitcher,
                    mViewSwitcher,
                    mViewHost,
                    PlasticPlugin.WorkspaceOperationsMonitor,
                    mDeveloperNewIncomingChangesUpdater,
                    PlasticPlugin.AssetStatusCache,
                    mViewSwitcher,
                    mViewSwitcher,
                    mShowDownloadPlasticExeWindow,
                    mIsGluonMode);

                DrawInspectorOperations.BuildOperations(
                    mWkInfo,
                    mWorkspaceWindow,
                    mViewSwitcher,
                    mViewSwitcher,
                    mViewHost,
                    PlasticPlugin.WorkspaceOperationsMonitor,
                    mDeveloperNewIncomingChangesUpdater,
                    PlasticPlugin.AssetStatusCache,
                    mViewSwitcher,
                    mViewSwitcher,
                    mShowDownloadPlasticExeWindow,
                    mIsGluonMode);

                mLastUpdateTime = EditorApplication.timeSinceStartup;

                mViewSwitcher.ShowBranchesViewIfNeeded();
                mViewSwitcher.ShowLocksViewIfNeeded();

                // Note: this need to be initialized regardless of the type of the UVCS Edition installed
                InitializeCloudSubscriptionData(mWkInfo);

                if (!EditionToken.IsCloudEdition())
                    return;

                InitializeNotificationBarUpdater(
                    mWkInfo, mStatusBar.NotificationBar);
            }
            catch (Exception ex)
            {
                mException = ex;

                ExceptionsHandler.HandleException("InitializePlastic", ex);
            }
        }

        void CheckIncomingChanges.IAutoRefreshIncomingChangesView.IfVisible()
        {
            mViewSwitcher.AutoRefreshIncomingChangesView();
        }

        void GluonCheckIncomingChanges.IAutoRefreshIncomingChangesView.IfVisible()
        {
            mViewSwitcher.AutoRefreshIncomingChangesView();
        }

        void CreateWorkspaceView.ICreateWorkspaceListener.OnWorkspaceCreated(
            WorkspaceInfo wkInfo, bool isGluonMode)
        {
            mWkInfo = wkInfo;
            mIsGluonMode = isGluonMode;
            mWelcomeView = null;

            PlasticPlugin.Enable();

            if (mIsGluonMode)
                ConfigurePartialWorkspace.AsFullyChecked(mWkInfo);

            InitializePlastic();
            Repaint();
        }

        void OnEnable()
        {
            mLog.Debug("OnEnable");

            wantsMouseMove = true;

            if (mException != null)
                return;

            minSize = new Vector2(
                UnityConstants.PLASTIC_WINDOW_MIN_SIZE_WIDTH,
                UnityConstants.PLASTIC_WINDOW_MIN_SIZE_HEIGHT);

            UpdateWindowIcon(PlasticNotification.Status.None);

            RegisterApplicationFocusHandlers(this);

            if (!PlasticPlugin.ConnectionMonitor.IsConnected)
                return;

            PlasticPlugin.Enable();

            InitializePlastic();
        }

        void OnDisable()
        {
            mLog.Debug("OnDisable");

            // We need to disable MonoFSWatcher because otherwise it hangs
            // when you move the window between monitors with different scale
            PlasticApp.DisableMonoFsWatcherIfNeeded();

            if (mException != null)
                return;

            UnRegisterApplicationFocusHandlers(this);

            ClosePlastic(this);
        }

        void OnDestroy()
        {
            mLog.Debug("OnDestroy");

            if (mException != null)
                return;

            if (mWkInfo == null)
                return;

            if (!PlasticApp.HasRunningOperation())
                return;

            bool bCloseWindow = GuiMessage.ShowQuestion(
                PlasticLocalization.GetString(PlasticLocalization.Name.OperationRunning),
                PlasticLocalization.GetString(PlasticLocalization.Name.ConfirmClosingRunningOperation),
                PlasticLocalization.GetString(PlasticLocalization.Name.YesButton));

            if (bCloseWindow)
                return;

            mLog.Debug(
                "Show window again because the user doesn't want " +
                "to quit it due to there is an operation running");

            mForceToReOpen = true;

            ReOpenPlasticWindow(this);
        }

        void OnFocus()
        {
            mLog.Debug("OnFocus");

            if (mException != null)
                return;

            if (mWkInfo == null)
                return;

            if (!PlasticPlugin.ConnectionMonitor.IsConnected)
                return;

            // We don't want to auto-refresh the views when the window
            // is focused due to a right mouse button click because
            // if there is no internet connection a dialog appears and
            // it prevents being able to open the context menu in order
            // to close the Plastic SCM window
            if (Mouse.IsRightMouseButtonPressed(Event.current))
                return;

            mCooldownAutoRefreshChangesAction.Ping();
        }

        void OnGUI()
        {
            if (!PlasticPlugin.ConnectionMonitor.IsConnected)
            {
                DoNotConnectedArea();
                return;
            }

            if (mException != null)
            {
                DoExceptionErrorArea();
                return;
            }

            try
            {
                // IMPORTANT: disable collab (if needed)
                // must be executed before the next if statement
                // where we check if collab is enabled
                if (mDisableCollabIfEnabledWhenLoaded)
                {
                    mDisableCollabIfEnabledWhenLoaded = false;
                    DisableCollabIfEnabled(ProjectPath.FromApplicationDataPath(
                        ApplicationDataPath.Get()));
                }

                if (CollabPlugin.IsEnabled())
                {
                    // execute Close() once after all inspectors update
                    // to avoid our window to be drawn in back color
                    EditorApplication.delayCall = Close;
                    return;
                }

                bool clientNeedsConfiguration = UnityConfigurationChecker.NeedsConfiguration() || ShowWelcomeViewForTesting;

                WelcomeView welcomeView = GetWelcomeView();

                if (clientNeedsConfiguration && welcomeView.autoLoginState == AutoLogin.State.Off)
                {
                    welcomeView.autoLoginState = AutoLogin.State.Started;
                }

                if (welcomeView.autoLoginState == AutoLogin.State.OrganizationChoosed)
                {
                    OnEnable();
                    welcomeView.autoLoginState = AutoLogin.State.InitializingPlastic;
                }

                if (NeedsToDisplayWelcomeView(clientNeedsConfiguration, mWkInfo))
                {
                    welcomeView.OnGUI(clientNeedsConfiguration);
                    return;
                }

                //TODO: Codice - beta: hide the switcher until the update dialog is implemented
                //DrawGuiModeSwitcher.ForMode(
                //    isGluonMode, plasticClient, changesTreeView, editorWindow);

                DoTabToolbar(
                    mWkInfo,
                    mViewSwitcher,
                    mShowDownloadPlasticExeWindow,
                    mProcessExecutor,
                    mIsGluonMode,
                    mIsCloudOrganization,
                    mIsUGOSubscription);

                mViewSwitcher.TabViewGUI();

                if (mWorkspaceWindow.IsOperationInProgress())
                    DrawProgressForOperations.For(
                        mWorkspaceWindow, mWorkspaceWindow.Progress,
                        position.width);

                mStatusBar.OnGUI(
                    mWkInfo,
                    mWorkspaceWindow,
                    mViewSwitcher,
                    mViewSwitcher,
                    mIncomingChangesNotifier,
                    mIsGluonMode);
            }
            catch (Exception ex)
            {
                if (IsExitGUIException(ex))
                    throw;

                GUI.enabled = true;

                if (IsIMGUIPaintException(ex))
                {
                    ExceptionsHandler.LogException("PlasticWindow", ex);
                    return;
                }

                mException = ex;

                DoExceptionErrorArea();

                ExceptionsHandler.HandleException("OnGUI", ex);
            }
        }

        void Update()
        {
            if (mException != null)
                return;

            if (mWkInfo == null)
                return;

            try
            {
                double currentUpdateTime = EditorApplication.timeSinceStartup;
                double elapsedSeconds = currentUpdateTime - mLastUpdateTime;

                mViewSwitcher.Update();
                mWorkspaceWindow.OnParentUpdated(elapsedSeconds);

                if (mWelcomeView != null)
                    mWelcomeView.Update();

                mLastUpdateTime = currentUpdateTime;
            }
            catch (Exception ex)
            {
                mException = ex;

                ExceptionsHandler.HandleException("Update", ex);
            }
        }

        void OnApplicationActivated()
        {
            mLog.Debug("OnApplicationActivated");

            if (mException != null)
                return;

            if (!PlasticPlugin.ConnectionMonitor.IsConnected)
                return;

            Reload.IfWorkspaceConfigChanged(
                PlasticGui.Plastic.API, mWkInfo, mIsGluonMode,
                ExecuteFullReload);

            if (mWkInfo == null)
                return;

            NewIncomingChanges.LaunchUpdater(
                mDeveloperNewIncomingChangesUpdater,
                mGluonNewIncomingChangesUpdater);

            if (!PlasticApp.HasRunningOperation())
                mCooldownAutoRefreshChangesAction.Ping();

            ((IWorkspaceWindow)mWorkspaceWindow).UpdateTitle();
        }

        void OnApplicationDeactivated()
        {
            mLog.Debug("OnApplicationDeactivated");

            if (mException != null)
                return;

            if (mWkInfo == null)
                return;

            if (!PlasticPlugin.ConnectionMonitor.IsConnected)
                return;

            NewIncomingChanges.StopUpdater(
                mDeveloperNewIncomingChangesUpdater,
                mGluonNewIncomingChangesUpdater);
        }

        void ExecuteFullReload()
        {
            mException = null;

            ClosePlastic(this);

            InitializePlastic();
        }

        void InitializeCloudSubscriptionData(WorkspaceInfo wkInfo)
        {
            mIsCloudOrganization = false;
            mIsUGOSubscription = false;

            RepositorySpec repSpec = PlasticGui.Plastic.API.GetRepositorySpec(wkInfo);

            if (repSpec == null)
                return;

            mIsCloudOrganization = PlasticGui.Plastic.API.IsCloud(repSpec.Server);

            if (!mIsCloudOrganization)
                return;

            string organizationName = ServerOrganizationParser.
                GetOrganizationFromServer(repSpec.Server);

            Task.Run(
                () =>
                {
                    string authToken = AuthToken.GetForServer(repSpec.Server);

                    if (string.IsNullOrEmpty(authToken))
                        return null;

                    return WebRestApiClient.PlasticScm.GetSubscriptionDetails(
                        organizationName, authToken);
                }).ContinueWith(
                t =>
                {
                    if (t.Result == null)
                    {
                        mLog.DebugFormat(
                            "Error getting Subscription details for organization {0}",
                            organizationName);
                        return;
                    }

                    mIsUGOSubscription = t.Result.OrderSource == UGO_ORDER_SOURCE;
                });
        }

        void DoNotConnectedArea()
        {
            string labelText = PlasticLocalization.GetString(
                PlasticLocalization.Name.NotConnectedTryingToReconnect);

            string buttonText = PlasticLocalization.GetString(
                PlasticLocalization.Name.TryNowButton);

            GUI.enabled = !PlasticPlugin.ConnectionMonitor.IsTryingReconnection;

            DrawActionHelpBox.For(
                Images.GetInfoDialogIcon(), labelText, buttonText,
                PlasticPlugin.ConnectionMonitor.CheckConnection);

            GUI.enabled = true;
        }

        void DoExceptionErrorArea()
        {
            string labelText = PlasticLocalization.GetString(
                PlasticLocalization.Name.UnexpectedError);

            string buttonText = PlasticLocalization.GetString(
                PlasticLocalization.Name.ReloadButton);

            DrawActionHelpBox.For(
                Images.GetErrorDialogIcon(), labelText, buttonText,
                ExecuteFullReload);
        }

        void InitializeNewIncomingChanges(
            WorkspaceInfo wkInfo,
            bool bIsGluonMode,
            ViewSwitcher viewSwitcher)
        {
            if (bIsGluonMode)
            {
                Gluon.IncomingChangesNotifier gluonNotifier =
                    new Gluon.IncomingChangesNotifier(this);
                mGluonNewIncomingChangesUpdater =
                    NewIncomingChanges.BuildUpdaterForGluon(
                        wkInfo, viewSwitcher, gluonNotifier, this, gluonNotifier,
                        new GluonCheckIncomingChanges.CalculateIncomingChanges());
                mIncomingChangesNotifier = gluonNotifier;
                return;
            }

            Developer.IncomingChangesNotifier developerNotifier =
                new Developer.IncomingChangesNotifier(this);
            mDeveloperNewIncomingChangesUpdater =
                NewIncomingChanges.BuildUpdaterForDeveloper(
                    wkInfo, viewSwitcher, developerNotifier,
                    this, developerNotifier);
            mIncomingChangesNotifier = developerNotifier;
        }

        void InitializeNotificationBarUpdater(
            WorkspaceInfo wkInfo,
            INotificationBar notificationBar)
        {
            mNotificationBarUpdater = new NotificationBarUpdater(
                notificationBar,
                PlasticGui.Plastic.WebRestAPI,
                new UnityPlasticTimerBuilder(),
                new NotificationBarUpdater.NotificationBarConfig());
            mNotificationBarUpdater.Start();
            mNotificationBarUpdater.SetWorkspace(wkInfo);
        }

        static void DoTabToolbar(
            WorkspaceInfo workspaceInfo,
            ViewSwitcher viewSwitcher,
            LaunchTool.IShowDownloadPlasticExeWindow showDownloadPlasticExeWindow,
            LaunchTool.IProcessExecutor processExecutor,
            bool isGluonMode,
            bool isCloudOrganization,
            bool isUGOSubscription)
        {
            EditorGUILayout.BeginHorizontal(EditorStyles.toolbar);

            viewSwitcher.TabButtonsGUI();

            GUILayout.FlexibleSpace();

            DoSearchField(viewSwitcher);

            DoToolbarButtons(
                workspaceInfo,
                viewSwitcher,
                showDownloadPlasticExeWindow,
                processExecutor,
                isGluonMode,
                isCloudOrganization,
                isUGOSubscription);

            EditorGUILayout.EndHorizontal();
        }

        static void DoSearchField(ViewSwitcher viewSwitcher)
        {
            if (viewSwitcher.IsViewSelected(ViewSwitcher.SelectedTab.PendingChanges))
            {
                viewSwitcher.PendingChangesTab.DrawSearchFieldForPendingChangesTab();
                return;
            }

            if (viewSwitcher.IsViewSelected(ViewSwitcher.SelectedTab.Changesets))
            {
                viewSwitcher.ChangesetsTab.DrawSearchFieldForChangesetsTab();
                return;
            }

            if (viewSwitcher.IsViewSelected(ViewSwitcher.SelectedTab.History))
            {
                viewSwitcher.HistoryTab.DrawSearchFieldForHistoryTab();
                return;
            }

            if (viewSwitcher.IsViewSelected(ViewSwitcher.SelectedTab.Branches))
            {
                viewSwitcher.BranchesTab.DrawSearchFieldForBranchesTab();
                return;
            }

            if (viewSwitcher.IsViewSelected(ViewSwitcher.SelectedTab.Locks))
            {
                viewSwitcher.LocksTab.DrawSearchFieldForLocksTab();
                return;
            }
        }

        static void DoToolbarButtons(
            WorkspaceInfo wkInfo,
            ViewSwitcher viewSwitcher,
            LaunchTool.IShowDownloadPlasticExeWindow showDownloadPlasticExeWindow,
            LaunchTool.IProcessExecutor processExecutor,
            bool isGluonMode,
            bool isCloudOrganization,
            bool isUGOSubscription)
        {
            //TODO: Codice - beta: hide the diff button until the behavior is implemented
            /*GUILayout.Button(PlasticLocalization.GetString(
                PlasticLocalization.Name.DiffWindowMenuItemDiff),
                EditorStyles.toolbarButton,
                GUILayout.Width(UnityConstants.REGULAR_BUTTON_WIDTH));*/

            if (viewSwitcher.IsViewSelected(ViewSwitcher.SelectedTab.Changesets))
            {
                viewSwitcher.ChangesetsTab.DrawDateFilter();
            }

            if (viewSwitcher.IsViewSelected(ViewSwitcher.SelectedTab.Branches))
            {
                viewSwitcher.BranchesTab.DrawDateFilter();
            }

            Texture refreshIcon = Images.GetRefreshIcon();
            string refreshIconTooltip = PlasticLocalization.GetString(
                PlasticLocalization.Name.RefreshButton);

            if (DrawToolbarButton(refreshIcon, refreshIconTooltip))
            {
                viewSwitcher.RefreshSelectedView();
            }

            if (viewSwitcher.IsViewSelected(ViewSwitcher.SelectedTab.PendingChanges))
            {
                Texture2D icon = Images.GetUndoIcon();
                string tooltip = PlasticLocalization.GetString(
                    PlasticLocalization.Name.UndoSelectedChanges);

                if (DrawToolbarButton(icon, tooltip))
                {
                    TrackFeatureUseEvent.For(
                        PlasticGui.Plastic.API.GetRepositorySpec(wkInfo),
                        TrackFeatureUseEvent.Features.UndoIconButton);

                    viewSwitcher.PendingChangesTab.UndoForMode(wkInfo, isGluonMode);
                }
            }

            if (isGluonMode)
            {
                string label = PlasticLocalization.GetString(PlasticLocalization.Name.ConfigureGluon);
                if (DrawActionButton.For(label))
                    LaunchTool.OpenWorkspaceConfiguration(
                        showDownloadPlasticExeWindow,
                        processExecutor,
                        wkInfo,
                        isGluonMode);
            }
            else
            {
                Texture2D icon = Images.GetBranchIcon();
                string tooltip = PlasticLocalization.GetString(PlasticLocalization.Name.Branches);
                if (DrawToolbarButton(icon, tooltip))
                {
                    ShowBranchesContextMenu(
                        wkInfo,
                        viewSwitcher,
                        showDownloadPlasticExeWindow,
                        processExecutor,
                        isGluonMode);
                }
            }

            if (DrawToolbarButton(Images.GetLockIcon(), PlasticLocalization.Name.ShowLocks.GetString()))
            {
                OpenLocksViewAndSendEvent(wkInfo, viewSwitcher);
            }

            if (isCloudOrganization)
            {
                if (DrawToolbarButton(
                    Images.GetInviteUsersIcon(),
                    PlasticLocalization.Name.InviteMembers.GetString()))
                {
                    InviteMembersToOrganization(wkInfo);
                }

                if (isUGOSubscription)
                {
                    if (DrawToolbarTextButton(PlasticLocalization.Name.UpgradePlan.GetString()))
                    {
                        OpenDevOpsUpgradePlanUrl();
                    }
                }
            }

            //TODO: Add settings button tooltip localization
            if (DrawToolbarButton(Images.GetSettingsIcon(), string.Empty))
            {
                ShowSettingsContextMenu(
                    showDownloadPlasticExeWindow,
                    processExecutor,
                    wkInfo,
                    isGluonMode);
            }
        }

        static bool DrawToolbarButton(Texture icon, string tooltip)
        {
            return GUILayout.Button(
                new GUIContent(icon, tooltip),
                EditorStyles.toolbarButton,
                GUILayout.Width(26));
        }

        static bool DrawToolbarTextButton(string text)
        {
            return GUILayout.Button(
                new GUIContent(text, string.Empty),
                EditorStyles.toolbarButton);
        }

        static void InviteMembersToOrganization(WorkspaceInfo wkInfo)
        {
            RepositorySpec repSpec = PlasticGui.Plastic.API.GetRepositorySpec(wkInfo);

            string organizationName = ServerOrganizationParser.
                GetOrganizationFromServer(repSpec.Server);

            CurrentUserAdminCheckResponse response = null;

            IThreadWaiter waiter = ThreadWaiter.GetWaiter(50);
            waiter.Execute(
                /*threadOperationDelegate*/
                delegate
                {
                    string authToken = AuthToken.GetForServer(repSpec.Server);

                    if (string.IsNullOrEmpty(authToken))
                    {
                        return;
                    }

                    response = WebRestApiClient.PlasticScm.IsUserAdmin(
                        organizationName,
                        authToken);
                },
                /*afterOperationDelegate*/
                delegate
                {
                    if (waiter.Exception != null)
                    {
                        ExceptionsHandler.LogException(
                            "IsUserAdmin",
                            waiter.Exception);

                        OpenUnityDashboardInviteUsersUrl(organizationName);
                        return;
                    }

                    if (response == null)
                    {
                        mLog.DebugFormat(
                            "Error checking if the user is the organization admin for {0}",
                            organizationName);

                        OpenUnityDashboardInviteUsersUrl(organizationName);
                        return;
                    }

                    if (response.Error != null)
                    {
                        mLog.DebugFormat(
                          "Error checking if the user is the organization admin: {0}",
                          string.Format("Unable to get IsUserAdminResponse: {0} [code {1}]",
                              response.Error.Message,
                              response.Error.ErrorCode));

                        OpenUnityDashboardInviteUsersUrl(organizationName);
                        return;
                    }

                    if (response.IsCurrentUserAdmin)
                    {
                        OpenUnityDashboardInviteUsersUrl(response.OrganizationName);
                        return;
                    }

                    GuiMessage.ShowInformation(
                        PlasticLocalization.GetString(PlasticLocalization.Name.InviteMembersTitle),
                        PlasticLocalization.GetString(PlasticLocalization.Name.InviteMembersMessage));
                });
        }

        static void OpenBranchListViewAndSendEvent(
            WorkspaceInfo wkInfo,
            ViewSwitcher viewSwitcher)
        {
            viewSwitcher.ShowBranchesView();

            TrackFeatureUseEvent.For(
               PlasticGui.Plastic.API.GetRepositorySpec(wkInfo),
               TrackFeatureUseEvent.Features.OpenBranchesView);
        }

        static void OpenLocksViewAndSendEvent(
            WorkspaceInfo wkInfo,
            ViewSwitcher viewSwitcher)
        {
            viewSwitcher.ShowLocksView();

            TrackFeatureUseEvent.For(
                PlasticGui.Plastic.API.GetRepositorySpec(wkInfo),
                TrackFeatureUseEvent.Features.OpenLocksView);
        }

        static void ShowBranchesContextMenu(
            WorkspaceInfo wkInfo,
            ViewSwitcher viewSwitcher,
            LaunchTool.IShowDownloadPlasticExeWindow showDownloadPlasticExeWindow,
            LaunchTool.IProcessExecutor processExecutor,
            bool isGluonMode)
        {
            GenericMenu menu = new GenericMenu();

            string branchesListView = PlasticLocalization.GetString(
                PlasticLocalization.Name.Branches);

            menu.AddItem(
               new GUIContent(branchesListView),
               false,
               () => OpenBranchListViewAndSendEvent(wkInfo, viewSwitcher));

            string branchExplorer = PlasticLocalization.GetString(
                PlasticLocalization.Name.BranchExplorerMenu);

            menu.AddItem(
              new GUIContent(branchExplorer),
              false,
              () => LaunchTool.OpenBranchExplorer(
                showDownloadPlasticExeWindow,
                processExecutor,
                wkInfo,
                isGluonMode));

            menu.ShowAsContext();
        }

        static void ShowSettingsContextMenu(
            LaunchTool.IShowDownloadPlasticExeWindow showDownloadPlasticExeWindow,
            LaunchTool.IProcessExecutor processExecutor,
            WorkspaceInfo wkInfo,
            bool isGluonMode)
        {
            GenericMenu menu = new GenericMenu();

            string openToolText = isGluonMode ?
                PlasticLocalization.Name.OpenInGluon.GetString() :
                PlasticLocalization.Name.OpenInDesktopApp.GetString();

            menu.AddItem(
                new GUIContent(openToolText),
                false,
                () => LaunchTool.OpenGUIForMode(
                    showDownloadPlasticExeWindow,
                    processExecutor,
                    wkInfo,
                    isGluonMode));

            menu.AddSeparator(string.Empty);

            menu.AddItem(
                new GUIContent(PlasticLocalization.Name.Options.GetString()),
                false,
                () => SettingsService.OpenProjectSettings(UnityConstants.PROJECT_SETTINGS_TAB_PATH));

            menu.AddItem(
                new GUIContent(PlasticAssetModificationProcessor.ForceCheckout ?
                    PlasticLocalization.Name.DisableForcedCheckout.GetString() :
                    PlasticLocalization.Name.EnableForcedCheckout.GetString()),
                false,
                () => PlasticAssetModificationProcessor.SetForceCheckoutOption(
                    !PlasticAssetModificationProcessor.ForceCheckout));

            menu.ShowAsContext();
        }

        static void OpenUnityDashboardInviteUsersUrl(string organization)
        {
            Application.OpenURL(UnityUrl.UnityDashboard.Plastic.GetForInviteUsers(
                organization, UnityUrl.UnityDashboard.UnityCloudRequestSource.Editor));
        }

        static void OpenDevOpsUpgradePlanUrl()
        {
            Application.OpenURL(UnityUrl.DevOps.GetSignUp());
        }

        static void DisableVCSIfEnabled(string projectPath)
        {
            if (!VCSPlugin.IsEnabled())
                return;

            VCSPlugin.Disable();

            mLog.DebugFormat("Disabled VCS Plugin on Project: {0}",
                projectPath);
        }

        static void DisableCollabIfEnabled(string projectPath)
        {
            if (!CollabPlugin.IsEnabled())
                return;

            CollabPlugin.Disable();

            mLog.DebugFormat("Disabled Collab Plugin on Project: {0}",
                projectPath);
        }

        static void DisposeNewIncomingChanges(PlasticWindow window)
        {
            NewIncomingChanges.DisposeUpdater(
                window.mDeveloperNewIncomingChangesUpdater,
                window.mGluonNewIncomingChangesUpdater);

            window.mDeveloperNewIncomingChangesUpdater = null;
            window.mGluonNewIncomingChangesUpdater = null;
        }

        static void DisposeNotificationBarUpdater(PlasticWindow window)
        {
            if (window.mNotificationBarUpdater == null)
                return;

            window.mNotificationBarUpdater.Dispose();
            window.mNotificationBarUpdater = null;
        }

        static void RegisterApplicationFocusHandlers(PlasticWindow window)
        {
            EditorWindowFocus.OnApplicationActivated += window.OnApplicationActivated;
            EditorWindowFocus.OnApplicationDeactivated += window.OnApplicationDeactivated;
        }

        static void UnRegisterApplicationFocusHandlers(PlasticWindow window)
        {
            EditorWindowFocus.OnApplicationActivated -= window.OnApplicationActivated;
            EditorWindowFocus.OnApplicationDeactivated -= window.OnApplicationDeactivated;
        }

        static void InitializePlasticOnForceToReOpen(PlasticWindow window)
        {
            if (window.mWkInfo == null)
                return;

            window.mViewSwitcher.OnEnable();

            window.InitializeNewIncomingChanges(
                window.mWkInfo,
                window.mIsGluonMode,
                window.mViewSwitcher);

            PlasticApp.RegisterWorkspaceWindow(
                window.mWorkspaceWindow);

            if (PlasticPlugin.WorkspaceOperationsMonitor != null)
            {
                PlasticPlugin.WorkspaceOperationsMonitor.RegisterWindow(
                    window.mWorkspaceWindow,
                    window.mViewHost,
                    window.mDeveloperNewIncomingChangesUpdater);
            }

            if (!EditionToken.IsCloudEdition())
                return;

            window.InitializeNotificationBarUpdater(
                window.mWkInfo,
                window.mStatusBar.NotificationBar);
        }

        static void ClosePlastic(PlasticWindow window)
        {
            if (window.mViewSwitcher != null)
                window.mViewSwitcher.OnDisable();

            PlasticApp.UnRegisterWorkspaceWindow();

            if (PlasticPlugin.WorkspaceOperationsMonitor != null)
                PlasticPlugin.WorkspaceOperationsMonitor.UnRegisterWindow();

            DisposeNewIncomingChanges(window);

            DisposeNotificationBarUpdater(window);

            AvatarImages.Dispose();
        }

        static void ReOpenPlasticWindow(PlasticWindow closedWindow)
        {
            EditorWindow dockWindow = FindEditorWindow.ToDock<PlasticWindow>();

            PlasticWindow newWindow = InstantiateFrom(closedWindow);

            InitializePlasticOnForceToReOpen(newWindow);

            if (DockEditorWindow.IsAvailable())
                DockEditorWindow.To(dockWindow, newWindow);

            newWindow.Show();
            newWindow.Focus();
        }

        static bool NeedsToDisplayWelcomeView(
            bool clientNeedsConfiguration,
            WorkspaceInfo wkInfo)
        {
            if (clientNeedsConfiguration)
                return true;

            if (wkInfo == null)
                return true;

            return false;
        }

        static bool IsExitGUIException(Exception ex)
        {
            return ex is ExitGUIException;
        }

        static bool IsIMGUIPaintException(Exception ex)
        {
            if (!(ex is ArgumentException))
                return false;

            return ex.Message.StartsWith("Getting control") &&
                   ex.Message.Contains("controls when doing repaint");
        }

        static PlasticWindow InstantiateFrom(PlasticWindow window)
        {
            PlasticWindow result = Instantiate(window);
            result.mIsGluonMode = window.mIsGluonMode;
            result.mIsCloudOrganization = window.mIsCloudOrganization;
            result.mIsUGOSubscription = window.mIsUGOSubscription;
            result.mDisableCollabIfEnabledWhenLoaded = window.mDisableCollabIfEnabledWhenLoaded;
            result.mLastUpdateTime = window.mLastUpdateTime;
            result.mWkInfo = window.mWkInfo;
            result.mException = window.mException;
            result.mWelcomeView = window.mWelcomeView;
            result.mViewSwitcher = window.mViewSwitcher;
            result.mViewHost = window.mViewHost;
            result.mWorkspaceWindow = window.mWorkspaceWindow;
            result.mStatusBar = window.mStatusBar;
            result.mNotificationBarUpdater = window.mNotificationBarUpdater;
            result.mCooldownAutoRefreshChangesAction = window.mCooldownAutoRefreshChangesAction;
            result.mDeveloperNewIncomingChangesUpdater = window.mDeveloperNewIncomingChangesUpdater;
            result.mGluonNewIncomingChangesUpdater = window.mGluonNewIncomingChangesUpdater;
            result.mIncomingChangesNotifier = window.mIncomingChangesNotifier;
            return result;
        }

        static class Reload
        {
            internal static void IfWorkspaceConfigChanged(
                IPlasticAPI plasticApi,
                WorkspaceInfo lastWkInfo,
                bool lastIsGluonMode,
                Action reloadAction)
            {
                string applicationPath = ApplicationDataPath.Get();

                bool isGluonMode = false;
                WorkspaceInfo wkInfo = null;

                IThreadWaiter waiter = ThreadWaiter.GetWaiter(10);
                waiter.Execute(
                    /*threadOperationDelegate*/ delegate
                    {
                        wkInfo = FindWorkspace.
                            InfoForApplicationPath(applicationPath, plasticApi);

                        if (wkInfo != null)
                            isGluonMode = plasticApi.IsGluonWorkspace(wkInfo);
                    },
                    /*afterOperationDelegate*/ delegate
                    {
                        if (waiter.Exception != null)
                            return;

                        if (!IsWorkspaceConfigChanged(
                                lastWkInfo, wkInfo,
                                lastIsGluonMode, isGluonMode))
                            return;

                        reloadAction();
                    });
            }

            static bool IsWorkspaceConfigChanged(
                WorkspaceInfo lastWkInfo,
                WorkspaceInfo currentWkInfo,
                bool lastIsGluonMode,
                bool currentIsGluonMode)
            {
                if (lastIsGluonMode != currentIsGluonMode)
                    return true;

                if (lastWkInfo == null)
                    return currentWkInfo != null;

                return !lastWkInfo.Equals(currentWkInfo);
            }
        }

        [SerializeField]
        bool mForceToReOpen;

        bool mIsGluonMode;
        bool mIsCloudOrganization;
        bool mIsUGOSubscription;

        [NonSerialized]
        WorkspaceInfo mWkInfo;
        double mLastUpdateTime = 0f;

        Exception mException;
        bool mDisableCollabIfEnabledWhenLoaded;
        WelcomeView mWelcomeView;
        ViewHost mViewHost;
        WorkspaceWindow mWorkspaceWindow;
        StatusBar mStatusBar;
        CooldownWindowDelayer mCooldownAutoRefreshChangesAction;
        IIncomingChangesNotifier mIncomingChangesNotifier;
        ViewSwitcher mViewSwitcher;
        NotificationBarUpdater mNotificationBarUpdater;
        NewIncomingChangesUpdater mDeveloperNewIncomingChangesUpdater;
        GluonNewIncomingChangesUpdater mGluonNewIncomingChangesUpdater;

        LaunchTool.IShowDownloadPlasticExeWindow mShowDownloadPlasticExeWindow =
            new LaunchTool.ShowDownloadPlasticExeWindow();
        LaunchTool.IProcessExecutor mProcessExecutor =
            new LaunchTool.ProcessExecutor();

        const string UGO_ORDER_SOURCE = "UGO";

        static readonly ILog mLog = PlasticApp.GetLogger("PlasticWindow");
    }
}
