/*
	Blood, William

	February 1, 2020

	CS A250
	Lab 1
*/

#include <iostream>

void printArray(int a[], int numOfElem);
void removeNumber(int a[], int& numOfElem, int idx);
void deleteDuplicates(int a[], int& numOfElem);

void printArray(int a[], int numOfElem) {
	for (int i = 0; i < numOfElem; ++i)
		cout << a[i] << " ";
}

void deleteDuplicates(int a[], int& numOfElem) {
	for (int i = 0; i < numOfElem; ++i) {	// Standard iterator
		int nextIndex = i + 1;			    // Location of possible duplicate
		while (nextIndex < numOfElem) {		// Linear search and destroy algorithm
			if (a[i] == a[nextIndex])
				removeNumber(a, numOfElem, nextIndex);
			else 
				++nextIndex;				// Advances to the next suspect
		}
	}
}

void removeNumber(int a[], int& numOfElem, int idx) {
	numOfElem--;							// Updates size
	for (int k = idx; k < numOfElem; k++)	// Replaces current element with next
		a[k] = a[k + 1];
}