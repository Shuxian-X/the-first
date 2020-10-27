#include <iostream>
#include <cstdio>
#include <ctime>
#include <iomanip> 
#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-6;

double f(double &x)
{
	return  (x + 9)*(x + 10)*(x - 4)*(x - 7);
}

double found(double &l, double &r)
{
	double mid = (l + r) / 2;
	while (fabs(f(mid)) > eps) {
		if (f(l)*f(mid) < 0)
			r = mid;
		else
			l = mid;
		mid = (l + r) / 2;
	}
	return mid;
}

int main()
{
	double l, r, tl, tr;
	cout << "please enter left and right boundaries:\n";
	cin >> l >> r;
	tl = l, tr = r;
	srand(int(time(NULL)));
	while (f(tl)*f(tr) > 0) {
		tl = l + rand() / (RAND_MAX + 1.0)*(r - l);
		tr = l + rand() / (RAND_MAX + 1.0)*(r - l);
	}
	double root = found(tl, tr);
	cout << "one root of function f(x) is: " << root << endl;
}