/**
 * @file demo.cpp
 * @author your name (you@domain.com)
 * @brief
    思考题 比较值传递和引用传递的相同点和不同点。
 调用被重载的函数时，通过什么来区分被调用的是哪一个函数
 * @version 0.1
 * @date 2022-05-06
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <algorithm>
#include <iostream>

using namespace std;
void test(int m, float &n);
int main() {
  int test_m = 5;
  float test_n = 5.0;
  test(test_m, test_n);
  cout << "************main***********" << endl;
  cout << "test_m=" << test_m << endl;
  cout << "test_m_pointer=" << &test_m << endl;
  cout << "test_n=" << test_n << endl;
  cout << "test_n_pointer=" << &test_n << endl;
  return 0;
}
void test(int m, float &n) {
  m = m + 5;
  n = n + m + 10.5;
  cout << "************test***********" << endl;
  cout << "m=" << m << endl;
  cout << "m_pointer=" << &m << endl;
  cout << "n=" << n << endl;
  cout << "n_pointer=" << &n << endl;
}
//解释地址.判断方法：值传递的函数不会改变函数外的值；而引用传递可以