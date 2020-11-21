
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-6;

class Triangle
{
private:
	double a, b, c, s; //各边边长, 面积

public:
	Triangle(double x = 3, double y = 4, double z = 5);
	~Triangle();
	bool judge_tri();  //判断能否构成三角形
	double C(); //输出三角形周长
	double S(); //输出三角形面积
	void judge_type(); //输出三角形类型（直角，锐角，还是钝角三角形）
};

Triangle::Triangle(double x, double y, double z)//判断能否构成三角形 
{
	a = x;
	b = y;
	c = z;
}

Triangle::~Triangle()
{
}

bool Triangle::judge_tri() //输出三角形周长
{
	if (a + b > c && a + c > b && b + c > a)
		return 1;
	return 0;
}

double Triangle::C() //输出三角形面积
{
	if (!judge_tri())
	{
		cout << "No triangle!\n\n";
		return 0;
	}
	cout << "The circumference of the triangle is  " << a + b + c << endl << endl;
	
	return a + b + c;
}

double Triangle::S() //输出三角形面积
{
	if (!judge_tri())
	{
		cout << "No triangle!\n\n";
		return 0;
	}
	double p = (a + b + c) / 2.0;
	s = sqrt(p*(p - a)*(p - b)*(p - c));
	cout << "The area of the triangle is  " << s << endl << endl;
	
	return s;
}

void Triangle::judge_type() //输出三角形类型（直角，锐角，还是钝角三角形）
{
	if (!judge_tri())
	{
		cout << "No triangle!\n\n";
		return;
	}
	double mn = min(a, min(b, c)), mx = max(a, max(b, c));
	double md = a + b + c - mn - mx;
	if (fabs(mn * mn + md * md) - mx * mx < eps) 
	{
		cout << "The type is right-angled triangle!\n\n";
	}
	else if((mn * mn + md * md) < mx * mx)
	{
		cout << "The type is acute triangle!\n\n";
	}
	else
	{
		cout << "The type is obtuse triangle!\n\n";
	}
}

int main()
{
	Triangle t(6, 8, 10);
	if (t.judge_tri())
		cout << "It can form a triangle!\n\n";
	else
		cout << "It can't form a triangle!\n\n";
	t.C();
	t.S();
	t.judge_type();
	
	return 0;
}
