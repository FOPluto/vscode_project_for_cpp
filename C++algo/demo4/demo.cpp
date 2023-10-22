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
int p[N], d[N];
int ans;

int find(int a){
    if(p[a] != a) {
        int t = find(p[a]);
        d[a] += d[p[a]];
        p[a] = t;
    }
    return p[a];
}

int main(){
    scanf("%d%d", &n, &m);

    for(int i = 1;i <= n;i++) p[i] = i;

    for(int i = 0;i < m;i++){
        int f, a, b;
        scanf("%d%d%d", &f, &a, &b);
        int pa = find(a);
        int pb = find(b);
        if(a > n || b > n){
            ans ++;
        } else {
            if(f == 1){
                if(pa == pb && (d[a] - d[b]) % 3) ans ++;
                else if(pa != pb) {
                    p[pa] = pb;
                    d[pa] = d[b] - d[a];
                }
            }
            else {
                if(pa == pb && (d[a] - d[b] - 1) % 3) ans ++ ;
                else if (pa != pb)
                {
                    p[pa] = pb;
                    d[pa] = d[b] + 1 - d[a];
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}