#include "stdafx.h"
#include "pikumin.h"
#include "Enemy.h"
#include "Input.h"
#include "game.h"


namespace {
	/*const float PI = 3.14159265358979323846f;*/
	//const float MoveSpeed = 0.08f*60.0f;
	
}

//�R���X�g���N�^
Pikumin::Pikumin() :
ESeat(nullptr)
{
	//�������B
	D3DXMatrixIdentity(&mWorld);
	D3DXMatrixIdentity(&mRot);
	m_seatNo = -1;
	flag_pikumin = false;
	Speed = D3DXVECTOR3(0.0f, POWER, 0.0f);
	direction_z = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	direction_x = D3DXVECTOR3(1.0f, 0.0f, 0.0f);
	
}
//�f�X�g���N�^
Pikumin::~Pikumin()
{
	Release();
}
//Init
void Pikumin::Init(LPDIRECT3DDEVICE9 pd3dDevice,const char* Name)
{
	GameObject::Init(pd3dDevice, Name);
	skinmodel.SetShadowReceiverFlag(false);
	rotation = D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f);
	scale = D3DXVECTOR3(5.0, 5.0, 5.0);
	nowStatus = PikuminStatus::STAND;
	D3DXVECTOR3 pos = position;
	characterController.Init(0.3f, 1.0f, pos);
	//characterController.SetGravity(-GRVITY);	//�d��
	Drowflag = false;
}


//�s�N�~���ǔ�
D3DXVECTOR3 Pikumin::PikuminHoming(D3DXVECTOR3 SeatPos, float MoveSpeed)
{
	D3DXVECTOR3 Move = characterController.GetMoveSpeed();
	Move.x = 0.0f;
	Move.z = 0.0f;

	D3DXVECTOR3 to = SeatPos - position;
	float L;
	L = D3DXVec3Length(&to);
	moveDir = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	moveDir = game->GETunity()->Getmovedir();
	D3DXVec3Normalize(&to, &to);
	D3DXVec3Normalize(&moveDir, &moveDir);
	D3DXVec3Cross(&direction_x, &direction_z, &D3DXVECTOR3(0.0f, 1.0f, 0.0f));

	if (nowStatus == PikuminStatus::HOMING || nowStatus == PikuminStatus::ATTACK || nowStatus == PikuminStatus::GOHOME || nowStatus == PikuminStatus::STAND_BY)
	{
		if (L < MoveSpeed * (1.0f / 60.0f))
		{
			position = SeatPos;
		}
		else
		{
			Move = to * MoveSpeed;
		}
		if (nowStatus == PikuminStatus::HOMING && D3DXVec3Length(&moveDir) > 0.0f){
			D3DXVECTOR3 forward = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
			float angle = acos(D3DXVec3Dot(&forward, &moveDir));
			D3DXVECTOR3 axis;
			D3DXVec3Cross(&axis, &forward, &moveDir);
			D3DXQuaternionRotationAxis(&rotation, &axis, angle);
		}
	}
	return Move;
}
//�X�V�B
bool Pikumin::Update()
{
	int OK;
	D3DXVECTOR3 origin = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Move = characterController.GetMoveSpeed();
	Move.x = 0.0f;
	Move.z = 0.0f;
	float Size = 10.0f;
	
	//����
	if (nowStatus == PikuminStatus::STAND)
	{
		Seat* seat = game->GETunity()->Getseat();
		seat[m_seatNo].Setflag(false);
		m_seatNo = -1;
		
	}
	//�J�����������Ă�������ɐi�ށB
	direction_z = game->GetGameCamera().GetCameraDir();
	
	D3DXVECTOR3 topikumin;
	topikumin = game->Getpointer()->Getpos() - position;
	float len = D3DXVec3Length(&topikumin);
	D3DXVECTOR3 toEnemy = game->GetEnemy()->Getpos() - position;
	float eneLen = D3DXVec3Length(&toEnemy);
	D3DXVECTOR3 toSeat;
	D3DXVec3Subtract(&toSeat, &game->GetEnemy()->Getpos(), &position);
	toSeat.y = 0.0f;
	if (m_seatNo != -1 )
	{
		//�����Ă���Ƃ��̏����B
		Seat* seat = game->GETunity()->Getseat();
		Move = PikuminHoming(seat[m_seatNo].GetSeatPos(),0.08f * 60.0f);
	}
	//�I���}�ɃZ�b�g
	if (nowStatus == PikuminStatus::STAND_BY)
	{
		Move = PikuminHoming(game->GETunity()->Getpos(), 0.08f * 60.0f);
	}
	//�����������
	if (nowStatus == PikuminStatus::THROW)
	{
		characterController.SetMoveSpeed(Speed);
		characterController.Execute();
		position = characterController.GetPosition();
		Speed = characterController.GetMoveSpeed();
		if (characterController.IsOnGround())
		{
			nowStatus = PikuminStatus::STAND;
			//�GAttack
			D3DXVECTOR3 moveDirTmp;
			Enemy* enemy = game->GetEnemy();
			for (int i = 0; i < ENEMY_NUM; i++)
			{
				ESeat = enemy[i].FindUnuseSeat(position);
				if (ESeat != nullptr)
				{
					//�V�[�g�����������B
					OK = i;
					break;
				}
			}
			if (ESeat != nullptr)
			{
				//�V�[�g�����������B
				ESeat->ESeatflag = true;
			}
			if (ESeat == nullptr)
			{		
				//�ҋ@��ԂɁB
				nowStatus = PikuminStatus::STAND;
			}
			if (ESeat != nullptr)
			{
				//�o�g���V�[�g�����������B�U�����������B
				D3DXVec3Subtract(&moveDirTmp, &ESeat->position, &position);
				moveDirTmp.y = 0.0f;
				if (D3DXVec3LengthSq(&moveDirTmp) < ATTACKRANGE * ATTACKRANGE) {
					
					//�U�����Ă���s�N�~�����Z�b�g
					Enemy* enemy = game->GetEnemy();
					enemy[OK].SetAttackPikumin(this);
					//�U�������W�ɓ������B
					nowStatus = PikuminStatus::ATTACK;
				}
				else {
					ESeat->ESeatflag = false;
					ESeat = nullptr;
				}
			}
			if (D3DXVec3LengthSq(&moveDirTmp) > 0.01f)
			{
				D3DXVec3Normalize(&moveDirTmp, &moveDirTmp);
				moveDir = moveDirTmp;
			}
		}
	}
	
	if (len <= 5.0f && game->GETPad()->IsTrigger(enButtonB))
	{
		if (m_seatNo == -1)
		{
			Seat* seat = game->GETunity()->Getseat();
			for (int i = 0; i < SEAT_NUM; i++)
			{
				
				if (seat[i].Getflag()==false)
				{
					nowStatus = PikuminStatus::HOMING;
					m_seatNo = i;
					seat[i].Setflag(true);
					break;
				}
			}
		}
	}
	//�U��
	if (nowStatus == PikuminStatus::ATTACK)
	{
		D3DXVECTOR3 dist;
		D3DXVec3Subtract(&dist, &ESeat->position, &position);
		dist.y = 0.0f;

		Move = PikuminHoming(ESeat->position, 0.08f*60.0f);
		

		if (D3DXVec3LengthSq(&dist) > ATTACKRANGE * ATTACKRANGE)
		{
			ESeat->ESeatflag = false;
			ESeat = nullptr;
			nowStatus = PikuminStatus::STAND;
		}
		if (ThisEnemy != NULL && ThisEnemy->GetStatus() == EnemyStatus::DEATH)
		{
			nowStatus = PikuminStatus::GOHOME;
		}
	}
	if (D3DXVec3Length(&toSeat) > 0.01f) {
		D3DXVec3Normalize(&toSeat,&toSeat);
		moveDir = toSeat;
	}
	
	if (nowStatus == PikuminStatus::GOHOME)
	{
		Move = PikuminHoming(origin, 0.08f*60.0f);
	}
	
	characterController.SetMoveSpeed(Move);
	//�L�����N�^�R���g���[���[�����s�B
	characterController.Execute();
	position = characterController.GetPosition();

	position.y += 0.6f;

	return true;
}

