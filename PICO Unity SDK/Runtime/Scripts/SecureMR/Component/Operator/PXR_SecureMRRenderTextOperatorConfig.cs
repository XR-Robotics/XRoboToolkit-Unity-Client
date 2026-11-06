#if !ENABLE_PICO_OPENXR_SDK
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace ByteDance.PICO.SecureMR
{
    public class PXR_SecureMRRenderTextOperatorConfig : PXR_SecureMROperatorConfig
    {
        public SecureMRFontTypeface typeface = SecureMRFontTypeface.Default;
        public string languageAndLocale;
        public int width;
        public int height;
    }
}
#endif