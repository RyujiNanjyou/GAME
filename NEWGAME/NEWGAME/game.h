/*!
* @brief	�Q�[���N���X�B
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
	* @brief	�R���X�g���N�^�B
	*/
	//Game();
	/*!
	* @brief	�f�X�g���N�^�B
	*/
	//~Game();
	/*!
	* @brief	�Q�[�����N�����Ă����x�����Ă΂��֐��B
	*/
	void Start();
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
	const Camera& GetCamera() const
	{
		return playCamera.GetCamera();
	}
	const Camera& GetlightCamera() const
	{
		return lightcam.GetCamera();
	}
	/*!
	* @brief	�Q�[���J�������擾�B
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
	//�������[���h�̎擾�B
	CPhysicsWorld* GetPhysicsWorld()
	{
		return &physicsWorld;
	}
private:
	CPad pad;
	PlayerCamera playCamera;			//�Q�[���J�����B
	Unity uni;
	Stage stg;
	Pikumin min[PIKUMIN_NUM];
	Map map;
	Light light;
	LightCamera lightcam;
	ShadowMap shadow;
	pointer ter;
	CPhysicsWorld physicsWorld;
	CParticleEmitter		particleEmitter;	//�p�[�e�B�N���G�~�b�^�[
	Enemy enemy[ENEMY_NUM];
};

extern Game* game;