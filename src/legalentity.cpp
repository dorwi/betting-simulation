#include "legalentity.h"

void Legal_entity::pay(double amount){
	b -= amount;
}

void Legal_entity::recieve(double amount){
	b += amount;
}