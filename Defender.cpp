#include "Defender.h"

void Defender::abillity(Board& b, int ix, int iy, int itx, int ity, int tmpX, int tmpY, Player& p1, Player& p2)
{
	if (b.malPos[ity - 1][itx] >= 1 && iy < ity - 1 && ix == itx)//���� ���� ���� �׸��� ���� Ŭ��������
	{
		setToY(b.getY()[iy]);
		setToX(b.getX()[ix]);
		//����ȣ ������ġ �ٲٱ�
		b.malPos[ity][itx] = 0;
		if (p1.getTurn() == 1)
			b.malPos[iy][ix] = 6;
		else
			b.malPos[iy][ix] = 16;
	}
	else if (b.malPos[ity + 1][itx] >= 1 && iy > ity + 1 && ix == itx)//�Ʒ��� ���� ����
	{
		setToY(b.getY()[iy]);
		setToX(b.getX()[ix]);
		//����ȣ ������ġ �ٲٱ�
		b.malPos[ity][itx] = 0;
		if (p1.getTurn() == 1)
			b.malPos[iy][ix] = 6;
		else
			b.malPos[iy][ix] = 16;
	}
	else if (b.malPos[ity][itx - 1] >= 1 && iy == ity && ix < itx - 1)//�¿� ���� ����
	{
		setToY(b.getY()[iy]);
		setToX(b.getX()[ix]);
		//����ȣ ������ġ �ٲٱ�
		b.malPos[ity][itx] = 0;
		if (p1.getTurn() == 1)
			b.malPos[iy][ix] = 6;
		else
			b.malPos[iy][ix] = 16;
	}
	else if (b.malPos[ity][itx + 1] >= 1 && iy == ity && ix > itx + 1)//�쿡 ���� ����
	{
		setToY(b.getY()[iy]);
		setToX(b.getX()[ix]);
		//����ȣ ������ġ �ٲٱ�
		b.malPos[ity][itx] = 0;
		if (p1.getTurn() == 1)
			b.malPos[iy][ix] = 6;
		else
			b.malPos[iy][ix] = 16;
	}
	else
	{
		setAblAni(0);//�ɷ� off
		//������
		p1.setTurn(0);
		p2.setTurn(1);
	}
}