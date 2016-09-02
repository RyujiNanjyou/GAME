#pragma once

#include "model.h"
#include "seat.h"

#define SEAT_NUM 100



//unityちゃんクラス。
class Unity {
public:
	//コンストラクタ
	Unity();
	//デストラクタ
	~Unity();
	//初期化。
	void Init(LPDIRECT3DDEVICE9 pd3dDevice);
	//更新。
	void Update();
	//描画。
	void Unity::Render(
		LPDIRECT3DDEVICE9 pd3dDevice,
		D3DXMATRIX viewMatrix,
		D3DXMATRIX projMatrix,
		D3DXVECTOR4* diffuseLightDirection,
		D3DXVECTOR4* diffuseLightColor,
		D3DXVECTOR4	 ambientLight,
		int numDiffuseLight
		);
	void UpdateWorldMatrix(const D3DXVECTOR3& trans, const D3DXQUATERNION& rot, const D3DXVECTOR3& scale);
	//開放。
	void Release();


	const D3DXMATRIX& GetRot() const
	{
		return mRotation;
	}
	const D3DXVECTOR3& Getpos() const
	{
		return position;
	}

	Seat* Getseat()
	{
		return seat;
	}

private:
	D3DXVECTOR3	toseat;
	Seat					seat[SEAT_NUM];
	Model					model;
	D3DXVECTOR3				position;		//座標。
	D3DXQUATERNION			rotation;		//回転
	D3DXMATRIX				mWorld;			//ワールド行列。
	D3DXMATRIX				mRotation;
	D3DXVECTOR3				moveDir;
	D3DXVECTOR3 direction_z;	//プレイヤーのZ方向。
	D3DXVECTOR3 direction_x;	//プレイヤーのX方向。//回転行列。
};