#if !ENABLE_PICO_OPENXR_SDK
using UnityEngine;

namespace ByteDance.PICO.SecureMR
{
    public class PXR_SecureMRModelOperatorConfiguration : PXR_SecureMROperatorConfig
    {
        [Header("Model Settings")]
        [Tooltip("The ML model asset to use")]
        public TextAsset modelAsset;

        [Tooltip("The type of model to use. RunModelInferenceOperator only supports LiteRT/TFLite models.")]
        public SecureMRModelType modelType = SecureMRModelType.LiteRtModel;

        [Tooltip("Name of the model")]
        public string modelName;

        [Header("LiteRT Settings")]
        [Tooltip("LiteRT execution target.")]
        public SecureMRModelTarget liteRtModelTarget = SecureMRModelTarget.Npu;

        [Tooltip("Number of CPU threads for LiteRT CPU execution. Use 0 to let the runtime decide.")]
        public int liteRtCpuTargetNumThreads = 0;

        /// <summary>
        /// Creates a ModelOperatorConfiguration from this ScriptableObject
        /// </summary>
        /// <returns>A ModelOperatorConfiguration instance ready to use with CreateOperator</returns>
        public ModelOperatorConfiguration CreateModelOperatorConfiguration()
        {
            if (modelAsset == null)
            {
                Debug.LogError("Model asset is not assigned in the configuration");
                return null;
            }

            if (modelType != SecureMRModelType.LiteRtModel)
            {
                Debug.LogError(
                    $"RunModelInferenceOperator only supports TFLite/LiteRT models. " +
                    $"QNN context binaries and other model types are no longer supported. Provided model type: {modelType}.");
                return null;
            }

            // Create the base configuration
            ModelOperatorConfiguration modelConfig = new ModelOperatorConfiguration(
                modelAsset.bytes,
                modelType,
                string.IsNullOrEmpty(modelName) ? modelAsset.name : modelName,
                new LiteRtModelConfiguration(liteRtModelTarget, liteRtCpuTargetNumThreads)
            );

            return modelConfig;
        }

    }
}
#endif
