#include "stdafx.h"
#include "stage.h"
#include "game.h"
#include "TestScene.h"


//�R���X�g���N�^
Stage::Stage()
{
	//�������B
	D3DXMatrixIdentity(&mWorld);
	D3DXMatrixIdentity(&mRot);
}

//�f�X�g���N�^
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
	//�X�L�����f�����烁�b�V���R���C�_�[���쐬����B
	D3DXMATRIX* rootBoneMatrix = skinmodeldata.GetRootBoneWorldMatrix();
	meshCollider.CreateFromSkinModel(&skinmodel, rootBoneMatrix);
	//�܂��͍��̂��쐬���邽�߂̏���ݒ�B
	RigidBodyInfo rbInfo;
	rbInfo.collider = &meshCollider;	//���̂̃R���W������ݒ肷��B
	rbInfo.mass = 0.0f;					//���ʂ�0�ɂ���Ɠ����Ȃ����̂ɂȂ�B
	rbInfo.pos = position;
	rbInfo.rot = rotation;
	rbInfo.scale = scale;
	//���̂��쐬�B
	rigidBody.Create(rbInfo);
	//�쐬�������̂𕨗����[���h�ɒǉ��B
	test->GetPhysicsWorld()->AddRigidBody(&rigidBody);
}


//�X�V�B
bool Stage::Update()
{

	test->UpdateLight();
	skinmodel.UpdateWorldMatrix(position, rotation, scale);
	return true;
}
