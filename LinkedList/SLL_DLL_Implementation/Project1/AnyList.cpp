#include "AnyList.h"

using namespace std;

	//default constructor
AnyList::AnyList() : first(nullptr), count(0){}

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