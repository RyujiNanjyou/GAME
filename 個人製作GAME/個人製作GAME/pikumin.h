#pragma once

#include "model.h"
#include "unity.h"

#define GRVITY 0.09f
#define POWER 1.0f

class Pikumin {
public:
	//�R���X�g���N�^
	Pikumin();
	//�f�X�g���N�^
	~Pikumin();
	//�������B
	void Init(LPDIRECT3DDEVICE9 pd3dDevice);
	//�X�V�B
	void Update();
	//�`��B
	void Pikumin::Render(
		LPDIRECT3DDEVICE9 pd3dDevice,
		D3DXMATRIX viewMatrix,
		D3DXMATRIX projMatrix,
		D3DXVECTOR4* diffuseLightDirection,
		D3DXVECTOR4* diffuseLightColor,
		D3DXVECTOR4	 ambientLight,
		int numDiffuseLight
		);
	//�J���B
	void Release();
	//���W��ݒ�B
	void SetPosition(D3DXVECTOR3 pos)
	{
		position = pos;
	}




private:
	Unity					uni;
	Model					model;
	D3DXVECTOR3				position;		//���W�B
	D3DXMATRIX				mWorld;			//���[���h�s��B
	D3DXMATRIX				mRotation;
	int						m_seatNo;		//�����Ă���V�[�g�̔ԍ��B
	bool					flag_pikumin;   
	float					len;
	float					Speed;

};