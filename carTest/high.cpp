#include "high.h"

using namespace std;

void High::carBack()
{
    printf("小车从[%d,%d]到了[0,0]\n", this->position.first,
           this->position.second);
    this->position.first  = 0;
    this->position.second = 0;
}