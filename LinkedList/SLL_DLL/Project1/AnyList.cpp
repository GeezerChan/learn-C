#include "AnyList.h"

using namespace std;

	//default constructor
AnyList::AnyList() : first(nullptr), count(0){}

void AnyList::printForward() 
{
	SLLNode* current = first;
	while (current != nullptr)
	{
		cout << current->getData() << " ";
		current = current->getNext();
	}
}

void AnyList::mystery2()
{
	SLLNode* temp = first->getNext();
	first->setNext(temp->getNext()->getNext());
	temp->getNext()->setNext(temp);
	temp = temp->getNext();
	// statement
	temp->getNext()->setNext(first); // cut infinite loop
		first = temp;
}

void AnyList::mystery()
{
	SLLNode* temp = first->getNext(); // node2
	first->setNext(temp->getNext()->getNext()); // node2 > node3 > node4
	temp->getNext()->setNext(temp);

	temp = temp->getNext();			// statement

	temp->getNext()->setNext(first);
	first = temp;
}

void AnyList::swapFirstAndSecond()
{
	SLLNode* temp = first->getNext();	// store 2nd node in temp
	first->setNext(temp->getNext());	// link first to 3rd node
	temp->setNext(first);				//  ?????
	first = temp;						// temp node is new first
}

/*
SLLNode* node1 = first;
	SLLNode* node2 = first->getNext();
	SLLNode* node3 = first->getNext()->getNext();

	node1->setNext(nullptr);	// node 1 ptr to node 3 ptr next
	node2->setNext(node1);				// node2 ptr to first

	node3->setNext(node2);
	first = node3;
*/


	//insertFront
void AnyList::insertFront(int newData)
{	
	first = new SLLNode(newData, first);
	++count;
}

	//print
void AnyList::print() const
{
	SLLNode* current = first;
	while (current != nullptr)
	{
		cout << current->getData() << " ";	
		current = current->getNext();		
	}
}

	//emptyTheList
void AnyList::emptyTheList()
{
	SLLNode* temp = first;
	while (first != nullptr)
	{
		first = first->getNext();
		delete temp;
		temp = first;
	}
	count = 0;
}

//destructor
AnyList::~AnyList()
{
	emptyTheList();
}