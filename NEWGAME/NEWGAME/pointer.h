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
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name, const char* EffectName)override;
	//�X�V�B
	void Update()override;
	void UpdateWorldMatrix(const D3DXVECTOR3& trans, const D3DXQUATERNION& rot, const D3DXVECTOR3& scale);
};

