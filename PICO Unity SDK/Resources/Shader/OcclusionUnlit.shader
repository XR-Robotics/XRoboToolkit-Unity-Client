Shader "PICO/EnvironmentDepth/BIRP/OcclusionUnlit"
{
    Properties
    {
        _Color ("Color", Color) = (1,1,1,1)
        _MainTex ("Albedo (RGB)", 2D) = "white" {}
        _EnvironmentDepthBias ("Environment Depth Bias", Float) = 0.0
    }
    SubShader
    {
        Tags { "RenderType"="Opaque" }
        LOD 200

        Pass
        {
            CGPROGRAM

            #pragma vertex vert
            #pragma fragment frag

            #pragma target 2.5

            #include "EnvironmentOcclusionBiRP.cginc"
            
            struct appdata
            {
                float4 vertex : POSITION;
                float2 uv : TEXCOORD0;
                UNITY_VERTEX_INPUT_INSTANCE_ID
            };

            struct v2f
            {
                float2 uv_MainTex : TEXCOORD0;
                float4 vertex : SV_POSITION;

                ENVIRONMENT_DEPTH_VERTEX_OUTPUT(1)

                UNITY_VERTEX_INPUT_INSTANCE_ID
                UNITY_VERTEX_OUTPUT_STEREO
            };

            sampler2D _MainTex;
            float4 _MainTex_ST;
            fixed4 _Color;
            float _EnvironmentDepthBias;

            v2f vert (appdata v) {
                v2f o;
                UNITY_SETUP_INSTANCE_ID(v);
                UNITY_INITIALIZE_VERTEX_OUTPUT_STEREO(o); // required to support stereo
                o.vertex = UnityObjectToClipPos(v.vertex);
                o.uv_MainTex = TRANSFORM_TEX(v.uv, _MainTex);
                ENVIRONMENT_DEPTH_INITIALIZE_VERTEX_OUTPUT(o, v.vertex);

                return o;
            }

            static inline fixed4 SampleBaseColor(v2f i)
            {
                return tex2D(_MainTex, i.uv_MainTex) * _Color;
            }

            fixed4 frag (v2f i) : SV_Target
            {
                UNITY_SETUP_STEREO_EYE_INDEX_POST_VERTEX(i);

                fixed4 c = SampleBaseColor(i);
                ENVIRONMENT_DEPTH_OCCLUDE_OUTPUT_PREMULTIPLY(i, c, _EnvironmentDepthBias);
                return c;
            }
            ENDCG
        }
    }
}