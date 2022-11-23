#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1000010;

struct edge
{
    int a, b, w;
} eg[N];

int p[N];

int n, m;

int find(int x){
    if(p[x] == x) p[x] = find(p[x]);
    return p[x];
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0;i < n;i++) p[i] = i;

    for(int i = 0;i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        eg[i] = {a, b, c};
    }
    
    sort(eg, eg + n, [](const edge& e1, const edge& e2){
        return e1.w > e2.w;
    });

    int res = 0, cnt = 0;

    for(int i = 0;i < m;i++){
        int a = eg[i].a, b = eg[i].b, w = eg[i].w;
        a = find(a);
        b = find(b);
        if(a != b){
            p[a] = b;
            res += w;
            cnt ++;
        }
    }

    if(cnt == n - 1){
        puts("impossible");
    } else {
        printf("%d\n", res);
    }

    return 0;
}