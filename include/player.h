#ifndef GUARD__PLAYER_H
#define GUARD__PLAYER_H

#include <vector>
#include "bettingcompany.h"
#include "legalentity.h"

class Betting_company;

class Player: public Legal_entity {
	friend 	std::ostream& operator<<(std::ostream&, const Player&);
public:
	explicit Player(int i): Legal_entity(100.0), id(i) {}
	void bet(Betting_company*);
	void pay(Betting_company*,double);
private:
	int id;
};

#endif