#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

#include "View.h"
#include "CustomerList.h"
#include "Customer.h"
#include "VehicleList.h"
#include "Vehicle.h"


void View::mainMenu(int& choice) {
    string str;

    choice = -1;

    cout<< "\n\n\n         **** Toby's Auto Mechanic Information Management System ****\n\n";
    cout<< "                                 MAIN MENU\n\n";
    cout<< "        1. Print Customer Database\n\n";
    cout<< "	2. Add Customer\n\n";
    cout<< "	3. Add Vehicle\n\n";
    cout<< "        0. Exit\n\n";

    while (choice < 0 || choice > 3) {
        cout << "Enter your selection:  ";
        choice = readInt();
    }

    if (choice == 0) { cout << endl; }
}


void View::printCustomers(CustomerList& arr) {
		string output = "";
		arr.toString(output);
		cout << output << endl;
}

void View::pause() {
    string str;

    cout << "Press enter to continue...";
    getline(cin, str);
}

int View::readInt() {
    string str;
    int    num;

    getline(cin, str);
    stringstream ss(str);
    ss >> num;

    return num;
}
