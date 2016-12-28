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
#include "Map.h"
#include "light.h"
#include "lightcamera.h"
#include "shadow.h"
#include "pointer.h"
#include "Physics.h"
#include "ParticleEmitter.h"
#include  "Enemy.h"
#define  PIKUMIN_NUM 1
#define ENEMY_NUM 5
#define ATTACKRANGE 2.0f

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
	const Camera& GetlightCamera() const
	{
		return lightcam.GetCamera();
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
	Light* GETlight(){ return &light; }
	Pikumin* Getpikumin(){ return min; }
	ShadowMap* Getshadow(){ return &shadow; }
	pointer* Getpointer(){ return &ter; }
	Enemy* GetEnemy(){ return enemy; }
	//物理ワールドの取得。
	CPhysicsWorld* GetPhysicsWorld()
	{
		return &physicsWorld;
	}
private:
	CPad pad;
	PlayerCamera playCamera;			//ゲームカメラ。
	Unity uni;
	Stage stg;
	Pikumin min[PIKUMIN_NUM];
	Map map;
	Light light;
	LightCamera lightcam;
	ShadowMap shadow;
	pointer ter;
	CPhysicsWorld physicsWorld;
	CParticleEmitter		particleEmitter;	//パーティクルエミッター
	Enemy enemy[ENEMY_NUM];
};

extern Game* game;