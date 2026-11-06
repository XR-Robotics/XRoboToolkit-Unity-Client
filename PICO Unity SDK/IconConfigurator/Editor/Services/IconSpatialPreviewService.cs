using System;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    public sealed class IconSpatialPreviewService : IDisposable
    {
        private const float k_LayerSpacing = 0.15f;
        private const float k_FieldOfView = 30f;
        private const float k_CameraDistance = 3.9f;
        private const float k_BackgroundDistanceFactor = 8.0f;
        private const float k_BackgroundScaleFactor = 12.0f;

        private PreviewRenderUtility m_previewUtility;
        private GameObject m_root;
        private readonly List<GameObject> m_layerQuads = new List<GameObject>();
        private readonly List<Material> m_layerMaterials = new List<Material>();
        private readonly List<Texture2D> m_lastLayers = new List<Texture2D>();
        private GameObject m_spotlightQuad;
        private Material m_spotlightMaterial;
        private Texture m_cachedPreviewTexture;
        private float m_lastYaw = float.MinValue;
        private int m_lastWidth;
        private int m_lastHeight;
        private bool m_disposed;

        public Texture Render(
            Texture2D background,
            Texture2D foreground1,
            Texture2D foreground2,
            float yaw,
            int width = 256,
            int height = 256)
        {
            return Render(
                new[]
                {
                    background,
                    foreground1,
                    foreground2,
                },
                yaw,
                width,
                height);
        }

        public Texture Render(IReadOnlyList<Texture2D> layers, float yaw, int width = 256, int height = 256)
        {
            if (m_disposed)
            {
                return null;
            }

            EnsurePreviewUtility();

            if (!HasVisibleLayer(layers))
            {
                return null;
            }

            bool sourcesChanged = SourcesChanged(layers);
            if (sourcesChanged)
            {
                RebuildPreviewScene(layers);
            }

            if (m_root == null || m_previewUtility == null)
            {
                return null;
            }

            bool needsRender = sourcesChanged
                || !Mathf.Approximately(yaw, m_lastYaw)
                || width != m_lastWidth
                || height != m_lastHeight
                || m_cachedPreviewTexture == null;

            if (!needsRender)
            {
                return m_cachedPreviewTexture;
            }

            m_lastYaw = yaw;
            m_lastWidth = width;
            m_lastHeight = height;

            m_root.transform.rotation = Quaternion.Euler(0f, yaw, 0f);

            Camera camera = m_previewUtility.camera;
            camera.aspect = width / (float)Mathf.Max(1, height);

            Rect previewRect = new Rect(0f, 0f, width, height);
            m_previewUtility.BeginPreview(previewRect, GUIStyle.none);
            m_previewUtility.Render();
            m_cachedPreviewTexture = m_previewUtility.EndPreview();

            return m_cachedPreviewTexture;
        }

        public void Cleanup()
        {
            Dispose();
        }

        public void Dispose()
        {
            if (m_disposed)
            {
                return;
            }

            m_disposed = true;
            CleanupPreviewScene();

            if (m_previewUtility != null)
            {
                m_previewUtility.Cleanup();
                m_previewUtility = null;
            }

            for (int i = 0; i < m_layerMaterials.Count; i++)
            {
                DestroyObject(m_layerMaterials[i]);
            }

            m_layerMaterials.Clear();

            DestroyObject(m_spotlightMaterial);
            m_spotlightMaterial = null;

            m_cachedPreviewTexture = null;
            m_lastLayers.Clear();
        }

        private void EnsurePreviewUtility()
        {
            if (m_previewUtility != null)
            {
                return;
            }

            CreatePreviewUtility();
            if (m_lastLayers.Count > 0)
            {
                List<Texture2D> layers = new List<Texture2D>(m_lastLayers);
                m_lastLayers.Clear();
                RebuildPreviewScene(layers);
            }
        }

        private void CreatePreviewUtility()
        {
            m_previewUtility = new PreviewRenderUtility();
            m_previewUtility.cameraFieldOfView = k_FieldOfView;
            m_previewUtility.ambientColor = new Color(0.16f, 0.16f, 0.18f, 1f);

            Camera camera = m_previewUtility.camera;
            camera.fieldOfView = k_FieldOfView;
            camera.clearFlags = CameraClearFlags.SolidColor;
            camera.backgroundColor = new Color(0.30f, 0.302f, 0.314f, 1f);
            camera.nearClipPlane = 0.01f;
            camera.farClipPlane = 100f;
            camera.transform.position = new Vector3(0f, 0f, -k_CameraDistance);
            camera.transform.rotation = Quaternion.identity;

            if (m_previewUtility.lights != null && m_previewUtility.lights.Length > 0)
            {
                m_previewUtility.lights[0].intensity = 1.45f;
                m_previewUtility.lights[0].color = new Color(1f, 0.95f, 0.86f, 1f);
                m_previewUtility.lights[0].transform.rotation = Quaternion.Euler(35f, 34f, 0f);
            }

            if (m_previewUtility.lights != null && m_previewUtility.lights.Length > 1)
            {
                m_previewUtility.lights[1].intensity = 0.45f;
                m_previewUtility.lights[1].color = new Color(0.55f, 0.64f, 1f, 1f);
                m_previewUtility.lights[1].transform.rotation = Quaternion.Euler(340f, 218f, 177f);
            }
        }

        private bool SourcesChanged(IReadOnlyList<Texture2D> layers)
        {
            if (layers == null)
            {
                return m_lastLayers.Count > 0;
            }

            if (m_lastLayers.Count != layers.Count)
            {
                return true;
            }

            for (int i = 0; i < layers.Count; i++)
            {
                if (m_lastLayers[i] != layers[i])
                {
                    return true;
                }
            }

            return false;
        }

        private void RebuildPreviewScene(IReadOnlyList<Texture2D> layers)
        {
            CleanupPreviewScene();
            m_lastLayers.Clear();
            m_cachedPreviewTexture = null;

            if (layers == null)
            {
                return;
            }

            for (int i = 0; i < layers.Count; i++)
            {
                m_lastLayers.Add(layers[i]);
            }

            if (!HasVisibleLayer(layers) || m_previewUtility == null)
            {
                return;
            }

            m_root = new GameObject("IconSpatialPreviewRoot")
            {
                hideFlags = HideFlags.HideAndDontSave,
            };

            List<Texture2D> visibleLayers = new List<Texture2D>();
            for (int i = 0; i < layers.Count; i++)
            {
                if (layers[i] != null)
                {
                    visibleLayers.Add(layers[i]);
                }
            }

            float centerOffset = (visibleLayers.Count - 1) * 0.5f;
            for (int i = 0; i < visibleLayers.Count; i++)
            {
                float zPosition = (centerOffset - i) * k_LayerSpacing;
                GameObject quad = CreateLayerQuad($"LayerQuad{i}", visibleLayers[i], i, zPosition);
                quad.transform.SetParent(m_root.transform, false);
                m_layerQuads.Add(quad);
            }

            m_spotlightQuad = CreateSpotlightQuad();
            SetupSpotlightQuad();

            m_previewUtility.AddSingleGO(m_root);
            m_previewUtility.AddSingleGO(m_spotlightQuad);

            Camera camera = m_previewUtility.camera;
            camera.transform.position = new Vector3(0f, 0f, -k_CameraDistance);
            camera.transform.rotation = Quaternion.identity;
            camera.ResetProjectionMatrix();
            camera.ResetWorldToCameraMatrix();
        }

        private GameObject CreateLayerQuad(string quadName, Texture2D texture, int materialIndex, float zPosition)
        {
            GameObject quad = GameObject.CreatePrimitive(PrimitiveType.Quad);
            quad.name = quadName;
            quad.hideFlags = HideFlags.HideAndDontSave;
            quad.transform.localPosition = new Vector3(0f, 0f, zPosition);
            quad.transform.localScale = GetImageQuadScale(texture);

            Collider collider = quad.GetComponent<Collider>();
            if (collider != null)
            {
                DestroyObject(collider);
            }

            Material material = GetOrCreateLayerMaterial(materialIndex);
            material.mainTexture = texture;
            material.color = Color.white;

            MeshRenderer renderer = quad.GetComponent<MeshRenderer>();
            if (renderer != null)
            {
                renderer.sharedMaterial = material;
                renderer.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
                renderer.receiveShadows = false;
            }

            return quad;
        }

        private Material GetOrCreateLayerMaterial(int index)
        {
            while (m_layerMaterials.Count <= index)
            {
                Shader shader = Shader.Find("Unlit/Transparent");
                if (shader == null)
                {
                    shader = Shader.Find("Sprites/Default");
                }

                if (shader == null)
                {
                    shader = Shader.Find("Unlit/Texture");
                }

                Material material = new Material(shader)
                {
                    hideFlags = HideFlags.HideAndDontSave,
                };
                m_layerMaterials.Add(material);
            }

            return m_layerMaterials[index];
        }

        private static Vector3 GetImageQuadScale(Texture2D texture)
        {
            if (texture == null || texture.height == 0)
            {
                return Vector3.one;
            }

            float aspectRatio = texture.width / (float)texture.height;
            return aspectRatio >= 1f
                ? new Vector3(aspectRatio, 1f, 1f)
                : new Vector3(1f, 1f / aspectRatio, 1f);
        }

        private GameObject CreateSpotlightQuad()
        {
            GameObject quad = GameObject.CreatePrimitive(PrimitiveType.Quad);
            quad.name = "SpotlightBackground";
            quad.hideFlags = HideFlags.HideAndDontSave;

            Collider collider = quad.GetComponent<Collider>();
            if (collider != null)
            {
                DestroyObject(collider);
            }

            MeshRenderer renderer = quad.GetComponent<MeshRenderer>();
            if (renderer != null)
            {
                renderer.sharedMaterial = GetSpotlightMaterial();
                renderer.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
                renderer.receiveShadows = false;
                renderer.lightProbeUsage = UnityEngine.Rendering.LightProbeUsage.Off;
                renderer.reflectionProbeUsage = UnityEngine.Rendering.ReflectionProbeUsage.Off;
            }

            return quad;
        }

        private Material GetSpotlightMaterial()
        {
            if (m_spotlightMaterial != null)
            {
                return m_spotlightMaterial;
            }

            Shader shader = Shader.Find("Unlit/Color");
            if (shader == null)
            {
                shader = Shader.Find("Hidden/Internal-Colored");
            }

            m_spotlightMaterial = new Material(shader)
            {
                hideFlags = HideFlags.HideAndDontSave,
                color = new Color(0.459f, 0.467f, 0.490f, 1f),
            };

            return m_spotlightMaterial;
        }

        private void SetupSpotlightQuad()
        {
            if (m_spotlightQuad == null || m_previewUtility == null)
            {
                return;
            }

            Camera camera = m_previewUtility.camera;
            float distanceBehind = k_LayerSpacing * k_BackgroundDistanceFactor + k_CameraDistance;
            Vector3 quadPosition = camera.transform.position + camera.transform.forward * distanceBehind;

            m_spotlightQuad.transform.position = quadPosition;
            m_spotlightQuad.transform.rotation = camera.transform.rotation;
            m_spotlightQuad.transform.localScale = Vector3.one * k_BackgroundScaleFactor;
        }

        private void CleanupPreviewScene()
        {
            DestroyObject(m_root);
            m_root = null;

            for (int i = 0; i < m_layerQuads.Count; i++)
            {
                DestroyObject(m_layerQuads[i]);
            }

            m_layerQuads.Clear();

            DestroyObject(m_spotlightQuad);
            m_spotlightQuad = null;
        }

        private static bool HasVisibleLayer(IReadOnlyList<Texture2D> layers)
        {
            if (layers == null)
            {
                return false;
            }

            for (int i = 0; i < layers.Count; i++)
            {
                if (layers[i] != null)
                {
                    return true;
                }
            }

            return false;
        }

        private static void DestroyObject(UnityEngine.Object target)
        {
            if (target != null)
            {
                UnityEngine.Object.DestroyImmediate(target);
            }
        }
    }
}
