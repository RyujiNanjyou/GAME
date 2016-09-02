#include "stdafx.h"
#include "model.h"
#include "game.h"
#include "unity.h"
#include "seat.h"
#include "Input.h"

 

//�R���X�g���N�^
Unity::Unity()
{
	//�������B
	D3DXMatrixIdentity(&mWorld);
	D3DXMatrixIdentity(&mRotation);
	direction_z = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	direction_x = D3DXVECTOR3(1.0f, 0.0f, 0.0f);
}
//�f�X�g���N�^
Unity::~Unity()
{
	Release();
}
void Unity::Init(LPDIRECT3DDEVICE9 pd3dDevice)
{
	model.Init(pd3dDevice, "orima.x");//unitychan.x
	position = D3DXVECTOR3(0.0f, -0.6f, 0.5f);
	rotation = D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f);
	int gyou = 1;		//�s�B
	int retu = 0;		//��B
	int numRetu = 3;	//�񐔁B
	int execRetu = 0;	//�z�u������̐��B



	for (int i = 0; i < SEAT_NUM; i++)
	{
		
		if (retu == 0) {
			seat[i].Setseat(D3DXVECTOR3(0.0f, -0.7f, -0.5f * gyou));
			seat[i].Init();
			retu = 1;
		}
		else {
			
			seat[i].Setseat(D3DXVECTOR3(0.5f * retu, -0.7f, -0.5f * gyou));
			seat[i].Init();
			retu *= -1.0f;
			if (retu > 0) {
				//��
				retu++;
			}
		}

		execRetu++;
		if (execRetu == numRetu) {
			//���̍s�ɔz�u�ł����͑S�Ĕz�u�����B
			execRetu = 0;
			retu = 0;
			gyou++;
			numRetu += 0;
		}



	}



}

void Unity::UpdateWorldMatrix(const D3DXVECTOR3& trans, const D3DXQUATERNION& rot, const D3DXVECTOR3& scale)
{
	D3DXMATRIX mTrans, mScale;
	D3DXMatrixScaling(&mScale, scale.x, scale.y, scale.z);
	D3DXMatrixTranslation(&mTrans, trans.x, trans.y, trans.z);
	D3DXMatrixRotationQuaternion(&mRotation, &rot);
	/*D3DXMATRIX mAddRot;
	D3DXMatrixRotationY(&mAddRot, D3DXToRadian(-90.0f));
	mRotation = mRotation * mAddRot;*/
	mWorld = mScale * mRotation * mTrans;
}

//�X�V�B
void Unity::Update()
{
	

	const float moveSpeed = 0.08f;
	
	 moveDir = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	if (GetAsyncKeyState('W')) {
		moveDir -= direction_z;

	}
	if (GetAsyncKeyState('S')) {
		moveDir += direction_z;
	}
	if (GetAsyncKeyState('A')) {
		moveDir -= direction_x;
	}
	if (GetAsyncKeyState('D')) {
		moveDir += direction_x;
	}
	if (game->GETPad()->Getf() == true)
	{
		D3DXVECTOR3 padmovedir;
		padmovedir.x = game->GETPad()->GetLStickXF();
		padmovedir.z = game->GETPad()->GetLStickYF();
		moveDir.x = direction_x.x * padmovedir.x - direction_z.x * padmovedir.z;
		moveDir.z = direction_x.z * padmovedir.x - direction_z.z * padmovedir.z;
	}
	
	//�J�����������Ă�������ɐi�ށB
	direction_z = game->GetGameCamera().GetCameraDir();
	D3DXVec3Normalize(&moveDir, &moveDir);
	//�J�����̌����Ă�������ƁA��x�N�g���Ƃ̊O�ς��v�Z����Ɖ��ړ��̃x�N�g�������܂�B
	D3DXVec3Cross(&direction_x, &direction_z, &D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	position += moveDir * moveSpeed;
	//��]���v�Z�B
	float angle = acos(D3DXVec3Dot(&direction_x, &D3DXVECTOR3(1.0f, 0.0f, 0.0f)));
	D3DXVECTOR3 axis;
	D3DXVec3Cross(&axis, &direction_x, &D3DXVECTOR3(1.0f, 0.0f, 0.0f));
	D3DXQuaternionRotationAxis(&rotation, &axis, -angle);
	//���[���h�s��̍X�V�B
	UpdateWorldMatrix(position, rotation, D3DXVECTOR3(3.0f, 3.0f, 3.0f));

	for (int i = 0; i < SEAT_NUM; i++)
	{
		seat[i].Update();
	}
	if (game->GETPad()->IsTrigger(enButtonX))
	{
		
	}
	
}
//�`��B
void Unity::Render(
	LPDIRECT3DDEVICE9 pd3dDevice,
	D3DXMATRIX viewMatrix,
	D3DXMATRIX projMatrix,
	D3DXVECTOR4* diffuseLightDirection,
	D3DXVECTOR4* diffuseLightColor,
	D3DXVECTOR4	 ambientLight,
	int numDiffuseLight
	)
{
	const Camera& camera = game->GetCamera();
	model.Render(pd3dDevice,
		viewMatrix,
		mWorld,			//���[���h�s��B
		mRotation,		//��]�s��B
		projMatrix,
		diffuseLightDirection,
		diffuseLightColor,
		ambientLight,
		numDiffuseLight
		);
	
}
void Unity::Release()
{
	model.Release();
}
