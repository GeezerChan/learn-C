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
public:
	Vector2D() : x(0), y(0) {}
	Vector2D(int newX, int newY) : x(newX), y(newY) {}

	friend int operator*(					// provide read access only to overloaded operators
		const Vector2D& lhs, const Vector2D& rhs
	);

	friend bool operator==(
		const Vector2D& lhs, const Vector2D& rhs
	);

	friend std::ostream& operator<<(
		std::ostream& out, const Vector2D& point
	);

	~Vector2D();
private:
	int x, y;
};

std::ostream& operator<< (std::ostream& out, const Vector2D& point) {
	out << "<" << point.x << "," << point.y << ">";
	return out;
}

int operator*(const Vector2D& lhs, const Vector2D& rhs) {
	return (lhs.x * rhs.x) + (lhs.y * rhs.y);		// returns the dot product of 2 vectors
}

bool operator==(const Vector2D& lhs, const Vector2D& rhs) {
	return (lhs.x == lhs.y && rhs.x == rhs.y);
}

Vector2D::~Vector2D(){}

#endif // !VECTOR2D_H_