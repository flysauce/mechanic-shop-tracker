#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"

class Motorcycle: public Vehicle{
	public:
		Motorcycle(string, string, string, int, int, bool);
		virtual string toString();
	private:
		bool sideCar;
};

#endif
