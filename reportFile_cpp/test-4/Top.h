// Top.h文件
#ifndef _TOP_
#define _TOP_
#include "Person.h"
class Girl;
class Boy;  //声明
class Top { //此为顶层类，可以同时访问Girl和Boy的私有成员
public:
  void visitgirlboy(Girl &girl, Boy &boy);
};
#endif // !_TOP_