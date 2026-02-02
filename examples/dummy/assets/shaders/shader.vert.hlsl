struct Input {
    uint VertexIndex : SV_VertexID;
};

struct Output {
    float4 Color : TEXCOORD0;
    float4 Position : SV_Position;
};

Output main(Input input) {
    float2 quadPos[6] = {
        float2(-1,-1), float2( 1,-1), float2( 1, 1),
        float2( 1, 1), float2(-1, 1), float2(-1,-1)
    };

    float4 quadColor[6] = {
        float4(1.0f, 0.0f, 0.0f, 1.0f), float4(0.0f, 1.0f, 0.0f, 1.0f), float4(0.0f, 0.0f, 1.0f, 1.0f),
        float4(0.0f, 0.0f, 1.0f, 1.0f), float4(0.0f, 0.0f, 0.0f, 1.0f), float4(1.0f, 0.0f, 0.0f, 1.0f)
    };

    Output output;
    float2 pos = quadPos[input.VertexIndex];
    output.Color = quadColor[input.VertexIndex];

    output.Position = float4(pos, 0.0f, 1.0f);
    return output;
}
