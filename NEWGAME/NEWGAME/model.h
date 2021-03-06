#pragma once
#include "camera.h"

class Model {
public:
	//コンストラクタ
	Model();
	//デストラクタ
	~Model();
	//初期化。
	void Init(LPDIRECT3DDEVICE9 pd3dDevice,char* fileName);
	//更新。
	void Update();
	
	//描画。
	void Model::Render(
		LPDIRECT3DDEVICE9 pd3dDevice,
		D3DXMATRIX viewMatrix,
		D3DXMATRIX	World,			//ワールド行列。
		D3DXMATRIX	Rotation,		//回転行列。
		D3DXMATRIX projMatrix,
		D3DXVECTOR4* diffuseLightDirection,
		D3DXVECTOR4* diffuseLightColor,
		D3DXVECTOR4	 ambientLight,
		int numDiffuseLight,
		bool shadowflag
		);
	//開放。
	void Release();
	//座標を設定。
	void SetPosition(D3DXVECTOR3 pos);
	ID3DXEffect* Geteffect()
	{
		return effect;
	}
	void Seteffect(ID3DXEffect* i)
	{
		effect = i;
	}
	void Setshadowflag(bool flag)
	{
		shadowreceiveflag = flag;
	}

	LPD3DXMESH GetOrgMeshFirst();

	LPD3DXMESH GetOrgMesh(LPD3DXFRAME frame);
	
private:
	Camera					camera;
	LPD3DXMESH				mesh;			//メッシュ。
	LPDIRECT3DTEXTURE9*		textures;		//テクスチャ。
	DWORD					numMaterial;	//マテリアルの数。
	ID3DXEffect*			effect;			//エフェクト。
	bool					shadowreceiveflag;
};