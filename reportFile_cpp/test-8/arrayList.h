#pragma once
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <utility>

using namespace std;

const unsigned int MaxLength = 1000;//最大的长度

template <class T>
class ArrayList {
public:
    const int length = MaxLength;
    T data[MaxLength];
    int next[MaxLength];
    int head;
    int number;
private:
    const int rear = -1;
    
    int idx;

public:

    ArrayList();

    int getNextCount(int count);//获取下一个节点地址的函数

    T getData(int count);//获取指定节点的

    void reset();//重置函数

    void show();//展示函数

    void add(T item);//添加函数,新建一个节点并且添加进去

    void splice(int position);//删除指定位置函数

    int find(T item);//查找函数
};