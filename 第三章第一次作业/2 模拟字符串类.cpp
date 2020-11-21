
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int npos = 0x3f3f3f3f;

class Mystring
{
private:
	char *p_str;
	int length;

public:
	Mystring();
	Mystring(const char *str);
	~Mystring();
	bool empty(); //�ж��ַ����Ƿ�Ϊ��
	int size(); //���㵱ǰ�ַ�������
	char *display(); //�����ǰ�ַ���
	void reverse(); //�ѵ�ǰ�ַ�����ת
	int append(Mystring &s); //���ַ���s���ӵ���ǰ�ַ�����β
	int append(Mystring &s, int n); //���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
	int compare(const Mystring &s); //�Ƚϵ�ǰ�ַ�����s�Ĵ�С������ֵΪ 1 ��ʾ��ǰ�ַ������ڸ����ַ��� s, Ϊ 0 ��ȣ�Ϊ 1 С�� 
	int insert(Mystring &s, int pos = 0); //�ڵ�ǰ�ַ����� pos λ��ǰ�����ַ��� s
	int erase(int pos = 0, int n = 0); //ɾ����ǰ�ַ��� pos ��ʼ������Ϊ n ���ַ�
	int find(const char c, int pos = 0); //��pos��ʼ�����ַ�c�ڵ�ǰ�ַ����е�һ�γ��ֵ�λ��
	int find(const Mystring &s, int pos = 0); //��pos��ʼ�����ַ���s�ڵ�ǰ���е�һ�γ��ֵ�λ��
};

Mystring::Mystring() :p_str(NULL), length(0) {}

Mystring::Mystring(const char * str)
{
	length = strlen(str);
	p_str = new char[length + 1];
	strcpy(p_str, str);
	p_str[length] = '\0';
}

Mystring::~Mystring()
{
	delete[] p_str;
}

bool Mystring::empty() //�ж��ַ����Ƿ�Ϊ��
{

	return length ==0 ? true : false;
}

int Mystring::size() //���㵱ǰ�ַ�������
{
	return length;
}

char * Mystring::display() //�����ǰ�ַ���
{
	return p_str;
}

void Mystring::reverse() //�ѵ�ǰ�ַ�����ת
{
	Mystring res;
	res.length = length;
	res.p_str = new char[length + 1];
	for (int i = 0; i < length; ++i)
		res.p_str[i] = p_str[length -1-i];
	res.p_str[length] = '\0';
	strcpy(p_str, res.p_str);
}

int Mystring::append(Mystring & s) //���ַ���s���ӵ���ǰ�ַ�����β
{
	int len = length + s.length;
	Mystring res;
	res.length = len;
	res.p_str = new char[len + 1];
	for (int i = 0; i < length; ++i)
		res.p_str[i] = p_str[i];
	for (int i = length; i < len; ++i)
		res.p_str[i] = s.p_str[i - length];
	res.p_str[len] = '\0';
	
	if(p_str) 
		delete []p_str; 
	length = len;
	p_str = new char[len + 1];
	strcpy(p_str, res.p_str);
	return 1;
}

int Mystring::append(Mystring & s, int n) //���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
{
	int len = length + n;
	Mystring res;
	res.length = len;
	res.p_str = new char[len + 1];
	for (int i = 0; i < length; ++i)
		res.p_str[i] = p_str[i];
	for (int i = length; i < len; ++i)
		res.p_str[i] = s.p_str[i - length];
	res.p_str[len] = '\0';

	if(p_str) 
		delete []p_str; 
	length = len;
	p_str = new char[len + 1];
	strcpy(p_str, res.p_str);
	return 1;
}

int Mystring::compare(const Mystring & s) //�Ƚϵ�ǰ�ַ�����s�Ĵ�С������ֵΪ 1 ��ʾ��ǰ�ַ������ڸ����ַ��� s, Ϊ 0 ��ȣ�Ϊ 1 С�� 
{
	int len = min(length, s.length);
	for (int i = 0; i < len; ++i) 
	{
		if (p_str[i] != s.p_str[i])
			return p_str[i] > s.p_str[i];
	}
	return length > s.length;

}

int Mystring::insert(Mystring & s, int pos) //�ڵ�ǰ�ַ����� pos λ��ǰ�����ַ��� s
{
	if (pos < 0 || pos > length) 
	{
		cout << "out of range\n";
		return 0;
	}
	int len = length + s.length;
	Mystring res;
	res.length = len;
	res.p_str = new char[len + 1];
	for (int i = 0; i < pos; ++i)
		res.p_str[i] = p_str[i];
	for(int i = pos; i < pos + s.length; ++i)
		res.p_str[i] = s.p_str[i-pos];
	for(int i = pos+s.length; i < len; ++i)
		res.p_str[i] = p_str[i - s.length];
	res.p_str[len] = '\0';

	if(p_str) 
		delete []p_str; 
	length = len;
	p_str = new char[len + 1];
	strcpy(p_str, res.p_str);
	return 1;
}

int Mystring::erase(int pos, int n) //ɾ����ǰ�ַ��� pos ��ʼ������Ϊ n ���ַ�
{
	if(pos < 0 || pos+n > length)
	{
		cout << "out of range\n";
		return 0;
	}
	int len = length - n;
	Mystring res;
	res.length = len;
	res.p_str = new char[len + 1];
	for (int i = 0; i < pos; ++i)
		res.p_str[i] = p_str[i];
	for (int i = pos + n; i < length; ++i)
		res.p_str[i - n] = p_str[i];
	res.p_str[len] = '\0';

	if(p_str) 
		delete []p_str; 
	length = len;
	p_str = new char[len + 1];
	strcpy(p_str, res.p_str);
	return 1;
}

int Mystring::find(const char c, int pos) //��pos��ʼ�����ַ�c�ڵ�ǰ�ַ����е�һ�γ��ֵ�λ��
{
	if (c == NULL || pos >= length)
		return npos;
	for (int i = pos; i < length; ++i) 
		if (p_str[i] == c) 
			return i;
	return npos;
}

int Mystring::find(const Mystring & s, int pos) //��pos��ʼ�����ַ���s�ڵ�ǰ���е�һ�γ��ֵ�λ��
{
	int len = s.length;
	if (s.p_str == NULL || pos < 0 || pos+len >= length)
		return npos;
	for (int i = pos; i < length-len; ++i) 
	{
		if (p_str[i] == s.p_str[0])
		{
			int j = 0, t = i;
			while (j < len && p_str[t] == s.p_str[j])
				++t, ++j;
			if (j == len)
				return i;
		}
	}
	return npos;
}



int main()
{
	Mystring s1("You never know your luck.");
	Mystring s2("Sow nothing,reap nothing.");
	
	if (!s1.empty())
		cout << "s1 != empty\n\n";
	cout << "s1.size = " <<  s1.size() << endl << endl;

	s1.reverse();
	cout << "after reverse, s1 = " << endl << s1.display() << endl << endl;

	s1.reverse();
	s1.append(s2);
	cout << "after reverse again and append s2, s1 = " << endl << s1.display() << endl << endl;

	s2.append(s1, 3);
	cout << "after append the first three characters of s1, s2 = " << endl << s2.display() << endl << endl;
	
	if(s2.erase(25, 3))
	cout << "after erase, s2 = " << endl << s2.display() << endl << endl;
	if (s1.erase(24, s2.size()))
		cout << "after erase, s1 = " << endl << s1.display() << endl << endl;
	
	if (s1.compare(s2) == 1)
		cout << "s1 > s2\n" << endl;
	else if(s1.compare(s2) == -1)
		cout << "s1 < s2\n" << endl;
	else
		cout << "s1 = s2\n" << endl;
	
	int p1 = s1.find('k');
	cout << "in s1, k's location of the first occurrence is  " << endl << p1 << endl << endl;

	int p2 = s1.find("luck");
	cout << "in s1, luck's location of the first occurrence is  " << endl << p2 << endl << endl;

	return 0;
}
