#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 510;

const int n = 8;

bool g[N][N], st[N], ph[N], hp[N];

vector<string> ans; //这个用于存储所有的结果

void find(int u){
    if(u == n + 1){
        int idx = -1;
        string res = "";
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++)
                if(g[i][j]) idx = j; //如果这个点放了
            res.push_back(idx + '0');//当前答案字符串的构建
        }
        ans.push_back(res);//将得到的答案放进vector中
        return;
    }
    for(int i = 1;i <= n;i++){
        if(!st[i] && !ph[i + u] && !hp[n + i - u]){
            st[i] = ph[i + u] = hp[n + i - u] = true;
            g[u][i] = true; //在这个点放皇后，相当于处理一下
            find(u + 1);
            g[u][i] = false; //拿皇后，相当于回溯还原
            st[i] = ph[i + u] = hp[n + i - u] = false;
        }
    }
}

int m;

int main(){
    scanf("%d", &m);
    
    find(1);
    
    while(m --){
        int num;
        cin >> num;
        cout << ans[num - 1] << endl; //输出对应位置的答案即可
    }
    return 0;
}