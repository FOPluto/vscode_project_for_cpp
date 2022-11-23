#include "people.h"

using namespace std;

int main()
{
    cout << "11111";

    date a(0, 0, 0);

    a.datashow();

    people p1(0, 0, a, 0);

    p1.setpeople();

    p1.showpeople();

    return 0;
}