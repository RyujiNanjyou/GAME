#include "stdafx.h"
#include "game.h"
#include "orima.h"
#include "seat.h"
#include "Input.h"
#include "pikumin.h"
 

//�R���X�g���N�^
Orima::Orima()
{
	//�������B
	D3DXMatrixIdentity(&mWorld);
	D3DXMatrixIdentity(&mRot);
	direction_z = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	direction_x = D3DXVECTOR3(1.0f, 0.0f, 0.0f);
}
//�f�X�g���N�^
Orima::~Orima()
{
	Release();
}
void Orima::Init(LPDIRECT3DDEVICE9 pd3dDevice,const char* Name){
	GameObject::Init(pd3dDevice, Name);
	anim.PlayAnimation(0);
	position = D3DXVECTOR3(0.0f, 1.0f, 0.5f);
	rotation = D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f);
	scale = D3DXVECTOR3(3.0, 3.0, 3.0);
	//�ȍ쐬
	int gyou = 1;		//�s�B
	int retu = 0;		//��B
	int numRetu = 3;	//�񐔁B
	int execRetu = 0;	//�z�u������̐��B

	for (int i = 0; i < SEAT_NUM; i++)
	{
		if (retu == 0) {
			seat[i].Setseat(D3DXVECTOR3(0.0f, 1.0f, -0.5f * gyou));
			seat[i].Init();
			retu = 1;
		}
		else {
			seat[i].Setseat(D3DXVECTOR3(0.5f * retu, 1.0f, -0.5f * gyou));
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
	D3DXVECTOR3 pos = position;
	characterController.Init(0.3f, 1.0f, pos);
	characterController.SetGravity(-20.0f);	//�d�͋��߁B
	skinmodel.SetShadowReceiverFlag(false);
	Drowflag = false;
}



//�X�V�B
bool Orima::Update()
{
	anim.Update(1.0f/60.0f);
	D3DXVECTOR3 MoveSpeed = characterController.GetMoveSpeed();
	MoveSpeed.x = 0.0f;	
	MoveSpeed.z = 0.0f;

	float moveSpeed = 0.08f * 60.0f;

	moveDir = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	D3DXVECTOR3 padmovedir;
	padmovedir.x = game->GETPad()->GetLStickXF();
	padmovedir.z = game->GETPad()->GetLStickYF();
	moveDir.x = direction_x.x * padmovedir.x - direction_z.x * padmovedir.z;
	moveDir.z = direction_x.z * padmovedir.x - direction_z.z * padmovedir.z;


	//�J�����������Ă�������ɐi�ށB
	direction_z = game->GetGameCamera().GetCameraDir();
	D3DXVec3Normalize(&moveDir, &moveDir);
	//�J�����̌����Ă�������ƁA��x�N�g���Ƃ̊O�ς��v�Z����Ɖ��ړ��̃x�N�g�������܂�B
	D3DXVec3Cross(&direction_x, &direction_z, &D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	//�L�����N�^���������x��ݒ�B
	MoveSpeed += moveDir * moveSpeed;
	characterController.SetMoveSpeed(MoveSpeed);
	//�L�����N�^�R���g���[���[�����s�B
	characterController.Execute();
	position = characterController.GetPosition();
	//��]���v�Z�B
	
	if (D3DXVec3Length(&moveDir) > 0.0f)
	{
		D3DXVECTOR3 forward = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
		float angle = acos(D3DXVec3Dot(&forward, &moveDir));
		D3DXVECTOR3 axis;
		D3DXVec3Cross(&axis, &forward, &moveDir);
		D3DXQuaternionRotationAxis(&rotation, &axis, angle);
	}
	
	for (int i = 0; i < SEAT_NUM; i++)
	{
		seat[i].Update();
	}
	int	OK = -1;
	const std::vector<Pikumin*>& pikuminList = game->GetPikumin();
	if (game->GETPad()->IsTrigger(enButtonX))
	{
		//�������Ȃ���ԁB		
		float len = 100000000.0f;
		for (int i = 0; i < pikuminList.size(); i++)
		{
			D3DXVECTOR3 to = position - pikuminList[i]->Getpos();
			float toLength = D3DXVec3Length(&to);
			if (toLength < len && pikuminList[i]->GatseatNo() != -1)
			{
				OK = i;
				len = toLength;
			}
		}
		if (OK != -1)
		{
			seat[pikuminList[OK]->GatseatNo()].Setflag(false);
		}
	}
	//�s�N�~�����������B
	if (OK != -1)
	{
		//��������ԁB
		D3DXVECTOR3 pointerpos = game->Getpointer()->Getpos();
		D3DXVECTOR3 topos = pointerpos - position;
		float len;
		len = D3DXVec3Length(&topos);
		float time = len / POWER;
		topos.y = 0;
		D3DXVec3Normalize(&topos, &topos);
		topos *= POWER;
		topos.y = (-0.5*-GRVITY*time*time) / time;
		pikuminList[OK]->setspeed(topos);
		pikuminList[OK]->SetNowStatus(PikuminStatus::STAND_BY);

		D3DXVECTOR3 toplayer = position - pikuminList[OK]->Getpos();
		float l = D3DXVec3Length(&toplayer);
 		if (pikuminList[OK]->GetStatus() == PikuminStatus::STAND_BY && l < 0.8)
		{
			pikuminList[OK]->SetNowStatus(PikuminStatus::THROW);
		}
	
	}
	//���Y�e�X�g
	if (game->GETPad()->IsTrigger(enButtonY))
	{
		Pikumin* pikumin = new Pikumin;
		D3DXVECTOR3 pikuminpos = D3DXVECTOR3(0.0, 0.0, 0.0);
		pikumin->Init(g_pd3dDevice, "Assets/pikumin");
		game->AddPikumin(pikumin);
	}
	
	position.y += 0.6f;
	
	return true;
}

