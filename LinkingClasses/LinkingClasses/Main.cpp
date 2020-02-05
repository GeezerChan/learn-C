/*
	Blood, William

	February 4, 2020

	CS A250
	Practice
*/

#include "Product.h"
#include <iostream>


int main() {
	Product whiteSoap; // uses default constructor
	Product blackSoap("Black Soap", 666, 420.69);


	// ...
	blackSoap.setPrice(69.69);
	blackSoap.print();
	whiteSoap.print();

	cout << "\nPrice of " << whiteSoap.getName() << ": "
		<< whiteSoap.getPrice() << endl;

	cout << "\nDiscounted price: " << blackSoap.getDiscountedPrice(0.25);
	
	cout << endl;
	system("Pause");
	return 0;
}