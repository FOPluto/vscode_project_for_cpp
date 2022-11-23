/**
 * @file demo.cpp
 * @author your name (you@domain.com)
 * @brief
    用递归方法编写函数 Fibonnacci(斐波那契)级数：
    并求出第 26 项的值。
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

const int N = 100010;

long long dp[N], n;

long long feb(int x) {
  if (x <= 2)
    return 1;
  if (dp[x])
    return dp[x]; //使用dp算法记忆存储可以加速防止栈溢出

  dp[x] = feb(x - 1) + feb(x - 2); //调用自己
  return dp[x];
}

int main() {
  cin >> n;
  cout << feb(n) << endl;
  return 0;
}
