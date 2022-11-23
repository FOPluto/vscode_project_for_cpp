// Person.cpp文件
#include "Person.h"

void Person::show() //展示函数，类内声明类外实现
{
  printf("此人的信息如下：\n");
  printf("编号: %d\n", this->number);
  printf("性别：%s\n", this->sex.c_str());
  printf("生日：%d年%d月%d日\n", this->birthday.year, this->birthday.month,
         this->birthday.day);
  printf("身份证号：%d\n", this->id);
  std::cout << "------------" << std::endl;
}

void Person::set() //设置函数，类内声明类外实现
{
  std::cout << "下面我们开始设置：" << std::endl;
  std::cout << "编号:  ";
  std::cin >> this->number;
  std::cout << "性别:  ";
  std::cin >> this->sex;
  std::cout << "生日（年月日输入）：  ";
  std::cin >> this->birthday.year >> this->birthday.month >> this->birthday.day;
  std::cout << "ID号:  ";
  std::cin >> this->id;
  std::cout << "finished" << std::endl;
}
Person::Person(int number, // Person构造函数类外实现 id默认为0
               std::string sex, Birthday birthday, int id = 0) {
  this->birthday = birthday;
  this->number = number;
  this->id = id;
  this->sex = sex;
}

Person::Person(const Person &personIn) //拷贝构造函数的使用
{
  this->number = personIn.number;
  this->sex = personIn.sex;
  this->birthday = personIn.birthday;
  this->id = personIn.id;
}
