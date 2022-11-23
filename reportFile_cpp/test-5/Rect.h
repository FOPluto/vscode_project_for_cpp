// Rect.h
#pragma once
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>

class Rect {
private:
  int **head; //指针
public:
  int rows; //记录行数，设置为公有
  int cols; //记录列数，设置为公有
public:
  Rect() {}                  //无参构造函数
  Rect(int **h) : head(h) {} //用二维数组来初始化矩阵的构造函数
  Rect(int rows, int cols);  //用rows和cols来初始化矩阵的构造函数
  Rect(const Rect &rectTemp); //用深拷贝的方式来初始化一个矩阵的构造函数

  ~Rect(); //析构函数

  void show(); // show函数，用于展示打印的函数

  void input(); // input函数，用来cin输入更改的函数

  void find(int x, int y); // find查询函数，用来查询对应的下标的值

  Rect operator+(const Rect &rect); //重载了+号运算符

  Rect operator-(const Rect &rect); //重载了-号运算符
};
