#include "bettingcompany.h"
#include "playerbet.h"
#include "customrandom.h"

#include <stdexcept>
#include <iostream>

using std::ostream; using std::endl;
using std::cout;

void Betting_company::recieve_bet(int dog, double amount, Player* p){
	if (dog < 0 || dog>=n_dogs)
		throw std::domain_error("Dog must be in a given interval");
	
	recieve(amount);
	Player_bet pb(p, dog, amount, odds[dog]);
	total_bets[dog] += amount;
	total_sum += amount;
	for (int i=0; i<n_dogs; ++i){
		odds[i] = total_sum / (total_bets[i] * odds[i]);
	}
	all_bets.push_back(pb);
}
	
void Betting_company::recieve(double amount){
	balance += amount;
}


void Betting_company::initialize(){
	probs.clear();
	odds.clear();
	all_bets.clear();
	total_bets.clear();
	for (int i=0; i<n_dogs; ++i){
		double p = 1.0/n_dogs;
		probs.push_back(p);
		odds.push_back(0.99*(1/p));
		total_bets.insert({i, total_start});
	}
	total_sum = n_dogs * total_start;
}

void Betting_company::pay_out(){
	int winning_dog = Custom_random::get_random(5);
	cout << "The winning dog is: " << winning_dog << endl;
	for (Player_bet& pb: all_bets){
		if (pb.won(winning_dog)){
			pb.process(*this);
		}
	}
}

void Betting_company::pay(double amount){
	balance -= amount;
}

ostream& operator<<(ostream& os, const Betting_company& bc){
	os << "Betting Company Balance: " << bc.balance << "\nOdds ";
	for (int i=0; i<bc.n_dogs; ++i){
		os << bc.odds[i] << "\t";	
	} 
	return os;
}
