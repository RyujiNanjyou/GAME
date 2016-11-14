#pragma once

#include "model.h"
#include "GameObject.h"
#include "CharacterController.h"

#define GRVITY 13.0f
#define POWER 10.0f

enum PikuminStatus { STAND = 0, HOMING, THROW, ATTACK };


class Pikumin : public GameObject {
public:
	//�R���X�g���N�^
	Pikumin();
	//�f�X�g���N�^
	~Pikumin();
	//�������B
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name, const char* EffectName)override;
	//�X�V�B
	void Update()override;
	//���W��ݒ�B
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
	int						m_seatNo;		//�����Ă���V�[�g�̔ԍ��B
	bool					flag_pikumin;   
						
	D3DXVECTOR3				Speed;
	D3DXVECTOR3				direction_z;	//�v���C���[��Z�����B
	D3DXVECTOR3				direction_x;	//�v���C���[��X�����B//��]�s��B
	PikuminStatus			nowStatus;
	CharacterController     characterController;	//�L�����N�^�R���g���[���B
};