#include "CustomerArray.h"
#include "Customer.h"
#include "defs.h"



//constructor(s)
CustomerArray::CustomerArray()
:elements(), size(0){}



//destructor(s)
CustomerArray::~CustomerArray(){
	for(int i = 0; i < size; i++){
		delete elements[i];
	}
}



//getter(s)
int CustomerArray::getSize(){return size;}



/*
Purpose: add customer to customerArray
Input: customer pointer
Output:
Return: 1 if add was successful
		0 if add was unsuccessful
Side effects: changes customerArray
*/
int CustomerArray::add(Customer* customer){
	if(size < MAX_CUSTOMERS){
		elements[size] = customer;
		size++;
		return C_OK;
	}
	else{
		return C_NOK;
	}
}



/*
Purpose: get customer at specific index from customerArray
Input: the index of the customer
Output: none
Return: customer, a customer is at the index
		0 if no customer exist in the list or the index inputted is out of bounds
Side effects: none
*/
Customer* CustomerArray::get(int i){
	if(i >= 0 && i <= size && size != 0){
		return elements[i];
	}
	else{
		return 0;
	}
}
