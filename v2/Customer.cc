#include <iostream>
using namespace std;
#include "Customer.h"



//static variable(s)
int Customer::nextId = 1000;



//constructor(s)
Customer::Customer(string fName, string lName, string add, string phone)
:id(nextId++), firstName(fName), lastName(lName), address(add), phoneNumber(phone), vehicles(){}



//getter(s)
int Customer::getId(){return id;}
string Customer::getFname(){return firstName;}
string Customer::getLname(){return lastName;}
string Customer::getAddress(){return address;}
string Customer::getPhoneNumber(){return phoneNumber;}
int Customer::getNumVehicles(){return vehicles.getSize();}
VehicleArray& Customer::getVehicles(){return vehicles;}



/*
Purpose: adds vehicle to customer member variable vehicleArray
Input: vehcile pointer
Output: none
Return: 1 if add was successful
		0 if add was unsuccessful
Side effects: adds a vehicle to the vehicleArray(vehicle) in customer
*/
int Customer::addVehicle(Vehicle* vehicle){
	return vehicles.add(vehicle);
}
