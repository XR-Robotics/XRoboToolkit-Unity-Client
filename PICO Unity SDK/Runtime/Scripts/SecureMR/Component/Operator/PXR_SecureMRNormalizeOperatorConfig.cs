#if !ENABLE_PICO_OPENXR_SDK
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace ByteDance.PICO.SecureMR
{
    public class PXR_SecureMRNormalizeOperatorConfig : PXR_SecureMROperatorConfig
    {
        public SecureMRNormalizeType normalizeType = SecureMRNormalizeType.L1;
    }
}

#endif