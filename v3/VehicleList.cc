#include "VehicleList.h"
#include <string>
#include <stdio.h>
using namespace std;

VehicleList::VehicleList()
:head(0){}

VehicleList::~VehicleList(){
	Node* curNode = head;
	Node* nexNode = 0;
	while(curNode != 0){
		nexNode = curNode->next;
		delete curNode->data;
		delete curNode;
		curNode = nexNode;
	}
}

/*
purpose: to add a vehicle object to the linked list in descending order by year
input: pointer to a vehicle object
output: puts the vehicle pointer into a node and adds the node to the linked list
return: none
*/
void VehicleList::add(Vehicle* vehicle){
    Node* curNode = head;
    Node* preNode = 0;
    Node* newNode = new Node;
    newNode->data = vehicle;
    newNode->next = 0;
    while(curNode != 0){
        if(curNode->data->getYear() < newNode->data->getYear()){
            break;
        }
        preNode = curNode;
        curNode = curNode->next;
    }
    if(preNode == 0){
        head = newNode;
    }
    else {
        preNode->next = newNode;
    }
    newNode->next = curNode;
}

/*
purpose: searches and returns vehicle data from linked list via vehicle list index
input: int index
output: none
return: pointer to a vehicle at index
*/
Vehicle* VehicleList::get(int index){
	Node* curNode = head;
	for(int i = 0; i < getSize(); i++){
		if(i == index){
			return curNode->data;
		}
		curNode = curNode->next;
	}
	return NULL;
}

/*
purpose: count the size of the nodes in the linked list
input: none
output: none
return: int representing the number of nodes in the list
*/
int VehicleList::getSize(){
	int size = 0;
	Node* node = head;
	while(node != 0){
		size++;
		node = node->next;
	}
	return size;
}

/*
purpose: put all of the vehicles data into a string
input: a reference to a string
output: add all of the vehicle data to the input string reference in a human readable fashion
return: none
*/
void VehicleList::toString(string& outStr){
	Node* curNode = head;
	char s[50];
	outStr += "	VEHICLES:\n";
	for(int i = 0; i < getSize(); i++){
		outStr += "	  Make: ";
		outStr += curNode->data->getMake();
		outStr += "  Model: ";
		outStr += curNode->data->getModel();
		outStr += "  Colour: ";
		outStr += curNode->data->getColour();
		outStr += "  Year: ";
		sprintf(s, "%d", curNode->data->getYear());
		outStr += s;	
		outStr += "  Mileage: ";
		sprintf(s, "%d", curNode->data->getMileage());
		outStr += s;
		outStr += "\n";
		curNode = curNode->next;
	}
}
