#pragma once
#include "GameObject.h"

#define ENEMY_SEAT 5
#define PI 3.14159265358979323846f
class Pikumin;
enum EnemyStatus{IDOL = 0,DEATH,DAMAGE,FOOD};
class Enemy: public GameObject
{
public:
	//�퓬�Ŏg�p����V�[�g
	struct EnemySeat {
		bool		ESeatflag;				//�g�p���t���O�B
		int			enemyseatNo;			//�V�[�g�ԍ��B
		D3DXVECTOR3	localPosition;			//���[�J�����W�B
		D3DXVECTOR3	position;				//���[���h���W�B
	};
	Enemy();
	~Enemy();
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name)override;
	bool Update()override;
	
	/*!
	* @brief	���g�p�̃V�[�g�������B
	*@param[in]	pos		���g�p�̃V�[�g�̒����炱�̍��W�Ɉ�ԋ߂��V�[�g��Ԃ��܂��B
	*@return		���g�p�̃V�[�g���Ȃ��ꍇ��NULL���Ԃ��Ă���B
	*/
	EnemySeat*  FindUnuseSeat(const D3DXVECTOR3& pos); 
	EnemyStatus GetStatus() { return nowEnemyStatus;}
	void SetStatus(EnemyStatus ES) { nowEnemyStatus = ES; }
	void SetAttackPikumin(Pikumin* pikumin)
	{
		attackPikumin = pikumin;
	}
private:
	EnemySeat eseat[ENEMY_SEAT];
	int life = 500;
	
	float Radian; 
	EnemyStatus nowEnemyStatus;
	Pikumin* attackPikumin = NULL;
};

