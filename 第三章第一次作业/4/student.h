#ifndef _STUDENT
#define _STUDENT
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define SIZE 80
using namespace std;


class Student
{
private:
	char *name; //姓名
	char sex;  //性别
	char ID[19], birth[10], addr[56]; //学号，出生日期，家庭住址
	double Chinese, Math, English, Physics, Chemistry, Biology; //6个科目的考试成绩
public:
	Student(); //无参构造
	Student(char *na, char sx, char *id, char *bir, char*addr, double Chin, double M, double E, double P, double Chem, double B);// 有参构造
	Student(const Student &per); //拷贝构造
	~Student(); //析构函数
	char *Get_name(); //提取姓名
	char Get_sex();  //提取性别
	char *Get_ID();  //提取学号
	char *Get_birth(); //提取出生日期
	char *Get_addr(); //提取家庭住址
	double Get_Chinese(); //提取语文成绩
	double Get_Math(); //提取数学成绩
	double Get_English(); //提取英语成绩
	double Get_Physics(); //提取物理成绩
	double Get_Chemistry(); //提取化学成绩
	double Get_Biology(); //提取生物成绩
	void Change(int num, double det); //修改学生成绩信息,各科编号分别对应数字 1,2,3,4,5,6
	void Display(); //显示学生信息
	void Input(); //输入学生信息
};

#endif