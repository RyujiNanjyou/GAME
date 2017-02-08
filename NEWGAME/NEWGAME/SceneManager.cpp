#include "stdafx.h"
#include "SceneManager.h"
#include "game.h"
#include "TestScene.h"
#include "TitleScene.h"


void SceneManager::InitializeScene()
{
	ChangeScene(GameScene::GAME);
}

void SceneManager::UpdateScene()
{
	if (scenes){
		scenes->Update();
	}
	if (nextScene != -1){
		if (scenes != NULL)
		{
			delete physicsworld;
			physicsworld = NULL;
			delete scenes;
		}
		if (nextScene == GameScene::TITLE)
		{
			scenes = new TitleScene;
		}
		if (nextScene == GameScene::GAME)
		{
			scenes = new Game;
		}
		if (nextScene == GameScene::RESULT)
		{
			//scenes = new CResultScene;
		}
		if (nextScene == GameScene::TEST)
		{
			scenes = new TestScene;
		}
		scenes->Init();
		nextScene = -1;
	}
}

void SceneManager::RenderScene()
{

	scenes->Render();
}

void SceneManager::ChangeScene(const int& key)
{
	nextScene = key;
}
