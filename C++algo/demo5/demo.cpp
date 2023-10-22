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

const int N = 400010;

const int M = 400010;

int n, m, q;

int ne[N], e[N], h[N], p[N], d[N];
bool is_d[N];


struct Edge {
    int from;
    int to;
} edge[N];

int idx, edge_idx;

int find(int x){
    if(x == p[x]) return p[x];
    return p[x] = find(p[x]);
}

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int main(){

    memset(h, 0xff, sizeof h);

    scanf("%d%d", &n, &m);

    for(int i = 0;i < n;i++) p[i] = i;

    for(int i = 0;i < m;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
        edge[i * 2] = {a, b};
        edge[i * 2 + 1] = {b, a};
    }

    scanf("%d", &q);

    for(int i = 0;i < q;i++){
        int item = 0;
        scanf("%d", &item);
        d[i] = item;
        is_d[item] = true;
    }

    int num = n - q;

    for(int i = 0;i < 2 * m;i++){
        int a = edge[i].from, b = edge[i].to;
        int pa = find(a), pb = find(b);
        if(!is_d[a] && !is_d[b]) {
            if(pa != pb) {
                p[pa] = pb;
                num --;
            }
        }
    }

    vector<int> ans;

    ans.push_back(num);

    for(int i = q - 1;i >= 0;i--){
        int t = d[i];
        num ++;
        is_d[t] = false;
        for(int j = h[t];j != -1;j = ne[j]){
            int pt = find(t), pe = find(e[j]);
            if(pt != pe && !is_d[e[j]]){
                num --;
                p[pe] = pt;
            }
        }
        ans.push_back(num);
    }

    for(auto item = ans.rbegin();item != ans.rend();item ++) printf("%d\n", *item);

    return 0;
}