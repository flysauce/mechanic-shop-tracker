#include "Vehicle.h"

Vehicle::Vehicle(string ma, string mo, string col, int y, int m)
:make(ma), model(mo), colour(col), year(y), mileage(m){}

Vehicle::~Vehicle(){}

string  Vehicle::getMake() const      { return make; }
string  Vehicle::getModel() const     { return model; }
string  Vehicle::getColour() const    { return colour; }
int     Vehicle::getYear() const      { return year; }
int     Vehicle::getMileage() const    { return mileage; }

