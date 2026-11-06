#if UNITY_EDITOR && !ENABLE_PICO_OPENXR_SDK
using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Compression;
using System.Linq;
using System.Net;
using ByteDance.PICO.SecureMR;
using UnityEditor;
using UnityEngine;

namespace ByteDance.PICO.SecureMR.Editor
{
    internal enum SpatialMLPipelineZooOverwritePolicy
    {
        Prompt,
        Fail,
        Replace
    }

    public sealed class SpatialMLPipelineZooImporterWindow : EditorWindow
    {
        private const string DefaultUrl = "https://huggingface.co/picoxr/face-mediapipe-pipeline/resolve/main/face-mediapipe-pipeline.zip?download=true";
        private string packageUrl = DefaultUrl;
        private string destinationRoot = "Assets/SpatialMLPipelineZoo";

        [MenuItem("PICO/SpatialML/Import SpatialML Pipeline Zoo Package")]
        public static void Open()
        {
            GetWindow<SpatialMLPipelineZooImporterWindow>("SpatialML Pipeline Zoo");
        }

        private void OnGUI()
        {
            EditorGUILayout.LabelField("Import a SpatialML pipeline zoo package", EditorStyles.boldLabel);
            packageUrl = EditorGUILayout.TextField("HuggingFace zip URL", packageUrl);
            destinationRoot = EditorGUILayout.TextField("Destination Root", destinationRoot);

            using (new EditorGUILayout.HorizontalScope())
            {
                if (GUILayout.Button("Download and Import"))
                {
                    var asset = SpatialMLPipelineZooImporter.ImportFromUrl(packageUrl, destinationRoot);
                    Selection.activeObject = asset;
                }

                if (GUILayout.Button("Import Local Zip/Folder"))
                {
                    var choice = EditorUtility.DisplayDialogComplex(
                        "Import SpatialML Package",
                        "Choose a local zip file or a folder containing manifest.json.",
                        "Zip File",
                        "Cancel",
                        "Folder");

                    SpatialMLPipelineZooAsset asset = null;
                    if (choice == 0)
                    {
                        var zipPath = EditorUtility.OpenFilePanel("SpatialML pipeline package zip", string.Empty, "zip");
                        if (!string.IsNullOrEmpty(zipPath))
                        {
                            asset = SpatialMLPipelineZooImporter.ImportFromZip(zipPath, destinationRoot);
                        }
                    }
                    else if (choice == 2)
                    {
                        var folderPath = EditorUtility.OpenFolderPanel("SpatialML pipeline package folder", string.Empty, string.Empty);
                        if (!string.IsNullOrEmpty(folderPath))
                        {
                            asset = SpatialMLPipelineZooImporter.ImportFromFolder(folderPath, destinationRoot);
                        }
                    }

                    if (asset != null)
                    {
                        Selection.activeObject = asset;
                    }
                }
            }
        }
    }

    public static class SpatialMLPipelineZooImporter
    {
        public static SpatialMLPipelineZooAsset ImportFromUrl(string url, string destinationRoot)
        {
            var tempZip = Path.Combine(Path.GetTempPath(), $"spatialml_pipeline_{Guid.NewGuid():N}.zip");
            try
            {
                using (var client = new WebClient()) client.DownloadFile(url, tempZip);
                return ImportFromZip(tempZip, destinationRoot);
            }
            finally
            {
                if (File.Exists(tempZip)) File.Delete(tempZip);
            }
        }

        public static SpatialMLPipelineZooAsset ImportFromZip(string zipPath, string destinationRoot)
        {
            var tempDir = Path.Combine(Path.GetTempPath(), $"spatialml_pipeline_{Guid.NewGuid():N}");
            Directory.CreateDirectory(tempDir);
            try
            {
                ZipFile.ExtractToDirectory(zipPath, tempDir);
                var packageRoot = FindPackageRoot(tempDir);
                return ImportFromFolder(packageRoot, destinationRoot);
            }
            finally
            {
                if (Directory.Exists(tempDir)) Directory.Delete(tempDir, true);
            }
        }

        public static SpatialMLPipelineZooAsset ImportFromFolder(string packageFolder, string destinationRoot)
        {
            return ImportFromFolder(
                packageFolder,
                destinationRoot,
                SpatialMLPipelineZooOverwritePolicy.Prompt);
        }

        internal static SpatialMLPipelineZooAsset ImportFromFolder(
            string packageFolder,
            string destinationRoot,
            SpatialMLPipelineZooOverwritePolicy overwritePolicy)
        {
            // Validate the entire package before inspecting or replacing the destination.
            var validatedPackage = SpatialMLPipelineZooPackageValidator.Validate(packageFolder);
            var packageName = SanitizePackageName(validatedPackage.PackageId);
            var assetFolder = CombineAssetPath(destinationRoot, packageName);
            var absoluteAssetFolder = Path.GetFullPath(ToAbsolutePath(assetFolder));
            EnsurePathUnderAssets(absoluteAssetFolder, "Resolved import destination is outside the Unity project's Assets folder.");

            if (Directory.Exists(absoluteAssetFolder))
            {
                switch (overwritePolicy)
                {
                    case SpatialMLPipelineZooOverwritePolicy.Prompt:
                        if (!EditorUtility.DisplayDialog(
                                "SpatialML Import",
                                $"Folder already exists and will be replaced:\n{assetFolder}\n\nContinue?",
                                "Replace",
                                "Cancel"))
                        {
                            throw new OperationCanceledException("Import cancelled by user.");
                        }
                        break;
                    case SpatialMLPipelineZooOverwritePolicy.Fail:
                        throw new IOException(
                            $"SpatialML package destination already exists: {assetFolder}");
                    case SpatialMLPipelineZooOverwritePolicy.Replace:
                        break;
                    default:
                        throw new ArgumentOutOfRangeException(
                            nameof(overwritePolicy),
                            overwritePolicy,
                            "Unsupported SpatialML package overwrite policy.");
                }

                if (!AssetDatabase.DeleteAsset(assetFolder) && Directory.Exists(absoluteAssetFolder))
                {
                    Directory.Delete(absoluteAssetFolder, true);
                }
            }

            Directory.CreateDirectory(absoluteAssetFolder);

            var copied = new Dictionary<string, string>();
            foreach (var file in validatedPackage.Files)
            {
                var targetRelative = file.IsBinary ? file.PackagePath + ".bytes" : file.PackagePath;
                var targetAssetPath = CombineAssetPath(assetFolder, targetRelative);
                var targetPath = Path.GetFullPath(ToAbsolutePath(targetAssetPath));
                EnsurePathUnderDirectory(
                    targetPath,
                    absoluteAssetFolder,
                    $"Blocked path traversal attempt: '{file.PackagePath}'.");
                Directory.CreateDirectory(Path.GetDirectoryName(targetPath));
                File.Copy(file.SourcePath, targetPath, true);
                copied[file.PackagePath] = targetAssetPath;
            }

            AssetDatabase.Refresh();

            var packageAsset = ScriptableObject.CreateInstance<SpatialMLPipelineZooAsset>();
            packageAsset.packageId = validatedPackage.PackageId;
            packageAsset.manifestJson = AssetDatabase.LoadAssetAtPath<TextAsset>(copied["manifest.json"]);

            foreach (var pipeline in validatedPackage.Pipelines)
            {
                var jsonPath = copied[pipeline.Path];
                packageAsset.pipelineJsonAssets.Add(new SpatialMLPipelineZooAsset.PipelineJsonAsset
                {
                    id = pipeline.Id,
                    packagePath = pipeline.Path,
                    json = AssetDatabase.LoadAssetAtPath<TextAsset>(jsonPath)
                });
            }

            foreach (var file in validatedPackage.Files.Where(item => item.IsBinary))
            {
                packageAsset.binaryAssets.Add(new SpatialMLPipelineZooAsset.BinaryAsset
                {
                    packagePath = file.PackagePath,
                    asset = AssetDatabase.LoadAssetAtPath<TextAsset>(copied[file.PackagePath])
                });
            }

            var packageAssetPath = CombineAssetPath(assetFolder, packageName + ".asset");
            AssetDatabase.CreateAsset(packageAsset, packageAssetPath);
            EditorUtility.SetDirty(packageAsset);
            AssetDatabase.SaveAssets();
            AssetDatabase.Refresh();
            Debug.Log($"Imported SpatialML pipeline zoo package '{packageName}' to {assetFolder}");
            return packageAsset;
        }

        internal static string VerifyImportedPackage(
            SpatialMLPipelineZooAsset packageAsset,
            string packageFolder)
        {
            if (packageAsset == null)
            {
                throw new InvalidDataException(
                    "SpatialML package import did not create a SpatialMLPipelineZooAsset.");
            }

            var packageAssetPath = AssetDatabase.GetAssetPath(packageAsset);
            if (string.IsNullOrEmpty(packageAssetPath) ||
                AssetDatabase.LoadAssetAtPath<SpatialMLPipelineZooAsset>(packageAssetPath) == null)
            {
                throw new InvalidDataException(
                    "SpatialML package import did not persist its SpatialMLPipelineZooAsset.");
            }

            if (packageAsset.manifestJson == null)
            {
                throw new InvalidDataException(
                    "Imported SpatialMLPipelineZooAsset does not reference manifest.json.");
            }

            foreach (var pipeline in packageAsset.pipelineJsonAssets)
            {
                if (pipeline == null || pipeline.json == null)
                {
                    throw new InvalidDataException(
                        "Imported SpatialMLPipelineZooAsset contains a missing pipeline JSON asset.");
                }
            }

            var importedBinaryPaths = new HashSet<string>(
                packageAsset.binaryAssets
                    .Where(item => item != null && !string.IsNullOrEmpty(item.packagePath))
                    .Select(item => NormalizePath(item.packagePath)),
                StringComparer.Ordinal);

            foreach (var binary in packageAsset.binaryAssets)
            {
                if (binary == null || binary.asset == null)
                {
                    throw new InvalidDataException(
                        "Imported SpatialMLPipelineZooAsset contains a missing binary asset.");
                }

                var binaryAssetPath = AssetDatabase.GetAssetPath(binary.asset);
                if (string.IsNullOrEmpty(binaryAssetPath) ||
                    !binaryAssetPath.EndsWith(".bytes", StringComparison.OrdinalIgnoreCase) ||
                    !File.Exists(ToAbsolutePath(binaryAssetPath)))
                {
                    throw new InvalidDataException(
                        $"Imported binary asset '{binary.packagePath}' was not generated as a .bytes file.");
                }
            }

            foreach (var file in Directory.GetFiles(packageFolder, "*", SearchOption.AllDirectories))
            {
                if (ShouldSkip(file))
                {
                    continue;
                }

                var relativePath = NormalizePath(Path.GetRelativePath(packageFolder, file));
                if (NeedsBytesExtension(relativePath) &&
                    !importedBinaryPaths.Contains(relativePath))
                {
                    throw new InvalidDataException(
                        $"Imported SpatialMLPipelineZooAsset is missing binary asset '{relativePath}'.");
                }
            }

            return packageAssetPath;
        }

        private static string FindPackageRoot(string extractedRoot)
        {
            if (File.Exists(Path.Combine(extractedRoot, "manifest.json"))) return extractedRoot;
            foreach (var dir in Directory.GetDirectories(extractedRoot))
            {
                if (Path.GetFileName(dir) == "__MACOSX") continue;
                if (File.Exists(Path.Combine(dir, "manifest.json"))) return dir;
            }
            throw new FileNotFoundException("No manifest.json found in extracted package.");
        }

        private static bool ShouldSkip(string file)
        {
            var normalized = NormalizePath(file);
            return normalized.Contains("/__MACOSX/") || Path.GetFileName(file).StartsWith("._") || Path.GetFileName(file) == ".DS_Store";
        }

        private static bool NeedsBytesExtension(string relativePath)
        {
            var ext = Path.GetExtension(relativePath).ToLowerInvariant();
            return ext != ".json" && ext != ".txt" && ext != ".js";
        }

        private static string SanitizePackageName(string rawPackageName)
        {
            var invalidCharacters = Path.GetInvalidFileNameChars();
            var packageName = new string(rawPackageName.Select(c =>
                c == '/' || c == '\\' || c == ':' || invalidCharacters.Contains(c) ? '_' : c).ToArray()).Trim();

            if (string.IsNullOrEmpty(packageName) || packageName == "." || packageName == ".." || packageName.Contains(".."))
            {
                throw new InvalidDataException($"Invalid package id '{rawPackageName}'.");
            }

            return packageName;
        }

        private static bool IsSafeRelativePath(string relativePath)
        {
            if (string.IsNullOrEmpty(relativePath) || Path.IsPathRooted(relativePath)) return false;

            var segments = NormalizePath(relativePath).Split('/');
            return segments.All(segment => !string.IsNullOrEmpty(segment) && segment != "." && segment != "..");
        }

        private static void EnsurePathUnderAssets(string absolutePath, string message)
        {
            var assetsRoot = Path.GetFullPath(Path.Combine(Directory.GetCurrentDirectory(), "Assets"));
            EnsurePathUnderDirectory(absolutePath, assetsRoot, message);
        }

        private static void EnsurePathUnderDirectory(string absolutePath, string absoluteRoot, string message)
        {
            var fullPath = Path.GetFullPath(absolutePath);
            var fullRoot = Path.GetFullPath(absoluteRoot);
            var rootWithSeparator = fullRoot.TrimEnd(Path.DirectorySeparatorChar, Path.AltDirectorySeparatorChar) + Path.DirectorySeparatorChar;
            if (!fullPath.Equals(fullRoot, StringComparison.OrdinalIgnoreCase) &&
                !fullPath.StartsWith(rootWithSeparator, StringComparison.OrdinalIgnoreCase))
            {
                throw new InvalidDataException(message);
            }
        }

        private static string CombineAssetPath(string left, string right) => NormalizePath(left.TrimEnd('/') + "/" + right.TrimStart('/'));
        private static string NormalizePath(string path) => path.Replace('\\', '/');
        private static string ToAbsolutePath(string assetPath) => Path.GetFullPath(Path.Combine(Directory.GetCurrentDirectory(), assetPath));

    }
}
#endif
