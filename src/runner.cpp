#include <iostream>
#include <ctime>
#include <cstdlib>
#include "customrandom.h"


using std::cout; using std::endl;

int main(){
	std::srand(std::time(0));
	cout << "Who let the dogs out?" << endl;
	cout << Custom_random::get_random(5) << endl;
	return 0;
}