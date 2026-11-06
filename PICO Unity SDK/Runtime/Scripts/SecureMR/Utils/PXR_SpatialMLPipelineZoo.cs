#if !ENABLE_PICO_OPENXR_SDK
using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using ByteDance.PICO.XR;
using UnityEngine;

namespace ByteDance.PICO.SecureMR
{
    public static class SpatialMLPipelineZoo
    {
        public static SpatialMLPipelineZooBundle LoadPackage(Provider provider, SpatialMLPipelineZooAsset packageAsset, params string[] pipelineIds)
        {
            if (provider == null) throw new ArgumentNullException(nameof(provider));
            if (packageAsset == null) throw new ArgumentNullException(nameof(packageAsset));
            if (packageAsset.manifestJson == null) throw new ArgumentException("Package manifestJson is not assigned.", nameof(packageAsset));

            var manifest = MiniJson.ParseObject(packageAsset.manifestJson.text);
            var bundle = new SpatialMLPipelineZooBundle
            {
                DetectionTensorName = GetString(GetObject(manifest, "runtime"), "detection_tensor")
            };

            var requested = pipelineIds == null || pipelineIds.Length == 0 ? null : new HashSet<string>(pipelineIds);
            foreach (var spec in ReadPipelineSpecs(manifest))
            {
                if (requested != null && !requested.Contains(spec.id)) continue;
                var pipelineJsonAsset = packageAsset.FindPipelineJson(spec.id, spec.path);
                if (pipelineJsonAsset == null) throw new InvalidOperationException($"Pipeline JSON not found for '{spec.id}' ({spec.path}).");
                var pipelineSpec = MiniJson.ParseObject(pipelineJsonAsset.text);
                var pipeline = DeserializePipeline(provider, packageAsset, pipelineSpec);
                pipeline.Id = spec.id;
                pipeline.Inputs = ReadTensorList(GetValue(pipelineSpec, "inputs"));
                pipeline.Outputs = ReadTensorList(GetValue(pipelineSpec, "outputs"));

                BindPackageGltfAssets(provider, packageAsset, pipelineSpec, bundle, pipeline);
                foreach (var input in pipeline.Inputs) EnsureSharedBinding(provider, bundle, pipeline, input);
                foreach (var output in pipeline.Outputs) EnsureSharedBinding(provider, bundle, pipeline, output);
                if (!string.IsNullOrEmpty(bundle.DetectionTensorName)) EnsureSharedBinding(provider, bundle, pipeline, bundle.DetectionTensorName);

                bundle.Pipelines.Add(spec.id, pipeline);
            }

            if (requested != null)
            {
                foreach (var id in requested)
                {
                    if (!bundle.Pipelines.ContainsKey(id)) throw new InvalidOperationException($"Requested pipeline '{id}' was not found in package manifest.");
                }
            }

            return bundle;
        }

        private static SpatialMLPipelineZooPipeline DeserializePipeline(
            Provider provider,
            SpatialMLPipelineZooAsset packageAsset,
            Dictionary<string, object> pipelineSpec)
        {
            var result = new SpatialMLPipelineZooPipeline { Pipeline = provider.CreatePipeline() };
            var tensorSpecs = GetObject(pipelineSpec, "tensors") ?? throw new InvalidOperationException("Pipeline JSON is missing tensors.");
            foreach (var pair in tensorSpecs)
            {
                var spec = pair.Value as Dictionary<string, object> ?? throw new InvalidOperationException($"Tensor '{pair.Key}' is not an object.");
                result.Tensors[pair.Key] = CreatePipelineTensor(result.Pipeline, spec);
            }

            var operators = GetList(pipelineSpec, "operators") ?? throw new InvalidOperationException("Pipeline JSON is missing operators.");
            foreach (var item in operators)
            {
                var opSpec = item as Dictionary<string, object> ?? throw new InvalidOperationException("Operator entry is not an object.");
                CreateOperator(packageAsset, result.Pipeline, result.Tensors, opSpec);
            }
            return result;
        }

        private static Tensor CreatePipelineTensor(Pipeline pipeline, Dictionary<string, object> spec)
        {
            var isPlaceholder = GetBool(spec, "is_placeholder");
            var tensorType = GetString(spec, "tensor_type");
            if (string.IsNullOrEmpty(tensorType)) tensorType = GetString(spec, "type");
            tensorType = tensorType.ToLowerInvariant();
            if (GetBool(spec, "is_gltf") || tensorType == "gltf")
                return pipeline.CreateTensorReference<Gltf>();
            if (tensorType == "timestamp") return isPlaceholder
                ? pipeline.CreateTensorReference<int, TimeStamp>(4, new TensorShape(1))
                : pipeline.CreateTensor<int, TimeStamp>(4, new TensorShape(1), ReadArray<int>(spec));

            var dataType = ParseDataType(
                GetValue(spec, "data_type"),
                tensorType == "rgba_array" ? SecureMRTensorDataType.Byte : SecureMRTensorDataType.Float);
            var usage = ParseUsage(spec, tensorType);
            var channels = GetInt(spec, "channels", DefaultChannels(tensorType));
            var shape = new TensorShape(ReadDimensions(spec, tensorType));

            return CreateTensor(pipeline, isPlaceholder, dataType, usage, channels, shape, spec);
        }

        private static Tensor CreateGlobalLike(Provider provider, Tensor local)
        {
            return CreateTensor(provider, local.DataType, local.Usage, local.Channels, new TensorShape(local.Dimensions ?? new[] { 1 }), null);
        }

        private static Tensor CreateTensor(Pipeline pipeline, bool placeholder, SecureMRTensorDataType dataType, SecureMRTensorUsage usage, int channels, TensorShape shape, Dictionary<string, object> spec)
        {
            if (placeholder)
            {
                switch (dataType)
                {
                    case SecureMRTensorDataType.Byte: return CreateReference<byte>(pipeline, usage, channels, shape);
                    case SecureMRTensorDataType.DynamicTextureByte: return CreateReference<byte>(pipeline, usage, channels, shape);
                    case SecureMRTensorDataType.Sbyte: return CreateReference<sbyte>(pipeline, usage, channels, shape);
                    case SecureMRTensorDataType.Ushort: return CreateReference<ushort>(pipeline, usage, channels, shape);
                    case SecureMRTensorDataType.Short: return CreateReference<short>(pipeline, usage, channels, shape);
                    case SecureMRTensorDataType.Int: return CreateReference<int>(pipeline, usage, channels, shape);
                    case SecureMRTensorDataType.Double: return CreateReference<double>(pipeline, usage, channels, shape);
                    case SecureMRTensorDataType.DynamicTextureFloat: return CreateReference<float>(pipeline, usage, channels, shape);
                    default: return CreateReference<float>(pipeline, usage, channels, shape);
                }
            }

            switch (dataType)
            {
                case SecureMRTensorDataType.Byte: return CreateLocal<byte>(pipeline, usage, channels, shape, spec);
                case SecureMRTensorDataType.DynamicTextureByte: return CreateLocal<byte>(pipeline, usage, channels, shape, spec);
                case SecureMRTensorDataType.Sbyte: return CreateLocal<sbyte>(pipeline, usage, channels, shape, spec);
                case SecureMRTensorDataType.Ushort: return CreateLocal<ushort>(pipeline, usage, channels, shape, spec);
                case SecureMRTensorDataType.Short: return CreateLocal<short>(pipeline, usage, channels, shape, spec);
                case SecureMRTensorDataType.Int: return CreateLocal<int>(pipeline, usage, channels, shape, spec);
                case SecureMRTensorDataType.Double: return CreateLocal<double>(pipeline, usage, channels, shape, spec);
                case SecureMRTensorDataType.DynamicTextureFloat: return CreateLocal<float>(pipeline, usage, channels, shape, spec);
                default: return CreateLocal<float>(pipeline, usage, channels, shape, spec);
            }
        }

        private static Tensor CreateTensor(Provider provider, SecureMRTensorDataType dataType, SecureMRTensorUsage usage, int channels, TensorShape shape, Dictionary<string, object> spec)
        {
            switch (dataType)
            {
                case SecureMRTensorDataType.Byte: return CreateGlobal<byte>(provider, usage, channels, shape, spec);
                case SecureMRTensorDataType.DynamicTextureByte: return CreateGlobal<byte>(provider, usage, channels, shape, spec);
                case SecureMRTensorDataType.Sbyte: return CreateGlobal<sbyte>(provider, usage, channels, shape, spec);
                case SecureMRTensorDataType.Ushort: return CreateGlobal<ushort>(provider, usage, channels, shape, spec);
                case SecureMRTensorDataType.Short: return CreateGlobal<short>(provider, usage, channels, shape, spec);
                case SecureMRTensorDataType.Int: return CreateGlobal<int>(provider, usage, channels, shape, spec);
                case SecureMRTensorDataType.Double: return CreateGlobal<double>(provider, usage, channels, shape, spec);
                case SecureMRTensorDataType.DynamicTextureFloat: return CreateGlobal<float>(provider, usage, channels, shape, spec);
                default: return CreateGlobal<float>(provider, usage, channels, shape, spec);
            }
        }

        private static Tensor CreateReference<T>(Pipeline pipeline, SecureMRTensorUsage usage, int channels, TensorShape shape) where T : struct
        {
            if (usage == SecureMRTensorUsage.Point) return pipeline.CreateTensorReference<T, Point>(channels, shape);
            if (usage == SecureMRTensorUsage.Color) return pipeline.CreateTensorReference<T, Color>(channels, shape);
            if (usage == SecureMRTensorUsage.Scalar) return pipeline.CreateTensorReference<T, Scalar>(channels, shape);
            if (usage == SecureMRTensorUsage.Slice) return pipeline.CreateTensorReference<T, Slice>(channels, shape);
            if (usage == SecureMRTensorUsage.TimeStamp) return pipeline.CreateTensorReference<T, TimeStamp>(channels, shape);
            if (usage == SecureMRTensorUsage.DynamicTexture) return pipeline.CreateTensorReference<T, DynamicTexture>(channels, shape);
            return pipeline.CreateTensorReference<T, Matrix>(channels, shape);
        }

        private static Tensor CreateLocal<T>(Pipeline pipeline, SecureMRTensorUsage usage, int channels, TensorShape shape, Dictionary<string, object> spec) where T : struct
        {
            var data = ReadArray<T>(spec);
            if (usage == SecureMRTensorUsage.Point) return pipeline.CreateTensor<T, Point>(channels, shape, data);
            if (usage == SecureMRTensorUsage.Color) return pipeline.CreateTensor<T, Color>(channels, shape, data);
            if (usage == SecureMRTensorUsage.Scalar) return pipeline.CreateTensor<T, Scalar>(channels, shape, data);
            if (usage == SecureMRTensorUsage.Slice) return pipeline.CreateTensor<T, Slice>(channels, shape, data);
            if (usage == SecureMRTensorUsage.TimeStamp) return pipeline.CreateTensor<T, TimeStamp>(channels, shape, data);
            if (usage == SecureMRTensorUsage.DynamicTexture) return pipeline.CreateTensor<T, DynamicTexture>(channels, shape, data);
            return pipeline.CreateTensor<T, Matrix>(channels, shape, data);
        }

        private static Tensor CreateGlobal<T>(Provider provider, SecureMRTensorUsage usage, int channels, TensorShape shape, Dictionary<string, object> spec) where T : struct
        {
            var data = ReadArray<T>(spec);
            if (usage == SecureMRTensorUsage.Point) return provider.CreateTensor<T, Point>(channels, shape, data);
            if (usage == SecureMRTensorUsage.Color) return provider.CreateTensor<T, Color>(channels, shape, data);
            if (usage == SecureMRTensorUsage.Scalar) return provider.CreateTensor<T, Scalar>(channels, shape, data);
            if (usage == SecureMRTensorUsage.Slice) return provider.CreateTensor<T, Slice>(channels, shape, data);
            if (usage == SecureMRTensorUsage.TimeStamp) return provider.CreateTensor<T, TimeStamp>(channels, shape, data);
            if (usage == SecureMRTensorUsage.DynamicTexture) return provider.CreateTensor<T, DynamicTexture>(channels, shape, data);
            return provider.CreateTensor<T, Matrix>(channels, shape, data);
        }

        private static void CreateOperator(
            SpatialMLPipelineZooAsset packageAsset,
            Pipeline pipeline,
            Dictionary<string, Tensor> tensors,
            Dictionary<string, object> opSpec)
        {
            var type = FormatOperatorType(GetString(opSpec, "type"));
            var inputs = ReadTensorList(GetValue(opSpec, "inputs"));
            var outputs = ReadTensorList(GetValue(opSpec, "outputs"));
            switch (type)
            {
                case "camera_access":
                {
                    var op = pipeline.CreateOperator<RectifiedVstAccessOperator>();
                    op.SetResult("right image", tensors[outputs[0]]);
                    op.SetResult("left image", tensors[outputs[1]]);
                    op.SetResult("timestamp", tensors[outputs[2]]);
                    op.SetResult("camera matrix", tensors[outputs[3]]);
                    break;
                }
                case "get_affine":
                {
                    var op = pipeline.CreateOperator<GetAffineOperator>();
                    if (inputs.Count >= 2)
                    {
                        op.SetOperand("src", Resolve(inputs[0], tensors).tensor);
                        op.SetOperand("dst", Resolve(inputs[1], tensors).tensor);
                    }
                    else
                    {
                        op.SetOperand("src", CreatePointTensor(pipeline, opSpec, "src_points"));
                        op.SetOperand("dst", CreatePointTensor(pipeline, opSpec, "dst_points"));
                    }
                    op.SetResult("result", Resolve(outputs[0], tensors).tensor);
                    break;
                }
                case "apply_affine":
                {
                    var op = pipeline.CreateOperator<ApplyAffineOperator>();
                    op.SetOperand("affine", Resolve(inputs[0], tensors).tensor);
                    op.SetOperand("src image", Resolve(inputs[1], tensors).tensor);
                    op.SetResult("dst image", Resolve(outputs[0], tensors).tensor);
                    break;
                }
                case "apply_affine_point":
                {
                    var op = pipeline.CreateOperator<ApplyAffinePointOperator>();
                    op.SetOperand("affine", Resolve(inputs[0], tensors).tensor);
                    op.SetOperand("src", Resolve(inputs[1], tensors).tensor);
                    op.SetResult("dst", Resolve(outputs[0], tensors).tensor);
                    break;
                }
                case "assignment": CreateAssignment(pipeline, tensors, inputs[0], outputs[0]); break;
                case "type_convert": CreateAssignment(pipeline, tensors, inputs[0], outputs[0]); break;
                case "cvt_color":
                {
                    var op = pipeline.CreateOperator<ConvertColorOperator>(
                        new ColorConvertOperatorConfiguration(GetIntOrAttr(opSpec, "flag", 0)));
                    op.SetOperand("src", Resolve(inputs[0], tensors).tensor);
                    op.SetResult("dst", Resolve(outputs[0], tensors).tensor);
                    break;
                }
                case "arithmetic":
                {
                    var op = pipeline.CreateOperator<ArithmeticComposeOperator>(
                        new ArithmeticComposeOperatorConfiguration(GetStringOrAttr(opSpec, "expression")));
                    for (var i = 0; i < inputs.Count; i++) op.SetOperand("{" + i + "}", Resolve(inputs[i], tensors).tensor);
                    op.SetResult("result", Resolve(outputs[0], tensors).tensor);
                    break;
                }
                case "elementwise":
                case "elementwise_min":
                case "elementwise_max":
                case "elementwise_multiply":
                case "elementwise_or":
                case "elementwise_and":
                {
                    var opName = type == "elementwise"
                        ? GetString(opSpec, "op").ToLowerInvariant()
                        : type.Substring("elementwise_".Length);
                    Operator op = CreateElementwiseOperator(pipeline, opName);
                    op.SetOperand("operand0", Resolve(inputs[0], tensors).tensor);
                    op.SetOperand("operand1", Resolve(inputs[1], tensors).tensor);
                    op.SetResult("result", Resolve(outputs[0], tensors).tensor);
                    break;
                }
                case "all":
                {
                    var op = pipeline.CreateOperator<AllOperator>();
                    BindUnaryOperator(op, tensors, inputs, outputs);
                    break;
                }
                case "any":
                {
                    var op = pipeline.CreateOperator<AnyOperator>();
                    BindUnaryOperator(op, tensors, inputs, outputs);
                    break;
                }
                case "nms":
                {
                    var op = pipeline.CreateOperator<NmsOperator>(
                        new NmsOperatorConfiguration(GetFloatOrAttr(opSpec, "threshold", 0.5f)));
                    BindNamedOrSequentialOperator(op, tensors, opSpec, inputs, outputs);
                    break;
                }
                case "solve_pnp":
                {
                    var op = pipeline.CreateOperator<SolvePnPOperator>();
                    BindNamedOrSequentialOperator(op, tensors, opSpec, inputs, outputs);
                    break;
                }
                case "uv2_cam":
                {
                    var op = pipeline.CreateOperator<UvTo3DInCameraSpaceOperator>();
                    op.SetOperand("uv", Resolve(inputs[0], tensors).tensor);
                    op.SetOperand("timestamp", Resolve(inputs[1], tensors).tensor);
                    op.SetOperand("camera intrisic", Resolve(inputs[2], tensors).tensor);
                    op.SetOperand("left image", Resolve(inputs[3], tensors).tensor);
                    op.SetOperand("right image", Resolve(inputs[4], tensors).tensor);
                    op.SetResult("point_xyz", Resolve(outputs[0], tensors).tensor);
                    break;
                }
                case "transform":
                {
                    var op = pipeline.CreateOperator<GetTransformMatrixOperator>();
                    op.SetOperand("rotation", Resolve(inputs[0], tensors).tensor);
                    op.SetOperand("translation", Resolve(inputs[1], tensors).tensor);
                    if (inputs.Count > 2) op.SetOperand("scale", Resolve(inputs[2], tensors).tensor);
                    op.SetResult("result", Resolve(outputs[0], tensors).tensor);
                    break;
                }
                case "normalize":
                {
                    var op = pipeline.CreateOperator<NormalizeOperator>(
                        new NormalizeOperatorConfiguration(
                            ParseNormalizeType(GetStringOrAttr(opSpec, "normalize_type", "l2"))));
                    BindUnaryOperator(op, tensors, inputs, outputs);
                    break;
                }
                case "cam_space_to_xr_local":
                {
                    var op = pipeline.CreateOperator<CameraSpaceToWorldOperator>();
                    op.SetOperand("timestamp", Resolve(inputs[0], tensors).tensor);
                    var eye = GetString(opSpec, "eye", "left").ToLowerInvariant();
                    op.SetResult(eye == "right" ? "right" : "left", Resolve(outputs[0], tensors).tensor);
                    break;
                }
                case "compare_to":
                {
                    var comparison = GetString(opSpec, "comparison");
                    if (string.IsNullOrEmpty(comparison)) comparison = GetStringOrAttr(opSpec, "compare");
                    var op = pipeline.CreateOperator<CustomizedCompareOperator>(
                        new ComparisonOperatorConfiguration(ParseComparison(comparison)));
                    op.SetOperand("operand0", Resolve(inputs[0], tensors).tensor);
                    op.SetOperand("operand1", Resolve(inputs[1], tensors).tensor);
                    op.SetResult("result", Resolve(outputs[0], tensors).tensor);
                    break;
                }
                case "argmax":
                {
                    var op = pipeline.CreateOperator<ArgmaxOperator>();
                    BindUnaryOperator(op, tensors, inputs, outputs, "operand", "result");
                    break;
                }
                case "sort_vector":
                {
                    var op = pipeline.CreateOperator<SortVectorOperator>();
                    BindUnaryOperator(op, tensors, inputs, outputs, "operand", "result");
                    break;
                }
                case "inversion":
                {
                    var op = pipeline.CreateOperator<InversionOperator>();
                    BindUnaryOperator(op, tensors, inputs, outputs, "operand", "result");
                    break;
                }
                case "sort_matrix":
                {
                    var sortMode = GetString(opSpec, "mode");
                    if (string.IsNullOrEmpty(sortMode)) sortMode = GetString(opSpec, "sort_type");
                    if (string.IsNullOrEmpty(sortMode)) sortMode = GetStringOrAttr(opSpec, "axis", "row");
                    var op = pipeline.CreateOperator<SortMatrixOperator>(
                        new SortMatrixOperatorConfiguration(ParseMatrixSortType(sortMode)));
                    BindUnaryOperator(op, tensors, inputs, outputs, "operand", "result");
                    break;
                }
                case "svd":
                {
                    var op = pipeline.CreateOperator<SvdOperator>();
                    BindNamedOrSequentialOperator(op, tensors, opSpec, inputs, outputs);
                    break;
                }
                case "norm":
                {
                    var op = pipeline.CreateOperator<NormOperator>();
                    BindUnaryOperator(op, tensors, inputs, outputs, "operand", "result");
                    break;
                }
                case "swap_hwc_chw":
                {
                    var op = pipeline.CreateOperator<SwapHwcChwOperator>();
                    BindUnaryOperator(op, tensors, inputs, outputs, "operand", "result");
                    break;
                }
                case "run_algorithm": CreateModelOperator(packageAsset, pipeline, tensors, opSpec); break;
                case "javascript":
                {
                    var op = pipeline.CreateOperator<JavascriptOperator>(
                        new JavascriptOperatorConfiguration(GetStringOrAttr(opSpec, "script")));
                    foreach (var pair in ReadMappedTensorList(GetValue(opSpec, "inputs"))) op.SetOperand(pair.alias, tensors[pair.tensor]);
                    foreach (var pair in ReadMappedTensorList(GetValue(opSpec, "outputs"))) op.SetResult(pair.alias, tensors[pair.tensor]);
                    break;
                }
                case "draw_text":
                {
                    var config = GetString(opSpec, "config");
                    if (string.IsNullOrEmpty(config)) config = GetAttr(opSpec, 0)?.ToString() ?? string.Empty;
                    var parts = config.Split('#');
                    var typeface = parts.Length > 0 ? parts[0] : GetString(opSpec, "typeface");
                    var locale = parts.Length > 1 ? parts[1] : GetString(opSpec, "language_and_locale", "en-US");
                    var width = parts.Length > 2 ? ParseInt(parts[2], 256) : GetInt(opSpec, "canvas_width", 256);
                    var height = parts.Length > 3 ? ParseInt(parts[3], 64) : GetInt(opSpec, "canvas_height", 64);
                    var op = pipeline.CreateOperator<RenderTextOperator>(
                        new RenderTextOperatorConfiguration(ParseTypeface(typeface), locale, width, height));
                    var gltfName = GetTensorName(opSpec, inputs, "gltf", 0);
                    op.SetOperand("gltf", Resolve(gltfName, tensors).tensor);
                    BindOptionalOperand(op, tensors, opSpec, inputs, "start", "start", 1);
                    BindOptionalOperand(op, tensors, opSpec, inputs, "colors", "colors", 2);
                    BindOptionalOperand(op, tensors, opSpec, inputs, "texture ID", "texture_id", 3);
                    BindOptionalOperand(op, tensors, opSpec, inputs, "font size", "font_size", 4);
                    var textName = GetTensorName(opSpec, inputs, "text_tensor", 5);
                    if (!string.IsNullOrEmpty(textName))
                    {
                        op.SetOperand("text", Resolve(textName, tensors).tensor);
                    }
                    else
                    {
                        var text = GetString(opSpec, "text");
                        if (string.IsNullOrEmpty(text)) text = GetAttr(opSpec, 1)?.ToString() ?? string.Empty;
                        var bytes = Encoding.UTF8.GetBytes(text);
                        if (bytes.Length == 0) bytes = new byte[] { 0 };
                        op.SetOperand("text", pipeline.CreateTensor<byte, Scalar>(
                            1, new TensorShape(Math.Max(1, bytes.Length)), bytes));
                    }
                    break;
                }
                case "load_texture":
                {
                    var op = pipeline.CreateOperator<LoadTextureOperator>();
                    op.SetOperand("gltf", Resolve(GetTensorName(opSpec, inputs, "gltf", 0), tensors).tensor);
                    op.SetOperand("rgb image", Resolve(GetTensorName(opSpec, inputs, "rgb_image", 1), tensors).tensor);
                    op.SetResult("texture ID", Resolve(GetTensorName(opSpec, outputs, "texture_id", 0), tensors).tensor);
                    break;
                }
                case "update_gltf":
                {
                    var updateType = GetString(opSpec, "update_type");
                    if (string.IsNullOrEmpty(updateType)) updateType = GetStringOrAttr(opSpec, "attribute");
                    var op = pipeline.CreateOperator<UpdateGltfOperator>(
                        new UpdateGltfOperatorConfiguration(ParseGltfAttribute(updateType)));
                    op.SetOperand("gltf", Resolve(GetTensorName(opSpec, inputs, "gltf", 0), tensors).tensor);
                    BindOptionalOperand(op, tensors, opSpec, inputs, "value", "value", 1);
                    BindOptionalOperand(op, tensors, opSpec, inputs, "material ID", "material_id", 2);
                    break;
                }
                case "render_gltf":
                {
                    var op = pipeline.CreateOperator<SwitchGltfRenderStatusOperator>();
                    op.SetOperand("gltf", Resolve(GetTensorName(opSpec, inputs, "gltf", 0), tensors).tensor);
                    BindOptionalOperand(op, tensors, opSpec, inputs, "world pose", "pose", 1);
                    BindOptionalOperand(op, tensors, opSpec, inputs, "view locked", "view_locked", 2);
                    BindOptionalOperand(op, tensors, opSpec, inputs, "is visible", "visible", 3);
                    break;
                }
                case "scenegraph_visibility":
                {
                    var op = pipeline.CreateOperator<ScenegraphVisibilityOperator>();
                    BindNamedOrSequentialOperator(op, tensors, opSpec, inputs, outputs);
                    break;
                }
                case "update_component":
                {
                    var op = pipeline.CreateOperator<UpdateComponentOperator>(new UpdateComponentOperatorConfiguration(
                        GetString(opSpec, "entity_path"), GetString(opSpec, "target_property_path")));
                    BindNamedOrSequentialOperator(op, tensors, opSpec, inputs, outputs);
                    break;
                }
                case "microphone":
                {
                    var op = pipeline.CreateOperator<MicrophoneOperator>(new MicrophoneOperatorConfiguration(
                        GetInt(opSpec, "sample_rate", 16000), GetString(opSpec, "pcm_type", "int16")));
                    BindNamedOrSequentialOperator(op, tensors, opSpec, inputs, outputs);
                    break;
                }
                case "speaker":
                {
                    var op = pipeline.CreateOperator<SpeakerOperator>(
                        new SpeakerOperatorConfiguration(GetInt(opSpec, "sample_rate", 16000)));
                    BindNamedOrSequentialOperator(op, tensors, opSpec, inputs, outputs);
                    break;
                }
                case "depth":
                {
                    var op = pipeline.CreateOperator<DepthOperator>();
                    BindNamedOrSequentialOperator(op, tensors, opSpec, inputs, outputs);
                    break;
                }
                default: throw new NotSupportedException($"Unsupported SpatialML pipeline operator '{type}'.");
            }
        }

        private static Tensor CreatePointTensor(Pipeline pipeline, Dictionary<string, object> opSpec, string key)
        {
            var values = ReadFloatArray(GetValue(opSpec, key));
            if (values == null || values.Length == 0) throw new InvalidOperationException($"get_affine requires '{key}'.");
            return pipeline.CreateTensor<float, Point>(2, new TensorShape(values.Length / 2), values);
        }

        private static Operator CreateElementwiseOperator(Pipeline pipeline, string opName)
        {
            if (opName == "min") return pipeline.CreateOperator<ElementwiseMinOperator>();
            if (opName == "max") return pipeline.CreateOperator<ElementwiseMaxOperator>();
            if (opName == "or") return pipeline.CreateOperator<ElementwiseOrOperator>();
            if (opName == "and") return pipeline.CreateOperator<ElementwiseAndOperator>();
            return pipeline.CreateOperator<ElementwiseMultiplyOperator>();
        }

        private static void BindUnaryOperator(Operator op, Dictionary<string, Tensor> tensors, List<string> inputs,
            List<string> outputs, string inputName = "src", string outputName = "dst")
        {
            if (inputs.Count > 0) op.SetOperand(inputName, Resolve(inputs[0], tensors).tensor);
            if (outputs.Count > 0) op.SetResult(outputName, Resolve(outputs[0], tensors).tensor);
        }

        private static void BindOptionalOperand(
            Operator op,
            Dictionary<string, Tensor> tensors,
            Dictionary<string, object> opSpec,
            List<string> inputs,
            string operandName,
            string propertyName,
            int inputIndex)
        {
            var tensorName = GetTensorName(opSpec, inputs, propertyName, inputIndex);
            if (!string.IsNullOrEmpty(tensorName))
                op.SetOperand(operandName, Resolve(tensorName, tensors).tensor);
        }

        private static void BindNamedOrSequentialOperator(Operator op, Dictionary<string, Tensor> tensors,
            Dictionary<string, object> opSpec, List<string> inputs, List<string> outputs)
        {
            var inputsValue = GetValue(opSpec, "inputs");
            var outputsValue = GetValue(opSpec, "outputs");
            var hasNamedInputs = HasNamedTensorMappings(inputsValue);
            var hasNamedOutputs = HasNamedTensorMappings(outputsValue);

            if (hasNamedInputs)
            {
                foreach (var pair in ReadMappedTensorList(inputsValue)) op.SetOperand(pair.alias, Resolve(pair.tensor, tensors).tensor);
            }
            else
            {
                for (var i = 0; i < inputs.Count; i++) op.SetOperand($"operand{i}", Resolve(inputs[i], tensors).tensor);
            }

            if (hasNamedOutputs)
            {
                foreach (var pair in ReadMappedTensorList(outputsValue)) op.SetResult(pair.alias, Resolve(pair.tensor, tensors).tensor);
            }
            else
            {
                for (var i = 0; i < outputs.Count; i++) op.SetResult($"result{i}", Resolve(outputs[i], tensors).tensor);
            }
        }

        private static void CreateModelOperator(
            SpatialMLPipelineZooAsset packageAsset,
            Pipeline pipeline,
            Dictionary<string, Tensor> tensors,
            Dictionary<string, object> opSpec)
        {
            var modelSpec = ReadInlineModelSpec(opSpec);
            var data = packageAsset.FindBinaryBytes(modelSpec.BinPath);
            if (data == null) throw new InvalidOperationException($"Model binary '{modelSpec.BinPath}' was not found in package asset.");

            var config = new ModelOperatorConfiguration(data, ParseModelType(modelSpec.ModelType), SanitizeModelName(modelSpec.ModelName),
                new LiteRtModelConfiguration(ParseModelTarget(modelSpec.ModelTarget), modelSpec.CpuTargetNumThreads));

            var inputsValue = GetValue(opSpec, "inputs");
            var outputsValue = GetValue(opSpec, "outputs");
            var mappedInputs = ReadMappedTensorList(inputsValue);
            var mappedOutputs = ReadMappedTensorList(outputsValue);
            var sequentialInputs = ReadTensorList(inputsValue);
            var sequentialOutputs = ReadTensorList(outputsValue);
            var hasNamedInputs = HasNamedTensorMappings(inputsValue);
            var hasNamedOutputs = HasNamedTensorMappings(outputsValue);

            var op = pipeline.CreateOperator<RunModelInferenceOperator>(config);

            if (hasNamedInputs)
            {
                foreach (var pair in mappedInputs) op.SetOperand(pair.alias, Resolve(pair.tensor, tensors).tensor);
            }
            else
            {
                for (var i = 0; i < sequentialInputs.Count; i++) op.SetOperand($"operand{i}", Resolve(sequentialInputs[i], tensors).tensor);
            }

            if (hasNamedOutputs)
            {
                foreach (var pair in mappedOutputs) op.SetResult(pair.alias, Resolve(pair.tensor, tensors).tensor);
            }
            else
            {
                for (var i = 0; i < sequentialOutputs.Count; i++) op.SetResult($"result{i}", Resolve(sequentialOutputs[i], tensors).tensor);
            }
        }

        private static ModelSpec ReadInlineModelSpec(Dictionary<string, object> opSpec)
        {
            var modelInfo = GetObject(opSpec, "model");
            if (modelInfo == null)
                throw new InvalidOperationException(
                    "RunModelInference operator requires inline model metadata under 'model'.");

            return new ModelSpec
            {
                BinPath = GetString(modelInfo, "bin_path"),
                ModelName = GetString(modelInfo, "model_name"),
                ModelType = GetString(modelInfo, "model_type"),
                ModelTarget = GetString(modelInfo, "model_target"),
                CpuTargetNumThreads = GetInt(modelInfo, "cpu_target_num_threads", 0)
            };
        }

        private static void CreateAssignment(Pipeline pipeline, Dictionary<string, Tensor> tensors, string input, string output)
        {
            var src = Resolve(input, tensors);
            var dst = Resolve(output, tensors);
            var op = pipeline.CreateOperator<AssignmentOperator>();
            op.SetOperand("src", src.tensor);
            if (src.slices != null) op.SetOperand("src slices", CreateSliceTensor(pipeline, src.slices));
            if (dst.slices != null) op.SetOperand("dst slices", CreateSliceTensor(pipeline, dst.slices));
            op.SetResult("dst", dst.tensor);
        }

        private static Tensor CreateSliceTensor(Pipeline pipeline, int[] slices)
        {
            var rank = Math.Max(1, slices.Length / 2);
            return pipeline.CreateTensor<int, Slice>(2, new TensorShape(new[] { rank }), slices);
        }

        private static (Tensor tensor, int[] slices) Resolve(string expression, Dictionary<string, Tensor> tensors)
        {
            var open = expression.IndexOf('[');
            if (open < 0) return (tensors[expression], null);
            var name = expression.Substring(0, open).Trim();
            var inside = expression.Substring(open + 1, expression.LastIndexOf(']') - open - 1);
            var values = new List<int>();
            foreach (var part in inside.Split(','))
            {
                var range = part.Trim().Split(':');
                if (range.Length == 1)
                {
                    var index = int.Parse(range[0], CultureInfo.InvariantCulture);
                    values.Add(index);
                    values.Add(index + 1);
                }
                else
                {
                    values.Add(int.Parse(range[0], CultureInfo.InvariantCulture));
                    values.Add(int.Parse(range[1], CultureInfo.InvariantCulture));
                }
            }
            return (tensors[name], values.ToArray());
        }

        private static void BindPackageGltfAssets(Provider provider, SpatialMLPipelineZooAsset packageAsset, Dictionary<string, object> pipelineSpec, SpatialMLPipelineZooBundle bundle, SpatialMLPipelineZooPipeline pipeline)
        {
            foreach (var pair in GetObject(pipelineSpec, "tensors"))
            {
                var spec = pair.Value as Dictionary<string, object>;
                if (spec == null) continue;
                var tensorType = GetString(spec, "tensor_type");
                if (string.IsNullOrEmpty(tensorType)) tensorType = GetString(spec, "type");
                if (!GetBool(spec, "is_gltf") &&
                    !tensorType.Equals("gltf", StringComparison.OrdinalIgnoreCase)) continue;
                if (!bundle.GlobalTensors.TryGetValue(pair.Key, out var global))
                {
                    var bytes = packageAsset.FindBinaryBytes(GetString(spec, "asset"));
                    if (bytes == null) throw new InvalidOperationException($"glTF asset '{GetString(spec, "asset")}' was not found in package asset.");
                    global = provider.CreateTensor<Gltf>(bytes);
                    bundle.GlobalTensors[pair.Key] = global;
                }
                pipeline.SubmitBindings[pair.Key] = global;
            }
        }

        private static void EnsureSharedBinding(Provider provider, SpatialMLPipelineZooBundle bundle, SpatialMLPipelineZooPipeline pipeline, string tensorName)
        {
            if (!pipeline.Tensors.TryGetValue(tensorName, out var local) || !local.PlaceHolder) return;
            if (!bundle.GlobalTensors.TryGetValue(tensorName, out var global))
            {
                global = CreateGlobalLike(provider, local);
                bundle.GlobalTensors[tensorName] = global;
            }
            pipeline.SubmitBindings[tensorName] = global;
        }

        private static IEnumerable<(string id, string path)> ReadPipelineSpecs(Dictionary<string, object> manifest)
        {
            if (GetValue(manifest, "pipelines") is List<object> list)
            {
                foreach (var item in list.OfType<Dictionary<string, object>>()) yield return (GetString(item, "id"), GetString(item, "path"));
            }
        }

        private static List<string> ReadTensorList(object value)
        {
            var output = new List<string>();
            if (!(value is List<object> list)) return output;
            foreach (var item in list)
            {
                if (item is string s) output.Add(s);
                else if (item is Dictionary<string, object> o) output.Add(GetString(o, "tensor"));
            }
            return output.Where(s => !string.IsNullOrEmpty(s)).ToList();
        }

        private static List<(string alias, string tensor)> ReadMappedTensorList(object value)
        {
            var output = new List<(string alias, string tensor)>();
            if (!(value is List<object> list)) return output;
            foreach (var item in list)
            {
                if (item is string s) output.Add((s, s));
                else if (item is Dictionary<string, object> o)
                {
                    var tensor = GetString(o, "tensor");
                    output.Add((GetString(o, "name", tensor), tensor));
                }
            }
            return output.Where(p => !string.IsNullOrEmpty(p.tensor)).ToList();
        }

        private static bool HasNamedTensorMappings(object value)
        {
            return value is List<object> list && list.Any(item => item is Dictionary<string, object>);
        }

        private static T[] ReadArray<T>(Dictionary<string, object> spec) where T : struct
        {
            var value = GetValue(spec, "data") ?? GetValue(spec, "value");
            if (!(value is List<object> list)) return null;
            var result = new T[list.Count];
            for (var i = 0; i < list.Count; i++) result[i] = (T)Convert.ChangeType(list[i], typeof(T), CultureInfo.InvariantCulture);
            return result;
        }

        private static int[] ReadDimensions(Dictionary<string, object> spec, string tensorType)
        {
            if (GetValue(spec, "dimensions") is List<object> dims) return dims.Select(v => Convert.ToInt32(v, CultureInfo.InvariantCulture)).ToArray();
            return new[] { GetInt(spec, "size", 1) };
        }

        private static int DefaultChannels(string tensorType)
        {
            if (tensorType == "point2_array") return 2;
            if (tensorType == "point3_array") return 3;
            if (tensorType == "rgba_array") return 4;
            return 1;
        }

        private static SecureMRTensorUsage ParseUsage(Dictionary<string, object> spec, string tensorType)
        {
            if (tensorType == "scalar_array") return SecureMRTensorUsage.Scalar;
            if (tensorType == "point2_array" || tensorType == "point3_array") return SecureMRTensorUsage.Point;
            if (tensorType == "rgba_array") return SecureMRTensorUsage.Color;
            if (tensorType == "timestamp") return SecureMRTensorUsage.TimeStamp;
            if (tensorType == "dynamic_texture" || tensorType == "dynamic_texture_byte" || tensorType == "dynamic_texture_float")
            {
                return SecureMRTensorUsage.DynamicTexture;
            }
            var usage = GetInt(spec, "usage", (int)SecureMRTensorUsage.Matrix);
            return Enum.IsDefined(typeof(SecureMRTensorUsage), usage) ? (SecureMRTensorUsage)usage : SecureMRTensorUsage.Matrix;
        }

        private static SecureMRTensorDataType ParseDataType(object value, SecureMRTensorDataType fallback)
        {
            if (value == null) return fallback;
            if (value is string s)
            {
                s = s.ToLowerInvariant();
                if (s == "uint8") return SecureMRTensorDataType.Byte;
                if (s == "int8") return SecureMRTensorDataType.Sbyte;
                if (s == "uint16") return SecureMRTensorDataType.Ushort;
                if (s == "int16") return SecureMRTensorDataType.Short;
                if (s == "int32") return SecureMRTensorDataType.Int;
                if (s == "float32" || s == "fp32") return SecureMRTensorDataType.Float;
                if (s == "float64" || s == "double") return SecureMRTensorDataType.Double;
                if (s == "dynamic_texture_byte") return SecureMRTensorDataType.DynamicTextureByte;
                if (s == "dynamic_texture_float") return SecureMRTensorDataType.DynamicTextureFloat;
            }
            return (SecureMRTensorDataType)Convert.ToInt32(value, CultureInfo.InvariantCulture);
        }

        private static float[] ReadFloatArray(object value)
        {
            if (!(value is List<object> list)) return null;
            var result = new float[list.Count];
            for (var i = 0; i < list.Count; i++) result[i] = Convert.ToSingle(list[i], CultureInfo.InvariantCulture);
            return result;
        }

        private static string GetTensorName(Dictionary<string, object> opSpec, List<string> tensors, string key, int index)
        {
            var fieldValue = GetString(opSpec, key);
            if (!string.IsNullOrEmpty(fieldValue)) return fieldValue;
            if (index >= 0 && index < tensors.Count) return tensors[index];
            return string.Empty;
        }

        private static int ParseInt(string value, int fallback)
        {
            return int.TryParse(value, NumberStyles.Integer, CultureInfo.InvariantCulture, out var parsed)
                ? parsed
                : fallback;
        }

        private static SecureMRComparison ParseComparison(string value)
        {
            if (value == ">") return SecureMRComparison.LargerThan;
            if (value == "<") return SecureMRComparison.SmallerThan;
            if (value == ">=") return SecureMRComparison.LargerOrEqual;
            if (value == "<=") return SecureMRComparison.SmallerOrEqual;
            if (value == "==") return SecureMRComparison.EqualTo;
            if (value == "!=") return SecureMRComparison.NotEqual;
            return SecureMRComparison.LargerThan;
        }

        private static SecureMRModelType ParseModelType(string value)
        {
            var normalized = value?.ToLowerInvariant() ?? string.Empty;
            if (normalized.Contains("litert") || normalized.Contains("tflite"))
            {
                return SecureMRModelType.LiteRtModel;
            }

            var message =
                $"RunModelInferenceOperator only supports TFLite/LiteRT models. " +
                $"QNN context binaries and other model types are no longer supported. Provided model type: {value}.";
            Debug.LogError(message);
            throw new InvalidOperationException(message);
        }

        private static SecureMRModelTarget ParseModelTarget(string value) => value.ToLowerInvariant() == "cpu" ? SecureMRModelTarget.Cpu : value.ToLowerInvariant() == "gpu" ? SecureMRModelTarget.Gpu : SecureMRModelTarget.Npu;
        private static SecureMRFontTypeface ParseTypeface(string value) => value.ToLowerInvariant() == "sans_serif" ? SecureMRFontTypeface.SansSerif : SecureMRFontTypeface.Default;

        private static SecureMRNormalizeType ParseNormalizeType(string value)
        {
            value = value.ToLowerInvariant();
            if (value == "l1") return SecureMRNormalizeType.L1;
            if (value == "inf") return SecureMRNormalizeType.Inf;
            if (value == "min_max" || value == "minmax") return SecureMRNormalizeType.MinMax;
            return SecureMRNormalizeType.L2;
        }

        private static SecureMRMatrixSortType ParseMatrixSortType(string value)
        {
            value = value.ToLowerInvariant();
            return value == "column" || value == "col"
                ? SecureMRMatrixSortType.Column
                : SecureMRMatrixSortType.Row;
        }

        private static SecureMRGltfOperatorAttribute ParseGltfAttribute(string value)
        {
            value = value.ToLowerInvariant();
            if (value == "texture") return SecureMRGltfOperatorAttribute.Texture;
            if (value == "animation") return SecureMRGltfOperatorAttribute.Animation;
            if (value == "world_pose") return SecureMRGltfOperatorAttribute.WorldPose;
            if (value == "local_transform") return SecureMRGltfOperatorAttribute.LocalTransform;
            if (value == "material_metallic_factor") return SecureMRGltfOperatorAttribute.MaterialMetallicFactor;
            if (value == "material_roughness_factor") return SecureMRGltfOperatorAttribute.MaterialRoughnessFactor;
            if (value == "material_occlusion_map_texture") return SecureMRGltfOperatorAttribute.MaterialOcclusionMapTexture;
            if (value == "material_base_color_factor") return SecureMRGltfOperatorAttribute.MaterialBaseColorFactor;
            if (value == "material_emissive_factor") return SecureMRGltfOperatorAttribute.MaterialEmissiveFactor;
            if (value == "material_emissive_strength") return SecureMRGltfOperatorAttribute.MaterialEmissiveStrength;
            if (value == "material_emissive_texture") return SecureMRGltfOperatorAttribute.MaterialEmissiveTexture;
            if (value == "material_normal_map_texture") return SecureMRGltfOperatorAttribute.MaterialNormalMapTexture;
            if (value == "material_metallic_roughness_texture") return SecureMRGltfOperatorAttribute.MaterialMetallicRoughnessTexture;
            return SecureMRGltfOperatorAttribute.MaterialBaseColorTexture;
        }

        private static string FormatOperatorType(string type)
        {
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_RECTIFIED_VST_ACCESS_PICO") return "camera_access";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_GET_AFFINE_PICO") return "get_affine";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_APPLY_AFFINE_PICO") return "apply_affine";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_APPLY_AFFINE_POINT_PICO") return "apply_affine_point";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_CONVERT_COLOR_PICO") return "cvt_color";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_ASSIGNMENT_PICO") return "assignment";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_ARITHMETIC_COMPOSE_PICO") return "arithmetic";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_ELEMENTWISE_MIN_PICO") return "elementwise_min";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_ELEMENTWISE_MAX_PICO") return "elementwise_max";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_ELEMENTWISE_MULTIPLY_PICO") return "elementwise_multiply";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_ELEMENTWISE_OR_PICO") return "elementwise_or";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_ELEMENTWISE_AND_PICO") return "elementwise_and";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_ALL_PICO") return "all";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_ANY_PICO") return "any";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_RUN_MODEL_INFERENCE_PICO") return "run_algorithm";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_JAVASCRIPT_PICO") return "javascript";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_NORMALIZE_PICO") return "normalize";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_UV_TO_3D_IN_CAM_SPACE_PICO") return "uv2_cam";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_UV_TO_3D_IN_CAMERA_SPACE_PICO") return "uv2_cam";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_CAMERA_SPACE_TO_WORLD_PICO") return "cam_space_to_xr_local";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_GET_TRANSFORM_MAT_PICO") return "transform";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_GET_TRANSFORM_MATRIX_PICO") return "transform";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_CUSTOMIZED_COMPARE_PICO") return "compare_to";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_ARGMAX_PICO") return "argmax";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_SORT_VECTOR_PICO") return "sort_vector";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_SORT_VEC_PICO") return "sort_vector";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_INVERSION_PICO") return "inversion";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_SORT_MATRIX_PICO") return "sort_matrix";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_SORT_MAT_PICO") return "sort_matrix";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_LOAD_TEXTURE_PICO") return "load_texture";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_UPDATE_GLTF_PICO") return "update_gltf";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_RENDER_TEXT_PICO") return "draw_text";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_SWITCH_GLTF_RENDER_STATUS_PICO") return "render_gltf";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_SCENEGRAPH_VISIBILITY_PICO") return "scenegraph_visibility";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_UPDATE_COMPONENT_PICO") return "update_component";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_MICROPHONE_PICO") return "microphone";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_SPEAKER_PICO") return "speaker";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_DEPTH_PICO") return "depth";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_SWAP_HWC_CHW_PICO") return "swap_hwc_chw";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_NMS_PICO") return "nms";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_NON_MAXIMUM_SUPPRESSION_PICO") return "nms";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_SOLVE_PNP_PICO" ||
                type == "XR_SECURE_MR_OPERATOR_TYPE_SOLVE_P_N_P_PICO") return "solve_pnp";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_SVD_PICO") return "svd";
            if (type == "XR_SECURE_MR_OPERATOR_TYPE_NORM_PICO") return "norm";
            if (type == "JS_SCRIPTING") return "javascript";
            if (type == "MAKE_TRANSFORM_MAT") return "transform";
            var normalized = type.ToLowerInvariant();
            if (normalized == "camera_space_to_world") return "cam_space_to_xr_local";
            if (normalized == "uv_to_3d_in_cam_space" ||
                normalized == "uv_to_3d_in_camera_space") return "uv2_cam";
            if (normalized == "customized_compare") return "compare_to";
            if (normalized == "solve_p_n_p") return "solve_pnp";
            if (normalized == "sort_vec") return "sort_vector";
            if (normalized == "sort_mat") return "sort_matrix";
            if (normalized == "get_transform_mat" ||
                normalized == "get_transform_matrix") return "transform";
            if (normalized == "switch_gltf_render_status") return "render_gltf";
            if (normalized == "render_text") return "draw_text";
            if (normalized == "run_model_inference") return "run_algorithm";
            return normalized;
        }

        private static string SanitizeModelName(string value) => string.IsNullOrEmpty(value) ? value : value.Replace('-', '_').Replace('.', '_').Replace(' ', '_');
        private static string GetStringOrAttr(
            Dictionary<string, object> obj,
            string key,
            string fallback = "")
        {
            var value = GetString(obj, key);
            if (!string.IsNullOrEmpty(value)) return value;
            return GetAttr(obj, 0)?.ToString() ?? fallback;
        }

        private static int GetIntOrAttr(Dictionary<string, object> obj, string key, int fallback)
        {
            var value = GetValue(obj, key) ?? GetAttr(obj, 0);
            return value == null ? fallback : Convert.ToInt32(value, CultureInfo.InvariantCulture);
        }

        private static float GetFloatOrAttr(Dictionary<string, object> obj, string key, float fallback)
        {
            var value = GetValue(obj, key) ?? GetAttr(obj, 0);
            return value == null ? fallback : Convert.ToSingle(value, CultureInfo.InvariantCulture);
        }

        private static object GetAttr(Dictionary<string, object> obj, int index)
        {
            var attrs = GetList(obj, "attrs");
            return attrs != null && index >= 0 && index < attrs.Count ? attrs[index] : null;
        }

        private static object GetValue(Dictionary<string, object> obj, string key) => obj != null && obj.TryGetValue(key, out var value) ? value : null;
        private static Dictionary<string, object> GetObject(Dictionary<string, object> obj, string key) => GetValue(obj, key) as Dictionary<string, object>;
        private static List<object> GetList(Dictionary<string, object> obj, string key) => GetValue(obj, key) as List<object>;
        private static string GetString(Dictionary<string, object> obj, string key, string fallback = "") => GetValue(obj, key)?.ToString() ?? fallback;
        private static int GetInt(Dictionary<string, object> obj, string key, int fallback = 0) => GetValue(obj, key) == null ? fallback : Convert.ToInt32(GetValue(obj, key), CultureInfo.InvariantCulture);
        private static bool GetBool(Dictionary<string, object> obj, string key) => GetValue(obj, key) is bool b && b;

        private sealed class ModelSpec
        {
            public string BinPath;
            public string ModelName;
            public string ModelType;
            public string ModelTarget;
            public int CpuTargetNumThreads;
        }

        private static class MiniJson
        {
            public static Dictionary<string, object> ParseObject(string json) => Parse(json) as Dictionary<string, object>;
            private static object Parse(string json) => new Parser(json).ParseValue();

            private sealed class Parser
            {
                private readonly string json;
                private int index;
                public Parser(string json) { this.json = json; }
                public object ParseValue()
                {
                    Skip();
                    if (index >= json.Length) return null;
                    var c = json[index];
                    if (c == '{') return ParseObjectInternal();
                    if (c == '[') return ParseArray();
                    if (c == '"') return ParseString();
                    if (char.IsDigit(c) || c == '-') return ParseNumber();
                    if (Match("true")) return true;
                    if (Match("false")) return false;
                    if (Match("null")) return null;
                    throw new FormatException($"Unexpected JSON token at {index}");
                }
                private Dictionary<string, object> ParseObjectInternal()
                {
                    var obj = new Dictionary<string, object>();
                    index++; Skip();
                    while (index < json.Length && json[index] != '}')
                    {
                        var key = ParseString(); Skip(); index++; obj[key] = ParseValue(); Skip();
                        if (json[index] == ',') { index++; Skip(); }
                    }
                    index++; return obj;
                }
                private List<object> ParseArray()
                {
                    var list = new List<object>();
                    index++; Skip();
                    while (index < json.Length && json[index] != ']')
                    {
                        list.Add(ParseValue()); Skip();
                        if (json[index] == ',') { index++; Skip(); }
                    }
                    index++; return list;
                }
                private string ParseString()
                {
                    index++;
                    var s = new System.Text.StringBuilder();
                    while (index < json.Length && json[index] != '"')
                    {
                        if (json[index] == '\\')
                        {
                            index++;
                            if (json[index] == 'n') s.Append('\n'); else if (json[index] == 'r') s.Append('\r'); else if (json[index] == 't') s.Append('\t'); else s.Append(json[index]);
                        }
                        else s.Append(json[index]);
                        index++;
                    }
                    index++; return s.ToString();
                }
                private object ParseNumber()
                {
                    var start = index;
                    while (index < json.Length && "-+0123456789.eE".IndexOf(json[index]) >= 0) index++;
                    var text = json.Substring(start, index - start);
                    if (text.IndexOfAny(new[] { '.', 'e', 'E' }) >= 0) return double.Parse(text, CultureInfo.InvariantCulture);
                    return long.Parse(text, CultureInfo.InvariantCulture);
                }
                private bool Match(string token)
                {
                    if (string.CompareOrdinal(json, index, token, 0, token.Length) != 0) return false;
                    index += token.Length; return true;
                }
                private void Skip() { while (index < json.Length && char.IsWhiteSpace(json[index])) index++; }
            }
        }
    }
}
#endif
