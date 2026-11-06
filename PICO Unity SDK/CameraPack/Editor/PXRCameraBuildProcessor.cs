using ByteDance.PICO.CameraPack;
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;
using UnityEngine;

public class PXRCameraBuildProcessor : IPreprocessBuildWithReport
{
    public int callbackOrder => 0;
    public void OnPreprocessBuild(BuildReport report)
    {
        if (report.summary.platformGroup == BuildTargetGroup.Android)
        {
            PluginImporter[] plugins = PluginImporter.GetAllImporters();
            foreach (PluginImporter plugin in plugins)
            {
                if (plugin.assetPath.Contains("PxrCamerakit.aar"))
                {
                    plugin.SetIncludeInBuildDelegate((path) =>
                    {
#if PICO_MS_SDK
                        return false;
#else
                        return true;
#endif
                    });
                }
            }
            
            var issues = CameraProjectValidation.GetValidationIssues();
            if (!issues)
            {
                Debug.LogError($"PICO CameraPack validation failed");
                throw new BuildFailedException($"There are unresolved PICO CameraPack configuration errors");
            }
        }
    }
}
