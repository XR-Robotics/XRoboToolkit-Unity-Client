Shader "PICO/EnvironmentDepth/Preprocessing"
{
    SubShader
    {
        Pass
        {
            Name "Environment Depth Preprocessing Pass"

            ZWrite Off

            CGPROGRAM
            #pragma target 4.5
            #pragma vertex vert
            #pragma fragment frag

            Texture2DArray_half _EnvironmentDepthTexture; // "_half" suffix means medium precision
            SamplerState sampler_EnvironmentDepthTexture;
            float4 _EnvironmentDepthTexture_TexelSize;

            struct Attributes
            {
                uint vertexId : SV_VertexID;
			          uint instanceId : SV_InstanceID;
            };

            struct Varyings
            {
                float4 positionCS : SV_POSITION;
                float2 uv : TEXCOORD0;
                uint depthSlice : SV_RenderTargetArrayIndex;
            };

            float4 CalculateMinMaxDepth(float2 uv, float slice)
            {
              static const int NUM_SAMPLES = 4;
              static const float2 offsets[NUM_SAMPLES] = {
                float2(-1.0f,  1.0f),
                float2( 1.0f,  1.0f),
                float2(-1.0f, -1.0f),
                float2( 1.0f, -1.0f)
              };

              const float2 onePixelOffset = _EnvironmentDepthTexture_TexelSize.xy;
              const float4 quarter = float4(0.25f, 0.25f, 0.25f, 0.25f);
              const float4 ones    = float4(1.0f, 1.0f, 1.0f, 1.0f);

              float4 gathered[NUM_SAMPLES];

              float minDepth = 1.0f;
              float maxDepth = 0.0f;
              float depthSum = 0.0f;
              float squareSum = 0.0f;

              // First pass: gather samples, accumulate avg, min/max and variance proxy
              [unroll]
              for (int i = 0; i < NUM_SAMPLES; ++i)
              {
                float2 uvSample = uv + (offsets[i] + 0.5f) * onePixelOffset;
                float4 g = _EnvironmentDepthTexture.Gather(sampler_EnvironmentDepthTexture, float3(uvSample.x, uvSample.y, slice));
                gathered[i] = g;

                depthSum  += dot(g, quarter);
                squareSum += dot(g * g, quarter);

                float localMax = max(max(g.x, g.y), max(g.z, g.w));
                float localMin = min(min(g.x, g.y), min(g.z, g.w));

                maxDepth = max(maxDepth, localMax);
                minDepth = min(minDepth, localMin);
              }

              // Base statistics
              float avg = depthSum * (1.0f / float(NUM_SAMPLES));
              float avgSquares = squareSum * (1.0f / float(NUM_SAMPLES));
              float variance = max(0.0f, avgSquares - avg * avg);
              float spread   = max(0.0f, maxDepth - minDepth);

              // Adaptive thresholds
              const float kMaxMetricDepthThrMultiplier = 0.85f;
              const float kMinMetricDepthThrMultiplier = 1.15f;

              float invMaxMul = 1.0f / kMaxMetricDepthThrMultiplier;
              float invMinMul = 1.0f / kMinMetricDepthThrMultiplier;

              float depthThrMax = (1.0f - invMaxMul) + maxDepth * invMaxMul;
              float depthThrMin = (1.0f - invMinMul) + minDepth * invMinMul;

              // Early out: homogeneous region
              if (depthThrMax < minDepth && depthThrMin > maxDepth)
              {
                return float4(1.0f - avg, 1.0f - avg, 0.0f, 0.0f);
              }

              // Soft masks with adaptive epsilon for smoother clustering
              float eps = max(0.001f, spread * (0.12f + saturate(variance * 8.0f) * 0.18f));
              const float4 thrMaxA = float4(depthThrMax - eps, depthThrMax - eps, depthThrMax - eps, depthThrMax - eps);
              const float4 thrMaxB = float4(depthThrMax + eps, depthThrMax + eps, depthThrMax + eps, depthThrMax + eps);
              const float4 thrMinA = float4(depthThrMin - eps, depthThrMin - eps, depthThrMin - eps, depthThrMin - eps);
              const float4 thrMinB = float4(depthThrMin + eps, depthThrMin + eps, depthThrMin + eps, depthThrMin + eps);

              float maxSumDepth = 0.0f;
              float minSumDepth = 0.0f;
              float maxSumCount = 0.0f;
              float minSumCount = 0.0f;

              // Second pass: accumulate masked mins and maxes (fractional weights)
              [unroll]
              for (int i = 0; i < NUM_SAMPLES; ++i)
              {
                float4 g = gathered[i];

                // maxMask ~ g >= depthThrMax (smoothed)
                float4 maxMask = smoothstep(thrMaxA, thrMaxB, g);
                // minMask ~ g <= depthThrMin (smoothed)
                float4 minMask = 1.0f - smoothstep(thrMinA, thrMinB, g);

                minSumDepth += dot(minMask, g);
                minSumCount += dot(minMask, ones);
                maxSumDepth += dot(maxMask, g);
                maxSumCount += dot(maxMask, ones);
              }

              // Safe guards against empty sets
              float minAvg = (minSumCount > 0.0f) ? (minSumDepth / minSumCount) : minDepth;
              float maxAvg = (maxSumCount > 0.0f) ? (maxSumDepth / maxSumCount) : maxDepth;

              return float4(1.0f - minAvg, 1.0f - maxAvg, avg - minAvg, maxAvg - minAvg);
            }

            Varyings vert(const Attributes input)
            {
                Varyings output;

                const uint vertexID = input.vertexId;
                const float2 uv = float2((vertexID << 1) & 2, vertexID & 2);
                output.uv = float2(uv.x, 1.0 - uv.y);
                output.positionCS = float4(uv * 2.0 - 1.0, 1.0, 1.0);

                output.depthSlice = input.instanceId;
                return output;
            }

            float4 frag(const Varyings input) : SV_Target
            {
                return CalculateMinMaxDepth(input.uv, input.depthSlice);
            }
            ENDCG
        }
    }
}