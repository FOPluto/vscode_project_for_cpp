// Top.cpp文件
#include "Top.h"
using namespace std;
void Top::visitgirlboy(Girl &girl, Boy &boy) //顶层类访问girl和boy的函数
{
  cout << "顶层类开始访问..." << endl;
  girl.show();
  boy.show();
  cout << "--------------------------------------" << endl;
}
