#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "student.h"
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 16;

int cnt = 0;

void menu() //����˵�����
{
	cout << "****************1.¼����Ϣ****************" << endl;
	cout << "****************2.��ѯ��Ϣ****************" << endl;
	cout << "****************3.�����Ϣ****************" << endl;
	cout << "****************4.�޸���Ϣ****************" << endl;
	cout << "****************0.��    ��****************" << endl;
}

void Output_stu(Student *array) //�����������Ԫ��
{
	cout << "ѧ�������� = " << cnt << endl << endl;
	for (int i = 0; i < cnt; ++i)
		array[i].Display();
}

void Input_stu(Student *array) //�����������Ԫ��
{
	char ch;
	do
	{
		array[cnt].Input();
		++cnt;
		cout << "���������� ��Y or N��" << endl << endl;
		cin >> ch;
	} while (ch == 'Y');
}

int Search_stu(Student *array, char *na) //��������ѯ
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
					cout << "���޴���" << endl << endl;
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
					cout << "���޴���" << endl << endl;
				else 
					array[i].Change(num, grade);
				cout << endl;
				break;
			}
		}
	} while (choice);

	return 0;
}

