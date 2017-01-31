/*!
*@brief	簡単なディフューズライティングのシェーダー。
*/

float4x4 g_worldMatrix;			//ワールド行列。
float4x4 g_viewMatrix;			//ビュー行列。
float4x4 g_projectionMatrix;	//プロジェクション行列。
float4x4 g_rotationMatrix;		//回転行列。法線を回転させるために必要になる。ライティングするなら必須。
float4x4 g_lightviewprojMatrix;
#define DIFFUSE_LIGHT_NUM	4		//ディフューズライトの数。
float4	g_diffuseLightDirection[DIFFUSE_LIGHT_NUM];	//ディフューズライトの方向。
float4	g_diffuseLightColor[DIFFUSE_LIGHT_NUM];		//ディフューズライトのカラー。
float4	g_ambientLight;								//環境光。

float3 vEyepos;
int		g_shadowreceiveflag;
texture g_diffuseTexture;		//ディフューズテクスチャ。
texture g_shadowTexture;
sampler g_diffuseTextureSampler =
sampler_state
{
	Texture = <g_diffuseTexture>;
	MipFilter = NONE;
	MinFilter = NONE;
	MagFilter = NONE;
	AddressU = Wrap;
	AddressV = Wrap;
};
sampler g_shadowTextureSampler =
sampler_state
{
	Texture = <g_shadowTexture>;
	MipFilter = LINEAR;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
	AddressU = Clamp;
	AddressV = Clamp;
};

struct VS_INPUT{
	float4	pos		: POSITION;
	float4	color	: COLOR0;
	float3	normal	: NORMAL0;
	float2	uv		: TEXCOORD0;
};

struct VS_OUTPUT{
	float4	pos		: POSITION;
	float4	color	: COLOR0;
	float2	uv		: TEXCOORD0;
	float3	normal	: TEXCOORD1;
	float3	eye		: TEXCOORD2;
	float4  lightViewPos	: TEXCOORD3;

};

/*!
*@brief	頂点シェーダー。
*/
VS_OUTPUT VSMain(VS_INPUT In)
{
	VS_OUTPUT Out;
	float4 pos;
	pos = mul(In.pos, g_worldMatrix);		//モデルのローカル空間からワールド空間に変換。
	float4 worldpos = pos;
	pos = mul(pos, g_viewMatrix);			//ワールド空間からビュー空間に変換。
	pos = mul(pos, g_projectionMatrix);	//ビュー空間から射影空間に変換。
	Out.pos = pos;
	float amb = -g_diffuseLightDirection[0].w;
	float3 L = -g_diffuseLightDirection[0].xyz;
		Out.color = In.color * max(amb, dot(In.normal, -g_diffuseLightDirection[0].xyz));
	Out.eye = vEyepos - pos.xyz;
	if (g_shadowreceiveflag == true)
	{
		Out.lightViewPos = mul(float4(worldpos.xyz,1.0f),g_lightviewprojMatrix);
	}
	Out.uv = In.uv;
	Out.normal = mul(In.normal, g_rotationMatrix);	//法線を回す。
	return Out;

	
}

/*!
*@brief	ピクセルシェーダー。
*/
float4 PSMain(VS_OUTPUT In) : COLOR
{
	//ライトを計算。
	float4 lig = 0.0f;
	for (int i = 0; i < DIFFUSE_LIGHT_NUM; i++)
	{
		lig.xyz += max(0.0f, dot(In.normal.xyz, -g_diffuseLightDirection[i].xyz));
		float3 L = -g_diffuseLightDirection[i].xyz;
			float3 N = normalize(L + normalize(In.eye));
			float3 R = normalize(In.normal);
			lig.xyz += pow(max(0.0f, dot(R, N)), 10.0f);
	}
	/*t = max(0.0f, t);
	lig.xyz = g_diffuseLightColor[0].xyz * t;*/
	
	float4 color = tex2D(g_diffuseTextureSampler, In.uv);
	if (g_shadowreceiveflag == 1)
	{
		float4 posInLVP = In.lightViewPos;
		posInLVP.xyz /= posInLVP.w;
		//uv座標に変換。
		float2 shadowMapUV = float2(0.5f, -0.5f) * posInLVP.xy + float2(0.5f, 0.5f);
		if ((shadowMapUV.x > 0.0f && shadowMapUV.x < 1.0f) && (shadowMapUV.y > 0.0f && shadowMapUV.y < 1.0f))
		{
			lig.xyz *= tex2D(g_shadowTextureSampler, shadowMapUV).xyz;
		}
	}
	lig += g_ambientLight;
	//lig
	color.xyz *= lig;
	return  color;
}

technique SkinModel
{
	pass p0
	{
		VertexShader 	= compile vs_3_0 VSMain();
		PixelShader 	= compile ps_3_0 PSMain();
	}
}
	
