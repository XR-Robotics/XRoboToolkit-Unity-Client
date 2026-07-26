using System;
using System.Text;
using LitJson;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// A validated, bounded recorder-status update from the operator control socket.
/// This metadata is rendered on Pico and is intentionally independent from the
/// compressed H.264 video path.
/// </summary>
public sealed class RemoteRecordStatusSnapshot
{
    public const string Schema = "g1_wuji_record_status_v1";

    public string State { get; private set; }
    public string OperatorTime { get; private set; }
    public int Episode { get; private set; }
    public int FrameCount { get; private set; }

    public static bool TryParse(byte[] payload, out RemoteRecordStatusSnapshot snapshot)
    {
        snapshot = null;
        if (payload == null || payload.Length == 0 || payload.Length > 4096)
        {
            return false;
        }

        try
        {
            JsonData json = JsonMapper.ToObject(Encoding.UTF8.GetString(payload));
            if (json == null || !json.IsObject ||
                !json.ContainsKey("schema") ||
                !string.Equals(json["schema"].ToString(), Schema, StringComparison.Ordinal))
            {
                return false;
            }

            string state = json.ContainsKey("state")
                ? NormalizeState(json["state"].ToString())
                : "UNKNOWN";
            string operatorTime = json.ContainsKey("operator_time")
                ? json["operator_time"].ToString().Trim()
                : string.Empty;
            if (operatorTime.Length == 0 || operatorTime.Length > 32)
            {
                return false;
            }

            snapshot = new RemoteRecordStatusSnapshot
            {
                State = state,
                OperatorTime = operatorTime,
                Episode = ReadNonNegativeInt(json, "episode"),
                FrameCount = ReadNonNegativeInt(json, "frame_count"),
            };
            return true;
        }
        catch (Exception)
        {
            return false;
        }
    }

    private static int ReadNonNegativeInt(JsonData json, string key)
    {
        if (!json.ContainsKey(key) ||
            !int.TryParse(json[key].ToString(), out int value))
        {
            return 0;
        }
        return Math.Max(0, value);
    }

    private static string NormalizeState(string value)
    {
        string normalized = string.IsNullOrEmpty(value)
            ? "UNKNOWN"
            : value.Trim().ToUpperInvariant();
        switch (normalized)
        {
            case "RECORDING":
            case "WAITING_FOR_START":
            case "NEED_TO_SAVE":
            case "SAVING":
            case "IDLE":
                return normalized;
            default:
                return "UNKNOWN";
        }
    }
}

/// <summary>
/// Renders the operator recorder state as one screen-space camera HUD per eye.
/// The HUD remains visible for both the legacy flat canvases and panoramic
/// skybox rendering, without touching or re-encoding a video frame.
/// </summary>
public sealed class RemoteRecordStatusOverlay : MonoBehaviour
{
    private sealed class EyeHud
    {
        public GameObject Root;
        public Text Text;
        public Image Background;
    }

    private EyeHud leftHud;
    private EyeHud rightHud;

    public bool IsConfigured => leftHud != null || rightHud != null;

    public void Configure(GameObject leftVideoCanvas, GameObject rightVideoCanvas)
    {
        if (IsConfigured)
        {
            return;
        }

        leftHud = CreateEyeHud(leftVideoCanvas, "Left");
        rightHud = CreateEyeHud(rightVideoCanvas, "Right");
        SetVisible(false);
    }

    public void Apply(RemoteRecordStatusSnapshot snapshot)
    {
        if (snapshot == null)
        {
            SetVisible(false);
            return;
        }

        string label;
        Color color;
        switch (snapshot.State)
        {
            case "RECORDING":
                label = "REC";
                color = new Color(1f, 0.28f, 0.28f, 1f);
                break;
            case "WAITING_FOR_START":
                label = "ARMED";
                color = new Color(1f, 0.76f, 0.22f, 1f);
                break;
            case "NEED_TO_SAVE":
            case "SAVING":
                label = "SAVING";
                color = new Color(1f, 0.66f, 0.18f, 1f);
                break;
            case "IDLE":
                label = "IDLE";
                color = new Color(0.82f, 0.82f, 0.82f, 1f);
                break;
            default:
                label = "--";
                color = new Color(0.7f, 0.7f, 0.7f, 1f);
                break;
        }

        string text =
            $"{label}  {snapshot.OperatorTime}\n" +
            $"EP {snapshot.Episode}  frames {snapshot.FrameCount}";
        ApplyToEye(leftHud, text, color);
        ApplyToEye(rightHud, text, color);
        SetVisible(true);
    }

    public void Clear()
    {
        SetVisible(false);
    }

    private EyeHud CreateEyeHud(GameObject videoCanvasObject, string eyeName)
    {
        if (videoCanvasObject == null)
        {
            return null;
        }

        Canvas videoCanvas = videoCanvasObject.GetComponent<Canvas>();
        if (videoCanvas == null || videoCanvas.worldCamera == null)
        {
            return null;
        }

        GameObject root = new GameObject(
            $"RemoteRecordStatusOverlay.{eyeName}",
            typeof(RectTransform),
            typeof(Canvas),
            typeof(CanvasScaler));
        // Keep screen-space canvases at scene root. RemoteCamera has a small
        // world-space scale for its legacy floating panel; inheriting that
        // transform would incorrectly shrink a screen-space HUD.
        root.transform.SetParent(null, false);
        root.layer = videoCanvasObject.layer;

        Canvas canvas = root.GetComponent<Canvas>();
        canvas.renderMode = RenderMode.ScreenSpaceCamera;
        canvas.worldCamera = videoCanvas.worldCamera;
        canvas.planeDistance = Mathf.Max(0.01f, videoCanvas.planeDistance - 0.01f);
        canvas.overrideSorting = true;
        canvas.sortingOrder = videoCanvas.sortingOrder + 100;

        CanvasScaler scaler = root.GetComponent<CanvasScaler>();
        scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
        scaler.referenceResolution = new Vector2(1920f, 1080f);
        scaler.screenMatchMode = CanvasScaler.ScreenMatchMode.MatchWidthOrHeight;
        scaler.matchWidthOrHeight = 0.5f;

        GameObject panel = new GameObject(
            "Panel",
            typeof(RectTransform),
            typeof(CanvasRenderer),
            typeof(Image));
        panel.transform.SetParent(root.transform, false);
        panel.layer = root.layer;
        RectTransform panelRect = panel.GetComponent<RectTransform>();
        panelRect.anchorMin = new Vector2(0.03f, 0.86f);
        panelRect.anchorMax = new Vector2(0.72f, 0.98f);
        panelRect.offsetMin = Vector2.zero;
        panelRect.offsetMax = Vector2.zero;
        Image background = panel.GetComponent<Image>();
        background.color = new Color(0f, 0f, 0f, 0.58f);
        background.raycastTarget = false;

        GameObject label = new GameObject(
            "Text",
            typeof(RectTransform),
            typeof(CanvasRenderer),
            typeof(Text),
            typeof(Outline));
        label.transform.SetParent(panel.transform, false);
        label.layer = root.layer;
        RectTransform textRect = label.GetComponent<RectTransform>();
        textRect.anchorMin = Vector2.zero;
        textRect.anchorMax = Vector2.one;
        textRect.offsetMin = new Vector2(18f, 8f);
        textRect.offsetMax = new Vector2(-18f, -8f);

        Text text = label.GetComponent<Text>();
        text.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        text.fontSize = 32;
        text.alignment = TextAnchor.MiddleLeft;
        text.horizontalOverflow = HorizontalWrapMode.Overflow;
        text.verticalOverflow = VerticalWrapMode.Truncate;
        text.raycastTarget = false;
        Outline outline = label.GetComponent<Outline>();
        outline.effectColor = new Color(0f, 0f, 0f, 0.9f);
        outline.effectDistance = new Vector2(2f, -2f);

        return new EyeHud { Root = root, Text = text, Background = background };
    }

    private static void ApplyToEye(EyeHud hud, string text, Color color)
    {
        if (hud == null)
        {
            return;
        }
        hud.Text.text = text;
        hud.Text.color = color;
    }

    private void SetVisible(bool visible)
    {
        if (leftHud != null)
        {
            leftHud.Root.SetActive(visible);
        }
        if (rightHud != null)
        {
            rightHud.Root.SetActive(visible);
        }
    }

    private void OnDisable()
    {
        SetVisible(false);
    }

    private void OnDestroy()
    {
        DestroyEyeHud(leftHud);
        DestroyEyeHud(rightHud);
        leftHud = null;
        rightHud = null;
    }

    private static void DestroyEyeHud(EyeHud hud)
    {
        if (hud != null && hud.Root != null)
        {
            if (Application.isPlaying)
            {
                UnityEngine.Object.Destroy(hud.Root);
            }
            else
            {
                UnityEngine.Object.DestroyImmediate(hud.Root);
            }
        }
    }
}
