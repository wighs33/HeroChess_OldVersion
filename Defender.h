#pragma once
#include "Mal.h"
#include "board.h"
#include "Player.h"

class Defender : public Mal
{
public:
	void abillity(Board& b, int ix, int iy, int itx, int ity, int tmpX, int tmpY, Player& p1, Player& p2);
};