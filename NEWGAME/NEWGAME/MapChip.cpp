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
	SMapChipLocInfo map;
	
	D3DXVECTOR3 trans, scale;
	
	D3DXMatrixRotationQuaternion(&mRot, &rotation);
	//ロードしたモデルデータを使ってSkinModelを初期化。
	D3DXMATRIX mTrans, mScale;
	D3DXMatrixScaling(&mScale, scale.x, scale.y, scale.z);
	D3DXMatrixTranslation(&mTrans, trans.x, trans.y, trans.z);
	D3DXMatrixRotationQuaternion(&mRot, &rotation);
	mWorld = mScale * mRot * mTrans;
	D3DXMatrixTranslation(&mWorld, position.x, position.y, position.z);
	skinmodel.SetDrawToShadowMap(true);
	skinmodel.UpdateWorldMatrix(position, rotation, D3DXVECTOR3(1.0, 1.0, 1.0));
	//ここから衝突判定絡みの初期化。
	//スキンモデルからメッシュコライダーを作成する。
	D3DXMATRIX* rootBoneMatrix = skinmodeldata.GetRootBoneWorldMatrix();
	meshCollider.CreateFromSkinModel(&skinmodel, rootBoneMatrix);
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
