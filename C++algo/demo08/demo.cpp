#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <unordered_map>

using namespace std;

const int N = 4000040;

int n;
int a[N];
int tr[N];
int Greater[N], lower[N];

int lowbit(int x){
    return x & -x; // 取到第一个不是一的数
}

void add(int x, int c){
    for(int i = x;i <= n;i += lowbit(i)) tr[i] += c;
}

int sum(int x){
    int res = 0;
    for(int i = x;i <= n;i -= lowbit(i)) res += tr[i];
    return res;
}

int main() {
    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }


}