#pragma once

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

class person {
  public:
    Person() {}  //�޲ι��췽��

  private:
    int         id;          // id��ţ�ÿ��Ա�����е�����
    std::string name;        // name���ƣ�ÿ��Ա�����е�����
    bool        sex;         //������о���TRUE�������Ů����FALSE
    std::string department;  //�����Ĳ���
    int         lever;       //�ȼ�

  public:
    virtual double getSalary() = 0;
}