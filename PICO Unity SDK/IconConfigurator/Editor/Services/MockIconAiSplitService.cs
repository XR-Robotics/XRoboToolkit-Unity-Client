using System;
using System.IO;
using UnityEditor;
using UnityEngine;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    public class MockIconAiSplitService : IIconAiSplitService
    {
        private const float k_ProgressStep = 0.1f;
        private const double k_ThrottleIntervalSeconds = 0.1;

        private Action<float> m_onProgress;
        private Action<IconAiSplitResult, string, string> m_onSuccess;
        private Action<string> m_onError;
        private IconLayerConfig m_sourceLayer;
        private string m_configGuid;
        private float m_progress;
        private double m_lastProgressTime;
        private float m_lastReportedProgress;

        public bool IsRunning { get; private set; }

        public void StartGenerate(
            IconLayerConfig sourceLayer,
            string configGuid,
            Action<float> onProgress,
            Action<IconAiSplitResult, string, string> onSuccess,
            Action<string> onError)
        {
            if (IsRunning)
            {
                return;
            }

            if (sourceLayer?.Texture == null)
            {
                onError?.Invoke("Flat source is missing.");
                return;
            }

            m_sourceLayer = sourceLayer;
            m_configGuid = configGuid;
            m_onProgress = onProgress;
            m_onSuccess = onSuccess;
            m_onError = onError;
            m_progress = 0f;
            IsRunning = true;

            EditorApplication.update += HandleEditorUpdate;
        }

        public void Cancel()
        {
            if (!IsRunning)
            {
                return;
            }

            CompleteInternal();
        }

        private void HandleEditorUpdate()
        {
            m_progress += k_ProgressStep;
            float clampedProgress = Mathf.Clamp01(m_progress);

            double now = EditorApplication.timeSinceStartup;
            bool shouldReport = (now - m_lastProgressTime >= k_ThrottleIntervalSeconds)
                                || clampedProgress >= 1f;

            if (shouldReport && clampedProgress != m_lastReportedProgress)
            {
                m_lastProgressTime = now;
                m_lastReportedProgress = clampedProgress;
                m_onProgress?.Invoke(clampedProgress);
            }

            if (m_progress < 1f)
            {
                return;
            }

            try
            {
                IconAiSplitResult result = GenerateMockResult();
                string requestId = Guid.NewGuid().ToString("N");
                string generatedAt = DateTime.UtcNow.ToString("O");
                m_onSuccess?.Invoke(result, requestId, generatedAt);
            }
            catch (Exception exception)
            {
                m_onError?.Invoke(exception.Message);
            }
            finally
            {
                CompleteInternal();
            }
        }

        private IconAiSplitResult GenerateMockResult()
        {
            EnsureFolder(IconConfiguratorPaths.RootDirectory);
            EnsureFolder(IconConfiguratorPaths.GeneratedDirectory);

            string outputRoot = $"{IconConfiguratorPaths.GeneratedDirectory}/{m_configGuid}/layers";
            EnsureFolder($"{IconConfiguratorPaths.GeneratedDirectory}/{m_configGuid}");
            EnsureFolder(outputRoot);

            Texture2D backgroundTexture = CreateTintedCopy(m_sourceLayer.Texture, new Color(0.75f, 0.75f, 0.75f, 1f), 0.85f);
            Texture2D foreground1Texture = CreateTintedCopy(m_sourceLayer.Texture, Color.white, 1f);
            Texture2D foreground2Texture = CreateTintedCopy(m_sourceLayer.Texture, new Color(1f, 1f, 1f, 0.55f), 0.55f);

            IconAiSplitResult result = new IconAiSplitResult
            {
                Background = WriteTexture(outputRoot, "background.png", IconLayerKind.Background, backgroundTexture),
                Foreground1 = WriteTexture(outputRoot, "foreground1.png", IconLayerKind.Foreground1, foreground1Texture),
                Foreground2 = WriteTexture(outputRoot, "foreground2.png", IconLayerKind.Foreground2, foreground2Texture),
            };

            UnityEngine.Object.DestroyImmediate(backgroundTexture);
            UnityEngine.Object.DestroyImmediate(foreground1Texture);
            UnityEngine.Object.DestroyImmediate(foreground2Texture);

            return result;
        }

        private static IconLayerConfig WriteTexture(
            string outputRoot,
            string fileName,
            IconLayerKind layerKind,
            Texture2D texture)
        {
            string assetPath = $"{outputRoot}/{fileName}";
            File.WriteAllBytes(assetPath, texture.EncodeToPNG());
            AssetDatabase.ImportAsset(assetPath, ImportAssetOptions.ForceSynchronousImport);

            TextureImporter importer = AssetImporter.GetAtPath(assetPath) as TextureImporter;

            if (importer != null)
            {
                importer.isReadable = true;
                importer.alphaIsTransparency = true;
                importer.textureCompression = TextureImporterCompression.Uncompressed;
                importer.mipmapEnabled = false;
                importer.SaveAndReimport();
            }

            Texture2D importedTexture = AssetDatabase.LoadAssetAtPath<Texture2D>(assetPath);

            return new IconLayerConfig
            {
                LayerKind = layerKind,
                AssetGuid = AssetDatabase.AssetPathToGUID(assetPath),
                AssetPath = assetPath,
                OriginalFileName = fileName,
                Texture = importedTexture,
            };
        }

        private static Texture2D CreateTintedCopy(Texture2D source, Color tint, float alphaMultiplier)
        {
            Texture2D output = new Texture2D(source.width, source.height, TextureFormat.RGBA32, false);
            Color[] sourcePixels = source.GetPixels();
            Color[] outputPixels = new Color[sourcePixels.Length];

            for (int i = 0; i < sourcePixels.Length; i++)
            {
                Color pixel = sourcePixels[i];
                outputPixels[i] = new Color(
                    pixel.r * tint.r,
                    pixel.g * tint.g,
                    pixel.b * tint.b,
                    pixel.a * alphaMultiplier * tint.a);
            }

            output.SetPixels(outputPixels);
            output.Apply();
            return output;
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

        private void CompleteInternal()
        {
            EditorApplication.update -= HandleEditorUpdate;
            IsRunning = false;
            m_sourceLayer = null;
            m_configGuid = null;
            m_onProgress = null;
            m_onSuccess = null;
            m_onError = null;
            m_progress = 0f;
            m_lastProgressTime = 0;
            m_lastReportedProgress = 0f;
        }
    }
}
