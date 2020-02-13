#include "User.h"
#include <iostream>

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
		keychain.newUser("Billy");
		keychain.newUser("Sofie");
		keychain.display();
	}

	{
		UserList keychain;
		keychain.newUser("Billy", "wb0710");
		keychain.newUser("Sophie", "bentley@2172001");
		keychain.newUser("Bentley", "Doggyrockwood94", 69);
		keychain.display();
	}

	cout << endl;
	system("Pause");
	return 0;
}