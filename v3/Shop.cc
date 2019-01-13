#include "Shop.h"
#include "defs.h"
#include <iostream>
#include <string>

void Shop::addCustomer(Customer* c) { customers.add(c); }

Customer* Shop::getCustomer(int i) { return (customers.get(i)); } 

CustomerList& Shop::getCustomers() { return customers; }

/*
purpose: to create a new customer during runtime
input: none
output: creates a new customer
return: none
*/
void Shop::createCustomer(){
	string fname, lname, add, phone;
	cout << "\nCUSTOMER CREATION\n\nFirst name: ";
	getline(cin, fname);
	cout << "\nLast name: ";
	getline(cin, lname);
	cout << "\nAddress: ";
	getline(cin, add);
	cout << "\nPhone number: ";
	getline(cin, phone);
	Customer* newCustomer = new Customer(fname, lname, add, phone);
	customers.add(newCustomer);
}

/*
purpose: to create a new vehicle during runtime and add it to a customer via there id
input: none
output: creates a new vehicle
return: none
*/
void Shop::createVehicle(){
	int id, year, mileage;
	string make, model, colour;
	Customer* customer = NULL;
	cout << "\nCUSTOMER SEARCH\n\nCustomer ID: ";
	cin >> id;
	customer = customers.get(id);
	if(customer != NULL){
		cout << "\nVEHICLE CREATION\n\nMake: ";
		cin.ignore();
		getline(cin, make);
		cout << "\nModel: ";
		getline(cin, model);
		cout << "\nColour: ";
		getline(cin, colour);
		cout << "\nYear: ";
		cin >> year;
		cout << "\nMileage: ";
		cin >> mileage;
		Vehicle* newVehicle = new Vehicle(make, model, colour, year, mileage);
		customer->addVehicle(newVehicle);
	}
	else{
		cout << "\nInvalid customer\n";
	}
}
