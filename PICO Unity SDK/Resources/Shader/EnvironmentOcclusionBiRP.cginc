
#include "UnityCG.cginc"

#define PREFER_HALF 0
#define SHADER_HINT_NICE_QUALITY 1

uniform UNITY_DECLARE_TEX2DARRAY(_EnvironmentDepthTexture);
float4 _EnvironmentDepthTexture_TexelSize;

UNITY_DECLARE_TEX2DARRAY(_PreprocessedEnvironmentDepthTexture);
float4 _PreprocessedEnvironmentDepthTexture_TexelSize;

float SampleEnvironmentDepth(float2 reprojectedUV) {
  return UNITY_SAMPLE_TEX2DARRAY(_EnvironmentDepthTexture,
           float3(reprojectedUV, (float)unity_StereoEyeIndex)).r;
}

#define ENVIRONMENT_DEPTH_CONVERT_OBJECT_TO_WORLD(objectPos) mul(unity_ObjectToWorld, objectPos).xyz;

float3 DepthConvertDepthToLinear(float zspace) {
  return LinearEyeDepth(zspace);
}

float4 SamplePreprocessedDepth(float2 uv, float slice) {
  return UNITY_SAMPLE_TEX2DARRAY(_PreprocessedEnvironmentDepthTexture,
           float3(uv, slice));
}

#include "EnvironmentOcclusion.cginc"

