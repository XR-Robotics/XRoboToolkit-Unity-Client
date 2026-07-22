using System;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// Switches the remote video between the legacy floating screen and a true
/// equirectangular skybox. The panoramic mode never fabricates a panorama from
/// a flat camera; it is enabled only when the operator explicitly advertises
/// equirectangular projection metadata.
/// </summary>
public sealed class RemoteVideoProjectionRenderer : MonoBehaviour
{
    public const string FlatProjection = "flat";
    public const string EquirectangularProjection = "equirectangular";
    public const string MonoLayout = "mono";
    public const string SideBySideLayout = "side_by_side";
    public const string TopBottomLayout = "top_bottom";

    private RemoteCameraWindow remoteWindow;
    private SetLERE legacyStereoRenderer;
    private RawImage flatImage;
    private Material panoramaMaterial;
    private Material previousSkybox;
    private Camera targetCamera;
    private CameraClearFlags previousClearFlags;
    private bool panoramaApplied;
    private bool flatImageStateCaptured;
    private bool flatImageWasEnabled;
    private string projection = FlatProjection;
    private string stereoLayout = MonoLayout;
    private Texture appliedTexture;

    private void Awake()
    {
        ResolveComponents();
    }

    public void SetLegacyStereoRenderer(SetLERE renderer)
    {
        if (legacyStereoRenderer == renderer)
        {
            return;
        }
        if (panoramaApplied && legacyStereoRenderer != null)
        {
            legacyStereoRenderer.SetProjectionSuspended(false);
        }
        legacyStereoRenderer = renderer;
        if (panoramaApplied && legacyStereoRenderer != null)
        {
            legacyStereoRenderer.SetProjectionSuspended(true);
        }
    }

    public void Configure(string requestedProjection, string requestedStereoLayout)
    {
        projection = NormalizeProjection(requestedProjection);
        stereoLayout = NormalizeStereoLayout(requestedStereoLayout);
        ResolveComponents();

        if (projection == EquirectangularProjection)
        {
            ApplyPanorama();
        }
        else
        {
            RestoreFlatScreen();
        }
    }

    public static string NormalizeProjection(string value)
    {
        return string.Equals(value, EquirectangularProjection, StringComparison.Ordinal)
            ? EquirectangularProjection
            : FlatProjection;
    }

    public static string NormalizeStereoLayout(string value)
    {
        if (string.Equals(value, SideBySideLayout, StringComparison.Ordinal))
        {
            return SideBySideLayout;
        }
        if (string.Equals(value, TopBottomLayout, StringComparison.Ordinal))
        {
            return TopBottomLayout;
        }
        return MonoLayout;
    }

    private void ResolveComponents()
    {
        if (remoteWindow == null)
        {
            remoteWindow = GetComponent<RemoteCameraWindow>();
        }
        if (remoteWindow != null && flatImage == null)
        {
            flatImage = remoteWindow.RemoteCameraImage;
        }
        if (targetCamera == null)
        {
            targetCamera = Camera.main;
        }
    }

    private void Update()
    {
        if (projection != EquirectangularProjection)
        {
            return;
        }
        if (!panoramaApplied)
        {
            ApplyPanorama();
            return;
        }
        Texture texture = remoteWindow != null ? remoteWindow.Texture : null;
        if (texture != null && texture != appliedTexture)
        {
            ApplyTexture(texture);
        }
    }

    private void ApplyPanorama()
    {
        ResolveComponents();
        Shader shader = Shader.Find("Skybox/Panoramic");
        if (shader == null)
        {
            Debug.LogError("Skybox/Panoramic shader is unavailable; keeping flat remote video.");
            projection = FlatProjection;
            RestoreFlatScreen();
            return;
        }

        if (!panoramaApplied)
        {
            previousSkybox = RenderSettings.skybox;
            if (targetCamera != null)
            {
                previousClearFlags = targetCamera.clearFlags;
                targetCamera.clearFlags = CameraClearFlags.Skybox;
            }
            if (flatImage != null)
            {
                flatImageWasEnabled = flatImage.enabled;
                flatImageStateCaptured = true;
            }
        }
        if (panoramaMaterial == null)
        {
            panoramaMaterial = new Material(shader);
            panoramaMaterial.name = "XRoboToolkit Runtime Panorama";
        }

        panoramaMaterial.SetFloat("_Mapping", 1f);
        panoramaMaterial.EnableKeyword("_MAPPING_LATITUDE_LONGITUDE_LAYOUT");
        panoramaMaterial.DisableKeyword("_MAPPING_6_FRAMES_LAYOUT");
        panoramaMaterial.SetFloat("_ImageType", 0f);
        panoramaMaterial.SetFloat("_Layout", LayoutValue(stereoLayout));
        panoramaMaterial.SetFloat("_Rotation", 0f);
        RenderSettings.skybox = panoramaMaterial;
        if (flatImage != null)
        {
            flatImage.enabled = false;
        }
        if (legacyStereoRenderer != null)
        {
            legacyStereoRenderer.SetProjectionSuspended(true);
        }
        panoramaApplied = true;

        Texture texture = remoteWindow != null ? remoteWindow.Texture : null;
        if (texture != null)
        {
            ApplyTexture(texture);
        }
        Debug.Log($"Remote video projection=equirectangular layout={stereoLayout}");
    }

    private void ApplyTexture(Texture texture)
    {
        appliedTexture = texture;
        panoramaMaterial.SetTexture("_MainTex", texture);
        WarnIfUnexpectedAspect(texture);
    }

    private void WarnIfUnexpectedAspect(Texture texture)
    {
        if (texture == null || texture.height <= 0)
        {
            return;
        }
        float expected = stereoLayout == SideBySideLayout
            ? 4f
            : stereoLayout == TopBottomLayout
                ? 1f
                : 2f;
        float actual = (float)texture.width / texture.height;
        if (Mathf.Abs(actual - expected) > 0.08f)
        {
            Debug.LogWarning(
                $"Equirectangular texture aspect is {actual:F2}; expected {expected:F2} " +
                $"for layout={stereoLayout}. Source metadata/resolution may be wrong.");
        }
    }

    private static float LayoutValue(string layout)
    {
        if (layout == SideBySideLayout)
        {
            return 1f;
        }
        if (layout == TopBottomLayout)
        {
            return 2f;
        }
        return 0f;
    }

    public void RestoreFlatScreen()
    {
        // A disabled remote window can later be re-used by the legacy PC-camera
        // path, which does not negotiate projection metadata. Clear the desired
        // mode here so re-enabling that window cannot resurrect a stale panorama.
        projection = FlatProjection;
        stereoLayout = MonoLayout;

        if (panoramaApplied)
        {
            if (RenderSettings.skybox == panoramaMaterial)
            {
                RenderSettings.skybox = previousSkybox;
            }
            if (targetCamera != null)
            {
                targetCamera.clearFlags = previousClearFlags;
            }
            if (flatImage != null && flatImageStateCaptured)
            {
                flatImage.enabled = flatImageWasEnabled;
            }
            if (legacyStereoRenderer != null)
            {
                legacyStereoRenderer.SetProjectionSuspended(false);
            }
        }
        panoramaApplied = false;
        flatImageStateCaptured = false;
        if (panoramaMaterial != null)
        {
            panoramaMaterial.SetTexture("_MainTex", null);
        }
        appliedTexture = null;
        previousSkybox = null;
        targetCamera = null;
    }

    private void OnDisable()
    {
        RestoreFlatScreen();
    }

    private void OnDestroy()
    {
        RestoreFlatScreen();
        if (panoramaMaterial != null)
        {
            Destroy(panoramaMaterial);
            panoramaMaterial = null;
        }
    }
}
