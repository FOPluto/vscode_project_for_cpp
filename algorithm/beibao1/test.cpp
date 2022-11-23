#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 3010;

int ans[N];
int w[N][N];
int n;

int main()
{
    scanf("%d", &n);
    int min = 0x3f3f3f3f;
    int max = 0;
    while (n--) {
        int s, e, ww;
        scanf("%d%d%d", &s, &e, &ww);
        w[s][e] = std::max(ww, w[s][e]);
        min     = std::min(min, s);
        max     = std::max(max, e);
    }

    for (int i = 1; i < N; i++) {
        ans[i] = std::max(ans[i], ans[i - 1]);
        for (int j = i; j < N; j++) {
            if (w[i][j]) {
                ans[j] = std::max(ans[j], ans[i] + w[i][j]);
            }
        }
    }
    int res = 0;
    for (int i = 1; i < N; i++) {
        res = std::max(res, ans[i]);
    }
    cout << res << endl;
    return 0;
}