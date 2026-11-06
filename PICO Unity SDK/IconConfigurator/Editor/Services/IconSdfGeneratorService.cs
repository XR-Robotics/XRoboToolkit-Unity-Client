using UnityEngine;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    public class IconSdfGeneratorService
    {
        private const float k_RadiusScale = 0.125f;
        private const int k_MinRadius = 8;
        private const int k_MaxRadius = 32;

        public Texture2D Generate(Texture2D source)
        {
            if (source == null)
            {
                return null;
            }

            Texture2D output = new Texture2D(source.width, source.height, TextureFormat.RGBA32, false);
            float maxDistance = CalculateMaxDistance(source);
            SDFTextureGenerator.Generate(
                source,
                output,
                maxDistance,
                maxDistance,
                maxDistance,
                RGBFillMode.Distance);
            output.Apply();
            return output;
        }

        private static float CalculateMaxDistance(Texture2D source)
        {
            return Mathf.Clamp(
                Mathf.RoundToInt(Mathf.Max(source.width, source.height) * k_RadiusScale),
                k_MinRadius,
                k_MaxRadius);
        }
    }
}
