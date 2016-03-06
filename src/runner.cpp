#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

#include "customrandom.h"
#include "player.h"
#include "bettingcompany.h"

using std::cout; using std::endl;
using std::vector;

int main(){
	cout << "---------------------- Initializing------------------------------" << endl;

	vector<Player> players;
	for(int i=0; i<10; ++i){
		Player p(i);
		players.push_back(p);
	}
	Betting_company betinc;


	for (vector<Player>::iterator it = players.begin(); it!=players.end(); ++it){
		it->pay(&betinc, 1.0);
	}

	cout << betinc << endl;
	cout << players[0] << endl;

	cout << "---------------------- Betting -----------------------------------" << endl;
	for (int round =0; round<30; ++round){
		for (vector<Player>::iterator it = players.begin(); it!=players.end(); ++it){
			it->bet(&betinc);
		}
		betinc.pay_out();
		betinc.initialize();
	}

	cout << betinc << endl;
	cout << players[0] << endl;

	cout << "....................... Pay out ----------------------------------" << endl;

	betinc.pay_out();
	cout << betinc << endl;
	for (int i=0; i<5; ++i){
		cout << players[i] << endl;		
	}

	return 0;
}