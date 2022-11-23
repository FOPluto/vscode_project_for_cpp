// Person.h文件
#ifndef _PERSON_
#define _PERSON_
#include "Top.h"
#include <algorithm>
#include <cstdio>
#include <iostream>

class Girl;
class Boy;  //声明

class Girl {  //定义Girl对象
  public:
    friend class Boy;  //声明友元类，此时Boy是girl的友元类
    friend class Top;
    Girl() {}  //无参构造函数
    Girl(int age, std::string name)
        : m_age(age), m_name(name) {}  //有参构造函数

  public:
    void visitboy(Boy& boy);  //用来被调用的访问友元类的函数
  private:
    int         m_age;
    std::string m_name;

    void show();  //私有的展示个人信息的函数
};
class Boy {
  public:
    friend class Top;
    void visitgirl(Girl& girl);  //用来被调用的访问友元类的函数
    Boy() {}                     //无参构造函数
    Boy(int age, std::string name) : m_age(age), m_name(name) {}  //汉参构造函数
  private:
    int         m_age;
    std::string m_name;
    void        show();  //私有的展示个人信息的函数
};
#endif