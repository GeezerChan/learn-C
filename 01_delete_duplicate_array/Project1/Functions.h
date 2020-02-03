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
	for (int i = 0; i < numOfElem; i++)
		cout << a[i] << " ";
}

void removeNumber(int a[], int& numOfElem, int idx) {
	numOfElem--;
	for (int k = idx; k < numOfElem; k++) {
		a[k] = a[k + 1];
	}
}

void deleteDuplicates(int a[], int& numOfElem) {

	for (int i = 0; i < numOfElem; ++i) {
		for (int j = 0; j < i; ++j) {
			if (a[i] == a[j]) {
				cout << "\nDuplicate found. Deleting [" << a[i] << "]\n";
				removeNumber(a, numOfElem, j);
			}
		}
	}
	cout << "Finished\nTotal remaining elements: " << numOfElem << endl;
	cout << endl;
}

