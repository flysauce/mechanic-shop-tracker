#include "VehicleArray.h"
#include "Vehicle.h"
#include "defs.h"



//constructor(s)
VehicleArray::VehicleArray()
:elements(), size(0){}



//destructor(s)
VehicleArray::~VehicleArray(){
	for(int i = 0; i < size; i++){
		delete elements[i];
	}
}



//getter(s)
int VehicleArray::getSize(){return size;}



/*
Purpose: add vehicle to vehicleArray if there is space
Input: vehicle pointer
Output: none
Return: 1 if add was successful
		0 if add was unsuccessful
Side effects: changes to vehcileArray
*/
int VehicleArray::add(Vehicle* vehicle){
	if(size < MAX_VEHICLES){
		elements[size] = vehicle;
		size++;
		return C_OK;
	}
	else{
		return C_NOK;
	}
}



/*
Purpose: get vehicle at specific index from vehicleArray
Input: the index of the vehicle
Output: none
Return: vehicle, a vehicle is at the index
		0 if no vehicles exist in the list or the index inputted is out of bounds
Side effects: none
*/
Vehicle* VehicleArray::get(int i){
	if(i >= 0 && i <= size && size != 0){
		return elements[i];
	}
	else{
		return 0;
	}
}
