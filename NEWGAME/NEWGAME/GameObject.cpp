#include "stdafx.h"
#include "GameObject.h"
#include "game.h"

GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name){

	char modelPath[256];
	sprintf(modelPath, "%s.X", Name);
	//まずはスキンモデルをロード。
	//model.Init(g_pd3dDevice, modelPath);
	skinmodeldata.LoadModelData(modelPath,NULL);
	skinmodel.Init(&skinmodeldata);
	skinmodel.SetLight(game->GETlight());
	//シェーダーをコンパイル。
	LPD3DXBUFFER  compileErrorBuffer = NULL;
	
	Drowflag = false;
}

void GameObject::Render(bool ShadowFlag){
	skinmodel.UpdateWorldMatrix(position, rotation, scale);
	if (Drowflag == false)
	{
		skinmodel.Draw(
			&game->GetCamera().GetViewMatrix(),
			&game->GetCamera().GetProjectionMatrix(),
			ShadowFlag
			);
	}
}
void GameObject::Release()
{
}