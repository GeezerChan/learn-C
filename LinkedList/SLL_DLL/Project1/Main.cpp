#include "AnyList.h"
#include "DoublyList.h"

#include <iostream>
using namespace std;

void testSLL();
void testDLL();

int main()
{
	DoublyList list1;

	list1.insertFront(2);
	list1.insertFront(4);
	list1.insertFront(6);
	list1.insertFront(10);
	list1.insertFront(1);
	list1.insertFront(31);
	list1.insertFront(13);
	list1.insertFront(85);
	list1.insertFront(23);

	cout << "\nLIST1: \n";
	list1.printForward();
	cout << endl;

	cout << "\Swap: \n";

	list1.mystery();
	list1.printForward();
	cout << endl;

	cout << endl;

	testSLL();
	testDLL();

	cout << endl;
	system("Pause");
	return 0;
}
