//Person.hpp�ļ������ļ���д����
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

class Birthday {
  public:  // birsday������
    int year;
    int month;
    int day;

  public:
    ~Birthday() {}  //��������
    Birthday() {}   //�������캯�����޲ι��캯�������٣���
    Birthday(int y, int m, int d) : year(y), month(m), day(d) {}
};

class Person {
  public:  // Person������
    int         number;
    std::string sex;
    Birthday    birthday;  //��Ƕ��
    int         id;

  public:
    void show();
    void set();

    Person() {}   //�޲ι��캯��
    ~Person() {}  //��������
    Person(int         number,
           std::string sex,
           Birthday    birthday,
           int         id);  //���ι��캯����������ʵ��

    Person(const Person& personIn);  //�������캯����������ʵ��
};
//Person.cpp�ļ�
inline void Person::show()  //չʾ������������������ʵ��
{
    printf("���˵���Ϣ���£�\n");
    printf("���: %d\n", this->number);
    printf("�Ա�%s\n", this->sex);
    printf("���գ�%d��%d��%d��\n", this->birthday.year, this->birthday.month,
           this->birthday.day);
    printf("���֤�ţ�%d\n", this->id);
}

inline void Person::set()  //���ú�����������������ʵ��
{
    std::cout << "�������ǿ�ʼ���ã�" << std::endl;
    std::cout << "���:  ";
    std::cin >> this->number;
    std::cout << "�Ա�:  ";
    std::cin >> this->sex;
    std::cout << "���գ����������룩��  ";
    std::cin >> this->birthday.year >> this->birthday.month >>
        this->birthday.day;
    std::cout << "ID��:  ";
    std::cin >> this->id;
    std::cout << "finished" << std::endl;
}
inline Person::Person(int         number,  // Person���캯������ʵ��
                      std::string sex,
                      Birthday    birthday,
                      int         id)
{
    this->birthday = birthday;
    this->number   = number;
    this->id       = id;
    this->sex      = sex;
}

inline Person::Person(const Person& personIn)  //�������캯����ʹ��
{
    this->number   = personIn.number;
    this->sex      = personIn.sex;
    this->birthday = personIn.birthday;
    this->id       = personIn.id;
}