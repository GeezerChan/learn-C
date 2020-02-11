#include <iostream>
#include "Node.h"

using namespace std;

void openAddPWToKeyTerminal(NodeList* keychain);

int main() {

	NodeList* keychain = new NodeList();
	
	openAddPWToKeyTerminal(keychain);
	
	keychain->printList();
	
	cout << endl;
	system("Pause");
	return 0;
}

void openAddPWToKeyTerminal(NodeList* keychain) {
	cout << "!Keychain accessed!\n"
		<< "Add a password or press 'q' to quit\n\n";

	while (true) {
		string password;
		cout << "Enter password: ";
		cin >> password;
		if (password == "q")
			break;

		keychain->appendToHead(password);
		cout << "Password added.\n\n";
	}

	cout << "Exiting terminal.\n";
}