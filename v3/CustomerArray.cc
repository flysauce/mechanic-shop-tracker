#include "CustomerArray.h"
#include "Customer.h"
#include "defs.h"

CustomerArray::CustomerArray() { size = 0; }
CustomerArray::~CustomerArray() { 
    for(int i = 0; i < size; i++) {
        delete elements[i];
    }
}

int CustomerArray::getSize()   { return size; }

int CustomerArray::add(Customer* c) {
    if (size == MAX_CUSTOMERS) {
        return C_NOK;
    }
    
    elements[size] = c;
    size++;
    return C_OK;
}

Customer* CustomerArray::get(int i) {
    if ((i >= size) || (i < 0)) {
        return 0;
    }

    return elements[i];
}


