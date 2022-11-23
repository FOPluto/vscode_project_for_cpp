#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#include "arrayList.hpp"

using namespace std;

template <typename T> ArrayList<T>::ArrayList()
{
    this->size              = 0;
    this->arraylist         = new list(1000);
    this->arraylist[0].next = -1;  //-1就是代表着不存在任何元素
}
template <typename T> ArrayList<T>::ArrayList(int size)
{
    this->size              = size;
    this->arrayList         = new list(size);
    this->arraylist[0].next = -1;  //-1就是代表着不存在任何元素
}

template <typename T> int ArrayList<T>::insert(T element, int index)
{
    if (this->size <= index) {
        return -1;
    }
    list eleList;
    eleList.element                  = element;
    eleList.next                     = this->size++;
    this->arraylist[this->size].next = *(this->arraylist[index].next).next;
    return index;
}
