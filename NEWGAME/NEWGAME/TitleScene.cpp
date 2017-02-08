#include "stdafx.h"
#include "TitleScene.h"


TitleScene::TitleScene()
{
}


TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
	lightcam.Start();
	sp.Init("Assets/wall.jpg");
}
void TitleScene::Update()
{
	lightcam.Update();
	sp.Update();
}
void TitleScene::Render()
{
	sp.Render(GetligCamera().GetViewMatrix(), GetligCamera().GetProjectionMatrix());
}