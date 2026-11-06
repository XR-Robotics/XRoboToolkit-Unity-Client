#if !ENABLE_PICO_OPENXR_SDK
using UnityEngine;

namespace ByteDance.PICO.SecureMR
{
    public class PXR_SecureMRSpeakerOperatorConfig : PXR_SecureMROperatorConfig
    {
        public int sampleRate = 16000;
    }
}
#endif
