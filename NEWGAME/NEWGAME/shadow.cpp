#include "stdafx.h"
#include "shadow.h"
#include "game.h"

extern LPDIRECT3DTEXTURE9 shadow;

ShadowMap::ShadowMap()
{
	pEffect = NULL;
}
ShadowMap::~ShadowMap()
{
	Release();
}

void ShadowMap::Create(int w, int h)
{
	D3DXMatrixIdentity(&rot);
	model[0].Init(g_pd3dDevice, "Assets/orima.x");
	model[1].Init(g_pd3dDevice, "Assets/pikumin.X");
	rendertarget.Create(w, h, 1, D3DFMT_A8R8G8B8, D3DFMT_D16, D3DMULTISAMPLE_NONE, 0);
	this->h = h;
	this->w = w;

	Near = 1.0f;
	Far = 1000.0f;


	LPD3DXBUFFER  compileErrorBuffer = NULL;
	HRESULT hr = D3DXCreateEffectFromFile(
		g_pd3dDevice,
		"Assets/shadowmap.fx",
		NULL,
		NULL,
		D3DXSHADER_DEBUG,
		NULL,
		&pEffect,
		&compileErrorBuffer
		);
	if (FAILED(hr)) {
		MessageBox(NULL, (char*)(compileErrorBuffer->GetBufferPointer()), "error", MB_OK);
		abort();
	}
}

void ShadowMap::Render(
	LPDIRECT3DDEVICE9 pd3dDevice,
	D3DXMATRIX viewMatrix,
	D3DXMATRIX projMatrix,
	D3DXVECTOR4* diffuseLightDirection,
	D3DXVECTOR4* diffuseLightColor,
	D3DXVECTOR4	 ambientLight,
	int numDiffuseLight
	)
{

	g_pd3dDevice->GetViewport(&viewport);
	g_pd3dDevice->GetRenderTarget(0, &BackBuffer);
	g_pd3dDevice->GetDepthStencilSurface(&BackZ);

	g_pd3dDevice->SetRenderTarget(0, rendertarget.GetRenderTarget());
	g_pd3dDevice->SetDepthStencilSurface(rendertarget.GetDepthStencilBuffer());

	g_pd3dDevice->Clear(
		0,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f),
		1.0f,
		0);

	D3DVIEWPORT9 viewport = { 0, 0, w, h, 0.0f, 1.0f };
	g_pd3dDevice->SetViewport(&viewport);
	g_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	float aspect;
	aspect = (float)viewport.Width / (float)viewport.Height;
	D3DXMatrixPerspectiveFovLH(&ProjMatrix, D3DXToRadian(45.0f), aspect, Near, Far);
	CreateLight(ProjMatrix);
	ID3DXEffect* backup[2];
	for (int i = 0; i < 2; i++)
	{
		backup[i] = model[i].Geteffect();
		model[i].Seteffect(pEffect);


	}
	
	

	model[0].Render(pd3dDevice,
		viewMatrix,
		game->GETunity()->Getworld(),			//ワールド行列。
		game->GETunity()->GetRot(),		//回転行列。
		projMatrix,
		diffuseLightDirection,
		diffuseLightColor,
		ambientLight,
		numDiffuseLight,
		true
		);
	Pikumin* min = game->Getpikumin();
	for (int i = 0; i < PIKUMIN; i++)
	{
		model[1].Render(pd3dDevice,
			viewMatrix,
			min[i].Getworld(),			//ワールド行列。
			min[i].GetRot(),		//回転行列。
			projMatrix,
			diffuseLightDirection,
			diffuseLightColor,
			ambientLight,
			numDiffuseLight,
			true
			);
	}
	

	//game->GETunity()->Render
	//	(
	//	pd3dDevice,
	//	viewMatrix,
	//	projMatrix,
	//	diffuseLightDirection,
	//	diffuseLightColor,
	//	ambientLight,
	//	numDiffuseLight,
	//	true
	//	); 

	model[0].Seteffect(backup[0]);
	model[1].Seteffect(backup[1]);
	g_pd3dDevice->SetRenderTarget(0, BackBuffer);
	g_pd3dDevice->SetDepthStencilSurface(BackZ);
	g_pd3dDevice->SetViewport(&viewport);
	g_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
	shadow = rendertarget.GetTexture();
}

void ShadowMap::CreateLight(D3DXMATRIX proj)
{
	D3DXVECTOR3 lightUp;
	float t = fabsf(D3DXVec3Dot(&lightdir, &D3DXVECTOR3(0.0f, 1.0f, 0.0f)));
	if (fabsf((t - 1.0f)) < 0.00001f)
	{
		lightUp = D3DXVECTOR3(1.0f, 0.0f, 0.0f);
	}
	else
	{
		lightUp = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	}
	D3DXVECTOR3 target;
	D3DXVec3Add(&target, &lightpos, &lightdir);
	D3DXMatrixLookAtLH(&lvMatrix, &lightpos, &target, &lightUp);
	D3DXMatrixMultiply(&LVPMatrix, &lvMatrix, &proj);
}
void ShadowMap::Release()
{
	if (pEffect != nullptr) {

		pEffect = nullptr;
	}
}