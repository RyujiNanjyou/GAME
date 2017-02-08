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
	Animation anim;
public:
	GameObject();
	~GameObject();
	virtual void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name);
	virtual bool Update() = 0;
	void Render(D3DXMATRIX viwe, D3DXMATRIX porj, bool ShadowFlag);

	void Setrot(D3DXQUATERNION rot){
		rotation = rot; 
	};
	void Setscale(D3DXVECTOR3 scale){
		this->scale = scale;
	};
	 D3DXMATRIX& GetRot() 
	{
		return mRot;
	}
	virtual	void Setpos(D3DXVECTOR3 pos)
	{
		position = pos;
	}
	 D3DXVECTOR3& Getpos()
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

