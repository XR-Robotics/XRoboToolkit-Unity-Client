using System;
using System.IO;
using System.Linq;

using UnityEditor;
using UnityEngine;

using Codice.Client.BaseCommands;
using Codice.Client.Common;
using Codice.Client.Common.Connection;
using Codice.Client.Common.Encryption;
using Codice.Client.Common.EventTracking;
using Codice.Client.Common.FsNodeReaders;
using Codice.Client.Common.FsNodeReaders.Watcher;
using Codice.Client.Common.Threading;
using Codice.CM.Common;
using Codice.CM.ConfigureHelper;
using Codice.CM.WorkspaceServer;
using Codice.LogWrapper;
using Codice.Utils;
using CodiceApp.EventTracking;
using MacUI;
using PlasticGui;
using PlasticGui.EventTracking;
using PlasticGui.WebApi;
using PlasticPipe.Certificates;
using Unity.PlasticSCM.Editor.Configuration;
using Unity.PlasticSCM.Editor.Tool;
using Unity.PlasticSCM.Editor.UI;

namespace Unity.PlasticSCM.Editor
{
    internal static class PlasticApp
    {
        static PlasticApp()
        {
            ConfigureLogging();

            RegisterDomainUnloadHandler();

            mLog = GetLogger("PlasticApp");
        }

        internal static ILog GetLogger(string name)
        {
            return LogManager.GetLogger(name);
        }

        internal static bool HasRunningOperation()
        {
            if (mWorkspaceWindow != null &&
                mWorkspaceWindow.IsOperationInProgress())
                return true;

            if (mWkInfo == null)
                return false;

            return TransactionManager.Get().ExistsAnyWorkspaceTransaction(mWkInfo);
        }

        internal static void InitializeIfNeeded()
        {
            if (mIsInitialized)
                return;

            mIsInitialized = true;

            mLog.Debug("InitializeIfNeeded");
            
            // Ensures that the Edition Token is initialized from the UVCS installation regardless of if the PlasticWindow is opened
            UnityConfigurationChecker.SynchronizeUnityEditionToken();
            PlasticInstallPath.LogInstallationInfo();

            if (!PlasticPlugin.IsUnitTesting)
                GuiMessage.Initialize(new UnityPlasticGuiMessage());

            RegisterExceptionHandlers();
            RegisterBeforeAssemblyReloadHandler();
            RegisterEditorWantsToQuit();
            RegisterEditorQuitting();

            InitLocalization();

            if (!PlasticPlugin.IsUnitTesting)
                ThreadWaiter.Initialize(new UnityThreadWaiterBuilder());

            ServicePointConfigurator.ConfigureServicePoint();
            CertificateUi.RegisterHandler(new ChannelCertificateUiImpl());

            SetupFsWatcher();

            // The plastic library holds an internal cache of slugs that relies on the file unityorgs.conf.
            // This file might contain outdated information or not exist at all, so we need to ensure
            // the cloud organizations are loaded and populated to the internal cache during the initialization.
            if (!PlasticPlugin.IsUnitTesting)
                SetupCloudOrganizations();

            EditionManager.Get().DisableCapability(EnumEditionCapabilities.Extensions);

            ClientHandlers.Register();

            PlasticGuiConfig.SetConfigFile(PlasticGuiConfig.UNITY_GUI_CONFIG_FILE);

            if (!PlasticPlugin.IsUnitTesting)
            {
                mEventSenderScheduler = EventTracking.Configure(
                    (PlasticWebRestApi)PlasticGui.Plastic.WebRestAPI,
                    ApplicationIdentifier.UnityPackage,
                    IdentifyEventPlatform.Get());
            }

            if (mEventSenderScheduler != null)
            {
                UVCPackageVersion.AsyncGetVersion();

                mPingEventLoop = new PingEventLoop(
                    BuildGetEventExtraInfoFunction.ForPingEvent());
                mPingEventLoop.Start();
            }

            PlasticMethodExceptionHandling.InitializeAskCredentialsUi(
                new CredentialsUiImpl());
            ClientEncryptionServiceProvider.SetEncryptionPasswordProvider(
                new MissingEncryptionPasswordPromptHandler());
        }

        internal static void SetWorkspace(WorkspaceInfo wkInfo)
        {
            mWkInfo = wkInfo;

            RegisterApplicationFocusHandlers();

            if (mEventSenderScheduler == null)
                return;

            mPingEventLoop.SetWorkspace(mWkInfo);
            PlasticGui.Plastic.WebRestAPI.SetToken(
                CmConnection.Get().BuildWebApiTokenForCloudEditionDefaultUser());
        }

        internal static void RegisterWorkspaceWindow(IWorkspaceWindow workspaceWindow)
        {
            mWorkspaceWindow = workspaceWindow;
        }

        internal static void UnRegisterWorkspaceWindow()
        {
            mWorkspaceWindow = null;
        }

        internal static void EnableMonoFsWatcherIfNeeded()
        {
            if (PlatformIdentifier.IsMac())
                return;

            MonoFileSystemWatcher.IsEnabled = true;
        }

        internal static void DisableMonoFsWatcherIfNeeded()
        {
            if (PlatformIdentifier.IsMac())
                return;

            MonoFileSystemWatcher.IsEnabled = false;
        }

        internal static void Dispose()
        {
            if (!mIsInitialized)
                return;

            try
            {
                mLog.Debug("Dispose");

                UnRegisterExceptionHandlers();
                UnRegisterApplicationFocusHandlers();
                UnRegisterEditorWantsToQuit();
                UnRegisterEditorQuitting();

                if (mEventSenderScheduler != null)
                {
                    mPingEventLoop.Stop();
                    // Launching and forgetting to avoid a timeout when sending events files and no
                    // network connection is available.
                    // This will be refactored once a better mechanism to send event is in place
                    mEventSenderScheduler.EndAndSendEventsAsync();
                }

                if (mWkInfo == null)
                    return;

                WorkspaceFsNodeReaderCachesCleaner.CleanWorkspaceFsNodeReader(mWkInfo);
            }
            finally
            {
                mIsInitialized = false;
            }
        }

        static void RegisterDomainUnloadHandler()
        {
            AppDomain.CurrentDomain.DomainUnload += AppDomainUnload;
        }

        static void RegisterEditorWantsToQuit()
        {
            EditorApplication.wantsToQuit += OnEditorWantsToQuit;
        }

        static void RegisterEditorQuitting()
        {
            EditorApplication.quitting += OnEditorQuitting;
        }

        static void RegisterBeforeAssemblyReloadHandler()
        {
            AssemblyReloadEvents.beforeAssemblyReload += BeforeAssemblyReload;
        }

        static void RegisterApplicationFocusHandlers()
        {
            EditorWindowFocus.OnApplicationActivated += OnApplicationActivated;

            EditorWindowFocus.OnApplicationDeactivated += OnApplicationDeactivated;
        }

        static void RegisterExceptionHandlers()
        {
            AppDomain.CurrentDomain.UnhandledException += HandleUnhandledException;

            Application.logMessageReceivedThreaded += HandleLog;
        }

        static void UnRegisterDomainUnloadHandler()
        {
            AppDomain.CurrentDomain.DomainUnload -= AppDomainUnload;
        }

        static void UnRegisterEditorWantsToQuit()
        {
            EditorApplication.wantsToQuit -= OnEditorWantsToQuit;
        }

        static void UnRegisterEditorQuitting()
        {
            EditorApplication.quitting -= OnEditorQuitting;
        }

        static void UnRegisterBeforeAssemblyReloadHandler()
        {
            AssemblyReloadEvents.beforeAssemblyReload -= BeforeAssemblyReload;
        }

        static void UnRegisterApplicationFocusHandlers()
        {
            EditorWindowFocus.OnApplicationActivated -= OnApplicationActivated;

            EditorWindowFocus.OnApplicationDeactivated -= OnApplicationDeactivated;
        }

        static void UnRegisterExceptionHandlers()
        {
            AppDomain.CurrentDomain.UnhandledException -= HandleUnhandledException;

            Application.logMessageReceivedThreaded -= HandleLog;
        }

        static void AppDomainUnload(object sender, EventArgs e)
        {
            mLog.Debug("AppDomainUnload");

            UnRegisterDomainUnloadHandler();
        }

        static void HandleUnhandledException(object sender, UnhandledExceptionEventArgs args)
        {
            Exception ex = (Exception)args.ExceptionObject;

            if (IsExitGUIException(ex) ||
                !IsPlasticStackTrace(ex.StackTrace))
                throw ex;

            GUIActionRunner.RunGUIAction(delegate {
                ExceptionsHandler.HandleException("HandleUnhandledException", ex);
            });
        }

        static void HandleLog(string logString, string stackTrace, LogType type)
        {
            if (type != LogType.Exception)
                return;

            if (!IsPlasticStackTrace(stackTrace))
                return;

            GUIActionRunner.RunGUIAction(delegate {
                mLog.ErrorFormat("[HandleLog] Unexpected error: {0}", logString);
                mLog.DebugFormat("Stack trace: {0}", stackTrace);

                string message = logString;
                if (ExceptionsHandler.DumpStackTrace())
                    message += Environment.NewLine + stackTrace;

                GuiMessage.ShowError(message);
            });
        }

        static void OnApplicationActivated()
        {
            mLog.Debug("OnApplicationActivated");

            EnableMonoFsWatcherIfNeeded();
        }

        static void OnApplicationDeactivated()
        {
            mLog.Debug("OnApplicationDeactivated");

            DisableMonoFsWatcherIfNeeded();
        }

        static void OnEditorQuitting()
        {
            mLog.Debug("OnEditorQuitting");

            PlasticPlugin.Shutdown();
        }

        static bool OnEditorWantsToQuit()
        {
            mLog.Debug("OnEditorWantsToQuit");

            if (!HasRunningOperation())
                return true;

            return GuiMessage.ShowQuestion(
                PlasticLocalization.GetString(PlasticLocalization.Name.OperationRunning),
                PlasticLocalization.GetString(PlasticLocalization.Name.ConfirmClosingRunningOperation),
                PlasticLocalization.GetString(PlasticLocalization.Name.YesButton));
        }

        static void BeforeAssemblyReload()
        {
            mLog.Debug("BeforeAssemblyReload");

            UnRegisterBeforeAssemblyReloadHandler();

            PlasticShutdown.Shutdown();
        }

        static void InitLocalization()
        {
            string language = null;
            try
            {
                language = ClientConfig.Get().GetLanguage();
            }
            catch
            {
                language = string.Empty;
            }

            Localization.Init(language);
            PlasticLocalization.SetLanguage(language);
        }

        static void SetupFsWatcher()
        {
            if (!PlatformIdentifier.IsMac())
                return;

            WorkspaceWatcherFsNodeReadersCache.Get().SetMacFsWatcherBuilder(
                new MacFsWatcherBuilder());
        }

        static void SetupCloudOrganizations()
        {
            if (!EditionToken.IsCloudEdition())
            {
                return;
            }

            OrganizationsInformation.LoadCloudOrganizationsAsync();
        }

        static bool IsPlasticStackTrace(string stackTrace)
        {
            if (stackTrace == null)
                return false;

            string[] namespaces = new[] {
                "Codice.",
                "GluonGui.",
                "PlasticGui."
            };

            return namespaces.Any(stackTrace.Contains);
        }

        static bool IsExitGUIException(Exception ex)
        {
            return ex is ExitGUIException;
        }

        static void ConfigureLogging()
        {
            try
            {
                string log4netpath = ToolConfig.GetUnityPlasticLogConfigFile();

                if (!File.Exists(log4netpath))
                    WriteLogConfiguration.For(log4netpath);

                XmlConfigurator.Configure(new FileInfo(log4netpath));
            }
            catch
            {
                //it failed configuring the logging info; nothing to do.
            }
        }

        static bool mIsInitialized;
        static IWorkspaceWindow mWorkspaceWindow;
        static WorkspaceInfo mWkInfo;
        static EventSenderScheduler mEventSenderScheduler;
        static PingEventLoop mPingEventLoop;
        static ILog mLog;
    }
}