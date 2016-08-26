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
	
	seatpos = game->GETunity()->Getpos() + toseat;

}