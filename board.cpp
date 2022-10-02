#include "board.h"

void Board::draw(HDC hdc)
{
	for (int i = 60; i <= 60*8; i += 60)
	{
		//가로
		MoveToEx(hdc, i, 60, NULL);
		LineTo(hdc, i, 60*11);
	}

	for (int i = 60; i <= 60 * 11; i += 60)
	{
		//세로
		MoveToEx(hdc, 60, i, NULL);
		LineTo(hdc, 60*8, i);
	}
}

void Board::moveable(HPEN hPen, HPEN oldPen, HDC mem1dc, Mal mal, Board b, Player p1)
{
	hPen = CreatePen(PS_SOLID, 3, RGB(0, 255, 0));	//칸에 초록테두리 그리기
	oldPen = (HPEN)SelectObject(mem1dc, hPen);
	Rectangle(mem1dc, mal.getX(), mal.getY(), mal.getX() + 60, mal.getY() + 60);	//말 위치
	if (mal.getY() - 60 >= b.getY()[0])//격자 안
	{
		if (b.malPos[b.posToIndex(mal.getY() - 60)][b.posToIndex(mal.getX())] == 0)//칸에 말없을 때
		{
			hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));//파란테두리
			oldPen = (HPEN)SelectObject(mem1dc, hPen);
			Rectangle(mem1dc, mal.getX(), mal.getY() - 60, mal.getX() + 60, mal.getY());// 이동할수 있는 위치		상
		}
		else if (p1.getTurn()==1&&b.malPos[b.posToIndex(mal.getY() - 60)][b.posToIndex(mal.getX())] > 10)//칸에 적있을 때
		{
			hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));//빨간테두리
			oldPen = (HPEN)SelectObject(mem1dc, hPen);
			Rectangle(mem1dc, mal.getX(), mal.getY() - 60, mal.getX() + 60, mal.getY());// 이동할수 있는 위치		상
		}
		else if (p1.getTurn() == 0 && b.malPos[b.posToIndex(mal.getY() - 60)][b.posToIndex(mal.getX())] < 10)//칸에 적있을 때
		{
			hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));//빨간테두리
			oldPen = (HPEN)SelectObject(mem1dc, hPen);
			Rectangle(mem1dc, mal.getX(), mal.getY() - 60, mal.getX() + 60, mal.getY());// 이동할수 있는 위치		상
		}
	}
	if (mal.getY() + 60 <= b.getY()[9])//격자 안
	{
		if (b.malPos[b.posToIndex(mal.getY() + 60)][b.posToIndex(mal.getX())] == 0)
		{
			hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
			oldPen = (HPEN)SelectObject(mem1dc, hPen);
			Rectangle(mem1dc, mal.getX(), mal.getY() + 60, mal.getX() + 60, mal.getY() + 120);// 이동할수 있는 위치	하
		}
		else if (p1.getTurn() == 1 && b.malPos[b.posToIndex(mal.getY() + 60)][b.posToIndex(mal.getX())] > 10)
		{
			hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
			oldPen = (HPEN)SelectObject(mem1dc, hPen);
			Rectangle(mem1dc, mal.getX(), mal.getY() + 60, mal.getX() + 60, mal.getY() + 120);// 이동할수 있는 위치	하
		}
		else if (p1.getTurn() == 0 && b.malPos[b.posToIndex(mal.getY() + 60)][b.posToIndex(mal.getX())] < 10)
		{
			hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
			oldPen = (HPEN)SelectObject(mem1dc, hPen);
			Rectangle(mem1dc, mal.getX(), mal.getY() + 60, mal.getX() + 60, mal.getY() + 120);// 이동할수 있는 위치	하
		}
	}
	if (mal.getX() - 60 >= b.getX()[0])//격자 안
	{
		if (b.malPos[b.posToIndex(mal.getY())][b.posToIndex(mal.getX() - 60)] == 0)
		{
			hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
			oldPen = (HPEN)SelectObject(mem1dc, hPen);
			Rectangle(mem1dc, mal.getX() - 60, mal.getY(), mal.getX(), mal.getY() + 60);// 이동할수 있는 위치		좌
		}
		else if (p1.getTurn() == 1 && b.malPos[b.posToIndex(mal.getY())][b.posToIndex(mal.getX() - 60)] > 10)
		{
			hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
			oldPen = (HPEN)SelectObject(mem1dc, hPen);
			Rectangle(mem1dc, mal.getX() - 60, mal.getY(), mal.getX(), mal.getY() + 60);// 이동할수 있는 위치		좌
		}
		else if (p1.getTurn() == 0 && b.malPos[b.posToIndex(mal.getY())][b.posToIndex(mal.getX() - 60)] < 10)
		{
			hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
			oldPen = (HPEN)SelectObject(mem1dc, hPen);
			Rectangle(mem1dc, mal.getX() - 60, mal.getY(), mal.getX(), mal.getY() + 60);// 이동할수 있는 위치		좌
		}
	}
	if ( mal.getX() + 60 <= b.getX()[6])//격자 안
	{
		if (b.malPos[b.posToIndex(mal.getY())][b.posToIndex(mal.getX() + 60)] == 0)
		{
			hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
			oldPen = (HPEN)SelectObject(mem1dc, hPen);
			Rectangle(mem1dc, mal.getX() + 60, mal.getY(), mal.getX() + 120, mal.getY() + 60);// 이동할수 있는 위치	우
		}
		else if (p1.getTurn() == 1 && b.malPos[b.posToIndex(mal.getY())][b.posToIndex(mal.getX() + 60)] > 10)
		{
			hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
			oldPen = (HPEN)SelectObject(mem1dc, hPen);
			Rectangle(mem1dc, mal.getX() + 60, mal.getY(), mal.getX() + 120, mal.getY() + 60);// 이동할수 있는 위치	우
		}
		else if (p1.getTurn() == 0 && b.malPos[b.posToIndex(mal.getY())][b.posToIndex(mal.getX() + 60)] < 10)
		{
			hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
			oldPen = (HPEN)SelectObject(mem1dc, hPen);
			Rectangle(mem1dc, mal.getX() + 60, mal.getY(), mal.getX() + 120, mal.getY() + 60);// 이동할수 있는 위치	우
		}
		if (b.malPos[b.posToIndex(mal.getY())][b.posToIndex(mal.getX())] == 3 ||
			b.malPos[b.posToIndex(mal.getY())][b.posToIndex(mal.getX())] == 4 ||
			b.malPos[b.posToIndex(mal.getY())][b.posToIndex(mal.getX())] == 5 ||
			b.malPos[b.posToIndex(mal.getY())][b.posToIndex(mal.getX())] == 13 ||
			b.malPos[b.posToIndex(mal.getY())][b.posToIndex(mal.getX())] == 14 ||
			b.malPos[b.posToIndex(mal.getY())][b.posToIndex(mal.getX())] == 15)
		{
			if (mal.getY() - 60 >= b.getY()[0] && mal.getX() - 60 >= b.getX()[0])//격자 안
			{
				if (b.malPos[b.posToIndex(mal.getY() - 60)][b.posToIndex(mal.getX() - 60)] == 0)//칸에 말없을 때
				{
					hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));//파란테두리
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, mal.getX() - 60, mal.getY() - 60, mal.getX(), mal.getY());// 이동할수 있는 위치		북서
				}
				else if (p1.getTurn() == 1 && b.malPos[b.posToIndex(mal.getY() - 60)][b.posToIndex(mal.getX() - 60)] > 10)//칸에 적있을 때
				{
					hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));//빨간테두리
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, mal.getX() - 60, mal.getY() - 60, mal.getX(), mal.getY());// 이동할수 있는 위치		북서
				}
				else if (p1.getTurn() == 0 && b.malPos[b.posToIndex(mal.getY() - 60)][b.posToIndex(mal.getX() - 60)] < 10)//칸에 적있을 때
				{
					hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));//빨간테두리
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, mal.getX() - 60, mal.getY() - 60, mal.getX(), mal.getY());// 이동할수 있는 위치		북서
				}
			}
			if (mal.getY() + 60 <= b.getY()[9] && mal.getX() + 60 <= b.getX()[6])//격자 안
			{
				if (b.malPos[b.posToIndex(mal.getY() + 60)][b.posToIndex(mal.getX() + 60)] == 0)//칸에 말없을 때
				{
					hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));//파란테두리
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, mal.getX() + 60, mal.getY() + 60, mal.getX() + 120, mal.getY() + 120);// 이동할수 있는 위치		남동
				}
				else if (p1.getTurn() == 1 && b.malPos[b.posToIndex(mal.getY() + 60)][b.posToIndex(mal.getX() + 60)] > 10)//칸에 적있을 때
				{
					hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));//빨간테두리
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, mal.getX() + 60, mal.getY() + 60, mal.getX() + 120, mal.getY() + 120);// 이동할수 있는 위치		남동
				}
				else if (p1.getTurn() == 0 && b.malPos[b.posToIndex(mal.getY() + 60)][b.posToIndex(mal.getX() + 60)] < 10)//칸에 적있을 때
				{
					hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));//빨간테두리
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, mal.getX() + 60, mal.getY() + 60, mal.getX() + 120, mal.getY() + 120);// 이동할수 있는 위치		남동
				}
			}
			if (mal.getY() - 60 >= b.getY()[0] && mal.getX() + 60 <= b.getX()[6])//격자 안
			{
				if (b.malPos[b.posToIndex(mal.getY() - 60)][b.posToIndex(mal.getX() + 60)] == 0)//칸에 말없을 때
				{
					hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));//파란테두리
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, mal.getX() + 60, mal.getY() - 60, mal.getX() + 120, mal.getY());// 이동할수 있는 위치		북동
				}
				else if (p1.getTurn() == 1 && b.malPos[b.posToIndex(mal.getY() - 60)][b.posToIndex(mal.getX() + 60)] > 10)//칸에 적있을 때
				{
					hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));//빨간테두리
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, mal.getX() + 60, mal.getY() - 60, mal.getX() + 120, mal.getY());// 이동할수 있는 위치		북동
				}
				else if (p1.getTurn() == 0 && b.malPos[b.posToIndex(mal.getY() - 60)][b.posToIndex(mal.getX() + 60)] <10)//칸에 적있을 때
				{
					hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));//빨간테두리
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, mal.getX() + 60, mal.getY() - 60, mal.getX() + 120, mal.getY());// 이동할수 있는 위치		북동
				}
			}
			if (mal.getX() - 60 >= b.getX()[0] && mal.getY() + 60 <= b.getY()[9])//격자 안
			{
				if (b.malPos[b.posToIndex(mal.getY() + 60)][b.posToIndex(mal.getX() - 60)] == 0)//칸에 말없을 때
				{
					hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));//파란테두리
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, mal.getX() - 60, mal.getY() + 60, mal.getX(), mal.getY() + 120);// 이동할수 있는 위치		남서
				}
				else if (p1.getTurn() == 1 && b.malPos[b.posToIndex(mal.getY() + 60)][b.posToIndex(mal.getX() - 60)] > 10)//칸에 적있을 때
				{
					hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));//빨간테두리
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, mal.getX() - 60, mal.getY() + 60, mal.getX(), mal.getY() + 120);// 이동할수 있는 위치		남서
				}
				else if (p1.getTurn() == 0 && b.malPos[b.posToIndex(mal.getY() + 60)][b.posToIndex(mal.getX() - 60)] < 10)//칸에 적있을 때
				{
					hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));//빨간테두리
					oldPen = (HPEN)SelectObject(mem1dc, hPen);
					Rectangle(mem1dc, mal.getX() - 60, mal.getY() + 60, mal.getX(), mal.getY() + 120);// 이동할수 있는 위치		남서
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