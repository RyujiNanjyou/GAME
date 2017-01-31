#include "stdafx.h"
#include "Map.h"
#include "MapChip.h"


using namespace std;
namespace {
	//マップチップの配置情報のテーブル。
	SMapChipLocInfo mapChipLocInfoTable[] =
	{
		#include "locationInfo.h"
	};
}
Map::Map()
{

}
Map::~Map()
{
	for (auto& mapchip : mapChipList){
		delete mapchip;
	}
}
void Map::Start()
{
	//配置情報からマップを構築
	int tableSize = sizeof(mapChipLocInfoTable) / sizeof(mapChipLocInfoTable[0]);
	
	
	for (int i = 0; i < tableSize;i++)
	{
		//マップチップを生成
		MapChip* mapChip = new MapChip;
		mapChip->Setpos(mapChipLocInfoTable[i].pos);
		mapChip->Setrot(mapChipLocInfoTable[i].rotation);
		mapChip->Setscale(mapChipLocInfoTable[i].scale);
		mapChip->Init(g_pd3dDevice, mapChipLocInfoTable[i].modelName);
		mapChipList.push_back(mapChip);
	}
}
void Map::Update()
{
	for (auto& mapChip : mapChipList){
		
		mapChip->Update();
	}
}
void Map::Render(
	LPDIRECT3DDEVICE9 pd3dDevice,
	D3DXMATRIX viewMatrix,
	D3DXMATRIX projMatrix,
	D3DXVECTOR4* diffuseLightDirection,
	D3DXVECTOR4* diffuseLightColor,
	D3DXVECTOR4	 ambientLight,
	int numDiffuseLight)
{
	for (auto& mapChip : mapChipList)
	{
		mapChip->Render(false);
	}
}
