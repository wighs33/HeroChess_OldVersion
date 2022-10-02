#include "Player.h"

bool Player::getTurn()
{
	return isTurn;
}

void Player::setTurn(bool turn)
{
	isTurn = turn;
}