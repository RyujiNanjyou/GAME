#pragma once

#include "model.h"
#include "seat.h"
#include "pikumin.h"
#include "GameObject.h"
#include "CharacterController.h"

#define SEAT_NUM 100



//unityちゃんクラス。
class Unity : public GameObject {
public:
	//コンストラクタ
	Unity();
	//デストラクタ
	~Unity();
	//初期化。
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name, const char* EffectName)override;
	//更新。
	void Update()override;
	void UpdateWorldMatrix(const D3DXVECTOR3& trans, const D3DXQUATERNION& rot, const D3DXVECTOR3& scale);



	Seat* Getseat()
	{
		return seat;
	}
	const D3DXVECTOR3 Getdir_z(){ return direction_z; }
	
private:
	D3DXVECTOR3				toseat;
	Seat					seat[SEAT_NUM];
	D3DXVECTOR3				forward;
	D3DXVECTOR3				direction_z;	//プレイヤーのZ方向。
	D3DXVECTOR3				direction_x;	//プレイヤーのX方向。//回転行列。
	CharacterController     characterController;	//キャラクタコントローラ。
};