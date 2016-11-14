#pragma once
#include "camera.h"

struct D3DXFRAME_DERIVED : public D3DXFRAME {
	D3DXMATRIXA16	CombinedTransformationMatrix;	//�����ςݍs��B
};
struct D3DXMESHCONTAINER_DERIVED : public D3DXMESHCONTAINER {
	LPDIRECT3DTEXTURE9* ppTextures;
	LPD3DXMESH pOrigMesh;
	LPD3DXATTRIBUTERANGE pAttributeTable;
	DWORD NumAttributeGroups;
	DWORD NumInfl;
	LPD3DXBUFFER pBoneCombinationBuf;
	D3DXMATRIX** ppBoneMatrixPtrs;
	D3DXMATRIX* pBoneOffsetMatrices;
	DWORD NumPaletteEntries;
	bool UseSoftwareVP;
	DWORD iAttributeSW;
};
class Model {
public:
	//�R���X�g���N�^
	Model();
	//�f�X�g���N�^
	~Model();
	//�������B
	void Init(LPDIRECT3DDEVICE9 pd3dDevice,char* fileName);
	//�X�V�B
	void Update();
	
	//�`��B
	void Model::Render(
		LPDIRECT3DDEVICE9 pd3dDevice,
		D3DXMATRIX viewMatrix,
		D3DXMATRIX	World,			//���[���h�s��B
		D3DXMATRIX	Rotation,		//��]�s��B
		D3DXMATRIX projMatrix,
		D3DXVECTOR4* diffuseLightDirection,
		D3DXVECTOR4* diffuseLightColor,
		D3DXVECTOR4	 ambientLight,
		int numDiffuseLight,
		bool shadowflag
		);
	//�J���B
	void Release();
	//���W��ݒ�B
	void SetPosition(D3DXVECTOR3 pos);
	ID3DXEffect* Geteffect()
	{
		return effect;
	}
	void Seteffect(ID3DXEffect* i)
	{
		effect = i;
	}
	void Setshadowflag(bool flag)
	{
		shadowreceiveflag = flag;
	}
	LPD3DXMESH GetOrgMeshFirst();
	LPD3DXMESH GetOrgMesh(LPD3DXFRAME frame);
	
	D3DXMATRIX* GetRootBoneWorldMatrix()
	{
	}
private:
	Camera					camera;
	LPD3DXMESH				mesh;			//���b�V���B
	LPDIRECT3DTEXTURE9*		textures;		//�e�N�X�`���B
	DWORD					numMaterial;	//�}�e���A���̐��B
	ID3DXEffect*			effect;			//�G�t�F�N�g�B
	bool					shadowreceiveflag;
};