using UnityEngine;
using UnityEngine.UI;

public class AndroidPluginTest : MonoBehaviour
{
    private const string PluginClassName = "com.example.androidplugin.PluginInstance";
    private AndroidJavaObject _pluginInstance;

    public Text outputText; // Assign a UI Text in Inspector to see results

    void Start()
    {
        Debug.Log("AndroidPluginTest Start");
        CallAndroidFunction();
    }

    public void CallAndroidFunction()
    {
        if (Application.platform == RuntimePlatform.Android)
        {
            try
            {
                using (AndroidJavaClass pluginClass = new AndroidJavaClass(PluginClassName))
                {
                    if (pluginClass != null)
                    {
                        string message = pluginClass.CallStatic<string>("getMessage");
                        Debug.Log("Message from Android: " + message);
                        if(outputText != null) outputText.text = message;

                        int sum = pluginClass.CallStatic<int>("add", 5, 10);
                        Debug.Log("Sum from Android: " + sum);
                        if(outputText != null) outputText.text += "\nSum: " + sum;
                    }
                }
            }
            catch (System.Exception e)
            {
                Debug.LogError("Error calling Android plugin: " + e.Message);
                if(outputText != null) outputText.text = "Error: " + e.Message;
            }
        }
        else
        {
            Debug.Log("Not running on Android, skipping plugin call.");
            if(outputText != null) outputText.text = "Not running on Android";
        }
    }
}
