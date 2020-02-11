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

//void NodeList::printList() {
//	Node* traversalPtr = head;
//
//	while (traversalPtr != 0) {
//		cout << *traversalPtr << endl;
//	}
//}

Node::~Node(){}