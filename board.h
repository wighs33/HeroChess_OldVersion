#pragma once
#include <windows.h>
#include "Mal.h"
#include "Player.h"

struct Board
{
public:
	void draw(HDC hdc);
	void moveable(HPEN hPen, HPEN oldPen, HDC mem1dc, Mal mal, Board b, Player p1);
	int* getY();
	int* getX();
	int posToIndex(int pos);
	int malPos[10][7];	//�� ��ȣ ���� p1:  1,2,3,4,5,6,7	p2: 11,12,13,14,15,16,17
private:
	int mY[10];// ��ġ����
	int mX[7];
};