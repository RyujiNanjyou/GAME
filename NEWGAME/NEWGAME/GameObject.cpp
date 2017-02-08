#include "stdafx.h"
#include "GameObject.h"
#include "game.h"
#include "TestScene.h"

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
	skinmodeldata.LoadModelData(modelPath,&anim);
	skinmodel.Init(&skinmodeldata);
	skinmodel.SetLight(game->GETlight());
	//skinmodel.SetLight(test->GETlight());
	skinmodel.SetEffect(effectmanager->LoadEffect("Assets/Model.fx"));
	//シェーダーをコンパイル。
	LPD3DXBUFFER  compileErrorBuffer = NULL;
	
	Drowflag = false;
}

void GameObject::Render(D3DXMATRIX viwe, D3DXMATRIX porj,bool ShadowFlag){
	skinmodel.UpdateWorldMatrix(position, rotation, scale);
	if (Drowflag == false)
	{
		skinmodel.Draw(
			&viwe,
			&porj,
			ShadowFlag
			);
	}
}
void GameObject::Release()
{
}