#pragma once

#include "GameObject.h"
#include "CharacterController.h"
#include "MeshCollider.h"

class Stage : public GameObject {
public:
	//コンストラクタ
	Stage();
	//デストラクタ
	~Stage();
	//初期化。
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name) override;
	//更新。
	bool Update() override;
private:
	RigidBody				rigidBody;		//剛体。
	MeshCollider			meshCollider;	//メッシュコライダー。
	CharacterController     characterController;	//キャラクタコントローラ。
};