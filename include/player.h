#ifndef GUARD__PLAYER_H
#define GUARD__PLAYER_H

#include <vector>
#include "bettingcompany.h"

class Betting_company;

class Player {
	friend 	std::ostream& operator<<(std::ostream&, const Player&);
public:
	explicit Player(int i): id(i), balance(100) {}
	void recieve(double);
	void bet(Betting_company*);
	void pay(Betting_company*,double);
private:
	int id;
	double balance;
};

#endif