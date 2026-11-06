#if !ENABLE_PICO_OPENXR_SDK
using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Threading;
using System.Threading.Tasks;
using ByteDance.PICO.XR;
using Unity.Collections;

namespace ByteDance.PICO.SecureMR
{
    public class Tensor
    {
        internal ISecureMRBackend Backend { get; set; }
        public ulong TensorHandle { get; private set; }
        public ulong PipelineHandle { get; private set; }

        public bool PlaceHolder { get; private set; }
        public bool IsGlobalTensor { get; private set; }
        
        public int[] Dimensions { get; internal set; }
        public sbyte Channels { get; internal set; }
        public SecureMRTensorUsage Usage { get; internal set; }
        public SecureMRTensorDataType DataType { get; internal set; }

        public Tensor(ulong tensorHandle, ulong pipelineHandle, bool placeHolder, bool isGlobalTensor)
        {
            this.TensorHandle = tensorHandle;
            this.PipelineHandle = pipelineHandle;
            this.PlaceHolder = placeHolder;
            this.IsGlobalTensor = isGlobalTensor;
        }

        public void Reset<T>(T[] tensorData) where T : struct
        {
            var backend = Backend ?? SecureMRBackendRouter.Current;
            if (IsGlobalTensor)
            {
                backend.ResetGlobalTensor(TensorHandle, tensorData);
            }
            else
            {
                if (typeof(T) == typeof(byte))
                {
                    backend.ResetPipelineTensor(PipelineHandle, TensorHandle, tensorData as byte[]);
                }
                else
                {
                    backend.ResetPipelineTensor(PipelineHandle, TensorHandle, tensorData);
                }
            }
        }

        public void Destroy()
        {
            if (IsGlobalTensor)
            {
                var backend = Backend ?? SecureMRBackendRouter.Current;
                backend.DestroyGlobalTensor(TensorHandle);
            }
        }
        
        public async Task<T[]> ReadbackBufferAsync<T>(int pollIntervalMs = 5) where T : struct
        {
            if (!IsGlobalTensor) throw new InvalidOperationException("Only global tensors support readback");
            var backend = Backend ?? SecureMRBackendRouter.Current;
            return await backend.ReadbackBufferAsync<T>(this, pollIntervalMs);
        }

        public async Task<int> ReadbackIntoAsync<T>(NativeArray<T> destination, int pollIntervalMs = 5) where T : unmanaged
        {
            if (!IsGlobalTensor) throw new InvalidOperationException("Only global tensors support readback");
            var backend = Backend ?? SecureMRBackendRouter.Current;
            return await backend.ReadbackIntoAsync(this, destination, pollIntervalMs);
        }

        public async Task<ReadbackTexture> ReadbackTextureAsync(int pollIntervalMs = 5)
        {
            if (!IsGlobalTensor) throw new InvalidOperationException("Only global tensors support readback");
            var backend = Backend ?? SecureMRBackendRouter.Current;
            return await backend.ReadbackTextureAsync(this, pollIntervalMs);
        }
        
    }

    public abstract class TensorBase{}
    public class Color : TensorBase{}

    public class Gltf { }
    public class Matrix : TensorBase{}
    public class Point : TensorBase{}
    public class Scalar : TensorBase{}
    public class Slice : TensorBase{}
    public class TimeStamp : TensorBase { }
    public class DynamicTexture : TensorBase{}
    
    public class TensorShape
    {
        public int[] Dimensions { get; }

        public TensorShape(params int[] dimensions)
        {
            if (dimensions == null || dimensions.Length == 0)
            {
                throw new ArgumentException("Dimensions array cannot be null or empty.");
            }

            Dimensions = dimensions;
        }
    }

    public class TensorMapping
    {
        public Dictionary<ulong, ulong> TensorMappings { get; private set; }

        public TensorMapping()
        {
            TensorMappings = new Dictionary<ulong, ulong>();
        }

        public void Set(Tensor localTensorReference, Tensor globalTensor)
        {
            TensorMappings.TryAdd(localTensorReference.TensorHandle, globalTensor.TensorHandle);
        }
    }
}
#endif

