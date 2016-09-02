#pragma once

#include "model.h"
#include "unity.h"

#define GRVITY 0.09f
#define POWER 1.0f

class Pikumin {
public:
	//コンストラクタ
	Pikumin();
	//デストラクタ
	~Pikumin();
	//初期化。
	void Init(LPDIRECT3DDEVICE9 pd3dDevice);
	//更新。
	void Update();
	//描画。
	void Pikumin::Render(
		LPDIRECT3DDEVICE9 pd3dDevice,
		D3DXMATRIX viewMatrix,
		D3DXMATRIX projMatrix,
		D3DXVECTOR4* diffuseLightDirection,
		D3DXVECTOR4* diffuseLightColor,
		D3DXVECTOR4	 ambientLight,
		int numDiffuseLight
		);
	//開放。
	void Release();
	//座標を設定。
	void SetPosition(D3DXVECTOR3 pos)
	{
		position = pos;
	}




private:
	Unity					uni;
	Model					model;
	D3DXVECTOR3				position;		//座標。
	D3DXMATRIX				mWorld;			//ワールド行列。
	D3DXMATRIX				mRotation;
	int						m_seatNo;		//座っているシートの番号。
	bool					flag_pikumin;   
	float					len;
	float					Speed;

};