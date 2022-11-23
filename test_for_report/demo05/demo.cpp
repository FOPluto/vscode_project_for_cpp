#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

const int N = 1010;
const int M = 1000010;

bool st[M];

int n, m;
int e[M], head[M], ne[M];

int idx;

void add(int a, int b){
    e[idx] = b;
    ne[idx] = head[a];
    head[a] = idx ++;
}

int main(){
    cin >> n >> m;
    
    if(n > m + 1) {
        puts("0");
        return 0;
    }
    
    memset(head, 0xff, sizeof head);
    memset(ne, 0xff, sizeof ne);
    while(m --){
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    int num = 0;
    for(int i = 1;i <= n;i++){
        int ans = 0;
        for(int j = head[i];j != -1;j = ne[j]){
            ans ++;
        }
        if(ans % 2) {
            puts("0");
            return 0;
        }
    }
    memset(st, 0, sizeof st);
    queue<int> q;
    q.push(1);
    num = 1;  //用于计数
    st[1] = true;
    while(!q.empty()){
        auto item = q.front();
        q.pop();
        for(int j = head[item];j != -1;j = ne[j]){
            int t = e[j];
            if(!st[t]){
                st[t] = true;
                q.push(t);
                num++;
            }
        }
    }
    if(num != n) {
        puts("0");
        return 0;
    }
    puts("1");
    return 0;
}