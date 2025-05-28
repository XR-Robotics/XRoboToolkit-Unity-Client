using UnityEditor;
using UnityEngine;
using System.IO;
using System.Diagnostics;
using UnityEditor.Build.Reporting;
using Debug = UnityEngine.Debug;

public class AutoBuilder
{
    // 菜单项路径
    [MenuItem("Build/One-Click Package %#b")]
    public static void BuildAll()
    {
        // 获取当前平台
        BuildTarget target = EditorUserBuildSettings.activeBuildTarget;
        string platformName = target.ToString();

        // 版本号管理
        VersionHandler.IncrementVersion();

        // 构建路径
        string buildPath = GetBuildPath(target);

        // 构建选项
        BuildOptions options = BuildOptions.None;

        // 执行打包
        Build(target, buildPath, options);

        // 打包后操作
        PostBuildActions(buildPath);
    }

    static string GetBuildPath(BuildTarget target)
    {
        string projectName = PlayerSettings.productName;
        string version = PlayerSettings.bundleVersion;

        return target switch
        {
            BuildTarget.Android =>
                $"{Directory.GetParent(Application.dataPath)}/Builds/Android/{projectName}_{version}.apk",
            BuildTarget.StandaloneWindows64 =>
                $"{Directory.GetParent(Application.dataPath)}/Builds/Windows/{projectName}_{version}/",
            BuildTarget.StandaloneOSX =>
                $"{Directory.GetParent(Application.dataPath)}/Builds/macOS/{projectName}_{version}.app",
            BuildTarget.iOS =>
                $"{Directory.GetParent(Application.dataPath)}/Builds/iOS/",
            _ => ""
        };
    }

    static void Build(BuildTarget target, string path, BuildOptions options)
    {
        // 确保目录存在
        Directory.CreateDirectory(Path.GetDirectoryName(path));

        // 获取场景列表
        string[] scenes = new string[EditorBuildSettings.scenes.Length];
        for (int i = 0; i < EditorBuildSettings.scenes.Length; i++)
        {
            scenes[i] = EditorBuildSettings.scenes[i].path;
        }

        // 构建参数
        BuildPlayerOptions buildOptions = new BuildPlayerOptions
        {
            scenes = scenes,
            locationPathName = path,
            target = target,
            options = options
        };

        // 执行构建
        BuildReport report = BuildPipeline.BuildPlayer(buildOptions);
        BuildSummary summary = report.summary;

        if (summary.result == BuildResult.Succeeded)
        {
            EditorUtility.DisplayDialog("构建成功",
                $"版本 {PlayerSettings.bundleVersion}\n" +
                $"路径: {path}", "确定");
        }
        else
        {
            EditorUtility.DisplayDialog("构建失败",
                "错误详情请查看控制台", "确定");
        }
    }

    static void PostBuildActions(string path)
    {
        // 自动打开构建目录（仅限Windows/macOS）
        if (Application.platform == RuntimePlatform.WindowsEditor)
        {
            Process.Start("explorer.exe",
                $"/select,{Path.GetFullPath(path)}");
        }
        else if (Application.platform == RuntimePlatform.OSXEditor)
        {
            Process.Start("open",
                $"-R \"{Path.GetFullPath(path)}\"");
        }
    }

    // 版本号自动递增工具
    private static class VersionHandler
    {
        public static void IncrementVersion()
        {
            string[] versions = PlayerSettings.bundleVersion.Split('.');

            if (versions.Length != 3)
            {
                Debug.LogWarning("版本号格式错误，重置为 1.0.0");
                PlayerSettings.bundleVersion = "1.0.0";
                return;
            }

            try
            {
                int major = int.Parse(versions[0]);
                int minor = int.Parse(versions[1]);
                int build = int.Parse(versions[2]);

                build++;
                if (build > 99)
                {
                    build = 0;
                    minor++;
                }
                if (minor > 9)
                {
                    minor = 0;
                    major++;
                }

                PlayerSettings.bundleVersion = $"{major}.{minor}.{build}";
            }
            catch
            {
                Debug.LogError("版本号解析失败");
            }
        }
    }
}