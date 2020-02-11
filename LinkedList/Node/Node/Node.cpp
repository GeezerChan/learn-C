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

	delete newNode; newNode = nullptr;
	count++;
}


Node::~Node(){}
