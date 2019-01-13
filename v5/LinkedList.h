#ifndef LINKEDLIST_H
#define LINKEDLIST_H
using namespace std;

template <class T>
class LinkedList {	
	template <typename U>
	friend ostream& operator << (ostream&, LinkedList<U>&);
	
	class Node{
		friend class LinkedList<T>;
		public:
			T* data;
			Node* next;
	};
	
	public:
		LinkedList();
		~LinkedList();
		int getSize() const;
		LinkedList<T>& operator += (T*);
		LinkedList<T>& operator -= (T*);
		T* operator [] (int);
	private:
		Node* head;
};

template <class T>
LinkedList<T>::LinkedList(): head(0) {}

template <class T>
LinkedList<T>::~LinkedList() {
	Node *cur = head, *nex = 0;
	while(cur != 0) {
		nex = cur->next;
		delete cur->data;
		delete cur;
		cur = nex;
	}
}

//returns the number of nodes in the list
template <class T>
int LinkedList<T>::getSize() const {
	Node* cur = head;
	int n = 0;
	while(cur != 0) {
		cur = cur->next;
		n++;
	}
	return n;
}

//overdie the += operator to add the object to the list and returns the list
template <class T>
LinkedList<T>& LinkedList<T>::operator += (T* t) {
	Node *cur = head, *pre = 0;
	Node* node = new Node();
	node->data = t;
	node->next = 0;
	while(cur != 0) {
		if(*(node->data) < *(cur->data)) {
			break;
		}
		pre = cur;
		cur = cur->next;
	}
	if(pre == 0) {
		head = node;
	}
	else {
		pre->next = node;
	}
	node->next = cur;
	return *this;
}

//overdie the -= operator to remove the object from the list and returns the list
template <class T>
LinkedList<T>& LinkedList<T>::operator -= (T* t) {
	Node *cur = head, *pre = 0;
	while(cur != 0) {
		if(t == cur->data) {
			break;
		}
		pre = cur;
		cur = cur->next;
	}
	if(cur == 0){
		return *this;
	}
	if(pre == 0) {
		head = cur->next;
	}
	else {
		pre->next = cur->next;
	}
	delete cur;
	return *this;
}

//override the [] operator
template <class T>
T* LinkedList<T>::operator [] (int i) {
	if( i < 0 || i > (getSize() - 1)) {
		return 0;
	}
	else {
		Node* cur = head;
		for(int j = 0; j < i; j++) {
			cur = cur->next;
		}
		return cur->data;
	}
}

//override the << operator
template <class T>
ostream& operator << (ostream& o, LinkedList<T>& t) {
	for(int i = 0; i < t.getSize(); i++) {
		o << (*(t[i]));
	}
	return o;
}

#endif
