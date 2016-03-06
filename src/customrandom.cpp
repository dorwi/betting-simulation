#include <cstdlib>
#include <stdexcept>

#include "customrandom.h"

/* returns a random number between [0,k) */
int Custom_random::get_random(int k){
	if (k <= 0 || k>RAND_MAX)
		throw std::domain_error("argument to get_random is out of the range");

	const int bucket_size = RAND_MAX / k;
	int r;
	do{
		r = rand() / bucket_size;
	} while (r >= k);

	return r;
}


double Custom_random::get_random_double(double a, double b){
	int r = rand();
	return a + (b-a)*r/RAND_MAX;
}

double Custom_random::get_random_double(double a){
	return Custom_random::get_random_double(0,a);
}