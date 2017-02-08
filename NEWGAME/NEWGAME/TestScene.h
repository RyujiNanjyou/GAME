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
	* @brief	�X�V�B
	*/
	void Update();
	/*!
	* @brief	�`��B
	*/
	void Render();
	void UpdateLight();
	void Terminate();
	/*!
	* @brief	�J�������擾�B
	*/
	Camera& GetligCamera()
	{
		return lightcam.GetCamera();
	}
	/*!
	* @brief	�Q�[���J�������擾�B
	*/
	const LightCamera& GetCamera() const
	{
		return lightcam;
	}
private:
	Stage				stg;
	Orima				orima;				//�I���}
	PlayerCamera		playCamera;			//�Q�[���J�����B
	LightCamera			lightcam;
};
extern TestScene* test;
