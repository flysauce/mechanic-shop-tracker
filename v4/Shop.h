#ifndef SHOP_H
#define SHOP_H

#include "Customer.h"
#include "CustomerList.h"
#include "Mechanic.h"
#include "defs.h"

class Shop{

    public:
    	Shop();
    	~Shop();
        Customer* getCustomer(int);
        CustomerList& getCustomers();
        int getMechSize();
        Mechanic** getMechanics();
        
        void operator += (Customer*);
        void operator -= (Customer*);
        void operator += (Mechanic*);

    private:
        CustomerList customers;
		Mechanic* mechanics[MAX_MECHANICS];
		int mechSize;
};

#endif
