using System.Collections.Generic;
using System.IO;

using Codice.Client.Commands.WkTree;
using Codice.Client.Common;
using Codice.Client.Common.GameUI;
using Codice.CM.Common;
using Codice.CM.Common.Mount;
using Codice.CM.Common.Partial;
using Codice.CM.WorkspaceServer.DataStore.Configuration;

namespace Unity.PlasticSCM.Editor.Configuration
{
    internal static class ConfigurePartialWorkspace
    {
        internal static void AsFullyChecked(WorkspaceInfo wkInfo)
        {
            string rootPath = WorkspacePath.GetWorkspacePathFromCmPath(
                wkInfo.ClientPath, "/", Path.DirectorySeparatorChar);

            WorkspaceTreeNode rootWkNode = CmConnection.Get().GetWorkspaceTreeHandler().
                WkGetWorkspaceTreeNode(rootPath);

            FullyCheckedDirectory rootDirectory = new FullyCheckedDirectory(
                MountPointId.WORKSPACE_ROOT, rootWkNode.RevInfo.ItemId);

            List<FullyCheckedDirectory> directoryList = new List<FullyCheckedDirectory>();
            directoryList.Add(rootDirectory);

            FullyCheckedDirectoriesStorage.Save(wkInfo, directoryList);
        }
    }
}
