using UnityEditor;

namespace Unity.PlasticSCM.Editor
{
    internal static class VCSPlugin
    {
        internal static bool IsEnabled()
        {
            return GetVersionControl() == "PlasticSCM";
        }

        internal static void Disable()
        {
            SetVersionControl("Visible Meta Files");

            AssetDatabase.SaveAssets();
        }

        static string GetVersionControl()
        {
            return VersionControlSettings.mode;
        }

        static void SetVersionControl(string versionControl)
        {
            VersionControlSettings.mode = versionControl;
        }
    }
}
