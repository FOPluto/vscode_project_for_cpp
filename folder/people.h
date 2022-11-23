#pragma once
#include <iostream>
class date {
  private:
    int year;
    int mon;
    int day;

  public:
    date(int x, int y, int z) : year(x), mon(y), day(z) {}  //构造函数
    date(date& d)
    {
        this->year = d.year;
        this->mon  = d.mon;
        this->day  = d.day;
    }
    ~date() {}

    void datashow();
    void setdata();
};

class people {
  public:
    people(int x, char y, date z, int m) : number(x), sex(y), brithday(z), id(m)
    {
    }
    ~people() {}

    void setpeople();
    void showpeople();

  private:
    int  number;
    char sex;
    date brithday;
    int  id;
};