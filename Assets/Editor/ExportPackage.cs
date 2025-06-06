using UnityEditor;

public class ExportPackage
{
    [MenuItem("Export/CustomExport")]
    static void Export()
    {
        AssetDatabase.ExportPackage(AssetDatabase.GetAllAssetPaths(), PlayerSettings.productName + ".unitypackage",
            ExportPackageOptions.Interactive | ExportPackageOptions.Recurse | ExportPackageOptions.IncludeDependencies |
            ExportPackageOptions.IncludeLibraryAssets);
    }
}
