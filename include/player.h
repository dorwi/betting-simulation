#ifndef GUARD__PLAYER_H
#define GUARD__PLAYER_H

#include <vector>
#include "bettingcompany.h"
#include "legalentity.h"
#include <string>

class Betting_company;

class Player: public Legal_entity {
	friend 	std::ostream& operator<<(std::ostream&, const Player*);
public:
	explicit Player(int i): Legal_entity(100.0), id(i) {}
	virtual void bet(Betting_company*);
	void pay(Betting_company*,double);
	virtual std::string name() const;
	virtual ~Player(){}
protected:
	int id;
};



class Agressive_player: public Player{
public:
	Agressive_player(int i): Player(i) {}
	void bet(Betting_company*);
	std::string name() const;
	~Agressive_player(){}
};


#endif