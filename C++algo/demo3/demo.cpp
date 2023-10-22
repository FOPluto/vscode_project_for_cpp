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

int n, m;
int a[N], b[N];

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
    for(int i = 1;i <= m;i++) scanf("%d", &b[i]);

    sort(a + 1, a + n + 1, [](int a1, int a2){
        return a1 > a2;
    });
    sort(b + 1, b + n + 1, [](int a1, int a2){
        return a1 > a2;
    });


    if(a[n] > b[1]) {
        printf("%d\n", b[1] + 1);
        return 0;
    }
    if(a[1] > b[m]) {
        printf("%d\n", a[1]);
        return 0;
    }
    
    int num1 = 0;
    int i = 1;
    for(;i <= m || num1 <= n;i++){
        while(a[++ num1] >= b[i]){}
        if(num1 >= i) break;
    }

    int num2 = m + 1;
    int j = n;
    for(;j >= 0|| num2 >= 0;j --){
        while(b[-- num2] <= a[i]){}
        if((m - num2 + 1) <= n - j) break;
    }

    printf("%d\n", a[num1]);

    return 0;
}