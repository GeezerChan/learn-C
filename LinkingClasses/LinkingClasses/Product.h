/*
	Blood, William

	February 4, 2020

	CS A250
	Practice
*/

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product {
public:
	Product();
	Product(const string& newName, int newID, double newPrice);
	void setPrice(double newPrice);
	void print() const;
	double getPrice() const;
	string getName() const;
	double getDiscountedPrice(double price) const;
	~Product();

private:
	std::string productName;
	int productID;
	double productPrice;

};

#endif