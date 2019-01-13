#ifndef VEHICLELIST_H
#define VEHICLELIST_H

#include "Vehicle.h"


class VehicleList
{
  class Node
  {
    friend class VehicleList;
    private:
      Vehicle* data;
      Node*    next;
  };
  
  friend ostream& operator << (ostream&, VehicleList&);

  public:
    VehicleList();
    ~VehicleList();
    int getSize() const;
    
    void operator += (Vehicle*);
    void operator -= (Vehicle*);
    Vehicle* operator [] (int);
    
  private:
    Node* head;
};

#endif
