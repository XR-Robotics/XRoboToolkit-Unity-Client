using System;
using System.Collections.Generic;
using System.IO;
using UnityEditor;
using UnityEngine;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    public class IconApplyService
    {
        private readonly IconConfiguratorValidator m_validator;
        private readonly IconCompositePreviewService m_compositePreviewService;
        private readonly List<IIconExportAdapter> m_exportAdapters;

        public IconApplyService(
            IconConfiguratorValidator validator,
            IconCompositePreviewService compositePreviewService,
            List<IIconExportAdapter> exportAdapters)
        {
            m_validator = validator;
            m_compositePreviewService = compositePreviewService;
            m_exportAdapters = exportAdapters ?? new List<IIconExportAdapter>();
        }

        public IconApplyPayload CreatePayload(IconConfiguratorConfigAsset config, string configGuid)
        {
            return CreatePayload(config, configGuid, true);
        }

        public IconApplyPayload CreatePayload(
            IconConfiguratorConfigAsset config,
            string configGuid,
            bool includePreviewTexture)
        {
            string outputRootPath = $"{IconConfiguratorPaths.GeneratedDirectory}/{configGuid}";
            List<IconLayerConfig> layers = GetActiveLayers(config);
            List<IconLayerConfig> sdfLayers = GetActiveSdfLayers(config);
            IconLayerConfig background = layers.Count > 0 ? layers[0] : null;
            IconLayerConfig foreground1 = layers.Count > 1 ? layers[1] : null;
            IconLayerConfig foreground2 = layers.Count > 2 ? layers[2] : null;
            Texture2D previewTexture = includePreviewTexture && m_compositePreviewService != null
                ? CreatePreviewTexture(layers)
                : null;

            return new IconApplyPayload
            {
                ConfigGuid = configGuid,
                OutputRootPath = outputRootPath,
                LayersOutputPath = $"{outputRootPath}/layers",
                PreviewOutputPath = $"{outputRootPath}/preview",
                MetadataOutputPath = $"{outputRootPath}/metadata",
                AndroidResRootPath = IconConfiguratorPaths.AndroidOutputDirectory,
                Localizations = new List<LocalizationEntry>(config.Localizations),
                Layers = layers,
                SdfLayers = sdfLayers,
                UseCloudSdfs = config.LastMode == IconConfiguratorMode.AiSplit,
                Background = background,
                Foreground1 = foreground1,
                Foreground2 = foreground2,
                PreviewTexture = previewTexture,
            };
        }

        public IconApplyPreflightResult CreatePreflight(
            IconConfiguratorConfigAsset config,
            string configGuid,
            IEnumerable<string> existingPathsOverride = null)
        {
            IconConfiguratorValidationResult validationResult = m_validator.Validate(config);
            if (!validationResult.CanApply)
            {
                throw new InvalidOperationException("Icon Configurator state is not valid for apply.");
            }

            IconApplyPayload payload = CreatePayload(config, configGuid, false);
            HashSet<string> existingPaths = BuildExistingPathSet(existingPathsOverride);
            List<string> plannedWritePaths = CollectPlannedWritePaths(payload);
            List<string> deletePaths = CollectStaleLocalePaths(payload, existingPaths);
            deletePaths.AddRange(CollectAndroidPluginCleanupPaths(existingPaths));
            List<string> overwritePaths = new List<string>();

            for (int i = 0; i < plannedWritePaths.Count; i++)
            {
                if (existingPaths.Contains(plannedWritePaths[i]))
                {
                    overwritePaths.Add(plannedWritePaths[i]);
                }
            }

            return new IconApplyPreflightResult
            {
                PlannedWritePaths = plannedWritePaths,
                OverwritePaths = overwritePaths,
                DeletePaths = deletePaths,
            };
        }

        public IconApplyResult Apply(IconConfiguratorConfigAsset config, string configGuid)
        {
            IconApplyPreflightResult preflight = CreatePreflight(config, configGuid);
            IconApplyPayload payload = CreatePayload(config, configGuid);
            IconApplyResult result = new IconApplyResult
            {
                OverwrittenPaths = new List<string>(preflight.OverwritePaths),
                DeletedPaths = new List<string>(preflight.DeletePaths),
            };

            try
            {
                DeletePaths(preflight.DeletePaths);

                foreach (IIconExportAdapter adapter in m_exportAdapters)
                {
                    adapter.Apply(payload);
                }
            }
            finally
            {
                if (payload.PreviewTexture != null)
                {
                    UnityEngine.Object.DestroyImmediate(payload.PreviewTexture);
                }
            }

            AssetDatabase.Refresh();
            result.WrittenPaths = preflight.PlannedWritePaths;
            return result;
        }

        public static string GetAndroidStringFilePath(string localeCode)
        {
            return IconConfiguratorLocales.GetAndroidStringFilePath(localeCode);
        }

        public static string GetLayerOutputFilePath(int layerIndex)
        {
            string fileName = IconLayerNaming.GetPngFileName(layerIndex);

            return $"{IconConfiguratorPaths.GeneratedDirectory}/{{configGuid}}/layers/{fileName}";
        }

        private Texture2D CreatePreviewTexture(List<IconLayerConfig> layers)
        {
            List<Texture2D> layerTextures = new List<Texture2D>();
            for (int i = 0; i < layers.Count; i++)
            {
                if (layers[i]?.Texture != null)
                {
                    layerTextures.Add(layers[i].Texture);
                }
            }

            return m_compositePreviewService.ComposePreview(layerTextures, 256);
        }

        private static List<IconLayerConfig> GetActiveLayers(IconConfiguratorConfigAsset config)
        {
            if (config.LastMode == IconConfiguratorMode.AiSplit)
            {
                config.AiSplit.EnsureDynamicResultLists();
                return new List<IconLayerConfig>(config.AiSplit.GeneratedLayers);
            }

            return config.Manual?.Layers != null
                ? new List<IconLayerConfig>(config.Manual.Layers)
                : new List<IconLayerConfig>();
        }

        private static List<IconLayerConfig> GetActiveSdfLayers(IconConfiguratorConfigAsset config)
        {
            if (config.LastMode != IconConfiguratorMode.AiSplit)
            {
                return new List<IconLayerConfig>();
            }

            config.AiSplit.EnsureDynamicResultLists();
            return new List<IconLayerConfig>(config.AiSplit.GeneratedSdfs);
        }

        private static List<string> CollectPlannedWritePaths(IconApplyPayload payload)
        {
            List<string> plannedPaths = new List<string>();

            for (int i = 0; i < payload.Layers.Count; i++)
            {
                if (payload.Layers[i] == null)
                {
                    continue;
                }

                plannedPaths.Add(GetConcreteLayerOutputPath(payload, i));
                plannedPaths.Add($"{payload.OutputRootPath}/sdf/{GetLayerFileName(i)}");
                plannedPaths.Add(GetAndroidDrawableLayerPath(i));
                plannedPaths.Add(GetAndroidDrawableSdfPath(i));
                plannedPaths.Add(GetAndroidPluginDrawableLayerPath(i));
                plannedPaths.Add(GetAndroidPluginDrawableSdfPath(i));
            }

            plannedPaths.Add($"{payload.PreviewOutputPath}/preview2d.png");
            plannedPaths.Add($"{payload.OutputRootPath}/launcher/launcher.png");
            plannedPaths.Add($"{payload.MetadataOutputPath}/icon-config.json");
            plannedPaths.Add($"{IconConfiguratorPaths.AndroidMipmapMdpiDirectory}/ic_spatial_launcher.png");
            plannedPaths.Add($"{IconConfiguratorPaths.AndroidValuesDirectory}/drawables_3d.xml");
            plannedPaths.Add($"{IconConfiguratorPaths.AndroidXmlDirectory}/locales_config.xml");
            plannedPaths.Add($"{IconConfiguratorPaths.AndroidPluginMipmapMdpiDirectory}/ic_spatial_launcher.png");
            plannedPaths.Add($"{IconConfiguratorPaths.AndroidPluginValuesDirectory}/drawables_3d.xml");
            plannedPaths.Add($"{IconConfiguratorPaths.AndroidPluginXmlDirectory}/locales_config.xml");
            plannedPaths.Add(IconConfiguratorPaths.AndroidManifestPath);
            plannedPaths.Add(IconConfiguratorPaths.AndroidLauncherManifestPath);

            for (int i = 0; i < payload.Localizations.Count; i++)
            {
                plannedPaths.Add(GetAndroidStringFilePath(payload.Localizations[i].LocaleCode));
                plannedPaths.Add(ToPluginResourcePath(GetAndroidStringFilePath(payload.Localizations[i].LocaleCode)));
            }

            return plannedPaths;
        }

        private static List<string> CollectStaleLocalePaths(IconApplyPayload payload, HashSet<string> existingPaths)
        {
            HashSet<string> desiredLocalePaths = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
            for (int i = 0; i < payload.Localizations.Count; i++)
            {
                string outputPath = GetAndroidStringFilePath(payload.Localizations[i].LocaleCode);
                desiredLocalePaths.Add(NormalizePath(outputPath));
                desiredLocalePaths.Add(NormalizePath(ToPluginResourcePath(outputPath)));
            }

            List<string> stalePaths = new List<string>();
            for (int i = 0; i < IconConfiguratorLocales.CleanupLocales.Count; i++)
            {
                string candidatePath = GetAndroidStringFilePath(IconConfiguratorLocales.CleanupLocales[i]);
                AddStaleLocalePathIfNeeded(candidatePath, desiredLocalePaths, existingPaths, stalePaths);
                AddStaleLocalePathIfNeeded(ToPluginResourcePath(candidatePath), desiredLocalePaths, existingPaths, stalePaths);
            }

            return stalePaths;
        }

        private static void AddStaleLocalePathIfNeeded(
            string path,
            HashSet<string> desiredLocalePaths,
            HashSet<string> existingPaths,
            List<string> stalePaths)
        {
            string normalizedPath = NormalizePath(path);
            if (desiredLocalePaths.Contains(normalizedPath))
            {
                return;
            }

            if (existingPaths.Contains(normalizedPath))
            {
                stalePaths.Add(path);
            }

            string metaPath = $"{path}.meta";
            if (existingPaths.Contains(NormalizePath(metaPath)))
            {
                stalePaths.Add(metaPath);
            }
        }

        private static HashSet<string> BuildExistingPathSet(IEnumerable<string> existingPathsOverride)
        {
            HashSet<string> existingPaths = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
            if (existingPathsOverride != null)
            {
                foreach (string path in existingPathsOverride)
                {
                    existingPaths.Add(NormalizePath(path));
                }

                return existingPaths;
            }

            AddExistingEntries($"{IconConfiguratorPaths.GeneratedDirectory}", existingPaths);
            AddExistingEntries($"{IconConfiguratorPaths.AndroidOutputDirectory}", existingPaths);
            AddExistingEntries($"{IconConfiguratorPaths.AndroidPluginResDirectory}", existingPaths);
            AddExistingEntries($"{IconConfiguratorPaths.AndroidPluginsDirectory}", existingPaths);
            return existingPaths;
        }

        private static void AddExistingEntries(string rootPath, HashSet<string> existingPaths)
        {
            string systemPath = Path.GetFullPath(rootPath);
            if (!Directory.Exists(systemPath))
            {
                return;
            }

            AddExistingPath(systemPath, existingPaths);
            string[] directories = Directory.GetDirectories(systemPath, "*", SearchOption.AllDirectories);
            for (int i = 0; i < directories.Length; i++)
            {
                AddExistingPath(directories[i], existingPaths);
            }

            string[] files = Directory.GetFiles(systemPath, "*", SearchOption.AllDirectories);
            for (int i = 0; i < files.Length; i++)
            {
                AddExistingPath(files[i], existingPaths);
            }
        }

        private static void AddExistingPath(string path, HashSet<string> existingPaths)
        {
            string assetRelativePath = path.Replace("\\", "/");
            int assetsIndex = assetRelativePath.IndexOf("/Assets/", StringComparison.OrdinalIgnoreCase);
            if (assetsIndex >= 0)
            {
                assetRelativePath = assetRelativePath.Substring(assetsIndex + 1);
            }
            else if (assetRelativePath.StartsWith("Assets/", StringComparison.OrdinalIgnoreCase))
            {
                // Keep relative asset path.
            }
            else
            {
                string projectRoot = NormalizePath(Path.GetFullPath("."));
                string normalizedPath = NormalizePath(Path.GetFullPath(path));
                if (normalizedPath.StartsWith(projectRoot + "/", StringComparison.OrdinalIgnoreCase))
                {
                    assetRelativePath = normalizedPath.Substring(projectRoot.Length + 1);
                }
            }

            existingPaths.Add(NormalizePath(assetRelativePath));
        }

        private static string GetConcreteLayerOutputPath(IconApplyPayload payload, int layerIndex)
        {
            return $"{payload.LayersOutputPath}/{GetLayerFileName(layerIndex)}";
        }

        private static string GetLayerFileName(int layerIndex)
        {
            return IconLayerNaming.GetPngFileName(layerIndex);
        }

        private static string GetAndroidDrawableLayerPath(int layerIndex)
        {
            return $"{IconConfiguratorPaths.AndroidDrawableDirectory}/{IconLayerNaming.GetAndroidLayerResourceName(layerIndex)}.png";
        }

        private static string GetAndroidDrawableSdfPath(int layerIndex)
        {
            return $"{IconConfiguratorPaths.AndroidDrawableDirectory}/{IconLayerNaming.GetAndroidSdfResourceName(layerIndex)}.png";
        }

        private static string GetAndroidPluginDrawableLayerPath(int layerIndex)
        {
            return $"{IconConfiguratorPaths.AndroidPluginDrawableDirectory}/{IconLayerNaming.GetAndroidLayerResourceName(layerIndex)}.png";
        }

        private static string GetAndroidPluginDrawableSdfPath(int layerIndex)
        {
            return $"{IconConfiguratorPaths.AndroidPluginDrawableDirectory}/{IconLayerNaming.GetAndroidSdfResourceName(layerIndex)}.png";
        }

        private static string ToPluginResourcePath(string outputResourcePath)
        {
            string normalizedPath = outputResourcePath.Replace("\\", "/");
            return normalizedPath.Replace(
                IconConfiguratorPaths.AndroidOutputDirectory,
                IconConfiguratorPaths.AndroidPluginResDirectory);
        }

        private static List<string> CollectAndroidPluginCleanupPaths(HashSet<string> existingPaths)
        {
            List<string> cleanupPaths = new List<string>();
            HashSet<string> addedPaths = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
            AddCleanupPathIfPresent(
                IconConfiguratorPaths.ObsoleteAndroidPluginResDirectory,
                existingPaths,
                cleanupPaths,
                addedPaths);
            AddCleanupPathIfPresent(
                $"{IconConfiguratorPaths.ObsoleteAndroidPluginResDirectory}.meta",
                existingPaths,
                cleanupPaths,
                addedPaths);

            string duplicatePrefix = $"{IconConfiguratorPaths.AndroidPluginsDirectory}/IconConfigurator ";
            foreach (string existingPath in existingPaths)
            {
                string normalizedPath = NormalizePath(existingPath);
                if (!normalizedPath.StartsWith(duplicatePrefix, StringComparison.OrdinalIgnoreCase))
                {
                    continue;
                }

                string duplicateRoot = GetDuplicateAndroidLibraryRoot(normalizedPath, duplicatePrefix);
                if (string.IsNullOrEmpty(duplicateRoot))
                {
                    continue;
                }

                AddUniqueDeletePath(duplicateRoot, cleanupPaths, addedPaths);
                AddCleanupPathIfPresent($"{duplicateRoot}.meta", existingPaths, cleanupPaths, addedPaths);
            }

            return cleanupPaths;
        }

        private static void AddCleanupPathIfPresent(
            string path,
            HashSet<string> existingPaths,
            List<string> cleanupPaths,
            HashSet<string> addedPaths)
        {
            string normalizedPath = NormalizePath(path);
            foreach (string existingPath in existingPaths)
            {
                string normalizedExistingPath = NormalizePath(existingPath);
                if (string.Equals(normalizedExistingPath, normalizedPath, StringComparison.OrdinalIgnoreCase)
                    || normalizedExistingPath.StartsWith(normalizedPath + "/", StringComparison.OrdinalIgnoreCase))
                {
                    AddUniqueDeletePath(path, cleanupPaths, addedPaths);
                    return;
                }
            }
        }

        private static void AddUniqueDeletePath(
            string path,
            List<string> cleanupPaths,
            HashSet<string> addedPaths)
        {
            if (addedPaths.Add(NormalizePath(path)))
            {
                cleanupPaths.Add(path);
            }
        }

        private static string GetDuplicateAndroidLibraryRoot(string path, string duplicatePrefix)
        {
            int suffixIndex = path.IndexOf(".androidlib", duplicatePrefix.Length, StringComparison.OrdinalIgnoreCase);
            if (suffixIndex < 0)
            {
                return string.Empty;
            }

            return path.Substring(0, suffixIndex + ".androidlib".Length);
        }

        private static void DeletePaths(List<string> paths)
        {
            for (int i = 0; i < paths.Count; i++)
            {
                string normalizedPath = NormalizePath(paths[i]);
                if (Directory.Exists(normalizedPath))
                {
                    FileUtil.DeleteFileOrDirectory(normalizedPath);
                    DeleteMetaFileIfExists(normalizedPath);
                    continue;
                }

                if (File.Exists(normalizedPath))
                {
                    File.Delete(normalizedPath);
                    DeleteMetaFileIfExists(normalizedPath);
                    continue;
                }

                if (Directory.Exists(paths[i]))
                {
                    FileUtil.DeleteFileOrDirectory(paths[i]);
                    DeleteMetaFileIfExists(paths[i]);
                    continue;
                }

                if (File.Exists(paths[i]))
                {
                    File.Delete(paths[i]);
                    DeleteMetaFileIfExists(paths[i]);
                }
            }
        }

        private static void DeleteMetaFileIfExists(string path)
        {
            string metaPath = $"{path}.meta";
            if (File.Exists(metaPath))
            {
                File.Delete(metaPath);
            }
        }

        private static string NormalizePath(string path)
        {
            return string.IsNullOrWhiteSpace(path)
                ? string.Empty
                : path.Replace("\\", "/");
        }
    }
}
