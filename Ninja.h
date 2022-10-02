#pragma once
#include "Mal.h"
#include "board.h"
#include "Player.h"

class Ninja : public Mal
{
public:
	void wiAbillity(Mal& re1, Mal& ni1, Mal& gh1, Mal& wa1, Mal& de1, Mal& kn1, Board b, int ix, int iy, int itx, int ity);
	void reghAbillity(Mal wi2, Mal re2, Mal ni2, Mal gh2, Mal wa2, Mal de2, Mal kn2, Board b, int ix, int iy);
	void deAbillity(Board b, int ix, int iy, int itx, int ity, int tmpX, int tmpY, Player& p1, Player& p2);
	void knAbillity(Board b, int ix, int iy, int tmpX, int tmpY, Mal& wi1, Mal& re1, Mal& ni1, Mal& gh1, Mal& wa1, Mal& de1);
	int cngMal;
};

