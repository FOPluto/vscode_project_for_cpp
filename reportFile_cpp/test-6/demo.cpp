/**
 * @file demo.cpp
 * @author zhangjunyong (you@domain.com)
 * @brief
    1、编写 C++程序，以完成以下功能（具体的数据成员、函数成员，请自主定义）：
（1）声明一个基类 Shape（形状），其中包含一个方法来计算面积；
（2）从 Shape 派生两个类：矩形类（Rectangle）和圆形类（Circle）；
（3）从 Rectangle 类派生正方形类 Square；
（4）分别实现派生类构造函数、析构函数及其它功能的成员函数；
（5）创建各派生类的对象，观察构造函数、析构函数的调用次序；
（6）计算不同对象的面积。
2、将 1 中 Shape
基类计算面积的方法定义为虚函数，比较与【形状（一）】程序的差异，体验其优点

 * @version 0.1
 * @date 2022-05-06
 *
 * @copyright Copyright (c) 2022
 */

// demo.cpp文件
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

int main() {
  Rectangle *rect = new Rectangle(10, 10);
  cout << "----------------------------------------------------" << endl;
  Circle *circle = new Circle(2);
  cout << "----------------------------------------------------" << endl;
  cout << "矩形的面积为:" << rect->caculate() << endl;
  cout << "圆形的面积为:" << circle->caculate() << endl;
  cout << "----------------------------------------------------" << endl;
  delete rect;
  cout << "----------------------------------------------------" << endl;
  delete circle;
  return 0;
}
