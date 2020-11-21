#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "student.h"
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 106;

class Stack
{
private:
	int top;
	double data[N];

public:
	Stack(); //���캯��
	~Stack();//��������

	void init(); //��ʼ��
	bool full(); //����
	bool empty(); //�п�
	void push(double &val); //��ջ
	double pop(); //��ջ
	int size(); //���С
	double get_top(); //��ջ��Ԫ��
};

Stack::Stack()//���캯��
{
	top = 0;
	memset(data, 0, sizeof data);
}

Stack::~Stack()//��������
{
}

void Stack::init() //��ʼ��
{
	top = 0;
	memset(data, 0, sizeof data);
}

bool Stack::full() //����
{
	if (top == N)
		return 1;
	return 0;
}

bool Stack::empty() //�п�
{
	if (top == 0)
		return 1;
	return 0;
}

void Stack::push(double & val) //��ջ
{
	data[top++] = val;
}

double Stack::pop() //��ջ
{
	return data[--top];
}

int Stack::size() //���С
{
	return top;
}

double Stack::get_top() //��ջ��Ԫ��
{
	return data[top-1];
}


int main()
{
	cout << "********ջ����������********" << endl;

	Stack sta;
	double tp = 0;
	while (!sta.full()) 
	{
		cout << "��ջ�����������ݣ�0��ֹ����";
		cin >> tp;
		if (!tp)
		{
			cout << "***********��ջ���!**********" << endl << endl;
			break;
		}
		sta.push(tp);
		cout << "�ɹ���ջ\n\n";
	}
	cout << "��ջ�����������ǰջ�� " << sta.size() << "��Ԫ�ز���ջ��\n";
	while (!sta.empty())
	{
		cout << sta.pop() << "  ";
	}
	cout << endl;
	return 0;
}