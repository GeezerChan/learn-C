#pragma once

#include <string>

using namespace std;

class User {
public:
	User() : username(""), password(""), userID(0), next(nullptr) {}
	User(const string& name, User* newNext) : username(name), next(newNext) {}
	User(const string& name, User* newNext, const string& pass) 
		: username(name), next(newNext), password(pass) {}
	User(const string& name, User* newNext, const string& pass, int id)
		: username(name), next(newNext), password(pass), userID(id) {}
	
	string getUsername() const { return username; }
	string getPassword() const { return password; }
	int getUserID() const { return userID; }

	void setUsername(const string& newName) { username = newName; }
	void setPassword(const string& newPassword) { username = newPassword; }
	void setUserID(int newUserID) { userID = newUserID; }

	User* getNext() { return next; }
	User* setNext(User* newNext) { next = newNext; }

	~User();
private:
	string username;
	string password;
	int userID;
	User* next;
};

class UserList
{
public:
	UserList() : head(nullptr), count(0) {}

	// Create a linked list
	void newUser(const string& newName);
	void newUser(const string& newName, const string& newPassword);
	void newUser(const string& newName, const string& newPassword, int id);

	void deleteUser(int id);

	void destroyList();

	void display() const;

	// Search through a linked list to find an elem
	// Insert new node
	// Delete a single element
	// Delete an entire linked list
	~UserList();

private:
	User* head;
	int count;
};

