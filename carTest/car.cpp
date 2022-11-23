// car.cpp
using namespace std;
#include "car.h"
typedef pair<int, int> PII;
void                   move(PII position01, PII position02)
{
    printf("小车从[%d, %d]移动到了[%d, %d]\n", position01.first,
           position01.second, position02.first, position02.second);
}
Car::Car() {}  //无参构造函数，最好都加

Car::Car(int x, int y)
{
    this->position.first  = x;
    this->position.second = y;
}
Car::Car(int x, int y, string id)
{
    this->id              = id;
    this->position.first  = x;
    this->position.second = y;
}
void Car::carForward(int x, int y)
{
    move(this->position, make_pair(x, y));

    this->position.first  = x;
    this->position.second = y;
}
PII Car::getPosition()
{
    return this->position;
}