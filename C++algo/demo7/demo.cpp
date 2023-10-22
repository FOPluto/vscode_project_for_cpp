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

int n, arr[N], m;

long long tree[N];

long long lazy[N], add[N];


void build(int index, int l, int r){
    if(l == r){
        tree[index] = arr[l];
        return;
    }
    int mid = l + r >> 1;
    build(index * 2, l, mid);
    build(index * 2 + 1, mid + 1, r);
    tree[index] = tree[index << 1] + tree[index << 1 | 1];
}


int query(int l, int r, int queryL, int queryR, int index){
    if(l == queryL && r == queryR) {
        return tree[index];
    }
    int mid = l + r >> 1;
    if(queryL > mid){
        return query(mid + 1, r, queryL, queryR, index * 2 + 1);
    }
    if(queryR <= mid){
        return query(l, mid, queryL, queryR, index * 2);
    }
    int resultL = query(l, mid, queryL, mid, index * 2);
    int resultR = query(mid + 1, r, mid + 1, queryR, index * 2 + 1);
    return resultR + resultL;
}


int change(int l, int r, int queryL, int queryR, int index, int k){
    if(l == queryL && r == queryR){
        lazy[index] += k * (r - l + 1);
        return  k * (r - l + 1);
    }
    int mid = r + l >> 1;
    if(queryL > mid){
        return change(mid + 1, r, queryL, queryR, index * 2 + 1, k);
    }
    if(queryR <= mid){
        return change(l, mid, queryL, queryR, index * 2, k);
    }
    change(l, mid, queryL, mid, index * 2, k);
    change(mid + 1, r, mid + 1, queryR, index * 2 + 1, k);
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n;i++) {
        scanf("%d", &arr[i]);
    }
    
    build(1, 1, n);

    while(m --){
        char ch[2];
        scanf("%s", ch);
        if(ch[0] == '1'){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            query(1, n, a, b, 1, c);
        } else {
            int a, b;
            scanf("%d%d", &a, &b);
            printf("%d\n", query(1, n, a, b, 1));
        }
    }

    return 0;
}