#pragma once

#include "model.h"
#include "seat.h"
#include "pikumin.h"
#include "GameObject.h"
#include "CharacterController.h"

#define SEAT_NUM 100
#define PIKUMIN 1


//unity�����N���X�B
class Unity : public GameObject {
public:
	//�R���X�g���N�^
	Unity();
	//�f�X�g���N�^
	~Unity();
	//�������B
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name, const char* EffectName)override;
	//�X�V�B
	void Update()override;
	void UpdateWorldMatrix(const D3DXVECTOR3& trans, const D3DXQUATERNION& rot, const D3DXVECTOR3& scale);



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