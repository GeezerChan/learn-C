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

void UserList::deleteUser(int id) {
	if (count == 0) cerr << "There are no users to delete.\n";
	else if (count == 1) {
		if (id == head->getUserID()) {
			cout << "Are you sure you wish to delete? (y/n)\n";
			string confirm;
			cin >> confirm;
			if (confirm == "y") {
				delete head;			// delete it
				head = nullptr;
				--count;
			}
			else {
				cout << "\nExiting.\n";
			}

		}
		else {
			cerr << "Could not find [" << id << "]\n";
		}
	}
	else {						// make a traversal pointer find&delete
		if (id == head->getUserID()) {
			cout << "Are you sure you wish to delete? (y/n)\n";
			string confirm;
			cin >> confirm;
			if (confirm == "y") {
				delete head;			// delete it
				head = nullptr;
				--count;
			}
			else {
				cout << "\nExiting.\n";
			}

		}
		else {
			User* selector = head;
			User* traversal = head->getNext();

			while (selector != nullptr) {
				if (id == head->getUserID()) {
					cout << "Are you sure you wish to delete? (y/n)\n";
					string confirm;
					cin >> confirm;
					if (confirm == "y") {
						delete head;			// delete it
						head = nullptr;
						--count;
					}
					else {
						cout << "\nExiting.\n";
					}
				}else {
					selector = traversal;
					traversal = traversal->getNext();
				}
			}
		}
	}
}

void UserList::display() const {
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