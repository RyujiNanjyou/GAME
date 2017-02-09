#include "stdafx.h"
#include "PlayerCamera.h"
#include "Input.h"
#include "game.h"

PlayerCamera::PlayerCamera() :
toEyePos(0.0f, 0.0f, 0.0f, 1.0f),
targetOffset(0.0f, 0.0f, 0.0f, 1.0f),
cameraDir(0.0f, 0.0f, 0.0f)
{
}
PlayerCamera::~PlayerCamera()
{
}
void PlayerCamera::Start(Orima* orima)
{
	toEyePos.z = -8.0f;
	toEyePos.y = 5.0f;
	targetOffset.y = 1.0f;
	targetOffset.x = 0.0f;
	camera.SetAspect(1280.0f / 720.0f);
	camera.Init();
	this->orima = orima;
	UpdateCamera();
}
//カメラを更新。
void PlayerCamera::UpdateCamera()
{
	
	D3DXVECTOR3 target;
	target = orima->Getpos();
	target.x += targetOffset.x;
	target.y += targetOffset.y;
	target.z += targetOffset.z;
	D3DXVECTOR3 eyePos = target;
	eyePos.x += toEyePos.x;
	eyePos.y += toEyePos.y;
	eyePos.z += toEyePos.z;

	camera.SetEyePt(eyePos);
	camera.SetLookatPt(target);
	camera.Update();
}
void PlayerCamera::PreUpdate()
{
	//if (GetInput().IsMouseMove()) {
	//	//マウスが動いた。
	//	D3DXVECTOR2 mouseMove = GetInput().GetMouseMove();
	//	//テスト
	//	D3DXMATRIX mRot;
	//	D3DXMatrixRotationY(&mRot, (mouseMove.x / WINDOW_WIDTH) * 1.0f);
	//	D3DXVec4Transform(&toEyePos, &toEyePos, &mRot);
	//}
	
	
	//ゲームパッド
	float padMove_X = game->GETPad()->IsPress(enButtonRB1);
	float padMove_Y = game->GETPad()->IsPress(enButtonLB1);
	//左右
	if (fabsf(padMove_X) > 0.0f) 
	{
		//Y軸周りの回転を計算。
		//回す
		D3DXMATRIX mRot_X;
		D3DXMatrixRotationY(&mRot_X, 0.05f * padMove_X);
		D3DXVec4Transform(&toEyePos, &toEyePos, &mRot_X);
	}
	if (fabsf(padMove_X) < 1.0f)
	{
		//Y軸周りの回転を計算。
		//回す
		D3DXMATRIX mRot_Y;
		D3DXMatrixRotationY(&mRot_Y, -0.05f * padMove_Y);
		D3DXVec4Transform(&toEyePos, &toEyePos, &mRot_Y);
	}
	//上下
	/*if (fabsf(padMove_Y) > 0.0f)
	{
		D3DXVECTOR3 rotAxis;
		D3DXVec3Cross(&rotAxis, &camera.GetUpVec(), &(D3DXVECTOR3)toEyePos);
		D3DXVec3Normalize(&rotAxis, &rotAxis);
		D3DXMATRIX mRot;
		D3DXMatrixRotationAxis(&mRot, &rotAxis, 0.05f * padMove_Y);
		
		D3DXVECTOR3 toPositionOld = toEyePos;
		D3DXVec4Transform(&toEyePos, &toEyePos, &mRot);
		D3DXVECTOR3 toPosDir = toEyePos;
		D3DXVec3Normalize(&toPosDir, &toPosDir);
		if (toPosDir.y < -0.1f) {
			カメラが上向きすぎ。
			toEyePos = (D3DXVECTOR4)toPositionOld;
		}
		else if (toPosDir.y > 0.8f) {
			カメラが下向きすぎ。
			toEyePos = (D3DXVECTOR4)toPositionOld;
		}
	}
*/
	cameraDir = D3DXVECTOR3(toEyePos);
	cameraDir.y = 0.0f;
	D3DXVec3Normalize(&cameraDir, &cameraDir);
}
void PlayerCamera::Update()
{
	UpdateCamera();
}