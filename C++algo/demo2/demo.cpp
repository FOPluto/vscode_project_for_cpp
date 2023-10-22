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

const int N = 100010;

const int INF = 0x3f3f3f3f;

long long n, m, p[200010 << 1];

long long find(int a){
    if(a == p[a])return a;
    return p[a]=find(p[a]);
}

struct Edge{
    long long x, y, w;
} arr[N];

int main(){
    scanf("%lld%lld", &n, &m);
    for(int i = 0;i < m;i++){
        scanf("%lld%lld%lld", &arr[i].x, &arr[i].y, &arr[i].w);
    }
    for(int i = 1;i <= n;i++) p[i] = i, p[i + n] = i + n;
    sort(arr, arr + m, [](Edge e1, Edge e2){
        return e1.w > e2.w;
    });
    for(int i = 0;i < m;i++){
        int a = arr[i].x;
        int b = arr[i].y;
        if(find(a) == find(b) || find(a + n) == find(b + n)){
            printf("%lld\n", arr[i].w);
            return 0;
        } else {
            p[p[a + n]] = p[b];
            p[p[a]] = p[b + n];
        }
    }
    puts("0");
    return 0;
}