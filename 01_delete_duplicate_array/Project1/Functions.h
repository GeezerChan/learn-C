/*
	Blood, William

	February 1, 2020

	CS A250
	Lab 1
*/

#include <iostream>

void unshift(int a[], int& numOfElem, int idx) {
	numOfElem--;							// Reduces array size by 1
	for (int k = idx; k < numOfElem; ++k)	// Shifts all elems from idx pos.
		a[k] = a[k + 1];
}

void printArray(int a[], int numOfElem) {
	for (int i = 0; i < numOfElem; ++i)		// Prints elems to cout stream
		cout << a[i] << " ";
}

void deleteDuplicates(int a[], int& numOfElem) {
	for (int i = 0; i < numOfElem; ++i) {	// Standard iterator
		int nextIndex = i + 1;			    // Location of possible duplicate
		while (nextIndex < numOfElem) {		// Begins searching from dupe pos.
			if (a[i] == a[nextIndex])		// Removes duplicate when encountered
				unshift(a, numOfElem, nextIndex);
			else 
				++nextIndex;				// Advances to the next element
		}
	}
}