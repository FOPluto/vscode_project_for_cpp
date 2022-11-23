// Rectangle.h文件
#pragma once
#include "Shape.h"

class Rectangle : public Shape {
private:
  double m_width;
  double m_height;

public:
  Rectangle(double width, double height) : m_height(height), m_width(width) {
    std::cout << "Rectangle被创建了" << std::endl;
  }
  ~Rectangle() { std::cout << "Rectangle被析构了" << std::endl; }
  double caculate() { return this->m_width * this->m_height; }
};
