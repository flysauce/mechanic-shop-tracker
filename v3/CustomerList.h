#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include "Customer.h"

class CustomerList{

	class Node{
		friend class CustomerList;
		private:
			Customer* data;
			Node* next;
	};
	
    public:
        CustomerList();
        ~CustomerList();
        void add(Customer*);
        Customer* get(int);
        int getSize();
        void toString(string& outStr);
        
    private:
        Node* head;
};

#endif
