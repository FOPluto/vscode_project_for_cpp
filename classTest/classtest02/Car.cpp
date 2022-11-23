// Demo文件
#include "Car.hpp"

using namespace std;

vector<Person> persons;  //存储人的容器

int main()
{
    int number = 0;
    cin >> number;  //输入操作的次数
    while (number--) {
        char ch;
        cin >> ch;
        if (ch == 'S') {  //展示
            for (auto per : persons)
                per.show();
        }
        else if (ch == 'I') {  //插入
            Person tempPerson;
            tempPerson.set();
            persons.push_back(tempPerson);
        }
        cout << "Done!" << endl;
        cout << "------------" << endl;  //完成一次操作的结尾
    }
    return 0;
}