using Codice.Client.Common;
using UnityEditor.IMGUI.Controls;

using Codice.CM.Common;

namespace Unity.PlasticSCM.Editor.Views.CreateWorkspace.Dialogs
{
    internal class RepositoryListViewItem : TreeViewItem
    {
        internal RepositoryInfo Repository { get; private set; }

        internal string ServerDisplayName { get; private set; }

        internal RepositoryListViewItem(int id, RepositoryInfo repository)
            : base(id, 0)
        {
            Repository = repository;
            ServerDisplayName = ResolveServer.ToDisplayString(repository.Server);

            displayName = repository.Name;
        }
    }
}
