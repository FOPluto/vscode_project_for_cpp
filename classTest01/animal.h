// animal.h文件(这次没有分文件了，因为代码比较短)
#pragma once
#include "mammal.h"
//----------------------------------------

class dog : virtual public mammal {
  public:
    dog()
    {
        cout << "创造了一个马" << endl;
    }  //无参构造函数
    dog(string name, int age, double weight) : mammal(name, age, weight)
    {
        cout << "创造了一个狗" << endl;
    }  //含参构造函数
    ~dog()
    {
        cout << this->m_name << "这个狗被销毁了" << endl;
    }
    void move()
    {
        cout << "狗狗 " << this->m_name << " 从狗窝里跑到草原上" << endl;
    }
    void eat()
    {
        cout << "狗狗 " << this->m_name << " 吃骨头" << endl;
    }
    void speak()
    {
        cout << "狗狗 " << this->m_name << " 汪汪汪" << endl;
    }
};
//-----------------------------------------
class cat : virtual public mammal {
  public:
    cat()
    {
        cout << "创造了一个猫 " << endl;
    }  //无参构造函数
    cat(string name, int age, double weight) : mammal(name, age, weight)
    {
        cout << "创造了一个猫" << endl;
    }       //含参构造函数
    ~cat()  //析构函数
    {
        cout << this->m_name << "这个猫被销毁了" << endl;
    }

    //行为函数的声明与实现
    void move()
    {
        cout << "猫猫 " << this->m_name << " 从猫窝里钻了出来" << endl;
    }
    void eat()
    {
        cout << "猫猫 " << this->m_name << " 吃鱼" << endl;
    }
    void speak()
    {
        cout << "猫猫 " << this->m_name << " 喵喵喵" << endl;
    }
};
//-----------------------------------------
class horse : virtual public mammal {
  public:
    horse() {}  //无参构造函数
    horse(string name, int age, double weight) : mammal(name, age, weight)
    {
        cout << this->m_name << "这个马被创建了" << endl;
    }  //含参构造函数
    ~horse()
    {  //析构函数
        cout << this->m_name << "这个马被销毁了（（（（" << endl;
    }
    void move()
    {
        cout << "马 " << this->m_name << " 跑到了那里" << endl;
    }
    void eat()
    {
        cout << "马 " << this->m_name << " 吃草" << endl;
    }
    void speak()
    {
        cout << "马 " << this->m_name << " 叫了（不记得马怎么叫的了）" << endl;
    }
};
//-----------------------------------------
class pig : virtual public mammal {
  public:
    pig()
    {
        cout << "创造了一个猪" << endl;
    }  //无参构造函数
    pig(string name, int age, double weight) : mammal(name, age, weight)
    {
        cout << "创造了一个猪" << endl;
    }  //含参构造函数
    ~pig()
    {
        cout << this->m_name << "这个猪猪被销毁了" << endl;
    }
    void move()
    {
        cout << "猪 " << this->m_name << " 冲到了那里" << endl;
    }
    void eat()
    {
        cout << "猪 " << this->m_name << " 吃草" << endl;
    }
    void speak()
    {
        cout << "猪 " << this->m_name << " 叫了（打不出来）" << endl;
    }
};
