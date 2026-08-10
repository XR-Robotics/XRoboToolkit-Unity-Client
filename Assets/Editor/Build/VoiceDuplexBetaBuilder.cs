using System;
using System.IO;
using System.Linq;
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;
using UnityEngine;

public static class VoiceDuplexBetaBuilder
{
    private const string DefaultApplicationIdentifier = "com.xrobotoolkit.client.voicebeta";
    private const string DefaultProductName = "XRoboToolkit Voice Beta";
    private const string DefaultVersionName = "1.1.2-beta.11";
    private const int DefaultVersionCode = 12;
    private const int TargetSdkApiLevel = 31;

    [MenuItem("Build/Voice Duplex Beta APK")]
    public static void BuildFromMenu()
    {
        if (EditorUserBuildSettings.activeBuildTarget != BuildTarget.Android)
        {
            bool switched = EditorUserBuildSettings.SwitchActiveBuildTarget(
                BuildTargetGroup.Android,
                BuildTarget.Android
            );
            if (!switched)
            {
                throw new BuildFailedException("Failed to switch the active build target to Android.");
            }
        }

        BuildBatch();
    }

    public static void BuildBatch()
    {
        if (EditorUserBuildSettings.activeBuildTarget != BuildTarget.Android)
        {
            throw new BuildFailedException(
                "Android is not the active build target. Start Unity with -buildTarget Android."
            );
        }

        RemoteVisionAddressStoreSelfTest.Run();
        PicoStreamPerformanceSelfTest.Run();
        RemoteRecordStatusSelfTest.Run();

        string versionName = GetEnvironmentOrDefault(
            "XRBT_BETA_VERSION_NAME",
            DefaultVersionName
        );
        int versionCode = GetPositiveIntEnvironmentOrDefault(
            "XRBT_BETA_VERSION_CODE",
            DefaultVersionCode
        );
        bool developmentBuild = GetBooleanEnvironmentOrDefault(
            "XRBT_BETA_DEVELOPMENT_BUILD",
            false
        );
        string projectRoot = Directory.GetParent(Application.dataPath).FullName;
        string outputPath = GetOutputPath(versionName);
        string[] scenes = EditorBuildSettings.scenes
            .Where(scene => scene.enabled && File.Exists(Path.Combine(projectRoot, scene.path)))
            .Select(scene => scene.path)
            .ToArray();

        if (scenes.Length == 0)
        {
            throw new BuildFailedException("No enabled build scenes were found.");
        }

        string originalApplicationIdentifier = PlayerSettings.GetApplicationIdentifier(
            BuildTargetGroup.Android
        );
        string originalProductName = PlayerSettings.productName;
        string originalVersionName = PlayerSettings.bundleVersion;
        int originalVersionCode = PlayerSettings.Android.bundleVersionCode;
        AndroidArchitecture originalArchitectures = PlayerSettings.Android.targetArchitectures;
        AndroidSdkVersions originalMinSdk = PlayerSettings.Android.minSdkVersion;
        AndroidSdkVersions originalTargetSdk = PlayerSettings.Android.targetSdkVersion;
        ScriptingImplementation originalBackend = PlayerSettings.GetScriptingBackend(
            BuildTargetGroup.Android
        );
        bool originalUseCustomKeystore = PlayerSettings.Android.useCustomKeystore;
        bool originalBuildAppBundle = EditorUserBuildSettings.buildAppBundle;

        try
        {
            PlayerSettings.SetApplicationIdentifier(
                BuildTargetGroup.Android,
                DefaultApplicationIdentifier
            );
            PlayerSettings.productName = DefaultProductName;
            PlayerSettings.bundleVersion = versionName;
            PlayerSettings.Android.bundleVersionCode = versionCode;
            PlayerSettings.Android.targetArchitectures = AndroidArchitecture.ARM64;
            PlayerSettings.Android.minSdkVersion = AndroidSdkVersions.AndroidApiLevel30;
            PlayerSettings.Android.targetSdkVersion = (AndroidSdkVersions)TargetSdkApiLevel;
            PlayerSettings.SetScriptingBackend(
                BuildTargetGroup.Android,
                ScriptingImplementation.IL2CPP
            );
            PlayerSettings.Android.useCustomKeystore = false;
            EditorUserBuildSettings.buildAppBundle = false;

            Directory.CreateDirectory(Path.GetDirectoryName(outputPath));
            BuildReport report = BuildPipeline.BuildPlayer(
                new BuildPlayerOptions
                {
                    scenes = scenes,
                    locationPathName = outputPath,
                    target = BuildTarget.Android,
                    options = developmentBuild ? BuildOptions.Development : BuildOptions.None,
                }
            );

            if (report.summary.result != BuildResult.Succeeded)
            {
                throw new BuildFailedException(
                    $"Voice duplex beta APK build failed: {report.summary.result}"
                );
            }

            Debug.Log(
                $"VOICE_DUPLEX_BETA_APK={outputPath} development_build={developmentBuild}"
            );
        }
        finally
        {
            PlayerSettings.SetApplicationIdentifier(
                BuildTargetGroup.Android,
                originalApplicationIdentifier
            );
            PlayerSettings.productName = originalProductName;
            PlayerSettings.bundleVersion = originalVersionName;
            PlayerSettings.Android.bundleVersionCode = originalVersionCode;
            PlayerSettings.Android.targetArchitectures = originalArchitectures;
            PlayerSettings.Android.minSdkVersion = originalMinSdk;
            PlayerSettings.Android.targetSdkVersion = originalTargetSdk;
            PlayerSettings.SetScriptingBackend(BuildTargetGroup.Android, originalBackend);
            PlayerSettings.Android.useCustomKeystore = originalUseCustomKeystore;
            EditorUserBuildSettings.buildAppBundle = originalBuildAppBundle;
            AssetDatabase.SaveAssets();
        }
    }

    private static string GetOutputPath(string versionName)
    {
        string configuredPath = Environment.GetEnvironmentVariable("XRBT_BETA_APK_PATH");
        string path = string.IsNullOrWhiteSpace(configuredPath)
            ? Path.Combine(
                Directory.GetParent(Application.dataPath).FullName,
                "Builds",
                "Android",
                $"XRoboToolkit_VoiceBeta_{versionName}.apk"
            )
            : configuredPath;
        return Path.GetFullPath(path);
    }

    private static string GetEnvironmentOrDefault(string name, string fallback)
    {
        string value = Environment.GetEnvironmentVariable(name);
        return string.IsNullOrWhiteSpace(value) ? fallback : value.Trim();
    }

    private static int GetPositiveIntEnvironmentOrDefault(string name, int fallback)
    {
        string value = Environment.GetEnvironmentVariable(name);
        if (string.IsNullOrWhiteSpace(value))
        {
            return fallback;
        }

        if (!int.TryParse(value, out int parsed) || parsed <= 0)
        {
            throw new BuildFailedException($"{name} must be a positive integer.");
        }

        return parsed;
    }

    private static bool GetBooleanEnvironmentOrDefault(string name, bool fallback)
    {
        string value = Environment.GetEnvironmentVariable(name);
        if (string.IsNullOrWhiteSpace(value))
        {
            return fallback;
        }

        switch (value.Trim().ToLowerInvariant())
        {
            case "1":
            case "true":
            case "yes":
            case "on":
                return true;
            case "0":
            case "false":
            case "no":
            case "off":
                return false;
            default:
                throw new BuildFailedException(
                    $"{name} must be one of: 1, 0, true, false, yes, no, on, off."
                );
        }
    }
}
