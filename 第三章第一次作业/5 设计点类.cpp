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
	double x, y; //�ᡢ������
	char nm[6] = "Alice"; //����������

public:
	Point(double a = 0, double b = 0); //���캯��
	~Point(); //��������
	void Modify(double a = 0, double b = 0);  //�޸�����
	void Output(); //�������
	friend double distance1(Point& , Point& );  //���� distance1 ��Ϊ�� Point ����Ԫ��������a��b֮��ľ���
	friend Another;  //�� Another ��Ϊ�� Point ����Ԫ��
};

class Another
{
private:
	char *name;
	double u, v;

public:
	Another();//���캯��
	Another(const char *na, double a, double b);//���캯��
	~Another(); //��������
	double distance2(Point &);//�����
};

Point::Point(double a, double b)
{
	x = a;
	y = b;
}

Point::~Point()
{
}

void Point::Modify(double a, double b) //�޸�����
{
	x = a;
	y = b;
}

void Point::Output() //�������
{
	cout << "����Ϊ �� (" << x << ',' << y << ')' << endl << endl;
}

double distance1(Point &a, Point &b)//��a��b֮��ľ���
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

double Another::distance2(Point &obj)//��ǰ���� obj ֮��ľ���
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
