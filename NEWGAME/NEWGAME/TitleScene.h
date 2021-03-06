#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "camera.h"
#include "lightCamera.h"
class TitleScene : public Scene
{
public:
	TitleScene();
	~TitleScene();
	void Init();
	void Update();
	void Render();
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
	Sprite				sp;
	LightCamera			lightcam;
};

