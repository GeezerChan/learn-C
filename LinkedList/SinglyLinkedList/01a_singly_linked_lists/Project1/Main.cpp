#include "AnyList.h"

#include <iostream>
using namespace std;

// declare non-member func processList()

void processList(AnyList myList, int elem);


int main()
{



	AnyList myList;
	
	// How to test a NodeList

	// list is empty
	{
		AnyList myList;
	}
	// list has 1 node and elem is found

	{
		AnyList myList;
		myList.insertFront(40);
		processList(myList, 40);
	}

	// list has 1 node and elem is not found

	//{
	//	AnyList myList;
	//	myList.insertFront(40);
	//	cout << "\nList: ";
	//	myList.print();
	//	cout << "\nDeleting 100..";
	//	myList.deleteElem(100);
	//	cout << "\nList: ";
	//	myList.print();
	//}

	// list has 2 node and elem is found

	// list has 2 node and elem is not found

	// list has several nodes and elem is found elsewhere in the middle

	{
		AnyList myList;
		myList.insertFront(4);
		myList.insertFront(3);
		myList.insertFront(2);
		myList.insertFront(1);
		processList(myList, 3);
	}

	// list has several nodes and elem is found in last position

	// list has several nodes and elem is not found

	
	cout << endl;
	system("Pause");
	return 0;
}

void processList(AnyList myList, int elem) {
	cout << "\nList: ";
	myList.print();
	cout << "\nDeleting 40..";
	myList.deleteElem(elem);
	cout << "\nList: ";
	myList.print();
}