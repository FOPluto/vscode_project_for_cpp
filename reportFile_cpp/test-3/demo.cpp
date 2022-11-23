/**
 * @file demo.cpp
 * @author your name (you@domain.com)
 * @brief
    设计一个用于人事管理的 People（人员）类。考虑到通用性，这里只抽象出所有 类型
人员都具有的属性：number（编号）、sex（性别）、birthday（出生日期）、id（身份
证号）等。 其中"出生日期"定义为一个"日期"类内嵌子对象。 用成员函数实现对人员信息
的录入和显示。 要求包括：
构造函数和析构函数、拷贝构造函数、内联成员函数、带缺省形参值的成员函数。

 * @version 0.1
 * @date 2022-05-06
 *
 * @copyright Copyright (c) 2022
 *
 */

// Demo文件
#include "Person.h"

using namespace std;

vector<Person> persons; //存储人的容器

int main() {
  int number = 0;
  cin >> number; //输入操作的次数
  while (number--) {
    char ch;
    cin >> ch;
    if (ch == 'S') { //展示
      for (auto per : persons)
        per.show();
    } else if (ch == 'I') { //插入
      Person tempPerson;
      tempPerson.set();
      persons.push_back(tempPerson);
    }
    cout << "Done!" << endl;
    cout << "------------" << endl; //完成一次操作的结尾
  }
  return 0;
}
