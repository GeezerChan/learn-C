/*
	Blood, William

	March 15, 2020

	CS A250
	Lab 9
*/

#include "MyClass.h"

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <ctime>
#include <queue>
#include <stack>

using namespace std;

// Declaration function printVector.
// The function passes a vector and prints all
// the elements on one line, separated by a space.
// Use an iterator and a FOR loop.
template<typename T>
void printVector(const vector<T>& v);

// Declaration function printList.
// The function passes a list and prints all
// the elements on one line, separated by a space.
// Use an iterator and a WHILE loop.
template<typename T>
void printList(const list<T>& l);

// Declaration of function fib.
// The function receives an integer as an index 
// and returns the fibonacci number in the series.
int fib(int n);

void showq(queue <int>& gq)
{
	queue<int> g = gq;
	while (!g.empty())
	{
		cout << '\t' << g.front();
		g.pop();
	}
	cout << '\n';
}


int main()
{
	

	{
		MyClass<int> MyObj;
	}

	{
		cout << endl;

		queue<int> q;
		q.push(1);
		q.push(3);
		q.push(8);

		queue<int> q2;
		q.push(2);
		q.push(4);
		q.push(6);

		queue<int> q3;

		while (!q.empty() && !q2.empty())
		{
			if (q.front() < q2.front())
			{
				q3.push(q.front());
				q.pop();
			}
			else
			{
				q3.push(q2.front());
				q2.pop();

			}
		}

		cout << "\nQ1: \n";

		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}

		cout << "\nQ2: \n";

		while (!q2.empty())
		{
			cout << q2.front() << " ";
			q2.pop();
		}

		cout << endl;

		cout << "\nQ3: \n";

		while (!q3.empty())
		{
			cout << q3.front() << " ";
			q3.pop();
		}

		cout << endl;


		// front
		// push (front val)
		// pop

		cout << endl;
	}


	{
		cout << endl;

		vector<int> v = { 10, 20 };
		v.reserve(10);
		for (int i = 0; i < 200; ++i)
			v.push_back(5);
		
		v.resize(7);

		v[v.size() - 3] = 1;
		v[v.size() - 2] = 2;
		v[v.size() - 1] = 3;

		v.resize(9, 6);

		for (auto e : v)
			cout << e << " ";
		cout << endl;

	}

	{
		queue <int> gquiz;
		gquiz.push(10);
		gquiz.push(20);
		gquiz.push(30);

		cout << "The queue gquiz is : ";
		showq(gquiz);

		cout << "\ngquiz.size() : " << gquiz.size();
		cout << "\ngquiz.front() : " << gquiz.front();
		cout << "\ngquiz.back() : " << gquiz.back();

		cout << "\ngquiz.pop() : ";
		gquiz.pop();
		showq(gquiz);

		return 0;
	}


	/***************************************************************************
			VECTORS
	***************************************************************************/
	cout << "  ***  STL VECTOR CLASS  ***  \n\n";

	// Use the default constructor to declare an integer vector v1.
	vector<int> v1;

	// void push_back (const value_type& val);
	// Use function push_back to insert the following values in v1: 12, 73, 41,
	// 38, 25, 56, an 63 in this order.
	v1.push_back(12);
	v1.push_back(73);
	v1.push_back(41);
	v1.push_back(38);
	v1.push_back(25);
	v1.push_back(56);
	v1.push_back(63);

	// size_type size() const noexcept;
	// Create a variable of type int named sizeV1 and store the size of the vector.
	// Use function size to retrieve the size of the vector. 
	// Make sure you cast the return value of the function size to the appropriate type.
	size_t sizeV1 = v1.size();

	// Use a FOR loop to print out the vector.
	// Do NOT use an iterator.
	for (const auto &elem : v1)
		cout << elem << " ";

	//void clear() noexcept;
	// Call the function clear on vector v1.
	v1.clear();

	// size_type size() const noexcept;
	// Call function size to print the size of v1.
	cout << v1.size() << endl;

	// size_type capacity() const noexcept;
	// Call function capacity to output the capacity of v1.
	cout << v1.capacity() << endl;

	// Create an array of integers containing: 10,11,12,13,14,15,16,17,18,19
	const int a[] = { 10,11,12,13,14,15,16,17,18,19 };

	// Use the default constructor to declare an integer vector v2.
	vector<int> v2;

	// void assign (InputIterator first, InputIterator last);
	// Use function assign to copy elements 12, 13, 14, 15, and 16 from the
	// array into v2.
	// One statement only.
	v2.assign(a, a + 6);

	// Call the function printVector to print v2.
	printVector(v2);

	// const_reference back() const;
	// Use the function back output the last element in the vector
	// (Notice that the back function returns a reference.)
	cout << v2.back() << endl;
		
	// Use the default constructor to declare an integer vector v3.
	vector<int> v3;

	// void assign (size_type n, const value_type& val);
	// Use function assign to insert the values 7, 7, 7, 7, and 7.
	// One statement only.
	v3.assign(5, 7);

	// Call the function printVector  to print v3.
	printVector(v3);

	// const_reference at(size_type n) const;
	// Use function at to replace the middle element with 100.
	// (Notice that the at function returns a reference.)
	v3.at(v3.size() / 2) = 100;

	// Call the function printVector to print v3.
	printVector(v3);

	// vector (const vector& x);
	// Use the copy constructor to create a new vector v4 with the 
	// same elements of v3.
	vector<int> v4(v3);

	// Call the function printVector to print v4.
	printVector(v4);

	// Create an iterator iterVector4 to point to the first element of v4.
	vector<int>::const_iterator iterVector4 = v4.cbegin();

	// Create an iterator iterVector2 to point to the second element of v2.
	vector<int>::const_iterator iterVector2 = v2.cbegin() + 1;

	// iterator insert (const_iterator position, InputIterator first, InputIterator last);
	// Use function insert to insert the second, third, and fourth element
	// of v2 as the first, second, and third element of v4.
	// (Notice that the insert function returns an iterator, 
	//   but if we do not intend to use it, we can ignore it.)
	v4.insert(iterVector4, iterVector2, iterVector2 + 4);

	// Call the function printVector to print v4.
	printVector(v4);

	// iterator insert (const_iterator position, size_type n, const value_type& val);
	// Use the function insert to insert three 0s at the end of v4.
	// (Notice that the insert function returns an iterator, 
	//   but if we do not intend to use it, we can ignore it.)
	v4.insert(v4.end(), { 0, 0, 0 });

	// Call the function printVector to print v4.
	printVector(v4);

	// bool empty() const noexcept;
	// const_reference back() const;
	// void pop_back();
	// Use a WHILE loop to remove and output each element of v2 backwards.
	// Use function empty for the loop condition, function back to output 
	// the last element, and function pop_back to remove elements.
	// (Notice that the insert function returns an iterator, 
	//   but if we do not intend to use it, we can ignore it.)
	cout << "Removing: ";
	while (!v2.empty())
	{
		cout << v2.back() << " ";
		v2.pop_back();
	}
	cout << endl;

	// void resize (size_type n, const value_type& val);
	// Use function resize to insert three times number
	// 4 into v2.
	v2.resize(3, 4);

	// Call the function printVector to print v2.
	printVector(v2);

	// const_reference front() const;
	// Use function front to output the first element in v4.
	// (Notice that the front function returns a reference.)
	cout << v4.front() << endl;

	// void swap (vector& x);
	// Use function swap to swap v2 with v4.
	v2.swap(v4);

	// Call the function printVector to print v2.
	printVector(v2);

	// Create a new vector v5;
	vector<int> v5;

	// Use the overloaded assignment operator to copy all the elements of v2
	// into v5.
	v5 = v2;

	// void resize (size_type n);
	// size_type size() const noexcept;
	// Delete the last element of v5 by using the functions resize and size
	v5.resize(v5.size() - 1);

	// Call the function printVector to print v5.
	printVector(v5);

	// Create an iterator iterVector5 to point to the first element of v5.
	vector<int>::const_iterator iterVector5 = v5.cbegin();

	// iterator erase (const_iterator first, const_iterator last);
	// size_type size() const noexcept;
	// Call the function erase to delete the second half of v5.
	// Use function size to get the range.
	// (Notice that the insert function returns an iterator, 
	//   but if we do not intend to use it, we can ignore it.)
	v5.erase(iterVector5 + (v5.size() / 2), v5.end());

	// Call the function printVector to print v5 again.
	printVector(v5);

	// iterator erase (const_iterator position);
	// Call the function erase to delete the first element of the vector.
	// (Notice that the insert function returns an iterator, 
	//   but if we do not intend to use it, we can ignore it.)
	v5.erase(iterVector5);

	// Call the function printVector to print v5 again.
	printVector(v5);

	// Create a vector of integers named v6 containing numbers from 100 to 105.
	// Using the copy constructor, create a vector named v7, a copy of v6.
	const vector<int> v6 = { 100, 101, 102, 103, 104, 105 };
	vector<int> v7(v6);

	// iterator erase (const_iterator position);
	// iterator insert (const_iterator position, const value_type& val);
	// Erase element 103 from v7 and insert element 333 in its place, 
	// by using an iterator.
	// Note that the function erase returns an iterator that can be used
	// to insert 333 in the right position.
	auto posOfDeletedElem = v7.erase(v7.begin() + 3);
	v7.insert(posOfDeletedElem, 333);

	// Using a range-based FOR loop, print the elements of v7.
	for (auto elem : v7)
		cout << elem << " ";

	/***************************************************************************
			LISTS
	***************************************************************************/

	cout << "\n\n----------------------------------------------------";
	cout << "\n  ***  STL LIST CLASS  ***  \n\n";

	// Use the default constructor to create three lists of integers, intList1,
	// intList2, and intList3.
	list<int> intList1, intList2, intList3;

	// void push_back (const value_type& val);
	// Use the function push_back to insert the following values in the first list: 
	// 23 58 58 58 36 15 15 93 98 58
	intList1.push_back(23);
	intList1.push_back(58);
	intList1.push_back(58);
	intList1.push_back(58);
	intList1.push_back(36);
	intList1.push_back(15);
	intList1.push_back(15);
	intList1.push_back(93);
	intList1.push_back(98);
	intList1.push_back(58);

	// Call function printList to print intList1.
	printList(intList1);

	// Using the overloaded assignment operator, copy elements of intList1 into intList2.
	intList2 = intList1;

	// Call function printList to print intList2.
	printList(intList2);

	// void sort();
	// Using function sort, sort all elements in the second list.
	intList2.sort();

	// Call function printList to print intList2.
	printList(intList2);

	// void unique();
	// Using function unique, remove all consecutive duplicates in the list.
	intList2.unique();

	// Call function printList to print intList2.
	printList(intList2);
			
	// void push_back (const value_type& val);
	//Insert the following elements in the third list:
	//  13 23 25 136 198
	intList3.push_back(13);
	intList3.push_back(23);
	intList3.push_back(25);
	intList3.push_back(136);
	intList3.push_back(198);

	// Call function printList to print intList3.
	printList(intList3);

	// void merge (list& x);
	// Add to the second list all elements of the third list.
	// --> This is ONE statement only.
	intList2.merge(intList3);

	// Call function printList to print intList2.
	printList(intList2);

	/*************************************************************************
	*		Create statements using the functions below.
	*       You might need to create new containers.
	*		Is the output what you expected?
	*************************************************************************/
	cout << "\n\n----------------------------------------------------";
	cout << "\n  ***  OTHER FUNCTIONS  ***  \n\n";

	// list: void assign (size_type n, const value_type& val);
	list<int> list1 = { 6, 2, 18, 0, 5, 0, 2};

	list1.assign(list1.size(), NULL);	// nulls all elements
	printList(list1);

	// vector: void assign (InputIterator first, InputIterator last);
	vector<int> vector1;
	vector1.assign(list1.begin(), list1.end());	// copies entire list into the vector

	// list: const_reference back() const;
	// (Notice that this back function returns a reference.)
	vector1.back() = 13;	// replaces the last 0 with 13

	// list: void clear() noexcept;
	vector1.clear();

	// list: bool empty() const noexcept;
	if (vector1.empty()) 
		cerr << "List is empty" << endl;


	// vector: const_reference front() const;
	vector1.push_back(666);
	vector1.front() = 6;	// replace 666 with 6

	// list: iterator insert (const_iterator position, const value_type& val);
	// (Notice that the insert function returns an iterator.)
	list1.insert(list1.begin(), 99); // inserts 99 in front of 6
	printList(list1);

	// list: void pop_back();
	list1.pop_back();

	// list: void pop_front();
	list1.pop_front();

	// list: void push_front (const value_type& val);
    
	srand( (unsigned)time(NULL) );	// initializes seed
    
	// adds 15 random fib numbers to the list ranging from 1 - 10

	int count = 15;     // Change this value to increase your chances!
    
	while (count-- > 1)
		list1.push_front( fib(rand() % 10 + 1) );

	// expected: double digit fibs will tend to show up at the end of list
	printList(list1);

	// list: void remove (const value_type& val);
	list1.remove(0);	// removes all zeroes
	printList(list1);

	// list: void reverse() noexcept;
	list1.reverse();	// descending order.
	printList(list1); 

	// list: void splice (const_iterator position, list& x);
	list<int> list3 = { fib(13), fib(12), fib(11), fib(10) };

	list1.splice(list1.begin(), list3);		// connects the remaining fibonacci numbers from list3.
	printList(list1);

	// list: void splice (const_iterator position, list& x, const_iterator i);
	// empties list3 into the middle of list1.
	list3.resize(1, fib(14));

	list<int>::iterator listIter1 = list1.begin();
	advance(listIter1, list1.size() / 2);   // preps iterator insertion point

	list1.splice(listIter1, list3, list3.begin());
    
    printList(list1);

	// list: void splice (const_iterator position, list& x, const_iterator first, const_iterator last);
	// merges a new list of 0's and sorts the list into a proper fibonacci sequence
	// in ascending order.
	list3.resize(5, NULL);

	list<int>::const_iterator listIter3 = list3.cbegin();
	list<int>::const_iterator listIter3End = list3.cend();
	listIter1 = list1.end();

	list1.splice(listIter1, list3, listIter3, listIter3End);	// empties list3 into the main list.

	cout << "list3: ";
	printList(list3);

	list1.sort();
	list1.unique();
        
	cout << "expected : 0 1 2 3 5 8 13 21 34 55 89 144 233 377 610 (If you're lucky!)\n"
		<< "Your list: ";
	printList(list1);
	
	// If you're lucky, final list will contain every fibonacci number in order.
	// Tip: increase your chances by increasing the value of count.

	cout << "\n\n----------------------------------------------------";

	cout  <<  endl;
	system("Pause");
	return 0;
}

// Definition function printVector

template<typename T>
void printVector(const vector<T>& v)
{
	if (v.empty())
	{
		cerr << "Vector is empty." << endl;
		return;
	}

	auto iter= v.cbegin();
	auto iterEnd = v.cend();

	for (iter; iter != iterEnd; ++iter)
		cout << *iter << " ";
	cout << endl;
}


// Definition function printList

template<typename T>
void printList(const list<T>& l)
{
	if (l.empty())
	{
		cerr << "List is empty." << endl;
		return;
	}

	auto iter = l.cbegin();
	auto iterEnd = l.cend();

	while (iter != iterEnd)
		cout << *(iter++) << " ";
	cout << endl;
}

// Returns the upper-bound of the desired fibonacci number in the series.
// fibonacci series: 1, 1, 2, 3, 5, 8, 13, 21...
// ex. fib(6) -> 13
int fib(int n)
{
	if (n <= 1)
		return 1;
	return fib(n - 2) + fib(n - 1);
}
