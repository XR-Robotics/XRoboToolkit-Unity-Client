#if !ENABLE_PICO_OPENXR_SDK
using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using Unity.Collections;
using Unity.Collections.LowLevel.Unsafe;

using UnityEngine;
using UnityEngine.XR;
using UnityEngine.XR.Management;

using ByteDance.PICO.XR;


namespace ByteDance.PICO.SecureMR
{
    #region SecureMR

    [StructLayout(LayoutKind.Sequential)]
    public struct SecureMRPipelineExecuteParameter
    {
        public XrStructureType type;
        public IntPtr next;
        public ulong pipelineRunToBeWaited;
        public ulong conditionTensor;
        public uint pairCount;
        public IntPtr pipelineIOPair; //SecureMrPipelineIOPair[]
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct SecureMRPipelineIOPair
    {
        public XrStructureType type;
        public IntPtr next;
        public ulong localPlaceHolderTensor;
        public ulong globalTensor;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct SecureMRTensorBuffer
    {
        public XrStructureType type;
        public IntPtr next;
        public uint bufferSize;
        public IntPtr buffer;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct SecureMRTensorCreateInfoShape
    {
        public XrStructureType type;
        public IntPtr next;
        public bool placeHolder;
        public uint dimensionsCount;
        public IntPtr dimensions;
        public IntPtr format; // XrSecureMrTensorFormat
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct SecureMRTensorCreateInfoGltf
    {
        public XrStructureType type;
        public IntPtr next;
        public bool placeHolder;
        public uint bufferSize;
        public IntPtr buffer;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct SecureMRTensorFormat
    {
        public SecureMRTensorDataType dataType;
        public sbyte channel;
        public SecureMRTensorUsage tensorUsage;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct SecureMROperatorArithmeticCompose
    {
        public XrStructureType type;
        public IntPtr next;

        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 2048)]
        public byte[] configText;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct SecureMROperatorComparison
    {
        public XrStructureType type;
        public IntPtr next;
        public SecureMRComparison comparison;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct SecureMROperatorNonMaximumSuppression
    {
        public XrStructureType type;
        public IntPtr next;
        public float threshold;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct SecureMROperatorNormalize
    {
        public XrStructureType type;
        public IntPtr next;
        public SecureMRNormalizeType normalizeType;
    }

    /// <summary>
    /// convert:https://docs.opencv.org/3.4/d8/d01/group__imgproc__color__conversions.html
    /// </summary>
    [StructLayout(LayoutKind.Sequential)]
    public struct SecureMROperatorColorConvert
    {
        public XrStructureType type;
        public IntPtr next;
        public int convert;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct SecureMROperatorSortMatrix
    {
        public XrStructureType type;
        public IntPtr next;
        public SecureMRMatrixSortType sortType;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct SecureMROperatorUpdateGltf
    {
        public XrStructureType type;
        public IntPtr next;
        public SecureMRGltfOperatorAttribute attribute;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct SecureMROperatorRenderText
    {
        public XrStructureType type;
        public IntPtr next;
        public SecureMRFontTypeface typeFace;
        public string languageAndLocale;
        public int width;
        public int height;
    }

    public enum ResultMsg
    {
        Unknown = int.MaxValue,
        SUCCESS = 0,
        PENDING = 1,
        FAILED = -1,
        TIMEOUT = -2,
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct SecureMROperatorModel
    {
        public XrStructureType type;
        public IntPtr next;
        public uint modelInputCount;
        public IntPtr modelInputs; //SecureMrOperatorIOMap[]
        public uint modelOutputCount;
        public IntPtr modelOutputs; //SecureMrOperatorIOMap[]
        public uint bufferSize;
        public IntPtr buffer;
        public SecureMRModelType modelType;
        public string modelName;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct SecureMROperatorLiteRtModel
    {
        public XrStructureType type;
        public IntPtr next;
        public SecureMRModelTarget modelTarget;
        public int cpuTargetNumThreads;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct SecureMROperatorIOMap
    {
        public XrStructureType type;
        public IntPtr next;
        public SecureMRModelEncoding encodingType;

        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 512)]
        public byte[] nodeName;

        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 512)]
        public byte[] operatorIOName;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct SecureMROperatorJavascript
    {
        public XrStructureType type;
        public IntPtr next;
        public string configText;
        public int configTextLength;
    }

    public struct SecureMROperatorModelConfig
    {
        public SecureMRModelEncoding encodingType;
        public string nodeName;
        public string operatorIOName;
    }

    public enum SecureMRModelEncoding
    {
        Float32 = 1,
        UInt8 = 2,
        Int8 = 3,
        UInt16 = 4,
        Int32 = 5,
    }

    public enum SecureMRModelType
    {
        [Obsolete("QNN context binaries are no longer supported. Use LiteRtModel instead. " +
            "This member is retained only for source/binary compatibility and will be rejected at runtime.")]
        QnnContextBinary = 1,
        LiteRtModel = 2,
    }

    public enum SecureMRModelTarget
    {
        Npu = 1,
        Gpu = 2,
        Cpu = 3,
    }

    public enum SecureMRFontTypeface
    {
        Default = 1,
        SansSerif = 2,
        Serif = 3,
        Monospace = 4,
        Bold = 5,
        Italic = 6,
    }

    public enum SecureMRGltfOperatorAttribute
    {
        Texture = 1,
        Animation = 2,
        WorldPose = 3,
        LocalTransform = 4,
        MaterialMetallicFactor = 5,
        MaterialRoughnessFactor = 6,
        MaterialOcclusionMapTexture = 7,
        MaterialBaseColorFactor = 8,
        MaterialEmissiveFactor = 9,
        MaterialEmissiveStrength = 10,
        MaterialEmissiveTexture = 11,
        MaterialBaseColorTexture = 12,
        MaterialNormalMapTexture = 13,
        MaterialMetallicRoughnessTexture = 14,
    }

    public enum SecureMRMatrixSortType
    {
        Column = 1,
        Row = 2,
    }

    public enum SecureMRNormalizeType
    {
        L1 = 1,
        L2 = 2,
        Inf = 3,
        MinMax = 4,
    }

    public enum SecureMRTensorDataType
    {
        Unknown = -1,
        Byte = 1,
        Sbyte,
        Ushort,
        Short,
        Int,
        Float,
        Double,
        DynamicTextureByte,
        DynamicTextureFloat

    }

    public enum SecureMRTensorUsage
    {
        Unknown = -1,
        Point = 1,
        Scalar,
        Slice,
        Color,
        TimeStamp,
        Matrix,
        DynamicTexture = 8
    }

    public enum SecureMRComparison
    {
        Unknown = 0,
        LargerThan = 1,
        SmallerThan = 2,
        SmallerOrEqual = 3,
        LargerOrEqual = 4,
        EqualTo = 5,
        NotEqual = 6,
    }

    public enum SecureMROperatorType
    {
        Unknown = 0,
        ArithmeticCompose = 1,
        ElementwiseMin = 4,
        ElementwiseMax = 5,
        ElementwiseMultiply = 6,
        CustomizedCompare = 7,
        ElementwiseOr = 8,
        ElementwiseAnd = 9,
        All = 10,
        Any = 11,
        Nms = 12,
        SolvePnP = 13,
        GetAffine = 14,
        ApplyAffine = 15,
        ApplyAffinePoint = 16,
        UvTo3DInCameraSpace = 17,
        Assignment = 18,
        RunModelInference = 19,
        Normalize = 21,
        CameraSpaceToWorld = 22,
        RectifiedVstAccess = 23,
        Argmax = 24,
        ConvertColor = 25,
        SortVector = 26,
        Inversion = 27,
        GetTransformMatrix = 28,
        SortMatrix = 29,
        SwitchGltfRenderStatus = 30,
        UpdateGltf = 31,
        RenderText = 32,
        LoadTexture = 33,
        Svd = 34,
        Norm = 35,
        SwapHwcChw = 36,
        ScenegraphVisibility = 37,
        UpdateComponent = 38,
        Javascript = 39,
        Microphone = 40,
        Speaker = 41,
        Depth = 42,
    }

    #endregion

    public static class PXR_SecureMRPlugin
    {
        public const string TAG = "SecureMR";

        #region XRSecureMR

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_CreateSecureMRFramework(int width, int height, out ulong providerHandle);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_DestroySecureMRFramework(ulong providerHandle);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_CreateSecureMRPipeline(ulong providerHandle, out ulong pipelineHandle);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_DestroySecureMRPipeline(ulong pipelineHandle);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_ExecuteSecureMRPipeline(ulong pipelineHandle,
            ref SecureMRPipelineExecuteParameter parameter, out ulong pipelineRunHandle);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_SetSecureMROperatorOperandByName(ulong pipelineHandle, ulong operatorHandle,
            ulong tensorHandle, string name);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_SetSecureMROperatorResultByName(ulong pipelineHandle, ulong operatorHandle,
            ulong tensorHandle, string name);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_CreateSecureMRTensorByShape(ulong frameworkHandle,
            SecureMRTensorCreateInfoShape createInfo, out ulong tensorHandle);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_CreateSecureMRTensorByGltf(ulong frameworkHandle,
            SecureMRTensorCreateInfoGltf createInfo, out ulong tensorHandle);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_CreateSecureMRPipelineTensorByShape(ulong pipelineHandle,
            SecureMRTensorCreateInfoShape createInfo, out ulong tensorHandle);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_CreateSecureMRPipelineTensorByGltf(ulong pipelineHandle,
            SecureMRTensorCreateInfoGltf createInfo, out ulong tensorHandle);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_ResetSecureMRTensor(ulong tensorHandle, ref SecureMRTensorBuffer buffer);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_ResetSecureMRPipelineTensor(ulong pipelineHandle, ulong tensorHandle,
            ref SecureMRTensorBuffer buffer);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_DestroySecureMRTensor(ulong tensorHandle);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_CreateSecureMROperator(ulong pipelineHandle, SecureMROperatorType operatorType,
            out ulong operatorHandle);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_CreateSecureMROperatorArithmeticCompose(ulong pipelineHandle,
            ref SecureMROperatorArithmeticCompose config, out ulong operatorHandle);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_CreateSecureMROperatorComparison(ulong pipelineHandle,
            ref SecureMROperatorComparison config, out ulong operatorHandle);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_CreateSecureMROperatorNonMaximumSuppression(ulong pipelineHandle,
            ref SecureMROperatorNonMaximumSuppression config, out ulong operatorHandle);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_CreateSecureMROperatorUVTo3D(ulong pipelineHandle, out ulong operatorHandle);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_CreateSecureMROperatorNormalize(ulong pipelineHandle,
            ref SecureMROperatorNormalize config, out ulong operatorHandle);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_CreateSecureMROperatorColorConvert(ulong pipelineHandle,
            ref SecureMROperatorColorConvert config, out ulong operatorHandle);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_CreateSecureMROperatorSortMatrix(ulong pipelineHandle,
            ref SecureMROperatorSortMatrix config, out ulong operatorHandle);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_CreateSecureMROperatorUpdateGltf(ulong pipelineHandle,
            ref SecureMROperatorUpdateGltf config, out ulong operatorHandle);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_CreateSecureMROperatorRenderText(ulong pipelineHandle,
            ref SecureMROperatorRenderText config, out ulong operatorHandle);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_CreateSecureMROperatorModel(ulong pipelineHandle, ref SecureMROperatorModel model,
            out ulong operatorHandle);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_CreateSecureMROperatorJavascript(ulong pipelineHandle,
            ref SecureMROperatorJavascript model, out ulong operatorHandle);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_CreateBufferFromGlobalTensorAsync(ulong tensor, out ulong future);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_CreateBufferFromGlobalTensorComplete(ulong tensor, ulong future,
            ref XrCreateBufferFromGlobalTensorCompletion completion);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_CreateTextureFromGlobalTensorAsync(ulong tensor, out ulong future);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_CreateTextureFromGlobalTensorComplete(ulong tensor, ulong future,
            ref XrCreateTextureFromGlobalTensorCompletion completion);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_GetReadbackTextureImage(ulong readbackTexture, IntPtr img);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern int Pxr_ReleaseReadbackTexture(ulong readbackTexture);

        #endregion

        #region SpatialSecureMR
        public static class SpatialSecureMR
        {
#if UNITY_ANDROID && !UNITY_EDITOR
            private const string JavaSsmrJniWrapperClass = "com.bytedance.pico.openmr.spatial.pack.SSMRJNIWrapper";
            private const string JavaPipelineJniWrapperClass = "com.bytedance.pico.openmr.spatial.pack.SSMRJNIWrapper$PipelineJNIWrapper";
            private const string JavaPipelineTensorMapClass = "com.bytedance.pico.openmr.spatial.pack.utils.PipelineTensorMap";
            private const string JavaModelEncodingClass = "com.bytedance.pico.openmr.spatial.pack.utils.ModelEncoding";
            private const string JavaModelEncodingTypeClass = "com.bytedance.pico.openmr.spatial.pack.utils.ModelEncoding$EncodingType";
            private const string JavaSsmrPackage = "com.bytedance.pico.openmr.spatial";
            private const string JavaSsmrAction = "com.bytedance.pico.openmr.spatial.SSMRService";

            private static readonly object BindLock = new object();
            private static volatile bool isConnected;
            private static volatile bool isConnecting;
            private static AndroidJavaObject appContext;
            private static ServiceConnectionProxy connectionProxy;

            private static InvalidOperationException WrapAndroidJavaException(AndroidJavaException exception)
            {
                return new InvalidOperationException(exception.Message, exception);
            }

            // Spatial JNI uses a different ordinal for BackendType than the public
            // SecureMRModelTarget enum. Translate here so callers can keep using the
            // existing public enum on both XR and Spatial backends.
            //   Spatial JNI: CPU = 0, GPU = 1, NPU = 2
            //   SecureMRModelTarget: Npu = 1, Gpu = 2, Cpu = 3
            internal static int ToSpatialBackendType(SecureMRModelTarget target)
            {
                switch (target)
                {
                    case SecureMRModelTarget.Cpu: return 0;
                    case SecureMRModelTarget.Gpu: return 1;
                    case SecureMRModelTarget.Npu: return 2;
                    default: return 2;
                }
            }

            // Spatial JNI runtime type ordinals (see SpatialSDK MR 3712 / OpenMR ModelTypes.h):
            //   WATERDROP = 0, TFLITE = 1
            internal const int SpatialRuntimeTypeWaterdrop = 0;
            internal const int SpatialRuntimeTypeTflite = 1;

            private static AndroidJavaObject GetModelEncodingType(int encodingType)
            {
                using (var encodingTypeClass = new AndroidJavaClass(JavaModelEncodingTypeClass))
                {
                    switch (encodingType)
                    {
                        case 1:
                            return encodingTypeClass.GetStatic<AndroidJavaObject>("FLOATING_POINT32");
                        case 2:
                            return encodingTypeClass.GetStatic<AndroidJavaObject>("UNSIGNED_FIXED_POINT8");
                        case 3:
                            return encodingTypeClass.GetStatic<AndroidJavaObject>("SIGNED_FIXED_POINT8");
                        case 4:
                            return encodingTypeClass.GetStatic<AndroidJavaObject>("UNSIGNED_FIXED_POINT16");
                        case 5:
                            return encodingTypeClass.GetStatic<AndroidJavaObject>("INT32");
                        default:
                            throw new ArgumentOutOfRangeException(nameof(encodingType), encodingType, null);
                    }
                }
            }
#endif

            public static bool EnsureConnected(int timeoutMs = 2000)
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                if (isConnected)
                {
                    return true;
                }

                StartBindIfNeeded();

                if (timeoutMs <= 0)
                {
                    return isConnected;
                }

                var sw = System.Diagnostics.Stopwatch.StartNew();
                while (sw.ElapsedMilliseconds < timeoutMs)
                {
                    if (isConnected)
                    {
                        return true;
                    }

                    Thread.Sleep(50);
                }

                return isConnected;
#else
                return false;
#endif
            }

#if UNITY_ANDROID && !UNITY_EDITOR
            private static void StartBindIfNeeded()
            {
                lock (BindLock)
                {
                    if (isConnected || isConnecting)
                    {
                        return;
                    }

                    isConnecting = true;

                    if (connectionProxy == null)
                    {
                        connectionProxy = new ServiceConnectionProxy();
                    }

                    if (appContext == null)
                    {
                        using (var unityPlayer = new AndroidJavaClass("com.unity3d.player.UnityPlayer"))
                        {
                            var activity = unityPlayer.GetStatic<AndroidJavaObject>("currentActivity");
                            appContext = activity.Call<AndroidJavaObject>("getApplicationContext");
                        }
                    }

                    using (var intent = new AndroidJavaObject("android.content.Intent"))
                    {
                        intent.Call<AndroidJavaObject>("setPackage", JavaSsmrPackage);
                        intent.Call<AndroidJavaObject>("setAction", JavaSsmrAction);
                        var bound = appContext.Call<bool>("bindService", intent, connectionProxy, 1);
                        if (!bound)
                        {
                            isConnecting = false;
                        }
                    }
                }
            }

            private sealed class ServiceConnectionProxy : AndroidJavaProxy
            {
                public ServiceConnectionProxy() : base("android.content.ServiceConnection")
                {
                }

                public void onServiceConnected(AndroidJavaObject name, AndroidJavaObject service)
                {
                    try
                    {
                        SetBinder(service);
                        isConnected = true;
                    }
                    catch
                    {
                        isConnected = false;
                    }
                    finally
                    {
                        isConnecting = false;
                    }
                }

                public void onServiceDisconnected(AndroidJavaObject name)
                {
                    isConnected = false;
                }
            }
#endif

            public static void SetBinder(AndroidJavaObject ssmrBinder)
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                if (ssmrBinder == null)
                {
                    throw new ArgumentNullException(nameof(ssmrBinder));
                }

                try
                {
                    using (var cls = new AndroidJavaClass(JavaSsmrJniWrapperClass))
                    {
                        cls.CallStatic("setBinder", ssmrBinder);
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#endif
            }

            public static long CreateSessionHandle(long appFormId, int imageWidth, int imageHeight, int width, int height, int depth)
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                try
                {
                    using (var cls = new AndroidJavaClass(JavaSsmrJniWrapperClass))
                    {
                        return cls.CallStatic<long>("createSessionHandle", appFormId, imageWidth, imageHeight, width, height, depth);
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#else
                return 0;
#endif
            }

            public static long ChangeContainerSize(long sessionHandle, int width, int height, int depth)
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                try
                {
                    using (var cls = new AndroidJavaClass(JavaSsmrJniWrapperClass))
                    {
                        return cls.CallStatic<long>("changeContainerSize", sessionHandle, width, height, depth);
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#else
                return 0;
#endif
            }

            public static void DestroySessionHandle(long sessionHandle)
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                try
                {
                    using (var cls = new AndroidJavaClass(JavaSsmrJniWrapperClass))
                    {
                        cls.CallStatic("destroySessionHandle", sessionHandle);
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#endif
            }

            public static long CreateTensor(long sessionHandle, int flag, int[] dimensions)
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                if (dimensions == null)
                {
                    throw new ArgumentNullException(nameof(dimensions));
                }

                try
                {
                    using (var cls = new AndroidJavaClass(JavaSsmrJniWrapperClass))
                    {
                        return cls.CallStatic<long>("createTensor", sessionHandle, flag, dimensions);
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#else
                return 0;
#endif
            }

            public static long CreateScene(long sessionHandle, AndroidJavaObject contentSharedMemory)
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                if (contentSharedMemory == null)
                {
                    throw new ArgumentNullException(nameof(contentSharedMemory));
                }

                try
                {
                    using (var cls = new AndroidJavaClass(JavaSsmrJniWrapperClass))
                    {
                        return cls.CallStatic<long>("createScene", sessionHandle, contentSharedMemory);
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#else
                return 0;
#endif
            }

            public static void ResetTensor(long globalTensorId, AndroidJavaObject contentSharedMemory)
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                if (contentSharedMemory == null)
                {
                    throw new ArgumentNullException(nameof(contentSharedMemory));
                }

                try
                {
                    using (var cls = new AndroidJavaClass(JavaSsmrJniWrapperClass))
                    {
                        cls.CallStatic("resetTensor", globalTensorId, contentSharedMemory);
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#endif
            }

            public static void DestroyTensor(long globalTensorId)
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                try
                {
                    using (var cls = new AndroidJavaClass(JavaSsmrJniWrapperClass))
                    {
                        cls.CallStatic("destroyTensor", globalTensorId);
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#endif
            }

            public static AndroidJavaObject ReadbackSharedMemory(long globalTensorId)
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                try
                {
                    using (var cls = new AndroidJavaClass(JavaSsmrJniWrapperClass))
                    {
                        return cls.CallStatic<AndroidJavaObject>("readbackSharedMemory", globalTensorId);
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#else
                return null;
#endif
            }

            public static long ReadbackTextureId(long globalTensorId)
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                try
                {
                    using (var cls = new AndroidJavaClass(JavaSsmrJniWrapperClass))
                    {
                        return cls.CallStatic<long>("readbackTextureId", globalTensorId);
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#else
                return 0;
#endif
            }

            public static long CreatePipeline(long sessionId)
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                try
                {
                    using (var cls = new AndroidJavaClass(JavaPipelineJniWrapperClass))
                    {
                        return cls.CallStatic<long>("create", sessionId);
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#else
                return 0;
#endif
            }

            public static void DestroyPipeline(long pipelineId)
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                try
                {
                    using (var cls = new AndroidJavaClass(JavaPipelineJniWrapperClass))
                    {
                        cls.CallStatic("destroy", pipelineId);
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#endif
            }

            public static long SubmitPipeline(long pipelineId, long waitFor, long conditionTensor, long tensorMap)
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                try
                {
                    using (var cls = new AndroidJavaClass(JavaPipelineJniWrapperClass))
                    {
                        return cls.CallStatic<long>("submit", pipelineId, waitFor, conditionTensor, tensorMap);
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#else
                return 0;
#endif
            }

            public static long PipelineCreateTensor(long pipelineId, int flag, int[] dimensions, bool hasLocalMemory)
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                if (dimensions == null)
                {
                    throw new ArgumentNullException(nameof(dimensions));
                }

                try
                {
                    using (var cls = new AndroidJavaClass(JavaPipelineJniWrapperClass))
                    {
                        return cls.CallStatic<long>("createTensor", pipelineId, flag, dimensions, hasLocalMemory);
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#else
                return 0;
#endif
            }

            public static void PipelineResetTensor(long pipelineId, long pipelineTensorId, AndroidJavaObject contentSharedMemory)
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                if (contentSharedMemory == null)
                {
                    throw new ArgumentNullException(nameof(contentSharedMemory));
                }

                try
                {
                    using (var cls = new AndroidJavaClass(JavaPipelineJniWrapperClass))
                    {
                        cls.CallStatic("resetTensor", pipelineId, pipelineTensorId, contentSharedMemory);
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#endif
            }

            public static long PipelineAddOperator(long pipelineId, int operatorType, string config)
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                try
                {
                    using (var cls = new AndroidJavaClass(JavaPipelineJniWrapperClass))
                    {
                        return cls.CallStatic<long>("addOperator", pipelineId, operatorType, config);
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#else
                return 0;
#endif
            }

            public static long PipelineAddModelInference(long pipelineId, string modelKey, AndroidJavaObject modelBinSharedMemory, long modelEncodingId)
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                if (modelKey == null)
                {
                    throw new ArgumentNullException(nameof(modelKey));
                }

                if (modelBinSharedMemory == null)
                {
                    throw new ArgumentNullException(nameof(modelBinSharedMemory));
                }

                try
                {
                    using (var cls = new AndroidJavaClass(JavaPipelineJniWrapperClass))
                    {
                        return cls.CallStatic<long>("addModelInference", pipelineId, modelKey, modelBinSharedMemory, modelEncodingId);
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#else
                return 0;
#endif
            }

            // Calls the 6-arg Java overload added in SpatialSDK MR 3712. Use this for
            // LiteRT/TFLite models. runtimeType uses the Spatial JNI ordinals
            // (WATERDROP = 0, TFLITE = 1); backendType uses the Spatial JNI ordinals
            // (CPU = 0, GPU = 1, NPU = 2). For SecureMRModelTarget translation, use
            // ToSpatialBackendType().
            public static long PipelineAddModelInference(long pipelineId, string modelKey, AndroidJavaObject modelBinSharedMemory, long modelEncodingId, int runtimeType, int backendType)
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                if (modelKey == null)
                {
                    throw new ArgumentNullException(nameof(modelKey));
                }

                if (modelBinSharedMemory == null)
                {
                    throw new ArgumentNullException(nameof(modelBinSharedMemory));
                }

                try
                {
                    using (var cls = new AndroidJavaClass(JavaPipelineJniWrapperClass))
                    {
                        return cls.CallStatic<long>("addModelInference", pipelineId, modelKey, modelBinSharedMemory, modelEncodingId, runtimeType, backendType);
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#else
                return 0;
#endif
            }

            public static void PipelineSetOperand(long opId, long pipelineTensorId, int operandIdx)
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                try
                {
                    using (var cls = new AndroidJavaClass(JavaPipelineJniWrapperClass))
                    {
                        cls.CallStatic("setOperand", opId, pipelineTensorId, operandIdx);
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#endif
            }

            public static void PipelineSetResult(long opId, long pipelineTensorId, int resultIdx)
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                try
                {
                    using (var cls = new AndroidJavaClass(JavaPipelineJniWrapperClass))
                    {
                        cls.CallStatic("setResult", opId, pipelineTensorId, resultIdx);
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#endif
            }

            public static void PipelineSetOperandByName(long opId, long pipelineTensorId, string operandName)
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                if (operandName == null)
                {
                    throw new ArgumentNullException(nameof(operandName));
                }

                try
                {
                    using (var cls = new AndroidJavaClass(JavaPipelineJniWrapperClass))
                    {
                        cls.CallStatic("setOperandByName", opId, pipelineTensorId, operandName);
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#endif
            }

            public static void PipelineSetResultByName(long opId, long pipelineTensorId, string resultName)
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                if (resultName == null)
                {
                    throw new ArgumentNullException(nameof(resultName));
                }

                try
                {
                    using (var cls = new AndroidJavaClass(JavaPipelineJniWrapperClass))
                    {
                        cls.CallStatic("setResultByName", opId, pipelineTensorId, resultName);
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#endif
            }

            public static long PipelineTensorMapCreate()
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                try
                {
                    using (var cls = new AndroidJavaClass(JavaPipelineTensorMapClass))
                    {
                        return cls.CallStatic<long>("create");
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#else
                return 0;
#endif
            }

            public static void PipelineTensorMapAdd(long map, long pipelineTensorId, long globalTensorId)
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                try
                {
                    using (var cls = new AndroidJavaClass(JavaPipelineTensorMapClass))
                    {
                        cls.CallStatic("add", map, pipelineTensorId, globalTensorId);
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#endif
            }

            public static void PipelineTensorMapDestroy(long map)
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                try
                {
                    using (var cls = new AndroidJavaClass(JavaPipelineTensorMapClass))
                    {
                        cls.CallStatic("destroy", map);
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#endif
            }

            public static long ModelEncodingCreate()
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                try
                {
                    using (var cls = new AndroidJavaClass(JavaModelEncodingClass))
                    {
                        return cls.CallStatic<long>("create");
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#else
                return 0;
#endif
            }

            public static void ModelEncodingAdd(long encodingId, bool isInput, string name, string alias, int encodingType)
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                if (name == null)
                {
                    throw new ArgumentNullException(nameof(name));
                }

                try
                {
                    using (var cls = new AndroidJavaClass(JavaModelEncodingClass))
                    using (var typeObj = GetModelEncodingType(encodingType))
                    {
                        cls.CallStatic("add", encodingId, isInput, name, alias, typeObj);
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#endif
            }

            public static void ModelEncodingDestroy(long encodingId)
            {
#if UNITY_ANDROID && !UNITY_EDITOR
                try
                {
                    using (var cls = new AndroidJavaClass(JavaModelEncodingClass))
                    {
                        cls.CallStatic("destroy", encodingId);
                    }
                }
                catch (AndroidJavaException e)
                {
                    throw WrapAndroidJavaException(e);
                }
#endif
            }

            public sealed class PipelineTensorMap : IDisposable
            {
                public long Handle { get; private set; }

                public PipelineTensorMap()
                {
                    Handle = PipelineTensorMapCreate();
                }

                public void Add(long pipelineTensorId, long globalTensorId)
                {
                    if (Handle == 0)
                    {
                        throw new ObjectDisposedException(nameof(PipelineTensorMap));
                    }

                    PipelineTensorMapAdd(Handle, pipelineTensorId, globalTensorId);
                }

                public void Dispose()
                {
                    if (Handle == 0)
                    {
                        return;
                    }

                    PipelineTensorMapDestroy(Handle);
                    Handle = 0;
                }
            }

            public sealed class ModelEncoding : IDisposable
            {
                public long Handle { get; private set; }

                public ModelEncoding()
                {
                    Handle = ModelEncodingCreate();
                }

                public void AddInput(string name, string alias, int encodingType)
                {
                    if (Handle == 0)
                    {
                        throw new ObjectDisposedException(nameof(ModelEncoding));
                    }

                    ModelEncodingAdd(Handle, true, name, alias, encodingType);
                }

                public void AddOutput(string name, string alias, int encodingType)
                {
                    if (Handle == 0)
                    {
                        throw new ObjectDisposedException(nameof(ModelEncoding));
                    }

                    ModelEncodingAdd(Handle, false, name, alias, encodingType);
                }

                public void Dispose()
                {
                    if (Handle == 0)
                    {
                        return;
                    }

                    ModelEncodingDestroy(Handle);
                    Handle = 0;
                }
            }
        }


        #endregion

        public static readonly Dictionary<Type, SecureMRTensorDataType> TensorDataTypeToEnum =
            new Dictionary<Type, SecureMRTensorDataType>
            {
                { typeof(char), SecureMRTensorDataType.Byte },
                { typeof(byte), SecureMRTensorDataType.Byte },
                { typeof(sbyte), SecureMRTensorDataType.Sbyte },
                { typeof(ushort), SecureMRTensorDataType.Ushort },
                { typeof(short), SecureMRTensorDataType.Short },
                { typeof(int), SecureMRTensorDataType.Int },
                { typeof(float), SecureMRTensorDataType.Float },
                { typeof(double), SecureMRTensorDataType.Double },
            };

        public static readonly Dictionary<Type, SecureMRTensorUsage> TensorClassToEnum =
            new Dictionary<Type, SecureMRTensorUsage>
            {
                { typeof(Scalar), SecureMRTensorUsage.Scalar },
                { typeof(Point), SecureMRTensorUsage.Point },
                { typeof(Slice), SecureMRTensorUsage.Slice },
                { typeof(Color), SecureMRTensorUsage.Color },
                { typeof(TimeStamp), SecureMRTensorUsage.TimeStamp },
                { typeof(Matrix), SecureMRTensorUsage.Matrix },
                { typeof(DynamicTexture), SecureMRTensorUsage.DynamicTexture }
            };

        public static readonly Dictionary<SecureMRTensorUsage, Type> TensorEnumToClass =
            new Dictionary<SecureMRTensorUsage, Type>
            {
                { SecureMRTensorUsage.Scalar, typeof(Scalar) },
                { SecureMRTensorUsage.Point, typeof(Point) },
                { SecureMRTensorUsage.Slice, typeof(Slice) },
                { SecureMRTensorUsage.Color, typeof(Color) },
                { SecureMRTensorUsage.TimeStamp, typeof(TimeStamp) },
                { SecureMRTensorUsage.Matrix, typeof(Matrix) },
                { SecureMRTensorUsage.DynamicTexture, typeof(DynamicTexture) }
            };

        public static readonly Dictionary<Type, SecureMROperatorType> OperatorClassToEnum =
            new Dictionary<Type, SecureMROperatorType>
            {
                { typeof(ArithmeticComposeOperator), SecureMROperatorType.ArithmeticCompose },
                { typeof(ElementwiseMinOperator), SecureMROperatorType.ElementwiseMin },
                { typeof(ElementwiseMaxOperator), SecureMROperatorType.ElementwiseMax },
                { typeof(ElementwiseMultiplyOperator), SecureMROperatorType.ElementwiseMultiply },
                { typeof(CustomizedCompareOperator), SecureMROperatorType.CustomizedCompare },
                { typeof(ElementwiseOrOperator), SecureMROperatorType.ElementwiseOr },
                { typeof(ElementwiseAndOperator), SecureMROperatorType.ElementwiseAnd },
                { typeof(AllOperator), SecureMROperatorType.All },
                { typeof(AnyOperator), SecureMROperatorType.Any },
                { typeof(NmsOperator), SecureMROperatorType.Nms },
                { typeof(SolvePnPOperator), SecureMROperatorType.SolvePnP },
                { typeof(GetAffineOperator), SecureMROperatorType.GetAffine },
                { typeof(ApplyAffineOperator), SecureMROperatorType.ApplyAffine },
                { typeof(ApplyAffinePointOperator), SecureMROperatorType.ApplyAffinePoint },
                { typeof(UvTo3DInCameraSpaceOperator), SecureMROperatorType.UvTo3DInCameraSpace },
                { typeof(AssignmentOperator), SecureMROperatorType.Assignment },
                { typeof(RunModelInferenceOperator), SecureMROperatorType.RunModelInference },
                { typeof(NormalizeOperator), SecureMROperatorType.Normalize },
                { typeof(CameraSpaceToWorldOperator), SecureMROperatorType.CameraSpaceToWorld },
                { typeof(RectifiedVstAccessOperator), SecureMROperatorType.RectifiedVstAccess },
                { typeof(ArgmaxOperator), SecureMROperatorType.Argmax },
                { typeof(ConvertColorOperator), SecureMROperatorType.ConvertColor },
                { typeof(SortVectorOperator), SecureMROperatorType.SortVector },
                { typeof(InversionOperator), SecureMROperatorType.Inversion },
                { typeof(GetTransformMatrixOperator), SecureMROperatorType.GetTransformMatrix },
                { typeof(SortMatrixOperator), SecureMROperatorType.SortMatrix },
                { typeof(SwitchGltfRenderStatusOperator), SecureMROperatorType.SwitchGltfRenderStatus },
                { typeof(UpdateGltfOperator), SecureMROperatorType.UpdateGltf },
                { typeof(RenderTextOperator), SecureMROperatorType.RenderText },
                { typeof(LoadTextureOperator), SecureMROperatorType.LoadTexture },
                { typeof(SvdOperator), SecureMROperatorType.Svd },
                { typeof(NormOperator), SecureMROperatorType.Norm },
                { typeof(SwapHwcChwOperator), SecureMROperatorType.SwapHwcChw },
                { typeof(ScenegraphVisibilityOperator), SecureMROperatorType.ScenegraphVisibility },
                { typeof(UpdateComponentOperator), SecureMROperatorType.UpdateComponent },
                { typeof(JavascriptOperator), SecureMROperatorType.Javascript },
                { typeof(MicrophoneOperator), SecureMROperatorType.Microphone },
                { typeof(SpeakerOperator), SecureMROperatorType.Speaker },
                { typeof(DepthOperator), SecureMROperatorType.Depth }
            };

        public static PxrResult UPxr_CreateSecureMRProvider(int width, int height, out ulong providerHandle)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                var result = Pxr_CreateSecureMRFramework(width, height, out providerHandle);

                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);
#else
            providerHandle = 0;
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_DestroySecureMRProvider(ulong providerHandle)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                var result = Pxr_DestroySecureMRFramework(providerHandle);

                return  PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);

#else
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_CreateSecureMRPipeline(ulong providerHandle, out ulong pipelineHandle)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                var result = Pxr_CreateSecureMRPipeline(providerHandle, out pipelineHandle);
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);
#else
            pipelineHandle = 0;
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_DestroySecureMRPipeline(ulong pipelineHandle)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                var result = Pxr_DestroySecureMRPipeline(pipelineHandle);
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);
#else
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_SetSecureMROperatorOperandByName(ulong pipelineHandle, ulong operatorHandle,
            ulong tensorHandle, string name)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                var result = Pxr_SetSecureMROperatorOperandByName(pipelineHandle, operatorHandle, tensorHandle, name);
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);
#else
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_SetSecureMROperatorResultByName(ulong pipelineHandle, ulong operatorHandle,
            ulong tensorHandle, string name)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                var result = Pxr_SetSecureMROperatorResultByName(pipelineHandle, operatorHandle, tensorHandle, name);
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);
#else
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_ExecuteSecureMRPipeline(ulong pipelineHandle,
            Dictionary<ulong, ulong> tensorMappings, out ulong pipelineRunHandle)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                SecureMRPipelineExecuteParameter parameter = new SecureMRPipelineExecuteParameter
                {
                    type = XrStructureType.XR_TYPE_SECURE_MR_PIPELINE_EXECUTE_PARAMETER_PICO,
                    next = IntPtr.Zero,
                    pipelineRunToBeWaited = 0,
                    conditionTensor = 0,
                    pairCount = 0,
                    pipelineIOPair = IntPtr.Zero
                };

                if (tensorMappings != null && tensorMappings.Count > 0)
                {
                    parameter.pairCount = (uint)tensorMappings.Count;
                    List<SecureMRPipelineIOPair> pairs = new List<SecureMRPipelineIOPair>();
                    foreach (var tensorMapping in tensorMappings)
                    {
                        SecureMRPipelineIOPair pair = new SecureMRPipelineIOPair
                        {
                            type = XrStructureType.XR_TYPE_SECURE_MR_PIPELINE_IO_PAIR_PICO,
                            next = IntPtr.Zero,
                            localPlaceHolderTensor = tensorMapping.Key,
                            globalTensor = tensorMapping.Value,
                        };
                        pairs.Add(pair);
                    }

                    int structSize = Marshal.SizeOf(typeof(SecureMRPipelineIOPair));
                    parameter.pipelineIOPair = Marshal.AllocHGlobal(structSize * tensorMappings.Count);
                    for (int i = 0; i < tensorMappings.Count; i++)
                    {
                        IntPtr temp = parameter.pipelineIOPair + i * structSize;
                        Marshal.StructureToPtr(pairs[i], temp, false);
                    }
                }

                var result = Pxr_ExecuteSecureMRPipeline(pipelineHandle, ref parameter, out pipelineRunHandle);

                Marshal.FreeHGlobal(parameter.pipelineIOPair);
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);
#else
            pipelineRunHandle = 0;
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_ExecuteSecureMRPipelineAfter(ulong pipelineHandle, ulong lastPipelineRunHandle,
            Dictionary<ulong, ulong> tensorMappings, out ulong pipelineRunHandle)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                SecureMRPipelineExecuteParameter parameter = new SecureMRPipelineExecuteParameter
                {
                    type = XrStructureType.XR_TYPE_SECURE_MR_PIPELINE_EXECUTE_PARAMETER_PICO,
                    next = IntPtr.Zero,
                    pipelineRunToBeWaited = lastPipelineRunHandle,
                    conditionTensor = 0,
                };
                parameter.pairCount = (uint)tensorMappings.Count;

                List<SecureMRPipelineIOPair> pairs = new List<SecureMRPipelineIOPair>();
                foreach (var tensorMapping in tensorMappings)
                {
                    SecureMRPipelineIOPair pair = new SecureMRPipelineIOPair
                    {
                        type = XrStructureType.XR_TYPE_SECURE_MR_PIPELINE_IO_PAIR_PICO,
                        next = IntPtr.Zero,
                        localPlaceHolderTensor = tensorMapping.Key,
                        globalTensor = tensorMapping.Value,
                    };
                    pairs.Add(pair);
                }

                int structSize = Marshal.SizeOf(typeof(SecureMRPipelineIOPair));
                parameter.pipelineIOPair = Marshal.AllocHGlobal(structSize * tensorMappings.Count);
                for (int i = 0; i < tensorMappings.Count; i++)
                {
                    IntPtr temp = parameter.pipelineIOPair + i * structSize;
                    Marshal.StructureToPtr(pairs[i], temp, false);
                }

                var result = Pxr_ExecuteSecureMRPipeline(pipelineHandle, ref parameter, out pipelineRunHandle);

                Marshal.FreeHGlobal(parameter.pipelineIOPair);
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);
#else
            pipelineRunHandle = 0;
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_ExecuteSecureMRPipelineConditional(ulong pipelineHandle, ulong conditionTensor,
            Dictionary<ulong, ulong> tensorMappings, out ulong pipelineRunHandle)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                SecureMRPipelineExecuteParameter parameter = new SecureMRPipelineExecuteParameter
                {
                    type = XrStructureType.XR_TYPE_SECURE_MR_PIPELINE_EXECUTE_PARAMETER_PICO,
                    next = IntPtr.Zero,
                    pipelineRunToBeWaited = 0,
                    conditionTensor = conditionTensor,
                };
                parameter.pairCount = (uint)tensorMappings.Count;

                List<SecureMRPipelineIOPair> pairs = new List<SecureMRPipelineIOPair>();
                foreach (var tensorMapping in tensorMappings)
                {
                    SecureMRPipelineIOPair pair = new SecureMRPipelineIOPair
                    {
                        type = XrStructureType.XR_TYPE_SECURE_MR_PIPELINE_IO_PAIR_PICO,
                        next = IntPtr.Zero,
                        localPlaceHolderTensor = tensorMapping.Key,
                        globalTensor = tensorMapping.Value,
                    };
                    pairs.Add(pair);
                }

                int structSize = Marshal.SizeOf(typeof(SecureMRPipelineIOPair));
                parameter.pipelineIOPair = Marshal.AllocHGlobal(structSize * tensorMappings.Count);
                for (int i = 0; i < tensorMappings.Count; i++)
                {
                    IntPtr temp = parameter.pipelineIOPair + i * structSize;
                    Marshal.StructureToPtr(pairs[i], temp, false);
                }

                var result = Pxr_ExecuteSecureMRPipeline(pipelineHandle, ref parameter, out pipelineRunHandle);

                Marshal.FreeHGlobal(parameter.pipelineIOPair);
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);
#else
            pipelineRunHandle = 0;
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_CreateSecureMRTensorByShape(ulong frameworkHandle, SecureMRTensorDataType dataType,
            int[] dimensions, sbyte channel, SecureMRTensorUsage usage, out ulong tensorHandle)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                SecureMRTensorCreateInfoShape createInfo = new SecureMRTensorCreateInfoShape
                {
                    type = XrStructureType.XR_TYPE_SECURE_MR_TENSOR_CREATE_INFO_SHAPE_PICO,
                    next = IntPtr.Zero,
                    placeHolder = false,
                    dimensionsCount = (uint)dimensions.Length,
                    dimensions = IntPtr.Zero,
                    format = IntPtr.Zero
                };

                SecureMRTensorFormat tensorFormat = new SecureMRTensorFormat
                {
                    dataType = dataType,
                    channel = channel,
                    tensorUsage = usage,
                };

                if (dimensions.Length > 0)
                {
                    int size = Marshal.SizeOf(typeof(int)) * dimensions.Length;
                    createInfo.dimensions = Marshal.AllocHGlobal(size);
                    Marshal.Copy(dimensions, 0, createInfo.dimensions, size);
                }

                int size1 = Marshal.SizeOf(typeof(SecureMRTensorFormat));
                createInfo.format = Marshal.AllocHGlobal(size1);
                Marshal.StructureToPtr(tensorFormat, createInfo.format, false);

                var result = Pxr_CreateSecureMRTensorByShape(frameworkHandle, createInfo, out tensorHandle);
                if (dimensions.Length > 0)
                {
                    Marshal.FreeHGlobal(createInfo.dimensions);
                }
                
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);
#else
            tensorHandle = 0;
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_CreateSecureMRPipelineTensorByShape(ulong pipelineHandle, bool placeHolder,
            SecureMRTensorDataType dataType, int[] dimensions, sbyte channel, SecureMRTensorUsage usage,
            out ulong tensorHandle)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                SecureMRTensorCreateInfoShape createInfo = new SecureMRTensorCreateInfoShape
                {
                    type = XrStructureType.XR_TYPE_SECURE_MR_TENSOR_CREATE_INFO_SHAPE_PICO,
                    next = IntPtr.Zero,
                    placeHolder = placeHolder,
                    dimensionsCount = 0,
                    dimensions = IntPtr.Zero,
                    format = IntPtr.Zero
                };

                SecureMRTensorFormat tensorFormat = new SecureMRTensorFormat
                {
                    dataType = dataType,
                    channel = channel,
                    tensorUsage = usage,
                };

                if (dimensions.Length > 0)
                {
                    createInfo.dimensionsCount = (uint)dimensions.Length;
                    int size = Marshal.SizeOf(typeof(int)) * dimensions.Length;
                    createInfo.dimensions = Marshal.AllocHGlobal(size);
                    Marshal.Copy(dimensions, 0, createInfo.dimensions, size);
                }

                int size1 = Marshal.SizeOf(typeof(SecureMRTensorFormat));
                createInfo.format = Marshal.AllocHGlobal(size1);
                Marshal.StructureToPtr(tensorFormat, createInfo.format, false);
                var result = Pxr_CreateSecureMRPipelineTensorByShape(pipelineHandle, createInfo, out tensorHandle);
                if (dimensions.Length > 0)
                {
                    Marshal.FreeHGlobal(createInfo.dimensions);
                }
                
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);
#else
            tensorHandle = 0;
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_CreateSecureMRTensorByGltf(ulong frameworkHandle, byte[] gltfData,
            out ulong tensorHandle)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                SecureMRTensorCreateInfoGltf createInfo = new SecureMRTensorCreateInfoGltf
                {
                    type = XrStructureType.XR_TYPE_SECURE_MR_TENSOR_CREATE_INFO_GLTF_PICO,
                    next = IntPtr.Zero,
                    placeHolder = false,
                };
                int size = Marshal.SizeOf(typeof(byte)) * gltfData.Length;

                createInfo.bufferSize = (uint)size;
                createInfo.buffer = Marshal.AllocHGlobal(size);
                Marshal.Copy(gltfData, 0, createInfo.buffer, size);

                var result = Pxr_CreateSecureMRTensorByGltf(frameworkHandle, createInfo, out tensorHandle);
                Marshal.FreeHGlobal(createInfo.buffer);
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);
#else
            tensorHandle = 0;
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_CreateSecureMRPipelineTensorByGltf(ulong pipelineHandle, bool placeHolder,
            byte[] gltfData, out ulong tensorHandle)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                SecureMRTensorCreateInfoGltf createInfo = new SecureMRTensorCreateInfoGltf
                {
                    type = XrStructureType.XR_TYPE_SECURE_MR_TENSOR_CREATE_INFO_GLTF_PICO,
                    next = IntPtr.Zero,
                    placeHolder = placeHolder,
                    bufferSize = 0,
                    buffer = IntPtr.Zero
                };

                if (gltfData!=null && gltfData.Length > 0)
                {
                    int size = Marshal.SizeOf(typeof(byte)) * gltfData.Length;
                    createInfo.bufferSize = (uint)size;
                    createInfo.buffer = Marshal.AllocHGlobal(size);
                    Marshal.Copy(gltfData, 0, createInfo.buffer, size);
                }
                var result = Pxr_CreateSecureMRPipelineTensorByGltf(pipelineHandle, createInfo, out tensorHandle);
                if (gltfData!=null && gltfData.Length > 0)
                {
                    Marshal.FreeHGlobal(createInfo.buffer);
                }
                
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);
#else
            tensorHandle = 0;
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_ResetSecureMRTensor<T>(ulong tensorHandle, T[] tensorData)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                SecureMRTensorBuffer buffer = new SecureMRTensorBuffer
                {
                    type = XrStructureType.XR_TYPE_SECURE_MR_TENSOR_BUFFER_PICO,
                    next = IntPtr.Zero,
                    bufferSize = 0
                };

                int size = Marshal.SizeOf(typeof(T)) * tensorData.Length;
                buffer.bufferSize = (uint)size;
                buffer.buffer = Marshal.AllocHGlobal(size);
                if (typeof(T) == typeof(byte))
                {
                    Marshal.Copy(tensorData as byte[], 0, buffer.buffer, tensorData.Length);
                }
                else if (typeof(T) == typeof(sbyte))
                {
                    sbyte[] sbyteArray = tensorData as sbyte[];
                    byte[] byteArray = new byte[size];
                    Buffer.BlockCopy(sbyteArray, 0, byteArray, 0, size);
                    Marshal.Copy(byteArray, 0, buffer.buffer, size);
                }
                else if (typeof(T) == typeof(short))
                {
                    Marshal.Copy(tensorData as short[], 0, buffer.buffer, tensorData.Length);
                }
                else if (typeof(T) == typeof(ushort))
                {
                    ushort[] ushortArray = tensorData as ushort[];
                    byte[] byteArray = new byte[size];
                    Buffer.BlockCopy(ushortArray, 0, byteArray, 0, size);
                    Marshal.Copy(byteArray, 0, buffer.buffer, size);
                }
                else if (typeof(T) == typeof(int))
                {
                    Marshal.Copy(tensorData as int[], 0, buffer.buffer, tensorData.Length);
                }
                else if (typeof(T) == typeof(float))
                {
                    Marshal.Copy(tensorData as float[], 0, buffer.buffer, tensorData.Length);
                }
                else if (typeof(T) == typeof(double))
                {
                    double[] doubleArray = tensorData as double[];
                    byte[] byteArray = new byte[size];
                    Buffer.BlockCopy(doubleArray, 0, byteArray, 0, size);
                    Marshal.Copy(byteArray, 0, buffer.buffer, size);
                }

                var result = Pxr_ResetSecureMRTensor(tensorHandle, ref buffer);

                Marshal.FreeHGlobal(buffer.buffer);
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);
#else
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_ResetSecureMRPipelineTensor<T>(ulong pipelineHandle, ulong tensorHandle,
            T[] tensorData)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                SecureMRTensorBuffer buffer = new SecureMRTensorBuffer
                {
                    type = XrStructureType.XR_TYPE_SECURE_MR_TENSOR_BUFFER_PICO,
                    next = IntPtr.Zero,
                };

                int size = Marshal.SizeOf(typeof(T)) * tensorData.Length;
                buffer.bufferSize = (uint)size;
                buffer.buffer = Marshal.AllocHGlobal(size);
                if (typeof(T) == typeof(byte))
                {
                    Marshal.Copy(tensorData as byte[], 0, buffer.buffer, tensorData.Length);
                }
                else if (typeof(T) == typeof(sbyte))
                {
                    sbyte[] sbyteArray = tensorData as sbyte[];
                    byte[] byteArray = new byte[size];
                    Buffer.BlockCopy(sbyteArray, 0, byteArray, 0, size);
                    Marshal.Copy(byteArray, 0, buffer.buffer, size);
                }
                else if (typeof(T) == typeof(short))
                {
                    Marshal.Copy(tensorData as short[], 0, buffer.buffer, tensorData.Length);
                }
                else if (typeof(T) == typeof(ushort))
                {
                    ushort[] ushortArray = tensorData as ushort[];
                    byte[] byteArray = new byte[size];
                    Buffer.BlockCopy(ushortArray, 0, byteArray, 0, size);
                    Marshal.Copy(byteArray, 0, buffer.buffer, size);
                }
                else if (typeof(T) == typeof(int))
                {
                    Marshal.Copy(tensorData as int[], 0, buffer.buffer, tensorData.Length);
                }
                else if (typeof(T) == typeof(float))
                {
                    Marshal.Copy(tensorData as float[], 0, buffer.buffer, tensorData.Length);
                }
                else if (typeof(T) == typeof(double))
                {
                    double[] doubleArray = tensorData as double[];
                    byte[] byteArray = new byte[size];
                    Buffer.BlockCopy(doubleArray, 0, byteArray, 0, size);
                    Marshal.Copy(byteArray, 0, buffer.buffer, size);
                }

                var result = Pxr_ResetSecureMRPipelineTensor(pipelineHandle, tensorHandle, ref buffer);

                Marshal.FreeHGlobal(buffer.buffer);
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);
#else
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_DestroySecureMRTensor(ulong tensorHandle)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                var result = Pxr_DestroySecureMRTensor(tensorHandle);
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);
#else
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_CreateSecureMROperator(ulong pipelineHandle, SecureMROperatorType operatorType,
            out ulong operatorHandle)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                var result = Pxr_CreateSecureMROperator(pipelineHandle, operatorType, out operatorHandle);
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);
#else
            operatorHandle = 0;
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_CreateSecureMROperatorArithmeticCompose(ulong pipelineHandle, string configText,
            out ulong operatorHandle)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                SecureMROperatorArithmeticCompose config = new SecureMROperatorArithmeticCompose
                {
                    type = XrStructureType.XR_TYPE_SECURE_MR_OPERATOR_ARITHMETIC_COMPOSE_PICO,
                    next = IntPtr.Zero,
                };

                config.configText = new byte[2048];
                byte[] stringBytes = Encoding.UTF8.GetBytes(configText);
                int copyLength = Math.Min(stringBytes.Length, 2048);
                Array.Copy(stringBytes,config.configText,copyLength);

                var result =
 Pxr_CreateSecureMROperatorArithmeticCompose(pipelineHandle, ref config, out operatorHandle);
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);
#else
            operatorHandle = 0;
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_CreateSecureMROperatorComparison(ulong pipelineHandle,
            SecureMRComparison comparison, out ulong operatorHandle)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                SecureMROperatorComparison config = new SecureMROperatorComparison
                {
                    type = XrStructureType.XR_TYPE_SECURE_MR_OPERATOR_COMPARISON_PICO,
                    next = IntPtr.Zero,
                    comparison = comparison
                };
                var result = Pxr_CreateSecureMROperatorComparison(pipelineHandle, ref config, out operatorHandle);
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);
#else
            operatorHandle = 0;
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_CreateSecureMROperatorNonMaximumSuppression(ulong pipelineHandle, float threshold,
            out ulong operatorHandle)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                SecureMROperatorNonMaximumSuppression config = new SecureMROperatorNonMaximumSuppression
                {
                    type = XrStructureType.XR_TYPE_SECURE_MR_OPERATOR_NON_MAXIMUM_SUPPRESSION_PICO,
                    next = IntPtr.Zero,
                    threshold = threshold,
                };
                var result =
 Pxr_CreateSecureMROperatorNonMaximumSuppression(pipelineHandle, ref config, out operatorHandle);
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);
#else
            operatorHandle = 0;
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_CreateSecureMROperatorUVTo3D(ulong pipelineHandle, out ulong operatorHandle)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                var result = Pxr_CreateSecureMROperatorUVTo3D(pipelineHandle, out operatorHandle);
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);
#else
            operatorHandle = 0;
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_CreateSecureMROperatorNormalize(ulong pipelineHandle,
            SecureMRNormalizeType normalizeType, out ulong operatorHandle)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                SecureMROperatorNormalize config = new SecureMROperatorNormalize
                {
                    type = XrStructureType.XR_TYPE_SECURE_MR_OPERATOR_NORMALIZE_PICO,
                    next = IntPtr.Zero,
                    normalizeType = normalizeType
                };
                var result = Pxr_CreateSecureMROperatorNormalize(pipelineHandle, ref config, out operatorHandle);
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);
#else
            operatorHandle = 0;
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_CreateSecureMROperatorColorConvert(ulong pipelineHandle, int convert,
            out ulong operatorHandle)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                SecureMROperatorColorConvert config = new SecureMROperatorColorConvert
                {
                    type = XrStructureType.XR_TYPE_SECURE_MR_OPERATOR_COLOR_CONVERT_PICO,
                    next = IntPtr.Zero,
                    convert = convert,
                };
                var result = Pxr_CreateSecureMROperatorColorConvert(pipelineHandle, ref config, out operatorHandle);
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);
#else
            operatorHandle = 0;
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_CreateSecureMROperatorSortMatrix(ulong pipelineHandle,
            SecureMRMatrixSortType sortType, out ulong operatorHandle)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                SecureMROperatorSortMatrix config = new SecureMROperatorSortMatrix
                {
                    type = XrStructureType.XR_TYPE_SECURE_MR_OPERATOR_SORT_MATRIX_PICO,
                    next = IntPtr.Zero,
                    sortType = sortType,
                };
                var result = Pxr_CreateSecureMROperatorSortMatrix(pipelineHandle, ref config, out operatorHandle);
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);
#else
            operatorHandle = 0;
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_CreateSecureMROperatorUpdateGltf(ulong pipelineHandle,
            SecureMRGltfOperatorAttribute attribute, out ulong operatorHandle)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                SecureMROperatorUpdateGltf config = new SecureMROperatorUpdateGltf
                {
                    type = XrStructureType.XR_TYPE_SECURE_MR_OPERATOR_UPDATE_GLTF_PICO,
                    next = IntPtr.Zero,
                    attribute = attribute
                };
                var result = Pxr_CreateSecureMROperatorUpdateGltf(pipelineHandle, ref config, out operatorHandle);
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);
#else
            operatorHandle = 0;
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_CreateSecureMROperatorRenderText(ulong pipelineHandle,
            SecureMRFontTypeface typeface, string languageAndLocale, int width, int height, out ulong operatorHandle)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                SecureMROperatorRenderText config = new SecureMROperatorRenderText
                {
                    type = XrStructureType.XR_TYPE_SECURE_MR_OPERATOR_RENDER_TEXT_PICO,
                    next = IntPtr.Zero,
                    typeFace = typeface,
                    languageAndLocale = languageAndLocale,
                    width = width,
                    height = height
                };
                var result = Pxr_CreateSecureMROperatorRenderText(pipelineHandle, ref config, out operatorHandle);
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);
#else
            operatorHandle = 0;
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_CreateSecureMrOperatorModel(
            ulong pipelineHandle,
            byte[] modelData,
            SecureMRModelType modelType,
            string modelName,
            LiteRtModelConfiguration liteRtConfiguration,
            out ulong operatorHandle)
        {
            operatorHandle = 0;

            if (modelType != SecureMRModelType.LiteRtModel)
            {
                Debug.LogError(
                    $"UPxr_CreateSecureMrOperatorModel only supports LiteRT models. " +
                    $"Other model types (e.g., legacy QNN context binaries) are not supported. " +
                    $"If this value comes from older serialized data, update it to {SecureMRModelType.LiteRtModel}. " +
                    $"Provided model type value: {(int)modelType} ({modelType}).");
                return PxrResult.ERROR_VALIDATION_FAILURE;
            }

#if UNITY_ANDROID && !UNITY_EDITOR
                IntPtr liteRtConfigPtr = IntPtr.Zero;
                IntPtr modelBufferPtr = IntPtr.Zero;

                try
                {
                    SecureMROperatorModel model = new SecureMROperatorModel
                    {
                        type = XrStructureType.XR_TYPE_SECURE_MR_OPERATOR_MODEL_PICO,
                        next = IntPtr.Zero,
                        modelInputCount = 0,
                        modelInputs = IntPtr.Zero,
                        modelOutputCount = 0,
                        modelOutputs = IntPtr.Zero,
                        bufferSize = (uint)modelData.Length,
                        modelType = modelType,
                        modelName = modelName,
                    };

                    var liteRtModel = new SecureMROperatorLiteRtModel
                    {
                        type = XrStructureType.XR_TYPE_SECURE_MR_OPERATOR_LITE_RT_MODEL_PICO,
                        next = IntPtr.Zero,
                        modelTarget = liteRtConfiguration?.modelTarget ?? SecureMRModelTarget.Npu,
                        cpuTargetNumThreads = liteRtConfiguration?.cpuTargetNumThreads ?? 0
                    };

                    liteRtConfigPtr = Marshal.AllocHGlobal(Marshal.SizeOf(typeof(SecureMROperatorLiteRtModel)));
                    Marshal.StructureToPtr(liteRtModel, liteRtConfigPtr, false);
                    model.next = liteRtConfigPtr;

                    //modelData
                    int size = Marshal.SizeOf(typeof(byte)) * modelData.Length;
                    modelBufferPtr = Marshal.AllocHGlobal(size);
                    model.buffer = modelBufferPtr;
                    Marshal.Copy(modelData, 0, model.buffer, size);

                    var result = Pxr_CreateSecureMROperatorModel(pipelineHandle, ref model, out operatorHandle);
                    return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);
                }
                finally
                {
                    if (modelBufferPtr != IntPtr.Zero)
                    {
                        Marshal.FreeHGlobal(modelBufferPtr);
                    }

                    if (liteRtConfigPtr != IntPtr.Zero)
                    {
                        Marshal.FreeHGlobal(liteRtConfigPtr);
                    }
                }
#else
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_CreateSecureMROperatorJavascript(ulong pipelineHandle, string configText,
            out ulong operatorHandle)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                SecureMROperatorJavascript config = new SecureMROperatorJavascript
                {
                    type = XrStructureType.XR_TYPE_SECURE_MR_OPERATOR_JAVASCRIPT_PICO,
                    next = IntPtr.Zero,
                    configText = configText,
                    configTextLength = configText.Length,
                };
                var result = Pxr_CreateSecureMROperatorJavascript(pipelineHandle, ref config, out operatorHandle);
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(result);
#else
            operatorHandle = 0;
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_CreateBufferFromGlobalTensorAsync(ulong tensor, out ulong future)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
            var ret = Pxr_CreateBufferFromGlobalTensorAsync(tensor, out future);
            return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(ret);
#else
            future = 0UL;
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_CreateBufferFromGlobalTensorComplete(ulong tensor, ulong future, out byte[] data)
        {
            data = Array.Empty<byte>();
#if UNITY_ANDROID && !UNITY_EDITOR
            XrCreateBufferFromGlobalTensorCompletion completion = new XrCreateBufferFromGlobalTensorCompletion()
            {
                type = XrStructureType.XR_TYPE_CREATE_BUFFER_FROM_GLOBAL_TENSOR_COMPLETION_PICO,
                next = IntPtr.Zero,
            };
            XrReadbackTensorBuffer tensorBuffer = new XrReadbackTensorBuffer()
            {
                type = XrStructureType.XR_TYPE_READBACK_TENSOR_BUFFER_PICO,
            };
            IntPtr tbPtr = Marshal.AllocHGlobal(Marshal.SizeOf(typeof(XrReadbackTensorBuffer)));
            Marshal.StructureToPtr(tensorBuffer, tbPtr, false);
            completion.tensorBuffer = tbPtr;
            
            var ret = Pxr_CreateBufferFromGlobalTensorComplete(tensor, future, ref completion);
            
            if (ret != 0)
            {
                Marshal.FreeHGlobal(tbPtr);
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(ret);
            }
            
            tensorBuffer = Marshal.PtrToStructure<XrReadbackTensorBuffer>(tbPtr);
            tensorBuffer.bufferCapacityInput = tensorBuffer.bufferCountOutput;
            tensorBuffer.buffer = Marshal.AllocHGlobal((int)tensorBuffer.bufferCapacityInput);
            Marshal.StructureToPtr(tensorBuffer, tbPtr, true);
            ret = Pxr_CreateBufferFromGlobalTensorComplete(tensor, future, ref completion);
            
            if (ret != 0)
            {
                Marshal.FreeHGlobal(tensorBuffer.buffer);
                Marshal.FreeHGlobal(tbPtr);
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(ret);
            }
            
            tensorBuffer = Marshal.PtrToStructure<XrReadbackTensorBuffer>(tbPtr);
            data = new byte[tensorBuffer.bufferCountOutput];
            if (tensorBuffer.bufferCountOutput > 0)
            {
                Marshal.Copy(tensorBuffer.buffer, data, 0, (int)tensorBuffer.bufferCountOutput);
            }

            Marshal.FreeHGlobal(tensorBuffer.buffer);
            Marshal.FreeHGlobal(tbPtr);
            return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(ret);
#else
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_CreateTextureFromGlobalTensorAsync(ulong tensor, out ulong future)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
            var ret = Pxr_CreateTextureFromGlobalTensorAsync(tensor, out future);
            return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(ret);
#else
            future = 0UL;
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_CreateTextureFromGlobalTensorComplete(ulong tensor, ulong future,
            out ulong textureHandle)
        {
            textureHandle = 0;
#if UNITY_ANDROID && !UNITY_EDITOR
            XrCreateTextureFromGlobalTensorCompletion completion = new XrCreateTextureFromGlobalTensorCompletion()
            {
                type = XrStructureType.XR_TYPE_CREATE_TEXTURE_FROM_GLOBAL_TENSOR_COMPLETION_PICO
            };
			var ret = Pxr_CreateTextureFromGlobalTensorComplete(tensor, future, ref completion);
            textureHandle = completion.texture;
			return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(ret);
#else
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_GetReadbackTextureImageVulkan(ulong textureHandle, out IntPtr vkImage)
        {
            vkImage = IntPtr.Zero;
#if UNITY_ANDROID && !UNITY_EDITOR
			var size = Marshal.SizeOf(typeof(XrReadbackTextureImageVulkan));
			IntPtr ptr = Marshal.AllocHGlobal(size);
			try
			{
				var hdr = new XrReadbackTextureImageVulkan
				{
					type = XrStructureType.XR_TYPE_READBACK_TEXTURE_IMAGE_VULKAN_PICO,
					next = IntPtr.Zero,
					image = IntPtr.Zero
				};
				Marshal.StructureToPtr(hdr, ptr, false);
				var ret = Pxr_GetReadbackTextureImage(textureHandle, ptr);
				if (ret == 0)
				{
					hdr = Marshal.PtrToStructure<XrReadbackTextureImageVulkan>(ptr);
					vkImage = hdr.image;
				}
				return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(ret);
			}
			finally
			{
				Marshal.FreeHGlobal(ptr);
			}
#else
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_GetReadbackTextureImageOpenGL(ulong textureHandle, out uint glTexId)
        {
            glTexId = 0U;
#if UNITY_ANDROID && !UNITY_EDITOR
			var size = Marshal.SizeOf(typeof(XrReadbackTextureImageOpenGL));
			IntPtr ptr = Marshal.AllocHGlobal(size);
			try
			{
				var hdr = new XrReadbackTextureImageOpenGL
				{
					type = XrStructureType.XR_TYPE_READBACK_TEXTURE_IMAGE_OPENGL_PICO,
					next = IntPtr.Zero,
					texId = 0U
				};
				Marshal.StructureToPtr(hdr, ptr, false);
				var ret = Pxr_GetReadbackTextureImage(textureHandle, ptr);
				if (ret == 0)
				{
					hdr = Marshal.PtrToStructure<XrReadbackTextureImageOpenGL>(ptr);
					glTexId = hdr.texId;
				}
                return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(ret);
			}
			finally
			{
				Marshal.FreeHGlobal(ptr);
			}
#else
            return PxrResult.SUCCESS;
#endif
        }

        public static PxrResult UPxr_ReleaseReadbackTexture(ulong textureHandle)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
			var ret = Pxr_ReleaseReadbackTexture(textureHandle);
			return PXR_Plugin.MixedReality.UPxr_ConvertIntToPxrResult(ret);
#else
            return PxrResult.SUCCESS;
#endif
        }

    }
}
#endif
