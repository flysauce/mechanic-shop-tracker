#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "CustomerList.h"

CustomerList::CustomerList() : head(0) { }


CustomerList::~CustomerList()
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

Customer* CustomerList::get(int id) 
{
  Node *currNode = head;

  while (currNode != 0) {
    if(currNode->data->getId() == id) {
      return currNode->data;
    }
    currNode = currNode->next;
  }

  return 0;
}

int CustomerList::getSize() const {
  Node *currNode = head;
  int size = 0;

  while (currNode != 0) {
    currNode = currNode->next;
    size++;
  }
  
  return size;
}

//overloading the += operator to now add a Customer objects from the CustomerList
void CustomerList::operator += (Customer* newCust){
  Node *currNode, *prevNode;
  Node* newNode = new Node;
  newNode->data = newCust;
  newNode->next = 0;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    if ((*newNode->data) < (*currNode->data))
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

//overloading the -= operator to now remove a Customer objects from the CustomerList
void CustomerList::operator -= (Customer* c){
  Node *currNode, *prevNode;

  prevNode = 0;
  currNode = head;

  while (currNode != 0) {
    if (currNode->data == c)
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

//overloading the [] operator so we can treat the linked list with array notation
Customer* CustomerList::operator [] (int i){
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

//overloading the cout opperator to easily print a CustomerList
ostream& operator << (ostream& output, CustomerList& cl){
  for(int i = 0; i < cl.getSize(); i++){
  	output << (*cl[i]) << endl;
  }
  
  return output;
}
