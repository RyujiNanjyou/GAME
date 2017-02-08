#include "stdafx.h"
#include "lightcamera.h"
#include "light.h"

LightCamera::LightCamera() :
toEyePos(0.0f, 0.0f, 0.0f, 1.0f),
targetOffset(0.0f, 0.0f, 0.0f, 1.0f),
cameraDir(0.0f, 0.0f, 0.0f)
{
}
LightCamera::~LightCamera()
{
}
void LightCamera::Start()
{
	//Light* light
	toEyePos.z = -10.0f;
	toEyePos.y = 5.0f;
	targetOffset.y = 1.0f;
	targetOffset.x = 0.0f;
	camera.SetAspect(1280.0f / 720.0f);
	camera.Init();
	//this->light = light;
	UpdateCamera();
}
//カメラを更新。
void LightCamera::UpdateCamera()
{
	D3DXVECTOR4 target;
	target = (D3DXVECTOR4)D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	target.x += targetOffset.x;
	target.y += targetOffset.y;
	target.z += targetOffset.z;
	D3DXVECTOR4 eyePos = target;
	eyePos.x += toEyePos.x;
	eyePos.y += toEyePos.y;
	eyePos.z += toEyePos.z;

	camera.SetEyePt((D3DXVECTOR3)eyePos);
	camera.SetLookatPt((D3DXVECTOR3)target);
	camera.Update();
}
void LightCamera::Update()
{
	UpdateCamera();
}