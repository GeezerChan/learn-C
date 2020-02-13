#include "User.h"
#include <iostream>

void UserList::newUser(const string& name) {
	head = new User(name, head);	// 
	count++;
}

void UserList::display() {
	if (!count) cerr << "Keychain empty." << endl;
	else {
		User* selector = head;
		while (selector != nullptr) {
			cout << "~~~~~~~~~ Keychain ~~~~~~~~~\n\n"
				<< "User ID: [" << selector->getUserID() << "]\n"
				<< "Username: [" << selector->getUsername() << "]\n"
				<< "Password: [" << selector->getPassword() << "]\n"
				<< endl;
		}
	}
}

UserList::~UserList()
{
	// destroyList()
}