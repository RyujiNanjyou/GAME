#pragma once
#include "GameObject.h"
#include "CharacterController.h"

class pointer : public GameObject
{
	D3DXVECTOR3				moveDir;
	D3DXVECTOR3				direction_z;	//�v���C���[��Z�����B
	D3DXVECTOR3				direction_x;	//�v���C���[��X�����B//��]�s��B
	CharacterController     characterController;	//�L�����N�^�R���g���[���B
public:
	pointer();
	~pointer();
	//�������B
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name)override;
	//�X�V�B
	bool Update()override;
};

