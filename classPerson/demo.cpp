// demo.cpp�ļ�
#include "Person.h"
#include "Top.h"
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    Girl g(18, "����");
    Boy  b(11, "Ů��");
    Top  tt;
    //����Ϊ������������
    g.visitboy(b);
    b.visitgirl(g);
    tt.visitgirlboy(g, b);
    //����
    return 0;
}