#if !ENABLE_PICO_OPENXR_SDK
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace ByteDance.PICO.SecureMR
{
    public class PXR_SecureMRUpdateGltfOperatorConfig : PXR_SecureMROperatorConfig
    {
        public SecureMRGltfOperatorAttribute attribute = SecureMRGltfOperatorAttribute.Texture;
    }
}
#endif
