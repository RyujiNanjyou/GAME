/*!
* @brief	�Q�[���N���X�B
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
	* @brief	�R���X�g���N�^�B
	*/
	Game();
	/*!
	* @brief	�f�X�g���N�^�B
	*/
	~Game();
	/*!
	* @brief	�Q�[�����N�����Ă����x�����Ă΂��֐��B
	*/
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
	Camera& GetCamera()
	{
		return playCamera.GetCamera();
	}
	/*!
	* @brief	�Q�[���J�������擾�B
	*/
	const PlayerCamera& GetGameCamera() const
	{
		return playCamera;
	}
	Orima* GETOrima(){ return &orima; }
	/*!
	* @brief	�s�N�~����ǉ��B�B
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
	Orima				orima;				//�I���}
	std::vector<Pikumin*> pikuminList;
	Map					map;
	LightCamera			lightcam;
	pointer				ter;
	Enemy				enemy[ENEMY_NUM];
	PlayerCamera		playCamera;			//�Q�[���J�����B
	Bloom bloom;
	
};

extern Game* game;