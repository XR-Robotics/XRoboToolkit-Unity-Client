using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using NUnit.Framework;
using UnityEditor;
using UnityEngine;

namespace ByteDance.PICO.IconConfigurator.Editor.Tests
{
    public class RealIconAiSplitServiceTests
    {
        [TearDown]
        public void TearDown()
        {
            if (AssetDatabase.IsValidFolder("Assets/IconConfigurator/Generated/config-guid"))
            {
                AssetDatabase.DeleteAsset("Assets/IconConfigurator/Generated/config-guid");
            }

            AssetDatabase.Refresh();
        }

        [Test]
        public void PreparePng_WhenSourceIsNonSquare_NormalizesToSquarePngUsingImportConstraints()
        {
            Texture2D source = CreateTexture(2, 4, new Color(0.2f, 0.4f, 0.8f, 1f));
            IconLayerConfig layer = new IconLayerConfig
            {
                Texture = source,
                OriginalFileName = "flat source.png",
            };

            AiSplitPreparedImage prepared = AiSplitFlatImagePreparer.PreparePng(layer);

            Assert.That(prepared.FileName, Is.EqualTo("flat_source.png"));
            Assert.That(prepared.PngBytes, Is.Not.Empty);
            Texture2D decoded = new Texture2D(2, 2, TextureFormat.RGBA32, false);
            Assert.That(decoded.LoadImage(prepared.PngBytes), Is.True);
            Assert.That(decoded.width, Is.EqualTo(512));
            Assert.That(decoded.height, Is.EqualTo(512));
            UnityEngine.Object.DestroyImmediate(decoded);
            UnityEngine.Object.DestroyImmediate(source);
        }

        [Test]
        public void Upload_WhenCalled_BuildsObjectKeyFromDirectoryTimestampAndFileNameWithConnectionClose()
        {
            FakeTosClient tosClient = new FakeTosClient();
            AiSplitTosUploader uploader = new AiSplitTosUploader(tosClient, () => 1781090000123L);
            AiSplitTosConfig config = new AiSplitTosConfig
            {
                BucketName = "bucket-name",
                ObjectDirectory = "icons/generated/",
                PublicBaseUrl = "https://cdn.example.test/base/",
            };

            AiSplitTosUploadResult result = uploader.Upload(config, "flat source.png", new byte[] { 1, 2, 3 });

            Assert.That(tosClient.LastBucketName, Is.EqualTo("bucket-name"));
            Assert.That(tosClient.LastObjectKey, Is.EqualTo("icons/generated/ai_split_1781090000123_flat_source.png"));
            Assert.That(tosClient.LastHeaders["Connection"], Is.EqualTo("close"));
            Assert.That(result.ObjectKey, Is.EqualTo(tosClient.LastObjectKey));
            Assert.That(result.PublicUrl, Is.EqualTo("https://cdn.example.test/base/icons/generated/ai_split_1781090000123_flat_source.png"));
        }

        [Test]
        public void StartGenerate_WhenInfoSucceeds_UploadsThenPostsGenerateAndPollsInfoWithoutRealNetwork()
        {
            FakeTosUploader tosUploader = new FakeTosUploader("https://cdn.example.test/flat.png");
            FakeAiSplitHttpClient httpClient = new FakeAiSplitHttpClient();
            FakeAiSplitAssetDownloader assetDownloader = new FakeAiSplitAssetDownloader();
            assetDownloader.AddPng("https://cdn.example.test/fg.png", Color.red);
            assetDownloader.AddPng("https://cdn.example.test/bg.png", Color.blue);
            assetDownloader.AddPng("https://cdn.example.test/fg-sdf.png", Color.white);
            assetDownloader.AddPng("https://cdn.example.test/bg-sdf.png", Color.gray);
            httpClient.EnqueueJson(0, "{\"code\":0,\"message\":\"ok\",\"request_id\":\"request-gen\",\"data\":{\"task_id\":\"task-1\"}}");
            httpClient.EnqueueJson(0, "{\"code\":0,\"message\":\"ok\",\"request_id\":\"request-info\",\"data\":{\"task_id\":\"task-1\",\"progress\":100,\"model_version\":\"model-v1\",\"layer\":[{\"url\":\"https://cdn.example.test/fg.png\",\"md5\":\"fg\"},{\"url\":\"https://cdn.example.test/bg.png\",\"md5\":\"bg\"}],\"sdf\":[{\"url\":\"https://cdn.example.test/fg-sdf.png\",\"md5\":\"fgs\"},{\"url\":\"https://cdn.example.test/bg-sdf.png\",\"md5\":\"bgs\"}]}}");
            RealIconAiSplitService service = CreateService(httpClient, tosUploader, assetDownloader: assetDownloader);
            IconAiSplitResult result = null;
            string successRequestId = null;
            List<float> progressValues = new List<float>();

            service.StartGenerate(CreateSourceLayer(), "config-guid", progressValues.Add, (value, requestId, _) =>
            {
                result = value;
                successRequestId = requestId;
            }, Assert.Fail);

            Assert.That(tosUploader.UploadCount, Is.EqualTo(1));
            Assert.That(httpClient.Requests, Has.Count.EqualTo(2));
            Assert.That(httpClient.Requests[0].Url, Is.EqualTo("https://api.example.test/sdf/gen"));
            Assert.That(httpClient.Requests[1].Url, Is.EqualTo("https://api.example.test/sdf/info"));
            Assert.That(httpClient.Requests[0].Headers["X-Tt-Env"], Is.EqualTo("ppe"));
            Assert.That(httpClient.Requests[0].Headers["X-Use-Ppe"], Is.EqualTo("1"));
            Assert.That(httpClient.Requests[0].Body, Does.Contain("\"image_url\":\"https://cdn.example.test/flat.png\""));
            Assert.That(httpClient.Requests[0].Body, Does.Contain("\"app_id\":556443"));
            Assert.That(httpClient.Requests[0].Body, Does.Contain("\"device_id\":1234567890123456"));
            Assert.That(httpClient.Requests[0].Body, Does.Contain("\"signature\":\""));
            Assert.That(httpClient.Requests[1].Body, Does.Contain("\"app_id\":556443"));
            Assert.That(httpClient.Requests[1].Body, Does.Contain("\"device_id\":1234567890123456"));
            Assert.That(httpClient.Requests[1].Body, Does.Contain("\"task_id\":\"task-1\""));
            Assert.That(result, Is.Not.Null);
            Assert.That(result.TaskId, Is.EqualTo("task-1"));
            Assert.That(result.RequestId, Is.EqualTo("request-info"));
            Assert.That(result.ModelVersion, Is.EqualTo("model-v1"));
            Assert.That(result.Layers, Has.Count.EqualTo(2));
            Assert.That(result.Sdfs, Has.Count.EqualTo(2));
            Assert.That(result.Layers[0].AssetPath, Does.EndWith("/background.png"));
            Assert.That(result.Layers[0].ContentHash, Is.EqualTo("bg"));
            Assert.That(successRequestId, Is.EqualTo("request-info"));
            Assert.That(progressValues, Does.Contain(0.05f));
            Assert.That(progressValues, Does.Contain(0.15f));
            Assert.That(progressValues, Does.Contain(0.3f));
            Assert.That(progressValues, Does.Contain(0.95f));
            Assert.That(progressValues[progressValues.Count - 1], Is.EqualTo(1f));
        }

        [Test]
        public void StartGenerate_WhenApiConfigUsesFullUrls_PostsDirectUrlsAndAddsPpeHeadersFromTtEnv()
        {
            FakeTosUploader tosUploader = new FakeTosUploader("https://cdn.example.test/flat.png");
            FakeAiSplitHttpClient httpClient = new FakeAiSplitHttpClient();
            FakeAiSplitAssetDownloader assetDownloader = new FakeAiSplitAssetDownloader();
            assetDownloader.AddPng("https://cdn.example.test/fg.png", Color.red);
            assetDownloader.AddPng("https://cdn.example.test/bg.png", Color.blue);
            assetDownloader.AddPng("https://cdn.example.test/fg-sdf.png", Color.white);
            assetDownloader.AddPng("https://cdn.example.test/bg-sdf.png", Color.gray);
            httpClient.EnqueueJson(0, "{\"code\":0,\"message\":\"ok\",\"request_id\":\"request-gen\",\"data\":{\"task_id\":\"task-full-url\"}}");
            httpClient.EnqueueJson(0, "{\"code\":0,\"message\":\"ok\",\"request_id\":\"request-info\",\"data\":{\"task_id\":\"task-full-url\",\"progress\":100,\"layer\":[{\"url\":\"https://cdn.example.test/fg.png\",\"md5\":\"fg\"},{\"url\":\"https://cdn.example.test/bg.png\",\"md5\":\"bg\"}],\"sdf\":[{\"url\":\"https://cdn.example.test/fg-sdf.png\",\"md5\":\"fgs\"},{\"url\":\"https://cdn.example.test/bg-sdf.png\",\"md5\":\"bgs\"}]}}");
            AiSplitTccConfig config = CreateConfig();
            config.Api.GeneratePath = "https://direct.example.test/sdf/gen";
            config.Api.InfoPath = "https://direct.example.test/sdf/info";
            AiSplitRegionConfig region = CreateRegion();
            region.ApiBaseUrl = "https://api.example.test/base";
            region.TtEnv = "ppe_direct";
            region.UsePpe = false;
            RealIconAiSplitService service = CreateService(
                httpClient,
                tosUploader,
                assetDownloader: assetDownloader,
                config: config,
                region: region);

            service.StartGenerate(CreateSourceLayer(), "config-guid", _ => { }, (_, _, _) => { }, Assert.Fail);

            Assert.That(httpClient.Requests, Has.Count.EqualTo(2));
            Assert.That(httpClient.Requests[0].Url, Is.EqualTo("https://direct.example.test/sdf/gen"));
            Assert.That(httpClient.Requests[1].Url, Is.EqualTo("https://direct.example.test/sdf/info"));
            Assert.That(httpClient.Requests[0].Headers["X-Tt-Env"], Is.EqualTo("ppe_direct"));
            Assert.That(httpClient.Requests[0].Headers["X-Use-Ppe"], Is.EqualTo("1"));
            Assert.That(httpClient.Requests[1].Headers["X-Tt-Env"], Is.EqualTo("ppe_direct"));
            Assert.That(httpClient.Requests[1].Headers["X-Use-Ppe"], Is.EqualTo("1"));
        }

        [Test]
        public void StartGenerate_WhenTosIsUnavailableAndUploadSucceeds_UsesReturnedImageUrl()
        {
            FakeTosUploader tosUploader = new FakeTosUploader("https://cdn.example.test/flat.png");
            FakeAiSplitHttpClient httpClient = new FakeAiSplitHttpClient();
            FakeAiSplitAssetDownloader assetDownloader = new FakeAiSplitAssetDownloader();
            assetDownloader.AddPng("https://cdn.example.test/fg.png", Color.red);
            assetDownloader.AddPng("https://cdn.example.test/bg.png", Color.blue);
            assetDownloader.AddPng("https://cdn.example.test/fg-sdf.png", Color.white);
            assetDownloader.AddPng("https://cdn.example.test/bg-sdf.png", Color.gray);
            httpClient.EnqueueJson(0, "{\"code\":0,\"message\":\"ok\",\"data\":{\"image_url\":\"https://upload.example.test/flat.png\"}}");
            httpClient.EnqueueJson(0, "{\"code\":0,\"message\":\"ok\",\"request_id\":\"request-gen\",\"data\":{\"task_id\":\"task-upload\"}}");
            httpClient.EnqueueJson(0, "{\"code\":0,\"message\":\"ok\",\"request_id\":\"request-info\",\"data\":{\"task_id\":\"task-upload\",\"progress\":100,\"layer\":[{\"url\":\"https://cdn.example.test/fg.png\",\"md5\":\"fg\"},{\"url\":\"https://cdn.example.test/bg.png\",\"md5\":\"bg\"}],\"sdf\":[{\"url\":\"https://cdn.example.test/fg-sdf.png\",\"md5\":\"fgs\"},{\"url\":\"https://cdn.example.test/bg-sdf.png\",\"md5\":\"bgs\"}]}}");
            AiSplitTccConfig config = CreateConfig();
            config.Tos = new AiSplitTosConfig();
            RealIconAiSplitService service = CreateService(httpClient, tosUploader, assetDownloader: assetDownloader, config: config);

            service.StartGenerate(CreateSourceLayer(), "config-guid", _ => { }, (_, _, _) => { }, Assert.Fail);

            Assert.That(tosUploader.UploadCount, Is.EqualTo(0));
            Assert.That(httpClient.Requests, Has.Count.EqualTo(3));
            Assert.That(httpClient.Requests[0].Url, Is.EqualTo("https://api.example.test/sdf/upload"));
            Assert.That(httpClient.Requests[0].Body, Does.Contain("\"img_bytes\":\""));
            Assert.That(httpClient.Requests[0].Body, Does.Not.Contain("\"img_base64\":\""));
            Assert.That(httpClient.Requests[1].Body, Does.Contain("\"image_url\":\"https://upload.example.test/flat.png\""));
            Assert.That(httpClient.Requests[1].Body, Does.Not.Contain("\"img_base64\":\""));
        }

        [Test]
        public void StartGenerate_WhenTosIsUnavailableAndUploadReturns404_FallsBackToImgBase64GenerateBody()
        {
            FakeTosUploader tosUploader = new FakeTosUploader("https://cdn.example.test/flat.png");
            FakeAiSplitHttpClient httpClient = new FakeAiSplitHttpClient();
            FakeAiSplitAssetDownloader assetDownloader = new FakeAiSplitAssetDownloader();
            assetDownloader.AddPng("https://cdn.example.test/fg.png", Color.red);
            assetDownloader.AddPng("https://cdn.example.test/bg.png", Color.blue);
            assetDownloader.AddPng("https://cdn.example.test/fg-sdf.png", Color.white);
            assetDownloader.AddPng("https://cdn.example.test/bg-sdf.png", Color.gray);
            httpClient.EnqueueJson(404, "404 page not found");
            httpClient.EnqueueJson(0, "{\"code\":0,\"message\":\"ok\",\"request_id\":\"request-gen\",\"data\":{\"task_id\":\"task-base64\"}}");
            httpClient.EnqueueJson(0, "{\"code\":0,\"message\":\"ok\",\"request_id\":\"request-info\",\"data\":{\"task_id\":\"task-base64\",\"progress\":100,\"layer\":[{\"url\":\"https://cdn.example.test/fg.png\",\"md5\":\"fg\"},{\"url\":\"https://cdn.example.test/bg.png\",\"md5\":\"bg\"}],\"sdf\":[{\"url\":\"https://cdn.example.test/fg-sdf.png\",\"md5\":\"fgs\"},{\"url\":\"https://cdn.example.test/bg-sdf.png\",\"md5\":\"bgs\"}]}}");
            AiSplitTccConfig config = CreateConfig();
            config.Tos = new AiSplitTosConfig();
            RealIconAiSplitService service = CreateService(httpClient, tosUploader, assetDownloader: assetDownloader, config: config);

            service.StartGenerate(CreateSourceLayer(), "config-guid", _ => { }, (_, _, _) => { }, Assert.Fail);

            Assert.That(tosUploader.UploadCount, Is.EqualTo(0));
            Assert.That(httpClient.Requests, Has.Count.EqualTo(3));
            Assert.That(httpClient.Requests[0].Url, Is.EqualTo("https://api.example.test/sdf/upload"));
            Assert.That(httpClient.Requests[1].Url, Is.EqualTo("https://api.example.test/sdf/gen"));
            Assert.That(httpClient.Requests[1].Body, Does.Contain("\"img_bytes\":\""));
            Assert.That(httpClient.Requests[1].Body, Does.Not.Contain("\"img_base64\":\""));
            Assert.That(httpClient.Requests[1].Body, Does.Not.Contain("\"image_url\":\""));
        }

        [Test]
        public void StartGenerate_WhenInfoReturnsForegroundFirst_DownloadsImportsAndStoresBackgroundFirst()
        {
            FakeTosUploader tosUploader = new FakeTosUploader("https://cdn.example.test/flat.png");
            FakeAiSplitHttpClient httpClient = new FakeAiSplitHttpClient();
            FakeAiSplitAssetDownloader assetDownloader = new FakeAiSplitAssetDownloader();
            assetDownloader.AddPng("https://cdn.example.test/fg.png", Color.red);
            assetDownloader.AddPng("https://cdn.example.test/mid.png", Color.green);
            assetDownloader.AddPng("https://cdn.example.test/bg.png", Color.blue);
            assetDownloader.AddPng("https://cdn.example.test/fg-sdf.png", Color.white);
            assetDownloader.AddPng("https://cdn.example.test/mid-sdf.png", Color.gray);
            assetDownloader.AddPng("https://cdn.example.test/bg-sdf.png", Color.black);
            httpClient.EnqueueJson(0, "{\"code\":0,\"message\":\"ok\",\"request_id\":\"request-gen\",\"data\":{\"task_id\":\"task-asset\"}}");
            httpClient.EnqueueJson(0, "{\"code\":0,\"message\":\"ok\",\"request_id\":\"request-info\",\"data\":{\"task_id\":\"task-asset\",\"progress\":100,\"model_version\":\"model-v2\",\"layer\":[{\"url\":\"https://cdn.example.test/fg.png\",\"md5\":\"fg\"},{\"url\":\"https://cdn.example.test/mid.png\",\"md5\":\"mid\"},{\"url\":\"https://cdn.example.test/bg.png\",\"md5\":\"bg\"}],\"sdf\":[{\"url\":\"https://cdn.example.test/fg-sdf.png\",\"md5\":\"fgs\"},{\"url\":\"https://cdn.example.test/mid-sdf.png\",\"md5\":\"mids\"},{\"url\":\"https://cdn.example.test/bg-sdf.png\",\"md5\":\"bgs\"}]}}");
            RealIconAiSplitService service = CreateService(httpClient, tosUploader, assetDownloader: assetDownloader);
            IconAiSplitResult result = null;

            service.StartGenerate(CreateSourceLayer(), "config-guid", _ => { }, (value, _, _) => result = value, Assert.Fail);

            Assert.That(result, Is.Not.Null);
            Assert.That(assetDownloader.DownloadedUrls, Is.EqualTo(new[]
            {
                "https://cdn.example.test/fg.png",
                "https://cdn.example.test/mid.png",
                "https://cdn.example.test/bg.png",
                "https://cdn.example.test/fg-sdf.png",
                "https://cdn.example.test/mid-sdf.png",
                "https://cdn.example.test/bg-sdf.png",
            }));
            Assert.That(result.Layers[0].ContentHash, Is.EqualTo("bg"));
            Assert.That(result.Layers[1].ContentHash, Is.EqualTo("mid"));
            Assert.That(result.Layers[2].ContentHash, Is.EqualTo("fg"));
            Assert.That(result.Sdfs[0].ContentHash, Is.EqualTo("bgs"));
            Assert.That(result.Sdfs[1].ContentHash, Is.EqualTo("mids"));
            Assert.That(result.Sdfs[2].ContentHash, Is.EqualTo("fgs"));
            Assert.That(result.Background, Is.SameAs(result.Layers[0]));
            Assert.That(result.Foreground1, Is.SameAs(result.Layers[1]));
            Assert.That(result.Foreground2, Is.SameAs(result.Layers[2]));
            AssertImportedTexture(result.Layers[0].AssetPath);
            AssertImportedTexture(result.Sdfs[0].AssetPath);
            Assert.That(result.Layers[0].AssetPath, Does.StartWith("Assets/IconConfigurator/Generated/config-guid/ai-split/task-asset/layers/"));
            Assert.That(result.Sdfs[0].AssetPath, Does.StartWith("Assets/IconConfigurator/Generated/config-guid/ai-split/task-asset/sdf/"));
        }

        [Test]
        public void StartGenerate_WhenResultCountIsOutsideSupportedRange_ReportsValidationErrorWithoutSuccess()
        {
            FakeTosUploader tosUploader = new FakeTosUploader("https://cdn.example.test/flat.png");
            FakeAiSplitHttpClient httpClient = new FakeAiSplitHttpClient();
            FakeAiSplitAssetDownloader assetDownloader = new FakeAiSplitAssetDownloader();
            assetDownloader.AddPng("https://cdn.example.test/only.png", Color.red);
            assetDownloader.AddPng("https://cdn.example.test/only-sdf.png", Color.white);
            httpClient.EnqueueJson(0, "{\"code\":0,\"message\":\"ok\",\"request_id\":\"request-gen\",\"data\":{\"task_id\":\"task-invalid\"}}");
            httpClient.EnqueueJson(0, "{\"code\":0,\"message\":\"ok\",\"request_id\":\"request-info\",\"data\":{\"task_id\":\"task-invalid\",\"progress\":100,\"layer\":[{\"url\":\"https://cdn.example.test/only.png\",\"md5\":\"only\"}],\"sdf\":[{\"url\":\"https://cdn.example.test/only-sdf.png\",\"md5\":\"only-sdf\"}]}}");
            RealIconAiSplitService service = CreateService(httpClient, tosUploader, assetDownloader: assetDownloader);
            bool succeeded = false;
            string errorMessage = string.Empty;

            service.StartGenerate(CreateSourceLayer(), "config-guid", _ => { }, (_, _, _) => succeeded = true, error => errorMessage = error);

            Assert.That(succeeded, Is.False);
            Assert.That(errorMessage, Does.Contain("between 2 and 3"));
            Assert.That(assetDownloader.DownloadedUrls, Is.Empty);
            Assert.That(AssetDatabase.IsValidFolder("Assets/IconConfigurator/Generated/config-guid/ai-split/task-invalid"), Is.False);
        }

        [Test]
        public void StartGenerate_WhenResultCountExceedsThreeLayers_ReportsValidationErrorWithoutSuccess()
        {
            FakeTosUploader tosUploader = new FakeTosUploader("https://cdn.example.test/flat.png");
            FakeAiSplitHttpClient httpClient = new FakeAiSplitHttpClient();
            FakeAiSplitAssetDownloader assetDownloader = new FakeAiSplitAssetDownloader();
            assetDownloader.AddPng("https://cdn.example.test/fg.png", Color.red);
            assetDownloader.AddPng("https://cdn.example.test/mid.png", Color.green);
            assetDownloader.AddPng("https://cdn.example.test/bg.png", Color.blue);
            assetDownloader.AddPng("https://cdn.example.test/extra.png", Color.yellow);
            assetDownloader.AddPng("https://cdn.example.test/fg-sdf.png", Color.white);
            assetDownloader.AddPng("https://cdn.example.test/mid-sdf.png", Color.gray);
            assetDownloader.AddPng("https://cdn.example.test/bg-sdf.png", Color.black);
            assetDownloader.AddPng("https://cdn.example.test/extra-sdf.png", new Color(0.25f, 0.25f, 0.25f, 1f));
            httpClient.EnqueueJson(0, "{\"code\":0,\"message\":\"ok\",\"request_id\":\"request-gen\",\"data\":{\"task_id\":\"task-too-many\"}}");
            httpClient.EnqueueJson(0, "{\"code\":0,\"message\":\"ok\",\"request_id\":\"request-info\",\"data\":{\"task_id\":\"task-too-many\",\"progress\":100,\"layer\":[{\"url\":\"https://cdn.example.test/fg.png\",\"md5\":\"fg\"},{\"url\":\"https://cdn.example.test/mid.png\",\"md5\":\"mid\"},{\"url\":\"https://cdn.example.test/bg.png\",\"md5\":\"bg\"},{\"url\":\"https://cdn.example.test/extra.png\",\"md5\":\"extra\"}],\"sdf\":[{\"url\":\"https://cdn.example.test/fg-sdf.png\",\"md5\":\"fgs\"},{\"url\":\"https://cdn.example.test/mid-sdf.png\",\"md5\":\"mids\"},{\"url\":\"https://cdn.example.test/bg-sdf.png\",\"md5\":\"bgs\"},{\"url\":\"https://cdn.example.test/extra-sdf.png\",\"md5\":\"extras\"}]}}");
            RealIconAiSplitService service = CreateService(httpClient, tosUploader, assetDownloader: assetDownloader);
            bool succeeded = false;
            string errorMessage = string.Empty;

            service.StartGenerate(CreateSourceLayer(), "config-guid", _ => { }, (_, _, _) => succeeded = true, error => errorMessage = error);

            Assert.That(succeeded, Is.False);
            Assert.That(errorMessage, Does.Contain("between 2 and 3"));
            Assert.That(assetDownloader.DownloadedUrls, Is.Empty);
            Assert.That(AssetDatabase.IsValidFolder("Assets/IconConfigurator/Generated/config-guid/ai-split/task-too-many"), Is.False);
        }

        [Test]
        public void StartGenerate_WhenProgressCallbackCancels_StopsPollingAndReportsCancelled()
        {
            FakeTosUploader tosUploader = new FakeTosUploader("https://cdn.example.test/flat.png");
            FakeAiSplitHttpClient httpClient = new FakeAiSplitHttpClient();
            httpClient.EnqueueJson(0, "{\"code\":0,\"message\":\"ok\",\"request_id\":\"request-gen\",\"data\":{\"task_id\":\"task-1\"}}");
            httpClient.EnqueueJson(0, "{\"code\":10002,\"message\":\"processing\",\"request_id\":\"request-info\",\"data\":{\"task_id\":\"task-1\",\"progress\":42}}");
            RealIconAiSplitService service = CreateService(httpClient, tosUploader);
            string errorMessage = string.Empty;

            service.StartGenerate(CreateSourceLayer(), "config-guid", _ => service.Cancel(), (_, _, _) =>
            {
                Assert.Fail("Cancelled generation should not succeed.");
            }, error => errorMessage = error);

            Assert.That(errorMessage, Does.Contain("cancelled").IgnoreCase);
            Assert.That(httpClient.Requests, Has.Count.EqualTo(2));
            Assert.That(service.IsRunning, Is.False);
        }

        [Test]
        public void StartGenerate_WhenProcessingResponseOmitsProgress_ReportsSimulatedProgressBelowComplete()
        {
            FakeTosUploader tosUploader = new FakeTosUploader("https://cdn.example.test/flat.png");
            FakeAiSplitHttpClient httpClient = new FakeAiSplitHttpClient();
            FakeAiSplitAssetDownloader assetDownloader = new FakeAiSplitAssetDownloader();
            assetDownloader.AddPng("https://cdn.example.test/fg.png", Color.red);
            assetDownloader.AddPng("https://cdn.example.test/bg.png", Color.blue);
            assetDownloader.AddPng("https://cdn.example.test/fg-sdf.png", Color.white);
            assetDownloader.AddPng("https://cdn.example.test/bg-sdf.png", Color.gray);
            httpClient.EnqueueJson(0, "{\"code\":0,\"message\":\"ok\",\"request_id\":\"request-gen\",\"data\":{\"task_id\":\"task-progress\"}}");
            httpClient.EnqueueJson(0, "{\"code\":10002,\"message\":\"processing\",\"request_id\":\"request-info-1\",\"data\":{\"task_id\":\"task-progress\"}}");
            httpClient.EnqueueJson(0, "{\"code\":0,\"message\":\"ok\",\"request_id\":\"request-info-2\",\"data\":{\"task_id\":\"task-progress\",\"progress\":100,\"layer\":[{\"url\":\"https://cdn.example.test/fg.png\",\"md5\":\"fg\"},{\"url\":\"https://cdn.example.test/bg.png\",\"md5\":\"bg\"}],\"sdf\":[{\"url\":\"https://cdn.example.test/fg-sdf.png\",\"md5\":\"fgs\"},{\"url\":\"https://cdn.example.test/bg-sdf.png\",\"md5\":\"bgs\"}]}}");
            RealIconAiSplitService service = CreateService(httpClient, tosUploader, assetDownloader: assetDownloader);
            List<float> progressValues = new List<float>();

            service.StartGenerate(CreateSourceLayer(), "config-guid", progressValues.Add, (_, _, _) => { }, Assert.Fail);

            Assert.That(progressValues, Has.Count.GreaterThanOrEqualTo(2));
            Assert.That(progressValues[0], Is.GreaterThan(0f));
            Assert.That(progressValues[0], Is.LessThan(1f));
            Assert.That(progressValues[progressValues.Count - 1], Is.EqualTo(1f));
        }

        [Test]
        public void StartGenerate_WhenPollingExceedsTimeout_ReportsTimeout()
        {
            FakeTosUploader tosUploader = new FakeTosUploader("https://cdn.example.test/flat.png");
            FakeAiSplitHttpClient httpClient = new FakeAiSplitHttpClient();
            httpClient.EnqueueJson(0, "{\"code\":0,\"message\":\"ok\",\"request_id\":\"request-gen\",\"data\":{\"task_id\":\"task-1\"}}");
            httpClient.EnqueueJson(0, "{\"code\":10002,\"message\":\"processing\",\"request_id\":\"request-info-1\",\"data\":{\"task_id\":\"task-1\",\"progress\":10}}");
            httpClient.EnqueueJson(0, "{\"code\":10002,\"message\":\"processing\",\"request_id\":\"request-info-2\",\"data\":{\"task_id\":\"task-1\",\"progress\":20}}");
            FakeAiSplitClock clock = new FakeAiSplitClock(new DateTime(2026, 6, 10, 10, 0, 0, DateTimeKind.Utc));
            RealIconAiSplitService service = CreateService(httpClient, tosUploader, clock, new AdvancingDelay(clock, TimeSpan.FromSeconds(301)));
            string errorMessage = string.Empty;

            service.StartGenerate(CreateSourceLayer(), "config-guid", _ => { }, (_, _, _) =>
            {
                Assert.Fail("Timed out generation should not succeed.");
            }, error => errorMessage = error);

            Assert.That(errorMessage, Does.Contain("timed out"));
            Assert.That(service.IsRunning, Is.False);
        }

        [Test]
        public void StartGenerate_WhenDefaultRunnerUsed_ReturnsBeforeHttpPostCompletes()
        {
            FakeTosUploader tosUploader = new FakeTosUploader("https://cdn.example.test/flat.png");
            BlockingAiSplitHttpClient httpClient = new BlockingAiSplitHttpClient();
            RealIconAiSplitService service = new RealIconAiSplitService(
                () => AiSplitTccLoadResult.Loaded(CreateConfig(), CreateRegion()),
                tosUploader,
                httpClient,
                new AiSplitDeviceIdProvider(() => "1234567890123456"),
                new AiSplitGenerationRateLimiter(() => DateTime.UtcNow),
                new FakeAiSplitClock(new DateTime(2026, 6, 10, 10, 0, 0, DateTimeKind.Utc)),
                new NoOpDelay(),
                new FakeAiSplitAssetDownloader(),
                mainThreadDispatcher: new ImmediateAiSplitMainThreadDispatcher());

            service.StartGenerate(CreateSourceLayer(), "config-guid", _ => { }, (_, _, _) => { }, _ => { });

            Assert.That(service.IsRunning, Is.True);
            Assert.That(httpClient.PostStarted.WaitOne(1000), Is.True);
            Assert.That(httpClient.PostCompleted, Is.False);
            httpClient.Release();
        }

        private static RealIconAiSplitService CreateService(
            IAiSplitHttpClient httpClient,
            IAiSplitTosUploader tosUploader,
            IAiSplitClock clock = null,
            IAiSplitDelay delay = null,
            IAiSplitAssetDownloader assetDownloader = null,
            AiSplitTccConfig config = null,
            AiSplitRegionConfig region = null,
            IAiSplitGenerationRunner generationRunner = null,
            IAiSplitMainThreadDispatcher mainThreadDispatcher = null)
        {
            return new RealIconAiSplitService(
                () => AiSplitTccLoadResult.Loaded(config ?? CreateConfig(), region ?? CreateRegion()),
                tosUploader,
                httpClient,
                new AiSplitDeviceIdProvider(() => "1234567890123456"),
                new AiSplitGenerationRateLimiter(() => DateTime.UtcNow),
                clock ?? new FakeAiSplitClock(new DateTime(2026, 6, 10, 10, 0, 0, DateTimeKind.Utc)),
                delay ?? new NoOpDelay(),
                assetDownloader ?? new FakeAiSplitAssetDownloader(),
                generationRunner ?? new ImmediateAiSplitGenerationRunner(),
                mainThreadDispatcher ?? new ImmediateAiSplitMainThreadDispatcher());
        }

        private static void AssertImportedTexture(string assetPath)
        {
            Assert.That(File.Exists(assetPath), Is.True);
            Texture2D texture = AssetDatabase.LoadAssetAtPath<Texture2D>(assetPath);
            Assert.That(texture, Is.Not.Null);
            TextureImporter importer = AssetImporter.GetAtPath(assetPath) as TextureImporter;
            Assert.That(importer, Is.Not.Null);
            Assert.That(importer.isReadable, Is.True);
            Assert.That(importer.alphaIsTransparency, Is.True);
            Assert.That(importer.mipmapEnabled, Is.False);
            Assert.That(importer.textureCompression, Is.EqualTo(TextureImporterCompression.Uncompressed));
        }

        private static AiSplitTccConfig CreateConfig()
        {
            return new AiSplitTccConfig
            {
                Enable = true,
                Api = new AiSplitApiConfig
                {
                    GeneratePath = "/sdf/gen",
                    InfoPath = "/sdf/info",
                },
                Timeouts = new AiSplitTimeoutConfig
                {
                    ConnectTimeoutSeconds = 3,
                    ReadTimeoutSeconds = 30,
                    PollIntervalSeconds = 1,
                    TotalTimeoutSeconds = 300,
                },
                Tos = new AiSplitTosConfig
                {
                    BucketName = "bucket",
                    ObjectDirectory = "icons/",
                    PublicBaseUrl = "https://cdn.example.test/",
                },
                Signing = new AiSplitSigningConfig
                {
                    AppId = "556443",
                    Salt = "salt",
                },
            };
        }

        private static AiSplitRegionConfig CreateRegion()
        {
            return new AiSplitRegionConfig
            {
                Region = "cn",
                ApiBaseUrl = "https://api.example.test",
                TtEnv = "ppe",
                UsePpe = true,
            };
        }

        private static IconLayerConfig CreateSourceLayer()
        {
            return new IconLayerConfig
            {
                Texture = CreateTexture(2, 2, Color.white),
                OriginalFileName = "flat.png",
            };
        }

        private static Texture2D CreateTexture(int width, int height, Color color)
        {
            Texture2D texture = new Texture2D(width, height, TextureFormat.RGBA32, false);
            Color[] pixels = new Color[width * height];
            for (int i = 0; i < pixels.Length; i++)
            {
                pixels[i] = color;
            }

            texture.SetPixels(pixels);
            texture.Apply();
            return texture;
        }

        private sealed class FakeTosClient : IAiSplitTosClient
        {
            public string LastBucketName { get; private set; }

            public string LastObjectKey { get; private set; }

            public Dictionary<string, string> LastHeaders { get; private set; }

            public void PutObject(string bucketName, string objectKey, byte[] bytes, Dictionary<string, string> headers)
            {
                LastBucketName = bucketName;
                LastObjectKey = objectKey;
                LastHeaders = headers;
            }
        }

        private sealed class FakeTosUploader : IAiSplitTosUploader
        {
            private readonly string m_publicUrl;

            public FakeTosUploader(string publicUrl)
            {
                m_publicUrl = publicUrl;
            }

            public int UploadCount { get; private set; }

            public AiSplitTosUploadResult Upload(AiSplitTosConfig config, string fileName, byte[] pngBytes)
            {
                UploadCount++;
                return new AiSplitTosUploadResult("icons/flat.png", m_publicUrl);
            }
        }

        private sealed class FakeAiSplitHttpClient : IAiSplitHttpClient
        {
            private readonly Queue<AiSplitHttpResponse> m_responses = new Queue<AiSplitHttpResponse>();

            public List<AiSplitHttpRequest> Requests { get; } = new List<AiSplitHttpRequest>();

            public void EnqueueJson(int statusCode, string body)
            {
                m_responses.Enqueue(new AiSplitHttpResponse(statusCode, Encoding.UTF8.GetBytes(body), false));
            }

            public AiSplitHttpResponse Post(AiSplitHttpRequest request)
            {
                Requests.Add(request);
                return m_responses.Dequeue();
            }
        }

        private sealed class BlockingAiSplitHttpClient : IAiSplitHttpClient
        {
            private readonly System.Threading.ManualResetEvent m_release = new System.Threading.ManualResetEvent(false);

            public System.Threading.ManualResetEvent PostStarted { get; } = new System.Threading.ManualResetEvent(false);

            public bool PostCompleted { get; private set; }

            public AiSplitHttpResponse Post(AiSplitHttpRequest request)
            {
                PostStarted.Set();
                m_release.WaitOne();
                PostCompleted = true;
                return new AiSplitHttpResponse(
                    0,
                    Encoding.UTF8.GetBytes("{\"code\":0,\"message\":\"ok\",\"data\":{\"task_id\":\"task-1\"}}"),
                    false);
            }

            public void Release()
            {
                m_release.Set();
            }
        }

        private sealed class FakeAiSplitAssetDownloader : IAiSplitAssetDownloader
        {
            private readonly Dictionary<string, byte[]> m_assets = new Dictionary<string, byte[]>();

            public List<string> DownloadedUrls { get; } = new List<string>();

            public void AddPng(string url, Color color)
            {
                Texture2D texture = CreateTexture(4, 4, color);
                m_assets[url] = texture.EncodeToPNG();
                UnityEngine.Object.DestroyImmediate(texture);
            }

            public byte[] Download(string url, int connectTimeoutSeconds, int readTimeoutSeconds)
            {
                DownloadedUrls.Add(url);
                return m_assets[url];
            }
        }

        private sealed class FakeAiSplitClock : IAiSplitClock
        {
            public FakeAiSplitClock(DateTime utcNow)
            {
                UtcNow = utcNow;
            }

            public DateTime UtcNow { get; private set; }

            public long UnixMilliseconds => new DateTimeOffset(UtcNow).ToUnixTimeMilliseconds();

            public void Advance(TimeSpan value)
            {
                UtcNow = UtcNow.Add(value);
            }
        }

        private sealed class NoOpDelay : IAiSplitDelay
        {
            public void Delay(TimeSpan value)
            {
            }
        }

        private sealed class AdvancingDelay : IAiSplitDelay
        {
            private readonly FakeAiSplitClock m_clock;
            private readonly TimeSpan m_advanceBy;

            public AdvancingDelay(FakeAiSplitClock clock, TimeSpan advanceBy)
            {
                m_clock = clock;
                m_advanceBy = advanceBy;
            }

            public void Delay(TimeSpan value)
            {
                m_clock.Advance(m_advanceBy);
            }
        }
    }
}
