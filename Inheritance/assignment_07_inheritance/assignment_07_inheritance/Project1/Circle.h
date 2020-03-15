/*
    Blood, William

    March 7, 2020

    CS A250
    Lab 7
*/

#ifndef CIRCLE_H
#define CIRCLE_H

// Class definition
// Your code here...
class Circle
{
public:
    Circle();
    Circle(double, double);

    double getRadius() const;
    double getPi() const;

    void setRadius(double);
    void setPi(double);

    double calculateArea() const;
    void printDimensions() const;

    ~Circle();
private:
    double radius;
    double pi;
};

#endif
