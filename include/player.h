#ifndef GUARD__PLAYER_H
#define GUARD__PLAYER_H

#include <vector>
#include "bettingcompany.h"

class Player {
public:
	Player(): balance(100) {}
	void recieve(int);
	void bet(Betting_company*);
private:
	int balance;
};

#endif