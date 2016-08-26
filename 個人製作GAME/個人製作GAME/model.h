#pragma once



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
		int numDiffuseLight
		);
	//開放。
	void Release();
	//座標を設定。
	void SetPosition(D3DXVECTOR3 pos);
private:
	
	LPD3DXMESH				mesh;			//メッシュ。
	LPDIRECT3DTEXTURE9*		textures;		//テクスチャ。
	DWORD					numMaterial;	//マテリアルの数。
	ID3DXEffect*			effect;			//エフェクト。
	
};