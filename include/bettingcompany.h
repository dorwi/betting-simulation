#ifndef GUARD__bettingcompany_h
#define GUARD__bettingcompany_h

#include <vector>
#include <iostream>
#include "player.h"
#include "playerbet.h"

class Player;

class Betting_company {
	friend 	std::ostream& operator<<(std::ostream&, const Betting_company&);
public:
	Betting_company(): balance(0) {};
	void put_bet(int, double, Player*);
	void recieve(double);
private:
	std::vector<double> probs;
	std::vector<Player_bet> all_bets;
	std::vector<double> odds;
	double balance; 
};

#endif