#include "arrayList.h"
#include "arrayList.cpp"

int main(){
    ArrayList<int>* arrayList = new ArrayList<int>();
    arrayList->add(123);
    arrayList->add(111);
    for(int i = 0;i < 5;i++) arrayList->add(11);

    arrayList->splice(2);
    arrayList->show();

    return 0;
}