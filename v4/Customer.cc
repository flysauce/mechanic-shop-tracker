#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#include "Customer.h"


int Customer::nextId = 1000;

Customer::Customer(string fname, string lname, string add, string pnum) : Person(fname, lname, add, pnum), id(Customer::nextId++) {}

int           Customer::getId() const           { return id; }
int           Customer::getNumVehicles() const  { return vehicles.getSize(); }
VehicleList&  Customer::getVehicles()           { return vehicles; }

void Customer::operator += (Vehicle* v){
	vehicles += (v);
}

//overriding the cout operator to print a Customer object
ostream& operator << (ostream& output, Customer& c){
	ostringstream name;
    name << c.getFname() << " " << c.getLname();

    output << "Customer ID " << c.getId() << endl << endl
           << "    Name: " << setw(40) << name.str() << endl 
           << "    Address: " << setw(37) << c.getAddress() << endl
           << "    Phone Number: " << setw(32) <<  c.getPhoneNumber() << endl;
    
    if (c.getNumVehicles() > 0) {
        output << endl << "    " << c.getNumVehicles() 
                  << " vehicle(s): " << endl << endl;

        output << c.getVehicles() << endl;
    }
           
	return output;
}
