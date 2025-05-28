Shader "PXR/HandCursor"
{
    Properties
    {
        [Header(Max)]
        _MaxOpen("MaxOpen",Range(0,1))= 0.721
        _MaxClose("MaxClose",Range(0,1))= 1

        [Header(Min)]
        _MinOpen("MinOpen",Range(0,1))= 0
        _MinClose("MinClose",Range(0,1))= 0.53

        [Header(Mid)]
        _MidMaxOpen("MidMaxOpne",Range(0,1))= 0.564
        _MidMaxClose("MidMaxClose",Range(0,1))= 0.87

        [Space(5)]
        _ClickStrength("ClickStrength",Range(0,1))= 0

        _OutColor("OutColor",Color) = (0.2264,0.2264,0.2264,0.6156863)
        _InnerColor("InnerColor",Color) = (0,0.688138,1,1)

        _InnerAlpha("InnerAlpha",Range(0,1)) = 1
    }
    CGINCLUDE
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

    uniform float _MaxOpen;
    uniform float _MaxClose;

    uniform float _MinOpen;
    uniform float _MinClose;

    uniform float _MidMaxOpen;
    uniform float _MidMaxClose;

    uniform float _ClickStrength;

    uniform fixed4 _OutColor;
    uniform fixed4 _InnerColor;

    uniform fixed _InnerAlpha;


    float max_lerp()
    {
        return lerp(_MaxOpen, _MaxClose, _ClickStrength);
    }
    float min_lerp()
    {
        return lerp(_MinOpen, _MinClose, _ClickStrength);
    }
    float mid_lerp()
    {
        return lerp(_MidMaxOpen, _MidMaxClose, _ClickStrength);
    }
    void Unity_Ellipse_float(float2 UV, float Width, float Height, out float Out)
    {
        float d = length((UV * 2 - 1) / float2(Width, Height));
        Out = saturate((1 - d) / fwidth(d));
    }
    void Unity_Remap_float(float4 In, float2 InMinMax, float2 OutMinMax, out float Out)
    {
        Out = OutMinMax.x + (In - InMinMax.x) * (OutMinMax.y - OutMinMax.x) / (InMinMax.y - InMinMax.x);
    }

    v2f vert(appdata v)
    {
        v2f o;
        o.vertex = UnityObjectToClipPos(v.vertex);
        o.uv = v.uv;
        return o;
    }

    fixed4 frag(v2f i) : SV_Target
    {
        float maxLerp = max_lerp();
        float max;
        Unity_Ellipse_float(i.uv, maxLerp, maxLerp, max);

        float minLerp = min_lerp();
        float min;
        Unity_Ellipse_float(i.uv, minLerp, minLerp, min);

        float midLerp = mid_lerp();
        float mid;
        Unity_Ellipse_float(i.uv, midLerp, midLerp, mid);

        //绘制颜色
        fixed4 albedo = lerp(_OutColor, _InnerColor, mid);

        //绘制透明度
        float maxSubmin = max - min;
        float dis = distance(i.uv,fixed2(0.5, 0.5));
        fixed2 inMinMax = fixed2(minLerp / 2, midLerp / 2);
        fixed2 outMinMax = fixed2(_InnerAlpha, 1);

        float remapValue;
        Unity_Remap_float(dis, inMinMax, outMinMax, remapValue);
        float alpha = clamp(0, 1, remapValue);
        alpha *= alpha;
        alpha *= maxSubmin;
        alpha *= albedo.a;

        fixed4 finalColor = fixed4(1, 1, 1, 1);
        finalColor.rgb = albedo.rgb;
        finalColor.a = alpha;

        return finalColor;
    }
    ENDCG

    //SubShader
    //{
    //    Tags
    //    {
    //        "RenderPipeline" = "UniversalPipeline"
    //        "Queue" = "Transparent"
    //        "RenderType" = "Transparent"
    //        "IgnoreProjector" = "True"
    //    }
    //    Pass
    //    {
    //        Tags
    //        {
    //            "LightMode" = "UniversalForward"
    //        }
    //        //Blend SrcAlpha OneMinusSrcAlpha
    //        CGPROGRAM
    //        #pragma vertex vert
    //        #pragma fragment frag
    //        #pragma target 3.0
    //        ENDCG
    //    }
    //}
    SubShader
    {
        Tags
        {
            "Queue" = "Transparent"
            "RenderType" = "Opaque"
            //"IgnoreProjector" = "True"
        }
        Pass
        {
        ZWrite Off
        ZTest Off
            Blend SrcAlpha OneMinusSrcAlpha,One One
            CGPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #pragma target 3.0
            ENDCG
        }
    }
}