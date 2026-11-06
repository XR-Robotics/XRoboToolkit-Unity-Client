using NUnit.Framework;
using UnityEngine;

namespace ByteDance.PICO.IconConfigurator.Editor.Tests
{
    public class IconCompositePreviewServiceTests
    {
        [Test]
        public void ComposePreview_WhenSourceIsPortrait_PreservesPortraitAspectRatio()
        {
            IconCompositePreviewService service = new IconCompositePreviewService();
            Texture2D portrait = CreateTexture(100, 200, Color.green);

            Texture2D result = service.ComposePreview(portrait, null, null);

            Assert.That(result, Is.Not.Null);
            Assert.That(result.width, Is.EqualTo(128));
            Assert.That(result.height, Is.EqualTo(256));

            Object.DestroyImmediate(portrait);
            Object.DestroyImmediate(result);
        }

        private static Texture2D CreateTexture(int width, int height, Color color)
        {
            Texture2D texture = new Texture2D(width, height, TextureFormat.RGBA32, false);
            Color[] pixels = new Color[width * height];

            for (int i = 0; i < pixels.Length; i++)
            {
                pixels[i] = color;
            }

            texture.SetPixels(pixels);
            texture.Apply();
            return texture;
        }
    }
}
