#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <thread>

//不能用using namespace

class ThreadTest {
  public:
    void operator()()
    {
        std::cout << "operator开始执行" << std::endl;
        std::cout << "operator开始执行" << std::endl;
        std::cout << "operator开始执行" << std::endl;
        std::cout << "operator开始执行" << std::endl;
    }
};