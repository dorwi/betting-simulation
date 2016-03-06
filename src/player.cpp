#include <stdexcept>

#include "player.h"
#include "bettingcompany.h"
#include <iostream>

using std::ostream;

void Player::recieve(double amount){
	if (amount<0){
		throw std::domain_error("The recieving amount cannot be negative");
	} else{
		balance += amount;
	}
}

void Player::bet(Betting_company*){

}


void Player::pay(Betting_company* betinc, double amount){
	if (amount<0 || balance - amount < 0){
		throw std::domain_error("The recieving amount cannot be negative or higher than the balance");
	}
	balance -= amount;
	betinc->recieve(amount);
}


ostream& operator<<(ostream& os, const Player& p){
	os << "Player " << p.id << " balance: " << p.balance;
	return os;
}
