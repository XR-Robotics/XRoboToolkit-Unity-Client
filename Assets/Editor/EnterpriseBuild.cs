using UnityEditor;
using UnityEngine;
using System.IO;
using System.Collections.Generic;
using UnityEditor.Build.Reporting;

/// <summary>
/// CLI-friendly build script for batchmode Android builds.
/// Usage: Unity -batchmode -executeMethod EnterpriseBuild.BuildAndroid outputPath=Builds/Android/app.apk
/// </summary>
public class EnterpriseBuild
{
    public static void BuildAndroid()
    {
        // Parse output path from command-line args
        string outputPath = "Builds/Android/XRoboToolkit-EnterpriseSDK.apk";
        foreach (string arg in System.Environment.GetCommandLineArgs())
        {
            if (arg.StartsWith("outputPath="))
                outputPath = arg.Substring("outputPath=".Length);
        }

        // Use debug signing (no custom keystore) so the build works on any machine
        PlayerSettings.Android.useCustomKeystore = false;

        // Gather enabled scenes
        var scenes = new List<string>();
        foreach (var scene in EditorBuildSettings.scenes)
        {
            if (scene.enabled)
                scenes.Add(scene.path);
        }

        // Ensure output directory exists
        string dir = Path.GetDirectoryName(outputPath);
        if (!string.IsNullOrEmpty(dir))
            Directory.CreateDirectory(dir);

        UnityEngine.Debug.Log($"[EnterpriseBuild] Building {scenes.Count} scene(s) to {outputPath}");

        BuildPlayerOptions options = new BuildPlayerOptions
        {
            scenes = scenes.ToArray(),
            locationPathName = outputPath,
            target = BuildTarget.Android,
            options = BuildOptions.None
        };

        BuildReport report = BuildPipeline.BuildPlayer(options);
        BuildSummary summary = report.summary;

        System.Console.WriteLine($"[EnterpriseBuild] Result: {summary.result}, Size: {summary.totalSize} bytes, Time: {summary.totalTime}");

        if (summary.result != BuildResult.Succeeded)
        {
            System.Console.WriteLine($"[EnterpriseBuild] FAILED — {summary.totalErrors} error(s)");
            EditorApplication.Exit(1);
        }
    }
}
