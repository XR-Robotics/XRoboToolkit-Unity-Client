using System;
using System.IO;
using System.Security.Cryptography;
using UnityEditor;
using UnityEngine;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    public class IconConfiguratorImportService
    {
        private const string k_OutputExtension = ".png";
        private const string k_SupportedFormatText = "PNG, JPG, JPEG, or WEBP";

        public static string[] GetSupportedImageFileFilters()
        {
            return new[] { "Image files", "png,jpg,jpeg,webp" };
        }

        public IconLayerConfig ImportLayerFromDialog(IconLayerKind layerKind)
        {
            string sourcePath = EditorUtility.OpenFilePanelWithFilters(
                $"Select {layerKind} image",
                string.Empty,
                GetSupportedImageFileFilters());

            if (string.IsNullOrWhiteSpace(sourcePath))
            {
                return null;
            }

            return ImportLayer(sourcePath, layerKind);
        }

        public bool TryImportLayer(string sourcePath, IconLayerKind layerKind, out IconLayerConfig importedLayer, out string errorMessage)
        {
            importedLayer = null;
            errorMessage = string.Empty;

            if (string.IsNullOrWhiteSpace(sourcePath))
            {
                errorMessage = "File path is empty.";
                return false;
            }

            if (!File.Exists(sourcePath))
            {
                errorMessage = "File does not exist.";
                return false;
            }

            string extension = Path.GetExtension(sourcePath).ToLowerInvariant();
            if (!IsSupportedImageExtension(extension))
            {
                errorMessage = $"Only {k_SupportedFormatText} files are supported.";
                return false;
            }

            try
            {
                IconLayerConfig layer = ImportLayer(sourcePath, layerKind);
                if (layer?.Texture == null)
                {
                    errorMessage = "Failed to import texture.";
                    return false;
                }

                if (layerKind == IconLayerKind.Background && !HasOpaqueContent(layer.Texture))
                {
                    if (!string.IsNullOrWhiteSpace(layer.AssetPath))
                    {
                        AssetDatabase.DeleteAsset(layer.AssetPath);
                    }

                    errorMessage = "Background layer must contain opaque pixels.";
                    return false;
                }

                importedLayer = layer;
                return true;
            }
            catch (Exception exception)
            {
                errorMessage = exception.Message;
                return false;
            }
        }

        public IconLayerConfig ImportLayer(string sourcePath, IconLayerKind layerKind)
        {
            EnsureFolder(IconConfiguratorPaths.RootDirectory);
            EnsureFolder(IconConfiguratorPaths.ImportedDirectory);

            byte[] sourceBytes = File.ReadAllBytes(sourcePath);
            string extension = Path.GetExtension(sourcePath).ToLowerInvariant();
            if (!IsSupportedImageExtension(extension))
            {
                throw new InvalidOperationException($"Only {k_SupportedFormatText} files are supported.");
            }

            if (sourceBytes == null || sourceBytes.Length < 100 || !IsValidImage(sourceBytes, extension))
            {
                throw new InvalidOperationException($"The file is not a valid {extension.ToUpper().Substring(1)} image or is corrupted (truncated).");
            }

            Texture2D sourceTexture = LoadSourceTexture(sourcePath, sourceBytes, extension);

            Texture2D normalizedTexture = IconTextureUtility.NormalizeToSquare(sourceTexture);
            byte[] normalizedBytes = normalizedTexture.EncodeToPNG();
            string hash = ComputeHash(normalizedBytes);

            string fileName = $"{layerKind.ToString().ToLowerInvariant()}_{hash.Substring(0, 8)}{k_OutputExtension}";
            string assetPath = $"{IconConfiguratorPaths.ImportedDirectory}/{fileName}";

            if (!File.Exists(assetPath))
            {
                File.WriteAllBytes(assetPath, normalizedBytes);
                AssetDatabase.ImportAsset(assetPath, ImportAssetOptions.ForceSynchronousImport);
            }

            ConfigureTextureImporter(assetPath);

            Texture2D texture = AssetDatabase.LoadAssetAtPath<Texture2D>(assetPath);
            UnityEngine.Object.DestroyImmediate(normalizedTexture);
            UnityEngine.Object.DestroyImmediate(sourceTexture);

            return new IconLayerConfig
            {
                LayerKind = layerKind,
                AssetGuid = AssetDatabase.AssetPathToGUID(assetPath),
                AssetPath = assetPath,
                OriginalFileName = Path.GetFileName(sourcePath),
                ContentHash = hash,
                DisplayName = Path.GetFileNameWithoutExtension(sourcePath),
                SourceWidth = texture != null ? texture.width : 0,
                SourceHeight = texture != null ? texture.height : 0,
                Texture = texture,
            };
        }

        private static bool HasOpaqueContent(Texture2D texture)
        {
            if (texture == null)
            {
                return false;
            }

            Color[] pixels = texture.GetPixels();
            for (int i = 0; i < pixels.Length; i++)
            {
                if (pixels[i].a > 0.99f)
                {
                    return true;
                }
            }

            return false;
        }

        private static bool IsSupportedImageExtension(string extension)
        {
            return extension == ".png"
                || extension == ".jpg"
                || extension == ".jpeg"
                || extension == ".webp";
        }

        private static bool IsValidImage(byte[] bytes, string extension)
        {
            if (bytes == null || bytes.Length < 100) return false;

            if (extension == ".png")
            {
                // Header: 89 50 4E 47
                bool headerOk = bytes[0] == 0x89 && bytes[1] == 0x50 && bytes[2] == 0x4E && bytes[3] == 0x47;
                if (!headerOk || bytes.Length < 12) return false;

                // PNG must end with IEND chunk: [00 00 00 00] 49 45 4E 44 AE 42 60 82
                // We check if "IEND" exists at the expected position from the end.
                return bytes[bytes.Length - 8] == 0x49 && bytes[bytes.Length - 7] == 0x45 &&
                       bytes[bytes.Length - 6] == 0x4E && bytes[bytes.Length - 5] == 0x44;
            }

            if (extension == ".jpg" || extension == ".jpeg")
            {
                // Header: FF D8
                bool headerOk = bytes[0] == 0xFF && bytes[1] == 0xD8;
                if (!headerOk) return false;

                // Look for EOI marker FF D9 scanning backwards from the end.
                // Some tools append metadata after EOI, so it may not be the very last two bytes.
                int searchEnd = Math.Min(bytes.Length - 2, 64);
                for (int i = bytes.Length - 2; i >= bytes.Length - 2 - searchEnd; i--)
                {
                    if (bytes[i] == 0xFF && bytes[i + 1] == 0xD9)
                    {
                        return true;
                    }
                }

                return false;
            }

            if (extension == ".webp")
            {
                // Header: RIFF....WEBP
                if (bytes.Length < 12) return false;
                bool riffOk = bytes[0] == (byte)'R' && bytes[1] == (byte)'I' && bytes[2] == (byte)'F' && bytes[3] == (byte)'F' &&
                              bytes[8] == (byte)'W' && bytes[9] == (byte)'E' && bytes[10] == (byte)'B' && bytes[11] == (byte)'P';
                if (!riffOk) return false;

                // Size check: bytes[4..7] is the size in RIFF header (little-endian)
                uint riffSize = BitConverter.ToUInt32(bytes, 4);
                return (riffSize + 8) <= (uint)bytes.Length;
            }

            return true;
        }

        private static Texture2D LoadSourceTexture(string sourcePath, byte[] sourceBytes, string extension)
        {
            Texture2D sourceTexture = new Texture2D(2, 2, TextureFormat.RGBA32, false);
            if (sourceTexture.LoadImage(sourceBytes))
            {
                return sourceTexture;
            }

            UnityEngine.Object.DestroyImmediate(sourceTexture);

            // If LoadImage failed for standard formats (PNG/JPG), it's a corrupted file.
            // We only attempt the AssetDatabase fallback for WEBP, which LoadImage might not support.
            if (extension != ".webp")
            {
                throw new InvalidOperationException($"Failed to decode {extension.ToUpper().Substring(1)} image. The file may be corrupted or in an unsupported sub-format.");
            }

            // Some editor-supported formats, such as WEBP, may not be supported by Texture2D.LoadImage.
            string temporaryAssetPath = $"{IconConfiguratorPaths.ImportedDirectory}/__source_{Guid.NewGuid():N}{extension}";
            File.Copy(sourcePath, temporaryAssetPath);
            AssetDatabase.ImportAsset(temporaryAssetPath, ImportAssetOptions.ForceSynchronousImport);
            ConfigureTextureImporter(temporaryAssetPath);

            Texture2D importedTexture = AssetDatabase.LoadAssetAtPath<Texture2D>(temporaryAssetPath);
            if (importedTexture == null)
            {
                AssetDatabase.DeleteAsset(temporaryAssetPath);
                throw new InvalidOperationException($"Failed to decode image. Supported formats are {k_SupportedFormatText}.");
            }

            Texture2D readableCopy = new Texture2D(importedTexture.width, importedTexture.height, TextureFormat.RGBA32, false);
            readableCopy.SetPixels(importedTexture.GetPixels());
            readableCopy.Apply();
            AssetDatabase.DeleteAsset(temporaryAssetPath);
            return readableCopy;
        }

        private static string ComputeHash(byte[] bytes)
        {
            using SHA256 sha256 = SHA256.Create();
            byte[] hash = sha256.ComputeHash(bytes);
            return BitConverter.ToString(hash).Replace("-", string.Empty).ToLowerInvariant();
        }

        private static void ConfigureTextureImporter(string assetPath)
        {
            TextureImporter importer = AssetImporter.GetAtPath(assetPath) as TextureImporter;

            if (importer == null)
            {
                return;
            }

            bool changed = false;

            if (!importer.isReadable)
            {
                importer.isReadable = true;
                changed = true;
            }

            if (!importer.alphaIsTransparency)
            {
                importer.alphaIsTransparency = true;
                changed = true;
            }

            if (importer.mipmapEnabled)
            {
                importer.mipmapEnabled = false;
                changed = true;
            }

            if (importer.textureCompression != TextureImporterCompression.Uncompressed)
            {
                importer.textureCompression = TextureImporterCompression.Uncompressed;
                changed = true;
            }

            if (changed)
            {
                importer.SaveAndReimport();
            }
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
    }
}
