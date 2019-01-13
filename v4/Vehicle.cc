#include "Vehicle.h"
#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>

Vehicle::Vehicle(string ma, string mo, string col, int y, int m) { 
    make = ma;
    model = mo;
    colour = col;
    year = y;
    mileage = m;
}

string  Vehicle::getMake() const     { return make; }
string  Vehicle::getModel() const    { return model; }
string  Vehicle::getColour() const   { return colour; }
int     Vehicle::getYear() const     { return year; }
int     Vehicle::getMilage() const   { return mileage; }

//overloading the cout operator to easily print a Vehicle object
ostream& operator << (ostream& output, Vehicle& v){
	ostringstream make_model;
	make_model << v.getMake() << " " << v.getModel();
	output << "\t" << setw(7) << v.getColour() << " " 
                   << v.getYear() << " " << setw(17) << make_model.str() << " (" 
                   << v.getMilage() << "km)";
	return output;
}

//overloading the < operator for easy Vehicle comparison based on vehicle year
bool Vehicle::operator < (Vehicle& v) const{
	return (year < v.year);
}

//overloading the > operator for easy Vehicle comparison based on vehicle year
bool Vehicle::operator > (Vehicle& v) const{
	return (year > v.year);
}
