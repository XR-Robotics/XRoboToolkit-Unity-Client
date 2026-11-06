#if !ENABLE_PICO_OPENXR_SDK
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace ByteDance.PICO.SecureMR
{
    public class PXR_SecureMRFloatTensorData : PXR_SecureMRTensorData
    {
        public float[] data;

        public override float[] ToFloatArray()
        {
            return data;
        }
    }
}

#endif