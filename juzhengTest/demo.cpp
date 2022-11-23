// demo.cpp(mainÎÄ¼ş)
#include "Rect.h"

using namespace std;

int main()
{
    Rect rect01(2, 2);
    rect01.input();
    cout << "rect01 is" << endl;
    rect01.show();
    cout << "------------------------" << endl;
    Rect rect02(rect01);
    cout << "rect02 is" << endl;
    rect02.show();
    cout << "------------------------" << endl;
    rect02.input();
    cout << "rect02 is" << endl;
    rect02.show();
    cout << "------------------------" << endl;
    Rect rect03 = rect01 + rect02;
    cout << "rect03 is" << endl;
    rect03.show();
    cout << "------------------------" << endl;
    Rect rect04 = rect01 - rect02;
    cout << "rect04 is" << endl;
    rect04.show();
    cout << "------------------------" << endl;
    return 0;
}