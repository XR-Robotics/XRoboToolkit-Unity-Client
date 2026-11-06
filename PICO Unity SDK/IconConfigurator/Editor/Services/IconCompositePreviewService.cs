using UnityEngine;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    public class IconCompositePreviewService
    {
        public Texture2D ComposePreview(System.Collections.Generic.IReadOnlyList<Texture2D> layers, int maxPreviewSize = 256)
        {
            if (layers == null || layers.Count == 0)
            {
                return null;
            }

            Texture2D referenceTexture = GetReferenceTexture(layers);
            if (referenceTexture == null)
            {
                return null;
            }

            Vector2Int outputSize = CalculateOutputSize(referenceTexture, maxPreviewSize);
            Texture2D output = new Texture2D(outputSize.x, outputSize.y, TextureFormat.RGBA32, false);
            Color[] pixels = new Color[outputSize.x * outputSize.y];

            for (int y = 0; y < outputSize.y; y++)
            {
                float normalizedY = outputSize.y == 1 ? 0f : y / (float)(outputSize.y - 1);

                for (int x = 0; x < outputSize.x; x++)
                {
                    float normalizedX = outputSize.x == 1 ? 0f : x / (float)(outputSize.x - 1);
                    Color color = Color.clear;

                    for (int i = 0; i < layers.Count; i++)
                    {
                        color = Blend(color, SampleFitted(layers[i], normalizedX, normalizedY, outputSize.x, outputSize.y));
                    }

                    pixels[(y * outputSize.x) + x] = color;
                }
            }

            output.SetPixels(pixels);
            output.Apply();
            return output;
        }

        public Texture2D ComposePreview(
            Texture2D background,
            Texture2D foreground1,
            Texture2D foreground2,
            int maxPreviewSize = 256)
        {
            return ComposePreview(
                new[]
                {
                    background,
                    foreground1,
                    foreground2,
                },
                maxPreviewSize);
        }

        private static Texture2D GetReferenceTexture(System.Collections.Generic.IReadOnlyList<Texture2D> layers)
        {
            for (int i = 0; i < layers.Count; i++)
            {
                if (layers[i] != null)
                {
                    return layers[i];
                }
            }

            return null;
        }

        private static Vector2Int CalculateOutputSize(Texture2D referenceTexture, int maxPreviewSize)
        {
            int width = referenceTexture.width;
            int height = referenceTexture.height;

            if (width >= height)
            {
                int scaledHeight = Mathf.Max(1, Mathf.RoundToInt(maxPreviewSize * (height / (float)width)));
                return new Vector2Int(maxPreviewSize, scaledHeight);
            }

            int scaledWidth = Mathf.Max(1, Mathf.RoundToInt(maxPreviewSize * (width / (float)height)));
            return new Vector2Int(scaledWidth, maxPreviewSize);
        }

        private static Color SampleFitted(Texture2D texture, float x, float y, int targetWidth, int targetHeight)
        {
            if (texture == null)
            {
                return Color.clear;
            }

            float targetAspect = targetWidth / (float)targetHeight;
            float textureAspect = texture.width / (float)texture.height;

            float contentWidth = 1f;
            float contentHeight = 1f;
            float offsetX = 0f;
            float offsetY = 0f;

            if (textureAspect > targetAspect)
            {
                contentHeight = targetAspect / textureAspect;
                offsetY = (1f - contentHeight) * 0.5f;
            }
            else if (textureAspect < targetAspect)
            {
                contentWidth = textureAspect / targetAspect;
                offsetX = (1f - contentWidth) * 0.5f;
            }

            bool outsideContent =
                x < offsetX
                || x > offsetX + contentWidth
                || y < offsetY
                || y > offsetY + contentHeight;

            if (outsideContent)
            {
                return Color.clear;
            }

            float sampleX = contentWidth <= 0f ? 0f : (x - offsetX) / contentWidth;
            float sampleY = contentHeight <= 0f ? 0f : (y - offsetY) / contentHeight;

            return texture.GetPixelBilinear(sampleX, sampleY);
        }

        private static Color Blend(Color destination, Color source)
        {
            float alpha = source.a + (destination.a * (1f - source.a));

            if (alpha <= 0f)
            {
                return Color.clear;
            }

            float red = ((source.r * source.a) + (destination.r * destination.a * (1f - source.a))) / alpha;
            float green = ((source.g * source.a) + (destination.g * destination.a * (1f - source.a))) / alpha;
            float blue = ((source.b * source.a) + (destination.b * destination.a * (1f - source.a))) / alpha;

            return new Color(red, green, blue, alpha);
        }
    }
}
