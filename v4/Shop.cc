#include "Shop.h"
#include "defs.h"

Shop::Shop(){
	mechSize = 0;
}

Shop::~Shop(){
	for(int i = 0; i < mechSize; i++){
		delete(mechanics[i]);
	}
}

Customer* Shop::getCustomer(int i)  { return customers.get(i); }

CustomerList& Shop::getCustomers() { return customers; }

//overloading the += operator to easily add a Customer to the shop CustomerList
void Shop::operator += (Customer* c){
	customers += (c);
}

//overloading the -= operator to easily remove a Customer to the shop CustomerList
void Shop::operator -= (Customer* c){
	customers -= (c);
}

//overloading the += operator to easily add a Customer to the shop Mechanic array
void Shop::operator += (Mechanic* m){
	if(mechSize < MAX_MECHANICS){
		mechanics[mechSize] = m;
		mechSize++;
	}
}

int Shop::getMechSize() { return mechSize; }

Mechanic** Shop::getMechanics() { return mechanics; }
