// Circle文件
#pragma once
#include "Shape.h"

class Circle : public Shape {
  private:
    double m_r;

  public:
    Circle(double r) : m_r(r)
    {
        std::cout << "Circle被创建了" << std::endl;
    }
    ~Circle()
    {
        std::cout << "Circle被析构了" << std::endl;
    }
    double caculate()
    {
        return PI * this->m_r * this->m_r;
    }
};