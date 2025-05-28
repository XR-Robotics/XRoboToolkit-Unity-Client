using System.IO;
using UnityEditor;
using UnityEngine;
using System.Collections.Generic;

/// <summary>
/// android project build script
/// create by oscar 2015/6/17
/// </summary>
class ProjectBuild : Editor
{
    /// <summary>
    /// Gets the output path from args
    /// </summary>
    /// <value>The output path.</value>
    public static string outputPath
    {
        get
        {
            foreach (string arg in System.Environment.GetCommandLineArgs())
            {
                if (arg.StartsWith("outputPath"))
                {
                    return arg.Split("="[0])[1];
                }
            }

            return @"D:\buildout";
        }
    }

    /// <summary>
    /// Gets the build scenes.
    /// </summary>
    /// <returns>The build scenes.</returns>
    static string[] GetBuildScenes()
    {
        List<string> names = new List<string>();
        foreach (EditorBuildSettingsScene e in EditorBuildSettings.scenes)
        {
            if (e == null)
                continue;
            if (e.enabled)
                names.Add(e.path);
        }

        return names.ToArray();
    }

    /// <summary>
    /// Gets the version from args
    /// </summary>
    /// <value>The version.</value>
    public static string version
    {
        get
        {
            foreach (string arg in System.Environment.GetCommandLineArgs())
            {
                if (arg.StartsWith("version"))
                {
                    return arg.Split("="[0])[1];
                }
            }

            return "1.0.0";
        }
    }

    /// <summary>
    /// Gets the versionCode from args
    /// </summary>
    /// <value>The versionCode.</value>
    public static string versionCode
    {
        get
        {
            foreach (string arg in System.Environment.GetCommandLineArgs())
            {
                if (arg.StartsWith("versionCode"))
                {
                    return arg.Split("="[0])[1];
                }
            }

            return "1";
        }
    }

    /// <summary>
    /// Gets the product name from args
    /// </summary>
    /// <value>The product name.</value>
    public static string productName
    {
        get
        {
            foreach (string arg in System.Environment.GetCommandLineArgs())
            {
                if (arg.StartsWith("productName"))
                {
                    return arg.Split("="[0])[1];
                }
            }

            return "PicoVRUnity";
        }
    }

    /// <summary>
    /// Builds for android.
    /// </summary>
    [MenuItem("Build/Andriod")]
    static void BuildForAndroid()
    {
        RemoveAutoTestScriptingDefineSymbol();
        Build();
    }

    /// <summary>
    /// Builds for android autotest.
    /// </summary>
    [MenuItem("Build/AndriodAutoTest")]
    static void BuildForAndroidAutoTest()
    {
        AddAutoTestScriptingDefineSymbol();
        Build();
    }

    static void Build()
    {
        string path = outputPath;
        PlayerSettings.bundleVersion = version;
        //Console.WriteLine("Hello: " + path.LastIndexOf (".apk"));
        PlayerSettings.Android.bundleVersionCode = int.Parse(versionCode);
        PlayerSettings.productName = productName;
        EditorUserBuildSettings.androidCreateSymbols = AndroidCreateSymbols.Debugging;

        if (path.LastIndexOf(".apk") == -1)
        {
            path = @"../bin/localApp.apk";
        }

        /* EditorUserBuildSettings.androidBuildType = AndroidBuildType.Release;
         EditorUserBuildSettings.androidBuildSystem = AndroidBuildSystem.Gradle;
         AddressableAssetSettings.BuildPlayerContent();
         BuildPipeline.BuildPlayer(GetBuildScenes(), path, BuildTarget.Android, BuildOptions.Development);
         BuildPipeline.BuildPlayer(GetBuildScenes(), path, BuildTarget.Android, BuildOptions.None);
         */
        //首先打cn的
        ReplaceJarByRegion(false);
        string pathDebug = path.Replace(".apk", "-cn-debug.apk");
        BuildPipeline.BuildPlayer(GetBuildScenes(), pathDebug, BuildTarget.Android, BuildOptions.Development);
        string pathRls = path.Replace(".apk", "-cn-release.apk");
        BuildPipeline.BuildPlayer(GetBuildScenes(), pathRls, BuildTarget.Android, BuildOptions.None);

        //再打海外的
        ReplaceJarByRegion(true);
        string pathDebugI18N = path.Replace(".apk", "-i18n-debug.apk");
        BuildPipeline.BuildPlayer(GetBuildScenes(), pathDebugI18N, BuildTarget.Android, BuildOptions.Development);
        string pathRlsI18N = path.Replace(".apk", "-i18n-release.apk");
        BuildPipeline.BuildPlayer(GetBuildScenes(), pathRlsI18N, BuildTarget.Android, BuildOptions.None);
    }

    private const string cnJarPath = "libCopeTmp/cn/robotassistant_lib.aar";
    private const string i18NJarPath = "libCopeTmp/i18n/robotassistant_lib.aar";
    private const string dstUnityJarPath = "Assets/Plugins/Android/robotassistant_lib.aar";

    static void ReplaceJarByRegion(bool isOverSea)
    {
        var projectDir = Directory.GetCurrentDirectory();

        var jarPath = Path.GetFullPath(Path.Combine(projectDir, isOverSea ? i18NJarPath : cnJarPath));
        var dstPath = Path.GetFullPath(Path.Combine(projectDir, dstUnityJarPath));
        if (File.Exists(jarPath))
        {
            Debug.Log($"UnityCI JarPath: {jarPath} dstPath:{dstPath}");
            File.Delete(dstPath);
            File.Copy(jarPath, dstPath);
            AssetDatabase.Refresh();
        }
        else
        {
            Debug.Log($"UnityBuildError:UnityCI JarPath NotFound !!!");
        }
    }

    /// <summary>
    /// Add AutoTest scripting define symbol(Macro) - "AUTOTEST_BUILD"
    /// </summary>
    static void AddAutoTestScriptingDefineSymbol()
    {
        List<string> scriptingDefineSymbolList =
            new(PlayerSettings.GetScriptingDefineSymbolsForGroup(BuildTargetGroup.Android).Split(";"));
        scriptingDefineSymbolList.RemoveAll(s => s == "AUTOTEST_BUILD");
        PlayerSettings.SetScriptingDefineSymbolsForGroup(BuildTargetGroup.Android,
            string.Join(";", scriptingDefineSymbolList) + ";AUTOTEST_BUILD");
    }

    /// <summary>
    /// Remove AutoTest scripting define symbol(Macro) - "AUTOTEST_BUILD"
    /// </summary>
    static void RemoveAutoTestScriptingDefineSymbol()
    {
        List<string> scriptingDefineSymbolList =
            new(PlayerSettings.GetScriptingDefineSymbolsForGroup(BuildTargetGroup.Android).Split(";"));
        scriptingDefineSymbolList.RemoveAll(s => s == "AUTOTEST_BUILD");
        PlayerSettings.SetScriptingDefineSymbolsForGroup(BuildTargetGroup.Android,
            string.Join(";", scriptingDefineSymbolList));
    }
}