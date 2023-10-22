#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

using namespace std;

struct demo_struct {
    int idx;
    std::string data;
    bool operator < (const demo_struct& other) const {
        return idx > other.idx; // 按照 idx 从小到大排序
    }
};

std::mutex mtx;
std::condition_variable cv;
queue<demo_struct> q;

void product(std::string src_) {
    while() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return q.size() <= 10000; });
        demo_struct demo;
        demo.idx = q.size();
        demo.data = src_;
        q.push(demo);
    }
}

void comsume() {
    while(1) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return !q.empty(); });
        auto item = q.front();
        q.pop();
        cout << "输出元素：" << "idx: " << item.idx << "  data: " << item.data << endl;
    }
}

int main() {
    std::thread t1(product, "");
    t1.join();
    int idx = 0;
    while(1) {
        demo_struct demo;
        cin >> demo.data;
        demo.idx = idx++;
        product(to_string(demo.idx));
    }
    return 0;
}