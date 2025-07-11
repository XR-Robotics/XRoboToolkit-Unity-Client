/*
Shader "Custom/SampleRT"
{
    Properties
    {
        _MainTex ("Texture", 2D) = "white" {}
    }
    SubShader
    {
        Tags { "RenderType"="Opaque" }
        LOD 100

        Pass
        {
            CGPROGRAM
            #pragma vertex vert
            #pragma fragment frag

            #include "UnityCG.cginc"

            struct appdata
            {
                float4 vertex : POSITION;
                float2 uv : TEXCOORD0;
            };

            struct v2f
            {
                float2 uv : TEXCOORD0;
                float4 vertex : SV_POSITION;
            };

            sampler2D _MainTex;
            float4 _MainTex_ST;
            sampler2D _mainRT;
            int _isLE;
            float _visibleRatio;
            float _contentRatio;

            v2f vert (appdata v)
            {
                v2f o;
                o.vertex = UnityObjectToClipPos(v.vertex);
                o.uv = TRANSFORM_TEX(v.uv, _MainTex);
                return o;
            }

            fixed4 frag (v2f i) : SV_Target
            {   
                fixed4 col = fixed4(0.0, 0.0, 0.0, 0.0);
                if(_isLE == 1) 
                {
                    if(i.uv.x > (1-_visibleRatio) && i.uv.y>(1-_visibleRatio)/1 && i.uv.y<(1.0-(1-_visibleRatio)/1))
                    {   
                        float2 new_uv = float2((i.uv.x - (1-_visibleRatio))/(_visibleRatio), (i.uv.y - (1-_visibleRatio)/1)/(_visibleRatio));
                        new_uv.y = (new_uv.y - 0.5) * 1.25 + 0.5;
                        col = tex2D(_mainRT, float2(new_uv.x * _contentRatio/2 + (1-_contentRatio)/2, new_uv.y*_contentRatio + (1-_contentRatio)/2));
                        // col = tex2D(_mainRT, new_uv);
                    }
                }
                else
                {
                    if(i.uv.x < _visibleRatio && i.uv.y>(1-_visibleRatio)/1 && i.uv.y<(1.0-(1-_visibleRatio)/1))
                    {   
                        float2 new_uv = float2((i.uv.x - (1-_visibleRatio))/(_visibleRatio), (i.uv.y - (1-_visibleRatio)/1)/(_visibleRatio));
                        new_uv.y = (new_uv.y - 0.5) * 1.25 + 0.5;
                        // Centered calculation - apply content ratio and center properly
                        float new_uv_x = new_uv.x * _contentRatio + (1 - _contentRatio) * 0.5;
                        // Apply stereo offset (right side of stereo pair)
                        new_uv_x = new_uv_x * 0.5 + 0.5;
                       // col = tex2D(_mainRT, float2((new_uv.x * _contentRatio + (1-_contentRatio)/2)/2+0.5, new_uv.y*_contentRatio + (1-_contentRatio)/2));
                       col = tex2D(_mainRT, float2(new_uv_x, new_uv.y*_contentRatio + (1-_contentRatio)/2));
                        //col = tex2D(_mainRT, new_uv);
                    }
                }
                return col;
            }
            ENDCG
        }
    }
}
*/

Shader "Custom/SampleRT"
{
    Properties
    {
        _MainTex ("Texture", 2D) = "white" {}
        _visibleRatio ("Visible Ratio", Range(0.0, 2.0)) = 1.0
        _contentRatio ("Content Ratio", Range(0.0, 2.0)) = 0.555
        _heightCompressionFactor ("Height Compression", Range(0.0, 2.0)) = 1.25
    }
    SubShader
    {
        Tags { "RenderType"="Opaque" }
        LOD 100
        Pass
        {
            CGPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #include "UnityCG.cginc"
            struct appdata
            {
                float4 vertex : POSITION;
                float2 uv : TEXCOORD0;
            };
            struct v2f
            {
                float2 uv : TEXCOORD0;
                float4 vertex : SV_POSITION;
            };
            sampler2D _MainTex;
            float4 _MainTex_ST;
            sampler2D _mainRT;
            int _isLE;
            float _contentRatio;
            float _visibleRatio;
            float _heightCompressionFactor;
            
            v2f vert (appdata v)
            {
                v2f o;
                o.vertex = UnityObjectToClipPos(v.vertex);
                o.uv = TRANSFORM_TEX(v.uv, _MainTex);
                return o;
            }
            
            fixed4 frag (v2f i) : SV_Target
            {   
                fixed4 col = fixed4(0.0, 0.0, 0.0, 0.0);
                
                // Adjust UV coordinates based on eye
                float2 adjusted_uv = i.uv;
                
                // Apply the x shift to the clipping center
                if(_isLE == 1) // Left eye
                {
                    adjusted_uv.x = i.uv.x + 0.08/2; // Shift left for left eye
                }
                else // Right eye
                {
                    adjusted_uv.x = i.uv.x - 0.08/2; // Shift right for right eye
                }
                
                // Calculate the bounds for visible area based on visibleRatio with 4:3 aspect ratio
                float widthRatio = _visibleRatio;
                float heightRatio = _visibleRatio * (3.0/4.0); // Apply 4:3 aspect ratio
                
                float minBoundX = (1.0 - widthRatio) * 0.5;
                float maxBoundX = 1.0 - minBoundX;
                float minBoundY = (1.0 - heightRatio) * 0.5;
                float maxBoundY = 1.0 - minBoundY;
                
                // Check if the current pixel is within the visible bounds
                // using the adjusted UV for x-coordinate
                if (adjusted_uv.x < minBoundX || adjusted_uv.x > maxBoundX || 
                    i.uv.y < minBoundY || i.uv.y > maxBoundY) {
                    return col; // Return transparent/black pixel
                }
                
                // Use original UV coordinates for texture sampling
                float2 new_uv = i.uv;
                
                // Apply height compression
                new_uv.y = (new_uv.y - 0.5) * _heightCompressionFactor + 0.5;
                
                if(_isLE == 1) // Left eye
                {
                    // Apply content ratio with consistent centering
                    float scaled_x = new_uv.x * _contentRatio + (1.0 - _contentRatio) * 0.5 + 0.08;
                    
                    // Map to left half of stereo texture
                    float final_x = scaled_x * 0.5;
                    float final_y = new_uv.y * _contentRatio + (1.0 - _contentRatio) * 0.5;
                    
                    col = tex2D(_mainRT, float2(final_x, final_y));
                }
                else // Right eye
                { 
                    // Apply content ratio with consistent centering
                    float scaled_x = new_uv.x * _contentRatio + (1.0 - _contentRatio) * 0.5 - 0.08;
                    
                    // Map to right half of stereo texture
                    float final_x = scaled_x * 0.5 + 0.5;
                    float final_y = new_uv.y * _contentRatio + (1.0 - _contentRatio) * 0.5;
                    
                    col = tex2D(_mainRT, float2(final_x, final_y));
                }
                
                return col;
            }
            ENDCG
        }
    }
}