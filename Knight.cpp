#include "Knight.h"

void Knight::abillity(Board& b, int ix, int iy,int tmpX, int tmpY, Mal& wi1, Mal& re1, Mal& ni1, Mal& gh1, Mal& wa1, Mal& de1, Player p1)
{
	if (p1.getTurn() == 1)
	{
		if (b.malPos[iy][ix] == 1)
		{
			b.malPos[iy][ix] = 0;
			wi1.setY(wi1.getY() + getY() - tmpY);
			wi1.setX(wi1.getX() + getX() - tmpX);
			b.malPos[b.posToIndex(wi1.getY())][b.posToIndex(wi1.getX())] = 1;
		}
		else if (b.malPos[iy][ix] == 2)
		{
			b.malPos[iy][ix] = 0;
			re1.setY(re1.getY() + getY() - tmpY);
			re1.setX(re1.getX() + getX() - tmpX);
			b.malPos[b.posToIndex(re1.getY())][b.posToIndex(re1.getX())] = 2;
		}
		else if (b.malPos[iy][ix] == 3)
		{
			b.malPos[iy][ix] = 0;
			ni1.setY(ni1.getY() + getY() - tmpY);
			ni1.setX(ni1.getX() + getX() - tmpX);
			b.malPos[b.posToIndex(ni1.getY())][b.posToIndex(ni1.getX())] = 3;
		}
		else if (b.malPos[iy][ix] == 4)
		{
			b.malPos[iy][ix] = 0;
			gh1.setY(gh1.getY() + getY() - tmpY);
			gh1.setX(gh1.getX() + getX() - tmpX);
			b.malPos[b.posToIndex(gh1.getY())][b.posToIndex(gh1.getX())] = 4;
		}
		else if (b.malPos[iy][ix] == 5)
		{
			b.malPos[iy][ix] = 0;
			wa1.setY(wa1.getY() + getY() - tmpY);
			wa1.setX(wa1.getX() + getX() - tmpX);
			b.malPos[b.posToIndex(wa1.getY())][b.posToIndex(wa1.getX())] = 5;
		}
		else if (b.malPos[iy][ix] == 6)
		{
			b.malPos[iy][ix] = 0;
			de1.setY(de1.getY() + getY() - tmpY);
			de1.setX(de1.getX() + getX() - tmpX);
			b.malPos[b.posToIndex(de1.getY())][b.posToIndex(de1.getX())] = 6;
		}
	}
	else
	{
		if (b.malPos[iy][ix] == 11)
		{
			b.malPos[iy][ix] = 0;
			wi1.setY(wi1.getY() + getY() - tmpY);
			wi1.setX(wi1.getX() + getX() - tmpX);
			b.malPos[b.posToIndex(wi1.getY())][b.posToIndex(wi1.getX())] = 11;
		}
		else if (b.malPos[iy][ix] == 12)
		{
			b.malPos[iy][ix] = 0;
			re1.setY(re1.getY() + getY() - tmpY);
			re1.setX(re1.getX() + getX() - tmpX);
			b.malPos[b.posToIndex(re1.getY())][b.posToIndex(re1.getX())] = 12;
		}
		else if (b.malPos[iy][ix] == 13)
		{
			b.malPos[iy][ix] = 0;
			ni1.setY(ni1.getY() + getY() - tmpY);
			ni1.setX(ni1.getX() + getX() - tmpX);
			b.malPos[b.posToIndex(ni1.getY())][b.posToIndex(ni1.getX())] = 13;
		}
		else if (b.malPos[iy][ix] == 14)
		{
			b.malPos[iy][ix] = 0;
			gh1.setY(gh1.getY() + getY() - tmpY);
			gh1.setX(gh1.getX() + getX() - tmpX);
			b.malPos[b.posToIndex(gh1.getY())][b.posToIndex(gh1.getX())] = 14;
		}
		else if (b.malPos[iy][ix] == 15)
		{
			b.malPos[iy][ix] = 0;
			wa1.setY(wa1.getY() + getY() - tmpY);
			wa1.setX(wa1.getX() + getX() - tmpX);
			b.malPos[b.posToIndex(wa1.getY())][b.posToIndex(wa1.getX())] = 15;
		}
		else if (b.malPos[iy][ix] == 16)
		{
			b.malPos[iy][ix] = 0;
			de1.setY(de1.getY() + getY() - tmpY);
			de1.setX(de1.getX() + getX() - tmpX);
			b.malPos[b.posToIndex(de1.getY())][b.posToIndex(de1.getX())] = 16;
		}
	}
}