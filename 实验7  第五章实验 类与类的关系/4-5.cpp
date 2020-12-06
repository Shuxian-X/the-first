#include <iostream>

using namespace std;

class A
{
public:
	int n;
};

class B: virtual public A
{

};

class C : virtual public A
{

};

class D : public B, public C
{

};

inline void print(D &d)
{
	cout << "d.A::n = " << d.A::n << ", d.B::n = " << d.B::n;
	cout << ", d.C::n = " << d.C::n << ", d.D::n = " << d.n << endl;
}

int main()
{
	D d;
	d.A::n = 10;
	print(d);

	d.B::n = 20;
	print(d);

	d.C::n = 30;
	print(d);

	d.n = 40;
	print(d);

	return 0;
}