#pragma once
#include "GameObject.h"
#include "CharacterController.h"

class pointer : public GameObject
{
	D3DXVECTOR3				moveDir;
	D3DXVECTOR3				direction_z;	//プレイヤーのZ方向。
	D3DXVECTOR3				direction_x;	//プレイヤーのX方向。//回転行列。
	CharacterController     characterController;	//キャラクタコントローラ。
public:
	pointer();
	~pointer();
	//初期化。
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name)override;
	//更新。
	bool Update()override;
};

