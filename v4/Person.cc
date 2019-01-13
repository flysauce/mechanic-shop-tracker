using namespace std;
#include "Person.h"

Person::Person(string fname, string lname, string add, string pnum){ 
    firstName   = fname;
    lastName    = lname;
    address     = add;
    phoneNumber = pnum;
}

string        Person::getFname() const        { return firstName; }
string        Person::getLname() const        { return lastName; }
string        Person::getAddress() const      { return address; }
string        Person::getPhoneNumber() const  { return phoneNumber; }

//overloading the < operator for easy Person comparison based on last name
bool Person::operator < (Person& p){
	return (lastName < p.lastName);
}

//overloading the > operator for easy Person comparison based on last name
bool Person::operator > (Person& p){
	return (lastName > p.lastName);
}
