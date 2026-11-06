#if !ENABLE_PICO_OPENXR_SDK
using System.Collections.Generic;

namespace ByteDance.PICO.SecureMR
{
    public sealed class SpatialMLPipelineZooBundle
    {
        public Dictionary<string, SpatialMLPipelineZooPipeline> Pipelines { get; } =
            new Dictionary<string, SpatialMLPipelineZooPipeline>();

        public Dictionary<string, Tensor> GlobalTensors { get; } = new Dictionary<string, Tensor>();

        public string DetectionTensorName { get; internal set; }

        public SpatialMLPipelineZooPipeline this[string pipelineId] => Pipelines[pipelineId];

        public void DestroyGlobals()
        {
            foreach (var tensor in GlobalTensors.Values)
            {
                tensor?.Destroy();
            }

            GlobalTensors.Clear();
        }
    }

    public sealed class SpatialMLPipelineZooPipeline
    {
        public string Id { get; internal set; }

        public Pipeline Pipeline { get; internal set; }

        public Dictionary<string, Tensor> Tensors { get; } = new Dictionary<string, Tensor>();

        public Dictionary<string, Tensor> SubmitBindings { get; } = new Dictionary<string, Tensor>();

        public List<string> Inputs { get; internal set; } = new List<string>();

        public List<string> Outputs { get; internal set; } = new List<string>();

        public TensorMapping CreateTensorMapping()
        {
            var mapping = new TensorMapping();
            foreach (var binding in SubmitBindings)
            {
                if (Tensors.TryGetValue(binding.Key, out var local) && local.PlaceHolder)
                {
                    mapping.Set(local, binding.Value);
                }
            }

            return mapping;
        }

        public ulong Execute()
        {
            return Pipeline.Execute(CreateTensorMapping());
        }

        public ulong ExecuteAfter(ulong runId)
        {
            return Pipeline.ExecuteAfter(runId, CreateTensorMapping());
        }
    }
}
#endif
