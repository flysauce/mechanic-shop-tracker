#include "Vehicle.h"



//constructor(s)
Vehicle::Vehicle(string make, string model, string colour, int year, int mileage)
:make(make), model(model), colour(colour), year(year), mileage(mileage){}
	
	

//getter(s)
string Vehicle::getMake(){return make;}
string Vehicle::getModel(){return model;}
string Vehicle::getColour(){return colour;}
int Vehicle::getYear(){return year;}
int Vehicle::getMilage(){return mileage;}
