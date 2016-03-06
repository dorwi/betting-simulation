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
		Player* p = new Player(i);
		players.push_back(p);
	}
	for(int i=0; i<10; ++i){
		Agressive_player* p = new Agressive_player(i);
		players.push_back(p);
	}
	Betting_company betinc;


	for (vector<Player*>::iterator it = players.begin(); it!=players.end(); ++it){
		(*it)->pay(&betinc, 1.0);
	}

	cout << betinc << endl;
	for (vector<Player*>::iterator it = players.begin(); it!=players.end(); ++it){
		cout << *it << endl;
	}

	cout << "------------------------------ Betting -----------------------------------" << endl;
	for (int round =0; round<100; ++round){
		for (vector<Player*>::iterator it = players.begin(); it!=players.end(); ++it){
			(*it)->bet(&betinc);
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