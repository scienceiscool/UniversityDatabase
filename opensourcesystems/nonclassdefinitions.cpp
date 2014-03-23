#include <iostream>
#include <string>
#include "car.h"

using namespace std;

void getCarData(string carName, int carYear, Car & myCar){
	myCar.setName(carName);
	myCar.setYear(carYear);
}

void outputCarData(Car & myCar){
	cout << "Name: " << myCar.getName() << endl << "Year: " << myCar.getYear();
}
