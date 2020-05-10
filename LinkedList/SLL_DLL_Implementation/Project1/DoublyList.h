#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>

class DLLNode
{
public:
	DLLNode() : data(0), next(nullptr), prev(nullptr) {}
	DLLNode(int theData, DLLNode* newPrev, DLLNode* newNext)
            : data(theData), prev(newPrev), next(newNext) {}
	DLLNode* getPrev( ) const { return prev; }
	DLLNode* getNext( ) const { return next; }
    int getData( ) const { return data; } 
    void setPrev(DLLNode* newPrev) { prev = newPrev; }
	void setNext(DLLNode* newNext) { next = newNext; }
	void setData(int theData) { data = theData; }

private:
    int data;
	DLLNode* next;
	DLLNode* prev;
};

class DoublyList
{
public:
	DoublyList(); 	

	void insertFront(int);

	void deleteBeforeLast();
    
	void printForward() const;
	void printReverse() const;
	
	void emptyTheList();
	~DoublyList();
      
private:
	DLLNode* first;
	DLLNode* last;
	int count;
};

#endif