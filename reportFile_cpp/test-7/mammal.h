// mammal.h文件
#pragma once
#include <algorithm>
#include <cstring>
#include <iostream>
#include <stdio.h>

using namespace std;

class mammal {
protected:
  string m_name;
  int m_age;
  double m_weight;

public:
  mammal() { cout << "mammal被创建了" << endl; }
  mammal(string name, int age, double weight)
      : m_name(name), m_age(age), m_weight(weight) {
    cout << "mammal被创建了" << endl;
  } //含参构造函数
  virtual ~mammal() { cout << "mammal的空间被释放了" << endl; }

  virtual void move() = 0;
  virtual void eat() = 0;
  virtual void speak() = 0; //这里将三个函数设置为了纯虚函数

  virtual void display() const; //虚函数常函数作为展示函数
};

void mammal::display() const {
  cout << "name is:" << this->m_name << endl;
  cout << "age is:" << this->m_age << endl;
  cout << "weight is:" << this->m_weight << endl;
}