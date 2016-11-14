#pragma once

class Seat
{

	D3DXVECTOR3 seatpos;
	bool FlagSeat;
	D3DXVECTOR3	toseat;
	
public:
	Seat();

	~Seat();
	void Init();
	void Update();
	void Setflag(bool flag){ FlagSeat = flag; }
	bool Getflag() { return FlagSeat; }
	const D3DXVECTOR3& GetSeatPos() const
	{
		return seatpos;
	}
	void Setseat(D3DXVECTOR3 pos)
	{

		seatpos = pos;
	}
};