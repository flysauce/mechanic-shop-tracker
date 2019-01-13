#include "Motorcycle.h"
#include <string.h>
#include <stdio.h>

Motorcycle::Motorcycle(string ma, string mo, string col, int y, int m, bool b)
:Vehicle(ma, mo, col, y, m), sideCar(b) {
}

//overriden toString function for vehicle derived classes, to allow for easy derived class printing
string Motorcycle::toString() {
	string s = "MOTORCYCLE:    ";
	string sc;
	if(this->sideCar == true) {
		sc = ", has sidecar";
	}
	else {
		sc = ", doesn't have sidecar";
	}
	s.append(sc);
	return s;
}
