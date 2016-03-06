#ifndef GUARD__playerbet_h
#define GUARD__playerbet_h

#include "player.h"
#include "bettingcompany.h"
#include <vector>

class Player;
class Betting_company;

class Player_bet{
public:
	Player_bet(Player* p, int d, double a, std::vector<double>& o)
		: player(p), dog(d), amount(a), odds(o) {}
	void process(Betting_company&);
	bool won(int);
private:
	Player* player;
	int dog;
	double amount;
	std::vector<double> odds; //at the time of the bet
};


#endif