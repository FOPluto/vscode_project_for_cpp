/**
 * @file demo.cpp
 * @author your name (you@domain.com)
 * @brief
    定义一个 Girl 类和一个 Boy 类，这两个类中都有表示姓名、年龄的私有成员变量，
都要定义构造函数、析构函数、输出成员变量信息的公有成员函数。
     1.根据要求定义相应的类；
     2.将 Girl 类作为 Boy 类的友元类，在 Girl 类的成员函数 visitboy(boy &)中访问
boy 类 的私有成员，观察程序运行结果； 3.在 boy 类的某成员函数 visitgirl(girl
&)中试图访问 girl 类的私有成员，观察编译器给 出的错误信息，理解友元的不可逆性；
     4.主函数中正确定义两个类的对象，调用各自的成员函数实现相应的功能；
     5.再将 boy 类作为 girl 类的友元类，在 boy 类的某成员函数 visistgirl(girl
&)中访问 girl 类的私有成员，观察编译器给出的信息；
     6. 删除两个类中的函数 visitgirl(girl &),visitboy(boy &) ，定义一个顶层函数
visitboygirl(boy
&,girl&)，作为以上两个类的友元，通过调用该函数输出男孩和女孩的信息。

 * @version 0.1
 * @date 2022-05-06
 *
 * @copyright Copyright (c) 2022
 *
 */
// demo.cpp文件
#include "Person.h"
#include "Top.h"
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  Girl g(18, "男生");
  Boy b(11, "女生");
  Top tt;
  //以上为定义这三个类
  g.visitboy(b);
  b.visitgirl(g);
  tt.visitgirlboy(g, b);
  //调用
  return 0;
}
