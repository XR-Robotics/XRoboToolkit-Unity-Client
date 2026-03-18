using System.IO;

using Codice.CM.Common;
using PlasticGui.WebApi;

namespace Unity.PlasticSCM.Editor.Hub.Operations
{
    internal class OperationParams
    {
        internal readonly string WorkspaceFullPath;
        internal readonly string Organization;
        internal readonly string Repository;
        internal readonly RepositorySpec RepositorySpec;
        internal readonly string AccessToken;

        internal static OperationParams BuildFromCommand(
            ParseArguments.Command command,
            string unityAccessToken)
        {
            string workspaceFullPath = command.HasWorkspacePath() ?
                Path.GetFullPath(command.WorkspacePath) :
                Path.GetFullPath(command.ProjectPath);

            return new OperationParams(
                workspaceFullPath,
                command.Organization,
                command.Repository,
                BuildRepositorySpec(
                    command.Organization, command.Repository),
                unityAccessToken);
        }

        static RepositorySpec BuildRepositorySpec(
            string organization,
            string repository)
        {
            string defaultCloudAlias = new PlasticWebRestApi()
                .GetDefaultCloudAlias();

            return RepositorySpec.BuildFromNameAndResolvedServer(
                repository,
                CloudServer.BuildFullyQualifiedName(organization, defaultCloudAlias)
            );
        }

        OperationParams(
            string workspaceFullPath,
            string organization,
            string repository,
            RepositorySpec repositorySpec,
            string accessToken)
        {
            WorkspaceFullPath = workspaceFullPath;
            Organization = organization;
            Repository = repository;
            RepositorySpec = repositorySpec;
            AccessToken = accessToken;
        }
    }
}
