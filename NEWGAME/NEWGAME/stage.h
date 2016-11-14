#pragma once

#include "model.h"

class Stage {
public:
	//�R���X�g���N�^
	Stage();
	//�f�X�g���N�^
	~Stage();
	//�������B
	void Init(LPDIRECT3DDEVICE9 pd3dDevice);
	//�X�V�B
	void Update();
	//�`��B
	void Stage::Render(
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
	Model					model;
	D3DXVECTOR3				position;		//���W�B
	D3DXMATRIX				mWorld;			//���[���h�s��B
	D3DXMATRIX				mRotation;
	
};