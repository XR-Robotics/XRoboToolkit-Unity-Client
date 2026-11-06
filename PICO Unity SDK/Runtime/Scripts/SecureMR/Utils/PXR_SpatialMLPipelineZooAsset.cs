#if !ENABLE_PICO_OPENXR_SDK
using System;
using System.Collections.Generic;
using UnityEngine;

namespace ByteDance.PICO.SecureMR
{
    [CreateAssetMenu(fileName = "SpatialMLPipelineZooPackage", menuName = "PICO/SecureMR/SpatialML Pipeline Zoo Package")]
    public sealed class SpatialMLPipelineZooAsset : ScriptableObject
    {
        public string packageId;
        public TextAsset manifestJson;
        public List<PipelineJsonAsset> pipelineJsonAssets = new List<PipelineJsonAsset>();
        public List<BinaryAsset> binaryAssets = new List<BinaryAsset>();

        public TextAsset FindPipelineJson(string pipelineId, string packagePath = null)
        {
            foreach (var item in pipelineJsonAssets)
            {
                if (item == null) continue;
                if (!string.IsNullOrEmpty(pipelineId) && item.id == pipelineId) return item.json;
                if (!string.IsNullOrEmpty(packagePath) && NormalizePath(item.packagePath) == NormalizePath(packagePath)) return item.json;
            }

            return null;
        }

        public byte[] FindBinaryBytes(string packagePath)
        {
            if (string.IsNullOrEmpty(packagePath)) return null;

            var normalized = NormalizePath(packagePath);
            foreach (var item in binaryAssets)
            {
                if (item?.asset == null) continue;
                if (string.IsNullOrEmpty(item.packagePath)) continue;
                if (NormalizePath(item.packagePath) == normalized) return item.asset.bytes;
            }

            return null;
        }

        private static string NormalizePath(string path)
        {
            return (path ?? string.Empty).Replace('\\', '/').TrimStart('/');
        }

        [Serializable]
        public sealed class PipelineJsonAsset
        {
            public string id;
            public string packagePath;
            public TextAsset json;
        }

        [Serializable]
        public sealed class BinaryAsset
        {
            public string packagePath;
            public TextAsset asset;
        }
    }
}
#endif
