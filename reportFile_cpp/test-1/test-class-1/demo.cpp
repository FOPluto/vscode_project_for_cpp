/**
 * @file demo.cpp
 * @author your name (you@domain.com)
 * @brief
 功能需求：运行时显示"Menu: A(dd) D(elete) S(ort) Q(uit)， Select one:"提示
 用户输入，A 表示增加，D 表示删除，S 表示排序，Q 表示退出，输入为 A、 D、S
 时分别提示" 数据已经增加、删除、排序。"输入为 Q 时程序结束。
 按照上述功能需求写两个程序，分别使用if分支语句和switch分支语句实现：
 程序1要求:使用 if … else 语句进行判断，用 break、continue 控制程序流程。
 程序2要求:使用 Switch 语句实现。
 * @version 0.1
 * @date 2022-05-06
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_map>
using namespace std;
//这里做一个简单的链表
const int N = 100010;

int ne[N], e[N];
int idx;
int head = -1;
//----------------------------------------------
void add() //定义添加函数
{
  int x;
  int t;
  printf("please input number:\n");
  scanf("%d", &x);
  e[idx] = x;
  ne[idx] = head;
  head = idx++;
  printf("add done\n");
  printf("---------------------\n");
}
//----------------------------------------------

void erase() //定义删除函数
{
  int t = 0;
  printf("please input number:\n");
  scanf("%d", &t);

  for (int i = head; i != -1; i = ne[i]) {
    if (e[ne[i]] == t) {
      ne[i] = ne[ne[i]];
    }
  }
  printf("delete done\n");
  printf("---------------------\n");
}
//----------------------------------------------

void sort() //定义排序函数
{
  printf("sort..\n");
}
//----------------------------------------------
int main() {
  char IN;
  bool flag = false;
  while (1) {
    cin >> IN;
    switch (IN) {
    case 'A':
      add();
      break;
    case 'D':
      erase();
      break;
    case 'S':
      sort();
      break;
    case 'Q':
      flag = true;
      break;
    }
    if (flag)
      break;
  }
  return 0;
}
