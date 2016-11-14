#pragma once

#include "GameObject.h"

class Enemy: public GameObject
{
public:
	Enemy();
	~Enemy();
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name, const char* EffectName)override;
	void Update()override;
	void UpdateWorldMatrix(const D3DXVECTOR3& trans, const D3DXQUATERNION& rot, const D3DXVECTOR3& scale);

};

