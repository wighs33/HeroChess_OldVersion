#include "Mal.h"

int Mal::getY()
{
	return mY;
}

int Mal::getX()
{
	return mX;
}

void Mal::setY(int y)
{
	mY=y;
}

void Mal::setX(int x)
{
	mX=x;
}

int Mal::getToX()
{
	return mToX;
}

void Mal::setToX(int toX)
{
	mToX = toX;
}

int Mal::getToY()
{
	return mToY;
}

void Mal::setToY(int toY)
{
	mToY = toY;
}

bool Mal::getSelect()
{
	return isSelect;
}

void Mal::setSelect(bool select)
{
	isSelect = select;
}

bool Mal::getAblTurn()
{
	return isAblTurn;
}

void Mal::setAblTurn(bool ablTurn)
{
	isAblTurn = ablTurn;
}

bool Mal::getMoveAni()
{
	return isMoveAni;
}

void Mal::setMoveAni(bool moveAni)
{
	isMoveAni = moveAni;
}

bool Mal::getAtkAni()
{
	return isAtkAni;
}

void Mal::setAtkAni(bool atkAni)
{
	isAtkAni = atkAni;
}

bool Mal::getAblAni()
{
	return isAblAni;
}

void Mal::setAblAni(bool ablAni)
{
	isAblAni = ablAni;
}