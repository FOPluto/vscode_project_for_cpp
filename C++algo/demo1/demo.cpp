#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

#define int long long

using namespace std;

const int N = 10010;

const int INF = 0x3f3f3f3f;

int nn, g[N][N], r, n, h;
int p[N], x[N], y[N], z[N];

int idx;
int f[N];
bool st[N];


bool ff;

int find(int a){
    if(p[a] != a) p[a] = find(p[a]);
    return p[a];
}

long long distance(int x1, int y1, int z1, int x2, int y2, int z2){
    return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
}

bool dfs(int index){
    if(z[index] + r >= h) ff = true;

    for(int i = 0;i < n;i++){
        if(!st[i] && distance(x[i], y[i], z[i], x[index], y[index], z[index]) <= 4 * r * r){
            st[i] = true;
            dfs(i);
        }
    }
}

signed main(){
    scanf("%lld", &nn);
    for(int i = 0;i < nn;i++){
        idx = 0;
        scanf("%lld%lld%lld", &n, &h, &r);
        for(int j = 0;j < n;j++){
            scanf("%lld%lld%lld", &x[j], &y[j], &z[j]);
            if(z[j] - r <= 0){
                f[idx ++] = j;
            }
        }
        bool flag = false;
        ff = false;
        for(int j = 0;j < idx;j++){
            memset(st, 0, sizeof st);
            dfs(f[j]);
            if(ff) {
                puts("Yes");
                flag = true;
                break;
            }
        }
        if(!flag) puts("No");
    }

    return 0;
}