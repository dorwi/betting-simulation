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
	cout << "Initializing" << endl;

	vector<Player> players;
	for(int i=0; i<100; ++i){
		Player p(i);
		players.push_back(p);
	}
	Betting_company betinc;

	for (vector<Player>::iterator it = players.begin(); it!=players.end(); ++it){
		it->pay(&betinc, 1.0);
	}

	cout << betinc << endl;
	cout << players[0] << endl;
	return 0;
}