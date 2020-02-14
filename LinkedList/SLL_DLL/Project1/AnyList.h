#ifndef ANYLIST_H
#define ANYLIST_H

#include<iostream>
#include <string>

class SLLNode
{
public:
	SLLNode() : data(0), next(nullptr) {}
	SLLNode(int theData, SLLNode* newNext) : data(theData), next(newNext){}
	SLLNode* getNext( ) const { return next; }
    int getData( ) const { return data; }
    void setData(int newData) { data = newData; }
    void setNext(SLLNode* newNext) { next = newNext; }
private:
    int data;
	SLLNode*next;
};


class AnyList
{
public:
	AnyList();

	void insertFront(int);	
	
	void print() const;

	void deleteBeforeLast();

	void emptyTheList();
	~AnyList();

private:
	SLLNode* first;
	int count;
};

#endif