#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#include "Mechanic.h"

int Mechanic::nextId = 5000;

Mechanic::Mechanic(string fname, string lname, string add, string pnum, int sal) : Person(fname, lname, add, pnum), id(Mechanic::nextId++), salary(sal) {}

//overloading the cout operator to easily print a Mechanic object
ostream& operator << (ostream& output, Mechanic& m){
	ostringstream name;
    name << m.getFname() << " " << m.getLname();

    output << "Customer ID " << m.getId() << endl << endl
           << "    Name: " << setw(40) << name.str() << endl 
           << "    Address: " << setw(37) << m.getAddress() << endl
           << "    Phone Number: " << setw(32) <<  m.getPhoneNumber() << endl
           << "    Salary: " << setw(38) << m.getSalary() << endl;
           
	return output;
}

int Mechanic::getSalary() const{ return salary; }
int Mechanic::getId() const { return id; }
