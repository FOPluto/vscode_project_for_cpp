#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 200003;

const int null = 0x3f3f3f3f;

int h[N], ne[N], e[N];
int n;

int idx;

void add(int a, int b){
    ne[idx] = h[a];
    e[idx] = b;
    h[a] = idx ++;
}

int find(int t){
    return (t % N + N) % N;
}

int main(){
    scanf("%d", &n);
    memset(h, 0xff, sizeof h);
    while(n --){
        char ch[2];
        int t = 0;
        scanf("%s%d", ch, &t);
        if(ch[0] == 'I'){
            int item = find(t);
            add(item, t);
        } else {
            int item = find(t);
            if(h[item] == -1) puts("No");
            else {
                bool flag = false;
                for(int i = h[item];i != -1;i = ne[i]){
                    if(e[i] == t) {
                        flag = true;
                        break;
                    }
                }
                if(flag) puts("Yes");
                else puts("No");
            }
        }
    }
    return 0;
}