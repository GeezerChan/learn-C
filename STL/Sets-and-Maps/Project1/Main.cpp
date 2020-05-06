/*
	Blood, William

	April 7, 2020

	CS A250
	Lab 10
*/

#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

// Declaration function printSet.
// The function is passed a list and prints all
// the elements on one line, separated by a space.
// Use a range-based FOR loop. If you do not know
// what this means, search the Web.
template<typename T>
void printSet(const set<T>& s);

int main()
{

	/***************************************************************************
			SETS
	***************************************************************************/
	cout << "  ***  STL SET CLASS  ***  \n\n";

	// Create a set of ints named set1 and use the initializer list to
	// insert the following integers in this order:
	// 2, 7, 5, 6, 9, 1 and 3.
	set<int> set1 = { 2, 7, 5, 6, 9, 1, 3 };

	// Print the set using the printSet function you implemented.
	cout << "\n1 2 3 5 6 7 9 --> ";
	printSet(set1);

	// What do you notice in the printout?
	// There's more instructions.

	// size_type erase (const value_type& val);
	// Use the function erase to erase the integer 2 from set1, but this
	// time use cout to print the return value.  What is the return
	// value?
	cout << "\nremoving 2.. --> ";
	cout << set1.erase(2) << endl;	// returns true (1) if successful

	// If you do not know what the return value is, then
	// check set::erase in cplusplus.com
	cout << endl;

	// Print set1.
	cout << "\n1 3 5 6 7 9 |" << endl;
	printSet(set1);

	// iterator erase (const_iterator position);
	// This function is different from the previous one, because
	// instead of passing a value, it passes a position indicated
	// by an iterator.  Delete the second element in the set
	// without creating an iterator variable, but do use the
	// prefix increment operator.
	set1.erase(++set1.begin());

	// Print set1.
	cout << "\n1 5 6 7 9 |" << endl;
	printSet(set1);

	// pair<iterator,bool> insert (const value_type& val);
	// Use the function insert to insert 4 and 8 in set1.
	set1.insert(4);
	set1.insert(8);

	// Print set1.
	cout << "\n1 4 5 6 7 8 9 |" << endl;
	printSet(set1);
	
	set<int>::iterator first = set1.begin();
	set<int>::iterator second = ++set1.begin();
	// iterator  erase(const_iterator first, const_iterator last);
	// Use function erase to delete the first and second element
	// in set1. Use the given iterators created above.
	// Note that you should write one statement only.
	set1.erase(first, ++second);

	// Print set1.
	cout << "\n5 6 7 8 9 |" << endl;
	printSet(set1);
	// Your output should be: 5 6 7 8
	// If it is not, you need to carefully view the function erase
	// to understand how it works.

	cout << "\n\n----------------------------------------------------";
	cout << "\n\nThe output for the next sections depends on your implementation.";
	

	/***************************************************************************
	MAPS
	***************************************************************************/
	cout << "\n\n----------------------------------------------------";
	cout << "\n  ***  STL MAP CLASS  ***  \n\n";

	// Create a few maps using the different constructors shown in the slides.
	// Use the following functions to manipulate the maps:
	// pair<iterator,bool> insert (const value_type& val);
	// void insert (InputIterator first, InputIterator last);
	// iterator  erase(const_iterator position);
	// size_type erase(const key_type& k);
	// iterator  erase(const_iterator first, const_iterator last);
	// Print each map without creating a print function, but by using
	// a loop.


	cout << "\n\n----------------------------------------------------";

	cout  <<  endl;
	system("Pause");
	return 0;
}

// Definition function printSet
template<typename T>
void printSet(const set<T>& s)
{
	if (s.empty())
	{
		cerr << "Container is empty." << endl;
		return;
	}

	for (auto elem : s)
		cout << elem << " ";
	cout << endl;
}
