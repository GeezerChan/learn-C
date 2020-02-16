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

	first = new Node(						// new node becomes the new head
		2,									
		first,								// primes new links with old links.
		last								
	);

	last = first;					        // old head becomes new head.

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

	first = new Node(						// replaces head with a new
		3,									// head, inheriting all of the 
		nullptr,							// existing old links.
		last								
	);
	
	last->setPrev(first);					// connects tail with new head.

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

	first->setNext(						// creates new node already linked 
		new Node(						// to the head.
			4,
			first,
			last
		)
	);
	
	last->setPrev(first->getNext());	// inserts new node to the middle by
										// traversing from the head.
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

	first = first->getNext();			// Replace head with next node.
	first->setPrev(nullptr);			// Deactivates the new head's previous pointer 
										// that is still attached to the deleted node.
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
	
	for (int newData = 5; newData < 8; ++newData) {
		last->setNext(					// creates new node already linked to the tail.
			new Node(					
				newData,				// data = newData;
				last,					// prev = last;
				nullptr					// next = nullptr;
			)
		);

		last = last->getNext();			// new node becomes the new tail.
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

	Node* temp = last;						/* declaration of re-usable pointer */

	last = last->getPrev();

	temp->getPrev()->setNext(nullptr);
	temp->setPrev(first);
	temp->setNext(first->getNext());

	first->getNext()->setPrev(temp);
	first->setNext(temp);					// temp remains 7

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
											// List before: 4 7 2 5 6
	first->setPrev(last->getPrev());		// create and link arms of head.
	first->setNext(last);

	last->getPrev()->setNext(first);		// detach the right and left arms 
											// from the occupying space.
	last->setPrev(first);					// connects the links in the space to old head.
	last->setNext(nullptr);					// seals the new end of the new tail.

	first = temp;

	first->setPrev(nullptr);
	
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
	temp = first;												// recycled pointer.

	auto max = temp->getData();									// initialized comparison val.
	
	while (temp->getNext() != nullptr) {						// iterates through the entire list from the head.
		if (temp->getData() > temp->getNext()->getData()) {		// compares current data with next data.
			max = temp->getData();

			temp->setData(temp->getNext()->getData());			// swap current data val first 
			temp->getNext()->setData(max);						// then the next.

			temp = first;										// ** GOES BACK TO THE HEAD OF THE LIST UNTIL 
		}														
		else {													// ALL VALUES ARE IN ORDER BEFORE MOVING TO NEXT. **
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
	temp = new Node(					// recycled pointer morphs into
		3,								// new node with links primed.
		first,
		first->getNext()
	);

	first->getNext()->setPrev(temp);	// connects the new node in between
	first->setNext(temp);				// head & next node.
	
	first = new Node(					
		1,
		nullptr,
		first
	);

	first->getNext()->setPrev(first);	// assigns new node to head.

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