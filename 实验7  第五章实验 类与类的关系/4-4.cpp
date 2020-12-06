#include <iostream>

using namespace std;

class X
{
public:
	X()
	{
		cout << "X::X() constructor executing\n";
	}
	~X()
	{
		cout << "X::~X() destructor executing\n";
	}
};

class Y: public X
{
public:
	Y()
	{
		cout << "Y::Y() constructor executing\n";
	}
	~Y()
	{
		cout << "Y::~Y() destructor executing\n";
	}
};

class Z : public Y
{
public:
	Z()
	{
		cout << "Z::Z() constructor executing\n";
	}
	~Z()
	{
		cout << "Z::~Z() destructor executing\n";
	}
};

int main()
{
	Z z;
	return 0;
}