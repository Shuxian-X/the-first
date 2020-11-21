#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "student.h"
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

class Another;

class Point
{
private:
	double x, y; //横、纵坐标
	char nm[6] = "Alice"; //这个点的名字

public:
	Point(double a = 0, double b = 0); //构造函数
	~Point(); //析构函数
	void Modify(double a = 0, double b = 0);  //修改坐标
	void Output(); //输出坐标
	friend double distance1(Point& , Point& );  //函数 distance1 作为类 Point 的友元函数，求a、b之间的距离
	friend Another;  //类 Another 作为类 Point 的友元类
};

class Another
{
private:
	char *name;
	double u, v;

public:
	Another();//构造函数
	Another(const char *na, double a, double b);//构造函数
	~Another(); //析构函数
	double distance2(Point &);//求距离
};

Point::Point(double a, double b)
{
	x = a;
	y = b;
}

Point::~Point()
{
}

void Point::Modify(double a, double b) //修改坐标
{
	x = a;
	y = b;
}

void Point::Output() //输出坐标
{
	cout << "坐标为 ： (" << x << ',' << y << ')' << endl << endl;
}

double distance1(Point &a, Point &b)//求a、b之间的距离
{
	return  sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

Another::Another()
{
	name = NULL;
}

Another::Another(const char * na, double a, double b)
{
	if (na)
	{
		name = new char[strlen(na) + 1];
		strcpy(name, na);
	}
	u = a;
	v = b;
}

Another::~Another()
{
	if (name)
		delete[]name;
}

double Another::distance2(Point &obj)//求当前点与 obj 之间的距离
{
	cout << "name1 = " << obj.nm << ", x = " << obj.x << ", y = " << obj.y << endl;
	cout << "name2 = " << name << ", x = " << u << ", y = " << v << endl;
	double dis = sqrt((obj.x - u)*(obj.x - u) + (obj.y - v)*(obj.y - v));
	cout << "distance is = " << dis << endl << endl;
	return dis;
}


int main()
{
	Point a(3, 4);
	Point b(9, 25);
	Another c("Cindy", 1.0, 1.0);
	double dis = distance1(a, b);
	cout << "the distance between a and b is: " << dis << endl << endl;
	c.distance2(a);
	return 0; 
}
