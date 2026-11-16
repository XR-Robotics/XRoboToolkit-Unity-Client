using System;
using System.IO;
using System.Linq;
using UnityEditor;
using UnityEditor.Build.Reporting;
using UnityEngine;

[InitializeOnLoad]
internal static class AuthorizedEyeDiagnosticsBuild
{
    private const string Version = "1.1.11";
    private static readonly string ProjectRoot = Directory.GetParent(Application.dataPath).FullName;
    private static readonly string RequestPath = Path.Combine(ProjectRoot, "Logs", "eye-diagnostics-build-" + Version + ".request");
    private static readonly string ResultPath = Path.Combine(ProjectRoot, "Logs", "eye-diagnostics-build-" + Version + "-result.json");

    static AuthorizedEyeDiagnosticsBuild()
    {
        EditorApplication.update += TryBuild;
    }

    private static void TryBuild()
    {
        if (!File.Exists(RequestPath) || EditorApplication.isCompiling || EditorApplication.isUpdating ||
            EditorApplication.isPlayingOrWillChangePlaymode || BuildPipeline.isBuildingPlayer)
            return;

        EditorApplication.update -= TryBuild;
        File.Move(RequestPath, RequestPath + ".consumed");
        var result = new BuildResultRecord();
        try
        {
            if (EditorUserBuildSettings.activeBuildTarget != BuildTarget.Android)
                throw new InvalidOperationException("The authorized build requires the active Android target.");

            PlayerSettings.bundleVersion = Version;
            result.version = Version;
            result.apkPath = Path.Combine(ProjectRoot, "Builds", "Android",
                PlayerSettings.productName + "_" + Version + ".apk");
            Debug.Log("[EyeDiagnosticsBuild] Starting Android build: " + result.apkPath);
            var report = BuildPipeline.BuildPlayer(new BuildPlayerOptions
            {
                scenes = EditorBuildSettings.scenes.Where(scene => scene.enabled).Select(scene => scene.path).ToArray(),
                locationPathName = result.apkPath,
                target = BuildTarget.Android,
                options = BuildOptions.None
            });
            result.result = report.summary.result.ToString();
            result.errors = report.summary.totalErrors;
            result.bytes = report.summary.totalSize.ToString();
            result.seconds = report.summary.totalTime.TotalSeconds;
            Debug.Log("[EyeDiagnosticsBuild] Result: " + result.result + ", errors: " + result.errors);
        }
        catch (Exception exception)
        {
            result.result = "Exception";
            result.message = exception.ToString();
            Debug.LogException(exception);
        }
        finally
        {
            File.WriteAllText(ResultPath, JsonUtility.ToJson(result, true));
        }
    }

    [Serializable]
    private sealed class BuildResultRecord
    {
        public string version;
        public string apkPath;
        public string result;
        public int errors;
        public string bytes;
        public double seconds;
        public string message;
    }
}
