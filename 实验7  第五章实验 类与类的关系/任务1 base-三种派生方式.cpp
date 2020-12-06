#include <iostream>

using namespace std;

class Base
{
	static int cnt;
public:
	int a;
protected:
	int b;
private:
	int c;

public:
	Base()
	{
		++cnt;
		cout << "constructing Base, a = " << a << ", b = " << b << ", c = " << c << endl;
	}
	Base(int x, int y, int z)
	{
		++cnt;
		a = x;
		b = y;
		c = z;
		cout << "constructing Base, a = " << a << ", b = " << b << ", c = " << c << endl;
	}
	~Base()
	{
		--cnt;
		cout << "destructing Base, a = " << a << ", b = " << b << ", c = " << c << endl;
	}

	int get_a()
	{
		return a;
	}
	int get_b()
	{
		return b;
	}
	int get_c()
	{
		return c;
	}
	static int statistic();
};

int Base::cnt = 0;

class Derived1 : public Base
{
private:
	int d1;
public:
	Derived1()
	{
		// cout << "constructing Derived1, a = " << a << ", b = " << b << ", c = " << c << "d1 = " << d1 << endl;
		// 报错，私有数据 c 虽然被子类继承，但是不可见，即具有不可访问属性
		cout << "constructing Derived1, a = " << a << ", b = " << b << ", c = " << get_c() << ", d1 = " << d1 << endl;
	}
	Derived1(int x, int y, int z, int t) : Base(x, y, z)
	{
		d1 = t;
		// cout << "constructing Derived1, a = " << a << ", b = " << b << ", c = " << c << "d1 = " << d1 << endl;
		// 报错，私有数据 c 虽然被子类继承，但是不可见，即具有不可访问属性
		cout << "constructing Derived1, a = " << a << ", b = " << b << ", c = " << get_c() << ", d1 = " << d1 << endl;
	}
	~Derived1()
	{
		cout << "destructing Derived1, a = " << a << ", b = " << b << ", c = " << get_c() << ", d1 = " << d1 << endl;
	}
	int get_d1()
	{
		return d1;
	}
};

class Derived2 : protected Base 
{
private:
	int d2;
public:
	Derived2()
	{
		cout << "constructing Derived2, a = " << a << ", b = " << b << ", c = " << get_c() << ", d2 = " << d2 << endl;
	}
	Derived2(int x, int y, int z, int t) : Base(x, y, z)
	{
		d2 = t;
		cout << "constructing Derived2, a = " << a << ", b = " << b << ", c = " << get_c() << ", d2 = " << d2 << endl;
	}
	~Derived2() 
	{
		cout << "destructing Derived2, a = " << a << ", b = " << b << ", c = " << get_c() << ", d2 = " << d2 << endl;
	}
	int get_d2()
	{
		return d2;
	}
	int Get_a()
	{
		return a;
	}
	int Get_b()
	{
		return b;
	}
	int Get_c()
	{
		return get_c();// 通过派生类公有函数访问基类继承变为保护的成员函数，进而访问私有数据成员
	}
};

class Derived3 : private Base
{
private:
	int d3;
public:
	Derived3()
	{
		cout << "constructing Derived3, a = " << a << ", b = " << b << ", c = " << get_c() << ", d3 = " << d3 << endl;
	}
	Derived3(int x, int y, int z, int t) : Base(x, y, z)
	{
		d3 = t;
		cout << "constructing Derived3, a = " << a << ", b = " << b << ", c = " << get_c() << ", d3 = " << d3 << endl;
	}
	~Derived3()
	{
		cout << "destructing Derived3, a = " << a << ", b = " << b << ", c = " << get_c() << ", d3 = " << d3 << endl;
	}
	int get_d3()
	{
		return d3;
	}
};

int Base::statistic()
{
	return cnt;
}

int main()
{
	Base t(1, 2, 3);
	cout << "count = " << Base::statistic() << endl << endl;
	Derived1 x(4, 5, 6, 7);
	cout << "count = " << Base::statistic() << endl << endl;
	Derived2 y(8, 9, 10, 11);
	cout << "count = " << Base::statistic() << endl << endl;
	Derived3 z(12, 13, 14, 15);
	cout << "count = " << Base::statistic() << endl << endl;

	//cout << "x.a = " << x.a << ", x.b = " << x.b << "x.d1 = " << x.d1 << endl;
	// b, d1  不可直接访问
	cout << "x.a = " << x.a << ", x.b = " << x.get_b() << ", x.d1 = " << x.get_d1() << endl << endl;

	//cout << "y.a = " << y.a << endl;
	// a 不可直接访问
	//cout << "y.a = " << y.get_a() << endl;
	// get_a() 不可直接访问
	cout << "y.a = " << y.Get_a() << endl << endl;

	cout << "y.c = " << y.Get_c() << endl << endl;

	return 0;
}

