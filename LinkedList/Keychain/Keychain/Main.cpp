#include "User.h"
#include <iostream>
#include <cmath>

using namespace std;

/* Driver code*/
int main() {

	/* Testing */
	UserList keychain;

	{
		UserList keychain;
		keychain.display();
	}

	{
		UserList keychain;
		keychain.newUser("John");
		keychain.newUser("Jill");
		keychain.display();
	}

	{
		UserList keychain;
		keychain.newUser("Billy", "wb0710");
		keychain.newUser("Sophie", "bentley@2172001");
		keychain.newUser("Bentley", "Doggyrockwood94", 420);
		keychain.display();
	}

	{
		UserList keychain;
		keychain.newUser("Admin", "password", 666);
		keychain.deleteUser(666);
		keychain.display();
	}

	{
		UserList keychain;
		keychain.newUser("JohnnyAppleseed", "apples123", 123);
		keychain.display();
	}

	{
		UserList keychain;
		cout << "Creating keychain...\n"
			<< "Press 'q' to quit at any time\n";

		while (true) {
			string username, password;
			int id;
			cout << "Add users\n"
				<< "example: John password123 420\n";
		

			cin >> username;
			if (username == "q" || username == "") {
				cout << "Quitting.\n";
				break;
			}
			else {
				cin >> password >> id;
				keychain.newUser(username, password, id);
				cout << username << " added.\n";
			}
			keychain.display();
		}
	}

	cout << endl;
	system("Pause");
	return 0;
}