using UnityEditor;
using UnityEngine;
using UnityEditor.Build.Reporting;
using System.IO;
using UnityEditor.SceneManagement;

public class Build
{
    public static void ExportAndroidProject()
    {
        EnsureSceneExists();
        Debug.Log("Exporting Android Project...");
        
        // Export to a separate build directory, not the source android folder
        string exportPath = "../build/exported_project"; 
        
        // Ensure directory exists (Unity might create it, but good to be safe)
        if (Directory.Exists(exportPath)) {
            // Optional: Clean previous export? Unity usually handles overwrite.
        }

        EditorUserBuildSettings.exportAsGoogleAndroidProject = true;
        
        BuildPlayerOptions buildPlayerOptions = new BuildPlayerOptions();
        buildPlayerOptions.scenes = new[] { "Assets/Scenes/SampleScene.unity" };
        buildPlayerOptions.locationPathName = exportPath;
        buildPlayerOptions.target = BuildTarget.Android;
        buildPlayerOptions.options = BuildOptions.AcceptExternalModificationsToPlayer;

        BuildReport report = BuildPipeline.BuildPlayer(buildPlayerOptions);
        
        if (report.summary.result == BuildResult.Succeeded)
        {
            Debug.Log("Build succeeded: " + report.summary.totalSize + " bytes");
        }
        else if (report.summary.result == BuildResult.Failed)
        {
            Debug.LogError("Build failed");
            if (Application.isBatchMode) EditorApplication.Exit(1);
        }
    }

    public static void BuildAndroidAPK()
    {
       // ... (Keep existing implementation or ignore)
       // We are switching to Export strategy.
        EnsureSceneExists();
        Debug.Log("Building Android APK...");
        string buildPath = "../build/android";
        string apkName = "UnityAndroidMixDemo.apk";
        string fullPath = Path.Combine(buildPath, apkName);
        if (!Directory.Exists(buildPath)) Directory.CreateDirectory(buildPath);
        EditorUserBuildSettings.exportAsGoogleAndroidProject = false; 
        BuildPlayerOptions buildPlayerOptions = new BuildPlayerOptions();
        buildPlayerOptions.scenes = new[] { "Assets/Scenes/SampleScene.unity" };
        buildPlayerOptions.locationPathName = fullPath;
        buildPlayerOptions.target = BuildTarget.Android;
        buildPlayerOptions.options = BuildOptions.None;
        BuildReport report = BuildPipeline.BuildPlayer(buildPlayerOptions);
        if (report.summary.result == BuildResult.Succeeded) Debug.Log("Build succeeded");
        else if (report.summary.result == BuildResult.Failed) { Debug.LogError("Build failed"); if (Application.isBatchMode) EditorApplication.Exit(1); }
    }

    private static void EnsureSceneExists()
    {
        string scenePath = "Assets/Scenes/SampleScene.unity";
        if (!File.Exists(scenePath))
        {
            Debug.Log("SampleScene.unity not found. Creating a new one...");
            Directory.CreateDirectory(Path.GetDirectoryName(scenePath));
            var scene = EditorSceneManager.NewScene(NewSceneSetup.DefaultGameObjects, NewSceneMode.Single);
            EditorSceneManager.SaveScene(scene, scenePath);
            AssetDatabase.ImportAsset(scenePath);
            Debug.Log("Created SampleScene.unity at " + scenePath);
        }
    }
}
