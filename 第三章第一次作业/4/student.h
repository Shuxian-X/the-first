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
	char *name; //����
	char sex;  //�Ա�
	char ID[19], birth[10], addr[56]; //ѧ�ţ��������ڣ���ͥסַ
	double Chinese, Math, English, Physics, Chemistry, Biology; //6����Ŀ�Ŀ��Գɼ�
public:
	Student(); //�޲ι���
	Student(char *na, char sx, char *id, char *bir, char*addr, double Chin, double M, double E, double P, double Chem, double B);// �вι���
	Student(const Student &per); //��������
	~Student(); //��������
	char *Get_name(); //��ȡ����
	char Get_sex();  //��ȡ�Ա�
	char *Get_ID();  //��ȡѧ��
	char *Get_birth(); //��ȡ��������
	char *Get_addr(); //��ȡ��ͥסַ
	double Get_Chinese(); //��ȡ���ĳɼ�
	double Get_Math(); //��ȡ��ѧ�ɼ�
	double Get_English(); //��ȡӢ��ɼ�
	double Get_Physics(); //��ȡ����ɼ�
	double Get_Chemistry(); //��ȡ��ѧ�ɼ�
	double Get_Biology(); //��ȡ����ɼ�
	void Change(int num, double det); //�޸�ѧ���ɼ���Ϣ,���Ʊ�ŷֱ��Ӧ���� 1,2,3,4,5,6
	void Display(); //��ʾѧ����Ϣ
	void Input(); //����ѧ����Ϣ
};

#endif