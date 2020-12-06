#include <iostream>

using namespace std;

class A
{
	int n;
public:
	A()
	{
		cout << "construting A" << endl;
	}
	~A()
	{
		cout << "destructing A" << endl;
	}
};

class B
{
	int n;
	A a;
public:
	B()
	{
		cout << "construting B" << endl;
	}
	~B()
	{
		cout << "destructing B" << endl;
	}
};

int main()
{
	B b;
	cout << "The end." << endl;
	return 0;
}