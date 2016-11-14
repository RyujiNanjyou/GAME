#include "stdafx.h"
#include "model.h"
#include "stage.h"
#include "Input.h"



//�R���X�g���N�^
Stage::Stage()
{
	//�������B
	D3DXMatrixIdentity(&mWorld);
	D3DXMatrixIdentity(&mRotation);
	position.x = 0.0f;
	position.y = 0.0f;
	position.z = 0.0f;
	
}
//�f�X�g���N�^
Stage::~Stage()
{
	Release();
}
void Stage::Init(LPDIRECT3DDEVICE9 pd3dDevice)
{
	model.Init(pd3dDevice, "stage.x");
}


//�X�V�B
void Stage::Update()
{

	//���[���h�s��̍X�V�B
	D3DXMatrixTranslation(&mWorld, position.x, position.y, position.z);

}
//�`��B
void Stage::Render(
	LPDIRECT3DDEVICE9 pd3dDevice,
	D3DXMATRIX viewMatrix,
	D3DXMATRIX projMatrix,
	D3DXVECTOR4* diffuseLightDirection,
	D3DXVECTOR4* diffuseLightColor,
	D3DXVECTOR4	 ambientLight,
	int numDiffuseLight
	)
{
	model.Render(pd3dDevice,
		viewMatrix,
		mWorld,			//���[���h�s��B
		mRotation,		//��]�s��B
		projMatrix,
		diffuseLightDirection,
		diffuseLightColor,
		ambientLight,
		numDiffuseLight,
		false
		);
}
void Stage::Release()
{
	model.Release();
}
