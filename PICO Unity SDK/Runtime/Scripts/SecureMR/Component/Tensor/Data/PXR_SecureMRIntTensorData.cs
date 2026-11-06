#if !ENABLE_PICO_OPENXR_SDK
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace ByteDance.PICO.SecureMR
{
    public class PXR_SecureMRIntTensorData : PXR_SecureMRTensorData
    {
        public int[] data;

        public override int[] ToIntArray()
        {
            return data;
        }
    }
}

#endif