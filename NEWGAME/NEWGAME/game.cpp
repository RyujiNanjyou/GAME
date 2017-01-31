#include "stdafx.h"
#include "camera.h"
#include "game.h"
#include "shadow.h"
#include "pikumin.h"



Game::Game()
{
}
Game::~Game()
{
	physicsWorld.Release();
	for (auto pikumin : pikuminList) {
		delete pikumin;
	}
}

void Game::UpdateLight()
{

}
/*!
* @brief	ゲームが起動してから一度だけ呼ばれる関数。
*/
void Game::Start()
{
	SParicleEmitParameter param;
	param.texturePath = "Assets/star.png";
	param.w = 0.5f;
	param.h = 0.5f;
	param.intervalTime = 0.2f;
	param.initSpeed = D3DXVECTOR3(0.0f, 5.0f, 0.0f);
	param.life = 0.5f;
	particleEmitter.Init(param);
	////物理ワールドを初期化。
	physicsWorld.Init();
	////ライトを初期化。
	playCamera.Start(&uni);
	//lightcam.Start(&light);
	uni.Init(g_pd3dDevice,"Assets/orima");
	
	
	Pikumin* pikumin = new Pikumin;
	float p_x = ((rand() % 100) - 50) / 50.0f;
	//	float t_y = ((rand() % 100) - 50) / 50.0f;
	float p_z = ((rand() % 100) - 50) / 50.0f;
	pikumin->Setpos(D3DXVECTOR3(p_x * 30.0f, 0.60f, p_z * 30.0f));
	pikumin->Init(g_pd3dDevice, "Assets/pikumin");
	pikuminList.push_back(pikumin);

	ter.Init(g_pd3dDevice, "Assets/pointer");
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		int z = i % 10;

		float p_x = ((rand() % 100) - 50) / 50.0f;
		//	float t_y = ((rand() % 100) - 50) / 50.0f;
		float p_z = ((rand() % 100) - 50) / 50.0f;
		enemy[i].Setpos(D3DXVECTOR3(p_x * 10.0f, 1.0f, p_z * 10.0f));
		enemy[i].Init(g_pd3dDevice, "Assets/atama");
	}
	
	
	shadow.Create(1280, 720);
	map.Start();
}
/*!
* @brief	更新。
*/
void Game::Update()
{
	
	playCamera.PreUpdate();
	uni.Update();
	playCamera.Update();
	
	for (auto pikuminIt = pikuminList.begin(); pikuminIt != pikuminList.end();) {
		if (!(*pikuminIt)->Update()) {
			delete *pikuminIt;
			pikuminIt = pikuminList.erase(pikuminIt);
		}
		else {
			pikuminIt++;
		}
	}
	D3DXVECTOR3 lightposition = uni.Getpos() + D3DXVECTOR3(0.0f,30.0f,0.0f);
	//shadow.SetLightPosition(lightposition);
	D3DXVECTOR3 lightDir = uni.Getpos() - lightposition; 
	D3DXVec3Normalize(&lightDir, &lightDir);
	shadow.SetLightDirection(lightDir);
	ter.Update();
	pad.Update();
	map.Update();
	particleEmitter.Update();
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		enemy[i].Update();
	}
}

/*!
* @brief	描画。
*/
void Game::Render()
{
	/*shadow.Render(g_pd3dDevice,
		GetCamera().GetViewMatrix(),
		GetCamera().GetProjectionMatrix(),
		light.GetDLDirecton(),
		light.GetDLColor(),
		light.Getamb(),
		LIGHT_NUM);*/
	shadow.Draw(
		&GetCamera().GetViewMatrix(),
		&GetCamera().GetProjectionMatrix()
		);

	uni.Render(false);
	for (auto pikumin : pikuminList)
	{
		pikumin->Render(false);
	}
	
	map.Render(g_pd3dDevice,
		GetCamera().GetViewMatrix(),
		GetCamera().GetProjectionMatrix(),
		light.GetDLDirecton(),
		light.GetDLColor(),
		light.Getamb(),
		LIGHT_NUM);

	ter.Render(false);

	particleEmitter.Render(
		GetCamera().GetViewMatrix(),
		GetCamera().GetProjectionMatrix());
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		enemy[i].Render(false);
	}

}
void Game::Terminate()
{
	uni.Release();
	for (auto pikumin : pikuminList)
	{
		pikumin->Release();

	}
	

}
