#ifndef GUARD__PLAYER_H
#define GUARD__PLAYER_H

#include <vector>
#include "bettingcompany.h"

class Player {
public:
	void receive(int);
	void bet(Betting_company);
private:
	int balance;
};

#endif