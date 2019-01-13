#ifndef VIEW_H
#define VIEW_H

#include "CustomerList.h"
#include "Mechanic.h"

class View {

    public:
        void mainMenu(int&);
        void printCustomers(CustomerList&) const;
        void pause() const;
        void promptUserInfo(string&, string&, string&, string&);
        void promptUserId(int&);
        void displayInvalid();
        void promptVehicleInfo(string&, string&, string&, int&, int&);
        void promptVehicleNumber(int&);
        void printMechanics(Mechanic**, int) const;
    private:
        int readInt() const;
};

#endif
