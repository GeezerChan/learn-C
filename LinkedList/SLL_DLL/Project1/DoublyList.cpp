#include "DoublyList.h"

using namespace std;

void DoublyList::mystery()
{
	first->setNext(first->getNext()->getNext());
	first->getNext()->getPrev()->setNext(first);
	first = first->getNext()->getPrev();
	first->setPrev(nullptr);
	first->getNext()->getNext()->setPrev(first->getNext());
	first->getNext()->setPrev(first); // STATEMENT
}

	//default constructor
DoublyList::DoublyList() : first(nullptr), 
								last(nullptr),count(0) {}

	//insertFront
void DoublyList::insertFront(int newData)
{
	first = new DLLNode(newData, nullptr, first);
	++count;
		
	if (count == 1)
		last = first;	
    else // if more than one node
		first->getNext()->setPrev(first);
}

	//printForward
void DoublyList::printForward() const
{
	DLLNode* current = first;
	while (current != nullptr)
	{
		cout << current->getData() << " ";
		current = current->getNext();
	}
}

	//printReverse
void DoublyList::printReverse() const
{
	DLLNode* current = last;
	while (current != nullptr)
	{
		cout << current->getData() << " ";
		current = current->getPrev();
	}
}

	//emptyTheList
void DoublyList::emptyTheList()
{
	DLLNode* temp = first;
	while (first != nullptr)
	{
		first = first->getNext();
		delete temp;
		temp = first;
	}
	last = nullptr;
	count = 0;
}

//destructor
DoublyList::~DoublyList()
{
	emptyTheList();
}
