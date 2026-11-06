#if !ENABLE_PICO_OPENXR_SDK
namespace ByteDance.PICO.SecureMR
{
    public class PXR_SecureMRByteTensorData : PXR_SecureMRTensorData
    {
        public byte[] data;

        public override byte[] ToByteArray()
        {
            return data;
        }
    }
}
#endif