#if ENABLE_PICO_XR_SDK 
using System;
using UnityEngine;
using UnityEngine.Rendering;

namespace ByteDance.PICO.XR
{
    public class PXR_LightEstimationManager : MonoBehaviour
    {
        private Cubemap cubemap;
        private uint cubeTexture;
        private ulong vkImage;
        private RenderTexture flippedCubemap;
        private Material flipMaterial;
        private bool requestQuery;
        private bool isQueryInFlight;
        private bool hasPendingData;
        private PxrLightEstimationData pendingData;
        private PxrResult pendingResult;
        private readonly object pendingLock = new object();
        private bool hasCapturedReflectionSettings;
        private DefaultReflectionMode originalReflectionMode;
        private Texture originalCustomReflectionTexture;
        private float originalReflectionIntensity;
        private bool hasAppliedCustomReflection;
        private bool hasValidData;
        private Texture2D validationTexture;
        
        // Start is called before the first frame update
        void Start()
        {
            StartLightEstimationProvider();
        }

        private async void StartLightEstimationProvider()
        {
            var pxrResult = await PXR_MixedReality.StartSenseDataProvider(PxrSenseDataProviderType.LightEstimation);
        }
        
        void OnEnable()
        {
            if (!hasCapturedReflectionSettings)
            {
                hasCapturedReflectionSettings = true;
                originalReflectionMode = RenderSettings.defaultReflectionMode;
                originalCustomReflectionTexture = RenderSettings.customReflectionTexture;
                originalReflectionIntensity = RenderSettings.reflectionIntensity;
            }
            PXR_Manager.LightEstimationUpdated += LightEstimationUpdated;
        }

        void OnDisable()
        {
            PXR_Manager.LightEstimationUpdated -= LightEstimationUpdated;
            if (hasAppliedCustomReflection && hasCapturedReflectionSettings)
            {
                RenderSettings.defaultReflectionMode = originalReflectionMode;
                RenderSettings.customReflectionTexture = originalCustomReflectionTexture;
                RenderSettings.reflectionIntensity = originalReflectionIntensity;
                hasAppliedCustomReflection = false;
            }
        }

        void Update()
        {
            if (requestQuery && !isQueryInFlight)
            {
                requestQuery = false;
                ReleasePreviousTexture();
                isQueryInFlight = true;
                var useVulkan = SystemInfo.graphicsDeviceType == GraphicsDeviceType.Vulkan;
                _ = QueryLightEstimationDataAsync(useVulkan);
            }

            if (hasPendingData)
            {
                PxrLightEstimationData data;
                PxrResult result;
                lock (pendingLock)
                {
                    data = pendingData;
                    result = pendingResult;
                    hasPendingData = false;
                }
                if (result == PxrResult.SUCCESS && (data.cubemap > 0 || data.vkImage != IntPtr.Zero))
                {
                    ApplyLightEstimationData(data);
                }
            }
        }

        void OnDestroy()
        {
            if (flippedCubemap != null)
            {
                flippedCubemap.Release();
                flippedCubemap = null;
            }
            if (flipMaterial != null)
            {
                Destroy(flipMaterial);
                flipMaterial = null;
            }
            if (validationTexture != null)
            {
                Destroy(validationTexture);
                validationTexture = null;
            }
        }
        
        private void LightEstimationUpdated()
        {
            requestQuery = true;
        }
        
        private async System.Threading.Tasks.Task QueryLightEstimationDataAsync(bool useVulkan)
        {
            var result = await PXR_MixedReality.QueryLightEstimationDataAsync(useVulkan).ConfigureAwait(false);
            lock (pendingLock)
            {
                pendingResult = result.result;
                pendingData = result.lightData;
                hasPendingData = true;
            }
            isQueryInFlight = false;
        
        }

        private void ReleasePreviousTexture()
        {
            if (SystemInfo.graphicsDeviceType == GraphicsDeviceType.Vulkan)
            {
                if (vkImage > 0)
                {
                    PXR_Plugin.MixedReality.UPxr_ReleaseEnvironmentTextureImageVulkan(vkImage);
                    vkImage = 0;
                }
            }
            else if (cubeTexture > 0)
            {
                PXR_Plugin.MixedReality.UPxr_ReleaseEnvironmentTextureImage(cubeTexture);
                cubeTexture = 0;
            }
        }

        private void ApplyLightEstimationData(PxrLightEstimationData data)
        {
            try
            {
                if (SystemInfo.graphicsDeviceType == GraphicsDeviceType.Vulkan)
                {
                    vkImage = (ulong)data.vkImage;
                    if (cubemap == null)
                    {
                        cubemap = new Cubemap(128, TextureFormat.RGBAHalf, false);
                    }
                    if (flippedCubemap == null)
                    {
                        flippedCubemap = new RenderTexture(128, 128, 0, RenderTextureFormat.ARGBHalf);
                        flippedCubemap.dimension = TextureDimension.Cube;
                        flippedCubemap.useMipMap = true;
                        flippedCubemap.autoGenerateMips = false;
                        flippedCubemap.Create();
                    }
                    var nativePtr = cubemap.GetNativeTexturePtr();
                    if (vkImage == 0 || nativePtr == IntPtr.Zero)
                    {
                        return;
                    }

                    PXR_Plugin.MixedReality.UPxr_CopyLightEstimationVulkanImageToUnityTexture(nativePtr, vkImage, 128, 1);
                    if (UpdateFlippedCubemap())
                    {
                        if (!hasAppliedCustomReflection)
                        {
                            hasAppliedCustomReflection = true;
                        }

                        RenderSettings.customReflectionTexture = flippedCubemap;
                        RenderSettings.defaultReflectionMode = DefaultReflectionMode.Custom;
                        RenderSettings.reflectionIntensity = 1;
                        DynamicGI.UpdateEnvironment();
                    }
                }
                else
                {
                    cubeTexture = data.cubemap;
                    if (cubemap == null)
                    {
                        cubemap = Cubemap.CreateExternalTexture(128, TextureFormat.RGBAHalf, false, nativeTex:(IntPtr)data.cubemap);
                    
                        if (flippedCubemap == null)
                        {
                            flippedCubemap = new RenderTexture(128, 128, 0, RenderTextureFormat.ARGBHalf);
                            flippedCubemap.dimension = TextureDimension.Cube;
                            flippedCubemap.useMipMap = true;
                            flippedCubemap.autoGenerateMips = false;
                            flippedCubemap.Create();
                        }
                    }
                    else
                    {
                        cubemap.UpdateExternalTexture((IntPtr)data.cubemap);
                    }

                    if (UpdateFlippedCubemap())
                    {
                        if (!hasAppliedCustomReflection)
                        {
                            hasAppliedCustomReflection = true;
                        }

                        RenderSettings.customReflectionTexture = flippedCubemap;
                        RenderSettings.defaultReflectionMode = DefaultReflectionMode.Custom;
                        RenderSettings.reflectionIntensity = 1;
                        DynamicGI.UpdateEnvironment();
                    }
                }
            
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                throw;
            }
        }

        private bool UpdateFlippedCubemap()
        {
            if (flipMaterial == null)
                flipMaterial = new Material(Shader.Find("PICO/LightEstimation/InvertCubemap"));

            bool isValid = true;
            if (cubemap != null && flippedCubemap != null)
            {
                // Explicitly set the texture to ensure the shader uses the updated external texture
                flipMaterial.SetTexture("_MainTex", cubemap);

                var oldRT = RenderTexture.active;
                for (int i = 0; i < 6; i++)
                {
                    flipMaterial.SetInt("_d", i);
                    Graphics.SetRenderTarget(flippedCubemap, 0, (CubemapFace)i);
                    GL.Clear(false, true, Color.clear);
                    Graphics.Blit(cubemap, flipMaterial);

                    if (!hasValidData && i == 0)
                    {
                        if (validationTexture == null)
                        {
                            validationTexture = new Texture2D(1, 1, TextureFormat.RGBAHalf, false);
                        }

                        validationTexture.ReadPixels(new Rect(0, 0, 1, 1), 0, 0);
                        Color c = validationTexture.GetPixel(0, 0);
                        if (c.r <= 0.01f && c.g <= 0.01f && c.b <= 0.01f && c.a <= 0.01f)
                        {
                            isValid = false;
                        }
                        else
                        {
                            hasValidData = true;
                        }
                    }
                }
                RenderTexture.active = oldRT;
                
                flippedCubemap.GenerateMips();
            }
            return isValid;
        }
    }
}
#endif
