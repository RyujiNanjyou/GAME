#include "stdafx.h"
#include "model.h"
#include "SkinModelData.h"
#include "game.h"
#include "SkinModel.h"


Model::Model()
{
	mesh = NULL;
	textures = NULL;
	numMaterial = 0;
	effect = NULL;
	
}

Model::~Model()
{
	Release();
}

//初期化
void Model::Init(LPDIRECT3DDEVICE9 pd3dDevice, char* fileNama)
{
	//Xファイルをロード。
	LPD3DXBUFFER pD3DXMtrlBuffer;
	//Xファイルのロード。
	D3DXLoadMeshFromX(fileNama, D3DXMESH_SYSTEMMEM,
		pd3dDevice, NULL,
		&pD3DXMtrlBuffer, NULL, &numMaterial,
		&mesh);
	// マテリアルバッファを取得。
	D3DXMATERIAL* d3dxMaterials = (D3DXMATERIAL*)pD3DXMtrlBuffer->GetBufferPointer();

	//テクスチャをロード。
	textures = new LPDIRECT3DTEXTURE9[numMaterial];
	for (DWORD i = 0; i < numMaterial; i++)
	{
		textures[i] = NULL;
		//テクスチャを作成する。
		HRESULT hr = D3DXCreateTextureFromFileA(pd3dDevice,
			d3dxMaterials[i].pTextureFilename,
			&textures[i]);
		char Assets[100] = "Assets//";
		if (hr != S_OK){
			//テクスチャ読み込み失敗。
			strcat(Assets, d3dxMaterials[i].pTextureFilename);
			 hr = D3DXCreateTextureFromFileA(pd3dDevice,
				 Assets,
				&textures[i]);
			//std::abort();
		}
	}
	// マテリアルバッファを解放。
	pD3DXMtrlBuffer->Release();

}
//UPDATE
void Model::Update()
{
}
void Model::Render(
	LPDIRECT3DDEVICE9 pd3dDevice,
	D3DXMATRIX viewMatrix,
	D3DXMATRIX World,			//ワールド行列。
	D3DXMATRIX Rotation,		//回転行列。
	D3DXMATRIX projMatrix,
	D3DXVECTOR4* diffuseLightDirection,
	D3DXVECTOR4* diffuseLightColor,
	D3DXVECTOR4	 ambientLight,
	int numDiffuseLight,
	bool shadowflag
	)
{

	if (shadowflag == true)
	{

		effect->SetTechnique("RenderShadowMap");
		effect->Begin(NULL, D3DXFX_DONOTSAVESHADERSTATE);
		effect->BeginPass(0);

		D3DXMATRIX WVP;
		WVP = World * game->Getshadow()->Getlvpmatrix();
		effect->SetMatrix("g_mWVP", &WVP);

		for (DWORD i = 0; i < numMaterial; i++)
		{
			effect->CommitChanges();						//この関数を呼び出すことで、データの転送が確定する。描画を行う前に一回だけ呼び出す。
			// Draw the mesh subset
			mesh->DrawSubset(i);
		}


		effect->EndPass();
		effect->End();

	}
	else
	{
		effect->SetTechnique("SkinModel");
		effect->Begin(NULL, D3DXFX_DONOTSAVESHADERSTATE);
		effect->BeginPass(0);

		//定数レジスタに設定するカラー。
		D3DXVECTOR4 color(1.0f, 0.0f, 0.0f, 1.0f);
		//ワールド行列の転送。
		effect->SetMatrix("g_worldMatrix", &World);
		//ビュー行列の転送。
		effect->SetMatrix("g_viewMatrix", &viewMatrix);			//ビュー行列を転送。

		effect->SetMatrix("g_projectionMatrix", &projMatrix);	//プロジェクション行列の転送。

		effect->SetMatrix("g_rotationMatrix", &Rotation);		//回転行列を転送。
		//ライトの向きを転送。
		effect->SetVectorArray("g_diffuseLightDirection", diffuseLightDirection, numDiffuseLight);
		//ライトのカラーを転送。
		effect->SetVectorArray("g_diffuseLightColor", diffuseLightColor, numDiffuseLight);
		//環境光を設定。
		effect->SetVector("g_ambientLight", &ambientLight);
		
		effect->SetMatrix("g_lightviewprojMatrix", &game->Getshadow()->Getlvpmatrix());
		effect->SetVector("vEyepos", &(D3DXVECTOR4)camera.GetEyePt());
		effect->SetInt("g_shadowreceiveflag", shadowreceiveflag);
		effect->SetTexture("g_shadowTexture", game->Getshadow()->GetRenderTarget()->GetTexture());
		for (DWORD i = 0; i < numMaterial; i++)
		{
			
			effect->SetTexture("g_diffuseTexture", textures[i]);
			effect->CommitChanges();						//この関数を呼び出すことで、データの転送が確定する。描画を行う前に一回だけ呼び出す。
			// Draw the mesh subset
			mesh->DrawSubset(i);
		}
		effect->EndPass();
		effect->End();
	}
	

	
	
	
}


//開放。
void Model::Release()
{
	//メッシュを開放。
	if (mesh != NULL) {
		mesh->Release();
		mesh = NULL;
	}
	//テクスチャを開放。
	if (textures != NULL) {
		for (unsigned int i = 0; i < numMaterial; i++) {
			if (textures[i] != NULL) {
				textures[i]->Release();
				textures[i] = NULL;
			}
		}
		delete[] textures;
		textures = NULL;
	}
	//エフェクトを開放。
	if (effect != NULL) {
		effect->Release();
		effect = NULL;
	}
}

LPD3DXMESH Model::GetOrgMeshFirst()
{
	return mesh;
}

LPD3DXMESH Model::GetOrgMesh(LPD3DXFRAME frame)
{
	D3DXMESHCONTAINER_DERIVED* pMeshContainer = (D3DXMESHCONTAINER_DERIVED*)(frame->pMeshContainer);
	if (pMeshContainer != NULL) {
		return pMeshContainer->pOrigMesh;
	}
	if (frame->pFrameSibling != NULL) {
		//兄弟
		LPD3DXMESH mesh = GetOrgMesh(frame->pFrameSibling);

		if (mesh) {
			return mesh;
		}
	}
	if (frame->pFrameFirstChild != NULL)
	{
		//子供。
		LPD3DXMESH mesh = GetOrgMesh(frame->pFrameFirstChild);
		if (mesh) {
			return mesh;
		}
	}

	return NULL;
}