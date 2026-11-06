#if UNITY_EDITOR && !ENABLE_PICO_OPENXR_SDK
using System;
using System.Collections.Generic;
using System.IO;
using ByteDance.PICO.SecureMR;
using UnityEditor;
using UnityEngine;

namespace ByteDance.PICO.SecureMR.Editor
{
    public static class SpatialMLPipelineZooImporterCli
    {
        public const string SourceArgument = "-spatialMLPackageSource";
        public const string DestinationArgument = "-spatialMLDestinationRoot";
        public const string OverwritePolicyArgument = "-spatialMLOverwritePolicy";
        public const string ResultPrefix = "SPATIALML_PIPELINE_ZOO_IMPORT_RESULT:";

        public static void Import()
        {
            ImportFromArguments(Environment.GetCommandLineArgs());
        }

        internal static SpatialMLPipelineZooAsset ImportFromArguments(string[] arguments)
        {
            ImportOptions options = null;
            try
            {
                options = ParseArguments(arguments);
                var packageAsset = SpatialMLPipelineZooImporter.ImportFromFolder(
                    options.SourcePath,
                    options.DestinationRoot,
                    options.OverwritePolicy);
                var packageAssetPath =
                    SpatialMLPipelineZooImporter.VerifyImportedPackage(
                        packageAsset,
                        options.SourcePath);

                AssetDatabase.SaveAssets();
                AssetDatabase.Refresh();

                LogResult(new ImportResult
                {
                    status = "installed",
                    sourcePath = options.SourcePath,
                    destinationRoot = options.DestinationRoot,
                    packageId = packageAsset.packageId,
                    packageAssetPath = packageAssetPath,
                    pipelineAssetCount = packageAsset.pipelineJsonAssets.Count,
                    binaryAssetCount = packageAsset.binaryAssets.Count
                });
                return packageAsset;
            }
            catch (Exception exception)
            {
                LogResult(new ImportResult
                {
                    status = "failed",
                    sourcePath = options?.SourcePath,
                    destinationRoot = options?.DestinationRoot,
                    error = exception.Message
                }, true);
                throw;
            }
        }

        internal static ImportOptions ParseArguments(string[] arguments)
        {
            var values = ParseNamedArguments(arguments);
            var sourcePath = RequiredValue(values, SourceArgument);
            var destinationRoot = RequiredValue(values, DestinationArgument);
            var overwritePolicyValue = RequiredValue(values, OverwritePolicyArgument);

            sourcePath = Path.GetFullPath(sourcePath);
            if (!Directory.Exists(sourcePath))
            {
                throw new DirectoryNotFoundException(
                    $"SpatialML package source folder does not exist: {sourcePath}");
            }

            destinationRoot = NormalizeAssetPath(destinationRoot);
            if (!destinationRoot.Equals("Assets", StringComparison.OrdinalIgnoreCase) &&
                !destinationRoot.StartsWith("Assets/", StringComparison.OrdinalIgnoreCase))
            {
                throw new ArgumentException(
                    "SpatialML destination root must be inside the Unity project's Assets folder.",
                    DestinationArgument);
            }

            destinationRoot = destinationRoot.Length == "Assets".Length
                ? "Assets"
                : "Assets/" + destinationRoot.Substring("Assets/".Length);

            if (!Enum.TryParse(
                    overwritePolicyValue,
                    true,
                    out SpatialMLPipelineZooOverwritePolicy overwritePolicy) ||
                overwritePolicy == SpatialMLPipelineZooOverwritePolicy.Prompt)
            {
                throw new ArgumentException(
                    $"SpatialML overwrite policy must be 'fail' or 'replace', not '{overwritePolicyValue}'.",
                    OverwritePolicyArgument);
            }

            return new ImportOptions
            {
                SourcePath = sourcePath,
                DestinationRoot = destinationRoot,
                OverwritePolicy = overwritePolicy
            };
        }

        private static Dictionary<string, string> ParseNamedArguments(string[] arguments)
        {
            var values = new Dictionary<string, string>(StringComparer.OrdinalIgnoreCase);
            for (var index = 0; index < (arguments?.Length ?? 0); index++)
            {
                var argument = arguments[index];
                if (string.IsNullOrEmpty(argument) || argument[0] != '-')
                {
                    continue;
                }

                var equalsIndex = argument.IndexOf('=');
                if (equalsIndex > 0)
                {
                    values[argument.Substring(0, equalsIndex)] =
                        argument.Substring(equalsIndex + 1);
                    continue;
                }

                if (index + 1 < arguments.Length &&
                    !string.IsNullOrEmpty(arguments[index + 1]) &&
                    arguments[index + 1][0] != '-')
                {
                    values[argument] = arguments[++index];
                }
            }

            return values;
        }

        private static string RequiredValue(
            IReadOnlyDictionary<string, string> values,
            string argumentName)
        {
            if (!values.TryGetValue(argumentName, out var value) ||
                string.IsNullOrWhiteSpace(value))
            {
                throw new ArgumentException(
                    $"Missing required command-line argument {argumentName}.",
                    argumentName);
            }

            return value.Trim();
        }

        private static string NormalizeAssetPath(string path)
        {
            return path.Replace('\\', '/').TrimEnd('/');
        }

        private static void LogResult(ImportResult result, bool isError = false)
        {
            var message = ResultPrefix + JsonUtility.ToJson(result);
            if (isError)
            {
                Debug.LogError(message);
            }
            else
            {
                Debug.Log(message);
            }
        }

        internal sealed class ImportOptions
        {
            public string SourcePath { get; set; }
            public string DestinationRoot { get; set; }
            public SpatialMLPipelineZooOverwritePolicy OverwritePolicy { get; set; }
        }

        [Serializable]
        private sealed class ImportResult
        {
            public string status;
            public string sourcePath;
            public string destinationRoot;
            public string packageId;
            public string packageAssetPath;
            public int pipelineAssetCount;
            public int binaryAssetCount;
            public string error;
        }
    }
}
#endif
