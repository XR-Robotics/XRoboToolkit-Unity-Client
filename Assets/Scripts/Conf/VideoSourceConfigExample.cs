using UnityEngine;

/// <summary>
/// Example script demonstrating how to use the VideoSource YAML parser
/// </summary>
public class VideoSourceConfigExample : MonoBehaviour
{
    [Header("Test Configuration")]
    [SerializeField] private bool testOnStart = true;

    private void Start()
    {
        if (testOnStart)
        {
            TestVideoSourceConfiguration();
        }
    }

    /// <summary>
    /// Test the video source configuration system
    /// </summary>
    [ContextMenu("Test Video Source Configuration")]
    public void TestVideoSourceConfiguration()
    {
        Debug.Log("=== Testing Video Source Configuration ===");

        // Wait for the config manager to initialize if it exists
        var configManager = VideoSourceConfigManager.Instance;
        if (configManager == null)
        {
            Debug.LogWarning("VideoSourceConfigManager not found. Make sure it's in the scene.");
            return;
        }

        // Test direct property access using dot notation
        TestDotNotationAccess();

        // Test video source object access
        TestVideoSourceAccess();

        // Test camera parameters
        TestCameraParameters();

        // Test error handling
        TestErrorHandling();
    }

    private void TestDotNotationAccess()
    {
        Debug.Log("--- Testing Dot Notation Access ---");

        var configManager = VideoSourceConfigManager.Instance;

        // Test PICO4U properties
        float pico4uVisibleRatio = configManager.GetFloatProperty("PICO4U.visibleRatio");
        float pico4uContentRatio = configManager.GetFloatProperty("PICO4U.contentRatio");
        float pico4uHeightCompression = configManager.GetFloatProperty("PICO4U.heightCompressionFactor");
        string pico4uRectSize = configManager.GetStringProperty("PICO4U.RawImageRectSize");
        int pico4uCamWidth = configManager.GetIntProperty("PICO4U.CamWidth");
        int pico4uCamHeight = configManager.GetIntProperty("PICO4U.CamHeight");
        int pico4uCamFPS = configManager.GetIntProperty("PICO4U.CamFPS");
        int pico4uCamBitrate = configManager.GetIntProperty("PICO4U.CamBitrate");

        Debug.Log($"PICO4U.visibleRatio: {pico4uVisibleRatio}");
        Debug.Log($"PICO4U.contentRatio: {pico4uContentRatio}");
        Debug.Log($"PICO4U.heightCompressionFactor: {pico4uHeightCompression}");
        Debug.Log($"PICO4U.RawImageRectSize: {pico4uRectSize}");
        Debug.Log($"PICO4U.CamWidth: {pico4uCamWidth}");
        Debug.Log($"PICO4U.CamHeight: {pico4uCamHeight}");
        Debug.Log($"PICO4U.CamFPS: {pico4uCamFPS}");
        Debug.Log($"PICO4U.CamBitrate: {pico4uCamBitrate}");

        // Test ZEDMINI properties
        float zedminiVisibleRatio = configManager.GetFloatProperty("ZEDMINI.visibleRatio");
        float zedminiContentRatio = configManager.GetFloatProperty("ZEDMINI.contentRatio");
        string zedminiRectSize = configManager.GetStringProperty("ZEDMINI.RawImageRectSize");
        int zedminiCamWidth = configManager.GetIntProperty("ZEDMINI.CamWidth");
        int zedminiCamHeight = configManager.GetIntProperty("ZEDMINI.CamHeight");

        Debug.Log($"ZEDMINI.visibleRatio: {zedminiVisibleRatio}");
        Debug.Log($"ZEDMINI.contentRatio: {zedminiContentRatio}");
        Debug.Log($"ZEDMINI.RawImageRectSize: {zedminiRectSize}");
        Debug.Log($"ZEDMINI.CamWidth: {zedminiCamWidth}");
        Debug.Log($"ZEDMINI.CamHeight: {zedminiCamHeight}");
    }

    private void TestVideoSourceAccess()
    {
        Debug.Log("--- Testing VideoSource Object Access ---");

        var configManager = VideoSourceConfigManager.Instance;

        // Get PICO4U video source
        VideoSource pico4u = configManager.GetVideoSource("PICO4U");
        if (pico4u != null)
        {
            Debug.Log($"VideoSource: {pico4u.name}, Type: {pico4u.camera}, Description: {pico4u.description}");
            Debug.Log($"Properties count: {pico4u.properties.Count}");

            foreach (var property in pico4u.properties)
            {
                Debug.Log($"  Property: {property.name} ({property.type}) = {property.value}");
            }
        }

        // Get ZEDMINI video source
        VideoSource zedmini = configManager.GetVideoSource("ZEDMINI");
        if (zedmini != null)
        {
            Debug.Log($"VideoSource: {zedmini.name}, Type: {zedmini.camera}, Description: {zedmini.description}");

            // Test property search
            var visibleRatioProperty = zedmini.GetProperty("visibleRatio");
            if (visibleRatioProperty != null)
            {
                Debug.Log($"Found property: {visibleRatioProperty.name} = {visibleRatioProperty.AsFloat()}");
            }
        }
    }

    private void TestCameraParameters()
    {
        Debug.Log("--- Testing Camera Parameters ---");

        var configManager = VideoSourceConfigManager.Instance;

        // Test PICO4U camera parameters
        configManager.SetVideoSource("PICO4U");
        var pico4uCamParams = configManager.CameraParameters;
        Debug.Log($"PICO4U Camera Parameters: {pico4uCamParams}");
        Debug.Log($"PICO4U Aspect Ratio: {pico4uCamParams.AspectRatio:F2}");
        Debug.Log($"PICO4U Total Pixels: {pico4uCamParams.TotalPixels:N0}");
        Debug.Log($"PICO4U Is Valid: {pico4uCamParams.IsValid}");

        // Test ZEDMINI camera parameters
        configManager.SetVideoSource("ZEDMINI");
        var zedminiCamParams = configManager.CameraParameters;
        Debug.Log($"ZEDMINI Camera Parameters: {zedminiCamParams}");
        Debug.Log($"ZEDMINI Aspect Ratio: {zedminiCamParams.AspectRatio:F2}");
        Debug.Log($"ZEDMINI Total Pixels: {zedminiCamParams.TotalPixels:N0}");
        Debug.Log($"ZEDMINI Is Valid: {zedminiCamParams.IsValid}");

        // Test individual camera properties through config manager
        Debug.Log($"Current CamWidth: {configManager.CamWidth}");
        Debug.Log($"Current CamHeight: {configManager.CamHeight}");
        Debug.Log($"Current CamFPS: {configManager.CamFPS}");
        Debug.Log($"Current CamBitrate: {configManager.CamBitrate}");
    }

    private void TestErrorHandling()
    {
        Debug.Log("--- Testing Error Handling ---");

        var configManager = VideoSourceConfigManager.Instance;

        // Test non-existent video source
        float nonExistentValue = configManager.GetFloatProperty("NONEXISTENT.visibleRatio");
        Debug.Log($"Non-existent video source property: {nonExistentValue} (should be 0)");

        // Test non-existent property
        float nonExistentProperty = configManager.GetFloatProperty("PICO4U.nonExistentProperty");
        Debug.Log($"Non-existent property: {nonExistentProperty} (should be 0)");

        // Test invalid property path format
        float invalidPath = configManager.GetFloatProperty("INVALID_PATH");
        Debug.Log($"Invalid property path: {invalidPath} (should be 0)");

        // Test property existence checks
        bool existsValid = configManager.HasProperty("PICO4U.visibleRatio");
        bool existsInvalid = configManager.HasProperty("PICO4U.nonExistent");
        Debug.Log($"PICO4U.visibleRatio exists: {existsValid} (should be true)");
        Debug.Log($"PICO4U.nonExistent exists: {existsInvalid} (should be false)");
    }

    /// <summary>
    /// Example of how to use the configuration in a real scenario
    /// </summary>
    public void ConfigureVideoStreamForDevice(string deviceName)
    {
        var configManager = VideoSourceConfigManager.Instance;
        if (configManager == null)
        {
            Debug.LogError("VideoSourceConfigManager not available");
            return;
        }

        // Get configuration for the specified device
        VideoSource deviceConfig = configManager.GetVideoSource(deviceName);
        if (deviceConfig == null)
        {
            Debug.LogError($"No configuration found for device: {deviceName}");
            return;
        }

        // Set as current video source
        configManager.SetVideoSource(deviceConfig);

        // Get shader configuration
        float visibleRatio = deviceConfig.GetFloatProperty("visibleRatio");
        float contentRatio = deviceConfig.GetFloatProperty("contentRatio");
        float heightCompression = deviceConfig.GetFloatProperty("heightCompressionFactor");
        string rectSize = deviceConfig.GetStringProperty("RawImageRectSize");

        // Get camera configuration
        var cameraParams = deviceConfig.GetCameraParameters();

        Debug.Log($"Configuring video stream for {deviceName}:");
        Debug.Log($"  Shader Settings:");
        Debug.Log($"    Visible Ratio: {visibleRatio}");
        Debug.Log($"    Content Ratio: {contentRatio}");
        Debug.Log($"    Height Compression: {heightCompression}");
        Debug.Log($"    Rect Size: {rectSize}");
        Debug.Log($"  Camera Settings:");
        Debug.Log($"    Resolution: {cameraParams.width}x{cameraParams.height}");
        Debug.Log($"    Frame Rate: {cameraParams.fps} FPS");
        Debug.Log($"    Bitrate: {cameraParams.BitrateInMbps:F1} Mbps");
        Debug.Log($"    Aspect Ratio: {cameraParams.AspectRatio:F2}");

        // Here you would apply these values to your video streaming components
        // For example:
        // shaderMaterial.SetFloat("_VisibleRatio", visibleRatio);
        // shaderMaterial.SetFloat("_ContentRatio", contentRatio);
        // cameraComponent.width = cameraParams.width;
        // cameraComponent.height = cameraParams.height;
        // cameraComponent.frameRate = cameraParams.fps;
        // cameraComponent.bitrate = cameraParams.bitrate;
        // etc.
    }
}
