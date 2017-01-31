#pragma once

#include "GameObject.h"
#include "CharacterController.h"
#include "seat.h"

#define SEAT_NUM 100


class Seat;
//unityちゃんクラス。
class Unity : public GameObject {
public:
	//コンストラクタ
	Unity();
	//デストラクタ
	~Unity();
	//初期化。
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name)override;
	//更新。
	bool Update()override;




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