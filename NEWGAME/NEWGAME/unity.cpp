#include "stdafx.h"
#include "model.h"
#include "game.h"
#include "unity.h"
#include "seat.h"
#include "Input.h"
#include "pikumin.h"
 

//コンストラクタ
Unity::Unity()
{
	//初期化。
	D3DXMatrixIdentity(&mWorld);
	D3DXMatrixIdentity(&mRot);
	direction_z = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	direction_x = D3DXVECTOR3(1.0f, 0.0f, 0.0f);
}
//デストラクタ
Unity::~Unity()
{
	Release();
}
void Unity::Init(LPDIRECT3DDEVICE9 pd3dDevice,const char* Name,const char* EffectName){
	GameObject::Init(pd3dDevice, Name, EffectName);
	position = D3DXVECTOR3(0.0f, 1.0f, 0.5f);
	rotation = D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f);

	//席作成
	int gyou = 1;		//行。
	int retu = 0;		//列。
	int numRetu = 3;	//列数。
	int execRetu = 0;	//配置した列の数。

	for (int i = 0; i < SEAT_NUM; i++)
	{
		
		if (retu == 0) {
			seat[i].Setseat(D3DXVECTOR3(0.0f, 0.6f, -0.5f * gyou));
			seat[i].Init();
			retu = 1;
		}
		else {
			
			seat[i].Setseat(D3DXVECTOR3(0.5f * retu, 0.6f, -0.5f * gyou));
			seat[i].Init();
			retu *= -1.0f;
			if (retu > 0) {
				//正
				retu++;
			}
		}

		execRetu++;
		if (execRetu == numRetu) {
			//この行に配置できる列は全て配置した。
			execRetu = 0;
			retu = 0;
			gyou++;
			numRetu += 0;
		}



	}
	D3DXVECTOR3 pos = position;
	characterController.Init(0.3f, 1.0f, pos);
	characterController.SetGravity(-20.0f);	//重力強め。
	model.Setshadowflag(false);

}

void Unity::UpdateWorldMatrix(const D3DXVECTOR3& trans, const D3DXQUATERNION& rot, const D3DXVECTOR3& scale)
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
bool Unity::Update()
{

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


	//カメラが向いている方向に進む。
	direction_z = game->GetGameCamera().GetCameraDir();
	D3DXVec3Normalize(&moveDir, &moveDir);
	//カメラの向いている方向と、上ベクトルとの外積を計算すると横移動のベクトルが求まる。
	D3DXVec3Cross(&direction_x, &direction_z, &D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	//position += moveDir * moveSpeed;
	//キャラクタが動く速度を設定。
	MoveSpeed += moveDir * moveSpeed;
	characterController.SetMoveSpeed(MoveSpeed);
	//キャラクタコントローラーを実行。
	characterController.Execute();
	position = characterController.GetPosition();
	//回転を計算。
	
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
	if (game->GETPad()->IsTrigger(enButtonX))
	{
		//投げられない状態。
		Pikumin* min = game->Getpikumin();
			
		
		float len = 100000000.0f;
		
		for (int i = 0; i < PIKUMIN_NUM; i++)
		{
			D3DXVECTOR3 to = position - min[i].Getpos();
			float	toLength = D3DXVec3Length(&to);
			if (toLength < len&&min[i].GatseatNo() != -1)
			{
				OK = i;
				len = toLength;
				
			}
			
		}
		/*if (OK == -1){
			printf("hoge\n");
		}*/
		if (OK != -1)
		{
			seat[min[OK].GatseatNo()].Setflag(false);
		}
		
	}
	//ピクミン投げ処理。
	if (OK != -1)
	{
		//投げれる状態。
		Pikumin* min = game->Getpikumin();
		min[OK].Setpos(position);
		D3DXVECTOR3 pointerpos = game->Getpointer()->Getpos();
		D3DXVECTOR3 topos = pointerpos - position;
		float len;
		len = D3DXVec3Length(&topos);
		float time = len / POWER;
		topos.y = 0;
		D3DXVec3Normalize(&topos, &topos);
		topos *= POWER;
		topos.y = (-0.5*-GRVITY*time*time) / time;
		min[OK].setspeed(topos);
		min[OK].SetNowStatus(PikuminStatus::THROW);
	
	}
	D3DXVECTOR3 pos = position;
	pos.y += 0.6f;
	//ワールド行列の更新。
	UpdateWorldMatrix(pos, rotation, D3DXVECTOR3(3.0f, 3.0f, 3.0f));

	return true;
}

