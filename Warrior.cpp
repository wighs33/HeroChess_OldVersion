#include "Warrior.h"

void Warrior::abillity(Board b,Player p1)
{
	wiCannotMove = 0;
	reCannotMove = 0;
	niCannotMove = 0;
	ghCannotMove = 0;
	waCannotMove = 0;
	deCannotMove = 0;
	knCannotMove = 0;
	if (p1.getTurn() == 1)
	{
		if (b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX())] == 11 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() + 60)] == 11 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() + 60)] == 11 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() + 60)] == 11 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX())] == 11 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() - 60)] == 11 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() - 60)] == 11 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() - 60)] == 11)
			wiCannotMove = 1;
		else	 if (b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX())] == 12 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() + 60)] == 12 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() + 60)] == 12 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() + 60)] == 12 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX())] == 12 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() - 60)] == 12 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() - 60)] == 12 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() - 60)] == 12)
			reCannotMove = 1;
		else	 if (b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX())] == 13 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() + 60)] == 13 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() + 60)] == 13 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() + 60)] == 13 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX())] == 13 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() - 60)] == 13 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() - 60)] == 13 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() - 60)] == 13)
			niCannotMove = 1;
		else	 if (b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX())] == 14 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() + 60)] == 14 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() + 60)] == 14 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() + 60)] == 14 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX())] == 14 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() - 60)] == 14 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() - 60)] == 14 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() - 60)] == 14)
			ghCannotMove = 1;
		else	 if (b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX())] == 15 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() + 60)] == 15 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() + 60)] == 15 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() + 60)] == 15 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX())] == 15 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() - 60)] == 15 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() - 60)] == 15 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() - 60)] == 15)
			waCannotMove = 1;
		else	 if (b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX())] == 16 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() + 60)] == 16 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() + 60)] == 16 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() + 60)] == 16 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX())] == 16 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() - 60)] == 16 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() - 60)] == 16 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() - 60)] == 16)
			deCannotMove = 1;
		else	 if (b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX())] == 17 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() + 60)] == 17 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() + 60)] == 17 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() + 60)] == 17 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX())] == 17 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() - 60)] == 17 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() - 60)] == 17 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() - 60)] == 17)
			knCannotMove = 1;
	}
	else
	{
		if (b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX())] == 1 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() + 60)] == 1 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() + 60)] == 1 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() + 60)] == 1 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX())] == 1 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() - 60)] == 1 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() - 60)] == 1 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() - 60)] == 1)
			wiCannotMove = 1;
		else	 if (b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX())] == 2 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() + 60)] == 2 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() + 60)] == 2 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() + 60)] == 2 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX())] == 2 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() - 60)] == 2 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() - 60)] == 2 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() - 60)] == 2)
			reCannotMove = 1;
		else	 if (b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX())] == 3 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() + 60)] == 3 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() + 60)] == 3 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() + 60)] == 3 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX())] == 3 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() - 60)] == 3 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() - 60)] == 3 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() - 60)] == 3)
			niCannotMove = 1;
		else	 if (b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX())] == 4 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() + 60)] == 4 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() + 60)] == 4 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() + 60)] == 4 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX())] == 4 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() - 60)] == 4 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() - 60)] == 4 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() - 60)] == 4)
			ghCannotMove = 1;
		else	 if (b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX())] == 5 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() + 60)] == 5 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() + 60)] == 5 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() + 60)] == 5 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX())] == 5 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() - 60)] == 5 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() - 60)] == 5 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() - 60)] == 5)
			waCannotMove = 1;
		else	 if (b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX())] == 6 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() + 60)] == 6 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() + 60)] == 6 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() + 60)] == 6 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX())] == 6 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() - 60)] == 6 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() - 60)] == 6 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() - 60)] == 6)
			deCannotMove = 1;
		else	 if (b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX())] == 7 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() + 60)] == 7 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() + 60)] == 7 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() + 60)] == 7 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX())] == 7 ||
			b.malPos[b.posToIndex(getY() + 60)][b.posToIndex(getX() - 60)] == 7 ||
			b.malPos[b.posToIndex(getY())][b.posToIndex(getX() - 60)] == 7 ||
			b.malPos[b.posToIndex(getY() - 60)][b.posToIndex(getX() - 60)] == 7)
			knCannotMove = 1;
	}
}