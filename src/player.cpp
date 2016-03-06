#include <stdexcept>

#include "player.h"
#include "bettingcompany.h"
#include "customrandom.h"
#include <iostream>

using std::ostream;


void Player::bet(Betting_company* bc){
	double amount = Custom_random::get_random_double(1.0, 5.0);
	int k = Custom_random::get_random(bc->n_dogs);
	bc->recieve_bet(k, amount, this);
	Legal_entity::pay(amount);
}


void Player::pay(Betting_company* betinc, double amount){
	if (amount<0 || balance() - amount < 0){
		throw std::domain_error("The recieving amount cannot be negative or higher than the balance");
	}
	Legal_entity::pay(amount);
	betinc->recieve(amount);
}


ostream& operator<<(ostream& os, const Player& p){
	os << "Player " << p.id << " balance: " << p.balance();
	return os;
}
