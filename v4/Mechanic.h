#ifndef MECHANIC_H
#define MECHANIC_H

#include <string>
#include "Person.h"
using namespace std;

class Mechanic : public Person{

	friend ostream& operator << (ostream&, Mechanic&);

	public:
		Mechanic(string = "", string = "", string = "", string = "", int = 0);
		int getSalary() const;
		int getId() const;
	
	private:
		static int nextId;
		const int id;
		int salary;
};

#endif
