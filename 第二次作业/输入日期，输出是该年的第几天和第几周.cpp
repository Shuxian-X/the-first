#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };  //���������¼ÿ���µ�����

bool judge(int y)
{
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) //�ж��Ƿ�Ϊ���꣬������� 29 ��
		return 1;
	return 0;
}

void fun(int y, int m, int d)
{
	int day = 0, week = 0;
	if (judge(y)) { //���Ϊ���꣬�Ѷ���������Ϊ 29
		month[2] = 29;
		for (int i = 1; i < m; ++i) //���㱾��֮ǰ�ж�����
			day += month[i];
		day += d; //���ϱ�����������
	}
	else {
		month[2] = 28;
		for (int i = 1; i < m; ++i)
			day += month[i];
		day += d;
	}
	week = day / 7; //��������
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