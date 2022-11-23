#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>


using namespace std;

const int N = 1010;

const int INF = 0x3f3f3f3f;

int n, m;
int g[N][N], dist[N];
bool st[N];

int prim(){
    int res = 0;
    for(int i = 0;i < n;i++){
        int t = -1;
        for(int j = 1;j <= n;j++){
            if(!st[j] && (t == -1 || dist[t] > dist[j])){
                t = j;
            }
        }
        if(i && dist[t] == INF) return INF;
        
        if(i) res += dist[t];
        st[t] = true;

        for(int j = 1;j <= n;j++){
            dist[j] = min(dist[j], g[t][j]);
        }
    }
    return res;
}

int main(){
    scanf("%d%d", &n, &m);
    memset(dist, 0x3f, sizeof dist);
    memset(g, 0x3f, sizeof g);

    while(m --){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int res = prim();

    if(res == INF) puts("impossible");
    else printf("%d", res);

    return 0;
}