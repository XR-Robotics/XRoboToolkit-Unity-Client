using System.Collections.Generic;
using System.IO;
using UnityEditor;
using UnityEngine;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    public class IconConfiguratorStateStore
    {
        private IconConfiguratorConfigAsset m_configAsset;

        public string ConfigAssetPath => IconConfiguratorPaths.ConfigAssetPath;

        public IconConfiguratorConfigAsset LoadOrCreateConfigAsset()
        {
            if (m_configAsset != null)
            {
                return m_configAsset;
            }

            EnsureFolder(IconConfiguratorPaths.RootDirectory);
            EnsureFolder(IconConfiguratorPaths.SettingsDirectory);

            m_configAsset = AssetDatabase.LoadAssetAtPath<IconConfiguratorConfigAsset>(IconConfiguratorPaths.ConfigAssetPath);

            if (m_configAsset == null && File.Exists(IconConfiguratorPaths.ConfigAssetPath))
            {
                FileUtil.DeleteFileOrDirectory(IconConfiguratorPaths.ConfigAssetPath);
                FileUtil.DeleteFileOrDirectory($"{IconConfiguratorPaths.ConfigAssetPath}.meta");
                AssetDatabase.Refresh(ImportAssetOptions.ForceSynchronousImport);
            }

            if (m_configAsset == null)
            {
                m_configAsset = ScriptableObject.CreateInstance<IconConfiguratorConfigAsset>();
                IconConfiguratorConfigNormalizer.Normalize(m_configAsset);
                AssetDatabase.CreateAsset(m_configAsset, IconConfiguratorPaths.ConfigAssetPath);
                AssetDatabase.SaveAssets();
            }
            else
            {
                IconConfiguratorConfigNormalizer.Normalize(m_configAsset);
            }

            RestoreTextureCache(m_configAsset);
            return m_configAsset;
        }

        public void Save()
        {
            if (m_configAsset == null)
            {
                return;
            }

            EditorUtility.SetDirty(m_configAsset);
            AssetDatabase.SaveAssets();
        }

        public string GetConfigGuid()
        {
            return AssetDatabase.AssetPathToGUID(IconConfiguratorPaths.ConfigAssetPath);
        }

        public void RestoreTextureCache(IconConfiguratorConfigAsset config)
        {
            if (config == null)
            {
                return;
            }

            List<IconLayerConfig> layers = new List<IconLayerConfig>();
            if (config.Manual?.Layers != null)
            {
                layers.AddRange(config.Manual.Layers);
            }

            layers.Add(config.AiSplit.FlatSource);
            layers.Add(config.AiSplit.Background);
            layers.Add(config.AiSplit.Foreground1);
            layers.Add(config.AiSplit.Foreground2);
            layers.AddRange(config.AiSplit.GeneratedLayers);
            layers.AddRange(config.AiSplit.GeneratedSdfs);

            foreach (IconLayerConfig layer in layers)
            {
                RestoreTexture(layer);
            }
        }

        private static void RestoreTexture(IconLayerConfig layer)
        {
            if (layer == null || !layer.HasAssetReference)
            {
                return;
            }

            Texture2D texture = AssetDatabase.LoadAssetAtPath<Texture2D>(layer.AssetPath);

            if (texture == null && !string.IsNullOrWhiteSpace(layer.AssetGuid))
            {
                string assetPath = AssetDatabase.GUIDToAssetPath(layer.AssetGuid);

                if (!string.IsNullOrWhiteSpace(assetPath))
                {
                    layer.AssetPath = assetPath;
                    texture = AssetDatabase.LoadAssetAtPath<Texture2D>(assetPath);
                }
            }

            layer.Texture = texture;
        }

        private static void EnsureFolder(string path)
        {
            if (AssetDatabase.IsValidFolder(path))
            {
                return;
            }

            string parent = path.Substring(0, path.LastIndexOf('/'));
            string folderName = path.Substring(path.LastIndexOf('/') + 1);

            if (!AssetDatabase.IsValidFolder(parent))
            {
                EnsureFolder(parent);
            }

            AssetDatabase.CreateFolder(parent, folderName);
        }
    }
}
