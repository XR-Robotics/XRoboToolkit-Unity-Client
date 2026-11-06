using System;
using System.Collections.Generic;
using NUnit.Framework;

namespace ByteDance.PICO.IconConfigurator.Editor.Tests
{
    public class IconAiSplitModelTests
    {
        [Test]
        public void AiSplitTccConfig_WhenCreated_ExposesSerializableRuntimeSections()
        {
            AiSplitTccConfig config = new AiSplitTccConfig
            {
                Enable = true,
                Regions = new List<AiSplitRegionConfig>
                {
                    new AiSplitRegionConfig
                    {
                        Region = "cn",
                        ApiBaseUrl = "https://example.test",
                        TccKey = "data.ai_split_config",
                    },
                },
                Timeouts = new AiSplitTimeoutConfig
                {
                    ConnectTimeoutSeconds = 3,
                    ReadTimeoutSeconds = 30,
                    PollIntervalSeconds = 2,
                    TotalTimeoutSeconds = 300,
                },
                Api = new AiSplitApiConfig
                {
                    GeneratePath = "/sdf/gen",
                    InfoPath = "/sdf/info",
                },
                Tos = new AiSplitTosConfig
                {
                    BucketName = "bucket",
                    ObjectDirectory = "icons/",
                    PublicBaseUrl = "https://cdn.example.test",
                },
                Signing = new AiSplitSigningConfig
                {
                    AppId = "app-id",
                    Salt = "salt",
                },
            };

            Assert.That(Attribute.IsDefined(typeof(AiSplitTccConfig), typeof(SerializableAttribute)), Is.True);
            Assert.That(Attribute.IsDefined(typeof(AiSplitRegionConfig), typeof(SerializableAttribute)), Is.True);
            Assert.That(config.Enable, Is.True);
            Assert.That(config.Regions[0].Region, Is.EqualTo("cn"));
            Assert.That(config.Timeouts.TotalTimeoutSeconds, Is.EqualTo(300));
            Assert.That(config.Api.GeneratePath, Is.EqualTo("/sdf/gen"));
            Assert.That(config.Tos.ObjectDirectory, Is.EqualTo("icons/"));
            Assert.That(config.Signing.AppId, Is.EqualTo("app-id"));
        }

        [Test]
        public void AiSplitResponseModels_WhenCreated_CarryRemoteAssetsProgressAndErrors()
        {
            AiSplitGenerateResponse generateResponse = new AiSplitGenerateResponse
            {
                Code = 0,
                Message = "ok",
                RequestId = "request-1",
                Data = new AiSplitGenerateData
                {
                    TaskId = "task-1",
                },
            };
            AiSplitInfoResponse infoResponse = new AiSplitInfoResponse
            {
                Code = 10002,
                Message = "processing",
                RequestId = "request-2",
                Data = new AiSplitInfoData
                {
                    TaskId = "task-1",
                    Progress = 42,
                    ModelVersion = "model-v2",
                    Layers = new List<AiSplitRemoteAsset>
                    {
                        new AiSplitRemoteAsset { Url = "https://cdn.example.test/layer.png", Md5 = "layer-md5" },
                    },
                    Sdfs = new List<AiSplitRemoteAsset>
                    {
                        new AiSplitRemoteAsset { Url = "https://cdn.example.test/sdf.png", Md5 = "sdf-md5" },
                    },
                    ErrorType = AiSplitErrorType.Timeout,
                    ErrorMessage = "timed out",
                },
            };

            Assert.That(generateResponse.Data.TaskId, Is.EqualTo("task-1"));
            Assert.That(infoResponse.Data.Progress, Is.EqualTo(42));
            Assert.That(infoResponse.Data.Layers[0].Url, Is.EqualTo("https://cdn.example.test/layer.png"));
            Assert.That(infoResponse.Data.Layers[0].Md5, Is.EqualTo("layer-md5"));
            Assert.That(infoResponse.Data.Sdfs[0].Md5, Is.EqualTo("sdf-md5"));
            Assert.That(infoResponse.Data.ErrorType, Is.EqualTo(AiSplitErrorType.Timeout));
            Assert.That(infoResponse.Data.ErrorMessage, Is.EqualTo("timed out"));
        }

        [Test]
        public void AiSplitState_EnsureDynamicResultLists_WhenLegacyLayersExist_MigratesLayersInOrder()
        {
            AiSplitState state = new AiSplitState
            {
                Background = CreateLayer(IconLayerKind.Background, "background"),
                Foreground1 = CreateLayer(IconLayerKind.Foreground1, "foreground1"),
                Foreground2 = CreateLayer(IconLayerKind.Foreground2, "foreground2"),
                TaskId = "task-1",
                RequestId = "request-1",
                ModelVersion = "model-v1",
                GeneratedAt = "2026-06-10T00:00:00.0000000Z",
                ErrorType = AiSplitErrorType.Service,
            };

            state.EnsureDynamicResultLists();

            Assert.That(state.GeneratedLayers, Has.Count.EqualTo(3));
            Assert.That(state.GeneratedLayers[0].DisplayName, Is.EqualTo("background"));
            Assert.That(state.GeneratedLayers[1].DisplayName, Is.EqualTo("foreground1"));
            Assert.That(state.GeneratedLayers[2].DisplayName, Is.EqualTo("foreground2"));
            Assert.That(state.TaskId, Is.EqualTo("task-1"));
            Assert.That(state.RequestId, Is.EqualTo("request-1"));
            Assert.That(state.ModelVersion, Is.EqualTo("model-v1"));
            Assert.That(state.ErrorType, Is.EqualTo(AiSplitErrorType.Service));
        }

        [Test]
        public void IconAiSplitResult_EnsureDynamicLists_WhenLegacyLayersAndSdfsExist_MigratesAssetsInOrder()
        {
            IconAiSplitResult result = new IconAiSplitResult
            {
                Background = CreateLayer(IconLayerKind.Background, "background"),
                Foreground1 = CreateLayer(IconLayerKind.Foreground1, "foreground1"),
                Foreground2 = CreateLayer(IconLayerKind.Foreground2, "foreground2"),
                Sdfs = new List<IconLayerConfig>
                {
                    CreateLayer(IconLayerKind.Background, "background-sdf"),
                    CreateLayer(IconLayerKind.Foreground1, "foreground1-sdf"),
                    CreateLayer(IconLayerKind.Foreground2, "foreground2-sdf"),
                },
                TaskId = "task-1",
                RequestId = "request-1",
                ModelVersion = "model-v1",
                GeneratedAt = "2026-06-10T00:00:00.0000000Z",
                ErrorType = AiSplitErrorType.InvalidResponse,
            };

            result.EnsureDynamicLists();

            Assert.That(result.Layers, Has.Count.EqualTo(3));
            Assert.That(result.Sdfs, Has.Count.EqualTo(3));
            Assert.That(result.Layers[2].DisplayName, Is.EqualTo("foreground2"));
            Assert.That(result.Sdfs[2].DisplayName, Is.EqualTo("foreground2-sdf"));
            Assert.That(result.TaskId, Is.EqualTo("task-1"));
            Assert.That(result.RequestId, Is.EqualTo("request-1"));
            Assert.That(result.ModelVersion, Is.EqualTo("model-v1"));
            Assert.That(result.GeneratedAt, Is.EqualTo("2026-06-10T00:00:00.0000000Z"));
            Assert.That(result.ErrorType, Is.EqualTo(AiSplitErrorType.InvalidResponse));
        }

        private static IconLayerConfig CreateLayer(IconLayerKind layerKind, string displayName)
        {
            return new IconLayerConfig
            {
                LayerKind = layerKind,
                DisplayName = displayName,
                AssetGuid = $"{displayName}-guid",
                AssetPath = $"Assets/IconConfigurator/Generated/{displayName}.png",
            };
        }
    }
}
