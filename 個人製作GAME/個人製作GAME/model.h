#pragma once



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
		int numDiffuseLight
		);
	//�J���B
	void Release();
	//���W��ݒ�B
	void SetPosition(D3DXVECTOR3 pos);
private:
	
	LPD3DXMESH				mesh;			//���b�V���B
	LPDIRECT3DTEXTURE9*		textures;		//�e�N�X�`���B
	DWORD					numMaterial;	//�}�e���A���̐��B
	ID3DXEffect*			effect;			//�G�t�F�N�g�B
	
};