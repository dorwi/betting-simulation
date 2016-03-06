#include "playerbet.h"
#include "bettingcompany.h"

void Player_bet::process(Betting_company& bc){
	double worth = amount * odds[dog];
	bc.pay(worth);
	player->recieve(worth); 
}

bool Player_bet::won(int k){
	return dog == k;
}