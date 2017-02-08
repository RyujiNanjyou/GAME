#pragma once

#include "Scene.h"

class Scene;

using namespace std;

enum GameScene { TITLE = 0, GAME, RESULT, TEST };

class SceneManager
{
public:
	SceneManager()
	{
		scenes = NULL;
	}
	void InitializeScene();
	void UpdateScene();
	void RenderScene();
	void ChangeScene(const int& key);
	void SetResult(bool flag)
	{
		resultflag = flag;
	}
	bool GetResult()
	{
		return resultflag;
	}
private:
	Scene* scenes;
	int nextScene = -1;
	bool resultflag = 0;		//0はゴール、1はデス

};
extern SceneManager* scenemanager;