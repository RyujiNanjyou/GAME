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
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name, const char* EffectName)override;
	//更新。
	void Update()override;
	void UpdateWorldMatrix(const D3DXVECTOR3& trans, const D3DXQUATERNION& rot, const D3DXVECTOR3& scale);
};

