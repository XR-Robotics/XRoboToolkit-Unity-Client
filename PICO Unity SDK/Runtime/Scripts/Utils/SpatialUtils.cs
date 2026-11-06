#if PICO_MS_SDK
using ByteDance.PICO.SpatialAdapter;
using ByteDance.PICO.Spatial.Stage;
using UnityEngine;
using UnityEngine.XR;

namespace ByteDance.PICO.XR
{
    public class SpatialUtils
    {
        public static class Mesh
        {
            public static void SyncMesh(MeshId meshId,MeshFilter meshFilter, VertexAttributeFlags flags)
            {
                if (SpatialNativeApi.Pmp_isUpdateMesh(meshId))
                {
                    Debug.Log($"AddOrUpdateMesh SyncMesh UnityXRMeshId({meshId}).");
                    SpatialAdapterRuntime.Instance.SyncMesh(meshFilter, 
                        VertexAttributeFlags.POSITION);
                }
            }
            public static void SyncMesh(MeshFilter meshFilter, VertexAttributeFlags flags)
            {
                SpatialAdapterRuntime.Instance.SyncMesh(meshFilter, 
                    VertexAttributeFlags.POSITION);
            }
            public static bool isUpdateMesh(MeshId meshId)
            {
               return SpatialNativeApi.Pmp_isUpdateMesh(meshId);
            }
        }
    }
}
#endif