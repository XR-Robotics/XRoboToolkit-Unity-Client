# Video Source YAML Parser

This is a comprehensive YAML parser for the video_source.yml configuration file in Unity. It provides easy access to video source configurations using dot notation (e.g., `PICO4U.visibleRatio`).

## Features

- **Full YAML Parsing**: Parses the video_source.yml file into structured VideoSource objects
- **Type-Safe Property Access**: Automatic type conversion for float, int, string, and boolean values
- **Dot Notation Access**: Access properties using convenient syntax like `PICO4U.visibleRatio`
- **Error Handling**: Graceful handling of missing files, invalid syntax, and type conversion errors
- **Singleton Manager**: Easy-to-use singleton configuration manager
- **Unity Integration**: Designed specifically for Unity with proper logging and MonoBehaviour integration

## File Structure

- `VideoSourceProperty.cs` - Represents a single property with type-safe value access
- `VideoSource.cs` - Represents a video source with multiple properties
- `VideoSourceYamlParser.cs` - Static parser utility for YAML files
- `VideoSourceConfigManager.cs` - Singleton manager for easy configuration access
- `VideoSourceConfigExample.cs` - Example usage and testing script
- `CameraParameters.cs` - Camera configuration data structure
- `VideoSourceManager.cs` - Unity component for managing video source updates

## Setup

1. **Add the VideoSourceConfigManager to your scene**:
   - Create an empty GameObject in your scene
   - Add the `VideoSourceConfigManager` component to it
   - The manager will automatically find and parse the video_source.yml file

2. **YAML File Location**:
   The parser will look for `video_source.yml` in these locations (in order):
   - `StreamingAssets/Conf/video_source.yml`
   - `Assets/Scripts/Conf/video_source.yml`

## Usage Examples

### Basic Property Access (Dot Notation)

```csharp
// Get the singleton instance
var configManager = VideoSourceConfigManager.Instance;

// Access properties using dot notation
float visibleRatio = configManager.GetFloatProperty("PICO4U.visibleRatio");
float contentRatio = configManager.GetFloatProperty("PICO4U.contentRatio");
string rectSize = configManager.GetStringProperty("PICO4U.RawImageRectSize");

Debug.Log($"PICO4U visible ratio: {visibleRatio}"); // Output: 0.555
Debug.Log($"PICO4U content ratio: {contentRatio}"); // Output: 1.8
Debug.Log($"PICO4U rect size: {rectSize}"); // Output: "585.6x282.6"
```

### Video Source Object Access

```csharp
// Get a complete video source object
VideoSource pico4u = configManager.GetVideoSource("PICO4U");

if (pico4u != null)
{
    Debug.Log($"Name: {pico4u.name}");
    Debug.Log($"Type: {pico4u.type}");
    Debug.Log($"Description: {pico4u.description}");
    
    // Access properties through the object
    float visibleRatio = pico4u.GetFloatProperty("visibleRatio");
    
    // Check if a property exists
    bool hasProperty = pico4u.HasProperty("visibleRatio");
    
    // Get all property names
    List<string> propertyNames = pico4u.GetPropertyNames();
}
```

### Type-Safe Property Access

```csharp
// Generic type access
float floatValue = configManager.GetProperty<float>("PICO4U.visibleRatio");
string stringValue = configManager.GetProperty<string>("PICO4U.RawImageRectSize");
int intValue = configManager.GetProperty<int>("PICO4U.someIntProperty");

// Convenience methods
float floatValue2 = configManager.GetFloatProperty("PICO4U.visibleRatio");
string stringValue2 = configManager.GetStringProperty("PICO4U.RawImageRectSize");
int intValue2 = configManager.GetIntProperty("PICO4U.someIntProperty");
```

### Camera Parameters Access

```csharp
// Get camera parameters from current video source
var cameraParams = configManager.CameraParameters;
Debug.Log($"Resolution: {cameraParams.width}x{cameraParams.height}");
Debug.Log($"Frame Rate: {cameraParams.fps} FPS");
Debug.Log($"Bitrate: {cameraParams.BitrateInMbps:F1} Mbps");
Debug.Log($"Aspect Ratio: {cameraParams.AspectRatio:F2}");

// Get individual camera properties
int width = configManager.CamWidth;
int height = configManager.CamHeight;
int fps = configManager.CamFPS;
int bitrate = configManager.CamBitrate;

// Access camera parameters from a specific video source
VideoSource pico4u = configManager.GetVideoSource("PICO4U");
var pico4uCamParams = pico4u.GetCameraParameters();
```

### Video Source Management

```csharp
// Set current video source
configManager.SetVideoSource("PICO4U");
// or
configManager.SetVideoSource(pico4uVideoSource);

// Access properties from current video source
float visibleRatio = configManager.VisibleRatio;
float contentRatio = configManager.ContentRatio;
var cameraParams = configManager.CameraParameters;
```

### Direct YAML Parsing (Advanced)

```csharp
// Parse YAML file directly without the manager
string yamlPath = "path/to/video_source.yml";
List<VideoSource> videoSources = VideoSourceYamlParser.ParseYamlFile(yamlPath);

// Parse YAML content from string
string yamlContent = "..."; // YAML content as string
List<VideoSource> videoSources2 = VideoSourceYamlParser.ParseYamlContent(yamlContent);
```

### Property Existence Checking

```csharp
// Check if a property exists before using it
if (configManager.HasProperty("PICO4U.visibleRatio"))
{
    float ratio = configManager.GetFloatProperty("PICO4U.visibleRatio");
    // Use the ratio...
}

// Get all video source names
List<string> videoSourceNames = configManager.GetVideoSourceNames();

// Get all property names for a specific video source
List<string> propertyNames = configManager.GetPropertyNames("PICO4U");
```

## Error Handling

The parser includes comprehensive error handling:

- **Missing Files**: Returns empty collections with warning logs
- **Invalid YAML Syntax**: Logs errors and continues parsing what it can
- **Type Conversion Errors**: Falls back to string values with warnings
- **Missing Properties**: Returns default values (0 for numbers, empty string for strings)
- **Invalid Property Paths**: Logs warnings and returns default values

## Supported YAML Format

The parser expects YAML in this format:

```yaml
# Video Stream Source Configuration
- name: "PICO4U"
  type: "VR"
  description: "PICO4U Video Stream Source"
  properties:
    - name: "visibleRatio"
      type: "float"
      description: "Visible ratio for the shader"
      value: 0.555
    - name: "contentRatio"
      type: "float" 
      description: "Content ratio for the shader"
      value: 1.8
    - name: "CamWidth"
      type: "int"
      description: "Camera width for the video stream"
      value: 1920
    - name: "CamHeight"
      type: "int"
      description: "Camera height for the video stream"
      value: 960
    - name: "CamFPS"
      type: "int"
      description: "Frame rate of the video stream in FPS"
      value: 60
    - name: "CamBitrate"
      type: "int"
      description: "Bitrate of the video stream in Kbps"
      value: 20971520
    # ... more properties

- name: "ZEDMINI"
  type: "ZED"
  # ... more video sources
```

## Supported Property Types

- `float` - Floating point numbers
- `double` - Double precision numbers  
- `int` / `integer` - Integer numbers
- `bool` / `boolean` - Boolean values
- `string` - Text values (default if no type specified)

## Testing

Use the `VideoSourceConfigExample` script to test the configuration:

1. Add the example script to any GameObject
2. Check "Test On Start" in the inspector, or
3. Use the context menu "Test Video Source Configuration" to run tests manually

The example script will:
- Test dot notation property access
- Test video source object access  
- Test error handling for invalid properties
- Demonstrate real-world usage scenarios

## Performance Notes

- The YAML file is parsed once during initialization
- All video sources are stored in a dictionary for O(1) lookup
- Property access within a video source is O(n) where n is the number of properties
- Consider caching frequently accessed values if performance is critical

## Thread Safety

The VideoSourceConfigManager is designed to be used from the main Unity thread. The parsed data is read-only after initialization, making it safe for multiple readers.
