using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Compression;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using UnityEditor;
using UnityEngine;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    public readonly struct AiSplitPreparedImage
    {
        public AiSplitPreparedImage(string fileName, byte[] pngBytes)
        {
            FileName = fileName ?? "flat.png";
            PngBytes = pngBytes ?? Array.Empty<byte>();
        }

        public string FileName { get; }

        public byte[] PngBytes { get; }
    }

    public static class AiSplitFlatImagePreparer
    {
        public static AiSplitPreparedImage PreparePng(IconLayerConfig sourceLayer)
        {
            if (sourceLayer?.Texture == null)
            {
                throw new InvalidOperationException("Flat source is missing.");
            }

            Texture2D normalized = IconTextureUtility.NormalizeToSquare(sourceLayer.Texture);
            try
            {
                return new AiSplitPreparedImage(
                    SanitizeFileName(sourceLayer.OriginalFileName),
                    normalized.EncodeToPNG());
            }
            finally
            {
                UnityEngine.Object.DestroyImmediate(normalized);
            }
        }

        private static string SanitizeFileName(string fileName)
        {
            string safeName = Path.GetFileName(string.IsNullOrWhiteSpace(fileName) ? "flat.png" : fileName);
            string extension = Path.GetExtension(safeName);
            if (!string.Equals(extension, ".png", StringComparison.OrdinalIgnoreCase))
            {
                safeName = Path.GetFileNameWithoutExtension(safeName) + ".png";
            }

            StringBuilder builder = new StringBuilder(safeName.Length);
            for (int i = 0; i < safeName.Length; i++)
            {
                char current = safeName[i];
                builder.Append(char.IsLetterOrDigit(current) || current == '.' || current == '_' || current == '-'
                    ? current
                    : '_');
            }

            return builder.ToString();
        }
    }

    public readonly struct AiSplitTosUploadResult
    {
        public AiSplitTosUploadResult(string objectKey, string publicUrl)
        {
            ObjectKey = objectKey ?? string.Empty;
            PublicUrl = publicUrl ?? string.Empty;
        }

        public string ObjectKey { get; }

        public string PublicUrl { get; }
    }

    public interface IAiSplitTosUploader
    {
        AiSplitTosUploadResult Upload(AiSplitTosConfig config, string fileName, byte[] pngBytes);
    }

    public interface IAiSplitTosClient
    {
        void PutObject(string bucketName, string objectKey, byte[] bytes, Dictionary<string, string> headers);
    }

    public sealed class AiSplitTosUploader : IAiSplitTosUploader
    {
        private readonly IAiSplitTosClient m_client;
        private readonly Func<long> m_unixMillisecondsProvider;

        public AiSplitTosUploader(IAiSplitTosClient client, Func<long> unixMillisecondsProvider)
        {
            m_client = client ?? throw new ArgumentNullException(nameof(client));
            m_unixMillisecondsProvider = unixMillisecondsProvider ?? (() => DateTimeOffset.UtcNow.ToUnixTimeMilliseconds());
        }

        public AiSplitTosUploadResult Upload(AiSplitTosConfig config, string fileName, byte[] pngBytes)
        {
            if (config == null)
            {
                throw new InvalidOperationException("TOS configuration is missing.");
            }

            string objectKey = CombineObjectKey(
                config.ObjectDirectory,
                "ai_split_" + m_unixMillisecondsProvider() + "_" + SanitizeObjectFileName(fileName));
            Dictionary<string, string> headers = new Dictionary<string, string>
            {
                ["Connection"] = "close",
            };

            m_client.PutObject(config.BucketName, objectKey, pngBytes ?? Array.Empty<byte>(), headers);
            return new AiSplitTosUploadResult(objectKey, CombinePublicUrl(config.PublicBaseUrl, objectKey));
        }

        private static string CombineObjectKey(string objectDirectory, string fileName)
        {
            string directory = (objectDirectory ?? string.Empty).Trim().Replace('\\', '/');
            if (string.IsNullOrEmpty(directory))
            {
                return fileName;
            }

            return directory.TrimEnd('/') + "/" + fileName;
        }

        private static string CombinePublicUrl(string publicBaseUrl, string objectKey)
        {
            string baseUrl = (publicBaseUrl ?? string.Empty).TrimEnd('/');
            return string.IsNullOrEmpty(baseUrl) ? objectKey : baseUrl + "/" + objectKey;
        }

        private static string SanitizeObjectFileName(string fileName)
        {
            string safeName = Path.GetFileName(string.IsNullOrWhiteSpace(fileName) ? "flat.png" : fileName);
            StringBuilder builder = new StringBuilder(safeName.Length);
            for (int i = 0; i < safeName.Length; i++)
            {
                char current = safeName[i];
                builder.Append(char.IsLetterOrDigit(current) || current == '.' || current == '_' || current == '-'
                    ? current
                    : '_');
            }

            return builder.ToString();
        }
    }

    public sealed class AiSplitHttpRequest
    {
        public string Url { get; set; } = string.Empty;

        public string Body { get; set; } = string.Empty;

        public int ConnectTimeoutSeconds { get; set; }

        public int ReadTimeoutSeconds { get; set; }

        public Dictionary<string, string> Headers { get; set; } = new Dictionary<string, string>();
    }

    public sealed class AiSplitHttpResponse
    {
        public AiSplitHttpResponse(int statusCode, byte[] bodyBytes, bool isCompressed)
        {
            StatusCode = statusCode;
            BodyBytes = bodyBytes ?? Array.Empty<byte>();
            IsCompressed = isCompressed;
        }

        public int StatusCode { get; }

        public byte[] BodyBytes { get; }

        public bool IsCompressed { get; }

        public bool IsSuccessStatusCode => StatusCode == 0 || (StatusCode >= 200 && StatusCode < 300);

        public string BodyString => Encoding.UTF8.GetString(BodyBytes);
    }

    public interface IAiSplitHttpClient
    {
        AiSplitHttpResponse Post(AiSplitHttpRequest request);
    }

    public interface IAiSplitAssetDownloader
    {
        byte[] Download(string url, int connectTimeoutSeconds, int readTimeoutSeconds);
    }

    public sealed class AiSplitHttpClient : IAiSplitHttpClient
    {
        public AiSplitHttpResponse Post(AiSplitHttpRequest request)
        {
            if (request == null)
            {
                throw new ArgumentNullException(nameof(request));
            }

            HttpWebRequest webRequest = (HttpWebRequest)WebRequest.Create(request.Url);
            webRequest.Method = "POST";
            webRequest.ContentType = "application/json";
            webRequest.Accept = "application/json";
            webRequest.AutomaticDecompression = DecompressionMethods.GZip | DecompressionMethods.Deflate;
            webRequest.Timeout = Math.Max(1, request.ConnectTimeoutSeconds) * 1000;
            webRequest.ReadWriteTimeout = Math.Max(1, request.ReadTimeoutSeconds) * 1000;

            if (request.Headers != null)
            {
                foreach (KeyValuePair<string, string> header in request.Headers)
                {
                    if (string.Equals(header.Key, "Connection", StringComparison.OrdinalIgnoreCase))
                    {
                        webRequest.KeepAlive = !string.Equals(header.Value, "close", StringComparison.OrdinalIgnoreCase);
                        continue;
                    }

                    webRequest.Headers[header.Key] = header.Value;
                }
            }

            byte[] requestBytes = Encoding.UTF8.GetBytes(request.Body ?? string.Empty);
            webRequest.ContentLength = requestBytes.Length;
            using (Stream requestStream = webRequest.GetRequestStream())
            {
                requestStream.Write(requestBytes, 0, requestBytes.Length);
            }

            try
            {
                using HttpWebResponse response = (HttpWebResponse)webRequest.GetResponse();
                return ReadResponse(response);
            }
            catch (WebException exception) when (exception.Response is HttpWebResponse errorResponse)
            {
                using (errorResponse)
                {
                    return ReadResponse(errorResponse);
                }
            }
        }

        private static AiSplitHttpResponse ReadResponse(HttpWebResponse response)
        {
            using Stream responseStream = response.GetResponseStream();
            byte[] bytes = ReadAllBytes(responseStream, response.ContentEncoding);
            return new AiSplitHttpResponse((int)response.StatusCode, bytes, false);
        }

        private static byte[] ReadAllBytes(Stream stream, string contentEncoding)
        {
            if (stream == null)
            {
                return Array.Empty<byte>();
            }

            Stream readableStream = stream;
            if (!string.IsNullOrWhiteSpace(contentEncoding))
            {
                if (contentEncoding.IndexOf("gzip", StringComparison.OrdinalIgnoreCase) >= 0)
                {
                    readableStream = new GZipStream(stream, CompressionMode.Decompress);
                }
                else if (contentEncoding.IndexOf("deflate", StringComparison.OrdinalIgnoreCase) >= 0)
                {
                    readableStream = new DeflateStream(stream, CompressionMode.Decompress);
                }
            }

            using (readableStream)
            using (MemoryStream memoryStream = new MemoryStream())
            {
                readableStream.CopyTo(memoryStream);
                return memoryStream.ToArray();
            }
        }
    }

    public sealed class AiSplitAssetDownloader : IAiSplitAssetDownloader
    {
        public byte[] Download(string url, int connectTimeoutSeconds, int readTimeoutSeconds)
        {
            if (string.IsNullOrWhiteSpace(url))
            {
                throw new InvalidOperationException("AI Split asset URL is empty.");
            }

            HttpWebRequest webRequest = (HttpWebRequest)WebRequest.Create(url);
            webRequest.Method = "GET";
            webRequest.Accept = "image/png,*/*";
            webRequest.AutomaticDecompression = DecompressionMethods.GZip | DecompressionMethods.Deflate;
            webRequest.Timeout = Math.Max(1, connectTimeoutSeconds) * 1000;
            webRequest.ReadWriteTimeout = Math.Max(1, readTimeoutSeconds) * 1000;

            try
            {
                using HttpWebResponse response = (HttpWebResponse)webRequest.GetResponse();
                if ((int)response.StatusCode < 200 || (int)response.StatusCode >= 300)
                {
                    throw new InvalidOperationException("AI Split asset download HTTP " + (int)response.StatusCode + ": " + url);
                }

                using Stream responseStream = response.GetResponseStream();
                using MemoryStream memoryStream = new MemoryStream();
                responseStream?.CopyTo(memoryStream);
                return memoryStream.ToArray();
            }
            catch (WebException exception) when (exception.Response is HttpWebResponse errorResponse)
            {
                using (errorResponse)
                {
                    throw new InvalidOperationException("AI Split asset download HTTP " + (int)errorResponse.StatusCode + ": " + url);
                }
            }
        }
    }

    public interface IAiSplitClock
    {
        DateTime UtcNow { get; }

        long UnixMilliseconds { get; }
    }

    public sealed class SystemAiSplitClock : IAiSplitClock
    {
        public DateTime UtcNow => DateTime.UtcNow;

        public long UnixMilliseconds => DateTimeOffset.UtcNow.ToUnixTimeMilliseconds();
    }

    public interface IAiSplitDelay
    {
        void Delay(TimeSpan value);
    }

    public sealed class ThreadAiSplitDelay : IAiSplitDelay
    {
        public void Delay(TimeSpan value)
        {
            System.Threading.Thread.Sleep(value);
        }
    }

    public interface IAiSplitGenerationRunner
    {
        void Run(Action action);
    }

    public sealed class ThreadedAiSplitGenerationRunner : IAiSplitGenerationRunner
    {
        public void Run(Action action)
        {
            Task.Run(action);
        }
    }

    public sealed class ImmediateAiSplitGenerationRunner : IAiSplitGenerationRunner
    {
        public void Run(Action action)
        {
            action?.Invoke();
        }
    }

    public interface IAiSplitMainThreadDispatcher
    {
        void Post(Action action);
    }

    public sealed class EditorAiSplitMainThreadDispatcher : IAiSplitMainThreadDispatcher
    {
        public void Post(Action action)
        {
            if (action == null)
            {
                return;
            }

            EditorApplication.delayCall += () => action();
        }
    }

    public sealed class ImmediateAiSplitMainThreadDispatcher : IAiSplitMainThreadDispatcher
    {
        public void Post(Action action)
        {
            action?.Invoke();
        }
    }

    public sealed class RealIconAiSplitService : IIconAiSplitService
    {
        private const int ProcessingCode = 10002;

        private readonly Func<AiSplitTccLoadResult> m_configLoader;
        private readonly IAiSplitTosUploader m_tosUploader;
        private readonly IAiSplitHttpClient m_httpClient;
        private readonly AiSplitDeviceIdProvider m_deviceIdProvider;
        private readonly AiSplitGenerationRateLimiter m_rateLimiter;
        private readonly IAiSplitClock m_clock;
        private readonly IAiSplitDelay m_delay;
        private readonly IAiSplitAssetDownloader m_assetDownloader;
        private readonly IAiSplitGenerationRunner m_generationRunner;
        private readonly IAiSplitMainThreadDispatcher m_mainThreadDispatcher;
        private volatile bool m_cancelRequested;

        public RealIconAiSplitService(
            Func<AiSplitTccLoadResult> configLoader,
            IAiSplitTosUploader tosUploader,
            IAiSplitHttpClient httpClient,
            AiSplitDeviceIdProvider deviceIdProvider,
            AiSplitGenerationRateLimiter rateLimiter,
            IAiSplitClock clock,
            IAiSplitDelay delay,
            IAiSplitAssetDownloader assetDownloader = null,
            IAiSplitGenerationRunner generationRunner = null,
            IAiSplitMainThreadDispatcher mainThreadDispatcher = null)
        {
            m_configLoader = configLoader ?? throw new ArgumentNullException(nameof(configLoader));
            m_tosUploader = tosUploader ?? throw new ArgumentNullException(nameof(tosUploader));
            m_httpClient = httpClient ?? throw new ArgumentNullException(nameof(httpClient));
            m_deviceIdProvider = deviceIdProvider ?? throw new ArgumentNullException(nameof(deviceIdProvider));
            m_rateLimiter = rateLimiter ?? throw new ArgumentNullException(nameof(rateLimiter));
            m_clock = clock ?? new SystemAiSplitClock();
            m_delay = delay ?? new ThreadAiSplitDelay();
            m_assetDownloader = assetDownloader ?? new AiSplitAssetDownloader();
            m_generationRunner = generationRunner ?? new ThreadedAiSplitGenerationRunner();
            m_mainThreadDispatcher = mainThreadDispatcher ?? new EditorAiSplitMainThreadDispatcher();
        }

        public bool IsRunning { get; private set; }

        public void StartGenerate(
            IconLayerConfig sourceLayer,
            string configGuid,
            Action<float> onProgress,
            Action<IconAiSplitResult, string, string> onSuccess,
            Action<string> onError)
        {
            if (IsRunning)
            {
                return;
            }

            if (sourceLayer?.Texture == null)
            {
                onError?.Invoke("Flat source is missing.");
                return;
            }

            if (!m_rateLimiter.TryAcquire(out string rateLimitError))
            {
                onError?.Invoke(rateLimitError);
                return;
            }

            IsRunning = true;
            m_cancelRequested = false;

            AiSplitPreparedImage preparedImage;
            AiSplitTccLoadResult loadResult;
            try
            {
                loadResult = m_configLoader();
                if (loadResult == null || !loadResult.Success)
                {
                    IsRunning = false;
                    m_cancelRequested = false;
                    onError?.Invoke(loadResult?.ErrorMessage ?? "AI Split configuration is unavailable.");
                    return;
                }

                preparedImage = AiSplitFlatImagePreparer.PreparePng(sourceLayer);
            }
            catch (Exception exception)
            {
                IsRunning = false;
                m_cancelRequested = false;
                onError?.Invoke(exception.Message);
                return;
            }

            m_generationRunner.Run(() => RunGenerate(
                preparedImage,
                loadResult,
                configGuid,
                onProgress,
                onSuccess,
                onError));
        }

        public void Cancel()
        {
            m_cancelRequested = true;
        }

        private void RunGenerate(
            AiSplitPreparedImage preparedImage,
            AiSplitTccLoadResult loadResult,
            string configGuid,
            Action<float> onProgress,
            Action<IconAiSplitResult, string, string> onSuccess,
            Action<string> onError)
        {
            try
            {
                AiSplitDownloadedResult downloadedResult = GenerateInternal(
                    preparedImage,
                    loadResult,
                    progress => PostProgress(onProgress, progress));
                if (m_cancelRequested)
                {
                    PostError(onError, "AI Split generation cancelled.");
                    return;
                }

                m_mainThreadDispatcher.Post(() =>
                {
                    try
                    {
                        if (m_cancelRequested)
                        {
                            FinishError(onError, "AI Split generation cancelled.");
                            return;
                        }

                        IconAiSplitResult result = CreateResult(configGuid, downloadedResult);
                        onProgress?.Invoke(1f);
                        onSuccess?.Invoke(result, result.RequestId, result.GeneratedAt);
                        FinishRunningState();
                    }
                    catch (Exception exception)
                    {
                        FinishError(onError, exception.Message);
                    }
                });
            }
            catch (TimeoutException exception)
            {
                PostError(onError, exception.Message);
            }
            catch (OperationCanceledException)
            {
                PostError(onError, "AI Split generation cancelled.");
            }
            catch (Exception exception)
            {
                PostError(onError, exception.Message);
            }
        }

        private AiSplitDownloadedResult GenerateInternal(
            AiSplitPreparedImage preparedImage,
            AiSplitTccLoadResult loadResult,
            Action<float> onProgress)
        {
            onProgress?.Invoke(0.05f);
            string appId = NormalizeInt64String(loadResult.Config.Signing.AppId);
            string deviceId = NormalizeInt64String(m_deviceIdProvider.GetDeviceId());
            string signature = AiSplitRequestSigner.GenerateSignature(
                appId,
                deviceId,
                loadResult.Config.Signing.Salt);
            string generateBody = CreateGenerateBody(
                loadResult,
                preparedImage,
                appId,
                deviceId,
                signature,
                onProgress);
            onProgress?.Invoke(0.3f);
            AiSplitGenerateResponseDto generateResponse = PostJson<AiSplitGenerateResponseDto>(
                loadResult,
                loadResult.Config.Api.GeneratePath,
                generateBody);
            if (generateResponse.code != 0)
            {
                throw new InvalidOperationException(CreateServiceError("sdf/gen", generateResponse.code, generateResponse.ErrorMessage));
            }

            string taskId = generateResponse.data?.task_id ?? string.Empty;
            if (string.IsNullOrWhiteSpace(taskId))
            {
                throw new InvalidOperationException("AI Split service returned an empty task id.");
            }

            DateTime startedAt = m_clock.UtcNow;
            int processingPollCount = 0;
            while (true)
            {
                ThrowIfCancelled();
                AiSplitInfoResponseDto infoResponse = PostJson<AiSplitInfoResponseDto>(
                    loadResult,
                    loadResult.Config.Api.InfoPath,
                    CreateInfoBody(appId, deviceId, signature, taskId));

                if (infoResponse.code == 0)
                {
                    ThrowIfCancelled();
                    onProgress?.Invoke(0.95f);
                    return DownloadResultAssets(loadResult, taskId, infoResponse);
                }

                if (infoResponse.code != ProcessingCode)
                {
                    throw new InvalidOperationException(CreateServiceError("sdf/info", infoResponse.code, infoResponse.ErrorMessage));
                }

                processingPollCount++;
                onProgress?.Invoke(GetProcessingProgress(infoResponse.data?.progress ?? 0, processingPollCount));
                ThrowIfCancelled();

                if (m_clock.UtcNow - startedAt >= TimeSpan.FromSeconds(loadResult.Config.Timeouts.TotalTimeoutSeconds))
                {
                    throw new TimeoutException("AI Split generation timed out.");
                }

                m_delay.Delay(TimeSpan.FromSeconds(Math.Max(0, loadResult.Config.Timeouts.PollIntervalSeconds)));
            }
        }

        private void PostProgress(Action<float> onProgress, float progress)
        {
            m_mainThreadDispatcher.Post(() =>
            {
                if (!m_cancelRequested)
                {
                    onProgress?.Invoke(progress);
                }
            });
        }

        private void PostError(Action<string> onError, string errorMessage)
        {
            m_mainThreadDispatcher.Post(() => FinishError(onError, errorMessage));
        }

        private void FinishError(Action<string> onError, string errorMessage)
        {
            onError?.Invoke(errorMessage);
            FinishRunningState();
        }

        private void FinishRunningState()
        {
            IsRunning = false;
            m_cancelRequested = false;
        }

        private T PostJson<T>(AiSplitTccLoadResult loadResult, string path, string body)
        {
            AiSplitHttpRequest request = new AiSplitHttpRequest
            {
                Url = ResolveEndpointUrl(loadResult.SelectedRegion.ApiBaseUrl, path),
                Body = body,
                ConnectTimeoutSeconds = loadResult.Config.Timeouts.ConnectTimeoutSeconds,
                ReadTimeoutSeconds = loadResult.Config.Timeouts.ReadTimeoutSeconds,
                Headers = CreateHeaders(loadResult.SelectedRegion),
            };

            AiSplitHttpResponse response = m_httpClient.Post(request);
            if (!response.IsSuccessStatusCode)
            {
                throw new InvalidOperationException("AI Split HTTP " + response.StatusCode + ": " + response.BodyString);
            }

            T parsed = JsonUtility.FromJson<T>(response.BodyString);
            if (parsed == null)
            {
                throw new InvalidOperationException("AI Split service returned an invalid JSON response.");
            }

            return parsed;
        }

        private static Dictionary<string, string> CreateHeaders(AiSplitRegionConfig region)
        {
            Dictionary<string, string> headers = new Dictionary<string, string>();
            if (!string.IsNullOrWhiteSpace(region.TtEnv))
            {
                headers["X-Tt-Env"] = region.TtEnv;
                headers["X-Use-Ppe"] = "1";
            }
            else if (region.UsePpe)
            {
                headers["X-Use-Ppe"] = "1";
            }

            return headers;
        }

        private string CreateGenerateBody(
            AiSplitTccLoadResult loadResult,
            AiSplitPreparedImage preparedImage,
            string appId,
            string deviceId,
            string signature,
            Action<float> onProgress)
        {
            if (HasUsableTosConfig(loadResult.Config.Tos))
            {
                AiSplitTosUploadResult uploadResult = m_tosUploader.Upload(
                    loadResult.Config.Tos,
                    preparedImage.FileName,
                    preparedImage.PngBytes);
                onProgress?.Invoke(0.15f);
                return CreateGenerateBodyWithImageUrl(appId, deviceId, signature, uploadResult.PublicUrl);
            }

            if (TryUploadViaService(loadResult, preparedImage, appId, deviceId, signature, out string uploadedImageUrl))
            {
                onProgress?.Invoke(0.15f);
                return CreateGenerateBodyWithImageUrl(appId, deviceId, signature, uploadedImageUrl);
            }

            onProgress?.Invoke(0.15f);
            return CreateGenerateBodyWithImageBase64(
                appId,
                deviceId,
                signature,
                Convert.ToBase64String(preparedImage.PngBytes ?? Array.Empty<byte>()));
        }

        private bool TryUploadViaService(
            AiSplitTccLoadResult loadResult,
            AiSplitPreparedImage preparedImage,
            string appId,
            string deviceId,
            string signature,
            out string uploadedImageUrl)
        {
            uploadedImageUrl = string.Empty;
            try
            {
                AiSplitUploadResponseDto response = PostJson<AiSplitUploadResponseDto>(
                    loadResult,
                    CreateUploadPath(loadResult.Config.Api.GeneratePath),
                    CreateUploadBody(
                        appId,
                        deviceId,
                        signature,
                        preparedImage.FileName,
                        Convert.ToBase64String(preparedImage.PngBytes ?? Array.Empty<byte>())));
                if (response.code != 0)
                {
                    return false;
                }

                uploadedImageUrl = NormalizeServiceUrl(
                    FirstNonEmpty(
                        response.data?.image_url,
                        response.data?.imageUrl,
                        response.data?.url,
                        response.data?.public_url,
                        response.data?.publicUrl,
                        response.data?.download_url,
                        response.data?.downloadUrl,
                        response.data?.file_url,
                        response.data?.fileUrl));
                return !string.IsNullOrWhiteSpace(uploadedImageUrl);
            }
            catch (InvalidOperationException exception)
            {
                Debug.LogWarning($"[IconConfigurator] AI Split upload failed, falling back to Base64: {exception.Message}");
                return false;
            }
        }

        private AiSplitDownloadedResult DownloadResultAssets(
            AiSplitTccLoadResult loadResult,
            string taskId,
            AiSplitInfoResponseDto response)
        {
            AiSplitRemoteAssetDto[] layerDtos = response.data?.layer ?? response.data?.layers ?? Array.Empty<AiSplitRemoteAssetDto>();
            AiSplitRemoteAssetDto[] sdfDtos = response.data?.sdf ?? response.data?.sdfs ?? Array.Empty<AiSplitRemoteAssetDto>();
            ValidateRemoteAssets(layerDtos, sdfDtos);

            return new AiSplitDownloadedResult(
                taskId,
                response.request_id,
                response.data?.model_version ?? string.Empty,
                m_clock.UtcNow.ToString("O"),
                layerDtos,
                sdfDtos,
                DownloadAssets(layerDtos, loadResult.Config.Timeouts),
                DownloadAssets(sdfDtos, loadResult.Config.Timeouts));
        }

        private IconAiSplitResult CreateResult(string configGuid, AiSplitDownloadedResult downloadedResult)
        {
            string outputRoot =
                $"{IconConfiguratorPaths.GeneratedDirectory}/{SanitizePathSegment(configGuid)}/ai-split/{SanitizePathSegment(downloadedResult.TaskId)}";

            try
            {
                EnsureFolder(IconConfiguratorPaths.RootDirectory);
                EnsureFolder(IconConfiguratorPaths.GeneratedDirectory);
                EnsureFolder($"{IconConfiguratorPaths.GeneratedDirectory}/{SanitizePathSegment(configGuid)}");
                EnsureFolder($"{IconConfiguratorPaths.GeneratedDirectory}/{SanitizePathSegment(configGuid)}/ai-split");
                EnsureFolder(outputRoot);
                EnsureFolder($"{outputRoot}/layers");
                EnsureFolder($"{outputRoot}/sdf");

                List<IconLayerConfig> layers = WriteImportedAssets(
                    outputRoot,
                    "layers",
                    ReverseCopy(downloadedResult.LayerAssets),
                    ReverseCopy(downloadedResult.LayerBytes));
                List<IconLayerConfig> sdfs = WriteImportedAssets(
                    outputRoot,
                    "sdf",
                    ReverseCopy(downloadedResult.SdfAssets),
                    ReverseCopy(downloadedResult.SdfBytes));
                NormalizeLayerMetadata(layers);
                NormalizeLayerMetadata(sdfs);

                IconAiSplitResult result = new IconAiSplitResult
                {
                    TaskId = downloadedResult.TaskId,
                    RequestId = downloadedResult.RequestId,
                    ModelVersion = downloadedResult.ModelVersion,
                    GeneratedAt = downloadedResult.GeneratedAt,
                    Layers = layers,
                    Sdfs = sdfs,
                };

                if (result.Layers.Count > 0)
                {
                    result.Background = result.Layers[0];
                }

                if (result.Layers.Count > 1)
                {
                    result.Foreground1 = result.Layers[1];
                }

                if (result.Layers.Count > 2)
                {
                    result.Foreground2 = result.Layers[2];
                }

                return result;
            }
            catch
            {
                if (AssetDatabase.IsValidFolder(outputRoot))
                {
                    AssetDatabase.DeleteAsset(outputRoot);
                }

                throw;
            }
        }

        private byte[][] DownloadAssets(AiSplitRemoteAssetDto[] assets, AiSplitTimeoutConfig timeouts)
        {
            byte[][] downloadedBytes = new byte[assets.Length][];
            for (int i = 0; i < assets.Length; i++)
            {
                ThrowIfCancelled();
                downloadedBytes[i] = m_assetDownloader.Download(
                    assets[i].url,
                    timeouts.ConnectTimeoutSeconds,
                    timeouts.ReadTimeoutSeconds);
                if (downloadedBytes[i] == null || downloadedBytes[i].Length == 0)
                {
                    throw new InvalidOperationException("AI Split downloaded asset is empty.");
                }
            }

            return downloadedBytes;
        }

        private static void ValidateRemoteAssets(AiSplitRemoteAssetDto[] layerDtos, AiSplitRemoteAssetDto[] sdfDtos)
        {
            if (layerDtos.Length != sdfDtos.Length)
            {
                throw new InvalidOperationException("AI Split layer/sdf asset counts must match.");
            }

            if (layerDtos.Length < ManualLayerState.MinLayerCount || layerDtos.Length > ManualLayerState.MaxLayerCount)
            {
                throw new InvalidOperationException(
                    $"AI Split result must contain between {ManualLayerState.MinLayerCount} and {ManualLayerState.MaxLayerCount} layer/sdf pairs.");
            }

            for (int i = 0; i < layerDtos.Length; i++)
            {
                if (string.IsNullOrWhiteSpace(layerDtos[i]?.url) || string.IsNullOrWhiteSpace(sdfDtos[i]?.url))
                {
                    throw new InvalidOperationException("AI Split service returned an empty layer/sdf URL.");
                }
            }
        }

        private static List<IconLayerConfig> WriteImportedAssets(
            string outputRoot,
            string assetGroup,
            AiSplitRemoteAssetDto[] assets,
            byte[][] assetBytes)
        {
            List<IconLayerConfig> layers = new List<IconLayerConfig>(assets.Length);
            for (int i = 0; i < assets.Length; i++)
            {
                string assetPath = $"{outputRoot}/{assetGroup}/{GetLayerFileName(i)}";
                File.WriteAllBytes(assetPath, assetBytes[i]);
                AssetDatabase.ImportAsset(assetPath, ImportAssetOptions.ForceSynchronousImport);
                ConfigureTextureImporter(assetPath);

                Texture2D texture = AssetDatabase.LoadAssetAtPath<Texture2D>(assetPath);
                if (texture == null)
                {
                    throw new InvalidOperationException("Failed to import AI Split downloaded texture.");
                }

                layers.Add(new IconLayerConfig
                {
                    AssetGuid = AssetDatabase.AssetPathToGUID(assetPath),
                    AssetPath = assetPath,
                    OriginalFileName = GetRemoteFileName(assets[i].url, GetLayerFileName(i)),
                    ContentHash = assets[i].md5 ?? string.Empty,
                    SourceWidth = texture.width,
                    SourceHeight = texture.height,
                    Texture = texture,
                });
            }

            return layers;
        }

        private static T[] ReverseCopy<T>(T[] values)
        {
            T[] copy = new T[values.Length];
            Array.Copy(values, copy, values.Length);
            Array.Reverse(copy);
            return copy;
        }

        private static void NormalizeLayerMetadata(List<IconLayerConfig> layers)
        {
            for (int i = 0; i < layers.Count; i++)
            {
                layers[i].LayerKind = IconLayerNaming.GetLayerKind(i);
                layers[i].DisplayName = IconLayerNaming.GetDisplayName(i);
            }
        }

        private static float GetProcessingProgress(int reportedProgress, int processingPollCount)
        {
            if (reportedProgress > 0)
            {
                return Mathf.Clamp(reportedProgress / 100f, 0f, 0.99f);
            }

            return Mathf.Clamp(processingPollCount * 0.05f, 0.05f, 0.95f);
        }

        private static string GetLayerFileName(int layerIndex)
        {
            return IconLayerNaming.GetPngFileName(layerIndex);
        }

        private static string GetRemoteFileName(string url, string fallback)
        {
            if (!Uri.TryCreate(url, UriKind.Absolute, out Uri uri))
            {
                return fallback;
            }

            string fileName = Path.GetFileName(uri.LocalPath);
            return string.IsNullOrWhiteSpace(fileName) ? fallback : fileName;
        }

        private static void ConfigureTextureImporter(string assetPath)
        {
            TextureImporter importer = AssetImporter.GetAtPath(assetPath) as TextureImporter;
            if (importer == null)
            {
                return;
            }

            bool changed = false;
            if (!importer.isReadable)
            {
                importer.isReadable = true;
                changed = true;
            }

            if (!importer.alphaIsTransparency)
            {
                importer.alphaIsTransparency = true;
                changed = true;
            }

            if (importer.mipmapEnabled)
            {
                importer.mipmapEnabled = false;
                changed = true;
            }

            if (importer.textureCompression != TextureImporterCompression.Uncompressed)
            {
                importer.textureCompression = TextureImporterCompression.Uncompressed;
                changed = true;
            }

            if (changed)
            {
                importer.SaveAndReimport();
            }
        }

        private static void EnsureFolder(string path)
        {
            if (AssetDatabase.IsValidFolder(path))
            {
                return;
            }

            string parent = path.Substring(0, path.LastIndexOf('/'));
            string folderName = path.Substring(path.LastIndexOf('/') + 1);

            if (!AssetDatabase.IsValidFolder(parent))
            {
                EnsureFolder(parent);
            }

            AssetDatabase.CreateFolder(parent, folderName);
        }

        private sealed class AiSplitDownloadedResult
        {
            public AiSplitDownloadedResult(
                string taskId,
                string requestId,
                string modelVersion,
                string generatedAt,
                AiSplitRemoteAssetDto[] layerAssets,
                AiSplitRemoteAssetDto[] sdfAssets,
                byte[][] layerBytes,
                byte[][] sdfBytes)
            {
                TaskId = taskId ?? string.Empty;
                RequestId = requestId ?? string.Empty;
                ModelVersion = modelVersion ?? string.Empty;
                GeneratedAt = generatedAt ?? string.Empty;
                LayerAssets = layerAssets ?? Array.Empty<AiSplitRemoteAssetDto>();
                SdfAssets = sdfAssets ?? Array.Empty<AiSplitRemoteAssetDto>();
                LayerBytes = layerBytes ?? Array.Empty<byte[]>();
                SdfBytes = sdfBytes ?? Array.Empty<byte[]>();
            }

            public string TaskId { get; }

            public string RequestId { get; }

            public string ModelVersion { get; }

            public string GeneratedAt { get; }

            public AiSplitRemoteAssetDto[] LayerAssets { get; }

            public AiSplitRemoteAssetDto[] SdfAssets { get; }

            public byte[][] LayerBytes { get; }

            public byte[][] SdfBytes { get; }
        }

        private static string SanitizePathSegment(string value)
        {
            string safeValue = string.IsNullOrWhiteSpace(value) ? "default" : value;
            StringBuilder builder = new StringBuilder(safeValue.Length);
            for (int i = 0; i < safeValue.Length; i++)
            {
                char current = safeValue[i];
                builder.Append(char.IsLetterOrDigit(current) || current == '_' || current == '-' ? current : '_');
            }

            return builder.ToString();
        }

        private void ThrowIfCancelled()
        {
            if (m_cancelRequested)
            {
                throw new OperationCanceledException();
            }
        }

        private static string ResolveEndpointUrl(string baseUrl, string path)
        {
            return IsAbsoluteHttpUrl(path) ? path : CombineUrl(baseUrl, path);
        }

        private static bool IsAbsoluteHttpUrl(string value)
        {
            return Uri.TryCreate(value, UriKind.Absolute, out Uri uri)
                && (uri.Scheme == Uri.UriSchemeHttp || uri.Scheme == Uri.UriSchemeHttps);
        }

        private static string CombineUrl(string baseUrl, string path)
        {
            return (baseUrl ?? string.Empty).TrimEnd('/') + "/" + (path ?? string.Empty).TrimStart('/');
        }

        private static bool HasUsableTosConfig(AiSplitTosConfig config)
        {
            return !string.IsNullOrWhiteSpace(config?.BucketName)
                && !string.IsNullOrWhiteSpace(config.ObjectDirectory)
                && !string.IsNullOrWhiteSpace(config.PublicBaseUrl);
        }

        private static string CreateUploadPath(string generatePath)
        {
            const string GenSuffix = "/sdf/gen";
            if (!string.IsNullOrWhiteSpace(generatePath)
                && generatePath.EndsWith(GenSuffix, StringComparison.OrdinalIgnoreCase))
            {
                return generatePath.Substring(0, generatePath.Length - GenSuffix.Length) + "/sdf/upload";
            }

            const string SimpleGenSuffix = "/gen";
            if (!string.IsNullOrWhiteSpace(generatePath)
                && generatePath.EndsWith(SimpleGenSuffix, StringComparison.OrdinalIgnoreCase))
            {
                return generatePath.Substring(0, generatePath.Length - SimpleGenSuffix.Length) + "/upload";
            }

            return "/sdf/upload";
        }

        private static string CreateGenerateBodyWithImageUrl(string appId, string deviceId, string signature, string imageUrl)
        {
            return "{"
                + "\"app_id\":" + ToJsonInt64Literal(appId) + ","
                + "\"device_id\":" + ToJsonInt64Literal(deviceId) + ","
                + "\"signature\":\"" + EscapeJson(signature) + "\","
                + "\"image_url\":\"" + EscapeJson(imageUrl) + "\""
                + "}";
        }

        private static string CreateGenerateBodyWithImageBase64(string appId, string deviceId, string signature, string imageBase64)
        {
            return "{"
                + "\"app_id\":" + ToJsonInt64Literal(appId) + ","
                + "\"device_id\":" + ToJsonInt64Literal(deviceId) + ","
                + "\"signature\":\"" + EscapeJson(signature) + "\","
                + "\"img_bytes\":\"" + EscapeJson(imageBase64) + "\""
                + "}";
        }

        private static string CreateUploadBody(string appId, string deviceId, string signature, string fileName, string imageBase64)
        {
            return "{"
                + "\"app_id\":" + ToJsonInt64Literal(appId) + ","
                + "\"device_id\":" + ToJsonInt64Literal(deviceId) + ","
                + "\"signature\":\"" + EscapeJson(signature) + "\","
                + "\"file_name\":\"" + EscapeJson(fileName) + "\","
                + "\"img_bytes\":\"" + EscapeJson(imageBase64) + "\""
                + "}";
        }

        private static string CreateInfoBody(string appId, string deviceId, string signature, string taskId)
        {
            return "{"
                + "\"app_id\":" + ToJsonInt64Literal(appId) + ","
                + "\"device_id\":" + ToJsonInt64Literal(deviceId) + ","
                + "\"signature\":\"" + EscapeJson(signature) + "\","
                + "\"task_id\":\"" + EscapeJson(taskId) + "\""
                + "}";
        }

        private static string ToJsonInt64Literal(string value)
        {
            return NormalizeInt64String(value);
        }

        private static string NormalizeInt64String(string value)
        {
            string trimmed = (value ?? string.Empty).Trim();
            if (long.TryParse(trimmed, out long parsed) && parsed >= 0)
            {
                return parsed.ToString();
            }

            byte[] bytes = Encoding.UTF8.GetBytes(trimmed);
            using System.Security.Cryptography.SHA256 sha256 = System.Security.Cryptography.SHA256.Create();
            byte[] hash = sha256.ComputeHash(bytes);
            long normalized = BitConverter.ToInt64(hash, 0) & long.MaxValue;
            return normalized.ToString();
        }

        private static string EscapeJson(string value)
        {
            return (value ?? string.Empty)
                .Replace("\\", "\\\\")
                .Replace("\"", "\\\"")
                .Replace("\r", "\\r")
                .Replace("\n", "\\n");
        }

        private static string FirstNonEmpty(params string[] values)
        {
            if (values == null)
            {
                return string.Empty;
            }

            for (int i = 0; i < values.Length; i++)
            {
                if (!string.IsNullOrWhiteSpace(values[i]))
                {
                    return values[i];
                }
            }

            return string.Empty;
        }

        private static string NormalizeServiceUrl(string value)
        {
            if (string.IsNullOrWhiteSpace(value))
            {
                return string.Empty;
            }

            return value.Trim().Trim('`').Trim();
        }

        private static string CreateServiceError(string endpoint, int code, string message)
        {
            return "AI Split " + endpoint + " failed with code " + code + ": " + (message ?? string.Empty);
        }

        [Serializable]
        private sealed class AiSplitGenerateResponseDto
        {
            public int code;
            public string message;
            public string msg;
            public string request_id;
            public AiSplitGenerateDataDto data;

            public string ErrorMessage => FirstNonEmpty(message, msg);
        }

        [Serializable]
        private sealed class AiSplitUploadResponseDto
        {
            public int code;
            public string message;
            public string msg;
            public AiSplitUploadDataDto data;
        }

        [Serializable]
        private sealed class AiSplitUploadDataDto
        {
            public string image_url;
            public string imageUrl;
            public string url;
            public string public_url;
            public string publicUrl;
            public string download_url;
            public string downloadUrl;
            public string file_url;
            public string fileUrl;
        }

        [Serializable]
        private sealed class AiSplitGenerateDataDto
        {
            public string task_id;
        }

        [Serializable]
        private sealed class AiSplitInfoResponseDto
        {
            public int code;
            public string message;
            public string msg;
            public string request_id;
            public AiSplitInfoDataDto data;

            public string ErrorMessage => FirstNonEmpty(message, msg);
        }

        [Serializable]
        private sealed class AiSplitInfoDataDto
        {
            public string task_id;
            public int progress;
            public string model_version;
            public AiSplitRemoteAssetDto[] layer;
            public AiSplitRemoteAssetDto[] layers;
            public AiSplitRemoteAssetDto[] sdf;
            public AiSplitRemoteAssetDto[] sdfs;
        }

        [Serializable]
        private sealed class AiSplitRemoteAssetDto
        {
            public string url;
            public string md5;
        }
    }
}
