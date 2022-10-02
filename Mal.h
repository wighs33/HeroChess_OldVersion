#pragma once

class Mal
{
public:
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	int getToX();
	void setToX(int toX);
	int getToY();
	void setToY(int toY);
	bool getSelect();
	void setSelect(bool select);
	bool getAblTurn();
	void setAblTurn(bool ablTurn);
	bool getMoveAni();
	void setMoveAni(bool moveAni);
	bool getAtkAni();
	void setAtkAni(bool atkAni);
	bool getAblAni();
	void setAblAni(bool ablAni);
	int cnt = 0;
private:
	int mX, mY;
	int mToX, mToY;
	bool isSelect=0;
	bool isAblTurn=0;
	bool isMoveAni=0;
	bool isAtkAni=0;
	bool isAblAni=0;
};

