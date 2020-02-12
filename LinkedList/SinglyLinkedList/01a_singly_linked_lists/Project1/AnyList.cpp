#include "AnyList.h"

using namespace std;

	//constructor
AnyList::AnyList()
{
	ptrToFirst = nullptr;
	count = 0;
}

	//insertFront
void AnyList::insertFront(int newData)
{	
	//Node *ptrToNewNode = new Node;	//create a pointer named ptrToNewNode that
									// points to an unnamed node

	//ptrToNewNode->setData(newData);		//store data in the new node

	//ptrToNewNode->setPtrToNext(ptrToFirst);	//set new node's pointer to point to the first node

	//ptrToFirst = ptrToNewNode;		//make the new node be the "first" node

	//
	//	There is shorter way to write the statements above using the overloaded constructor:

/*			Node *ptrToNewNode = new Node(newData, ptrToFirst);
			ptrToFirst = ptrToNewNode;	*/	

	//	Or even better, without creating any pointers:
	//	    
			ptrToFirst = new Node(newData, ptrToFirst);
	//*/	

	++count;
}

void AnyList::deleteElem(int elem) {
	// list is empty
	if (count == 0) {
		cerr << "List is empty" << endl;
	}
	else {
	// list only 1 node
		if (count == 1) {
			if (ptrToFirst->getData() == elem) {
				delete ptrToFirst;
				ptrToFirst = nullptr;
			}
			--count;
		}
		else if (count == 2) { 
			if (ptrToFirst->getData() == elem) {
				Node* current = ptrToFirst;
				ptrToFirst = ptrToFirst->getPtrToNext();
				delete current;
				current = nullptr;
				--count;
			}
			else if (ptrToFirst->getPtrToNext()->getData() == elem) {
				// RESTRICTION: DO NOT MAKE A NEW NODE
				delete ptrToFirst->getPtrToNext();
				ptrToFirst->setPtrToNext(nullptr);
				--count;
			}
			else {
				Node* current = ptrToFirst;
				Node* traversalPtr = ptrToFirst->getPtrToNext(); // starts at 2nd node

				if (current->getData() == elem) {
					
				} // item is in the first node
				else { // item is somewhere else
					current = current->getPtrToNext();
					while (current != nullptr) {
						if (current->getData() == elem) {
							traversalPtr->setPtrToNext(current->getPtrToNext());
							delete current;
							current = nullptr;
							--count;
						}
						else {
							traversalPtr = current;
							current = current->getPtrToNext();
						}
					}
				}
			}
		}
	}
	// list has 2 nodes
	// list has lots (middle)
	// elem somewhere in middle orl ast
	// elem not found
}

	//print
void AnyList::print() const
{
	if (ptrToFirst == nullptr) // check if the list is empty
							   // you can also use: if (count < 1)
		cerr << "List is empty.";  // use cerr, rather than cout (why?)
	else
	{
		Node *current = ptrToFirst;   //create a pointer to traverse the list	
									  //this pointer will start with the first node in the list

		while (current != nullptr)	//while the current pointer is NOT pointing to NULL
		{						    //  that is, the current pointer has not reached the 
			                        //  end of the list
			cout << current->getData() << " ";	//output the data 
			current = current->getPtrToNext();		//move the pointer current forward
		}
	}
}

	//destroyList - Does not delete the list object; it ONLY deletes the nodes.
void AnyList::destroyList()
{ 
    Node  *temp = ptrToFirst; //pointer to delete the node, starting with the first node
	
	while (ptrToFirst != nullptr)
    {
		ptrToFirst = ptrToFirst->getPtrToNext();
        delete temp;
		temp = ptrToFirst;
    }

	count = 0;
}

	//destructor
AnyList::~AnyList()
{
	destroyList();
}