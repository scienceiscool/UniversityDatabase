#include <string>
#include <iostream>

using namespace std;

#ifndef CAR_H
#define CAR_H

class Car{
public:
	Car();
	void setName(string);
	void setYear(int);
	string getName();
	int getYear();
private:
	string name;
	int year;
};

#endif
