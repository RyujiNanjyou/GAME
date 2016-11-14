#pragma once

#include "RenderTarget.h"
#include "model.h"

class ShadowMap
{
	D3DVIEWPORT9		viewport;			//ビューポート
	LPDIRECT3DSURFACE9	BackBuffer ;
	LPDIRECT3DSURFACE9	BackZ;
	int					w, h;
	CRenderTarget		rendertarget;
	Model				model[2];
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

	void Render(
		LPDIRECT3DDEVICE9 pd3dDevice,
		D3DXMATRIX viewMatrix,
		D3DXMATRIX projMatrix,
		D3DXVECTOR4* diffuseLightDirection,
		D3DXVECTOR4* diffuseLightColor,
		D3DXVECTOR4	 ambientLight,
		int numDiffuseLight
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