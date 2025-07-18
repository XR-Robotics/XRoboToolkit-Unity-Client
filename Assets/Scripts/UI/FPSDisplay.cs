using System.Diagnostics;
using UnityEngine;
using UnityEngine.UI;

public class FPSDisplay : MonoBehaviour
{
    public Text fpsText;
    private static float deltaTime = 0.0f;
    private static Stopwatch stopwatch;

    private void Awake()
    {
        stopwatch = Stopwatch.StartNew();
    }

    public static void UpdateTime()
    {
        var unDeltaTime = stopwatch.ElapsedMilliseconds; // Time interval (seconds)
        stopwatch.Restart(); // reset
        // Accumulated frame interval time
        deltaTime += (unDeltaTime - deltaTime) * 0.1f;
        //   Debug.Log("deltaTime:" + deltaTime);
    }

    private void Update()
    {
        if (fpsText != null)
        {
            if (Time.frameCount % 10 == 0)
            {
                var text = $"FPS: N/A";
                // Calculate FPS
                if (deltaTime > 0)
                {
                    var fps = 1000.0f / deltaTime;
                    text = $"{fps:F1}";
                }

                fpsText.text = text;
            }
        }
    }
}