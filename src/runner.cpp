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
	cout << "---------------------------- Initializing------------------------------" << endl;

	vector<Player*> players;
	for(int i=0; i<10; ++i){
		players.push_back(new Player(i));
	}
	for(int i=0; i<10; ++i){
		players.push_back(new Agressive_player(i));
	}
	for(int i=0; i<10; ++i){
		players.push_back(new VIP_player(i));
	}
	for(int i=0; i<10; ++i){
		players.push_back(new Agressive_VIP_player(i));
	}

	Betting_company betinc;

	cout << betinc << endl;
	for (vector<Player*>::iterator it = players.begin(); it!=players.end(); ++it){
		cout << *it << endl;
	}

	cout << "------------------------------ Betting -----------------------------------" << endl;
	for (int round =0; round<100; ++round){
		for (vector<Player*>::iterator it = players.begin(); it!=players.end(); ++it){
			if ((*it)->participate(&betinc)){
				(*it)->bet(&betinc);				
			}
		}
		betinc.pay_out();
		betinc.initialize();
	}
	cout << "------------------------------- After betting rounds -----------------------" << endl;

	for (vector<Player*>::iterator it = players.begin(); it!=players.end(); ++it){
		cout << (*it) << endl;
	}

	for (vector<Player*>::iterator it = players.begin(); it!=players.end(); ++it){
		delete *it;
	}	

	return 0;
}