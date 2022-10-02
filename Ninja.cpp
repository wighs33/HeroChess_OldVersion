#include "Ninja.h"

void Ninja::wiAbillity(Mal& re1, Mal& ni1, Mal& gh1, Mal& wa1, Mal& de1, Mal& kn1, Board b, int ix, int iy, int itx, int ity)
{
	setToY(b.getY()[iy]);
	setToX(b.getX()[ix]);
	cngMal = b.malPos[iy][ix];
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

void Ninja::reghAbillity(Mal wi2, Mal re2, Mal ni2, Mal gh2, Mal wa2, Mal de2, Mal kn2, Board b, int ix, int iy)
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

void Ninja::deAbillity(Board b, int ix, int iy, int itx, int ity, int tmpX, int tmpY, Player& p1, Player& p2)
{
	if (b.malPos[ity - 1][itx] >= 1 && iy > ity - 1 && ix == itx)//위에 말이 놓임 그리고 윗줄 클릭했을때
	{
		setToY(b.getY()[iy]);
		setToX(b.getX()[ix]);
		tmpY = getY();
		tmpX = getX();
		//말번호 저장위치 바꾸기
		b.malPos[ity][itx] = 0;
		b.malPos[iy][ix] = 6;
	}
	else if (b.malPos[ity + 1][itx] >= 1 && iy < ity + 1 && ix == itx)//아래에 말이 놓임
	{
		setToY(b.getY()[iy]);
		setToX(b.getX()[ix]);
		tmpY = getY();
		tmpX = getX();
		//말번호 저장위치 바꾸기
		b.malPos[ity][itx] = 0;
		b.malPos[iy][ix] = 6;
	}
	else if (b.malPos[ity][itx - 1] >= 1 && iy == ity && ix < itx - 1)//좌에 말이 놓임
	{
		setToY(b.getY()[iy]);
		setToX(b.getX()[ix]);
		tmpY = getY();
		tmpX = getX();
		//말번호 저장위치 바꾸기
		b.malPos[ity][itx] = 0;
		b.malPos[iy][ix] = 6;
	}
	else if (b.malPos[ity][itx + 1] >= 1 && iy == ity && ix > itx + 1)//우에 말이 놓임
	{
		setToY(b.getY()[iy]);
		setToX(b.getX()[ix]);
		tmpY = getY();
		tmpX = getX();
		//말번호 저장위치 바꾸기
		b.malPos[ity][itx] = 0;
		b.malPos[iy][ix] = 6;
	}
	else
	{
		setAblAni(0);//능력 off
		//턴종료
		p1.setTurn(0);
		p2.setTurn(1);
	}
}

void Ninja::knAbillity(Board b, int ix, int iy, int tmpX, int tmpY, Mal& wi1, Mal& re1, Mal& ni1, Mal& gh1, Mal& wa1, Mal& de1)
{
	if (b.malPos[iy][ix] == 1)
	{
		wi1.setY(wi1.getY() + getY() - tmpY);
		wi1.setX(wi1.getX() + getX() - tmpX);
	}
	else if (b.malPos[iy][ix] == 2)
	{
		re1.setY(re1.getY() + getY() - tmpY);
		re1.setX(re1.getX() + getX() - tmpX);
	}
	else if (b.malPos[iy][ix] == 3)
	{
		ni1.setY(ni1.getY() + getY() - tmpY);
		ni1.setX(ni1.getX() + getX() - tmpX);
	}
	else if (b.malPos[iy][ix] == 4)
	{
		gh1.setY(gh1.getY() + getY() - tmpY);
		gh1.setX(gh1.getX() + getX() - tmpX);
	}
	else if (b.malPos[iy][ix] == 5)
	{
		wa1.setY(wa1.getY() + getY() - tmpY);
		wa1.setX(wa1.getX() + getX() - tmpX);
	}
	else if (b.malPos[iy][ix] == 6)
	{
		de1.setY(de1.getY() + getY() - tmpY);
		de1.setX(de1.getX() + getX() - tmpX);
	}
}