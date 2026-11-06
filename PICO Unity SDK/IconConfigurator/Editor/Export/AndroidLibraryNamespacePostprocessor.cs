using System.IO;
using UnityEditor.Android;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    public class AndroidLibraryNamespacePostprocessor : IPostGenerateGradleAndroidProject
    {
        public int callbackOrder => 0;

        public void OnPostGenerateGradleAndroidProject(string path)
        {
            string buildGradlePath = Path.Combine(path, "IconConfigurator.androidlib", "build.gradle");
            AndroidLibraryNamespacePatcher.PatchBuildGradleFile(buildGradlePath);
        }
    }
}
