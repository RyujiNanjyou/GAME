#include "stdafx.h"
#include "MapChip.h"
#include "game.h"

MapChip::MapChip()
{
	D3DXMatrixIdentity(&mWorld);
	D3DXMatrixIdentity(&mRot);
}


MapChip::~MapChip()
{
	game->GetPhysicsWorld()->RemoveRigidBody(&rigidBody);
}
void MapChip::Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name)
{
	GameObject::Init(pd3dDevice, Name);

	skinmodel.SetShadowReceiverFlag(true);
	position = D3DXVECTOR3(0.0,-3.0,0.0);
	rotation = D3DXQUATERNION(0.0,0.0,0.0,1.0);
	scale = D3DXVECTOR3(1.0,1.0,1.0);
	//ここから衝突判定絡みの初期化。
	Update();
	//スキンモデルからメッシュコライダーを作成する。
	D3DXMATRIX* rootBoneMatrix = skinmodeldata.GetRootBoneWorldMatrix();
	meshCollider.CreateFromSkinModel(&skinmodel,rootBoneMatrix);
	//続いて剛体を作成する。

	//まずは剛体を作成するための情報を設定。
	RigidBodyInfo rbInfo;
	rbInfo.collider = &meshCollider;	//剛体のコリジョンを設定する。
	rbInfo.mass = 0.0f;					//質量を0にすると動かない剛体になる。
	rbInfo.pos = position;
	rbInfo.rot = rotation;
	rbInfo.scale = scale;
	//剛体を作成。
	rigidBody.Create(rbInfo);
	//作成した剛体を物理ワールドに追加。
	game->GetPhysicsWorld()->AddRigidBody(&rigidBody);
}
bool MapChip::Update()
{
	game->UpdateLight();
	skinmodel.UpdateWorldMatrix(position, rotation, scale);
	return true;
}
