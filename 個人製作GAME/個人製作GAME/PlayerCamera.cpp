#include "stdafx.h"
#include "camera.h"
#include "PlayerCamera.h"
#include "unity.h"
#include "Input.h"

PlayerCamera::PlayerCamera() :
toEyePos(0.0f, 0.0f, 0.0f, 1.0f),
targetOffset(0.0f, 0.0f, 0.0f, 1.0f),
cameraDir(0.0f, 0.0f, 0.0f)
{
}
PlayerCamera::~PlayerCamera()
{
}
void PlayerCamera::Start(Unity* uni)
{
	toEyePos.z = -10.0f;
	toEyePos.y = 5.0f;
	targetOffset.y = 1.0f;
	targetOffset.x = 0.0f;
	camera.SetAspect(1280.0f / 720.0f);
	camera.Init();
	this->uni = uni;
	UpdateCamera();
}
//カメラを更新。
void PlayerCamera::UpdateCamera()
{
	D3DXVECTOR3 target;

	target = uni->Getpos();
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
	if (GetInput().IsMouseMove()) {
		//マウスが動いた。
		D3DXVECTOR2 mouseMove = GetInput().GetMouseMove();
		//テスト
		D3DXMATRIX mRot;
		D3DXMatrixRotationY(&mRot, (mouseMove.x / WINDOW_WIDTH) * 1.0f);
		D3DXVec4Transform(&toEyePos, &toEyePos, &mRot);
	}
	cameraDir = D3DXVECTOR3(toEyePos);
	cameraDir.y = 0.0f;
	D3DXVec3Normalize(&cameraDir, &cameraDir);
}
void PlayerCamera::Update()
{
	UpdateCamera();
}