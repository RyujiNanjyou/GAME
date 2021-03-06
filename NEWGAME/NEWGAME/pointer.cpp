#include "stdafx.h"
#include "pointer.h"
#include "game.h"


pointer::pointer()
{
	D3DXMatrixIdentity(&mWorld);
	D3DXMatrixIdentity(&mRot);
	direction_z = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	direction_x = D3DXVECTOR3(1.0f, 0.0f, 0.0f);
}

pointer::~pointer()
{
	Release();
}

void pointer::Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name)
{
	GameObject::Init(pd3dDevice, Name);
	position = D3DXVECTOR3(0.0f, 0.01f, 0.0f);
	rotation = D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f);
	scale = D3DXVECTOR3(3.0, 3.0, 3.0);
	D3DXVECTOR3 pos = position;
	characterController.Init(0.3f, 1.0f, pos);
	characterController.SetGravity(-20.0f);	//重力強め。
	Drowflag = false;
}

bool pointer::Update()
{
	D3DXVECTOR3 MoveSpeed = characterController.GetMoveSpeed();
	MoveSpeed.x = 0.0f;
	MoveSpeed.z = 0.0f;
	const float moveSpeed = 0.1f * 60.0f;

	moveDir = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	D3DXVECTOR3 padmovedir;
	padmovedir.x = game->GETPad()->GetRStickXF();
	padmovedir.z = game->GETPad()->GetRStickYF();

	moveDir.x = direction_x.x * padmovedir.x - direction_z.x * padmovedir.z;
	moveDir.z = direction_x.z * padmovedir.x - direction_z.z * padmovedir.z;


	//カメラが向いている方向に進む。
	direction_z = game->GetGameCamera().GetCameraDir();
	D3DXVec3Normalize(&moveDir, &moveDir);
	//カメラの向いている方向と、上ベクトルとの外積を計算すると横移動のベクトルが求まる。
	D3DXVec3Cross(&direction_x, &direction_z, &D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	//position += moveDir * moveSpeed;
	//キャラクタが動く速度を設定。
	MoveSpeed += moveDir * moveSpeed;
	characterController.SetMoveSpeed(MoveSpeed);
	//キャラクタコントローラーを実行。
	characterController.Execute();
	position = characterController.GetPosition();
	//回転を計算。
	if (D3DXVec3Length(&moveDir) > 0.0f){
		D3DXVECTOR3 forward = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
		float angle = acos(D3DXVec3Dot(&forward, &moveDir));
		D3DXVECTOR3 axis;
		D3DXVec3Cross(&axis, &forward, &moveDir);
		D3DXQuaternionRotationAxis(&rotation, &axis, angle);
	}
	position.y += 0.2f;
	
	return true;
}
