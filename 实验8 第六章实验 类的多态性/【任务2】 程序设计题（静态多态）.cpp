#include<iostream>
using namespace std;

class Array
{
private:
	int size;
	int *ps;
public:
	Array();
	Array(int sz);
	Array(const Array &);
	~Array();

	void print();//输出对象内容
	int Size() const;//得到数组大小
	void modify(int pos, int target);//位置，修改后大小

	Array & operator = (const Array &);//实现数组对象的赋值操作

	Array operator + (const Array &);//加法操作（成员函数）
	Array operator++();//自增操作
	Array &operator+=(const Array &);

	friend Array operator - (const Array &, const Array &);//减法操作（友元函数）
	friend Array operator--(Array &);

};

Array::Array()
{
}

Array::Array(int sz)
{
	size = sz;
	ps = new int[size];
	for (int i = 0; i < size; ++i)
		ps[i] = i;
}

Array::Array(const Array &a)
{
	size = a.size;
	ps = new int[size];
	for (int i = 0; i < size; ++i)
		ps[i] = a.ps[i];
}

Array::~Array()
{
	delete[]ps;
}

void Array::print()//输出对象内容
{
	cout << "size = " << size << endl;
	cout << "the array = ";
	for (int i = 0; i < size; ++i)
		cout << ps[i] << ", ";
	cout << endl << endl;
}

int Array::Size() const//得到数组大小
{
	return size;
}

void Array::modify(int pos, int target)//位置，修改后大小
{
	ps[pos] = target;
}

Array & Array::operator=(const Array &a)//实现数组对象的赋值操作
{
	if (ps)
		delete[]ps;
	if (a.size)
	{
		size = a.size;
		ps = new int[size];
		for (int i = 0; i < size; ++i)
			ps[i] = a.ps[i];
	}
	else
		size = 0;
	return *this;
}

Array Array::operator+(const Array &a)//加法操作（成员函数）
{
	int tp = size < a.size ? size : a.size;
	if (tp == size)
	{
		Array arr(a); 
		for (int i = 0; i < tp; ++i)
			arr.ps[i] += ps[i];
		return arr;
	}
	else
	{
		Array arr(*this);
		for (int i = 0; i < tp; ++i)
			arr.ps[i] += a.ps[i];
		return arr;
	}
}

Array Array::operator++()//自增操作
{
	for (int i = 0; i < size; ++i)
		++ps[i];
	return *this;
}

Array & Array::operator+=(const Array &a)
{
	int tp = size < a.size ? size : a.size;
	for (int i = 0; i < tp; ++i) 
		ps[i] += a.ps[i];
	return *this;
}

Array operator-(const Array &a, const Array &b)//减法操作（友元函数）
{
	int tp = b.size < a.size ? b.size : a.size;
	if (tp == b.size)
	{
		Array arr(a);
		for (int i = 0; i < tp; ++i)
			arr.ps[i] -= b.ps[i];
		return arr;
	}
	else
	{
		Array arr(b);
		for (int i = 0; i < tp; ++i)
			arr.ps[i] -= a.ps[i];
		return arr;
	}
}

Array operator--(Array &a)//自减操作
{
	for (int i = 0; i < a.size; ++i)
		--a.ps[i];
	return a;
}


int main()
{
	Array a(6), b(8), c(10);
	cout << "a: ";
	a.print();
	cout << "b: ";
	b.print();
	cout << "c: ";
	c.print();

	Array d;
	d = a + b + c;
	cout << "after d = a+b+c,  d: \n";
	d.print();

	a += b;
	cout << "after a += b, a: \n";
	a.print();

	a.modify(3, 300);
	cout << "after change the element at position 3 to 300, a:\n";
	a.print();

	++a;
	cout << "after ++a, a:\n";
	a.print();

	--b;
	cout << "after --b, b:\n";
	b.print();

	c = c - a;
	cout << "after c-a, c:\n";
	c.print();

	return 0;
}