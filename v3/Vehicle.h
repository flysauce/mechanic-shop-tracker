#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle {

    public:
        Vehicle(string, string, string, int, int);
    	~Vehicle();
        string getMake() const;
        string getModel() const;
        string getColour() const;
        int getYear() const;
        int getMileage() const;

    private:
        string make;
        string model;
        string colour;
        int year;
        int mileage;
};

#endif
