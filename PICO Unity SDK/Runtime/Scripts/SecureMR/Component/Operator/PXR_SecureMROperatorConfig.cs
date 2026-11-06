#if !ENABLE_PICO_OPENXR_SDK
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace ByteDance.PICO.SecureMR
{
    [DisallowMultipleComponent]
    public abstract class PXR_SecureMROperatorConfig : MonoBehaviour
    {
        
    }

    public class PXR_SecureMRUpdateComponentOperatorConfig : PXR_SecureMROperatorConfig
    {
        public string entityPath;
        public string targetPropertyPath;
    }
}

#endif
