#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 110010;

int  arr[100][2];
bool st[100][N];
int  n, m;

int main()
{
    scanf("%d%d", &n, &m);

    st[0][0] = true;
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        arr[i][0] = a;
        arr[i][1] = b;
    }
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            if (st[i][j]) {
                st[i + 1][j + arr[i][0]] = true;
                st[i + 1][j + arr[i][1]] = true;
            }
        }
    }

    for (int i = 0; i <= m; i++) {
        printf("%d", st[n][i]);
    }
    return 0;
}