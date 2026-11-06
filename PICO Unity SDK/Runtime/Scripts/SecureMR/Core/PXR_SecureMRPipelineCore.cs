#if !ENABLE_PICO_OPENXR_SDK
using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using ByteDance.PICO.XR;

namespace ByteDance.PICO.SecureMR
{
    public class Pipeline
    {
        private readonly ISecureMRBackend backend;
        public ulong pipelineHandle;

        internal Pipeline(ISecureMRBackend backend, ulong frameworkHandle)
        {
            this.backend = backend ?? throw new ArgumentNullException(nameof(backend));
            pipelineHandle = backend.CreatePipeline(frameworkHandle);
        }

        public T CreateOperator<T>() where T : Operator
        {
            PXR_SecureMRPlugin.OperatorClassToEnum.TryGetValue(typeof(T), out var enumValue);
            var op = (T)Activator.CreateInstance(typeof(T), pipelineHandle, enumValue);
            op.Backend = backend;
            op.OperatorHandle = backend.CreateOperator(pipelineHandle, enumValue, null);
            return op;
        }


        public T CreateOperator<T>(OperatorConfiguration configuration) where T : Operator
        {
            PXR_SecureMRPlugin.OperatorClassToEnum.TryGetValue(typeof(T), out var enumValue);
            var op = (T)Activator.CreateInstance(typeof(T), pipelineHandle, enumValue, configuration);
            op.Backend = backend;
            op.OperatorHandle = backend.CreateOperator(pipelineHandle, enumValue, configuration);
            return op;
        }


        public Tensor CreateTensor<T, TType>(int channels, TensorShape shape, T[] data = null)
            where T : struct
            where TType : TensorBase, new()
        {
            PXR_SecureMRPlugin.TensorDataTypeToEnum.TryGetValue(typeof(T), out var dataType);
            PXR_SecureMRPlugin.TensorClassToEnum.TryGetValue(typeof(TType), out var enumValue);
            var tensorHandle = backend.CreatePipelineTensorByShape(pipelineHandle, false, dataType, shape.Dimensions, (sbyte)channels, enumValue);
            var t = new Tensor(tensorHandle, pipelineHandle, false, false)
            {
                Dimensions = shape.Dimensions,
                Channels = (sbyte)channels,
                Usage = enumValue,
                DataType = dataType
            };
            t.Backend = backend;
            if (data != null)
            {
                t.Reset(data);
            }
            return t;
        }
        
        public Tensor CreateTensor<TType>(byte[] data)
            where TType : Gltf, new()
        {
            var tensorHandle = backend.CreatePipelineTensorByGltf(pipelineHandle, false);
            var t = new Tensor(tensorHandle, pipelineHandle, false, false);
            t.Backend = backend;
            if (data != null)
            {
                t.Reset(data);
            }
            return t;
        }

        public Tensor CreateTensorReference<T, TType>(int channels, TensorShape shape)
            where T : struct
            where TType : TensorBase, new()
        {
            PXR_SecureMRPlugin.TensorDataTypeToEnum.TryGetValue(typeof(T), out var dataType);
            PXR_SecureMRPlugin.TensorClassToEnum.TryGetValue(typeof(TType), out var enumValue);
            
            if (enumValue == SecureMRTensorUsage.DynamicTexture)
            {
                if (dataType == SecureMRTensorDataType.Byte)
                {
                    dataType = SecureMRTensorDataType.DynamicTextureByte;
                }

                if (dataType == SecureMRTensorDataType.Float)
                {
                    dataType = SecureMRTensorDataType.DynamicTextureFloat;
                }
            }
            
            var tensorHandle = backend.CreatePipelineTensorByShape(pipelineHandle, true, dataType, shape.Dimensions, (sbyte)channels, enumValue);
            var t = new Tensor(tensorHandle, pipelineHandle, true, false)
            {
                Dimensions = shape.Dimensions,
                Channels = (sbyte)channels,
                Usage = PXR_SecureMRPlugin.TensorClassToEnum[typeof(TType)],
                DataType = dataType
            };
            t.Backend = backend;
            return t;
        }
        
        public Tensor CreateTensorReference<TType>()
            where TType : Gltf, new()
        {
            var tensorHandle = backend.CreatePipelineTensorByGltf(pipelineHandle, true);
            var t = new Tensor(tensorHandle, pipelineHandle, true, false);
            t.Backend = backend;
            return t;
        }

        public TensorMapping CreateTensorMapping()
        {
            return new TensorMapping();
        }
        
        public void Destroy()
        {
            backend.DestroyPipeline(pipelineHandle);
        }

        public ulong Execute(TensorMapping tensorMappings = null)
        {
            return backend.Submit(pipelineHandle, tensorMappings?.TensorMappings, 0, 0);
        }

        public ulong ExecuteAfter(ulong runId, TensorMapping tensorMappings = null)
        {
            return backend.Submit(pipelineHandle, tensorMappings?.TensorMappings, runId, 0);
        }

        public ulong ExecuteConditional(ulong conditionTensorHandle, TensorMapping tensorMappings = null)
        {
            return backend.Submit(pipelineHandle, tensorMappings?.TensorMappings, 0, conditionTensorHandle);
        }
    }
}

#endif
