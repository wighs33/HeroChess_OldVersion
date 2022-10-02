#pragma once
#include "Mal.h"
#include "board.h"

class Knight : public Mal
{
public:
	void abillity(Board& b, int ix, int iy, int tmpX, int tmpY, Mal& wi1, Mal& re1, Mal& ni1, Mal& gh1, Mal& wa1, Mal& de1,Player p1);
};

