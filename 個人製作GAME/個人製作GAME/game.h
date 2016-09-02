/*!
* @brief	ゲームクラス。
*/
#pragma once
#include "camera.h"
#include "stage.h"
#include "unity.h"
#include "PlayerCamera.h"
#include "pikumin.h"
#include "seat.h"
#include "Pad.h"

#define  PIKUMIN_NUM 100

class Game{
public:
	/*!
	* @brief	コンストラクタ。
	*/
	//Game();
	/*!
	* @brief	デストラクタ。
	*/
	//~Game();
	/*!
	* @brief	ゲームが起動してから一度だけ呼ばれる関数。
	*/
	void Start();
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
	const Camera& GetCamera() const
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
	Unity* GETunity(){ return &uni; }
	CPad* GETPad(){ return &pad; }
private:
	CPad pad;
	Seat seat[2];
	PlayerCamera playCamera;			//ゲームカメラ。
	Unity uni;
	Stage stg;
	Pikumin min[PIKUMIN_NUM];
};

extern Game* game;