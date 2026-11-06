#if !ENABLE_PICO_OPENXR_SDK
using System;

namespace ByteDance.PICO.SecureMR
{
    public abstract class SceneGraphProperty
    {
        private readonly string m_componentName;
        private readonly string m_property;

        public string Path => $"{m_componentName}:{m_property}";

        protected SceneGraphProperty(string componentName, string property)
        {
            m_componentName = componentName;
            m_property = property;
        }

        public sealed class Transform : SceneGraphProperty
        {
            private Transform(string property) : base("TransformComponent", property) { }

            public static readonly Transform Position = new Transform("Position");
            public static readonly Transform Rotation = new Transform("Rotation");
            public static readonly Transform Scale = new Transform("Scale");
            public static readonly Transform LocalMatrix = new Transform("LocalMatrix");
        }

        public sealed class CameraAnchor : SceneGraphProperty
        {
            private CameraAnchor(string property) : base("AnchorComponent", property) { }

            public static readonly CameraAnchor Follow = new CameraAnchor("ViewLocked");
            public static readonly CameraAnchor Locked = new CameraAnchor("WorldLocked");
        }

        public sealed class Text : SceneGraphProperty
        {
            private Text(string property) : base("TextComponent", property) { }

            public static readonly Text Content = new Text("Text");
            public static readonly Text Color = new Text("TextColor");
            public static readonly Text BackgroundColor = new Text("BackgroundColor");
            public static readonly Text FontSize = new Text("FontSize");
            public static readonly Text HorizontalAlignment = new Text("HorizontalAlignment");
            public static readonly Text VerticalAlignment = new Text("VerticalAlignment");
        }

        private sealed class PbrMaterialPropertyBaseColor : SceneGraphProperty
        {
            public PbrMaterialPropertyBaseColor(int index) : base("ModelComponent", $"BaseColor:{index}") { }
        }

        private sealed class PbrMaterialPropertyRoughness : SceneGraphProperty
        {
            public PbrMaterialPropertyRoughness(int index) : base("ModelComponent", $"Roughness:{index}") { }
        }

        private sealed class PbrMaterialPropertyMetallic : SceneGraphProperty
        {
            public PbrMaterialPropertyMetallic(int index) : base("ModelComponent", $"Metallic:{index}") { }
        }

        private sealed class PbrMaterialPropertyBaseColorTexture : SceneGraphProperty
        {
            public PbrMaterialPropertyBaseColorTexture(int index) : base("ModelComponent", $"BaseColorTexture:{index}") { }
        }

        private sealed class PbrMaterialPropertyRoughnessTexture : SceneGraphProperty
        {
            public PbrMaterialPropertyRoughnessTexture(int index) : base("ModelComponent", $"RoughnessTexture:{index}") { }
        }

        private sealed class PbrMaterialPropertyMetallicTexture : SceneGraphProperty
        {
            public PbrMaterialPropertyMetallicTexture(int index) : base("ModelComponent", $"MetallicTexture:{index}") { }
        }

        public sealed class PbrMaterials
        {
            public SceneGraphProperty BaseColor => new PbrMaterialPropertyBaseColor(0);
            public SceneGraphProperty Roughness => new PbrMaterialPropertyRoughness(0);
            public SceneGraphProperty Metallic => new PbrMaterialPropertyMetallic(0);
            public SceneGraphProperty BaseColorTexture => new PbrMaterialPropertyBaseColorTexture(0);
            public SceneGraphProperty RoughnessTexture => new PbrMaterialPropertyRoughnessTexture(0);
            public SceneGraphProperty MetallicTexture => new PbrMaterialPropertyMetallicTexture(0);

            public IndexedPbrMaterial this[int index] => new IndexedPbrMaterial(index);

            public sealed class IndexedPbrMaterial
            {
                private readonly int m_index;

                internal IndexedPbrMaterial(int index)
                {
                    m_index = index;
                }

                public SceneGraphProperty BaseColor => new PbrMaterialPropertyBaseColor(m_index);
                public SceneGraphProperty Roughness => new PbrMaterialPropertyRoughness(m_index);
                public SceneGraphProperty Metallic => new PbrMaterialPropertyMetallic(m_index);
                public SceneGraphProperty BaseColorTexture => new PbrMaterialPropertyBaseColorTexture(m_index);
                public SceneGraphProperty RoughnessTexture => new PbrMaterialPropertyRoughnessTexture(m_index);
                public SceneGraphProperty MetallicTexture => new PbrMaterialPropertyMetallicTexture(m_index);
            }
        }

        public static readonly PbrMaterials PBRMaterials = new PbrMaterials();
    }
}
#endif
