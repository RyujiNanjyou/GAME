#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy()
{
	//初期化。
	D3DXMatrixIdentity(&mWorld);
	D3DXMatrixIdentity(&mRot);
}


Enemy::~Enemy()
{
	Release();
}

void Enemy::Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name, const char* EffectName)
{
	GameObject::Init(pd3dDevice, Name, EffectName);
	model.Setshadowflag(false);
	rotation = D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f);
	position = D3DXVECTOR3(-5.0f, 0.0f, 0.0f);

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
}

void Enemy::UpdateWorldMatrix(const D3DXVECTOR3& trans, const D3DXQUATERNION& rot, const D3DXVECTOR3& scale)
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

void Enemy::Update()
{
	//ピクミン追尾テスト操作
	if (GetAsyncKeyState('W'))
	{
		position.z -= 0.08;
	}
	if (GetAsyncKeyState('S'))
	{
		position.z += 0.08;
	}
	if (GetAsyncKeyState('A'))
	{
		position.x += 0.08;
	}
	if (GetAsyncKeyState('D'))
	{
		position.x -= 0.08;
	}

	for (auto& Eseat : eseat)
	{
		D3DXVec3Add(&Eseat.position, &position, &Eseat.localPosition);
	}
	
	UpdateWorldMatrix(position, rotation, D3DXVECTOR3(3.0f, 3.0f, 3.0f));

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
			D3DXVec3Subtract(&diff, &Eseat.position, &position);
			distTmp = D3DXVec3LengthSq(&diff);
			if (distTmp < dist) {
				dist = distTmp;
				result = &Eseat;
			}
		}
	}
	return result;
}