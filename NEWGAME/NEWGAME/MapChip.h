#pragma once

#include "GameObject.h"
#include "MeshCollider.h"
#include "RigidBody.h"


//�}�b�v�`�b�v�̔z�u���B

struct SMapChipLocInfo {
	const char* modelName;		//���f���B
	D3DXVECTOR3	pos;			//���W�B
	D3DXQUATERNION	rotation;		//��]�B
	D3DXVECTOR3 scale;
};
class MapChip : public GameObject
{
public:
	MapChip();
	~MapChip();
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name)override;
	bool Update()override;
	
private:
	RigidBody rigidBody;		//���́B
	MeshCollider meshCollider;	//���b�V���R���C�_�[�B
	//std::orimaque_ptr<D3DXMATRIX[]>		worldMatrixBuffer;	//���[���h�s��̃o�b�t�@
};

