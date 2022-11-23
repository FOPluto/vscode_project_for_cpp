// Person.h�ļ�
#ifndef _PERSON_
#define _PERSON_
#include "Top.h"
#include <algorithm>
#include <cstdio>
#include <iostream>

class Girl;
class Boy;  //����

class Girl {  //����Girl����
  public:
    friend class Boy;  //������Ԫ�࣬��ʱBoy��girl����Ԫ��
    friend class Top;
    Girl() {}  //�޲ι��캯��
    Girl(int age, std::string name)
        : m_age(age), m_name(name) {}  //�вι��캯��

  public:
    void visitboy(Boy& boy);  //���������õķ�����Ԫ��ĺ���
  private:
    int         m_age;
    std::string m_name;

    void show();  //˽�е�չʾ������Ϣ�ĺ���
};
class Boy {
  public:
    friend class Top;
    void visitgirl(Girl& girl);  //���������õķ�����Ԫ��ĺ���
    Boy() {}                     //�޲ι��캯��
    Boy(int age, std::string name) : m_age(age), m_name(name) {}  //���ι��캯��
  private:
    int         m_age;
    std::string m_name;
    void        show();  //˽�е�չʾ������Ϣ�ĺ���
};
#endif