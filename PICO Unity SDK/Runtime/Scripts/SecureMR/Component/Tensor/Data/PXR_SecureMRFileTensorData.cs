#if !ENABLE_PICO_OPENXR_SDK
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace ByteDance.PICO.SecureMR
{
    public class PXR_SecureMRFileTensorData : PXR_SecureMRTensorData
    {
        public TextAsset fileAsset;

        public override byte[] ToByteArray()
        {
            if (fileAsset != null)
            {
                return fileAsset.bytes;
            }
            else
            {
                return null;
            }
        }
    }
}
#endif
