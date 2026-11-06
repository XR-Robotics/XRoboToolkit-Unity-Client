#if PICO_MS_SDK
using ByteDance.PICO.SpatialAdapter;
using UnityEngine;

namespace ByteDance.PICO.XR
{
    [DisallowMultipleComponent]
    [RequireComponent(typeof(SpatialCamera))]
    public sealed class PXR_SpatialCameraSpatialModeSynchronizer : MonoBehaviour
    {
        private void Start()
        {
            PXR_SpatialAdapterSpatialMode.SyncSpatialAdapterSpatialMode();
        }
    }
}
#endif
