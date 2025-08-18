using System.Collections;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class LogWindow : MonoBehaviour
{
    public TextMeshProUGUI text;

    public ScrollRect scrollRect;

    private static LogWindow _instance;

    public RectTransform rectTransform;

    private void Awake()
    {
        _instance = this;
    }

    private IEnumerator AutoScrollCoroutine()
    {
        LayoutRebuilder.ForceRebuildLayoutImmediate(scrollRect.content as RectTransform);
        yield return new WaitForEndOfFrame(); // Wait one frame for layout to update

        // Update rectTransform height based on text content
        UpdateRectTransformHeight();

        scrollRect.verticalNormalizedPosition = 0f;
    }

    private void UpdateRectTransformHeight()
    {
        if (rectTransform != null && text != null)
        {
            // Force the text to update its preferred height
            text.ForceMeshUpdate();

            // Get the preferred height of the text
            float preferredHeight = text.preferredHeight;

            // Update the rectTransform height
            Vector2 sizeDelta = rectTransform.sizeDelta;
            sizeDelta.y = preferredHeight + 10f; // Add some padding
            rectTransform.sizeDelta = sizeDelta;
        }
    }

    public void AppendText(string message)
    {
        if (_instance != null)
        {
            // add time prefix of local timezone to the message
            string timePrefix = $"[{System.DateTime.Now:HH:mm:ss}] ";
            _instance.text.text += $"{timePrefix}{message}\n";

            StartCoroutine(AutoScrollCoroutine());
        }
    }

    private static void Message(string message)
    {
        if (_instance != null)
        {
            _instance.AppendText(message);
        }
    }

    public static void Info(string info)
    {
        // white color text
        Message($"<color=white>{info}</color>");
    }

    public static void Warn(string info)
    {
        // yellow color text
        Message($"<color=yellow>{info}</color>");
    }

    public static void Error(string info)
    {
        // red color text
        Message($"<color=red>{info}</color>");
    }
}