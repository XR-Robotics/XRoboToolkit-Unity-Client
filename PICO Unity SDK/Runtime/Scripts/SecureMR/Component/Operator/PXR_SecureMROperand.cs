#if !ENABLE_PICO_OPENXR_SDK
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace ByteDance.PICO.SecureMR
{
    public class PXR_SecureMROperand : MonoBehaviour
    {
        public string name;
        public PXR_SecureMRPipelineTensor tensor;
    }
}
#endif