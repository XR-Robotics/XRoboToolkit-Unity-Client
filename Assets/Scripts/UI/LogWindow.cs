using System.Collections;
using System.Collections.Concurrent;
using System.Text;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class LogWindow : MonoBehaviour
{
    private const int MaxMessagesPerFrame = 200;
    private static readonly ConcurrentQueue<string> PendingMessages = new ConcurrentQueue<string>();

    public TextMeshProUGUI text;

    public ScrollRect scrollRect;

    public RectTransform rectTransform;

    private void Update()
    {
        if (text == null || PendingMessages.IsEmpty)
        {
            return;
        }

        var builder = new StringBuilder();
        int count = 0;
        while (count < MaxMessagesPerFrame && PendingMessages.TryDequeue(out string message))
        {
            builder.Append(message);
            count++;
        }

        if (builder.Length == 0)
        {
            return;
        }

        text.text += builder.ToString();
        StartCoroutine(AutoScrollCoroutine());
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
        Message(message);
    }

    private static void Message(string message)
    {
        // Network and audio callbacks may run outside Unity's main thread.
        // Queue the already-formatted line and let Update() perform all UI work.
        string timePrefix = $"[{System.DateTime.Now:HH:mm:ss}] ";
        PendingMessages.Enqueue($"{timePrefix}{message}\n");
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
