#include <iostream>
#include <string>

using namespace std;

const int N = 106;

class Student
{
private:
	string name; //姓名
	bool gender; //性别，1 男 0 女
	int id; //学号
	double score; //入学成绩
	string research; //研究领域
	string tutor; //指导教师
	const string university; //学校名称

public:
	Student(); //构造函数
	Student(string na, bool g, int ID, double sco, string re, string tu);
	Student(const Student &per); //拷贝构造函数
	~Student(); //析构函数

	string Get_name(); // 获取研究生对应数据信息
	bool Get_gender();
	int Get_id();
	double Get_score();
	string Get_research();
	string Get_tutor();
	string Get_university();

	void Display(); //普通成员函数 输出研究生基本数据信息
	void Display()const; //常成员函数 输出研究生基本数据信息
	double Output_GPA(const Student *stu, int n); //输出多个研究生对象的平均成绩
	friend void Output_level(const Student &stu); //友元函数 输出每个研究生对象的成绩等级
};

Student::Student() : university("SDNU") //构造函数,在初始化列表里对const数据成员初始化
{
}

Student::Student(string na, bool g, int ID, double sco, string re, string tu) : university("SDNU") //构造函数,在初始化列表里对const数据成员初始化
{
	name = na;
	gender = g;
	id = ID;
	score = sco;
	research = re;
	tutor = tu;
}

Student::Student(const Student & per) : university("SDNU") //构造函数,在初始化列表里对const数据成员初始化
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

void Student::Display() //普通成员函数 输出研究生基本数据信息
{
	cout << "姓    名: " << name << endl;
	cout << "性    别: " << (gender ? "M" : "F") << endl;
	cout << "学    号: " << id << endl;
	cout << "入学成绩: " << score << endl;
	cout << "研究领域: " << research << endl;
	cout << "指导教师: " << tutor << endl;
	cout << "学校名称: " << university << endl << endl;
}

void Student::Display() const  //常成员函数 输出研究生基本数据信息
{
	cout << "姓    名: " << name << endl;
	cout << "性    别: " << (gender ? "M" : "F") << endl;
	cout << "学    号: " << id << endl;
	cout << "入学成绩: " << score << endl;
	cout << "研究领域: " << research << endl;
	cout << "指导教师: " << tutor << endl;
	cout << "学校名称: " << university << endl << endl;
}

double Student::Output_GPA(const Student * stu, int n) //输出多个研究生对象的平均成绩
{
	double sum = 0;
	for (int i = 0; i < n; ++i)
		sum += stu[i].score;
	double res = sum / n;
	cout << n << "名研究生的平均成绩为 " << res << endl << endl;
	return res;
}

void Output_level(const Student &stu) //友元函数 输出研究生对象的成绩等级
{
	int tp = (int)(stu.score / 10);
	switch (tp)
	{
	case 10:
	case 9: cout << "研究生" << stu.name << "的成绩等级为 ： A" << endl; break;
	case 8: cout << "研究生" << stu.name << "的成绩等级为 ： B" << endl; break;
	case 7: cout << "研究生" << stu.name << "的成绩等级为 ： C" << endl; break;
	case 6: cout << "研究生" << stu.name << "的成绩等级为 ： D" << endl; break;
	default: cout << "研究生" << stu.name << "的成绩等级为 ： E" << endl; break;
	}
}

int main()
{
	//研究生对象数组
	Student stu[3] = {
						Student("Alice", 0, 0101, 92, "Computer System Architecture", "Edwin"),
						Student("Alex", 1, 0102, 85, "Computer and Theory", "Apollo"),
						Student("Ford", 1, 0103, 76, "Computer Application Technology", "Cole"),
	};

	//普通研究生对象
	//Student a("Ada", 0, 0104, 446, "Information Security and Engineering", "Barbara");
	Student a(stu[0]);

	//常研究生对象
	//const Student b("Cathy", 0, 0105, 401, "Computer Science and Technology", "Diana");
	const Student b(stu[1]);

	cout << "---------------各对象的详细信息如下---------------" << endl;
	for (int i = 0; i < 3; ++i)
		stu[i].Display();

	stu[0].Output_GPA(stu, 3);
	
	for(int i = 0; i < 3; ++i)
		Output_level(stu[i]);

	return 0;
}
