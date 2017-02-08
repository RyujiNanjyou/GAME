#include "TestScene.h"


TestScene::TestScene()
{

}


TestScene::~TestScene()
{
	physicsWorld.Release();
}
void TestScene::UpdateLight()
{

}
void TestScene::Init()
{
	physicsWorld.Init();
	////ƒ‰ƒCƒg‚ğ‰Šú‰»B
	playCamera.Start(&orima);
	//lightcam.Start(&light);
	orima.Init(g_pd3dDevice, "Assets/orima");
	stg.Init(g_pd3dDevice, "Assets/stage");
}

void TestScene::Update()
{
	playCamera.PreUpdate();
	orima.Update();
	playCamera.Update();
	stg.Update();
}

void TestScene::Render()
{
	orima.Render(GetligCamera().GetViewMatrix(),
		GetligCamera().GetProjectionMatrix(),
		false);

	stg.Render(GetligCamera().GetViewMatrix(),
		GetligCamera().GetProjectionMatrix(),
		false);
}
void TestScene::Terminate()
{
	orima.Release();
}