#include "people.h"

void date::datashow()
{
    std::cout << year << "年" << mon << " 月" << day << "日" << '\n';
}

void date::setdata()
{
    int x, y, z;
    std::cout << "输入日期";
    std::cin >> x >> y >> z;
    this->year = x;
    this->mon  = y;
    this->day  = z;
}

void people::setpeople()
{
    int  num;
    char se;
    date a(0, 0, 0);
    a.setdata();
    int di;
    std::cout << "输入姓名 性别 编号";
    std::cin >> num >> se >> di;
    this->number   = num;
    this->sex      = se;
    this->brithday = a;
    this->id       = di;
}

void people::showpeople()
{
    std::cout << "姓名 " << number << '\n';
    std::cout << "性别 " << sex << '\n';
    brithday.datashow();
    std::cout << "编号" << id << '\n';
}
