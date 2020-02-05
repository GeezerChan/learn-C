/*
	Blood, William

	February 4, 2020

	CS A250
	Practice
*/

#include "Product.h"
#include <iostream>
#include <iomanip>

// Initialize variables
Product::Product() {
	productName = "Placeholder name";
	productID = 0;
	productPrice = 0.0;
}

Product::Product(const string& newName, int newID, double newPrice) {
	productName = newName;
	productID = newID;
	productPrice = newPrice;
}
void Product::setPrice(double newPrice) {
	productPrice = newPrice;
}

void Product::print() const {
	cout << "Product name: " << fixed << showpoint << setprecision(2)
		<< productName << "\nProduct ID: #"
		<< productID << "\nProduct price: $"
		<< productPrice << "\n";
}

string Product::getName() const {
	return productName;
}

double Product::getPrice() const {
	return productPrice;
}

double Product::getDiscountedPrice(double price) const {
	return productPrice - (productPrice * price);
}

Product::~Product() {

}