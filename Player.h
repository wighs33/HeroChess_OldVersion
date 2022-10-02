#pragma once

class Player
{
public:
	bool getTurn();
	void setTurn(bool turn);
private:
	bool isTurn;
};

