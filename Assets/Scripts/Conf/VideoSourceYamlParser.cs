using System;
using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;
using UnityEngine;

public static class VideoSourceYamlParser
{
    /// <summary>
    /// Parse the video_source.yml file and return a list of VideoSource objects
    /// </summary>
    /// <param name="yamlFilePath">Path to the YAML file</param>
    /// <returns>List of parsed VideoSource objects</returns>
    public static List<VideoSource> ParseYamlFile(string yamlFilePath)
    {
        try
        {
            if (!File.Exists(yamlFilePath))
            {
                Debug.LogError($"YAML file not found: {yamlFilePath}");
                return new List<VideoSource>();
            }

            string yamlContent = File.ReadAllText(yamlFilePath);
            return ParseYamlContent(yamlContent);
        }
        catch (Exception e)
        {
            Debug.LogError($"Failed to parse YAML file {yamlFilePath}: {e.Message}");
            return new List<VideoSource>();
        }
    }

    /// <summary>
    /// Parse YAML content string and return a list of VideoSource objects
    /// </summary>
    /// <param name="yamlContent">YAML content as string</param>
    /// <returns>List of parsed VideoSource objects</returns>
    public static List<VideoSource> ParseYamlContent(string yamlContent)
    {
        var videoSources = new List<VideoSource>();

        try
        {
            // Split content into lines
            string[] lines = yamlContent.Split(new[] { '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries);

            VideoSource currentVideoSource = null;
            VideoSourceProperty currentProperty = null;
            bool inPropertiesSection = false;

            for (int i = 0; i < lines.Length; i++)
            {
                string line = lines[i];
                string trimmedLine = line.Trim();

                // Skip comments and empty lines
                if (string.IsNullOrEmpty(trimmedLine) || trimmedLine.StartsWith("#"))
                    continue;

                // Check for new video source (starts with "- name:" at the root level - no deep indentation)
                if (trimmedLine.StartsWith("- name:") && !line.StartsWith("    "))
                {
                    // Save previous property and video source if they exist
                    if (currentProperty != null && currentVideoSource != null)
                    {
                        currentVideoSource.AddProperty(currentProperty);
                        currentProperty = null;
                    }

                    if (currentVideoSource != null)
                    {
                        videoSources.Add(currentVideoSource);
                    }

                    // Create new video source
                    currentVideoSource = new VideoSource();
                    currentVideoSource.name = ExtractQuotedValue(trimmedLine);
                    inPropertiesSection = false;
                    currentProperty = null;
                    continue;
                }

                if (currentVideoSource == null)
                    continue;

                // Parse video source attributes
                if (trimmedLine.StartsWith("camera:"))
                {
                    currentVideoSource.camera = ExtractQuotedValue(trimmedLine);
                }
                else if (trimmedLine.StartsWith("description:"))
                {
                    currentVideoSource.description = ExtractQuotedValue(trimmedLine);
                }
                else if (trimmedLine.StartsWith("properties:"))
                {
                    inPropertiesSection = true;
                    // Save any pending property before entering new properties section
                    if (currentProperty != null)
                    {
                        currentVideoSource.AddProperty(currentProperty);
                        currentProperty = null;
                    }
                }
                else if (inPropertiesSection)
                {
                    // Parse properties - these should be indented with "    - name:"
                    if (trimmedLine.StartsWith("- name:") && line.StartsWith("    "))
                    {
                        // Save previous property if exists
                        if (currentProperty != null)
                        {
                            currentVideoSource.AddProperty(currentProperty);
                        }

                        // Create new property
                        currentProperty = new VideoSourceProperty("", "", "", null);
                        currentProperty.name = ExtractQuotedValue(trimmedLine);
                    }
                    else if (currentProperty != null)
                    {
                        if (trimmedLine.StartsWith("type:"))
                        {
                            currentProperty.type = ExtractQuotedValue(trimmedLine);
                        }
                        else if (trimmedLine.StartsWith("description:"))
                        {
                            currentProperty.description = ExtractQuotedValue(trimmedLine);
                        }
                        else if (trimmedLine.StartsWith("value:"))
                        {
                            currentProperty.value = ParseValue(trimmedLine, currentProperty.type);
                        }
                    }
                }
            }

            // Add the last property and video source
            if (currentProperty != null && currentVideoSource != null)
            {
                currentVideoSource.AddProperty(currentProperty);
            }

            if (currentVideoSource != null)
            {
                videoSources.Add(currentVideoSource);
            }
        }
        catch (Exception e)
        {
            Debug.LogError($"Failed to parse YAML content: {e.Message}");
        }

        return videoSources;
    }

    /// <summary>
    /// Extract quoted value from a YAML line
    /// </summary>
    private static string ExtractQuotedValue(string line)
    {
        // Match quoted strings
        var quotedMatch = Regex.Match(line, @"""([^""]*)""");
        if (quotedMatch.Success)
        {
            return quotedMatch.Groups[1].Value;
        }

        // Match single quoted strings
        var singleQuotedMatch = Regex.Match(line, @"'([^']*)'");
        if (singleQuotedMatch.Success)
        {
            return singleQuotedMatch.Groups[1].Value;
        }

        // Extract value after colon (unquoted)
        int colonIndex = line.IndexOf(':');
        if (colonIndex >= 0 && colonIndex < line.Length - 1)
        {
            return line.Substring(colonIndex + 1).Trim();
        }

        return "";
    }

    /// <summary>
    /// Parse a value based on its type
    /// </summary>
    private static object ParseValue(string line, string type)
    {
        string valueStr = ExtractQuotedValue(line);

        // Remove comments (anything after #)
        int commentIndex = valueStr.IndexOf('#');
        if (commentIndex >= 0)
        {
            valueStr = valueStr.Substring(0, commentIndex).Trim();
        }

        try
        {
            switch (type?.ToLower())
            {
                case "float":
                    return float.Parse(valueStr, System.Globalization.CultureInfo.InvariantCulture);
                case "double":
                    return double.Parse(valueStr, System.Globalization.CultureInfo.InvariantCulture);
                case "int":
                case "integer":
                    return int.Parse(valueStr);
                case "bool":
                case "boolean":
                    return bool.Parse(valueStr);
                case "string":
                default:
                    return valueStr;
            }
        }
        catch (Exception e)
        {
            Debug.LogWarning($"Failed to parse value '{valueStr}' as type '{type}': {e.Message}. Using string value.");
            return valueStr;
        }
    }
}
