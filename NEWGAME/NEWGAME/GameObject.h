#pragma once
#include "stdafx.h"
#include "model.h"

class GameObject
{
protected:
	ID3DXEffect* effect;			//�G�t�F�N�g�B
	Model model;
	D3DXVECTOR3	position;			//���W�B
	D3DXQUATERNION	rotation;		//��]�B
	D3DXMATRIX	mRot;
	D3DXMATRIX	mWorld;			//���[���h�s��
	D3DXVECTOR3	moveDir;
public:
	GameObject();
	~GameObject();
	virtual void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name,const char* EffectName);
	virtual bool Update() = 0;
	bool Render(LPDIRECT3DDEVICE9 pd3dDevice,
		D3DXMATRIX viewMatrix,
		D3DXMATRIX projMatrix,
		D3DXVECTOR4* diffuseLightDirection,
		D3DXVECTOR4* diffuseLightColor,
		D3DXVECTOR4	 ambientLight,
		int numDiffuseLight
		);

	void Setrot(D3DXQUATERNION rot){
		rotation = rot; 
	};

	const D3DXMATRIX& GetRot() const
	{
		return mRot;
	}
	void Setpos(D3DXVECTOR3 pos)
	{
		position = pos;
	}
	const D3DXVECTOR3& Getpos() const
	{
		return position;
	}
	D3DXMATRIX Getworld()
	{
		return mWorld;
	}
	D3DXVECTOR3 Getmovedir()
	{
		return moveDir;
	}
	virtual void Release();
	
};

