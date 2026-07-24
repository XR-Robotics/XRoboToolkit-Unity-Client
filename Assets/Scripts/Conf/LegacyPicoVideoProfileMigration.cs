using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;

public static class LegacyPicoVideoProfileMigration
{
    private static readonly IReadOnlyDictionary<string, int> LegacyValues =
        new Dictionary<string, int>(StringComparer.OrdinalIgnoreCase)
        {
            { "CamWidth", 2160 },
            { "CamHeight", 810 },
            { "CamFPS", 60 },
            { "CamBitrate", 20 * 1024 * 1024 },
        };

    private static readonly IReadOnlyDictionary<string, int> LowLatencyValues =
        new Dictionary<string, int>(StringComparer.OrdinalIgnoreCase)
        {
            { "CamWidth", 1280 },
            { "CamHeight", 480 },
            { "CamFPS", 15 },
            { "CamBitrate", 1000000 },
        };

    public static bool TryMigrate(string yaml, out string migratedYaml)
    {
        migratedYaml = yaml;
        if (string.IsNullOrEmpty(yaml))
        {
            return false;
        }

        string[] lines = yaml.Split('\n');
        var valueLineByProperty = new Dictionary<string, int>(StringComparer.OrdinalIgnoreCase);
        var valueByProperty = new Dictionary<string, int>(StringComparer.OrdinalIgnoreCase);
        bool inPico4U = false;
        string currentProperty = null;

        for (int index = 0; index < lines.Length; index++)
        {
            string line = lines[index];
            string trimmed = line.Trim();
            bool isRootSource = trimmed.StartsWith("- name:", StringComparison.Ordinal) &&
                                line.Length > 0 &&
                                !char.IsWhiteSpace(line[0]);
            if (isRootSource)
            {
                inPico4U = string.Equals(
                    ExtractName(trimmed),
                    "PICO4U",
                    StringComparison.OrdinalIgnoreCase);
                currentProperty = null;
                continue;
            }

            if (!inPico4U)
            {
                continue;
            }

            if (trimmed.StartsWith("- name:", StringComparison.Ordinal))
            {
                currentProperty = ExtractName(trimmed);
                continue;
            }

            if (currentProperty == null ||
                !trimmed.StartsWith("value:", StringComparison.Ordinal) ||
                !LegacyValues.ContainsKey(currentProperty))
            {
                continue;
            }

            if (!TryParseIntValue(trimmed, out int value))
            {
                return false;
            }

            valueLineByProperty[currentProperty] = index;
            valueByProperty[currentProperty] = value;
            currentProperty = null;
        }

        foreach (KeyValuePair<string, int> expected in LegacyValues)
        {
            if (!valueByProperty.TryGetValue(expected.Key, out int actual) || actual != expected.Value)
            {
                return false;
            }
        }

        foreach (KeyValuePair<string, int> replacement in LowLatencyValues)
        {
            int lineIndex = valueLineByProperty[replacement.Key];
            lines[lineIndex] = Regex.Replace(
                lines[lineIndex],
                @"^(\s*value:\s*)[^\s#]+(.*)$",
                match =>
                    match.Groups[1].Value +
                    replacement.Value +
                    match.Groups[2].Value);
        }

        migratedYaml = string.Join("\n", lines);
        return true;
    }

    private static string ExtractName(string line)
    {
        int colonIndex = line.IndexOf(':');
        if (colonIndex < 0 || colonIndex == line.Length - 1)
        {
            return string.Empty;
        }

        return line.Substring(colonIndex + 1).Trim().Trim('"', '\'');
    }

    private static bool TryParseIntValue(string line, out int value)
    {
        int colonIndex = line.IndexOf(':');
        string raw = colonIndex >= 0 ? line.Substring(colonIndex + 1) : string.Empty;
        int commentIndex = raw.IndexOf('#');
        if (commentIndex >= 0)
        {
            raw = raw.Substring(0, commentIndex);
        }

        return int.TryParse(raw.Trim(), out value);
    }
}
