#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

const int N = 1010;

const int INF = 0x3f3f3f3f; //定义0x3f3f3f3f为无穷大

// Prim算法

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
        // 找到当前距离根节点最小的元素，用t记录
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
        
        if(i) res += dist[t]; // 将距离添加到res中
        
        for(int j = 1;j <= n;j++){
            dist[j] = min(dist[j], g[t][j]);
        }//根据最小的点t来更新接下来的每个点
    }
    cout << res;
    return 0;
}


// Kruskal算法则是维护一个森林，每次将两棵树合并成一棵树，并查集

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100010;
const int M = 200010;

int p[N];




struct edge{
    int a, b, w;
} eg[M];

int n, m;

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n;i++) p[i] = i;
    
    for(int i = 0;i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        eg[i] = {a, b, c};
    }
    
    sort(eg, eg + m, [](const edge& e1, const edge& e2){
        return e1.w < e2.w;
    });
    
    int cnt = 0, res = 0;
    
    for(int i = 0;i < m;i++){
        int a = eg[i].a, b = eg[i].b, w = eg[i].w;
        a = find(a), b = find(b);
        if(a != b){
            p[a] = b;
            res += w;
            cnt ++;
        }
    }
    
    if(cnt != n - 1){
        puts("-1");
    } else {
        printf("%d\n", res);
    }
    
    return 0;
}