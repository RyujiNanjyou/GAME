#pragma once

#include "GameObject.h"
#include "CharacterController.h"
#include "Enemy.h"

#define GRVITY 15.8f
#define POWER 10.0f

enum PikuminStatus { STAND = 0, HOMING, THROW, ATTACK, GOHOME, STAND_BY };


class Pikumin : public GameObject {
public:
	//コンストラクタ
	Pikumin();
	//デストラクタ
	~Pikumin();
	//初期化。
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name)override;
	//更新。
	bool Update()override;
	//座標を設定。
	
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
	PikuminStatus GetStatus(){ return nowStatus; }
	void setspeed(D3DXVECTOR3 speed)
	{
		Speed = speed;
	}
	CharacterController GetcharacterController()
	{
		return characterController;
	}
	D3DXVECTOR3 PikuminHoming(D3DXVECTOR3 SeatPos,float MoveSpeed);
	void SetThisEnemy(Enemy* enemy)
	{
		ThisEnemy = enemy;
	}
	void Setpos(D3DXVECTOR3 pos){
		characterController.SetPosition(pos);
		GameObject::Setpos(pos);
	}
private:
	int						m_seatNo;		//座っているシートの番号。
	bool					flag_pikumin;  
	D3DXVECTOR3				Speed;
	D3DXVECTOR3				direction_z;	//プレイヤーのZ方向。
	D3DXVECTOR3				direction_x;	//プレイヤーのX方向。//回転行列。
	PikuminStatus			nowStatus;
	CharacterController     characterController;	//キャラクタコントローラ。
	Enemy::EnemySeat*		ESeat;

	Enemy* ThisEnemy = NULL;
};