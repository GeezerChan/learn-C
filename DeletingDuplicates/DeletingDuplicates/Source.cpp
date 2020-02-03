#include <iostream>
using namespace std;

void printArray(int a[], int numOfElem);
void deleteDuplicate(int a[], int& numOfElem);
void removeNumber(int a[], int& numOfElem, int idx);

int main() {
	cout << "Array: ";
	int a[] = { 1, 2, 2, 1, 2, 2, 2 };
	int numOfElem = 7;
	printArray(a, numOfElem);

	cout << "\nAfter deleting: ";


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
	for (int i = 0; i < numOfElem; i++) {
		cout << "checking duplicates of " << a[i] << endl;
		for (int j = i + 1; j < numOfElem;) {
			cout << "scanning " << a[j] << endl;
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
void removeNumber(int a[], int& numOfElem, int idx) {
	numOfElem--;
	for (int k = idx; k < numOfElem; k++) {
		a[k] = a[k + 1];
	}
}