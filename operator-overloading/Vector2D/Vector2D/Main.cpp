#include "Vector2D.h"

#include <iostream>
#include <string>
using namespace std;

Vector2D func()
{
	Vector2D v1(6, 6);
	return v1;
}

int main()
{
	Vector2D x;

	Vector2D y(x);
	//Vector2D y = x;
	//y = x;
	//x = func();


	cout << endl;
	system("Pause");
	return 0;
}

