using System.IO;
using System.Text.RegularExpressions;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    public static class AndroidLibraryNamespacePatcher
    {
        public const string AndroidLibraryNamespace = "com.iconfeature.iconconfigurator";

        public static bool PatchBuildGradleFile(string buildGradlePath)
        {
            if (string.IsNullOrWhiteSpace(buildGradlePath) || !File.Exists(buildGradlePath))
            {
                return false;
            }

            string content = File.ReadAllText(buildGradlePath);
            if (Regex.IsMatch(content, @"(?m)^\s*namespace\s+[""']"))
            {
                // If there's an existing namespace, replace it to avoid conflicts
                string updated = Regex.Replace(content, @"(?m)^(\s*)namespace\s+[""'][^""']+[""']", $"$1namespace \"{AndroidLibraryNamespace}\"");
                if (updated != content)
                {
                    File.WriteAllText(buildGradlePath, updated);
                    return true;
                }
                return false;
            }

            Match androidBlockMatch = Regex.Match(content, @"(?m)^(\s*)android[^\S\r\n]*\{[^\S\r\n]*(\r?\n|$)");
            if (!androidBlockMatch.Success)
            {
                return false;
            }

            string newline = content.Contains("\r\n") ? "\r\n" : "\n";
            string indent = androidBlockMatch.Groups[1].Value;
            string androidLine = androidBlockMatch.Value.TrimEnd('\r', '\n');
            string updatedContent = content.Remove(androidBlockMatch.Index, androidBlockMatch.Length)
                .Insert(androidBlockMatch.Index, $"{androidLine}{newline}{indent}    namespace \"{AndroidLibraryNamespace}\"{newline}");
            File.WriteAllText(buildGradlePath, updatedContent);
            return true;
        }
    }
}
