#include <stdexcept>

#include "player.h"
#include "bettingcompany.h"

void Player::recieve(int amount){
	if (amount<0){
		throw std::domain_error("The recieving amount cannot be negative");
	} else{
		balance += amount;
	}
}

void Player::bet(Betting_company*){

}