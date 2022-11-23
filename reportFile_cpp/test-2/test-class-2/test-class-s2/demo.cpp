/**
 * @file demo.cpp
 * @author your name (you@domain.com)
 * @brief
    设计一个函数，判断一个整数是否为素数。并完成下列程序设计:
 ①编写求素数的函数，并用这个函数求 3-200 之间的所有素数 ②在 4-200
 之间，验证歌德巴赫猜想:任何一个充分大的偶数都可以表示为两个素数之 和。输出
 4=2+2 6=3+3 …… 200=3+197 注：素数又称质数，指在一个大于 1 的自然数中，除了 1
 和此整数自身外，不能被其 他自然数(不包括 0)整除的数。
 * @version 0.1
 * @date 2022-05-06
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

bool judge(int x) {
  bool temp = true;

  for (int i = 2; i <= x / i; i++) {
    if (x % i == 0) {
      temp = false;
      break;
    }
  }
  return temp;
}

pair<int, int> pp;

int main() {
  for (int i = 4; i <= 200; i += 2) {
    int num = i;
    bool flag;
    for (int j = 2; j < i; j++) {
      flag = false;
      for (int k = 2; k < i; k++) {
        if (judge(j) && judge(k)) {
          if (j + k == num) {
            flag = true;
            pp.first = j, pp.second = k;
            break;
          }
        }
      }
      if (flag)
        break;
    }
    printf("%d=%d+%d\n", i, pp.first, pp.second);
  }
  return 0;
}
