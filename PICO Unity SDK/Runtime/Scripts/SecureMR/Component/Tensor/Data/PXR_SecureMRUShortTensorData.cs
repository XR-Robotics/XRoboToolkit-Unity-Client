#if !ENABLE_PICO_OPENXR_SDK
namespace ByteDance.PICO.SecureMR
{
    public class PXR_SecureMRUShortTensorData : PXR_SecureMRTensorData
    {
        public ushort[] data;

        public override ushort[] ToUShortArray()
        {
            return data;
        }
    }
}
#endif