#ifndef VIEW_H
#define VIEW_H

#include "CustomerList.h"

class View {

    public:
        void mainMenu(int&);
        void printCustomers(CustomerList&);
        void pause();

    private:
        int readInt();
};

#endif
