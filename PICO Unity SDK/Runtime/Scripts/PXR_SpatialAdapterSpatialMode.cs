#if PICO_MS_SDK
using ByteDance.PICO.SpatialAdapter;
using ByteDance.PICO.Spatial.Stage;
using UnityEngine;

namespace ByteDance.PICO.XR
{
    public static class PXR_SpatialAdapterSpatialMode
    {
        public static SpatialCamera.SpatialMode GetSpatialMode()
        {
            if (SpatialCamera.Current == null)
            {
                return SpatialCamera.SpatialMode.WindowContainer;
            }

            return SpatialCamera.CurrentSpatialMode;
        }

        public static void SyncSpatialAdapterSpatialMode()
        {
            var spatialMode = GetSpatialMode();
            //Debug.Log($"SyncSpatialAdapterSpatialMode: {spatialMode}");
            SpatialNativeApi.Pmp_SetSpatialAdapterSpatialMode((int)spatialMode);
        }
    }
}
#endif
