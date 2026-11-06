using System.IO;
using System.Security;
using System.Text;
using UnityEditor;
using UnityEngine;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    public class AndroidAppNameExportAdapter : IIconExportAdapter
    {
        private readonly IconSdfGeneratorService m_sdfGeneratorService = new IconSdfGeneratorService();

        public void Apply(IconApplyPayload payload)
        {
            EnsureFolder(IconConfiguratorPaths.RootDirectory);
            EnsureFolder(IconConfiguratorPaths.OutputDirectory);
            EnsureFolder(IconConfiguratorPaths.AndroidDirectory);
            EnsureFolder(IconConfiguratorPaths.AndroidOutputDirectory);
            EnsureFolder(IconConfiguratorPaths.AndroidDrawableDirectory);
            EnsureFolder(IconConfiguratorPaths.AndroidMipmapMdpiDirectory);
            EnsureFolder(IconConfiguratorPaths.AndroidValuesDirectory);
            EnsureFolder(IconConfiguratorPaths.AndroidXmlDirectory);
            DeleteObsoletePluginResDirectory();
            DeleteDuplicateAndroidLibraryDirectories();
            EnsureAndroidLibraryScaffolding();
            EnsureFolder(IconConfiguratorPaths.AndroidPluginResDirectory);
            EnsureFolder(IconConfiguratorPaths.AndroidPluginDrawableDirectory);
            EnsureFolder(IconConfiguratorPaths.AndroidPluginMipmapMdpiDirectory);
            EnsureFolder(IconConfiguratorPaths.AndroidPluginValuesDirectory);
            EnsureFolder(IconConfiguratorPaths.AndroidPluginXmlDirectory);

            DeleteStaleLocaleFiles(payload);
            ExportDrawableTextures(payload);
            ExportDrawables3dArray(payload);
            ExportLocalesConfig(payload);

            foreach (LocalizationEntry entry in payload.Localizations)
            {
                string filePath = IconApplyService.GetAndroidStringFilePath(entry.LocaleCode);
                EnsureFolder(Path.GetDirectoryName(filePath)?.Replace("\\", "/"));
                string xml = BuildStringsXml(entry.AppName);
                File.WriteAllText(filePath, xml, Encoding.UTF8);

                string pluginFilePath = ToPluginResourcePath(filePath);
                EnsureFolder(Path.GetDirectoryName(pluginFilePath)?.Replace("\\", "/"));
                File.WriteAllText(pluginFilePath, xml, Encoding.UTF8);
            }
        }

        private static void DeleteObsoletePluginResDirectory()
        {
            if (Directory.Exists(IconConfiguratorPaths.ObsoleteAndroidPluginResDirectory))
            {
                FileUtil.DeleteFileOrDirectory(IconConfiguratorPaths.ObsoleteAndroidPluginResDirectory);
                FileUtil.DeleteFileOrDirectory($"{IconConfiguratorPaths.ObsoleteAndroidPluginResDirectory}.meta");
            }
        }

        private static void DeleteDuplicateAndroidLibraryDirectories()
        {
            if (!Directory.Exists(IconConfiguratorPaths.AndroidPluginsDirectory))
            {
                return;
            }

            string[] duplicateDirectories = Directory.GetDirectories(
                IconConfiguratorPaths.AndroidPluginsDirectory,
                "IconConfigurator *.androidlib",
                SearchOption.TopDirectoryOnly);

            for (int i = 0; i < duplicateDirectories.Length; i++)
            {
                FileUtil.DeleteFileOrDirectory(duplicateDirectories[i].Replace("\\", "/"));
            }

            string[] duplicateMetas = Directory.GetFiles(
                IconConfiguratorPaths.AndroidPluginsDirectory,
                "IconConfigurator *.androidlib.meta",
                SearchOption.TopDirectoryOnly);

            for (int i = 0; i < duplicateMetas.Length; i++)
            {
                FileUtil.DeleteFileOrDirectory(duplicateMetas[i].Replace("\\", "/"));
            }
        }

        private static void EnsureAndroidLibraryScaffolding()
        {
            EnsureFolder(IconConfiguratorPaths.AndroidLibraryDirectory);
            File.WriteAllText(
                IconConfiguratorPaths.AndroidLibraryProjectPropertiesPath,
                "android.library=true\n",
                Encoding.UTF8);
            File.WriteAllText(
                IconConfiguratorPaths.AndroidLibraryManifestPath,
                "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n<manifest xmlns:android=\"http://schemas.android.com/apk/res/android\" package=\"com.iconfeature.iconconfigurator\" />\n",
                Encoding.UTF8);
        }

        private static void DeleteStaleLocaleFiles(IconApplyPayload payload)
        {
            System.Collections.Generic.HashSet<string> desiredPaths =
                new System.Collections.Generic.HashSet<string>(System.StringComparer.OrdinalIgnoreCase);
            for (int i = 0; i < payload.Localizations.Count; i++)
            {
                desiredPaths.Add(IconApplyService.GetAndroidStringFilePath(payload.Localizations[i].LocaleCode).Replace("\\", "/"));
            }

            for (int i = 0; i < IconConfiguratorLocales.CleanupLocales.Count; i++)
            {
                string normalizedPath = IconApplyService.GetAndroidStringFilePath(
                    IconConfiguratorLocales.CleanupLocales[i]).Replace("\\", "/");
                if (!desiredPaths.Contains(normalizedPath) && File.Exists(normalizedPath))
                {
                    DeleteFileAndMeta(normalizedPath);
                }

                string pluginPath = ToPluginResourcePath(normalizedPath);
                if (!desiredPaths.Contains(normalizedPath) && File.Exists(pluginPath))
                {
                    DeleteFileAndMeta(pluginPath);
                }
            }
        }

        private static void DeleteFileAndMeta(string path)
        {
            if (File.Exists(path))
            {
                File.Delete(path);
            }

            string metaPath = $"{path}.meta";
            if (File.Exists(metaPath))
            {
                File.Delete(metaPath);
            }
        }

        private static string BuildStringsXml(string appName)
        {
            string escapedName = SecurityElement.Escape(appName) ?? string.Empty;
            return
$@"<?xml version=""1.0"" encoding=""utf-8""?>
<resources>
    <string name=""{IconConfiguratorAndroidResources.AppName}"">{escapedName}</string>
</resources>
";
        }

        private void ExportDrawableTextures(IconApplyPayload payload)
        {
            for (int i = 0; i < payload.Layers.Count; i++)
            {
                WriteDrawableTexture(payload.Layers[i]?.Texture, GetLayerResourceName(i));
                WriteSdfOutput(payload, i, GetSdfResourceName(i));
            }

            if (payload.PreviewTexture != null)
            {
                WriteMipmapTexture(payload.PreviewTexture, "ic_spatial_launcher");
            }
        }

        private void ExportDrawables3dArray(IconApplyPayload payload)
        {
            StringBuilder builder = new StringBuilder();
            builder.AppendLine(@"<?xml version=""1.0"" encoding=""utf-8""?>");
            builder.AppendLine("<resources>");
            builder.AppendLine(@"    <array name=""icon_3d_list"">");
            for (int i = payload.Layers.Count - 1; i >= 0; i--)
            {
                AppendArrayItemIfPresent(builder, payload.Layers[i]?.Texture, GetLayerResourceName(i));
            }
            builder.AppendLine("    </array>");
            builder.AppendLine(@"    <array name=""icon_sdf_list"">");
            for (int i = payload.Layers.Count - 1; i >= 0; i--)
            {
                AppendArrayItemIfPresent(builder, GetSdfTextureForArray(payload, i), GetSdfResourceName(i));
            }
            builder.AppendLine("    </array>");
            builder.AppendLine("</resources>");

            File.WriteAllText(
                $"{IconConfiguratorPaths.AndroidValuesDirectory}/drawables_3d.xml",
                builder.ToString(),
                Encoding.UTF8);
            File.WriteAllText(
                $"{IconConfiguratorPaths.AndroidPluginValuesDirectory}/drawables_3d.xml",
                builder.ToString(),
                Encoding.UTF8);
        }

        private static void ExportLocalesConfig(IconApplyPayload payload)
        {
            StringBuilder builder = new StringBuilder();
            builder.AppendLine(@"<?xml version=""1.0"" encoding=""utf-8""?>");
            builder.AppendLine(@"<locale-config xmlns:android=""http://schemas.android.com/apk/res/android"">");

            foreach (LocalizationEntry entry in payload.Localizations)
            {
                if (string.IsNullOrWhiteSpace(entry.LocaleCode))
                {
                    continue;
                }

                builder.AppendLine($@"    <locale android:name=""{entry.LocaleCode}"" />");
            }

            builder.AppendLine("</locale-config>");

            File.WriteAllText(
                $"{IconConfiguratorPaths.AndroidXmlDirectory}/locales_config.xml",
                builder.ToString(),
                Encoding.UTF8);
            File.WriteAllText(
                $"{IconConfiguratorPaths.AndroidPluginXmlDirectory}/locales_config.xml",
                builder.ToString(),
                Encoding.UTF8);
        }

        private void WriteSdfTexture(Texture2D texture, string resourceName)
        {
            if (texture == null)
            {
                return;
            }

            Texture2D sdfTexture = m_sdfGeneratorService.Generate(texture);

            if (sdfTexture == null)
            {
                return;
            }

            try
            {
                WriteDrawableTexture(sdfTexture, resourceName);
            }
            finally
            {
                UnityEngine.Object.DestroyImmediate(sdfTexture);
            }
        }

        private void WriteSdfOutput(IconApplyPayload payload, int layerIndex, string resourceName)
        {
            if (payload.UseCloudSdfs)
            {
                Texture2D cloudSdf = layerIndex >= 0 && layerIndex < payload.SdfLayers.Count
                    ? payload.SdfLayers[layerIndex]?.Texture
                    : null;
                WriteDrawableTexture(cloudSdf, resourceName);
                return;
            }

            WriteSdfTexture(payload.Layers[layerIndex]?.Texture, resourceName);
        }

        private static Texture2D GetSdfTextureForArray(IconApplyPayload payload, int layerIndex)
        {
            if (payload.UseCloudSdfs)
            {
                return layerIndex >= 0 && layerIndex < payload.SdfLayers.Count
                    ? payload.SdfLayers[layerIndex]?.Texture
                    : null;
            }

            return payload.Layers[layerIndex]?.Texture;
        }

        private static void WriteDrawableTexture(Texture2D texture, string resourceName)
        {
            if (texture == null)
            {
                return;
            }

            byte[] pngBytes = texture.EncodeToPNG();
            File.WriteAllBytes(
                $"{IconConfiguratorPaths.AndroidDrawableDirectory}/{resourceName}.png",
                pngBytes);
            File.WriteAllBytes(
                $"{IconConfiguratorPaths.AndroidPluginDrawableDirectory}/{resourceName}.png",
                pngBytes);
        }

        private static void WriteMipmapTexture(Texture2D texture, string resourceName)
        {
            if (texture == null)
            {
                return;
            }

            byte[] pngBytes = texture.EncodeToPNG();
            File.WriteAllBytes(
                $"{IconConfiguratorPaths.AndroidMipmapMdpiDirectory}/{resourceName}.png",
                pngBytes);
            File.WriteAllBytes(
                $"{IconConfiguratorPaths.AndroidPluginMipmapMdpiDirectory}/{resourceName}.png",
                pngBytes);
        }

        private static void AppendArrayItemIfPresent(StringBuilder builder, Texture2D texture, string resourceName)
        {
            if (texture == null)
            {
                return;
            }

            builder.AppendLine($@"        <item>@drawable/{resourceName}</item>");
        }

        private static string GetLayerResourceName(int layerIndex)
        {
            return IconLayerNaming.GetAndroidLayerResourceName(layerIndex);
        }

        private static string GetSdfResourceName(int layerIndex)
        {
            return IconLayerNaming.GetAndroidSdfResourceName(layerIndex);
        }

        private static string ToPluginResourcePath(string outputResourcePath)
        {
            string normalizedPath = outputResourcePath.Replace("\\", "/");
            return normalizedPath.Replace(
                IconConfiguratorPaths.AndroidOutputDirectory,
                IconConfiguratorPaths.AndroidPluginResDirectory);
        }

        private static void EnsureFolder(string path)
        {
            if (string.IsNullOrWhiteSpace(path) || AssetDatabase.IsValidFolder(path) || Directory.Exists(path))
            {
                return;
            }

            string normalizedPath = path.Replace("\\", "/");
            if (normalizedPath.StartsWith(IconConfiguratorPaths.AndroidLibraryDirectory + "/", System.StringComparison.OrdinalIgnoreCase))
            {
                Directory.CreateDirectory(normalizedPath);
                return;
            }

            string parent = normalizedPath.Substring(0, normalizedPath.LastIndexOf('/'));
            string folderName = normalizedPath.Substring(normalizedPath.LastIndexOf('/') + 1);

            if (!AssetDatabase.IsValidFolder(parent))
            {
                EnsureFolder(parent);
            }

            AssetDatabase.CreateFolder(parent, folderName);
            if (!Directory.Exists(normalizedPath))
            {
                Directory.CreateDirectory(normalizedPath);
            }
        }
    }
}
