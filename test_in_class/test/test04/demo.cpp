#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<unordered_map>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
#include<set> 
#include<array>
#include<stack>

using namespace std;

const int N = 1e6 + 10;

struct node {
    char val;
    int le, ri;
} e[N];

int cnt;
void dfs_p (int p) {
    if (p == -1) return;
    char ans = e[p].val;
    cout << ans;
    if (e[p].le != -1) dfs_p(e[p].le);
    if (e[p].ri != -1) dfs_p(e[p].ri);
    if (e[p].le == -1 && e[p].ri == -1) cnt++;
}

void dfs_z (int p) {
    if (p == -1) return;
    if (e[p].le != -1) dfs_z(e[p].le);
    char ans = e[p].val;
    cout << ans;
    if (e[p].ri != -1) dfs_z(e[p].ri);
}

void dfs_h (int p) {
    if (p == -1) return;
    if (e[p].le != -1) dfs_h(e[p].le);
    if (e[p].ri != -1) dfs_h(e[p].ri); 
    char ans = e[p].val;
    cout << ans;   
}

int main() {
    string s;
    cin >> s;

    s = '\0' + s;
    char ro = s[1];
    e[1].val = ro;

    if (s[1] == '#') {
        cout << "0" << endl;
        return 0;
    }

    for (int i = 1; i <= N; i++) { 
        e[i].le = e[i].ri = -1;
    }
    
    int la = 0;
    for (int i = 2; i < (int)s.size(); i++) {
        char va = s[i];
        int pos = (i+la)/2 ;
        if (s[i] == '#') {
            e[i].val = '*';
            if ((la+i) % 2 == 0) e[pos].le = -1;
            else e[pos].ri = -1;
            continue;
        }
        if (e[pos].val == '*') {
            while (e[pos].val == '*') {
                la++;
                pos = (i+la)/2;
            }
        }
        if ((i+la) % 2 == 0) e[pos].le = i;
        else e[pos].ri = i;
        e[i].val = va;
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
