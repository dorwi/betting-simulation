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
	virtual bool participate(Betting_company*);
	void pay(Betting_company*,double);
	virtual std::string name() const;
	virtual ~Player(){}
protected:
	int id;
};



class Agressive_player: public virtual Player{
public:
	Agressive_player(int i): Player(i) {}
	virtual void bet(Betting_company*);
	virtual bool participate(Betting_company* bc) { return Player::participate(bc);}
	virtual std::string name() const;
	virtual ~Agressive_player(){}
};

class VIP_player: public virtual Player{
public:
	VIP_player(int i): Player(i) {}
	virtual void bet(Betting_company* bc) {Player::bet(bc);}
	virtual bool participate(Betting_company*) {return true;}
	virtual std::string name() const;
	virtual ~VIP_player(){}
};

class Agressive_VIP_player: public Agressive_player, public VIP_player{
public:
	Agressive_VIP_player(int i): Player(i), Agressive_player(i), VIP_player(i) {}
	void bet(Betting_company* bc) {Agressive_player::bet(bc);}
	bool participate(Betting_company* bc) {return VIP_player::participate(bc);}
	std::string name() const;
	~Agressive_VIP_player(){}
};


#endif