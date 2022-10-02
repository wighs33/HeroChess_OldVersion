#include "board.h"

void Board::draw(HDC hdc)
{
	for (int i = 60; i <= 60*8; i += 60)
	{
		//����
		MoveToEx(hdc, i, 60, NULL);
		LineTo(hdc, i, 60*11);
	}

	for (int i = 60; i <= 60 * 11; i += 60)
	{
		//����
		MoveToEx(hdc, 60, i, NULL);
		LineTo(hdc, 60*8, i);
	}
}

void Board::moveable(HPEN hPen, HPEN oldPen, HDC mem1dc, Mal mal, Board b, Player p1)
{
	hPen = CreatePen(PS_SOLID, 3, RGB(0, 255, 0));	//ĭ�� �ʷ��׵θ� �׸���
	oldPen = (HPEN)SelectObject(mem1dc, hPen);
	Rectangle(mem1dc, mal.getX(), mal.getY(), mal.getX() + 60, mal.getY() + 60);	//�� ��ġ
	if (mal.getY() - 60 >= b.getY()[0])//���� ��
	{
		if (b.malPos[b.posToIndex(mal.getY() - 60)][b.posToIndex(mal.getX())] == 0)//ĭ�� ������ ��
		{
			hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));//�Ķ��׵θ�
			oldPen = (HPEN)SelectObject(mem1dc, hPen);
			Rectangle(mem1dc, mal.getX(), mal.getY() - 60, mal.getX() + 60, mal.getY());// �̵��Ҽ� �ִ� ��ġ		��
		}
		else if (p1.getTurn()==1&&b.malPos[b.posToIndex(mal.getY() - 60)][b.posToIndex(mal.getX())] > 10)//ĭ�� ������ ��
		{
			hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));//�����׵θ�
			oldPen = (HPEN)SelectObject(mem1dc, hPen);
			Rectangle(mem1dc, mal.getX(), mal.getY() - 60, mal.getX() + 60, mal.getY());// �̵��Ҽ� �ִ� ��ġ		��
		}
		else if (p1.getTurn() == 0 && b.malPos[b.posToIndex(mal.getY() - 60)][b.posToIndex(mal.getX())] < 10)//ĭ�� ������ ��
		{
			hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));//�����׵θ�
			oldPen = (HPEN)SelectObject(mem1dc, hPen);
			Rectangle(mem1dc, mal.getX(), mal.getY() - 60, mal.getX() + 60, mal.getY());// �̵��Ҽ� �ִ� ��ġ		��
		}
	}
	if (mal.getY() + 60 <= b.getY()[9])//���� ��
	{
		if (b.malPos[b.posToIndex(mal.getY() + 60)][b.posToIndex(mal.getX())] == 0)
		{
			hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
			oldPen = (HPEN)SelectObject(mem1dc, hPen);
			Rectangle(mem1dc, mal.getX(), mal.getY() + 60, mal.getX() + 60, mal.getY() + 120);// �̵��Ҽ� �ִ� ��ġ	��
		}
		else if (p1.getTurn() == 1 && b.malPos[b.posToIndex(mal.getY() + 60)][b.posToIndex(mal.getX())] > 10)
		{
			hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
			oldPen = (HPEN)SelectObject(mem1dc, hPen);
			Rectangle(mem1dc, mal.getX(), mal.getY() + 60, mal.getX() + 60, mal.getY() + 120);// �̵��Ҽ� �ִ� ��ġ	��
		}
		else if (p1.getTurn() == 0 && b.malPos[b.posToIndex(mal.getY() + 60)][b.posToIndex(mal.getX())] < 10)
		{
			hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
			oldPen = (HPEN)SelectObject(mem1dc, hPen);
			Rectangle(mem1dc, mal.getX(), mal.getY() + 60, mal.getX() + 60, mal.getY() + 120);// �̵��Ҽ� �ִ� ��ġ	��
		}
	}
	if (mal.getX() - 60 >= b.getX()[0])//���� ��
	{
		if (b.malPos[b.posToIndex(mal.getY())][b.posToIndex(mal.getX() - 60)] == 0)
		{
			hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
			oldPen = (HPEN)SelectObject(mem1dc, hPen);
			Rectangle(mem1dc, mal.getX() - 60, mal.getY(), mal.getX(), mal.getY() + 60);// �̵��Ҽ� �ִ� ��ġ		��
		}
		else if (p1.getTurn() == 1 && b.malPos[b.posToIndex(mal.getY())][b.posToIndex(mal.getX() - 60)] > 10)
		{
			hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
			oldPen = (HPEN)SelectObject(mem1dc, hPen);
			Rectangle(mem1dc, mal.getX() - 60, mal.getY(), mal.getX(), mal.getY() + 60);// �̵��Ҽ� �ִ� ��ġ		��
		}
		else if (p1.getTurn() == 0 && b.malPos[b.posToIndex(mal.getY())][b.posToIndex(mal.getX() - 60)] < 10)
		{
			hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
			oldPen = (HPEN)SelectObject(mem1dc, hPen);
			Rectangle(mem1dc, mal.getX() - 60, mal.getY(), mal.getX(), mal.getY() + 60);// �̵��Ҽ� �ִ� ��ġ		��
		}
	}
	if ( mal.getX() + 60 <= b.getX()[6])//���� ��
	{
		if (b.malPos[b.posToIndex(mal.getY())][b.posToIndex(mal.getX() + 60)] == 0)
		{
			hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
			oldPen = (HPEN)SelectObject(mem1dc, hPen);
			Rectangle(mem1dc, mal.getX() + 60, mal.getY(), mal.getX() + 120, mal.getY() + 60);// �̵��Ҽ� �ִ� ��ġ	��
		}
		else if (p1.getTurn() == 1 && b.malPos[b.posToIndex(mal.getY())][b.posToIndex(mal.getX() + 60)] > 10)
		{
			hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
			oldPen = (HPEN)SelectObject(mem1dc, hPen);
			Rectangle(mem1dc, mal.getX() + 60, mal.getY(), mal.getX() + 120, mal.getY() + 60);// �̵��Ҽ� �ִ� ��ġ	��
		}
		else if (p1.getTurn() == 0 && b.malPos[b.posToIndex(mal.getY())][b.posToIndex(mal.getX() + 60)] < 10)
		{
			hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
			oldPen = (HPEN)SelectObject(mem1dc, hPen);
			Rectangle(mem1dc, mal.getX() + 60, mal.getY(), mal.getX() + 120, mal.getY() + 60);// �̵��Ҽ� �ִ� ��ġ	��
		}
		if (b.malPos[b.posToIndex(mal.getY())][b.posToIndex(mal.getX())] == 3 ||
			b.malPos[b.posToIndex(mal.getY())][b.posToIndex(mal.getX())] == 4 ||
			b.malPos[b.posToIndex(mal.getY())][b.posToIndex(mal.getX())] == 5 ||
			b.malPos[b.posToIndex(mal.getY())][b.posToIndex(mal.getX())] == 13 ||
			b.malPos[b.posToIndex(mal.getY())][b.posToIndex(mal.getX())] == 14 ||
			b.malPos[b.posToIndex(mal.getY())][b.posToIndex(mal.getX())] == 15)
		{
			if (mal.getY() - 60 >= b.getY()[0] && mal.getX() - 60 >= b.getX()[0])//���� ��
			{
				if (b.malPos[b.posToIndex(mal.getY() - 60)][b.posToIndex(mal.getX() - 60)] == 0)//ĭ�� ������ ��
				{
					hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));//�Ķ��׵θ�
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, mal.getX() - 60, mal.getY() - 60, mal.getX(), mal.getY());// �̵��Ҽ� �ִ� ��ġ		�ϼ�
				}
				else if (p1.getTurn() == 1 && b.malPos[b.posToIndex(mal.getY() - 60)][b.posToIndex(mal.getX() - 60)] > 10)//ĭ�� ������ ��
				{
					hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));//�����׵θ�
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, mal.getX() - 60, mal.getY() - 60, mal.getX(), mal.getY());// �̵��Ҽ� �ִ� ��ġ		�ϼ�
				}
				else if (p1.getTurn() == 0 && b.malPos[b.posToIndex(mal.getY() - 60)][b.posToIndex(mal.getX() - 60)] < 10)//ĭ�� ������ ��
				{
					hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));//�����׵θ�
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, mal.getX() - 60, mal.getY() - 60, mal.getX(), mal.getY());// �̵��Ҽ� �ִ� ��ġ		�ϼ�
				}
			}
			if (mal.getY() + 60 <= b.getY()[9] && mal.getX() + 60 <= b.getX()[6])//���� ��
			{
				if (b.malPos[b.posToIndex(mal.getY() + 60)][b.posToIndex(mal.getX() + 60)] == 0)//ĭ�� ������ ��
				{
					hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));//�Ķ��׵θ�
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, mal.getX() + 60, mal.getY() + 60, mal.getX() + 120, mal.getY() + 120);// �̵��Ҽ� �ִ� ��ġ		����
				}
				else if (p1.getTurn() == 1 && b.malPos[b.posToIndex(mal.getY() + 60)][b.posToIndex(mal.getX() + 60)] > 10)//ĭ�� ������ ��
				{
					hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));//�����׵θ�
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, mal.getX() + 60, mal.getY() + 60, mal.getX() + 120, mal.getY() + 120);// �̵��Ҽ� �ִ� ��ġ		����
				}
				else if (p1.getTurn() == 0 && b.malPos[b.posToIndex(mal.getY() + 60)][b.posToIndex(mal.getX() + 60)] < 10)//ĭ�� ������ ��
				{
					hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));//�����׵θ�
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, mal.getX() + 60, mal.getY() + 60, mal.getX() + 120, mal.getY() + 120);// �̵��Ҽ� �ִ� ��ġ		����
				}
			}
			if (mal.getY() - 60 >= b.getY()[0] && mal.getX() + 60 <= b.getX()[6])//���� ��
			{
				if (b.malPos[b.posToIndex(mal.getY() - 60)][b.posToIndex(mal.getX() + 60)] == 0)//ĭ�� ������ ��
				{
					hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));//�Ķ��׵θ�
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, mal.getX() + 60, mal.getY() - 60, mal.getX() + 120, mal.getY());// �̵��Ҽ� �ִ� ��ġ		�ϵ�
				}
				else if (p1.getTurn() == 1 && b.malPos[b.posToIndex(mal.getY() - 60)][b.posToIndex(mal.getX() + 60)] > 10)//ĭ�� ������ ��
				{
					hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));//�����׵θ�
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, mal.getX() + 60, mal.getY() - 60, mal.getX() + 120, mal.getY());// �̵��Ҽ� �ִ� ��ġ		�ϵ�
				}
				else if (p1.getTurn() == 0 && b.malPos[b.posToIndex(mal.getY() - 60)][b.posToIndex(mal.getX() + 60)] <10)//ĭ�� ������ ��
				{
					hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));//�����׵θ�
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, mal.getX() + 60, mal.getY() - 60, mal.getX() + 120, mal.getY());// �̵��Ҽ� �ִ� ��ġ		�ϵ�
				}
			}
			if (mal.getX() - 60 >= b.getX()[0] && mal.getY() + 60 <= b.getY()[9])//���� ��
			{
				if (b.malPos[b.posToIndex(mal.getY() + 60)][b.posToIndex(mal.getX() - 60)] == 0)//ĭ�� ������ ��
				{
					hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));//�Ķ��׵θ�
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, mal.getX() - 60, mal.getY() + 60, mal.getX(), mal.getY() + 120);// �̵��Ҽ� �ִ� ��ġ		����
				}
				else if (p1.getTurn() == 1 && b.malPos[b.posToIndex(mal.getY() + 60)][b.posToIndex(mal.getX() - 60)] > 10)//ĭ�� ������ ��
				{
					hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));//�����׵θ�
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, mal.getX() - 60, mal.getY() + 60, mal.getX(), mal.getY() + 120);// �̵��Ҽ� �ִ� ��ġ		����
				}
				else if (p1.getTurn() == 0 && b.malPos[b.posToIndex(mal.getY() + 60)][b.posToIndex(mal.getX() - 60)] < 10)//ĭ�� ������ ��
				{
					hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));//�����׵θ�
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, mal.getX() - 60, mal.getY() + 60, mal.getX(), mal.getY() + 120);// �̵��Ҽ� �ִ� ��ġ		����
				}
			}
		}
	}
}

int* Board::getY()
{
	return mY;
}

int* Board::getX()
{
	return mX;
}

int Board::posToIndex(int pos)
{
	return pos / 60 - 1;
}