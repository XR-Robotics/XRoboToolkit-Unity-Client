using UnityEngine;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    /// <summary>
    /// Shared helpers for icon texture processing. Centralizes the square-normalization
    /// logic that import and AI Split preparation both rely on, and uses batched pixel
    /// writes instead of per-pixel <see cref="Texture2D.SetPixel"/> calls.
    /// </summary>
    public static class IconTextureUtility
    {
        /// <summary>
        /// Produces a square RGBA32 texture that contains the source scaled to fit and
        /// centered on a transparent background. The caller owns the returned texture and
        /// is responsible for destroying it.
        /// </summary>
        public static Texture2D NormalizeToSquare(Texture2D sourceTexture)
        {
            // The AI service requires square input. To avoid backend RPC timeouts (1s) on complex images:
            // 1. Determine base size using the smaller dimension to focus on the center content.
            // 2. Cap the final target size at 512x512.
            int minDimension = Mathf.Min(sourceTexture.width, sourceTexture.height);
            int targetSize = Mathf.Min(minDimension, 512);
            
            Texture2D normalized = new Texture2D(targetSize, targetSize, TextureFormat.RGBA32, false);

            Color[] pixels = new Color[targetSize * targetSize];
            for (int i = 0; i < pixels.Length; i++)
            {
                pixels[i] = Color.clear;
            }

            // Perform center-crop and scale:
            // Calculate which part of the source to sample from to get a square crop from the center.
            float sourceAspect = (float)sourceTexture.width / sourceTexture.height;
            for (int y = 0; y < targetSize; y++)
            {
                float v = (float)y / (targetSize - 1);
                int rowStart = y * targetSize;
                for (int x = 0; x < targetSize; x++)
                {
                    float u = (float)x / (targetSize - 1);
                    
                    // Map [0,1] target UV to [0,1] source UV with center-crop logic
                    float sourceU = u;
                    float sourceV = v;
                    
                    if (sourceAspect > 1f) // Wider than tall (e.g. 16:9)
                    {
                        float offset = (1f - 1f / sourceAspect) * 0.5f;
                        sourceU = offset + (u / sourceAspect);
                    }
                    else if (sourceAspect < 1f) // Taller than wide
                    {
                        float offset = (1f - sourceAspect) * 0.5f;
                        sourceV = offset + (v * sourceAspect);
                    }

                    pixels[rowStart + x] = sourceTexture.GetPixelBilinear(sourceU, sourceV);
                }
            }

            normalized.SetPixels(pixels);
            normalized.Apply();
            return normalized;
        }
    }
}
