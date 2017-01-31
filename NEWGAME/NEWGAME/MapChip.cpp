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
	//��������Փ˔��藍�݂̏������B
	Update();
	//�X�L�����f�����烁�b�V���R���C�_�[���쐬����B
	D3DXMATRIX* rootBoneMatrix = skinmodeldata.GetRootBoneWorldMatrix();
	meshCollider.CreateFromSkinModel(&skinmodel,rootBoneMatrix);
	//�����č��̂��쐬����B

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
	game->GetPhysicsWorld()->AddRigidBody(&rigidBody);
}
bool MapChip::Update()
{
	game->UpdateLight();
	skinmodel.UpdateWorldMatrix(position, rotation, scale);
	return true;
}
