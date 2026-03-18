using UnityEditor;
using UnityEngine;
using UnityEngine.UIElements;

using PlasticGui;
using PlasticGui.WebApi;
using PlasticGui.Configuration.CloudEdition.Welcome;
using PlasticGui.Configuration.OAuth;
using System.Collections.Generic;
using Codice.Client.Common.Servers;
using Codice.Client.Common;
using Codice.Utils;
using Unity.PlasticSCM.Editor.Views.Welcome;

using Codice.CM.Common;

namespace Unity.PlasticSCM.Editor.Configuration.CloudEdition.Welcome
{
    internal interface IWelcomeWindowNotify
    {
        void SuccessForHomeView(string userName);
        void Back();
    }

    internal class CloudEditionWelcomeWindow :
        EditorWindow,
        OAuthSignIn.INotify,
        IWelcomeWindowNotify
    {
        internal static void ShowWindow(
            IPlasticWebRestApi restApi,
            CmConnection cmConnection,
            WelcomeView welcomeView,
            bool autoLogin = false)
        {
            sRestApi = restApi;
            sCmConnection = cmConnection;
            sAutoLogin = autoLogin;
            CloudEditionWelcomeWindow window = GetWindow<CloudEditionWelcomeWindow>();

            window.titleContent = new GUIContent(
                PlasticLocalization.GetString(PlasticLocalization.Name.SignInToUnityVCS));
            window.minSize = window.maxSize = new Vector2(450, 300);

            window.mWelcomeView = welcomeView;

            window.Show();
        }

        internal static CloudEditionWelcomeWindow GetWelcomeWindow()
        {
            return GetWindow<CloudEditionWelcomeWindow>();
        }

        // Save the Default Server in the config files of all clients, so they are already configured.
        // Avoids having the Desktop application asking the user again later.
        internal static void SaveDefaultCloudServer(string cloudServer, string username)
        {
            SaveCloudServer.ToPlasticGuiConfig(cloudServer);
            SaveCloudServer.ToPlasticGuiConfigFile(
                cloudServer, GetPlasticConfigFileToSaveOrganization());
            SaveCloudServer.ToPlasticGuiConfigFile(
                cloudServer, GetGluonConfigFileToSaveOrganization());

            KnownServers.ServersFromCloud.InitializeForWindows(
                PlasticGuiConfig.Get().Configuration.DefaultCloudServer);

            SetupUnityEditionToken.CreateCloudEditionTokenIfNeeded();

            ClientConfigData clientConfigData = ConfigurationChecker.GetClientConfigData();

            if (sAutoLogin)
            {
                clientConfigData.WorkspaceServer = cloudServer;
                clientConfigData.WorkingMode = SEIDWorkingMode.SSOWorkingMode.ToString();
                clientConfigData.SecurityConfig = username;

                GetWindow<PlasticWindow>().GetWelcomeView().autoLoginState = AutoLogin.State.OrganizationChoosed;
            }

            ClientConfig.Get().Save(clientConfigData);
        }

        internal static string GetPlasticConfigFileToSaveOrganization()
        {
            if (PlatformIdentifier.IsMac())
            {
                return "macgui.conf";
            }

            return "plasticgui.conf";
        }

        internal static string GetGluonConfigFileToSaveOrganization()
        {
            if (PlatformIdentifier.IsMac())
            {
                return "gluon.conf";
            }

            return "gameui.conf";
        }

        internal void CancelJoinOrganization()
        {
            if (sAutoLogin)
            {
                GetWindow<PlasticWindow>().GetWelcomeView().autoLoginState = AutoLogin.State.Started;
            }
        }

        internal void SaveDefaultCloudServer(string organization)
        {
            SaveDefaultCloudServer(organization, mUserName);
        }

        internal void ReplaceRootPanel(VisualElement panel)
        {
            rootVisualElement.Clear();
            rootVisualElement.Add(panel);
        }

        internal void ShowOrganizationPanel(string title)
        {
            mOrganizationPanel = new OrganizationPanel(
                this,
                sRestApi,
                title);

            ReplaceRootPanel(mOrganizationPanel);
        }

        internal void FillUser(string userName)
        {
            mUserName = userName;
        }

        internal void ShowOrganizationPanelFromAutoLogin()
        {
            ShowOrganizationPanel(GetWindowTitle());
        }

        internal string GetWindowTitle()
        {
            return PlasticLocalization.Name.SignInToUnityVCS.GetString();
        }

        internal SignInPanel GetSignInPanel()
        {
            return mSignInPanel;
        }

        void OAuthSignIn.INotify.SuccessForConfigure(
            List<string> organizations,
            bool canCreateAnOrganization,
            string userName,
            string accessToken)
        {
            // empty implementation
        }

        void OAuthSignIn.INotify.SuccessForSSO(string organization)
        {
            // empty implementation
        }

        void OAuthSignIn.INotify.SuccessForProfile(string email)
        {
            // empty implementation
        }

        void OAuthSignIn.INotify.SuccessForHomeView(string userName)
        {
            ShowOrganizationPanel(GetWindowTitle());

            Focus();

            mUserName = userName;
        }

        void OAuthSignIn.INotify.SuccessForCredentials(
            string email,
            string accessToken)
        {
            // empty implementation
        }

        void OAuthSignIn.INotify.Cancel(string errorMessage)
        {
            Focus();
        }

        void IWelcomeWindowNotify.SuccessForHomeView(string userName)
        {
            GetWindow<PlasticWindow>().InitializePlastic();
                
            ShowOrganizationPanel(GetWindowTitle());

            Focus();

            mUserName = userName;
        }

        void IWelcomeWindowNotify.Back()
        {
            rootVisualElement.Clear();
            rootVisualElement.Add(mSignInPanel);
        }

        void OnEnable()
        {
            BuildComponents();
        }

        void OnDestroy()
        {
            Dispose();

            if (mWelcomeView != null)
                mWelcomeView.OnUserClosedConfigurationWindow();
        }

        void Dispose()
        {
            if (mSignInPanel != null)
                mSignInPanel.Dispose();

            if (mOrganizationPanel != null)
                mOrganizationPanel.Dispose();
        }

        void BuildComponents()
        {
            VisualElement root = rootVisualElement;

            root.Clear();

            mSignInPanel = new SignInPanel(
                this,
                sRestApi,
                sCmConnection);

            titleContent = new GUIContent(GetWindowTitle());

            root.Add(mSignInPanel);
            if (sAutoLogin)
                mSignInPanel.SignInWithUnityIdButtonAutoLogin();
        }

        string mUserName;

        OrganizationPanel mOrganizationPanel;
        SignInPanel mSignInPanel;
        WelcomeView mWelcomeView;

        static IPlasticWebRestApi sRestApi;
        static CmConnection sCmConnection;
        static bool sAutoLogin = false;
    }
}