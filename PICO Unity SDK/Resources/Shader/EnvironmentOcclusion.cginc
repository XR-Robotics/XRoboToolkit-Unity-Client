
uniform float4x4 _EnvironmentDepthReprojectionMatrices[2];
uniform float4 _EnvironmentDepthZBufferParams;
uniform float _EnvironmentOcclusionEnabled;

#define SAMPLE_OFFSET_PIXELS 6.0f
#define RELATIVE_ERROR_SCALE 0.015f
#define ENVIRONMENT_OCCLUSION_SCREENSPACE_OFFSET SAMPLE_OFFSET_PIXELS / _EnvironmentDepthTexture_TexelSize.zw

float SampleEnvironmentDepthLinear(float2 uv)
{
  const float inputDepthEye = SampleEnvironmentDepth(uv);

  const float inputDepthNdc = inputDepthEye * 2.0 - 1.0;
  const float linearDepth = (1.0f / (inputDepthNdc + _EnvironmentDepthZBufferParams.y)) * _EnvironmentDepthZBufferParams.x;

  return linearDepth;
}


float ComputeEnvironmentOcclusion(float2 uvCoords, float linearSceneDepth) {

  const float2 halfPixelOffset = 0.5f * float2(_PreprocessedEnvironmentDepthTexture_TexelSize.xy);
  uvCoords -= halfPixelOffset;

  float biasedDepthSpace = _EnvironmentDepthZBufferParams.x / linearSceneDepth - _EnvironmentDepthZBufferParams.y;

  float cubeDepthRangeLow  = (biasedDepthSpace + 1.0f) * 0.5f;

  const float kRange = 1.0f / 1.04f - 1.0f;
  float cubeDepthRangeInv = 1.0f / (cubeDepthRangeLow * kRange - kRange);

  float4 texSample = SamplePreprocessedDepth(uvCoords, unity_StereoEyeIndex);
  float3 minMaxMid = float3(1.0f - texSample.x, 1.0f - texSample.y, texSample.z + 1.0f - texSample.x);
  float3 alphas = clamp((minMaxMid - cubeDepthRangeLow) * cubeDepthRangeInv, 0.0f, 1.0f);

  float alpha = alphas.z;
  if (alphas.y - alphas.x > 0.03f) {
    
    const float kForegroundLevel = 0.2f;
    const float kBackgroundLevel = 0.8f;
    float interp = texSample.z / texSample.w;
    alpha = lerp(alphas.x, alphas.y, smoothstep(kForegroundLevel, kBackgroundLevel, interp));
  }

  return alpha;
}

float CalculateEnvironmentDepthOcclusion(float3 worldCoords, float bias)
{
  const float4 depthSpace =
    mul(_EnvironmentDepthReprojectionMatrices[unity_StereoEyeIndex], float4(worldCoords, 1.0));

  const float2 uvCoords = (depthSpace.xy / depthSpace.w + 1.0f) * 0.5f;

  float linearSceneDepth = (1.0f / ((depthSpace.z / depthSpace.w) + _EnvironmentDepthZBufferParams.y)) * _EnvironmentDepthZBufferParams.x;
  linearSceneDepth -= bias * linearSceneDepth * UNITY_NEAR_CLIP_VALUE;

  float occlusion = ComputeEnvironmentOcclusion(uvCoords, linearSceneDepth);
  float enabled = saturate(_EnvironmentOcclusionEnabled);
  return lerp(1.0f, occlusion, enabled);
}

// Always enable occlusion macros; runtime toggle via _EnvironmentOcclusionEnabled
#define ENVIRONMENT_DEPTH_VERTEX_OUTPUT(number) \
  float3 posWorld : TEXCOORD##number;

#define ENVIRONMENT_DEPTH_INITIALIZE_VERTEX_OUTPUT(output, vertex) \
  output.posWorld = ENVIRONMENT_DEPTH_CONVERT_OBJECT_TO_WORLD(vertex)

#define ENVIRONMENT_DEPTH_GET_OCCLUSION_VALUE_WORLDPOS(posWorld, zBias) \
  CalculateEnvironmentDepthOcclusion(posWorld.xyz, zBias);

#define ENVIRONMENT_DEPTH_GET_OCCLUSION_VALUE(input, zBias) ENVIRONMENT_DEPTH_GET_OCCLUSION_VALUE_WORLDPOS(input.posWorld, zBias);

#define ENVIRONMENT_DEPTH_OCCLUDE_OUTPUT_PREMULTIPLY_WORLDPOS(posWorld, output, zBias) \
    float occlusionValue = ENVIRONMENT_DEPTH_GET_OCCLUSION_VALUE_WORLDPOS(posWorld, zBias); \
    output *= occlusionValue; \

#define ENVIRONMENT_DEPTH_OCCLUDE_OUTPUT_PREMULTIPLY_WORLDPOS_NAME(input, fieldName, output, zBias) \
  ENVIRONMENT_DEPTH_OCCLUDE_OUTPUT_PREMULTIPLY_WORLDPOS(input . ##fieldName, output, zBias)

#define ENVIRONMENT_DEPTH_OCCLUDE_OUTPUT_PREMULTIPLY(input, output, zBias) \
  ENVIRONMENT_DEPTH_OCCLUDE_OUTPUT_PREMULTIPLY_WORLDPOS(input.posWorld, output, zBias)
