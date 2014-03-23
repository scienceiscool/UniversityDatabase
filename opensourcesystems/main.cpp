#include <iostream>
#include <string>
#include "car.h"

using namespace std;

void getCarData(string carName, int carYear, Car & myCar);
//Purpose: Stores the data into the Car object
//Preconditions: Object is declared and initialized
//Postconditions: Object is filled with data

void outputCarData(Car & myCar);
//Purpose: Outputs the Car data
//Preconditions: Object is filled with data
//Postconditions: Car data has been printed to output stream

int main(){
	Car myCar;
	string name;
	int year;
	
	cout << "Enter the car name: ";
	cin  >> name;
	cout << endl;
	cout << "Enter the car year: ";
	cin  >> year;
	cout << endl;
	
	getCarData(name, year, myCar);
	outputCarData(myCar);

	return 0;
}
