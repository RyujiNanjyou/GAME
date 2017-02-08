/*!
* @brief	ゲームクラス。
*/
#pragma once

#include "Scene.h"
#include "camera.h"
#include "PlayerCamera.h"
#include "orima.h"
#include "seat.h"
#include "Map.h"
#include "lightcamera.h"
#include "pointer.h"
#include "Enemy.h"
#include "bloom.h"


#define  PIKUMIN_NUM 100
#define ENEMY_NUM 5
#define ATTACKRANGE 2.0f

class Pikumin;
class Game : public Scene{
public:
	/*!
	* @brief	コンストラクタ。
	*/
	Game();
	/*!
	* @brief	デストラクタ。
	*/
	~Game();
	/*!
	* @brief	ゲームが起動してから一度だけ呼ばれる関数。
	*/
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
	Camera& GetCamera()
	{
		return playCamera.GetCamera();
	}
	/*!
	* @brief	ゲームカメラを取得。
	*/
	const PlayerCamera& GetGameCamera() const
	{
		return playCamera;
	}
	Orima* GETOrima(){ return &orima; }
	/*!
	* @brief	ピクミンを追加。。
	*/
	void AddPikumin(Pikumin* pikumin)
	{
		pikuminList.push_back(pikumin);
	}
	const std::vector<Pikumin*>& GetPikumin()
	{
		return pikuminList;
	}
	pointer* Getpointer(){ return &ter; }
	Enemy* GetEnemy(){ return enemy; }
	
private:
	Orima				orima;				//オリマ
	std::vector<Pikumin*> pikuminList;
	Map					map;
	LightCamera			lightcam;
	pointer				ter;
	Enemy				enemy[ENEMY_NUM];
	PlayerCamera		playCamera;			//ゲームカメラ。
	Bloom bloom;
	
};

extern Game* game;