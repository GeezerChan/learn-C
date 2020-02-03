#include <iostream>
using namespace std;

void printArray(int a[], int numOfElem);
void deleteDuplicate(int a[], int& numOfElem);
void removeNumber(int a[], int& numOfElem, int idx);

int main() {
	cout << "Array: ";
	int a[] = { 1, 1, 2, 2, 3 };
	int numOfElem = 5;
	printArray(a, 5);

	cout << "\nAfter deleting: " << endl;


	deleteDuplicate(a, numOfElem);
	printArray(a, numOfElem);

	cout << endl;
	system("Pause");
	return 0;
}

void printArray(int a[], int numOfElem) {
	for (int i = 0; i < numOfElem; i++)
		cout << a[i] << " ";
}

void deleteDuplicate(int a[], int& numOfElem) {
	for (int i = 0; i < numOfElem; ++i) {
		for (int j = 0; j < i; ++j) {
			if (a[i] == a[j]) {
				cout << "\nDuplicate found. Deleting [" << a[i] << "]\n";
				removeNumber(a, numOfElem, j);
			}
		}
	}
	cout << "Finished\nTotal remaining elements: " << numOfElem << endl;
}
void removeNumber(int a[], int& numOfElem, int idx) {
	numOfElem--;
	for (int k = idx; k < numOfElem; k++) {
		a[k] = a[k + 1];
	}
}