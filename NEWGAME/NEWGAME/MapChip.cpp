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
void MapChip::Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name, const char* EffectName)
{
	GameObject::Init(pd3dDevice, Name, EffectName);
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
	model.Setshadowflag(true);
	//ここから衝突判定絡みの初期化。
	//スキンモデルからメッシュコライダーを作成する。
	//D3DXMATRIX* rootBoneMatrix = model.GetRootBoneWorldMatrix();
	meshCollider.CreateFromSkinModel(&model, &mWorld);
	//続いて剛体を作成する。
	//まずは剛体を作成するための情報を設定。
	RigidBodyInfo rbInfo;
	rbInfo.collider = &meshCollider;	//剛体のコリジョンを設定する。
	rbInfo.mass = 0.0f;					//質量を0にすると動かない剛体になる。
	rbInfo.pos = position;
	rbInfo.rot = rotation;
	//剛体を作成。
	rigidBody.Create(rbInfo);
	//作成した剛体を物理ワールドに追加。
	game->GetPhysicsWorld()->AddRigidBody(&rigidBody);

}
void MapChip::Update()
{
	game->UpdateLight();
}
