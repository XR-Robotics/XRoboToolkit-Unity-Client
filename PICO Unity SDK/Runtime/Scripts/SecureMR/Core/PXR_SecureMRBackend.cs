#if !ENABLE_PICO_OPENXR_SDK
using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using ByteDance.PICO.XR;
using Unity.Collections;
using Unity.Collections.LowLevel.Unsafe;
using UnityEngine;

namespace ByteDance.PICO.SecureMR
{
    internal enum SecureMRBackendKind
    {
        XR,
        Spatial
    }

    internal interface ISecureMRBackend
    {
        SecureMRBackendKind Kind { get; }

        ulong CreateProvider(int imageWidth, int imageHeight);
        void DestroyProvider(ulong providerHandle);

        ulong CreatePipeline(ulong providerHandle);
        void DestroyPipeline(ulong pipelineHandle);

        ulong CreateGlobalTensorByShape(ulong providerHandle, SecureMRTensorDataType dataType, int[] dimensions, sbyte channels, SecureMRTensorUsage usage);
        ulong CreateGlobalTensorByGltf(ulong providerHandle, byte[] gltfData);
        void ResetGlobalTensor<T>(ulong globalTensorId, T[] data) where T : struct;
        void DestroyGlobalTensor(ulong globalTensorId);

        ulong CreatePipelineTensorByShape(ulong pipelineHandle, bool placeHolder, SecureMRTensorDataType dataType, int[] dimensions, sbyte channels, SecureMRTensorUsage usage);
        ulong CreatePipelineTensorByGltf(ulong pipelineHandle, bool placeHolder);
        void ResetPipelineTensor<T>(ulong pipelineHandle, ulong pipelineTensorId, T[] data) where T : struct;
        void ResetPipelineTensor(ulong pipelineHandle, ulong pipelineTensorId, byte[] data);

        ulong Submit(ulong pipelineHandle, Dictionary<ulong, ulong> tensorMapping, ulong waitForRunId, ulong conditionGlobalTensorId);

        ulong CreateOperator(ulong pipelineHandle, SecureMROperatorType operatorType, OperatorConfiguration configuration);
        PxrResult SetOperand(Operator op, string name, Tensor tensor);
        PxrResult SetResult(Operator op, string name, Tensor tensor);

        Task<T[]> ReadbackBufferAsync<T>(Tensor globalTensor, int pollIntervalMs) where T : struct;
        Task<int> ReadbackIntoAsync<T>(Tensor globalTensor, NativeArray<T> destination, int pollIntervalMs) where T : unmanaged;
        Task<ReadbackTexture> ReadbackTextureAsync(Tensor globalTensor, int pollIntervalMs);
    }

    internal static class SecureMRBackendRouter
    {
        private static readonly ISecureMRBackend XrBackend = new SecureMRBackendXR();
        private static readonly ISecureMRBackend SpatialBackend = new SecureMRBackendSpatial();

        internal static ISecureMRBackend Current
        {
            get
            {
                var projectConfig = PXR_ProjectSetting.GetProjectConfig();
                if (projectConfig != null && projectConfig.isSpatialAdapter)
                {
                    return SpatialBackend;
                }

                return XrBackend;
            }
        }
    }

    internal sealed class SecureMRBackendXR : ISecureMRBackend
    {
        public SecureMRBackendKind Kind => SecureMRBackendKind.XR;

        public ulong CreateProvider(int imageWidth, int imageHeight)
        {
            var result = PXR_SecureMRPlugin.UPxr_CreateSecureMRProvider(imageWidth, imageHeight, out var providerHandle);
            if (result != PxrResult.SUCCESS)
            {
                throw new InvalidOperationException("Failed to create SecureMRProvider" + result);
            }
            return providerHandle;
        }

        public void DestroyProvider(ulong providerHandle)
        {
            PXR_SecureMRPlugin.UPxr_DestroySecureMRProvider(providerHandle);
        }

        public ulong CreatePipeline(ulong providerHandle)
        {
            var result = PXR_SecureMRPlugin.UPxr_CreateSecureMRPipeline(providerHandle, out var pipelineHandle);
            if (result != PxrResult.SUCCESS)
            {
                throw new InvalidOperationException("Failed to create SecureMR pipeline" + result);
            }
            return pipelineHandle;
        }

        public void DestroyPipeline(ulong pipelineHandle)
        {
            PXR_SecureMRPlugin.UPxr_DestroySecureMRPipeline(pipelineHandle);
        }

        public ulong CreateGlobalTensorByShape(ulong providerHandle, SecureMRTensorDataType dataType, int[] dimensions, sbyte channels, SecureMRTensorUsage usage)
        {
            var result = PXR_SecureMRPlugin.UPxr_CreateSecureMRTensorByShape(providerHandle, dataType, dimensions, channels, usage, out var tensorHandle);
            if (result != PxrResult.SUCCESS)
            {
                throw new InvalidOperationException("Failed to create global tensor" + result);
            }
            return tensorHandle;
        }

        public ulong CreateGlobalTensorByGltf(ulong providerHandle, byte[] gltfData)
        {
            var result = PXR_SecureMRPlugin.UPxr_CreateSecureMRTensorByGltf(providerHandle, gltfData, out var tensorHandle);
            if (result != PxrResult.SUCCESS)
            {
                throw new InvalidOperationException("Failed to create global gltf tensor" + result);
            }
            return tensorHandle;
        }

        public void ResetGlobalTensor<T>(ulong globalTensorId, T[] data) where T : struct
        {
            var result = PXR_SecureMRPlugin.UPxr_ResetSecureMRTensor(globalTensorId, data);
            if (result != PxrResult.SUCCESS)
            {
                throw new InvalidOperationException("Failed to reset global tensor" + result);
            }
        }

        public void DestroyGlobalTensor(ulong globalTensorId)
        {
            PXR_SecureMRPlugin.UPxr_DestroySecureMRTensor(globalTensorId);
        }

        public ulong CreatePipelineTensorByShape(ulong pipelineHandle, bool placeHolder, SecureMRTensorDataType dataType, int[] dimensions, sbyte channels, SecureMRTensorUsage usage)
        {
            var result = PXR_SecureMRPlugin.UPxr_CreateSecureMRPipelineTensorByShape(pipelineHandle, placeHolder, dataType, dimensions, channels, usage, out var tensorHandle);
            if (result != PxrResult.SUCCESS)
            {
                throw new InvalidOperationException("Failed to create local tensor:" + result);
            }
            return tensorHandle;
        }

        public ulong CreatePipelineTensorByGltf(ulong pipelineHandle, bool placeHolder)
        {
            var result = PXR_SecureMRPlugin.UPxr_CreateSecureMRPipelineTensorByGltf(pipelineHandle, placeHolder, null, out var tensorHandle);
            if (result != PxrResult.SUCCESS)
            {
                throw new InvalidOperationException("Failed to create local gltf tensor:" + result);
            }
            return tensorHandle;
        }

        public void ResetPipelineTensor<T>(ulong pipelineHandle, ulong pipelineTensorId, T[] data) where T : struct
        {
            var result = PXR_SecureMRPlugin.UPxr_ResetSecureMRPipelineTensor(pipelineHandle, pipelineTensorId, data);
            if (result != PxrResult.SUCCESS)
            {
                throw new InvalidOperationException("Failed to reset pipeline tensor" + result);
            }
        }

        public void ResetPipelineTensor(ulong pipelineHandle, ulong pipelineTensorId, byte[] data)
        {
            var result = PXR_SecureMRPlugin.UPxr_ResetSecureMRPipelineTensor(pipelineHandle, pipelineTensorId, data);
            if (result != PxrResult.SUCCESS)
            {
                throw new InvalidOperationException("Failed to reset pipeline tensor" + result);
            }
        }

        public ulong Submit(ulong pipelineHandle, Dictionary<ulong, ulong> tensorMapping, ulong waitForRunId, ulong conditionGlobalTensorId)
        {
            PxrResult result;
            ulong pipelineRunHandle;
            if (conditionGlobalTensorId != 0)
            {
                result = PXR_SecureMRPlugin.UPxr_ExecuteSecureMRPipelineConditional(pipelineHandle, conditionGlobalTensorId, tensorMapping, out pipelineRunHandle);
            }
            else if (waitForRunId != 0)
            {
                result = PXR_SecureMRPlugin.UPxr_ExecuteSecureMRPipelineAfter(pipelineHandle, waitForRunId, tensorMapping, out pipelineRunHandle);
            }
            else
            {
                result = PXR_SecureMRPlugin.UPxr_ExecuteSecureMRPipeline(pipelineHandle, tensorMapping, out pipelineRunHandle);
            }

            if (result != PxrResult.SUCCESS)
            {
                throw new InvalidOperationException("Failed to execute pipeline:" + result);
            }

            return pipelineRunHandle;
        }

        public ulong CreateOperator(ulong pipelineHandle, SecureMROperatorType operatorType, OperatorConfiguration configuration)
        {
            PxrResult result;
            ulong operatorHandle;

            if (operatorType == SecureMROperatorType.ScenegraphVisibility || operatorType == SecureMROperatorType.UpdateComponent)
            {
                throw new InvalidOperationException($"Operator {operatorType} is only supported in Spatial backend");
            }

            if (operatorType == SecureMROperatorType.ArithmeticCompose)
            {
                var cfg = (ArithmeticComposeOperatorConfiguration)configuration;
                result = PXR_SecureMRPlugin.UPxr_CreateSecureMROperatorArithmeticCompose(pipelineHandle, cfg.configText, out operatorHandle);
            }
            else if (operatorType == SecureMROperatorType.CustomizedCompare)
            {
                var cfg = (ComparisonOperatorConfiguration)configuration;
                result = PXR_SecureMRPlugin.UPxr_CreateSecureMROperatorComparison(pipelineHandle, cfg.comparison, out operatorHandle);
            }
            else if (operatorType == SecureMROperatorType.Nms)
            {
                var cfg = (NmsOperatorConfiguration)configuration;
                result = PXR_SecureMRPlugin.UPxr_CreateSecureMROperatorNonMaximumSuppression(pipelineHandle, cfg.threshold, out operatorHandle);
            }
            else if (operatorType == SecureMROperatorType.Normalize)
            {
                var cfg = (NormalizeOperatorConfiguration)configuration;
                result = PXR_SecureMRPlugin.UPxr_CreateSecureMROperatorNormalize(pipelineHandle, cfg.normalizeType, out operatorHandle);
            }
            else if (operatorType == SecureMROperatorType.ConvertColor)
            {
                var cfg = (ColorConvertOperatorConfiguration)configuration;
                result = PXR_SecureMRPlugin.UPxr_CreateSecureMROperatorColorConvert(pipelineHandle, cfg.convert, out operatorHandle);
            }
            else if (operatorType == SecureMROperatorType.SortMatrix)
            {
                var cfg = (SortMatrixOperatorConfiguration)configuration;
                result = PXR_SecureMRPlugin.UPxr_CreateSecureMROperatorSortMatrix(pipelineHandle, cfg.sortType, out operatorHandle);
            }
            else if (operatorType == SecureMROperatorType.UpdateGltf)
            {
                var cfg = (UpdateGltfOperatorConfiguration)configuration;
                result = PXR_SecureMRPlugin.UPxr_CreateSecureMROperatorUpdateGltf(pipelineHandle, cfg.attribute, out operatorHandle);
            }
            else if (operatorType == SecureMROperatorType.RenderText)
            {
                var cfg = (RenderTextOperatorConfiguration)configuration;
                result = PXR_SecureMRPlugin.UPxr_CreateSecureMROperatorRenderText(pipelineHandle, cfg.typeface, cfg.languageAndLocale, cfg.width, cfg.height, out operatorHandle);
            }
            else if (operatorType == SecureMROperatorType.RunModelInference)
            {
                var cfg = (ModelOperatorConfiguration)configuration;
                if (!ModelOperatorConfiguration.TryValidateModelType(cfg.modelType, out var modelTypeError))
                {
                    Debug.LogError($"{modelTypeError} Operator creation aborted.");
                    return default;
                }

                result = PXR_SecureMRPlugin.UPxr_CreateSecureMrOperatorModel(
                    pipelineHandle,
                    cfg.modelData,
                    cfg.modelType,
                    cfg.modelName,
                    cfg.liteRtConfiguration,
                    out operatorHandle);
            }
            else if (operatorType == SecureMROperatorType.Javascript)
            {
                var cfg = (JavascriptOperatorConfiguration)configuration;
                result = PXR_SecureMRPlugin.UPxr_CreateSecureMROperatorJavascript(pipelineHandle, cfg.configText, out operatorHandle);
            }
            else if (operatorType == SecureMROperatorType.UvTo3DInCameraSpace)
            {
                result = PXR_SecureMRPlugin.UPxr_CreateSecureMROperatorUVTo3D(pipelineHandle, out operatorHandle);
            }
            else
            {
                result = PXR_SecureMRPlugin.UPxr_CreateSecureMROperator(pipelineHandle, operatorType, out operatorHandle);
            }

            if (result != PxrResult.SUCCESS)
            {
                throw new InvalidOperationException("Failed to create operator:" + result);
            }

            return operatorHandle;
        }

        public PxrResult SetOperand(Operator op, string name, Tensor tensor)
        {
            return PXR_SecureMRPlugin.UPxr_SetSecureMROperatorOperandByName(op.PipelineHandle, op.OperatorHandle, tensor.TensorHandle, name);
        }

        public PxrResult SetResult(Operator op, string name, Tensor tensor)
        {
            return PXR_SecureMRPlugin.UPxr_SetSecureMROperatorResultByName(op.PipelineHandle, op.OperatorHandle, tensor.TensorHandle, name);
        }

        public Task<T[]> ReadbackBufferAsync<T>(Tensor globalTensor, int pollIntervalMs) where T : struct
        {
            return Readback.ReadbackBufferAsync<T>(globalTensor, pollIntervalMs);
        }

        public async Task<int> ReadbackIntoAsync<T>(Tensor globalTensor, NativeArray<T> destination, int pollIntervalMs) where T : unmanaged
        {
            var values = await Readback.ReadbackBufferAsync<T>(globalTensor, pollIntervalMs);
            if (values == null || values.Length == 0 || !destination.IsCreated || destination.Length == 0)
            {
                return 0;
            }

            var count = Math.Min(values.Length, destination.Length);
            NativeArray<T>.Copy(values, destination, count);
            return count * UnsafeUtility.SizeOf<T>();
        }

        public Task<ReadbackTexture> ReadbackTextureAsync(Tensor globalTensor, int pollIntervalMs)
        {
            return Readback.ReadbackTextureAsync(globalTensor, pollIntervalMs);
        }
    }

    internal sealed class SecureMRBackendSpatial : ISecureMRBackend
    {
        public SecureMRBackendKind Kind => SecureMRBackendKind.Spatial;

        private const int DefaultContainerWidth = 500;
        private const int DefaultContainerHeight = 500;
        private const int DefaultContainerDepth = 100;

        public ulong CreateProvider(int imageWidth, int imageHeight)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
            if (!PXR_SecureMRPlugin.SpatialSecureMR.EnsureConnected(2000))
            {
                throw new InvalidOperationException("SSMR backend service is not connected");
            }
            var sessionId = PXR_SecureMRPlugin.SpatialSecureMR.CreateSessionHandle(0, imageWidth, imageHeight, DefaultContainerWidth, DefaultContainerHeight, DefaultContainerDepth);
            return unchecked((ulong)sessionId);
#else
            return 0;
#endif
        }

        public ulong CreateProvider(
            int imageWidth,
            int imageHeight,
            SpatialContainerConfiguration containerConfiguration)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
            if (!PXR_SecureMRPlugin.SpatialSecureMR.EnsureConnected(2000))
            {
                throw new InvalidOperationException("SSMR backend service is not connected");
            }

            var sessionId = PXR_SecureMRPlugin.SpatialSecureMR.CreateSessionHandle(
                0,
                imageWidth,
                imageHeight,
                containerConfiguration.containerWidth,
                containerConfiguration.containerHeight,
                containerConfiguration.GetBackendDepth());
            return unchecked((ulong)sessionId);
#else
            return 0;
#endif
        }


        public void DestroyProvider(ulong providerHandle)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
            PXR_SecureMRPlugin.SpatialSecureMR.DestroySessionHandle(unchecked((long)providerHandle));
#endif
        }

        public ulong CreatePipeline(ulong providerHandle)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
            var pipelineId = PXR_SecureMRPlugin.SpatialSecureMR.CreatePipeline(unchecked((long)providerHandle));
            return unchecked((ulong)pipelineId);
#else
            return 0;
#endif
        }

        public void DestroyPipeline(ulong pipelineHandle)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
            PXR_SecureMRPlugin.SpatialSecureMR.DestroyPipeline(unchecked((long)pipelineHandle));
#endif
        }

        public ulong CreateGlobalTensorByShape(ulong providerHandle, SecureMRTensorDataType dataType, int[] dimensions, sbyte channels, SecureMRTensorUsage usage)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
            var sessionId = unchecked((long)providerHandle);
            var flag = SpatialTensorFlag.From(dataType, usage, channels);
            var tensorId = PXR_SecureMRPlugin.SpatialSecureMR.CreateTensor(sessionId, flag, dimensions);
            return unchecked((ulong)tensorId);
#else
            return 0;
#endif
        }

        public ulong CreateGlobalTensorByGltf(ulong providerHandle, byte[] gltfData)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
            if (gltfData == null)
            {
                throw new ArgumentNullException(nameof(gltfData));
            }

            var sessionId = unchecked((long)providerHandle);
            using (var shMem = AndroidSharedMemory.CreateFromBytes("securemr_gltf", gltfData))
            {
                var tensorId = PXR_SecureMRPlugin.SpatialSecureMR.CreateScene(sessionId, shMem);
                return unchecked((ulong)tensorId);
            }
#else
            return 0;
#endif
        }

        public void ResetGlobalTensor<T>(ulong globalTensorId, T[] data) where T : struct
        {
#if UNITY_ANDROID && !UNITY_EDITOR
            if (data == null)
            {
                throw new ArgumentNullException(nameof(data));
            }

            using (var shMem = AndroidSharedMemory.CreateFromArray("securemr_global_tensor", data))
            {
                PXR_SecureMRPlugin.SpatialSecureMR.ResetTensor(unchecked((long)globalTensorId), shMem);
            }
#endif
        }

        public void DestroyGlobalTensor(ulong globalTensorId)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
            PXR_SecureMRPlugin.SpatialSecureMR.DestroyTensor(unchecked((long)globalTensorId));
#endif
        }

        public ulong CreatePipelineTensorByShape(ulong pipelineHandle, bool placeHolder, SecureMRTensorDataType dataType, int[] dimensions, sbyte channels, SecureMRTensorUsage usage)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
            var flag = SpatialTensorFlag.From(dataType, usage, channels);
            var tensorId = PXR_SecureMRPlugin.SpatialSecureMR.PipelineCreateTensor(unchecked((long)pipelineHandle), flag, dimensions, !placeHolder);
            return unchecked((ulong)tensorId);
#else
            return 0;
#endif
        }

        public ulong CreatePipelineTensorByGltf(ulong pipelineHandle, bool placeHolder)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
            var flag = SpatialTensorFlag.SceneGraph();
            var tensorId = PXR_SecureMRPlugin.SpatialSecureMR.PipelineCreateTensor(unchecked((long)pipelineHandle), flag, Array.Empty<int>(), !placeHolder);
            return unchecked((ulong)tensorId);
#else
            return 0;
#endif
        }

        public void ResetPipelineTensor<T>(ulong pipelineHandle, ulong pipelineTensorId, T[] data) where T : struct
        {
#if UNITY_ANDROID && !UNITY_EDITOR
            if (data == null)
            {
                throw new ArgumentNullException(nameof(data));
            }

            using (var shMem = AndroidSharedMemory.CreateFromArray("securemr_pipeline_tensor", data))
            {
                PXR_SecureMRPlugin.SpatialSecureMR.PipelineResetTensor(unchecked((long)pipelineHandle), unchecked((long)pipelineTensorId), shMem);
            }
#endif
        }

        public void ResetPipelineTensor(ulong pipelineHandle, ulong pipelineTensorId, byte[] data)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
            if (data == null)
            {
                throw new ArgumentNullException(nameof(data));
            }

            using (var shMem = AndroidSharedMemory.CreateFromBytes("securemr_pipeline_tensor", data))
            {
                PXR_SecureMRPlugin.SpatialSecureMR.PipelineResetTensor(unchecked((long)pipelineHandle), unchecked((long)pipelineTensorId), shMem);
            }
#endif
        }

        public ulong Submit(ulong pipelineHandle, Dictionary<ulong, ulong> tensorMapping, ulong waitForRunId, ulong conditionGlobalTensorId)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
            using (var map = new PXR_SecureMRPlugin.SpatialSecureMR.PipelineTensorMap())
            {
                if (tensorMapping != null)
                {
                    foreach (var kv in tensorMapping)
                    {
                        map.Add(unchecked((long)kv.Key), unchecked((long)kv.Value));
                    }
                }

                var runId = PXR_SecureMRPlugin.SpatialSecureMR.SubmitPipeline(unchecked((long)pipelineHandle), unchecked((long)waitForRunId), unchecked((long)conditionGlobalTensorId), map.Handle);
                return unchecked((ulong)runId);
            }
#else
            return 0;
#endif
        }

        public ulong CreateOperator(ulong pipelineHandle, SecureMROperatorType operatorType, OperatorConfiguration configuration)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
            if (operatorType == SecureMROperatorType.SwitchGltfRenderStatus || operatorType == SecureMROperatorType.UpdateGltf || operatorType == SecureMROperatorType.RenderText || operatorType == SecureMROperatorType.LoadTexture)
            {
                throw new InvalidOperationException($"Operator {operatorType} is not supported in Spatial backend");
            }

            if (operatorType == SecureMROperatorType.RunModelInference)
            {
                var cfg = (ModelOperatorConfiguration)configuration;
                if (!ModelOperatorConfiguration.TryValidateModelType(cfg.modelType, out var modelTypeError))
                {
                    Debug.LogError($"{modelTypeError} Operator creation aborted.");
                    return default;
                }

                using (var encoding = new PXR_SecureMRPlugin.SpatialSecureMR.ModelEncoding())
                {
                    using (var shMem = AndroidSharedMemory.CreateFromBytes("securemr_model", cfg.modelData))
                    {
                        // LiteRT/TFLite path - use the 6-arg JNI overload added
                        // in SpatialSDK MR 3712. cpuTargetNumThreads is currently
                        // not surfaced by the Spatial JNI and is therefore
                        // ignored here; if the service ever exposes it, pass it
                        // through a future overload.
                        int backendType = cfg.liteRtConfiguration != null
                            ? PXR_SecureMRPlugin.SpatialSecureMR.ToSpatialBackendType(cfg.liteRtConfiguration.modelTarget)
                            : 2; // NPU default
                        long opId = PXR_SecureMRPlugin.SpatialSecureMR.PipelineAddModelInference(
                            unchecked((long)pipelineHandle), cfg.modelName, shMem, encoding.Handle,
                            PXR_SecureMRPlugin.SpatialSecureMR.SpatialRuntimeTypeTflite,
                            backendType);
                        return unchecked((ulong)opId);
                    }
                }
            }

            var configString = SpatialOperatorConfig.ToConfigString(operatorType, configuration);
            var op = PXR_SecureMRPlugin.SpatialSecureMR.PipelineAddOperator(unchecked((long)pipelineHandle), (int)operatorType, configString);
            return unchecked((ulong)op);
#else
            return 0;
#endif
        }

        public PxrResult SetOperand(Operator op, string name, Tensor tensor)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
            PXR_SecureMRPlugin.SpatialSecureMR.PipelineSetOperandByName(unchecked((long)op.OperatorHandle), unchecked((long)tensor.TensorHandle), name);
#endif
            return PxrResult.SUCCESS;
        }

        public PxrResult SetResult(Operator op, string name, Tensor tensor)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
            PXR_SecureMRPlugin.SpatialSecureMR.PipelineSetResultByName(unchecked((long)op.OperatorHandle), unchecked((long)tensor.TensorHandle), name);
#endif
            return PxrResult.SUCCESS;
        }

        public Task<T[]> ReadbackBufferAsync<T>(Tensor globalTensor, int pollIntervalMs) where T : struct
        {
#if UNITY_ANDROID && !UNITY_EDITOR
            var shMem = PXR_SecureMRPlugin.SpatialSecureMR.ReadbackSharedMemory(unchecked((long)globalTensor.TensorHandle));
            if (shMem == null)
            {
                return Task.FromResult(Array.Empty<T>());
            }

            using (shMem)
            {
                var byteCount = Math.Max(0, shMem.Call<int>("getSize"));
                if (byteCount == 0)
                {
                    shMem.Call("close");
                    return Task.FromResult(Array.Empty<T>());
                }

                byte[] bytes;
                using (var nativeBytes = new NativeArray<byte>(byteCount, Allocator.TempJob))
                {
                    var copied = AndroidSharedMemory.CopyToNativeArray(shMem, nativeBytes);
                    if (copied <= 0)
                    {
                        shMem.Call("close");
                        return Task.FromResult(Array.Empty<T>());
                    }

                    bytes = new byte[copied];
                    NativeArray<byte>.Copy(nativeBytes, bytes, copied);
                }

                shMem.Call("close");
                return Task.FromResult(SpatialBytesConverter.ConvertBytesTo<T>(bytes));
            }
#else
            return Task.FromResult(Array.Empty<T>());
#endif
        }

        public Task<int> ReadbackIntoAsync<T>(Tensor globalTensor, NativeArray<T> destination, int pollIntervalMs) where T : unmanaged
        {
#if UNITY_ANDROID && !UNITY_EDITOR
            if (!destination.IsCreated || destination.Length == 0)
            {
                return Task.FromResult(0);
            }

            var shMem = PXR_SecureMRPlugin.SpatialSecureMR.ReadbackSharedMemory(unchecked((long)globalTensor.TensorHandle));
            if (shMem == null)
            {
                return Task.FromResult(0);
            }

            using (shMem)
            {
                var copied = AndroidSharedMemory.CopyToNativeArray(shMem, destination);
                shMem.Call("close");
                return Task.FromResult(copied);
            }
#else
            return Task.FromResult(0);
#endif
        }

        public Task<ReadbackTexture> ReadbackTextureAsync(Tensor globalTensor, int pollIntervalMs)
        {
#if UNITY_ANDROID && !UNITY_EDITOR
            var textureId = PXR_SecureMRPlugin.SpatialSecureMR.ReadbackTextureId(unchecked((long)globalTensor.TensorHandle));
            if (textureId == 0)
            {
                return Task.FromResult<ReadbackTexture>(null);
            }

            var width = globalTensor.Dimensions != null && globalTensor.Dimensions.Length >= 2 ? globalTensor.Dimensions[0] : 0;
            var height = globalTensor.Dimensions != null && globalTensor.Dimensions.Length >= 2 ? globalTensor.Dimensions[1] : 0;

            TextureFormat format = TextureFormat.RGBA32;
            if (globalTensor.DataType == SecureMRTensorDataType.DynamicTextureFloat)
            {
                format = TextureFormat.RGBAFloat;
            }
            else if (globalTensor.Channels == 1)
            {
                format = TextureFormat.R8;
            }

            var tex = Texture2D.CreateExternalTexture(width, height, format, false, false, new IntPtr(textureId));
            return Task.FromResult(new ReadbackTexture(0, tex));
#else
            return Task.FromResult<ReadbackTexture>(null);
#endif
        }

        private static class SpatialTensorFlag
        {
            private const int DataTypeLength8 = 1 << 12;
            private const int DataTypeLength16 = 1 << 13;
            private const int DataTypeLength32 = 1 << 14;
            private const int DataTypeLength64 = 1 << 15;

            private const int DataTypeUInt = 1 << 16;
            private const int DataTypeInt = 1 << 17;
            private const int DataTypeFloat = 1 << 18;

            private const int UsagePoint = 1 << 9;
            private const int UsageScalarLike = 1 << 10;
            private const int UsageMultiDimensional = 1 << 11;
            private const int UsageSceneGraph = 1 << 20;
            private const int SpecialFlagDynamicTexture = 1 << 21;

            internal static int SceneGraph()
            {
                return UsageSceneGraph;
            }

            internal static int From(SecureMRTensorDataType dataType, SecureMRTensorUsage usage, sbyte channels)
            {
                var channelBits = (int)channels;
                if (channelBits < 0) channelBits = 0;
                if (channelBits > 511) channelBits = 511;
                var flag = DataTypeFlag(dataType) | UsageFlag(usage) | channelBits;
                if (dataType == SecureMRTensorDataType.DynamicTextureByte || dataType == SecureMRTensorDataType.DynamicTextureFloat)
                {
                    flag |= SpecialFlagDynamicTexture;
                }
                return flag;
            }

            private static int UsageFlag(SecureMRTensorUsage usage)
            {
                switch (usage)
                {
                    case SecureMRTensorUsage.Point:
                        return UsagePoint;
                    case SecureMRTensorUsage.Matrix:
                    case SecureMRTensorUsage.DynamicTexture:
                        return UsageMultiDimensional;
                    case SecureMRTensorUsage.Scalar:
                    case SecureMRTensorUsage.Slice:
                    case SecureMRTensorUsage.Color:
                    case SecureMRTensorUsage.TimeStamp:
                        return UsageScalarLike;
                    default:
                        return UsageMultiDimensional;
                }
            }

            private static int DataTypeFlag(SecureMRTensorDataType dataType)
            {
                switch (dataType)
                {
                    case SecureMRTensorDataType.Byte:
                    case SecureMRTensorDataType.DynamicTextureByte:
                        return DataTypeLength8 | DataTypeUInt;
                    case SecureMRTensorDataType.Sbyte:
                        return DataTypeLength8 | DataTypeInt;
                    case SecureMRTensorDataType.Ushort:
                        return DataTypeLength16 | DataTypeUInt;
                    case SecureMRTensorDataType.Short:
                        return DataTypeLength16 | DataTypeInt;
                    case SecureMRTensorDataType.Int:
                        return DataTypeLength32 | DataTypeInt;
                    case SecureMRTensorDataType.Float:
                    case SecureMRTensorDataType.DynamicTextureFloat:
                        return DataTypeLength32 | DataTypeFloat;
                    case SecureMRTensorDataType.Double:
                        return DataTypeLength64 | DataTypeFloat;
                    default:
                        return DataTypeLength32 | DataTypeFloat;
                }
            }
        }

        private static class SpatialOperatorConfig
        {
            internal static string ToConfigString(SecureMROperatorType operatorType, OperatorConfiguration configuration)
            {
                if (configuration == null)
                {
                    return null;
                }

                if (operatorType == SecureMROperatorType.ArithmeticCompose)
                {
                    return ((ArithmeticComposeOperatorConfiguration)configuration).configText;
                }

                if (operatorType == SecureMROperatorType.CustomizedCompare)
                {
                    var cmp = ((ComparisonOperatorConfiguration)configuration).comparison;
                    switch (cmp)
                    {
                        case SecureMRComparison.LargerThan:
                            return ">";
                        case SecureMRComparison.SmallerThan:
                            return "<";
                        case SecureMRComparison.SmallerOrEqual:
                            return "<=";
                        case SecureMRComparison.LargerOrEqual:
                            return ">=";
                        case SecureMRComparison.EqualTo:
                            return "==";
                        case SecureMRComparison.NotEqual:
                            return "!=";
                        default:
                            return null;
                    }
                }

                if (operatorType == SecureMROperatorType.Nms)
                {
                    return ((NmsOperatorConfiguration)configuration).threshold.ToString();
                }

                if (operatorType == SecureMROperatorType.Normalize)
                {
                    var t = ((NormalizeOperatorConfiguration)configuration).normalizeType;
                    switch (t)
                    {
                        case SecureMRNormalizeType.L1:
                            return "L1";
                        case SecureMRNormalizeType.L2:
                            return "L2";
                        case SecureMRNormalizeType.Inf:
                            return "INF";
                        case SecureMRNormalizeType.MinMax:
                            return "MINMAX";
                        default:
                            return null;
                    }
                }

                if (operatorType == SecureMROperatorType.ConvertColor)
                {
                    return ((ColorConvertOperatorConfiguration)configuration).convert.ToString();
                }

                if (operatorType == SecureMROperatorType.SortMatrix)
                {
                    var s = ((SortMatrixOperatorConfiguration)configuration).sortType;
                    return s == SecureMRMatrixSortType.Row ? "ROW" : "COLUMN";
                }

                if (operatorType == SecureMROperatorType.Javascript)
                {
                    return ((JavascriptOperatorConfiguration)configuration).configText;
                }

                if (operatorType == SecureMROperatorType.UpdateComponent)
                {
                    var cfg = (UpdateComponentOperatorConfiguration)configuration;
                    return $"{cfg.entityPath}:{cfg.targetPropertyPath}";
                }

                if (operatorType == SecureMROperatorType.Microphone)
                {
                    var cfg = (MicrophoneOperatorConfiguration)configuration;
                    return $"{cfg.sampleRate};{cfg.pcmType}";
                }

                if (operatorType == SecureMROperatorType.Speaker)
                {
                    var cfg = (SpeakerOperatorConfiguration)configuration;
                    return cfg.sampleRate.ToString();
                }

                return null;
            }
        }

        private static class SpatialBytesConverter
        {
            internal static T[] ConvertBytesTo<T>(byte[] bytes) where T : struct
            {
                if (bytes == null || bytes.Length == 0) return Array.Empty<T>();
                var size = System.Runtime.InteropServices.Marshal.SizeOf(typeof(T));
                var count = bytes.Length / size;
                if (typeof(T) == typeof(byte)) return (T[])(object)bytes;
                var dest = new T[count];
                Buffer.BlockCopy(bytes, 0, dest, 0, count * size);
                return dest;
            }
        }

#if UNITY_ANDROID && !UNITY_EDITOR
        private static class AndroidSharedMemory
        {
            internal static AndroidJavaObject CreateFromBytes(string name, byte[] bytes)
            {
                if (bytes == null) throw new ArgumentNullException(nameof(bytes));
                using (var sharedMemoryClass = new AndroidJavaClass("android.os.SharedMemory"))
                {
                    var shMem = sharedMemoryClass.CallStatic<AndroidJavaObject>("create", name, bytes.Length);
                    var buf = shMem.Call<AndroidJavaObject>("mapReadWrite");
                    using (var byteOrderClass = new AndroidJavaClass("java.nio.ByteOrder"))
                    {
                        buf.Call<AndroidJavaObject>("order", byteOrderClass.CallStatic<AndroidJavaObject>("nativeOrder"));
                    }
                    var signedBytes = new sbyte[bytes.Length];
                    Buffer.BlockCopy(bytes, 0, signedBytes, 0, bytes.Length);
                    buf.Call<AndroidJavaObject>("put", signedBytes);
                    sharedMemoryClass.CallStatic("unmap", buf);
                    buf.Dispose();
                    return shMem;
                }
            }

            internal static AndroidJavaObject CreateFromArray<T>(string name, T[] arr) where T : struct
            {
                if (arr == null) throw new ArgumentNullException(nameof(arr));
                var size = System.Runtime.InteropServices.Marshal.SizeOf(typeof(T)) * arr.Length;
                var bytes = new byte[size];
                if (typeof(T) == typeof(byte))
                {
                    Array.Copy(arr as byte[], bytes, size);
                }
                else
                {
                    Buffer.BlockCopy(arr, 0, bytes, 0, size);
                }
                return CreateFromBytes(name, bytes);
            }

            internal static byte[] ReadAllBytes(AndroidJavaObject sharedMemory)
            {
                if (sharedMemory == null) return Array.Empty<byte>();
                using (var sharedMemoryClass = new AndroidJavaClass("android.os.SharedMemory"))
                {
                    var size = sharedMemory.Call<int>("getSize");
                    var buf = sharedMemory.Call<AndroidJavaObject>("mapReadOnly");
                    var signedBytes = new sbyte[size];
                    buf.Call<AndroidJavaObject>("get", signedBytes);
                    sharedMemoryClass.CallStatic("unmap", buf);
                    buf.Dispose();
                    var bytes = new byte[size];
                    Buffer.BlockCopy(signedBytes, 0, bytes, 0, size);
                    return bytes;
                }
            }

            internal static unsafe int CopyToNativeArray<T>(AndroidJavaObject sharedMemory, NativeArray<T> destination)
                where T : unmanaged
            {
                if (sharedMemory == null || !destination.IsCreated || destination.Length == 0)
                {
                    return 0;
                }

                AndroidJavaObject buffer = null;
                using (var sharedMemoryClass = new AndroidJavaClass("android.os.SharedMemory"))
                {
                    try
                    {
                        buffer = sharedMemory.Call<AndroidJavaObject>("mapReadOnly");
                        var rawBuffer = buffer.GetRawObject();
                        var src = AndroidJNI.GetDirectBufferAddress(rawBuffer);
                        var capacity = AndroidJNI.GetDirectBufferCapacity(rawBuffer);
                        if (src == null || capacity <= 0)
                        {
                            return 0;
                        }

                        var destinationBytes = destination.Length * UnsafeUtility.SizeOf<T>();
                        var bytesToCopy = (int)Math.Min(capacity, destinationBytes);
                        UnsafeUtility.MemCpy(
                            NativeArrayUnsafeUtility.GetUnsafeBufferPointerWithoutChecks(destination),
                            src,
                            bytesToCopy);
                        return bytesToCopy;
                    }
                    finally
                    {
                        if (buffer != null)
                        {
                            sharedMemoryClass.CallStatic("unmap", buffer);
                            buffer.Dispose();
                        }
                    }
                }
            }
        }
#endif
    }
}
#endif
