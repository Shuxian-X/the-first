#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

void swap(int *p1, int *p2)
{
	int tp;
	tp = *p1;
	*p1 = *p2;
	*p2 = tp;
}

int main()
{
	int a, b;
	cout << "Please enter two number to exchange:\n";
	cin >> a >> b;
	int *p1 = &a, *p2 = &b;
	swap(p1, p2);
	cout << "after exchange:\n";
	cout << a << ' ' << b << "\n";
	system("pause");
	return 0;
}