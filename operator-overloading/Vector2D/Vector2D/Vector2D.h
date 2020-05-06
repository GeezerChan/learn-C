/*
	Blood, William

	February 20, 2020

	CS A250
	Lab 6
*/

#ifndef VECTOR2D_H_
#define VECTOR2D_H_

#include <iostream>

class Vector2D {
	friend std::ostream& operator<<(std::ostream& out, const Vector2D& point);

public:
	Vector2D() : x(0), y(0) {}
	Vector2D(int newX, int newY) : x(newX), y(newY) {}

	int operator*(const Vector2D& rhs);
	bool operator==(const Vector2D& rhs);

	~Vector2D();
private:
	int x, y;
};

std::ostream& operator<< (std::ostream& out, const Vector2D& point) {
	out << "<" << point.x << "," << point.y << ">";
	return out;
}

int Vector2D::operator*(const Vector2D& rhs) {
	return (x* rhs.x) + (y * rhs.y);		// returns the dot product of 2 vectors
}

bool Vector2D::operator==(const Vector2D& rhs) {
	return (this->x == this->y && rhs.x == rhs.y);
}

Vector2D::~Vector2D(){}

#endif // !VECTOR2D_H_