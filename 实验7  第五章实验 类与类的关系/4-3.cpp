#include <iostream>

using namespace std;

class A
{
public:
	A()
	{
		cout << 'A';
	}
};

class B
{
public:
	B()
	{
		cout << 'B';
	}
};

class C: public A
{
public:
	C()
	{
		cout << 'C';
	}
};

class D : public A, public B
{
public:
	D()
	{
		cout << 'D';
	}
};

class E :public B, public virtual C
{
public:
	D d;
	E()
	{
		cout << 'E';
	}
};

class F: public virtual C, public D, public E
{
public:
	C c, d;
	E e;
	F()
	{
		cout << 'F';
	}
};

int main()
{
	A a;
	cout << endl;
	B b;
	cout << endl;
	C c;
	cout << endl;
	D d;          //ABD 
	cout << endl;
	E e;          //ACBABDE 
	cout << endl;
	F f;          //ACABDBABDEACACACBABDEF 
	cout << endl;

	return 0;
}
