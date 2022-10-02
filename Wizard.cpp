#include "Wizard.h"


void Wizard::abillity(Mal& re1, Mal& ni1, Mal& gh1, Mal& wa1, Mal& de1, Mal& kn1, Board& b, int ix, int iy, int itx, int ity, Player p1)
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
			b.malPos[iy][ix] = 1;
		}
		else if (b.malPos[iy][ix] == 3)
		{
			ni1.setToY(b.getY()[ity]);
			ni1.setToX(b.getX()[itx]);
			//말번호 저장위치 바꾸기
			b.malPos[ity][itx] = 3;
			b.malPos[iy][ix] = 1;
		}
		else if (b.malPos[iy][ix] == 4)
		{
			gh1.setToY(b.getY()[ity]);
			gh1.setToX(b.getX()[itx]);
			//말번호 저장위치 바꾸기
			b.malPos[ity][itx] = 4;
			b.malPos[iy][ix] = 1;
		}
		else if (b.malPos[iy][ix] == 5)
		{
			wa1.setToY(b.getY()[ity]);
			wa1.setToX(b.getX()[itx]);
			//말번호 저장위치 바꾸기
			b.malPos[ity][itx] = 5;
			b.malPos[iy][ix] = 1;
		}
		else if (b.malPos[iy][ix] == 6)
		{
			de1.setToY(b.getY()[ity]);
			de1.setToX(b.getX()[itx]);
			//말번호 저장위치 바꾸기
			b.malPos[ity][itx] = 6;
			b.malPos[iy][ix] = 1;
		}
		else if (b.malPos[iy][ix] == 7)
		{
			kn1.setToY(b.getY()[ity]);
			kn1.setToX(b.getX()[itx]);
			//말번호 저장위치 바꾸기
			b.malPos[ity][itx] = 7;
			b.malPos[iy][ix] = 1;
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
			b.malPos[iy][ix] = 11;
		}
		else if (b.malPos[iy][ix] == 13)
		{
			ni1.setToY(b.getY()[ity]);
			ni1.setToX(b.getX()[itx]);
			//말번호 저장위치 바꾸기
			b.malPos[ity][itx] = 13;
			b.malPos[iy][ix] = 11;
		}
		else if (b.malPos[iy][ix] == 14)
		{
			gh1.setToY(b.getY()[ity]);
			gh1.setToX(b.getX()[itx]);
			//말번호 저장위치 바꾸기
			b.malPos[ity][itx] = 14;
			b.malPos[iy][ix] = 11;
		}
		else if (b.malPos[iy][ix] == 15)
		{
			wa1.setToY(b.getY()[ity]);
			wa1.setToX(b.getX()[itx]);
			//말번호 저장위치 바꾸기
			b.malPos[ity][itx] = 15;
			b.malPos[iy][ix] = 11;
		}
		else if (b.malPos[iy][ix] == 16)
		{
			de1.setToY(b.getY()[ity]);
			de1.setToX(b.getX()[itx]);
			//말번호 저장위치 바꾸기
			b.malPos[ity][itx] = 16;
			b.malPos[iy][ix] = 11;
		}
		else if (b.malPos[iy][ix] == 17)
		{
			kn1.setToY(b.getY()[ity]);
			kn1.setToX(b.getX()[itx]);
			//말번호 저장위치 바꾸기
			b.malPos[ity][itx] = 17;
			b.malPos[iy][ix] = 11;
		}
	}
}
