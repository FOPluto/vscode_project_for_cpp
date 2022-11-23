/**
 * @file demo.cpp
 * @author your name (you@domain.com)
 * @brief
        找出2~10000之内的所有完全数。所谓完全数，即其各因子之和正好等于本身的数。
    如 6=1+2+3，28=1+2+4+7+14，所以6，28都是完全数
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

int main() {
  for (int i = 2; i <= 10000; i++) {
    int t = i;
    int res = 0;
    unordered_map<int, int> m;
    for (int j = 1; j < i; j++) {
      if (t % j == 0) {
        m[j]++;
      }
    }
    for (auto t : m) {
      int a = t.first, b = t.second;
      if (b)
        res += a;
    }
    if (res == i)
      printf("%d is the wanquanshu!\n", i);
  }
  return 0;
}
