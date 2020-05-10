/*
	Blood, William

	February 10, 2020

	CS A250
	Lab 3
*/

#include "AnyList.h"
#include "DoublyList.h"

using namespace std;

//deleteBeforeLast  (member of the AnyList class)

void AnyList::deleteBeforeLast()
{
	//Case 1: List is empty
	if (count == 0)
		cerr << "Cannot delete from an empty list.";

	//Case 2: List has only one node
	else if (count == 1)
		cerr << "Cannot delete from a list that has only one node.";

	//Case 3: List has two nodes
	else if (count == 2)
	{
		SLLNode* current = first;
		first = first->getNext();

		delete current;
		current = nullptr;

		--count;
	}

	else
	{
		SLLNode* current = first->getNext();
		SLLNode* trailCurrent = first;

		while (current->getNext()->getNext() != nullptr)
		{
			trailCurrent = current;
			current = current->getNext();
		}

		trailCurrent->setNext(current->getNext());

		delete current;
		current = nullptr;

		--count;
	}
}

	//deleteBeforeLast  (member of the DoublyList class)
void DoublyList::deleteBeforeLast()
{
	//Case 1: List is empty
	if (count == 0)
		cerr << "Cannot delete from an empty list.";

	//Case 2: List has only one node
	else if (count == 1)
		cerr << "Cannot delete from a list that has only one node.";

	//Case 3: List has two nodes
	else if (count == 2)
	{
		last->setPrev(nullptr);
		delete first;
		first = last;

		--count;
	}

	//Case 4: List has more than two nodes
	else
	{
		//pointer to node before last
		DLLNode* beforeLast = last->getPrev();

		//pointer to two nodes before last
		DLLNode* temp = beforeLast->getPrev();

		temp->setNext(last);
		last->setPrev(temp);

		delete beforeLast;
		beforeLast = nullptr;

		--count;
	}
}