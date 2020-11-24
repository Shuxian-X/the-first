#include <iostream>
#include <string>

using namespace std;

const int N = 106;

class Student
{
private:
	string name; //����
	bool gender; //�Ա�1 �� 0 Ů
	int id; //ѧ��
	double score; //��ѧ�ɼ�
	string research; //�о�����
	string tutor; //ָ����ʦ
	const string university; //ѧУ����

public:
	Student(); //���캯��
	Student(string na, bool g, int ID, double sco, string re, string tu);
	Student(const Student &per); //�������캯��
	~Student(); //��������

	string Get_name(); // ��ȡ�о�����Ӧ������Ϣ
	bool Get_gender();
	int Get_id();
	double Get_score();
	string Get_research();
	string Get_tutor();
	string Get_university();

	void Display(); //��ͨ��Ա���� ����о�������������Ϣ
	void Display()const; //����Ա���� ����о�������������Ϣ
	double Output_GPA(const Student *stu, int n); //�������о��������ƽ���ɼ�
	friend void Output_level(const Student &stu); //��Ԫ���� ���ÿ���о�������ĳɼ��ȼ�
};

Student::Student() : university("SDNU") //���캯��,�ڳ�ʼ���б����const���ݳ�Ա��ʼ��
{
}

Student::Student(string na, bool g, int ID, double sco, string re, string tu) : university("SDNU") //���캯��,�ڳ�ʼ���б����const���ݳ�Ա��ʼ��
{
	name = na;
	gender = g;
	id = ID;
	score = sco;
	research = re;
	tutor = tu;
}

Student::Student(const Student & per) : university("SDNU") //���캯��,�ڳ�ʼ���б����const���ݳ�Ա��ʼ��
{
	name = per.name;
	gender = per.gender;
	id = per.id;
	score = per.score;
	research = per.research;
	tutor = per.tutor;
}

Student::~Student()
{
}

string Student::Get_name()
{
	return name;
}

bool Student::Get_gender()
{
	return gender;
}

int Student::Get_id()
{
	return id;
}

double Student::Get_score()
{
	return score;
}

string Student::Get_research()
{
	return research;
}

string Student::Get_tutor()
{
	return tutor;
}

string Student::Get_university()
{
	return university;
}

void Student::Display() //��ͨ��Ա���� ����о�������������Ϣ
{
	cout << "��    ��: " << name << endl;
	cout << "��    ��: " << (gender ? "M" : "F") << endl;
	cout << "ѧ    ��: " << id << endl;
	cout << "��ѧ�ɼ�: " << score << endl;
	cout << "�о�����: " << research << endl;
	cout << "ָ����ʦ: " << tutor << endl;
	cout << "ѧУ����: " << university << endl << endl;
}

void Student::Display() const  //����Ա���� ����о�������������Ϣ
{
	cout << "��    ��: " << name << endl;
	cout << "��    ��: " << (gender ? "M" : "F") << endl;
	cout << "ѧ    ��: " << id << endl;
	cout << "��ѧ�ɼ�: " << score << endl;
	cout << "�о�����: " << research << endl;
	cout << "ָ����ʦ: " << tutor << endl;
	cout << "ѧУ����: " << university << endl << endl;
}

double Student::Output_GPA(const Student * stu, int n) //�������о��������ƽ���ɼ�
{
	double sum = 0;
	for (int i = 0; i < n; ++i)
		sum += stu[i].score;
	double res = sum / n;
	cout << n << "���о�����ƽ���ɼ�Ϊ " << res << endl << endl;
	return res;
}

void Output_level(const Student &stu) //��Ԫ���� ����о�������ĳɼ��ȼ�
{
	int tp = (int)(stu.score / 10);
	switch (tp)
	{
	case 10:
	case 9: cout << "�о���" << stu.name << "�ĳɼ��ȼ�Ϊ �� A" << endl; break;
	case 8: cout << "�о���" << stu.name << "�ĳɼ��ȼ�Ϊ �� B" << endl; break;
	case 7: cout << "�о���" << stu.name << "�ĳɼ��ȼ�Ϊ �� C" << endl; break;
	case 6: cout << "�о���" << stu.name << "�ĳɼ��ȼ�Ϊ �� D" << endl; break;
	default: cout << "�о���" << stu.name << "�ĳɼ��ȼ�Ϊ �� E" << endl; break;
	}
}

int main()
{
	//�о�����������
	Student stu[3] = {
						Student("Alice", 0, 0101, 92, "Computer System Architecture", "Edwin"),
						Student("Alex", 1, 0102, 85, "Computer and Theory", "Apollo"),
						Student("Ford", 1, 0103, 76, "Computer Application Technology", "Cole"),
	};

	//��ͨ�о�������
	//Student a("Ada", 0, 0104, 446, "Information Security and Engineering", "Barbara");
	Student a(stu[0]);

	//���о�������
	//const Student b("Cathy", 0, 0105, 401, "Computer Science and Technology", "Diana");
	const Student b(stu[1]);

	cout << "---------------���������ϸ��Ϣ����---------------" << endl;
	for (int i = 0; i < 3; ++i)
		stu[i].Display();

	stu[0].Output_GPA(stu, 3);
	
	for(int i = 0; i < 3; ++i)
		Output_level(stu[i]);

	return 0;
}
