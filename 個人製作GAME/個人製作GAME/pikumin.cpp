#include "stdafx.h"
#include "model.h"
#include "pikumin.h"
#include "Input.h"
#include "game.h"
namespace {
	const float PI = 3.14159265358979323846f;
	const float MoveSpeed = 0.08f;
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
	flag_pikumin = false;
	Speed = POWER;
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

	D3DXVECTOR3 topikumin;
	topikumin = game->GETunity()->Getpos() - position;
	len = D3DXVec3LengthSq(&topikumin);
	if (m_seatNo != -1)
	{
		//座っているときの処理。
		Seat* seat = game->GETunity()->Getseat();
		D3DXVECTOR3 to = seat[m_seatNo].GetSeatPos() - position;
		float L;
		L = D3DXVec3LengthSq(&to);
		
		D3DXVec3Normalize(&to, &to);
		if (flag_pikumin == false)
		{
			if (L < MoveSpeed)
			{
				position = seat[m_seatNo].GetSeatPos();
			}
			else
			{
				position += to * MoveSpeed;
			}

		}
		
		//ピクミン投げ処理。
		if (game->GETPad()->IsTrigger(enButtonX))
		{
			flag_pikumin = true;
			
		}
		
		if (flag_pikumin==true)
		{
			Speed -= GRVITY;
			position.y += Speed;
			position.z += 0.5f;
			if (position.y < -0.7)
			{
				position.y = -0.7f;
				position.z -= 0.5f;
			}

		}else
		{
			flag_pikumin = false;
		}
		

	}
	if (len <= 5.0f && game->GETPad()->IsTrigger(enButtonB))
	{
		if (m_seatNo == -1)
		{
			//座ってないときの処理。
			m_seatNo = -1;
			Seat* seat = game->GETunity()->Getseat();
			for (int i = 0; i < SEAT_NUM; i++)
			{
				if (seat[i].Getflag() == false)
				{
					m_seatNo = i;
					seat[i].Setflag(true);
					break;
				}
			}
		}
	}
	
	/*if (game->GETPad()->IsTrigger(enButtonX))
	{
		Seat* seat = game->GETunity()->Getseat();
		for (int i = 0; i < SEAT_NUM; i++)
		{
			if (seat[i].Getflag() == true)
			{
				
				m_seatNo = -1;
				seat[i].Setflag(false);
				break;
			}
			
		}
		
	}*/
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
