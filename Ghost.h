#pragma once
#include "Mal.h"
#include "Board.h"
#include "Player.h"

class Ghost : public Mal
{
public:
	void abillity(Mal& wi2, Mal& re2, Mal& ni2, Mal& gh2, Mal& wa2, Mal& de2, Mal& kn2, Board& b, int ix, int iy, Player p1);
	void wiAbillity(Mal& re1, Mal& ni1, Mal& gh1, Mal& wa1, Mal& de1, Mal& kn1, Board& b, int ix, int iy, int itx, int ity, Player p1);
	void knAbillity(Board& b, int ix, int iy, int tmpX, int tmpY, Mal& wi1, Mal& re1, Mal& ni1, Mal& gh1, Mal& wa1, Mal& de1, Player p1);
	void waAbillity(Board b, Player p1);
	bool wiCannotMove=0;
	bool reCannotMove=0;
	bool niCannotMove=0;
	bool ghCannotMove=0;
	bool waCannotMove=0;
	bool deCannotMove=0;
	bool knCannotMove=0;
	bool aniTmp = 0;
	int killedBy = 0;
	int cngMal;
};

