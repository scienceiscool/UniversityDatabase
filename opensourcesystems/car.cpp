#include <iostream>
#include <string>
#include "car.h"

using namespace std;

Car::Car(){
	name = " ";
	year = 0;
}

void Car::setName(string user_name){
	name = user_name;
}

void Car::setYear(int user_year){
	year = user_year;
}

string Car::getName(){
	return name;
}

int Car::getYear(){
	return year;
}
