// car.h
#pragma once
#include <algorithm>
#include <cstdio>
#include <iostream>

#ifndef _CAR_  //防止重定义
#    define _CAR_
class Car {
  public:
    Car();                                         //声明无参构造方法
    Car(int x, int y);                             //声明带参构造方法
    Car(int x, int y, std::string id);             //声明带参构造方法
    void                carForward(int x, int y);  //成员方法
    std::pair<int, int> getPosition();             //

  public:
    std::pair<int, int> position;
    std::string         id;
    double              ver;
};
#endif