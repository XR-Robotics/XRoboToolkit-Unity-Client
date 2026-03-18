using System;
using System.Collections.Generic;

using Codice;
using Codice.Client.Commands;
using Codice.Client.Commands.WkTree;
using Codice.Client.Common;
using Codice.Client.Common.Locks;
using Codice.Client.Common.Threading;
using Codice.Client.Common.WkTree;
using Codice.CM.Common;
using Codice.CM.Common.Mount;
using Codice.Utils;
using PlasticGui.WorkspaceWindow;
using PlasticGui.WorkspaceWindow.Items.Locks;

namespace Unity.PlasticSCM.Editor.AssetsOverlays.Cache
{
    internal class LockStatusCache
    {
        internal LockStatusCache(
            WorkspaceInfo wkInfo,
            Action repaintProjectWindow,
            Action repaintInspector)
        {
            mWkInfo = wkInfo;
            mRepaintProjectWindow = repaintProjectWindow;
            mRepaintInspector = repaintInspector;
        }

        internal AssetStatus GetStatus(string fullPath)
        {
            LockStatusData lockStatusData = GetLockStatusData(fullPath);

            if (lockStatusData == null)
                return AssetStatus.None;

            return lockStatusData.Status;
        }

        internal LockStatusData GetLockStatusData(string fullPath)
        {
            lock (mLock)
            {
                if (mStatusByPathCache == null)
                {
                    mStatusByPathCache = BuildPathDictionary.ForPlatform<LockStatusData>();

                    mCurrentCancelToken.Cancel();
                    mCurrentCancelToken = new CancelToken();
                    AsyncCalculateStatus(mCurrentCancelToken);

                    return null;
                }

                LockStatusData result;

                if (mStatusByPathCache.TryGetValue(fullPath, out result))
                    return result;

                return null;
            }
        }

        internal void Clear()
        {
            lock (mLock)
            {
                mCurrentCancelToken.Cancel();

                mStatusByPathCache = null;
            }
        }

        void AsyncCalculateStatus(CancelToken cancelToken)
        {
            Dictionary<string, LockStatusData> statusByPathCache = null;

            IThreadWaiter waiter = ThreadWaiter.GetWaiter(50);
            waiter.Execute(
                /*threadOperationDelegate*/ delegate
                {
                    Dictionary<MountPointWithPath, List<WorkspaceTreeNode>> lockCandidates =
                        new Dictionary<MountPointWithPath, List<WorkspaceTreeNode>>();

                    FillLockCandidates.ForTree(mWkInfo, lockCandidates);

                    if (cancelToken.IsCancelled())
                        return;

                    Dictionary<WorkspaceTreeNode, LockInfo> lockInfoByNode =
                        SearchLocks.GetLocksInfo(mWkInfo, lockCandidates);

                    if (cancelToken.IsCancelled())
                        return;

                    statusByPathCache = BuildStatusByNodeCache.
                        ForLocks(mWkInfo.ClientPath, lockInfoByNode);
                },
                /*afterOperationDelegate*/ delegate
                {
                    if (waiter.Exception != null)
                    {
                        ExceptionsHandler.LogException(
                            "LockStatusCache",
                            waiter.Exception);
                        return;
                    }

                    if (cancelToken.IsCancelled())
                        return;

                    lock (mLock)
                    {
                        mStatusByPathCache = statusByPathCache;
                    }

                    mRepaintProjectWindow();
                    mRepaintInspector();
                });
        }

        static class BuildStatusByNodeCache
        {
            internal static Dictionary<string, LockStatusData> ForLocks(
                string wkPath,
                Dictionary<WorkspaceTreeNode, LockInfo> lockInfoByNode)
            {
                Dictionary<string, LockStatusData> result =
                    BuildPathDictionary.ForPlatform<LockStatusData>();

                LockOwnerNameResolver nameResolver = new LockOwnerNameResolver();

                foreach (WorkspaceTreeNode node in lockInfoByNode.Keys)
                {
                    LockStatusData lockStatusData = BuildLockStatusData(
                       node, lockInfoByNode[node], nameResolver);

                    string nodeWkPath = WorkspacePath.GetWorkspacePathFromCmPath(
                        wkPath,
                        WorkspaceNodeOperations.GetCmPath(node),
                        PathHelper.GetDirectorySeparatorChar(wkPath));

                    result.Add(nodeWkPath, lockStatusData);
                }

                return result;
            }

            static LockStatusData BuildLockStatusData(
                WorkspaceTreeNode node,
                LockInfo lockInfo,
                LockOwnerNameResolver nameResolver)
            {
                return new LockStatusData(
                    GetAssetStatus(node, lockInfo),
                    nameResolver.GetSeidName(lockInfo.SEIDData),
                    BranchInfoCache.GetProtectedBranchName(
                        node.RepSpec, lockInfo.HolderBranchId));
            }

            static AssetStatus GetAssetStatus(
                WorkspaceTreeNode node,
                LockInfo lockInfo)
            {
                if (lockInfo.Status == LockInfo.LockStatus.Retained)
                    return AssetStatus.Retained;

                return CheckWorkspaceTreeNodeStatus.IsCheckedOut(node) ?
                    AssetStatus.Locked : AssetStatus.LockedRemote;
            }
        }

        CancelToken mCurrentCancelToken = new CancelToken();

        Dictionary<string, LockStatusData> mStatusByPathCache;

        readonly Action mRepaintInspector;
        readonly Action mRepaintProjectWindow;
        readonly WorkspaceInfo mWkInfo;

        static object mLock = new object();
    }
}
