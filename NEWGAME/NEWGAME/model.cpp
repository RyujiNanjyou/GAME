#include "stdafx.h"
#include "model.h"
#include "SkinModelData.h"
#include "game.h"
#include "SkinModel.h"


Model::Model()
{
	mesh = NULL;
	textures = NULL;
	numMaterial = 0;
	effect = NULL;
	
}

Model::~Model()
{
	Release();
}

//������
void Model::Init(LPDIRECT3DDEVICE9 pd3dDevice, char* fileNama)
{
	//X�t�@�C�������[�h�B
	LPD3DXBUFFER pD3DXMtrlBuffer;
	//X�t�@�C���̃��[�h�B
	D3DXLoadMeshFromX(fileNama, D3DXMESH_SYSTEMMEM,
		pd3dDevice, NULL,
		&pD3DXMtrlBuffer, NULL, &numMaterial,
		&mesh);
	// �}�e���A���o�b�t�@���擾�B
	D3DXMATERIAL* d3dxMaterials = (D3DXMATERIAL*)pD3DXMtrlBuffer->GetBufferPointer();

	//�e�N�X�`�������[�h�B
	textures = new LPDIRECT3DTEXTURE9[numMaterial];
	for (DWORD i = 0; i < numMaterial; i++)
	{
		textures[i] = NULL;
		//�e�N�X�`�����쐬����B
		HRESULT hr = D3DXCreateTextureFromFileA(pd3dDevice,
			d3dxMaterials[i].pTextureFilename,
			&textures[i]);
		char Assets[100] = "Assets//";
		if (hr != S_OK){
			//�e�N�X�`���ǂݍ��ݎ��s�B
			strcat(Assets, d3dxMaterials[i].pTextureFilename);
			 hr = D3DXCreateTextureFromFileA(pd3dDevice,
				 Assets,
				&textures[i]);
			//std::abort();
		}
	}
	// �}�e���A���o�b�t�@������B
	pD3DXMtrlBuffer->Release();

}
//UPDATE
void Model::Update()
{
}
void Model::Render(
	LPDIRECT3DDEVICE9 pd3dDevice,
	D3DXMATRIX viewMatrix,
	D3DXMATRIX World,			//���[���h�s��B
	D3DXMATRIX Rotation,		//��]�s��B
	D3DXMATRIX projMatrix,
	D3DXVECTOR4* diffuseLightDirection,
	D3DXVECTOR4* diffuseLightColor,
	D3DXVECTOR4	 ambientLight,
	int numDiffuseLight,
	bool shadowflag
	)
{

	if (shadowflag == true)
	{

		effect->SetTechnique("RenderShadowMap");
		effect->Begin(NULL, D3DXFX_DONOTSAVESHADERSTATE);
		effect->BeginPass(0);

		D3DXMATRIX WVP;
		WVP = World * game->Getshadow()->Getlvpmatrix();
		effect->SetMatrix("g_mWVP", &WVP);

		for (DWORD i = 0; i < numMaterial; i++)
		{
			effect->CommitChanges();						//���̊֐����Ăяo�����ƂŁA�f�[�^�̓]�����m�肷��B�`����s���O�Ɉ�񂾂��Ăяo���B
			// Draw the mesh subset
			mesh->DrawSubset(i);
		}


		effect->EndPass();
		effect->End();

	}
	else
	{
		effect->SetTechnique("SkinModel");
		effect->Begin(NULL, D3DXFX_DONOTSAVESHADERSTATE);
		effect->BeginPass(0);

		//�萔���W�X�^�ɐݒ肷��J���[�B
		D3DXVECTOR4 color(1.0f, 0.0f, 0.0f, 1.0f);
		//���[���h�s��̓]���B
		effect->SetMatrix("g_worldMatrix", &World);
		//�r���[�s��̓]���B
		effect->SetMatrix("g_viewMatrix", &viewMatrix);			//�r���[�s���]���B

		effect->SetMatrix("g_projectionMatrix", &projMatrix);	//�v���W�F�N�V�����s��̓]���B

		effect->SetMatrix("g_rotationMatrix", &Rotation);		//��]�s���]���B
		//���C�g�̌�����]���B
		effect->SetVectorArray("g_diffuseLightDirection", diffuseLightDirection, numDiffuseLight);
		//���C�g�̃J���[��]���B
		effect->SetVectorArray("g_diffuseLightColor", diffuseLightColor, numDiffuseLight);
		//������ݒ�B
		effect->SetVector("g_ambientLight", &ambientLight);
		
		effect->SetMatrix("g_lightviewprojMatrix", &game->Getshadow()->Getlvpmatrix());
		effect->SetVector("vEyepos", &(D3DXVECTOR4)camera.GetEyePt());
		effect->SetInt("g_shadowreceiveflag", shadowreceiveflag);
		effect->SetTexture("g_shadowTexture", game->Getshadow()->GetRenderTarget()->GetTexture());
		for (DWORD i = 0; i < numMaterial; i++)
		{
			
			effect->SetTexture("g_diffuseTexture", textures[i]);
			effect->CommitChanges();						//���̊֐����Ăяo�����ƂŁA�f�[�^�̓]�����m�肷��B�`����s���O�Ɉ�񂾂��Ăяo���B
			// Draw the mesh subset
			mesh->DrawSubset(i);
		}
		effect->EndPass();
		effect->End();
	}
	

	
	
	
}


//�J���B
void Model::Release()
{
	//���b�V�����J���B
	if (mesh != NULL) {
		mesh->Release();
		mesh = NULL;
	}
	//�e�N�X�`�����J���B
	if (textures != NULL) {
		for (unsigned int i = 0; i < numMaterial; i++) {
			if (textures[i] != NULL) {
				textures[i]->Release();
				textures[i] = NULL;
			}
		}
		delete[] textures;
		textures = NULL;
	}
	//�G�t�F�N�g���J���B
	if (effect != NULL) {
		effect->Release();
		effect = NULL;
	}
}

LPD3DXMESH Model::GetOrgMeshFirst()
{
	return mesh;
}

LPD3DXMESH Model::GetOrgMesh(LPD3DXFRAME frame)
{
	D3DXMESHCONTAINER_DERIVED* pMeshContainer = (D3DXMESHCONTAINER_DERIVED*)(frame->pMeshContainer);
	if (pMeshContainer != NULL) {
		return pMeshContainer->pOrigMesh;
	}
	if (frame->pFrameSibling != NULL) {
		//�Z��
		LPD3DXMESH mesh = GetOrgMesh(frame->pFrameSibling);

		if (mesh) {
			return mesh;
		}
	}
	if (frame->pFrameFirstChild != NULL)
	{
		//�q���B
		LPD3DXMESH mesh = GetOrgMesh(frame->pFrameFirstChild);
		if (mesh) {
			return mesh;
		}
	}

	return NULL;
}