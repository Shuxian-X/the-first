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

Student::Student(char * na, char sx, char * id, char * bir, char * ad, double Chin, double M, double E, double P, double Chem, double B)// �вι���
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

Student::Student(const Student & per) //��������
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

Student::~Student() //��������
{
	if (name)
		delete[]name;
}

char * Student::Get_name()//��ȡ����
{
	return name;
}

char Student::Get_sex()  //��ȡ�Ա�
{
	return sex;
}

char * Student::Get_ID()  //��ȡѧ��
{
	return ID;
}

char * Student::Get_birth() //��ȡ��������
{
	return birth;
}

char * Student::Get_addr() //��ȡ��ͥסַ
{
	return addr;
}

double Student::Get_Chinese() //��ȡ���ĳɼ�
{
	return Chinese;
}

double Student::Get_Math() //��ȡ��ѧ�ɼ�
{
	return Math;
}

double Student::Get_English() //��ȡӢ��ɼ�
{
	return English;
}

double Student::Get_Physics() //��ȡ����ɼ�
{
	return Physics;
}

double Student::Get_Chemistry() //��ȡ��ѧ�ɼ�
{
	return Chemistry;
}

double Student::Get_Biology()  //��ȡ����ɼ�
{
	return Biology;
}

void Student::Change(int num, double det) //�޸�ѧ���ɼ���Ϣ,���Ʊ�ŷֱ��Ӧ���� 1,2,3,4,5,6
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

void Student::Display() //��ʾѧ����Ϣ
{
	cout << " ��  �� �� " << name << endl;
	cout << " ��  �� �� " << sex << endl;
	cout << " ѧ  �� �� " << ID << endl;
	cout << "�������ڣ� " << birth << endl;
	cout << "��ͥסַ�� " << addr << endl;
	cout << "���ĳɼ��� " << Chinese << endl;
	cout << "��ѧ�ɼ��� " << Math << endl;
	cout << "Ӣ��ɼ��� " << English << endl;
	cout << "����ɼ��� " << Physics << endl;
	cout << "��ѧ�ɼ��� " << Chemistry << endl;
	cout << "����ɼ��� " << Biology << endl << endl;
}

void Student::Input() //����ѧ����Ϣ
{
	char na[10];
	cout << "���� ��  �� �� ";
	cin >> na;
	if (name)
		delete[]name;
	name = new char[strlen(na) + 1];
	strcpy(name, na);
	cout << "���� ��  �� �� ";
	cin >> sex;
	cout << "���� ѧ  �� �� ";
	cin >> ID;
	cout << "����������ڣ� ";
	cin >> birth;
	cout << "�����ͥסַ�� ";
	cin >> addr;
	cout << "�������ĳɼ��� ";
	cin >> Chinese;
	cout << "������ѧ�ɼ��� ";
	cin >> Math;
	cout << "����Ӣ��ɼ��� ";
	cin >> English;
	cout << "��������ɼ��� ";
	cin >> Physics;
	cout << "���뻯ѧ�ɼ��� ";
	cin >> Chemistry;
	cout << "��������ɼ��� ";
	cin >> Biology;
}