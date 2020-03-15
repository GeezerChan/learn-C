/*
	Blood, William

	March 7, 2020

	CS A250
	Lab 7
*/

#ifndef CYLINDER_H
#define CYLINDER_H

#include "Circle.h"

// Class definition
// Your code here...
class Cylinder : public Circle
{
public:
    Cylinder();
    Cylinder(double, double, double);

    double getHeight() const;
    void setHeight(double);

    double calculateVolume() const;
    void printDimensions() const;

    ~Cylinder();
private:
    double height;
};

#endif
