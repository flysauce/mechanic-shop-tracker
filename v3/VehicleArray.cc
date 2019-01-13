#include "VehicleArray.h"
#include "Vehicle.h"
#include "defs.h"

VehicleArray::VehicleArray() { size = 0; }
VehicleArray::~VehicleArray() { 
    for(int i = 0; i < size; i++) {
        delete elements[i];
    }
}

int VehicleArray::getSize()   { return size; }

int VehicleArray::add(Vehicle* v) {
    if (size == MAX_VEHICLES) {
        return C_NOK;
    }
    
    elements[size] = v;
    size++;
    return C_OK;
}

Vehicle* VehicleArray::get(int i) {
    if ((i >= size) || (i < 0)) {
        return 0;
    }

    return elements[i];
}


