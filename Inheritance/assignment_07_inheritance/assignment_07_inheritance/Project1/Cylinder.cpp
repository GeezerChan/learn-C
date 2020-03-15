/*
	Blood, William

	March 7, 2020

	CS A250
	Lab 7
*/

#include "Cylinder.h"

#include <iostream>
using namespace std;

// Class implementation
// Your code here...

Cylinder::Cylinder()
{
    height = 0.0;
}

Cylinder::Cylinder(double r, double pi, double h)
    : Circle(r, pi)
{
    height = h;
}

double Cylinder::getHeight() const { return height; }
void Cylinder::setHeight(double h) { height = h; }

double Cylinder::calculateVolume() const
{
    return calculateArea() * height;
}

void Cylinder::printDimensions() const
{
    Circle::printDimensions();
    cout << "Height: " << height << endl;
}

Cylinder::~Cylinder() {}
