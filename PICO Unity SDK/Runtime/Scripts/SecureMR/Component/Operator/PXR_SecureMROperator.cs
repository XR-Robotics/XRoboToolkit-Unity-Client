#if !ENABLE_PICO_OPENXR_SDK
using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace ByteDance.PICO.SecureMR
{
    public class PXR_SecureMROperator : MonoBehaviour
    {
        public SecureMROperatorType operatorType;

        public PXR_SecureMROperatorConfig operatorConfig;

        public PXR_SecureMROperand[] operands;

        public PXR_SecureMRResult[] results;

        internal Operator Operator;

        public void InitializeOperator(PXR_SecureMRPipeline pipeline)
        {
            switch (operatorType)
            {
                case SecureMROperatorType.Unknown:
                    break;
                case SecureMROperatorType.ArithmeticCompose:
                {
                    if (operatorConfig != null && operatorConfig is PXR_SecureMRArithmeticComposeOperatorConfig opConfig)
                    {
                        ArithmeticComposeOperatorConfiguration arithmeticComposeOperatorConfig = new ArithmeticComposeOperatorConfiguration(opConfig.configText);
                        Operator = pipeline.pipeline.CreateOperator<ArithmeticComposeOperator>(arithmeticComposeOperatorConfig);
                    }
                }
                    break;
                case SecureMROperatorType.Nms:
                {
                    if (operatorConfig != null && operatorConfig is PXR_SecureMRNmsOperatorConfig opConfig)
                    {
                        NmsOperatorConfiguration nmsOperatorConfig = new NmsOperatorConfiguration(opConfig.threshold);
                        Operator = pipeline.pipeline.CreateOperator<NmsOperator>(nmsOperatorConfig);
                    }
                }
                    break;
                case SecureMROperatorType.ElementwiseMin:
                {
                    Operator = pipeline.pipeline.CreateOperator<ElementwiseMinOperator>();
                }
                    break;
                case SecureMROperatorType.ElementwiseMax:
                {
                    Operator = pipeline.pipeline.CreateOperator<ElementwiseMaxOperator>();
                }
                    break;
                case SecureMROperatorType.ElementwiseMultiply:
                {
                    Operator = pipeline.pipeline.CreateOperator<ElementwiseMultiplyOperator>();
                }
                    break;
                case SecureMROperatorType.CustomizedCompare:
                {
                    if (operatorConfig != null && operatorConfig is PXR_SecureMRComparisonOperatorConfig opConfig)
                    {
                        ComparisonOperatorConfiguration comparisonOperatorConfig = new ComparisonOperatorConfiguration(opConfig.comparison);
                        Operator = pipeline.pipeline.CreateOperator<CustomizedCompareOperator>(comparisonOperatorConfig);
                    }
                }
                    break;
                case SecureMROperatorType.ElementwiseOr:
                {
                    Operator = pipeline.pipeline.CreateOperator<ElementwiseOrOperator>();
                }
                    break;
                case SecureMROperatorType.ElementwiseAnd:
                {
                    Operator = pipeline.pipeline.CreateOperator<ElementwiseAndOperator>();
                }
                    break;
                case SecureMROperatorType.All:
                {
                    Operator = pipeline.pipeline.CreateOperator<AllOperator>();
                }
                    break;
                case SecureMROperatorType.Any:
                {
                    Operator = pipeline.pipeline.CreateOperator<AnyOperator>();
                }
                    break;

                case SecureMROperatorType.SolvePnP:
                {
                    Operator = pipeline.pipeline.CreateOperator<SolvePnPOperator>();
                }
                    break;
                case SecureMROperatorType.GetAffine:
                {
                    Operator = pipeline.pipeline.CreateOperator<GetAffineOperator>();
                }
                    break;
                case SecureMROperatorType.ApplyAffine:
                {
                    Operator = pipeline.pipeline.CreateOperator<ApplyAffineOperator>();
                }
                    break;
                case SecureMROperatorType.ApplyAffinePoint:
                {
                    Operator = pipeline.pipeline.CreateOperator<ApplyAffinePointOperator>();
                }
                    break;
                case SecureMROperatorType.UvTo3DInCameraSpace:
                {
                    Operator = pipeline.pipeline.CreateOperator<UvTo3DInCameraSpaceOperator>();
                }
                    break;
                case SecureMROperatorType.Assignment:
                {
                    Operator = pipeline.pipeline.CreateOperator<AssignmentOperator>();
                }
                    break;
                case SecureMROperatorType.RunModelInference:
                {
                    if (operatorConfig != null && operatorConfig is PXR_SecureMRModelOperatorConfiguration opConfig)
                    {
                        var modelOperatorConfiguration = opConfig.CreateModelOperatorConfiguration();
                        if (modelOperatorConfiguration == null)
                        {
                            // Prevent later parameter binding from dereferencing a null Operator.
                            Operator = null;
                            UnityEngine.Debug.LogError("[SecureMR] RunModelInference: modelOperatorConfiguration is null. Operator will not be created; parameter initialization will be skipped for this component.");
                            return;
                        }

                        Operator = pipeline.pipeline.CreateOperator<RunModelInferenceOperator>(modelOperatorConfiguration);
                    }
                }
                    break;
                case SecureMROperatorType.Normalize:
                {
                    if (operatorConfig != null && operatorConfig is PXR_SecureMRNormalizeOperatorConfig opConfig)
                    {
                        NormalizeOperatorConfiguration normalizeOperatorConfig = new NormalizeOperatorConfiguration(opConfig.normalizeType);
                        Operator = pipeline.pipeline.CreateOperator<NormalizeOperator>(normalizeOperatorConfig);
                    }
                }
                    break;
                case SecureMROperatorType.CameraSpaceToWorld:
                {
                    Operator = pipeline.pipeline.CreateOperator<CameraSpaceToWorldOperator>();
                }
                    break;
                case SecureMROperatorType.RectifiedVstAccess:
                {
                    Operator = pipeline.pipeline.CreateOperator<RectifiedVstAccessOperator>();
                }
                    break;
                case SecureMROperatorType.Argmax:
                {
                    Operator = pipeline.pipeline.CreateOperator<ArgmaxOperator>();
                }
                    break;
                case SecureMROperatorType.ConvertColor:
                {
                    if (operatorConfig != null && operatorConfig is PXR_SecureMRColorConvertOperatorConfig opConfig)
                    {
                        ColorConvertOperatorConfiguration colorConvertOperatorConfig = new ColorConvertOperatorConfiguration(opConfig.convert);
                        Operator = pipeline.pipeline.CreateOperator<ConvertColorOperator>(colorConvertOperatorConfig);
                    }
                }
                    break;
                case SecureMROperatorType.SortVector:
                {
                    Operator = pipeline.pipeline.CreateOperator<SortVectorOperator>();
                }
                    break;
                case SecureMROperatorType.Inversion:
                {
                    Operator = pipeline.pipeline.CreateOperator<InversionOperator>();
                }
                    break;
                case SecureMROperatorType.GetTransformMatrix:
                {
                    Operator = pipeline.pipeline.CreateOperator<GetTransformMatrixOperator>();
                }
                    break;
                case SecureMROperatorType.SortMatrix:
                {
                    if (operatorConfig != null && operatorConfig is PXR_SecureMRSortMatrixOperatorConfig opConfig)
                    {
                        SortMatrixOperatorConfiguration colorConvertOperatorConfig = new SortMatrixOperatorConfiguration(opConfig.sortType);
                        Operator = pipeline.pipeline.CreateOperator<SortMatrixOperator>(colorConvertOperatorConfig);
                    }
                }
                    break;
                case SecureMROperatorType.SwitchGltfRenderStatus:
                {
                    Operator = pipeline.pipeline.CreateOperator<SwitchGltfRenderStatusOperator>();
                }
                    break;
                case SecureMROperatorType.UpdateGltf:
                {
                    if (operatorConfig != null && operatorConfig is PXR_SecureMRUpdateGltfOperatorConfig opConfig)
                    {
                        UpdateGltfOperatorConfiguration colorConvertOperatorConfig = new UpdateGltfOperatorConfiguration(opConfig.attribute);
                        Operator = pipeline.pipeline.CreateOperator<UpdateGltfOperator>(colorConvertOperatorConfig);
                    }
                }
                    break;
                case SecureMROperatorType.RenderText:
                {
                    if (operatorConfig != null && operatorConfig is PXR_SecureMRRenderTextOperatorConfig opConfig)
                    {
                        RenderTextOperatorConfiguration colorConvertOperatorConfig = new RenderTextOperatorConfiguration(opConfig.typeface, opConfig.languageAndLocale, opConfig.width, opConfig.height);
                        Operator = pipeline.pipeline.CreateOperator<UpdateGltfOperator>(colorConvertOperatorConfig);
                    }
                }
                    break;
                case SecureMROperatorType.LoadTexture:
                {
                    Operator = pipeline.pipeline.CreateOperator<LoadTextureOperator>();
                }
                    break;
                case SecureMROperatorType.ScenegraphVisibility:
                {
                    Operator = pipeline.pipeline.CreateOperator<ScenegraphVisibilityOperator>();
                }
                    break;
                case SecureMROperatorType.UpdateComponent:
                {
                    if (operatorConfig != null && operatorConfig is PXR_SecureMRUpdateComponentOperatorConfig opConfig)
                    {
                        UpdateComponentOperatorConfiguration updateComponentOperatorConfig = new UpdateComponentOperatorConfiguration(opConfig.entityPath, opConfig.targetPropertyPath);
                        Operator = pipeline.pipeline.CreateOperator<UpdateComponentOperator>(updateComponentOperatorConfig);
                    }
                }
                    break;
                case SecureMROperatorType.Microphone:
                {
                    if (operatorConfig != null && operatorConfig is PXR_SecureMRMicrophoneOperatorConfig opConfig)
                    {
                        MicrophoneOperatorConfiguration microphoneOperatorConfiguration = new MicrophoneOperatorConfiguration(opConfig.sampleRate, opConfig.pcmType);
                        Operator = pipeline.pipeline.CreateOperator<MicrophoneOperator>(microphoneOperatorConfiguration);
                    }
                }
                    break;
                case SecureMROperatorType.Speaker:
                {
                    if (operatorConfig != null && operatorConfig is PXR_SecureMRSpeakerOperatorConfig opConfig)
                    {
                        SpeakerOperatorConfiguration speakerOperatorConfiguration = new SpeakerOperatorConfiguration(opConfig.sampleRate);
                        Operator = pipeline.pipeline.CreateOperator<SpeakerOperator>(speakerOperatorConfiguration);
                    }
                }
                    break;
                case SecureMROperatorType.Depth:
                {
                    Operator = pipeline.pipeline.CreateOperator<DepthOperator>();
                }
                    break;
                default:
                    throw new ArgumentOutOfRangeException();
            }
        }

        public void InitializeParameters()
        {
            if (Operator == null)
            {
                UnityEngine.Debug.LogError($"[SecureMR] Skipping parameter initialization for operator '{operatorType}' because it was not created.");
                return;
            }

            for (int i = 0; i < operands.Length; i++)
            {
                Operator.SetOperand(operands[i].name, operands[i].tensor.tensor);
            }

            for (int i = 0; i < results.Length; i++)
            {
                Operator.SetResult(results[i].name, results[i].tensor.tensor);
            }
        }
    }
}
#endif
