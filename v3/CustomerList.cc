#include <string>
#include "CustomerList.h"
#include <stdio.h>
#include <iostream>
using namespace std;

CustomerList::CustomerList()
:head(0){}

CustomerList::~CustomerList(){
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
purpose: to add a customer object to the linked list in alphabetical order by last name
input: pointer to a customer object
output: puts the customer pointer into a node and adds the node to the linked list
return: none
*/
void CustomerList::add(Customer* customer){
	Node* curNode = head;
	Node* preNode = 0;
    Node* newNode = new Node;
    newNode->data = customer;
    newNode->next = 0;
    while(curNode != 0){
        if(curNode->data->getLname() > newNode->data->getLname()){
            break;
        }
        preNode = curNode;
        curNode = curNode->next;
    }
    if(preNode == 0){
        head = newNode;
    }
    else{
        preNode->next = newNode;
    }
    newNode->next = curNode;
}

/*
purpose: searches and returns customer data from linked list via customer id
input: customer id integer
output: none
return: pointer to a customer with matching id integer
*/
Customer* CustomerList::get(int id){
	Node* node = head;
	for(int i = 0; i < getSize(); i++){
		if(node->data->getId() == id){
			return node->data;
		}
		node = node->next;
	}
	return NULL;
}

/*
purpose: count the size of the nodes in the linked list
input: none
output: none
return: int representing the number of nodes in the list
*/
int CustomerList::getSize(){
	int size = 0;
	Node* node = head;
	while(node != 0){
		size++;
		node = node->next;
	}
		return size;
}

/*
purpose: put all of the customer data into a string
input: a reference to a string
output: add all of the customer data to the input string reference in a human readable fashion
return: none
*/
void CustomerList::toString(string& outStr){
	Node* curNode = head;
	char s[50];
	cout << endl << "CUSTOMERS: " << endl << endl;
	for(int i = 0; i < getSize(); i++){
		outStr += "Customer ID: ";
		sprintf(s, "%d", curNode->data->getId());
		outStr += s;
		outStr += "\n";
		outStr += "	Name: ";
		outStr += curNode->data->getFname();
		outStr += " ";
		outStr += curNode->data->getLname();
		outStr += "\n";
		outStr += "	Address: ";
		outStr += curNode->data->getAddress();
		outStr += "\n";
		outStr += "	Phone Number: ";
		outStr += curNode->data->getPhoneNumber();
		outStr += "\n";
		if(curNode->data->getNumVehicles() != 0){
			curNode->data->getVehicles().toString(outStr);
		}
		curNode = curNode->next;
		outStr += "\n\n";
	}
}
