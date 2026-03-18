using System.IO;

using UnityEditor;

using Codice.Client.Common;
using Codice.Utils;
using Unity.PlasticSCM.Editor.Tool;
using Unity.PlasticSCM.Editor.Views;

namespace Unity.PlasticSCM.Editor
{
    internal static class UnityConfigurationChecker
    {
        internal static void SynchronizeUnityEditionToken()
        {
            string plasticClientBinDir = PlasticInstallPath.GetClientBinDir();

            if (!string.IsNullOrEmpty(plasticClientBinDir) && !IsPlasticInstalling())
                SetupUnityEditionToken.FromPlasticInstallation(plasticClientBinDir);
        }

        internal static bool NeedsConfiguration()
        {
            SynchronizeUnityEditionToken();
            
            if (ConfigurationChecker.NeedConfiguration())
                return true;

            if (ClientConfig.Get().GetClientConfigData().WorkingMode == "SSOWorkingMode" &&
                !CmConnection.Get().IsAnyTokenConfigured())
                return true;

            return false;
        }
        
        static bool IsPlasticInstalling()
        {
            if (!EditorWindow.HasOpenInstances<DownloadPlasticExeDialog>())
                return false;
       
            DownloadPlasticExeDialog window = EditorWindow.
                GetWindow<DownloadPlasticExeDialog>(null,false);
            if (window == null)
                return false;

            return window.IsPlasticInstalling;
        }
    }
    // The plugin rely on the "cloudedition.token" to be created in the "plastic4e config folder, instead of checking
    // the one in the UVCS installation directory, since it can run without an existing installation.
    internal static class SetupUnityEditionToken
    {
        // When called from the Hub; if the UVCS installation directory is found, synchronize the token file from it.
        // Else, create the "cloudedition.token" file unconditionally so it's treated as a Cloud Edition going forward.
        internal static void CreateCloudEditionTokenIfNeeded()
        {
            string plasticClientBinDir = PlasticInstallPath.GetClientBinDir();

            if (!string.IsNullOrEmpty(plasticClientBinDir))
            {
                FromPlasticInstallation(plasticClientBinDir);
                return;
            }

            string tokenFilePath = UserConfigFolder.GetConfigFile(EditionToken.CLOUD_EDITION_FILE_NAME);

            if (!File.Exists(tokenFilePath))
                File.Create(tokenFilePath).Dispose();
        }

        // Synchronize the "cloudedition.token" file between the installation directory and the "plastic4" config folder
        internal static void FromPlasticInstallation(string plasticClientBinDir)
        {
            bool isCloudPlasticInstall = IsPlasticInstallOfEdition(
                plasticClientBinDir,
                EditionToken.CLOUD_EDITION_FILE_NAME);

            bool isDvcsPlasticInstall = IsPlasticInstallOfEdition(
                plasticClientBinDir,
                EditionToken.DVCS_EDITION_FILE_NAME);

            SetupTokenFiles(
                isCloudPlasticInstall,
                isDvcsPlasticInstall);
        }

        static void SetupTokenFiles(
            bool isCloudPlasticInstall,
            bool isDvcsPlasticInstall)
        {
            string unityCloudEditionTokenFile = UserConfigFolder.GetConfigFile(
                EditionToken.CLOUD_EDITION_FILE_NAME);

            string unityDvcsEditionTokenFile = UserConfigFolder.GetConfigFile(
                EditionToken.DVCS_EDITION_FILE_NAME);

            CreateOrDeleteTokenFile(isCloudPlasticInstall, unityCloudEditionTokenFile);
            CreateOrDeleteTokenFile(isDvcsPlasticInstall, unityDvcsEditionTokenFile);
        }

        static void CreateOrDeleteTokenFile(bool isEdition, string editionTokenFile)
        {
            if (isEdition && !File.Exists(editionTokenFile))
            {
                File.Create(editionTokenFile).Dispose();

                return;
            }

            if (!isEdition && File.Exists(editionTokenFile))
            {
                File.Delete(editionTokenFile);

                return;
            }
        }

        static bool IsPlasticInstallOfEdition(
            string plasticClientBinDir,
            string editionFileName)
        {
            return File.Exists(Path.Combine(
                plasticClientBinDir,
                editionFileName));
        }
    }
}