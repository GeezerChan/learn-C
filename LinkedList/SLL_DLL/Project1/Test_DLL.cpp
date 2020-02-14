#include "DoublyList.h"

#include <iostream>
using namespace std;

void deleteDLL(DoublyList& myList)
{
	// Comment/uncomment for testing
	myList.deleteBeforeLast();
}

void testDLL()
{
	{
		//DLL TEST: List is empty
		DoublyList myList;
		cout << "DLL TEST: List is empty."
			<< "\n     Expected: (error message)"
			<< "\n  Your output: ";
		deleteDLL(myList);
	}

	cout << "\n\n--------------------------------------------------\n";

	{
		//DLL TEST: List has only one node
		DoublyList myList;
		myList.insertFront(2);
		cout << "DLL TEST: List has only one node."
			<< "\n     Expected: (error message)"
			<< "\n  Your output: ";
		deleteDLL(myList);
	}

	cout << "\n\n--------------------------------------------------\n";

	{
		//DLL TEST: List has only two nodes
		DoublyList myList;
		myList.insertFront(6);
		myList.insertFront(3);
		cout << "DLL TEST: List has only two nodes."
			<< "\n      List is: ";
		myList.printForward();
		cout << "\nDelete node before last..."
			<< "\n     Expected: 6"
			<< "\n  Your output: ";
		deleteDLL(myList);
		myList.printForward();
		cout << "\nPrint reverse..."
			<< "\n     Expected: 6"
			<< "\n  Your output: ";
		myList.printReverse();
	}

	cout << "\n\n--------------------------------------------------\n";

	{
		//DLL TEST: List has three nodes
		DoublyList myList;
		myList.insertFront(8);
		myList.insertFront(5);
		myList.insertFront(2);
		cout << "DLL TEST: List has more than two nodes."
			<< "\n      List is: ";
		myList.printForward();
		cout << "\nDelete node before last..."
			<< "\n     Expected: 2 8"
			<< "\n  Your output: ";
		deleteDLL(myList);
		myList.printForward();
		cout << "\nPrint reverse..."
			<< "\n     Expected: 8 2"
			<< "\n  Your output: ";
		myList.printReverse();
	}

	cout << "\n\n--------------------------------------------------\n";

	{
		//DLL TEST: List has more than three nodes	
		DoublyList myList;
		myList.insertFront(32);
		myList.insertFront(65);
		myList.insertFront(53);
		myList.insertFront(48);
		myList.insertFront(11);
		myList.insertFront(87);
		myList.insertFront(91);
		cout << "DLL TEST: List has more than two nodes."
			<< "\n      List is: ";
		myList.printForward();
		cout << "\nDelete node before last..."
			<< "\n     Expected: 91 87 11 48 53 32"
			<< "\n  Your output: ";
		deleteDLL(myList);
		myList.printForward();
		cout << "\nPrint reverse..."
			<< "\n     Expected: 32 53 48 11 87 91"
			<< "\n  Your output: ";
		myList.printReverse();
	}

	cout << "\n\n==================================================\n";
}