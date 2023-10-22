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

typedef long long LL;

const int N = 500010;

LL a[N], n, temp[N];

LL merge(int l, int r){
    if(l >= r) return 0;
    int mid = l + r >> 1;
    int i = l, j = mid + 1;
    int idx = 0;
    LL res = merge(l, mid) + merge(mid + 1, r);
    while(i <= mid && j <= r){
        if(a[i] <= a[j]) temp[idx ++] = a[i ++];
        else {
            temp[idx ++] = a[j ++];
            res += (LL)mid - i + 1;
        }
    }

    while(i <= mid) temp[idx ++] = a[i ++];
    while(j <= r) temp[idx ++] = a[j ++];

    for(int k = l, q = 0;k <= r;k++, q ++){
        a[k] = temp[q];
    }

    return res;
}

int main(){
    scanf("%lld", &n);
    for(int i = 0;i < n;i++) scanf("%lld", &a[i]);
    LL res = merge(0, n - 1);
    printf("%lld\n", res);
    return 0;
} 