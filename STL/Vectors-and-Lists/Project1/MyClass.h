#ifndef MYCLASS_H_
#define MYCLASS_H_

template <typename T>
class MyClass
{
public:
	MyClass() : first(0), second(0) {}

private:
	T first;
	T second;
};

#endif // !MYCLASS_H_
