/*
	Blood, William

	February 10, 2020

	CS A250
	Lab 3
*/

#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

class Node {
public:
	Node() : data(""), next(nullptr) {}
	Node(string newData) : data(newData) {}
	Node(string newData, Node* newNode) : data(newData), next(newNode) {}

	string getData() const { return data; }
	Node* getNext() const { return next; }
	
	void setData(const string& newData) { data = newData; }
	void setNext(Node* newNext) { next = newNext; }
	
	~Node();
private:
	string data;
	Node* next;
};

class NodeList {
public:
	NodeList() : head(nullptr), count(0) {}
	
	void appendToHead(const string& newData);
	
	~NodeList() {}
private:
	int count;
	Node* head;
};

#endif // !NODE_H
