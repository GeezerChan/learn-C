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
	for (int i = 0; i < numOfElem; i++) {
		cout << "checking for duplicates of " << a[i] << endl;
		for (int j = i + 1; j < numOfElem;) {
			cout << "looking at " << a[j] << endl;
			if (a[i] == a[j]) {
				cout << "duplicate found. deleting [" << a[j] << "]\n";
				numOfElem--;
				for (int r = j; r < numOfElem; r++) {
					a[j] = a[j + 1];
				}
			}
			else ++j;
		}
	}
}