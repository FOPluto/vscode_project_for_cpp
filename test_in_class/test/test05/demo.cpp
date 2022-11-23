#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1010;

bool st[N];

int n, m;
int e[N], head[N], ne[N];

int idx;

void add(int a, int b){
    e[idx] = b;
    ne[idx] = head[a];
    head[a] = idx ++;
}

int main(){
    cin >> n >> m;
    memset(head, 0xff, sizeof head);
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
        if(ans % 2 == 0) num ++;
    }
    if(num != n) {
        puts("0");
        return 0;
    }
    for(int i = 1;i <= n;i++){
        memset(st, 0, sizeof st);
        queue<int> q;
        q.push(i);
        num = 1;  //用于计数
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
            if(num != n) {
                puts("0");
                return 0;
            }
        }
        q = queue<int>();
    }
    puts("1");
    return 0;
}