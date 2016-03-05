#ifndef GUARD__bettingcompany_h
#define GUARD__bettingcompany_h

#include <vector>
#include "player.h"
#include "playerbet.h"

class Player;

class Betting_company {
public:
	Betting_company(): balance(0) {};
	void put_bet(int, int, Player*);
private:
	std::vector<double> probs;
	std::vector<Player_bet> all_bets;
	std::vector<double> odds;
	int balance; 
};

#endif