#include "AnyList.h"

#include <iostream>
using namespace std;

void deleteSLL(AnyList& myList)
{
	// Comment/uncomment for testing
	myList.deleteBeforeLast();
}

void testSLL()
{
	{
		//SLL TEST: List is empty
		AnyList myList;
		cout << "SLL TEST: List is empty."
			<< "\n     Expected: (error message)"
			<< "\n  Your output: ";
		deleteSLL(myList);
	}

	cout << "\n\n--------------------------------------------------\n";

	{
		//SLL TEST: List has only one node
		AnyList myList;
		myList.insertFront(2);
		cout << "SLL TEST: List has only one node."
			<< "\n     Expected: (error message)"
			<< "\n  Your output: ";
		deleteSLL(myList);
	}

	cout << "\n\n--------------------------------------------------\n";

	{
		//SLL TEST: List has only two nodes
		AnyList myList;
		myList.insertFront(2);
		myList.insertFront(3);
		cout << "SLL TEST: List has only two nodes."
			<< "\n      List is: ";
		myList.print();
		cout << "\nDelete node before last..."
			<< "\n     Expected: 2"
			<< "\n  Your output: ";
		deleteSLL(myList);
		myList.print();
	}

	cout << "\n\n--------------------------------------------------\n";

	{
		//SLL TEST: List has three nodes
		AnyList myList;
		myList.insertFront(2);
		myList.insertFront(4);
		myList.insertFront(5);
		cout << "SLL TEST: List has more than two nodes."
			<< "\n      List is: ";
		myList.print();
		cout << "\nDelete node before last..."
			<< "\n     Expected: 5 2"
			<< "\n  Your output: ";
		deleteSLL(myList);
		myList.print();
	}

	cout << "\n\n--------------------------------------------------\n";

	{
		//SLL TEST: List has more than three nodes	
		AnyList myList;
		myList.insertFront(23);
		myList.insertFront(56);
		myList.insertFront(35);
		myList.insertFront(84);
		myList.insertFront(15);
		myList.insertFront(75);
		cout << "SLL TEST: List has more than two nodes."
			<< "\n      List is: ";
		myList.print();
		cout << "\nDelete node before last..."
			<< "\n     Expected: 75 15 84 35 23"
			<< "\n  Your output: ";
		deleteSLL(myList);
		myList.print();
	}

	cout << "\n\n==================================================\n";
}