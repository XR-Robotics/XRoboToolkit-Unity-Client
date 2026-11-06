#if !ENABLE_PICO_OPENXR_SDK
using UnityEngine;

namespace ByteDance.PICO.SecureMR
{
    public class PXR_SecureMRMicrophoneOperatorConfig : PXR_SecureMROperatorConfig
    {
        public int sampleRate = 16000;
        public string pcmType = "PCM_INT16";
    }
}
#endif
