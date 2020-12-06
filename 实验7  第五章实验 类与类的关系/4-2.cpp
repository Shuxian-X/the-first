#include <iostream>

using namespace std;

class A
{
	int n;
public:
	A(int x)
	{
		n = x;
		cout << "construting A, n = " << n << endl;
	}
	~A()
	{
		cout << "destructing A, n = " << n << endl;
	}
};

class B
{
	int n;
	A a;
public:
	B(int x, int y): a(x) //有参在初始化列表中解决 
	{
		n = y;
		cout << "construting B, n = " << n << endl;
	}
	~B()
	{
		cout << "destructing B, n = " << n << endl;
	}
};

class C
{
	int n;
	A a;
	B b;
public:
	C(int x, int y, int z) : a(x * 2), b(x, y)
	{
		n = z;
		cout << "construting C, n = " << n << endl;
	}
	~C()
	{
		cout << "destructing C, n = " << n << endl;
	}
};
int main()
{
	C obj(5, 6, 7);
	return 0;
}
