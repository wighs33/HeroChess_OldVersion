#include "Defender.h"

void Defender::abillity(Board& b, int ix, int iy, int itx, int ity, int tmpX, int tmpY, Player& p1, Player& p2)
{
	if (b.malPos[ity - 1][itx] >= 1 && iy < ity - 1 && ix == itx)//위에 말이 놓임 그리고 윗줄 클릭했을때
	{
		setToY(b.getY()[iy]);
		setToX(b.getX()[ix]);
		//말번호 저장위치 바꾸기
		b.malPos[ity][itx] = 0;
		if (p1.getTurn() == 1)
			b.malPos[iy][ix] = 6;
		else
			b.malPos[iy][ix] = 16;
	}
	else if (b.malPos[ity + 1][itx] >= 1 && iy > ity + 1 && ix == itx)//아래에 말이 놓임
	{
		setToY(b.getY()[iy]);
		setToX(b.getX()[ix]);
		//말번호 저장위치 바꾸기
		b.malPos[ity][itx] = 0;
		if (p1.getTurn() == 1)
			b.malPos[iy][ix] = 6;
		else
			b.malPos[iy][ix] = 16;
	}
	else if (b.malPos[ity][itx - 1] >= 1 && iy == ity && ix < itx - 1)//좌에 말이 놓임
	{
		setToY(b.getY()[iy]);
		setToX(b.getX()[ix]);
		//말번호 저장위치 바꾸기
		b.malPos[ity][itx] = 0;
		if (p1.getTurn() == 1)
			b.malPos[iy][ix] = 6;
		else
			b.malPos[iy][ix] = 16;
	}
	else if (b.malPos[ity][itx + 1] >= 1 && iy == ity && ix > itx + 1)//우에 말이 놓임
	{
		setToY(b.getY()[iy]);
		setToX(b.getX()[ix]);
		//말번호 저장위치 바꾸기
		b.malPos[ity][itx] = 0;
		if (p1.getTurn() == 1)
			b.malPos[iy][ix] = 6;
		else
			b.malPos[iy][ix] = 16;
	}
	else
	{
		setAblAni(0);//능력 off
		//턴종료
		p1.setTurn(0);
		p2.setTurn(1);
	}
}