// Demo�ļ�
#include "Car.hpp"

using namespace std;

vector<Person> persons;  //�洢�˵�����

int main()
{
    int number = 0;
    cin >> number;  //��������Ĵ���
    while (number--) {
        char ch;
        cin >> ch;
        if (ch == 'S') {  //չʾ
            for (auto per : persons)
                per.show();
        }
        else if (ch == 'I') {  //����
            Person tempPerson;
            tempPerson.set();
            persons.push_back(tempPerson);
        }
        cout << "Done!" << endl;
        cout << "------------" << endl;  //���һ�β����Ľ�β
    }
    return 0;
}