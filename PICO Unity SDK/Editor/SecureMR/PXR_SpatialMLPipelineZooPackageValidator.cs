#if UNITY_EDITOR && !ENABLE_PICO_OPENXR_SDK
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using LitJson;

namespace ByteDance.PICO.SecureMR.Editor
{
    internal static class SpatialMLPipelineZooPackageValidator
    {
        private static readonly HashSet<string> AllowedModes =
            new HashSet<string>(new[] { "xr", "spatial" }, StringComparer.Ordinal);
        private static readonly HashSet<string> XrOnlyOperators =
            new HashSet<string>(new[]
            {
                "LOAD_TEXTURE", "RENDER_TEXT", "SWITCH_GLTF_RENDER_STATUS", "UPDATE_GLTF"
            }, StringComparer.Ordinal);
        private static readonly HashSet<string> SpatialOnlyOperators =
            new HashSet<string>(new[] { "SCENEGRAPH_VISIBILITY", "UPDATE_COMPONENT" }, StringComparer.Ordinal);
        private static readonly HashSet<string> GltfReferenceKeys =
            new HashSet<string>(new[]
            {
                "asset", "asset_path", "gltf", "gltf_path", "gltf_asset", "scene", "scene_path"
            }, StringComparer.OrdinalIgnoreCase);

        internal sealed class ValidatedPackage
        {
            internal string PackageId;
            internal readonly List<PipelineEntry> Pipelines = new List<PipelineEntry>();
            internal readonly List<PackageFile> Files = new List<PackageFile>();
            internal readonly HashSet<string> ReferencedBinaryPaths =
                new HashSet<string>(StringComparer.Ordinal);
        }

        internal sealed class PipelineEntry
        {
            internal string Id;
            internal string Path;
        }

        internal sealed class PackageFile
        {
            internal string SourcePath;
            internal string PackagePath;
            internal bool IsBinary;
        }

        internal static ValidatedPackage Validate(string packageFolder)
        {
            if (string.IsNullOrWhiteSpace(packageFolder))
                throw new ArgumentException("SpatialML package folder is required.", nameof(packageFolder));

            var packageRoot = Path.GetFullPath(packageFolder);
            if (!Directory.Exists(packageRoot))
                throw new DirectoryNotFoundException($"SpatialML package folder was not found: {packageRoot}");

            var manifestPath = Path.Combine(packageRoot, "manifest.json");
            if (!File.Exists(manifestPath))
                throw new FileNotFoundException("SpatialML package folder must contain manifest.json", packageRoot);

            var result = new ValidatedPackage();
            foreach (var file in Directory.GetFiles(packageRoot, "*", SearchOption.AllDirectories)
                         .OrderBy(path => path, StringComparer.Ordinal))
            {
                if (ShouldSkip(file)) continue;
                var relativePath = NormalizePackagePath(Path.GetRelativePath(packageRoot, file), "package file");
                EnsurePathUnderRoot(file, packageRoot, $"Package file escapes package root: '{relativePath}'.");
                result.Files.Add(new PackageFile
                {
                    SourcePath = file,
                    PackagePath = relativePath,
                    IsBinary = NeedsBytesExtension(relativePath)
                });
            }

            var manifest = ReadJsonObject(manifestPath, "manifest.json");
            if (!TryGet(manifest, "schema_version", out var version) ||
                !version.IsString || (string)version != "2")
                throw new InvalidDataException("SpatialML manifest schema_version must be the string \"2\".");

            result.PackageId = RequireString(manifest, "id", "SpatialML manifest");
            if (manifest.ContainsKey("model") || manifest.ContainsKey("models"))
                throw new InvalidDataException(
                    "SpatialML schema version 2 does not allow manifest-level 'model' or 'models' entries.");

            var supportedModes = ReadSupportedModes(manifest);
            var pipelines = RequireArray(manifest, "pipelines", "SpatialML manifest");
            if (pipelines.Count == 0)
                throw new InvalidDataException("SpatialML manifest requires a non-empty 'pipelines' list.");

            var ids = new HashSet<string>(StringComparer.Ordinal);
            var xrOnlyUses = new List<string>();
            var spatialOnlyUses = new List<string>();
            for (var index = 0; index < pipelines.Count; index++)
            {
                var entry = RequireObject(pipelines[index], $"SpatialML manifest pipeline #{index}");
                var id = RequireString(entry, "id", $"SpatialML manifest pipeline #{index}");
                if (!ids.Add(id)) throw new InvalidDataException($"Duplicate SpatialML pipeline id: {id}");
                var path = NormalizePackagePath(
                    RequireString(entry, "path", $"SpatialML manifest pipeline '{id}'"),
                    $"pipeline '{id}' path");
                var pipelinePath = ResolveRequiredFile(
                    packageRoot, path, $"Manifest references missing pipeline: {path}");
                var pipeline = ReadJsonObject(pipelinePath, $"pipeline '{id}'");
                ValidatePipeline(packageRoot, id, pipeline, result, xrOnlyUses, spatialOnlyUses);
                result.Pipelines.Add(new PipelineEntry { Id = id, Path = path });
            }

            ValidateModes(supportedModes, xrOnlyUses, spatialOnlyUses);
            return result;
        }

        private static HashSet<string> ReadSupportedModes(JsonData manifest)
        {
            var modes = new HashSet<string>(StringComparer.Ordinal);
            if (!TryGet(manifest, "runtime", out var runtime)) return modes;
            if (runtime == null || !runtime.IsObject)
                throw new InvalidDataException("SpatialML manifest 'runtime' must be an object when present.");
            if (!TryGet(runtime, "supported_modes", out var supportedModes)) return modes;
            if (supportedModes == null || !supportedModes.IsArray)
                throw new InvalidDataException("SpatialML manifest runtime.supported_modes must be an array.");
            for (var index = 0; index < supportedModes.Count; index++)
            {
                var value = supportedModes[index];
                if (value == null || !value.IsString)
                    throw new InvalidDataException(
                        "SpatialML manifest runtime.supported_modes may contain only 'xr' and 'spatial'.");
                var mode = ((string)value).Trim().ToLowerInvariant();
                if (!AllowedModes.Contains(mode))
                    throw new InvalidDataException(
                        $"Unsupported SpatialML execution mode '{value}'. Expected 'xr' or 'spatial'.");
                modes.Add(mode);
            }
            return modes;
        }

        private static void ValidatePipeline(
            string packageRoot,
            string pipelineId,
            JsonData pipeline,
            ValidatedPackage result,
            ICollection<string> xrOnlyUses,
            ICollection<string> spatialOnlyUses)
        {
            var tensors = RequireObjectProperty(pipeline, "tensors", $"Pipeline '{pipelineId}'");
            foreach (var tensorName in tensors.Keys)
            {
                var tensor = RequireObject(tensors[tensorName], $"Tensor '{tensorName}' in pipeline '{pipelineId}'");
                ValidateTensorDescriptor(pipelineId, tensorName, tensor);
                ValidateMatrixDimensions(tensorName, tensor);
                if (IsGltfTensor(tensor) && TryGetString(tensor, "asset", out var asset))
                    ValidateAsset(packageRoot, asset, $"Tensor '{tensorName}'", result);
            }

            var operators = RequireArray(pipeline, "operators", $"Pipeline '{pipelineId}'");
            ValidateTensorReferences(pipeline, "inputs", tensors, $"Pipeline '{pipelineId}'");
            ValidateTensorReferences(pipeline, "outputs", tensors, $"Pipeline '{pipelineId}'");
            for (var index = 0; index < operators.Count; index++)
            {
                var context = $"Operator #{index} in pipeline '{pipelineId}'";
                var op = RequireObject(operators[index], context);
                var type = NormalizeOperatorType(RequireString(op, "type", context));
                ValidateTensorReferences(op, "inputs", tensors, context);
                ValidateTensorReferences(op, "outputs", tensors, context);
                if (XrOnlyOperators.Contains(type)) xrOnlyUses.Add($"{pipelineId}:{type}");
                if (SpatialOnlyOperators.Contains(type)) spatialOnlyUses.Add($"{pipelineId}:{type}");
                if (type == "RUN_MODEL_INFERENCE") ValidateInlineModel(packageRoot, op, context, result);
                if (type == "SWAP_HWC_CHW") ValidateSwapHwcChw(op, tensors, context);

                foreach (var key in op.Keys)
                {
                    if (!GltfReferenceKeys.Contains(key) ||
                        !TryGetString(op, key, out var assetOrTensor)) continue;

                    // Older operator spellings store the GLTF tensor name in fields such as
                    // "gltf". The tensor descriptor owns the package-relative asset path.
                    if (!tensors.ContainsKey(ReadTensorName(op[key])))
                        ValidateAsset(packageRoot, assetOrTensor, context, result);
                }
            }
        }

        private static void ValidateTensorDescriptor(string pipelineId, string name, JsonData tensor)
        {
            if (IsGltfTensor(tensor)) return;

            var tensorType = string.Empty;
            if (TryGetString(tensor, "tensor_type", out var value) || TryGetString(tensor, "type", out value))
                tensorType = value.Trim().ToLowerInvariant();

            if (tensorType == "timestamp") return;
            if (tensorType == "scalar_array" || tensorType == "point2_array" ||
                tensorType == "point3_array" || tensorType == "rgba_array")
            {
                if (GetInt(tensor, "size", 0) <= 0 && ReadIntegerArray(tensor, "dimensions").Count == 0)
                    throw new InvalidDataException(
                        $"Pipeline '{pipelineId}' tensor '{name}' must have a positive size.");
                return;
            }
            if (!string.IsNullOrEmpty(tensorType) && tensorType != "matrix" && tensorType != "mat")
                throw new InvalidDataException(
                    $"Pipeline '{pipelineId}' tensor '{name}' has unsupported tensor_type '{tensorType}'.");

            var dimensions = ReadIntegerArray(tensor, "dimensions");
            if (dimensions.Count == 0 || dimensions.Any(dimension => dimension <= 0))
                throw new InvalidDataException(
                    $"Pipeline '{pipelineId}' tensor '{name}' dimensions must contain positive integers.");
            if (GetInt(tensor, "channels", 1) <= 0)
                throw new InvalidDataException(
                    $"Pipeline '{pipelineId}' tensor '{name}' channels must be positive.");
        }

        private static void ValidateTensorReferences(
            JsonData op, string key, JsonData tensors, string context)
        {
            if (!TryGet(op, key, out var references)) return;
            if (references == null || !references.IsArray)
                throw new InvalidDataException($"{context} '{key}' must be an array.");
            for (var index = 0; index < references.Count; index++)
            {
                var name = ReadTensorName(references[index]);
                if (string.IsNullOrWhiteSpace(name))
                    throw new InvalidDataException($"{context} {key}[{index}] is not a valid tensor reference.");
                if (!tensors.ContainsKey(name))
                    throw new InvalidDataException($"{context} {key} tensor '{name}' was not declared.");
            }
        }

        private static void ValidateInlineModel(
            string packageRoot, JsonData op, string context, ValidatedPackage result)
        {
            foreach (var legacyKey in new[] { "model_id", "model_asset", "model_file", "model_path", "bin_path" })
            {
                if (op.ContainsKey(legacyKey))
                    throw new InvalidDataException(
                        $"{context} uses legacy '{legacyKey}'. Schema version 2 requires inline model metadata.");
            }

            if (!TryGet(op, "model", out var model) || model == null || !model.IsObject)
                throw new InvalidDataException($"{context} requires an inline 'model' object.");

            var binPath = RequireString(model, "bin_path", $"{context} model");
            RequireString(model, "model_name", $"{context} model");
            if (RequireString(model, "model_type", $"{context} model") != "tflite")
                throw new InvalidDataException($"{context} model_type must be 'tflite'.");
            var target = RequireString(model, "model_target", $"{context} model").ToLowerInvariant();
            if (target != "npu" && target != "cpu" && target != "gpu")
                throw new InvalidDataException($"{context} model_target must be 'npu', 'cpu', or 'gpu'.");
            if (TryGet(model, "cpu_target_num_threads", out var threads) && ToInt(threads, 0) <= 0)
                throw new InvalidDataException($"{context} cpu_target_num_threads must be a positive integer.");

            ValidateModelTensorMetadata(model, "input", context);
            ValidateModelTensorMetadata(model, "output", context);
            ValidateAsset(packageRoot, binPath, $"{context} model", result);
        }

        private static void ValidateModelTensorMetadata(JsonData model, string key, string context)
        {
            if (!TryGet(model, key, out var entries)) return;
            if (entries == null || !entries.IsArray)
                throw new InvalidDataException($"{context} model.{key} must be an array when present.");
            for (var index = 0; index < entries.Count; index++)
            {
                var entry = RequireObject(entries[index], $"{context} model.{key}[{index}]");
                RequireString(entry, "name", $"{context} model.{key}[{index}]");
                RequireString(entry, "encoding_type", $"{context} model.{key}[{index}]");
                var shape = RequireArray(entry, "shape", $"{context} model.{key}[{index}]");
                if (shape.Count == 0 || Enumerable.Range(0, shape.Count).Any(i => ToInt(shape[i], 0) <= 0))
                    throw new InvalidDataException(
                        $"{context} model.{key}[{index}].shape must contain positive integers.");
            }
        }

        private static void ValidateMatrixDimensions(string name, JsonData tensor)
        {
            if (!IsMatrixTensor(tensor)) return;
            if (!TryGet(tensor, "dimensions", out var dimensions) || dimensions == null ||
                !dimensions.IsArray || dimensions.Count < 2)
                throw new InvalidDataException(
                    $"Tensor '{name}' is declared as matrix/MAT usage but must have at least two dimensions. " +
                    "Use [1, N] or [N, 1] for vector-shaped matrix data.");
        }

        private static bool IsMatrixTensor(JsonData tensor)
        {
            if (TryGetString(tensor, "tensor_type", out var tensorType) ||
                TryGetString(tensor, "type", out tensorType))
            {
                var normalized = tensorType.Trim().ToLowerInvariant().Replace('-', '_');
                if (normalized == "matrix" || normalized == "mat") return true;
            }
            if (!TryGet(tensor, "usage", out var usage)) return false;
            if (usage.IsString)
            {
                var text = ((string)usage).Trim().ToLowerInvariant().Replace('-', '_');
                if (text == "matrix" || text == "mat") return true;
            }
            return ToInt(usage, int.MinValue) == 6;
        }

        private static bool IsGltfTensor(JsonData tensor)
        {
            if (TryGet(tensor, "is_gltf", out var isGltf) && isGltf != null &&
                isGltf.IsBoolean && (bool)isGltf)
                return true;
            if (TryGetString(tensor, "tensor_type", out var tensorType) ||
                TryGetString(tensor, "type", out tensorType))
                return tensorType.Trim().Equals("gltf", StringComparison.OrdinalIgnoreCase);
            return false;
        }

        private static void ValidateSwapHwcChw(JsonData op, JsonData tensors, string context)
        {
            var inputs = RequireArray(op, "inputs", context);
            var outputs = RequireArray(op, "outputs", context);
            if (inputs.Count != 1 || outputs.Count != 1)
                throw new InvalidDataException(
                    $"{context} swap_hwc_chw requires exactly one input and one output tensor.");

            var inputName = ReadTensorName(inputs[0]);
            var outputName = ReadTensorName(outputs[0]);
            if (string.IsNullOrEmpty(inputName) || string.IsNullOrEmpty(outputName) ||
                !tensors.ContainsKey(inputName) || !tensors.ContainsKey(outputName)) return;

            var input = RequireObject(tensors[inputName], $"Tensor '{inputName}'");
            var output = RequireObject(tensors[outputName], $"Tensor '{outputName}'");
            var inputDimensions = ReadIntegerArray(input, "dimensions");
            var outputDimensions = ReadIntegerArray(output, "dimensions");
            var inputChannels = GetInt(input, "channels", 1);
            var outputChannels = GetInt(output, "channels", 1);
            if (inputDimensions.Count != 2)
                throw new InvalidDataException(
                    $"{context} input '{inputName}' must use two dimensions plus channels.");

            var expectedDimensions = inputChannels <= 4
                ? new[] { inputChannels, inputDimensions[0] }
                : new[] { inputDimensions[1], inputChannels };
            var expectedChannels = inputChannels <= 4 ? inputDimensions[1] : inputDimensions[0];
            if (!outputDimensions.SequenceEqual(expectedDimensions) || outputChannels != expectedChannels)
                throw new InvalidDataException(
                    $"{context} output '{outputName}' has dimensions [{string.Join(", ", outputDimensions)}] and channels {outputChannels}; " +
                    $"expected [{string.Join(", ", expectedDimensions)}] and channels {expectedChannels}.");
        }

        private static void ValidateModes(
            ISet<string> supportedModes,
            ICollection<string> xrOnlyUses,
            ICollection<string> spatialOnlyUses)
        {
            if (xrOnlyUses.Count > 0 && spatialOnlyUses.Count > 0)
                throw new InvalidDataException(
                    $"Package pipelines mix XR-only operators ({string.Join(", ", xrOnlyUses)}) " +
                    $"and Spatial-only operators ({string.Join(", ", spatialOnlyUses)}).");
            if (supportedModes.Contains("spatial") && xrOnlyUses.Count > 0)
                throw new InvalidDataException(
                    $"Manifest runtime.supported_modes includes spatial, but package uses XR-only operators: {string.Join(", ", xrOnlyUses)}.");
            if (supportedModes.Contains("xr") && spatialOnlyUses.Count > 0)
                throw new InvalidDataException(
                    $"Manifest runtime.supported_modes includes xr, but package uses Spatial-only operators: {string.Join(", ", spatialOnlyUses)}.");
        }

        private static void ValidateAsset(
            string packageRoot, string assetPath, string context, ValidatedPackage result)
        {
            var normalized = NormalizePackagePath(assetPath, $"{context} asset path");
            ResolveRequiredFile(
                packageRoot, normalized, $"{context} references missing package asset: {normalized}");
            if (NeedsBytesExtension(normalized)) result.ReferencedBinaryPaths.Add(normalized);
        }

        private static JsonData ReadJsonObject(string path, string description)
        {
            try
            {
                var value = JsonMapper.ToObject(File.ReadAllText(path));
                if (value == null || !value.IsObject)
                    throw new InvalidDataException($"{description} must contain a JSON object.");
                return value;
            }
            catch (InvalidDataException)
            {
                throw;
            }
            catch (Exception exception)
            {
                throw new InvalidDataException(
                    $"Failed to parse {description}: {exception.Message}", exception);
            }
        }

        private static JsonData RequireObjectProperty(JsonData parent, string key, string context)
        {
            if (!TryGet(parent, key, out var value))
                throw new InvalidDataException($"{context} is missing required '{key}'.");
            return RequireObject(value, $"{context} '{key}'");
        }

        private static JsonData RequireObject(JsonData value, string context)
        {
            if (value == null || !value.IsObject)
                throw new InvalidDataException($"{context} must be an object.");
            return value;
        }

        private static JsonData RequireArray(JsonData parent, string key, string context)
        {
            if (!TryGet(parent, key, out var value) || value == null || !value.IsArray)
                throw new InvalidDataException($"{context} requires an array '{key}'.");
            return value;
        }

        private static string RequireString(JsonData parent, string key, string context)
        {
            if (!TryGetString(parent, key, out var value) || string.IsNullOrWhiteSpace(value))
                throw new InvalidDataException($"{context} requires a non-empty string '{key}'.");
            return value;
        }

        private static bool TryGet(JsonData parent, string key, out JsonData value)
        {
            value = null;
            if (parent == null || !parent.IsObject || !parent.ContainsKey(key)) return false;
            value = parent[key];
            return true;
        }

        private static bool TryGetString(JsonData parent, string key, out string value)
        {
            value = null;
            if (!TryGet(parent, key, out var data) || data == null || !data.IsString) return false;
            value = (string)data;
            return !string.IsNullOrWhiteSpace(value);
        }

        private static string ReadTensorName(JsonData value)
        {
            if (value == null) return null;
            string reference;
            if (value.IsString)
                reference = (string)value;
            else if (value.IsObject && TryGetString(value, "tensor", out var tensor))
                reference = tensor;
            else
                return null;

            var sliceStart = reference.IndexOf('[');
            return (sliceStart < 0 ? reference : reference.Substring(0, sliceStart)).Trim();
        }

        private static List<int> ReadIntegerArray(JsonData parent, string key)
        {
            var values = new List<int>();
            if (!TryGet(parent, key, out var array) || array == null || !array.IsArray) return values;
            for (var index = 0; index < array.Count; index++) values.Add(ToInt(array[index], 0));
            return values;
        }

        private static int GetInt(JsonData parent, string key, int fallback)
        {
            return TryGet(parent, key, out var value) ? ToInt(value, fallback) : fallback;
        }

        private static int ToInt(JsonData value, int fallback)
        {
            if (value == null) return fallback;
            try
            {
                if (value.IsInt) return (int)value;
                if (value.IsLong) return checked((int)(long)value);
                if (value.IsString && int.TryParse(
                        (string)value, NumberStyles.Integer, CultureInfo.InvariantCulture, out var parsed))
                    return parsed;
            }
            catch (OverflowException)
            {
                return fallback;
            }
            return fallback;
        }

        private static string NormalizeOperatorType(string type)
        {
            var normalized = type.Trim().ToUpperInvariant();
            const string prefix = "XR_SECURE_MR_OPERATOR_TYPE_";
            const string suffix = "_PICO";
            if (normalized.StartsWith(prefix, StringComparison.Ordinal))
                normalized = normalized.Substring(prefix.Length);
            if (normalized.EndsWith(suffix, StringComparison.Ordinal))
                normalized = normalized.Substring(0, normalized.Length - suffix.Length);
            if (normalized == "RUN_ALGORITHM") return "RUN_MODEL_INFERENCE";
            if (normalized == "UPLOAD_TEXTURE_TO_GLTF") return "LOAD_TEXTURE";
            if (normalized == "DRAW_TEXT") return "RENDER_TEXT";
            if (normalized == "RENDER_GLTF") return "SWITCH_GLTF_RENDER_STATUS";
            if (normalized == "CHW_HWC") return "SWAP_HWC_CHW";
            return normalized;
        }

        private static string NormalizePackagePath(string path, string description)
        {
            if (string.IsNullOrWhiteSpace(path) || Path.IsPathRooted(path))
                throw new InvalidDataException($"Invalid package-relative {description}: '{path}'.");
            var normalized = path.Replace((char)92, '/');
            var segments = normalized.Split('/');
            if (segments.Any(segment =>
                    string.IsNullOrEmpty(segment) || segment == "." || segment == ".."))
                throw new InvalidDataException($"Invalid package-relative {description}: '{path}'.");
            return string.Join("/", segments);
        }

        private static string ResolveRequiredFile(string packageRoot, string relativePath, string message)
        {
            var path = Path.GetFullPath(Path.Combine(
                packageRoot, relativePath.Replace('/', Path.DirectorySeparatorChar)));
            EnsurePathUnderRoot(path, packageRoot, $"Package path escapes package root: '{relativePath}'.");
            if (!File.Exists(path)) throw new InvalidDataException(message);
            return path;
        }

        private static void EnsurePathUnderRoot(string path, string root, string message)
        {
            var fullPath = Path.GetFullPath(path);
            var fullRoot = Path.GetFullPath(root);
            var rootWithSeparator = fullRoot.TrimEnd(
                Path.DirectorySeparatorChar, Path.AltDirectorySeparatorChar) + Path.DirectorySeparatorChar;
            if (!fullPath.StartsWith(rootWithSeparator, StringComparison.OrdinalIgnoreCase))
                throw new InvalidDataException(message);
        }

        private static bool ShouldSkip(string file)
        {
            var normalized = file.Replace('\\', '/');
            var name = Path.GetFileName(file);
            return normalized.Contains("/__MACOSX/") ||
                   name.StartsWith("._", StringComparison.Ordinal) || name == ".DS_Store";
        }

        private static bool NeedsBytesExtension(string relativePath)
        {
            var extension = Path.GetExtension(relativePath).ToLowerInvariant();
            return extension != ".json" && extension != ".txt" && extension != ".js";
        }
    }
}
#endif
