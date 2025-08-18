using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using UnityEngine;
using UnityEngine.Networking;

public class VideoSourceConfigManager : MonoBehaviour
{
    [Header("Configuration")] [SerializeField]
    private string yamlFileName = "video_source.yml";

    private Dictionary<string, VideoSource> videoSources;
    private bool isInitialized = false;

    // Event
    public event Action OnInitialized;

    /// <summary>
    /// Singleton instance
    /// </summary>
    public static VideoSourceConfigManager Instance { get; private set; }

    private void Awake()
    {
        if (Instance == null)
        {
            Instance = this;
            DontDestroyOnLoad(gameObject);
        }
        else
        {
            Destroy(gameObject);
        }
    }

    private void LoadConfiguration(string path)
    {
        LogWindow.Info($"Loading video sources from {path}");
        videoSources = new Dictionary<string, VideoSource>();
        // Parse the YAML file
        var parsedVideoSources = VideoSourceYamlParser.ParseYamlFile(path);

        // Convert to dictionary for fast lookup
        foreach (var videoSource in parsedVideoSources)
        {
            if (!string.IsNullOrEmpty(videoSource.name))
            {
                videoSources[videoSource.name.ToUpper()] = videoSource;
            }
        }

        isInitialized = true;
        Debug.Log($"VideoSourceConfigManager initialized successfully. Loaded {videoSources.Count} video sources.");
        LogWindow.Info($"Loaded {videoSources.Count} video sources.");

        // Log loaded video sources
        foreach (var kvp in videoSources)
        {
            Debug.Log($"Loaded video source: {kvp.Key} with {kvp.Value.properties.Count} properties");
        }

        OnInitialized?.Invoke();
    }

    /// <summary>
    /// Initialize the configuration manager by loading and parsing the YAML file
    /// </summary>
    public void Initialize()
    {
        try
        {
            string yamlPath;

#if UNITY_EDITOR
            // In editor, use the file directly from Resources folder
            yamlPath = Path.Combine(Application.dataPath, "StreamingAssets", yamlFileName);

            if (File.Exists(yamlPath))
            {
                LoadConfiguration(yamlPath);
            }
            else
            {
                Debug.Log($"Please ensure video_source.yml exists in Assets/StreamingAssets/");
            }
#else
            // In build, check persistentDataPath first, then copy from Resources if needed
            yamlPath = Path.Combine(Application.persistentDataPath, yamlFileName);

            if (File.Exists(yamlPath))
            {
                LoadConfiguration(yamlPath);
                Debug.Log($"Load video_source.yml from {yamlPath}");
            } else {
                // Copy from StreamingAssets
                CopyYamlFromStreamingAssets(yamlPath);
            }
#endif
        }
        catch (Exception e)
        {
            Debug.Log($"Failed to initialize VideoSourceConfigManager: {e.Message}");
            isInitialized = false;
        }
    }

    /// <summary>
    /// Copy the YAML file from StreamingAssets to persistentDataPath
    /// </summary>
    /// <param name="targetPath">The target path where the file should be copied</param>
    private void CopyYamlFromStreamingAssets(string targetPath)
    {
        try
        {
#if UNITY_ANDROID && !UNITY_EDITOR
            // Load from StreamingAssets
            string streamingAssetsPath = Path.Combine(Application.streamingAssetsPath, yamlFileName);
            // On Android, StreamingAssets are in a JAR file, use UnityWebRequest
            StartCoroutine(LoadFromStreamingAssetsCoroutine(streamingAssetsPath, targetPath));
#endif
        }
        catch (Exception e)
        {
            Debug.Log($"Failed to copy video_source.yml file: {e.Message}");
            throw;
        }
    }

    /// <summary>
    /// Coroutine to load YAML file from StreamingAssets on Android
    /// </summary>
    private System.Collections.IEnumerator LoadFromStreamingAssetsCoroutine(string streamingAssetsPath,
        string targetPath)
    {
        using (UnityWebRequest www = UnityWebRequest.Get(streamingAssetsPath))
        {
            yield return www.SendWebRequest();

            if (www.result == UnityWebRequest.Result.Success)
            {
                try
                {
                    // Ensure the directory exists
                    string directory = Path.GetDirectoryName(targetPath);
                    if (!Directory.Exists(directory))
                    {
                        Directory.CreateDirectory(directory);
                    }

                    // Write the content to the target path
                    File.WriteAllText(targetPath, www.downloadHandler.text);
                    Debug.Log($"Successfully copied video_source.yml from StreamingAssets to {targetPath}");

                    // Load it
                    LoadConfiguration(targetPath);
                }
                catch (Exception e)
                {
                    Debug.LogError($"Failed to write YAML file from StreamingAssets: {e.Message}");
                }
            }
            else
            {
                Debug.Log($"Failed to load video_source.yml from StreamingAssets: {www.error}");
            }
        }
    }

    /// <summary>
    /// Get a video source by name
    /// </summary>
    /// <param name="name">Name of the video source (case-insensitive)</param>
    /// <returns>VideoSource object or null if not found</returns>
    public VideoSource GetVideoSource(string name)
    {
        if (!isInitialized || string.IsNullOrEmpty(name))
            return null;

        string upperName = name.ToUpper();
        return videoSources.ContainsKey(upperName) ? videoSources[upperName] : null;
    }

    /// <summary>
    /// Get a property value using dot notation (e.g., "PICO4U.visibleRatio")
    /// </summary>
    /// <typeparam name="T">The type to convert to</typeparam>
    /// <param name="propertyPath">Property path in format "VideoSourceName.PropertyName"</param>
    /// <returns>The typed value or default if not found</returns>
    public T GetProperty<T>(string propertyPath)
    {
        if (!isInitialized || string.IsNullOrEmpty(propertyPath))
            return default(T);

        string[] parts = propertyPath.Split('.');
        if (parts.Length != 2)
        {
            Debug.LogWarning(
                $"Invalid property path format: {propertyPath}. Expected format: 'VideoSourceName.PropertyName'");
            return default(T);
        }

        string videoSourceName = parts[0];
        string propertyName = parts[1];

        var videoSource = GetVideoSource(videoSourceName);
        if (videoSource == null)
        {
            Debug.LogWarning($"Video source not found: {videoSourceName}");
            return default(T);
        }

        return videoSource.GetPropertyValue<T>(propertyName);
    }

    /// <summary>
    /// Get a float property using dot notation
    /// </summary>
    /// <param name="propertyPath">Property path in format "VideoSourceName.PropertyName"</param>
    /// <returns>The float value or 0 if not found</returns>
    public float GetFloatProperty(string propertyPath)
    {
        return GetProperty<float>(propertyPath);
    }

    /// <summary>
    /// Get a string property using dot notation
    /// </summary>
    /// <param name="propertyPath">Property path in format "VideoSourceName.PropertyName"</param>
    /// <returns>The string value or empty string if not found</returns>
    public string GetStringProperty(string propertyPath)
    {
        return GetProperty<string>(propertyPath) ?? string.Empty;
    }

    /// <summary>
    /// Get an int property using dot notation
    /// </summary>
    /// <param name="propertyPath">Property path in format "VideoSourceName.PropertyName"</param>
    /// <returns>The int value or 0 if not found</returns>
    public int GetIntProperty(string propertyPath)
    {
        return GetProperty<int>(propertyPath);
    }

    /// <summary>
    /// Check if a property exists using dot notation
    /// </summary>
    /// <param name="propertyPath">Property path in format "VideoSourceName.PropertyName"</param>
    /// <returns>True if the property exists</returns>
    public bool HasProperty(string propertyPath)
    {
        if (!isInitialized || string.IsNullOrEmpty(propertyPath))
            return false;

        string[] parts = propertyPath.Split('.');
        if (parts.Length != 2)
            return false;

        string videoSourceName = parts[0];
        string propertyName = parts[1];

        var videoSource = GetVideoSource(videoSourceName);
        return videoSource?.HasProperty(propertyName) ?? false;
    }

    /// <summary>
    /// Get all video source names
    /// </summary>
    /// <returns>List of video source names</returns>
    public List<string> GetVideoSourceNames()
    {
        return isInitialized ? videoSources.Keys.ToList() : new List<string>();
    }

    /// <summary>
    /// Get all property names for a video source
    /// </summary>
    /// <param name="videoSourceName">Name of the video source</param>
    /// <returns>List of property names</returns>
    public List<string> GetPropertyNames(string videoSourceName)
    {
        var videoSource = GetVideoSource(videoSourceName);
        return videoSource?.GetPropertyNames() ?? new List<string>();
    }

    // Example usage methods for testing
    [ContextMenu("Test Configuration")]
    private void TestConfiguration()
    {
        if (!isInitialized)
        {
            Debug.LogWarning("Configuration not initialized");
            return;
        }

        // Test accessing PICO4U properties
        Debug.Log($"PICO4U.visibleRatio: {GetFloatProperty("PICO4U.visibleRatio")}");
        Debug.Log($"PICO4U.contentRatio: {GetFloatProperty("PICO4U.contentRatio")}");
        Debug.Log($"PICO4U.heightCompressionFactor: {GetFloatProperty("PICO4U.heightCompressionFactor")}");
        Debug.Log($"PICO4U.RawImageRectSize: {GetStringProperty("PICO4U.RawImageRectSize")}");
        Debug.Log($"PICO4U.CamWidth: {GetIntProperty("PICO4U.CamWidth")}");
        Debug.Log($"PICO4U.CamHeight: {GetIntProperty("PICO4U.CamHeight")}");
        Debug.Log($"PICO4U.CamFPS: {GetIntProperty("PICO4U.CamFPS")}");
        Debug.Log($"PICO4U.CamBitrate: {GetIntProperty("PICO4U.CamBitrate")}");

        // Test accessing ZEDMINI properties
        Debug.Log($"ZEDMINI.visibleRatio: {GetFloatProperty("ZEDMINI.visibleRatio")}");
        Debug.Log($"ZEDMINI.contentRatio: {GetFloatProperty("ZEDMINI.contentRatio")}");
        Debug.Log($"ZEDMINI.heightCompressionFactor: {GetFloatProperty("ZEDMINI.heightCompressionFactor")}");
        Debug.Log($"ZEDMINI.RawImageRectSize: {GetStringProperty("ZEDMINI.RawImageRectSize")}");
        Debug.Log($"ZEDMINI.CamWidth: {GetIntProperty("ZEDMINI.CamWidth")}");
        Debug.Log($"ZEDMINI.CamHeight: {GetIntProperty("ZEDMINI.CamHeight")}");
        Debug.Log($"ZEDMINI.CamFPS: {GetIntProperty("ZEDMINI.CamFPS")}");
        Debug.Log($"ZEDMINI.CamBitrate: {GetIntProperty("ZEDMINI.CamBitrate")}");

        // Test camera parameters
        SetVideoSource("PICO4U");
        var pico4uCamParams = CameraParameters;
        Debug.Log($"PICO4U Camera Parameters: {pico4uCamParams}");

        SetVideoSource("ZEDMINI");
        var zedminiCamParams = CameraParameters;
        Debug.Log($"ZEDMINI Camera Parameters: {zedminiCamParams}");

        // Test checking if properties exist
        Debug.Log($"Has PICO4U.visibleRatio: {HasProperty("PICO4U.visibleRatio")}");
        Debug.Log($"Has PICO4U.nonExistentProperty: {HasProperty("PICO4U.nonExistentProperty")}");
    }

    public VideoSource PICO4U
    {
        get => GetVideoSource("PICO4U");
    }

    public VideoSource ZEDMINI
    {
        get => GetVideoSource("ZEDMINI");
    }

    private VideoSource _currentVideoSource;

    public VideoSource CurrentVideoSource
    {
        get
        {
            // If no current video source is set, default to PICO4U
            if (_currentVideoSource == null && isInitialized)
            {
                _currentVideoSource = GetVideoSource("PICO4U");
            }

            return _currentVideoSource;
        }
    }

    public void SetVideoSource(VideoSource videoSource)
    {
        _currentVideoSource = videoSource;
    }

    public void SetVideoSource(string videoSourceName)
    {
        _currentVideoSource = GetVideoSource(videoSourceName);
    }

    public float VisibleRatio => CurrentVideoSource?.GetFloatProperty("visibleRatio") ?? 0f;
    public float ContentRatio => CurrentVideoSource?.GetFloatProperty("contentRatio") ?? 0f;
    public float HeightCompressionFactor => CurrentVideoSource?.GetFloatProperty("heightCompressionFactor") ?? 0f;
    public string RawImageRectSize => CurrentVideoSource?.GetStringProperty("RawImageRectSize") ?? string.Empty;

    /// <summary>
    /// Get camera parameters from the current video source
    /// </summary>
    public CameraParameters CameraParameters => CurrentVideoSource?.GetCameraParameters() ?? new CameraParameters();

    /// <summary>
    /// Get camera width from the current video source
    /// </summary>
    public int CamWidth => CurrentVideoSource?.GetIntProperty("CamWidth") ?? 1920;

    /// <summary>
    /// Get camera height from the current video source
    /// </summary>
    public int CamHeight => CurrentVideoSource?.GetIntProperty("CamHeight") ?? 1080;

    /// <summary>
    /// Get camera FPS from the current video source
    /// </summary>
    public int CamFPS => CurrentVideoSource?.GetIntProperty("CamFPS") ?? 30;

    /// <summary>
    /// Get camera bitrate from the current video source
    /// </summary>
    public int CamBitrate => CurrentVideoSource?.GetIntProperty("CamBitrate") ?? 5000000;

    public float RectWidth
    {
        get
        {
            if (string.IsNullOrEmpty(RawImageRectSize))
                return 0f;

            string[] parts = RawImageRectSize.Split('x');
            if (parts.Length < 2 || !float.TryParse(parts[0], out float width))
                return 0f;

            return width;
        }
    }

    public float RectHeight
    {
        get
        {
            if (string.IsNullOrEmpty(RawImageRectSize))
                return 0f;

            string[] parts = RawImageRectSize.Split('x');
            if (parts.Length < 2 || !float.TryParse(parts[1], out float height))
                return 0f;

            return height;
        }
    }
}
