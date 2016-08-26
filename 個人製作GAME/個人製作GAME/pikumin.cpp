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
	//初期化。
	D3DXMatrixIdentity(&mWorld);
	D3DXMatrixIdentity(&mRotation);
	position.x = 0.0f;
	position.y = 0.0f;
	position.z = 0.0f;
	m_seatNo = -1;
}
//デストラクタ
Pikumin::~Pikumin()
{
	Release();
}
void Pikumin::Init(LPDIRECT3DDEVICE9 pd3dDevice)
{
	model.Init(pd3dDevice, "pikumin.x"); 
}


//更新。
void Pikumin::Update()
{

	//ワールド行列の更新。
	D3DXMatrixTranslation(&mWorld, position.x, position.y, position.z);
	if (m_seatNo != -1){
		//座っているときの処理。
		Seat* seat = game->GETunity()->Getseat();
		D3DXVECTOR3 to = seat[m_seatNo].GetSeatPos() - position;
		D3DXVec3Normalize(&to, &to);
		position += to*0.03f;
	}
	else{
		//座ってないときの処理。
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
//描画。
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
		mWorld,			//ワールド行列。
		mRotation,		//回転行列。
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
