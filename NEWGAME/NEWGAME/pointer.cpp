#include "stdafx.h"
#include "pointer.h"
#include "game.h"


pointer::pointer()
{
	D3DXMatrixIdentity(&mWorld);
	D3DXMatrixIdentity(&mRot);
	direction_z = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	direction_x = D3DXVECTOR3(1.0f, 0.0f, 0.0f);
}

pointer::~pointer()
{
	Release();
}

void pointer::Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name, const char* EffectName)
{
	GameObject::Init(pd3dDevice, Name, EffectName);
	position = D3DXVECTOR3(0.0f, 0.01f, 0.0f);
	rotation = D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f);

	D3DXVECTOR3 pos = position;
	characterController.Init(0.3f, 1.0f, pos);
	characterController.SetGravity(-20.0f);	//�d�͋��߁B
}

void pointer::UpdateWorldMatrix(const D3DXVECTOR3& trans, const D3DXQUATERNION& rot, const D3DXVECTOR3& scale)
{
	D3DXMATRIX mTrans, mScale;
	D3DXMatrixScaling(&mScale, scale.x, scale.y, scale.z);
	D3DXMatrixTranslation(&mTrans, trans.x, trans.y, trans.z);
	D3DXMatrixRotationQuaternion(&mRot, &rot);
	/*D3DXMATRIX mAddRot;
	D3DXMatrixRotationY(&mAddRot, D3DXToRadian(-90.0f));
	mRotation = mRotation * mAddRot;*/
	mWorld = mScale * mRot * mTrans;
}

bool pointer::Update()
{
	D3DXVECTOR3 MoveSpeed = characterController.GetMoveSpeed();
	MoveSpeed.x = 0.0f;
	MoveSpeed.z = 0.0f;
	const float moveSpeed = 0.1f * 60.0f;

	moveDir = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	D3DXVECTOR3 padmovedir;
	padmovedir.x = game->GETPad()->GetRStickXF();
	padmovedir.z = game->GETPad()->GetRStickYF();

	moveDir.x = direction_x.x * padmovedir.x - direction_z.x * padmovedir.z;
	moveDir.z = direction_x.z * padmovedir.x - direction_z.z * padmovedir.z;


	//�J�����������Ă�������ɐi�ށB
	direction_z = game->GetGameCamera().GetCameraDir();
	D3DXVec3Normalize(&moveDir, &moveDir);
	//�J�����̌����Ă�������ƁA��x�N�g���Ƃ̊O�ς��v�Z����Ɖ��ړ��̃x�N�g�������܂�B
	D3DXVec3Cross(&direction_x, &direction_z, &D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	//position += moveDir * moveSpeed;
	//�L�����N�^���������x��ݒ�B
	MoveSpeed += moveDir * moveSpeed;
	characterController.SetMoveSpeed(MoveSpeed);
	//�L�����N�^�R���g���[���[�����s�B
	characterController.Execute();
	position = characterController.GetPosition();
	//��]���v�Z�B
	if (D3DXVec3Length(&moveDir) > 0.0f){
		D3DXVECTOR3 forward = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
		float angle = acos(D3DXVec3Dot(&forward, &moveDir));
		D3DXVECTOR3 axis;
		D3DXVec3Cross(&axis, &forward, &moveDir);
		D3DXQuaternionRotationAxis(&rotation, &axis, angle);
	}
	D3DXVECTOR3 pos = position;
	pos.y += 0.2f;
	//���[���h�s��̍X�V�B
	UpdateWorldMatrix(pos, rotation, D3DXVECTOR3(3.0f, 0.0f, 3.0f));
	return true;
}
