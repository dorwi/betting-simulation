#include "bettingcompany.h"
#include "playerbet.h"

#include <iostream>

using std::ostream; using std::endl;

void Betting_company::put_bet(int dog, double amount, Player* p){

}
	
void Betting_company::recieve(double amount){
	balance += amount;
}



ostream& operator<<(ostream& os, const Betting_company& bc){
	os << "Betting Company Balance: " << bc.balance;
	return os;
}
