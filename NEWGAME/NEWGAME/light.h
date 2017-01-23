#pragma once 
#include "stdafx.h"

#define		LIGHT_NUM  4
class Light
{
	
	D3DXVECTOR4 			diffuseLightDirection[LIGHT_NUM];	//���C�g�̕����B
	D3DXVECTOR4				diffuseLightColor[LIGHT_NUM];		//���C�g�̐F�B
	D3DXVECTOR4				ambientLight;						//����
public:
	Light()
	{
		diffuseLightDirection[0] = D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
		diffuseLightDirection[1] = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);
		diffuseLightDirection[2] = D3DXVECTOR4(0.0f, -1.0f, 0.0f, 1.0f);
		diffuseLightDirection[3] = D3DXVECTOR4(-1.0f, 0.0f, 0.0f, 1.0f);

		//�f�B�t���[�Y���C�g�B
		diffuseLightColor[0] = D3DXVECTOR4(0.5f, 0.5f, 0.5f, 1.0f);
		diffuseLightColor[1] = D3DXVECTOR4(0.5f, 0.5f, 0.5f, 1.0f);
		diffuseLightColor[2] = D3DXVECTOR4(0.5f, 0.4f, 0.6f, 1.0f);
		diffuseLightColor[3] = D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f);

		//�����B
		ambientLight = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	}
	~Light()
	{

	}
	
	D3DXVECTOR4 *GetDLDirecton() { return diffuseLightDirection; }
	D3DXVECTOR4 *GetDLColor() { return diffuseLightColor; }
	D3DXVECTOR4 &Getamb() { return ambientLight; }
	
};
