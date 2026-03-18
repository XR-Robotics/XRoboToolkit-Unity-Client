using System.Linq;

using UnityEditor;
using UnityEngine;
using UnityEngine.UIElements;

using Codice.Client.Common;
using Codice.Client.Common.EventTracking;
using Codice.CM.Common;
using PlasticGui;
using Unity.PlasticSCM.Editor.Tool;
using Unity.PlasticSCM.Editor.UI;
using Unity.PlasticSCM.Editor.UI.UIElements;
using Unity.PlasticSCM.Editor.Views.Welcome;

namespace Unity.PlasticSCM.Editor.Views
{
    internal class DownloadPlasticExeDialog : PlasticDialog, DownloadAndInstallOperation.INotify
    {
        internal bool IsPlasticInstalling { get { return mIsPlasticInstalling; } }

        protected override Rect DefaultRect
        {
            get
            {
                var baseRect = base.DefaultRect;
                return new Rect(baseRect.x, baseRect.y, DIALOG_WIDTH, DIALOG_HEIGHT);
            }
        }

        internal static ProgressControlsForDialogs.Data Show(
            RepositorySpec repSpec,
            bool isGluonMode,
            string installCloudFrom,
            string installEnterpriseFrom,
            string cancelInstallFrom,
            ProgressControlsForDialogs.Data progressData)
        {
            DownloadPlasticExeDialog dialog;

            if (HasOpenInstances<DownloadPlasticExeDialog>())
            {
                dialog = GetWindow<DownloadPlasticExeDialog>(true);
            }
            else
            {
                dialog = Create(repSpec, isGluonMode, installCloudFrom, installEnterpriseFrom, cancelInstallFrom, progressData);

                dialog.RunUtility(focusedWindow);
            }

            return progressData != null ? progressData : dialog.mProgressControls.ProgressData;
        }

        static DownloadPlasticExeDialog Create(
            RepositorySpec repSpec,
            bool isGluonMode,
            string installCloudFrom,
            string installEnterpriseFrom,
            string cancelInstallFrom,
            ProgressControlsForDialogs.Data progressData)
        {
            var instance = CreateInstance<DownloadPlasticExeDialog>();
            instance.mRepSpec = repSpec;
            instance.mInstallCloudFrom = installCloudFrom;
            instance.mInstallEnterpriseFrom = installEnterpriseFrom;
            instance.mCancelInstallFrom = cancelInstallFrom;
            instance.mIsGluonMode = isGluonMode;
            instance.mProgressData = progressData;
            instance.mInstallerFile = GetInstallerTmpFileName.ForPlatform();
            instance.mIsCloudEdition = EditionToken.IsCloudEdition();
            instance.mTitle = PlasticLocalization.Name.UnityVersionControl.GetString();
            return instance;
        }

        protected override string GetTitle()
        {
            return mTitle;
        }

        void OnEnable()
        {
            BuildComponents();
        }

        void OnDestroy()
        {
            Dispose();
        }

        protected override void OnModalGUI()
        {
            if (InstallationFinished())
            {
                mMessageLabel.text = PlasticLocalization.Name.UnityVersionControlInstalled.GetString();
                mCancelButton.text = PlasticLocalization.Name.CloseButton.GetString();
                mConfirmMessageLabel.Collapse();
                mDownloadButton.Collapse();
                maxSize = new Vector2(DIALOG_WIDTH, REDUCED_DIALOG_HEIGHT);
                return;
            }

            if (mProgressData != null)
            {
                if (mProgressControlsContainer.Children().OfType<ProgressControlsForDialogs>().Any())
                {
                    mProgressControlsContainer.RemoveAt(0);
                    mProgressLabel = new Label(GetMessageFromProgressData(mProgressData));
                    mProgressControlsContainer.Add(mProgressLabel);
                }

                mProgressLabel.text = GetMessageFromProgressData(mProgressData);
                UpdateButtonsStatuses();
            }
        }

        void CancelButton_Clicked()
        {
            if (!IsExeAvailable.ForMode(mIsGluonMode))
                TrackFeatureUseEvent.For(mRepSpec, mCancelInstallFrom);

            Close();
        }

        void DownloadButton_Clicked()
        {
            if (mIsCloudEdition)
            {
                TrackFeatureUseEvent.For(mRepSpec, mInstallCloudFrom);

                DownloadAndInstallOperation.Run(
                    Edition.Cloud, mInstallerFile, mProgressControls, this);
            }
            else
            {
                TrackFeatureUseEvent.For(mRepSpec, mInstallEnterpriseFrom);

                DownloadAndInstallOperation.Run(
                    Edition.Enterprise, mInstallerFile, mProgressControls, this);
            }
        }

        void DownloadAndInstallOperation.INotify.InstallationStarted()
        {
            mIsPlasticInstalling = true;
        }

        void DownloadAndInstallOperation.INotify.InstallationFinished()
        {
            mIsPlasticInstalling = false;
        }

        bool InstallationFinished()
        {
            return mCancelButton.enabledSelf && IsExeAvailable.ForMode(mIsGluonMode);
        }

        void UpdateButtonsStatuses()
        {
            if (!string.IsNullOrEmpty(mProgressData.StatusMessage))
            {
                mCancelButton.SetEnabled(true);
                mCancelButton.text = PlasticLocalization.Name.CloseButton.GetString();
                mDownloadButton.Collapse();
                return;
            }

            if (IsExeAvailable.ForMode(mIsGluonMode))
            {
                mCancelButton.SetEnabled(true);
                return;
            }

            mDownloadButton.SetEnabled(false);
            mCancelButton.SetEnabled(false);
        }

        static string GetMessageFromProgressData(ProgressControlsForDialogs.Data data)
        {
            if (!string.IsNullOrEmpty(data.StatusMessage))
            {
                return data.StatusMessage;
            }
            else
            {
                if (data.ProgressPercent >= 0)
                    return string.Format("{0} ({1}%)", data.ProgressMessage, (int)(data.ProgressPercent * 100));
                else
                    return data.ProgressMessage;
            }
        }

        void Dispose()
        {
            mDownloadButton.clicked -= DownloadButton_Clicked;
            mCancelButton.clicked -= CancelButton_Clicked;
        }

        void BuildComponents()
        {
            VisualElement root = rootVisualElement;
            root.Clear();

            InitializeLayoutAndStyles();

            mMessageLabel = root.Q<Label>("title");
            mConfirmMessageLabel = root.Q<Label>("message");
            mDownloadButton = root.Q<Button>("download");
            mCancelButton = root.Q<Button>("cancel");
            mProgressControlsContainer = root.Q<VisualElement>("progressControlsContainer");

            mMessageLabel.text = PlasticLocalization.Name.InstallUnityVersionControl.GetString();
            mConfirmMessageLabel.text = PlasticLocalization.Name.InstallConfirmationMessage.GetString();
            mDownloadButton.text = PlasticLocalization.Name.YesButton.GetString();
            mDownloadButton.clicked += DownloadButton_Clicked;
            mCancelButton.text = PlasticLocalization.Name.NoButton.GetString();
            mCancelButton.clicked += CancelButton_Clicked;

            mProgressControls = new ProgressControlsForDialogs(
                new VisualElement[] {
                    mDownloadButton,
                    mCancelButton
                });

            mProgressControlsContainer.Add(mProgressControls);
        }

        void InitializeLayoutAndStyles()
        {
            rootVisualElement.LoadLayout(typeof(DownloadPlasticExeDialog).Name);
            rootVisualElement.LoadStyle(typeof(DownloadPlasticExeDialog).Name);
        }

        string mTitle;

        Label mMessageLabel;
        Label mConfirmMessageLabel;
        Label mProgressLabel;
        Button mDownloadButton;
        Button mCancelButton;
        ProgressControlsForDialogs mProgressControls;
        VisualElement mProgressControlsContainer;

        RepositorySpec mRepSpec;
        string mInstallCloudFrom;
        string mInstallEnterpriseFrom;
        string mCancelInstallFrom;
        string mInstallerFile;
        bool mIsCloudEdition;
        bool mIsGluonMode;
        bool mIsPlasticInstalling;
        ProgressControlsForDialogs.Data mProgressData;

        const float DIALOG_WIDTH = 500;
        const float DIALOG_HEIGHT = 250;
        const float REDUCED_DIALOG_HEIGHT = 125;
    }
}