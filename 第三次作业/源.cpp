//#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <algorithm>
using namespace std;

bool judge(const double &a, const double &b, const double &c)
{
	if ((a + b > c) && (a + c > b) && (b + c > a))
		return 1;
	return 0;
}

double C(const double &a, const double &b, const double &c)
{
	return a + b + c;
}

double S(const double &a, const double &b, const double &c)
{
	double tp = (a + b + c) / 2.0;
	return sqrt(tp * (tp - a) * (tp - b) * (tp - c));
}

bool cmp(const double &a, const double &b)
{
	return a > b;
}

void MaxC(double *len, const int num)
{
	sort(len, len + num, cmp);
	int flag = 0;
	int i, j, k;
	i = 0, j = 1, k = 2;
	while (k < num) {
		if (judge(len[i], len[j], len[k])) {
			flag = 1;
			cout << "最大周长: " << C(len[i], len[j], len[k]) << " \n边长分别为: " << len[i] << ",  " << len[j] << ",  " << len[k] << endl << endl;
			return;
		}
		++i;++j;++k;
	}
	if (!flag)
		cout << "当前木棍长度无法构成任何三角形!" << endl;
}

void MaxS(double *len, const int num)
{
	sort(len, len + num, cmp);
	int flag = 0;
	int i, j, k;
	i = 0, j = 1, k = 2;
	double tp, ans, a, b, c;
	ans = 0;
	while (k < num) {
		if (judge(len[i], len[j], len[k])) {
			flag = 1;
				tp = S(len[i], len[j], len[k]);
				if (tp > ans) {
					ans = tp;
						a = len[i];
						b = len[j];
						c = len[k];
				}
		}
		++i;++j; ++k;
	}
	if (flag)
		cout << "最大面积: " << ans << " \n边长为: " << a << ",  " << b << ",  " << c << endl << endl;
	else
		cout << "当前木棍长度无法构成任何三角形!" << endl;
}

int main()
{
	int m;
	cout << "-------------- 输入数据 --------------" << endl;
	cout << "请输入木棍的总个数:\n";
	cin >> m;
	double *len = new double[m];
	cout << "请依次输入 " << m << " 根木棍的长度" << endl;
	for (int i = 0; i < m; ++i)
		cin >> len[i];
	cout << endl << "-------------- 输出结果 --------------" << endl;
	/*----------------------------------*
		  1. 搜索最大周长,并输出周长
	*-----------------------------------*/
	MaxC(len, m);
	/*----------------------------------*
		  2. 搜索最大面积,并输出面积
	*-----------------------------------*/
	MaxS(len, m);
	delete[] len;
	system("pause");
	return 0;
}