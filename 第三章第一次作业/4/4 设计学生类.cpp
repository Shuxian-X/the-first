#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "student.h"
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 16;

int cnt = 0;

void menu() //定义菜单函数
{
	cout << "****************1.录入信息****************" << endl;
	cout << "****************2.查询信息****************" << endl;
	cout << "****************3.浏览信息****************" << endl;
	cout << "****************4.修改信息****************" << endl;
	cout << "****************0.退    出****************" << endl;
}

void Output_stu(Student *array) //输出对象数组元素
{
	cout << "学生总人数 = " << cnt << endl << endl;
	for (int i = 0; i < cnt; ++i)
		array[i].Display();
}

void Input_stu(Student *array) //输入对象数组元素
{
	char ch;
	do
	{
		array[cnt].Input();
		++cnt;
		cout << "继续输入吗？ （Y or N）" << endl << endl;
		cin >> ch;
	} while (ch == 'Y');
}

int Search_stu(Student *array, char *na) //按姓名查询
{
	for (int i = 0; i < cnt; ++i)
		if (strcmp(array[i].Get_name(), na) == 0)
			return i;
}

int main()
{
	Student array[N];
	int choice, i;
	do
	{
		menu();
		cout << "please input you choice: ";
		cin >> choice;
		if (choice >= 0 && choice <= 4)
		{
			switch (choice) 
			{
			case 1: Input_stu(array); break;
			case 2: cout << "Input the name searched" << endl;
				char na[20];
				cin >> na;
				i = Search_stu(array, na);
				if (i == N)
					cout << "查无此人" << endl << endl;
				else
					array[i].Display();
				break;
			case 3: Output_stu(array); break;
			case 4: cout << "Input the name, subject number, new grade: " << endl;
				int num;
				double grade;
				cin >> na >> num >> grade;
				i = Search_stu(array, na);
				if (i == N)
					cout << "查无此人" << endl << endl;
				else 
					array[i].Change(num, grade);
				cout << endl;
				break;
			}
		}
	} while (choice);

	return 0;
}

