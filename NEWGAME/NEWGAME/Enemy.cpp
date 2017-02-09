#include "stdafx.h"
#include "Enemy.h"
#include "pikumin.h"
#include "game.h"

Enemy::Enemy()
{
	//初期化。
	D3DXMatrixIdentity(&mWorld);
	D3DXMatrixIdentity(&mRot);
	Radian = 0.0f;
}


Enemy::~Enemy()
{
	Release();
}

void Enemy::Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name)
{
	GameObject::Init(pd3dDevice, Name);
	//anim.PlayAnimation(0,0.5);
	skinmodel.SetShadowReceiverFlag(false);
	//model.Setshadowflag(false);
	rotation = D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f);
	scale = D3DXVECTOR3(10.0f, 10.0f, 10.0f);
	nowEnemyStatus = EnemyStatus::IDOL;
	float angleBase = 2.0f * PI / ENEMY_SEAT;
	for (int i = 0; i < ENEMY_SEAT; i++)
	{
		eseat[i].enemyseatNo = i;
		eseat[i].ESeatflag = false;
		eseat[i].localPosition.x = sinf(angleBase * i) * 1.5f;
		eseat[i].localPosition.y = 0.0f;
		eseat[i].localPosition.z = cosf(angleBase * i) * 1.5f;
		D3DXVec3Add(&eseat[i].position, &position, &eseat[i].localPosition);
	
	
	}
	Drowflag = false;
}



bool Enemy::Update()
{
	//anim.Update(1.0f / 60.0f);
	bool  flag = true;

	//ピクミン追尾テスト操作
	/*if (GetAsyncKeyState('W'))
	{
		position.z -= 0.05  ;
	}
	if (GetAsyncKeyState('S'))
	{
		position.z += 0.05 ;
	}
	if (GetAsyncKeyState('A'))
	{
		position.x += 0.05;
	}
	if (GetAsyncKeyState('D'))
	{
		position.x -= 0.05;
	}*/

	for (auto& Eseat : eseat)
	{
		D3DXVec3Add(&Eseat.position, &position, &Eseat.localPosition);
	}
	if (attackPikumin != nullptr && nowEnemyStatus == EnemyStatus::IDOL)
	{
		attackPikumin->SetThisEnemy(this);
		nowEnemyStatus = EnemyStatus::DAMAGE;
	}
	if (nowEnemyStatus == EnemyStatus::DAMAGE )
	{
		life -= 1;

		if (life <= 0.0f)
		{
			life = 0;
			Radian = -90.0f;
		}
		else
		{
			Radian = 0.0f;
		}
		if (life == 0)
		{
			nowEnemyStatus = EnemyStatus::DEATH;
		}
	}
	if (nowEnemyStatus == EnemyStatus::DEATH)
	{
		if (attackPikumin != NULL
			&& attackPikumin->GetStatus() == PikuminStatus::GOHOME)
		{
			//敵を運ぶピクミンのポジションを代入
			position = attackPikumin->Getpos();
			D3DXVECTOR3 Goolto = D3DXVECTOR3(0.0f, 0.0f, 0.0f) - position;
			position.y += 2.5f;
			float LeN = D3DXVec3Length(&Goolto);
			if (LeN < 0.8f)
			{
				nowEnemyStatus = EnemyStatus::FOOD;
			}
		}

		if (nowEnemyStatus == EnemyStatus::FOOD)
		{

			flag = false;
			Drowflag = true;
			const std::vector<Pikumin*>& pikuminList = game->GetPikumin();
			/*Pikumin* pikumin = new Pikumin;
			D3DXVECTOR3 pikuminpos = D3DXVECTOR3(0.0, 0.0, 0.0);
			pikumin->Init(g_pd3dDevice, "Assets/pikumin");
			game->AddPikumin(pikumin);*/
			attackPikumin->SetNowStatus(PikuminStatus::STAND);
			/*for (auto pikumin : pikuminList)
			{
			pikumin->SetNowStatus(PikuminStatus::STAND);
			}*/
		}
	}
	return flag;
	
}
Enemy::EnemySeat* Enemy::FindUnuseSeat(const D3DXVECTOR3& pos)
{
	float dist = FLT_MAX;
	float distTmp;
	EnemySeat* result = 0;
	for (auto& Eseat : eseat)
	{
		if (!Eseat.ESeatflag) {
			//未使用。
			D3DXVECTOR3 diff;
			D3DXVec3Subtract(&diff, &Eseat.position, &pos);
			distTmp = D3DXVec3Length(&diff);
			if (distTmp < dist && distTmp < ATTACKRANGE) {
				dist = distTmp;
				result = &Eseat;
			}
		}
	}
	return result;
}