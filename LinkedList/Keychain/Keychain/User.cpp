#include "User.h"
#include <iostream>

void UserList::newUser(const string& name) {
	head = new User(name, head);	// 
	count++;
}

void UserList::newUser(const string& name, const string& password) {
	head = new User(name, head, password);	// 
	count++;
}

void UserList::newUser(const string& name, const string& password, int id) {
	head = new User(name, head, password, id);	// 
	count++;
}

void UserList::display() {
	if (head == nullptr) cerr << "Keychain empty." << endl;
	else {
		User* selector = head;

		cout << "~~~~~~~~~ Keychain ~~~~~~~~~\n\n";
		while (selector != nullptr) {
				cout << "User ID: [" << selector->getUserID() << "]\n"
				<< "Username: [" << selector->getUsername() << "]\n"
				<< "Password: [" << selector->getPassword() << "]\n"
				<< endl;
			selector = selector->getNext(); // Switches link to next user
		}
	}
}

UserList::~UserList()
{
	// destroyList()
}

User::~User(){}