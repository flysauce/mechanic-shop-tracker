#include "Truck.h"
#include <string.h>
#include <stdio.h>

Truck::Truck(string ma, string mo, string col, int y, int m, int a)
:Vehicle(ma, mo, col, y, m), axles(a) {
}

//overriden toString function for vehicle derived classes, to allow for easy derived class printing
string Truck::toString() {
	string s = "TRUCK:         ";
	string s1 = ", ";
	string s2 = " axle(s)";
	stringstream ss;
	ss << this->axles;
	s.append(s1);
	s.append(ss.str());
	s.append(s2);
	return s;
}
