#pragma once
#include "Mal.h"
#include "board.h"
#include "Player.h"

class Wizard : public Mal
{
public:
	void abillity(Mal& re1, Mal& ni1, Mal& gh1, Mal& wa1, Mal& de1, Mal& kn1, Board& b, int ix, int iy, int itx, int ity,Player p1);
	int cngMal;
};

