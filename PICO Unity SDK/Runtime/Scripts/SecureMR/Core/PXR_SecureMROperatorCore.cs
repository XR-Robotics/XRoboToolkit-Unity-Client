#if !ENABLE_PICO_OPENXR_SDK
using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using ByteDance.PICO.XR;

namespace ByteDance.PICO.SecureMR
{
    public abstract class OperatorConfiguration
    {

    }

    public class ArithmeticComposeOperatorConfiguration : OperatorConfiguration
    {
        public string configText { get; set; }

        public ArithmeticComposeOperatorConfiguration(string configText)
        {
            this.configText = configText;
        }
    }

    public class ComparisonOperatorConfiguration : OperatorConfiguration
    {
        public SecureMRComparison comparison { get; set; }

        public ComparisonOperatorConfiguration(SecureMRComparison comparison)
        {
            this.comparison = comparison;
        }
    }

    public class NmsOperatorConfiguration : OperatorConfiguration
    {
        public float threshold { get; set; }

        public NmsOperatorConfiguration(float threshold)
        {
            this.threshold = threshold;
        }
    }

    public class NormalizeOperatorConfiguration : OperatorConfiguration
    {
        public SecureMRNormalizeType normalizeType { get; set; }

        public NormalizeOperatorConfiguration(SecureMRNormalizeType normalizeType)
        {
            this.normalizeType = normalizeType;
        }
    }

    public class ColorConvertOperatorConfiguration : OperatorConfiguration
    {
        public int convert { get; set; }
        public ColorConvertOperatorConfiguration(int convert)
        {
            this.convert = convert;
        }
    }

    public class SortMatrixOperatorConfiguration : OperatorConfiguration
    {
        public SecureMRMatrixSortType sortType { get; set; }
        public SortMatrixOperatorConfiguration(SecureMRMatrixSortType sortType)
        {
            this.sortType = sortType;
        }
    }

    public class UpdateGltfOperatorConfiguration : OperatorConfiguration
    {
        public SecureMRGltfOperatorAttribute attribute { get; set; }
        public UpdateGltfOperatorConfiguration(SecureMRGltfOperatorAttribute attribute)
        {
            this.attribute = attribute;
        }
    }

    public class RenderTextOperatorConfiguration : OperatorConfiguration
    {
        public SecureMRFontTypeface typeface { get; set; }
        public string languageAndLocale { get; set; }
        public int width { get; set; }
        public int height { get; set; }

        public RenderTextOperatorConfiguration(SecureMRFontTypeface typeface, string languageAndLocale, int width, int height)
        {
            this.typeface = typeface;
            this.languageAndLocale = languageAndLocale;
            this.width = width;
            this.height = height;
        }
    }

    public class ModelOperatorConfiguration : OperatorConfiguration
    {
        private const string UnsupportedModelTypeMessage =
            "RunModelInferenceOperator only supports TFLite/LiteRT models. " +
            "QNN context binaries and other model types are no longer supported.";

        public byte[] modelData { get; set; }
        public SecureMRModelType modelType { get; set; }
        public string modelName { get; set; }
        public LiteRtModelConfiguration liteRtConfiguration { get; set; }

        public ModelOperatorConfiguration(
            byte[] modelData,
            SecureMRModelType modelType,
            string modelName,
            LiteRtModelConfiguration liteRtConfiguration)
        {
            ThrowIfUnsupportedModelType(modelType);

            this.modelData = modelData;
            this.modelType = modelType;
            this.modelName = modelName;
            this.liteRtConfiguration = liteRtConfiguration;
        }

        public ModelOperatorConfiguration(byte[] modelData, SecureMRModelType modelType, string modelName)
            : this(modelData, modelType, modelName, null)
        {
        }

        internal static bool TryValidateModelType(SecureMRModelType modelType, out string error)
        {
            if (modelType == SecureMRModelType.LiteRtModel)
            {
                error = null;
                return true;
            }

            error = $"{UnsupportedModelTypeMessage} Provided model type: {modelType}.";
            return false;
        }

        internal static void ThrowIfUnsupportedModelType(SecureMRModelType modelType)
        {
            if (!TryValidateModelType(modelType, out var error))
            {
                throw new ArgumentException(error, nameof(modelType));
            }
        }
    }

    public class LiteRtModelConfiguration
    {
        public SecureMRModelTarget modelTarget { get; set; }
        public int cpuTargetNumThreads { get; set; }

        public LiteRtModelConfiguration(SecureMRModelTarget modelTarget, int cpuTargetNumThreads = 0)
        {
            this.modelTarget = modelTarget;
            this.cpuTargetNumThreads = cpuTargetNumThreads;
        }
    }
    
    public class JavascriptOperatorConfiguration : OperatorConfiguration
    {
        public string configText { get; set; }
        
        public JavascriptOperatorConfiguration(string configText)
        {
            this.configText = configText;
        }
    }

    public class UpdateComponentOperatorConfiguration : OperatorConfiguration
    {
        public string entityPath { get; set; }
        public string targetPropertyPath { get; set; }

        public UpdateComponentOperatorConfiguration(string entityPath, string targetPropertyPath)
        {
            this.entityPath = entityPath;
            this.targetPropertyPath = targetPropertyPath;
        }
    }

    public class MicrophoneOperatorConfiguration : OperatorConfiguration
    {
        public int sampleRate { get; set; }
        public string pcmType { get; set; }

        public MicrophoneOperatorConfiguration(int sampleRate, string pcmType)
        {
            this.sampleRate = sampleRate;
            this.pcmType = pcmType;
        }
    }

    public class SpeakerOperatorConfiguration : OperatorConfiguration
    {
        public int sampleRate { get; set; }

        public SpeakerOperatorConfiguration(int sampleRate)
        {
            this.sampleRate = sampleRate;
        }
    }

    public abstract class Operator
    {
        internal ISecureMRBackend Backend { get; set; }
        public SecureMROperatorType OperatorType { get; private set; }
        public ulong OperatorHandle { get; internal set; }
        public ulong PipelineHandle { get; private set; }

        public PxrResult SetOperand(string name, Tensor tensor)
        {
            var backend = Backend ?? SecureMRBackendRouter.Current;
            return backend.SetOperand(this, name, tensor);
        }

        public PxrResult SetResult(string name, Tensor tensor)
        {
            var backend = Backend ?? SecureMRBackendRouter.Current;
            return backend.SetResult(this, name, tensor);
        }

        public Operator(ulong pipelineHandle, SecureMROperatorType operatorType)
        {
            PipelineHandle = pipelineHandle;
            OperatorType = operatorType;
        }
    }

    public class ArithmeticComposeOperator : Operator
    {
        public ArithmeticComposeOperator(ulong pipelineHandle, SecureMROperatorType operatorType, ArithmeticComposeOperatorConfiguration config) : base(pipelineHandle, operatorType) { }
    }

    public class ElementwiseMinOperator : Operator
    {
        public ElementwiseMinOperator(ulong pipelineHandle, SecureMROperatorType operatorType) : base(pipelineHandle, operatorType) { }
    }

    public class ElementwiseMaxOperator : Operator
    {
        public ElementwiseMaxOperator(ulong pipelineHandle, SecureMROperatorType operatorType) : base(pipelineHandle, operatorType) { }
    }

    public class ElementwiseMultiplyOperator : Operator
    {
        public ElementwiseMultiplyOperator(ulong pipelineHandle, SecureMROperatorType operatorType) : base(pipelineHandle, operatorType) { }
    }

    public class CustomizedCompareOperator : Operator
    {
        public CustomizedCompareOperator(ulong pipelineHandle, SecureMROperatorType operatorType, ComparisonOperatorConfiguration configuration) : base(pipelineHandle, operatorType) { }
    }

    public class ElementwiseOrOperator : Operator
    {
        public ElementwiseOrOperator(ulong pipelineHandle, SecureMROperatorType operatorType) : base(pipelineHandle, operatorType) { }
    }

    public class ElementwiseAndOperator : Operator
    {
        public ElementwiseAndOperator(ulong pipelineHandle, SecureMROperatorType operatorType) : base(pipelineHandle, operatorType) { }
    }

    public class AllOperator : Operator
    {
        public AllOperator(ulong pipelineHandle, SecureMROperatorType operatorType) : base(pipelineHandle, operatorType) { }
    }

    public class AnyOperator : Operator
    {
        public AnyOperator(ulong pipelineHandle, SecureMROperatorType operatorType) : base(pipelineHandle, operatorType) { }
    }

    public class NmsOperator : Operator
    {
        public NmsOperator(ulong pipelineHandle, SecureMROperatorType operatorType, NmsOperatorConfiguration configuration) : base(pipelineHandle, operatorType) { }
    }

    public class SolvePnPOperator : Operator
    {
        public SolvePnPOperator(ulong pipelineHandle, SecureMROperatorType operatorType) : base(pipelineHandle, operatorType) { }
    }

    public class GetAffineOperator : Operator
    {
        public GetAffineOperator(ulong pipelineHandle, SecureMROperatorType operatorType) : base(pipelineHandle, operatorType) { }
    }

    public class ApplyAffineOperator : Operator
    {
        public ApplyAffineOperator(ulong pipelineHandle, SecureMROperatorType operatorType) : base(pipelineHandle, operatorType) { }
    }

    public class ApplyAffinePointOperator : Operator
    {
        public ApplyAffinePointOperator(ulong pipelineHandle, SecureMROperatorType operatorType) : base(pipelineHandle, operatorType) { }
    }

    public class UvTo3DInCameraSpaceOperator : Operator
    {
        public UvTo3DInCameraSpaceOperator(ulong pipelineHandle, SecureMROperatorType operatorType) : base(pipelineHandle, operatorType) { }
    }

    public class AssignmentOperator : Operator
    {
        public AssignmentOperator(ulong pipelineHandle, SecureMROperatorType operatorType) : base(pipelineHandle, operatorType) { }
    }

    public class RunModelInferenceOperator : Operator
    {
        public RunModelInferenceOperator(ulong pipelineHandle, SecureMROperatorType operatorType, ModelOperatorConfiguration configuration) : base(pipelineHandle, operatorType) { }
    }

    public class NormalizeOperator : Operator
    {
        public NormalizeOperator(ulong pipelineHandle, SecureMROperatorType operatorType, NormalizeOperatorConfiguration configuration) : base(pipelineHandle, operatorType) { }
    }

    public class CameraSpaceToWorldOperator : Operator
    {
        public CameraSpaceToWorldOperator(ulong pipelineHandle, SecureMROperatorType operatorType) : base(pipelineHandle, operatorType) { }
    }

    public class RectifiedVstAccessOperator : Operator
    {
        public RectifiedVstAccessOperator(ulong pipelineHandle, SecureMROperatorType operatorType) : base(pipelineHandle, operatorType) { }
    }

    public class ArgmaxOperator : Operator
    {
        public ArgmaxOperator(ulong pipelineHandle, SecureMROperatorType operatorType) : base(pipelineHandle, operatorType) { }
    }

    public class ConvertColorOperator : Operator
    {
        public ConvertColorOperator(ulong pipelineHandle, SecureMROperatorType operatorType, ColorConvertOperatorConfiguration convertConfiguration) : base(pipelineHandle, operatorType) { }
    }

    public class SortVectorOperator : Operator
    {
        public SortVectorOperator(ulong pipelineHandle, SecureMROperatorType operatorType) : base(pipelineHandle, operatorType) { }
    }

    public class InversionOperator : Operator
    {
        public InversionOperator(ulong pipelineHandle, SecureMROperatorType operatorType) : base(pipelineHandle, operatorType) { }
    }

    public class GetTransformMatrixOperator : Operator
    {
        public GetTransformMatrixOperator(ulong pipelineHandle, SecureMROperatorType operatorType) : base(pipelineHandle, operatorType) { }
    }

    public class SortMatrixOperator : Operator
    {
        public SortMatrixOperator(ulong pipelineHandle, SecureMROperatorType operatorType, SortMatrixOperatorConfiguration configuration) : base(pipelineHandle, operatorType) { }
    }

    public class SwitchGltfRenderStatusOperator : Operator
    {
        public SwitchGltfRenderStatusOperator(ulong pipelineHandle, SecureMROperatorType operatorType) : base(pipelineHandle, operatorType) { }
    }

    public class UpdateGltfOperator : Operator
    {
        public UpdateGltfOperator(ulong pipelineHandle, SecureMROperatorType operatorType, UpdateGltfOperatorConfiguration configuration) : base(pipelineHandle, operatorType) { }
    }

    public class RenderTextOperator : Operator
    {
        public RenderTextOperator(ulong pipelineHandle, SecureMROperatorType operatorType, RenderTextOperatorConfiguration configuration) : base(pipelineHandle, operatorType) { }
    }

    public class LoadTextureOperator : Operator
    {
        public LoadTextureOperator(ulong pipelineHandle, SecureMROperatorType operatorType) : base(pipelineHandle, operatorType) { }
    }
    
    public class SvdOperator : Operator
    {
        public SvdOperator(ulong pipelineHandle, SecureMROperatorType operatorType) : base(pipelineHandle, operatorType) { }
    }
    
    public class NormOperator : Operator
    {
        public NormOperator(ulong pipelineHandle, SecureMROperatorType operatorType) : base(pipelineHandle, operatorType) { }
    }
    
    public class SwapHwcChwOperator : Operator
    {
        public SwapHwcChwOperator(ulong pipelineHandle, SecureMROperatorType operatorType) : base(pipelineHandle, operatorType) { }
    }

    public class ScenegraphVisibilityOperator : Operator
    {
        public ScenegraphVisibilityOperator(ulong pipelineHandle, SecureMROperatorType operatorType) : base(pipelineHandle, operatorType) { }
    }

    public class UpdateComponentOperator : Operator
    {
        public UpdateComponentOperator(ulong pipelineHandle, SecureMROperatorType operatorType, UpdateComponentOperatorConfiguration configuration) : base(pipelineHandle, operatorType) { }
    }

    public class MicrophoneOperator : Operator
    {
        public MicrophoneOperator(ulong pipelineHandle, SecureMROperatorType operatorType, MicrophoneOperatorConfiguration configuration) : base(pipelineHandle, operatorType) { }
    }

    public class SpeakerOperator : Operator
    {
        public SpeakerOperator(ulong pipelineHandle, SecureMROperatorType operatorType, SpeakerOperatorConfiguration configuration) : base(pipelineHandle, operatorType) { }
    }

    public class DepthOperator : Operator
    {
        public DepthOperator(ulong pipelineHandle, SecureMROperatorType operatorType) : base(pipelineHandle, operatorType) { }
    }
    
    public class JavascriptOperator : Operator
    {
        public JavascriptOperator(ulong pipelineHandle, SecureMROperatorType operatorType, JavascriptOperatorConfiguration operatorConfiguration) : base(pipelineHandle, operatorType) { }
    }
}

#endif
