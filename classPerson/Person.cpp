// Person.cpp�ļ�
#include "Person.h"
using namespace std;
// show����չʾ������Ϣ����������˽�е�
void Girl::show()  // girl��Ϣչʾ
{
    cout << "Girl is:" << endl;
    cout << this->m_age << " " << this->m_name << endl;
}
void Boy::show()  // boy��Ϣչʾ
{
    cout << "Boy is:" << endl;
    cout << this->m_age << " " << this->m_name << endl;
}
// visit�������ʶԷ�����Ϣ�����к���
void Girl::visitboy(Boy& boy)
{
    cout << "Ů����ʼ����..." << endl;
    cout << "Girl�޷�����Boy���е�show����,֤����Ԫ�಻������!" << endl;
    cout << "----------------------------------------------" << endl;
    // boy.show();//�˶�ȥ��ע�ͻᱨ��������Ϣ��show����Ϊ˽�к���
}
void Boy::visitgirl(Girl& girl)
{
    cout << "������ʼ����..." << endl;
    girl.show();
    cout << "----------------------------------------------" << endl;
}