#include <iostream>

using namespace std;

class X
{
public:
	void f()
	{
		cout << "X::f() executing\n";
	}
};

class Y: public X
{
public:
	void f()
	{
		cout << "Y::f() executing\n";
	}
};

int main()
{
	X x;
	Y y;

	X *p = &x;
	p->f();

	p = &y;
	p->f(); //复制兼容，Y中的f()算派生类新增成员，不可访问，所以调用的是基类X中的f()

	y.f(); //同名覆盖，调用Y中的f()

	return 0;
}