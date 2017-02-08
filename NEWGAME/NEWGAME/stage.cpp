#include "stdafx.h"
#include "stage.h"
#include "game.h"
#include "TestScene.h"


//コンストラクタ
Stage::Stage()
{
	//初期化。
	D3DXMatrixIdentity(&mWorld);
	D3DXMatrixIdentity(&mRot);
}

//デストラクタ
Stage::~Stage()
{
	test->GetPhysicsWorld()->RemoveRigidBody(&rigidBody);
	Release();
}

void Stage::Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name)
{
	GameObject::Init(pd3dDevice, Name);
	position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	rotation = D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f);
	scale = D3DXVECTOR3(1.0, 1.0, 1.0);
	Update();
	//スキンモデルからメッシュコライダーを作成する。
	D3DXMATRIX* rootBoneMatrix = skinmodeldata.GetRootBoneWorldMatrix();
	meshCollider.CreateFromSkinModel(&skinmodel, rootBoneMatrix);
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
	test->GetPhysicsWorld()->AddRigidBody(&rigidBody);
}


//更新。
bool Stage::Update()
{

	test->UpdateLight();
	skinmodel.UpdateWorldMatrix(position, rotation, scale);
	return true;
}
