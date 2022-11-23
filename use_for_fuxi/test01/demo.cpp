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
int g[N][N];
bool st[N];
bool dg[N];
bool gd[N];
int n;

void dfs(int u){
    if(u == n + 1){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(j != 1) printf(" ");
                printf("%d", g[i][j]);
            }
            puts("");
        }
        puts("");
        return;
    }
    for(int i = 1;i <= n;i++){
        if(!st[i] && !dg[i + u] && !gd[n + i - u]){
            st[i] = dg[i + u] = gd[n + i - u] = true;
            g[u][i] = 'Q';
            dfs(u + 1);
            st[i] = dg[i + u] = gd[n + i - u] = false;
            g[u][i] = '.';
        }
    }
}

int main(){
    scanf("%d", &n);

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            g[i][j] = '.';
        }
    }
    dfs(1);
    return 0;
}
