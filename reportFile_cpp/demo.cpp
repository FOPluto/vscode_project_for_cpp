#include <iostream>
#include<cstring>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class Girl;
class Boy
{
private:
	char* name;
	int age;
public:
	Boy(char* n, int a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
		age = a;
	}
	~Boy()
	{
		delete name;
	}
	void output()
	{
		cout << "姓名：" << name << "  年龄:" << age << endl;
	}
};
class Girl
{
private:
	char* name;
	int age;
public:
	Girl(char n[], int a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
		age = a;
	}
	~Girl()
	{
		delete name;
	}
	void output()
	{
		cout << "姓名：" << name << "  年龄:" << age << endl;
	}
};

int main()
{
	char name[10] = "张三";
	char name1[10] = "李四";
	Boy a(name, 19);
	Girl b(name1, 20);
	a.output();
	b.output();
	getchar();
}
