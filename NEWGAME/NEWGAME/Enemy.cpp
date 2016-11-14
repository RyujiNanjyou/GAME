#include "Enemy.h"


Enemy::Enemy()
{
	//èâä˙âªÅB
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
	position = D3DXVECTOR3(0.0f, 3.0f, 0.0f);
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
	UpdateWorldMatrix(position, rotation, D3DXVECTOR3(5.0f, 5.0f, 5.0f));
}