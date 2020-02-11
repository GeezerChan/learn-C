#include <iostream>
#include "Node.h"

using namespace std;

void validatePassword(string& password) {
	NodeList* login = new NodeList();
	while (true) {
		cout << "Enter the password: " << endl;
		cin >> password;
		if (password == "Billy" || password == "q") break;
		login->appendToHead(password);
	}
	cout << password << endl;
}

int main() {

	string password;
	validatePassword(password);

	cout << endl;
	system("Pause");
	return 0;
}