#pragma once

#include "GameObject.h"
#include "CharacterController.h"
#include "MeshCollider.h"

class Stage : public GameObject {
public:
	//�R���X�g���N�^
	Stage();
	//�f�X�g���N�^
	~Stage();
	//�������B
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name) override;
	//�X�V�B
	bool Update() override;
private:
	RigidBody				rigidBody;		//���́B
	MeshCollider			meshCollider;	//���b�V���R���C�_�[�B
	CharacterController     characterController;	//�L�����N�^�R���g���[���B
};