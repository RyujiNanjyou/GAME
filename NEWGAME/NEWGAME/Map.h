#pragma once

class MapChip;
#include "MapChip.h"
/*!
* @brief	マップクラス。
*/
class Map{
public:

	Map();
	~Map();
	void Start();
	void Update();
	void Render(LPDIRECT3DDEVICE9 pd3dDevice,
		D3DXMATRIX viewMatrix,
		D3DXMATRIX projMatrix,
		D3DXVECTOR4* diffuseLightDirection,
		D3DXVECTOR4* diffuseLightColor,
		D3DXVECTOR4	 ambientLight,
		int numDiffuseLight);

private:
	MapChip					chip;
	D3DXMATRIX				mWorld;			//ワールド行列。
	D3DXMATRIX				mRotation;
	std::vector<MapChip*> mapChipList;	//マップチップのリスト。
};