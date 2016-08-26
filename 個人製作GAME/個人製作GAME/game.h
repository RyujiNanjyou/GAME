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
#define  DARK_UNITY 100

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
	/*!
	* @brief	�Q�[���J�������擾�B
	*/
	const PlayerCamera& GetGameCamera() const
	{
		return playCamera;
	}
	Unity* GETunity(){ return &uni; }

private:
	Seat seat[2];
	PlayerCamera playCamera;			//�Q�[���J�����B
	Unity uni;
	Stage stg;
	Pikumin min[DARK_UNITY];
};

extern Game* game;