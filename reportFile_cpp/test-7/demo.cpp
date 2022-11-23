// main.cpp文件
#include "animal.h"
int main() {
  mammal *arr[4];//定义基类的指针数组

  arr[0] = new cat("tomcat", 18, 40.5);//依次存入这个数组中
  cout << "--------------------------------" << endl;
  arr[1] = new dog("狗狗", 18, 40.5);
  cout << "--------------------------------" << endl;
  arr[2] = new horse("马马", 20, 80);
  cout << "--------------------------------" << endl;
  arr[3] = new pig("猪猪", 25, 100.1);

  //依次执行它的函数（用循环）
  for(int i = 0;i < 4;i++){
    cout << "--------------------------------" << endl;
    arr[i]->eat();
  }
  for(int i = 0;i < 4;i++){
    cout << "--------------------------------" << endl;
    arr[i]->move();
  }
    for(int i = 0;i < 4;i++){
    cout << "--------------------------------" << endl;
    arr[i]->speak();
  }   
  for(int i = 0;i < 4;i++){
    cout << "--------------------------------" << endl;
    delete arr[i];
  }
  
  return 0;
}
