using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class LogWindow : MonoBehaviour
{
    public TextMeshProUGUI text;

    private static LogWindow _instance;

    private void Awake()
    {
        _instance = this;
    }

    private static void Message(string message)
    {
        if (_instance != null)
        {
            // add time prefix of local timezone to the message
            string timePrefix = $"[{System.DateTime.Now:HH:mm:ss}] ";
            _instance.text.text += $"{timePrefix}{message}\n";
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