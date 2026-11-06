#if !ENABLE_PICO_OPENXR_SDK
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace ByteDance.PICO.SecureMR
{
    public abstract class PXR_SecureMRTensor : MonoBehaviour
    {
        internal Tensor tensor;
        public PXR_SecureMRMetadata metadata;
    }
}
#endif