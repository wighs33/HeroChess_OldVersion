#pragma once
#include "Mal.h"
#include "board.h"
#include "Player.h"

class Reaper :  public Mal
{
public:
	void abillity(Mal& wi2, Mal& re2, Mal& ni2, Mal& gh2, Mal& wa2, Mal& de2, Mal& kn2, Board& b, int ix, int iy, Player p1);
};

