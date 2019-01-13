#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;
#include <string>

#include "VehicleList.h"

VehicleList::VehicleList() : head(0) { }


VehicleList::~VehicleList()
{
  Node *currNode, *nextNode;

  currNode = head;

  while (currNode != 0) {
    nextNode = currNode->next;
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}

int VehicleList::getSize() const {
  Node *currNode = head;
  int size = 0;

  while (currNode != 0) {
    currNode = currNode->next;
    size++;
  }
  
  return size;
}

//overloading the += operator to now add a Vehicle objects from the VehicleList
void VehicleList::operator += (Vehicle* newVeh){
  Node *currNode, *prevNode;
  Node* newNode = new Node;
  newNode->data = newVeh;
  newNode->next = 0;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    if ((*newNode->data) > (*currNode->data))
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == 0) {
    head = newNode;
  }
  else {
    prevNode->next = newNode;
  }

  newNode->next = currNode;
}

//overloading the -= operator to now remove a Vehicle objects from the VehicleList
void VehicleList::operator -= (Vehicle* v){
  Node *currNode, *prevNode;

  prevNode = 0;
  currNode = head;

  while (currNode != 0) {
    if (currNode->data == v)
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (currNode == 0) 
    return;

  if (prevNode == 0) {
    head = currNode->next;
  }
  else {
    prevNode->next = currNode->next;
  }
  delete currNode->data;
  delete currNode;
}

//overloading the [] operator to be able to treated the VehicleList with array notation
Vehicle* VehicleList::operator [] (int i){
	if(i < 0 || i > getSize() - 1){
		return NULL;
	}
	int count = 0;
	Node* curNode = head;
	while(curNode != 0){
		if(count == i){
			return curNode->data;
		}
		count++;
		curNode = curNode->next;
	}
}

//overloarding the cout operator to be able to easily print a VehicleList
ostream& operator << (ostream& output, VehicleList& vl){
  for(int i = 0; i < vl.getSize(); i++){
  	output << (*vl[i]) << endl;
  }
  
  return output;
}
