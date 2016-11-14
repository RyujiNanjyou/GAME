#pragma once
#include "camera.h"

class Unity;

//ゲームカメラ
class PlayerCamera
{
public:
	PlayerCamera();
	~PlayerCamera();
	void Start(Unity* uni);
	void PreUpdate();
	void Update();
	//カメラを取得。
	const Camera& GetCamera() const
	{
		return camera;
	}
	//カメラの方向を取得。
	D3DXVECTOR3 GetCameraDir() const
	{
		return cameraDir;
	}

private:
	//カメラを更新。
	void UpdateCamera();
	Camera		camera;
	Unity*		uni;			//追従するプレイヤー。
	D3DXVECTOR4 targetOffset;	//注視点のオフセット。
	D3DXVECTOR4 toEyePos;		//注視点から視点までのベクトル。	
	D3DXVECTOR3 cameraDir;		//カメラの方向。
};

