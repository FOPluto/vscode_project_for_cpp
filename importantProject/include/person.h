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
    Person() {}  //无参构造方法

  private:
    int         id;          // id编号，每个员工都有的属性
    std::string name;        // name名称，每个员工都有的属性
    bool        sex;         //如果是男就是TRUE，如果是女就是FALSE
    std::string department;  //所属的部门
    int         lever;       //等级

  public:
    virtual double getSalary() = 0;
}