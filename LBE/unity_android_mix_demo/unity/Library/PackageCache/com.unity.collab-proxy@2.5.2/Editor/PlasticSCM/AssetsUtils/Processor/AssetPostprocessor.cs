using System.Collections.Generic;
using System.Linq;

using UnityEditor;

using Codice.Client.Common;
using Codice.Client.Common.FsNodeReaders.Watcher;
using Codice.LogWrapper;
using Unity.PlasticSCM.Editor.UI;

namespace Unity.PlasticSCM.Editor.AssetUtils.Processor
{
    class AssetPostprocessor : UnityEditor.AssetPostprocessor
    {
        internal static bool AutomaticAdd { get; private set; }

        static AssetPostprocessor()
        {
            AutomaticAdd = BoolSetting.Load(UnityConstants.AUTOMATIC_ADD_KEY_NAME, true);
        }
        
        internal static void SetAutomaticAddOption(bool isEnabled)
        {
            if (AutomaticAdd != isEnabled)
            {
                AutomaticAdd = isEnabled;
                
                BoolSetting.Save(isEnabled, UnityConstants.AUTOMATIC_ADD_KEY_NAME);
            }
        }

        internal struct PathToMove
        {
            internal readonly string SrcPath;
            internal readonly string DstPath;

            internal PathToMove(string srcPath, string dstPath)
            {
                SrcPath = srcPath;
                DstPath = dstPath;
            }
        }

        internal static void Enable(
            string wkPath,
            PlasticAssetsProcessor plasticAssetsProcessor)
        {
            mLog.Debug("Enable");

            mWkPath = wkPath;
            mPlasticAssetsProcessor = plasticAssetsProcessor;

            mIsEnabled = true;
        }

        internal static void Disable()
        {
            mLog.Debug("Disable");

            mIsEnabled = false;

            mWkPath = null;
            mPlasticAssetsProcessor = null;
        }

        internal static void SetIsRepaintNeededAfterAssetDatabaseRefresh()
        {
            mIsRepaintNeededAfterAssetDatabaseRefresh = true;
        }

        static void OnPostprocessAllAssets(
            string[] importedAssets,
            string[] deletedAssets,
            string[] movedAssets,
            string[] movedFromAssetPaths)
        {
            if (!mIsEnabled)
                return;

            if (mIsRepaintNeededAfterAssetDatabaseRefresh)
            {
                mIsRepaintNeededAfterAssetDatabaseRefresh = false;

                ProjectWindow.Repaint();
                RepaintInspector.All();
            }

            // We need to ensure that the MonoFSWatcher is enabled before processing Plastic operations
            // It fixes the following scenario: 
            // 1. Close PlasticSCM window
            // 2. Create an asset, it appears with the added overlay
            // 3. Open PlasticSCM window, the asset should appear as added instead of deleted locally
            PlasticApp.EnableMonoFsWatcherIfNeeded();

            mPlasticAssetsProcessor.MoveOnSourceControl(
                ExtractPathsToMove(movedAssets, movedFromAssetPaths));

            mPlasticAssetsProcessor.DeleteFromSourceControl(
                GetPathsContainedOnWorkspace(mWkPath, deletedAssets));

            if (AutomaticAdd)
            {
                mPlasticAssetsProcessor.AddToSourceControl(
                    GetPathsContainedOnWorkspace(mWkPath, importedAssets));
            }

            // We expect modified assets to go through AssetModificationProcessor.OnWillSaveAssets before getting here.
            // To fix: there is a known limitation of renamed prefabs not triggering OnWillSaveAssets method.
            if (AssetModificationProcessor.ModifiedAssets == null)
                return;

            mPlasticAssetsProcessor.CheckoutOnSourceControl(
                GetPathsContainedOnWorkspace(
                    mWkPath, AssetModificationProcessor.ModifiedAssets));

            AssetModificationProcessor.ModifiedAssets = null;
        }

        static List<PathToMove> ExtractPathsToMove(string[] movedAssets, string[] movedFromAssetPaths)
        {
            List<PathToMove> proposedPathsToMove = GetPathsToMoveContainedOnWorkspace(mWkPath, movedAssets, movedFromAssetPaths);

            // Unity doesn't provide the moved paths ordered.
            // We want to enqueue the batched movements in hierarchical order to avoid plastic considering assets as locally moved.
            // It also avoid unnecessary children movements when their parents are also moved.
            proposedPathsToMove.Sort((x, y) => PathHelper.GetPathMatchSorter().Compare(x.SrcPath, y.SrcPath));

            List<PathToMove> pathsToMove = new List<PathToMove>();

            foreach (PathToMove proposedPathToMove in proposedPathsToMove)
            {
                if (pathsToMove.Any(pathToMove => PathHelper.IsContainedOn(proposedPathToMove.SrcPath, pathToMove.SrcPath)))
                {
                    continue;
                }

                pathsToMove.Add(proposedPathToMove);
            }

            return pathsToMove;
        }

        static List<PathToMove> GetPathsToMoveContainedOnWorkspace(
            string wkPath,
            string[] movedAssets,
            string[] movedFromAssetPaths)
        {
            List<PathToMove> result = new List<PathToMove>(movedAssets.Length);

            for (int i = 0; i < movedAssets.Length; i++)
            {
                string fullSrcPath = AssetsPath.GetFullPathUnderWorkspace.
                    ForAsset(wkPath, movedFromAssetPaths[i]);

                if (fullSrcPath == null)
                    continue;

                string fullDstPath = AssetsPath.GetFullPathUnderWorkspace.
                    ForAsset(wkPath, movedAssets[i]);

                if (fullDstPath == null)
                    continue;

                result.Add(new PathToMove(
                    fullSrcPath, fullDstPath));
            }

            return result;
        }

        static List<string> GetPathsContainedOnWorkspace(
            string wkPath, string[] assets)
        {
            List<string> result = new List<string>(
                assets.Length);

            foreach (string asset in assets)
            {
                string fullPath = AssetsPath.GetFullPathUnderWorkspace.
                    ForAsset(wkPath, asset);

                if (fullPath == null)
                    continue;

                result.Add(fullPath);
            }

            return result;
        }

        static bool mIsEnabled;
        static bool mIsRepaintNeededAfterAssetDatabaseRefresh;

        static PlasticAssetsProcessor mPlasticAssetsProcessor;
        static string mWkPath;

        static readonly ILog mLog = PlasticApp.GetLogger("AssetPostprocessor");
    }
}
