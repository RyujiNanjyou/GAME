#include "stdafx.h"
#include "camera.h"
#include "game.h"

const int				LIGHT_NUM = 4;
D3DXVECTOR4 			g_diffuseLightDirection[LIGHT_NUM];	//ライトの方向。
D3DXVECTOR4				g_diffuseLightColor[LIGHT_NUM];		//ライトの色。
D3DXVECTOR4				g_ambientLight;//環境光



void Game::UpdateLight()
{
	g_diffuseLightDirection[0] = D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
	g_diffuseLightDirection[1] = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);
	g_diffuseLightDirection[2] = D3DXVECTOR4(0.0f, -1.0f, 0.0f, 1.0f);
	g_diffuseLightDirection[3] = D3DXVECTOR4(-1.0f, 0.0f, 0.0f, 1.0f);

	//ディフューズライト。
	g_diffuseLightColor[0] = D3DXVECTOR4(0.5f, 0.5f, 0.5f, 1.0f);
	g_diffuseLightColor[1] = D3DXVECTOR4(0.5f, 0.5f, 0.5f, 1.0f);
	g_diffuseLightColor[2] = D3DXVECTOR4(0.5f, 0.4f, 0.6f, 1.0f);
	g_diffuseLightColor[3] = D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f);

	//環境光。
	g_ambientLight = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
}
/*!
* @brief	ゲームが起動してから一度だけ呼ばれる関数。
*/
void Game::Start()
{
	//ライトを初期化。
	ZeroMemory(g_diffuseLightDirection, sizeof(g_diffuseLightDirection));
	ZeroMemory(g_diffuseLightColor, sizeof(g_diffuseLightColor));
	playCamera.Start(&uni);
	uni.Init(g_pd3dDevice);
	for (int i = 0; i < DARK_UNITY; i++)
	{
		int z = i % 10;
		min[i].Init(g_pd3dDevice);
		float t_x = ((rand() % 100) - 50) / 50.0f;
		//	float t_y = ((rand() % 100) - 50) / 50.0f;
		float t_z = ((rand() % 100) - 50) / 50.0f;
		min[i].SetPosition(D3DXVECTOR3(t_x * 30.0f, - 0.7f, t_z * 30.0f));
	}

	stg.Init(g_pd3dDevice);
	stg.SetPosition(D3DXVECTOR3(0.0f, -1.5f, 0.0f));
}
/*!
* @brief	更新。
*/
void Game::Update()
{
	
	playCamera.PreUpdate();
	uni.Update();
	playCamera.Update();
	for (int i = 0; i < DARK_UNITY; i++)
	{
		min[i].Update();

	}
	
	stg.Update();
	
	
}

/*!
* @brief	描画。
*/
void Game::Render()
{
	uni.Render(g_pd3dDevice,
		GetCamera().GetViewMatrix(),
		GetCamera().GetProjectionMatrix(),
		g_diffuseLightDirection,
		g_diffuseLightColor,
		g_ambientLight,
		LIGHT_NUM);
	for (int i = 0; i < DARK_UNITY; i++)
	{
		min[i].Render(g_pd3dDevice,
		GetCamera().GetViewMatrix(),
		GetCamera().GetProjectionMatrix(),
		g_diffuseLightDirection,
		g_diffuseLightColor,
		g_ambientLight,
		LIGHT_NUM);

	}
	

	stg.Render(g_pd3dDevice,
		GetCamera().GetViewMatrix(),
		GetCamera().GetProjectionMatrix(),
		g_diffuseLightDirection,
		g_diffuseLightColor,
		g_ambientLight,
		LIGHT_NUM);
}
void Game::Terminate()
{
	uni.Release();
	for (int i = 0; i < DARK_UNITY; i++)
	{
		min[i].Release();

	}
	
	stg.Release();
}
