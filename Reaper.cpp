#include "Reaper.h"

void Reaper::abillity(Mal& wi2,Mal& re2, Mal& ni2, Mal& gh2, Mal& wa2, Mal& de2, Mal& kn2,Board& b, int ix, int iy, Player p1)
{
	if (p1.getTurn() == 1)
	{
		if (b.malPos[iy][ix] == 11)
		{
			wi2.setY(0);
			wi2.setX(0);
			b.malPos[iy][ix] = 0;
		}
		else if (b.malPos[iy][ix] == 12)
		{
			re2.setY(0);
			re2.setX(0);
			b.malPos[iy][ix] = 0;
		}
		else if (b.malPos[iy][ix] == 13)
		{
			ni2.setY(0);
			ni2.setX(0);
			b.malPos[iy][ix] = 0;
		}
		else if (b.malPos[iy][ix] == 14)
		{
			gh2.setY(0);
			gh2.setX(0);
			b.malPos[iy][ix] = 0;
		}
		else if (b.malPos[iy][ix] == 15)
		{
			wa2.setY(0);
			wa2.setX(0);
			b.malPos[iy][ix] = 0;
		}
		else if (b.malPos[iy][ix] == 16)
		{
			de2.setY(0);
			de2.setX(0);
			b.malPos[iy][ix] = 0;
		}
		else if (b.malPos[iy][ix] == 17)
		{
			kn2.setY(0);
			kn2.setX(0);
			b.malPos[iy][ix] = 0;
		}
	}
	else
	{
		if (b.malPos[iy][ix] == 1)
		{
			wi2.setY(0);
			wi2.setX(0);
			b.malPos[iy][ix] = 0;
		}
		else if (b.malPos[iy][ix] == 2)
		{
			re2.setY(0);
			re2.setX(0);
			b.malPos[iy][ix] = 0;
		}
		else if (b.malPos[iy][ix] == 3)
		{
			ni2.setY(0);
			ni2.setX(0);
			b.malPos[iy][ix] = 0;
		}
		else if (b.malPos[iy][ix] == 4)
		{
			gh2.setY(0);
			gh2.setX(0);
			b.malPos[iy][ix] = 0;
		}
		else if (b.malPos[iy][ix] == 5)
		{
			wa2.setY(0);
			wa2.setX(0);
			b.malPos[iy][ix] = 0;
		}
		else if (b.malPos[iy][ix] == 6)
		{
			de2.setY(0);
			de2.setX(0);
			b.malPos[iy][ix] = 0;
		}
		else if (b.malPos[iy][ix] == 7)
		{
			kn2.setY(0);
			kn2.setX(0);
			b.malPos[iy][ix] = 0;
		}
	}
}