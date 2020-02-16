/*
	Blood, William

	February 15, 2020

	CS A250
	Lab 3
*/

#include "DoublyList.h"

using namespace std;

// createAList
void DoublyList::createAList()
{
	/*
		NOTE:
			
			* You will need to declare one pointer and 
			  you may re-use this pointer throughout the function, but
			  you are NOT allowed to create additional pointers.

			* Pay CLOSE attention to instructions.
			
			************* IMPORTANT ****************

			*** DO NOT REMOVE EXISTING COMMENTS. ***			
	*/

	/*----------------------------------------------------------------
	SECTION 1
	------------------------------------------------------------------*/

	// Create a dynamic node that stores the value 2 and make 
	// this node be the first node of the calling object.
	// List becomes: 2
	// Use the overloaded constructor.
	// Do NOT create a pointer.
	// Your code here...

	first = new Node(		// new node becomes the new head.
		2,									
		first,				// primes new links with old links.
		last								
	);

	last = first;			// old head becomes new head.

	// Update count;
	// Your code here...
	++count;								

	cout << "SECTION 1 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 2
	------------------------------------------------------------------*/

	// Create another node that stores the value 3 and 
	// insert this node to the left of the node that is 
	// storing value 2.
	// List becomes: 3 2
	// Do NOT create a pointer.
	// Your code here...

	last = first;

	first = new Node(		// replaces head with a new head.
		3,					// inherits last position.
		nullptr,
		last
	);
	
	last->setPrev(first);	// connects tail with new head.

	// Update count;
	// Your code here...
	++count;								

	cout << "\nSECTION 2 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 3
	------------------------------------------------------------------*/

	// Create another node that stores the value 4 and
	// insert this node to the right of the node that is
	// storing value 3.
	// List becomes: 3 4 2
	// NO MORE than 3 statements.
	// Your code here...

	first->setNext(		// creates new node already linked to head.
		new Node(				
			4,
			first,
			last
		)
	);
	
	// inserts new node to the middle by traversing from the head.
	last->setPrev(first->getNext());	

	// Update count;
	// Your code here...
	++count;

	cout << "\nSECTION 3 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 4
	------------------------------------------------------------------*/

	// Delete the first node.
	// List becomes: 4 2
	// Your code here...

	first = first->getNext();	// Replace head with next node.

	// Deactivates new head's prev still attached to the deleted node
	first->setPrev(nullptr);	
	
	// Update count.
	// Your code here...
	--count;


	cout << "\nSECTION 4 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 5
	------------------------------------------------------------------*/

	// Insert three nodes at the end of the list storing 
	// 5 6 7 in this order.
	// List becomes: 4 2 5 6 7
	// Do NOT use the pointer you created.
	// Your code here..

	// Creates 3 new nodes primed & already linked to the tail.
	for (int newData = 5; newData < 8; ++newData) {
		last->setNext(					
			new Node(					
				newData,			// data = newData;
				last,				// prev = last;
				nullptr				// next = nullptr;
			)
		);

		last = last->getNext();		// new node becomes the new tail.
	}

	// Update count.
	// One statement only.
	// Your code here...
	count += 3;


	cout << "\nSECTION 5 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 6
	------------------------------------------------------------------*/

	// Move last node to second position.
	// Here steps are very important. Carefully think 
	// how you can move nodes around without losing any
	// nodes and keeping all pointers pointing to the
	// correct nodes.
	// Note: 
	//		You may NOT create an additional node.
	//		NO loops are necessary.
	// List becomes: 4 7 2 5 6
	// Your code here...

	Node* temp = last;			/* declaration of re-usable pointer */

	last = last->getPrev();

	temp->getPrev()->setNext(nullptr);
	temp->setPrev(first);
	temp->setNext(first->getNext());

	first->getNext()->setPrev(temp);
	first->setNext(temp);				// temp remains 7

	cout << "\nSECTION 6 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 7
	------------------------------------------------------------------*/
	
	// Move the first node in between the node before last and
	// last node (the second node will become the first node
	// in the list, and the first node will become the before-last 
	// node in the list).
	//		You may NOT create an additional node.
	//		No loops are necessary.
	// List becomes: 7 2 5 4 6
	// Your code here...
	
	// Creates and links arms (prev & next) of head.
	first->setPrev(last->getPrev());	
	first->setNext(last);

	// Reattaches arms from target node with old head.	
	last->getPrev()->setNext(first); 
	last->setPrev(first);		// chains target node links to old head.
	last->setNext(nullptr);		// seals the new end of the new tail.

	first = temp;				// insertion.

	first->setPrev(nullptr);	// seals the entrance to the head.
	
	cout << "\nSECTION 7 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 8
	------------------------------------------------------------------*/

	// WITHOUT moving any nodes, swap around the values to 
	// create an ordered list. 
	// Note that there is no need to move the value 5.
	// You may declare an int, BUT do NOT use any literals.
	// List becomes: 2 4 5 6 7
	// Your code here...

	// List before: 7 2 5 4 6
	temp = first;						// recycled pointer.

	auto max = temp->getData();			// initialized comparison val.

	// Iterates through the list from the head, pushing max to the end.
	while (temp->getNext() != nullptr) {						
		if (temp->getData() > temp->getNext()->getData()) {		
			max = temp->getData();		// holds the current data.
			
			// Swaps current data first, then the next node's data.
			temp->setData(temp->getNext()->getData());
			temp->getNext()->setData(max);

			temp = first;	// GOES BACK TO THE HEAD OF THE LIST UNTIL
		}														
		else {			// ALL VALUES ARE IN ORDER BEFORE MOVING ON.
			temp = temp->getNext();								
		}
	}

	cout << "\nSECTION 8 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 9
	------------------------------------------------------------------*/

	// Add two nodes storing 1 and 3 to complete the ordered list.
	// List becomes: 1 2 3 4 5 6 7
	// Your code here...

	// inserts 3 first

	// recycled pointer morphs into new node with links primed.
	temp = new Node(
		3,
		first,
		first->getNext()
	);

	// connects the new node in between head & next node.
	first->getNext()->setPrev(temp);	
	first->setNext(temp);
	
	first = new Node(					
		1,
		nullptr,
		first
	);

	// connects final node to head.
	first->getNext()->setPrev(first);

	// Add 2 to count.
	// Your code here...
	count += 2;

	cout << "\nSECTION 9 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 10
	------------------------------------------------------------------*/

	/*
	Go back to check the following:
		Are there any sections that have more than one blank line?
		If so, do not leave unnecessary white space.
		Leave only one blank line.
	
		Are your statements too long that is necessary to scroll 
		horizontally? If so, break your statements in readable portions.
	
		Instructions said to create and use ONLY ONE pointer.
		Go back and check that you did not create more than one pointer.
	  
		Re-visit your code for efficiency.
	*/

}