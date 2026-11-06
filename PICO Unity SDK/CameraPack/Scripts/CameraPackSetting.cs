using System.IO;
using UnityEditor;
using UnityEngine;

namespace ByteDance.PICO.CameraPack
{
    [System.Serializable]
    public class CameraPackSetting : ScriptableObject
    {
        private static CameraPackSetting _instance;

        public static CameraPackSetting GetConfig()
        {
            if (_instance != null) return _instance;

            _instance = Resources.Load<CameraPackSetting>("PXR_CameraPackSetting");
#if UNITY_EDITOR
            if (_instance == null)
            {
                _instance = CreateInstance<CameraPackSetting>();
                
                string resourcesPath = Path.Combine(Application.dataPath, "Resources");
                if (!Directory.Exists(resourcesPath))
                {
                    AssetDatabase.CreateFolder("Assets", "Resources");
                }
                
                string assetPath = "Assets/Resources/PXR_CameraPackSetting.asset";
                // Check if asset already exists to avoid overwriting
                if (AssetDatabase.LoadAssetAtPath<CameraPackSetting>(assetPath) == null)
                {
                    AssetDatabase.CreateAsset(_instance, assetPath);
                    AssetDatabase.SaveAssets();
                }
            }
#endif
            return _instance;
        }
         
#if UNITY_EDITOR
        public static void SaveAssets()
        {
            EditorUtility.SetDirty(GetConfig());
            AssetDatabase.SaveAssets();
        }
#endif
    }
}
