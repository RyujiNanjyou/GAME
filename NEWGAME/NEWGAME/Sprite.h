#pragma once
#include "Primitive.h"
#include "SceneManager.h"
/*!
*@brief	���W��UV���W
*/
struct SShapeVertex {
	float		pos[4];
	float		uv[2];
};
static const D3DVERTEXELEMENT9 scShapeVertex_PT_Element[] = {
	{ 0, 0, D3DDECLTYPE_FLOAT4, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0 },
	{ 0, 16, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 0 },
	D3DDECL_END()
};
class Sprite
{
public:
	Sprite();
	~Sprite();
	void Init(const char* TexPath);
	void Update();
	void Render(const D3DXMATRIX& viewMatrix, const D3DXMATRIX& projMatrix);
private:
	CPrimitive			primitive;			//!<�v���~�e�B�u�B
	LPDIRECT3DTEXTURE9	texture;			//!<�e�N�X�`���B
	ID3DXEffect*		spriteEffect;		//!<�V�F�[�_�[�G�t�F�N�g�B
	D3DXVECTOR3			position;
	
};

