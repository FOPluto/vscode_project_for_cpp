// Shape.h文件
#pragma once
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

double const PI = std::acos(double(-1));  //这里得到的是3.14159
class Shape {
  public:
    virtual double caculate()
    {
        std::cout << "父类的计算方法被调用了" << std::endl;
    }
    Shape()
    {
        std::cout << "Shape被构造了出来" << std::endl;
    }
    ~Shape()
    {
        std::cout << "Shape被析构了" << std::endl;
    }
};