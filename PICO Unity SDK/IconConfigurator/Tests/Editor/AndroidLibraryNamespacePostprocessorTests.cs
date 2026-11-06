using System.IO;
using NUnit.Framework;

namespace ByteDance.PICO.IconConfigurator.Editor.Tests
{
    public class AndroidLibraryNamespacePatcherTests
    {
        private const string k_TestDirectory = "Assets/IconConfigurator/GradleTests";
        private const string k_TestBuildGradlePath = "Assets/IconConfigurator/GradleTests/build.gradle";

        [SetUp]
        public void SetUp()
        {
            DeleteTestDirectory();
            Directory.CreateDirectory(k_TestDirectory);
        }

        [TearDown]
        public void TearDown()
        {
            DeleteTestDirectory();
        }

        [Test]
        public void PatchBuildGradleFile_WhenNamespaceMissing_InsertsNamespaceInAndroidBlock()
        {
            File.WriteAllText(
                k_TestBuildGradlePath,
@"apply plugin: 'com.android.library'

android {
    compileSdk 36
}
");

            bool changed = AndroidLibraryNamespacePatcher.PatchBuildGradleFile(k_TestBuildGradlePath);

            string content = File.ReadAllText(k_TestBuildGradlePath);
            Assert.That(changed, Is.True);
            Assert.That(content, Does.Contain("android {\n    namespace \"com.iconfeature.iconconfigurator\"\n    compileSdk 36"));
        }

        [Test]
        public void PatchBuildGradleFile_WhenNamespaceAlreadyExists_DoesNotDuplicateNamespace()
        {
            File.WriteAllText(
                k_TestBuildGradlePath,
@"apply plugin: 'com.android.library'

android {
    namespace ""com.iconfeature.iconconfigurator""
    compileSdk 36
}
");

            bool changed = AndroidLibraryNamespacePatcher.PatchBuildGradleFile(k_TestBuildGradlePath);

            string content = File.ReadAllText(k_TestBuildGradlePath);
            Assert.That(changed, Is.False);
            Assert.That(CountOccurrences(content, "namespace \"com.iconfeature.iconconfigurator\""), Is.EqualTo(1));
        }

        private static int CountOccurrences(string content, string value)
        {
            int count = 0;
            int index = 0;

            while ((index = content.IndexOf(value, index, System.StringComparison.Ordinal)) >= 0)
            {
                count++;
                index += value.Length;
            }

            return count;
        }

        private static void DeleteTestDirectory()
        {
            if (Directory.Exists(k_TestDirectory))
            {
                Directory.Delete(k_TestDirectory, true);
            }
        }
    }
}
