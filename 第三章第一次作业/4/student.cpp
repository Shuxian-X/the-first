#define _CRT_SECURE_NO_WARNINGS
#include "student.h"

Student::Student()
{
	name = NULL;
	sex = 'M';
	Chinese = 0;
	Math = 0;
	English = 0;
	Physics = 0;
	Chemistry = 0;
	Biology = 0;
}

Student::Student(char * na, char sx, char * id, char * bir, char * ad, double Chin, double M, double E, double P, double Chem, double B)// 有参构造
{
	if (na)
	{
		name = new char[strlen(na) + 1];
		strcpy(name, na);
	}
	sex = sx;
	strcpy(ID, id);
	strcpy(birth, bir);
	strcpy(addr, ad);
	Chinese = Chin;
	Math = M;
	English = E;
	Physics = P;
	Chemistry = Chem;
	Biology = B;
}

Student::Student(const Student & per) //拷贝构造
{
	if (per.name)
	{
		name = new char[strlen(per.name) + 1];
		strcpy(name, per.name);
	}
	sex = per.sex;
	strcpy(ID, per.ID);
	strcpy(birth, per.birth);
	strcpy(addr, per.addr);
	Chinese = per.Chinese;
	Math = per.Math;
	English = per.English;
	Physics = per.Physics;
	Chemistry = per.Chemistry;
	Biology = per.Biology;
}

Student::~Student() //析构函数
{
	if (name)
		delete[]name;
}

char * Student::Get_name()//提取姓名
{
	return name;
}

char Student::Get_sex()  //提取性别
{
	return sex;
}

char * Student::Get_ID()  //提取学号
{
	return ID;
}

char * Student::Get_birth() //提取出生日期
{
	return birth;
}

char * Student::Get_addr() //提取家庭住址
{
	return addr;
}

double Student::Get_Chinese() //提取语文成绩
{
	return Chinese;
}

double Student::Get_Math() //提取数学成绩
{
	return Math;
}

double Student::Get_English() //提取英语成绩
{
	return English;
}

double Student::Get_Physics() //提取物理成绩
{
	return Physics;
}

double Student::Get_Chemistry() //提取化学成绩
{
	return Chemistry;
}

double Student::Get_Biology()  //提取生物成绩
{
	return Biology;
}

void Student::Change(int num, double det) //修改学生成绩信息,各科编号分别对应数字 1,2,3,4,5,6
{
	switch (num) 
	{
	case 1: Chinese = det; break;
	case 2: Math = det; break;
	case 3: English = det; break;
	case 4: Physics = det; break;
	case 5: Chemistry = det; break;
	case 6: Biology = det; break;
	}
}

void Student::Display() //显示学生信息
{
	cout << " 姓  名 ： " << name << endl;
	cout << " 性  别 ： " << sex << endl;
	cout << " 学  号 ： " << ID << endl;
	cout << "出生日期： " << birth << endl;
	cout << "家庭住址： " << addr << endl;
	cout << "语文成绩： " << Chinese << endl;
	cout << "数学成绩： " << Math << endl;
	cout << "英语成绩： " << English << endl;
	cout << "物理成绩： " << Physics << endl;
	cout << "化学成绩： " << Chemistry << endl;
	cout << "生物成绩： " << Biology << endl << endl;
}

void Student::Input() //输入学生信息
{
	char na[10];
	cout << "输入 姓  名 ： ";
	cin >> na;
	if (name)
		delete[]name;
	name = new char[strlen(na) + 1];
	strcpy(name, na);
	cout << "输入 性  别 ： ";
	cin >> sex;
	cout << "输入 学  号 ： ";
	cin >> ID;
	cout << "输入出生日期： ";
	cin >> birth;
	cout << "输入家庭住址： ";
	cin >> addr;
	cout << "输入语文成绩： ";
	cin >> Chinese;
	cout << "输入数学成绩： ";
	cin >> Math;
	cout << "输入英语成绩： ";
	cin >> English;
	cout << "输入物理成绩： ";
	cin >> Physics;
	cout << "输入化学成绩： ";
	cin >> Chemistry;
	cout << "输入生物成绩： ";
	cin >> Biology;
}