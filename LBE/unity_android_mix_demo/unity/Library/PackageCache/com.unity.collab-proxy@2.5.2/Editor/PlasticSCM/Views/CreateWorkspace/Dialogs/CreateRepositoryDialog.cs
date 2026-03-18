using System.Collections.Generic;
using System.Linq;
using UnityEditor;
using UnityEngine;

using Codice.Client.Common;
using Codice.Client.Common.Threading;
using Codice.CM.Common;
using PlasticGui;
using PlasticGui.WorkspaceWindow.Home.Repositories;
using PlasticGui.WebApi;
using PlasticGui.WorkspaceWindow.Servers;
using Unity.PlasticSCM.Editor.UI;
using Unity.PlasticSCM.Editor.UI.Progress;

namespace Unity.PlasticSCM.Editor.Views.CreateWorkspace.Dialogs
{
    internal class CreateRepositoryDialog :
        PlasticDialog,
        KnownServersListOperations.IKnownServersList
    {
        protected override Rect DefaultRect
        {
            get
            {
                var baseRect = base.DefaultRect;
                return new Rect(baseRect.x, baseRect.y, 600, 310);
            }
        }

        internal static RepositoryCreationData CreateRepository(
            EditorWindow parentWindow,
            IPlasticWebRestApi plasticWebRestApi,
            string proposedRepositoryName,
            string proposedServer,
            string lastUsedRepServer,
            string clientConfServer)
        {
            string server = CreateRepositoryDialogUserAssistant.GetProposedServer(
                proposedServer, lastUsedRepServer, clientConfServer);

            CreateRepositoryDialog dialog = Create(
                plasticWebRestApi,
                new ProgressControlsForDialogs(),
                proposedRepositoryName,
                server);

            ResponseType dialogResult = dialog.RunModal(parentWindow);

            RepositoryCreationData result = dialog.BuildCreationData();

            result.Result = dialogResult == ResponseType.Ok;
            return result;
        }

        protected override void OnModalGUI()
        {
            Title(PlasticLocalization.Name.NewRepositoryTitle.GetString());

            Paragraph(PlasticLocalization.Name.NewRepositoryExplanation.GetString());

            Paragraph(PlasticLocalization.Name.CreateRepositoryDialogDetailedExplanation.GetString());

            if (Event.current.type == EventType.Layout)
            {
                mProgressControls.ProgressData.CopyInto(mProgressData);
            }

            GUILayout.Space(5);

            DoEntriesArea();

            DrawProgressForDialogs.For(mProgressControls.ProgressData);

            GUILayout.FlexibleSpace();

            DoButtonsArea();

            mProgressControls.ForcedUpdateProgress(this);
        }

        protected override string GetTitle()
        {
            return PlasticLocalization.Name.NewRepositoryTitle.GetString();
        }

        void KnownServersListOperations.IKnownServersList.FillValues(List<string> knownServers)
        {
            mKnownServers = knownServers.Select(ResolveServer.ToDisplayString).ToList();
            mKnownServers.Sort();

            OnServerSelected(mSelectedServer);
        }

        void DoEntriesArea()
        {
            mRepositoryName = TextEntry(
                PlasticLocalization.Name.RepositoryNameShortLabel.GetString(),
                mRepositoryName,
                REPONAME_CONTROL_NAME,
                ENTRY_WIDTH,
                ENTRY_X);

            if (!mFocusIsAreadySet)
            {
                mFocusIsAreadySet = true;
                GUI.FocusControl(REPONAME_CONTROL_NAME);
            }

            GUILayout.Space(5);
            
            mSelectedServer = ComboBox(
                PlasticLocalization.Name.RepositoryServerOrOrganizationLabel.GetString(),
                mSelectedServer,
                mKnownServers,
                OnServerSelected,
                ENTRY_WIDTH,
                ENTRY_X);

            if (OrganizationsInformation.IsUnityOrganization(mSelectedServer))
            {
                GUILayout.Space(5);

                DoOrganizationProjectsDropdown();
                DoCreateOrganizationProjectLink();
            }
        }

        void DoOrganizationProjectsDropdown()
        {
            if (mSelectedProject == null)
            {
                GUI.enabled = false;
            }

            ComboBox(
                PlasticLocalization.Name.OrganizationProjectLabel.GetString(),
                mSelectedProject,
                mCurrentServerProjects,
                OnProjectSelected,
                ENTRY_WIDTH,
                ENTRY_X);

            GUI.enabled = true;
        }

        void DoCreateOrganizationProjectLink()
        {
            GUILayout.BeginHorizontal();

            GUILayout.FlexibleSpace();

            if (GUILayout.Button(
                    PlasticLocalization.Name.CreateOrganizationProjectLabel.GetString(),
                    UnityStyles.LinkLabel,
                    GUILayout.Height(20)))
            {
                // TODO refactor this code once the new changes in the OrganizationInfo are available
                string serverName = ResolveServer.FromUserInput(mSelectedServer, CmConnection.Get().UnityOrgResolver);
                string organizationName = ServerOrganizationParser.GetOrganizationFromServer(serverName);

                Application.OpenURL(UnityUrl.UnityDashboard.UnityOrganizations.GetProjectsUrl(organizationName));
            }

            GUILayout.EndHorizontal();
        }

        void OnServerSelected(object server)
        {
            ((IProgressControls) mProgressControls).HideProgress();
            mProgressControls.ProgressData.StatusMessage = string.Empty;
            mProgressControls.ProgressData.StatusType = MessageType.None;

            mIsLoadingProjects = false;

            if (server == null || string.IsNullOrEmpty(server.ToString()))
            {
                mSelectedServer = null;
                mSelectedProject = null;

                return;
            }

            mSelectedServer = server.ToString();

            // We need to ensure it is a known server because the dropdown is editable
            if (OrganizationsInformation.IsUnityOrganization(mSelectedServer) && mKnownServers.Contains(mSelectedServer))
            {
                LoadServerProjects(mSelectedServer);
            }
            else
            {
                mSelectedProject = null;
            }

            Repaint();
        }

        void OnFocus()
        {
            OnServerSelected(mSelectedServer);
        }

        void OnProjectSelected(object project)
        {
            mSelectedProject = project.ToString();

            Repaint();
        }

        void LoadServerProjects(string server)
        {
            mIsLoadingProjects = true;

            ((IProgressControls) mProgressControls).ShowProgress(
                PlasticLocalization.Name.RetrievingServerProjects.GetString());

            List<string> serverProjects = null;

            IThreadWaiter waiter = ThreadWaiter.GetWaiter();
            waiter.Execute(
                /*threadOperationDelegate*/ delegate
                {
                    string serverName = ResolveServer.FromUserInput(server, CmConnection.Get().UnityOrgResolver);

                    serverProjects = OrganizationsInformation.GetOrganizationProjects(serverName);
                },
                /*afterOperationDelegate*/ delegate
                {
                    mIsLoadingProjects = false;

                    if (waiter.Exception != null)
                    {
                        ((IProgressControls) mProgressControls).ShowError(
                        PlasticLocalization.Name.ErrorRetrievingServerProjects.GetString());
                    }

                    mCurrentServerProjects = serverProjects;

                    if (mCurrentServerProjects == null || mCurrentServerProjects.Count == 0)
                    {
                        mSelectedProject = null;

                        ((IProgressControls) mProgressControls).ShowError(
                            PlasticLocalization.Name.NoServerProjectsFound.GetString());
                    }
                    else
                    {
                        if (string.IsNullOrEmpty(mSelectedProject) || !mCurrentServerProjects.Contains(mSelectedProject))
                        {
                            mSelectedProject = mCurrentServerProjects.First();
                        }

                        ((IProgressControls) mProgressControls).HideProgress();
                    }
                });
        }

        void DoButtonsArea()
        {
            using (new EditorGUILayout.HorizontalScope())
            {
                GUILayout.FlexibleSpace();

                if (mIsLoadingProjects)
                {
                    GUI.enabled = false;
                }

                if (Application.platform == RuntimePlatform.WindowsEditor)
                {
                    DoOkButton();
                    DoCancelButton();
                    return;
                }

                DoCancelButton();
                DoOkButton();
            }
        }

        void DoOkButton()
        {
            if (!AcceptButton(PlasticLocalization.Name.OkButton.GetString()))
                return;

            OkButtonWithValidationAction();
        }

        void DoCancelButton()
        {
            if (!NormalButton(PlasticLocalization.Name.CancelButton.GetString()))
                return;

            CancelButtonAction();
        }

        void OkButtonWithValidationAction()
        {
            RepositoryCreationValidation.AsyncValidation(
                BuildCreationData(),
                this,
                mProgressControls);
        }

        RepositoryCreationData BuildCreationData()
        {
            string repositoryName = mSelectedProject != null
                ? string.Format("{0}/{1}", mSelectedProject, mRepositoryName)
                : mRepositoryName;

            return new RepositoryCreationData(
                repositoryName,
                ResolveServer.FromUserInput(mSelectedServer, CmConnection.Get().UnityOrgResolver));
        }

        static CreateRepositoryDialog Create(
            IPlasticWebRestApi plasticWebRestApi,
            ProgressControlsForDialogs progressControls,
            string proposedRepositoryName,
            string proposedServer)
        {
            var instance = CreateInstance<CreateRepositoryDialog>();
            instance.mEnterKeyAction = instance.OkButtonWithValidationAction;
            instance.mEscapeKeyAction = instance.CancelButtonAction;
            instance.mPlasticWebRestApi = plasticWebRestApi;
            instance.mProgressControls = progressControls;
            instance.BuildComponents(proposedRepositoryName, proposedServer);
            return instance;
        }

        void BuildComponents(string proposedRepositoryName, string proposedServer)
        {
            mSelectedServer = ResolveServer.ToDisplayString(proposedServer);
            mSelectedProject = null;

            mRepositoryName = proposedRepositoryName;
            if (OrganizationsInformation.IsUnityOrganization(proposedServer))
            {
                string[] repositoryNameParts = proposedRepositoryName.Split('/');

                if (repositoryNameParts.Length > 1)
                {
                    mRepositoryName = repositoryNameParts[repositoryNameParts.Length - 1].Trim();
                }
            }

            KnownServersListOperations.GetCombinedServers(
                true,
                GetExtraServers(proposedServer),
                mProgressControls,
                this,
                mPlasticWebRestApi,
                CmConnection.Get().GetProfileManager());
        }

        static List<string> GetExtraServers(string proposedServer)
        {
            List<string> result = new List<string>();
            if (!string.IsNullOrEmpty(proposedServer))
                result.Add(proposedServer);

            return result;
        }

        IPlasticWebRestApi mPlasticWebRestApi;
        bool mFocusIsAreadySet;

        string mRepositoryName;
        string mSelectedServer;
        string mSelectedProject;
        bool mIsLoadingProjects;

        List<string> mKnownServers = new List<string>();
        List<string> mCurrentServerProjects = new List<string>();

        ProgressControlsForDialogs.Data mProgressData = new ProgressControlsForDialogs.Data();

        ProgressControlsForDialogs mProgressControls;

        const float ENTRY_WIDTH = 400;
        const float ENTRY_X = 175f;
        const string REPONAME_CONTROL_NAME = "CreateRepositoryDialog.RepositoryName";
    }
}
