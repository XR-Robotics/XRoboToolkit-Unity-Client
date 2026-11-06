using System;
using System.Runtime.InteropServices;
#if PICO_XR_NEW
using ByteDance.PICO.XR;
#elif PICO_XR_3
using Unity.XR.PXR;
#endif

namespace ByteDance.PICO.CameraPack
{
    /// <summary>
    /// Wrapper for Native Unity Image Render plugin.
    /// Handles passing texture pointers and raw image data to the native layer.
    /// </summary>
    public class UnityImageRender
    {
        private const string Dll = "UnityImageRender";

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern void setTextureCameraFromUnity(IntPtr texture, int w, int h);
        
        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern void setCameraImageDataRaw(ulong imageId, ref XrCameraImageDataRawBuffer rawBufferData);
    }
}