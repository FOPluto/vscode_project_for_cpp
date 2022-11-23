/**
 * @file demo.cpp
 * @author your name (you@domain.com)
 * @brief
用类来实现矩阵，定义一个矩阵的类，属性包括：
    矩阵大小，用 lines, rows（行、列来表示）；
    存贮矩阵的数组指针，根据矩阵大小动态申请（new）。
矩阵类的方法包括：
    构造函数：参数是矩阵大小，需要动态申请存贮矩阵的数组；
    析构函数：需要释放矩阵的数组指针；
    拷贝构造函数：需要申请和复制数组（深复制）；
    输入函数：可以从 cin 中输入矩阵元素；
    输出函数：将矩阵格式化输出到 cout；
    矩阵相加函数：实现两个矩阵相加的功能，结果保存在另一个矩阵里，但必须矩阵大小相同；
    矩阵相减的函数：实现两个矩阵相减的功能，结果保存在另一个矩阵里，但必须矩阵大小相同。
主函数功能：
    定义三个矩阵：A1、A2、A3；
    初始化 A1、A2；
    计算并输出 A3 = A1+A2，A3=A1+A2；
    用 new 动态创建三个矩阵类的对象：pA1、pA1、pA3
    初始化 pA1、pA2；
    计算并输出 pA3=pA1+pA2，pA3=pA1-pA2；
    释放 pA1、pA1、pA3。

 * @version 0.1
 * @date 2022-05-06
 *
 * @copyright Copyright (c) 2022
 *
 */

// demo.cpp(main文件)
#include "Rect.h"

using namespace std;

int main() {
  Rect A1(2, 2), A2(2, 2), A3(2, 2); //定义三个矩阵：A1、A2、A3
  A1.input();                        // A1初始化
  A2.input();                        // A2初始化
  A3.show();
  cout << "-----------------------" << endl;
  A1.show();
  cout << "-----------------------" << endl;
  A2.show();
  cout << "-----------------------" << endl;
  A3 = A1 + A2; //计算并输出 A3 = A1 + A2，A3 = A1 + A2
  A3.show();
  cout << "-----------------------" << endl;
  A3 = A2 + A1;
  A3.show();
  cout << "-----------------------" << endl;
  Rect *pA1 = new Rect(2, 2);
  Rect *pA2 = new Rect(2, 2);
  pA1->input();
  pA2->input();
  Rect pA3 = *(new Rect(2, 2));
  cout << "-----------------------" << endl;
  pA3 = *pA1 + *pA2;
  pA3.show();
  cout << "-----------------------" << endl;
  pA3 = *pA1 - *pA2;
  pA3.show();
  delete &pA3;
  delete pA1;
  delete pA2;
  return 0;
}
