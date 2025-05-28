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
        if (Time.frameCount % 10 == 0)
        {
            // Calculate FPS
            var fps = 1000.0f / deltaTime;
            if (fpsText != null) fpsText.text = $"FPS: {fps:f1}";
        }
    }
}