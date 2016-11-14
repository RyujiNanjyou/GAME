#pragma once

#include "model.h"
#include "GameObject.h"
#include "CharacterController.h"

#define GRVITY 13.0f
#define POWER 10.0f

enum PikuminStatus { STAND = 0, HOMING, THROW, ATTACK };


class Pikumin : public GameObject {
public:
	//コンストラクタ
	Pikumin();
	//デストラクタ
	~Pikumin();
	//初期化。
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name, const char* EffectName)override;
	//更新。
	void Update()override;
	//座標を設定。
	void UpdateWorldMatrix(const D3DXVECTOR3& trans, const D3DXQUATERNION& rot, const D3DXVECTOR3& scale);
	bool Getpikuflag() { return flag_pikumin; }
	void Setpikuflag(bool f) 
	{ 
		flag_pikumin = f; 
		if (f == true){
			m_seatNo = -1;
		}
	}
	
	int GatseatNo(){ return m_seatNo; }
	void SetseatNo(int i){ m_seatNo = i; }
	void SetNowStatus(PikuminStatus i)
	{
		nowStatus = i;
		if (i == THROW){
			characterController.Jump();
		}
	
	}
	void setspeed(D3DXVECTOR3 speed)
	{
		Speed = speed;
	}
	CharacterController GetcharacterController()
	{
		return characterController;
	}
private:
	int						m_seatNo;		//座っているシートの番号。
	bool					flag_pikumin;   
						
	D3DXVECTOR3				Speed;
	D3DXVECTOR3				direction_z;	//プレイヤーのZ方向。
	D3DXVECTOR3				direction_x;	//プレイヤーのX方向。//回転行列。
	PikuminStatus			nowStatus;
	CharacterController     characterController;	//キャラクタコントローラ。
};