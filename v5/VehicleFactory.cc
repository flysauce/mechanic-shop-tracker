#include "VehicleFactory.h"

//creates a derived car class
Vehicle* VehicleFactory::create(string a, string b, string c, int d, int e){
	Car* t = new Car(a, b, c, d, e);
	return t;
}

//creates a derived truck class
Vehicle* VehicleFactory::create(string a, string b, string c, int d, int e, int f){
	Truck* t = new Truck(a, b, c, d, e, f);
	return t;
}

//creates a derived motorcycle class
Vehicle* VehicleFactory::create(string a, string b, string c, int d, int e, bool f){
	Motorcycle* t = new Motorcycle(a, b, c, d, e, f);
	return t;
}
