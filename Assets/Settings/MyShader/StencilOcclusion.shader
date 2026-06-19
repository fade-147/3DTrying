Shader "MyShader/StencilOcclusion"
{
    // Team-mate through-wall Fresnel highlight.
    //
    // IMPORTANT: this shader relies on StencilWrite.shader (Queue=Geometry-1)
    // being added as a separate material before this one.  The stencil write
    // pre-fills stencil=1 at all team-mate visible pixels so that Stencil
    // NotEqual 1 blocks the highlight from bleeding through the character's
    // own clothing / equipment.
    //
    // Render order (guaranteed by Queue values):
    //   1. StencilWrite (1999) — all renderers — depth + stencil=1
    //   2. Opaque geometry  (2000) — body, clothing, world
    //   3. THIS shader      (3000) — ZTest Greater + Stencil NotEqual 1
    //      -> shows only through walls, never through own meshes

    Properties
    {
        [MainColor] _BaseColor("Color", Color) = (0.2719384, 0.8416287, 0.9150943, 1)
        _DitherCount ("Dither Count", Range(0, 1)) = 1

        // URP standard blend / transparency controls
        _Surface("__surface", Float) = 1.0          // Transparent
        _Blend  ("__blend",   Float) = 0.0
        _Cull   ("__cull",    Float) = 0.0          // Off  (Both faces)
        [ToggleUI] _AlphaClip("__clip", Float) = 0.0
        [HideInInspector] _SrcBlend("__src", Float) = 5.0
        [HideInInspector] _DstBlend("__dst", Float) = 10.0
        [HideInInspector] _SrcBlendAlpha("__srcA", Float) = 5.0
        [HideInInspector] _DstBlendAlpha("__dstA", Float) = 10.0
        [HideInInspector] _ZWrite("__zw", Float) = 0.0
        [HideInInspector] _QueueOffset("_QueueOffset", Float) = 0.0
    }

    SubShader
    {
        Tags
        {
            "RenderType"            = "Transparent"
            "Queue"                 = "Transparent"
            "IgnoreProjector"       = "True"
            "UniversalMaterialType" = "Unlit"
            "RenderPipeline"        = "UniversalPipeline"
        }
        LOD 100

        Blend [_SrcBlend][_DstBlend], [_SrcBlendAlpha][_DstBlendAlpha]
        ZWrite [_ZWrite]
        Cull [_Cull]

        Pass
        {
            Name "Occlusion"
            Tags { "LightMode" = "UniversalForward" }

            Blend SrcAlpha OneMinusSrcAlpha
            ZWrite Off
            ZTest Greater
            Cull Back
            Offset 0, -1   // pull depth closer — ensures ZTest Greater fails on
                            // visible pixels despite float-precision differences
                            // between TransformObjectToHClip and skin shaders

            HLSLPROGRAM
            #pragma target 4.5
            #pragma vertex Vert
            #pragma fragment Frag

            #pragma shader_feature_local_fragment _SURFACE_TYPE_TRANSPARENT
            #pragma shader_feature_local_fragment _ALPHATEST_ON

            #pragma multi_compile_fog
            #pragma multi_compile_instancing
            #include_with_pragmas "Packages/com.unity.render-pipelines.universal/ShaderLibrary/RenderingLayers.hlsl"

            #include "Packages/com.unity.render-pipelines.universal/ShaderLibrary/Core.hlsl"

            CBUFFER_START(UnityPerMaterial)
                half4 _BaseColor;
                float _DitherCount;
            CBUFFER_END

            static const float DITHER_THRESHOLDS[16] =
            {
                 1.0 / 17.0,   9.0 / 17.0,   3.0 / 17.0,  11.0 / 17.0,
                13.0 / 17.0,   5.0 / 17.0,  15.0 / 17.0,   7.0 / 17.0,
                 4.0 / 17.0,  12.0 / 17.0,   2.0 / 17.0,  10.0 / 17.0,
                16.0 / 17.0,   8.0 / 17.0,  14.0 / 17.0,   6.0 / 17.0
            };

            struct Attributes
            {
                float4 positionOS : POSITION;
                float3 normalOS   : NORMAL;
            };

            struct Varyings
            {
                float4 positionCS  : SV_POSITION;
                float3 worldNormal : TEXCOORD0;
                float3 worldPos    : TEXCOORD1;
            };

            Varyings Vert(Attributes input)
            {
                Varyings o;
                // TransformObjectToHClip (one matrix mul) — MUST match the Z
                // produced by URP Simple Lit / Lit shaders exactly, otherwise
                // ZTest Greater sees a tiny float-precision offset and passes
                // at every pixel.
                o.positionCS = TransformObjectToHClip(input.positionOS.xyz);

                // World-space position for Fresnel view direction.
                o.worldPos = TransformObjectToWorld(input.positionOS.xyz);

                // World-space normal for Fresnel calculation.
                VertexNormalInputs normInputs = GetVertexNormalInputs(input.normalOS);
                o.worldNormal = normInputs.normalWS;
                return o;
            }

            half4 Frag(Varyings input) : SV_Target
            {
                float3 worldNormal  = normalize(input.worldNormal);
                float3 worldViewDir = normalize(_WorldSpaceCameraPos - input.worldPos);
                float  fresnel      = 1.0 - saturate(dot(worldNormal, worldViewDir));
                half3  baseColor    = fresnel * _BaseColor.rgb;

                uint2 pixel       = uint2(input.positionCS.xy);
                uint  ditherIndex = (pixel.x % 4u) * 4u + (pixel.y % 4u);
                float alpha       = _DitherCount - DITHER_THRESHOLDS[ditherIndex];
                alpha             = saturate(alpha);

                return half4(baseColor, alpha);
            }
            ENDHLSL
        }
    }

    FallBack "Hidden/Universal Render Pipeline/FallbackError"
}
