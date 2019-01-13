#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car: public Vehicle{
	public:
		Car(string, string, string, int, int);
		virtual string toString();
};

#endif
