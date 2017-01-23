#pragma once
#include "model.h"
#include "SkinModel.h"
#include "SkinModelData.h"
#include "Animation.h"
class GameObject
{
protected:
	ID3DXEffect* effect;			//エフェクト。
	Model model;
	SkinModel skinmodel;
	SkinModelData skinmodeldata;
	D3DXVECTOR3	position;			//座標。
	D3DXQUATERNION	rotation;		//回転。
	D3DXVECTOR3 scale;
	D3DXMATRIX	mRot;
	D3DXMATRIX	mWorld;			//ワールド行列
	D3DXVECTOR3	moveDir;
	bool Drowflag;
public:
	GameObject();
	~GameObject();
	virtual void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name);
	virtual bool Update() = 0;
	void Render();

	void Setrot(D3DXQUATERNION rot){
		rotation = rot; 
	};
	void Setscale(D3DXVECTOR3 scale){
		this->scale = scale;
	};
	const D3DXMATRIX& GetRot() const
	{
		return mRot;
	}
	virtual	void Setpos(D3DXVECTOR3 pos)
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

