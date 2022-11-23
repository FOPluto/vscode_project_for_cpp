// demo.cpp文件
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

int main()
{
    Rectangle* rect = new Rectangle(10, 10);
    cout << "----------------------------------------------------" << endl;
    Circle* circle = new Circle(2);
    cout << "----------------------------------------------------" << endl;
    cout << "矩形的面积为:" << rect->caculate() << endl;
    cout << "圆形的面积为:" << circle->caculate() << endl;
    cout << "----------------------------------------------------" << endl;
    delete rect;
    cout << "----------------------------------------------------" << endl;
    delete circle;
    return 0;
}