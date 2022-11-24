#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<set> 
#include<array>
#include<stack>

using namespace std;

const int N = 1e6 + 10;

struct node {
    char v;
    int l, r;
} e[N];

int cnt;
void dfs_p (int p) {   // 后序遍历
    if (p == -1) return;
    char ans = e[p].v;
    cout << ans;
    if (e[p].l != -1) dfs_p(e[p].l);
    if (e[p].r != -1) dfs_p(e[p].r);
    if (e[p].l == -1 && e[p].r == -1) cnt++;
}

void dfs_z (int p) {  // 中序遍历
    if (p == -1) return;
    if (e[p].l != -1) dfs_z(e[p].l);
    char ans = e[p].v;
    cout << ans;
    if (e[p].r != -1) dfs_z(e[p].r);
}

void dfs_h (int p) {  // 前序遍历
    if (p == -1) return;
    if (e[p].l != -1) dfs_h(e[p].l);
    if (e[p].r != -1) dfs_h(e[p].r); 
    char ans = e[p].v;
    cout << ans;   
}

int main() {
    string s;
    cin >> s;
    s = " " + s;  // 往右边缩进一下方便索引
    char ro = s[1];
    e[1].v = ro;

    if (s[1] == '#') { // 特判一下
        cout << "0" << endl;
        return 0;
    }
    
    for (int i = 1; i <= N; i++) {  // 初始化所有节点的左孩子和右孩子
        e[i].l = e[i].r = -1;   // -1代表没有
    }
    
    int flag = 0;
    for (int i = 2; i < (int)s.size(); i++) {
        char ch = s[i];
        int pos = (i + flag) / 2;
        if (s[i] == '#') {
            e[i].v = '*';
            if ((flag + i) % 2 == 0) e[pos].l = -1;
            else e[pos].r = -1;
            continue;
        }
        if (e[pos].v == '*') {
            while (e[pos].v == '*') {
                flag ++;
                pos = (i + flag) / 2;
            }
        }
        if ((i + flag) % 2 == 0) e[pos].l = i;
        else e[pos].r = i;
        e[i].v = ch;
    }
    
    dfs_p(1);
    puts("");
    dfs_z(1);
    puts("");
    dfs_h(1);
    puts("");
    printf("%d\n", cnt);

    return 0;
}
