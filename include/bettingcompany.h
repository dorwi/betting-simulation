#ifndef GUARD__bettingcompany_h
#define GUARD__bettingcompany_h

#include <vector>
#include <iostream>
#include <map>
#include "player.h"
#include "playerbet.h"

class Player;
class Player_bet;

class Betting_company {
	friend 	std::ostream& operator<<(std::ostream&, const Betting_company&);
public:
	Betting_company(): balance(0) { initialize(); }
	const int n_dogs = 5;
	const double total_start = 20.0;
	void recieve_bet(int, double, Player*);
	void recieve(double);
	void pay(double);
	void pay_out();
	void initialize();
private:
	std::vector<double> probs;
	std::vector<Player_bet> all_bets;
	std::vector<double> odds;
	std::map<int, double> total_bets;
	double balance;
	double total_sum;
};

#endif