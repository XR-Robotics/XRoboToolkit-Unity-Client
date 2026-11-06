using System.IO;
using NUnit.Framework;
using UnityEditor;
using UnityEngine;

namespace ByteDance.PICO.IconConfigurator.Editor.Tests
{
    public class IconConfiguratorImportServiceTests
    {
        [TearDown]
        public void TearDown()
        {
            DeleteImportedAsset("Assets/IconConfigurator/Imported/background_");
            DeleteImportedAsset("Assets/IconConfigurator/Imported/foreground1_");
            AssetDatabase.Refresh();
        }

        [Test]
        public void TryImportLayer_WhenPngIsNonSquare_NormalizesToSquareTexture()
        {
            string sourcePath = CreatePngFile(600, 300, new Color(1f, 0f, 0f, 1f), "icon-configurator-import-normalize.png");
            IconConfiguratorImportService service = new IconConfiguratorImportService();

            try
            {
                bool imported = service.TryImportLayer(
                    sourcePath,
                    IconLayerKind.Foreground1,
                    out IconLayerConfig layer,
                    out string errorMessage);

                Assert.That(imported, Is.True, errorMessage);
                Assert.That(layer, Is.Not.Null);
                Assert.That(layer.Texture, Is.Not.Null);
                Assert.That(layer.Texture.width, Is.EqualTo(1024));
                Assert.That(layer.Texture.height, Is.EqualTo(1024));
            }
            finally
            {
                File.Delete(sourcePath);
            }
        }

        [TestCase("jpg")]
        [TestCase("jpeg")]
        public void TryImportLayer_WhenAiFlatSourceUsesJpegExtension_ImportsAndNormalizesToPngAsset(string extension)
        {
            string sourcePath = CreateJpegFile(300, 600, new Color(0f, 0.5f, 1f, 1f), $"icon-configurator-import-flat-source.{extension}");
            IconConfiguratorImportService service = new IconConfiguratorImportService();

            try
            {
                bool imported = service.TryImportLayer(
                    sourcePath,
                    IconLayerKind.FlatSource,
                    out IconLayerConfig layer,
                    out string errorMessage);

                Assert.That(imported, Is.True, errorMessage);
                Assert.That(layer, Is.Not.Null);
                Assert.That(layer.AssetPath, Does.EndWith(".png"));
                Assert.That(layer.Texture.width, Is.EqualTo(1024));
                Assert.That(layer.Texture.height, Is.EqualTo(1024));
            }
            finally
            {
                File.Delete(sourcePath);
            }
        }

        [Test]
        public void TryImportLayer_WhenExtensionIsUnsupported_ReturnsSupportedFormatMessage()
        {
            string sourcePath = Path.Combine(Path.GetTempPath(), "icon-configurator-import-source.bmp");
            File.WriteAllBytes(sourcePath, new byte[] { 1, 2, 3 });
            IconConfiguratorImportService service = new IconConfiguratorImportService();

            try
            {
                bool imported = service.TryImportLayer(
                    sourcePath,
                    IconLayerKind.FlatSource,
                    out IconLayerConfig layer,
                    out string errorMessage);

                Assert.That(imported, Is.False);
                Assert.That(layer, Is.Null);
                Assert.That(errorMessage, Does.Contain("PNG, JPG, JPEG, or WEBP"));
            }
            finally
            {
                File.Delete(sourcePath);
            }
        }

        [Test]
        public void TryImportLayer_WhenBackgroundHasNoOpaquePixels_ReturnsError()
        {
            string sourcePath = CreateTransparentPngFile(256, 256, "icon-configurator-import-transparent.png");
            IconConfiguratorImportService service = new IconConfiguratorImportService();

            try
            {
                bool imported = service.TryImportLayer(
                    sourcePath,
                    IconLayerKind.Background,
                    out IconLayerConfig layer,
                    out string errorMessage);

                Assert.That(imported, Is.False);
                Assert.That(layer, Is.Null);
                Assert.That(errorMessage, Does.Contain("opaque"));
            }
            finally
            {
                File.Delete(sourcePath);
            }
        }

        private static string CreatePngFile(int width, int height, Color color, string fileName)
        {
            string filePath = Path.Combine(Path.GetTempPath(), fileName);
            Texture2D texture = new Texture2D(width, height, TextureFormat.RGBA32, false);
            Color transparent = new Color(0f, 0f, 0f, 0f);

            for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < width; x++)
                {
                    bool filled = x > width / 4 && x < (width * 3) / 4 && y > height / 4 && y < (height * 3) / 4;
                    texture.SetPixel(x, y, filled ? color : transparent);
                }
            }

            texture.Apply();
            File.WriteAllBytes(filePath, texture.EncodeToPNG());
            Object.DestroyImmediate(texture);
            return filePath;
        }

        private static string CreateJpegFile(int width, int height, Color color, string fileName)
        {
            string filePath = Path.Combine(Path.GetTempPath(), fileName);
            Texture2D texture = new Texture2D(width, height, TextureFormat.RGBA32, false);

            for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < width; x++)
                {
                    texture.SetPixel(x, y, color);
                }
            }

            texture.Apply();
            File.WriteAllBytes(filePath, texture.EncodeToJPG());
            Object.DestroyImmediate(texture);
            return filePath;
        }

        private static string CreateTransparentPngFile(int width, int height, string fileName)
        {
            string filePath = Path.Combine(Path.GetTempPath(), fileName);
            Texture2D texture = new Texture2D(width, height, TextureFormat.RGBA32, false);
            Color[] pixels = new Color[width * height];
            for (int i = 0; i < pixels.Length; i++)
            {
                pixels[i] = Color.clear;
            }

            texture.SetPixels(pixels);
            texture.Apply();
            File.WriteAllBytes(filePath, texture.EncodeToPNG());
            Object.DestroyImmediate(texture);
            return filePath;
        }

        private static void DeleteImportedAsset(string assetPrefix)
        {
            string[] assetGuids = AssetDatabase.FindAssets("t:Texture2D", new[] { "Assets/IconConfigurator/Imported" });
            for (int i = 0; i < assetGuids.Length; i++)
            {
                string assetPath = AssetDatabase.GUIDToAssetPath(assetGuids[i]);
                if (assetPath.StartsWith(assetPrefix))
                {
                    AssetDatabase.DeleteAsset(assetPath);
                }
            }
        }
    }
}
