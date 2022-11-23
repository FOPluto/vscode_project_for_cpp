// demo.cpp文件
#include "Person.h"
#include "Top.h"
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    Girl g(18, "男生");
    Boy  b(11, "女生");
    Top  tt;
    //以上为定义这三个类
    g.visitboy(b);
    b.visitgirl(g);
    tt.visitgirlboy(g, b);
    //调用
    return 0;
}