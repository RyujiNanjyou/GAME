#include "stdafx.h"
#include "model.h"
#include "pikumin.h"
#include "Input.h"
#include "game.h"
namespace {
	const float PI = 3.14159265358979323846f;
	const float MoveSpeed = 0.08f*60.0f;
}


Pikumin::Pikumin()
{
	//初期化。
	D3DXMatrixIdentity(&mWorld);
	D3DXMatrixIdentity(&mRot);
	m_seatNo = -1;
	flag_pikumin = false;
	Speed = D3DXVECTOR3(0.0f, POWER, 0.0f);
	direction_z = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	direction_x = D3DXVECTOR3(1.0f, 0.0f, 0.0f);
	
}
//デストラクタ
Pikumin::~Pikumin()
{
	Release();
}
void Pikumin::Init(LPDIRECT3DDEVICE9 pd3dDevice,const char* Name, const char* EffectName)
{
	GameObject::Init(pd3dDevice, Name, EffectName);
	model.Setshadowflag(false);	
	rotation = D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f);
	
	nowStatus = PikuminStatus::STAND;
	D3DXVECTOR3 pos = position;
	characterController.Init(0.3f, 1.0f, pos);
	//characterController.SetGravity(GRVITY);	//重力
}
void Pikumin::UpdateWorldMatrix(const D3DXVECTOR3& trans, const D3DXQUATERNION& rot, const D3DXVECTOR3& scale)
{
	D3DXMATRIX mTrans, mScale;
	D3DXMatrixScaling(&mScale, scale.x, scale.y, scale.z);
	D3DXMatrixTranslation(&mTrans, trans.x, trans.y, trans.z);
	D3DXMatrixRotationQuaternion(&mRot, &rot);
	/*D3DXMATRIX mAddRot;
	D3DXMatrixRotationY(&mAddRot, D3DXToRadian(-90.0f));
	mRot = mRot * mAddRot;*/
	mWorld = mScale * mRot * mTrans;
}

//更新。
void Pikumin::Update()
{
	D3DXVECTOR3 Move = characterController.GetMoveSpeed();
	Move.x = 0.0f;
	Move.z = 0.0f;

	if (nowStatus == PikuminStatus::STAND)
	{
		Seat* seat = game->GETunity()->Getseat();
		seat[m_seatNo].Setflag(false);
		m_seatNo = -1;
		//Speed = D3DXVECTOR3(0.0f, POWER, 0.0f);
		
		
	}
	//カメラが向いている方向に進む。
	direction_z = game->GetGameCamera().GetCameraDir();

	D3DXVECTOR3 topikumin;
	topikumin = game->Getpointer()->Getpos() - position;
	float len = D3DXVec3LengthSq(&topikumin);
	if (m_seatNo != -1 )
	{
		//座っているときの処理。
		Seat* seat = game->GETunity()->Getseat();
		D3DXVECTOR3 to = seat[m_seatNo].GetSeatPos() - position;
		float L;
		L = D3DXVec3LengthSq(&to);
		moveDir = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
		moveDir = game->GETunity()->Getmovedir();
		D3DXVec3Normalize(&to, &to);
		D3DXVec3Normalize(&moveDir, &moveDir);
		D3DXVec3Cross(&direction_x, &direction_z, &D3DXVECTOR3(0.0f, 1.0f, 0.0f));
		if (D3DXVec3Length(&moveDir) > 0.0f){
			D3DXVECTOR3 forward = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
			float angle = acos(D3DXVec3Dot(&forward, &moveDir));
			D3DXVECTOR3 axis;
			D3DXVec3Cross(&axis, &forward, &moveDir);
			D3DXQuaternionRotationAxis(&rotation, &axis, angle);
		}
		if (nowStatus==PikuminStatus::HOMING)//flag_pikumin == false
		{
		
			if (L < MoveSpeed * (1.0f/60.0f))
			{
				position = seat[m_seatNo].GetSeatPos();
			}
			else
			{
				//position += to * MoveSpeed;
			
				Move = to * MoveSpeed;
				characterController.SetMoveSpeed(Move);
				//キャラクタコントローラーを実行。
				characterController.Execute();
				position = characterController.GetPosition();
				
			}
	
		}
		
	}
	
		
	//投げ投げ
	if (nowStatus == PikuminStatus::THROW)//flag_pikumin==true
	{
		
		
	/*	D3DXVECTOR3 topointer;
		topointer = game->Getpointer()->Getpos() - game->GETunity()->Getpos();
		float PointerLen = D3DXVec3LengthSq(&topointer);
		float deltaTime = 1.0f / 60.0f;
		Speed.y -= GRVITY * deltaTime;
		Move = Move + Speed * deltaTime;
		
		position.x = nextPosition.x;
		position.z = nextPosition.z;
		
		if (Move.y < 0.6f && Speed <= 0)
		{
			
			nowStatus = PikuminStatus::STAND;
		}*/
		characterController.SetMoveSpeed(Speed);
		characterController.Execute();
		position = characterController.GetPosition();
		Speed = characterController.GetMoveSpeed();
		if (characterController.IsOnGround()){
			nowStatus = PikuminStatus::STAND;
		}
	}
	
	if (len <= 5.0f && game->GETPad()->IsTrigger(enButtonB))
	{
		if (m_seatNo == -1)
		{
			 
			Seat* seat = game->GETunity()->Getseat();
			for (int i = 0; i < SEAT_NUM; i++)
			{
				
				if (seat[i].Getflag()==false)//nowStatus == PikuminStatus::STAND
				{
					nowStatus = PikuminStatus::HOMING;
					m_seatNo = i;
					seat[i].Setflag(true);
					break;
				}
			}
		}
	}
	
	characterController.SetMoveSpeed(Move);
	//キャラクタコントローラーを実行。
	characterController.Execute();
	position = characterController.GetPosition();
	D3DXVECTOR3 pos = position;
	pos.y += 0.6f;
	//ワールド行列の更新。
	UpdateWorldMatrix(pos, rotation, D3DXVECTOR3(5.0f, 5.0f, 5.0f));
}

