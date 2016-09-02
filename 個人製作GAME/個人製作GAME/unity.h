#pragma once

#include "model.h"
#include "seat.h"

#define SEAT_NUM 100



//unity�����N���X�B
class Unity {
public:
	//�R���X�g���N�^
	Unity();
	//�f�X�g���N�^
	~Unity();
	//�������B
	void Init(LPDIRECT3DDEVICE9 pd3dDevice);
	//�X�V�B
	void Update();
	//�`��B
	void Unity::Render(
		LPDIRECT3DDEVICE9 pd3dDevice,
		D3DXMATRIX viewMatrix,
		D3DXMATRIX projMatrix,
		D3DXVECTOR4* diffuseLightDirection,
		D3DXVECTOR4* diffuseLightColor,
		D3DXVECTOR4	 ambientLight,
		int numDiffuseLight
		);
	void UpdateWorldMatrix(const D3DXVECTOR3& trans, const D3DXQUATERNION& rot, const D3DXVECTOR3& scale);
	//�J���B
	void Release();


	const D3DXMATRIX& GetRot() const
	{
		return mRotation;
	}
	const D3DXVECTOR3& Getpos() const
	{
		return position;
	}

	Seat* Getseat()
	{
		return seat;
	}

private:
	D3DXVECTOR3	toseat;
	Seat					seat[SEAT_NUM];
	Model					model;
	D3DXVECTOR3				position;		//���W�B
	D3DXQUATERNION			rotation;		//��]
	D3DXMATRIX				mWorld;			//���[���h�s��B
	D3DXMATRIX				mRotation;
	D3DXVECTOR3				moveDir;
	D3DXVECTOR3 direction_z;	//�v���C���[��Z�����B
	D3DXVECTOR3 direction_x;	//�v���C���[��X�����B//��]�s��B
};