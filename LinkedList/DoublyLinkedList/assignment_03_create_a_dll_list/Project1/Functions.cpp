/*
	Name header
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

	first = new Node(						// creates body
		2,									// holding an integer as data.
		first,								// connects new head with old head
		last								// connects temp to head
	);

	// Update count;
	// Your code here...
	++count;								// update count & check for 
											// a list with a head & temp.
	last = first;					        // links temp with head to create a body

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
	first = new Node(						// creates body
		3,									// holding an integer as data.
		first,								// connects new head with old head
		last								// connects temp to head
	);
	last->setPrev(first);
	first->setPrev(nullptr);
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

	first->setNext(new Node(
		4,
		first,
		last
	));
	
	last->setPrev(first->getNext());	// Enable reverse: connect the temp's prev to the middle
										// by navigating from the head of the list.
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
	first->setPrev(nullptr);			// Unlink & deactivate the next node's previous pointer
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
	
	// Why not just link a new list to last??
	last->setNext(new Node(
		5,
		last,
		nullptr
	));
	last = last->getNext();

	last->setNext(new Node(
		6,
		last,
		nullptr
	));
	last = last->getNext();

	last->setNext(new Node(
		7,
		last,
		nullptr
	));
	last = last->getNext();
	


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

	Node* temp = last;					/* declaration of re-usable pointer */

	last = last->getPrev();

	temp->getPrev()->setNext(nullptr);
	temp->setPrev(first);
	temp->setNext(first->getNext());

	first->getNext()->setPrev(temp);
	first->setNext(temp);						// temp remains 7

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

	
	first->setPrev(last->getPrev());		// create and link arms of head
	first->setNext(last);
	// detach the right and left arms 
	last->getPrev()->setNext(first);		// from the occupying space

	last->setPrev(first);
	last->setNext(nullptr);

	first = temp;

	first->setPrev(nullptr);

					// seal the last link
	
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
	temp = first;
	
	while (temp->getNext() != nullptr) {
		if (temp->getData() > temp->getNext()->getData()) {	// workhorse 7 2
			auto max = temp->getData();
			temp->setData(temp->getNext()->getData());		// swap temp and next values.
			temp->getNext()->setData(max);
		}
		
		temp = temp->getNext();						// nav to the next page.
	}

	temp = first;										

	while (temp->getNext() != nullptr) {						
		if (temp->getData() > temp->getNext()->getData()) {	 
			auto max = temp->getData();					
			temp->setData(temp->getNext()->getData());		// swap temp and next values
			temp->getPrev()->setData(temp->getPrev()->getData());

			temp->getNext()->setData(max);
		}

		temp = temp->getNext();						// nav to the next page
	}

	cout << "\nSECTION 8 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 9
	------------------------------------------------------------------*/

	// Add two nodes storing 1 and 3 to complete the ordered list.
	// List becomes: 1 2 3 4 5 6 7
	// Your code here...

	// insert 3 first
	Node* node3 = new Node(				// create node & activate links
		3,
		first,
		first->getNext()
	);

	first->getNext()->setPrev(node3);	// chain links in between head and next node
	first->setNext(node3);
	
	first = new Node(					
		1,
		nullptr,
		first
	);

	first->getNext()->setPrev(first);	// assign new node to head

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