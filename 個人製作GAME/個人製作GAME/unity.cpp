#include "stdafx.h"
#include "model.h"
#include "game.h"
#include "unity.h"
#include "seat.h"
#include "Input.h"

 

//コンストラクタ
Unity::Unity()
{
	//初期化。
	D3DXMatrixIdentity(&mWorld);
	D3DXMatrixIdentity(&mRotation);
	direction_z = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	direction_x = D3DXVECTOR3(1.0f, 0.0f, 0.0f);
}
//デストラクタ
Unity::~Unity()
{
	Release();
}
void Unity::Init(LPDIRECT3DDEVICE9 pd3dDevice)
{
	model.Init(pd3dDevice, "orima.x");//unitychan.x
	position = D3DXVECTOR3(0.0f, -0.6f, 0.5f);
	rotation = D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f);
	int gyou = 1;		//行。
	int retu = 0;		//列。
	int numRetu = 3;	//列数。
	int execRetu = 0;	//配置した列の数。



	for (int i = 0; i < SEAT_NUM; i++)
	{
		
		if (retu == 0) {
			seat[i].Setseat(D3DXVECTOR3(0.0f, -0.7f, -0.5f * gyou));
			seat[i].Init();
			retu = 1;
		}
		else {
			
			seat[i].Setseat(D3DXVECTOR3(0.5f * retu, -0.7f, -0.5f * gyou));
			seat[i].Init();
			retu *= -1.0f;
			if (retu > 0) {
				//正
				retu++;
			}
		}

		execRetu++;
		if (execRetu == numRetu) {
			//この行に配置できる列は全て配置した。
			execRetu = 0;
			retu = 0;
			gyou++;
			numRetu += 0;
		}



	}



}

void Unity::UpdateWorldMatrix(const D3DXVECTOR3& trans, const D3DXQUATERNION& rot, const D3DXVECTOR3& scale)
{
	D3DXMATRIX mTrans, mScale;
	D3DXMatrixScaling(&mScale, scale.x, scale.y, scale.z);
	D3DXMatrixTranslation(&mTrans, trans.x, trans.y, trans.z);
	D3DXMatrixRotationQuaternion(&mRotation, &rot);
	/*D3DXMATRIX mAddRot;
	D3DXMatrixRotationY(&mAddRot, D3DXToRadian(-90.0f));
	mRotation = mRotation * mAddRot;*/
	mWorld = mScale * mRotation * mTrans;
}

//更新。
void Unity::Update()
{
	

	const float moveSpeed = 0.08f;
	
	 moveDir = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	if (GetAsyncKeyState('W')) {
		moveDir -= direction_z;

	}
	if (GetAsyncKeyState('S')) {
		moveDir += direction_z;
	}
	if (GetAsyncKeyState('A')) {
		moveDir -= direction_x;
	}
	if (GetAsyncKeyState('D')) {
		moveDir += direction_x;
	}
	if (game->GETPad()->Getf() == true)
	{
		D3DXVECTOR3 padmovedir;
		padmovedir.x = game->GETPad()->GetLStickXF();
		padmovedir.z = game->GETPad()->GetLStickYF();
		moveDir.x = direction_x.x * padmovedir.x - direction_z.x * padmovedir.z;
		moveDir.z = direction_x.z * padmovedir.x - direction_z.z * padmovedir.z;
	}
	
	//カメラが向いている方向に進む。
	direction_z = game->GetGameCamera().GetCameraDir();
	D3DXVec3Normalize(&moveDir, &moveDir);
	//カメラの向いている方向と、上ベクトルとの外積を計算すると横移動のベクトルが求まる。
	D3DXVec3Cross(&direction_x, &direction_z, &D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	position += moveDir * moveSpeed;
	//回転を計算。
	float angle = acos(D3DXVec3Dot(&direction_x, &D3DXVECTOR3(1.0f, 0.0f, 0.0f)));
	D3DXVECTOR3 axis;
	D3DXVec3Cross(&axis, &direction_x, &D3DXVECTOR3(1.0f, 0.0f, 0.0f));
	D3DXQuaternionRotationAxis(&rotation, &axis, -angle);
	//ワールド行列の更新。
	UpdateWorldMatrix(position, rotation, D3DXVECTOR3(3.0f, 3.0f, 3.0f));

	for (int i = 0; i < SEAT_NUM; i++)
	{
		seat[i].Update();
	}
	if (game->GETPad()->IsTrigger(enButtonX))
	{
		
	}
	
}
//描画。
void Unity::Render(
	LPDIRECT3DDEVICE9 pd3dDevice,
	D3DXMATRIX viewMatrix,
	D3DXMATRIX projMatrix,
	D3DXVECTOR4* diffuseLightDirection,
	D3DXVECTOR4* diffuseLightColor,
	D3DXVECTOR4	 ambientLight,
	int numDiffuseLight
	)
{
	const Camera& camera = game->GetCamera();
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
void Unity::Release()
{
	model.Release();
}
