using System;
using System.Collections.Generic;
using System.Linq;

[Serializable]
public class VideoSource
{
    public string name;
    public string camera;
    public string description;
    public List<VideoSourceProperty> properties;

    public VideoSource()
    {
        properties = new List<VideoSourceProperty>();
    }

    public VideoSource(string name, string camera, string description)
    {
        this.name = name;
        this.camera = camera;
        this.description = description;
        this.properties = new List<VideoSourceProperty>();
    }

    /// <summary>
    /// Add a property to this video source
    /// </summary>
    public void AddProperty(VideoSourceProperty property)
    {
        properties.Add(property);
    }

    /// <summary>
    /// Get a property by name
    /// </summary>
    /// <param name="propertyName">Name of the property</param>
    /// <returns>The property or null if not found</returns>
    public VideoSourceProperty GetProperty(string propertyName)
    {
        return properties.FirstOrDefault(p => p.name.Equals(propertyName, StringComparison.OrdinalIgnoreCase));
    }

    /// <summary>
    /// Get a property value by name with type conversion
    /// </summary>
    /// <typeparam name="T">The type to convert to</typeparam>
    /// <param name="propertyName">Name of the property</param>
    /// <returns>The typed value or default if not found</returns>
    public T GetPropertyValue<T>(string propertyName)
    {
        var property = GetProperty(propertyName);
        return property != null ? property.GetValue<T>() : default(T);
    }

    /// <summary>
    /// Get a property value as float (common use case)
    /// </summary>
    /// <param name="propertyName">Name of the property</param>
    /// <returns>The float value or 0 if not found</returns>
    public float GetFloatProperty(string propertyName)
    {
        return GetPropertyValue<float>(propertyName);
    }

    /// <summary>
    /// Get a property value as string
    /// </summary>
    /// <param name="propertyName">Name of the property</param>
    /// <returns>The string value or empty string if not found</returns>
    public string GetStringProperty(string propertyName)
    {
        return GetPropertyValue<string>(propertyName) ?? string.Empty;
    }

    /// <summary>
    /// Check if a property exists
    /// </summary>
    /// <param name="propertyName">Name of the property</param>
    /// <returns>True if the property exists</returns>
    public bool HasProperty(string propertyName)
    {
        return GetProperty(propertyName) != null;
    }

    /// <summary>
    /// Get all property names
    /// </summary>
    /// <returns>List of property names</returns>
    public List<string> GetPropertyNames()
    {
        return properties.Select(p => p.name).ToList();
    }

    /// <summary>
    /// Get camera parameters from this video source
    /// </summary>
    /// <returns>CameraParameters object with camera settings</returns>
    public CameraParameters GetCameraParameters()
    {
        return CameraParameters.FromVideoSource(this);
    }

    /// <summary>
    /// Get a property value as int (common use case)
    /// </summary>
    /// <param name="propertyName">Name of the property</param>
    /// <returns>The int value or 0 if not found</returns>
    public int GetIntProperty(string propertyName)
    {
        return GetPropertyValue<int>(propertyName);
    }
}
