~/*
	Blood, William

	February 1, 2020

	CS A250
	Lab 1
*/

#include <iostream>


void printArray(int a[], int numOfElem);
void deleteDuplicate(int a[], int& numOfElem);
void removeNumber(int a[], int& numOfElem, int idx);

void printArray(int a[], int numOfElem) {
	for (int i = 0; i < numOfElem; i++)
		cout << a[i] << " ";
}

void deleteDuplicate(int a[], int& numOfElem) {
	for (int i = 0; i < numOfElem; ++i) {
		for (int j = 0; j < i; ++j) {
			if (a[i] == a[j]) {
				cout << "Duplicate found. Deleting [" << a[i] << "]\n";
				removeNumber(a, numOfElem, j);
			}
		}
	}
	cout << "elements after: " << numOfElem;
	cout << endl;
}
void removeNumber(int a[], int& numOfElem, int idx) {
	numOfElem--;
	for (int k = idx; k < numOfElem; k++) {
		a[k] = a[k + 1];
	}
}
