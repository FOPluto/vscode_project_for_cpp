//Person.hpp文件（分文件编写程序）
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

class Birthday {
  public:  // birsday的属性
    int year;
    int month;
    int day;

  public:
    ~Birthday() {}  //析构函数
    Birthday() {}   //两个构造函数（无参构造函数不可少！）
    Birthday(int y, int m, int d) : year(y), month(m), day(d) {}
};

class Person {
  public:  // Person的属性
    int         number;
    std::string sex;
    Birthday    birthday;  //内嵌类
    int         id;

  public:
    void show();
    void set();

    Person() {}   //无参构造函数
    ~Person() {}  //析构函数
    Person(int         number,
           std::string sex,
           Birthday    birthday,
           int         id);  //含参构造函数，在类外实现

    Person(const Person& personIn);  //拷贝构造函数，在类外实现
};
//Person.cpp文件
inline void Person::show()  //展示函数，类内声明类外实现
{
    printf("此人的信息如下：\n");
    printf("编号: %d\n", this->number);
    printf("性别：%s\n", this->sex);
    printf("生日：%d年%d月%d日\n", this->birthday.year, this->birthday.month,
           this->birthday.day);
    printf("身份证号：%d\n", this->id);
}

inline void Person::set()  //设置函数，类内声明类外实现
{
    std::cout << "下面我们开始设置：" << std::endl;
    std::cout << "编号:  ";
    std::cin >> this->number;
    std::cout << "性别:  ";
    std::cin >> this->sex;
    std::cout << "生日（年月日输入）：  ";
    std::cin >> this->birthday.year >> this->birthday.month >>
        this->birthday.day;
    std::cout << "ID号:  ";
    std::cin >> this->id;
    std::cout << "finished" << std::endl;
}
inline Person::Person(int         number,  // Person构造函数类外实现
                      std::string sex,
                      Birthday    birthday,
                      int         id)
{
    this->birthday = birthday;
    this->number   = number;
    this->id       = id;
    this->sex      = sex;
}

inline Person::Person(const Person& personIn)  //拷贝构造函数的使用
{
    this->number   = personIn.number;
    this->sex      = personIn.sex;
    this->birthday = personIn.birthday;
    this->id       = personIn.id;
}