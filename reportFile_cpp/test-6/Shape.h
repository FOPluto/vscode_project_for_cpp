// Shape.h文件
#pragma once
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
double const PI = std::acos(double(-1)); //这里得到的是3.14159
class Shape {
public:
  virtual double caculate() = 0;
  Shape() { std::cout << "Shape被构造了出来" << std::endl; }
  ~Shape() { std::cout << "Shape被析构了" << std::endl; }
};