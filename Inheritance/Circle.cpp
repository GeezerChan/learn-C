#include "Circle.h"

#include <iostream>
using namespace std;

// Class implementation
// Your code here...
Circle::Circle()
{
    radius = 0.0;
    PI = 3.142;
}

Circle::Circle(double r, double pi)
{
    radius = 0.0;
    PI = 3.142;
}

double Circle::getRadius() const { return radius; }
double Circle::getPi() const { return PI; }

void Circle::setRadius(double r) { radius = r; }
void Circle::setPi(double pi) { PI = pi; }

double Circle::calculateArea() const
{
    return PI * (radius * radius);
}
void Circle::printDimensions() const
{
    cout << "Radius: " << radius << endl;
    cout << "Pi: " << PI << endl;
}

Circle::~Circle() {}