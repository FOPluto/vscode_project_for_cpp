#pragma once
const int N = 1e6;

template <typename T> class ArrayList {
  public:
    //插入算法
    int insert(T element, int index);

    //获取算法
    T get(int index);

    //删除算法
    T listDelete(int index);
    T listDelete(T element);

    //排序算法
    void sort();

    //构造函数
    ArrayList<T>();
    ArrayList<T>(int size);

    //析构函数
    ~ArrayList<T>();

  private:
    struct list
    {
        T     element;
        list* next;
    };

    list* arraylist;

  public:
    int size;
};