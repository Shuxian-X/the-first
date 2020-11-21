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
	Stack(); //构造函数
	~Stack();//析构函数

	void init(); //初始化
	bool full(); //判满
	bool empty(); //判空
	void push(double &val); //入栈
	double pop(); //出栈
	int size(); //求大小
	double get_top(); //求栈顶元素
};

Stack::Stack()//构造函数
{
	top = 0;
	memset(data, 0, sizeof data);
}

Stack::~Stack()//析构函数
{
}

void Stack::init() //初始化
{
	top = 0;
	memset(data, 0, sizeof data);
}

bool Stack::full() //判满
{
	if (top == N)
		return 1;
	return 0;
}

bool Stack::empty() //判空
{
	if (top == 0)
		return 1;
	return 0;
}

void Stack::push(double & val) //入栈
{
	data[top++] = val;
}

double Stack::pop() //出栈
{
	return data[--top];
}

int Stack::size() //求大小
{
	return top;
}

double Stack::get_top() //求栈顶元素
{
	return data[top-1];
}


int main()
{
	cout << "********栈类设计与测试********" << endl;

	Stack sta;
	double tp = 0;
	while (!sta.full()) 
	{
		cout << "入栈，请输入数据（0终止）：";
		cin >> tp;
		if (!tp)
		{
			cout << "***********入栈完毕!**********" << endl << endl;
			break;
		}
		sta.push(tp);
		cout << "成功入栈\n\n";
	}
	cout << "从栈顶依次输出当前栈内 " << sta.size() << "个元素并出栈：\n";
	while (!sta.empty())
	{
		cout << sta.pop() << "  ";
	}
	cout << endl;
	return 0;
}