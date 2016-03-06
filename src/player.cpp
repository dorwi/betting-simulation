#include <stdexcept>

#include "player.h"
#include "bettingcompany.h"
#include "customrandom.h"
#include <iostream>
#include <string>
#include <sstream>

using std::ostream; using std::string; using std::stringstream;


void Player::bet(Betting_company* bc){
	double amount = Custom_random::get_random_double(1.0, 5.0);
	if (has(amount)){
		int k = Custom_random::get_random(bc->n_dogs);
		bc->recieve_bet(k, amount, this);
		Legal_entity::pay(amount);
	}
}


void Player::pay(Betting_company* betinc, double amount){
	if (amount<0 || balance() - amount < 0){
		throw std::domain_error("The paying amount cannot be negative or higher than the balance");
	}
	Legal_entity::pay(amount);
	betinc->recieve(amount);
}

string Player::name() const{
	stringstream ss;
	ss << "Player " << id;
	return ss.str(); 
}

string Agressive_player::name() const{
	stringstream ss;
	ss << "Agressive Player " << id;
	return ss.str(); 
}

ostream& operator<<(ostream& os, const Player* p){
	os << p->name() << " balance: " << p->balance() << " ";
	return os;
}


void Agressive_player::bet(Betting_company* bc){
	double amount = 2*Custom_random::get_random_double(1.0, 5.0);
	if (has(amount)){
		int k = Custom_random::get_random(bc->n_dogs);
		bc->recieve_bet(k, amount, this);
		Legal_entity::pay(amount);
	}
}