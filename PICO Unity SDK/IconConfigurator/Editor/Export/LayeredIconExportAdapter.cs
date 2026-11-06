using System;
using System.IO;
using UnityEditor;
using UnityEngine;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    public class LayeredIconExportAdapter : IIconExportAdapter
    {
        private readonly IconSdfGeneratorService m_sdfGeneratorService = new IconSdfGeneratorService();

        public void Apply(IconApplyPayload payload)
        {
            EnsureFolder(IconConfiguratorPaths.RootDirectory);
            EnsureFolder(IconConfiguratorPaths.GeneratedDirectory);
            EnsureFolder(payload.OutputRootPath);
            EnsureFolder(payload.LayersOutputPath);
            EnsureFolder($"{payload.OutputRootPath}/sdf");
            EnsureFolder($"{payload.OutputRootPath}/launcher");
            EnsureFolder(payload.PreviewOutputPath);
            EnsureFolder(payload.MetadataOutputPath);

            for (int i = 0; i < payload.Layers.Count; i++)
            {
                WriteLayerTexture(payload.Layers[i], $"{payload.LayersOutputPath}/{GetLayerFileName(i)}");
                WriteSdfOutput(payload, i, $"{payload.OutputRootPath}/sdf/{GetLayerFileName(i)}");
            }

            if (payload.PreviewTexture != null)
            {
                byte[] previewPngBytes = payload.PreviewTexture.EncodeToPNG();
                File.WriteAllBytes($"{payload.PreviewOutputPath}/preview2d.png", previewPngBytes);
                File.WriteAllBytes($"{payload.OutputRootPath}/launcher/launcher.png", previewPngBytes);
            }

            IconConfigMetadata metadata = new IconConfigMetadata
            {
                ConfigGuid = payload.ConfigGuid,
                GeneratedAt = DateTime.UtcNow.ToString("O"),
                BackgroundPath = payload.Background?.AssetPath,
                Foreground1Path = payload.Foreground1?.AssetPath,
                Foreground2Path = payload.Foreground2?.AssetPath,
                LayerCount = payload.Layers.Count,
            };
            File.WriteAllText(
                $"{payload.MetadataOutputPath}/icon-config.json",
                JsonUtility.ToJson(metadata, true));
        }

        private static string GetLayerFileName(int index)
        {
            return IconLayerNaming.GetPngFileName(index);
        }

        private static void WriteLayerTexture(IconLayerConfig layer, string outputPath)
        {
            if (layer?.Texture == null)
            {
                return;
            }

            File.WriteAllBytes(outputPath, layer.Texture.EncodeToPNG());
        }

        private void WriteSdfTexture(IconLayerConfig layer, string outputPath)
        {
            if (layer?.Texture == null)
            {
                return;
            }

            Texture2D sdfTexture = m_sdfGeneratorService.Generate(layer.Texture);

            if (sdfTexture == null)
            {
                return;
            }

            try
            {
                File.WriteAllBytes(outputPath, sdfTexture.EncodeToPNG());
            }
            finally
            {
                UnityEngine.Object.DestroyImmediate(sdfTexture);
            }
        }

        private void WriteSdfOutput(IconApplyPayload payload, int layerIndex, string outputPath)
        {
            if (payload.UseCloudSdfs)
            {
                IconLayerConfig sdfLayer = layerIndex >= 0 && layerIndex < payload.SdfLayers.Count
                    ? payload.SdfLayers[layerIndex]
                    : null;
                WriteLayerTexture(sdfLayer, outputPath);
                return;
            }

            WriteSdfTexture(payload.Layers[layerIndex], outputPath);
        }

        private static void EnsureFolder(string path)
        {
            if (AssetDatabase.IsValidFolder(path))
            {
                return;
            }

            string parent = path.Substring(0, path.LastIndexOf('/'));
            string folderName = path.Substring(path.LastIndexOf('/') + 1);

            if (!AssetDatabase.IsValidFolder(parent))
            {
                EnsureFolder(parent);
            }

            AssetDatabase.CreateFolder(parent, folderName);
        }

        [Serializable]
        private class IconConfigMetadata
        {
            public string ConfigGuid;
            public string GeneratedAt;
            public string BackgroundPath;
            public string Foreground1Path;
            public string Foreground2Path;
            public int LayerCount;
        }
    }
}
