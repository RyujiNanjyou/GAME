#pragma once
#include "GameObject.h"

#define ENEMY_SEAT 5
#define PI 3.14159265358979323846f

enum EnemyStatus{IDOL = 0,DEATH,DAMAGE};
class Enemy: public GameObject
{
public:
	//戦闘で使用するシート
	struct EnemySeat {
		bool		ESeatflag;				//使用中フラグ。
		int			enemyseatNo;			//シート番号。
		D3DXVECTOR3	localPosition;			//ローカル座標。
		D3DXVECTOR3	position;				//ワールド座標。
	};
	Enemy();
	~Enemy();
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name, const char* EffectName)override;
	bool Update()override;
	void UpdateWorldMatrix(const D3DXVECTOR3& trans, const D3DXQUATERNION& rot, const D3DXVECTOR3& scale);
	/*!
	* @brief	未使用のシートを検索。
	*@param[in]	pos		未使用のシートの中からこの座標に一番近いシートを返します。
	*@return		未使用のシートがない場合はNULLが返ってくる。
	*/
	EnemySeat*  FindUnuseSeat(const D3DXVECTOR3& pos); 
	EnemyStatus GetStatus() { return nowEnemyStatus;}
	void SetStatus(EnemyStatus ES) { nowEnemyStatus = ES; }
private:
	EnemySeat eseat[ENEMY_SEAT];
	int life = 500;
	int Num;
	float Radian; 
	EnemyStatus nowEnemyStatus;
};

