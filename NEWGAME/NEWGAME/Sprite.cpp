#include "stdafx.h"
#include "Sprite.h"


Sprite::Sprite():
texture(nullptr),
spriteEffect(nullptr)
{
}


Sprite::~Sprite()
{
	if (spriteEffect != nullptr){
		spriteEffect->Release();
	}
	if (texture != nullptr){
		texture->Release();
	}
}

void Sprite::Init(const char* TexPath)
{


	HRESULT hr = D3DXCreateTextureFromFileA(g_pd3dDevice, TexPath, &texture);
	
	float halfW = 5.0f * 0.5f;

	float halfH = 5.0f * 0.5f;

	D3DXVECTOR4 uv(0.0f, 0.0f, 1.0f, 1.0f);
	

	position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	
	SShapeVertex vb[] = {
		{
			-halfW, halfH, 0.0f, 1.0f,
			uv.x, uv.y
		},
		{
			halfW, halfH, 0.0f, 1.0f,
			uv.z, uv.y
		},
		{
			-halfW, -halfH, 0.0f, 1.0f,
			uv.x, uv.w
		},
		{
			halfW, -halfH, 0.0f, 1.0f,
			uv.z, uv.w
		},

	};
	short index[]{
		0, 1, 2, 3
	};
	primitive.Create(
		CPrimitive::eTriangleStrip,
		4,
		sizeof(SShapeVertex),
		scShapeVertex_PT_Element,
		vb,
		4,
		D3DFMT_INDEX16,
		index
		);
	LPD3DXBUFFER  compileErrorBuffer = NULL;
	hr = D3DXCreateEffectFromFile(
		g_pd3dDevice,
		"Assets/ColorTexPrim.fx",
		NULL,
		NULL,
#ifdef _DEBUG
		D3DXSHADER_DEBUG,
#else
		D3DXSHADER_SKIPVALIDATION,
#endif
		NULL,
		&spriteEffect,
		&compileErrorBuffer
		);
	if (FAILED(hr)) {
		MessageBox(NULL, (char*)(compileErrorBuffer->GetBufferPointer()), "error", MB_OK);
		std::abort();
	}
}
void Sprite::Update()
{
	if (GetAsyncKeyState('W'))
	{
		scenemanager->ChangeScene(GameScene::GAME);
	}
}
void Sprite::Render(const D3DXMATRIX& viewMatrix, const D3DXMATRIX& projMatrix)
{
	D3DXMATRIX m, mTrans;
	D3DXMatrixTranslation(&mTrans, position.x, position.y, position.z);
	D3DXMATRIX Rot;
	D3DXMatrixInverse(&Rot, NULL, &viewMatrix);
	Rot.m[3][0] = 0.0f;
	Rot.m[3][1] = 0.0f;
	Rot.m[3][2] = 0.0f;
	Rot.m[3][3] = 1.0f;

	m = Rot * mTrans * viewMatrix * projMatrix;
	//アルファブレンディングを有効にする。
	g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
	g_pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_ONE);
	g_pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);


	spriteEffect->SetTechnique("ColorTexPrimAdd");

	spriteEffect->Begin(NULL, D3DXFX_DONOTSAVESHADERSTATE);
	spriteEffect->BeginPass(0);
	g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, FALSE);

	spriteEffect->SetValue("g_mWVP", &m, sizeof(m));
	spriteEffect->SetTexture("g_texture", texture);
	spriteEffect->CommitChanges();

	g_pd3dDevice->SetStreamSource(0, primitive.GetVertexBuffer()->GetBody(), 0, primitive.GetVertexBuffer()->GetStride());
	g_pd3dDevice->SetIndices(primitive.GetIndexBuffer()->GetBody());
	g_pd3dDevice->SetVertexDeclaration(primitive.GetVertexDecl());
	g_pd3dDevice->DrawIndexedPrimitive(primitive.GetD3DPrimitiveType(), 0, 0, primitive.GetNumVertex(), 0, primitive.GetNumPolygon());
	spriteEffect->EndPass();
	spriteEffect->End();
	g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
	g_pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_ONE);
	g_pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ZERO);
	g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
}