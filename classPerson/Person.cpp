// Person.cpp文件
#include "Person.h"
using namespace std;
// show函数展示个人信息。在类中是私有的
void Girl::show()  // girl信息展示
{
    cout << "Girl is:" << endl;
    cout << this->m_age << " " << this->m_name << endl;
}
void Boy::show()  // boy信息展示
{
    cout << "Boy is:" << endl;
    cout << this->m_age << " " << this->m_name << endl;
}
// visit函数访问对方的信息。共有函数
void Girl::visitboy(Boy& boy)
{
    cout << "女生开始访问..." << endl;
    cout << "Girl无法调用Boy类中的show函数,证明友元类不可逆性!" << endl;
    cout << "----------------------------------------------" << endl;
    // boy.show();//此段去掉注释会报错：报错信息：show函数为私有函数
}
void Boy::visitgirl(Girl& girl)
{
    cout << "男生开始访问..." << endl;
    girl.show();
    cout << "----------------------------------------------" << endl;
}