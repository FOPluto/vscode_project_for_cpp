#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100010, M = 200010;
int       h[N], e[M], ne[M], idx;
int       n, m;
int       color[N];

void add(int a, int b)
{
    e[idx]  = b;
    ne[idx] = h[a];
    h[a]    = idx++;
}
bool dfs(int u, int c)
{
    color[u] = c;
    for (int i = h[u]; i != -1; i = ne[i]) {
        if (!color[i]) {
            if (!dfs(i, 3 - c))
                return false;
            else {
                if (color[i] = c)
                    return false;
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }

    bool flag = true;

    for (int i = 1; i <= n; i++) {
        if (!dfs(i, 1)) {
            flag = false;
            break;
        }
    }
    if (flag)
        puts("Yes");
    else
        puts("No");
    return 0;
}