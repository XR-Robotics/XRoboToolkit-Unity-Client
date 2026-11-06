using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text.RegularExpressions;
using System.Xml.Linq;
using UnityEditor;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    public class AndroidManifestExportAdapter : IIconExportAdapter
    {
        private const string k_ApplicationElementName = "application";
        private const string k_ActivityElementName = "activity";
        private const string k_IntentFilterElementName = "intent-filter";
        private const string k_ActionElementName = "action";
        private const string k_CategoryElementName = "category";
        private const string k_MetaDataElementName = "meta-data";
        private const string k_DefaultUnityActivityName = "com.unity3d.player.UnityPlayerActivity";
        private const string k_UnityGameActivityName = "com.unity3d.player.UnityPlayerGameActivity";
        private const string k_UnityPlayerActivityMetadataName = "unityplayer.UnityActivity";
        private const string k_GameActivityLibMetadataName = "android.app.lib_name";
        private const string k_MainActionName = "android.intent.action.MAIN";
        private const string k_LauncherCategoryName = "android.intent.category.LAUNCHER";
        private const string k_Icon3DListName = "icon.3d.list";
        private const string k_SdfListName = "icon.sdf.list";

        private static readonly XNamespace s_androidNamespace = "http://schemas.android.com/apk/res/android";
        private static readonly XNamespace s_toolsNamespace = "http://schemas.android.com/tools";
        private readonly string m_manifestPath;
        private readonly string m_launcherManifestPath;
        private readonly bool m_updatePlayerSettings;

        public AndroidManifestExportAdapter()
            : this(
                IconConfiguratorPaths.AndroidManifestPath,
                IconConfiguratorPaths.AndroidLauncherManifestPath,
                true)
        {
        }

        public AndroidManifestExportAdapter(string manifestPath)
            : this(manifestPath, manifestPath, false)
        {
        }

        public AndroidManifestExportAdapter(
            string manifestPath,
            string launcherManifestPath,
            bool updatePlayerSettings)
        {
            m_manifestPath = manifestPath;
            m_launcherManifestPath = launcherManifestPath;
            m_updatePlayerSettings = updatePlayerSettings;
        }

        public void Apply(IconApplyPayload payload)
        {
            PatchMainManifest();
            PatchLauncherManifest();

            if (m_updatePlayerSettings)
            {
                TrySetAndroidBoolProperty("useCustomMainManifest", true);
                TrySetAndroidBoolProperty("useCustomLauncherManifest", true);
                EnsureProjectSettingsFlag("useCustomMainManifest");
                EnsureProjectSettingsFlag("useCustomLauncherManifest");
            }
        }

        private void PatchMainManifest()
        {
            XDocument document = LoadOrCreateManifest(m_manifestPath);
            XElement manifest = document.Root ?? CreateManifestRoot(document);
            EnsureAndroidNamespace(manifest);
            XElement application = EnsureApplication(manifest);
            EnsureLauncherActivities(application);
            SaveManifest(document, m_manifestPath);
        }

        private void PatchLauncherManifest()
        {
            XDocument document = LoadOrCreateManifest(m_launcherManifestPath);
            XElement manifest = document.Root ?? CreateManifestRoot(document);
            EnsureAndroidNamespace(manifest);
            EnsureToolsNamespace(manifest);

            XElement application = EnsureApplication(manifest);
            application.SetAttributeValue(s_androidNamespace + "icon", "@mipmap/ic_spatial_launcher");
            application.SetAttributeValue(s_androidNamespace + "label", IconConfiguratorAndroidResources.AppNameReference);
            application.SetAttributeValue(s_androidNamespace + "localeConfig", "@xml/locales_config");
            application.SetAttributeValue(s_toolsNamespace + "replace", "android:icon,android:label");

            EnsureLauncherActivities(application);
            UpsertMetadata(application, k_Icon3DListName, "@array/icon_3d_list");
            UpsertMetadata(application, k_SdfListName, "@array/icon_sdf_list");

            SaveManifest(document, m_launcherManifestPath);
        }

        private static XDocument LoadOrCreateManifest(string manifestPath)
        {
            EnsureFolder(Path.GetDirectoryName(manifestPath)?.Replace("\\", "/"));
            return File.Exists(manifestPath)
                ? XDocument.Load(manifestPath)
                : CreateDefaultManifest();
        }

        private static XElement EnsureApplication(XElement manifest)
        {
            XElement application = manifest.Element(k_ApplicationElementName);
            if (application == null)
            {
                application = new XElement(k_ApplicationElementName);
                manifest.Add(application);
            }

            return application;
        }

        private static void EnsureLauncherActivities(XElement application)
        {
            XElement customLauncherActivity = FindCustomLauncherActivity(application);
            if (customLauncherActivity != null)
            {
                customLauncherActivity.SetAttributeValue(s_androidNamespace + "exported", "true");
                EnsureLauncherIntentFilter(customLauncherActivity);
                return;
            }

            string[] activityNames = GetUnityLauncherActivityNames();
            for (int i = 0; i < activityNames.Length; i++)
            {
                XElement activity = FindActivityByName(application, activityNames[i])
                    ?? CreateUnityActivity(application, activityNames[i]);

                activity.SetAttributeValue(s_androidNamespace + "exported", "true");
                EnsureUnityActivityDefaults(activity);
                EnsureLauncherIntentFilter(activity);
                UpsertMetadataValue(activity, k_UnityPlayerActivityMetadataName, "true");
            }
        }

        private static XElement FindCustomLauncherActivity(XElement application)
        {
            return application.Elements(k_ActivityElementName).FirstOrDefault(activity =>
                !IsUnityActivity(activity) &&
                activity.Elements(k_IntentFilterElementName).Any(HasLauncherIntentFilter));
        }

        private static XElement FindActivityByName(XElement application, string activityName)
        {
            return application.Elements(k_ActivityElementName)
                .FirstOrDefault(activity => IsActivityNamed(activity, activityName));
        }

        private static XElement CreateUnityActivity(XElement application, string activityName)
        {
            XElement activity = new XElement(
                k_ActivityElementName,
                new XAttribute(s_androidNamespace + "name", activityName));
            application.Add(activity);
            return activity;
        }

        private static string[] GetUnityLauncherActivityNames()
        {
            PropertyInfo property = typeof(PlayerSettings.Android).GetProperty(
                "applicationEntry",
                BindingFlags.Public | BindingFlags.Static);

            if (property == null || !property.CanRead)
            {
                return new[] { k_DefaultUnityActivityName };
            }

            object applicationEntry = property.GetValue(null);
            if (applicationEntry == null)
            {
                return new[] { k_DefaultUnityActivityName };
            }

            bool hasActivityEntry = HasApplicationEntryFlag(applicationEntry, "Activity");
            bool hasGameActivityEntry = HasApplicationEntryFlag(applicationEntry, "GameActivity");
            List<string> activityNames = new List<string>(2);

            if (hasActivityEntry || !hasGameActivityEntry)
            {
                activityNames.Add(k_DefaultUnityActivityName);
            }

            if (hasGameActivityEntry)
            {
                activityNames.Add(k_UnityGameActivityName);
            }

            return activityNames.ToArray();
        }

        private static bool HasApplicationEntryFlag(object applicationEntry, string flagName)
        {
            Type entryType = applicationEntry.GetType();
            if (!entryType.IsEnum)
            {
                return false;
            }

            try
            {
                object flag = Enum.Parse(entryType, flagName);
                long entryValue = Convert.ToInt64(applicationEntry);
                long flagValue = Convert.ToInt64(flag);
                return (entryValue & flagValue) == flagValue;
            }
            catch (ArgumentException)
            {
                return false;
            }
            catch (InvalidCastException)
            {
                return false;
            }
        }

        private static void EnsureUnityActivityDefaults(XElement activity)
        {
            string activityName = activity.Attribute(s_androidNamespace + "name")?.Value;
            if (string.Equals(activityName, k_DefaultUnityActivityName, StringComparison.Ordinal) &&
                activity.Attribute(s_androidNamespace + "theme") == null)
            {
                activity.SetAttributeValue(s_androidNamespace + "theme", "@style/UnityThemeSelector");
                return;
            }

            if (!string.Equals(activityName, k_UnityGameActivityName, StringComparison.Ordinal))
            {
                return;
            }

            if (activity.Attribute(s_androidNamespace + "theme") == null)
            {
                activity.SetAttributeValue(s_androidNamespace + "theme", "@style/BaseUnityGameActivityTheme");
            }

            UpsertMetadataValue(activity, k_GameActivityLibMetadataName, "game");
        }

        private static void EnsureLauncherIntentFilter(XElement activity)
        {
            XElement intentFilter = activity.Elements(k_IntentFilterElementName)
                .FirstOrDefault(HasLauncherIntentFilter)
                ?? activity.Elements(k_IntentFilterElementName)
                    .FirstOrDefault(HasPartialLauncherIntentFilter);

            if (intentFilter == null)
            {
                intentFilter = new XElement(k_IntentFilterElementName);
                activity.Add(intentFilter);
            }

            EnsureIntentAction(intentFilter, k_MainActionName);
            EnsureIntentCategory(intentFilter, k_LauncherCategoryName);
        }

        private static bool HasLauncherIntentFilter(XElement intentFilter)
        {
            return HasIntentAction(intentFilter, k_MainActionName) &&
                HasIntentCategory(intentFilter, k_LauncherCategoryName);
        }

        private static bool HasPartialLauncherIntentFilter(XElement intentFilter)
        {
            return HasIntentAction(intentFilter, k_MainActionName) ||
                HasIntentCategory(intentFilter, k_LauncherCategoryName);
        }

        private static bool HasIntentAction(XElement intentFilter, string actionName)
        {
            return intentFilter.Elements(k_ActionElementName).Any(element =>
                string.Equals(element.Attribute(s_androidNamespace + "name")?.Value, actionName, StringComparison.Ordinal));
        }

        private static bool HasIntentCategory(XElement intentFilter, string categoryName)
        {
            return intentFilter.Elements(k_CategoryElementName).Any(element =>
                string.Equals(element.Attribute(s_androidNamespace + "name")?.Value, categoryName, StringComparison.Ordinal));
        }

        private static void EnsureIntentAction(XElement intentFilter, string actionName)
        {
            if (HasIntentAction(intentFilter, actionName))
            {
                return;
            }

            intentFilter.Add(new XElement(
                k_ActionElementName,
                new XAttribute(s_androidNamespace + "name", actionName)));
        }

        private static void EnsureIntentCategory(XElement intentFilter, string categoryName)
        {
            if (HasIntentCategory(intentFilter, categoryName))
            {
                return;
            }

            intentFilter.Add(new XElement(
                k_CategoryElementName,
                new XAttribute(s_androidNamespace + "name", categoryName)));
        }

        private static bool IsActivityNamed(XElement activity, string activityName)
        {
            return string.Equals(
                activity.Attribute(s_androidNamespace + "name")?.Value,
                activityName,
                StringComparison.Ordinal);
        }

        private static bool HasUnityActivityMetadata(XElement activity)
        {
            return activity.Elements(k_MetaDataElementName).Any(element =>
                string.Equals(
                    element.Attribute(s_androidNamespace + "name")?.Value,
                    k_UnityPlayerActivityMetadataName,
                    StringComparison.Ordinal));
        }

        private static bool ShouldMarkUnityActivity(XElement activity)
        {
            return IsUnityActivity(activity);
        }

        private static bool IsUnityActivity(XElement activity)
        {
            return IsActivityNamed(activity, k_DefaultUnityActivityName) ||
                IsActivityNamed(activity, k_UnityGameActivityName) ||
                HasUnityActivityMetadata(activity);
        }

        private static void SaveManifest(XDocument document, string manifestPath)
        {
            EnsureFolder(Path.GetDirectoryName(manifestPath)?.Replace("\\", "/"));
            document.Save(manifestPath);
            AssetDatabase.ImportAsset(manifestPath, ImportAssetOptions.ForceSynchronousImport);
        }

        private static XDocument CreateDefaultManifest()
        {
            return new XDocument(
                new XDeclaration("1.0", "utf-8", null),
                new XElement(
                    "manifest",
                    new XAttribute(XNamespace.Xmlns + "android", s_androidNamespace.NamespaceName),
                    new XElement(k_ApplicationElementName)));
        }

        private static XElement CreateManifestRoot(XDocument document)
        {
            XElement manifest = new XElement("manifest");
            document.Add(manifest);
            return manifest;
        }

        private static void EnsureAndroidNamespace(XElement manifest)
        {
            XAttribute namespaceAttribute = manifest.Attribute(XNamespace.Xmlns + "android");
            if (namespaceAttribute == null)
            {
                manifest.SetAttributeValue(XNamespace.Xmlns + "android", s_androidNamespace.NamespaceName);
            }
        }

        private static void EnsureToolsNamespace(XElement manifest)
        {
            XAttribute namespaceAttribute = manifest.Attribute(XNamespace.Xmlns + "tools");
            if (namespaceAttribute == null)
            {
                manifest.SetAttributeValue(XNamespace.Xmlns + "tools", s_toolsNamespace.NamespaceName);
            }
        }

        private static void UpsertMetadata(XElement application, string name, string resource)
        {
            XElement metadata = application.Elements(k_MetaDataElementName)
                .FirstOrDefault(element => element.Attribute(s_androidNamespace + "name")?.Value == name);

            if (metadata == null)
            {
                metadata = new XElement(k_MetaDataElementName);
                application.Add(metadata);
            }

            metadata.SetAttributeValue(s_androidNamespace + "name", name);
            metadata.SetAttributeValue(s_androidNamespace + "resource", resource);
        }

        private static void UpsertMetadataValue(XElement parent, string name, string value)
        {
            XElement metadata = parent.Elements(k_MetaDataElementName)
                .FirstOrDefault(element => element.Attribute(s_androidNamespace + "name")?.Value == name);

            if (metadata == null)
            {
                metadata = new XElement(k_MetaDataElementName);
                parent.Add(metadata);
            }

            metadata.SetAttributeValue(s_androidNamespace + "name", name);
            metadata.SetAttributeValue(s_androidNamespace + "value", value);
        }

        private static void TrySetAndroidBoolProperty(string propertyName, bool value)
        {
            PropertyInfo property = typeof(PlayerSettings.Android).GetProperty(
                propertyName,
                BindingFlags.Public | BindingFlags.Static);

            if (property == null || property.PropertyType != typeof(bool) || !property.CanWrite)
            {
                return;
            }

            property.SetValue(null, value);
        }

        private static void EnsureProjectSettingsFlag(string flagName)
        {
            const string projectSettingsPath = "ProjectSettings/ProjectSettings.asset";
            if (!File.Exists(projectSettingsPath))
            {
                return;
            }

            string content = File.ReadAllText(projectSettingsPath);
            string pattern = $@"(?m)^(\s*{Regex.Escape(flagName)}:\s*)\d+\s*$";

            if (!Regex.IsMatch(content, pattern))
            {
                return;
            }

            string updatedContent = Regex.Replace(content, pattern, match => $"{match.Groups[1].Value}1");
            if (updatedContent != content)
            {
                File.WriteAllText(projectSettingsPath, updatedContent);
                AssetDatabase.ImportAsset(projectSettingsPath, ImportAssetOptions.ForceSynchronousImport);
            }
        }

        private static void EnsureFolder(string path)
        {
            if (string.IsNullOrWhiteSpace(path))
            {
                return;
            }

            if (Directory.Exists(path))
            {
                return;
            }

            string normalizedPath = path.Replace("\\", "/");
            string systemPath = Path.GetFullPath(normalizedPath);
            Directory.CreateDirectory(systemPath);
        }
    }
}
