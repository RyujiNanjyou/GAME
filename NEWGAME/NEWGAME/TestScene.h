#pragma once
#include "Scene.h"
#include "camera.h"
#include "PlayerCamera.h"
#include "lightcamera.h"
#include "stage.h"
#include "orima.h"

class TestScene : public Scene
{
public:
	TestScene();
	~TestScene();
	void Init();
	/*!
	* @brief	更新。
	*/
	void Update();
	/*!
	* @brief	描画。
	*/
	void Render();
	void UpdateLight();
	void Terminate();
	/*!
	* @brief	カメラを取得。
	*/
	Camera& GetligCamera()
	{
		return lightcam.GetCamera();
	}
	/*!
	* @brief	ゲームカメラを取得。
	*/
	const LightCamera& GetCamera() const
	{
		return lightcam;
	}
private:
	Stage				stg;
	Orima				orima;				//オリマ
	PlayerCamera		playCamera;			//ゲームカメラ。
	LightCamera			lightcam;
};
extern TestScene* test;
