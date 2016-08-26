#include "stdafx.h"
#include "model.h"
#include "pikumin.h"
#include "Input.h"
#include "game.h"
namespace {
	const float PI = 3.14159265358979323846f;
}

Pikumin::Pikumin()
{
	//�������B
	D3DXMatrixIdentity(&mWorld);
	D3DXMatrixIdentity(&mRotation);
	position.x = 0.0f;
	position.y = 0.0f;
	position.z = 0.0f;
	m_seatNo = -1;
}
//�f�X�g���N�^
Pikumin::~Pikumin()
{
	Release();
}
void Pikumin::Init(LPDIRECT3DDEVICE9 pd3dDevice)
{
	model.Init(pd3dDevice, "pikumin.x"); 
}


//�X�V�B
void Pikumin::Update()
{

	//���[���h�s��̍X�V�B
	D3DXMatrixTranslation(&mWorld, position.x, position.y, position.z);
	if (m_seatNo != -1){
		//�����Ă���Ƃ��̏����B
		Seat* seat = game->GETunity()->Getseat();
		D3DXVECTOR3 to = seat[m_seatNo].GetSeatPos() - position;
		D3DXVec3Normalize(&to, &to);
		position += to*0.03f;
	}
	else{
		//�����ĂȂ��Ƃ��̏����B
		m_seatNo = -1;
		Seat* seat = game->GETunity()->Getseat();
		for (int i = 0; i < SEAT_NUM; i++){
			if (seat[i].Getflag() == false){
				m_seatNo = i;
				seat[i].Setflag(true);
				break;
			}
		}
	}
	
}
//�`��B
void Pikumin::Render(
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
		numDiffuseLight
		);
}
void Pikumin::Release()
{
	model.Release();
}
