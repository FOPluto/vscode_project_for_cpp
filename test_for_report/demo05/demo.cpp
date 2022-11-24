#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

const int N = 1010;
const int M = 1000010; //节点的开大了一点

bool st[M];

int n, m;
int e[M], head[M], ne[M];
// e表示这个位置存的节点编号
// head表示这个节点所对应的下一个节点列表的头结点位置
// ne表示链表中下一个元素的位置
int idx; // idx表示当前用到的节点

void add(int a, int b){ // 链表插入我使用头插法
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
    
    memset(head, 0xff, sizeof head); //先初始化head和ne（ne可以不用）
    memset(ne, 0xff, sizeof ne); //-1表示这个链表结束
    while(m --){
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a); //因为是无向图，所以反过来插一次
    }
    int num = 0;
    for(int i = 1;i <= n;i++){
        int ans = 0;
        for(int j = head[i];j != -1;j = ne[j]){
            ans ++; //对当前节点的子节点计数，看有几个子节点
        }
        if(ans % 2) { //如果存在奇数度的点，就直接输出0并结束
            puts("0");
            return 0;
        }
    }
    memset(st, 0, sizeof st); // 初始化st
    queue<int> q;
    q.push(1);
    num = 1;  //用于计数
    st[1] = true;
    while(!q.empty()){ // 使用bfs判断是否为连通图
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
