#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

double fun(const double &a, const double &b, const double &c)
{
	double p = (a + b + c) / 2.0;
	double s = sqrt(p * (p - a) * (p - b) * (p - c));
	return s;
}

int main()
{
	double a, b, c;
	cout << "Please input three sides of triangle:\n";
	cin >> a >> b >> c;
	cout << "The area of the triangle is:\n";
	cout << fun(a, b, c) << "\n";
		return 0;
}