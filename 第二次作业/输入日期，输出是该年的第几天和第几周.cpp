#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };  //定义数组记录每个月的天数

bool judge(int y)
{
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) //判断是否为闰年，闰年二月 29 天
		return 1;
	return 0;
}

void fun(int y, int m, int d)
{
	int day = 0, week = 0;
	if (judge(y)) { //如果为闰年，把二月天数改为 29
		month[2] = 29;
		for (int i = 1; i < m; ++i) //计算本月之前有多少天
			day += month[i];
		day += d; //加上本月已有天数
	}
	else {
		month[2] = 28;
		for (int i = 1; i < m; ++i)
			day += month[i];
		day += d;
	}
	week = day / 7; //计算周数
	if (day % 7)
		++week;
	printf("This is the %d day of the year, the %d week of the year.\n", day, week);
}

int main()
{
	int y, m, d;
	cout << "Please enter the date in the format:\n";
	scanf("%d-%d-%d", &y, &m, &d);
	fun(y, m, d);
	return 0;
}