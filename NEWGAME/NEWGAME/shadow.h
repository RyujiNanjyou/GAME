#pragma once

#include "RenderTarget.h"
#include "SkinModel.h"
#include "SkinModelData.h"


class ShadowMap
{
	D3DVIEWPORT9		viewport;			//ビューポート
	LPDIRECT3DSURFACE9	BackBuffer ;
	LPDIRECT3DSURFACE9	BackZ;
	int					w, h;
	CRenderTarget		rendertarget;
	SkinModel			skinmodel;
	SkinModelData		modeldata;
	D3DXVECTOR3			lightpos;
	D3DXVECTOR3			lightdir;
	D3DXMATRIX			rot;
	D3DXMATRIX			world;
	D3DXMATRIX			ProjMatrix;
	D3DXMATRIX			LVPMatrix;
	D3DXMATRIX			lvMatrix;
	ID3DXEffect*		pEffect;
	float				Near;				//!<近平面。
	float				Far;				//!<遠平面。
public:

	ShadowMap();
	
	~ShadowMap();

	void Create(int w, int h);

	void CreateLight(D3DXMATRIX);

	void Draw(
		D3DXMATRIX* viewMatrix,
		D3DXMATRIX* projMatrix
		);

	void Release();

	CRenderTarget* GetRenderTarget(){
		return &rendertarget;
	}
	D3DXMATRIX Getlvpmatrix()
	{
		return LVPMatrix;
	}

	void SetLightPosition(D3DXVECTOR3 pos)
	{
		lightpos = pos;
	}

	void SetLightDirection(D3DXVECTOR3 Dir)
	{
		lightdir = Dir;
	}
	float GetNear() const
	{
		return Near;
	}
	/*!
	* @brief	遠平面
	*/
	float GetFar() const
	{
		return Far;
	}
};
extern LPDIRECT3DTEXTURE9 shadow;
