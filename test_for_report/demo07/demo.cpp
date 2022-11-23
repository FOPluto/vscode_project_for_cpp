#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

const int N = 1010;

const int INF = 0x3f3f3f3f;

int g[N][N];
bool st[N];
int dist[N];
int n, m;

int main(){
    cin >> n >> m;
    memset(g, 0x3f, sizeof g); //初始化一下距离矩阵
    memset(dist, 0x3f, sizeof dist);
    while(m --){
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
        g[b][a] = min(g[b][a], c);
    }
    
    int res = 0;
    
    for(int i = 0;i < n;i++){
        int t = -1;
        for(int j = 1;j <= n;j++){
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }
        st[t] = true;
        
        if(i && dist[t] == INF) {
            puts("-1");
            return 0;
        }
        
        if(i) res += dist[t];
        
        for(int j = 1;j <= n;j++){
            dist[j] = min(dist[j], g[t][j]);
        }
    }
    cout << res;
    return 0;
}