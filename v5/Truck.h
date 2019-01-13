#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck: public Vehicle{
	public:
		Truck(string, string, string, int, int, int);
		virtual string toString();
	private:
		int axles;
};

#endif
