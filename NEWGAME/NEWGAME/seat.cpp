#include "stdafx.h"
#include "seat.h"
#include "game.h"
Seat::Seat()
{	
	//seatpos = D3DXVECTOR3(0.0f, -0.7f, -0.5f);
}
Seat::~Seat()
{
}
void Seat::Init()
{
	
	toseat = seatpos - game->GETunity()->Getpos();
	
	
}
void Seat::Update()
{
	D3DXVECTOR4 ROT;
	D3DXVec3Transform(&ROT, &toseat, &game->GETunity()->GetRot());
	D3DXVECTOR3 Vec3(ROT.x, ROT.y, ROT.z);
	
	
	seatpos = game->GETunity()->Getpos() + Vec3;
	

}