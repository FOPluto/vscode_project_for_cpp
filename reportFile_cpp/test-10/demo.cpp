#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <cstdio>
#include <unordered_map>

using namespace std;

const int N = 100010, M = 200010

int n, m;
int h[N], e[M], ne[M], idx;
int color[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool dfs(int u, int c) {
    color[u] = c;//更新的值

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!color[j])
        {
            if (!dfs(j, 3 - c)) return false;//递归到下一层
        }
        else if (color[j] == c) return false;//如果不能匹配，就返回false，代表不是二分图
    }

    return true;//没有返回false就返回true
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    while (m -- )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    bool flag = true;
    for (int i = 1; i <= n; i ++) //对每个点都要试一次，因为不确定有没有独立块
        if (!color[i])
        {
            if (!dfs(i, 1))
            {
                flag = false;
                break;
            }
        }
    //只要有一个地方有冲突就不行
    if (flag) puts("Yes");
    else puts("No");

    return 0;
}

/**
 * @brief 样例
4 4
1 3
1 4
2 3
2 4
 */