#pragma once
#include "Mal.h"
#include "board.h"

class Warrior : public Mal
{
public:
	void abillity(Board b, Player p1);
	bool wiCannotMove=0;
	bool reCannotMove=0;
	bool niCannotMove=0;
	bool ghCannotMove=0;
	bool waCannotMove=0;
	bool deCannotMove=0;
	bool knCannotMove=0;
};

