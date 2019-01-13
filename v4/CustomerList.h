#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include "Customer.h"


class CustomerList
{
  class Node
  {
    friend class CustomerList;
    private:
      Customer* data;
      Node*    next;
  };
  
  friend ostream& operator << (ostream&, CustomerList&);

  public:
    CustomerList();
    ~CustomerList();
    int getSize() const;
    Customer* get(int);
    
    void operator += (Customer*);
    void operator -= (Customer*);
    Customer* operator [] (int);
    
  private:
    Node* head;
};

#endif
