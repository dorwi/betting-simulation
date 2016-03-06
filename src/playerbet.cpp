#include "playerbet.h"
#include "bettingcompany.h"

#include <iostream>

using std::cout; using std::endl;

void Player_bet::process(Betting_company& bc){
	double worth = amount * odds;
	bc.pay(worth);
	player->recieve(worth); 
}

bool Player_bet::won(int k){
	return dog == k;
}