#pragma once

#include "GameObject.h"
#include "CharacterController.h"
#include "seat.h"

#define SEAT_NUM 100


class Seat;
//unity�����N���X�B
class Unity : public GameObject {
public:
	//�R���X�g���N�^
	Unity();
	//�f�X�g���N�^
	~Unity();
	//�������B
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name)override;
	//�X�V�B
	bool Update()override;




	Seat* Getseat()
	{
		return seat;
	}
	const D3DXVECTOR3 Getdir_z(){ return direction_z; }
	
private:
	D3DXVECTOR3				toseat;
	Seat					seat[SEAT_NUM];
	D3DXVECTOR3				forward;
	D3DXVECTOR3				direction_z;	//�v���C���[��Z�����B
	D3DXVECTOR3				direction_x;	//�v���C���[��X�����B//��]�s��B
	CharacterController     characterController;	//�L�����N�^�R���g���[���B
};