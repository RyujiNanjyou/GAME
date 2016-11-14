#include "GameObject.h"


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name, const char* EffectName){

	char modelPath[256];
	sprintf(modelPath, "%s.X", Name);
	//�܂��̓X�L�����f�������[�h�B
	model.Init(g_pd3dDevice, modelPath);

	//�V�F�[�_�[���R���p�C���B
	LPD3DXBUFFER  compileErrorBuffer = NULL;
	//�V�F�[�_�[���R���p�C���B
	HRESULT hr = D3DXCreateEffectFromFile(
		pd3dDevice,
		/*"basic.fx"*/EffectName,
		NULL,
		NULL,
		D3DXSHADER_SKIPVALIDATION,
		NULL,
		&effect,
		&compileErrorBuffer
		);
	if (hr != S_OK) {
		MessageBox(NULL, (char*)(compileErrorBuffer->GetBufferPointer()), "error", MB_OK);
		std::abort();
	}
}

void GameObject::Render(LPDIRECT3DDEVICE9 pd3dDevice,
	D3DXMATRIX viewMatrix,
	D3DXMATRIX projMatrix,
	D3DXVECTOR4* diffuseLightDirection,
	D3DXVECTOR4* diffuseLightColor,
	D3DXVECTOR4	 ambientLight,
	int numDiffuseLight){
	model.Seteffect(effect);
	model.Render(pd3dDevice,
		viewMatrix,
		mWorld,			//���[���h�s��B
		mRot,		//��]�s��B
		projMatrix,
		diffuseLightDirection,
		diffuseLightColor,
		ambientLight,
		numDiffuseLight,
		false
		);
}
void GameObject::Release()
{
	model.Release();
}