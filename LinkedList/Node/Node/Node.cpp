/*
	Blood, William

	February 10, 2020

	CS A250
	Lab 3
*/

#include "Node.h"
#include <iostream>

void NodeList::appendToHead(const string& newData) {
	Node* newNode = new Node(newData);

	if (head == nullptr) head = newNode;
	else {
		newNode->setNext(head);
		head = newNode;
	}
	
	count++;
}

void NodeList::printList() {
	Node* traversalPtr = head;

	cout << "****************** Key Chain ******************\n\n";

	while (traversalPtr != nullptr) {
		cout << "Username: [xxxxxxxxx]\n";
		cout << "Password: ["
			<< traversalPtr->getData() << "]\n\n";

		traversalPtr = traversalPtr->getNext();
	}
}

void NodeList::destroyList() {
	// use a while loop
	Node* temp = head;

	while (temp != nullptr) {
		head = head->getNext();
		delete temp;
		temp = head;
	}

	count = 0; // Do not count-- for each deleted node
}

void NodeList::deleteElem(const string& elem) {
	if (elem.empty()) cerr << "List is empty" << endl;
	else if (count == 1) { cerr << "There is 1 node in the list" << endl; }
	else if (count == 2) { cout << "this is the 'middle'" << endl; }
}

//void NodeList::printList() {
//	Node* traversalPtr = head;
//
//	while (traversalPtr != 0) {
//		cout << *traversalPtr << endl;
//	}
//}

// Don't forget to define destructor!
Node::~Node(){
	// destroyList()
}