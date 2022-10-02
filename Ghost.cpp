#include "Ghost.h"

void Ghost::abillity(Mal& wi2, Mal& re2, Mal& ni2, Mal& gh2, Mal& wa2, Mal& de2, Mal& kn2, Board& b, int ix, int iy, Player p1)
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

#include "Wizard.h"


void Ghost::wiAbillity(Mal& re1, Mal& ni1, Mal& wi1, Mal& wa1, Mal& de1, Mal& kn1, Board& b, int ix, int iy, int itx, int ity, Player p1)
{
	setToY(b.getY()[iy]);
	setToX(b.getX()[ix]);
	cngMal = b.malPos[iy][ix];
	if (p1.getTurn() == 1)
	{
		if (b.malPos[iy][ix] == 2)
		{
			re1.setToY(b.getY()[ity]);
			re1.setToX(b.getX()[itx]);
			//말번호 저장위치 바꾸기
			b.malPos[ity][itx] = 2;
			b.malPos[iy][ix] = 4;
		}
		else if (b.malPos[iy][ix] == 3)
		{
			ni1.setToY(b.getY()[ity]);
			ni1.setToX(b.getX()[itx]);
			//말번호 저장위치 바꾸기
			b.malPos[ity][itx] = 3;
			b.malPos[iy][ix] = 4;
		}
		else if (b.malPos[iy][ix] == 1)
		{
			wi1.setToY(b.getY()[ity]);
			wi1.setToX(b.getX()[itx]);
			//말번호 저장위치 바꾸기
			b.malPos[ity][itx] = 1;
			b.malPos[iy][ix] = 4;
		}
		else if (b.malPos[iy][ix] == 5)
		{
			wa1.setToY(b.getY()[ity]);
			wa1.setToX(b.getX()[itx]);
			//말번호 저장위치 바꾸기
			b.malPos[ity][itx] = 5;
			b.malPos[iy][ix] = 4;
		}
		else if (b.malPos[iy][ix] == 6)
		{
			de1.setToY(b.getY()[ity]);
			de1.setToX(b.getX()[itx]);
			//말번호 저장위치 바꾸기
			b.malPos[ity][itx] = 6;
			b.malPos[iy][ix] = 4;
		}
		else if (b.malPos[iy][ix] == 7)
		{
			kn1.setToY(b.getY()[ity]);
			kn1.setToX(b.getX()[itx]);
			//말번호 저장위치 바꾸기
			b.malPos[ity][itx] = 7;
			b.malPos[iy][ix] = 4;
		}
	}
	else
	{
		if (b.malPos[iy][ix] == 12)
		{
			re1.setToY(b.getY()[ity]);
			re1.setToX(b.getX()[itx]);
			//말번호 저장위치 바꾸기
			b.malPos[ity][itx] = 12;
			b.malPos[iy][ix] = 14;
		}
		else if (b.malPos[iy][ix] == 13)
		{
			ni1.setToY(b.getY()[ity]);
			ni1.setToX(b.getX()[itx]);
			//말번호 저장위치 바꾸기
			b.malPos[ity][itx] = 13;
			b.malPos[iy][ix] = 14;
		}
		else if (b.malPos[iy][ix] == 11)
		{
			wi1.setToY(b.getY()[ity]);
			wi1.setToX(b.getX()[itx]);
			//말번호 저장위치 바꾸기
			b.malPos[ity][itx] = 11;
			b.malPos[iy][ix] = 14;
		}
		else if (b.malPos[iy][ix] == 15)
		{
			wa1.setToY(b.getY()[ity]);
			wa1.setToX(b.getX()[itx]);
			//말번호 저장위치 바꾸기
			b.malPos[ity][itx] = 15;
			b.malPos[iy][ix] = 14;
		}
		else if (b.malPos[iy][ix] == 16)
		{
			de1.setToY(b.getY()[ity]);
			de1.setToX(b.getX()[itx]);
			//말번호 저장위치 바꾸기
			b.malPos[ity][itx] = 16;
			b.malPos[iy][ix] = 14;
		}
		else if (b.malPos[iy][ix] == 17)
		{
			kn1.setToY(b.getY()[ity]);
			kn1.setToX(b.getX()[itx]);
			//말번호 저장위치 바꾸기
			b.malPos[ity][itx] = 17;
			b.malPos[iy][ix] = 14;
		}
	}
}

void Ghost::waAbillity(Board b, Player p1)
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

void Ghost::knAbillity(Board& b, int ix, int iy, int tmpX, int tmpY, Mal& wi1, Mal& re1, Mal& ni1, Mal& gh1, Mal& wa1, Mal& de1, Player p1)
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