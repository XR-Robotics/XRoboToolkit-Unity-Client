#if ENABLE_PICO_XR_SDK
using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using JetBrains.Annotations;
using UnityEngine;
using UnityEngine.XR.Management;
using UnityEngine.Rendering;
using UnityEngine.XR;
using UnityEngine.Experimental.Rendering;
using Debug = UnityEngine.Debug;

namespace ByteDance.PICO.XR
{
    public class PXR_EnvironmentDepthManager : MonoBehaviour
    {
        private static readonly int EnvironmentOcclusionEnabledID = Shader.PropertyToID("_EnvironmentOcclusionEnabled");
        
        private static readonly int DepthTextureID = Shader.PropertyToID("_EnvironmentDepthTexture");
        private static readonly int ReprojectionMatricesID = Shader.PropertyToID("_EnvironmentDepthReprojectionMatrices");
        private static readonly int ZBufferParamsID = Shader.PropertyToID("_EnvironmentDepthZBufferParams");
        private static readonly int PreprocessedEnvironmentDepthTexture = Shader.PropertyToID("_PreprocessedEnvironmentDepthTexture");
        
        [SerializeField] 
        private Transform xrOrigin;
        
        private uint? prevTextureId;
        private Material preprocessMaterial;
        [CanBeNull] private RenderTexture preprocessTexture;
        private RenderTargetSetup preprocessRenderTargetSetup;
        
        private readonly Vector3 _scalingVector3 = new(1, 1, -1);
        
        public bool IsDepthAvailable { get; private set; }
        
        private readonly Matrix4x4[] _reprojectionMatrices = new Matrix4x4[2];
        private XRDisplaySubsystem xrDisplay;

        private void Awake()
        {
            var displays = new List<XRDisplaySubsystem>(1);
#if UNITY_6000_0_OR_NEWER
            SubsystemManager.GetSubsystems(displays);
#else
            SubsystemManager.GetInstances(displays);
#endif
            xrDisplay = displays.FirstOrDefault();
            

            const string shaderName = "PICO/EnvironmentDepth/Preprocessing";
            var shader = Shader.Find(shaderName);
            if (shader != null)
            {
                preprocessMaterial = new Material(shader);
            }
        }

        private void Start()
        {
            PXR_Manager.EnableVideoSeeThrough = true;
        }

        private void OnEnable()
        {
            Application.onBeforeRender += OnBeforeRender;
            _ = PXR_MixedReality.StartSenseDataProvider(PxrSenseDataProviderType.EnvironmentDepth);
        }

        private void ResetDepthTextureIfAvailable()
        {
            if (IsDepthAvailable)
            {
                IsDepthAvailable = false;
                Shader.SetGlobalTexture(DepthTextureID, null);
                Shader.SetGlobalFloat(EnvironmentOcclusionEnabledID, 0.0f);
            }
        }

        private void OnDisable()
        {
            Application.onBeforeRender -= OnBeforeRender;
            ResetDepthTextureIfAvailable();
            PXR_MixedReality.StopSenseDataProvider(PxrSenseDataProviderType.EnvironmentDepth);
                
        }

        private void OnDestroy()
        {
            if (preprocessMaterial != null)
                Destroy(preprocessMaterial);
            if (preprocessTexture != null)
                Destroy(preprocessTexture);
        }
        
        private void OnBeforeRender()
        {
#if !UNITY_EDITOR
            var trackingSpaceWorldToLocal = GetTrackingSpaceWorldToLocalMatrix();

            if (!TryFetchDepthTexture(out var depthTexture))
                return;

            var leftEyeData = GetFrameDesc(0);
            var rightEyeData = GetFrameDesc(1);

            var depthZBufferParams = ComputeNdcToLinearDepthParameters(leftEyeData.nearZ, leftEyeData.farZ);
            Shader.SetGlobalVector(ZBufferParamsID, depthZBufferParams);

            _reprojectionMatrices[0] = CalculateReprojection(leftEyeData) * trackingSpaceWorldToLocal;
            _reprojectionMatrices[1] = CalculateReprojection(rightEyeData) * trackingSpaceWorldToLocal;
            Shader.SetGlobalMatrixArray(ReprojectionMatricesID, _reprojectionMatrices);

            PreprocessDepthTexture(depthTexture);
#endif
        }

        private void EnsureXrDisplay()
        {
            if (xrDisplay != null)
                return;

            var displays = new List<XRDisplaySubsystem>(1);
#if UNITY_6000_0_OR_NEWER
            SubsystemManager.GetSubsystems(displays);
#else
            SubsystemManager.GetInstances(displays);
#endif
            xrDisplay = displays.FirstOrDefault();
        }

        private bool TryFetchDepthTexture(out RenderTexture depthTexture)
        {
            depthTexture = null;
            EnsureXrDisplay();

            uint textureId = 0;
            if (xrDisplay == null || !xrDisplay.running || PXR_MixedReality.GetEnvironmentDepthTextureId(ref textureId) != PxrResult.SUCCESS)
                return false;

            depthTexture = xrDisplay.GetRenderTexture(textureId);
            
            if (depthTexture == null) 
            {
                ResetDepthTextureIfAvailable();
                return false;
            }

            var textureChanged = prevTextureId != textureId;
            prevTextureId = textureId;
            
            if (textureChanged || !IsDepthAvailable)
            {
                Shader.SetGlobalTexture(DepthTextureID, depthTexture);
            }

            if (!IsDepthAvailable)
            {
                IsDepthAvailable = true;
                Shader.SetGlobalFloat(EnvironmentOcclusionEnabledID, preprocessMaterial != null ? 1.0f : 0.0f);
            }

            return true;
        }

        public EnvironmentDepthFrameDesc GetFrameDesc(int eye)
        {
            EnvironmentDepthFrameDesc desc = new EnvironmentDepthFrameDesc();
            PXR_Plugin.MixedReality.UPxr_GetEnvironmentDepthFrameDesc(ref desc,eye);
            return new EnvironmentDepthFrameDesc
            {
                createPoseLocation = desc.createPoseLocation,
                createPoseRotation = desc.createPoseRotation,
                fovLeftAngle = desc.fovLeftAngle,
                fovRightAngle = desc.fovRightAngle,
                fovTopAngle = desc.fovTopAngle,
                fovDownAngle = desc.fovDownAngle,
                nearZ = desc.nearZ,
                farZ = desc.farZ
            };
        }
        
        private Matrix4x4 GetTrackingSpaceWorldToLocalMatrix()
        {
            return xrOrigin != null ? xrOrigin.worldToLocalMatrix : Matrix4x4.identity;
        }
        
        private void PreprocessDepthTexture(RenderTexture depthTexture)
        {
            if (preprocessMaterial == null)
                return;

            if (preprocessTexture != null && (preprocessTexture.width != depthTexture.width || preprocessTexture.height != depthTexture.height))
            {
                preprocessTexture.Release();
                Destroy(preprocessTexture);
                preprocessTexture = null;
            }

            if (preprocessTexture == null)
            {
                preprocessTexture = new RenderTexture(depthTexture.width, depthTexture.height, GraphicsFormat.R16G16B16A16_SFloat, GraphicsFormat.None)
                {
                    dimension = TextureDimension.Tex2DArray,
                    volumeDepth = 2,
                    name = nameof(preprocessTexture),
                    depth = 0
                };
                preprocessTexture.Create();
                Shader.SetGlobalTexture(PreprocessedEnvironmentDepthTexture, preprocessTexture);

                preprocessRenderTargetSetup = new RenderTargetSetup
                {
                    color = new[] { preprocessTexture.colorBuffer },
                    depth = preprocessTexture.depthBuffer,
                    depthSlice = -1,
                    colorLoad = new[] { RenderBufferLoadAction.DontCare },
                    colorStore = new[] { RenderBufferStoreAction.Store },
                    depthLoad = RenderBufferLoadAction.DontCare,
                    depthStore = RenderBufferStoreAction.DontCare,
                    mipLevel = 0,
                    cubemapFace = CubemapFace.Unknown
                };
            }
            
            Graphics.SetRenderTarget(preprocessRenderTargetSetup);
            preprocessMaterial.SetPass(0);
            Graphics.DrawProceduralNow(MeshTopology.Triangles, 3, 2);
        }
        
        private Vector4 ComputeNdcToLinearDepthParameters(float near, float far)
        {
            float invDepthFactor;
            float depthOffset;
            invDepthFactor = -2.0f * far * near / (far - near);
            depthOffset = -(far + near) / (far - near);

            return new Vector4(invDepthFactor, depthOffset, 0, 0);
        }

        private Matrix4x4 CalculateReprojection(EnvironmentDepthFrameDesc frameDesc)
        {
            CalculateDepthCameraMatrices(frameDesc, out var proj, out var view);
            return proj * view;
        }

        private void CalculateDepthCameraMatrices(EnvironmentDepthFrameDesc frameDesc, out Matrix4x4 projMatrix, out Matrix4x4 viewMatrix)
        {
            float left = frameDesc.fovLeftAngle;
            float right = frameDesc.fovRightAngle;
            float bottom = frameDesc.fovDownAngle;
            float top = frameDesc.fovTopAngle;
            float near = frameDesc.nearZ;
            float far = frameDesc.farZ;
    
            float toRad = 1.0f;
            float l = Mathf.Tan(left * toRad);
            float r = Mathf.Tan(right * toRad);
            float b = Mathf.Tan(bottom * toRad);
            float t = Mathf.Tan(top * toRad);
    
            float m00 = 2.0f / (r - l);
            float m02 = (r + l) / (r - l);
            float m11 = 2.0f / (t - b);
            float m12 = (t + b) / (t - b);
    
            float c, d;
            if (float.IsInfinity(far)) { c = -1.0f; d = -2.0f * near; }
            else { c = -(far + near) / (far - near); d = -(2.0f * far * near) / (far - near); }
            float e = -1.0f;
    
            projMatrix = new Matrix4x4
            {
                m00 = m00, m01 = 0,    m02 = m02, m03 = 0,
                m10 = 0,    m11 = m11, m12 = m12, m13 = 0,
                m20 = 0,    m21 = 0,   m22 = c,   m23 = d,
                m30 = 0,    m31 = 0,   m32 = e,   m33 = 0
            };
    
            var q = frameDesc.createPoseRotation;
            var depthOrientation = new Quaternion(q.x, q.y, q.z, q.w);
    
            viewMatrix = Matrix4x4.TRS(frameDesc.createPoseLocation, depthOrientation, _scalingVector3).inverse;
        }
    }
}
#endif
