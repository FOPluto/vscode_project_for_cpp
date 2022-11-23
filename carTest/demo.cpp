#include "car.h"
#include "high.h"

using namespace std;
int main()
{
    Car car01(2, 2);

    car01.carForward(10, 0);

    cout << car01.getPosition().first << " " << car01.getPosition().second
         << endl;

    cout << "--------------------" << endl;
    High* high = new High();

    high->carForward(10, 10);
    high->carBack();
    delete (high);
    return 0;
}