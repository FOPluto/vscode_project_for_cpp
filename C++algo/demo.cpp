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

const int N = 1010;

const int INF = 0x3f3f3f3f;

int n, m;
int g[N][N], dist[N];
bool st[N];

int find(){
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for(int i = 0;i < n;i++){
        int t = -1;
        for(int j = 1;j <= n;j++){
            if(!st[j] && (t == -1 || dist[j] < dist[t])){
                t = j;
            }
        }
        if(i && dist[t] == INF){
            return INF;
        }

        if(i) res = max(dist[t], res);

        for(int j = 1;j <= n;j++){
            dist[j] = min(dist[j], g[t][j]);
        }
        st[t] = true;
    }
    return res;
}

int main(){
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof g);
    for(int i = 0;i < m;i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[b][a] = g[a][b] = min(g[a][b], c);
    }
    int res = find();
    if(res == INF) puts("-1");
    else printf("%d", res);
    return 0;
}