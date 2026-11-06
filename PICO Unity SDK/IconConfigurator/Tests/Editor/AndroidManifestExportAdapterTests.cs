using System;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Xml.Linq;
using NUnit.Framework;
using UnityEditor;

namespace ByteDance.PICO.IconConfigurator.Editor.Tests
{
    public class AndroidManifestExportAdapterTests
    {
        private const string k_TestManifestPath = "Assets/IconConfigurator/ManifestTests/AndroidManifest.xml";
        private const string k_TestLauncherManifestPath = "Assets/IconConfigurator/ManifestTests/launcherManifest.xml";
        private const string k_UnityPlayerActivityName = "com.unity3d.player.UnityPlayerActivity";
        private const string k_UnityPlayerGameActivityName = "com.unity3d.player.UnityPlayerGameActivity";
        private static readonly XNamespace s_androidNamespace = "http://schemas.android.com/apk/res/android";
        private static readonly XNamespace s_toolsNamespace = "http://schemas.android.com/tools";

        [SetUp]
        public void SetUp()
        {
            DeleteTestManifestDirectory();
        }

        [TearDown]
        public void TearDown()
        {
            DeleteTestManifestDirectory();
        }

        [Test]
        public void Apply_WhenManifestMissing_CreatesMainAndLauncherManifestsWithoutIconConflict()
        {
            AndroidManifestExportAdapter adapter = new AndroidManifestExportAdapter(
                k_TestManifestPath,
                k_TestLauncherManifestPath,
                false);

            adapter.Apply(new IconApplyPayload());

            XElement mainApplication = XDocument.Load(k_TestManifestPath).Root.Element("application");
            Assert.That(mainApplication, Is.Not.Null);
            Assert.That(mainApplication.Attribute(s_androidNamespace + "icon"), Is.Null);
            AssertLauncherActivity(mainApplication, k_UnityPlayerActivityName);

            XElement launcherApplication = XDocument.Load(k_TestLauncherManifestPath).Root.Element("application");
            Assert.That(launcherApplication.Attribute(s_androidNamespace + "icon")?.Value, Is.EqualTo("@mipmap/ic_spatial_launcher"));
            Assert.That(launcherApplication.Attribute(s_androidNamespace + "label")?.Value, Is.EqualTo("@string/icon_configurator_app_name"));
            Assert.That(launcherApplication.Attribute(s_androidNamespace + "localeConfig")?.Value, Is.EqualTo("@xml/locales_config"));
            Assert.That(launcherApplication.Attribute(s_toolsNamespace + "replace")?.Value, Is.EqualTo("android:icon,android:label"));
            AssertMetadata(launcherApplication, "icon.3d.list", "@array/icon_3d_list");
            AssertMetadata(launcherApplication, "icon.sdf.list", "@array/icon_sdf_list");
            AssertLauncherActivity(launcherApplication, k_UnityPlayerActivityName);
        }

        [Test]
        public void Apply_WhenCustomLauncherManifestExists_PreservesCustomNodesAndAvoidsDuplicateMetadata()
        {
            Directory.CreateDirectory(Path.GetDirectoryName(k_TestManifestPath));
            File.WriteAllText(
                k_TestLauncherManifestPath,
@"<?xml version=""1.0"" encoding=""utf-8""?>
<manifest xmlns:android=""http://schemas.android.com/apk/res/android"">
    <uses-permission android:name=""android.permission.INTERNET"" />
    <application android:theme=""@style/CustomTheme"">
        <activity android:name=""com.example.CustomActivity"" />
        <meta-data android:name=""icon.3d.list"" android:resource=""@array/old_icon_list"" />
    </application>
</manifest>");

            AndroidManifestExportAdapter adapter = new AndroidManifestExportAdapter(
                k_TestManifestPath,
                k_TestLauncherManifestPath,
                false);

            adapter.Apply(new IconApplyPayload());

            XDocument document = XDocument.Load(k_TestLauncherManifestPath);
            XElement application = document.Root.Element("application");
            Assert.That(document.Root.Elements("uses-permission").Any(), Is.True);
            Assert.That(application.Elements("activity").Any(), Is.True);
            Assert.That(application.Attribute(s_androidNamespace + "theme")?.Value, Is.EqualTo("@style/CustomTheme"));
            Assert.That(application.Attribute(s_androidNamespace + "icon")?.Value, Is.EqualTo("@mipmap/ic_spatial_launcher"));
            Assert.That(application.Attribute(s_androidNamespace + "label")?.Value, Is.EqualTo("@string/icon_configurator_app_name"));
            Assert.That(application.Attribute(s_toolsNamespace + "replace")?.Value, Is.EqualTo("android:icon,android:label"));
            Assert.That(application.Elements("meta-data")
                .Count(element => element.Attribute(s_androidNamespace + "name")?.Value == "icon.3d.list"), Is.EqualTo(1));
            AssertMetadata(application, "icon.3d.list", "@array/icon_3d_list");
            AssertMetadata(application, "icon.sdf.list", "@array/icon_sdf_list");
            AssertLauncherActivity(application, k_UnityPlayerActivityName);
        }

        [Test]
        public void Apply_WhenUnityPlayerActivityExistsWithoutLauncherNodes_RepairsMainActivityInPlace()
        {
            Directory.CreateDirectory(Path.GetDirectoryName(k_TestManifestPath));
            File.WriteAllText(
                k_TestManifestPath,
$@"<?xml version=""1.0"" encoding=""utf-8""?>
<manifest xmlns:android=""http://schemas.android.com/apk/res/android"">
    <application>
        <activity android:name=""{k_UnityPlayerActivityName}"" />
    </application>
</manifest>");

            AndroidManifestExportAdapter adapter = new AndroidManifestExportAdapter(
                k_TestManifestPath,
                k_TestLauncherManifestPath,
                false);

            adapter.Apply(new IconApplyPayload());

            XElement application = XDocument.Load(k_TestManifestPath).Root.Element("application");
            Assert.That(application.Elements("activity").Count(), Is.EqualTo(1));
            AssertLauncherActivity(application, k_UnityPlayerActivityName);
        }

        [Test]
        public void Apply_WhenCustomLauncherActivityExists_DoesNotConvertItToUnityActivity()
        {
            const string customActivityName = "com.example.CustomLauncherActivity";
            Directory.CreateDirectory(Path.GetDirectoryName(k_TestManifestPath));
            File.WriteAllText(
                k_TestManifestPath,
$@"<?xml version=""1.0"" encoding=""utf-8""?>
<manifest xmlns:android=""http://schemas.android.com/apk/res/android"">
    <application>
        <activity android:name=""{customActivityName}"">
            <intent-filter>
                <action android:name=""android.intent.action.MAIN"" />
                <category android:name=""android.intent.category.LAUNCHER"" />
            </intent-filter>
        </activity>
    </application>
</manifest>");

            AndroidManifestExportAdapter adapter = new AndroidManifestExportAdapter(
                k_TestManifestPath,
                k_TestLauncherManifestPath,
                false);

            adapter.Apply(new IconApplyPayload());

            XElement application = XDocument.Load(k_TestManifestPath).Root.Element("application");
            XElement activity = application.Elements("activity")
                .FirstOrDefault(element => element.Attribute(s_androidNamespace + "name")?.Value == customActivityName);

            Assert.That(application.Elements("activity").Count(), Is.EqualTo(1));
            Assert.That(activity, Is.Not.Null);
            Assert.That(activity.Attribute(s_androidNamespace + "exported")?.Value, Is.EqualTo("true"));
            Assert.That(activity.Elements("meta-data").Any(
                element => element.Attribute(s_androidNamespace + "name")?.Value == "unityplayer.UnityActivity"), Is.False);
        }

        [Test]
        public void Apply_WhenActivityAndGameActivityEntriesAreEnabled_CreatesBothUnityLauncherActivities()
        {
            if (!TrySetAndroidApplicationEntry(out object originalEntry, "Activity", "GameActivity"))
            {
                Assert.Ignore("PlayerSettings.Android.applicationEntry is unavailable in this Unity version.");
            }

            try
            {
                AndroidManifestExportAdapter adapter = new AndroidManifestExportAdapter(
                    k_TestManifestPath,
                    k_TestLauncherManifestPath,
                    false);

                adapter.Apply(new IconApplyPayload());

                XElement mainApplication = XDocument.Load(k_TestManifestPath).Root.Element("application");
                XElement launcherApplication = XDocument.Load(k_TestLauncherManifestPath).Root.Element("application");

                AssertLauncherActivity(mainApplication, k_UnityPlayerActivityName);
                AssertLauncherActivity(mainApplication, k_UnityPlayerGameActivityName);
                AssertGameActivityDefaults(mainApplication);
                AssertLauncherActivity(launcherApplication, k_UnityPlayerActivityName);
                AssertLauncherActivity(launcherApplication, k_UnityPlayerGameActivityName);
                AssertGameActivityDefaults(launcherApplication);
            }
            finally
            {
                RestoreAndroidApplicationEntry(originalEntry);
            }
        }

        private static void AssertMetadata(XElement application, string name, string resource)
        {
            XElement metadata = application.Elements("meta-data")
                .FirstOrDefault(element => element.Attribute(s_androidNamespace + "name")?.Value == name);
            Assert.That(metadata, Is.Not.Null);
            Assert.That(metadata.Attribute(s_androidNamespace + "resource")?.Value, Is.EqualTo(resource));
        }

        private static void AssertLauncherActivity(XElement application, string activityName)
        {
            XElement activity = application.Elements("activity")
                .FirstOrDefault(element => element.Attribute(s_androidNamespace + "name")?.Value == activityName);
            Assert.That(activity, Is.Not.Null);
            Assert.That(activity.Attribute(s_androidNamespace + "exported")?.Value, Is.EqualTo("true"));

            XElement intentFilter = activity.Elements("intent-filter").FirstOrDefault();
            Assert.That(intentFilter, Is.Not.Null);
            Assert.That(intentFilter.Elements("action").Any(
                element => element.Attribute(s_androidNamespace + "name")?.Value == "android.intent.action.MAIN"), Is.True);
            Assert.That(intentFilter.Elements("category").Any(
                element => element.Attribute(s_androidNamespace + "name")?.Value == "android.intent.category.LAUNCHER"), Is.True);

            XElement unityActivityMetadata = activity.Elements("meta-data")
                .FirstOrDefault(element => element.Attribute(s_androidNamespace + "name")?.Value == "unityplayer.UnityActivity");
            Assert.That(unityActivityMetadata, Is.Not.Null);
            Assert.That(unityActivityMetadata.Attribute(s_androidNamespace + "value")?.Value, Is.EqualTo("true"));
        }

        private static void AssertGameActivityDefaults(XElement application)
        {
            XElement activity = application.Elements("activity")
                .FirstOrDefault(element => element.Attribute(s_androidNamespace + "name")?.Value == k_UnityPlayerGameActivityName);
            Assert.That(activity, Is.Not.Null);
            Assert.That(activity.Attribute(s_androidNamespace + "theme")?.Value, Is.EqualTo("@style/BaseUnityGameActivityTheme"));

            XElement libNameMetadata = activity.Elements("meta-data")
                .FirstOrDefault(element => element.Attribute(s_androidNamespace + "name")?.Value == "android.app.lib_name");
            Assert.That(libNameMetadata, Is.Not.Null);
            Assert.That(libNameMetadata.Attribute(s_androidNamespace + "value")?.Value, Is.EqualTo("game"));
        }

        private static bool TrySetAndroidApplicationEntry(out object originalEntry, params string[] entryNames)
        {
            originalEntry = null;
            PropertyInfo property = typeof(PlayerSettings.Android).GetProperty(
                "applicationEntry",
                BindingFlags.Public | BindingFlags.Static);

            if (property == null || !property.CanRead || !property.CanWrite || !property.PropertyType.IsEnum)
            {
                return false;
            }

            originalEntry = property.GetValue(null);
            long value = 0;
            for (int i = 0; i < entryNames.Length; i++)
            {
                object flag = Enum.Parse(property.PropertyType, entryNames[i]);
                value |= Convert.ToInt64(flag);
            }

            property.SetValue(null, Enum.ToObject(property.PropertyType, value));
            return true;
        }

        private static void RestoreAndroidApplicationEntry(object originalEntry)
        {
            if (originalEntry == null)
            {
                return;
            }

            PropertyInfo property = typeof(PlayerSettings.Android).GetProperty(
                "applicationEntry",
                BindingFlags.Public | BindingFlags.Static);

            if (property != null && property.CanWrite)
            {
                property.SetValue(null, originalEntry);
            }
        }

        private static void DeleteTestManifestDirectory()
        {
            string directory = Path.GetDirectoryName(k_TestManifestPath);
            if (Directory.Exists(directory))
            {
                Directory.Delete(directory, true);
            }
        }
    }
}
