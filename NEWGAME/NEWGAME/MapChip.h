#pragma once

#include "GameObject.h"
#include "model.h"
#include "MeshCollider.h"
#include "RigidBody.h"


//マップチップの配置情報。
struct SMapChipLocInfo {
	const char* modelName;		//モデル。
	D3DXVECTOR3	pos;			//座標。
	D3DXQUATERNION	rotation;		//回転。
};
class MapChip : public GameObject
{
public:
	MapChip();
	~MapChip();
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name, const char* EffectName)override;
	void Update()override;
	
private:
	RigidBody rigidBody;		//剛体。
	MeshCollider meshCollider;	//メッシュコライダー。
	//std::unique_ptr<D3DXMATRIX[]>		worldMatrixBuffer;	//ワールド行列のバッファ
};

