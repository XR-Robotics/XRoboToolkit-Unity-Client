using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Threading;

using Codice;
using Codice.Client.BaseCommands;
using Codice.Client.Commands;
using Codice.Client.Commands.WkTree;
using Codice.LogWrapper;
using Codice.Utils;
using GluonGui;
using PlasticGui;
using PlasticGui.WorkspaceWindow;
using Unity.PlasticSCM.Editor.UI;
using Unity.PlasticSCM.Editor.Views.IncomingChanges;
using Unity.PlasticSCM.Editor.Views.PendingChanges;

namespace Unity.PlasticSCM.Editor.AssetUtils.Processor
{
    internal class WorkspaceOperationsMonitor
    {
        public interface IDisableAssetsProcessor
        {
            void Disable();
        }

        internal WorkspaceOperationsMonitor(
            IPlasticAPI plasticApi,
            IDisableAssetsProcessor disableAssetsProcessor,
            bool isGluonMode)
        {
            mPlasticAPI = plasticApi;
            mDisableAssetsProcessor = disableAssetsProcessor;
            mIsGluonMode = isGluonMode;
        }

        internal void RegisterWindow(
            IWorkspaceWindow workspaceWindow,
            ViewHost viewHost,
            NewIncomingChangesUpdater incomingChangesUpdater)
        {
            mWorkspaceWindow = workspaceWindow;
            mViewHost = viewHost;
            mNewIncomingChangesUpdater = incomingChangesUpdater;
        }

        internal void UnRegisterWindow()
        {
            mWorkspaceWindow = null;
            mViewHost = null;
            mNewIncomingChangesUpdater = null;
        }

        internal void RegisterPendingChangesView(
            PendingChangesTab pendingChangesTab)
        {
            mPendingChangesTab = pendingChangesTab;
        }

        internal void RegisterIncomingChangesView(
            IIncomingChangesTab incomingChangesTab)
        {
            mIncomingChangesTab = incomingChangesTab;
        }

        internal void UnRegisterViews()
        {
            mPendingChangesTab = null;
            mIncomingChangesTab = null;
        }

        internal void Start()
        {
            mLog.Debug("Start");

            mCancelToken = new CancelToken();
            mIsEnabled = true;

            Thread thread = new Thread(TaskLoopThread);
            thread.IsBackground = true;
            thread.Name = "Plastic SCM Workspace Operations Monitor thread";
            thread.Start();
        }

        internal void Stop()
        {
            mLog.Debug("Stop");

            SetAsFinished();
        }

        internal void Disable()
        {
            mIsEnabled = false;

            mLog.Debug("Disabled");
        }

        internal void Enable()
        {
            mIsEnabled = true;

            mLog.Debug("Enabled");
        }

        internal void AddAssetsProcessorPathsToAdd(
            List<string> paths)
        {
            AddPathsToProcess(
                mAssetsProcessorPathsToAdd, paths,
                mLock, mResetEvent, mIsEnabled);
        }

        internal void AddAssetsProcessorPathsToDelete(
            List<string> paths)
        {
            AddPathsToProcess(
                mAssetsProcessorPathsToDelete, paths,
                mLock, mResetEvent, mIsEnabled);
        }

        internal void AddAssetsProcessorPathsToCheckout(
            List<string> paths)
        {
            AddPathsToProcess(
                mAssetsProcessorPathsToCheckout, paths,
                mLock, mResetEvent, mIsEnabled);
        }

        internal void AddAssetsProcessorPathsToMove(
            List<AssetPostprocessor.PathToMove> paths)
        {
            AddPathsToMoveToProcess(
                mAssetsProcessorPathsToMove, paths,
                mLock, mResetEvent, mIsEnabled);
        }

        internal void AddPathsToCheckout(
            List<string> paths)
        {
            AddPathsToProcess(
                mPathsToCheckout, paths,
                mLock, mResetEvent, mIsEnabled);
        }

        void TaskLoopThread()
        {
            while (true)
            {
                try
                {
                    if (mCancelToken.IsCancelled())
                        break;

                    if (!mIsEnabled)
                    {
                        SleepUntilNextWorkload();
                        continue;
                    }

                    bool hasAssetProcessorOpsPending = false;
                    bool hasCheckoutOpsPending = false;
                    ProcessOperations(
                        mPlasticAPI,
                        mAssetsProcessorPathsToAdd,
                        mAssetsProcessorPathsToDelete,
                        mAssetsProcessorPathsToCheckout,
                        mAssetsProcessorPathsToMove,
                        mPathsToCheckout,
                        mCancelToken,
                        mLock,
                        mDisableAssetsProcessor,
                        out hasAssetProcessorOpsPending,
                        out hasCheckoutOpsPending);

                    if (mCancelToken.IsCancelled())
                        break;

                    if (hasAssetProcessorOpsPending ||
                        hasCheckoutOpsPending)
                        continue;

                    SleepUntilNextWorkload();
                }
                catch (Exception e)
                {
                    mLog.ErrorFormat(
                        "Error running the tasks loop : {0}", e.Message);
                    mLog.DebugFormat(
                        "Stacktrace: {0}", e.StackTrace);
                }
            }
        }

        void ProcessOperations(
            IPlasticAPI plasticApi,
            List<string> assetsProcessorPathsToAdd,
            List<string> assetsProcessorPathsToDelete,
            List<string> assetsProcessorPathsToCheckout,
            List<AssetPostprocessor.PathToMove> assetsProcessorPathsToMove,
            List<string> pathsToCheckout,
            CancelToken cancelToken,
            object lockObj,
            IDisableAssetsProcessor disableAssetsProcessor,
            out bool hasAssetProcessorOpsPending,
            out bool hasCheckoutOpsPending)
        {
            hasAssetProcessorOpsPending = false;
            hasCheckoutOpsPending = false;

            mLog.Debug("Starting process operations...");

            bool hasAssetProcessorOpsProcessed =
                ProcessAssetProcessorOperations(
                    plasticApi,
                    assetsProcessorPathsToAdd,
                    assetsProcessorPathsToDelete,
                    assetsProcessorPathsToCheckout,
                    assetsProcessorPathsToMove,
                    cancelToken,
                    lockObj,
                    disableAssetsProcessor);

            if (cancelToken.IsCancelled())
                return;

            bool hasCheckoutOpsProcessed =
                ProcessCheckoutOperation(
                    plasticApi,
                    pathsToCheckout,
                    cancelToken,
                    lockObj);

            mLog.Debug("ProcessOperations - Processed paths ? " +
                 (hasAssetProcessorOpsProcessed || hasCheckoutOpsProcessed));

            if (cancelToken.IsCancelled())
                return;

            HasPendingOperationsToProcess(
                assetsProcessorPathsToAdd,
                assetsProcessorPathsToDelete,
                assetsProcessorPathsToCheckout,
                assetsProcessorPathsToMove,
                pathsToCheckout,
                lockObj,
                out hasAssetProcessorOpsPending,
                out hasCheckoutOpsPending);

            bool isAfterAssetProcessorOpNeeded =
                hasAssetProcessorOpsProcessed &&
                !hasAssetProcessorOpsPending;

            bool isAfterCheckoutOpNeeded =
                hasCheckoutOpsProcessed &&
                !hasCheckoutOpsPending;

            if (!isAfterAssetProcessorOpNeeded &&
                !isAfterCheckoutOpNeeded)
                return;

            if (cancelToken.IsCancelled())
                return;

            EditorDispatcher.Dispatch(() =>
            {
                mLog.Debug("AfterProcessOperations");

                RefreshAsset.VersionControlCache();

                if (isAfterAssetProcessorOpNeeded)
                    AfterAssetProcessorOperation();

                if (isAfterCheckoutOpNeeded)
                    AfterCheckoutOperation();
            });
        }

        void AfterAssetProcessorOperation()
        {
            AutoRefresh.PendingChangesView(mPendingChangesTab);

            AutoRefresh.IncomingChangesView(mIncomingChangesTab);

            if (mIsGluonMode)
            {
                RefreshViewsAfterAssetProcessorForGluon(mViewHost);
                return;
            }

            RefreshViewsAfterAssetProcessorForDeveloper(mWorkspaceWindow);
        }

        void AfterCheckoutOperation()
        {
            if (mIsGluonMode)
            {
                RefreshViewsAfterCheckoutForGluon(mViewHost);
                return;
            }

            if (mNewIncomingChangesUpdater != null)
                mNewIncomingChangesUpdater.Update(DateTime.Now);

            RefreshViewsAfterCheckoutForDeveloper(mWorkspaceWindow);
        }

        void SetAsFinished()
        {
            if (mCancelToken.IsCancelled())
                return;

            mCancelToken.Cancel();
            mResetEvent.Set();
        }

        void SleepUntilNextWorkload()
        {
            mLog.Debug("SleepUntilNextWorkload");

            mResetEvent.Reset();
            mResetEvent.WaitOne();
        }

        static bool ProcessAssetProcessorOperations(
            IPlasticAPI plasticApi,
            List<string> assetsProcessorPathsToAdd,
            List<string> assetsProcessorPathsToDelete,
            List<string> assetsProcessorPathsToCheckout,
            List<AssetPostprocessor.PathToMove> assetsProcessorPathsToMove,
            CancelToken cancelToken,
            object lockObj,
            IDisableAssetsProcessor disableAssetsProcessor)
        {
            bool hasProcessedPaths = false;

            try
            {
                hasProcessedPaths = AssetsProcessorOperations.
                    AddIfNotControlled(
                        plasticApi,
                        ExtractPathsToProcess(assetsProcessorPathsToAdd, lockObj),
                        FilterManager.Get().GetIgnoredFilter(),
                        cancelToken);

                if (cancelToken.IsCancelled())
                    return false;

                hasProcessedPaths |= AssetsProcessorOperations.
                    DeleteIfControlled(
                        plasticApi,
                        ExtractPathsToProcess(assetsProcessorPathsToDelete, lockObj),
                        cancelToken);

                if (cancelToken.IsCancelled())
                    return false;

                hasProcessedPaths |= AssetsProcessorOperations.
                    CheckoutIfControlledAndChanged(
                        plasticApi,
                        ExtractPathsToProcess(assetsProcessorPathsToCheckout, lockObj),
                        cancelToken);

                if (cancelToken.IsCancelled())
                    return false;

                hasProcessedPaths |= AssetsProcessorOperations.
                    MoveIfControlled(
                        plasticApi,
                        ExtractPathsToMoveToProcess(assetsProcessorPathsToMove, lockObj).AsReadOnly(),
                        cancelToken);
            }
            catch (Exception ex)
            {
                LogException(ex);

                disableAssetsProcessor.Disable();
            }

            return hasProcessedPaths;
        }

        static bool ProcessCheckoutOperation(
            IPlasticAPI plasticApi,
            List<string> pathsToProcess,
            CancelToken cancelToken,
            object lockObj)
        {
            List<string> paths = ExtractPathsToProcess(
                pathsToProcess, lockObj);

            List<string> result = new List<string>();

            foreach (string path in paths)
            {
                if (cancelToken.IsCancelled())
                    return false;

                WorkspaceTreeNode node =
                    plasticApi.GetWorkspaceTreeNode(path);

                if (node != null &&
                    !CheckWorkspaceTreeNodeStatus.IsCheckedOut(node))
                    result.Add(path);
            }

            if (cancelToken.IsCancelled())
                return false;

            bool hasPathsToProcess = result.Count > 0;

            if (hasPathsToProcess)
            {
                plasticApi.Checkout(
                    result.ToArray(),
                    CheckoutModifiers.ProcessSymlinks);
            }

            LogProcessedPaths("ProcessCheckoutOperation", result);

            return hasPathsToProcess;
        }

        static void AddPathsToProcess(
            List<string> pathsToProcess,
            List<string> paths,
            object lockObj,
            ManualResetEvent resetEvent,
            bool isEnabled)
        {
            if (!isEnabled)
                return;

            lock (lockObj)
            {
                pathsToProcess.AddRange(paths);
            }

            resetEvent.Set();
        }

        static void AddPathsToMoveToProcess(
            List<AssetPostprocessor.PathToMove> pathsToProcess,
            List<AssetPostprocessor.PathToMove> paths,
            object lockObj,
            ManualResetEvent resetEvent,
            bool isEnabled)
        {
            if (!isEnabled)
                return;

            lock (lockObj)
            {
                pathsToProcess.AddRange(paths);
            }

            resetEvent.Set();
        }

        static List<string> ExtractPathsToProcess(
            List<string> pathsToProcess,
            object lockObj)
        {
            List<string> result;

            lock (lockObj)
            {
                result = new List<string>(pathsToProcess);
                pathsToProcess.Clear();
            }

            return result;
        }

        static List<AssetPostprocessor.PathToMove> ExtractPathsToMoveToProcess(
            List<AssetPostprocessor.PathToMove> pathsToProcess,
            object lockObj)
        {
            List<AssetPostprocessor.PathToMove> result;

            lock (lockObj)
            {
                result = new List<AssetPostprocessor.PathToMove>(pathsToProcess);
                pathsToProcess.Clear();
            }

            return result;
        }

        static void HasPendingOperationsToProcess(
            List<string> assetsProcessorPathsToAdd,
            List<string> assetsProcessorPathsToDelete,
            List<string> assetsProcessorPathsToCheckout,
            List<AssetPostprocessor.PathToMove> assetsProcessorPathsToMove,
            List<string> pathsToCheckout,
            object lockObj,
            out bool hasAssetProcessorOperations,
            out bool hasCheckoutOperations)
        {
            lock (lockObj)
            {
                hasAssetProcessorOperations =
                    assetsProcessorPathsToAdd.Count > 0 ||
                    assetsProcessorPathsToDelete.Count > 0 ||
                    assetsProcessorPathsToCheckout.Count > 0 ||
                    assetsProcessorPathsToMove.Count > 0;

                hasCheckoutOperations =
                    pathsToCheckout.Count > 0;
            }
        }

        static void RefreshViewsAfterAssetProcessorForGluon(ViewHost viewHost)
        {
            if (viewHost == null)
            {
                return;
            }

            viewHost.RefreshView(ViewType.LocksView);
        }

        static void RefreshViewsAfterAssetProcessorForDeveloper(IWorkspaceWindow workspaceWindow)
        {
            if (workspaceWindow == null)
            {
                return;
            }

            workspaceWindow.RefreshView(ViewType.LocksView);
        }

        static void RefreshViewsAfterCheckoutForDeveloper(
            IWorkspaceWindow workspaceWindow)
        {
            if (workspaceWindow == null)
                return;

            workspaceWindow.RefreshView(ViewType.BranchExplorerView);
            workspaceWindow.RefreshView(ViewType.PendingChangesView);
            workspaceWindow.RefreshView(ViewType.HistoryView);
            workspaceWindow.RefreshView(ViewType.LocksView);
        }

        static void RefreshViewsAfterCheckoutForGluon(
            ViewHost viewHost)
        {
            if (viewHost == null)
                return;

            viewHost.RefreshView(ViewType.WorkspaceExplorerView);
            viewHost.RefreshView(ViewType.CheckinView);
            viewHost.RefreshView(ViewType.IncomingChangesView);
            viewHost.RefreshView(ViewType.SearchView);
            viewHost.RefreshView(ViewType.LocksView);
        }

        static void LogProcessedPaths(
            string operation,
            List<string> paths)
        {
            if (paths.Count == 0)
            {
                mLog.DebugFormat(
                    "{0} - There are no processed paths.",
                    operation);
                return;
            }

            mLog.DebugFormat(
                "{0} - Processed paths: {1}{2}",
                operation, Environment.NewLine,
                string.Join(Environment.NewLine, paths));
        }

        static void LogException(Exception ex)
        {
            mLog.WarnFormat("Message: {0}", ex.Message);

            mLog.DebugFormat(
                "StackTrace:{0}{1}",
                Environment.NewLine, ex.StackTrace);
        }

        internal static class AssetsProcessorOperations
        {
            internal static bool AddIfNotControlled(
                IPlasticAPI plasticApi,
                List<string> paths,
                IgnoredFilesFilter ignoredFilter,
                CancelToken cancelToken)
            {
                List<string> result = new List<string>();

                foreach (string path in paths)
                {
                    if (cancelToken.IsCancelled())
                        return false;

                    string metaPath = MetaPath.GetMetaPath(path);

                    if (plasticApi.GetWorkspaceFromPath(path) == null)
                        return false;

                    if (plasticApi.GetWorkspaceTreeNode(path) == null &&
                        !ignoredFilter.IsIgnored(path))
                        result.Add(path);

                    if (File.Exists(metaPath) &&
                        plasticApi.GetWorkspaceTreeNode(metaPath) == null &&
                        !ignoredFilter.IsIgnored(path))
                        result.Add(metaPath);
                }

                if (cancelToken.IsCancelled())
                    return false;

                bool hasPathsToProcess = result.Count > 0;

                if (hasPathsToProcess)
                {
                    IList checkouts;
                    plasticApi.Add(
                        result.ToArray(),
                        GetDefaultAddOptions(),
                        out checkouts);
                }

                LogProcessedPaths("AddIfNotControlled", result);

                return hasPathsToProcess;
            }

            internal static bool DeleteIfControlled(
                IPlasticAPI plasticApi,
                List<string> paths,
                CancelToken cancelToken)
            {
                List<string> processedPaths = new List<string>(paths.Count);

                foreach (string path in paths)
                {
                    if (cancelToken.IsCancelled())
                        return false;

                    string metaPath = MetaPath.GetMetaPath(path);

                    if (plasticApi.GetWorkspaceTreeNode(path) != null)
                    {
                        processedPaths.Add(path);
                    }

                    if (plasticApi.GetWorkspaceTreeNode(metaPath) != null)
                    {
                        processedPaths.Add(metaPath);
                    }
                }

                if (cancelToken.IsCancelled())
                    return false;

                plasticApi.DeleteControlled(
                    processedPaths.ToArray(), DeleteModifiers.None, null);

                LogProcessedPaths("DeleteIfControlled", processedPaths);

                return processedPaths.Count > 0;
            }

            internal static bool MoveIfControlled(
                IPlasticAPI plasticApi,
                ReadOnlyCollection<AssetPostprocessor.PathToMove> paths,
                CancelToken cancelToken)
            {
                List<string> processedPaths = new List<string>(paths.Count);

                foreach (AssetPostprocessor.PathToMove pathToMove in paths)
                {
                    if (cancelToken.IsCancelled())
                        return false;

                    if (plasticApi.GetWorkspaceTreeNode(pathToMove.SrcPath) != null)
                    {
                        plasticApi.Move(
                            pathToMove.SrcPath, pathToMove.DstPath,
                            MoveModifiers.None);

                        processedPaths.Add(string.Format("{0} to {1}",
                            pathToMove.SrcPath, pathToMove.DstPath));
                    }

                    if (cancelToken.IsCancelled())
                        return false;

                    string srcMetaPath = MetaPath.GetMetaPath(pathToMove.SrcPath);
                    string dstMetaPath = MetaPath.GetMetaPath(pathToMove.DstPath);

                    if (plasticApi.GetWorkspaceTreeNode(srcMetaPath) != null)
                    {
                        plasticApi.Move(
                            srcMetaPath, dstMetaPath,
                            MoveModifiers.None);

                        processedPaths.Add(string.Format("{0} to {1}",
                            srcMetaPath, dstMetaPath));
                    }
                }

                LogProcessedPaths("MoveIfControlled", processedPaths);

                return processedPaths.Count > 0;
            }

            internal static bool CheckoutIfControlledAndChanged(
                IPlasticAPI plasticApi,
                List<string> paths,
                CancelToken cancelToken)
            {
                List<string> result = new List<string>();

                foreach (string path in paths)
                {
                    if (cancelToken.IsCancelled())
                        return false;

                    string metaPath = MetaPath.GetMetaPath(path);

                    WorkspaceTreeNode node =
                        plasticApi.GetWorkspaceTreeNode(path);
                    WorkspaceTreeNode nodeMeta =
                        plasticApi.GetWorkspaceTreeNode(metaPath);

                    if (node != null &&
                        !CheckWorkspaceTreeNodeStatus.IsCheckedOut(node) &&
                        ChangedFileChecker.IsChanged(node.LocalInfo, path, false))
                        result.Add(path);

                    if (nodeMeta != null &&
                        !CheckWorkspaceTreeNodeStatus.IsCheckedOut(nodeMeta) &&
                        ChangedFileChecker.IsChanged(nodeMeta.LocalInfo, metaPath, false))
                        result.Add(metaPath);
                }

                if (cancelToken.IsCancelled())
                    return false;

                bool hasPathsToProcess = result.Count > 0;

                if (hasPathsToProcess)
                {
                    plasticApi.Checkout(
                        result.ToArray(),
                        CheckoutModifiers.None);
                }

                LogProcessedPaths("CheckoutIfControlledAndChanged", result);

                return hasPathsToProcess;
            }

            static AddOptions GetDefaultAddOptions()
            {
                AddOptions options = new AddOptions();
                options.AddPrivateParents = true;
                options.NeedCheckPlatformPath = true;
                return options;
            }
        }

        object mLock = new object();

        List<string> mAssetsProcessorPathsToAdd = new List<string>();
        List<string> mAssetsProcessorPathsToDelete = new List<string>();
        List<string> mAssetsProcessorPathsToCheckout = new List<string>();
        List<AssetPostprocessor.PathToMove> mAssetsProcessorPathsToMove = new List<AssetPostprocessor.PathToMove>();
        List<string> mPathsToCheckout = new List<string>();

        PendingChangesTab mPendingChangesTab;
        IIncomingChangesTab mIncomingChangesTab;
        IWorkspaceWindow mWorkspaceWindow;
        ViewHost mViewHost;
        NewIncomingChangesUpdater mNewIncomingChangesUpdater;

        volatile bool mIsEnabled;
        volatile ManualResetEvent mResetEvent = new ManualResetEvent(false);
        CancelToken mCancelToken = new CancelToken();

        readonly bool mIsGluonMode = false;
        readonly IDisableAssetsProcessor mDisableAssetsProcessor;
        readonly IPlasticAPI mPlasticAPI;

        static readonly ILog mLog = PlasticApp.GetLogger("WorkspaceOperationsMonitor");
    }
}
