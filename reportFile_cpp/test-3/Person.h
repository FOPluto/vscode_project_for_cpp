// Person.hpp文件（分文件编写程序）
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

class Birthday {
public: // birthday的属性
  int year;
  int month;
  int day;

public:
  ~Birthday() {} //析构函数
  Birthday() {}  //两个构造函数（无参构造函数不可少！）
  Birthday(int y, int m, int d) : year(y), month(m), day(d) {}
};

class Person {
public: // Person的属性
  int number;
  std::string sex;
  Birthday birthday; //内嵌类
  int id;

public:
  void show();
  void set();

  Person() {}  //无参构造函数
  ~Person() {} //析构函数
  Person(int number, std::string sex, Birthday birthday,
         int id); //含参构造函数，在类外实现

  Person(const Person &personIn); //拷贝构造函数，在类外实现
};