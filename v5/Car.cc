#include "Car.h"
#include <string.h>
#include <stdio.h>

Car::Car(string ma, string mo, string col, int y, int m)
:Vehicle(ma, mo, col, y, m) {
}

//overriden toString function for vehicle derived classes, to allow for easy derived class printing
string Car::toString() {
	string s = "CAR:           ";
	return s;
}
